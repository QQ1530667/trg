#!/bin/dash
case "$1" in
	*webkit2*)
		echo "loadconfig webkit2config"
		;;
	*)
		echo "loadconfig webkit1config"
		;;
esac
