#!/bin/dash

SCRIPT_NAME="$(basename "$0")"
cd "$(dirname "$0")"
. ./common.sh

[ -n "$1" ] || fail "echo $SCRIPT_NAME: usage: $SCRIPT_NAME <marks_file> [regex-]"
FILE="$1"
shift 1
[ -f "$FILE" ] || fail "echo $SCRIPT_NAME: error: marks file \\\"$FILE\\\" does not exist"
grep -e "$*" < "$FILE" | sed -e 's/ /\t/' -e 's/^/echo /' | escape | sed -e 's/^echo /echo "/' -e 's/$/"/'
