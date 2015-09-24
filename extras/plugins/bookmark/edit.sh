#!/bin/dash

munge_name() {
	printf '%s\n' "$*" | tr / _
}

SCRIPT_NAME="$(basename "$0")"
if [ -z "$1" ]; then
	echo "echo $SCRIPT_NAME: usage: $SCRIPT_NAME <editor> [category]"
	exit 1
fi

cd "$(dirname "$0")"
CATEGORY="x$(munge_name "$2")"
[ "$CATEGORY" = "x" -o "$CATEGORY" = "xUncategorized" ] && CATEGORY=Uncategorized
[ "$CATEGORY" = "x." ] && CATEGORY=.

$1 ./bookmarks/"$CATEGORY"
cat ./header.html ./bookmarks/Uncategorized ./bookmarks/x* ./footer.html > ./bookmarks.html 2> /dev/null || true
