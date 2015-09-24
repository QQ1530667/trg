#!/bin/dash

munge_name() {
	printf '%s\n' "$*" | tr / _
}

SCRIPT_NAME="$(basename "$0")"
if [ -z "$1" -o -z "$2" ]; then
	echo "echo $SCRIPT_NAME: usage: $SCRIPT_NAME <uri> <title> [category]"
	exit 1
fi

cd "$(dirname "$0")"
URI="$1"
TITLE="$2"
[ -z "$TITLE" ] && TITLE="$1"
CATEGORY="x$(munge_name "$3")"
[ "$CATEGORY" = "x" ] && CATEGORY=Uncategorized

mkdir -p ./bookmarks

[ -f "./bookmarks/$CATEGORY" ] || printf '%s\n' "<h1>:: ${CATEGORY#x}</h1>" > "./bookmarks/$CATEGORY"
sed -i -e "1a \\
<p><a href=\"$URI\">$TITLE</a><br><span class="uri">$URI</span></p>" "./bookmarks/$CATEGORY"

cat ./header.html ./bookmarks/Uncategorized ./bookmarks/x* ./footer.html > ./bookmarks.html 2> /dev/null || true
