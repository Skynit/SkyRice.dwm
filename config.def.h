/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 2;		/* border pixel of windows */
static const unsigned int gappx = 10;		/* gaps between windows */
static const unsigned int snap = 32;    	/* snap pixel */
static const unsigned int colorfultag = 1;	/* 0 means use SchemeSel for selected tag */
static const int swallowfloating = 0;		/* 1 means swallow floating windows by default */
static const int showbar = 1;        		/* 0 means no bar */
static const int topbar = 1;        		/* 0 means bottom bar */
static const int vpad = 10;					/* vertical padding of bar */
static const int hpad = 10;			    	/* horizontal padding of bar */
static const int user_bh = 0;				/* 0 means dwm calculate bar height */
static const Bool viewmontag = True;		/* switch view on tag switch */
static const char *fonts[] = { "Roboto Mono:style=bold:size=12", "Material Design Icons:style=Regular:size=15", "Font Awesome 5 Free,Font Awesome 5 Free Regular:style=Regular:size=13", "Font Awesome 5 Free,Font Awesome 5 Free Solid:style=Solid:size=13", "Font Awesome 5 Brands,Font Awesome 5 Brands Regular:style=Regular:size=13", "monospace:size=14" };
static const char dmenufont[] = "Roboto Mono:style=Regular:size=12";
static const char col_green[] = "#7cb091";
static const char col_green_light[] = "#ace2c1";
static const char col_green_dark[] = "#4e8063";
static const char col_yellow[] = "#f7ce72";
static const char col_yellow_light[] = "#ffffa2";
static const char col_yellow_dark[] = "#c29d43";
static const char col_orange[] = "#e8a165";
static const char col_orange_light[] = "#ffd294";
static const char col_orange_dark[] = "#b37239";
static const char col_purple[] = "#562c5d";
static const char col_purple_light[] = "#84578a";
static const char col_purple_dark[] = "#2b0333";
static const char col_blue_sec[] = "#292055";
static const char col_blue_sec_light[] = "#534781";
static const char col_blue_sec_dark[] = "#02002b";
static const char col_blue[] = "#527ec1";
static const char col_blue_light[] = "#85adf4";
static const char col_blue_dark[] = "#155290";
static const char col_red[] = "#ce625a";
static const char col_red_light[] = "#ff9287";
static const char col_red_dark[] = "#993331";
static const char col_black[] = "#1e2d37";
static const char col_black_light[] = "#465661";
static const char col_black_dark[] = "#000211";
static const char col_white[] = "#fefefd";
static const char col_white_light[] = "#ffffff";
static const char col_white_dark[] = "#cbcbca";
static const char col_grey[] = "#dbe1dc";
static const char col_grey_light[] = "#ffffff";
static const char col_grey_dark[] = "#a9afaa";

static const char *colors[][3] = {
	/* fg - bg - border   */
	[SchemeNorm] = { col_white_dark, col_black_dark, col_black_dark },
	[SchemeSel] = { col_red, col_black_dark,  col_red_dark },
	[SchemeTag1] = { col_red, col_black_dark,  col_black_dark },
	[SchemeTag2] = { col_orange, col_black_dark,  col_black_dark },
	[SchemeTag3] = { col_blue_light, col_black_dark,  col_black_dark },
	[SchemeTag4] = { col_green, col_black_dark,  col_black_dark },
	[SchemeTag5] = { col_purple_light, col_black_dark,  col_black_dark },
	[SchemeTag6] = { col_yellow, col_black_dark,  col_black_dark }
};

/* tagging */
static const char *tags[] = { "\uf17c", "\uf269", "\uf392", "\uf1bc", "\uf6cc", "\uf379" };
static const unsigned int ulinepad = 5;		/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke = 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset = 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall = 0;				/* 1 to show underline on all tags, 0 for just the active ones */
static const int tagscheme[] = { SchemeTag1, SchemeTag2, SchemeTag3, SchemeTag4, SchemeTag5, SchemeTag6 };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	*/
	/* class - instance - title - tags - mask- isfloating - isterminal - noswallow - monitor */
	{ "firefox", NULL, NULL, 1 << 1, False, False, -1, -1 },
	{ "discord", NULL, NULL, 1 << 2, False, False, 0, -1 },
	{ "Spotify", NULL, NULL, 1 << 3, False, False, 0, -1 },
	{ "code-oss", NULL, NULL, 1 << 4, False, False, 0, -1 },
	{ "st", NULL, NULL, 0, False, True, 0, -1 }
};

/* layout(s) */
static const float mfact = 0.55;	/* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    	/* number of clients in master area */
static const int resizehints = 0;    	/* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; 	/* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol - arrange function */
	{ "[]=", tile },    /* first entry is default */
	{ "><>", NULL },    /* no layout function means floating behavior */
	{ "[M]", monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/zsh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_black, "-nf", col_white_dark, "-sb", col_blue_dark, "-sf", col_white_light, NULL };
static const char *termcmd[] = { "st", NULL };
static const char *xbacklight_increase[] = { "xbacklight", "-inc", "5%", NULL };
static const char *xbacklight_decrease[] = { "xbacklight", "-dec", "5%", NULL };
static const char *pulsemixer_increase[] = { "pulsemixer", "--change-volume", "+5", NULL };
static const char *pulsemixer_decrease[] = { "pulsemixer", "--change-volume", "-5", NULL };
static const char *pulsemixer_mute[] = { "pulsemixer", "--toggle-mute", NULL };

static Key keys[] = {
	/* modifier - key - function - argument */
	{ MODKEY, XK_p, spawn, {.v = dmenucmd } },
	{ MODKEY|ShiftMask, XK_Return, spawn, {.v = termcmd } },
	{ 0, 0x1008ff02, spawn, {.v = xbacklight_increase } },
	{ 0, 0x1008ff03, spawn, {.v = xbacklight_decrease } },
	{ 0, 0x1008ff13, spawn, {.v = pulsemixer_increase } },
	{ 0, 0x1008ff11, spawn, {.v = pulsemixer_decrease } },
	{ 0, 0x1008ff12, spawn, {.v = pulsemixer_mute } },
	{ MODKEY, XK_b, togglebar, {0} },
	{ MODKEY, XK_j, focusstack, {.i = +1 } },
	{ MODKEY, XK_h, focusstack, {.i = -1 } },
	{ MODKEY, XK_i, incnmaster, {.i = +1 } },
	{ MODKEY, XK_d, incnmaster, {.i = -1 } },
	{ MODKEY, XK_k, setmfact, {.f = -0.05} },
	{ MODKEY, XK_l, setmfact, {.f = +0.05} },
	{ MODKEY, XK_Return, zoom, {0} },
	{ MODKEY, XK_Tab, view, {0} },
	{ MODKEY|ShiftMask, XK_c, killclient, {0} },
	{ MODKEY, XK_t, setlayout, {.v = &layouts[0]} },
	{ MODKEY, XK_f, setlayout, {.v = &layouts[1]} },
	{ MODKEY, XK_m, setlayout, {.v = &layouts[2]} },
	{ MODKEY, XK_space, setlayout, {0} },
	{ MODKEY|ShiftMask, XK_space, togglefloating, {0} },
	{ MODKEY, XK_KP_Insert, view, {.ui = ~0 } },
	{ MODKEY|ShiftMask, XK_KP_Insert, tag, {.ui = ~0 } },
	{ MODKEY, XK_comma, focusmon, {.i = -1 } },
	{ MODKEY, XK_semicolon, focusmon, {.i = +1 } },
	{ MODKEY|ShiftMask, XK_comma, tagmon, {.i = -1 } },
	{ MODKEY|ShiftMask, XK_semicolon, tagmon, {.i = +1 } },
	{ MODKEY, XK_KP_Subtract, setgaps, {.i = -1 } },
	{ MODKEY, XK_KP_Add, setgaps, {.i = +1 } },
	{ MODKEY, XK_KP_Multiply, setgaps, {.i = 0  } },
	TAGKEYS(XK_KP_End, 0)
	TAGKEYS(XK_KP_Down, 1)
	TAGKEYS(XK_KP_Next, 2)
	TAGKEYS(XK_KP_Left, 3)
	TAGKEYS(XK_KP_Begin, 4)
	TAGKEYS(XK_KP_Right, 5)
	{ MODKEY|ShiftMask, XK_q, quit, {0} }
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click - event mask - button - function - argument */
	{ ClkLtSymbol, 0, Button1, setlayout, {0} },
	{ ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]} },
	{ ClkWinTitle, 0, Button2, zoom, {0} },
	{ ClkStatusText, 0, Button2, spawn, {.v = termcmd } },
	{ ClkClientWin, MODKEY, Button1, movemouse, {0} },
	{ ClkClientWin, MODKEY, Button2, togglefloating, {0} },
	{ ClkClientWin, MODKEY, Button3, resizemouse, {0} },
	{ ClkTagBar, 0, Button1, view, {0} },
	{ ClkTagBar, 0, Button3, toggleview, {0} },
	{ ClkTagBar, MODKEY, Button1, tag, {0} },
	{ ClkTagBar, MODKEY, Button3, toggletag, {0} },
};
