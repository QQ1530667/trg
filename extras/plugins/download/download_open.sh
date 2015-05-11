#!/bin/dash

SCRIPT_NAME="$(basename "$0")"
CMD_FIFO="$1"
TERM="${2:-xterm}"
FILE="$3"
if ! [ -n "$CMD_FIFO" -a -n "$FILE" -a -e "$FILE" ]; then
	[ -n "$CMD_FIFO" -a -p "$CMD_FIFO" ] && echo "echo $SCRIPT_NAME: error: file does not exist: \"$FILE\"" > "$CMD_FIFO"
	exit 1
fi

rm_prompt() {
	$TERM -e "$(dirname "$0")/rm_prompt.sh" "$1"
}

case "$(file -b --mime-type "$FILE")" in
	application/pdf)
		mupdf "$FILE"
		rm_prompt "$FILE"
		;;
	application/*officedocument* | \
	application/vnd.ms-excel | \
	application/msword)
		libreoffice "$FILE"
		rm_prompt "$FILE"
		;;
esac
