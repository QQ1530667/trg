#!/bin/dash

SCRIPT_NAME="$(basename "$0")"
[ -n "$1" ] || exit 1
CMD_FIFO="$1"
shift 1
URI="$*"
STRIPPED_URI="${URI%%\?*}"
STRIPPED_URI="${STRIPPED_URI%%#*}"

case "$STRIPPED_URI" in
	*.torrent|magnet:*)
		transmission-remote 192.168.1.9 -a "$URI"
		;;
	http://imgur.com/a/*|http://www.imgur.com/a/*)
		curl -s "$STRIPPED_URI/embed" | grep '<img id="thumb-' | sed 's@.*<img id="thumb-\([^"]*\)".*@http://i.imgur.com/\1.jpg@' | xargs feh
		;;
	http://imgur.com/*|http://www.imgur.com/*)
		feh "http://i.imgur.com/$(basename "$URI").jpg"
		;;
	*.png|*.jpg|*.jpeg|*.bmp|*.gif|*.tif|*.tiff)
		feh "$URI"
		;;
	*)
		[ -p "$CMD_FIFO" ] && echo "echo $SCRIPT_NAME: no handler for \\\"$URI\\\"" > "$CMD_FIFO"
esac
