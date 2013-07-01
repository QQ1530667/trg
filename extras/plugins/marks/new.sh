#!/bin/dash

SCRIPT_NAME="$(basename "$0")"
cd "$(dirname "$0")"
. ./common.sh

[ -n "$1" -a -n "$2" -a -n "$3" -a "$#" = "3" ] || fail "echo $SCRIPT_NAME: usage: $SCRIPT_NAME <file> <uri> <mark>"
FILE="$1"
URI="$2"
MARK="$3"
if [ -f "$FILE" ] && [ "$(fetch_mark "$FILE" "$MARK")" ]; then
	echo "echo $SCRIPT_NAME: mark \\\"$MARK\\\" already exists"
else
	echo "$MARK $URI" >> "$FILE"
fi
