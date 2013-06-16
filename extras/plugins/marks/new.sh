#!/bin/dash

fetch_mark() {
	awk -F' ' -v MARK="$2" '$1==MARK{ print $0; exit }' "$1" | cut -d' ' -f2-
}

SCRIPT_NAME="$(basename "$0")"
if ! [ -n "$1" -a -n "$2" -a -n "$3" -a "$#" = "3" ]; then
	echo "echo $SCRIPT_NAME: usage: $SCRIPT_NAME <marks-file> <uri> <mark>"
	exit 1
fi
FILE="$1"
URI="$2"
MARK="$3"
if [ -f "$FILE" ] && [ "$(fetch_mark "$FILE" "$MARK")" ]; then
	echo "echo $SCRIPT_NAME: mark \\\"$MARK\\\" already exists"
else
	echo "$MARK $URI" >> "$FILE"
fi
