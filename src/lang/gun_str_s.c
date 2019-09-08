#include <ultra64.h>

char *lang[] = {
	/*0x00*/ "\n",
	/*0x01*/ "Kill count",
	/*0x02*/ "Died once\n",
	/*0x03*/ "Died",
	/*0x04*/ "times",
	/*0x05*/ "Suicide count",
	/*0x06*/ "Unarmed\n",
	/*0x07*/ "Falcon 2\n",
	/*0x08*/ "Falcon 2 (silencer)\n",
	/*0x09*/ "Falcon 2 (scope)\n",
	/*0x0a*/ "MagSec 4\n",
	/*0x0b*/ "Mauler\n",
	/*0x0c*/ "DY357 Magnum\n",
	/*0x0d*/ "DY357-LX\n",
	/*0x0e*/ "Phoenix\n",
	/*0x0f*/ "CMP150\n",
	/*0x10*/ "AR34\n",
	/*0x11*/ "Dragon\n",
	/*0x12*/ "SuperDragon\n",
	/*0x13*/ "K7 Avenger\n",
	/*0x14*/ "Cyclone\n",
	/*0x15*/ "MagSec SMG\n",
	/*0x16*/ "RC-P120\n",
	/*0x17*/ "Callisto NTG\n",
	/*0x18*/ "Laptop Gun\n",
	/*0x19*/ "Shotgun\n",
	/*0x1a*/ "Reaper\n",
	/*0x1b*/ "Rocket Launcher\n",
	/*0x1c*/ "Devastator\n",
	/*0x1d*/ "Slayer\n",
	/*0x1e*/ "MaianGrenade\n",
	/*0x1f*/ "FarSight XR-20\n",
	/*0x20*/ "Sniper Rifle\n",
	/*0x21*/ "Crossbow\n",
	/*0x22*/ "Tranquilizer\n",
	/*0x23*/ "Combat Knife\n",
	/*0x24*/ "Grenade\n",
	/*0x25*/ "N-Bomb\n",
	/*0x26*/ "Timed Mine\n",
	/*0x27*/ "Proximity Mine\n",
	/*0x28*/ "Remote Mine\n",
	/*0x29*/ "ECM Mine\n",
	/*0x2a*/ "FlashBang\n",
	/*0x2b*/ "Disguise\n",
	/*0x2c*/ "Rocket\n",
	/*0x2d*/ "Homing Rocket\n",
	/*0x2e*/ "Grenade Round\n",
	/*0x2f*/ "Laser\n",
	/*0x30*/ "Bolt\n",
	/*0x31*/ "Psychosis Gun\n",
	/*0x32*/ "PP9i\n",
	/*0x33*/ "CC13\n",
	/*0x34*/ "Klobb\n",
	/*0x35*/ "KF7 Special\n",
	/*0x36*/ "ZZT (9mm)\n",
	/*0x37*/ "D5K\n",
	/*0x38*/ "AR53\n",
	/*0x39*/ "RC-P45\n",
	/*0x3a*/ "Tester\n",
	/*0x3b*/ "Night Sight\n",
	/*0x3c*/ "CamSpy\n",
	/*0x3d*/ "DrugSpy\n",
	/*0x3e*/ "BombSpy\n",
	/*0x3f*/ "Door Decoder\n",
	/*0x40*/ "Explosives\n",
	/*0x41*/ "X-Ray Scanner\n",
	/*0x42*/ "Alien Medpack\n",
	/*0x43*/ "Suitcase\n",
	/*0x44*/ "Disguise\n",
	/*0x45*/ "IR Scanner\n",
	/*0x46*/ "R-Tracker\n",
	/*0x47*/ "Briefcase\n",
	/*0x48*/ "Suicide Pill\n",
	/*0x49*/ "Cloaking Device\n",
	/*0x4a*/ "Combat Boost\n",
	/*0x4b*/ "Data Uplink\n",
	/*0x4c*/ "Horizon Scanner\n",
	/*0x4d*/ "Falcon 2 (s)\n",
	/*0x4e*/ "Falcon 2 (+)\n",
	/*0x4f*/ "FarSight\n",
	/*0x50*/ "R-Launcher\n",
	/*0x51*/ "Proxy Mine\n",
	/*0x52*/ "Psychosis\n",
	/*0x53*/ "Knife\n",
	/*0x54*/ "DY357\n",
	/*0x55*/ "Single Shot\n",
	/*0x56*/ "Rapid Fire\n",
	/*0x57*/ "Burst Fire\n",
	/*0x58*/ "Reapage\n",
	/*0x59*/ "Shotgun Fire\n",
	/*0x5a*/ "Rail-gun effect\n",
	/*0x5b*/ "Rocket Launch\n",
	/*0x5c*/ "Targetted Rocket\n",
	/*0x5d*/ "Fly-By-Wire Rocket\n",
	/*0x5e*/ "Pistol Whip\n",
	/*0x5f*/ "Explosive Shells\n",
	/*0x60*/ "Guided Shots\n",
	/*0x61*/ "Magazine Discharge\n",
	/*0x62*/ "Grenade Launcher\n",
	/*0x63*/ "Wall Hugger\n",
	/*0x64*/ "Punch\n",
	/*0x65*/ "Disarm\n",
	/*0x66*/ "Follow Lock-On\n",
	/*0x67*/ "Use Scope\n",
	/*0x68*/ "Half Magazine Discharge\n",
	/*0x69*/ "Double Blast\n",
	/*0x6a*/ "Grinder\n",
	/*0x6b*/ "Sedate\n",
	/*0x6c*/ "Lethal Injection\n",
	/*0x6d*/ "Knife Slash\n",
	/*0x6e*/ "Throw Poison Knife\n",
	/*0x6f*/ "Target Locator\n",
	/*0x70*/ "Instant Kill\n",
	/*0x71*/ "Boost\n",
	/*0x72*/ "Revert\n",
	/*0x73*/ "High Impact Shells\n",
	/*0x74*/ "Cloak\n",
	/*0x75*/ "Deploy as Sentry Gun\n",
	/*0x76*/ "Proximity Self Destruct\n",
	/*0x77*/ "Threat Detector\n",
	/*0x78*/ "Timed Explosive\n",
	/*0x79*/ "Proximity Explosive\n",
	/*0x7a*/ "Remote Explosive\n",
	/*0x7b*/ "Detonate\n",
	/*0x7c*/ "4-Second Fuse\n",
	/*0x7d*/ "Proximity Pinball\n",
	/*0x7e*/ "Timed Detonation\n",
	/*0x7f*/ "Proximity Detonation\n",
	/*0x80*/ "3-Round Burst\n",
	/*0x81*/ "Charge-Up Shot\n",
	/*0x82*/ "Crouch\n",
	/*0x83*/ "Infect\n",
	/*0x84*/ "Pulse Fire\n",
	/*0x85*/ "Short Range Stream\n",
	/*0x86*/ "Impact Detonation\n",
	/*0x87*/ "Light Amplifier\n",
	/*0x88*/ "Mobile Camera\n",
	/*0x89*/ "X-Ray Vision\n",
	/*0x8a*/ "Thermal Imager\n",
	/*0x8b*/ "Zoom\n",
	/*0x8c*/ "Jamming Device\n",
	/*0x8d*/ "Connect\n",
	/*0x8e*/ "Identify Targets\n",
	/*0x8f*/ "Wear Disguise\n",
	/*0x90*/ "Place Explosives\n",
	/*0x91*/ "Telescopic Sight\n",
	/*0x92*/ "Silencer\n",
	/*0x93*/ "Magazine Extension\n",
	/*0x94*/ "Laser Sight\n",
	/*0x95*/ "dataDyne\n",
	/*0x96*/ "Carrington\n",
	/*0x97*/ "Chesluk Industries\n",
	/*0x98*/ "Skedar\n",
	/*0x99*/ "Maian\n",
	/*0x9a*/ "JonesCorp\n",
	/*0x9b*/ "Even without a weapon, you are still a worthy adversary. Use your fists to knock your opponents out or disarm them and use their weapons against them.\n",
	/*0x9c*/ "Accurate and trustworthy, this gun is the workhorse of the Institute's operations. Use the laser sight to place bullets with deadly effect, or pistol-whip adversaries to knock them out.\n",
	/*0x9d*/ "An upgraded Falcon 2, which has the added benefit of being silent, but deadly.\n",
	/*0x9e*/ "An upgraded Falcon 2, featuring a 2x magnification scope which allows you to take advantage of the Falcon's superior accuracy.\n",
	/*0x9f*/ "A state-of-the-art military pistol, largely used by peacekeeping forces. It has a slight zoom capability, and boasts a 3-round burst secondary fire mode.\n",
	/*0xa0*/ "If you see a Skedar coming at you, the chances are it's carrying one of these. A large magazine and a bladed barrel make the pistol a formidable handgun, but the killer blow comes from the secondary function - charge the shot up for extra power at the cost of a few rounds of ammo.\n",
	/*0xa1*/ "The dataDyne DY357 is the most powerful handgun in the world. Each round has an impressive penetration factor and knocks the target back with the weight and power of the shot. Custom models are made for valued clients; NSA director Trent Easton is rumored to have a gold plated variant.\n",
	/*0xa2*/ "The DY357-LX was custom built for NSA director Trent Easton. Besides boasting an attractive genuine tiger skin grip, this golden gun features a velocity optimized barrel, meaning that each bullet always meets its target with fatal force.\n",
	/*0xa3*/ "The Maian standard issue sidearm. A flexible gun, the pistol fires standard shots, or explosive shots at no cost to the rest of the magazine.\n",
	/*0xa4*/ "A dataDyne classic, and a bestseller, this submachine gun boasts a 32 rnd mag and a special feature - the ability to designate and lock on to targets in the line of sight. It turns an average marksman into an excellent one, provided he or she is clever enough to operate the gun. Average fire rate: 900 rpm.\n",
	/*0xa5*/ "The Carrington Institute's main assault rifle. A good range and magazine size make it a useful weapon; the secondary mode enables the user to move while zoomed in on a target. Average fire rate: 750 rpm.\n",
	/*0xa6*/ "A standard assault rifle with an evil twist - when the secondary mode is activated, it becomes a proximity-activated mine that looks like a gun. Average fire rate: 700 rpm.\n",
	/*0xa7*/ "A variant of the Dragon assault rifle - instead of a proximity explosive, it has a small grenade launcher. Excellent support weapon. Average fire rate: 700 rpm.\n",
	/*0xa8*/ "Another piece of high-tech kit from dataDyne. Ordinarily an assault rifle with a smallish magazine and a powerful punch, it has a threat detection mode that highlights explosives, wallguns, and similar hazards. Average fire rate: 950 rpm.\n",
	/*0xa9*/ "Designed for use by bodyguards, the Cyclone has been adopted by Presidential Security due to its excellent capability when used for suppression. In extreme circumstances, it can more than double the fire rate, discharging the magazine in a second. Average fire rate: 900 rpm. Unloads at 2000 rpm.\n",
	/*0xaa*/ "The Carrington Institute secret weapon. It fires at a phenomenal rate and has a huge magazine capacity. The secondary mode is a cloaking device that runs off the ammunition in the magazine. A devastating weapon. Average fire rate: 1100 rpm.\n",
	/*0xab*/ "Another example of excellent Maian firearm design. It can fire standard shots as fast as any other SMG, or it can fire high velocity rounds which will easily penetrate objects to find targets hiding in cover. The only drawbacks with the secondary fire mode are that the fire rate is lower and the accuracy suffers from the power of the shot. Average fire rate: 900 rpm (s/f:300 rpm).\n",
	/*0xac*/ "A submachine gun made to look like a laptop PC. In disguised form, the gun cannot fire, but when activated, it unfolds into shape. The PC gun will not bear close inspection; it will boot up, but the memory is a quarter of what it is supposed to be. Average fire rate: 1000 rpm.\n",
	/*0xad*/ "A dataDyne weapon manufactured for security forces. A nine-cartridge magazine combined with single or double fire modes make it a dangerous close-quarters weapon.\n",
	/*0xae*/ "A truly terrifying weapon in the hands of someone strong enough to control the massive recoil; for anyone else, a highly unwieldy but effective corridor clearance weapon. Maximum fire rate: 1800 rpm.\n",
	/*0xaf*/ "A cumbersome weapon. Fires either a standard rocket or a slower, homing rocket when locked on to the unfortunate target.\n",
	/*0xb0*/ "A long range grenade delivery system manufactured by dataDyne. The secondary fire mode coats the grenades with a sticky substance; when fired, the bomb attaches itself to wall or ceiling. After a few seconds, it detaches to fall to the ground, where it detonates.\n",
	/*0xb1*/ "The Skedar enjoy seeing the terror of their enemies. It seems natural that they should have a remote-controlled rocket as a secondary fire mode on their basic rocket launcher, so that they can take pleasure from the prey's vain attempts to escape the closing projectile.\n",
	/*0xb2*/ "The FarSight rifle is a Maian hybrid of an X-ray scanning device coupled with a rifle that can shoot through solid objects. The scope can lock onto and track life sources, though the device does not pan as fast as a running enemy can move.\n",
	/*0xb3*/ "With a powerful zoom and a high velocity bullet, this Carrington Institute weapon is one of the best sniper rifles ever made. Crouch down for perfectaccuracy.\n",
	/*0xb4*/ "This crossbow is a short-range 'pistol' sized example, mounted on a Carrington Institute agent's wrist. It folds up to aid concealment and can fire up to five bolts, either the more usual drugged shots, or a lethal bolt.\n",
	/*0xb5*/ "A rapid-fire device, it can be used as a weapon in an emergency, but it is designed primarily as a dermal spray injector for sedative drugs. Users are advised that a full discharge of the drug reservoir can be fatal.\n",
	/*0xb6*/ "A large and vicious combat knife. It contains a vial of poison that shatters when thrown, usually killing the target in approximately six seconds. A dataDyne weapon through and through.\n",
	/*0xb7*/ "An updated version of the trusty grenade. Can be thrown with a four-second fuse or used as a bouncing proximity bomb.\n",
	/*0xb8*/ "A hand-held, small area effect neutron bomb. It can either detonate on impact or be set to proximity detonation.\n",
	/*0xb9*/ "A mine with a short timed fuse. It has a threat detection/evaluation sensor that can be activated as a secondary mode.\n",
	/*0xba*/ "A mine with a proximity fuse. It has a threat detection/evaluation sensor that can be activated as a secondary mode.\n",
	/*0xbb*/ "A mine that can be triggered remotely. The activate command is the secondary mode.\n",
	/*0xbc*/ "A focused white-noise jamming device, capable of simulating one of many common electrical faults in any system to which it is directly attached.\n",
	/*0xbd*/ "The laser is wrist-mounted and deadly accurate. It can either fire long-range pulses, or it can sustain a constant, concentrated stream of energy at short range.\n",
	/*0xbe*/ "Geneered stimulants designed for combat applications. When administered, they seem to slow down the passage of time to give a reaction window.\n",
	/*0xbf*/ "The latest of a line of 'starlight' scopes that enhance visible light to produce a clearer picture of the surrounding environment. Uses a target-movement algorithm to highlight possible threats.\n",
	/*0xc0*/ "Using the smallest application yet of anti-grav technology, this is the ultimate snooping device. Has a video/audio link with a recording function and an onboard facility for spectroscopic holography.\n",
	/*0xc1*/ "A short-range scope that can see through any material - even lead - producing a simplified chromatic representation of the environment.\n",
	/*0xc2*/ "This scope uses infra-red scanning modulated with ultrasonic data to provide not only a clearer picture of the surrounding area, but also a location of any structural irregularities. It can also locate enemies using cloaking technology or other optical baffles.\n",
	/*0xc3*/ "Uses the light-warping qualities of an alien crystal to create a refractive field around the wearer. Functions as long as there is little kinetic disturbance within the field boundary; the act of firing a gun is enough to cause a return to visibility.\n",
	/*0xc4*/ "A binocular-input long range visual scanner. The visor shows a composite image of the two input sources. Also has a zoom function.\n",
	/*0xc5*/ "Capable of remote interrogation of almost any type of stored data, which is sent directly back to the Institute computer hackers. A variant of this device provides the hackers with a direct link into the local system.\n",
	/*0xc6*/ "A powerful tracking device that can be customized to fit any set of parameters: people, weapons, objects, and locations are some of the possibilities.\n",
	/*0xc7*/ "A modified medical scanner that contains the most up-to-date record of the President's state of health and a library of past conditions and treatments. It can detect the vital functions of the President from a distance, even when the target is in the middle of a crowd.\n",
	/*0xc8*/ "A safecracker, pure and simple. Breaks electronic encoded locks, usually in a matter of seconds, though this, of course, depends on the individual lock.\n",
	/*0xc9*/ "Maian medical marvel, can auto-diagnose and perform surgical procedures without the need of incisions. One drawback is that it only works on Maians; the other drawback is the lack of a bedside manner.\n",
	/*0xca*/ "A small plastic explosive charge, complete with sealed tamper-proof timer, and embedded with teflon-coated shrapnel. Nasty.\n",
	/*0xcb*/ "As you are aware, this is a directional fusion bomb, to be placed so that the charge is directed downwards. This will obliterate the dataDyne research labs and cause the rest of the building to collapse into the hole.\n",
	/*0xcc*/ "A small bug that is attached to any part of a communication relay. It 'piggybacks' the official signal, enabling the link between Institute and agent to be maintained through intensive local countermeasures; to all intents and purposes, it is part of the target location's comms setup.\n",
	/*0xcd*/ "The inner workings of this bug are a closely guarded secret - the self-destruct mechanism forms a large part of the device. It is speculated that this is an example of quantum molecular communication, which explains the phenomenal reliability of the device in field use.\n",
	/*0xce*/ "Uses quantum communication technology to provide supremely accurate targetting infomation to orbital weapons, helping to minimize collateral damage. The same technology is used in the Carrington Institute tracker bugs.\n",
	/*0xcf*/ "Details of the flight path and communication codes and frequencies for Air Force One - also current encryption keys.\n",
	/*0xd0*/ "All data pertaining to ocean floor research carried out by dataDyne on the pirated deep sea diving operations vessel Pelagic II. Contents  sonar mapping, geological data, alien artifact data, hull samples, etc.\n",
	/*0xd1*/ "The last personality-state recording of the artificial intelligence, self-designated Dr. Caroll, prior to memory wipe and cerebral restructuring. Use for case study, theoretical projections only. Morally incorrupt, and therefore dangerous. dataDyne I.S.C.E.O. 23/6/23\n",
	/*0xd2*/ "A chemical cocktail that warps the perceived reality of the target. Good becomes bad, bad becomes good; enemies and friends change places. Another one of the darker research projects from Trent Easton's Area 51.\n",
	/*0xd3*/ "Not your normal outfit. Wear it to pretend not to be you.\n",
	/*0xd4*/ "PROXY\n",
	/*0xd5*/ "TIMED\n",
	/*0xd6*/ "REMOTE\n",
	/*0xd7*/ "AUTOGUN\n",
	/*0xd8*/ "IMPACT\n",
	/*0xd9*/ "Big King Rocket\n",
	/*0xda*/ "Data Uplink\n",
	/*0xdb*/ "President Scanner\n",
	/*0xdc*/ "AutoSurgeon\n",
	/*0xdd*/ "Skedar Bomb\n",
	/*0xde*/ "Comms Rider\n",
	/*0xdf*/ "Tracer Bug\n",
	/*0xe0*/ "Target Amplifier\n",
	/*0xe1*/ "Flight Plans\n",
	/*0xe2*/ "Research Tape\n",
	/*0xe3*/ "Backup Disk\n",
	/*0xe4*/ "Key Card\n",
	/*0xe5*/ "Briefcase\n",
	/*0xe6*/ "Necklace\n",
	/*0xe7*/ "PresidentScan\n",
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
};
