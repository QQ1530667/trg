#!/bin/dash

echo -n "remove $(basename "$1") (Y/n)? "
read -r RESPONSE
[ "$RESPONSE" = "n" ] || rm "$1"
