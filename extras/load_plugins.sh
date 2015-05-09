#!/bin/dash

cd "$(dirname "$0")"
[ -n "$(ls plugins/)" ] && echo loadconfig plugins/*/config
true
