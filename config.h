#ifdef __HAVE_WEBKIT2__
#define WKB_WEBKIT_API "2"
#else
#define WKB_WEBKIT_API "1"
#endif

static const gchar null_title[]      = "Untitled";

#define VAR_PREFIX_WEBKIT_WEB_VIEW "v."
#define VAR_PREFIX_WEBKIT_SETTINGS "s."
#define VAR_PREFIX_SOUP_SESSION    "soup."

#define VAR_WEBKIT_API     "wkb.webkit-api"
#define VAR_CMD_FIFO       "wkb.cmd-fifo"
#define VAR_CONFIG_DIR     "wkb.config-dir"
#define VAR_COOKIE_FILE    "wkb.cookie-file"
#define VAR_COOKIE_POLICY  "wkb.cookie-policy"
#define VAR_AUTO_SCROLL    "wkb.auto-scroll"
#define VAR_SHOW_CONSOLE   "wkb.show-console"
#define VAR_PRINT_KEYVAL   "wkb.print-keyval"
#define VAR_ALLOW_POPUPS   "wkb.allow-popups"
#define VAR_DOWNLOAD_DIR   "wkb.download-dir"
#define VAR_DL_OPEN_CMD    "wkb.download-open"
#define VAR_DL_AUTO_OPEN   "wkb.auto-open-downloads"
#define VAR_DEFAULT_WIDTH  "wkb.default-width"
#define VAR_DEFAULT_HEIGHT "wkb.default-height"
#ifdef __HAVE_WEBKIT2__
#define VAR_SPELL_LANGS    "wkb.spellcheck-langs"
#define VAR_SPELL          "wkb.spellcheck"
#define VAR_TLS_ERRORS     "wkb.tls-errors"
#endif
#define VAR_FIND_STRING    "wkb.find"
#define VAR_HOMEPAGE       "wkb.homepage"
#define VAR_CURRENT_URI    "uri"
#define VAR_FC_DIR         "file-chooser.dir"
#define VAR_FC_FILE        "file-chooser.file"
#define VAR_CLIPBOARD_TEXT "clipboard.text"
#define VAR_LOAD_STARTED   "hook.load-started"
#define VAR_DOM_READY      "hook.dom-ready"
#define VAR_LOAD_FINISHED  "hook.load-finished"
#define VAR_CREATE         "hook.create"

#ifdef __HAVE_WEBKIT2__
static gchar cmd_add_ss_desc[]        = "add-stylesheet: add a stylesheet\n";
static gchar cmd_add_ss_usage[]       = "add-stylesheet: usage: add-stylesheet <source> <base-uri> <whitelist> <blacklist>\n";
#endif
static gchar cmd_alias_desc[]         = "alias: define an alias, print the alias definition if no value is given, or list aliases if no arguments are given\n";
static gchar cmd_alias_usage[]        = "alias: usage: alias [<name> [value]]\n";
static gchar cmd_bind_desc[]          = "bind: bind a key to a handler, print matching binds if no handler is given, or list bindings if no arguments are given\n";
static gchar cmd_bind_usage[]         = "bind: usage: bind [<modes:a,n,c,i,p> <modifiers:-,s|S,c,1,2,3,4,5> <key> [<handler> [arg]]]\n";
static gchar cmd_clear_desc[]         = "clear: clear the console\n";
static gchar cmd_clear_usage[]        = "clear: usage: clear\n";
#ifdef __HAVE_WEBKIT2__
static gchar cmd_clear_cache_desc[]   = "clear-cache: clear all cached resources\n";
static gchar cmd_clear_cache_usage[]  = "clear-cache: usage: clear\n";
#endif
static gchar cmd_dl_cancel_desc[]     = "dl-cancel: cancel the specified downloads, or all downloads if no arguments are given\n";
static gchar cmd_dl_cancel_usage[]    = "dl-cancel: usage: dl-cancel [id ...]\n";
static gchar cmd_dl_clear_desc[]      = "dl-clear: cancel and remove the specified downloads, or all downloads if no arguments are given\n";
static gchar cmd_dl_clear_usage[]     = "dl-clear: usage: dl-clear [id ...]\n";
static gchar cmd_dl_new_desc[]        = "dl-new: download the specified uri (defaults to {"VAR_CURRENT_URI"})\n";
static gchar cmd_dl_new_usage[]       = "dl-new: usage: dl-new [uri-]\n";
static gchar cmd_dl_open_desc[]       = "dl-open: run {"VAR_DL_OPEN_CMD"} on the specified downloads (%f is substituted with the file path)\n";
static gchar cmd_dl_open_usage[]      = "dl-open: usage: dl-open [id ...]\n";
static gchar cmd_dl_status_desc[]     = "dl-status: display status information for the specified downloads, or all downloads if no arguments are given\n";
static gchar cmd_dl_status_usage[]    = "dl-status: usage: dl-status [id ...]\n";
static gchar cmd_echo_desc[]          = "echo: print args to console\n";
static gchar cmd_echo_usage[]         = "echo: usage: echo [args ...]\n";
static gchar cmd_eopen_input_desc[]   = "eopen-input: open the input bar with the contents set to the arguments given with special characters escaped\n";
static gchar cmd_eopen_input_usage[]  = "eopen-input: usage: eopen-input [args ...]\n";
static gchar cmd_find_desc[]          = "find: search the page for the next occurrence of either a specified string or {"VAR_FIND_STRING"} if none is given\n";
static gchar cmd_find_usage[]         = "find: usage: find [string-]\n";
static gchar cmd_help_desc[]          = "help: list commands or display help for a given command\n";
static gchar cmd_help_usage[]         = "help: usage: help [command]\n";
static gchar cmd_js_desc[]            = "js: evaluate javascript expression\n";
static gchar cmd_js_usage[]           = "js: usage: js <expression->\n";
static gchar cmd_js_file_desc[]       = "js-file: run javascript file(s)\n";
static gchar cmd_js_file_usage[]      = "js-file: usage: js-file <file ...>\n";
static gchar cmd_last_desc[]          = "last: switch to the previously displayed tab\n";
static gchar cmd_last_usage[]         = "last: usage: last\n";
static gchar cmd_loadconfig_desc[]    = "loadconfig: load configuration file(s); relative to {"VAR_CONFIG_DIR"} if not full path\n";
static gchar cmd_loadconfig_usage[]   = "loadconfig: usage: loadconfig <file ...>\n";
static gchar cmd_nav_desc[]           = "nav: navigate back or forward\n";
static gchar cmd_nav_usage[]          = "nav: usage: nav [+|-]<number>\n";
static gchar cmd_necho_desc[]         = "necho: print args to console; do not force console to be shown\n";
static gchar cmd_necho_usage[]        = "necho: usage: necho [args ...]\n";
static gchar cmd_nset_desc[]          = "nset: set a variable, print the variable definition if no value is given, or list variables if no arguments are given; do not create the variable if it does not exist\n";
static gchar cmd_nset_usage[]         = "nset: usage: nset [<name> [value]]\n";
static gchar cmd_open_desc[]          = "open: load a uri (defaults to {"VAR_HOMEPAGE"})\n";
static gchar cmd_open_usage[]         = "open: usage: open [uri-]\n";
static gchar cmd_open_input_desc[]    = "open-input: open the input bar with the contents set to the arguments given\n";
static gchar cmd_open_input_usage[]   = "open-input: usage: open-input [args ...]\n";
static gchar cmd_print_desc[]         = "print: run the print dialog\n";
static gchar cmd_print_usage[]        = "print: usage: print\n";
static gchar cmd_quit_desc[]          = "quit: quit the program\n";
static gchar cmd_quit_usage[]         = "quit: usage: quit\n";
static gchar cmd_reload_desc[]        = "reload: reload the current page\n";
static gchar cmd_reload_usage[]       = "reload: usage: reload\n";
static gchar cmd_reload_nc_desc[]     = "reload!: reload the current page without using any cached data\n";
static gchar cmd_reload_nc_usage[]    = "reload!: usage: reload!\n";
static gchar cmd_reorder_desc[]       = "reorder: change the position of the current tab\n";
static gchar cmd_reorder_usage[]      = "reorder: usage: reorder <[+|-]<number>|e>\n";
static gchar cmd_rfind_desc[]         = "rfind: search the page for the previous occurrence of either a specified string or {"VAR_FIND_STRING"} if none is given\n";
static gchar cmd_rfind_usage[]        = "rfind: usage: rfind [string-]\n";
static gchar cmd_set_desc[]           = "set: set a variable, print the variable definition if no value is given, or list variables if no arguments are given\n";
static gchar cmd_set_usage[]          = "set: usage: set [<name> [value]]\n";
static gchar cmd_set_mode_desc[]      = "set-mode: set the mode\n";
static gchar cmd_set_mode_usage[]     = "set-mode: usage: set-mode <mode:n,c,i,p>\n";
static gchar cmd_spawn_desc[]         = "spawn: asynchronously execute an external program; stdout and stderr are redirected to /dev/null\n";
static gchar cmd_spawn_usage[]        = "spawn: usage: spawn <program> [args ...]\n";
static gchar cmd_spawn_sync_desc[]    = "spawn-sync: synchronously execute an external program; stdout is captured and executed line-by-line; stderr is captured and printed to the console\n";
static gchar cmd_spawn_sync_usage[]   = "spawn-sync: usage: spawn-sync <program> [args ...]\n";
static gchar cmd_stop_desc[]          = "stop: stop loading the page\n";
static gchar cmd_stop_usage[]         = "stop: usage: stop\n";
static gchar cmd_switch_desc[]        = "switch: switch to a given tab\n";
static gchar cmd_switch_usage[]       = "switch: usage: switch <[+|-]<number>|e>\n";
static gchar cmd_tclose_desc[]        = "tclose: close the current tab\n";
static gchar cmd_tclose_usage[]       = "tclose: usage: tclose\n";
static gchar cmd_topen_desc[]         = "topen: load a uri in a new tab (defaults to {"VAR_HOMEPAGE"})\n";
static gchar cmd_topen_usage[]        = "topen: usage: topen [uri-]\n";
static gchar cmd_unalias_desc[]       = "unalias: remove an alias definition\n";
static gchar cmd_unalias_usage[]      = "unalias: usage: unalias <name>\n";
static gchar cmd_unbind_desc[]        = "unbind: unbind a key\n";
static gchar cmd_unbind_usage[]       = "unbind: usage: unbind <modes:a,n,c,i,p> <modifiers:-,s|S,c,1,2,3,4,5> <key>\n";
static gchar cmd_unset_desc[]         = "unset: unset a variable\n";
static gchar cmd_unset_usage[]        = "unset: usage: unset <name>\n";
static gchar cmd_wclose_desc[]        = "wclose: close the current window\n";
static gchar cmd_wclose_usage[]       = "wclose: usage: wclose\n";
static gchar cmd_window_desc[]        = "window: run a command in given window\n";
static gchar cmd_window_usage[]       = "window: usage: window <id|first|last> [command-]\n";
static gchar cmd_wopen_desc[]         = "wopen: load a uri in a new window (defaults to {"VAR_HOMEPAGE"})\n";
static gchar cmd_wopen_usage[]        = "wopen: usage: wopen [uri-]\n";
static gchar cmd_zoom_desc[]          = "zoom: set the zoom level for the current tab\n";
static gchar cmd_zoom_usage[]         = "zoom: usage: zoom [+|-]<number:1.0=100%>\n";

static struct command commands[] = {
#ifdef __HAVE_WEBKIT2__
	{ "add-stylesheet",  cmd_add_ss_desc,       cmd_add_ss_usage,       cmd_add_ss },
#endif
	{ "alias",           cmd_alias_desc,        cmd_alias_usage,        cmd_alias },
	{ "bind",            cmd_bind_desc,         cmd_bind_usage,         cmd_bind },
	{ "clear",           cmd_clear_desc,        cmd_clear_usage,        cmd_clear },
#ifdef __HAVE_WEBKIT2__
	{ "clear-cache",     cmd_clear_cache_desc,  cmd_clear_cache_usage,  cmd_clear_cache },
#endif
	{ "dl-clear",        cmd_dl_clear_desc,     cmd_dl_clear_usage,     cmd_dl_clear },
	{ "dl-cancel",       cmd_dl_cancel_desc,    cmd_dl_cancel_usage,    cmd_dl_cancel },
	{ "dl-new",          cmd_dl_new_desc,       cmd_dl_new_usage,       cmd_dl_new },
	{ "dl-open",         cmd_dl_open_desc,      cmd_dl_open_usage,      cmd_dl_open },
	{ "dl-status",       cmd_dl_status_desc,    cmd_dl_status_usage,    cmd_dl_status },
	{ "echo",            cmd_echo_desc,         cmd_echo_usage,         cmd_echo },
	{ "eopen-input",     cmd_eopen_input_desc,  cmd_eopen_input_usage,  cmd_open_input },
	{ "find",            cmd_find_desc,         cmd_find_usage,         cmd_find },
	{ "help",            cmd_help_desc,         cmd_help_usage,         cmd_help },
	{ "js",              cmd_js_desc,           cmd_js_usage,           cmd_js },
	{ "js-file",         cmd_js_file_desc,      cmd_js_file_usage,      cmd_js_file },
	{ "last",            cmd_last_desc,         cmd_last_usage,         cmd_last },
	{ "loadconfig",      cmd_loadconfig_desc,   cmd_loadconfig_usage,   cmd_loadconfig },
	{ "nav",             cmd_nav_desc,          cmd_nav_usage,          cmd_nav },
	{ "necho",           cmd_necho_desc,        cmd_necho_usage,        cmd_echo },
	{ "nset",            cmd_nset_desc,         cmd_nset_usage,         cmd_set },
	{ "open",            cmd_open_desc,         cmd_open_usage,         cmd_open },
	{ "open-input",      cmd_open_input_desc,   cmd_open_input_usage,   cmd_open_input },
	{ "print",           cmd_print_desc,        cmd_print_usage,        cmd_print },
	{ "quit",            cmd_quit_desc,         cmd_quit_usage,         cmd_quit },
	{ "reload",          cmd_reload_desc,       cmd_reload_usage,       cmd_reload },
	{ "reload!",         cmd_reload_nc_desc,    cmd_reload_nc_usage,    cmd_reload_nc },
	{ "reorder",         cmd_reorder_desc,      cmd_reorder_usage,      cmd_reorder },
	{ "rfind",           cmd_rfind_desc,        cmd_rfind_usage,        cmd_find },
	{ "set",             cmd_set_desc,          cmd_set_usage,          cmd_set },
	{ "set-mode",        cmd_set_mode_desc,     cmd_set_mode_usage,     cmd_set_mode },
	{ "spawn",           cmd_spawn_desc,        cmd_spawn_usage,        cmd_spawn },
	{ "spawn-sync",      cmd_spawn_sync_desc,   cmd_spawn_sync_usage,   cmd_spawn },
	{ "stop",            cmd_stop_desc,         cmd_stop_usage,         cmd_stop },
	{ "switch",          cmd_switch_desc,       cmd_switch_usage,       cmd_switch },
	{ "tclose",          cmd_tclose_desc,       cmd_tclose_usage,       cmd_tclose },
	{ "topen",           cmd_topen_desc,        cmd_topen_usage,        cmd_topen },
	{ "unalias",         cmd_unalias_desc,      cmd_unalias_usage,      cmd_unalias },
	{ "unbind",          cmd_unbind_desc,       cmd_unbind_usage,       cmd_unbind },
	{ "unset",           cmd_unset_desc,        cmd_unset_usage,        cmd_unset },
	{ "wclose",          cmd_wclose_desc,       cmd_wclose_usage,       cmd_wclose },
	{ "window",          cmd_window_desc,       cmd_window_usage,       cmd_window },
	{ "wopen",           cmd_wopen_desc,        cmd_wopen_usage,        cmd_wopen },
	{ "zoom",            cmd_zoom_desc,         cmd_zoom_usage,         cmd_zoom },
};

static struct var_handler var_handlers[] = {
	{ set_handler_gobject,  get_handler_gobject,  init_handler_gobject },
	{ set_handler_wkb,      get_handler_wkb,      init_handler_wkb },
};

static struct bind_handler bind_handlers[] = {
	{ "hist-next",             bind_hist_next },
	{ "hist-prev",             bind_hist_prev },
	{ "pass",                  bind_pass },
	{ "run",                   bind_run },
};

static struct default_wkb_setting default_wkb_settings[] = {
	{ VAR_WEBKIT_API,      WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_STRING,  get_webkit_api,      NULL,                { .s = NULL } },
	{ VAR_CMD_FIFO,        WKB_SETTING_SCOPE_WINDOW,  WKB_SETTING_TYPE_STRING,  get_cmd_fifo,        NULL,                { .s = NULL } },
	{ VAR_CONFIG_DIR,      WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_STRING,  get_config_dir,      set_config_dir,      { .s = NULL } },
	{ VAR_COOKIE_FILE,     WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_STRING,  get_cookie_file,     set_cookie_file,     { .s = NULL } },
	{ VAR_COOKIE_POLICY,   WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_STRING,  get_cookie_policy,   set_cookie_policy,   { .s = "no-third-party" } },
	{ VAR_AUTO_SCROLL,     WKB_SETTING_SCOPE_WINDOW,  WKB_SETTING_TYPE_BOOL,    get_auto_scroll,     set_auto_scroll,     { .b = TRUE } },
	{ VAR_SHOW_CONSOLE,    WKB_SETTING_SCOPE_WINDOW,  WKB_SETTING_TYPE_BOOL,    get_show_console,    set_show_console,    { .b = FALSE } },
	{ VAR_PRINT_KEYVAL,    WKB_SETTING_SCOPE_WINDOW,  WKB_SETTING_TYPE_BOOL,    get_print_keyval,    set_print_keyval,    { .b = FALSE } },
	{ VAR_ALLOW_POPUPS,    WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_BOOL,    get_allow_popups,    set_allow_popups,    { .b = TRUE } },
	{ VAR_DOWNLOAD_DIR,    WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_STRING,  get_download_dir,    set_download_dir,    { .s = NULL } },
	{ VAR_DL_OPEN_CMD,     WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_STRING,  get_dl_open_cmd,     set_dl_open_cmd,     { .s = NULL } },
	{ VAR_DL_AUTO_OPEN,    WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_BOOL,    get_dl_auto_open,    set_dl_auto_open,    { .b = FALSE } },
	{ VAR_DEFAULT_WIDTH,   WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_INT,     get_default_width,   set_default_width,   { .i = 800 } },
	{ VAR_DEFAULT_HEIGHT,  WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_INT,     get_default_height,  set_default_height,  { .i = 600 } },
#ifdef __HAVE_WEBKIT2__
	{ VAR_SPELL_LANGS,     WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_STRING,  get_spell_langs,     set_spell_langs,     { .s = NULL } },
	{ VAR_SPELL,           WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_BOOL,    get_spell,           set_spell,           { .b = FALSE } },
	{ VAR_TLS_ERRORS,      WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_BOOL,    get_tls_errors,      set_tls_errors,      { .b = TRUE } },
#endif
	{ VAR_FIND_STRING,     WKB_SETTING_SCOPE_WINDOW,  WKB_SETTING_TYPE_STRING,  get_find_string,     set_find_string,     { .s = NULL } },
	{ VAR_HOMEPAGE,        WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_STRING,  get_homepage,        set_homepage,        { .s = NULL } },
	{ VAR_CURRENT_URI,     WKB_SETTING_SCOPE_WINDOW,  WKB_SETTING_TYPE_STRING,  get_current_uri,     NULL,                { .s = NULL } },
	{ VAR_FC_DIR,          WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_STRING,  get_fc_dir,          NULL,                { .s = NULL } },
	{ VAR_FC_FILE,         WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_STRING,  get_fc_file,         NULL,                { .s = NULL } },
	{ VAR_CLIPBOARD_TEXT,  WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_STRING,  get_clipboard_text,  set_clipboard_text,  { .s = NULL } },
	{ VAR_LOAD_STARTED,    WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_STRING,  get_load_started,    set_load_started,    { .s = NULL } },
	{ VAR_DOM_READY,       WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_STRING,  get_dom_ready,       set_dom_ready,       { .s = NULL } },
	{ VAR_LOAD_FINISHED,   WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_STRING,  get_load_finished,   set_load_finished,   { .s = NULL } },
	{ VAR_CREATE,          WKB_SETTING_SCOPE_GLOBAL,  WKB_SETTING_TYPE_STRING,  get_create,          set_create,          { .s = NULL } },
};

static const gchar *builtin_config[] = {
	"bind nci - Escape run \"set-mode n\"",
	"bind a 1 Escape run \"set-mode n\"",
	"bind n - colon run \"set-mode c\"",
	"bind n - i run \"set-mode i\"",
	"bind n 1 i run \"set-mode p\"",
	"bind nci c e run \"set "VAR_SHOW_CONSOLE" !\"",
	"bind nc - Tab run \"set "VAR_SHOW_CONSOLE" !\"",
	"bind nci c s run \"set "VAR_AUTO_SCROLL" !; necho "VAR_AUTO_SCROLL"=\\{"VAR_AUTO_SCROLL"}\"",
	"bind nci c k run \"set "VAR_PRINT_KEYVAL" !; necho "VAR_PRINT_KEYVAL"=\\{"VAR_PRINT_KEYVAL"}\"",
	"bind nci c w run \"set "VAR_ALLOW_POPUPS" !; necho "VAR_ALLOW_POPUPS"=\\{"VAR_ALLOW_POPUPS"}\"",
	"bind nci c c run clear",
	"bind nci 1 l run \"switch +1\"",
	"bind nci 1 h run \"switch -1\"",
	"bind n - apostrophe run \"open-input \\\"switch \\\"\"",
	"bind n - 1 run \"switch 1\"",
	"bind n - 2 run \"switch 2\"",
	"bind n - 3 run \"switch 3\"",
	"bind n - 4 run \"switch 4\"",
	"bind n - 5 run \"switch 5\"",
	"bind n - 6 run \"switch 6\"",
	"bind n - 7 run \"switch 7\"",
	"bind n - 8 run \"switch 8\"",
	"bind n - 9 run \"switch 9\"",
	"bind n - m run last",
	"bind nci 1 m run last",
	"bind n - period run \"open-input \\\"reorder \\\"\"",
	"bind n - greater run \"reorder +1\"",
	"bind n - less run \"reorder -1\"",
	"bind n - b run \"nav -1\"",
	"bind n - H run \"nav -1\"",
	"bind n - L run \"nav +1\"",
	"bind n - r run reload",
	"bind n - R run reload!",
	"bind n - g run \"open-input \\\"nav \\\"\"",
	"bind n - x run stop",
	"bind n - d run tclose",
	"bind n - D run wclose",
	"bind n - Z run quit",
	"bind n - slash run \"open-input \\\"find \\\"\"",
	"bind n - question run \"open-input \\\"rfind \\\"\"",
	"bind n - n run find",
	"bind n - N run rfind",
	"bind n - o run \"open-input \\\"open \\\"\"",
	"bind n - O run \"eopen-input \\\"open \\{"VAR_CURRENT_URI"}\\\"\"",
	"bind n - t run \"open-input \\\"topen \\\"\"",
	"bind n - T run \"eopen-input \\\"topen \\{"VAR_CURRENT_URI"}\\\"\"",
	"bind n - w run \"open-input \\\"wopen \\\"\"",
	"bind n - W run \"eopen-input \\\"wopen \\{"VAR_CURRENT_URI"}\\\"\"",
	"bind n - plus run \"zoom +0.1\"",
	"bind n - minus run \"zoom -0.1\"",
	"bind n - equal run \"zoom 1\"",
	"bind c - Up hist-prev",
	"bind c - Down hist-next",
	"bind n - c run \"nset "VAR_CLIPBOARD_TEXT" \\\"\\{"VAR_CURRENT_URI"}\\\"\"",
	"set scroll.x 100",
	"set scroll.y 100",
	"bind n - Up run \"js window.scrollBy(0, -\\\{scroll.y})\"",
	"bind n - k run \"js window.scrollBy(0, -\\\{scroll.y})\"",
	"bind n - Down run \"js window.scrollBy(0, \\\{scroll.y})\"",
	"bind n - j run \"js window.scrollBy(0, \\\{scroll.y})\"",
	"bind n - Left run \"js window.scrollBy(-\\\{scroll.x}, 0)\"",
	"bind n - h run \"js window.scrollBy(-\\\{scroll.x}, 0)\"",
	"bind n - Right run \"js window.scrollBy(\\\{scroll.x}, 0)\"",
	"bind n - l run \"js window.scrollBy(\\\{scroll.x}, 0)\"",
	"bind n - Page_Up run \"js window.scrollBy(0, -window.innerHeight)\"",
	"bind n - Page_Down run \"js window.scrollBy(0, window.innerHeight)\"",
	"bind n c b run \"js window.scrollBy(0, -window.innerHeight)\"",
	"bind n c f run \"js window.scrollBy(0, window.innerHeight)\"",
	"bind n c u run \"js window.scrollBy(0, -window.innerHeight / 2)\"",
	"bind n c d run \"js window.scrollBy(0, window.innerHeight / 2)\"",
	"bind n s space run \"js window.scrollBy(0, -window.innerHeight / 2)\"",
	"bind n S space run \"js window.scrollBy(0, window.innerHeight / 2)\"",
	"bind n - Home run \"js window.scrollBy(0, -document.height)\"",
	"bind n - End run \"js window.scrollBy(0, document.height)\"",
	"bind n - 0 run \"js window.scrollBy(-document.width, 0)\"",
	"bind n - dollar run \"js window.scrollBy(document.width, 0)\"",
	"set XDG_CONFIG_HOME_DEFAULT \"{HOME}/.config\"",
	"nset "VAR_CONFIG_DIR" \"{XDG_CONFIG_HOME:XDG_CONFIG_HOME_DEFAULT}/wkb\"",
	"nset "VAR_DOWNLOAD_DIR" \"{HOME}\"",
	"nset "VAR_DL_OPEN_CMD" \"spawn xdg-open \\\"%f\\\"\"",
	"nset "VAR_COOKIE_FILE" \"{"VAR_CONFIG_DIR"}/cookies.txt\"",
#ifdef __HAVE_WEBKIT2__
	"add-stylesheet \"@import url('file://{"VAR_CONFIG_DIR"}/stylesheet.css');\" \"\" \"\" \"\"",
#else
	"nset s.user-stylesheet-uri \"file://{"VAR_CONFIG_DIR"}/stylesheet.css\"",
	"nset s.enable-page-cache t",
#endif
	"loadconfig config",
};
