#!/bin/dash

escape() {
	sed -e 's@\\@\\\\@g' -e 's@"@\\"@g' -e 's@{@\\{@g' -e 's@;@\\;@g'
}

SCRIPT_NAME="$(basename "$0")"
if ! [ -n "$1" ]; then
	echo "echo $SCRIPT_NAME: usage: $SCRIPT_NAME <marks-file> [regex-]"
	exit 1
fi
if ! [ -f "$1" ]; then
	echo "echo $SCRIPT_NAME: error: marks file \\\"$2\\\" does not exist"
	exit 1
fi
FILE="$1"
shift 1
grep -e "$*" < "$FILE" | sed -e 's/^/echo /' | escape
