#ifndef _IN_TYPES_H
#define _IN_TYPES_H
#include <ultra64.h>
#include "constants.h"
#include "gbiex.h"
#include "lang.h"
#include "pads.h"

#define bool s32
#define ubool u32

// Float version of a graphics matrix, which has higher precision than an Mtx.
// Matrices are stored as Mtxfs then converted to an Mtx when passed to the GPU.
// Mtxs use a union and a long long int to force alignments. Mtxfs are not
// aligned but still use the union for consistency with Mtx.
typedef union {
	f32 m[4][4];
	s32 unused;
} Mtxf;

// This hacky structure allows coords to be accessed using
// coord->x, coord->y and coord->z, but also as
// coord->f[0], coord->f[1] and coord->f[2].
// In some places code only matches when using the float array.
struct coord {
	union {
		struct {
			f32 x;
			f32 y;
			f32 z;
		};
		f32 f[3];
	};
};

struct bbox {
	f32 xmin;
	f32 xmax;
	f32 ymin;
	f32 ymax;
	f32 zmin;
	f32 zmax;
};

struct propstate {
	/*0x00*/ u16 propcount;
	/*0x02*/ u16 chrpropcount;
	/*0x04*/ u16 foregroundpropcount;
	/*0x06*/ u16 foregroundchrpropcount;
	/*0x08*/ s32 updatetime;
	/*0x0c*/ s32 chrupdatetime;
	/*0x10*/ s32 slotupdate240;
	/*0x14*/ s32 slotupdate60error;
	/*0x18*/ u16 lastupdateframe;
};

struct playerstats {
	/*0x00*/ u32 shotcount[7];
	/*0x1c*/ s32 killcount;
	/*0x20*/ u32 ggkillcount;
	/*0x24*/ u32 kills[4];
	/*0x34*/ u32 drawplayercount;
	/*0x38*/ f32 distance;
	/*0x3c*/ u32 backshotcount;
	/*0x40*/ f32 armourcount;
	/*0x44*/ s32 fastest2kills;
	/*0x48*/ s32 slowest2kills;
	/*0x4c*/ s32 longestlife;
	/*0x50*/ s32 shortestlife;
	/*0x54*/ u32 maxkills;
	/*0x58*/ s32 maxsimulkills;
	/*0x5c*/ f32 damagescale; // of received damage
	/*0x60*/ s32 tokenheldtime;
	/*0x64*/ u32 unk64;
	/*0x68*/ u32 cloaktime;
	/*0x6c*/ u32 speedpillcount;

	// Temporary hack
	union {
	/*0x70*/ s32 mpindex;
	/*0x70*/ u32 mpindexu32;
	};

	/*0x74*/ f32 scale_bg2gfx;
	/*0x78*/ f32 damreceived;
	/*0x7c*/ f32 damtransmitted;
};

struct fileguid {
	s32 fileid;
	u16 deviceserial;
};

struct g_vars {
	/*000000*/ s32 diffframe60;
	/*000004*/ f32 diffframe60f;
	/*000008*/ s32 lvframe60;
	/*00000c*/ s32 lvframenum; // increments by 1 each frame when not paused
	/*000010*/ f32 diffframe60freal;
	/*000014*/ s32 lastframetime;
	/*000018*/ s32 thisframetime;
	/*00001c*/ s32 thisframeticks;
	/*000020*/ s32 lostframetime;
	/*000024*/ s32 lostframetime240;
	/*000028*/ u32 mininc60;
	/*00002c*/ s32 roomportalrecursionlimit;
	/*000030*/ s32 lvframe240;
	/*000034*/ s32 lvupdate240; // 0 = paused, 4 = slowmo, 8 = normal
	/*000038*/ s32 lvupdate240_60;
	/*00003c*/ s32 lvupdate240_60error;
	/*000040*/ s32 diffframe240;
	/*000044*/ f32 lvupdate240f;
	/*000048*/ f32 diffframe240f;
	/*00004c*/ f32 lvupdate240freal; // actually a 60 value?
	/*000050*/ f32 lvupdate240frealprev;
	/*000054*/ s32 lastframe240;
	/*000058*/ s32 thisframe240;
	/*00005c*/ f32 diffframe240freal;
	/*000060*/ s16 *waypointnums; // ordered by room asc, padnum asc
	/*000064*/ struct player *players[4];
	/*000074*/ struct playerstats playerstats[4];
	/*000274*/ u32 playerorder[4];
	/*000284*/ struct player *currentplayer;
	/*000288*/ struct playerstats *currentplayerstats;
	/*00028c*/ s32 currentplayernum; // 0-3 - controller numbers I think
	/*000290*/ s32 currentplayerindex; // 0-3 - but 2 or 3 probably only used in combat simulator
	/*000294*/ s32 bondplayernum;
	/*000298*/ s32 coopplayernum;
	/*00029c*/ s32 antiplayernum;
	/*0002a0*/ struct player *bond; // Joanna
	/*0002a4*/ struct player *coop; // Co-op buddy when controlled by human
	/*0002a8*/ struct player *anti; // Counter-op
	/*0002ac*/ s32 tickmode;
	/*0002b0*/ s32 killcount;
	/*0002b4*/ u32 knockoutcount;
	/*0002b8*/ struct textoverride *textoverrides;
	/*0002bc*/ s32 roomcount;
	/*0002c0*/ u32 hitboundscount;
	/*0002c4*/ u32 unk0002c4;
	/*0002c8*/ u32 unk0002c8;
	/*0002cc*/ u32 unk0002cc;
	/*0002d0*/ u32 unk0002d0;
	/*0002d4*/ u32 unk0002d4;
	/*0002d8*/ u32 unk0002d8;
	/*0002dc*/ u32 unk0002dc;
	/*0002e0*/ u32 unk0002e0;
	/*0002e4*/ u32 unk0002e4;
	/*0002e8*/ u32 unk0002e8;
	/*0002ec*/ u32 unk0002ec;
	/*0002f0*/ u32 unk0002f0;
	/*0002f4*/ u32 unk0002f4;
	/*0002f8*/ u32 unk0002f8;
	/*0002fc*/ u32 unk0002fc;
	/*000300*/ u32 unk000300;
	/*000304*/ u32 unk000304;
	/*000308*/ u32 unk000308;
	/*00030c*/ u32 unk00030c;
	/*000310*/ u32 unk000310;
	/*000314*/ u32 mplayerisrunning;     // combat sim with any number of players, coop with human buddy, and counter-op
	/*000318*/ u32 normmplayerisrunning; // combat sim with any number of players
	/*00031c*/ s32 lvmpbotlevel;
	/*000320*/ s32 lockscreen;
	/*000324*/ bool bondvisible;
	/*000328*/ bool bondcollisions;
	/*00032c*/ bool enableslopes;
	/*000330*/ u32 padrandomroutes;
	/*000334*/ s32 maxprops;
	/*000338*/ struct prop *props; // pointer to array of structs
	/*00033c*/ struct prop *activeprops; // head of a doubly linked list
	/*000340*/ struct prop *activepropstail; // next pointer points to pausedprops
	/*000344*/ struct prop *freeprops; // head of a singularly linked list
	/*000348*/ struct prop **onscreenprops; // sorted by distance, furthest first
	/*00034c*/ struct prop **endonscreenprops;
	/*000350*/ s32 numonscreenprops;
	/*000354*/ struct prop *pausedprops; // head of a doubly linked list, prev pointer points to activepropstail
	/*000358*/ u8 numpropstates;
	/*000359*/ u8 allocstateindex;
	/*00035a*/ u8 runstateindex;
	/*00035b*/ u8 alwaystick;
	/*00035c*/ u16 updateframe;
	/*00035e*/ u16 prevupdateframe;
	/*000360*/ struct propstate propstates[7];
	/*000424*/ struct chrdata *chrdata;
	/*000428*/ struct truckobj *truck;
	/*00042c*/ struct heliobj *heli;
	/*000430*/ struct chopperobj *hovercar;
	/*000434*/ u8 *ailist;
	/*000438*/ u32 aioffset;
	/*00043c*/ u32 unk00043c;
	/*000440*/ s32 antiheadnum;
	/*000444*/ s32 antibodynum;
	/*000448*/ s32 coopradaron;
	/*00044c*/ s32 antiradaron;
	/*000450*/ s32 pendingantiplayernum;
	/*000454*/ s32 coopfriendlyfire;
	/*000458*/ u32 modifiedfiles;
	/*00045c*/ s32 speedpilltime; // in time60
	/*000460*/ s32 speedpillchange;
	/*000464*/ u32 speedpillwant;
	/*000468*/ bool speedpillon;
	/*00046c*/ s32 restartlevel;
	/*000470*/ s32 perfectbuddynum;
	/*000474*/ s32 numaibuddies;
	/*000478*/ bool aibuddiesspawned;
	/*00047c*/ s32 bossfileid;
	/*000480*/ u16 bossdeviceserial;
	/*000482*/ u16 unk000482;
	/*000484*/ s32 mphilltime;
	/*000488*/ s32 totalkills;
	/*00048c*/ u32 unk00048c;

	// 1 when entering game setup
	// 2 when entering combat simulator
	// 3 when entering Quick Go
	/*000490*/ s32 unk000490;

	/*000494*/ s8 unk000494[4];
	/*000498*/ s32 unk000498;
	/*00049c*/ s32 unk00049c;
	/*0004a0*/ s32 unk0004a0;
	/*0004a4*/ s32 mpquickteamnumsims;
	/*0004a8*/ s32 mpsimdifficulty;
	/*0004ac*/ s8 mpplayerteams[4];
	/*0004b0*/ u32 mpquickteam;
	/*0004b4*/ s32 stagenum;
	/*0004b8*/ struct prop *aibuddies[4];
	/*0004c8*/ u32 dontplaynrg; // allow X music to be played (NRG = energy track)
	/*0004cc*/ s32 in_cutscene;
	/*0004d0*/ u8 paksconnected;
	/*0004d1*/ u8 paksconnected2;
	/*0004d2*/ s8 autocutnum; // cutscene scene number (0, 1 or 2), set to -1 while loading cutscene
	/*0004d3*/ s8 autocutplaying; // true if playing a cutscene via the menu, false when a button is pressed
	/*0004d4*/ s8 autocutgroupcur; // index into g_Cutscenes
	/*0004d5*/ s8 autocutgroupleft; // number of cutscenes left to play
	/*0004d6*/ s8 autocutfinished; // true if cutscene reached natural end
	/*0004d7*/ s8 autocutgroupskip; // true if pressed start during auto cutscene
	/*0004d8*/ s32 joydisableframestogo;
	/*0004dc*/ u8 playertojoymap[4];
	/*0004e0*/ u8 fourmeg2player;
	/*0004e1*/ u8 remakewallhitvtx;
	/*0004e2*/ u8 cutsceneskip60ths;
	/*0004e3*/ u8 langfilteron;

	// 000f = Counter: if 10-15 then ticks down 1 per 7 frames, if under 10 then 1 per frame.
	// 00f0 = One bit per pak. Does something with the pak if counter expired.
	// 0f00 = One bit per pak. Does something with the pak if counter expired (likely opposite of the above).
	/*0004e4*/ u16 unk0004e4;

	/*0004e8*/ u32 unk0004e8;
	/*0004ec*/ u32 unk0004ec;
	/*0004f0*/ u32 unk0004f0;
	/*0004f4*/ u32 unk0004f4;
	/*0004f8*/ u32 unk0004f8;
	/*0004fc*/ u32 unk0004fc;
	/*0004e0*/ u32 unk000500;
	/*000504*/ u32 unk000504;
	/*000508*/ u32 unk000508;
	/*00050c*/ u32 unk00050c;
	/*000510*/ f32 unk000510;
	/*000514*/ u32 unk000514;
	/*000518*/ u32 unk000518;
	/*00051c*/ u32 unk00051c;
	/*000520*/ u32 unk000520;
	/*000524*/ u32 unk000524;
	/*000528*/ u32 unk000528;
	/*00052c*/ u32 unk00052c;
	/*000530*/ u32 unk000530;
	/*000534*/ u32 unk000534;
	/*000538*/ u32 unk000538;
	/*00053c*/ u32 unk00053c;
	/*000540*/ u32 unk000540;
	/*000544*/ u32 unk000544;
	/*000548*/ u32 unk000548;
	/*00054c*/ u32 unk00054c;
	/*000550*/ u32 unk000550;
	/*000554*/ u32 unk000554;
	/*000558*/ u32 unk000558;
	/*00055c*/ u32 unk00055c;
	/*000560*/ u32 unk000560;
	/*000564*/ u32 unk000564;
	/*000568*/ u32 unk000568;
	/*00056c*/ u32 unk00056c;
	/*000570*/ u32 unk000570;
	/*000574*/ u32 unk000574;
	/*000578*/ u32 unk000578;
	/*00057c*/ u32 unk00057c;
	/*000580*/ u32 unk000580;
	/*000584*/ u32 unk000584;
	/*000588*/ u32 unk000588;
	/*00058c*/ u32 unk00058c;
	/*000590*/ u32 unk000590;
	/*000594*/ u32 unk000594;
	/*000598*/ u32 unk000598;
	/*00059c*/ u32 unk00059c;
	/*0005a0*/ u32 unk0005a0;
	/*0005a4*/ u32 unk0005a4;
	/*0005a8*/ u32 unk0005a8;
	/*0005ac*/ u32 unk0005ac;
	/*0005b0*/ u32 unk0005b0;
	/*0005b4*/ u32 unk0005b4;
	/*0005b8*/ u32 unk0005b8;
	/*0005bc*/ u32 unk0005bc;
	/*0005c0*/ u32 unk0005c0;
	/*0005c4*/ u32 unk0005c4;
	/*0005c8*/ u32 unk0005c8;
	/*0005cc*/ u32 unk0005cc;
	/*0005d0*/ u32 unk0005d0;
	/*0005d4*/ u32 unk0005d4;
	/*0005d8*/ u32 unk0005d8;
	/*0005dc*/ u32 unk0005dc;
	/*0005e0*/ u32 unk0005e0;
	/*0005e4*/ u32 unk0005e4;
	/*0005e8*/ u32 unk0005e8;
	/*0005ec*/ u32 unk0005ec;
	/*0005f0*/ u32 unk0005f0;
	/*0005f4*/ u32 unk0005f4;
	/*0005f8*/ u32 unk0005f8;
	/*0005fc*/ u32 unk0005fc;
	/*000600*/ u32 unk000600;
	/*000604*/ u32 unk000604;
	/*000608*/ u32 unk000608;
	/*00060c*/ u32 unk00060c;
	/*000610*/ u32 unk000610;
	/*000614*/ u32 unk000614;
	/*000618*/ u32 unk000618;
	/*00061c*/ u32 unk00061c;
	/*000620*/ u32 unk000620;
	/*000624*/ u32 unk000624;
	/*000628*/ u32 unk000628;
	/*00062c*/ u32 unk00062c;
	/*000630*/ u32 unk000630;
	/*000634*/ u32 unk000634;
	/*000638*/ u32 unk000638;
	/*00063c*/ u32 unk00063c;
	/*000640*/ u32 unk000640;
	/*000644*/ u32 unk000644;
	/*000648*/ u32 unk000648;
	/*00064c*/ u32 unk00064c;
	/*000650*/ u32 unk000650;
	/*000654*/ u32 unk000654;
	/*000658*/ u32 unk000658;
	/*00065c*/ u32 unk00065c;
	/*000660*/ u32 unk000660;
	/*000664*/ u32 unk000664;
	/*000668*/ u32 unk000668;
	/*00066c*/ u32 unk00066c;
	/*000670*/ u32 unk000670;
	/*000674*/ u32 unk000674;
	/*000678*/ u32 unk000678;
	/*00067c*/ u32 unk00067c;
	/*000680*/ u32 unk000680;
	/*000684*/ u32 unk000684;
	/*000688*/ u32 unk000688;
	/*00068c*/ u32 unk00068c;
	/*000690*/ u32 unk000690;
	/*000694*/ u32 unk000694;
	/*000698*/ u32 unk000698;
	/*00069c*/ u32 unk00069c;
	/*0006a0*/ u32 unk0006a0;
	/*0006a4*/ u32 unk0006a4;
	/*0006a8*/ u32 unk0006a8;
	/*0006ac*/ u32 unk0006ac;
	/*0006b0*/ u32 unk0006b0;
	/*0006b4*/ u32 unk0006b4;
	/*0006b8*/ u32 unk0006b8;
	/*0006bc*/ u32 unk0006bc;
	/*0006c0*/ u32 unk0006c0;
	/*0006c4*/ u32 unk0006c4;
	/*0006c8*/ u32 unk0006c8;
	/*0006cc*/ u32 unk0006cc;
	/*0006d0*/ u32 unk0006d0;
	/*0006d4*/ u32 unk0006d4;
	/*0006d8*/ u32 unk0006d8;
	/*0006dc*/ u32 unk0006dc;
	/*0006e0*/ u32 unk0006e0;
	/*0006e4*/ u32 unk0006e4;
	/*0006e8*/ u32 unk0006e8;
	/*0006ec*/ u32 unk0006ec;
	/*0006f0*/ u32 unk0006f0;
	/*0006f4*/ u32 unk0006f4;
	/*0006f8*/ u32 unk0006f8;
	/*0006fc*/ u32 unk0006fc;
	/*000700*/ u32 unk000700;
	/*000704*/ u32 unk000704;
	/*000708*/ u8 unk000708[0x1a8];
};

struct weaponobj;
struct prop;
struct explosion;

/**
 * Most, if not all, entity types (chrs, objs, weapons etc) have a pointer to a
 * prop struct. The struct contains properties that most entities have in
 * common such as coords and a room number. You can think of it as generic
 * entity.
 *
 * The type field indicates what type it is (chr, obj etc) and the entity
 * pointer points back to the proper entity struct.
 */
struct prop {
	/*0x00*/ u8 type;
	/*0x01*/ u8 flags;
	/*0x02*/ s16 timetoregen; // ticks down

	/*0x04*/
	union {
		struct chrdata *chr;
		struct defaultobj *obj;
		struct doorobj *door;
		struct weaponobj *weapon;
		struct explosion *explosion;
		struct smoke *smoke;
	};

	/*0x08*/ struct coord pos;
	/*0x14*/ f32 z;
	/*0x18*/ struct prop *parent;
	/*0x1c*/ struct prop *child;
	/*0x20*/ struct prop *next;
	/*0x24*/ struct prop *prev;
	/*0x28*/ s16 rooms[8];
	/*0x38*/ u16 lastupdateframe;
	/*0x3a*/ u16 propupdate240;
	/*0x3c*/ u8 propupdate60err;
	/*0x3d*/ u8 propstateindex;
	/*0x3e*/ u8 backgroundedframes;
	/*0x3f*/ u8 forceonetick : 1;
	/*0x3f*/ u8 backgrounded : 1;
	/*0x3f*/ u8 forcetick : 1;
	/*0x3f*/ u8 active : 1;
	/*0x40*/ struct var800a41b0 *unk40;
	/*0x44*/ struct var800a41b0 *unk44;
};

struct packedpad {
	s32 flags : 18;
	s32 room : 10;
	s32 liftnum : 4;
};

struct pad {
	/*0x00*/ struct coord pos;
	/*0x0c*/ struct coord look;
	/*0x18*/ struct coord up;
	/*0x24*/ struct coord normal;
	/*0x30*/ struct bbox bbox;
	/*0x48*/ s32 room;
	/*0x4c*/ u32 flags;
	/*0x50*/ u8 liftnum; // 1-10, 0 indicates no lift
	/*0x52*/ s16 unk52;
};

union filedataptr {
	u8 *u8;
	u32 *u32;
};

struct attackanimconfig {
	/*0x00*/ s16 animnum;
	/*0x04*/ f32 unk04;
	/*0x08*/ f32 unk08;
	/*0x0c*/ f32 unk0c;
	/*0x10*/ f32 unk10; // frame number
	/*0x14*/ f32 unk14; // frame number
	/*0x18*/ f32 unk18; // frame number
	/*0x1c*/ f32 unk1c; // frame number
	/*0x20*/ f32 unk20; // frame number
	/*0x24*/ f32 unk24; // frame number
	/*0x28*/ f32 unk28; // frame number
	/*0x2c*/ f32 unk2c; // frame number
	/*0x30*/ f32 unk30;
	/*0x34*/ f32 unk34;
	/*0x38*/ f32 unk38;
	/*0x3c*/ f32 unk3c;
	/*0x40*/ f32 unk40;
	/*0x44*/ f32 unk44;
};

struct model;

struct anim {
	/*0x00*/ s16 animnum;
	/*0x02*/ s16 animnum2;
	/*0x04*/ u8 unk04;
	/*0x05*/ u8 unk05;
	/*0x06*/ u8 unk06;
	/*0x07*/ u8 unk07;
	/*0x08*/ s8 flip;
	/*0x09*/ s8 flip2;
	/*0x0a*/ s8 looping;
	/*0x0b*/ s8 average;
	/*0x0c*/ f32 frame;
	/*0x10*/ f32 frac;
	/*0x14*/ s16 framea;
	/*0x16*/ s16 frameb;
	/*0x18*/ f32 endframe;
	/*0x1c*/ f32 speed;
	/*0x20*/ f32 newspeed;
	/*0x24*/ f32 oldspeed;
	/*0x28*/ f32 timespeed;
	/*0x2c*/ f32 elapsespeed;
	/*0x30*/ f32 frame2;
	/*0x34*/ f32 frac2;
	/*0x38*/ s16 frame2a;
	/*0x3a*/ s16 frame2b;
	/*0x3c*/ f32 endframe2;
	/*0x40*/ f32 speed2;
	/*0x44*/ f32 newspeed2;
	/*0x48*/ f32 oldspeed2;
	/*0x4c*/ f32 timespeed2;
	/*0x50*/ f32 elapsespeed2;
	/*0x54*/ f32 fracmerge;
	/*0x58*/ f32 timemerge;
	/*0x5c*/ f32 elapsemerge;
	/*0x60*/ f32 loopframe;
	/*0x64*/ f32 loopmerge;
	/*0x68*/ void (*flipfunc)(void);
	/*0x6c*/ u32 unk6c;
	/*0x70*/ bool (*unk70)(struct model *model, struct coord *arg1, struct coord *arg2, f32 *ground);
	/*0x74*/ f32 playspeed;
	/*0x78*/ f32 newplay;
	/*0x7c*/ f32 oldplay;
	/*0x80*/ f32 timeplay;
	/*0x84*/ f32 elapseplay;
	/*0x88*/ f32 animscale;
};

struct modeltype {
	s16 type;
	u16 numthings;
	u16 *things;
};

struct modelrodata_chrinfo { // type 0x01
	u16 unk00;
	s16 mtxindex;
	f32 unk04;
	u16 rwdataindex;
};

struct modelrodata_position { // type 0x02
	struct coord pos;
	u16 part;
	s16 pieces[3];
	f32 drawdist;
};

struct modelrodata_gundl { // type 0x04
	Gfx *primary;
	Gfx *secondary;
	void *baseaddr;
	void *unk0c;
	u16 unk10;
	s16 unk12;
};

struct modelrodata_distance { // type 0x08
	f32 near;
	f32 far;
	struct modelnode *target;
	u16 rwdataindex;
};

struct modelrodata_reorder { // type 0x09
	f32 unk00;
	f32 unk04;
	f32 unk08;
	f32 unk0c[3];
	struct modelnode *unk18;
	struct modelnode *unk1c;
	s16 unk20;
	u16 rwdataindex;
};

struct modelrodata_bbox { // type 0x0a
	s32 hitpart;
	f32 xmin;
	f32 xmax;
	f32 ymin;
	f32 ymax;
	f32 zmin;
	f32 zmax;
};

struct modelrodata_type0b { // type 0x0b
	u32 unk00;
	u32 unk04;
	u32 unk08;
	u32 unk0c;
	u32 unk10;
	u32 unk14;
	u32 unk18;
	u32 unk1c;
	u32 unk20;
	u32 unk24;
	u32 unk28;
	u32 unk2c;
	u32 unk30;
	u32 unk34;
	u32 unk38;
	void *unk3c;
	u32 unk40;
	u16 rwdataindex;
	void *baseaddr;
};

struct modelrodata_gunfire { // type 0x0c
	struct coord pos;
	struct coord dim;
	struct modeltexture *texture;
	f32 unk1c;
	u16 rwdataindex;
	void *baseaddr;
};

struct modelrodata_type0d { // type 0x0d
	u32 unk00;
	u32 unk04;
	u32 unk08;
	u32 unk0c;
	void *unk10;
	void *unk14;
	u32 unk18;
	void *baseaddr;
};

struct modelrodata_type11 { // type 0x11
	u32 unk00;
	u32 unk04;
	u32 unk08;
	u32 unk0c;
	u32 unk10;
	void *unk14;
};

struct modelrodata_toggle { // type 0x12
	struct modelnode *target;
	u16 rwdataindex;
};

struct modelrodata_positionheld { // type 0x15
	struct coord pos;
	s16 unk0c;
};

struct modelrodata_type16 { // type 0x16
	u32 unk00;
	void *unk04;
	Gfx *unk08;
	void *baseaddr;
};

struct modelrodata_headspot { // type 0x17
	u16 rwdataindex;
};

struct modelrodata_dl { // type 0x18
	/*0x00*/ Gfx *primary;
	/*0x04*/ Gfx *secondary;
	/*0x08*/ u32 *colourtable;
	/*0x0c*/ struct gfxvtx *vertices;
	/*0x10*/ s16 numvertices;
	/*0x12*/ s16 mcount;
	/*0x14*/ u16 rwdataindex;
	/*0x16*/ u16 numcolours;
};

union modelrodata {
	struct modelrodata_chrinfo chrinfo;
	struct modelrodata_position position;
	struct modelrodata_gundl gundl;
	struct modelrodata_distance distance;
	struct modelrodata_reorder reorder;
	struct modelrodata_bbox bbox;
	struct modelrodata_type0b type0b;
	struct modelrodata_gunfire gunfire;
	struct modelrodata_type0d type0d;
	struct modelrodata_type11 type11;
	struct modelrodata_toggle toggle;
	struct modelrodata_positionheld positionheld;
	struct modelrodata_type16 type16;
	struct modelrodata_headspot headspot;
	struct modelrodata_dl dl;
};

struct modelnode {
	/*0x00*/ u16 type;
	/*0x04*/ union modelrodata *rodata;
	/*0x08*/ struct modelnode *parent;
	/*0x0c*/ struct modelnode *next;
	/*0x10*/ struct modelnode *prev;
	/*0x14*/ struct modelnode *child;
};

struct modelfiledata {
	struct modelnode *rootnode;
	struct modeltype *type;

	// This is a pointer to a variable length array of pointers to modelnodes,
	// but the array is followed by an s16 array of part numbers.
	struct modelnode **parts;

	s16 numparts;
	s16 nummatrices;
	f32 unk10;
	s16 rwdatalen; // in words
	void *unk18;
};

struct model {
	/*0x00*/ u8 unk00;
	/*0x01*/ u8 unk01;
	/*0x02*/ s16 unk02;
	/*0x04*/
	union {
		struct chrdata *chr;
		struct defaultobj *obj;
	};
	/*0x08*/ struct modelfiledata *filedata;
	/*0x0c*/ Mtxf *matrices;
	/*0x10*/ union modelrwdata **rwdatas;
	/*0x14*/ f32 scale;
	/*0x18*/ struct model *attachedtomodel;
	/*0x1c*/ struct modelnode *attachedtonode;
	/*0x20*/ struct anim *anim;
};

struct modelrwdata_chrinfo { // type 0x01
	s8 unk00;
	s8 unk01;
	s8 unk02;
	f32 ground;
	struct coord pos;
	f32 unk14; // angle
	f32 unk18;
	f32 unk1c;
	f32 unk20; // angle
	struct coord unk24;
	f32 unk30; // angle
	struct coord unk34;
	struct coord unk40; // "2" version of unk24
	struct coord unk4c; // "2" version of unk34
	f32 unk58;
	f32 unk5c;
};

struct modelrwdata_05 { // type 0x05
	bool unk00;
};

struct modelrwdata_distance { // type 0x08
	bool visible;
};

struct modelrwdata_reorder { // type 0x09
	bool visible;
};

struct modelrwdata_0b { // type 0x0b
	u16 unk00;
	u16 unk04;
};

struct modelrwdata_gunfire { // type 0x0c
	s16 visible;
	u16 unk02;
};

struct modelrwdata_toggle { // type 0x12
	bool visible;
};

struct modelrwdata_headspot { // type 0x17
	struct modelfiledata *modelfiledata;
	void *rwdatas;
};

struct modelrwdata_dl { // type 0x18
	struct gfxvtx *vertices;
	Gfx *gdl;
	u32 *unk08;
};

union modelrwdata {
	struct modelrwdata_chrinfo chrinfo;
	struct modelrwdata_05 type05;
	struct modelrwdata_distance distance;
	struct modelrwdata_reorder reorder;
	struct modelrwdata_0b type0b;
	struct modelrwdata_gunfire gunfire;
	struct modelrwdata_toggle toggle;
	struct modelrwdata_headspot headspot;
	struct modelrwdata_dl dl;
};

struct waygroup {
	s32 *neighbours;
	s32 *waypoints;
	s32 unk08;
};

struct waypoint {
	s32 padnum;
	s32 *neighbours; // most significant two bits are booleans, remaining bits are waypoint index
	s32 groupnum;
	s32 unk0c;
};

struct aibot {
	/*0x000*/ u8 unk000;
	/*0x002*/ s16 aibotnum;
	/*0x004*/ struct mpsim *simulant;
	/*0x008*/ s16 attackingplayernum;
	/*0x00a*/ s16 followingplayernum;
	/*0x00c*/ s16 dangerouspropnum; // index into g_DangerousProps
	/*0x010*/ struct prop *fetchprop;
	/*0x014*/ struct invitem *items;
	/*0x018*/ s8 maxitems;
	/*0x01c*/ s32 *ammoheld;
	/*0x020*/ s32 weaponnum;
	/*0x024*/ s32 loadedammo[2]; // amount of ammo in current clip
	/*0x02c*/ s16 unk02c[2];
	/*0x030*/ u32 unk030; // timer of some sort
	/*0x034*/ u32 unk034;
	/*0x038*/ u32 unk038;
	/*0x03c*/ u16 unk03c;
	/*0x03e*/ s16 unk03e;
	/*0x040*/ f32 unk040;
	/*0x044*/ struct prop *skrocket;
	/*0x048*/ s16 unk048;
	/*0x04a*/ s16 unk04a;
	/*0x04c*/ u8 unk04c_00 : 1;
	/*0x04c*/ u8 iscloserangeweapon : 1;
	/*0x04c*/ u8 gunfunc : 1;
	/*0x04c*/ u8 unk04c_03 : 1;
	/*0x04c*/ u8 unk04c_04 : 1;
	/*0x04c*/ u8 unk04c_05 : 1;
	/*0x04c*/ u8 cloakdeviceenabled : 1;
	/*0x04c*/ u8 unk04c_07 : 1;
	/*0x04d*/ u8 unk04d[2];
	/*0x04f*/ u8 teamisonlyai : 1;
	/*0x04f*/ u8 unk04f_01 : 1;
	/*0x04f*/ u8 unk04f_02 : 1;
	/*0x04f*/ u8 unk04f_03 : 1;
	/*0x04f*/ u8 unk04f_04 : 1;
	/*0x04f*/ u8 unk04f_05 : 1;
	/*0x04f*/ u8 unk04f_06 : 1;
	/*0x04f*/ u8 unk04f_07 : 1;
	/*0x050*/ struct prop *unk050;
	/*0x054*/ u32 unk054;
	/*0x058*/ u8 unk058; // related to fireslots
	/*0x059*/ u8 unk059;
	/*0x05c*/ u32 unk05c;
	/*0x060*/ u32 unk060;

	/**
	 * 0x0001 = has unlimited ammo (darksim?)
	 * 0x0004 = detected dangerous prop
	 * 0x1000 = using remote mines
	 */
	/*0x064*/ u16 unk064;

	/*0x068*/ struct attackanimconfig *unk068;
	/*0x06c*/ f32 unk06c;
	/*0x070*/ f32 unk070;
	/*0x074*/ s8 unk074;
	/*0x075*/ s8 unk075;
	/*0x076*/ s16 lastkilledbyplayernum;
	/*0x078*/ u8 unk078;
	/*0x079*/ u8 command;
	/*0x07a*/ s16 rooms[1];
	/*0x07c*/ u32 unk07c;
	/*0x080*/ u32 unk080;
	/*0x084*/ u32 unk084;
	/*0x088*/ u32 unk088;
	/*0x08c*/ struct coord defendholdpos;
	/*0x098*/ f32 unk098;
	/*0x09c*/ u8 unk09c_00 : 1;
	/*0x09c*/ u8 unk09c_01 : 1;
	/*0x09c*/ u8 rcp120cloakenabled : 1;
	/*0x09c*/ u8 unk09c_03 : 1;
	/*0x09c*/ u8 unk09c_04 : 1;
	/*0x09c*/ u8 unk09c_05 : 1;
	/*0x09c*/ u8 unk09c_06 : 1;
	/*0x09c*/ u8 cheap : 1; // True if aibot is not in any visible room
	/*0x09d*/ u8 unk09d;
	/*0x0a0*/ s32 unk0a0;
	/*0x0a4*/ f32 unk0a4;
	/*0x0a8*/ f32 angleoffset;
	/*0x0ac*/ f32 speedtheta;
	/*0x0b0*/ f32 unk0b0; // likely to be the turn angle to 360 degrees, in radians
	/*0x0b4*/ f32 unk0b4;
	/*0x0b8*/ f32 unk0b8;
	/*0x0bc*/ s32 unk0bc;
	/*0x0c0*/ s32 attackpropnum;
	/*0x0c4*/ u32 unk0c4[2];
	/*0x0cc*/ u32 unk0cc; // Timer? Related to weapon switching
	/*0x0d0*/ s32 unk0d0;
	/*0x0d4*/ s32 followprotectpropnum;
	/*0x0d8*/ s32 unk0d8;
	/*0x0dc*/ u32 unk0dc;
	/*0x0e0*/ s16 unk0e0[2];
	/*0x0e4*/ f32 unk0e4[2];
	/*0x0ec*/ u32 unk0ec;
	/*0x0f0*/ u32 unk0f0;
	/*0x0f4*/ u32 unk0f4;
	/*0x0f8*/ u32 unk0f8;
	/*0x0fc*/ u32 unk0fc;
	/*0x100*/ u32 unk100;
	/*0x104*/ u32 unk104;
	/*0x108*/ struct coord shotspeed; // "boost" when aibot is shot
	/*0x114*/ s32 unk114;
	/*0x118*/ u32 unk118;
	/*0x11c*/ s32 unk11c;
	/*0x120*/ s32 unk120;
	/*0x124*/ s32 unk124;
	/*0x128*/ u32 unk128;
	/*0x12c*/ u32 unk12c;
	/*0x130*/ s8 unk130[12];
	/*0x13c*/ f32 playerdistances[12];
	/*0x16c*/ u8 unk16c[12];
	/*0x178*/ s32 unk178[12];
	/*0x1a8*/ s16 unk1a8[12];
	/*0x1c0*/ f32 unk1c0;
	/*0x1c4*/ f32 unk1c4;
	/*0x1c8*/ f32 unk1c8;
	/*0x1cc*/ s32 unk1cc;
	/*0x1d0*/ u32 unk1d0;
	/*0x1d4*/ f32 unk1d4;
	/*0x1d8*/ u32 unk1d8;
	/*0x1dc*/ u32 unk1dc;
	/*0x1e0*/ u32 unk1e0;
	/*0x1e4*/ s32 unk1e4;
	/*0x1e8*/ u32 unk1e8;
	/*0x1ec*/ u32 unk1ec;
	/*0x1f0*/ u32 unk1f0;
	/*0x1f4*/ u32 unk1f4;
	/*0x1f8*/ u32 unk1f8;
	/*0x1fc*/ u32 unk1fc;
	/*0x200*/ u32 unk200;
	/*0x204*/ u32 unk204;
	/*0x208*/ s32 unk208;
	/*0x20c*/ s32 randttl60;
	/*0x210*/ u32 rand;
	/*0x214*/ f32 killsbygunfunc[6][2];
	/*0x244*/ f32 suicidesbygunfunc[6][2];
	/*0x274*/ s32 equipdurations60[6][2];
	/*0x2a4*/ s32 unk2a4;
	/*0x2a8*/ s32 unk2a8[6];
	/*0x2c0*/ s32 dampensuicidesttl60;

	/**
	 * Some kind of cloak counter? Ticks up while cloaked. Over 1 causes RCP120
	 * ammo to be removed, and when this happens this value is decreased.
	 */
	/*0x2c4*/ f32 unk2c4;

	/*0x2c8*/ s32 unk2c8;
	/*0x2cc*/ u32 unk2cc;
	/*0x2d0*/ u32 unk2d0;
	/*0x2d4*/ f32 unk2d4;
	/*0x2d8*/ u32 unk2d8;
	/*0x2dc*/ u32 unk2dc;
};

struct tile {
	/*0x00*/ u8 type;
	/*0x01*/ u8 numvertices;
	/*0x02*/ u16 flags;
};

struct tiletype0 {
	struct tile header;
	/*0x04*/ u16 floortype;
	/*0x06*/ u8 xmin; // These are byte offsets relative to the start of tile
	/*0x07*/ u8 ymin;
	/*0x08*/ u8 zmin;
	/*0x09*/ u8 xmax;
	/*0x0a*/ u8 ymax;
	/*0x0b*/ u8 zmax;
	/*0x0c*/ u16 floorcol;
	/*0x0e*/ s16 vertices[64][3];
};

struct tiletype1 {
	struct tile header;
	/*0x04*/ u16 floortype;
	/*0x06*/ u8 xmin; // These are indexes into vertices
	/*0x07*/ u8 ymin;
	/*0x08*/ u8 zmin;
	/*0x09*/ u8 xmax;
	/*0x0a*/ u8 ymax;
	/*0x0b*/ u8 zmax;
	/*0x0c*/ u16 floorcol;
	/*0x10*/ struct coord vertices[64];
};

struct tiletype2 {
	struct tile header;
	/*0x04*/ f32 ymax;
	/*0x08*/ f32 ymin;
	/*0x0c*/ f32 vertices[8][2];
};

struct tiletype3 {
	struct tile header;
	/*0x04*/ f32 ymax;
	/*0x08*/ f32 ymin;
	/*0x0c*/ f32 x;
	/*0x10*/ f32 z;
	/*0x14*/ f32 width; // radius
};

struct tilething {
	struct tile *tile;
	u32 unk04;
	u32 unk08;
	struct prop *lift;
	u32 floorroom;
};

struct act_stand {
	/*0x2c*/ s32 prestand;
	/*0x30*/ s32 flags;
	/*0x34*/ s32 entityid;
	/*0x38*/ bool reaim;
	/*0x3c*/ s32 turning;
	/*0x40*/ bool checkfacingwall;
	/*0x44*/ s32 wallcount;
	/*0x48*/ f32 mergetime;
	/*0x4c*/ u8 playwalkanim;
};

struct act_anim {
	/*0x2c*/ bool movewheninvis;
	/*0x30*/ bool pauseatend;
	/*0x34*/ bool completed;
	/*0x38*/ bool slowupdate;
	/*0x3c*/ bool lockpos;
	/*0x40*/ u8 ishitanim;
	/*0x41*/ u8 reverse;
	/*0x42*/ u16 hitframe;
	/*0x44*/ u16 hitdamage;
	/*0x46*/ u16 hitradius;
	/*0x48*/ s16 animnum;
	/*0x4a*/ u8 flip;
	/*0x4c*/ f32 startframe;
	/*0x50*/ f32 endframe;
	/*0x54*/ f32 speed;
	/*0x58*/ f32 blend;
};

struct act_die {
	/*0x2c*/ s32 notifychrindex;
	/*0x30*/ f32 thudframe1;
	/*0x34*/ f32 thudframe2;
	/*0x38*/ f32 timeextra;
	/*0x3c*/ f32 elapseextra;
	/*0x40*/ struct coord extraspeed; // for changing position while airborne (eg. when shot by magnum)
	/*0x4c*/ s16 drcarollimagedelay;
};

struct act_dead {
	/*0x2c*/ bool fadenow;
	/*0x30*/ bool fadewheninvis;
	/*0x34*/ s32 invistimer60;
	/*0x38*/ s32 fadetimer60;
	/*0x3c*/ s32 notifychrindex;
};

struct act_argh {
	/*0x2c*/ s32 notifychrindex;
	/*0x30*/ s32 lvframe60;
};

// Gun settings
struct gset {
	u8 weaponnum;
	u8 unk0639;
	u8 unk063a;
	u8 weaponfunc; // 0 or 1
};

struct act_preargh {
	/*0x2c*/ struct coord dir;
	/*0x38*/ f32 relshotdir;
	/*0x3c*/ s32 hitpart;
	/*0x40*/ struct gset gset;
	/*0x44*/ s32 aplayernum;
};

struct act_attack {
	/*0x2c*/ struct attackanimconfig *animcfg;
	/*0x30*/ s8 turning;
	/*0x31*/ s8 fired;
	/*0x32*/ s8 nextgun;
	/*0x33*/ s8 numshots; // number of shots fired so far in this anim
	/*0x34*/ s8 maxshots; // number of shots to attempt in this anim
	/*0x35*/ s8 onehanded;
	/*0x36*/ s8 dorecoil;
	/*0x37*/ s8 dooneburst;
	/*0x38*/ s8 firegun[2]; // whether this gun is going to attempt to fire in this anim
	/*0x3a*/ s8 everytick[2]; // whether gun's fire rate is high enough to fire on every tick
	/*0x3c*/ u8 singleshot[2];
	/*0x3e*/ s8 flip;
	/*0x40*/ s32 pausecount;
	/*0x44*/ s32 lastfire60;
	/*0x48*/ s32 lastontarget60;
	/*0x4c*/ u32 flags;
	/*0x50*/ s32 entityid;
	/*0x54*/ s32 standing;
	/*0x58*/ s32 reaim;
};

struct act_attackwalk {
	/*0x2c*/ s32 unk02c;
	/*0x30*/ s32 frame60count;
	/*0x34*/ s32 frame60max;
	/*0x38*/ bool facedtarget;
	/*0x3c*/ struct attackanimconfig *animcfg;
	/*0x40*/ s32 nextshot60;
	/*0x44*/ s32 nextgun;
	/*0x48*/ s8 firegun[2];
	/*0x4a*/ s8 everytick[2];
	/*0x4c*/ s8 singleshot[2];
	/*0x4e*/ u8 flip;
	/*0x50*/ s32 dorecoil;
	/*0x54*/ f32 turnspeed;
};

struct act_sidestep {
	/*0x2c*/ bool side;
};

struct act_jumpout {
	/*0x2c*/ bool side;
};

struct act_runpos {
	/*0x2c*/ struct coord pos;
	/*0x38*/ f32 neardist;
	/*0x3c*/ s32 eta60;
	/*0x40*/ f32 turnspeed;
};

struct waydata {
	/*0x00*/ s8 mode;
	/*0x01*/ u8 iter;
	/*0x02*/ u8 gotaimpos;
	/*0x03*/ u8 gotaimposobj;
	/*0x04*/ struct coord aimpos;
	/*0x10*/ u32 unk10;
	/*0x14*/ u32 unk14;
	/*0x18*/ u32 unk18;
	/*0x1c*/ u32 unk1c;
	/*0x20*/ u32 unk20;
	/*0x24*/ u32 unk24;
	/*0x28*/ s32 age;
	/*0x2c*/ u32 aimposobj;
	/*0x30*/ s8 unk30_test;
	/*0x34*/ u32 unk34;

	// These are the distances between the current waypoint and the previous
	// when using magic mode.
	/*0x38*/ f32 magicdone;
	/*0x3c*/ f32 magictotal;
	/*0x40*/ s32 lastvisible60;
};

struct act_patrol {
	/*0x02c*/ struct path *path;
	/*0x030*/ s32 nextstep;
	/*0x034*/ bool forward;
	/*0x038*/ struct waydata waydata;
	/*0x07c*/ f32 turnspeed;
};

struct act_gopos {
	/*0x02c*/ struct coord endpos;
	/*0x038*/ s16 endrooms[8];
	/*0x048*/ struct waypoint *target; // Target/final waypoint

	// Array of pointers to the next couple of waypoints. Recalculated each time
	// a waypoint is reached, and probably even more frequently than that.
	/*0x04c*/ struct waypoint *waypoints[MAX_CHRWAYPOINTS];

	// Index of the waypoint in the above array that the chr is running to. If
	// the chr has line of sight (through doors) to the next or next + 1 then
	// the index can be changed to that one and the chr will run straight to it.
	// This index will always be 0, 1 or 2. When it reaches 3 the pathfinding is
	// recalculated, the array replaced with a new one and index set to 0.
	/*0x064*/ u8 curindex;

	// x....... = walking directly to pad due to PADFLAG_AIWALKDIRECT
	// .x...... = ducking due to PADFLAG_AIDUCK
	// ....x... = on preset path
	// ......xx = speed
	/*0x065*/ u8 flags;

	/*0x066*/ u16 restartttl;
	/*0x068*/ struct waydata waydata;
	/*0x0ac*/ f32 turnspeed;
};

struct act_surprised {
	/*0x2c*/ u32 type;
};

struct act_throwgrenade {
	/*0x2c*/ u32 flags;
	/*0x30*/ u32 entityid;
	/*0x34*/ u32 hand;
	/*0x38*/ bool needsequip;
};

struct act_bondmulti {
	/*0x2c*/ struct attackanimconfig *animcfg;
};

struct act_druggedcomingup {
	/*0x2c*/ s16 timer60;
};

struct act_robotattack {
	/*0x2c*/ struct coord pos[2];
	/*0x44*/ struct coord dir[2];
	/*0x5c*/ u32 guntype[2];
	/*0x64*/ s32 numshots[2];
	/*0x6c*/ u8 firing[2];
	/*0x6e*/ u8 finished;
};

struct act_skjump {
	/*0x2c*/ u8 state;
	/*0x2d*/ u8 needsnewanim;
	/*0x2e*/ u8 hit;
	/*0x30*/ f32 vel[2];
	/*0x38*/ f32 roty;
	/*0x3c*/ s32 timer60; // counts down
	/*0x40*/ struct coord pos;
	/*0x4c*/ s32 total60;
	/*0x50*/ f32 ground;
};

struct chrdata {
	/*0x000*/ s16 chrnum;
	/*0x002*/ s8 accuracyrating;
	/*0x003*/ s8 speedrating; // 0-100
	/*0x004*/ u8 firecount[2];
	/*0x006*/ s8 headnum;
	/*0x007*/ s8 actiontype;
	/*0x008*/ s8 sleep;
	/*0x009*/ s8 invalidmove;
	/*0x00a*/ s8 numclosearghs;
	/*0x00b*/ s8 numarghs;
	/*0x00c*/ u8 fadealpha;
	/*0x00d*/ s8 arghrating;
	/*0x00e*/ s8 aimendcount;
	/*0x00f*/ u8 grenadeprob;
	/*0x010*/ s16 bodynum;
	/*0x012*/ s8 flinchcnt;
	/*0x013*/ s8 path;
	/*0x014*/ u32 hidden;
	/*0x018*/ u32 chrflags;
	/*0x01c*/ struct prop *prop;
	/*0x020*/ struct model *model;
	/*0x024*/ f32 chrwidth;
	/*0x028*/ f32 chrheight;

	union {
		struct act_stand act_stand;
		struct act_anim act_anim;
		struct act_die act_die;
		struct act_dead act_dead;
		struct act_argh act_argh;
		struct act_preargh act_preargh;
		struct act_attack act_attack;
		struct act_attackwalk act_attackwalk;
		// act_attackroll uses act_attack
		struct act_sidestep act_sidestep;
		struct act_jumpout act_jumpout;
		struct act_runpos act_runpos;
		struct act_patrol act_patrol;
		struct act_gopos act_gopos;
		struct act_surprised act_surprised;
		struct act_throwgrenade act_throwgrenade;
		struct act_bondmulti act_bondmulti;
		// act_bot_attackstand uses act_attack
		// act_bot_attackkneel uses act_attack
		// act_bot_attackstrafe uses act_attack
		// act_druggeddrop uses act_die
		// act_druggedko uses act_dead
		struct act_druggedcomingup act_druggedcomingup;
		// act_attackamount uses act_attack
		struct act_robotattack act_robotattack;
		struct act_skjump act_skjump;
	};

	/*0x0b0*/ f32 sumground;
	/*0x0b4*/ f32 manground;
	/*0x0b8*/ f32 ground;
	/*0x0bc*/ struct coord fallspeed;
	/*0x0c8*/ struct coord prevpos;
	/*0x0d4*/ s32 lastwalk60;
	/*0x0d8*/ s32 lastmoveok60;
	/*0x0dc*/ f32 visionrange;
	/*0x0e0*/ s32 lastseetarget60;
	/*0x0e4*/ s32 lastvisibletarget60;
	/*0x0e8*/ struct prop *poisonprop;
	/*0x0ec*/ s16 lastshooter;
	/*0x0ee*/ s16 timeshooter;
	/*0x0f0*/ f32 hearingscale;
	/*0x0f4*/ s32 lastheartarget60;
	/*0x0f8*/ u8 shadecol[4];
	/*0x0fc*/ u8 nextcol[4];
	/*0x100*/ f32 damage;
	/*0x104*/ f32 maxdamage;
	/*0x108*/ u8 *ailist;
	/*0x10c*/ u16 aioffset;
	/*0x10e*/ s16 aireturnlist;
	/*0x110*/ s16 aishotlist;
	/*0x112*/ u8 morale;
	/*0x113*/ u8 alertness;
	/*0x114*/ u32 flags;
	/*0x118*/ u32 flags2;
	/*0x11c*/ s32 timer60;
	/*0x120*/ s32 soundtimer;
	/*0x124*/ u8 random;
	/*0x125*/ u8 team;
	/*0x126*/ u8 soundgap;
	/*0x128*/ s16 padpreset1;
	/*0x12a*/ s16 chrpreset1;
	/*0x12c*/ s16 proppreset1;
	/*0x12e*/ s16 chrseeshot;
	/*0x130*/ s16 chrseedie;
	/*0x132*/ s16 chrdup;
	struct tiletype3 geo;
	/*0x14c*/ f32 shotbondsum;
	/*0x150*/ f32 aimuplshoulder;
	/*0x154*/ f32 aimuprshoulder;
	/*0x158*/ f32 aimupback;
	/*0x15c*/ f32 aimsideback;
	/*0x160*/ f32 aimendlshoulder;
	/*0x164*/ f32 aimendrshoulder;
	/*0x168*/ f32 aimendback;
	/*0x16c*/ f32 aimendsideback;
	/*0x170*/ struct prop *weapons_held[3]; // gun 1, gun 2, hat
	/*0x17c*/ s8 fireslots[2];
	/*0x17e*/ s16 target; // index into g_Vars.props
	/*0x180*/ f32 cshield;

	// The cm fields are related to the chr's shield visual effect
	/*0x184*/ s8 cmnum;
	/*0x185*/ s8 cmnum2;
	/*0x186*/ s8 cmnum3;
	/*0x187*/ s8 cmnum4;
	/*0x188*/ u16 cmcount;

	/*0x18a*/ u16 floorcol;
	/*0x18c*/ f32 oldframe;
	/*0x190*/ s8 footstep;
	/*0x191*/ u8 floortype;
	/*0x192*/ u16 hidden2; // First 3 bits are a number
	/*0x194*/ f32 magicframe;
	/*0x198*/ f32 magicspeed;
#if VERSION >= VERSION_NTSC_1_0
	/*0x19c*/ s16 magicanim;
	/*0x19e*/ s16 goposforce;
#else
	/*0x19c*/ s32 magicanim;
#endif
	/*0x1a0*/ s32 bdlist[60];
	/*0x290*/ u8 bdstart;
	/*0x291*/ u8 goposhitcount;
	/*0x292*/ s16 cover;
	/*0x294*/ struct coord targetlastseenp;
	/*0x2a0*/ u8 myaction;
	/*0x2a1*/ u8 orders;
	/*0x2a2*/ u8 squadron;
	/*0x2a3*/ u8 listening;
	/*0x2a4*/ u32 convtalk;
	/*0x2a8*/ s32 talktimer;
	/*0x2ac*/ u8 question;
	/*0x2ad*/ u8 talkgap;
	/*0x2ae*/ u16 unk2ae;
	/*0x2b0*/ u8 tude;
	/*0x2b1*/ u8 voicebox;
	/*0x2b2*/ s16 floorroom;
	/*0x2b4*/ u32 unk2b4;
	/*0x2b8*/ s16 oldrooms[8];
	/*0x2c8*/ struct coord runfrompos;
	/*0x2d4*/ struct aibot *aibot;
	/*0x2d8*/ s16 blurdrugamount;

	// Cloakpause is set to a positive value when shooting, then decreases to
	// zero over a couple of seconds. When zero is reached, the cloak is
	// applied again.
	/*0x2da*/ s16 cloakpause;

	/*0x2dc*/ f32 drugheadsway;
	/*0x2e0*/ u8 drugheadcount;
	/*0x2e1*/ u8 cloakfadefrac : 7;
	/*0x2e1*/ u8 cloakfadefinished : 1;
	/*0x2e2*/ u8 teamscandist;
	/*0x2e3*/ u8 naturalanim;
	/*0x2e4*/ s32 myspecial; // This is an object tag ID
	/*0x2e8*/ f32 timeextra;
	/*0x2ec*/ f32 elapseextra;
	/*0x2f0*/ struct coord extraspeed;
	/*0x2fc*/ u8 yvisang;
	/*0x2fd*/ u8 hitpart;
	/*0x2fe*/ u8 race;
	/*0x2ff*/ u8 blurnumtimesdied;
	/*0x300*/ struct prop *gunprop;
	/*0x304*/ f32 pushspeed[2];
	/*0x30c*/ f32 gunroty[2];
	/*0x314*/ f32 gunrotx[2];
	/*0x31c*/ u32 onladder;
	/*0x320*/ struct coord laddernormal;

	/*0x32c*/
	u8 liftaction : 8;

	u8 inlift : 1;
	u8 pouncebits : 3;
	u8 unk32c_12 : 2;
	u8 darkroomthing : 1;
	u8 playerdeadthing : 1;

	u8 p1p2 : 2;
	u8 unk32c_18 : 1;
	u8 noblood : 1;
	u8 rtracked : 1;
	u8 unk32c_21 : 1;
	u8 unk32c_22 : 2;

	u8 specialdie : 8;

	/*0x330*/ u16 roomtosearch;
	/*0x332*/ u8 propsoundcount;
	/*0x333*/ s8 patrolnextstep;
	/*0x334*/ u8 bulletstaken;
	/*0x335*/ u8 woundedsplatsadded;
	/*0x336*/ u16 tickssincesplat;
	/*0x338*/ u8 splatsdroppedhe;
	/*0x339*/ u8 stdsplatsadded;
	/*0x33a*/ u8 deaddropsplatsadded;
	/*0x33b*/ s8 aimtesttimer60;
	/*0x33c*/ struct coord lastdroppos;
	/*0x348*/ struct fireslotthing *unk348[2];
	/*0x350*/ struct chrdata *lastattacker;
	/*0x354*/ s16 aipunchdodgelist;
	/*0x356*/ s16 aishootingatmelist;
	/*0x358*/ s16 poisoncounter;
	/*0x35a*/ s16 aidarkroomlist;
	/*0x35c*/ s16 aiplayerdeadlist;
	/*0x35e*/ u8 dodgerating;
	/*0x35f*/ u8 maxdodgerating;
	/*0x360*/ u8 unarmeddodgerating;
	/*0x361*/ u8 lastfootsample;
	/*0x362*/ u8 drcarollimage_left : 4;
	/*0x362*/ u8 drcarollimage_right : 4;
	/*0x364*/ struct prop *lift;
};

// This appears to be misnamed. Not only is it projectiles such as grenades and
// crossbow bolts, but objects being pushed like couches also have this struct.
// So I guess it denotes a generic moving object?
struct projectile {
	/*0x000*/ u32 flags;
	/*0x004*/ struct coord unk004; // distance moved in last tick
	/*0x010*/ f32 unk010;
	/*0x014*/ f32 unk014;
	/*0x018*/ f32 unk018;
	/*0x01c*/ f32 unk01c;
	/*0x020*/ f32 unk020;
	/*0x024*/ u32 unk024;
	/*0x028*/ u32 unk028;
	/*0x02c*/ u32 unk02c;
	/*0x030*/ u32 unk030;
	/*0x034*/ u32 unk034;
	/*0x038*/ u32 unk038;
	/*0x03c*/ u32 unk03c;
	/*0x040*/ u32 unk040;
	/*0x044*/ struct projectile *unk044;
	/*0x048*/ u32 unk048;
	/*0x04c*/ u32 unk04c;
	/*0x050*/ u32 unk050;
	/*0x054*/ u32 unk054;
	/*0x058*/ u32 unk058;
	/*0x05c*/ u32 unk05c;
	/*0x060*/ f32 unk060;
	/*0x064*/ u32 unk064;
	/*0x068*/ u32 unk068;
	/*0x06c*/ u32 unk06c;
	/*0x070*/ u32 unk070;
	/*0x074*/ u32 unk074;
	/*0x078*/ u32 unk078;
	/*0x07c*/ u32 unk07c;
	/*0x080*/ u32 unk080;
	/*0x084*/ u32 unk084;
	/*0x088*/ struct prop *ownerprop;
	/*0x08c*/ f32 unk08c;
	/*0x090*/ u32 unk090;
	/*0x094*/ s32 unk094;
	/*0x098*/ f32 unk098;
	/*0x09c*/ s32 unk09c;
	/*0x0a0*/ u32 unk0a0;
	/*0x0a4*/ s32 unk0a4;
	/*0x0a8*/ u32 unk0a8;
	/*0x0ac*/ u32 unk0ac;
	/*0x0b0*/ s16 dropreason;
	/*0x0b2*/ s16 unk0b2;
	/*0x0b4*/ s32 unk0b4;
	/*0x0b8*/ f32 unk0b8;
	/*0x0bc*/ f32 unk0bc;
	/*0x0c0*/ f32 unk0c0;
	/*0x0c4*/ struct coord pos;
	/*0x0d0*/ u32 unk0d0;
	/*0x0d4*/ struct defaultobj *obj;
	/*0x0d8*/ s32 unk0d8;
	/*0x0dc*/ f32 unk0dc;
	/*0x0e0*/ f32 unk0e0;
	/*0x0e4*/ f32 unk0e4;
	/*0x0e8*/ u32 unk0e8;
	/*0x0ec*/ f32 unk0ec;
	/*0x0f0*/ f32 unk0f0;
	/*0x0f4*/ u32 unk0f4;
	/*0x0f8*/ s16 waypads[6];
	/*0x104*/ u8 numwaypads;
	/*0x105*/ u8 unk105;
	/*0x108*/ struct prop *unk108;
};

struct monitorthing {
	/*0x000*/ u32 flags;
	/*0x004*/ Mtxf matrix;
	/*0x044*/ struct projectile *unk044;
};

struct tvscreen {
	/*0x00*/ u32 *cmdlist;
	/*0x04*/ u16 offset;
	/*0x06*/ s16 pause60;
	/*0x08*/ struct textureconfig *tconfig;
	/*0x0c*/ f32 rot;
	/*0x10*/ f32 xscale;
	/*0x14*/ f32 xscalefrac;
	/*0x18*/ f32 xscaleinc;
	/*0x1c*/ f32 xscaleold;
	/*0x20*/ f32 xscalenew;
	/*0x24*/ f32 yscale;
	/*0x28*/ f32 yscalefrac;
	/*0x2c*/ f32 yscaleinc;
	/*0x30*/ f32 yscaleold;
	/*0x34*/ f32 yscalenew;
	/*0x38*/ f32 xmid;
	/*0x3c*/ f32 xmidfrac;
	/*0x40*/ f32 xmidinc;
	/*0x44*/ f32 xmidold;
	/*0x48*/ f32 xmidnew;
	/*0x4c*/ f32 ymid;
	/*0x50*/ f32 ymidfrac;
	/*0x54*/ f32 ymidinc;
	/*0x58*/ f32 ymidold;
	/*0x5c*/ f32 ymidnew;
	/*0x60*/ u8 red;
	/*0x61*/ u8 redold;
	/*0x62*/ u8 rednew;
	/*0x63*/ u8 green;
	/*0x64*/ u8 greenold;
	/*0x65*/ u8 greennew;
	/*0x66*/ u8 blue;
	/*0x67*/ u8 blueold;
	/*0x68*/ u8 bluenew;
	/*0x69*/ u8 alpha;
	/*0x6a*/ u8 alphaold;
	/*0x6b*/ u8 alphanew;
	/*0x6c*/ f32 colfrac;
	/*0x70*/ f32 colinc;
};

struct hov {
	/*0x00*/ u32 unk00;
	/*0x04*/ f32 unk04;
	/*0x08*/ f32 unk08;
	/*0x0c*/ f32 unk0c;
	/*0x10*/ f32 unk10;
	/*0x14*/ f32 unk14;
	/*0x18*/ f32 unk18;
	/*0x1c*/ f32 unk1c;
	/*0x20*/ f32 unk20;
	/*0x24*/ f32 unk24;
	/*0x28*/ f32 unk28;
	/*0x2c*/ f32 unk2c;
	/*0x30*/ f32 unk30;
	/*0x34*/ f32 ground;
	/*0x38*/ s32 groundnext60; // time60 of when ground should be updated next
	/*0x3c*/ s32 groundprev60; // time60 of when ground was last updated
};

struct defaultobj {
	/*0x00*/ u16 extrascale;
	/*0x02*/ u8 hidden2;
	/*0x03*/ u8 type;
	/*0x04*/ s16 modelnum;
	/*0x06*/ s16 pad;
	/*0x08*/ u32 flags;
	/*0x0c*/ u32 flags2;
	/*0x10*/ u32 flags3;
	/*0x14*/ struct prop *prop;
	/*0x18*/ struct model *model;
	/*0x1c*/ f32 realrot[9];
	/*0x40*/ u32 hidden;
	union {
		/*0x44*/ struct tiletype1 *geo1;
		/*0x44*/ struct tiletype2 *geo2;
		/*0x44*/ struct tiletype3 *geo3;
		/*0x44*/ struct tiletype3 *unkgeo; // temporary, to indicate that I don't know which geo pointer is being used
	};
	union {
		/*0x48*/ struct projectile *projectile;
		/*0x48*/ struct monitorthing *monitorthing;
	};
	/*0x4c*/ s16 damage;
	/*0x4e*/ s16 maxdamage;
	/*0x50*/ u8 shadecol[4];
	/*0x54*/ u8 nextcol[4];
	/*0x58*/ u16 floorcol;
	/*0x5a*/ s8 numtiles;
};

struct doorobj { // objtype 0x01
	struct defaultobj base;
	/*0x5c*/ f32 maxfrac;
	/*0x60*/ f32 perimfrac;
	/*0x64*/ f32 accel;
	/*0x68*/ f32 decel;
	/*0x6c*/ f32 maxspeed;
	/*0x70*/ u16 doorflags;
	/*0x72*/ u16 doortype;
	/*0x74*/ u32 keyflags;
	/*0x78*/ s32 autoclosetime;
	/*0x7c*/ f32 frac; // 0 = closed, maxfrac = fully open
	/*0x80*/ f32 fracspeed;
	/*0x84*/ s8 mode;
	/*0x85*/ u8 glasshits;
	/*0x86*/ s16 fadealpha;
	/*0x88*/ s16 xludist;
	/*0x8a*/ s16 opadist;
	/*0x8c*/ struct coord startpos;
	/*0x98*/ u32 unk98;
	/*0x9c*/ u32 unk9c;
	/*0xa0*/ u32 unka0;
	/*0xa4*/ struct gfxvtx *unka4;
	/*0xa8*/ u32 unka8;
	/*0xac*/ u32 unkac;
	/*0xb0*/ u32 unkb0;
	/*0xb4*/ u32 unkb4;
	/*0xb8*/ u32 unkb8;
	/*0xbc*/ struct doorobj *sibling;
	/*0xc0*/ s32 lastopen60;
	/*0xc4*/ s16 portalnum;
	/*0xc6*/ s8 soundtype;
	/*0xc7*/ s8 fadetime60; // counts down
	/*0xc8*/ s32 lastcalc60;
	/*0xcc*/ u8 laserfade;
	/*0xcd*/ u8 unusedmaybe[3];
	/*0xd0*/ u8 shadeinfo1[4]; // player 1
	/*0xd4*/ u8 shadeinfo2[4]; // player 2
};

struct doorscaleobj { // objtype 0x02
	u32 unk00;
	s32 scale;
};

struct keyobj { // objtype 0x04
	struct defaultobj base;
	u32 keyflags;
};

struct cctvobj { // objtype 0x06
	struct defaultobj base;

	// Note y is being used as an abbreviation for yaw
	/*0x5c*/ s16 lookatpadnum;
	/*0x5e*/ s16 toleft;
	/*0x60*/ Mtxf camrotm;
	/*0xa0*/ f32 yzero;
	/*0xa4*/ f32 yrot;
	/*0xa8*/ f32 yleft;
	/*0xac*/ f32 yright;
	/*0xb0*/ f32 yspeed;
	/*0xb4*/ f32 ymaxspeed;
	/*0xb8*/ s32 seebondtime60;
	/*0xbc*/ f32 maxdist;
	/*0xc0*/ f32 xzero;
};

struct ammocrateobj { // objtype 0x07
	struct defaultobj base;
	/*0x5c*/ s32 ammotype;
};

struct weaponobj { // objtype 0x08
	struct defaultobj base;
	/*0x5c*/ u8 weaponnum;
	/*0x5d*/ s8 unk5d;
	/*0x5e*/ s8 unk5e;
	/*0x5f*/ u8 gunfunc;
	/*0x60*/ s8 unk60;
	/*0x61*/ s8 dualweaponnum;

	/**
	 * timer240 is used for activation of proxy Dragons, grenades and proxy
	 * mines. It ticks down to 1 where it becomes active, and set to 0 when the
	 * item should explode.
	 */
	/*0x62*/ s16 timer240;

	/*0x64*/ struct weaponobj *dualweapon; // other weapon when dual wielding
};

struct packedchr { // objtype 0x09
	s16 chrindex;
	s8 unk02;
	s8 typenum;
	u32 spawnflags;
	s16 chrnum;
	u16 padnum;
	u8 bodynum;
	s8 headnum;
	u16 ailistnum;
	u16 padpreset;
	u16 chrpreset;
	u16 hearscale;
	u16 viewdist;
	u32 flags;
	u32 flags2;
	u8 team;
	u8 squadron;
	s16 chair;
	u32 convtalk;
	u8 tude;
	u8 naturalanim;
	u8 yvisang;
	u8 teamscandist;
};

struct singlemonitorobj { // objtype 0x0a
	struct defaultobj base;
	/*0x5c*/ struct tvscreen screen;
	/*0xd0*/ s16 owneroffset;
	/*0xd2*/ s8 ownerpart;
	/*0xd3*/ u8 imagenum;
};

struct multimonitorobj { // objtype 0x0b
	struct defaultobj base;
	struct tvscreen screens[4];
	u8 imagenums[4];
};

struct hangingmonitorsobj { // objtype 0x0c
	struct defaultobj base;
};

struct autogunobj { // objtype 0x0d
	struct defaultobj base;
	/*0x5c*/ s16 targetpad;
	/*0x5e*/ u8 firing;
	/*0x5f*/ u8 firecount;
	/*0x60*/ f32 yzero;
	/*0x64*/ f32 ymaxleft;
	/*0x68*/ f32 ymaxright;
	/*0x6c*/ f32 yrot;
	/*0x70*/ f32 yspeed;
	/*0x74*/ f32 xzero;
	/*0x78*/ f32 xrot;
	/*0x7c*/ f32 xspeed;
	/*0x80*/ f32 maxspeed;
	/*0x84*/ f32 aimdist;
	/*0x88*/ f32 barrelspeed;
	/*0x8c*/ f32 barrelrot;
	/*0x90*/ s32 lastseebond60;
	/*0x94*/ s32 lastaimbond60;
	/*0x98*/ s32 allowsoundframe;
	/*0x9c*/ struct beam *beam;
	/*0xa0*/ f32 shotbondsum;
	/*0xa4*/ u32 unka4;
	/*0xa8*/ u8 targetteam;
	/*0xa9*/ u8 ammoquantity;
	/*0xaa*/ u16 nextchrtest;
};

struct linkgunsobj { // objtype 0x0e
	u32 unk00;
	s16 offset1;
	s16 offset2;
};

struct hatobj { // objtype 0x11
	struct defaultobj base;
};

struct grenadeprobobj { // objtype 0x12
	u32 unk00;
	s16 chrnum;
	u16 probability;
};

struct linkliftdoorobj {
	u32 unk00;
	struct prop *door;
	struct prop *lift;
	struct linkliftdoorobj *next;
	s32 stopnum;
};

struct multiammocrateslot {
	u16 modelnum;
	u16 quantity;
};

struct multiammocrateobj { // objtype 0x14
	struct defaultobj base;
	/*0x5c*/ struct multiammocrateslot slots[19]; // indexed by ammotype minus 1
};

struct shieldobj { // objtype 0x15
	struct defaultobj base;
	/*0x5c*/ f32 initialamount;
	/*0x60*/ f32 amount;
};

struct tag { // objtype 0x16
	/*0x00*/ u32 identifier; // always 0x00000016
	/*0x04*/ u16 tagnum;
	/*0x06*/ s16 cmdoffset;
	/*0x08*/ struct tag *next;
	/*0x0c*/ struct defaultobj *obj;
};

struct objective { // objtype 0x17
	/*0x00*/ u32 unk00;
	/*0x04*/ s32 index;
	/*0x08*/ u32 text;
	/*0x0c*/ u16 unk0c;
	/*0x0e*/ u8 flags;
	/*0x0f*/ s8 difficulties;
};

struct briefingobj { // objtype 0x23
	u32 unk00;
	u32 type;
	u32 text;
	struct briefingobj *next;
};

struct padlockeddoorobj { // objtype 0x26
	u32 unk00;
	struct doorobj *door;
	struct defaultobj *lock;
	struct padlockeddoorobj *next;
};

struct truckobj { // objtype 0x27
	struct defaultobj base;
	/*0x5c*/ u8 *ailist;
	/*0x60*/ u16 aioffset;
	/*0x62*/ s16 aireturnlist;
	/*0x64*/ f32 speed;
	/*0x68*/ f32 wheelxrot;
	/*0x6c*/ f32 wheelyrot;
	/*0x70*/ f32 speedaim;
	/*0x74*/ f32 speedtime60;
	/*0x78*/ f32 turnrot60;
	/*0x7c*/ f32 roty;
	/*0x80*/ struct path *path;
	/*0x84*/ s32 nextstep;
};

struct heliobj { // objtype 0x28
	struct defaultobj base;
	/*0x5c*/ u8 *ailist;
	/*0x60*/ u16 aioffset;
	/*0x62*/ s16 aireturnlist;
	/*0x64*/ f32 rotoryrot;
	/*0x68*/ f32 rotoryspeed;
	/*0x6c*/ f32 rotoryspeedaim;
	/*0x70*/ f32 rotoryspeedtime;
	/*0x74*/ f32 speed;
	/*0x78*/ f32 speedaim;
	/*0x7c*/ f32 speedtime60;
	/*0x80*/ f32 yrot;
	/*0x84*/ struct path *path;
	/*0x88*/ s32 nextstep;
};

struct glassobj { // objtype 0x2a
	struct defaultobj base;
	/*0x5c*/ s16 portalnum;
};

struct safeobj { // objtype 0x2b
	u32 unk00;
};

struct safeitemobj {
	u32 unk00;
	struct defaultobj *item;
	struct safeobj *safe;
	struct doorobj *door;
	struct safeitemobj *next;
};

struct cameraposobj { // objtype 0x2e
	s32 type;
	f32 x;
	f32 y;
	f32 z;
	f32 theta;
	f32 verta;
	s32 pad;
};

struct tintedglassobj { // objtype 0x2f
	struct defaultobj base;
	/*0x5c*/ s16 xludist;
	/*0x5e*/ s16 opadist;
	/*0x60*/ s16 opacity;
	/*0x62*/ s16 portalnum;
	/*0x64*/ f32 unk64;
};

struct liftobj { // objtype 0x30
	struct defaultobj base;
	/*0x5c*/ s16 pads[4];
	/*0x64*/ struct doorobj *doors[4];
	/*0x74*/ f32 dist;
	/*0x78*/ f32 speed;
	/*0x7c*/ f32 accel;
	/*0x80*/ f32 maxspeed;
	/*0x84*/ s8 soundtype;
	/*0x85*/ s8 levelcur;
	/*0x86*/ s8 levelaim;
	/*0x88*/ struct coord prevpos;
};

struct linksceneryobj { // objtype 0x31
	u32 unk00;
	struct defaultobj *trigger;
	struct defaultobj *unexp;
	struct defaultobj *exp;
	struct linksceneryobj *next;
};

struct blockedpathobj { // objtype 0x32
	u32 unk00;
	struct defaultobj *blocker;
	s16 waypoint1;
	s16 waypoint2;
	struct blockedpathobj *next;
};

struct hoverbikeobj { // objtype 0x33
	struct defaultobj base;
	struct hov hov;
	/*0x09c*/ f32 speed[2];
	/*0x0a4*/ f32 prevpos[2];
	/*0x0ac*/ f32 w;
	/*0x0b0*/ f32 rels[2];
	/*0x0b8*/ f32 exreal;
	/*0x0bc*/ f32 ezreal;
	/*0x0c0*/ f32 ezreal2;
	/*0x0c4*/ f32 leanspeed;
	/*0x0c8*/ f32 leandiff;
	/*0x0cc*/ u32 maxspeedtime240;
	/*0x0d0*/ f32 speedabs[2];
	/*0x0d8*/ f32 speedrel[2];
};

struct hoverpropobj { // objtype 0x35
	struct defaultobj base;
	struct hov hov;
};

struct fanobj { // objtype 0x36
	struct defaultobj base;
	/*0x5c*/ f32 yrot;
	/*0x60*/ f32 yrotprev;
	/*0x64*/ f32 ymaxspeed;
	/*0x68*/ f32 yspeed;
	/*0x6c*/ f32 yaccel;
	/*0x70*/ s8 on;
};

struct hovercarobj { // objtype 0x37
	struct defaultobj base;
	/*0x5c*/ u8 *ailist;
	/*0x60*/ u16 aioffset;
	/*0x62*/ s16 aireturnlist;
	/*0x64*/ f32 speed;
	/*0x68*/ f32 speedaim;
	/*0x6c*/ f32 speedtime60;
	/*0x70*/ f32 turnyspeed60;
	/*0x74*/ f32 turnxspeed60;
	/*0x78*/ f32 turnrot60;
	/*0x7c*/ f32 roty;
	/*0x80*/ f32 rotx;
	/*0x84*/ f32 rotz;
	/*0x88*/ struct path *path;
	/*0x8c*/ s32 nextstep;
	/*0x90*/ s16 status;
	/*0x92*/ s16 dead;
	/*0x94*/ s16 deadtimer60;
	/*0x96*/ s16 sparkstimer60;
};

struct padeffectobj { // objtype 0x38
	u32 unk00;
	s32 effect;
	s32 pad;
};

struct chopperobj { // objtype 0x39
	struct defaultobj base;
	/*0x5c*/ u8 *ailist;
	/*0x60*/ u16 aioffset;
	/*0x62*/ s16 aireturnlist;
	union {
		struct {
			/*0x64*/ f32 speed;
			/*0x68*/ f32 speedaim;
			/*0x6c*/ f32 speedtime60;
		};
		struct coord fall;
	};
	/*0x70*/ u32 turnyspeed60;
	/*0x74*/ u32 turnxspeed60;
	/*0x78*/ f32 turnrot60;
	/*0x7c*/ f32 roty;
	/*0x80*/ f32 rotx;
	/*0x84*/ f32 rotz;
	/*0x88*/ struct path *path;
	/*0x8c*/ s32 nextstep;
	/*0x90*/ s16 weaponsarmed;
	/*0x92*/ s16 ontarget;
	/*0x94*/ s16 target;
	/*0x96*/ u8 attackmode;
	/*0x97*/ u8 cw;
	/*0x98*/ f32 vx;
	/*0x9c*/ f32 vy;
	/*0xa0*/ f32 vz;
	/*0xa4*/ f32 power;
	/*0xa8*/ f32 otx;
	/*0xac*/ f32 oty;
	/*0xb0*/ f32 otz;
	/*0xb4*/ f32 bob;
	/*0xb8*/ f32 bobstrength;
	/*0xbc*/ u32 targetvisible;
	/*0xc0*/ s32 timer60;
	/*0xc4*/ s32 patroltimer60;
	/*0xc8*/ u32 gunturnyspeed60;
	/*0xcc*/ u32 gunturnxspeed60;
	/*0xd0*/ f32 gunroty;
	/*0xd4*/ f32 gunrotx;
	/*0xd8*/ f32 barrelrotspeed;
	/*0xdc*/ f32 barrelrot;
	/*0xe0*/ struct fireslotthing *fireslotthing;
	/*0xe4*/ bool dead;
};

struct mineobj { // objtype 0x3a
	struct defaultobj base;
};

struct escalatorobj { // objtype 0x3b
	struct defaultobj base;
	/*0x5c*/ s32 frame;
	/*0x60*/ struct coord prevpos;
};

struct eyespy {
	/*0x00*/ struct prop *prop;
	/*0x04*/ struct coord look;
	/*0x10*/ struct coord up;
	/*0x1c*/ f32 theta; // turn angle in degrees
	/*0x20*/ f32 costheta;
	/*0x24*/ f32 sintheta;
	/*0x28*/ f32 verta;
	/*0x2c*/ f32 cosverta;
	/*0x30*/ f32 sinverta;
	/*0x34*/ u8 init;
	/*0x35*/ u8 initialised;
	/*0x36*/ s8 startuptimer60;
	/*0x37*/ s8 active;
	/*0x38*/ s8 buttonheld;
	/*0x39*/ s8 camerabuttonheld;
	/*0x3a*/ s16 bobdir;
	/*0x3c*/ u8 bobtimer;
	/*0x3d*/ u8 bobactive;
	/*0x40*/ struct coord vel;
	/*0x4c*/ struct coord unk4c;
	/*0x58*/ f32 speed;
	/*0x5c*/ f32 oldground;
	/*0x60*/ f32 height; // height above ground - 30 to 160 on G5 and CI training, 80 to 160 elsewhere
	/*0x64*/ f32 gravity;
	/*0x68*/ s8 camerashuttertime;
	/*0x69*/ u8 hit;
	/*0x6a*/ u8 opendoor;
	/*0x6b*/ u8 mode;
	/*0x6c*/ f32 velf[2];
	/*0x74*/ f32 vels[2];
	/*0x7c*/ f32 pitch;
};

struct audiohandle {
	u32 unk00;
};

/**
 * List of guns that the player has equipped and the amount of time they've been
 * equipped for. It's used to determine the weapon of choice for the endscreen.
 * The time is increased for the equipped weapon on each tick.
 *
 * The list is only 10 items long. If an 11th item is used, the least used item
 * in the list will be removed.
 */
struct gunheld {
	s32 weapon1;
	s32 weapon2;
	s32 totaltime240_60;
};

struct playerbond {

	// unk00.x = look vector x (-1 to +1)
	// unk00.y = always 0?
	// unk00.z = look vector z (-1 to +1)
	/*0x0338 0x036c*/ struct coord unk00;

	/*0x0344 0x0378*/ f32 width; // always 30?

	/*0x0348 0x037c*/ struct coord unk10;

	// unk1c.x = affected by both left/right and up/down looking
	// unk1c.y = vertical look vector (-1 for down, 1 for up)
	// unk1c.z = affected by both left/right and up/down looking
	/*0x0354 0x0388*/ struct coord unk1c;

	// unk28.x = affected by both horiz and vertical angle
	// unk28.y = 0 when looking up or down, .999 when looking horizontal
	// unk28.z = pos.z
	/*0x0360 0x0394*/ struct coord unk28;
};

struct threat {
	struct prop *prop;
	s16 x1; // x1
	s16 y1; // y1
	s16 x2; // x2
	s16 y2; // y2
};

struct beam {
	/*0x00*/ s8 age;
	/*0x01*/ s8 weaponnum;
	/*0x04*/ struct coord from;
	/*0x10*/ struct coord dir;
	/*0x1c*/ f32 maxdist;
	/*0x20*/ f32 speed;
	/*0x24*/ f32 mindist;
	/*0x28*/ f32 dist;
};

struct abmag {
	// When the gauge uses separate bars, this is zero/unused. When the gauge
	// uses merged bars, this is the same figure as displayed on the HUD.
	/*0x00*/ s16 loadedammo;

	// Counts up to 255 when firing or reloading. It's used to determine the
	// brightness of the bar in the ammo gauge.
	/*0x02*/ s16 timer60;

	// When firing, this is the number of bars still loaded + any bars recently
	// fired which are fading to empty.
	// When loading, this is the number of bars which are loaded and don't have
	// a fade effect on them.
	// In other words, it's a reference to where the fade effects start and is
	// also a reference for the timer.
	/*0x04*/ s8 ref;

	// When positive, is the number of slots remaining to settle when reloading,
	// including slots which are fully empty.
	// When negative, is the number of slots remaining to settle when firing.
	/*0x05*/ s8 change;

	/*0x06*/ u16 alignment;
};

// Weapon data per hand
struct hand {
	struct gset gset;
	/*0x063c*/ s8 firing;
	/*0x063d*/ s8 flashon;
	/*0x063e*/ u8 gunon;
	/*0x063f*/ s8 visible;
	/*0x0640*/ s8 inuse; // true if hand is holding a gun, false if not
	/*0x0644*/ bool triggeron;
	/*0x0648*/ bool triggerprev;
	/*0x064c*/ bool triggerreleased;
	/*0x0650*/ s32 count;
	/*0x0654*/ s32 count60;
	/*0x0658*/ u32 mode;
	/*0x065c*/ u32 modenext; // 0 = idle, 9 = reloading
	/*0x0660*/ u32 numfires;
	/*0x0664*/ u32 numshotguncarts;
	/*0x0668*/ u32 refiretime;
	/*0x066c*/ u32 typechange;
	/*0x0670*/ s32 pausetime60;
	/*0x0674*/ u32 pausechange;
	/*0x0678*/ u32 nextprevchange; // "
	/*0x067c*/ struct coord posstart;
	/*0x0688*/ f32 rotxstart;
	/*0x068c*/ struct coord posend;
	/*0x0698*/ f32 rotxend;
	/*0x069c*/ struct coord posoffset;
	/*0x06a8*/ f32 rotxoffset;
	/*0x06ac*/ Mtxf posrotmtx;
	/*0x06ec*/ bool useposrot;
	/*0x06f0*/ struct coord damppos;
	/*0x06fc*/ struct coord damplook;
	/*0x0708*/ struct coord dampup;
	/*0x0714*/ struct coord damppossum;
	/*0x0720*/ struct coord damplooksum;
	/*0x072c*/ struct coord dampupsum;
	/*0x0738*/ f32 blendpos[4][3];
	/*0x0768*/ f32 blendlook[4][3];
	/*0x0798*/ f32 blendup[4][3];
	/*0x07c8*/ s32 curblendpos;
	/*0x07cc*/ f32 dampt;
	/*0x07d0*/ f32 blendscale;
	/*0x07d4*/ f32 blendscale1;
	/*0x07d8*/ s32 sideflag;
	/*0x07dc*/ struct coord adjustdamp;
	/*0x07e8*/ struct coord adjustpos;
	/*0x07f4*/ f32 xshift;
	/*0x07f8*/ struct coord aimpos;
	/*0x0804*/ struct audiohandle *audiohandle2;
	/*0x0808*/ struct audiohandle *audiohandle3;
	/*0x080c*/ s32 allowshootframe;
	/*0x0810*/ s32 lastshootframe60;
	/*0x0814*/ struct beam beam;
	/*0x0840*/ f32 noiseradius;
	/*0x0844*/ u32 fingerroty;
	/*0x0848*/ u32 slidetrans;
	/*0x084c*/ u32 slideinc;
	/*0x0850*/ struct weaponobj *rocket;
	/*0x0854*/ bool firedrocket;
	/*0x0858*/ s32 loadedammo[2];
	/*0x0860*/ s32 clipsizes[2];
	/*0x0868*/ f32 angledamper;
	/*0x086c*/ u32 lastrotangx;
	/*0x0870*/ u32 lastrotangy;
	/*0x0874*/ f32 matmot1;
	/*0x0878*/ f32 matmot2;
	/*0x087c*/ f32 matmot3;
	/*0x0880*/ u32 unk0880;
	/*0x0884*/ u32 unk0884;
	/*0x0888*/ f32 loadslide;
	/*0x088c*/ f32 upgrademult[12];
	/*0x08bc*/ f32 finalmult[12];
	/*0x08ec*/ Mtxf cammtx;
	/*0x092c*/ Mtxf posmtx;
	/*0x096c*/ Mtxf prevmtx;
	/*0x09ac*/ struct coord muzzlepos;
	/*0x09b8*/ f32 muzzlez;
	/*0x09bc*/ struct model unk09bc;
	/*0x09e0*/ struct anim anim;
	/*0x0a6c*/ u32 unk0a6c[32];
	/*0x0aec*/ u32 handsavedata[32];
	/*0x0b6c*/ u32 unk0b6c;
	/*0x0b70*/ u32 unk0b70;
	/*0x0b74*/ u32 unk0b74;
	/*0x0b78*/ u32 unk0b78;
	/*0x0b7c*/ u32 unk0b7c;
	/*0x0b80*/ u32 unk0b80;
	/*0x0b84*/ u32 unk0b84;
	/*0x0b88*/ u32 unk0b88;
	/*0x0b8c*/ struct anim *unk0b8c;
	/*0x0b90*/ s32 burstbullets;
	/*0x0b94*/ struct coord hitpos;
	/*0x0ba0*/ u32 unk0ba0;
	/*0x0ba4*/ u32 unk0ba4;
	/*0x0ba8*/ u32 unk0ba8;
	/*0x0bac*/ u32 unk0bac;
	/*0x0bb0*/ u32 unk0bb0;
	/*0x0bb4*/ u32 unk0bb4;
	/*0x0bb8*/ u32 unk0bb8;
	/*0x0bbc*/ u32 unk0bbc;
	/*0x0bc0*/ u32 unk0bc0;
	/*0x0bc4*/ u32 unk0bc4;
	/*0x0bc8*/ u32 unk0bc8;
	/*0x0bcc*/ u32 unk0bcc;
	/*0x0bd0*/ u32 unk0bd0;
	/*0x0bd4*/ u32 unk0bd4;
	/*0x0bd8*/ u32 unk0bd8;
	/*0x0bdc*/ u32 unk0bdc;
	/*0x0be0*/ u32 unk0be0;
	/*0x0be4*/ u32 unk0be4;
	/*0x0be8*/ u32 unk0be8;
	/*0x0bec*/ u32 unk0bec;
	/*0x0bf0*/ u32 unk0bf0;
	/*0x0bf4*/ u32 unk0bf4;
	/*0x0bf8*/ u32 unk0bf8;
	/*0x0bfc*/ u32 unk0bfc;
	/*0x0c00*/ u32 unk0c00;
	/*0x0c04*/ u32 unk0c04;
	/*0x0c08*/ u32 unk0c08;
	/*0x0c0c*/ u32 unk0c0c;
	/*0x0c10*/ u32 unk0c10;
	/*0x0c14*/ u8 lastdirvalid;
	/*0x0c18*/ struct coord lastshootdir;
	/*0x0c24*/ struct coord lastshootpos;
	/*0x0c30*/ s32 shotstotake;
	/*0x0c34*/ f32 shotremainder;
	/*0x0c38*/ u32 hitspershot;
	/*0x0c3c*/ s32 state;
	/*0x0c40*/ s32 stateminor;
	/*0x0c44*/ u32 stateflags;
	/*0x0c48*/ u32 statemode;
	/*0x0c4c*/ s32 stateframes;
	/*0x0c50*/ s32 statecycles;
	/*0x0c54*/ s32 statelastframe;
	/*0x0c58*/ Mtxf muzzlemat;
	/*0x0c98*/ f32 gs_float1;
	/*0x0c9c*/ f32 gs_float2;
	/*0x0ca0*/ f32 gs_float3;
	/*0x0ca4*/ f32 gs_float4;
	/*0x0ca8*/ s32 gs_int1;
	/*0x0cac*/ s32 gs_int2;
	/*0x0cb0*/ s32 gs_int3;
	/*0x0cb4*/ s32 gs_int4;
	/*0x0cb8*/ s32 animload;
	/*0x0cbc*/ s32 animframeinc;
#if VERSION >= VERSION_PAL_FINAL
	/*0x0cc0*/ f32 animframeincfreal;
#else
	/*0x0cc0*/ u32 animframeincfreal;
#endif
	/*0x0cc4*/ u32 animmode;
	/*0x0cc8*/ u8 unk0cc8_01 : 1;
	/*0x0cc8*/ u8 unk0cc8_02 : 1;
	/*0x0cc8*/ u8 unk0cc8_03 : 1;
	/*0x0cc8*/ u8 unk0cc8_04 : 1;
	/*0x0cc8*/ u8 unk0cc8_05 : 1;
	/*0x0cc8*/ u8 unk0cc8_06 : 1;
	/*0x0cc8*/ u8 unk0cc8_07 : 1;
	/*0x0cc8*/ u8 unk0cc8_08 : 1;
	/*0x0cc9*/ u8 animloopcount;
	/*0x0ccc*/ f32 crosspos[2];
	/*0x0cd4*/ f32 guncrosspossum[2];
	/*0x0cdc*/ u32 statejob;
	/*0x0ce0*/ s32 statevar1;
	/*0x0ce4*/ s32 attacktype;
	/*0x0ce8*/ struct guncmd *unk0ce8;
	/*0x0cec*/ ubool unk0cec;
	/*0x0cf0*/ struct coord unk0cf0;
	/*0x0cfc*/ struct coord unk0cfc;
	/*0x0d08*/ f32 ganstarot;
	/*0x0d0c*/ s16 primetimer;
	/*0x0d0e*/ u8 unk0d0e_00 : 4;
	/*0x0d0e*/ u8 unk0d0e_04 : 3;
	/*0x0d0e*/ u8 unk0d0e_07 : 1;
	/*0x0d0f*/ u8 unk0d0f_00 : 2;
	/*0x0d0f*/ u8 unk0d0f_02 : 1;
	/*0x0d0f*/ u8 unk0d0f_03 : 1;
	/*0x0d0f*/ u8 unk0d0f_04 : 4;
	/*0x0d10*/ u32 unk0d10;
	/*0x0d14*/ u32 unk0d14;
	/*0x0d18*/ u32 unk0d18;
	/*0x0d1c*/ u32 unk0d1c;
	/*0x0d20*/ u32 unk0d20;
	/*0x0d24*/ u32 unk0d24;
	/*0x0d28*/ u32 unk0d28;
	/*0x0d2c*/ u32 unk0d2c;
	/*0x0d30*/ u32 unk0d30;
	/*0x0d34*/ u32 unk0d34;
	/*0x0d38*/ u32 unk0d38;
	/*0x0d3c*/ u32 unk0d3c;
	/*0x0d40*/ u32 unk0d40;
	/*0x0d44*/ u32 unk0d44;
	/*0x0d48*/ u32 unk0d48;
	/*0x0d4c*/ u32 unk0d4c;
	/*0x0d50*/ u32 unk0d50;
	/*0x0d54*/ u32 unk0d54;
	/*0x0d58*/ u32 unk0d58;
	/*0x0d5c*/ u32 unk0d5c;
	/*0x0d60*/ u32 unk0d60;
	/*0x0d64*/ u32 unk0d64;
	/*0x0d68*/ u32 unk0d68;
	/*0x0d6c*/ u32 unk0d6c;
	/*0x0d70*/ u32 unk0d70;
	/*0x0d74*/ u16 gunroundsspent[4]; // actually a countdown timer
	/*0x0d7c*/ u32 ispare1;
	/*0x0d80*/ struct guncmd *unk0d80;
	/*0x0d84*/ struct audiohandle *audiohandle;
	/*0x0d88*/ u32 ispare4;
	/*0x0d8c*/ u32 ispare5;
	/*0x0d90*/ u32 ispare6;
	/*0x0d94*/ u32 ispare7;
	/*0x0d98*/ u32 ispare8;
	/*0x0d9c*/ u32 ispare9;
	/*0x0da0*/ u32 ispare10;
	/*0x0da4*/ f32 fspare1;
	/*0x0da8*/ f32 fspare2;
	/*0x0dac*/ f32 fspare3;
	/*0x0db0*/ f32 fspare4;
	/*0x0db4*/ f32 fspare5;
	/*0x0db8*/ f32 gunsmokepoint;
	/*0x0dbc*/ u32 fspare7;
	/*0x0dc0*/ u32 fspare8;
	/*0x0dc4*/ struct abmag abmag;
	/*0x0dcc*/ u32 unk0dcc;
	/*0x0dd0*/ u32 unk0dd0;
	/*0x0dd4*/ s32 unk0dd4;
	/*0x0dd8*/ u32 unk0dd8;
};

struct player0610 {
	/*0x00*/ u16 unk00;
	/*0x02*/ u16 unk02;
	/*0x04*/ u16 unk04;
	/*0x06*/ u16 unk06;
	/*0x08*/ u16 unk08;
	/*0x0a*/ u16 unk0a;
	/*0x0c*/ u16 unk0c;
	/*0x0e*/ u16 unk0e;
};

struct gunctrl {
	/*0x1580*/ s8 weaponnum;
	/*0x1581*/ s8 prevweaponnum; // previously drawn weapon, switched to when throwing Dragon/Laptop or when ammo depleted
	/*0x1582*/ s8 switchtoweaponnum; // weaponnum to change to
	/*0x1583*/ u8 dualwielding : 1;
	/*0x1583*/ u8 unk1583_01 : 1;
	/*0x1583*/ u8 invertgunfunc : 1;
	/*0x1583*/ u8 gangsta : 1;
	/*0x1583*/ u8 unk1583_04 : 1;
	/*0x1583*/ u8 wantammo : 1;
	/*0x1583*/ u8 unk1583_06 : 1;
	/*0x1583*/ u8 passivemode : 1;
	/*0x1584*/ s32 gunmemnew;
	/*0x1588*/ s32 gunmemtype;
	/*0x158c*/ void *unk158c;
	/*0x1590*/ u32 unk1590;
	/*0x1594*/ struct modelfiledata *unk1594;
	/*0x1598*/ s32 unk1598;
	/*0x159c*/ u16 handfilenum;
	/*0x15a0*/ s32 unk15a0;
	/*0x15a4*/ s32 unk15a4;
	/*0x15a8*/ u32 unk15a8;
	/*0x15ac*/ u32 unk15ac;
	/*0x15b0*/ u8 unk15b0;
	/*0x15b1*/ u8 unk15b1;
	/*0x15b4*/ u32 unk15b4;
	/*0x15b8*/ u32 unk15b8;
	/*0x15bc*/ u32 unk15bc;
	/*0x15c0*/ u32 unk15c0;
	/*0x15c4*/ u32 unk15c4;
	/*0x15c8*/ u32 unk15c8;
	/*0x15cc*/ u32 unk15cc;
	/*0x15d0*/ u32 unk15d0;
	/*0x15d4*/ u32 unk15d4;
	/*0x15d8*/ u32 unk15d8;
	/*0x15dc*/ struct abmag abmag;
	/*0x15e4*/ s8 ammotypes[2];
	/*0x15e6*/ u8 action;
	/*0x15e7*/ u8 fnfader;
	/*0x15e8*/ u8 upgradewant;
	/*0x15e9*/ s8 lastmag;
	/*0x15ea*/ u8 gunmemowner;
	/*0x15eb*/ s8 gunlocktimer;
	/*0x15ec*/ u16 curfnstr;
	/*0x15ee*/ u8 fnstrtimer;
	/*0x15ef*/ u8 guntypetimer;
	/*0x15f0*/ u8 guntypefader;
	/*0x15f2*/ u16 curgunstr;
	/*0x15f4*/ u8 paddingashdown;
};

struct player {
	/*0x0000*/ s32 cameramode;
	/*0x0004*/ struct coord memcampos; // Room that the camera is in (differs from the player's room during cutscenes and Slayer rocket)
	/*0x0010*/ u16 visionmode;
	/*0x0014*/ s32 memcamroom;
	/*0x0018*/ struct coord eraserpos;
	/*0x0024*/ f32 eraserpropdist;
	/*0x0028*/ u32 eraserbgdist;
	/*0x002c*/ u32 eraserdepth;
	/*0x0030*/ bool isfalling;
	/*0x0034*/ s32 fallstart; // lvframe60 when player started falling
	/*0x0038*/ struct coord globaldrawworldoffset;
	/*0x0044*/ struct coord globaldrawcameraoffset;
	/*0x0050*/ struct coord globaldrawworldbgoffset;
	/*0x005c*/ Mtx *matrix5c;
	/*0x0060*/ Mtx *matrix60;
	/*0x0064*/ Mtxf *matrix64;
	/*0x0068*/ Mtxf *matrix68;
	/*0x006c*/ Mtxf *matrix6c;
	/*0x0070*/ f32 sumground;
	/*0x0074*/ f32 vv_manground; // Feet Y value in absolute coordinates
	/*0x0078*/ f32 vv_ground; // Ground Y value in absolute coordinates
	/*0x007c*/ struct coord bdeltapos; // Only y is used? Negative when falling

	// These crouch fields are related to recovering after a fall - not actual crouching
	/*0x0088*/ f32 sumcrouch;
	/*0x008c*/ f32 crouchheight; // Negative, is Y offset to regular standing height
	/*0x0090*/ s32 crouchtime240; // Set to 60 when landing, counts down
	/*0x0094*/ f32 crouchfall; // -90 when slowing the descent, increments back to 0 while returning to stand

	/*0x0098*/ s32 swaypos;
	/*0x009c*/ f32 swayoffset;
	/*0x00a0*/ f32 swaytarget;
	/*0x00a4*/ f32 swayoffset0;
	/*0x00a8*/ f32 swayoffset2;
	/*0x00ac*/ s32 crouchpos;
	/*0x00b0*/ s32 autocrouchpos;
	/*0x00b4*/ f32 crouchoffset;
	/*0x00b8*/ f32 crouchspeed;
	/*0x00bc*/ struct prop *prop;
	/*0x00c0*/ bool bondperimenabled;
	/*0x00c4*/ u32 devicesactive;
	/*0x00c8*/ s32 badrockettime;
	/*0x00cc*/ f32 gunspeed;
	/*0x00d0*/ s32 bondactivateorreload;
	/*0x00d4*/ struct model *model00d4;
	/*0x00d8*/ bool isdead;
	/*0x00dc*/ f32 bondhealth; // frac (range 0-1)
	/*0x00e0*/ struct audiohandle *chokehandle;
	/*0x00e4*/ f32 oldhealth;
	/*0x00e8*/ f32 oldarmour;
	/*0x00ec*/ f32 apparenthealth;
	/*0x00f0*/ f32 apparentarmour;
	/*0x00f4*/ f32 damageshowtime;
	/*0x00f8*/ f32 healthshowtime;
	/*0x00fc*/ u32 healthshowmode;
	/*0x0100*/ s32 docentreupdown;
	/*0x0104*/ u32 lastupdown60;
	/*0x0108*/ s32 prevupdown;
	/*0x010c*/ s32 movecentrerelease;
	/*0x0110*/ bool lookaheadcentreenabled;
	/*0x0114*/ bool automovecentreenabled;
	/*0x0118*/ bool fastmovecentreenabled;
	/*0x011c*/ bool automovecentre;
	/*0x0120*/ bool insightaimmode;

	/*0x0124*/ bool autoyaimenabled;
	/*0x0128*/ f32 autoaimy;
	/*0x012c*/ struct prop *autoyaimprop;
	/*0x0130*/ s32 autoyaimtime60;

	/*0x0134*/ bool autoxaimenabled;
	/*0x0138*/ f32 autoaimx;
	/*0x013c*/ struct prop *autoxaimprop;
	/*0x0140*/ s32 autoxaimtime60;

	/*0x0144*/ f32 vv_theta;   // turn angle in degrees
	/*0x0148*/ f32 speedtheta; // turn speed
	/*0x014c*/ f32 vv_costheta;
	/*0x0150*/ f32 vv_sintheta;

	/*0x0154*/ f32 vv_verta;   // look up/down angle. 0 = horizontal, 90 = up
	/*0x0158*/ f32 vv_verta360;
	/*0x015c*/ f32 speedverta; // look up/down speed
	/*0x0160*/ f32 vv_cosverta;
	/*0x0164*/ f32 vv_sinverta;

	/*0x0168*/ f32 speedsideways;    // range -1 to 1
	/*0x016c*/ f32 speedstrafe;
	/*0x0170*/ f32 speedforwards;    // range -1 to 1
	/*0x0174*/ f32 speedboost;       // speed multiplier - ranges from 1 to 1.25 - kicks in after 3 seconds of full speed
	/*0x0178*/ s32 speedmaxtime60;   // amount of time player has held full forward speed
	/*0x017c*/ f32 bondshotspeed[3];
	/*0x0188*/ f32 bondfadetime60;
	/*0x018c*/ f32 bondfadetimemax60;
	/*0x0190*/ f32 bondfadefracold;
	/*0x0194*/ f32 bondfadefracnew;
	/*0x0198*/ f32 bondbreathing;
	/*0x019c*/ s32 activatetimelast;
	/*0x01a0*/ s32 activatetimethis;
	/*0x01a4*/ struct coord moveinitspeed;
	/*0x01b0*/ s32 bondmovemode;
	/*0x01b4*/ f32 gunextraaimx;
	/*0x01b8*/ f32 gunextraaimy;
	/*0x01bc*/ s32 playwatchup;
	/*0x01c0*/ struct anim unk01c0;
	/*0x024c*/ s16 invdowntime;
	/*0x024e*/ s16 usedowntime;
	/*0x0250*/ u8 activemenumode;
	/*0x0251*/ u8 ecol_1;
	/*0x0252*/ u8 ecol_2;
	/*0x0253*/ u8 ecol_3;
	/*0x0254*/ s32 erasertime; // related to FarSight's auto tracking
	/*0x0258*/ f32 autoeraserdist;
	/*0x025c*/ struct prop *autoerasertarget;
	/*0x0260*/ s32 aimtaptime;
	/*0x0264*/ struct weaponobj *slayerrocket;
	/*0x0268*/ bool eyesshut;
	/*0x026c*/ f32 eyesshutfrac;
	/*0x0270*/ u8 epcol_0;
	/*0x0271*/ u8 epcol_1;
	/*0x0272*/ u8 epcol_2;
	/*0x0273*/ u8 flashbang;
	/*0x0274*/ bool waitforzrelease;
	/*0x0278*/ f32 shieldshowrot;
	/*0x027c*/ u32 shieldshowrnd;
	/*0x0280*/ f32 shieldshowtime;
	/*0x0284*/ s16 bondprevrooms[8];
	/*0x0294*/ f32 liftground;
	/*0x0298*/ struct prop *lift;
	/*0x029c*/ f32 ladderupdown;
	/*0x02a0*/ struct coord laddernormal;
	/*0x02ac*/ bool onladder;
	/*0x02b0*/ bool inlift;
	/*0x02b4*/ struct coord posdie;
	/*0x02c0*/ struct coord bonddampeyesum;
	/*0x02cc*/ struct coord bonddampeye;
	/*0x02d8*/ s32 colourscreenred;
	/*0x02dc*/ s32 colourscreengreen;
	/*0x02e0*/ s32 colourscreenblue;
	/*0x02e4*/ f32 colourscreenfrac;
	/*0x02e8*/ f32 colourfadetime60;
	/*0x02ec*/ f32 colourfadetimemax60;
	/*0x02f0*/ s32 colourfaderedold;
	/*0x02f4*/ s32 colourfaderednew;
	/*0x02f8*/ s32 colourfadegreenold;
	/*0x02fc*/ s32 colourfadegreennew;
	/*0x0300*/ s32 colourfadeblueold;
	/*0x0304*/ s32 colourfadebluenew;
	/*0x0308*/ f32 colourfadefracold;
	/*0x030c*/ f32 colourfadefracnew;
	/*0x0310*/ struct coord bondprevpos;
	/*0x031c*/ f32 thetadie;
	/*0x0320*/ f32 vertadie;
	/*0x0324*/ u32 bondtype; // OUTFIT constant
	/*0x0328*/ bool startnewbonddie;
	/*0x032c*/ bool redbloodfinished;
	/*0x0330*/ bool deathanimfinished;
	/*0x0334*/ s32 controldef;
	/*0x0338*/ struct playerbond bonddie;
	/*0x036c*/ struct playerbond bond2;
	/*0x03a0*/ bool resetheadpos;
	/*0x03a4*/ bool resetheadrot;
	/*0x03a8*/ bool resetheadtick;
	/*0x03ac*/ s32 headanim;
	/*0x03b0*/ f32 headdamp;
	/*0x03b4*/ s32 headwalkingtime60;
	/*0x03b8*/ f32 headamplitude;
	/*0x03bc*/ f32 sideamplitude;
	/*0x03c0*/ struct coord headpos;
	/*0x03cc*/ struct coord headlook;
	/*0x03d8*/ struct coord headup;
	/*0x03e4*/ struct coord headpossum;
	/*0x03f0*/ struct coord headlooksum;
	/*0x03fc*/ struct coord headupsum;
	/*0x0408*/ struct coord headbodyoffset;
	/*0x0414*/ f32 standheight;
	/*0x0418*/ struct coord standbodyoffset;
	/*0x0424*/ f32 standfrac;
	/*0x0428*/ struct coord standlook[2];
	/*0x0440*/ struct coord standup[2];
	/*0x0458*/ s32 standcnt;
	/*0x045c*/ struct model model;
	/*0x0480*/ struct eyespy *eyespy;
	/*0x0484*/ u8 *unk0484; // pointer to vtx buffer?
	/*0x0488*/ u8 *unk0488; // pointer to vtx buffer?
	/*0x048c*/ bool aborted;
	/*0x0490*/ s32 eyespydarts;
	/*0x0494*/ union modelrwdata *bondheadsave[30];
	/*0x050c*/ u32 unk050c;
	/*0x0510*/ Mtxf bondheadmatrices[4];
	/*0x0610*/ struct player0610 viewport[2];
	/*0x0630*/ s16 viewwidth;  // 320 lo-res, 640 hi-res
	/*0x0632*/ s16 viewheight; // 220 regardless of res
	/*0x0634*/ s16 viewleft;   // 0
	/*0x0636*/ s16 viewtop;    // 0
	/*0x0638*/ struct hand hands[2];
	struct gunctrl gunctrl;
	/*0x15f8*/ f32 gunposamplitude;
	/*0x15fc*/ f32 gunxamplitude;
	/*0x1600*/ s32 doautoselect;
	/*0x1604*/ u32 playertriggeron;
	/*0x1608*/ u32 playertriggerprev;
	/*0x160c*/ s32 playertrigtime240;
	/*0x1610*/ s32 curguntofire; // 0 or 1, for dual wielding
	/*0x1614*/ u8 gunshadecol[4];
	/*0x1618*/ s16 resetshadecol;
	/*0x161a*/ u16 floorcol;
	/*0x161c*/ u16 floorflags;
	/*0x161e*/ u8 floortype;
	/*0x1620*/ u32 aimtype;
	/*0x1624*/ struct threat lookingatprop;
	/*0x1630*/ struct threat cmpfollowprops[4];
	/*0x1660*/ f32 crosspos[2];
	/*0x1668*/ f32 crosspossum[2];
	/*0x1670*/ f32 guncrossdamp;
	/*0x1674*/ f32 crosspos2[2];
	/*0x167c*/ f32 crosssum2[2];
	/*0x1684*/ f32 gunaimdamp;
	/*0x1688*/ struct coord aimangle;
	/*0x1694*/ Mtxf aimanglemat;
	/*0x16d4*/ bool copiedgoldeneye;
	/*0x16d8*/ u32 gunammooff;
	/*0x16dc*/ f32 gunsync;
	/*0x16e0*/ f32 syncchange;
	/*0x16e4*/ f32 synccount;
	/*0x16e8*/ s32 syncoffset;
	/*0x16ec*/ f32 cyclesum;
	/*0x16f0*/ f32 gunampsum;
	/*0x16f4*/ f32 gunzoomfovs[3]; // saved zoom levels/fovs for sniper, farsight and horizon scanner
	/*0x1700*/ s32 lastroomforoffset;
	/*0x1704*/ f32 c_screenwidth;
	/*0x1708*/ f32 c_screenheight;
	/*0x170c*/ f32 c_screenleft;
	/*0x1710*/ f32 c_screentop;
	/*0x1714*/ f32 c_perspnear;
	/*0x1718*/ f32 c_perspfovy;
	/*0x171c*/ f32 c_perspaspect;
	/*0x1720*/ f32 c_halfwidth;
	/*0x1724*/ f32 c_halfheight;
	/*0x1728*/ f32 c_scalex;
	/*0x172c*/ f32 c_scaley;
	/*0x1730*/ f32 c_recipscalex;
	/*0x1734*/ f32 c_recipscaley;
	/*0x1738*/ void *unk1738;
	/*0x173c*/ Mtx *unk173c;
	/*0x1740*/ Mtxf *matrix1740;
	/*0x1744*/ s32 c_viewfmdynticknum;
	/*0x1748*/ u32 unk1748;
	/*0x174c*/ Mtxf *unk174c;
	/*0x1750*/ void *unk1750;
	/*0x1754*/ Mtxf *unk1754;
	/*0x1758*/ Mtx *unk1758;
	/*0x175c*/ void *unk175c;
	/*0x1760*/ Mtxf *prev1740;
	/*0x1764*/ s32 c_prevviewfmdynticknum;
	/*0x1768*/ Mtxf *unk1768;
	/*0x176c*/ f32 c_scalelod60;
	/*0x1770*/ f32 c_scalelod;
	/*0x1774*/ f32 c_lodscalez;
	/*0x1778*/ u32 c_lodscalezu32;
	/*0x177c*/ struct coord c_cameratopnorm;
	/*0x1788*/ struct coord c_cameraleftnorm;
	/*0x1794*/ f32 screenxminf;
	/*0x1798*/ f32 screenyminf;
	/*0x179c*/ f32 screenxmaxf;
	/*0x17a0*/ f32 screenymaxf;
	/*0x17a4*/ u32 gunsightoff;
	/*0x17a8*/ s32 ammoheldarr[33]; // ammo quantities not loaded into a gun
	/*0x182c*/ u32 unk182c;
	/*0x1830*/ u32 unk1830;
	/*0x1834*/ u32 unk1834;
	/*0x1838*/ u32 unk1838;
	/*0x183c*/ u32 unk183c;
	/*0x1840*/ f32 zoomintime;
	/*0x1844*/ f32 zoomintimemax;
	/*0x1848*/ f32 zoominfovy;
	/*0x184c*/ f32 zoominfovyold;
	/*0x1850*/ f32 zoominfovynew;
	/*0x1854*/ f32 fovy;
	/*0x1858*/ f32 aspect;
	/*0x185c*/ u32 hudmessoff;
	/*0x1860*/ s32 bondmesscnt;
	/*0x1864*/ struct invitem *weapons; // circular linked list, sorted
	/*0x1868*/ struct invitem *equipment; // slots, allocated, unsorted
	/*0x186c*/ s32 equipmaxitems;
	/*0x1870*/ u32 equipallguns;
	/*0x1874*/ u32 equipcuritem;
	/*0x1878*/ struct gunheld gunheldarr[10];
	/*0x18f0*/ s32 magnetattracttime;
	/*0x18f4*/ f32 angleoffset;
	/*0x18f8*/ u32 buthist[10];
	/*0x1920*/ u8 buthistindex;
	/*0x1921*/ u8 buthistlen;
	/*0x1922*/ u8 invincible;
	/*0x1924*/ s32 healthdamagetype; // 0-7, decreases based on amount of damage taken
	/*0x1928*/ f32 bondleandown;
	/*0x192c*/ bool mpmenuon;
	/*0x1930*/ u32 mpmenumode;
	/*0x1934*/ u32 mpquitconfirm;
	/*0x1938*/ u32 mpjoywascentre;
	/*0x193c*/ s32 damagetype;
	/*0x1940*/ u32 deathcount;
	/*0x1948*/ u32 oldcrosspos[2];
	/*0x194c*/ s32 lastkilltime60;
	/*0x1950*/ s32 lastkilltime60_2;
	/*0x1954*/ s32 lastkilltime60_3;
	/*0x1958*/ s32 lastkilltime60_4;
	/*0x195c*/ s32 lifestarttime60;
	/*0x1960*/ u32 killsthislife;
	/*0x1964*/ u32 healthdisplaytime60;
	/*0x1968*/ f32 guncloseroffset;
	/*0x196c*/ f32 shootrotx;
	/*0x1970*/ f32 shootroty;
	/*0x1974*/ char *award1;
	/*0x1978*/ char *award2;
	/*0x197c*/ struct coord chrmuzzlelastpos[2];
	/*0x1994*/ s32 chrmuzzlelast[2];
	/*0x199c*/ f32 healthscale;
	/*0x19a0*/ f32 armourscale;
	/*0x19a4*/ f32 speedgo;
	/*0x19a8*/ s32 sighttimer240;
	/*0x19ac*/ s32 crouchoffsetreal;
	/*0x19b0*/ s16 floorroom;
	/*0x19b2*/ u8 unk19b2;
	/*0x19b3*/ u8 dostartnewlife;
	/*0x19b4*/ f32 crouchoffsetsmall;
	/*0x19b8*/ s32 crouchoffsetrealsmall; // 0 = standing, -90 = squatting, can be between during transition
	/*0x19bc*/ f32 vv_height;     // 159 when Jo, regardless of crouch state
	/*0x19c0*/ f32 vv_headheight; // 172 when Jo, regardless of crouch state
	/*0x19c4*/ f32 vv_eyeheight;  // 159 when Jo, regardless of crouch state
	/*0x19c8*/ bool haschrbody;
	/*0x19cc*/ struct tiletype3 periminfo;
	/*0x19e4*/ struct tiletype3 perimshoot;
	/*0x19fc*/ f32 bondprevtheta;
	/*0x1a00*/ struct coord grabbedprevpos;
	/*0x1a0c*/ f32 grabbedrotoffset;
	/*0x1a10*/ struct coord grabbedposoffset;
	/*0x1a1c*/ s32 grabbeddoextra;
	/*0x1a20*/ f32 grabbedrotextra;
	/*0x1a24*/ s32 pausemode;
	/*0x1a28*/ s32 pausetime60;
	/*0x1a2c*/ struct coord grabbedposextra;
	/*0x1a38*/ f32 grabbedrotextrasum;
	/*0x1a3c*/ struct coord grabbedposextrasum;
	/*0x1a48*/ f32 bondtankthetaspeedsum;
	/*0x1a4c*/ f32 bondtankverta;
	/*0x1a50*/ f32 bondtankvertasum;
	/*0x1a54*/ f32 bondturrettheta;
	/*0x1a58*/ f32 bondturretthetasum;
	/*0x1a5c*/ f32 bondturretspeedsum;
	/*0x1a60*/ f32 bondturretside;
	/*0x1a64*/ f32 bondturretchange;
	/*0x1a68*/ s32 bondtankslowtime;
	/*0x1a6c*/ struct prop *hoverbike;
	/*0x1a70*/ struct coord bondvehicleoffset;
	/*0x1a7c*/ s32 bondvehiclemode;

	// All bondenter properties are related to mounting the hoverbike
	/*0x1a80*/ f32 bondentert;
	/*0x1a84*/ f32 bondentert2;
	/*0x1a88*/ u32 bondentertheta;
	/*0x1a8c*/ u32 bondenterverta;
	/*0x1a90*/ struct coord bondenterpos;
	/*0x1a9c*/ Mtxf bondentermtx;
	/*0x1adc*/ struct coord bondenteraim;

	/*0x1ae8*/ f32 bondonground;
	/*0x1aec*/ struct prop *tank;
	/*0x1af0*/ struct prop *unk1af0;
	/*0x1af4*/ u32 bondonturret;
	/*0x1af8*/ s32 walkinitmove;
	/*0x1afc*/ struct coord walkinitpos;
	/*0x1b08*/ Mtxf walkinitmtx;
	/*0x1b48*/ f32 walkinitt;
	/*0x1b4c*/ f32 walkinitt2;
	/*0x1b50*/ struct coord walkinitstart;
	/*0x1b5c*/ struct prop *grabbedprop;
	/*0x1b60*/ f32 bondgrabthetaspeedsum;
	/*0x1b64*/ s32 grabstarttime;
	/*0x1b68*/ f32 autoaimdamp;
	/*0x1b6c*/ struct coord bondforcespeed;
	/*0x1b78*/ bool bondtankexplode;
	/*0x1b7c*/ s32 bondviewlevtime60;
	/*0x1b80*/ f32 bondwatchtime60;
	/*0x1b84*/ bool tickdiefinished;
	/*0x1b88*/ s32 introanimnum;
	/*0x1b8c*/ s32 lastsighton;
	/*0x1b90*/ u16 targetset[4]; // related to cmpfollowprops
	/*0x1b98*/ u8 target;
	/*0x1b9c*/ f32 speedthetacontrol;
	/*0x1ba0*/ s32 cam_room;
	/*0x1ba4*/ s16 autocontrol_aimpad;
	/*0x1ba6*/ s16 autocontrol_lookup;
	/*0x1ba8*/ s16 autocontrol_dist;
	/*0x1baa*/ s16 autocontrol_walkspeed;
	/*0x1bac*/ s32 autocontrol_turnspeed;
	/*0x1bb0*/ struct coord cam_pos;
	/*0x1bbc*/ struct coord cam_look;
	/*0x1bc8*/ struct coord cam_up;
	/*0x1bd4*/ u32 unk1bd4;
	/*0x1bd8*/ s32 autocontrol_x;
	/*0x1bdc*/ s32 autocontrol_y;
	/*0x1be0*/ f32 cachedlookahead;
	/*0x1be4*/ u16 lookaheadframe;
	/*0x1be6*/ u8 numaibuddies;
	/*0x1be7*/ u8 aibuddynums[MAX_SIMULANTS];
	/*0x1bf0*/ bool bondexploding;
	/*0x1bf4*/ s32 bondnextexplode; // lvframe60 of next explosion
	/*0x1bf8*/ s32 bondcurexplode;  // Increases by 1 on each tick even when not exploding
	/*0x1bfc*/ u8 teleportstate;
	/*0x1bfd*/ u8 teleporttime;
	/*0x1bfe*/ s16 teleportpad;
	/*0x1c00*/ u16 teleportcamerapad;
	/*0x1c04*/ struct chrdata *commandingaibot;
	/*0x1c08*/ u32 training;
	/*0x1c0c*/ s32 deadtimer;
	/*0x1c10*/ bool coopcanrestart;
	/*0x1c14*/ s32 foot;
	/*0x1c18*/ f32 footstepdist;
	/*0x1c1c*/ u32 unk1c1c;
	/*0x1c20*/ u32 unk1c20;
	/*0x1c24*/ u32 unk1c24;
	/*0x1c28*/ s32 unk1c28;
	/*0x1c2c*/ s32 unk1c2c;
	/*0x1c30*/ s32 unk1c30;
	/*0x1c34*/ s32 unk1c34;
	/*0x1c38*/ s32 unk1c38;
	/*0x1c3c*/ s32 unk1c3c;
	/*0x1c40*/ u32 joybutinhibit;
	/*0x1c44*/ struct coord bondextrapos;
	/*0x1c50*/ u8 unk1c50_01 : 1;
	/*0x1c51*/ u8 disguised : 1;
	/*0x1c54*/ u32 devicesinhibit;
	/*0x1c58*/ f32 grabbedforcez;
	/*0x1c5c*/ f32 stealhealth;
	/*0x1c60*/ s32 unk1c60;
	/*0x1c64*/ s32 unk1c64;
	/*0x1c68*/ u32 unk1c68;
	/*0x1c6c*/ u32 unk1c6c;
};

struct ailist {
	u8 *list;
	s32 id;
};

struct path {
	/*0x00*/ s32 *pads;
	/*0x04*/ u8 id;
	/*0x05*/ u8 flags;
	/*0x06*/ u16 len;
};

struct covercandidate {
	u64 sqdist;
	s32 covernum;
};

struct coverdefinition {
	struct coord pos;
	struct coord look;
	u16 flags;
};

struct cover {
	/*0x00*/ struct coord *pos;
	/*0x04*/ struct coord *look;
	/*0x08*/ s16 rooms[2];
	/*0x0c*/ u16 flags;
};

struct padsfileheader {
	s32 numpads;
	s32 numcovers;
	s32 waypointsoffset;
	s32 waygroupsoffset;
	s32 coversoffset;
	s16 padoffsets[1];
};

struct stagesetup {
	/*0x00*/ struct waypoint *waypoints;
	/*0x04*/ struct waygroup *waygroups;
	/*0x08*/ void *cover;
	/*0x0c*/ s32 *intro;
	/*0x10*/ u32 *props;
	/*0x14*/ struct path *paths;
	/*0x18*/ struct ailist *ailists;
	/*0x1c*/ s8 *padfiledata;
};

struct noisesettings {
	f32 minradius;
	f32 maxradius;
	f32 incradius;
	f32 unk0c;
	f32 unk10;
};

struct inventory_class {
	f32 zoomfov;
	f32 unk04;
	f32 unk08;
	f32 unk0c;
	f32 unk10;
	f32 unk14;
	u32 unk18;
	u32 flags;
};

struct inventory_typef {
	// See related functions: bgun0f097f28 and bgun0f097df0

	// unk00 - Some kind of condition field
	// 0 = terminator
	// 4 = if bit in hand->unk0639 (bit index specified via unk02)
	// 5 = if in left hand
	// 6 = if in right hand
	u8 unk00;

	u16 unk02;

	// 0 = do true thing if condition passed
	// 1 = do false thing if condition passed
	// 3 = do true thing if condition passed, or false thing if condition failed
	u8 unk04;

	u16 partnum;
	u16 unk08;
};

struct weaponfunc {
	/*0x00*/ s32 type;
	/*0x04*/ u16 name;
	/*0x06*/ u8 unk06;
	/*0x07*/ s8 ammoindex; // -1 = no ammo, 0 or 1 = index into weapon->ammos[]
	/*0x08*/ struct noisesettings *noisesettings;
	/*0x0c*/ struct guncmd *fire_animation;
	/*0x10*/ u32 flags;
};

struct weaponfunc_shoot {
	struct weaponfunc base;
	/*0x14*/ struct noisesettings *unk14;
	/*0x18*/ s8 unk18;
	/*0x1c*/ f32 damage;
	/*0x20*/ f32 spread;

	/**
	 * Setting these 4 bytes to higher values causes slower recoil animations
	 * after shooting.
	 */
	/*0x24*/ s8 unk24;
	/*0x25*/ s8 unk25;
	/*0x26*/ s8 unk26;
	/*0x27*/ s8 unk27;

	/*0x28*/ f32 recoil;
	/*0x2c*/ f32 unk2c;
	/*0x30*/ f32 unk30;
	/*0x34*/ f32 strength;
	/*0x38*/ u8 unk38;
	/*0x3a*/ u16 shootsound;
	/*0x3c*/ u8 unk3c;
};

struct weaponfunc_shootsingle {
	struct weaponfunc_shoot base;
};

struct weaponfunc_shootauto {
	struct weaponfunc_shoot base;
	/*0x40*/ f32 initialfirerate; // rounds per minute
	/*0x44*/ f32 maxfirerate; // rounds per minute
	/*0x48*/ f32 *unk48;
	/*0x4c*/ f32 *unk4c;
	/*0x50*/ s8 unk50;
	/*0x51*/ s8 unk51;
};

struct weaponfunc_shootprojectile {
	struct weaponfunc_shoot base;
	/*0x40*/ s32 projectilemodelnum;
	/*0x44*/ u32 unk44;
	/*0x48*/ u32 unk48;
	/*0x4c*/ u32 unk4c;
	/*0x50*/ u32 unk50;
	/*0x54*/ u32 unk54;
	/*0x58*/ u32 unk58;
	/*0x5c*/ u32 unk5c;
	/*0x60*/ u32 unk60;
};

struct weaponfunc_throw {
	struct weaponfunc base;
	/*0x14*/ s32 projectilemodelnum;
	/*0x18*/ s16 activatetime60; // time until proxies become active, or timed mine/grenade explodes
	/*0x1c*/ s32 recoverytime60; // time before player can throw another
	/*0x20*/ f32 damage;
};

struct weaponfunc_close {
	struct weaponfunc base;
	/*0x14*/ f32 damage;
	/*0x18*/ f32 range;
	/*0x1c*/ u32 unk1c;
	/*0x20*/ u32 unk20;
	/*0x24*/ u32 unk24;
	/*0x28*/ u32 unk28;
	/*0x2c*/ u32 unk2c;
	/*0x30*/ u32 unk30;
	/*0x34*/ u32 unk34;
	/*0x38*/ u32 unk38;
	/*0x3c*/ u32 unk3c;
	/*0x40*/ u32 unk40;
	/*0x44*/ u32 unk44;
	/*0x48*/ u32 unk48;
};

struct weaponfunc_special {
	struct weaponfunc base;
	/*0x14*/ s32 specialfunc;
	/*0x18*/ s32 unk18;
	/*0x1c*/ u32 unk1c;
};

struct weaponfunc_device {
	struct weaponfunc base;
	/*0x14*/ u32 device;
};

struct inventory_ammo {
	u32 type;
	u32 casingeject;
	s16 clipsize;
	struct guncmd *reload_animation;
	u8 flags;
};

struct modelpartvisibility {
	u8 part;
	u8 visible;
};

struct weapon {
	/*0x00*/ u16 hi_model;
	/*0x02*/ u16 lo_model;
	/*0x04*/ struct guncmd *equip_animation;
	/*0x08*/ struct guncmd *unequip_animation;
	/*0x0c*/ struct guncmd *pritosec_animation;
	/*0x10*/ struct guncmd *sectopri_animation;
	/*0x14*/ void *functions[2];
	/*0x1c*/ struct inventory_ammo *ammos[2];
	/*0x24*/ struct inventory_class *eptr;
	/*0x28*/ f32 sway;
	/*0x2c*/ f32 leftright;
	/*0x30*/ f32 updown;
	/*0x34*/ f32 frontback;
	/*0x38*/ f32 unk38;
	/*0x3c*/ struct inventory_typef *fptr;
	/*0x40*/ struct modelpartvisibility *partvisibility;
	/*0x44*/ u16 shortname;
	/*0x46*/ u16 name;
	/*0x48*/ u16 manufacturer;
	/*0x4a*/ u16 description;
	/*0x4c*/ u32 flags;
};

struct cutscene {
	s16 stage;
	s16 mission;
	u32 scene;
	u16 name;
};

struct cheat {
	u16 nametextid;
	u16 time;
	u8 stage_index;
	u8 difficulty;
	u8 flags;
};

struct headorbody {
	/*0x00*/ u16 ismale : 1;
	/*0x00*/ u16 unk00_01 : 1;
	/*0x00*/ u16 canvaryheight : 1;
	/*0x00*/ u16 type : 3;
	/*0x00*/ u16 height : 8;
	/*0x02*/ u16 filenum;
	/*0x04*/ f32 scale;
	/*0x08*/ f32 animscale;
	/*0x0c*/ void *filedata;
	/*0x10*/ u16 handfilenum;
};

struct stagetableentry {
	/*0x00*/ s16 id;
	/*0x02*/ u8 light_type;
	/*0x03*/ u8 light_alpha;
	/*0x04*/ u8 light_width;
	/*0x05*/ u8 light_height;
	/*0x06*/ u16 unk06;
	/*0x08*/ u16 bgfileid;
	/*0x0a*/ u16 tilefileid;
	/*0x0c*/ u16 padsfileid;
	/*0x0e*/ u16 setupfileid;
	/*0x10*/ u16 mpsetupfileid;
	/*0x14*/ f32 unk14;
	/*0x18*/ f32 unk18;
	/*0x1c*/ f32 unk1c;
	/*0x20*/ u16 unk20;
	/*0x22*/ u8 unk22;
	/*0x23*/ s8 unk23;
	/*0x24*/ u32 unk24;
	/*0x28*/ u32 unk28;
	/*0x2c*/ s16 unk2c;
	/*0x2e*/ u16 unk2e;
	/*0x30*/ u16 unk30;
	/*0x34*/ f32 unk34;
};

struct mpweaponset {
	/*0x00*/ u16 name;
	/*0x02*/ u8 slots[6];
	/*0x08*/ u8 requirefeatures[4];
	/*0x0c*/ u8 unk0c;
	/*0x0d*/ u8 unk0d;
	/*0x0e*/ u8 unk0e;
	/*0x0f*/ u8 unk0f;
	/*0x10*/ u8 unk10;
	/*0x11*/ u8 unk11;
};

struct mphead {
	s16 headnum;
	u8 requirefeature;
};

struct mpsimulanttype {
	/*0x00*/ u8 type;
	/*0x01*/ u8 difficulty;
	/*0x02*/ u16 name;
	/*0x04*/ s16 body;
	/*0x06*/ u8 requirefeature;
};

struct mpbody {
	s16 bodynum;
	s16 name;
	s16 headnum;
	u8 requirefeature;
};

struct mptrack {
	u16 musicnum : 7;
	u16 duration : 9;
	s16 name;
	s16 unlockstage;
};

struct stageoverviewentry {
	/*0x00*/ u32 stagenum;
	/*0x04*/ u8 unk04;
	/*0x06*/ u16 name1; // "dataDyne Central"
	/*0x08*/ u16 name2; // " - Defection"
	/*0x0a*/ u16 name3; // "dataDyne Defection"
};

struct stagemusic {
	s16 stagenum;
	s16 primarytrack;
	s16 ambienttrack;
	s16 xtrack;
};

struct mission {
	u32 first_stage_index;
	u16 name;
};

struct var800a6600 {
	u32 unk00;
	u32 unk04;
	u32 unk08;
	u32 unk0c;
	f32 unk10;
	f32 unk14;
};

struct var80081058 {
	/*0x00*/ s32 fogmin;
	/*0x04*/ s32 fogmax;
	/*0x08*/ u8 sky_r;
	/*0x09*/ u8 sky_g;
	/*0x0a*/ u8 sky_b;
	/*0x0b*/ u8 num_suns;
	/*0x0c*/ struct sun *sun;
	/*0x10*/ u8 clouds_enabled;
	/*0x14*/ f32 clouds_scale;
	/*0x18*/ u16 unk18;
	/*0x1c*/ f32 clouds_r;
	/*0x20*/ f32 clouds_g;
	/*0x24*/ f32 clouds_b;
	/*0x28*/ u8 water_enabled;
	/*0x2c*/ f32 water_scale;
	/*0x30*/ u16 water_type;
	/*0x34*/ f32 water_r;
	/*0x38*/ f32 water_g;
	/*0x3c*/ f32 water_b;
	/*0x40*/ f32 unk40;
	/*0x44*/ f32 skyredfrac;
	/*0x48*/ f32 skygreenfrac;
	/*0x4c*/ f32 skybluefrac;
};

struct sun {
	u8 lens_flare;
	u8 red;
	u8 green;
	u8 blue;
	f32 x;
	f32 y;
	f32 z;
	u16 texture_size;
	u16 orb_size;
};

struct skytype1 {
	/*0x00*/ s16 stage;
	/*0x02*/ s16 near;
	/*0x04*/ s16 far;
	/*0x06*/ s16 unk06;
	/*0x08*/ s16 unk08;
	/*0x0a*/ s16 unk0a;
	/*0x0c*/ s16 fogmin;
	/*0x0e*/ s16 fogmax;
	/*0x10*/ u8 sky_r;
	/*0x11*/ u8 sky_g;
	/*0x12*/ u8 sky_b;
	/*0x13*/ u8 num_suns;
	/*0x14*/ struct sun *sun;
	/*0x18*/ u8 clouds_enabled;
	/*0x1a*/ s16 clouds_scale;
	/*0x1c*/ u8 unk1c;
	/*0x1d*/ u8 clouds_r;
	/*0x1e*/ u8 clouds_g;
	/*0x1f*/ u8 clouds_b;
	/*0x20*/ u8 water_enabled;
	/*0x21*/ u8 unk21;
	/*0x22*/ s16 water_scale;
	/*0x24*/ u8 water_type;
	/*0x25*/ u8 water_r;
	/*0x26*/ u8 water_g;
	/*0x27*/ u8 water_b;
	/*0x28*/ u8 unk28;
};

struct skytype2 {
	/*0x00*/ s32 stage;
	/*0x04*/ s16 near;
	/*0x06*/ s16 far;
	/*0x08*/ s16 unk08;
	/*0x0a*/ s16 unk0a;
	/*0x0c*/ s16 unk0c;
	/*0x0e*/ u8 sky_r;
	/*0x0f*/ u8 sky_g;
	/*0x10*/ u8 sky_b;
	/*0x11*/ u8 num_suns;
	/*0x14*/ struct sun *sun;
	/*0x18*/ u8 clouds_enabled;
	/*0x19*/ u8 clouds_r;
	/*0x1a*/ u8 clouds_g;
	/*0x1b*/ u8 clouds_b;
	/*0x1c*/ f32 clouds_scale;
	/*0x20*/ s16 unk20;
	/*0x22*/ u8 water_enabled;
	/*0x23*/ u8 water_r;
	/*0x24*/ u8 water_g;
	/*0x25*/ u8 water_b;
	/*0x28*/ f32 water_scale;
	/*0x2c*/ s16 water_type;
	/*0x30*/ f32 unk30;
	/*0x34*/ u32 unk34;
};

struct hoverprop {
	u32 fileid;
	s32 y_offset;
	u16 size;
};

struct menuitemdata_controller {
	u8 textfadetimer;
	u8 contfadetimer;
	u8 curmode;
	u8 controlgroup;
	s8 prevmode;
};

struct menuitemdata_dropdown {
	u16 unk00;
	u16 unk02;
	s16 unk04;
	u16 unk06;
	u16 unk08;
	u16 unk0a;
	s16 scrolloffset;
	u16 unk0e;
};

struct menuitemdata_keyboard {
	char string[11];
	s8 col;
	s8 row;
	u8 capslock : 1;      // Pressed A on caps button
	u8 capseffective : 1; // Same as above, but inverted if holding L or R
};

struct menuitemdata_list {
	s16 unk00;
	s16 unk02;
	s16 unk04;
	s16 unk06;
};

struct menuitemdata_marquee {
	u16 totalmoved;
	u16 sum;
	u16 unk04;
	u16 unk06;
};

struct menuitemdata_ranking {
	s16 scrolloffset;
};

struct menuitemdata_scrollable {
	s16 unk00;
	s16 unk02;
	s16 unk04;
	s16 unk06;
	s16 unk08;
};

struct menuitemdata_slider {
	s16 unk00;
};

union menuitemdata {
	struct menuitemdata_controller controller;
	struct menuitemdata_dropdown dropdown;
	struct menuitemdata_keyboard keyboard;
	struct menuitemdata_list list;
	struct menuitemdata_marquee marquee;
	struct menuitemdata_ranking ranking;
	struct menuitemdata_scrollable scrollable;
	struct menuitemdata_slider slider;
};

struct handlerdata_carousel {
	s32 value;
	u32 unk04;
};

struct handlerdata_checkbox {
	u32 value;
};

struct handlerdata_dropdown {
	u32 value;
	u32 unk04;
};

struct handlerdata_keyboard {
	char *string;
};

struct handlerdata_label {
	u32 colour1;
	u32 colour2;
};

struct handlerdata_list {
	u32 value;
	u32 unk04;
	u32 groupstartindex;
	u32 unk0c;
};

struct handlerdata_list2 {
	s16 unk00;
	s16 unk02;
	u32 unk04;
	u32 unk08;
	u32 unk0c;
};

struct handlerdata_slider {
	u32 value;
	char *label;
};

struct menuitemrenderdata {
	s32 x;
	s32 y;
	s32 width;
	u32 colour;
	u8 unk10;
};

struct handlerdata_type19 {
	Gfx *gdl;
	struct menuitemrenderdata *renderdata1;
	struct menuitemrenderdata *renderdata2;
};

struct handlerdata_dialog1 {
	u32 preventclose;
};

struct handlerdata_dialog2 {
	struct menuinputs *inputs;
};

union handlerdata {
	struct handlerdata_carousel carousel;
	struct handlerdata_checkbox checkbox;
	struct handlerdata_list list;
	struct handlerdata_list2 list2;
	struct handlerdata_dropdown dropdown;
	struct handlerdata_keyboard keyboard;
	struct handlerdata_label label;
	struct handlerdata_slider slider;
	struct handlerdata_type19 type19;

	struct handlerdata_dialog1 dialog1;
	struct handlerdata_dialog2 dialog2;
};

struct menuitem {
	u8 type;
	u8 param;
	u32 param1;
	u32 param2;
	s32 param3;

	union {
		s32 (*handler)(s32 operation, struct menuitem *item, union handlerdata *data);
		void (*handlervoid)(s32 operation, struct menuitem *item, union handlerdata *data);
	};
};

struct menudialog {
	u8 type;
	u32 title;
	struct menuitem *items;
	s32 (*handler)(s32 operation, struct menudialog *dialog, union handlerdata *data);
	u32 unk10;
	struct menudialog *nextsibling;
};

struct twowords {
	u32 unk00;
	u32 unk04;
};

struct surfacetype {
	u16 *sounds;
	u8 *unk04;
	s16 numsounds;
	s16 num04;
};

union soundnumhack {
	u16 packed;

	struct {
		u16 isruss : 1;
		u16 id : 15;
	} bits;

	struct {
		u16 isruss : 1;
		u16 unk02 : 2;
		u16 id : 13;
	} bits2;

	struct {
		u16 isruss : 1;
		u16 unk02 : 2;
		u16 unk04 : 2;
		u16 id : 11;
	} bits3;
};

struct audiorussmapping {
	s16 soundnum;
	u16 audioconfig_index;
};

struct audioconfig {
	f32 unk00;
	f32 unk04;
	f32 unk08;
	f32 unk0c;
	s32 unk10;
	s32 unk14;
	u32 unk18;
	u32 flags; // 0x10 = contains swearing
};

struct bootbufferthingdeep {
	u16 unk00;
	u16 unk02;
	u16 unk04;
	u16 unk06;
	u16 *unk08;
	union {
		u16 *u16p;
		struct {
			u16 u16_1;
			u16 u16_2;
		};
	} unk0c;
	u32 unk10;
};

struct bootbufferthing {
	struct bootbufferthingdeep unk00[120];
};

struct credit {
	u8 more : 1;
	u8 notranin : 1;
	u8 notranout : 1;
	u8 durationindex : 2;
	u8 style;
	u16 text1;
	u16 text2;
};

struct sparktype {
	u16 unk00;
	s16 unk02;
	u16 unk04;
	u16 unk06;
	u16 unk08;
	u16 unk0a;
	f32 weight;
	u16 maxage;
	u16 unk12;
	u16 unk14;
	u32 unk18;
	u32 unk1c;
	u32 unk20;
	f32 decel;
};

struct sparkgroup {
	s32 type;
	s32 numsparks;
	s32 age;
	s32 startindex; // index into g_Sparks
	u32 unk10;
	u32 unk14;
	u32 unk18;
	u32 unk1c;
	u32 unk20;
};

struct spark {
	struct coord pos;
	struct coord speed;
	s32 ttl; // time to live (number of ticks remaining)
};

struct roombitfield {
	u8 prevop : 4;
	u8 b : 4;
};

struct screenbox {
	s16 xmin;
	s16 ymin;
	s16 xmax;
	s16 ymax;
};

struct room14 {
	/*0x00*/ u32 unk00;
	/*0x04*/ u32 unk04;
	/*0x08*/ u32 unk08;
	/*0x0c*/ u32 unk0c;
};

struct room {
	/*0x00*/ u16 flags;
	/*0x02*/ s16 unk02;
	/*0x04*/ u8 portalrecursioncount;
	/*0x05*/ s8 numportals;
	/*0x06*/ u8 unk06;
	/*0x07*/ u8 unk07;
	/*0x08*/ s8 numlights;
	/*0x09*/ u8 numwaypoints; // note: excludes waypoints with PADFLAG_AIDROP
	/*0x0a*/ u16 lightindex; // index of start of this room's lights in data file
	/*0x0c*/ u16 firstwaypoint; // offset into g_Vars.waypoints
	/*0x0e*/ s16 roomportallistoffset;
	/*0x10*/ s16 unk10;
	/*0x14*/ struct room14 *unk14;
	/*0x18*/ f32 bbmin[3];
	/*0x24*/ f32 bbmax[3];
	/*0x30*/ struct coord centre;
	/*0x3c*/ f32 radius; // from volume centre to the corner in 3D
	/*0x40*/ u32 unk40;
	/*0x44*/ void *unk44;
	/*0x48*/ u8 unk48;
	/*0x49*/ u8 unk49;
	/*0x4a*/ u8 unk4a;
	/*0x4b*/ u8 unk4b;
	/*0x4c*/ u8 unk4c;
	/*0x4d*/ u8 unk4d;
	/*0x4e*/ struct roombitfield bitfield;
	/*0x50*/ s16 brightness;
	/*0x52*/ s16 unk52;
	/*0x54*/ u16 unk54;
	/*0x58*/ u32 unk58;
	/*0x5c*/ f32 unk5c;
	/*0x60*/ f32 unk60;
	/*0x64*/ f32 unk64;
	/*0x68*/ f32 unk68;
	/*0x6c*/ f32 unk6c;
	/*0x70*/ f32 unk70;
	/*0x74*/ u32 unk74;
	/*0x78*/ u32 unk78;
	/*0x7c*/ u32 unk7c;
	/*0x80*/ s32 unk80;
	/*0x84*/ u32 unk84;
	/*0x88*/ u32 unk88;
};

struct fireslotthing {
	/*0x00*/ u8 unk00;
	/*0x01*/ s8 unk01;
	/*0x04*/ struct beam *beam;
	/*0x08*/ s32 unk08;
	/*0x0c*/ f32 unk0c;
	/*0x10*/ f32 unk10;
	/*0x14*/ f32 unk14;
	/*0x18*/ u32 unk18;
	/*0x1c*/ u32 unk1c;
};

struct fireslot {
	/*0x00*/ s32 endlvframe;
#if VERSION < VERSION_NTSC_1_0
	struct audiohandle *unk04nb;
	struct audiohandle *unk08nb;
#endif
	/*0x04*/ struct beam beam;
};

struct menulayer {
	struct menuframe *siblings[5];
	s8 numsiblings;
	s8 cursibling;
};

struct menuframe {
	struct menudialog *dialog;
	u8 unk04;
	u8 unk05;
	u16 unk06;
	struct menuitem *focuseditem;
	/*0x0c*/ bool dimmed; // when dropdown is open or slider is active
	/*0x10*/ u32 unk10;
	/*0x14*/ s32 unk14;
	/*0x18*/ s32 y;
	/*0x1c*/ s32 unk1c;
	/*0x20*/ s32 height;
	/*0x24*/ u32 unk24;
	/*0x28*/ u32 unk28;
	/*0x2c*/ s32 unk2c;
	/*0x30*/ u32 unk30;
	/*0x34*/ u32 unk34;
	/*0x38*/ u32 unk38;
	/*0x3c*/ u8 type; // dialog type
	/*0x3c*/ u8 type2; // used when transitioning
	/*0x40*/ f32 transitiontimer; // >= 0 means transitioning from one dialog type to another
	/*0x44*/ u32 colourweight;
	/*0x48*/ f32 unk48;
	/*0x4c*/ f32 unk4c;
	/*0x50*/ f32 unk50;
	/*0x54*/ u32 unk54;
	/*0x58*/ u32 unk58;
	/*0x5c*/ u32 unk5c;
	/*0x60*/ u8 unk60;
	/*0x64*/ u32 unk64;
	/*0x68*/ u32 unk68;
	/*0x6c*/ u8 unk6c;
	/*0x6d*/ s8 unk6d;
	/*0x6e*/ u8 unk6e;
};

struct menudfc {
	struct menuitem *item;
	f32 unk04;
};

struct menudata_endscreen {
	u32 unke1c;

	// ......xx = timed cheat ID
	// .....1.. = this stage + difficulty has a timed cheat
	// .....2.. = timed cheat just got unlocked
	// .....4.. = timed cheat already unlocked
	// .....8.. = completion cheat just got unlocked
	// ....1... = this stage has a completion cheat
	// ..xx.... = completion cheat ID
	u32 cheatinfo;

	bool isfirstcompletion;
	u32 unke28;
	u32 stageindex;
};

struct menudata_main {
	u32 unke1c;
	u32 controlmode;
	u32 mpindex;
	u32 unke28;
	u32 unke2c;
};

struct menudata_mpsetup {
	u32 slotindex;
	u32 slotcount;
	u32 unke24;
};

struct menudata_mppause {
	u32 unke1c;
	u32 unke20;
	u32 unke24;
	s32 weaponnum; // of selected weapon in inventory menu
};

struct menudata_mpend {
	u32 unke1c;
};

struct menudata_filemgr {
	/*0xe1c*/ u32 filetypeplusone;
	/*0xe20*/ u32 device;
	/*0xe24*/ u32 unke24;
	union {
		u32 isdeletingforsave;
		u32 noteindex;
	};
	/*0xe2c*/ u32 unke2c;
	/*0xe30*/ u32 unke30;
	/*0xe34*/ u16 errno;
	/*0xe38*/ struct filelistfile *filetodelete;
	/*0xe3c*/ u8 device1;
	/*0xe3d*/ u8 filetypetodelete;
	/*0xe3e*/ u8 unke3e;
	/*0xe3f*/ u8 listnum;
	/*0xe40*/ u16 unke40_00 : 1;
	/*0xe40*/ u16 unke40_01 : 1;
	/*0xe40*/ u16 unke40_02 : 14;
	/*0xe42*/ u8 fileop;
	union {
		void *unke44;
		s32 mpplayernum;
	};
	/*0xe48*/ u32 fileid;
	/*0xe4c*/ u32 deviceserial;
	/*0xe50*/ u16 isretryingsave;
	/*0xe52*/ u8 device2;
	/*0xe53*/ char filename[20];
	/*0xe68*/ struct perfectheadtexturelist *headtextures;
	/*0xe6c*/ s8 device3;
};

struct menudata_main4mb {
	u32 slotindex;
};

struct menudata_training {
	u32 unke1c;
	struct mpconfigfull *mpconfig;
	u32 unke24;
	u32 weaponnum;
};

struct textureconfig {
	union {
		u32 texturenum;
		u8 *textureptr;
	};
	u8 width;
	u8 height;
	u8 level;
	u8 format;
	u8 depth;
	u8 s;
	u8 t;
	u8 unk0b;
};

struct perfectheadtexturelist {
	u8 unk000[16][0x80];
	struct fileguid fileguids[16];
	s32 lastupdated240;
	struct textureconfig selectedtexture;
};

struct menu {
	struct menuframe frames[10];
	/*0x460*/ s16 numframes;
	/*0x464*/ struct menulayer layers[6];
	/*0x4f4*/ s16 depth; // index into layers. 1-indexed?
	/*0x4f8*/ struct menuframe *curframe;
	/*0x4fc*/ s16 unk4fc[1][2];
	/*0x500*/ u32 unk500;
	/*0x504*/ u32 unk504;
	/*0x508*/ u32 unk508;
	/*0x50c*/ u32 unk50c;
	/*0x510*/ u32 unk510;
	/*0x514*/ u32 unk514;
	/*0x518*/ u32 unk518;
	/*0x51c*/ u32 unk51c;
	/*0x520*/ u32 unk520;
	/*0x524*/ u32 unk524;
	/*0x528*/ u32 unk528;
	/*0x52c*/ u32 unk52c;
	/*0x530*/ u32 unk530;
	/*0x534*/ u32 unk534;
	/*0x538*/ u32 unk538;
	/*0x53c*/ u32 unk53c;
	/*0x540*/ u32 unk540;
	/*0x544*/ u32 unk544;
	/*0x548*/ u32 unk548;
	/*0x54c*/ u32 unk54c;
	/*0x550*/ u32 unk550;
	/*0x554*/ u32 unk554;
	/*0x558*/ u32 unk558;
	/*0x55c*/ u32 unk55c;
	/*0x560*/ u32 unk560;
	/*0x564*/ u32 unk564;
	/*0x568*/ u32 unk568;
	/*0x56c*/ u32 unk56c;
	/*0x570*/ u32 unk570;
	/*0x574*/ u32 unk574;
	/*0x578*/ u32 unk578;
	/*0x57c*/ u32 unk57c;
	/*0x580*/ u32 unk580;
	/*0x584*/ u32 unk584;
	/*0x588*/ u32 unk588;
	/*0x58c*/ u32 unk58c;
	/*0x590*/ u32 unk590;
	/*0x594*/ u32 unk594;
	/*0x598*/ u32 unk598;
	/*0x59c*/ u32 unk59c;
	/*0x5a0*/ u32 unk5a0;
	/*0x5a4*/ u32 unk5a4;
	/*0x5a8*/ u32 unk5a8;
	/*0x5ac*/ u32 unk5ac;
	/*0x5b0*/ u32 unk5b0;
	/*0x5b4*/ u32 unk5b4;
	/*0x5b8*/ u32 unk5b8;
	/*0x5bc*/ u32 unk5bc;
	/*0x5c0*/ u32 unk5c0;
	/*0x5c4*/ u32 unk5c4;
	/*0x5c8*/ u32 unk5c8;
	/*0x5cc*/ u32 unk5cc;
	/*0x5d0*/ u32 unk5d0;
	/*0x5d4*/ u32 unk5d4;
	/*0x5d8*/ u32 unk5d8;
	/*0x5dc*/ u32 unk5dc;
	/*0x5e0*/ u32 unk5e0;
	/*0x5e4*/ u32 unk5e4;
	/*0x5e8*/ u32 unk5e8;
	/*0x5ec*/ u32 unk5ec;
	/*0x5f0*/ u32 unk5f0;
	/*0x5f4*/ u32 unk5f4;
	/*0x5f8*/ u32 unk5f8;
	/*0x5fc*/ u32 unk5fc;
	/*0x600*/ u32 unk600;
	/*0x604*/ u32 unk604;
	/*0x608*/ u32 unk608;
	/*0x60c*/ u32 unk60c;
	/*0x610*/ u32 unk610;
	/*0x614*/ u32 unk614;
	/*0x618*/ u32 unk618;
	/*0x61c*/ u32 unk61c;
	/*0x620*/ u32 unk620;
	/*0x624*/ u32 unk624;
	/*0x628*/ u32 unk628;
	/*0x62c*/ u32 unk62c;
	/*0x630*/ u32 unk630;
	/*0x634*/ u32 unk634;
	/*0x638*/ u32 unk638;
	/*0x63c*/ u32 unk63c;
	/*0x640*/ u32 unk640;
	/*0x644*/ u32 unk644;
	/*0x648*/ u32 unk648;
	/*0x64c*/ u32 unk64c;
	/*0x650*/ u32 unk650;
	/*0x654*/ u32 unk654;
	/*0x658*/ u32 unk658;
	/*0x65c*/ s32 unk65c;
	/*0x660*/ u16 unk660[1][5]; // length unknown
	/*0x66c*/ u32 unk66c;
	/*0x670*/ u32 unk670;
	/*0x674*/ u32 unk674;
	/*0x678*/ u32 unk678;
	/*0x67c*/ u32 unk67c;
	/*0x680*/ u32 unk680;
	/*0x684*/ u32 unk684;
	/*0x688*/ u32 unk688;
	/*0x68c*/ u32 unk68c;
	/*0x690*/ u32 unk690;
	/*0x694*/ u32 unk694;
	/*0x698*/ u32 unk698;
	/*0x69c*/ u32 unk69c;
	/*0x6a0*/ u32 unk6a0;
	/*0x6a4*/ u32 unk6a4;
	/*0x6a8*/ u32 unk6a8;
	/*0x6ac*/ u32 unk6ac;
	/*0x6b0*/ u32 unk6b0;
	/*0x6b4*/ u32 unk6b4;
	/*0x6b8*/ u32 unk6b8;
	/*0x6bc*/ u32 unk6bc;
	/*0x6c0*/ u32 unk6c0;
	/*0x6c4*/ u32 unk6c4;
	/*0x6c8*/ u32 unk6c8;
	/*0x6cc*/ u32 unk6cc;
	/*0x6d0*/ u32 unk6d0;
	/*0x6d4*/ u32 unk6d4;
	/*0x6d8*/ s32 unk6d8;
	/*0x6dc*/ u32 unk6dc;
	/*0x6e0*/ u32 unk6e0;
	/*0x6e4*/ u32 unk6e4;
	/*0x6e8*/ u32 unk6e8;
	/*0x6ec*/ u32 unk6ec;
	/*0x6f0*/ u32 unk6f0;
	/*0x6f4*/ u32 unk6f4;
	/*0x6f8*/ u32 unk6f8;
	/*0x6fc*/ u32 unk6fc;
	/*0x700*/ u32 unk700;
	/*0x704*/ u32 unk704;
	/*0x708*/ u32 unk708;
	/*0x70c*/ u32 unk70c;
	/*0x710*/ u32 unk710;
	/*0x714*/ u32 unk714;
	/*0x718*/ u32 unk718;
	/*0x71c*/ u32 unk71c;
	/*0x720*/ u32 unk720;
	/*0x724*/ u32 unk724;
	/*0x728*/ u32 unk728;
	/*0x72c*/ u32 unk72c;
	/*0x730*/ u32 unk730;
	/*0x734*/ u32 unk734;
	/*0x738*/ u32 unk738;
	/*0x73c*/ u32 unk73c;
	/*0x740*/ u32 unk740;
	/*0x744*/ u32 unk744;
	/*0x748*/ u32 unk748;
	/*0x74c*/ u32 unk74c;
	/*0x750*/ u32 unk750;
	/*0x754*/ u32 unk754;
	/*0x758*/ u32 unk758;
	/*0x75c*/ u32 unk75c;
	/*0x760*/ u32 unk760;
	/*0x764*/ u32 unk764;
	/*0x768*/ u32 unk768;
	/*0x76c*/ u32 unk76c;
	/*0x770*/ u32 unk770;
	/*0x774*/ u32 unk774;
	/*0x778*/ u32 unk778;
	/*0x77c*/ u32 unk77c;
	/*0x780*/ u32 unk780;
	/*0x784*/ u32 unk784;
	/*0x788*/ u32 unk788;
	/*0x78c*/ u32 unk78c;
	/*0x790*/ u32 unk790;
	/*0x794*/ u32 unk794;
	/*0x798*/ u32 unk798;
	/*0x79c*/ u32 unk79c;
	/*0x7a0*/ u32 unk7a0;
	/*0x7a4*/ u32 unk7a4;
	/*0x7a8*/ u32 unk7a8;
	/*0x7ac*/ u32 unk7ac;
	/*0x7b0*/ u32 unk7b0;
	/*0x7b4*/ u32 unk7b4;
	/*0x7b8*/ u32 unk7b8;
	/*0x7bc*/ u32 unk7bc;
	/*0x7c0*/ u32 unk7c0;
	/*0x7c4*/ u32 unk7c4;
	/*0x7c8*/ u32 unk7c8;
	/*0x7cc*/ u32 unk7cc;
	/*0x7d0*/ u32 unk7d0;
	/*0x7d4*/ u32 unk7d4;
	/*0x7d8*/ u32 unk7d8;
	/*0x7dc*/ u32 unk7dc;
	/*0x7e0*/ u32 unk7e0;
	/*0x7e4*/ u32 unk7e4;
	/*0x7e8*/ u32 unk7e8;
	/*0x7ec*/ u32 unk7ec;
	/*0x7f0*/ u32 unk7f0;
	/*0x7f4*/ u32 unk7f4;
	/*0x7f8*/ u32 unk7f8;
	/*0x7fc*/ u32 unk7fc;
	/*0x800*/ u32 unk800;
	/*0x804*/ u32 unk804;
	/*0x808*/ u32 unk808;
	/*0x80c*/ u32 unk80c;
	/*0x810*/ u32 unk810;
	/*0x814*/ u32 unk814;
	/*0x818*/ u32 unk818;
	/*0x81c*/ s32 unk81c;
	/*0x820*/ u32 unk820;
	/*0x824*/ u32 unk824;
	/*0x828*/ u32 unk828;
	/*0x82c*/ s16 unk82c;
	/*0x830*/ u32 unk830;
	/*0x834*/ u32 unk834;
	/*0x838*/ u16 unk838;
	/*0x83a*/ u8 unk83a;
	/*0x83b*/ u8 playernum;
	/*0x83c*/ u8 unk83c;
	/*0x83d*/ u8 unk83d;
	/*0x83e*/ u8 unk83e;
	/*0x83f*/ u8 unk83f;
	/*0x840*/ u8 unk840;

	union {
		/*0x844*/ u32 unk844;
		/*0x844*/ u8 *mpconfigbuffer; // for MENUROOT_TRAINING
	};

	union {
		/*0x848*/ u32 unk848;
		/*0x848*/ u32 mpconfigbufferlen; // for MENUROOT_TRAINING
	};

	/*0x84c*/ u32 unk84c;
	/*0x850*/ u32 unk850;
	/*0x854*/ u8 unk854;
	/*0x855*/ u8 unk855;
	/*0x858*/ u32 unk858;
	/*0x85c*/ u32 unk85c;
	/*0x860*/ u32 unk860;
	/*0x864*/ u32 unk864;
	/*0x868*/ u32 unk868;
	/*0x86c*/ u32 unk86c;
	/*0x870*/ u32 unk870;
	/*0x874*/ u32 unk874;
	/*0x878*/ u32 unk878;
	/*0x87c*/ u32 unk87c;
	/*0x880*/ u32 unk880;
	/*0x884*/ u32 unk884;
	/*0x888*/ u32 unk888;
	/*0x88c*/ u32 unk88c;
	/*0x890*/ u32 unk890;
	/*0x894*/ u32 unk894;
	/*0x898*/ u32 unk898;
	/*0x89c*/ u16 unk89c;
	/*0x8a0*/ u32 unk8a0;
	/*0x8a4*/ u32 unk8a4;
	/*0x8a8*/ u32 unk8a8;
	/*0x8ac*/ u32 unk8ac;
	/*0x8b0*/ u32 unk8b0;
	/*0x8b4*/ u32 unk8b4;
	/*0x8b8*/ u32 unk8b8;
	/*0x8bc*/ u32 unk8bc;
	/*0x8c0*/ u32 unk8c0;
	/*0x8c4*/ u32 unk8c4;
	/*0x8c8*/ u32 unk8c8;
	/*0x8cc*/ u32 unk8cc;
	/*0x8d0*/ u32 unk8d0;
	/*0x8d4*/ u32 unk8d4;
	/*0x8d8*/ u32 unk8d8;
	/*0x8dc*/ u32 unk8dc;
	/*0x8e0*/ u32 unk8e0;
	/*0x8e4*/ u32 unk8e4;
	/*0x8e8*/ u32 unk8e8;
	/*0x8ec*/ u32 unk8ec;
	/*0x8f0*/ u32 unk8f0;
	/*0x8f4*/ u32 unk8f4;
	/*0x8f8*/ u32 unk8f8;
	/*0x8fc*/ u32 unk8fc;
	/*0x900*/ u32 unk900;
	/*0x904*/ u32 unk904;
	/*0x908*/ u32 unk908;
	/*0x90c*/ u32 unk90c;
	/*0x910*/ u32 unk910;
	/*0x914*/ u32 unk914;
	/*0x918*/ u32 unk918;
	/*0x91c*/ u32 unk91c;
	/*0x920*/ u32 unk920;
	/*0x924*/ u32 unk924;
	/*0x928*/ u32 unk928;
	/*0x92c*/ u32 unk92c;
	/*0x930*/ u32 unk930;
	/*0x934*/ u32 unk934;
	/*0x938*/ u32 unk938;
	/*0x93c*/ u32 unk93c;
	/*0x940*/ u32 unk940;
	/*0x944*/ u32 unk944;
	/*0x948*/ u32 unk948;
	/*0x94c*/ u32 unk94c;
	/*0x950*/ u32 unk950;
	/*0x954*/ u32 unk954;
	/*0x958*/ u32 unk958;
	/*0x95c*/ u32 unk95c;
	/*0x960*/ u32 unk960;
	/*0x964*/ u32 unk964;
	/*0x968*/ u32 unk968;
	/*0x96c*/ u32 unk96c;
	/*0x970*/ u32 unk970;
	/*0x974*/ u32 unk974;
	/*0x978*/ u32 unk978;
	/*0x97c*/ u32 unk97c;
	/*0x980*/ u32 unk980;
	/*0x984*/ u32 unk984;
	/*0x988*/ u32 unk988;
	/*0x98c*/ u32 unk98c;
	/*0x990*/ u32 unk990;
	/*0x994*/ u32 unk994;
	/*0x998*/ u32 unk998;
	/*0x99c*/ u32 unk99c;
	/*0x9a0*/ u32 unk9a0;
	/*0x9a4*/ u32 unk9a4;
	/*0x9a8*/ u32 unk9a8;
	/*0x9ac*/ u32 unk9ac;
	/*0x9b0*/ u32 unk9b0;
	/*0x9b4*/ u32 unk9b4;
	/*0x9b8*/ u32 unk9b8;
	/*0x9bc*/ u32 unk9bc;
	/*0x9c0*/ u32 unk9c0;
	/*0x9c4*/ u32 unk9c4;
	/*0x9c8*/ u32 unk9c8;
	/*0x9cc*/ u32 unk9cc;
	/*0x9d0*/ u32 unk9d0;
	/*0x9d4*/ u32 unk9d4;
	/*0x9d8*/ u32 unk9d8;
	/*0x9dc*/ u32 unk9dc;
	/*0x9e0*/ u32 unk9e0;
	/*0x9e4*/ u32 unk9e4;
	/*0x9e8*/ u32 unk9e8;
	/*0x9ec*/ u32 unk9ec;
	/*0x9f0*/ u32 unk9f0;
	/*0x9f4*/ u32 unk9f4;
	/*0x9f8*/ u32 unk9f8;
	/*0x9fc*/ u32 unk9fc;
	/*0xa00*/ u32 unka00;
	/*0xa04*/ u32 unka04;
	/*0xa08*/ u32 unka08;
	/*0xa0c*/ u32 unka0c;
	/*0xa10*/ u32 unka10;
	/*0xa14*/ u32 unka14;
	/*0xa18*/ u32 unka18;
	/*0xa1c*/ u32 unka1c;
	/*0xa20*/ u32 unka20;
	/*0xa24*/ u32 unka24;
	/*0xa28*/ u32 unka28;
	/*0xa2c*/ u32 unka2c;
	/*0xa30*/ u32 unka30;
	/*0xa34*/ u32 unka34;
	/*0xa38*/ u32 unka38;
	/*0xa3c*/ u32 unka3c;
	/*0xa40*/ u32 unka40;
	/*0xa44*/ u32 unka44;
	/*0xa48*/ u32 unka48;
	/*0xa4c*/ u32 unka4c;
	/*0xa50*/ u32 unka50;
	/*0xa54*/ u32 unka54;
	/*0xa58*/ u32 unka58;
	/*0xa5c*/ u32 unka5c;
	/*0xa60*/ u32 unka60;
	/*0xa64*/ u32 unka64;
	/*0xa68*/ u32 unka68;
	/*0xa6c*/ u32 unka6c;
	/*0xa70*/ u32 unka70;
	/*0xa74*/ u32 unka74;
	/*0xa78*/ u32 unka78;
	/*0xa7c*/ u32 unka7c;
	/*0xa80*/ u32 unka80;
	/*0xa84*/ u32 unka84;
	/*0xa88*/ u32 unka88;
	/*0xa8c*/ u32 unka8c;
	/*0xa90*/ u32 unka90;
	/*0xa94*/ u32 unka94;
	/*0xa98*/ u32 unka98;
	/*0xa9c*/ u32 unka9c;
	/*0xaa0*/ u32 unkaa0;
	/*0xaa4*/ u32 unkaa4;
	/*0xaa8*/ u32 unkaa8;
	/*0xaac*/ u32 unkaac;
	/*0xab0*/ u32 unkab0;
	/*0xab4*/ u32 unkab4;
	/*0xab8*/ u32 unkab8;
	/*0xabc*/ u32 unkabc;
	/*0xac0*/ u32 unkac0;
	/*0xac4*/ u32 unkac4;
	/*0xac8*/ u32 unkac8;
	/*0xacc*/ u32 unkacc;
	/*0xad0*/ u32 unkad0;
	/*0xad4*/ u32 unkad4;
	/*0xad8*/ u32 unkad8;
	/*0xadc*/ u32 unkadc;
	/*0xae0*/ u32 unkae0;
	/*0xae4*/ u32 unkae4;
	/*0xae8*/ u32 unkae8;
	/*0xaec*/ u32 unkaec;
	/*0xaf0*/ u32 unkaf0;
	/*0xaf4*/ u32 unkaf4;
	/*0xaf8*/ u32 unkaf8;
	/*0xafc*/ u32 unkafc;
	/*0xb00*/ u32 unkb00;
	/*0xb04*/ u32 unkb04;
	/*0xb08*/ u32 unkb08;
	/*0xb0c*/ u32 unkb0c;
	/*0xb10*/ u32 unkb10;
	/*0xb14*/ u32 unkb14;
	/*0xb18*/ u32 unkb18;
	/*0xb1c*/ u32 unkb1c;
	/*0xb20*/ u32 unkb20;
	/*0xb24*/ u32 unkb24;
	/*0xb28*/ u32 unkb28;
	/*0xb2c*/ u32 unkb2c;
	/*0xb30*/ u32 unkb30;
	/*0xb34*/ u32 unkb34;
	/*0xb38*/ u32 unkb38;
	/*0xb3c*/ u32 unkb3c;
	/*0xb40*/ u32 unkb40;
	/*0xb44*/ u32 unkb44;
	/*0xb48*/ u32 unkb48;
	/*0xb4c*/ u32 unkb4c;
	/*0xb50*/ u32 unkb50;
	/*0xb54*/ u32 unkb54;
	/*0xb58*/ u32 unkb58;
	/*0xb5c*/ u32 unkb5c;
	/*0xb60*/ u32 unkb60;
	/*0xb64*/ u32 unkb64;
	/*0xb68*/ u32 unkb68;
	/*0xb6c*/ u32 unkb6c;
	/*0xb70*/ u32 unkb70;
	/*0xb74*/ u32 unkb74;
	/*0xb78*/ u32 unkb78;
	/*0xb7c*/ u32 unkb7c;
	/*0xb80*/ u32 unkb80;
	/*0xb84*/ u32 unkb84;
	/*0xb88*/ u32 unkb88;
	/*0xb8c*/ u32 unkb8c;
	/*0xb90*/ u32 unkb90;
	/*0xb94*/ u32 unkb94;
	/*0xb98*/ u32 unkb98;
	/*0xb9c*/ u32 unkb9c;
	/*0xba0*/ u32 unkba0;
	/*0xba4*/ u32 unkba4;
	/*0xba8*/ u32 unkba8;
	/*0xbac*/ u32 unkbac;
	/*0xbb0*/ u32 unkbb0;
	/*0xbb4*/ u32 unkbb4;
	/*0xbb8*/ u32 unkbb8;
	/*0xbbc*/ u32 unkbbc;
	/*0xbc0*/ u32 unkbc0;
	/*0xbc4*/ u32 unkbc4;
	/*0xbc8*/ u32 unkbc8;
	/*0xbcc*/ u32 unkbcc;
	/*0xbd0*/ u32 unkbd0;
	/*0xbd4*/ u32 unkbd4;
	/*0xbd8*/ u32 unkbd8;
	/*0xbdc*/ u32 unkbdc;
	/*0xbe0*/ u32 unkbe0;
	/*0xbe4*/ u32 unkbe4;
	/*0xbe8*/ u32 unkbe8;
	/*0xbec*/ u32 unkbec;
	/*0xbf0*/ u32 unkbf0;
	/*0xbf4*/ u32 unkbf4;
	/*0xbf8*/ u32 unkbf8;
	/*0xbfc*/ u32 unkbfc;
	/*0xc00*/ u32 unkc00;
	/*0xc04*/ u32 unkc04;
	/*0xc08*/ u32 unkc08;
	/*0xc0c*/ u32 unkc0c;
	/*0xc10*/ u32 unkc10;
	/*0xc14*/ u32 unkc14;
	/*0xc18*/ u32 unkc18;
	/*0xc1c*/ u32 unkc1c;
	/*0xc20*/ u32 unkc20;
	/*0xc24*/ u32 unkc24;
	/*0xc28*/ u32 unkc28;
	/*0xc2c*/ u32 unkc2c;
	/*0xc30*/ u32 unkc30;
	/*0xc34*/ u32 unkc34;
	/*0xc38*/ u32 unkc38;
	/*0xc3c*/ u32 unkc3c;
	/*0xc40*/ u32 unkc40;
	/*0xc44*/ u32 unkc44;
	/*0xc48*/ u32 unkc48;
	/*0xc4c*/ u32 unkc4c;
	/*0xc50*/ u32 unkc50;
	/*0xc54*/ u32 unkc54;
	/*0xc58*/ u32 unkc58;
	/*0xc5c*/ u32 unkc5c;
	/*0xc60*/ u32 unkc60;
	/*0xc64*/ u32 unkc64;
	/*0xc68*/ u32 unkc68;
	/*0xc6c*/ u32 unkc6c;
	/*0xc70*/ u32 unkc70;
	/*0xc74*/ u32 unkc74;
	/*0xc78*/ u32 unkc78;
	/*0xc7c*/ u32 unkc7c;
	/*0xc80*/ u32 unkc80;
	/*0xc84*/ u32 unkc84;
	/*0xc88*/ u32 unkc88;
	/*0xc8c*/ u32 unkc8c;
	/*0xc90*/ u32 unkc90;
	/*0xc94*/ u32 unkc94;
	/*0xc98*/ u32 unkc98;
	/*0xc9c*/ u32 unkc9c;
	/*0xca0*/ u32 unkca0;
	/*0xca4*/ u32 unkca4;
	/*0xca8*/ u32 unkca8;
	/*0xcac*/ u32 unkcac;
	/*0xcb0*/ u32 unkcb0;
	/*0xcb4*/ u32 unkcb4;
	/*0xcb8*/ u32 unkcb8;
	/*0xcbc*/ u32 unkcbc;
	/*0xcc0*/ u32 unkcc0;
	/*0xcc4*/ u32 unkcc4;
	/*0xcc8*/ u32 unkcc8;
	/*0xccc*/ u32 unkccc;
	/*0xcd0*/ u32 unkcd0;
	/*0xcd4*/ u32 unkcd4;
	/*0xcd8*/ u32 unkcd8;
	/*0xcdc*/ u32 unkcdc;
	/*0xce0*/ u32 unkce0;
	/*0xce4*/ u32 unkce4;
	/*0xce8*/ u32 unkce8;
	/*0xcec*/ u32 unkcec;
	/*0xcf0*/ u32 unkcf0;
	/*0xcf4*/ u32 unkcf4;
	/*0xcf8*/ u32 unkcf8;
	/*0xcfc*/ u32 unkcfc;
	/*0xd00*/ u32 unkd00;
	/*0xd04*/ u32 unkd04;
	/*0xd08*/ u32 unkd08;
	/*0xd0c*/ u32 unkd0c;
	/*0xd10*/ u32 unkd10;
	/*0xd14*/ u32 unkd14;
	/*0xd18*/ u32 unkd18;
	/*0xd1c*/ u32 unkd1c;
	/*0xd20*/ u32 unkd20;
	/*0xd24*/ u32 unkd24;
	/*0xd28*/ u32 unkd28;
	/*0xd2c*/ u32 unkd2c;
	/*0xd30*/ u32 unkd30;
	/*0xd34*/ u32 unkd34;
	/*0xd38*/ u32 unkd38;
	/*0xd3c*/ u32 unkd3c;
	/*0xd40*/ u32 unkd40;
	/*0xd44*/ u32 unkd44;
	/*0xd48*/ u32 unkd48;
	/*0xd4c*/ u32 unkd4c;
	/*0xd50*/ f32 unkd50;
	/*0xd54*/ f32 unkd54;
	/*0xd58*/ f32 unkd58;
	/*0xd5c*/ f32 unkd5c;
	/*0xd60*/ f32 unkd60;
	/*0xd64*/ f32 unkd64;
	/*0xd68*/ f32 unkd68;
	/*0xd6c*/ f32 unkd6c;
	/*0xd70*/ f32 unkd70;
	/*0xd74*/ f32 unkd74;
	/*0xd78*/ f32 unkd78;
	/*0xd7c*/ f32 unkd7c;
	/*0xd80*/ f32 unkd80;
	/*0xd84*/ f32 unkd84;
	/*0xd88*/ f32 unkd88;
	/*0xd8c*/ f32 unkd8c;
	/*0xd90*/ f32 unkd90;
	/*0xd94*/ f32 unkd94;
	/*0xd98*/ u32 unkd98;
	/*0xd9c*/ u32 unkd9c;
	/*0xda0*/ u32 unkda0;
	/*0xda4*/ u32 unkda4;
	/*0xda8*/ u32 unkda8;
	/*0xdac*/ u32 unkdac;
	/*0xdb0*/ u32 unkdb0;
	/*0xdb4*/ s32 unkdb4;
	/*0xdb8*/ s32 unkdb8;
	/*0xdbc*/ u32 unkdbc;
	/*0xdc0*/ u32 unkdc0;
	/*0xdc4*/ u32 unkdc4;
	/*0xdc8*/ u32 unkdc8;
	/*0xdcc*/ u32 unkdcc;
	/*0xdd0*/ u32 unkdd0;
	/*0xdd4*/ u32 unkdd4;
	/*0xdd8*/ u32 unkdd8;
	/*0xddc*/ u32 unkddc;
	/*0xde0*/ u32 unkde0;
	/*0xde4*/ u32 unkde4;
	/*0xde8*/ u32 unkde8;
	/*0xdec*/ u32 unkdec;
	/*0xdf0*/ u32 unkdf0;
	/*0xdf4*/ struct modelpartvisibility *partvisibility;
	/*0xdf8*/ u8 unkdf8;
	/*0xdfc*/ struct menudfc unkdfc[4];

	union {
		struct menudata_endscreen endscreen;
		struct menudata_main main;
		struct menudata_mpsetup mpsetup;
		struct menudata_mppause mppause;
		struct menudata_mpend mpend;
		struct menudata_filemgr fm;
		struct menudata_main4mb main4mb;
		struct menudata_training training;
	};
};

struct gamefile {
	/*0x00*/ char name[11];
	/*0x0b*/ u8 thumbnail : 5; // stage index of the image to show on file select screen
	/*0x0b*/ u8 autodifficulty : 3;
	/*0x0c*/ u8 autostageindex;
	/*0x10*/ u32 totaltime;
	/*0x14*/ u8 flags[10];
	/*0x1e*/ u16 unk1e;
	/*0x20*/ u16 besttimes[NUM_SOLOSTAGES][3];
	/*0xa0*/ s32 coopcompletions[3]; // indexed by difficulty
	/*0xac*/ u8 firingrangescores[9];
	/*0xb5*/ u8 weaponsfound[6];
};

struct mpchr {
	/*0x00*/ char name[12]; // up to 10 visible chars plus line break plus null byte
	/*0x0c*/ u8 unk0c;
	/*0x0d*/ u8 unk0d;
	/*0x0e*/ u8 unk0e;
	/*0x0f*/ u8 mpheadnum;
	/*0x10*/ u8 mpbodynum;
	/*0x11*/ u8 team;
	/*0x14*/ u32 displayoptions;
	/*0x18*/ u16 unk18;
	/*0x1a*/ u16 unk1a;
	/*0x1c*/ u16 unk1c;
	/*0x1e*/ s8 placement; // 0 = winner, 1 = second place etc
	/*0x20*/ u32 unk20;
	/*0x24*/ s16 killcounts[12]; // per player - each index is a chrslot
	/*0x3c*/ s16 numdeaths;
	/*0x3e*/ s16 unk3e;
	/*0x40*/ s16 unk40;
	/*0x42*/ u16 unk42;
	/*0x44*/ u8 controlmode;
	/*0x45*/ s8 contpad1;
	/*0x46*/ s8 contpad2;
	/*0x47*/ u8 simtype;
};

struct mpplayer {
	/*0x00*/ struct mpchr base;
	/*0x48*/ u16 options;
	/*0x4c*/ struct fileguid fileguid;
	/*0x54*/ u32 kills;
	/*0x58*/ u32 deaths;
	/*0x5c*/ u32 gamesplayed;
	/*0x60*/ u32 gameswon;
	/*0x64*/ u32 gameslost;
	/*0x68*/ u32 time;
	/*0x6c*/ u32 distance; // 1 unit = 100 metres
	/*0x70*/ u32 accuracy;
	/*0x74*/ u32 damagedealt;
	/*0x78*/ u32 painreceived;
	/*0x7c*/ u32 headshots;
	/*0x80*/ u32 ammoused;
	/*0x84*/ u32 accuracymedals;
	/*0x88*/ u32 headshotmedals;
	/*0x8c*/ u32 killmastermedals;
	/*0x90*/ u32 survivormedals;
	/*0x94*/ u8 medals;
	/*0x95*/ u8 title;
	/*0x96*/ u8 newtitle;
	/*0x97*/ u8 gunfuncs[5];
	/*0x9c*/ u8 unk9c;
	/*0x9d*/ u8 handicap;
};

struct mpsim {
	/*0x00*/ struct mpchr base;
	/*0x48*/ u8 difficulty;
};

struct missionconfig {
	u8 difficulty : 7;
	u8 pdmode : 1;

	/*0x01*/ u8 stagenum;
	/*0x02*/ u8 stageindex;

	u8 iscoop : 1;
	u8 isanti : 1;

	/*0x04*/ u8 pdmodereaction;
	/*0x05*/ u8 pdmodehealth;
	/*0x06*/ u8 pdmodedamage;
	/*0x07*/ u8 pdmodeaccuracy;
	/*0x08*/ f32 pdmodereactionf;
	/*0x0c*/ f32 pdmodehealthf;
	/*0x10*/ f32 pdmodedamagef;
	/*0x14*/ f32 pdmodeaccuracyf;
};

struct mpsetup {
	/*0x800acb88*/ char name[12];
	/*0x800acb94*/ u32 options;
	/*0x800acb98*/ u8 scenario;
	/*0x800acb99*/ u8 stagenum;
	/*0x800acb9a*/ u8 timelimit;
	/*0x800acb9b*/ u8 scorelimit;
	/*0x800acb9c*/ u16 teamscorelimit;

	/**
	 * Each bit signifies that a player or sim is participating.
	 *
	 * Bits 0x000f are for players
	 * Bits 0x0ff0 are for sims
	 * Bits 0xf000 are probably not used
	 */
	/*0x800acb9e*/ u16 chrslots;
	/*0x800acba0*/ u8 weapons[6];
	/*0x800acba6*/ u8 paused;
	/*0x800acba8*/ struct fileguid fileguid;
};

struct bossfile {
	/*0x00*/ char teamnames[8][12];
	/*0x60*/ u8 locktype;
	/*0x61*/ u8 unk89;
	/*0x62*/ u8 usingmultipletunes;
	/*0x63*/ u8 unk8b;
	/*0x64*/ s8 tracknum; // -1 = random
	/*0x8d*/ u8 multipletracknums[6];
};

struct savebuffer {
	u32 bitpos;
	u8 bytes[220];
};

struct mpscenario {
	struct menudialog *optionsdialog;
	void (*initfunc)(void);
	s32 (*unk08)(void);
	void (*resetfunc)(void);
	void (*tickfunc)(void);
	void (*unk14)(struct chrdata *chr);
	void *unk18;
	void (*killfunc)(struct mpchr *mpchr, s32 arg1, s32 *score, s32 *arg3);
	Gfx *(*radarfunc)(Gfx *gdl);
	bool (*radar2func)(Gfx **gdl, struct prop *prop);
	bool (*highlightfunc)(struct prop *prop, u32 *colour);
	bool (*spawnfunc)(f32 arg0, struct coord *pos, s16 *rooms, struct prop *prop, f32 *arg4);
	s32 (*maxteamsfunc)(void);
	bool (*isroomhighlightedfunc)(s16 room);
	void (*unk38)(s16 arg0, s32 *arg1, s32 *arg2, s32 *arg3);
	void *unk3c;
	void (*readsavefunc)(struct savebuffer *buffer);
	void (*writesavefunc)(struct savebuffer *buffer);
};

struct mpscenariooverview {
	u16 name;
	u16 shortname;
	u8 unlockfeature;
	u8 unk05;
};

struct mparena {
	s16 stagenum;
	u8 requirefeature;
	u16 name;
};

struct filelistfile {
	s32 fileid;
	u16 deviceserial;
	char name[16];
};

// This stores information about all files of a particular filetype across all
// devices. For example, the copy file dialog might list all MP player files
// from all devices in one listing, and that information is stored here.
struct filelist {
	/*0x000*/ struct filelistfile files[30];
	/*0x2d0*/ s16 numfiles;
	/*0x2d2*/ s8 spacesfree[5]; // per device - controller paks then game pak
	/*0x2d8*/ struct fileguid deviceguids[5];
	/*0x300*/ s8 devicestartindexes[5]; // game pak then controller paks
	/*0x308*/ s8 unk305[5]; // controller paks then game pak - error count?
	/*0x30a*/ u8 numdevices;
	/*0x30b*/ u8 filetype;
	/*0x30c*/ u8 timeuntilupdate;
	/*0x30d*/ u8 unk30d;
	/*0x30e*/ u8 updatedthisframe;
};

struct challenge {
	/*0x00*/ u16 name;
	/*0x02*/ s16 confignum;

	// Bitfield xxx4 321a
	// The number denotes if that player has the challenge available,
	// and `a` denotes if any other has the challenge available.
	/*0x04*/ u8 availability;

	// Same structure as availability, however each byte determines how many
	// players it was completed with. So completions[0] is for completions with
	// a single player and completions[3] is for completions with 4 players.
	/*0x05*/ u8 completions[4];

	// Array of features which will become unlocked once the challenge is
	// available. The array is automatically populated at runtime based on what
	// features the challenge uses.
	/*0x09*/ u8 unlockfeatures[16];
};

struct scenariodata_cbt {
	u32 unk00;
	u32 unk04;
	u32 unk08;
	u16 unk0c;
	s16 unk0e[1]; // possibly for a different scenario - see mpGetNumTeammatesDefendingHill
};

struct scenariodata_htb {
	u32 unk00;
	struct prop *token; // Briefcase or chr
	struct coord pos;
	u32 unk14;
	s16 nextindex;
	s16 padnums[60];
};

struct htmthing {
	u32 unk00;
	struct prop *prop;
	s16 unk08;
	u8 unk0a;
	u8 unk0b;
};

struct scenariodata_htm {
	/*0x800ac110*/ s16 nextindex;
	/*0x800ac112*/ u16 unk002;
	/*0x800ac114*/ s16 padnums[60];
	/*0x800ac18c*/ struct htmthing unk07c[7]; // only the first element is used?
	/*0x800ac1e0*/ s16 unk0d0;
	/*0x800ac1e2*/ s16 unk0d2;
	/*0x800ac1e4*/ s32 unk0d4;
	/*0x800ac1e8*/ u32 unk0d8[12];
	/*0x800ac218*/ u32 unk108[12];
	/*0x800ac248*/ u32 unk138;
	/*0x800ac24c*/ struct prop *uplink;
	/*0x800ac250*/ u32 unk140;
};

struct scenariodata_pac {
	s16 unk00;
	u16 age240;
	s32 victimindex;
	s16 victims[12]; // shuffled list of player numbers
	s16 unk20[12];
	s16 wincounts[12]; // indexed by player num
};

struct scenariodata_koh {
	/*0x800ac110*/ u32 unk00;
	/*0x800ac114*/ s16 occupiedteam;
	/*0x800ac116*/ s16 unk06;
	/*0x800ac118*/ s16 unk08;
	/*0x800ac11a*/ s16 hillindex;
	/*0x800ac11c*/ s16 hillcount;
	/*0x800ac11e*/ s16 hillrooms[2];
	/*0x800ac122*/ s16 hillpads[9];
	/*0x800ac134*/ struct coord hillpos;
	/*0x800ac140*/ f32 unk30;
	/*0x800ac144*/ f32 unk34;
	/*0x800ac148*/ f32 unk38;
};

struct ctcspawnpadsperteam {
	s16 teamindex;
	s16 numspawnpads;
	s16 spawnpads[6];
};

struct scenariodata_ctc {
	/*0x00*/ s16 unk00[4]; // teams enabled?
	/*0x08*/ s16 teamindexes[4];
	/*0x10*/ s16 baserooms[4];
	/*0x18*/ struct ctcspawnpadsperteam spawnpadsperteam[4];
	/*0x58*/ struct prop *tokens[4];
};

struct scenariodata {
	union {
		struct scenariodata_cbt cbt;
		struct scenariodata_htb htb;
		struct scenariodata_htm htm;
		struct scenariodata_pac pac;
		struct scenariodata_koh koh;
		struct scenariodata_ctc ctc;
	};
};

struct bgportal {
	u16 unk00;
	s16 roomnum1;
	s16 roomnum2;
	u8 flags;
};

struct portalthing {
	u16 unk00;
	u16 unk02;
	u16 unk04;
	s16 unk06;
	u32 unk08;
	u32 unk0c;
};

struct var800a4ccc { // related to portals
	struct coord coord;
	f32 unk0c;
	f32 unk10;
};

struct trainingdata {
	u8 intraining : 1;
	u8 failed : 1;
	u8 completed : 1;
	u8 finished : 1;
	u8 holographedpc : 1;
	s8 timeleft;
	s32 timetaken;
	struct defaultobj *obj;
	u32 unk0c;
};

struct activemenu {
	/*0x00*/ s8 screenindex;
	/*0x02*/ s16 xradius;
	/*0x04*/ s16 slotwidth;
	/*0x06*/ s16 selx;
	/*0x08*/ s16 sely;
	/*0x0a*/ s16 dstx;
	/*0x0c*/ s16 dsty;
	/*0x0e*/ u8 slotnum; // 0-8, where 4 is middle
	/*0x0f*/ u8 fromslotnum; // when moving from one slot to another
	/*0x10*/ s32 cornertimer;
	/*0x14*/ s32 returntimer; // time before selection returns to middle after releasing control stick
	/*0x18*/ f32 alphafrac;
	/*0x1c*/ f32 selpulse; // determines the border colour of the selection box

	/**
	 * Indexes into the player's inventory. Element 0 is AM slot top left,
	 * then it goes left to right, top to bottom. Updated every tick while
	 * the active menu is open. A value of 0xff means the slot is not shown.
	 */
	/*0x20*/ u8 invindexes[8];

	/**
	 * Weapon numbers to slot mapping. In multiplayer this is determined at the
	 * start of the match. A value of 0xff means the slot cannot be shown in
	 * this match.
	 */
	/*0x28*/ u8 favourites[8];

	/*0x30*/ u8 togglefunc;
	/*0x31*/ u8 numitems; // number of items in player's inventory; can be higher than the number of AM slots
	/*0x32*/ u8 allbots; // when player holds R on the bot command screen
	/*0x33*/ u8 prevallbots; // used when opening "Pick Target" menu for attack command
	/*0x34*/ s8 origscreennum; // original screen number before using allbots
};

struct briefing {
	u16 briefingtextnum;
	u16 objectivenames[6]; // index 0 is the briefing, and the rest are objectives
	u16 objectivedifficulties[6]; // index 0 is unused
	u16 langbank;
};

struct criteria_roomentered {
	u32 unk00;
	u32 pad;
	u32 status;
	struct criteria_roomentered *next;
};

struct criteria_multiroomentered {
	u32 unk00;
	u32 unk04;
	u32 pad;
	u32 status;
	struct criteria_multiroomentered *next;
};

struct criteria_holograph {
	u32 unk00;
	u32 obj;
	u32 status;
	struct criteria_holograph *next;
};

struct mppreset {
	u16 name;
	u32 confignum;
	u8 requirefeatures[16]; // Doesn't seem to be used? All values are zero
};

struct explosiontype {
	/*0x00*/ f32 rangeh;
	/*0x04*/ f32 rangev;
	/*0x08*/ f32 changerateh;
	/*0x0c*/ f32 changeratev;
	/*0x10*/ f32 innersize;
	/*0x14*/ f32 blastradius;
	/*0x18*/ f32 damageradius;
	/*0x1c*/ s16 duration;
	/*0x1e*/ u16 propagationrate;
	/*0x20*/ f32 flarespeed;
	/*0x24*/ u8 smoketype;
	/*0x26*/ u16 sound;
	/*0x28*/ f32 damage;
};

struct explosionpart {
	struct coord pos;
	u32 size;
	u32 rot;
	s16 frame;
	u8 bb;
};

struct explosionbb { // billboards?
	struct coord unk00;
	struct coord unk0c;
	s16 room;
	s16 room2;
};

struct explosion {
	struct prop *prop;
	u32 unk04;
	struct explosionpart parts[40];
	/*0x3c8*/ s16 age;
	/*0x3ca*/ s16 frame60;
	/*0x3cc*/ s8 type;
	/*0x3cd*/ s8 makescorch;
	/*0x3ce*/ s8 owner;
	/*0x3cf*/ u8 numbb;
	/*0x3d0*/ u32 unk3d0;
	/*0x3d4*/ u32 unk3d4;
	/*0x3d8*/ u32 unk3d8;
	/*0x3dc*/ u32 unk3dc;
	/*0x3e0*/ u32 unk3e0;
	/*0x3e4*/ u32 unk3e4;
	/*0x3e8*/ struct explosionbb bbs[5]; // may be smaller
	/*0x474*/ u32 unk474;
};

struct smoketype {
	/*0x00*/ s16 duration;
	/*0x02*/ u16 fadespeed;
	/*0x04*/ u16 spreadspeed;
	/*0x06*/ u16 size;
	/*0x08*/ f32 bgrotatespeed;
	/*0x0c*/ u32 colour;
	/*0x10*/ f32 fgrotatespeed;
	/*0x14*/ u16 numclouds;
	/*0x18*/ f32 unk18;
	/*0x1c*/ f32 unk1c;
	/*0x20*/ f32 unk20;
};

struct smokepart {
	/*0x00*/ struct coord pos;
	/*0x0c*/ f32 size;
	/*0x10*/ u32 rot;
	/*0x14*/ u32 deltarot;
	/*0x18*/ u32 offset1;
	/*0x1c*/ u32 offset2;
	/*0x20*/ u32 alpha;
	/*0x24*/ u16 count;
};

struct smoke {
	/*0x000*/ struct prop *prop; // Prop of the smoke itself
	/*0x004*/ s16 age;
	/*0x006*/ u16 type : 7;
	/*0x006*/ u16 srcispadeffect : 1;
	/*0x007*/ u16 unk06_08 : 8;
	/*0x008*/ struct smokepart parts[10];
	/*0x198*/ void *source; // The thing generating smoke. Can be prop or padeffect
};

struct textoverride {
	/*0x00*/ u32 unk00;
	/*0x04*/ s32 objoffset;
	/*0x08*/ s32 weapon;
	/*0x0c*/ u32 unk0c;
	/*0x10*/ u32 unk10;
	/*0x14*/ u32 unk14;
	/*0x18*/ u32 unk18;
	/*0x1c*/ u32 activatetextid;
	/*0x20*/ struct textoverride *next;
	/*0x24*/ struct defaultobj *obj;
};

struct pakdata {
	/*0x000*/ OSPfsState notes[16];
	/*0x200*/ bool notesinuse[16];
	/*0x240*/ u16 pagesused;
	/*0x242*/ u16 pagesfree;
};

struct pakheadercache {
	s32 blocknum;
	u8 payload[0x20];
};

struct pak {
	/*0x000*/ s32 type;
	/*0x004*/ u32 rumblestate;
	/*0x008*/ u32 unk008;
	/*0x00c*/ u32 unk00c;
	/*0x010*/ u32 unk010;
	/*0x014*/ u8 unk014;
	/*0x018*/ struct pakdata pakdata;
	/*0x25c*/ u32 nextfileid;
	/*0x260*/ u32 serial;
	/*0x264*/ u32 unk264;
	/*0x268*/ u32 unk268;
	/*0x26c*/ u32 unk26c;
	/*0x270*/ u32 unk270;
	/*0x274*/ u32 unk274;
	/*0x278*/ u32 unk278;
	/*0x27c*/ u32 unk27c;
	/*0x280*/ u32 unk280;
	/*0x284*/ s32 rumblepulsestopat;
	/*0x288*/ u32 rumblepulselen;
	/*0x28c*/ u32 rumblepulsetimer;  // counts up to pulselen then loops
	/*0x290*/ u32 unk290;
	/*0x294*/ u32 unk294;
	/*0x298*/ u32 unk298;
	/*0x29c*/ s32 noteindex;
	/*0x2a0*/ u32 numbytes;
	/*0x2a4*/ u32 numblocks;
	/*0x2a8*/ u32 numpages;
	/*0x2ac*/ u32 unk2ac;
	/*0x2b0*/ u32 unk2b0;
	/*0x2b4*/ f32 rumblettl;
	/*0x2b8*/ u8 unk2b8_01 : 1;
	/*0x2b8*/ u8 unk2b8_02 : 1;
	/*0x2b8*/ u8 unk2b8_03 : 1;
	/*0x2b8*/ u8 unk2b8_04 : 1;
	/*0x2b8*/ u8 unk2b8_05 : 1;
	/*0x2b8*/ u8 unk2b8_06 : 1;
	/*0x2b8*/ u8 unk2b8_07 : 1;
	/*0x2b9*/ u8 unk2b9;
	/*0x2ba*/ u8 unk2ba;
	/*0x2bb*/ u8 unk2bb;
	/*0x2bc*/ u8 unk2bc;
	/*0x2bd*/ u8 unk2bd;
	/*0x2be*/ u8 headercachecount;
	/*0x2c0*/ struct pakheadercache *headercache;
	/*0x2c4*/ u8 *unk2c4; // len 4096
#if VERSION >= VERSION_NTSC_1_0
	/*0x2c8*/ u32 unk2c8;
#endif
};

struct gecreditsdata {
	/*0x00*/ u16 text1;
	/*0x02*/ u16 text2;
	/*0x04*/ u16 posoffset1;
	/*0x06*/ u16 alignoffset1;
	/*0x08*/ u16 posoffset2;
	/*0x0a*/ u16 alignoffset2;
};

struct memorypool {
	/*0x00*/ u32 start;
	/*0x04*/ u32 leftpos;
	/*0x08*/ u32 rightpos;
	/*0x0c*/ u32 end;
	/*0x10*/ u32 prevallocation;
};

struct invitem_weap {
	s16 weapon1;
	s16 pickuppad;
};

struct invitem_prop {
	struct prop *prop;
};

struct invitem_dual {
	s32 weapon1;
	s32 weapon2;
};

struct invitem {
	/*0x00*/ s32 type;

	union {
		struct invitem_weap type_weap;
		struct invitem_prop type_prop;
		struct invitem_dual type_dual;
	};

	/*0x0c*/ struct invitem *next;
	/*0x10*/ struct invitem *prev;
};

struct chrnumaction {
	s16 chrnum;
	u8 myaction;
};

struct modelstate {
	struct modelfiledata *filedata;
	u16 fileid;
	u16 scale;
};

struct simdifficulty {
	u8 unk00;
	f32 unk04;
	f32 unk08;
	u16 unk0c;
	f32 unk10;
	f32 unk14;
	f32 unk18;
	s32 blurdrugamount;
};

struct animtablerow {
	s16 animnum;
	bool flip;
	f32 endframe;
	f32 speed;
	u32 unk10;
	f32 thudframe1;
	f32 thudframe2;
};

struct animtable {
	s32 hitpart;
	struct animtablerow *deathanims;
	struct animtablerow *injuryanims;
	s32 deathanimcount;
	s32 injuryanimcount;
};

struct var80075c00 {
	s16 animnum;
	f32 loopframe;
	f32 endframe;
	f32 unk0c;
	f32 unk10;
	f32 unk14;
};

struct vimode {
	s32 fbwidth;
	s32 fbheight;
	s32 width;
	f32 yscale;
	s32 xscale;
	s32 fullheight;
	s32 fulltop;
	s32 wideheight;
	s32 widetop;
	s32 cinemaheight;
	s32 cinematop;
};

struct miscbio {
	u32 name;
	u32 description;
};

struct hangarbio {
	u32 name;
	u32 description;
	u32 unk08;
	u32 unk0c;
};

struct chrbio {
	u32 name;
	u32 race;
	u32 age;
	u32 description;
};

struct mpteaminfo {
	struct mpchr *mpchr;
	u32 teamnum;
	u32 unk08;
	u32 unk0c;
	s32 score;
};

struct hudmessagething {
	s32 unk00;
};

struct hudmsgtype {
	/*0x00*/ u8 unk00;
	/*0x01*/ u8 unk01;
	/*0x02*/ u8 unk02;
	/*0x04*/ struct hudmessagething *unk04;
	/*0x08*/ struct hudmessagething *unk08;
	/*0x0c*/ u32 colour;
	/*0x10*/ u32 unk10;
	/*0x14*/ u8 alignh;
	/*0x15*/ u8 alignv;
	/*0x16*/ s16 unk16;
	/*0x18*/ s16 unk18;
	/*0x1c*/ s32 duration;
};

struct hudmessage {
	/*0x000*/ u8 state;
	/*0x001*/ u8 boxed;
	/*0x002*/ u8 allowfadein;
	/*0x003*/ u8 flash;
	/*0x004*/ u8 opacity;
	/*0x006*/ u16 timer;
	/*0x008*/ u32 font1;
	/*0x00c*/ u32 font2;
	/*0x010*/ u32 textcolour;
	/*0x014*/ u32 glowcolour;
	/*0x018*/ u16 x;
	/*0x01a*/ u16 y;
	/*0x01c*/ u16 width;
	/*0x01e*/ u16 height;
	/*0x020*/ char text[400];
	/*0x1b0*/ s32 channelnum;
	/*0x1b4*/ u32 type;
	/*0x1b8*/ s32 id;
	/*0x1bc*/ s32 showduration;
	/*0x1c0*/ s32 playernum;
	/*0x1c4*/ u32 flags;
	/*0x1c8*/ u8 alignh;
	/*0x1c9*/ u8 alignv;
	/*0x1cc*/ u32 xmarginextra;
	/*0x1d0*/ u32 xmargin;
	/*0x1d4*/ u32 ymargin;
	/*0x1d8*/ u32 hash;
};

struct frtarget {
	/*0x00*/ u8 inuse : 1;         // 1 if being used at all in this session
	/*0x00*/ u8 active : 1;        // 1 if target has appeared
	/*0x00*/ u8 destroyed : 1;
	/*0x00*/ u8 scriptenabled : 1;
	/*0x00*/ u8 rotating : 1;
	/*0x00*/ u8 rotateoncloak : 1;
	/*0x00*/ u8 frpadindex : 2;
	/*0x01*/ u8 maxdamage;
	/*0x02*/ u8 scriptindex;
	/*0x04*/ struct prop *prop;
	/*0x08*/ struct coord dstpos;
	/*0x14*/ s32 scriptsleep;
	/*0x18*/ s32 timeuntilrotate;
	/*0x1c*/ f32 travelspeed;
	/*0x20*/ u8 damage;
	/*0x21*/ u8 scriptoffset;
	/*0x24*/ f32 rotatespeed;      // Negative for reverse direction
	/*0x28*/ f32 angle;
	/*0x2c*/ f32 rotatetoangle;
	/*0x30*/ u8 flags;
	/*0x31*/ u8 silent;            // 0 if playing the hum sound while travelling
	/*0x32*/ u8 donestopsound;     // 1 if the clank sound has played when stopping travelling
	/*0x33*/ u8 travelling;
	/*0x34*/ s8 frpadnum;
	/*0x38*/ s32 invincibletimer;
};

struct frdata {
	/*0x000*/ u8 maxactivetargets;
	/*0x002*/ u16 goalscore;
	/*0x004*/ u8 goaltargets;
	/*0x005*/ u8 timelimit;
	/*0x006*/ u8 ammolimit;
	/*0x007*/ u8 sdgrenadelimit;
	/*0x008*/ u8 goalaccuracy;
	/*0x00c*/ f32 speed;
	/*0x010*/ struct frtarget targets[18];
	/*0x448*/ u8 difficulty;
	/*0x44c*/ s32 timetaken;
	/*0x450*/ s32 score;
	/*0x454*/ u8 numtargets;
	/*0x455*/ u8 targetsdestroyed;
	/*0x456*/ u16 slot;
	/*0x458*/ u16 numshots;
	/*0x45a*/ u8 numshotssincetopup;
	/*0x45b*/ u8 failreason;
	/*0x45c*/ u16 numhitsbullseye;
	/*0x45e*/ u16 numhitsring1;
	/*0x460*/ u16 numhitsring2;
	/*0x462*/ u16 numhitsring3;
	/*0x464*/ s8 menucountdown;
	/*0x465*/ u8 menutype : 3;
	/*0x465*/ u8 donelighting : 1;
	/*0x465*/ u8 donealarm : 1;
	/*0x465*/ u8 ammohasgrace : 1;
	/*0x466*/ u8 helpscriptindex;
	/*0x467*/ u8 helpscriptoffset;
	/*0x468*/ u8 helpscriptenabled;
	/*0x46c*/ s32 helpscriptsleep;
	/*0x470*/ u8 padindexoffset;
	/*0x471*/ u8 feedbackzone;
	/*0x472*/ s8 feedbackttl;
	/*0x474*/ s16 proxyendtimer;
	/*0x476*/ s16 ammoextra;
	/*0x478*/ s16 sdgrenadeextra;
	/*0x47c*/ u32 unk47c;
};

struct menudata_5d8 {
	struct fileguid fileguid;
	u8 unk08;
	u8 unk09;
	u8 unk0a;
	u8 unk0b;
};

struct menudata {
	/*0x000*/ s32 count;
	/*0x004*/ s32 root;
	/*0x008*/ s32 unk008; // also a menuroot constant
	/*0x00c*/ struct menudialog *unk00c;
	/*0x010*/ f32 unk010;
	/*0x014*/ u8 unk014;
	/*0x015*/ u8 unk015;
	/*0x016*/ u8 unk016;
	/*0x017*/ u8 unk017[4];
	/*0x01b*/ s8 unk01b;
	/*0x01c*/ u32 unk01c;
	/*0x020*/ u32 unk020;
	/*0x024*/ u32 unk024;
	/*0x028*/ u32 unk028;
	/*0x02c*/ u32 unk02c;
	/*0x030*/ u32 unk030;
	/*0x034*/ u32 unk034;
	/*0x038*/ u32 unk038;
	/*0x03c*/ u32 unk03c;
	/*0x040*/ u32 unk040;
	/*0x044*/ u32 unk044;
	/*0x048*/ u32 unk048;
	/*0x04c*/ u32 unk04c;
	/*0x050*/ u32 unk050;
	/*0x054*/ u32 unk054;
	/*0x058*/ u32 unk058;
	/*0x05c*/ u32 unk05c;
	/*0x060*/ u32 unk060;
	/*0x064*/ u32 unk064;
	/*0x068*/ u32 unk068;
	/*0x06c*/ u32 unk06c;
	/*0x070*/ u32 unk070;
	/*0x074*/ u32 unk074;
	/*0x078*/ u32 unk078;
	/*0x07c*/ u32 unk07c;
	/*0x080*/ u32 unk080;
	/*0x084*/ u32 unk084;
	/*0x088*/ u32 unk088;
	/*0x08c*/ u32 unk08c;
	/*0x090*/ u32 unk090;
	/*0x094*/ u32 unk094;
	/*0x098*/ u32 unk098;
	/*0x09c*/ u32 unk09c;
	/*0x0a0*/ u32 unk0a0;
	/*0x0a4*/ u32 unk0a4;
	/*0x0a8*/ u32 unk0a8;
	/*0x0ac*/ u32 unk0ac;
	/*0x0b0*/ u32 unk0b0;
	/*0x0b4*/ u32 unk0b4;
	/*0x0b8*/ u32 unk0b8;
	/*0x0bc*/ u32 unk0bc;
	/*0x0c0*/ u32 unk0c0;
	/*0x0c4*/ u32 unk0c4;
	/*0x0c8*/ u32 unk0c8;
	/*0x0cc*/ u32 unk0cc;
	/*0x0d0*/ u32 unk0d0;
	/*0x0d4*/ u32 unk0d4;
	/*0x0d8*/ u32 unk0d8;
	/*0x0dc*/ u32 unk0dc;
	/*0x0e0*/ u32 unk0e0;
	/*0x0e4*/ u32 unk0e4;
	/*0x0e8*/ u32 unk0e8;
	/*0x0ec*/ u32 unk0ec;
	/*0x0f0*/ u32 unk0f0;
	/*0x0f4*/ u32 unk0f4;
	/*0x0f8*/ u32 unk0f8;
	/*0x0fc*/ u32 unk0fc;
	/*0x100*/ u32 unk100;
	/*0x104*/ u32 unk104;
	/*0x108*/ u32 unk108;
	/*0x10c*/ u32 unk10c;
	/*0x110*/ u32 unk110;
	/*0x114*/ u32 unk114;
	/*0x118*/ u32 unk118;
	/*0x11c*/ u32 unk11c;
	/*0x120*/ u32 unk120;
	/*0x124*/ u32 unk124;
	/*0x128*/ u32 unk128;
	/*0x12c*/ u32 unk12c;
	/*0x130*/ u32 unk130;
	/*0x134*/ u32 unk134;
	/*0x138*/ u32 unk138;
	/*0x13c*/ u32 unk13c;
	/*0x140*/ u32 unk140;
	/*0x144*/ u32 unk144;
	/*0x148*/ u32 unk148;
	/*0x14c*/ u32 unk14c;
	/*0x150*/ u32 unk150;
	/*0x154*/ u32 unk154;
	/*0x158*/ u32 unk158;
	/*0x15c*/ u32 unk15c;
	/*0x160*/ u32 unk160;
	/*0x164*/ u32 unk164;
	/*0x168*/ u32 unk168;
	/*0x16c*/ u32 unk16c;
	/*0x170*/ u32 unk170;
	/*0x174*/ u32 unk174;
	/*0x178*/ u32 unk178;
	/*0x17c*/ u32 unk17c;
	/*0x180*/ u32 unk180;
	/*0x184*/ u32 unk184;
	/*0x188*/ u32 unk188;
	/*0x18c*/ u32 unk18c;
	/*0x190*/ u32 unk190;
	/*0x194*/ u32 unk194;
	/*0x198*/ u32 unk198;
	/*0x19c*/ u32 unk19c;
	/*0x1a0*/ u32 unk1a0;
	/*0x1a4*/ u32 unk1a4;
	/*0x1a8*/ u32 unk1a8;
	/*0x1ac*/ u32 unk1ac;
	/*0x1b0*/ u32 unk1b0;
	/*0x1b4*/ u32 unk1b4;
	/*0x1b8*/ u32 unk1b8;
	/*0x1bc*/ u32 unk1bc;
	/*0x1c0*/ u32 unk1c0;
	/*0x1c4*/ u32 unk1c4;
	/*0x1c8*/ u32 unk1c8;
	/*0x1cc*/ u32 unk1cc;
	/*0x1d0*/ u32 unk1d0;
	/*0x1d4*/ u32 unk1d4;
	/*0x1d8*/ u32 unk1d8;
	/*0x1dc*/ u32 unk1dc;
	/*0x1e0*/ u32 unk1e0;
	/*0x1e4*/ u32 unk1e4;
	/*0x1e8*/ u32 unk1e8;
	/*0x1ec*/ u32 unk1ec;
	/*0x1f0*/ u32 unk1f0;
	/*0x1f4*/ u32 unk1f4;
	/*0x1f8*/ u32 unk1f8;
	/*0x1fc*/ u32 unk1fc;
	/*0x200*/ u32 unk200;
	/*0x204*/ u32 unk204;
	/*0x208*/ u32 unk208;
	/*0x20c*/ u32 unk20c;
	/*0x210*/ u32 unk210;
	/*0x214*/ u32 unk214;
	/*0x218*/ u32 unk218;
	/*0x21c*/ u32 unk21c;
	/*0x220*/ u32 unk220;
	/*0x224*/ u32 unk224;
	/*0x228*/ u32 unk228;
	/*0x22c*/ u32 unk22c;
	/*0x230*/ u32 unk230;
	/*0x234*/ u32 unk234;
	/*0x238*/ u32 unk238;
	/*0x23c*/ u32 unk23c;
	/*0x240*/ u32 unk240;
	/*0x244*/ u32 unk244;
	/*0x248*/ u32 unk248;
	/*0x24c*/ u32 unk24c;
	/*0x250*/ u32 unk250;
	/*0x254*/ u32 unk254;
	/*0x258*/ u32 unk258;
	/*0x25c*/ u32 unk25c;
	/*0x260*/ u32 unk260;
	/*0x264*/ u32 unk264;
	/*0x268*/ u32 unk268;
	/*0x26c*/ u32 unk26c;
	/*0x270*/ u32 unk270;
	/*0x274*/ u32 unk274;
	/*0x278*/ u32 unk278;
	/*0x27c*/ u32 unk27c;
	/*0x280*/ u32 unk280;
	/*0x284*/ u32 unk284;
	/*0x288*/ u32 unk288;
	/*0x28c*/ u32 unk28c;
	/*0x290*/ u32 unk290;
	/*0x294*/ u32 unk294;
	/*0x298*/ u32 unk298;
	/*0x29c*/ u32 unk29c;
	/*0x2a0*/ u32 unk2a0;
	/*0x2a4*/ u32 unk2a4;
	/*0x2a8*/ u32 unk2a8;
	/*0x2ac*/ u32 unk2ac;
	/*0x2b0*/ u32 unk2b0;
	/*0x2b4*/ u32 unk2b4;
	/*0x2b8*/ u32 unk2b8;
	/*0x2bc*/ u32 unk2bc;
	/*0x2c0*/ u32 unk2c0;
	/*0x2c4*/ u32 unk2c4;
	/*0x2c8*/ u32 unk2c8;
	/*0x2cc*/ u32 unk2cc;
	/*0x2d0*/ u32 unk2d0;
	/*0x2d4*/ u32 unk2d4;
	/*0x2d8*/ u32 unk2d8;
	/*0x2dc*/ u32 unk2dc;
	/*0x2e0*/ u32 unk2e0;
	/*0x2e4*/ u32 unk2e4;
	/*0x2e8*/ u32 unk2e8;
	/*0x2ec*/ u32 unk2ec;
	/*0x2f0*/ u32 unk2f0;
	/*0x2f4*/ u32 unk2f4;
	/*0x2f8*/ u32 unk2f8;
	/*0x2fc*/ u32 unk2fc;
	/*0x300*/ u32 unk300;
	/*0x304*/ u32 unk304;
	/*0x308*/ u32 unk308;
	/*0x30c*/ u32 unk30c;
	/*0x310*/ u32 unk310;
	/*0x314*/ u32 unk314;
	/*0x318*/ u32 unk318;
	/*0x31c*/ u32 unk31c;
	/*0x320*/ u32 unk320;
	/*0x324*/ u32 unk324;
	/*0x328*/ u32 unk328;
	/*0x32c*/ u32 unk32c;
	/*0x330*/ u32 unk330;
	/*0x334*/ u32 unk334;
	/*0x338*/ u32 unk338;
	/*0x33c*/ u32 unk33c;
	/*0x340*/ u32 unk340;
	/*0x344*/ u32 unk344;
	/*0x348*/ u32 unk348;
	/*0x34c*/ u32 unk34c;
	/*0x350*/ u32 unk350;
	/*0x354*/ u32 unk354;
	/*0x358*/ u32 unk358;
	/*0x35c*/ u32 unk35c;
	/*0x360*/ u32 unk360;
	/*0x364*/ u32 unk364;
	/*0x368*/ u32 unk368;
	/*0x36c*/ u32 unk36c;
	/*0x370*/ u32 unk370;
	/*0x374*/ u32 unk374;
	/*0x378*/ u32 unk378;
	/*0x37c*/ u32 unk37c;
	/*0x380*/ u32 unk380;
	/*0x384*/ u32 unk384;
	/*0x388*/ u32 unk388;
	/*0x38c*/ u32 unk38c;
	/*0x390*/ u32 unk390;
	/*0x394*/ u32 unk394;
	/*0x398*/ u32 unk398;
	/*0x39c*/ u32 unk39c;
	/*0x3a0*/ u32 unk3a0;
	/*0x3a4*/ u32 unk3a4;
	/*0x3a8*/ u32 unk3a8;
	/*0x3ac*/ u32 unk3ac;
	/*0x3b0*/ u32 unk3b0;
	/*0x3b4*/ u32 unk3b4;
	/*0x3b8*/ u32 unk3b8;
	/*0x3bc*/ u32 unk3bc;
	/*0x3c0*/ u32 unk3c0;
	/*0x3c4*/ u32 unk3c4;
	/*0x3c8*/ u32 unk3c8;
	/*0x3cc*/ u32 unk3cc;
	/*0x3d0*/ u32 unk3d0;
	/*0x3d4*/ u32 unk3d4;
	/*0x3d8*/ u32 unk3d8;
	/*0x3dc*/ u32 unk3dc;
	/*0x3e0*/ u32 unk3e0;
	/*0x3e4*/ u32 unk3e4;
	/*0x3e8*/ u32 unk3e8;
	/*0x3ec*/ u32 unk3ec;
	/*0x3f0*/ u32 unk3f0;
	/*0x3f4*/ u32 unk3f4;
	/*0x3f8*/ u32 unk3f8;
	/*0x3fc*/ u32 unk3fc;
	/*0x400*/ u32 unk400;
	/*0x404*/ u32 unk404;
	/*0x408*/ u32 unk408;
	/*0x40c*/ u32 unk40c;
	/*0x410*/ u32 unk410;
	/*0x414*/ u32 unk414;
	/*0x418*/ u32 unk418;
	/*0x41c*/ u32 unk41c;
	/*0x420*/ u32 unk420;
	/*0x424*/ u32 unk424;
	/*0x428*/ u32 unk428;
	/*0x42c*/ u32 unk42c;
	/*0x430*/ u32 unk430;
	/*0x434*/ u32 unk434;
	/*0x438*/ u32 unk438;
	/*0x43c*/ u32 unk43c;
	/*0x440*/ u32 unk440;
	/*0x444*/ u32 unk444;
	/*0x448*/ u32 unk448;
	/*0x44c*/ u32 unk44c;
	/*0x450*/ u32 unk450;
	/*0x454*/ u32 unk454;
	/*0x458*/ u32 unk458;
	/*0x45c*/ u32 unk45c;
	/*0x460*/ u32 unk460;
	/*0x464*/ u32 unk464;
	/*0x468*/ u32 unk468;
	/*0x46c*/ u32 unk46c;
	/*0x470*/ u32 unk470;
	/*0x474*/ u32 unk474;
	/*0x478*/ u32 unk478;
	/*0x47c*/ u32 unk47c;
	/*0x480*/ u32 unk480;
	/*0x484*/ u32 unk484;
	/*0x488*/ u32 unk488;
	/*0x48c*/ u32 unk48c;
	/*0x490*/ u32 unk490;
	/*0x494*/ u32 unk494;
	/*0x498*/ u32 unk498;
	/*0x49c*/ u32 unk49c;
	/*0x4a0*/ u32 unk4a0;
	/*0x4a4*/ u32 unk4a4;
	/*0x4a8*/ u32 unk4a8;
	/*0x4ac*/ u32 unk4ac;
	/*0x4b0*/ u32 unk4b0;
	/*0x4b4*/ u32 unk4b4;
	/*0x4b8*/ u32 unk4b8;
	/*0x4bc*/ u32 unk4bc;
	/*0x4c0*/ u32 unk4c0;
	/*0x4c4*/ u32 unk4c4;
	/*0x4c8*/ u32 unk4c8;
	/*0x4cc*/ u32 unk4cc;
	/*0x4d0*/ u32 unk4d0;
	/*0x4d4*/ u32 unk4d4;
	/*0x4d8*/ u32 unk4d8;
	/*0x4dc*/ u32 unk4dc;
	/*0x4e0*/ u32 unk4e0;
	/*0x4e4*/ u32 unk4e4;
	/*0x4e8*/ u32 unk4e8;
	/*0x4ec*/ u32 unk4ec;
	/*0x4f0*/ u32 unk4f0;
	/*0x4f4*/ u32 unk4f4;
	/*0x4f8*/ u32 unk4f8;
	/*0x4fc*/ u32 unk4fc;
	/*0x500*/ u32 unk500;
	/*0x504*/ u32 unk504;
	/*0x508*/ u32 unk508;
	/*0x50c*/ u32 unk50c;
	/*0x510*/ u32 unk510;
	/*0x514*/ u32 unk514;
	/*0x518*/ u32 unk518;
	/*0x51c*/ u32 unk51c;
	/*0x520*/ u32 unk520;
	/*0x524*/ u32 unk524;
	/*0x528*/ u32 unk528;
	/*0x52c*/ u32 unk52c;
	/*0x530*/ u32 unk530;
	/*0x534*/ u32 unk534;
	/*0x538*/ u32 unk538;
	/*0x53c*/ u32 unk53c;
	/*0x540*/ u32 unk540;
	/*0x544*/ u32 unk544;
	/*0x548*/ u32 unk548;
	/*0x54c*/ u32 unk54c;
	/*0x550*/ u32 unk550;
	/*0x554*/ u32 unk554;
	/*0x558*/ u32 unk558;
	/*0x55c*/ u32 unk55c;
	/*0x560*/ u32 unk560;
	/*0x564*/ u32 unk564;
	/*0x568*/ u32 unk568;
	/*0x56c*/ u32 unk56c;
	/*0x570*/ u32 unk570;
	/*0x574*/ u32 unk574;
	/*0x578*/ u32 unk578;
	/*0x57c*/ u32 unk57c;
	/*0x580*/ u32 unk580;
	/*0x584*/ u32 unk584;
	/*0x588*/ u32 unk588;
	/*0x58c*/ u32 unk58c;
	/*0x590*/ u32 unk590;
	/*0x594*/ u32 unk594;
	/*0x598*/ u32 unk598;
	/*0x59c*/ u32 unk59c;
	/*0x5a0*/ u32 unk5a0;
	/*0x5a4*/ u32 unk5a4;
	/*0x5a8*/ u32 unk5a8;
	/*0x5ac*/ u32 unk5ac;
	/*0x5b0*/ u32 unk5b0;
	/*0x5b4*/ u32 unk5b4;
	/*0x5b8*/ u32 unk5b8;
	/*0x5bc*/ u32 unk5bc;
	/*0x5c0*/ u32 unk5c0;
	/*0x5c4*/ u32 unk5c4;
	/*0x5c8*/ u32 unk5c8;
	/*0x5cc*/ u32 unk5cc;
	/*0x5d0*/ u32 unk5d0;
	/*0x5d4*/ u8 unk5d4;
	/*0x5d5*/ u8 unk5d5_01 : 1;
	/*0x5d5*/ u8 unk5d5_02 : 1;
	/*0x5d5*/ u8 unk5d5_03 : 1;
	/*0x5d5*/ u8 unk5d5_04 : 1;
	/*0x5d5*/ u8 unk5d5_05 : 1;
	/*0x5d5*/ u8 unk5d5_06 : 1;
	/*0x5d5*/ u8 unk5d5_07 : 1;
	/*0x5d5*/ u8 unk5d5_08 : 1;
	/*0x5d8*/ struct menudata_5d8 unk5d8[12];
	/*0x668*/ s8 unk668;
	/*0x669*/ u8 unk669[4];
	/*0x66d*/ u8 unk66d;
	/*0x66e*/ s8 unk66e; // index into 669
	/*0x66f*/ u8 unk66f;
	/*0x670*/ s32 unk670;
	/*0x674*/ s32 unk674;
};

struct ammotype {
	s32 capacity;
	u32 unk04;
	f32 unk08;
};

struct weather58 {
	f32 unk00;
	f32 unk04;
	s32 unk08;
};

struct weatherdata {
	/*0x00*/ f32 windspeedx;
	/*0x04*/ f32 windspeedz;
	/*0x08*/ f32 windanglerad;
	/*0x0c*/ f32 unk0c;
	/*0x10*/ s32 unk10;
	/*0x14*/ f32 windspeed;
	/*0x18*/ u32 unk18;
	/*0x1c*/ u32 unk1c;
	/*0x20*/ s32 type;
	/*0x24*/ struct weatherparticledata *particledata;
	/*0x28*/ u32 unk28;
	/*0x2c*/ u32 unk2c;
	/*0x30*/ u32 unk30;
	/*0x34*/ struct audiohandle *audiohandles[4];
	/*0x44*/ s32 unk44;
	/*0x48*/ s32 unk48;
	/*0x4c*/ s32 unk4c;
	/*0x50*/ s32 unk50;
	/*0x54*/ s32 unk54;
	/*0x58*/ struct weather58 unk58[4];
	/*0x88*/ f32 unk88;
	/*0x8c*/ f32 unk8c;
	/*0x90*/ s32 unk90;
	/*0x94*/ s32 unk94;
	/*0x98*/ u32 unk98;
	/*0x9c*/ u32 unk9c;
	/*0xa0*/ u32 unka0;
	/*0xa4*/ u32 unka4;
	/*0xa8*/ u32 unka8;
	/*0xac*/ u32 unkac;
	/*0xb0*/ u32 unkb0;
	/*0xb4*/ u32 unkb4;
	/*0xb8*/ f32 unkb8;
	/*0xbc*/ f32 unkbc;
	/*0xc0*/ s32 unkc0;
	/*0xc4*/ f32 unkc4;
	/*0xc8*/ f32 unkc8;
	/*0xcc*/ s32 intensity;
	/*0xd0*/ s32 unkd0;
	/*0xd4*/ s32 unkd4;
	/*0xd8*/ u32 unkd8;
	/*0xdc*/ u32 unkdc;
	/*0xe0*/ u32 unke0;
	/*0xe4*/ u32 unke4;
	/*0xe8*/ u32 unke8;
	/*0xec*/ u32 unkec;
	/*0xf0*/ u32 unkf0;
	/*0xf4*/ u32 unkf4;
	/*0xf8*/ s16 unkf8;
	/*0xfc*/ u32 unkfc;
};

struct weatherparticle {
	struct coord pos;
	s32 active;
	struct coord inc;
	f32 unk1c;
};

struct weatherparticledata {
	struct weatherparticle particles[500];
	/*0x3e80*/ f32 unk3e80;
	/*0x3e84*/ f32 unk3e84;
	/*0x3e88*/ f32 unk3e88;
	/*0x3e8c*/ struct coord boundarymax;
	/*0x3e98*/ struct coord boundarymin;
	/*0x3ea4*/ struct coord boundaryrange;
	/*0x3eb0*/ u32 unk3eb0;
	/*0x3eb4*/ u32 unk3eb4;
	/*0x3eb8*/ u32 unk3eb8;
	/*0x3ebc*/ u32 unk3ebc;
	/*0x3ec0*/ u32 unk3ec0;
	/*0x3ec4*/ u32 unk3ec4;
	/*0x3ec8*/ f32 unk3ec8[8];
	/*0x3ee8*/ u32 unk3ee8;
	/*0x3eec*/ u32 unk3eec;
	/*0x3ef0*/ u32 unk3ef0;
	/*0x3ef4*/ u32 unk3ef4;
	/*0x3ef8*/ u32 unk3ef8;
	/*0x3efc*/ u32 unk3efc;
};

struct texture {
	u8 soundsurfacetype : 4;
	u8 surfacetype : 4;
	u8 unk01;
	u16 dataoffset;
	u32 unk04;
};

struct var800aabb8 {
	u16 unk00_00 : 2;
	u16 unk00_02 : 14;
};

struct fileinfo {
	u32 size;
	u32 unk04;
};

struct portalcmd {
	u8 type;
	u8 len;
	s32 param;
};

struct var800a4640_00 {
	s16 unk00;
	u8 unk02;
	u8 unk03;
	struct screenbox box;
};

struct var800a4640 {
	/*0x000*/ struct var800a4640_00 unk000[60];
	/*0x2d0*/ struct var800a4640_00 unk2d0;
};

struct zrange {
	f32 near;
	f32 far;
};

struct var800a4d00 {
	/*0x00*/ s16 roomnum;
	/*0x02*/ s16 unk02[5]; // also roomnums
	/*0x0c*/ s8 unk0c;
	/*0x0d*/ s8 unk0d;
	/*0x0e*/ s16 unk0e;
	/*0x10*/ struct screenbox screenbox;
};

struct var800a4cf0 {
	u16 unk00;
	s16 index; // index into unk10
	s16 unk04; // also an index into unk10
	struct zrange zrange;
	struct var800a4d00 unk10[250];
};

struct menuinputs {
	/*0x00*/ s8 leftright; // Both control stick and C/D buttons - set on initial press and key repeat
	/*0x01*/ s8 updown;    // As above
	/*0x02*/ u8 select;    // A/Z buttons
	/*0x03*/ u8 back;      // B button
	/*0x04*/ s8 xaxis;     // Control stick's current left/right position
	/*0x05*/ s8 yaxis;     // Control stick's current up/down position
	/*0x06*/ u8 shoulder;  // L or R buttons
	/*0x07*/ u8 back2;     // Used in keyboard
	/*0x08*/ s8 unk08;
	/*0x09*/ s8 unk09;
	/*0x0a*/ s8 start;
};

struct mpconfigsim {
	u8 type;
	u8 mpheadnum;
	u8 mpbodynum;
	u8 team;
	u8 difficulties[4]; // per player count
};

struct mpconfig {
	struct mpsetup setup;
	struct mpconfigsim simulants[8];
};

struct mpweapon {
	/*0x00*/ u8 weaponnum;
	/*0x01*/ s8 weapon1ammotypeminusone;
	/*0x02*/ u8 weapon1ammoqty;
	/*0x03*/ s8 weapon2ammotypeminusone;
	/*0x04*/ u8 weapon2ammoqty;
	/*0x05*/ u8 giveweapon : 1;
	/*0x05*/ u8 unlockfeature : 7;
	/*0x06*/ s16 model;
	/*0x08*/ s16 extrascale;
};

struct mpstrings {
	char description[200];
	char aibotnames[8][15];
};

struct mpconfigfull {
	struct mpconfig config;
	struct mpstrings strings;
};

struct movedata {
	/*0x00*/ s32 canswivelgun;
	/*0x04*/ s32 canmanualaim;
	/*0x08*/ s32 triggeron;
	/*0x0c*/ s32 btapcount;
	/*0x10*/ s32 canlookahead;
	/*0x14*/ s32 unk14;
	/*0x18*/ s32 cannaturalturn;
	/*0x1c*/ s32 cannaturalpitch;
	/*0x20*/ s32 digitalstepforward;
	/*0x24*/ s32 digitalstepback;
	/*0x28*/ s32 digitalstepleft;
	/*0x2c*/ s32 digitalstepright;
	/*0x30*/ f32 unk30;
	/*0x34*/ f32 unk34;
	/*0x38*/ f32 speedvertadown;
	/*0x3c*/ f32 speedvertaup;
	/*0x40*/ f32 aimturnleftspeed;
	/*0x44*/ f32 aimturnrightspeed;
	/*0x48*/ s32 weaponbackoffset;
	/*0x4c*/ s32 weaponforwardoffset;
	/*0x50*/ u32 unk50;
	/*0x54*/ u32 unk54;
	/*0x58*/ u32 unk58;
	/*0x5c*/ f32 zoomoutfovpersec;
	/*0x60*/ f32 zoominfovpersec;
	/*0x64*/ s32 crouchdown;
	/*0x68*/ s32 crouchup;
	/*0x6c*/ s32 rleanleft;
	/*0x70*/ s32 rleanright;
	/*0x74*/ s32 detonating;
	/*0x78*/ s32 canautoaim;
	/*0x7c*/ s32 farsighttempautoseek;
	/*0x80*/ s32 eyesshut;
	/*0x84*/ s32 invertpitch;
	/*0x88*/ s32 disablelookahead;
	/*0x8c*/ s32 c1stickxsafe; // raw values but adjusted to remove dead zone
	/*0x90*/ s32 c1stickysafe;
	/*0x94*/ s32 c1stickxraw; // raw values from control stick
	/*0x98*/ s32 c1stickyraw;
	/*0x9c*/ s32 analogturn;
	/*0xa0*/ s32 analogpitch;
	/*0xa4*/ s32 analogstrafe;
	/*0xa8*/ s32 analogwalk;
};

struct attackanimgroup {
	struct attackanimconfig *animcfg;
	s32 len;
};

struct modelthing {
	/*0x00*/ u32 unk00;
	/*0x04*/ u32 unk04;
	/*0x08*/ u32 unk08;
	/*0x0c*/ u32 unk0c;
	/*0x10*/ s16 unk10;
	/*0x12*/ u16 unk12;
	/*0x14*/ u16 unk14;
	/*0x16*/ u16 unk16;
};

struct animheader {
	/*0x00*/ u16 numframes;
	/*0x02*/ u16 framelen; // in bytes
	/*0x04*/ u8 *data;
	/*0x08*/ u16 initialposbytes;
	/*0x0a*/ u8 initiaposbitsperentry;
	/*0x0b*/ u8 flags;
};

struct objticksp476 {
	/*0x00*/ Mtxf *matrix;
	/*0x04*/ u32 unk04;
	/*0x08*/ u32 unk08;
	/*0x0c*/ u32 unk0c;
	/*0x10*/ Mtxf *unk10;
	/*0x14*/ u32 unk14;
	/*0x18*/ u32 unk18;
	/*0x1c*/ u32 unk1c;
	/*0x20*/ u32 unk20;
	/*0x24*/ u32 unk24;
	/*0x28*/ u32 unk28;
	/*0x2c*/ u32 unk2c;
	/*0x30*/ u32 unk30;
	/*0x34*/ u32 unk34;
	/*0x38*/ u32 unk38;
	/*0x3c*/ u32 unk3c;
};

// Suspected to be the same as objticksp476
struct modelrenderdata {
	/*0x00*/ u32 unk00;
	/*0x04*/ bool zbufferenabled;
	/*0x08*/ u32 flags;
	/*0x0c*/ Gfx *gdl;
	/*0x10*/ u32 unk10;
	/*0x14*/ u32 unk14;
	/*0x18*/ u32 unk18;
	/*0x1c*/ u32 unk1c;
	/*0x20*/ u32 unk20;
	/*0x24*/ u32 unk24;
	/*0x28*/ u32 unk28;
	/*0x2c*/ u32 unk2c;
	/*0x30*/ s32 unk30;
	/*0x34*/ u32 envcolour;
	/*0x38*/ u32 fogcolour;
	/*0x3c*/ u32 cullmode;
};

struct rend_vidat {
	/*0x00*/ void *unk00;
	/*0x04*/ u16 x;
	/*0x06*/ u16 y;
	/*0x08*/ f32 fovy;
	/*0x0c*/ f32 aspect;
	/*0x10*/ f32 znear;
	/*0x14*/ f32 zfar;
	/*0x18*/ s16 bufx;
	/*0x1a*/ s16 bufy;
	/*0x1c*/ s16 viewx;
	/*0x1e*/ s16 viewy;
	/*0x20*/ s16 viewleft;
	/*0x22*/ s16 viewtop;
	/*0x24*/ bool usezbuf;
	/*0x28*/ void *unk28;
};

struct var80062a8c {
	/*0x00*/ struct prop *prop;
	/*0x04*/ struct modelnode *node;
	/*0x08*/ struct model *model;
	/*0x0c*/ s32 lvframe60;
	/*0x10*/ s8 side;
	/*0x11*/ s8 unk011;
	/*0x12*/ s16 unk012;
	/*0x14*/ s16 unk014;
	/*0x14*/ s16 unk016;
	/*0x18*/ s8 unk018[32];
	/*0x38*/ s8 unk038[32];
	/*0x58*/ f32 shield;
};

struct bgroom {
	u32 unk00;
	struct coord pos;
	u8 unk10;
	u8 unk11;
};

struct damagetype {
	f32 flashstartframe;
	f32 flashfullframe;
	f32 flashendframe;
	f32 maxalpha;
	s32 red;
	s32 green;
	s32 blue;
};

struct healthdamagetype {
	s32 openendframe;
	s32 updatestartframe;
	s32 updateendframe;
	s32 closestartframe;
	s32 closeendframe;
};

struct optiongroup {
	s32 offset;
	u16 name;
};

struct var800aa5d8 {
	s32 tracktype;
	s32 tracknum;
	s32 unk08;
	f32 unk0c;
	s16 volume;
	s16 unk12;
	s16 unk14;
	s16 unk16;
	s16 unk18;
};

struct casing {
	/*0x00*/ u32 unk00;
	/*0x04*/ u32 unk04;
	/*0x08*/ u32 unk08;
	/*0x0c*/ u32 unk0c;
	/*0x10*/ u32 unk10;
	/*0x14*/ u32 unk14;
	/*0x18*/ u32 unk18;
	/*0x1c*/ u32 unk1c;
	/*0x20*/ u32 unk20;
	/*0x24*/ u32 unk24;
	/*0x28*/ u32 unk28;
	/*0x2c*/ u32 unk2c;
	/*0x30*/ u32 unk30;
	/*0x34*/ u32 unk34;
	/*0x38*/ u32 unk38;
	/*0x3c*/ u32 unk3c;
	/*0x40*/ u32 unk40;
};

struct mplockinfo {
	s8 lockedplayernum;
	s8 lastwinner;
	s8 lastloser;
	s8 unk03;
	s32 unk04; // might not be part of struct
};

struct var8009da60 {
	union {
		s32 unk00;
		struct prop *unk00_prop;
	};

	u8 unk04;
	u8 unk05;
	u32 unk08;
	u32 unk0c;
	u32 unk10;
	struct coord unk14;
	struct coord unk20;
	f32 unk2c;
};

struct var800a4ce8 {
	u16 unk00;
	s16 unk02;
};

struct var800aaa38 {
	u32 tracktype;
	u32 unk04;
	u32 unk08;
	u32 unk0c;
};

struct var80094ed8 {
	/*0x000*/ u32 unk000;
	/*0x004*/ u32 unk004;
	/*0x008*/ u32 unk008;
	/*0x00c*/ u32 unk00c;
	/*0x010*/ u32 unk010;
	/*0x014*/ u32 unk014;
	/*0x018*/ u32 unk018;
	/*0x01c*/ u32 unk01c;
	/*0x020*/ u32 unk020;
	/*0x024*/ u32 unk024;
	/*0x028*/ u32 unk028;
	/*0x02c*/ u32 unk02c;
	/*0x030*/ u32 unk030;
	/*0x034*/ u32 unk034;
	/*0x038*/ u32 unk038;
	/*0x03c*/ u32 unk03c;
	/*0x040*/ u32 unk040;
	/*0x044*/ u32 unk044;
	/*0x048*/ u32 unk048;
	/*0x04c*/ u32 unk04c;
	/*0x050*/ u32 unk050;
	/*0x054*/ u32 unk054;
	/*0x058*/ u32 unk058;
	/*0x05c*/ u32 unk05c;
	/*0x060*/ u32 unk060;
	/*0x064*/ u32 unk064;
	/*0x068*/ u32 unk068;
	/*0x06c*/ u32 unk06c;
	/*0x070*/ u32 unk070;
	/*0x074*/ u32 unk074;
	/*0x078*/ u32 unk078;
	/*0x07c*/ u32 unk07c;
	/*0x080*/ u32 unk080;
	/*0x084*/ u32 unk084;
	/*0x088*/ u32 unk088;
	/*0x08c*/ u32 unk08c;
	/*0x090*/ u32 unk090;
	/*0x094*/ u32 unk094;
	/*0x098*/ u32 unk098;
	/*0x09c*/ u32 unk09c;
	/*0x0a0*/ u32 unk0a0;
	/*0x0a4*/ u32 unk0a4;
	/*0x0a8*/ u32 unk0a8;
	/*0x0ac*/ u32 unk0ac;
	/*0x0b0*/ u32 unk0b0;
	/*0x0b4*/ u32 unk0b4;
	/*0x0b8*/ u32 unk0b8;
	/*0x0bc*/ u32 unk0bc;
	/*0x0c0*/ u32 unk0c0;
	/*0x0c4*/ u32 unk0c4;
	/*0x0c8*/ u32 unk0c8;
	/*0x0cc*/ u32 unk0cc;
	/*0x0d0*/ u32 unk0d0;
	/*0x0d4*/ u32 unk0d4;
	/*0x0d8*/ u32 unk0d8;
	/*0x0dc*/ u32 unk0dc;
	/*0x0e0*/ u32 unk0e0;
	/*0x0e4*/ u32 unk0e4;
	/*0x0e8*/ u32 unk0e8;
	/*0x0ec*/ u32 unk0ec;
	/*0x0f0*/ u32 unk0f0;
	/*0x0f4*/ u32 unk0f4;
	/*0x0f8*/ ALCSPlayer *seqp;
	/*0x0fc*/ void *unk0fc;
	/*0x100*/ u16 unk100;
	/*0x104*/ u32 unk104;
};

struct lasersight {
	s32 id;
	struct coord unk04;
	struct coord beamnear;
	struct coord beamfar;
	f32 unk28;
	struct coord dotpos;
	struct coord dotrot;
	u32 unk44;
};

struct vec3s16 {
	s16 x;
	s16 y;
	s16 z;
};

struct light {
	/*0x00*/ u16 roomnum;
	/*0x02*/ u16 unk02;
	/*0x04*/ u8 unk04;
	/*0x05*/ u8 unk05_00 : 1;
	/*0x05*/ u8 healthy : 1; // just a guess based on context
	/*0x05*/ u8 on : 1;
	/*0x05*/ u8 unk05_03 : 1;
	/*0x05*/ u8 vulnerable : 1;
	/*0x06*/ u8 unk06;
	/*0x07*/ s8 unk07;
	/*0x08*/ s8 unk08;
	/*0x09*/ s8 unk09;
	/*0x0a*/ struct vec3s16 bbox[4];
};

struct var80061420 {
	s32 unk00;
	s32 unk04;
};

struct var800ab5b8 {
	u32 unk00;
	u32 unk04;
	u32 unk08;
	u32 unk0c;
	u32 unk10;
	u32 unk14;
	u32 unk18;
	u32 unk1c;
	u32 unk20;
	u32 unk24;
	u32 unk28;
};

struct var800ab718 {
	u32 unk00;
	u32 unk04;
	u32 unk08;
	u32 unk0c;
	u32 unk10;
};

struct splat {
	/*0x000*/ struct coord unk000;
	/*0x00c*/ struct coord unk00c;
	/*0x018*/ u32 unk018;
	/*0x01c*/ struct coord unk01c;
	/*0x028*/ struct coord unk028;
	/*0x034*/ u32 unk034;
	/*0x038*/ u32 unk038;
	/*0x03c*/ u32 unk03c;
	/*0x040*/ u32 unk040;
	/*0x044*/ u32 unk044;
	/*0x048*/ u32 unk048;
	/*0x04c*/ u32 unk04c;
	/*0x050*/ u32 unk050;
	/*0x054*/ u32 unk054;
	/*0x058*/ u32 unk058;
	/*0x05c*/ u32 unk05c;
	/*0x060*/ u32 unk060;
	/*0x064*/ u32 unk064;
	/*0x068*/ u32 unk068;
	/*0x06c*/ u32 unk06c;
	/*0x070*/ u32 unk070;
	/*0x074*/ u32 unk074;
	/*0x078*/ u32 unk078;
	/*0x07c*/ u32 unk07c;
	/*0x080*/ u32 unk080;
	/*0x084*/ u32 unk084;
	/*0x088*/ u32 unk088;
	/*0x08c*/ u32 unk08c;
	/*0x090*/ u32 unk090;
	/*0x094*/ u32 unk094;
	/*0x098*/ u32 unk098;
	/*0x09c*/ u32 unk09c;
	/*0x0a0*/ u32 unk0a0;
	/*0x0a4*/ u32 unk0a4;
	/*0x0a8*/ u32 unk0a8;
	/*0x0ac*/ u32 unk0ac;
	/*0x0b0*/ u32 unk0b0;
	/*0x0b4*/ u32 unk0b4;
	/*0x0b8*/ u32 unk0b8;
	/*0x0bc*/ u32 unk0bc;
	/*0x0c0*/ u32 unk0c0;
	/*0x0c4*/ u32 unk0c4;
	/*0x0c8*/ u32 unk0c8;
	/*0x0cc*/ u32 unk0cc;
	/*0x0d0*/ u32 unk0d0;
	/*0x0d4*/ u32 unk0d4;
	/*0x0d8*/ u32 unk0d8;
	/*0x0dc*/ u32 unk0dc;
	/*0x0e0*/ u32 unk0e0;
	/*0x0e4*/ u32 unk0e4;
	/*0x0e8*/ u32 unk0e8;
	/*0x0ec*/ u32 unk0ec;
	/*0x0f0*/ u32 unk0f0;
	/*0x0f4*/ u32 unk0f4;
	/*0x0f8*/ u32 unk0f8;
	/*0x0fc*/ u32 unk0fc;
	/*0x100*/ u32 unk100;
	/*0x104*/ u32 unk104;
	/*0x108*/ u32 unk108;
	/*0x10c*/ u32 unk10c;
	/*0x110*/ u32 unk110;
	/*0x114*/ u32 unk114;
	/*0x118*/ u32 unk118;
	/*0x11c*/ u32 unk11c;
	/*0x120*/ u32 unk120;
	/*0x124*/ u32 unk124;
	/*0x128*/ u32 unk128;
	/*0x12c*/ u32 unk12c;
	/*0x130*/ u32 unk130;
	/*0x134*/ u32 unk134;
	/*0x138*/ u32 unk138;
	/*0x13c*/ u32 unk13c;
	/*0x140*/ u32 unk140;
	/*0x144*/ u32 unk144;
	/*0x148*/ u32 unk148;
	/*0x14c*/ u32 unk14c;
	/*0x150*/ u32 unk150;
	/*0x154*/ u32 unk154;
	/*0x158*/ u32 unk158;
	/*0x15c*/ u32 unk15c;
	/*0x160*/ u32 unk160;
	/*0x164*/ u32 unk164;
	/*0x168*/ u32 unk168;
	/*0x16c*/ u32 unk16c;
	/*0x170*/ u32 unk170;
	/*0x174*/ u32 unk174;
	/*0x178*/ u32 unk178;
	/*0x17c*/ u32 unk17c;
	/*0x180*/ u32 unk180;
	/*0x184*/ u32 unk184;
	/*0x188*/ u32 unk188;
	/*0x18c*/ u32 unk18c;
	/*0x190*/ u32 unk190;
	/*0x194*/ u32 unk194;
	/*0x198*/ u32 unk198;
	/*0x19c*/ u32 unk19c;
	/*0x1a0*/ u32 unk1a0;
	/*0x1a4*/ u32 unk1a4;
	/*0x1a8*/ u32 unk1a8;
	/*0x1ac*/ u32 unk1ac;
	/*0x1b0*/ u32 unk1b0;
	/*0x1b4*/ u32 unk1b4;
	/*0x1b8*/ u32 unk1b8;
	/*0x1bc*/ u32 unk1bc;
	/*0x1c0*/ u32 unk1c0;
	/*0x1c4*/ u32 unk1c4;
	/*0x1c8*/ u32 unk1c8;
	/*0x1cc*/ u32 unk1cc;
	/*0x1d0*/ u32 unk1d0;
	/*0x1d4*/ u32 unk1d4;
	/*0x1d8*/ u32 unk1d8;
	/*0x1dc*/ u32 unk1dc;
	/*0x1e0*/ u32 unk1e0;
	/*0x1e4*/ u32 unk1e4;
	/*0x1e8*/ u32 unk1e8;
	/*0x1ec*/ u32 unk1ec;
	/*0x1f0*/ u32 unk1f0;
	/*0x1f4*/ u32 unk1f4;
	/*0x1f8*/ u32 unk1f8;
	/*0x1fc*/ u32 unk1fc;
	/*0x200*/ u32 unk200;
	/*0x204*/ u32 unk204;
	/*0x208*/ u32 unk208;
	/*0x20c*/ u32 unk20c;
	/*0x210*/ u32 unk210;
	/*0x214*/ u32 unk214;
	/*0x218*/ u32 unk218;
	/*0x21c*/ u32 unk21c;
	/*0x220*/ u32 unk220;
	/*0x224*/ u32 unk224;
	/*0x228*/ u32 unk228;
	/*0x22c*/ u32 unk22c;
	/*0x230*/ u32 unk230;
	/*0x234*/ u32 unk234;
	/*0x238*/ u32 unk238;
	/*0x23c*/ u32 unk23c;
	/*0x240*/ u32 unk240;
	/*0x244*/ u32 unk244;
	/*0x248*/ u32 unk248;
	/*0x24c*/ u32 unk24c;
	/*0x250*/ u32 unk250;
	/*0x254*/ u32 unk254;
	/*0x258*/ u32 unk258;
	/*0x25c*/ u32 unk25c;
	/*0x260*/ u32 unk260;
	/*0x264*/ u32 unk264;
	/*0x268*/ u32 unk268;
	/*0x26c*/ u32 unk26c;
	/*0x270*/ u32 unk270;
	/*0x274*/ u32 unk274;
	/*0x278*/ u32 unk278;
	/*0x27c*/ u32 unk27c;
	/*0x280*/ u32 unk280;
	/*0x284*/ u32 unk284;
	/*0x288*/ u32 unk288;
	/*0x28c*/ u32 unk28c;
	/*0x290*/ u32 unk290;
	/*0x294*/ u32 unk294;
	/*0x298*/ u32 unk298;
	/*0x29c*/ u32 unk29c;
	/*0x2a0*/ u32 unk2a0;
	/*0x2a4*/ u32 unk2a4;
	/*0x2a8*/ u32 unk2a8;
	/*0x2ac*/ u32 unk2ac;
	/*0x2b0*/ u32 unk2b0;
	/*0x2b4*/ u32 unk2b4;
	/*0x2b8*/ u32 unk2b8;
	/*0x2bc*/ u32 unk2bc;
	/*0x2c0*/ u32 unk2c0;
	/*0x2c4*/ u32 unk2c4;
	/*0x2c8*/ u32 unk2c8;
	/*0x2cc*/ u32 unk2cc;
	/*0x2d0*/ u32 unk2d0;
	/*0x2d4*/ u32 unk2d4;
	/*0x2d8*/ u32 unk2d8;
	/*0x2dc*/ u32 unk2dc;
	/*0x2e0*/ u32 unk2e0;
	/*0x2e4*/ u32 unk2e4;
	/*0x2e8*/ u32 unk2e8;
	/*0x2ec*/ u32 unk2ec;
	/*0x2f0*/ u32 unk2f0;
	/*0x2f4*/ u32 unk2f4;
	/*0x2f8*/ u32 unk2f8;
	/*0x2fc*/ u32 unk2fc;
	/*0x300*/ u32 unk300;
	/*0x304*/ u32 unk304;
	/*0x308*/ u32 unk308;
	/*0x30c*/ u32 unk30c;
	/*0x310*/ u32 unk310;
	/*0x314*/ u32 unk314;
	/*0x318*/ u32 unk318;
	/*0x31c*/ u32 unk31c;
	/*0x320*/ u32 unk320;
	/*0x324*/ u32 unk324;
	/*0x328*/ u32 unk328;
	/*0x32c*/ u32 unk32c;
	/*0x330*/ u32 unk330;
	/*0x334*/ u32 unk334;
	/*0x338*/ u32 unk338;
	/*0x33c*/ u32 unk33c;
	/*0x340*/ u32 unk340;
	/*0x344*/ u32 unk344;
	/*0x348*/ u32 unk348;
	/*0x34c*/ u32 unk34c;
	/*0x350*/ u32 unk350;
	/*0x354*/ u32 unk354;
	/*0x358*/ u32 unk358;
	/*0x35c*/ u32 unk35c;
	/*0x360*/ u32 unk360;
	/*0x364*/ u32 unk364;
	/*0x368*/ u32 unk368;
	/*0x36c*/ u32 unk36c;
	/*0x370*/ u32 unk370;
	/*0x374*/ u32 unk374;
	/*0x378*/ u32 unk378;
	/*0x37c*/ u32 unk37c;
	/*0x380*/ u32 unk380;
	/*0x384*/ u32 unk384;
	/*0x388*/ u32 unk388;
	/*0x38c*/ u32 unk38c;
	/*0x390*/ u32 unk390;
	/*0x394*/ u32 unk394;
	/*0x398*/ u32 unk398;
	/*0x39c*/ u32 unk39c;
	/*0x3a0*/ u32 unk3a0;
	/*0x3a4*/ u32 unk3a4;
	/*0x3a8*/ u32 unk3a8;
	/*0x3ac*/ u32 unk3ac;
	/*0x3b0*/ u32 unk3b0;
	/*0x3b4*/ u32 unk3b4;
	/*0x3b8*/ u32 unk3b8;
	/*0x3bc*/ u32 unk3bc;
	/*0x3c0*/ u32 unk3c0;
	/*0x3c4*/ u32 unk3c4;
	/*0x3c8*/ u32 unk3c8;
	/*0x3cc*/ u32 unk3cc;
	/*0x3d0*/ u32 unk3d0;
	/*0x3d4*/ u32 unk3d4;
	/*0x3d8*/ u32 unk3d8;
	/*0x3dc*/ u32 unk3dc;
	/*0x3e0*/ u32 unk3e0;
	/*0x3e4*/ u32 unk3e4;
	/*0x3e8*/ u32 unk3e8;
	/*0x3ec*/ u32 unk3ec;
	/*0x3f0*/ u32 unk3f0;
	/*0x3f4*/ u32 unk3f4;
	/*0x3f8*/ u32 unk3f8;
	/*0x3fc*/ u32 unk3fc;
	/*0x400*/ u32 unk400;
	/*0x404*/ u32 unk404;
	/*0x408*/ u32 unk408;
	/*0x40c*/ u32 unk40c;
	/*0x410*/ u32 unk410;
	/*0x414*/ u32 unk414;
	/*0x418*/ u32 unk418;
	/*0x41c*/ u32 unk41c;
	/*0x420*/ u32 unk420;
	/*0x424*/ u32 unk424;
	/*0x428*/ u32 unk428;
	/*0x42c*/ u32 unk42c;
	/*0x430*/ u32 unk430;
	/*0x434*/ u32 unk434;
	/*0x438*/ u32 unk438;
	/*0x43c*/ u32 unk43c;
	/*0x440*/ u32 unk440;
};

struct menurendercontext {
	s16 x;
	s16 y;
	s16 width;
	s16 height;
	struct menuitem *item;
	bool focused;
	struct menuframe *frame;
	union menuitemdata *data;
};

struct menucolourpalette {
	/*0x00*/ u32 unk00;
	/*0x04*/ u32 unk04;
	/*0x08*/ u32 unk08;
	/*0x0c*/ u32 unk0c;
	/*0x10*/ u32 unk10;
	/*0x14*/ u32 unk14;
	/*0x18*/ u32 unfocused;
	/*0x1c*/ u32 disabled;
	/*0x20*/ u32 focused;
	/*0x24*/ u32 checkedunfocused;
	/*0x28*/ u32 unk28;
	/*0x2c*/ u32 unk2c;
	/*0x30*/ u32 unk30;
	/*0x34*/ u32 unk34;
	/*0x38*/ u32 unk38;
};

struct var800a45d0 {
	/*0x00*/ u8 unk00;
	/*0x04*/ u32 colour04;
	/*0x08*/ u32 colour08;
	/*0x0c*/ s32 unk0c;
	/*0x10*/ s32 unk10;
	/*0x14*/ f32 unk14;
	/*0x18*/ u8 unk18;
	/*0x1c*/ u32 unk1c;
	/*0x20*/ u32 unk20;
	/*0x24*/ f32 unk24;
	/*0x28*/ u8 unk28;
	/*0x29*/ u8 unk29;
	/*0x2a*/ u8 unk2a;
	/*0x2c*/ s32 unk2c;
	/*0x30*/ s32 unk30;
	/*0x34*/ u32 unk34;
	/*0x38*/ s32 x1;
	/*0x3c*/ s32 x2;
	/*0x40*/ u32 unk40;
	/*0x44*/ u32 colour44;
	/*0x48*/ u32 colour48;
	/*0x4c*/ u32 unk4c;
	/*0x50*/ u32 unk50;
	/*0x54*/ u32 unk54;
	/*0x58*/ u32 colour58;
	/*0x5c*/ u32 colour5c;
	/*0x60*/ u32 unk60;
};

struct bytelist {
	u8 b0;
	u8 b1;
	u8 b2;
	u8 b3;
	u8 b4;
	u8 b5;
	u8 b6;
	u8 b7;
	u8 b8;
	u8 b9;
};

struct stageallocation {
	s32 stagenum;
	char *string;
};

struct contsample {
	OSContPad pads[4];
};

struct joydata {
	struct contsample samples[20];
	s32 curlast;
	s32 curstart;
	s32 nextlast;
	s32 nextsecondlast;
	u16 buttonspressed[4];
	u16 buttonsreleased[4];
	s32 unk200;
};

struct guncmd {
	u8 type;
	u8 unk01;
	u16 unk02;
	s32 unk04;
};

struct pakthing {
	char unk00[4]; // len unknown
	u32 unk04;
	u32 unk08;
	u32 unk0c;
	u16 unk10;
};

struct pakfileheader {
	union {
		struct {
			u16 headersum[2];  // checksum from filetype to end of header
			u16 bodysum[2];
			u32 filetype : 9; // PAKFILETYPE constant
			u32 bodylen : 11; // not aligned
			u32 filelen : 12; // aligned to 0x10
			u32 deviceserial : 13;
			u32 fileid : 7;
			u32 unk0c_21 : 9;
			u32 occupied : 1;
			u32 writecompleted : 1; // 0 while writing data, then updated to 1 afterwards
			u32 version : 1;        // 0, but can be set to 1 using -forceversion argument
		};
		u8 bytes[16];
	};
};

struct var80067e6c {
	s16 animnum;
	f32 value;
};

struct gfxvtx {
	/*0x00*/ s16 x;
	/*0x02*/ s16 y;
	/*0x04*/ s16 z;
	/*0x06*/ u8 flags;
	/*0x07*/ u8 s;
	/*0x08*/ s16 unk08;
	/*0x0a*/ s16 unk0a;
};

struct shard {
	/*0x00*/ s16 room;
	/*0x04*/ s32 age60;
	/*0x08*/ struct coord pos;
	/*0x14*/ struct coord rot;
	/*0x20*/ struct coord vel;
	/*0x2c*/ struct coord rotspeed;
	/*0x38*/ struct gfxvtx vertices[3];
	/*0x5c*/ u8 colours[3][4];
	/*0x68*/ u8 type;
};

struct audiochannel {
	/*0x00*/ struct audiohandle *audiohandle;
	/*0x04*/ s16 soundnum04;
	/*0x06*/ s16 unk06;
	/*0x08*/ s16 unk08;
	/*0x0a*/ s16 unk0a;
	/*0x0c*/ s16 unk0c;
	/*0x0e*/ s16 unk0e;
	/*0x10*/ s16 unk10;
	/*0x12*/ u16 unk12;
	/*0x14*/ u32 unk14;
	/*0x18*/ s16 unk18;
	/*0x1a*/ u8 unk1a;
	/*0x1c*/ s32 unk1c;
	/*0x20*/ s32 unk20;
	/*0x24*/ s16 padnum;
	/*0x26*/ s16 soundnum26;
	/*0x28*/ s16 unk28;
	/*0x2a*/ u16 unk2a;
	/*0x2c*/ s16 unk2c;
	/*0x2e*/ s16 channelnum;
	/*0x30*/ u16 flags;
	/*0x32*/ u16 flags2;
	/*0x34*/ f32 unk34;
	/*0x38*/ f32 unk38;
	/*0x3c*/ f32 unk3c;
	/*0x40*/ f32 unk40;
	/*0x44*/ f32 unk44;
	/*0x48*/ f32 unk48;
	/*0x4c*/ f32 unk4c;
	/*0x50*/ struct prop *prop;
	/*0x54*/ struct coord *posptr;
	/*0x58*/ struct coord pos;
	/*0x64*/ s16 rooms[8];
#if VERSION >= VERSION_NTSC_1_0
	/*0x74*/ u32 uuid;
#endif
};

struct var8007e3d0_data {
	void *unk00;
	u32 unk04;
	u32 unk08;
	s16 unk0c;
	s16 unk0e;
};

struct var8007e3d0 {
	s32 valifsp;
	s32 numifsp;
	s32 valifmp;
	s32 numifmp;
	s32 valifspecial;
	s32 numifspecial;
	s32 unk18;
	s32 unk1c;
	s32 unk20;
	struct var8007e3d0_data *unk24;
	s32 val1;
	s32 val2;
	s32 numallocated;
};

struct stageheadlimit {
	u8 stagenum;
	u8 maxheads;
};

struct var800a41b0 {
	/*0x00*/ u32 unk00;
	/*0x04*/ u32 unk04;
	/*0x08*/ u32 unk08;
	/*0x0c*/ u32 unk0c;
	/*0x10*/ u32 unk10;
	/*0x14*/ u32 unk14;
	/*0x18*/ u32 unk18;
	/*0x1c*/ u32 unk1c;
	/*0x20*/ u32 unk20;
	/*0x24*/ u32 unk24;
	/*0x28*/ u32 unk28;
	/*0x2c*/ u32 unk2c;
	/*0x30*/ u32 unk30;
	/*0x34*/ u32 unk34;
	/*0x38*/ u32 unk38;
	/*0x3c*/ u32 unk3c;
	/*0x40*/ u32 unk40;
	/*0x44*/ u32 unk44;
	/*0x48*/ u32 unk48;
	/*0x4c*/ u32 unk4c;
	/*0x50*/ u32 unk50;
	/*0x54*/ u32 unk54;
	/*0x58*/ u32 unk58;
	/*0x5c*/ struct prop *prop;
	/*0x60*/ u32 unk60;
	/*0x64*/ u32 unk64;
	/*0x68*/ s16 unk68;
	/*0x6a*/ u8 unk6a;
	/*0x6b*/ u8 unk6b;
	/*0x6c*/ u8 unk6c;
	/*0x6d*/ u8 unk6d;
	/*0x6e*/ u8 unk6e;
	/*0x6f*/ u8 unk6f_00 : 1;
	/*0x6f*/ u8 unk6f_01 : 1;
	/*0x6f*/ u8 unk6f_02 : 1;
	/*0x6f*/ u8 unk6f_03 : 1;
	/*0x70*/ u32 unk70_00 : 28;
	/*0x70*/ u32 unk70_28 : 4;
	/*0x74*/ struct var800a41b0 *prev;
	/*0x78*/ u32 unk78;
};

/**
 * This struct is used as a pretend linked list.
 *
 * The final item in the propnums array is not a propnum; it's the index of the
 * next chunk in the chunks array.
 *
 * The first item in the propnums array is -2 if this chunk is unallocated.
 */
struct roomproplistchunk {
	s16 propnums[8];
};

struct var8009ce60 {
	struct defaultobj base;
	/*0x5c*/ u32 unk5c;
};

struct nbomb {
	struct coord pos;
	s32 age240;
	f32 radius;
	s16 unk14;
	f32 unk18;
	struct prop *prop;
	struct audiohandle *audiohandle20;
	struct audiohandle *audiohandle24;
};

struct roomacousticdata {
	f32 surfacearea;
	f32 unk04;
	f32 unk08;
	f32 roomvolume;
};

struct var8009dd78 {
	s16 unk00;
	f32 unk04;
};

struct colour {
	union {
		struct {
			u8 r;
			u8 g;
			u8 b;
			u8 a;
		} u8;
		u32 u32;
	};
};

struct var800ab570 {
	u32 unk00;
	u32 unk04;
};

struct collisionthing {
	struct tile *tile;
	u32 unk04;
	s32 unk08;
	struct prop *prop;
	u32 roomnum;
};

struct escastepkeyframe {
	s32 frame;
	struct coord pos;
};

struct fontchar {
	u8 index;
	s8 baseline;
	u8 height;
	u8 width;
	u32 unk04;
	u8 *pixeldata;
};

struct font {
	u32 unk000[169];
	struct fontchar chars[94]; // can be 135 in PAL
};

typedef union {
	struct {
		short     type;
	} gen;

	struct {
		short     type;
		struct    AudioInfo_s *info;
	} done;

	OSScMsg       app;
} AudioMsg;

typedef struct AudioInfo_s {
	short         *data;          /* Output data pointer */
	short         frameSamples;   /* # of samples synthesized in this frame */
	OSScTask      task;           /* scheduler structure */
	AudioMsg      msg;            /* completion message */
} AudioInfo;

typedef struct {
	Acmd          *ACMDList[2];
	AudioInfo     *audioInfo[3];
	OSThread      thread;
	OSMesgQueue   audioFrameMsgQ;
	OSMesg        audioFrameMsgBuf[8];
	OSMesgQueue   audioReplyMsgQ;
	OSMesg        audioReplyMsgBuf[8];
	ALGlobals     g;
} AMAudioMgr;

typedef struct {
	ALLink        node;
	u32           startAddr;
	u32           lastFrame;
	char          *ptr;
} AMDMABuffer;

typedef struct {
	u8            initialized;
	AMDMABuffer   *firstUsed;
	AMDMABuffer   *firstFree;
} AMDMAState;

union audioparam {
	s32 s32;
	f32 f32;
};

struct animationdefinition {
	u16 numkeyframes;
	u16 numkeyframebytes;
	void *data;
	u16 unk08;
	u8 unk0a;
	u8 flags;
};

struct portalvertices {
	u8 count;
	struct coord vertices[1];
};

struct aibotweaponpreference {
	u8 unk00;
	u8 unk01;
	u8 unk02;
	u8 unk03;
	u16 unk04_00 : 1;
	u16 unk04_01 : 1;
	u16 unk04_02 : 4;
	u16 unk04_06 : 4;
	u16 unk06;
	u16 unk08;
	u16 unk0a;
	u16 unk0c;
	u16 unk0e_00 : 3;
	u16 unk0e_03 : 1;
};

struct handweaponinfo {
	s32 weaponnum;
	struct weapon *definition;
	struct gunctrl *gunctrl;
};

struct seqtableentry {
	u8 *data;
	u16 binlen;
	u16 ziplen;
};

struct seqtable {
	u16 count;
	struct seqtableentry entries[1];
};

struct mp3vars {
	/*0x00*/ s32 var8009c390;
	/*0x04*/ u32 var8009c394;
	/*0x08*/ u8 *var8009c398;
	/*0x0c*/ s16 var8009c39c;
	/*0x0e*/ s16 var8009c39e;
	/*0x10*/ s16 ivol1;
	/*0x12*/ s16 ivol2;
	/*0x14*/ u16 var8009c3a4;
	/*0x16*/ u16 var8009c3a6;
	/*0x18*/ u16 ratel1;
	/*0x1a*/ s16 ratem1;
	/*0x1c*/ s16 var8009c3ac;
	/*0x1e*/ u16 ratel2;
	/*0x20*/ s16 ratem2;
	/*0x22*/ s16 var8009c3b2;
	/*0x24*/ u16 var8009c3b4;
	/*0x28*/ s32 samples;
	/*0x2c*/ s32 var8009c3bc;
	/*0x30*/ s32 var8009c3c0;
	/*0x34*/ s32 var8009c3c4;
	/*0x38*/ u32 var8009c3c8;
	/*0x3c*/ u32 var8009c3cc;
	/*0x40*/ u32 var8009c3d0;
	/*0x44*/ u8 *var8009c3d4;
	/*0x48*/ u32 var8009c3d8;
	/*0x4c*/ void *var8009c3dc;
	/*0x50*/ u32 var8009c3e0;
	/*0x54*/ u32 var8009c3e4;
	/*0x58*/ u32 var8009c3e8;
	/*0x5c*/ s16 var8009c3ec;
	/*0x5e*/ s16 var8009c3ee;
	/*0x60*/ u8 var8009c3f0;
};

struct var8009c340 {
	u8 unk00;
	u8 unk01;
	u8 unk02;
	u8 unk03;
};

struct var80095210 {
	u16 *soundnums;
	u8 unk04[45];
	u16 unk32[45];
};

struct rdptask {
	OSScTask sctask;
	u16 *framebuffer;
	u32 unk5c;
};

struct var8009ddec {
	/*0x00*/ u32 unk00;
	/*0x04*/ struct coord pos;
	/*0x10*/ f32 look[2];
	/*0x18*/ s32 pad;
};

struct hitthing {
	struct coord unk00;
	struct coord unk0c;
	u32 unk18;
	u32 unk1c;
	u32 unk20;
	u32 unk24;
	s16 unk28;
	s16 texturenum;
	s16 unk2c;
	s16 unk2e;
};

struct hit {
	/*0x00*/ f32 distance;
	/*0x04*/ struct prop *prop;
	/*0x08*/ u32 unk08;
	/*0x0c*/ struct modelnode *node;
	/*0x10*/ struct hitthing hitthing;
	/*0x40*/ u32 unk40;
	/*0x44*/ struct modelnode *unk44;
	/*0x48*/ struct model *model;
	/*0x4c*/ s8 unk4c;
	/*0x4d*/ s8 unk4d;
	/*0x50*/ struct coord pos;
	/*0x5c*/ struct coord dir;
};

struct shotdata {
	/*0x00*/ struct coord unk00;
	/*0x0c*/ struct coord unk0c;
	/*0x18*/ struct gset gset;
	/*0x1c*/ struct coord gunpos;
	/*0x28*/ struct coord dir;
	/*0x34*/ f32 unk34;
	/*0x38*/ s32 unk38;
	/*0x3c*/ struct hit hits[10];
};

#endif
