#!/bin/sh

fail() {
	echo ">> Failed"
	exit $1
}

[ -z "$CC" ] && CC="gcc"

CFLAGS="-Os -Wall $CFLAGS"
LDFLAGS="-lm $LDFLAGS"
EXEC_NAME="wkb"

CFLAGS="$CFLAGS $(pkg-config --cflags gtk+-3.0 webkit2gtk-3.0)"
LDFLAGS="$LDFLAGS $(pkg-config --libs gtk+-3.0 webkit2gtk-3.0)"

echo "CFLAGS: $CFLAGS"
echo "LDLAGS: $LDFLAGS"

$CC -o $EXEC_NAME wkb.c $CFLAGS $LDFLAGS || fail $?
[ "$STRIP" = "n" ] || strip -s $EXEC_NAME || echo "strip failed..."

echo ">> Build successful"
