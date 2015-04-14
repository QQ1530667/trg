#!/bin/sh

fail() {
	echo "## failed"
	exit $1
}

[ -z "$CC" ] && CC="gcc"

if pkg-config --exists webkit2gtk-4.0; then
	WEBKIT_PKG=webkit2gtk-4.0
elif pkg-config --exists webkit2gtk-3.0; then
	WEBKIT_PKG=webkit2gtk-3.0
else
	echo "## error: wkb requires webkit2gtk"
	fail
fi

[ "$WITH_SHARED" = "y" ] && CFLAGS="$CFLAGS -DWITH_SHARED"

CFLAGS="-Os -Wall $(pkg-config --cflags gtk+-3.0 $WEBKIT_PKG) $CFLAGS"
LDFLAGS="$(pkg-config --libs gtk+-3.0 $WEBKIT_PKG) -lm $LDFLAGS"

echo "CFLAGS: $CFLAGS"
echo "LDLAGS: $LDFLAGS"

$CC -o wkb $CFLAGS $LDFLAGS wkb.c || fail $?

echo ">> Build successful"
