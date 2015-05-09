### About:

Wkb is a modal web browser utilizing WebKitGTK.

### Building:

#### Dependencies:

* webkit2gtk or webkitgtk

#### Full dependency list for example configuration:

* dash
* awk
* sed (needs support for `-i` flag)
* grep
* xterm (or other terminal)
* vim (or other editor)
* feh
* curl
* mupdf
* libreoffice
* transmission-cli

#### Build with gtk3 and webkit2:

	$ ./build.sh

#### Build with gtk3 and webkit1:

	$ ./build.sh --with-webkit1

#### Build with gtk2 and webkit1:

	$ ./build.sh --with-gtk2 --with-webkit1

### Usage:

#### Synopsis:

	wkb [command ...]

#### Example:

	$ wkb nset wkb.download-dir /tmp\; open google.com\; topen archlinux.org

Run `:help [command]` to get a list of available commands or to get help for a specific command.

### Command Language:

The command language is very simple and resembles sh in some ways.

#### Control characters:

Semicolons are used as command line separators. For example:

	echo hello; echo world

executes `echo hello` and then `echo world`.

Newlines are interpreted as command line separators when reading from a file or command FIFO.

#### Quoting:

Quoting removes the special meaning of whitespace characters and control characters.

#### Backslashes:

A backslash removes any special meaning of the following character with the exception of the newline character.

#### Aliases:

Aliases are defined by a name and corresponding value by the `alias` command. If the first word in a command line matches an alias's name, the contents of the alias will be expanded in place of the word. For example, if an alias is defined with the name `hello` and the value `echo Hello,`, then:

	hello World!

would expand to:

	echo Hello, World!

Aliases can be escaped by prepending `!`.

#### Variable expansion:

Variables are expanded by enclosing the variable name in braces (example: `{wkb.download-dir}`). Both internal variables (those that can be accessed with the `set` command) and environment variables can be expanded.

Alternate variables can be specified within braces, separated by `:` (example: `{XDG_CONFIG_HOME:XDG_CONFIG_HOME_DEFAULT}`). If a variable does not exist or is empty, the next alternate will be tried. This feature is used internally to set `wkb.config-dir` because the `XDG_CONFIG_HOME` environment variable may not be set.

#### Comments:

If the first non-whitespace character in a line is `#`, the line is not interpreted.

### Configuration:

Wkb reads `$XDG_CONFIG_HOME/wkb/config` on startup. See `extras/` for an example configuration.

### Theming:

Theming is done via the normal gtk configuration files (`$XDG_CONFIG_HOME/gtk-3.0/gtk.css` for gtk3 or `$HOME/.gtkrc-2.0` for gtk2). Fonts are not assigned in the code, so the minimal themes are required for correct console output.

#### Minimal theme for gtk3:

	#wkb-console {
		font: Monospace 8;
	}

#### Minimal theme for gtk2:

	style "style-wkb-console"
	{
		font_name = "Monospace 8"
	}
	widget "wkb.GtkVBox.wkb-console-sw.wkb-console" style "style-wkb-console"
