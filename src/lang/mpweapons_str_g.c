#include <ultra64.h>

char *lang[] = {
	/*0x00*/ "%shas the\n%s",
	/*0x01*/ "%shas the %s%s",
	/*0x02*/ "%shas our\n%s",
	/*0x03*/ "Got the %s%s",
	/*0x04*/ "You captured\nthe %s%s",
	/*0x05*/ "%scaptured our\n%s",
	/*0x06*/ "%scaptured\nthe %s%s",
	/*0x07*/ "Have a point for living!\n",
	/*0x08*/ "You're supposed to look\n",
	/*0x09*/ "after your friends!\n",
	/*0x0a*/ "Well done!\n",
	/*0x0b*/ "You popped a cap!\n",
	/*0x0c*/ "Have 2 Points...\n",
	/*0x0d*/ "You are the victim!\n",
	/*0x0e*/ "Protect %s!\n",
	/*0x0f*/ "Get %s!\n",
	/*0x10*/ "Download successful.\n",
	/*0x11*/ "Connection broken.\n",
	/*0x12*/ "Starting download.\n",
	/*0x13*/ "You need to use the Data Uplink.\n",
	/*0x14*/ "King of\nthe Hill!\n",
	/*0x15*/ "We have\nthe Hill!\n",
	/*0x16*/ "%shas captured\nthe Hill!\n",
	/*0x17*/ "%ds/Point\n",
	/*0x18*/ "1 Point!\n",
	/*0x19*/ "No Shield\n",
	/*0x1a*/ "Automatics\n",
	/*0x1b*/ "Rocket Launcher\n",
	/*0x1c*/ "Simulants\n",
	/*0x1d*/ "King of the Hill\n",
	/*0x1e*/ "Complex FarSight\n",
	/*0x1f*/ "Hold the Briefcase\n",
	/*0x20*/ "Pistol One-Hit Kills\n",
	/*0x21*/ "Capture the Case\n",
	/*0x22*/ "Cloaking\n",
	/*0x23*/ "Temple Explosives\n",
	/*0x24*/ "Slayer\n",
	/*0x25*/ "Tranquilizer\n",
	/*0x26*/ "Slow Motion\n",
	/*0x27*/ "Press START\n",
	/*0x28*/ "Paused\n",
	/*0x29*/ "Custom\n",
	/*0x2a*/ "Random\n",
	/*0x2b*/ "Random Five\n",
	/*0x2c*/ "Close Combat\n",
	/*0x2d*/ "Proximity Mine\n",
	/*0x2e*/ "Rocket Launcher\n",
	/*0x2f*/ "Grenade Launcher\n",
	/*0x30*/ "Explosive\n",
	/*0x31*/ "Golden Magnum\n",
	/*0x32*/ "Heavy\n",
	/*0x33*/ "Tranquilizer\n",
	/*0x34*/ "FarSight\n",
	/*0x35*/ "Power\n",
	/*0x36*/ "Automatics\n",
	/*0x37*/ "Pistols\n",
	/*0x38*/ "Test\n",
	/*0x39*/ "4mb Test\n",
	/*0x3a*/ "Nothing\n",
	/*0x3b*/ "Shield\n",
	/*0x3c*/ "Disabled\n",
	/*0x3d*/ "Objectives Complete\n",
	/*0x3e*/ "Unknown\n",
	/*0x3f*/ "Missing\n",
	/*0x40*/ "Damaged Controller Pak Inserted\n",
	/*0x41*/ "is damaged or inserted\n",
	/*0x42*/ "incorrectly.\n",
	/*0x43*/ "Please remove and try again.\n",
	/*0x44*/ "Full Controller Pak Inserted\n",
	/*0x45*/ "is too full to save files.\n",
	/*0x46*/ "Use the Game Notes Editor to\n",
	/*0x47*/ "free some space (hold START\n",
	/*0x48*/ "while powering up.)\n",
	/*0x49*/ "OK\n",
	/*0x4a*/ "----------\n",
	/*0x4b*/ "Hurricane Fists\n",
	/*0x4c*/ "Cloaking Device\n",
	/*0x4d*/ "Invincible\n",
	/*0x4e*/ "All Guns in Solo\n",
	/*0x4f*/ "Unlimited Ammo\n",
	/*0x50*/ "Unlimited Ammo, No Reloads\n",
	/*0x51*/ "Slo-mo Single Player\n",
	/*0x52*/ "DK Mode\n",
	/*0x53*/ "Trent's Magnum\n",
	/*0x54*/ "FarSight\n",
	/*0x55*/ "Small Jo\n",
	/*0x56*/ "Small Characters\n",
	/*0x57*/ "Enemy Shields\n",
	/*0x58*/ "Jo Shield\n",
	/*0x59*/ "Super Shield\n",
	/*0x5a*/ "Classic Sight\n",
	/*0x5b*/ "Team Heads Only\n",
	/*0x5c*/ "Play as Elvis\n",
	/*0x5d*/ "Enemy Rockets\n",
	/*0x5e*/ "Unlimited Ammo - Laptop Sentry Gun\n",
	/*0x5f*/ "Marquis of Queensbury Rules\n",
	/*0x60*/ "Perfect Darkness\n",
	/*0x61*/ "Pugilist\n",
	/*0x62*/ "Hotshot\n",
	/*0x63*/ "Hit and Run\n",
	/*0x64*/ "Alien\n",
	/*0x65*/ "R-Tracker / Weapon Cache Locations\n",
	/*0x66*/ "Rocket Launcher\n",
	/*0x67*/ "Sniper Rifle\n",
	/*0x68*/ "X-Ray Scanner\n",
	/*0x69*/ "Superdragon\n",
	/*0x6a*/ "Laptop Gun\n",
	/*0x6b*/ "Phoenix\n",
	/*0x6c*/ "Psychosis Gun\n",
	/*0x6d*/ "PP7\n",
	/*0x6e*/ "DD44\n",
	/*0x6f*/ "Klobb\n",
	/*0x70*/ "KF7 Soviet\n",
	/*0x71*/ "ZMG (9mm)\n",
	/*0x72*/ "D5K\n",
	/*0x73*/ "AR33\n",
	/*0x74*/ "RC-P90\n",
	/*0x75*/ "Velvet Dark\n",
	/*0x76*/ "Fun\n",
	/*0x77*/ "Gameplay\n",
	/*0x78*/ "Weapons\n",
	/*0x79*/ "Buddies\n",
	/*0x7a*/ "Weapons for Jo in Solo\n",
	/*0x7b*/ "Classic Weapons for Jo in Solo\n",
	/*0x7c*/ "dataDyne Defection",
	/*0x7d*/ "dataDyne Extraction",
	/*0x7e*/ "A51 Infiltration",
	/*0x7f*/ "A51 Rescue",
	/*0x80*/ "A51 Escape",
	/*0x81*/ "Difficulty:\n",
	/*0x82*/ "Cheat Solo Missions\n",
	/*0x83*/ "Cheat Combat Simulator\n",
	/*0x84*/ "Cheat Co-Operative\n",
	/*0x85*/ "Cheat Counter-Operative\n",
	/*0x86*/ "Dishonored\n",
	/*0x87*/ "Cheated\n",
	/*0x88*/ "Cheat available",
	/*0x89*/ "Complete",
	/*0x8a*/ "for cheat:",
	/*0x8b*/ "on",
	/*0x8c*/ "in under",
	/*0x8d*/ " or insert Game Boy (r) Perfect Dark into Transfer Pak (tm), connect Transfer Pak to any controller, then enter and exit menu",
	/*0x8e*/ "Select cheat for information\n",
	/*0x8f*/ "Buddy Available",
	/*0x90*/ "Win Golds on the firing range to enable classic guns.\n",
	/*0x91*/ "Sight on Screen\n",
	/*0x92*/ "Target\n",
	/*0x93*/ "Zoom Range\n",
	/*0x94*/ "Show Ammo\n",
	/*0x95*/ "Gun Function\n",
	/*0x96*/ "Paintball\n",
	/*0x97*/ "Subtitles\n",
	/*0x98*/ "Mission Time\n",
	/*0x99*/ "Mode\n",
	/*0x9a*/ "Split\n",
	/*0x9b*/ "Do you want to abort\nthe mission?\n",
	/*0x9c*/ "Joanna Leather\n",
	/*0x9d*/ "Joanna Negotiator\n",
	/*0x9e*/ "Elvis (Waistcoat)\n",
	/*0x9f*/ "Error\n",
	/*0xa0*/ "Cannot delete file as\nit is being used.\n",
	/*0xa1*/ "Cancel\n",
	/*0xa2*/ "Time Limit:\n",
	/*0xa3*/ "Score Limit:\n",
	/*0xa4*/ "Team Score Limit:\n",
	/*0xa5*/ "Challenge Completed!\n",
	/*0xa6*/ "Challenge Failed!\n",
	/*0xa7*/ "Challenge Cheated!\n",
	/*0xa8*/ "Cutscene Subtitles\n",
	/*0xa9*/ "In-Game Subtitles\n",
	/*0xaa*/ "Alternative Title Screen\n",
	/*0xab*/ "Start Challenge\n",
	/*0xac*/ "dataDyne Investigation",
	/*0xad*/ "Error\n",
	/*0xae*/ "The Controller Pak\nhas been removed.\n",
	/*0xaf*/ "Attempt Repair\n",
	/*0xb0*/ "Are you sure you want\nto attempt repair of\nthis Controller Pak?\n",
	/*0xb1*/ "Data may be lost!\n",
	/*0xb2*/ "Cancel\n",
	/*0xb3*/ "Repair\n",
	/*0xb4*/ "Repair Successful\n",
	/*0xb5*/ "The Controller Pak has\nbeen repaired.\n",
	/*0xb6*/ "Repair Failed\n",
	/*0xb7*/ "The Controller Pak could\nnot be repaired.\n",
	/*0xb8*/ "L/R: ",
	/*0xb9*/ "C-UP: ",
	/*0xba*/ "C-L/R: ",
	/*0xbb*/ "C-DOWN: ",
	/*0xbc*/ "A: ",
	/*0xbd*/ "B: ",
	/*0xbe*/ "STICK: ",
	/*0xbf*/ "Z: ",
	/*0xc0*/ "D-PAD: ",
	/*0xc1*/ "AIM TOGGLE",
	/*0xc2*/ "LOOK UP / GET UP",
	/*0xc3*/ "STRAFE",
	/*0xc4*/ "LOOK DOWN / CROUCH",
	/*0xc5*/ "CHANGE GUN / ACTIVEMENU",
	/*0xc6*/ "RELOAD / ACTION / SECONDARY FIRE",
	/*0xc7*/ "WALK AND TURN",
	/*0xc8*/ "FIRE",
	/*0xc9*/ "AS C-BUTTONS",
	/*0xca*/ "Turn off all Cheats\n",
	/*0xcb*/ NULL,
	/*0xcc*/ NULL,
	/*0xcd*/ NULL,
	/*0xce*/ NULL,
	/*0xcf*/ NULL,
	/*0xd0*/ NULL,
	/*0xd1*/ NULL,
	/*0xd2*/ NULL,
	/*0xd3*/ NULL,
	/*0xd4*/ NULL,
	/*0xd5*/ NULL,
	/*0xd6*/ NULL,
	/*0xd7*/ NULL,
	/*0xd8*/ NULL,
	/*0xd9*/ NULL,
	/*0xda*/ NULL,
	/*0xdb*/ NULL,
	/*0xdc*/ NULL,
	/*0xdd*/ NULL,
	/*0xde*/ NULL,
	/*0xdf*/ NULL,
	/*0xe0*/ NULL,
	/*0xe1*/ NULL,
	/*0xe2*/ NULL,
	/*0xe3*/ NULL,
	/*0xe4*/ NULL,
	/*0xe5*/ NULL,
	/*0xe6*/ NULL,
	/*0xe7*/ NULL,
	/*0xe8*/ NULL,
	/*0xe9*/ NULL,
	/*0xea*/ NULL,
	/*0xeb*/ NULL,
	/*0xec*/ NULL,
	/*0xed*/ NULL,
	/*0xee*/ NULL,
	/*0xef*/ NULL,
	/*0xf0*/ NULL,
	/*0xf1*/ NULL,
	/*0xf2*/ NULL,
	/*0xf3*/ NULL,
	/*0xf4*/ NULL,
	/*0xf5*/ NULL,
	/*0xf6*/ NULL,
	/*0xf7*/ NULL,
	/*0xf8*/ NULL,
	/*0xf9*/ NULL,
	/*0xfa*/ NULL,
	/*0xfb*/ NULL,
	/*0xfc*/ NULL,
	/*0xfd*/ NULL,
	/*0xfe*/ NULL,
	/*0xff*/ NULL,
	/*0x100*/ NULL,
	/*0x101*/ NULL,
	/*0x102*/ NULL,
	/*0x103*/ NULL,
	/*0x104*/ NULL,
	/*0x105*/ NULL,
	/*0x106*/ NULL,
	/*0x107*/ NULL,
};
