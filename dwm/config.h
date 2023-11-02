static const unsigned int borderpx = 1;
static const unsigned int snap     = 4;
static char font[]                 = "monospace:size=10";
static const char *fonts[]         = {font, "monospace:size=10"};
static char normfgcolor[]          = "#bbbbbb";
static char normbgcolor[]          = "#222222";
static char normbordercolor[]      = "#444444";
static char selfgcolor[]           = "#eeeeee";
static char selbgcolor[]           = "#005577";
static char selbordercolor[]       = "#005577";
static char *colors[][3]           = {
	[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
	[SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor },
};

ResourcePref resources[] = {
		{ "font",            STRING, &font            },
		{ "normfgcolor",     STRING, &normfgcolor     },
		{ "normbgcolor",     STRING, &normbgcolor     },
		{ "normbordercolor", STRING, &normbordercolor },
		{ "selfgcolor",      STRING, &selfgcolor      },
		{ "selbgcolor",      STRING, &selbgcolor      },
		{ "selbordercolor",  STRING, &selbordercolor  }
};
 

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
};

static const int showbar        = 1;
static const int topbar         = 1;
static const char *tags[]       = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const float mfact        = 0.5; // factor of master area size [0.05..0.95]
static const int nmaster        = 1;   // number of clients in master area
static const int resizehints    = 0;   // 1 means respect size hints in tiled resizals
static const int lockfullscreen = 1;   // 1 will force focus on the fullscreen window

static const Layout layouts[] = {
	{ "[]=", tile },
	{ "[]#", deck }
};


/* commands */
#define SCRIPT_PATH "/home/tx/Scripts"
static const char *dmenucmd[]              = { "dmenu_run", NULL };
static const char *termcmd[]               = { "st", NULL };
static const char *screenshotcmd[]         = { "flameshot", "gui", NULL };
static const char *scratchpadcmd[]         = { "st", "-g", "120x34", NULL }; // TODO: scratch size
static const char *refreshlanguagescript[] = { SCRIPT_PATH"/status_bar.js", "refresh", "language", NULL };
static const char *shutdownscript[]        = { SCRIPT_PATH"/shutdown_menu.sh", NULL };
static const char *togglemicscript[]       = { SCRIPT_PATH"/toggle_mic.sh", NULL };
static const char *incrvolumescript[]      = { SCRIPT_PATH"/incr_volume.sh", NULL };
static const char *decrvolumescript[]      = { SCRIPT_PATH"/decr_volume.sh", NULL };

/* key definitions */
#define ALTKEY Mod1Mask
#define SUPERKEY Mod4Mask
#define MODKEY ALTKEY
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,              KEY, view,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,  KEY, toggleview, {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,    KEY, tag,        {.ui = 1 << TAG} },

#include "movestack.c"
static const Key keys[] = {
	{ MODKEY,                XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,      XK_Return, spawn,          {.v = termcmd } },
    { MODKEY,                XK_grave,  togglescratch,  {.v = scratchpadcmd } },
     // TODO: scripts
	{ MODKEY,                XK_j,      focusstack,     {.i = +1 } }, // TODO: what
	{ MODKEY,                XK_k,      focusstack,     {.i = -1 } }, // TODO: what
	{ MODKEY,                XK_h,      setmfact,       {.f = -0.1} },
	{ MODKEY,                XK_l,      setmfact,       {.f = +0.1} },
	{ MODKEY|ShiftMask,      XK_j,      movestack,      {.i = +1 } }, // TODO: what
	{ MODKEY|ShiftMask,      XK_k,      movestack,      {.i = -1 } }, // TODO: what
	{ MODKEY,                XK_Return, zoom,           {0} }, // TODO: what
	{ MODKEY,                XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,      XK_c,      killclient,     {0} },
	{ MODKEY,                XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                XK_g,      setlayout,      {.v = &layouts[1]} }
	{ MODKEY,                XK_space,  setlayout,      {0} }, // TODO: what
	{ MODKEY|ShiftMask,      XK_space,  togglefloating, {0} },
	{ MODKEY,                XK_0,      view,           {.ui = ~0 } }, // TODO: what
	{ MODKEY|ShiftMask,      XK_0,      tag,            {.ui = ~0 } }, // TODO: what
	{ MODKEY,                XK_comma,  focusmon,       {.i = -1 } }, // TODO: what
	{ MODKEY,                XK_period, focusmon,       {.i = +1 } }, // TODO: what
	{ MODKEY|ShiftMask,      XK_comma,  tagmon,         {.i = -1 } }, // TODO: what
	{ MODKEY|ShiftMask,      XK_period, tagmon,         {.i = +1 } }, // TODO: what
	TAGKEYS(                 XK_1,                      0)
	TAGKEYS(                 XK_2,                      1)
	TAGKEYS(                 XK_3,                      2)
	TAGKEYS(                 XK_4,                      3)
	TAGKEYS(                 XK_5,                      4)
	TAGKEYS(                 XK_6,                      5)
	TAGKEYS(                 XK_7,                      6)
	TAGKEYS(                 XK_8,                      7)
	TAGKEYS(                 XK_9,                      8)
	{ MODKEY|ShiftMask,      XK_q,      quit,           {0} }
};

/* ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} }
};