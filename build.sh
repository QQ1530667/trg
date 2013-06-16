#!/bin/dash

fail() {
	echo ">> Failed"
	exit $1
}

[ -z "$CC" ] && CC="gcc"

CFLAGS="-Os -Wall $CFLAGS"
LDFLAGS="-lm $LDFLAGS"
EXEC_NAME="wkb"

if [ "$WITH_WEBKIT2" = "y" ]; then
	CFLAGS="$CFLAGS $(pkg-config --cflags gtk+-3.0 webkit2gtk-3.0) -D__HAVE_WEBKIT2__ -D__HAVE_GTK3__"
	LDFLAGS="$LDFLAGS $(pkg-config --libs gtk+-3.0 webkit2gtk-3.0)"
else
	if [ "$WITH_GTK3" = "y" ]; then
		CFLAGS="$CFLAGS $(pkg-config --cflags gtk+-3.0 webkitgtk-3.0) -D__HAVE_GTK3__"
		LDFLAGS="$LDFLAGS $(pkg-config --libs gtk+-3.0 webkitgtk-3.0)"
	else
		CFLAGS="$CFLAGS $(pkg-config --cflags gtk+-2.0 webkit-1.0)"
		LDFLAGS="$LDFLAGS $(pkg-config --libs gtk+-2.0 webkit-1.0)"
	fi
fi
echo "CFLAGS: $CFLAGS"
echo "LDLAGS: $LDFLAGS"

$CC -o $EXEC_NAME wkb.c $CFLAGS $LDFLAGS || fail $?
[ "$STRIP" = "n" ] || strip -s $EXEC_NAME || echo "strip failed..."

echo ">> Build successful"
