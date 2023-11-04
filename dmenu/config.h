static char font[]   = "monospace:size=10";
static char *fonts[] = {font, "monospace:size=10"};
static char normfgcolor[]     = "#bbbbbb";
static char normbgcolor[]     = "#222222";
static char selfgcolor[]      = "#eeeeee";
static char selbgcolor[]      = "#005577";
static char outfgcolor[]      = "#000000";
static char outbgcolor[]      = "#00ffff";
static char highnormfgcolor[] = "#ffc978";
static char highnormbgcolor[] = "#005577";
static char highselfgcolor[]  = "#ffc978";
static char highselbgcolor[]  = "#222222";
static char *colors[SchemeLast][2] = {
	[SchemeNorm]          = { normfgcolor,     normbgcolor     },
	[SchemeSel]           = { selfgcolor,      selbgcolor      },
	[SchemeOut]           = { outfgcolor,      outbgcolor      },
	[SchemeSelHighlight]  = { highnormfgcolor, highnormbgcolor },
	[SchemeNormHighlight] = { highselfgcolor,  highselbgcolor  },
};

ResourcePref resources[] = {
	{ "font",            STRING, &font            },
	{ "normfgcolor",     STRING, &normfgcolor     },
	{ "normbgcolor",     STRING, &normbgcolor     },
	{ "selfgcolor",      STRING, &selfgcolor      },
	{ "selbgcolor",      STRING, &selbgcolor      },
	{ "outfgcolor",      STRING, &outfgcolor      },
	{ "outbgcolor",      STRING, &outbgcolor      },
    { "highnormfgcolor", STRING, &highnormfgcolor },
    { "highnormbgcolor", STRING, &highnormbgcolor },
    { "highselfgcolor",  STRING, &highselfgcolor  },
    { "highselbgcolor",  STRING, &highselbgcolor  }
};

/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines = 0;
static int topbar         = 1;
static int fuzzy          = 1;
static char *prompt       = NULL;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";