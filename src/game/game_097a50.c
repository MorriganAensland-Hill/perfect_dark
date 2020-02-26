#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "gvars/gvars.h"
#include "types.h"

const char var7f1ab890[] = "rontime";
const char var7f1ab898[] = "rofftime";
const char var7f1ab8a4[] = "gkef";
const char var7f1ab8ac[] = "changegunmem type %d CurrentPlayer->gunctrl.gunmemtype %d\n";
const char var7f1ab8e8[] = "LockTimer: %d\n";
const char var7f1ab8f8[] = "BriGun: Releasing gunmem - current gunmemtype %d gunmemnew %d\n";
const char var7f1ab938[] = "GiveMem: %d\n";
const char var7f1ab948[] = "BriGun:  BriGunLoadTick process GUN_LOADSTATE_LOAD_OBJ\n";
const char var7f1ab980[] = "BriGun:  Loading - %s, pMem 0x%08x Size %d\n";
const char var7f1ab9ac[] = "BriGun:  Warning: LoadSize > MemSize, clamping decomp. buffer from %d to %d (%d Bytes)\n";
const char var7f1aba04[] = "BriGun:  obLoadto at 0x%08x, size %d\n";
const char var7f1aba2c[] = "BriGun:  Used size %d (Ob Size %d)\n";
const char var7f1aba50[] = "BriGun:  block len %d usedsize %d\n";
const char var7f1aba74[] = "BriGun:  obln ram_len %d block_len %d\n";
const char var7f1aba9c[] = "BriGun:  new used size %d\n";
const char var7f1abab8[] = "BriGun:  Texture Block at 0x%08x size %d, endp 0x%08x\n";
const char var7f1abaf0[] = "BriGun:  Set Load State: GUN_LOADSTATE_DECOMPRESS_TEXTURES\n";
const char var7f1abb2c[] = "BriGun:  BriGunLoadTick process GUN_LOADSTATE_DECOMPRESS_TEXTURES\n";
const char var7f1abb70[] = "BriGun:  at texture %d\n";
const char var7f1abb88[] = "BriGun:  Uncompress %d of %d\n";
const char var7f1abba8[] = "BriGun:  Set Load State: GUN_LOADSTATE_DECOMPRESS_DLS\n";
const char var7f1abbe0[] = "BriGun:  BriGunLoadTick process GUN_LOADSTATE_DECOMPRESS_DLS\n";
const char var7f1abc20[] = "BriGun:  propgfx_decompress 0x%08x\n";
const char var7f1abc44[] = "BriGun:  DL waste space %d from %d (Used %d, Ramlen %d, ObSize %d)\n";
const char var7f1abc88[] = "Increase GUNSAVESIZE to %d!!!\n";
const char var7f1abca8[] = "BriGun:  Set Load State: GUN_LOADSTATE_LOADED\n";
const char var7f1abcd8[] = "need a new gun loading (lock %d gunmemnew %d)\n";
const char var7f1abd08[] = "loading gun file: %d type: %d\n";
const char var7f1abd28[] = "BriGun: Process MASTER_GUN_LOADSTATE_FLUX\n";
const char var7f1abd54[] = "BriGun: Set Master State: MASTER_GUN_LOADSTATE_HANDS\n";
const char var7f1abd8c[] = "BriGun: Process MASTER_GUN_LOADSTATE_HANDS\n";
const char var7f1abdb8[] = "BriGun: Setup Hand Load\n";
const char var7f1abdd4[] = "Hand  : Using cached hands\n";
const char var7f1abdf0[] = "Hand  : Look ma no hands!\n";
const char var7f1abe0c[] = "BriGun: Set Master State: MASTER_GUN_LOADSTATE_GUN\n";
const char var7f1abe40[] = "BriGun: Process MASTER_GUN_LOADSTATE_GUN\n";
const char var7f1abe6c[] = "BriGun: Setup Gun Load\n";
const char var7f1abe84[] = "BriGun: Set Master State: MASTER_GUN_LOADSTATE_CARTS\n";
const char var7f1abebc[] = "BriGun: Process MASTER_GUN_LOADSTATE_CARTS\n";
const char var7f1abee8[] = "BriGun: Cart Loaded setting GUN_LOADSTATE_FLUX\n";
const char var7f1abf18[] = "BriGun: Cart loading - looking for carts\n";
const char var7f1abf44[] = "BriGun: Loading cart %d\n";
const char var7f1abf60[] = "BriGun: Request for cart %d ignored - cart already loaded\n";
const char var7f1abf9c[] = "BriGun: Compile Hand 0x%08x Gun 0x%0x8\n";
const char var7f1abfc4[] = "Gun   : Compiled Gun 0x%08x\n";
const char var7f1abfe4[] = "Gun   : Compiled Size %d\n";
const char var7f1ac000[] = "Hand  : Compiled Hand 0x%08x\n";
const char var7f1ac020[] = "Hand  : Compiled Size %d\n";
const char var7f1ac03c[] = "Gun   : Compile overhead %d bytes\n";
const char var7f1ac060[] = "Hand  : Hand Obj 0x%08x Gun Obj 0x%08x \n";
const char var7f1ac08c[] = "Gun   : After Comp : Base 0x%08x Free %d\n";
const char var7f1ac0b8[] = "Gun   : After Cached Setup : Base 0x%08x Free %d\n";
const char var7f1ac0ec[] = "Gun   : TotalUsed %d, Free %d\n";
const char var7f1ac10c[] = "BriGun: Set Master State: MASTER_GUN_LOADSTATE_LOADED\n";
const char var7f1ac144[] = "GunLockTimer: %d\n";
const char var7f1ac158[] = "** error\n";
const char var7f1ac164[] = "** error\n";
const char var7f1ac170[] = "wantedfn %d tiggle %d\n";
const char var7f1ac188[] = "%d\n";
const char var7f1ac18c[] = "%02d:%02d:%02d\n";
const char var7f1ac19c[] = "%02d:%02d\n";

const u32 var7f1ac1a8[] = {0x461c4000};
const u32 var7f1ac1ac[] = {0x3f451eb8};
const u32 var7f1ac1b0[] = {0x3f333333};
const u32 var7f1ac1b4[] = {0x3f5f5dd8};
const u32 var7f1ac1b8[] = {0x3f5f5dd8};
const u32 var7f1ac1bc[] = {0x7f09a1b8};
const u32 var7f1ac1c0[] = {0x7f09a1b8};
const u32 var7f1ac1c4[] = {0x7f09a17c};
const u32 var7f1ac1c8[] = {0x7f09a17c};
const u32 var7f1ac1cc[] = {0x7f09a17c};
const u32 var7f1ac1d0[] = {0x7f09a17c};
const u32 var7f1ac1d4[] = {0x7f09a17c};
const u32 var7f1ac1d8[] = {0x7f09a17c};
const u32 var7f1ac1dc[] = {0x7f09a17c};
const u32 var7f1ac1e0[] = {0x7f09a17c};
const u32 var7f1ac1e4[] = {0x7f09a17c};
const u32 var7f1ac1e8[] = {0x7f09a17c};
const u32 var7f1ac1ec[] = {0x7f09a17c};
const u32 var7f1ac1f0[] = {0x7f09a17c};
const u32 var7f1ac1f4[] = {0x7f09a17c};
const u32 var7f1ac1f8[] = {0x7f09a17c};
const u32 var7f1ac1fc[] = {0x7f09a17c};
const u32 var7f1ac200[] = {0x7f09a17c};
const u32 var7f1ac204[] = {0x7f09a17c};
const u32 var7f1ac208[] = {0x7f09a17c};
const u32 var7f1ac20c[] = {0x7f09a17c};
const u32 var7f1ac210[] = {0x7f09a17c};
const u32 var7f1ac214[] = {0x7f09a17c};
const u32 var7f1ac218[] = {0x7f09a17c};
const u32 var7f1ac21c[] = {0x7f09a17c};
const u32 var7f1ac220[] = {0x7f09a17c};
const u32 var7f1ac224[] = {0x7f09a1b8};
const u32 var7f1ac228[] = {0x7f09a17c};
const u32 var7f1ac22c[] = {0x7f09a17c};
const u32 var7f1ac230[] = {0x7f09a1b8};
const u32 var7f1ac234[] = {0x7f09a1b8};
const u32 var7f1ac238[] = {0x7f09a17c};
const u32 var7f1ac23c[] = {0x7f09a1b8};
const u32 var7f1ac240[] = {0x7f09a1b8};
const u32 var7f1ac244[] = {0x7f09a1b8};
const u32 var7f1ac248[] = {0x7f09a17c};
const u32 var7f1ac24c[] = {0x7f09a17c};
const u32 var7f1ac250[] = {0x7f09a17c};
const u32 var7f1ac254[] = {0x7f09a17c};
const u32 var7f1ac258[] = {0x7f09a17c};
const u32 var7f1ac25c[] = {0x7f09a17c};
const u32 var7f1ac260[] = {0x7f09a17c};
const u32 var7f1ac264[] = {0x7f09a17c};
const u32 var7f1ac268[] = {0x7f09a17c};
const u32 var7f1ac26c[] = {0x7f09a17c};
const u32 var7f1ac270[] = {0x7f09a17c};
const u32 var7f1ac274[] = {0x7f09a17c};
const u32 var7f1ac278[] = {0x7f09a17c};
const u32 var7f1ac27c[] = {0x7f09a17c};
const u32 var7f1ac280[] = {0x7f09a17c};
const u32 var7f1ac284[] = {0x7f09a17c};
const u32 var7f1ac288[] = {0x7f09a17c};
const u32 var7f1ac28c[] = {0x7f09a17c};
const u32 var7f1ac290[] = {0x7f09a1b8};
const u32 var7f1ac294[] = {0x7f09a17c};
const u32 var7f1ac298[] = {0x7f09a17c};
const u32 var7f1ac29c[] = {0x7f09a17c};
const u32 var7f1ac2a0[] = {0x7f09a17c};
const u32 var7f1ac2a4[] = {0x7f09a17c};
const u32 var7f1ac2a8[] = {0x7f09a17c};
const u32 var7f1ac2ac[] = {0x7f09a17c};
const u32 var7f1ac2b0[] = {0x7f09a1b8};
const u32 var7f1ac2b4[] = {0x7f09a1b8};
const u32 var7f1ac2b8[] = {0x7f09a1b8};
const u32 var7f1ac2bc[] = {0x7f09a17c};
const u32 var7f1ac2c0[] = {0x7f09a17c};
const u32 var7f1ac2c4[] = {0x7f09a17c};
const u32 var7f1ac2c8[] = {0x7f09a17c};
const u32 var7f1ac2cc[] = {0x7f09a17c};
const u32 var7f1ac2d0[] = {0x7f09a17c};
const u32 var7f1ac2d4[] = {0x7f09a17c};
const u32 var7f1ac2d8[] = {0x7f09a17c};
const u32 var7f1ac2dc[] = {0x7f09a17c};
const u32 var7f1ac2e0[] = {0x7f09a17c};
const u32 var7f1ac2e4[] = {0x7f09a17c};
const u32 var7f1ac2e8[] = {0x7f09a17c};
const u32 var7f1ac2ec[] = {0x7f09a17c};
const u32 var7f1ac2f0[] = {0x7f09a17c};
const u32 var7f1ac2f4[] = {0x7f09a17c};
const u32 var7f1ac2f8[] = {0x7f09a17c};
const u32 var7f1ac2fc[] = {0x7f09a17c};
const u32 var7f1ac300[] = {0x7f09a17c};
const u32 var7f1ac304[] = {0x7f09a17c};
const u32 var7f1ac308[] = {0x7f09a17c};
const u32 var7f1ac30c[] = {0x7f09a17c};
const u32 var7f1ac310[] = {0x7f09a17c};
const u32 var7f1ac314[] = {0x7f09a17c};
const u32 var7f1ac318[] = {0x7f09a1b8};
const u32 var7f1ac31c[] = {0x3f5f5dd8};
const u32 var7f1ac320[] = {0x3ecccccd};
const u32 var7f1ac324[] = {0x3fc90fdb};
const u32 var7f1ac328[] = {0x40c907a9};
const u32 var7f1ac32c[] = {0x3fc90fdb};
const u32 var7f1ac330[] = {0x40490fdb};
const u32 var7f1ac334[] = {0x3ecccccd};
const u32 var7f1ac338[] = {0x3dcccccd};
const u32 var7f1ac33c[] = {0x3c23d70a};
const u32 var7f1ac340[] = {0x7f09b928};
const u32 var7f1ac344[] = {0x7f09b928};
const u32 var7f1ac348[] = {0x7f09b928};
const u32 var7f1ac34c[] = {0x7f09b928};
const u32 var7f1ac350[] = {0x7f09b928};
const u32 var7f1ac354[] = {0x7f09b928};
const u32 var7f1ac358[] = {0x7f09b928};
const u32 var7f1ac35c[] = {0x7f09b928};
const u32 var7f1ac360[] = {0x7f09b928};
const u32 var7f1ac364[] = {0x7f09b928};
const u32 var7f1ac368[] = {0x7f09b928};
const u32 var7f1ac36c[] = {0x7f09b928};
const u32 var7f1ac370[] = {0x7f09b928};
const u32 var7f1ac374[] = {0x7f09b9f8};
const u32 var7f1ac378[] = {0x7f09b9f8};
const u32 var7f1ac37c[] = {0x7f09b9f8};
const u32 var7f1ac380[] = {0x7f09b9f8};
const u32 var7f1ac384[] = {0x7f09b9f8};
const u32 var7f1ac388[] = {0x7f09b928};
const u32 var7f1ac38c[] = {0x7f09b9f8};
const u32 var7f1ac390[] = {0x7f09b9f8};
const u32 var7f1ac394[] = {0x7f09b9f8};
const u32 var7f1ac398[] = {0x7f09b9f8};
const u32 var7f1ac39c[] = {0x7f09b9f8};
const u32 var7f1ac3a0[] = {0x7f09b9f8};
const u32 var7f1ac3a4[] = {0x7f09b9f8};
const u32 var7f1ac3a8[] = {0x7f09b928};
const u32 var7f1ac3ac[] = {0x7f09b9f8};
const u32 var7f1ac3b0[] = {0x7f09b9f8};
const u32 var7f1ac3b4[] = {0x7f09b9f8};
const u32 var7f1ac3b8[] = {0x7f09b9f8};
const u32 var7f1ac3bc[] = {0x7f09b9f8};
const u32 var7f1ac3c0[] = {0x7f09b9f8};
const u32 var7f1ac3c4[] = {0x7f09b9f8};
const u32 var7f1ac3c8[] = {0x7f09b928};
const u32 var7f1ac3cc[] = {0x7f09b928};
const u32 var7f1ac3d0[] = {0x7f09bbd8};
const u32 var7f1ac3d4[] = {0x7f09bb9c};
const u32 var7f1ac3d8[] = {0x7f09bb9c};
const u32 var7f1ac3dc[] = {0x7f09bb9c};
const u32 var7f1ac3e0[] = {0x7f09bb9c};
const u32 var7f1ac3e4[] = {0x7f09bb9c};
const u32 var7f1ac3e8[] = {0x7f09ba7c};
const u32 var7f1ac3ec[] = {0x7f09bb9c};
const u32 var7f1ac3f0[] = {0x7f09bb9c};
const u32 var7f1ac3f4[] = {0x7f09bb9c};
const u32 var7f1ac3f8[] = {0x7f09bb9c};
const u32 var7f1ac3fc[] = {0x7f09ba7c};
const u32 var7f1ac400[] = {0x7f09bb9c};
const u32 var7f1ac404[] = {0x7f09bb9c};
const u32 var7f1ac408[] = {0x7f09bb9c};
const u32 var7f1ac40c[] = {0x7f09bb9c};
const u32 var7f1ac410[] = {0x7f09bb9c};
const u32 var7f1ac414[] = {0x7f09bb9c};
const u32 var7f1ac418[] = {0x7f09bb9c};
const u32 var7f1ac41c[] = {0x7f09bb9c};
const u32 var7f1ac420[] = {0x7f09bb9c};
const u32 var7f1ac424[] = {0x7f09ba7c};
const u32 var7f1ac428[] = {0x7f09bb9c};
const u32 var7f1ac42c[] = {0x7f09bb9c};
const u32 var7f1ac430[] = {0x7f09bb9c};
const u32 var7f1ac434[] = {0x7f09bbd8};
const u32 var7f1ac438[] = {0x7f09bb9c};
const u32 var7f1ac43c[] = {0x7f09bb08};
const u32 var7f1ac440[] = {0x7f09bb9c};
const u32 var7f1ac444[] = {0x7f09bbd8};
const u32 var7f1ac448[] = {0x7f09bbd8};
const u32 var7f1ac44c[] = {0x7f09bbd8};
const u32 var7f1ac450[] = {0x7f09bbd8};
const u32 var7f1ac454[] = {0x7f09bbd8};
const u32 var7f1ac458[] = {0x7f09bbd8};
const u32 var7f1ac45c[] = {0x7f09bb9c};
const u32 var7f1ac460[] = {0x7f09bb9c};
const u32 var7f1ac464[] = {0x7f09bb9c};
const u32 var7f1ac468[] = {0x7f09bb9c};
const u32 var7f1ac46c[] = {0x7f09bb9c};
const u32 var7f1ac470[] = {0x7f09bb9c};
const u32 var7f1ac474[] = {0x7f09bb9c};
const u32 var7f1ac478[] = {0x7f09bb9c};
const u32 var7f1ac47c[] = {0x7f09bb08};
const u32 var7f1ac480[] = {0x40047ae1};
const u32 var7f1ac484[] = {0x3f5f5dd8};
const u32 var7f1ac488[] = {0x7f09c9ec};
const u32 var7f1ac48c[] = {0x7f09c9ec};
const u32 var7f1ac490[] = {0x7f09c9b0};
const u32 var7f1ac494[] = {0x7f09c9b0};
const u32 var7f1ac498[] = {0x7f09c9b0};
const u32 var7f1ac49c[] = {0x7f09c9b0};
const u32 var7f1ac4a0[] = {0x7f09c9b0};
const u32 var7f1ac4a4[] = {0x7f09c9b0};
const u32 var7f1ac4a8[] = {0x7f09c9b0};
const u32 var7f1ac4ac[] = {0x7f09c9b0};
const u32 var7f1ac4b0[] = {0x7f09c9b0};
const u32 var7f1ac4b4[] = {0x7f09c9b0};
const u32 var7f1ac4b8[] = {0x7f09c9b0};
const u32 var7f1ac4bc[] = {0x7f09c9b0};
const u32 var7f1ac4c0[] = {0x7f09c9ec};
const u32 var7f1ac4c4[] = {0x7f09c9b0};
const u32 var7f1ac4c8[] = {0x7f09c9b0};
const u32 var7f1ac4cc[] = {0x7f09c9b0};
const u32 var7f1ac4d0[] = {0x7f09c9b0};
const u32 var7f1ac4d4[] = {0x7f09c9b0};
const u32 var7f1ac4d8[] = {0x7f09c91c};
const u32 var7f1ac4dc[] = {0x7f09c9b0};
const u32 var7f1ac4e0[] = {0x7f09c9b0};
const u32 var7f1ac4e4[] = {0x7f09c9b0};
const u32 var7f1ac4e8[] = {0x7f09c9b0};
const u32 var7f1ac4ec[] = {0x7f09c9b0};
const u32 var7f1ac4f0[] = {0x7f09c7b4};
const u32 var7f1ac4f4[] = {0x7f09c9ec};
const u32 var7f1ac4f8[] = {0x7f09c888};
const u32 var7f1ac4fc[] = {0x7f09c770};
const u32 var7f1ac500[] = {0x7f09c9ec};
const u32 var7f1ac504[] = {0x7f09c9ec};
const u32 var7f1ac508[] = {0x7f09c844};
const u32 var7f1ac50c[] = {0x7f09c844};
const u32 var7f1ac510[] = {0x7f09c7f8};
const u32 var7f1ac514[] = {0x7f09c9ec};
const u32 var7f1ac518[] = {0x7f09c9b0};
const u32 var7f1ac51c[] = {0x7f09c9b0};
const u32 var7f1ac520[] = {0x7f09c9b0};
const u32 var7f1ac524[] = {0x7f09c9b0};
const u32 var7f1ac528[] = {0x7f09c9b0};
const u32 var7f1ac52c[] = {0x7f09c9b0};
const u32 var7f1ac530[] = {0x7f09c9b0};
const u32 var7f1ac534[] = {0x7f09c9b0};
const u32 var7f1ac538[] = {0x7f09c888};
const u32 var7f1ac53c[] = {0x7f09c9b0};
const u32 var7f1ac540[] = {0x7f09c9b0};
const u32 var7f1ac544[] = {0x7f09c9b0};
const u32 var7f1ac548[] = {0x7f09c9b0};
const u32 var7f1ac54c[] = {0x7f09c9ec};
const u32 var7f1ac550[] = {0x7f09c6dc};
const u32 var7f1ac554[] = {0x7f09c9b0};
const u32 var7f1ac558[] = {0x7f09c9b0};
const u32 var7f1ac55c[] = {0x7f09c844};
const u32 var7f1ac560[] = {0x7f09c844};
const u32 var7f1ac564[] = {0x7f09c844};
const u32 var7f1ac568[] = {0x7f09c844};
const u32 var7f1ac56c[] = {0x7f09c844};
const u32 var7f1ac570[] = {0x7f09c844};
const u32 var7f1ac574[] = {0x7f09c9ec};
const u32 var7f1ac578[] = {0x7f09c9ec};
const u32 var7f1ac57c[] = {0x7f09c844};
const u32 var7f1ac580[] = {0x7f09c844};
const u32 var7f1ac584[] = {0x7f09c844};
const u32 var7f1ac588[] = {0x7f09c9ec};
const u32 var7f1ac58c[] = {0x7f09c9ec};
const u32 var7f1ac590[] = {0x7f09c9ec};
const u32 var7f1ac594[] = {0x7f09c9ec};
const u32 var7f1ac598[] = {0x7f09c9ec};
const u32 var7f1ac59c[] = {0x7f09c9ec};
const u32 var7f1ac5a0[] = {0x7f09c9ec};
const u32 var7f1ac5a4[] = {0x7f09c9ec};
const u32 var7f1ac5a8[] = {0x7f09c9ec};
const u32 var7f1ac5ac[] = {0x7f09c9ec};
const u32 var7f1ac5b0[] = {0x7f09c9ec};
const u32 var7f1ac5b4[] = {0x7f09c9ec};
const u32 var7f1ac5b8[] = {0x7f09c9ec};
const u32 var7f1ac5bc[] = {0x7f09c9ec};
const u32 var7f1ac5c0[] = {0x7f09c9ec};
const u32 var7f1ac5c4[] = {0x7f09c9b0};
const u32 var7f1ac5c8[] = {0x7f09c9ec};
const u32 var7f1ac5cc[] = {0x7f09c9b0};
const u32 var7f1ac5d0[] = {0x7f09c9b0};
const u32 var7f1ac5d4[] = {0x7f09c9b0};
const u32 var7f1ac5d8[] = {0x7f09c9b0};
const u32 var7f1ac5dc[] = {0x7f09c9b0};
const u32 var7f1ac5e0[] = {0x7f09c9b0};
const u32 var7f1ac5e4[] = {0x7f09c9ec};
const u32 var7f1ac5e8[] = {0x3f59999a};
const u32 var7f1ac5ec[] = {0x3f5f5dd8};
const u32 var7f1ac5f0[] = {0x7f09cc10};
const u32 var7f1ac5f4[] = {0x7f09cc28};
const u32 var7f1ac5f8[] = {0x7f09cc58};
const u32 var7f1ac5fc[] = {0x7f09cc88};
const u32 var7f1ac600[] = {0x7f09cc40};
const u32 var7f1ac604[] = {0x7f09cc70};
const u32 var7f1ac608[] = {0x7f09cccc};
const u32 var7f1ac60c[] = {0x7f09ccb8};
const u32 var7f1ac610[] = {0x7f09cca0};
const u32 var7f1ac614[] = {0x3da3d70a};
const u32 var7f1ac618[] = {0x3dcccccd};
const u32 var7f1ac61c[] = {0x3dcccccd};
const u32 var7f1ac620[] = {0x3dcccccd};
const u32 var7f1ac624[] = {0x3f7cb924};
const u32 var7f1ac628[] = {0x3c51b700};
const u32 var7f1ac62c[] = {0x3f4ccccd};
const u32 var7f1ac630[] = {0x3dcccccd};
const u32 var7f1ac634[] = {0x3dcccccd};
const u32 var7f1ac638[] = {0x40c907a9};
const u32 var7f1ac63c[] = {0x40333333};
const u32 var7f1ac640[] = {0x3f4ccccd};
const u32 var7f1ac644[] = {0x3e4ccccd};
const u32 var7f1ac648[] = {0x3dcccccd};
const u32 var7f1ac64c[] = {0x3e99999a};
const u32 var7f1ac650[] = {0x3f7cb924};
const u32 var7f1ac654[] = {0x3f7cb924};
const u32 var7f1ac658[] = {0x3c51b700};
const u32 var7f1ac65c[] = {0x3c888889};
const u32 var7f1ac660[] = {0x3e4ccccd};
const u32 var7f1ac664[] = {0x3dcccccd};
const u32 var7f1ac668[] = {0xbdcccccd};
const u32 var7f1ac66c[] = {0xbf4ccccd};
const u32 var7f1ac670[] = {0x7f09df30};
const u32 var7f1ac674[] = {0x7f09df40};
const u32 var7f1ac678[] = {0x7f09df40};
const u32 var7f1ac67c[] = {0x7f09df40};
const u32 var7f1ac680[] = {0x7f09df40};
const u32 var7f1ac684[] = {0x7f09df40};
const u32 var7f1ac688[] = {0x7f09df40};
const u32 var7f1ac68c[] = {0x7f09df40};
const u32 var7f1ac690[] = {0x7f09df40};
const u32 var7f1ac694[] = {0x7f09df40};
const u32 var7f1ac698[] = {0x7f09df30};
const u32 var7f1ac69c[] = {0x7f09df40};
const u32 var7f1ac6a0[] = {0x7f09df40};
const u32 var7f1ac6a4[] = {0x7f09df40};
const u32 var7f1ac6a8[] = {0x7f09df40};
const u32 var7f1ac6ac[] = {0x7f09df30};
const u32 var7f1ac6b0[] = {0x7f09df40};
const u32 var7f1ac6b4[] = {0x7f09df40};
const u32 var7f1ac6b8[] = {0x7f09df40};
const u32 var7f1ac6bc[] = {0x7f09df40};
const u32 var7f1ac6c0[] = {0x7f09df30};
const u32 var7f1ac6c4[] = {0x7f09df40};
const u32 var7f1ac6c8[] = {0x7f09df40};
const u32 var7f1ac6cc[] = {0x7f09df30};
const u32 var7f1ac6d0[] = {0x7f09e080};
const u32 var7f1ac6d4[] = {0x7f09e11c};
const u32 var7f1ac6d8[] = {0x7f09e0b8};
const u32 var7f1ac6dc[] = {0x7f09e110};
const u32 var7f1ac6e0[] = {0x7f09e11c};
const u32 var7f1ac6e4[] = {0x7f09e11c};
const u32 var7f1ac6e8[] = {0x7f09e11c};
const u32 var7f1ac6ec[] = {0x7f09e11c};
const u32 var7f1ac6f0[] = {0x7f09e11c};
const u32 var7f1ac6f4[] = {0x7f09e11c};
const u32 var7f1ac6f8[] = {0x7f09e118};
const u32 var7f1ac6fc[] = {0x7f09e118};
const u32 var7f1ac700[] = {0x4141999a};
const u32 var7f1ac704[] = {0x3dcccccd};
const u32 var7f1ac708[] = {0x4096c5bf};
const u32 var7f1ac70c[] = {0x404907a9};
const u32 var7f1ac710[] = {0x3fd55555};
const u32 var7f1ac714[] = {0x3eb2b179};
const u32 var7f1ac718[] = {0xbeb2b179};
const u32 var7f1ac71c[] = {0x3eb2b179};
const u32 var7f1ac720[] = {0x41ad5555};
const u32 var7f1ac724[] = {0x41855555};
const u32 var7f1ac728[] = {0x3fd55555};
const u32 var7f1ac72c[] = {0x3dcccccd};
const u32 var7f1ac730[] = {0x3fd55555};
const u32 var7f1ac734[] = {0x3e32b179};
const u32 var7f1ac738[] = {0xbe32b179};
const u32 var7f1ac73c[] = {0x3e32b179};
const u32 var7f1ac740[] = {0x3fd55555};
const u32 var7f1ac744[] = {0x3e99999a};
const u32 var7f1ac748[] = {0x3dcccccd};
const u32 var7f1ac74c[] = {0x3e99999a};
const u32 var7f1ac750[] = {0x3dcccccd};
const u32 var7f1ac754[] = {0xb3d6bf95};
const u32 var7f1ac758[] = {0x33d6bf95};
const u32 var7f1ac75c[] = {0xc5bb8000};
const u32 var7f1ac760[] = {0x3f6d4de3};
const u32 var7f1ac764[] = {0x3d9590e8};
const u32 var7f1ac768[] = {0x3e2aaaab};
const u32 var7f1ac76c[] = {0x7f0a2de0};
const u32 var7f1ac770[] = {0x7f0a2e00};
const u32 var7f1ac774[] = {0x7f0a2e20};
const u32 var7f1ac778[] = {0x7f0a2e38};
const u32 var7f1ac77c[] = {0x7f0a2e4c};
const u32 var7f1ac780[] = {0x7f0a2e60};
const u32 var7f1ac784[] = {0x7f0a2f10};
const u32 var7f1ac788[] = {0x7f0a3070};
const u32 var7f1ac78c[] = {0x7f0a3070};
const u32 var7f1ac790[] = {0x7f0a2fb4};
const u32 var7f1ac794[] = {0x7f0a2fdc};
const u32 var7f1ac798[] = {0x7f0a3070};
const u32 var7f1ac79c[] = {0x7f0a3070};
const u32 var7f1ac7a0[] = {0x7f0a3070};
const u32 var7f1ac7a4[] = {0x7f0a3070};
const u32 var7f1ac7a8[] = {0x7f0a3070};
const u32 var7f1ac7ac[] = {0x7f0a2f4c};
const u32 var7f1ac7b0[] = {0x7f0a3070};
const u32 var7f1ac7b4[] = {0x7f0a3070};
const u32 var7f1ac7b8[] = {0x7f0a3070};
const u32 var7f1ac7bc[] = {0x7f0a3070};
const u32 var7f1ac7c0[] = {0x7f0a2f88};
const u32 var7f1ac7c4[] = {0x7f0a3004};
const u32 var7f1ac7c8[] = {0x40490fdb};
const u32 var7f1ac7cc[] = {0x42853333};
const u32 var7f1ac7d0[] = {0x3c8efa35};
const u32 var7f1ac7d4[] = {0x3f19999a};
const u32 var7f1ac7d8[] = {0x3e4ccccd};
const u32 var7f1ac7dc[] = {0x7f0a35ac};
const u32 var7f1ac7e0[] = {0x7f0a36dc};
const u32 var7f1ac7e4[] = {0x7f0a35ac};
const u32 var7f1ac7e8[] = {0x7f0a35dc};
const u32 var7f1ac7ec[] = {0x7f0a35dc};
const u32 var7f1ac7f0[] = {0x7f0a36dc};
const u32 var7f1ac7f4[] = {0x7f0a360c};
const u32 var7f1ac7f8[] = {0x7f0a360c};
const u32 var7f1ac7fc[] = {0x7f0a363c};
const u32 var7f1ac800[] = {0x7f0a3664};
const u32 var7f1ac804[] = {0x7f0a36dc};
const u32 var7f1ac808[] = {0x7f0a3690};
const u32 var7f1ac80c[] = {0x7f0a3664};
const u32 var7f1ac810[] = {0x7f0a363c};
const u32 var7f1ac814[] = {0x7f0a363c};
const u32 var7f1ac818[] = {0x7f0a363c};
const u32 var7f1ac81c[] = {0x7f0a363c};
const u32 var7f1ac820[] = {0x7f0a36c4};
const u32 var7f1ac824[] = {0x7f0a36b8};
const u32 var7f1ac828[] = {0x3f28f5c3};
const u32 var7f1ac82c[] = {0x3f666666};
const u32 var7f1ac830[] = {0x7f0a372c};
const u32 var7f1ac834[] = {0x7f0a3740};
const u32 var7f1ac838[] = {0x7f0a372c};
const u32 var7f1ac83c[] = {0x7f0a372c};
const u32 var7f1ac840[] = {0x7f0a372c};
const u32 var7f1ac844[] = {0x7f0a3740};
const u32 var7f1ac848[] = {0x7f0a372c};
const u32 var7f1ac84c[] = {0x7f0a372c};
const u32 var7f1ac850[] = {0x7f0a3740};
const u32 var7f1ac854[] = {0x7f0a3740};
const u32 var7f1ac858[] = {0x7f0a3740};
const u32 var7f1ac85c[] = {0x7f0a3740};
const u32 var7f1ac860[] = {0x7f0a3740};
const u32 var7f1ac864[] = {0x7f0a3740};
const u32 var7f1ac868[] = {0x7f0a3740};
const u32 var7f1ac86c[] = {0x7f0a3740};
const u32 var7f1ac870[] = {0x7f0a3740};
const u32 var7f1ac874[] = {0x7f0a373c};
const u32 var7f1ac878[] = {0x7f0a3734};
const u32 var7f1ac87c[] = {0x3c23d70a};
const u32 var7f1ac880[] = {0x3f747ae1};
const u32 var7f1ac884[] = {0x47ae147b};
const u32 var7f1ac888[] = {0x33d6bf95};
const u32 var7f1ac88c[] = {0xbe0f5c29};
const u32 var7f1ac890[] = {0x3e19999a};
const u32 var7f1ac894[] = {0x40490fdb};
const u32 var7f1ac898[] = {0x3e4ccccd};
const u32 var7f1ac89c[] = {0x40490fdb};
const u32 var7f1ac8a0[] = {0x3e4ccccd};
const u32 var7f1ac8a4[] = {0x40c90fd0};
const u32 var7f1ac8a8[] = {0x3dcccccd};
const u32 var7f1ac8ac[] = {0x3dcccccd};
const u32 var7f1ac8b0[] = {0x3ecccccd};
const u32 var7f1ac8b4[] = {0x3f19999a};
const u32 var7f1ac8b8[] = {0x46fffe00};
const u32 var7f1ac8bc[] = {0x3c23d70a};
const u32 var7f1ac8c0[] = {0x3fd16873};
const u32 var7f1ac8c4[] = {0x3c23d70a};
const u32 var7f1ac8c8[] = {0x411fffff};
const u32 var7f1ac8cc[] = {0x3f088888};
const u32 var7f1ac8d0[] = {0x40c907a9};
const u32 var7f1ac8d4[] = {0x3d0bd8cf};
const u32 var7f1ac8d8[] = {0x40c907a9};
const u32 var7f1ac8dc[] = {0x3d0bd8cf};
const u32 var7f1ac8e0[] = {0x40c907a9};
const u32 var7f1ac8e4[] = {0x3d0bd8cf};
const u32 var7f1ac8e8[] = {0x3f088888};
const u32 var7f1ac8ec[] = {0x40c907a9};
const u32 var7f1ac8f0[] = {0x40c907a9};
const u32 var7f1ac8f4[] = {0x3c3d3463};
const u32 var7f1ac8f8[] = {0x40c907a9};
const u32 var7f1ac8fc[] = {0x3c3d3463};
const u32 var7f1ac900[] = {0x40c907a9};
const u32 var7f1ac904[] = {0x40c907a9};
const u32 var7f1ac908[] = {0x3bda10fd};
const u32 var7f1ac90c[] = {0x40c907a9};
const u32 var7f1ac910[] = {0x3bda10fd};
const u32 var7f1ac914[] = {0x3e99999a};
const u32 var7f1ac918[] = {0x3e8e38e4};
const u32 var7f1ac91c[] = {0x40c907a9};
const u32 var7f1ac920[] = {0x3fd33333};
const u32 var7f1ac924[] = {0x33333333};
const u32 var7f1ac928[] = {0x3fc33333};
const u32 var7f1ac92c[] = {0x33333333};
const u32 var7f1ac930[] = {0x3dccccce};
const u32 var7f1ac934[] = {0x40c907a9};
const u32 var7f1ac938[] = {0x411fffff};
const u32 var7f1ac93c[] = {0x7f0a550c};
const u32 var7f1ac940[] = {0x7f0a550c};
const u32 var7f1ac944[] = {0x7f0a550c};
const u32 var7f1ac948[] = {0x7f0a550c};
const u32 var7f1ac94c[] = {0x7f0a550c};
const u32 var7f1ac950[] = {0x7f0a550c};
const u32 var7f1ac954[] = {0x7f0a550c};
const u32 var7f1ac958[] = {0x7f0a550c};
const u32 var7f1ac95c[] = {0x7f0a550c};
const u32 var7f1ac960[] = {0x7f0a550c};
const u32 var7f1ac964[] = {0x7f0a550c};
const u32 var7f1ac968[] = {0x7f0a550c};
const u32 var7f1ac96c[] = {0x7f0a550c};
const u32 var7f1ac970[] = {0x7f0a550c};
const u32 var7f1ac974[] = {0x7f0a550c};
const u32 var7f1ac978[] = {0x7f0a550c};
const u32 var7f1ac97c[] = {0x7f0a550c};
const u32 var7f1ac980[] = {0x7f0a5540};
const u32 var7f1ac984[] = {0x7f0a550c};
const u32 var7f1ac988[] = {0x7f0a550c};
const u32 var7f1ac98c[] = {0x7f0a550c};
const u32 var7f1ac990[] = {0x7f0a5540};
const u32 var7f1ac994[] = {0x7f0a5540};
const u32 var7f1ac998[] = {0x7f0a5540};
const u32 var7f1ac99c[] = {0x7f0a5540};
const u32 var7f1ac9a0[] = {0x7f0a5540};
const u32 var7f1ac9a4[] = {0x7f0a550c};
const u32 var7f1ac9a8[] = {0x7f0a5528};
const u32 var7f1ac9ac[] = {0x7f0a5540};
const u32 var7f1ac9b0[] = {0x7f0a5540};
const u32 var7f1ac9b4[] = {0x7f0a5540};
const u32 var7f1ac9b8[] = {0x7f0a5540};
const u32 var7f1ac9bc[] = {0x7f0a5540};
const u32 var7f1ac9c0[] = {0x7f0a5540};
const u32 var7f1ac9c4[] = {0x7f0a550c};
const u32 var7f1ac9c8[] = {0x7f0a550c};
const u32 var7f1ac9cc[] = {0x7f0a550c};
const u32 var7f1ac9d0[] = {0x7f0a550c};
const u32 var7f1ac9d4[] = {0x7f0a550c};
const u32 var7f1ac9d8[] = {0x7f0a550c};
const u32 var7f1ac9dc[] = {0x7f0a550c};
const u32 var7f1ac9e0[] = {0x7f0a550c};
const u32 var7f1ac9e4[] = {0x40490fdb};
const u32 var7f1ac9e8[] = {0x3dccccce};
const u32 var7f1ac9ec[] = {0x7f0a61f4};
const u32 var7f1ac9f0[] = {0x7f0a6254};
const u32 var7f1ac9f4[] = {0x7f0a6254};
const u32 var7f1ac9f8[] = {0x7f0a6254};
const u32 var7f1ac9fc[] = {0x7f0a6254};
const u32 var7f1aca00[] = {0x7f0a6254};
const u32 var7f1aca04[] = {0x7f0a61fc};
const u32 var7f1aca08[] = {0x7f0a6254};
const u32 var7f1aca0c[] = {0x7f0a6254};
const u32 var7f1aca10[] = {0x7f0a6254};
const u32 var7f1aca14[] = {0x7f0a6210};
const u32 var7f1aca18[] = {0x7f0a6210};
const u32 var7f1aca1c[] = {0x7f0a6210};
const u32 var7f1aca20[] = {0x7f0a6210};
const u32 var7f1aca24[] = {0x7f0a6210};
const u32 var7f1aca28[] = {0x7f0a6254};
const u32 var7f1aca2c[] = {0x7f0a6254};
const u32 var7f1aca30[] = {0x7f0a6254};
const u32 var7f1aca34[] = {0x7f0a6254};
const u32 var7f1aca38[] = {0x7f0a6254};
const u32 var7f1aca3c[] = {0x7f0a6254};
const u32 var7f1aca40[] = {0x7f0a6254};
const u32 var7f1aca44[] = {0x7f0a6254};
const u32 var7f1aca48[] = {0x7f0a6254};
const u32 var7f1aca4c[] = {0x7f0a6254};
const u32 var7f1aca50[] = {0x7f0a6254};
const u32 var7f1aca54[] = {0x7f0a6254};
const u32 var7f1aca58[] = {0x7f0a6254};
const u32 var7f1aca5c[] = {0x7f0a6254};
const u32 var7f1aca60[] = {0x7f0a6254};
const u32 var7f1aca64[] = {0x7f0a6254};
const u32 var7f1aca68[] = {0x7f0a6254};
const u32 var7f1aca6c[] = {0x7f0a6254};
const u32 var7f1aca70[] = {0x7f0a6210};
const u32 var7f1aca74[] = {0x40490fdb};
const u32 var7f1aca78[] = {0x3dcccccd};
const u32 var7f1aca7c[] = {0x3d4ccccd};
const u32 var7f1aca80[] = {0x3ba3d70a};
const u32 var7f1aca84[] = {0x3cf5c28f};
const u32 var7f1aca88[] = {0x3ecccccd};
const u32 var7f1aca8c[] = {0x3faaaaab};
const u32 var7f1aca90[] = {0x3f3ebebf};
const u32 var7f1aca94[] = {0x453b8000};
const u32 var7f1aca98[] = {0x453b8000};
const u32 var7f1aca9c[] = {0x453b8000};
const u32 var7f1acaa0[] = {0x453b8000};
const u32 var7f1acaa4[] = {0x7f0a8a60};
const u32 var7f1acaa8[] = {0x7f0a8b50};
const u32 var7f1acaac[] = {0x7f0a8b50};
const u32 var7f1acab0[] = {0x7f0a8b50};
const u32 var7f1acab4[] = {0x7f0a8a60};
const u32 var7f1acab8[] = {0x7f0a8b50};
const u32 var7f1acabc[] = {0x7f0a8b50};
const u32 var7f1acac0[] = {0x7f0a8a0c};
const u32 var7f1acac4[] = {0x7f0a8a0c};
const u32 var7f1acac8[] = {0x7f0a8a0c};
const u32 var7f1acacc[] = {0x7f0a8a60};
const u32 var7f1acad0[] = {0x7f0a8a60};
const u32 var7f1acad4[] = {0x7f0a8b50};
const u32 var7f1acad8[] = {0x7f0a8b50};
const u32 var7f1acadc[] = {0x7f0a8b50};
const u32 var7f1acae0[] = {0x7f0a89a0};
const u32 var7f1acae4[] = {0x7f0a8a60};
const u32 var7f1acae8[] = {0x7f0a8b50};
const u32 var7f1acaec[] = {0x7f0a8b50};
const u32 var7f1acaf0[] = {0x7f0a8b50};
const u32 var7f1acaf4[] = {0x7f0a8b50};
const u32 var7f1acaf8[] = {0x7f0a8b50};
const u32 var7f1acafc[] = {0x7f0a8b50};
const u32 var7f1acb00[] = {0x7f0a8b50};
const u32 var7f1acb04[] = {0x7f0a8b50};
const u32 var7f1acb08[] = {0x7f0a8b50};
const u32 var7f1acb0c[] = {0x7f0a8a60};
const u32 var7f1acb10[] = {0x7f0a8b50};
const u32 var7f1acb14[] = {0x7f0a8a0c};
const u32 var7f1acb18[] = {0x7f0a8e6c};
const u32 var7f1acb1c[] = {0x7f0a8ee8};
const u32 var7f1acb20[] = {0x7f0a8ee8};
const u32 var7f1acb24[] = {0x7f0a8ee8};
const u32 var7f1acb28[] = {0x7f0a8e6c};
const u32 var7f1acb2c[] = {0x7f0a8e6c};
const u32 var7f1acb30[] = {0x7f0a8ee8};
const u32 var7f1acb34[] = {0x7f0a8ee8};
const u32 var7f1acb38[] = {0x7f0a8ee8};
const u32 var7f1acb3c[] = {0x7f0a8e6c};
const u32 var7f1acb40[] = {0x7f0a8ee8};
const u32 var7f1acb44[] = {0x7f0a8ee8};
const u32 var7f1acb48[] = {0x7f0a8ee8};
const u32 var7f1acb4c[] = {0x7f0a8ee8};
const u32 var7f1acb50[] = {0x7f0a8ee8};
const u32 var7f1acb54[] = {0x7f0a8ee8};
const u32 var7f1acb58[] = {0x7f0a8ee8};
const u32 var7f1acb5c[] = {0x7f0a8ee8};
const u32 var7f1acb60[] = {0x7f0a8ee8};
const u32 var7f1acb64[] = {0x7f0a8ee8};
const u32 var7f1acb68[] = {0x7f0a8ee8};
const u32 var7f1acb6c[] = {0x7f0a8ee8};
const u32 var7f1acb70[] = {0x7f0a8ee8};
const u32 var7f1acb74[] = {0x7f0a8e6c};
const u32 var7f1acb78[] = {0x7f0a8ee8};
const u32 var7f1acb7c[] = {0x7f0a8ee8};
const u32 var7f1acb80[] = {0x7f0a8ee8};
const u32 var7f1acb84[] = {0x7f0a8e6c};
const u32 var7f1acb88[] = {0x7f0a8ee8};
const u32 var7f1acb8c[] = {0x7f0a8ee8};
const u32 var7f1acb90[] = {0x7f0a8ee8};
const u32 var7f1acb94[] = {0x7f0a8ee8};
const u32 var7f1acb98[] = {0x7f0a8ee8};
const u32 var7f1acb9c[] = {0x7f0a8ee8};
const u32 var7f1acba0[] = {0x7f0a8ee8};
const u32 var7f1acba4[] = {0x7f0a8e6c};
const u32 var7f1acba8[] = {0x7f0a8e6c};
const u32 var7f1acbac[] = {0x7f0a8e6c};
const u32 var7f1acbb0[] = {0xc7c35000};
const u32 var7f1acbb4[] = {0x47c35000};
const u32 var7f1acbb8[] = {0x7f0a9934};
const u32 var7f1acbbc[] = {0x7f0a9974};
const u32 var7f1acbc0[] = {0x7f0a9950};
const u32 var7f1acbc4[] = {0x7f0a9974};
const u32 var7f1acbc8[] = {0x7f0a9974};
const u32 var7f1acbcc[] = {0x7f0a9974};
const u32 var7f1acbd0[] = {0x7f0a9974};
const u32 var7f1acbd4[] = {0x7f0a9974};
const u32 var7f1acbd8[] = {0x7f0a9974};
const u32 var7f1acbdc[] = {0x7f0a9974};
const u32 var7f1acbe0[] = {0x7f0a996c};
const u32 var7f1acbe4[] = {0x7f0a996c};
const u32 var7f1acbe8[] = {0x7f0a996c};
const u32 var7f1acbec[] = {0x7f0a996c};
const u32 var7f1acbf0[] = {0x7f0a996c};
const u32 var7f1acbf4[] = {0x7f0a996c};
const u32 var7f1acbf8[] = {0x7f0a996c};
const u32 var7f1acbfc[] = {0x7f0a996c};
const u32 var7f1acc00[] = {0x7f0a996c};
const u32 var7f1acc04[] = {0x7f0a996c};
const u32 var7f1acc08[] = {0x7f0a996c};
const u32 var7f1acc0c[] = {0x00000000};

GLOBAL_ASM(
glabel func0f097a50
/*  f097a50:	3c013f80 */ 	lui	$at,0x3f80
/*  f097a54:	44819000 */ 	mtc1	$at,$f18
/*  f097a58:	44808000 */ 	mtc1	$zero,$f16
/*  f097a5c:	46009386 */ 	mov.s	$f14,$f18
/*  f097a60:	46109032 */ 	c.eq.s	$f18,$f16
/*  f097a64:	46008006 */ 	mov.s	$f0,$f16
/*  f097a68:	46008086 */ 	mov.s	$f2,$f16
/*  f097a6c:	45010009 */ 	bc1t	.L0f097a94
/*  f097a70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097a74:	46120000 */ 	add.s	$f0,$f0,$f18
.L0f097a78:
/*  f097a78:	460e1080 */ 	add.s	$f2,$f2,$f14
/*  f097a7c:	46006103 */ 	div.s	$f4,$f12,$f0
/*  f097a80:	46047382 */ 	mul.s	$f14,$f14,$f4
/*  f097a84:	46107032 */ 	c.eq.s	$f14,$f16
/*  f097a88:	00000000 */ 	sll	$zero,$zero,0x0
/*  f097a8c:	4502fffa */ 	bc1fl	.L0f097a78
/*  f097a90:	46120000 */ 	add.s	$f0,$f0,$f18
.L0f097a94:
/*  f097a94:	03e00008 */ 	jr	$ra
/*  f097a98:	46001006 */ 	mov.s	$f0,$f2
/*  f097a9c:	00000000 */ 	sll	$zero,$zero,0x0
);
