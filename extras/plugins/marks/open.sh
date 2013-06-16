#!/bin/dash

fetch_mark() {
	awk -F' ' -v MARK="$2" '$1==MARK{ print $0; exit }' "$1" | cut -d' ' -f2-
}

escape() {
	sed -e 's@\\@\\\\@g' -e 's@"@\\"@g' -e 's@{@\\{@g' -e 's@;@\\;@g'
}

SCRIPT_NAME="$(basename "$0")"
if ! [ -n "$1" -a -n "$2" ]; then
	echo "echo $SCRIPT_NAME: usage: $SCRIPT_NAME <marks-file> <command> [uri|mark-]"
	exit 1
fi
FILE="$1"
COMMAND="$2"
shift 2
MARK="$*/"
unset URI
[ -f "$FILE" ] && URI="$(fetch_mark "$FILE" "${MARK%%/*}")"
if [ -n "$URI" ]; then
	ESCAPED_PATH="$(echo "${MARK#*/}" | escape)"
	echo "$COMMAND $URI/$ESCAPED_PATH" | sed -e 's@\([^:]\)///*@\1/@g' -e 's@/$@@'
else
	echo "$COMMAND $*" | escape
fi
