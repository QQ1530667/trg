#!/bin/dash

SCRIPT_NAME="$(basename "$0")"
if ! [ -n "$1" -a -n "$2" ]; then
	echo "echo $SCRIPT_NAME: usage: $SCRIPT_NAME <bookmarks-file> <uri> [title] [comment]"
	exit 1
fi
if ! [ -f "$1" ]; then
	echo "echo $SCRIPT_NAME: error: bookmarks file \"$1\" does not exist or is not a regular file"
	exit 1
fi
uri="$2"
echo "$uri" | grep -q ':' || uri="http://$uri"
comment=""
[ -n "$4" ] && comment="<span class="comment"><br>$4</span>"
if [ -n "$3" ]; then
	content="<p><a href=\"$uri\">$3</a><br><span class="uri">$uri</span>$comment</p>"
else
	content="<p><a href=\"$uri\">$uri</a>$comment</p>"
fi
sed -i -e "1a $content" "$1"
