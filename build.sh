#!/bin/sh

fail() {
	echo ">> Failed"
	exit $1
}

[ -z "$CC" ] && CC="gcc"

CFLAGS="-Os -Wall $CFLAGS"
LDFLAGS="-lm $LDFLAGS"
EXEC_NAME="wkb"

WEBKIT_PKG=webkit2gtk-3.0
if pkg-config --exists webkit2gtk-4.0; then
	WEBKIT_PKG=webkit2gtk-4.0
fi

CFLAGS="$CFLAGS $(pkg-config --cflags gtk+-3.0 $WEBKIT_PKG)"
LDFLAGS="$LDFLAGS $(pkg-config --libs gtk+-3.0 $WEBKIT_PKG)"

echo "CFLAGS: $CFLAGS"
echo "LDLAGS: $LDFLAGS"

$CC -o $EXEC_NAME wkb.c $CFLAGS $LDFLAGS || fail $?
[ "$STRIP" = "n" ] || strip -s $EXEC_NAME || echo "strip failed..."

echo ">> Build successful"
