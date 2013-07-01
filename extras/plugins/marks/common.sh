fetch_mark() {
	awk -F' ' -v MARK="$2" '$1==MARK{ print $0; exit }' "$1" | cut -d' ' -f2-
}

escape() {
	sed -e 's@\\@\\\\@g' -e 's@"@\\"@g' -e 's@{@\\{@g' -e 's@;@\\;@g'
}

fail() {
	echo "$@"
	exit 1
}
