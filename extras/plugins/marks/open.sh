#!/bin/dash

SCRIPT_NAME="$(basename "$0")"
cd "$(dirname "$0")"
. ./common.sh

[ -n "$1" ] || fail "echo $SCRIPT_NAME: usage: $SCRIPT_NAME <file> <command> [uri|mark-]"
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
