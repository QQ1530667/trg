#!/bin/dash
cd "$(dirname "$0")"

COMMAND="js-file"

# base scripts
for i in plugins/default.js plugins/*_a.js; do
	COMMAND="$COMMAND \"$PWD/$i\""
done

# site specific scripts (nothing for now)

# main script
echo "$COMMAND \"$PWD/img_hover.js\""
