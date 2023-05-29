/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappx     = 6;         /* gap between windows */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "FiraCode Nerd Font:style=Bold:size=8" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#dddddd";
static const char col_gray4[]       = "#ffffff";
static const char col_cyan[]        = "#005577";
//static const char urg_fg[] = "#ffffff";
//static const char urg_bg[] = "#A93744";
//static const char urg_border[] = "#A93744";

static unsigned int baralpha        = 200;
static unsigned int borderalpha     = OPAQUE;
//static const char *colors[][3]      = {
                   //fg         bg         border   
    //[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
    //[SchemeSel]  = { col_gray4, urg_bg,  urg_bg  },
    //[SchemeUrg] =  { urg_fg,    urg_bg,  urg_border },
//};
//static const char norm_fg[] = "#c0c0c0";
//static const char norm_bg[] = "#050506";
//static const char norm_border[] = "#434344";

//static const char sel_fg[] = "#c0c0c0";
//static const char sel_bg[] = "#AB6C5E";
//static const char sel_border[] = "#c0c0c0";

//static const char *colors[][3]      = {
    //[>               fg           bg         border                         <]
    //[SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    //[SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
    //[SchemeUrg] =  { urg_fg,      urg_bg,    urg_border },
//};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "Spotify",  NULL,       NULL,       8,       0,           -1 },
	{ "Brave",  NULL,       NULL,         0,            0,           -1 },
	{ "executor-vim",  NULL,       NULL,         0,            1,           -1 },
	{ "chtsh",  NULL,       NULL,         0,            1,           -1 },
	{ "notes",  NULL,       NULL,         0,            1,           -1 },
	{ "yad",  NULL,       NULL,         0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
 	{ "[@]",      spiral },
 	{ "[\\]",      dwindle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "alacritty", NULL };

// My Commands
static const char *roficmd[]  = { "rofi", "-show", "drun", NULL};
static const char *rofipasscmd[]  = { "rofi-pass", "--last-used", NULL};
static const char *browsercmd[] = { "brave", NULL };
static const char *browser_privatecmd[] = { "brave", "--incognito", NULL };
static const char *file_managercmd[]  = { "alacritty", "-e", "lf", NULL };
static const char *wallpaper_managercmd[]  = { "kitty", "-e", "ranger", NULL };
static const char *terminalcmd[]  = { "alacritty", NULL };
static const char *terminal2cmd[]  = { "alacritty", "--config-file=/home/kshitij/.config/alacritty/alacritty-nontmux.yml", NULL };
static const char *monitorcmd[]  = { "alacritty", "-e", "bpytop", NULL };
static const char *notetakercmd[]  = { "/home/kshitij/.scripts/note-taker", NULL };
static const char *notetopdfcmd[]  = { "/home/kshitij/.scripts/note-to-pdf", NULL };
static const char *scriptercmd[]  = { "/home/kshitij/.scripts/scripter", NULL };

static const char *shutdowncmd[]  = { "systemctl", "poweroff", NULL };
static const char *rebootcmd[]  = { "systemctl", "reboot", NULL };
static const char *suspendcmd[]  = { "systemctl", "suspend", NULL };

// Song cmds (PlayerCTL)
static const char *playcmd[]  = { "playerctl", "play-pause", NULL };
static const char *nextcmd[]  = { "playerctl", "next", NULL };
static const char *prevcmd[]  = { "playerctl", "previous", NULL };
static const char *forwardcmd[]  = { "playerctl", "position", "5+", NULL };
static const char *backwardcmd[]  = { "playerctl", "position", "5-", NULL };
static const char *incvolcmd[]  = { "playerctl", "volume", "0.05%+", NULL };
static const char *decvolcmd[]  = {  "playerctl", "volume", "0.05%-", NULL };

// Brightness Controls
static const char *incbricmd[]  = { "lux", "-a", "5%", NULL };
static const char *decbricmd[]  = { "lux", "-s", "5%", NULL };

// Night Light commands
static const char *nightlight[]  = { "redshift", "-O", "5000", NULL };
static const char *nonightlight[]  = { "redshift", "-x", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
    // My Shortcuts
	//{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = terminalcmd } }, // Alacritty terminal with tmux
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = terminal2cmd } }, // Non tmux alacritty
	{ MODKEY,                       XK_f,      spawn,          {.v = browsercmd } }, // Open Browser
	{ MODKEY|ShiftMask,             XK_f,      spawn,          {.v = browser_privatecmd } }, // Browser private
    { MODKEY,                       XK_q,      killclient,     {0} },
    { ControlMask,                  XK_space,  spawn,          {.v = roficmd } },
    { MODKEY,                       XK_i,      spawn,          {.v = monitorcmd} },
    { MODKEY,                       XK_n,      spawn,          {.v = notetakercmd} },
    { MODKEY|ShiftMask,             XK_n,      spawn,          {.v = notetopdfcmd} },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
    // Quit dwm
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_x,      spawn,           {.v = shutdowncmd} },
	{ MODKEY|ShiftMask,             XK_z,      spawn,           {.v = rebootcmd} },
	{ MODKEY|ShiftMask,             XK_s,      spawn,           {.v = suspendcmd} },
	{ MODKEY|ShiftMask,             XK_p,      spawn,           {.v = rofipasscmd} },
    // Audio And Brightness
	{ MODKEY|ShiftMask,             XK_Up,      spawn,           {.v = incbricmd} },
	{ MODKEY|ShiftMask,             XK_Down,      spawn,           {.v = decbricmd} },
    // Window Management
    { MODKEY,                       XK_Tab,    focusstack,     {.i = +1 } },
    // Resize master
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    // Full Screen
    { MODKEY,                       XK_z,      togglebar,      {0} },
    { MODKEY,                       XK_space,    view,           {0} },
    { MODKEY,                       XK_s,        spawn,           {.v = scriptercmd} },
    { MODKEY,                       XK_w,        spawn,           {.v = wallpaper_managercmd} },
    { MODKEY,                       XK_e,        spawn,           {.v = file_managercmd} },
    { MODKEY,                       XK_r,        spawn,           {.v = nightlight} },
	{ MODKEY|ShiftMask,             XK_r,      spawn,           {.v = nonightlight} },
    // Music Controls
	{ MODKEY|ShiftMask,             XK_Left,      spawn,           {.v = decvolcmd} },
	{ MODKEY|ShiftMask,             XK_Right,      spawn,           {.v = incvolcmd} },
	{ MODKEY|ShiftMask,             XK_m,      spawn,           {.v = playcmd} },
	{ MODKEY,                       XK_period,      spawn,           {.v = nextcmd} },
	{ MODKEY,                       XK_comma,      spawn,           {.v = prevcmd} },
	{ MODKEY|ShiftMask,             XK_period,      spawn,           {.v = forwardcmd} },
	{ MODKEY|ShiftMask,             XK_comma,      spawn,           {.v = backwardcmd} },

    // Fibonacci layout
    //{ MODKEY,                       XK_y,      setlayout,      {.v = &layouts[3]} },
    //{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[4]} },

    // Defaults removed
    //{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	//{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	//{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	//{ MODKEY,                       XK_Return, zoom,           {0} },
	//{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	//{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	//{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	//{ MODKEY,                       XK_space,  setlayout,      {0} },
	//{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	//{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	//{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	//{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	//{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	//{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	//{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

