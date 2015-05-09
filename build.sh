#!/bin/sh

fail() {
	echo "## failed"
	exit $1
}

CONFIG_GTK_VERSION=3
CONFIG_WEBKIT_API=2
unset CONFIG_NO_CONFIG WEBKIT_PKG EXTRA_CFLAGS

for i in "$@"; do
	case "$i" in
		--no-config) NO_CONFIG=y ;;
	esac
done

[ "$NO_CONFIG" != "y" -a -f ./.config ] && . ./.config

USAGE="Usage: $0 [option]

Options:
  --with-gtk3
  --with-gtk2       (webkit1 only)
  --with-webkit2
  --with-webkit1
  --shared-process  (webkit2 only; use shared process model)
  --no-config       (ignore .config)
  --help"

for i in "$@"; do
	case "$i" in
		--with-gtk3)      CONFIG_GTK_VERSION=3 ;;
		--with-gtk2)      CONFIG_GTK_VERSION=2 ;;
		--with-webkit2)   CONFIG_WEBKIT_API=2 ;;
		--with-webkit1)   CONFIG_WEBKIT_API=1 ;;
		--shared-process) EXTRA_CFLAGS="$EXTRA_CFLAGS -D__WITH_SHARED__" ;;
		--no-config) ;;
		--help) echo "$USAGE"; exit 0 ;;
		*) echo "error: invalid option: $i"; echo "$USAGE"; exit 1 ;;
	esac
done

[ -z "$CC" ] && CC="gcc"

if [ "$CONFIG_WEBKIT_API" == 2 ]; then
	if pkg-config --exists webkit2gtk-4.0; then
		WEBKIT_PKG=webkit2gtk-4.0
	elif pkg-config --exists webkit2gtk-3.0; then
		WEBKIT_PKG=webkit2gtk-3.0
	else
		echo "## error: cannot find webkit2gtk"
		fail
	fi
	EXTRA_CFLAGS="$EXTRA_CFLAGS -D__HAVE_WEBKIT2__ -D__HAVE_GTK3__"
else
	if [ "$CONFIG_GTK_VERSION" == 3 ]; then
		if pkg-config --exists webkitgtk-3.0; then
			WEBKIT_PKG=webkitgtk-3.0
			EXTRA_CFLAGS="$EXTRA_CFLAGS -D__HAVE_GTK3__"
		else
			echo "## error: cannot find webkitgtk-3.0"
			fail
		fi
	else
		if pkg-config --exists webkit-1.0; then
			WEBKIT_PKG=webkit-1.0
		else
			echo "## error: cannot find webkit-1.0"
			fail
		fi
	fi
fi

CFLAGS="-Os -Wall $(pkg-config --cflags $WEBKIT_PKG) $EXTRA_CFLAGS $CFLAGS"
LDFLAGS="$(pkg-config --libs $WEBKIT_PKG) -lm $LDFLAGS"

echo "CFLAGS: $CFLAGS"
echo "LDLAGS: $LDFLAGS"

$CC -o wkb $CFLAGS $LDFLAGS wkb.c || fail $?

echo ">> Build successful"
