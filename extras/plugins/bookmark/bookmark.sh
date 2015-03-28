#!/bin/dash

SCRIPT_NAME="$(basename "$0")"
if ! [ -n "$1" -a -n "$2" ]; then
	echo "echo $SCRIPT_NAME: usage: $SCRIPT_NAME <file> <uri> [title] [comment]"
	exit 1
fi
if ! [ -f "$1" ]; then
	echo '<html><head><meta http-equiv="Content-Type" content="text/html;charset=utf-8"><title>Bookmarks</title><style type="text/css">body { background-color:#fff; color:#444; font-size:10pt; font-family:Verdana; margin:0 auto; padding:2em; word-wrap:break-word; max-width:60em; } a { color:#444; text-decoration:none; font-weight:bold; } p { padding:0.4em 0; } .uri { color:#999; font-size:80%; } .comment { font-size:80%; }</style></head><body>' > "$1"
	echo '</body>' >> "$1"
fi
uri="$2"
echo "$uri" | grep -q ':' || uri="http://$uri"
comment=""
[ -n "$4" ] && comment="<br><span class=\"comment\">$4</span>"
if [ -n "$3" ]; then
	content="<p><a href=\"$uri\">$3</a><br><span class="uri">$uri</span>$comment</p>"
else
	content="<p><a href=\"$uri\">$uri</a>$comment</p>"
fi
sed -i -e "1a $content" "$1"
