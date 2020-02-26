#include <ultra64.h>
#include "constants.h"
#include "game/data/data_000000.h"
#include "game/data/data_0083d0.h"
#include "game/data/data_0160b0.h"
#include "game/data/data_020df0.h"
#include "game/game_096b20.h"
#include "game/game_0c79f0.h"
#include "game/game_113220.h"
#include "gvars/gvars.h"
#include "library/library_12dc0.h"
#include "library/library_159b0.h"
#include "library/library_1a500.h"
#include "library/library_233c0.h"
#include "types.h"

const u32 var7f1b3a20[] = {0x3ca3d70a};
const u32 var7f1b3a24[] = {0x3ca3d70a};
const u32 var7f1b3a28[] = {0x3c23d70a};
const u32 var7f1b3a2c[] = {0xbc23d70a};
const u32 var7f1b3a30[] = {0xbc23d70a};
const u32 var7f1b3a34[] = {0x3c23d70a};
const u32 var7f1b3a38[] = {0x3c9374c0};
const u32 var7f1b3a3c[] = {0x3c9374c0};
const u32 var7f1b3a40[] = {0x3f7b645a};
const u32 var7f1b3a44[] = {0x3f333333};
const u32 var7f1b3a48[] = {0x3dcccccd};
const u32 var7f1b3a4c[] = {0x3f19999a};
const u32 var7f1b3a50[] = {0x3f199999};
const u32 var7f1b3a54[] = {0x3ecccccd};
const u32 var7f1b3a58[] = {0x3ecccccd};
const u32 var7f1b3a5c[] = {0x3f666666};
const u32 var7f1b3a60[] = {0x3f7b645a};
const u32 var7f1b3a64[] = {0x3f7f5b81};
const u32 var7f1b3a68[] = {0x3f75c28f};
const u32 var7f1b3a6c[] = {0x3f7f5b81};
const u32 var7f1b3a70[] = {0x3cccccce};
const u32 var7f1b3a74[] = {0x3c088889};
const u32 var7f1b3a78[] = {0x3c4cccce};
const u32 var7f1b3a7c[] = {0x3b888889};

GLOBAL_ASM(
glabel func0f113220
/*  f113220:	3c0e800a */ 	lui	$t6,0x800a
/*  f113224:	8dcea244 */ 	lw	$t6,-0x5dbc($t6)
/*  f113228:	8dc3047c */ 	lw	$v1,0x47c($t6)
/*  f11322c:	80620008 */ 	lb	$v0,0x8($v1)
/*  f113230:	2c4f0001 */ 	sltiu	$t7,$v0,0x1
/*  f113234:	03e00008 */ 	jr	$ra
/*  f113238:	a06f0008 */ 	sb	$t7,0x8($v1)
);

GLOBAL_ASM(
glabel func0f11323c
/*  f11323c:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f113240:	afbf002c */ 	sw	$ra,0x2c($sp)
/*  f113244:	afb20028 */ 	sw	$s2,0x28($sp)
/*  f113248:	afb10024 */ 	sw	$s1,0x24($sp)
/*  f11324c:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f113250:	0c004b70 */ 	jal	random
/*  f113254:	f7b40018 */ 	sdc1	$f20,0x18($sp)
/*  f113258:	44822000 */ 	mtc1	$v0,$f4
/*  f11325c:	3c11800a */ 	lui	$s1,%hi(g_Vars)
/*  f113260:	3c012f80 */ 	lui	$at,0x2f80
/*  f113264:	4481a000 */ 	mtc1	$at,$f20
/*  f113268:	26319fc0 */ 	addiu	$s1,$s1,%lo(g_Vars)
/*  f11326c:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f113270:	2412000c */ 	addiu	$s2,$zero,0xc
/*  f113274:	04410005 */ 	bgez	$v0,.L0f11328c
/*  f113278:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f11327c:	3c014f80 */ 	lui	$at,0x4f80
/*  f113280:	44814000 */ 	mtc1	$at,$f8
/*  f113284:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113288:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f11328c:
/*  f11328c:	46143282 */ 	mul.s	$f10,$f6,$f20
/*  f113290:	8e0e0458 */ 	lw	$t6,0x458($s0)
/*  f113294:	3c013f00 */ 	lui	$at,0x3f00
/*  f113298:	44818000 */ 	mtc1	$at,$f16
/*  f11329c:	01d20019 */ 	multu	$t6,$s2
/*  f1132a0:	3c017f1b */ 	lui	$at,%hi(var7f1b3a20)
/*  f1132a4:	c4243a20 */ 	lwc1	$f4,%lo(var7f1b3a20)($at)
/*  f1132a8:	46105481 */ 	sub.s	$f18,$f10,$f16
/*  f1132ac:	3c013f80 */ 	lui	$at,0x3f80
/*  f1132b0:	44813000 */ 	mtc1	$at,$f6
/*  f1132b4:	46049202 */ 	mul.s	$f8,$f18,$f4
/*  f1132b8:	00007812 */ 	mflo	$t7
/*  f1132bc:	020fc021 */ 	addu	$t8,$s0,$t7
/*  f1132c0:	e7080428 */ 	swc1	$f8,0x428($t8)
/*  f1132c4:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f1132c8:	8e190458 */ 	lw	$t9,0x458($s0)
/*  f1132cc:	03320019 */ 	multu	$t9,$s2
/*  f1132d0:	00004012 */ 	mflo	$t0
/*  f1132d4:	02084821 */ 	addu	$t1,$s0,$t0
/*  f1132d8:	0c004b70 */ 	jal	random
/*  f1132dc:	e5260430 */ 	swc1	$f6,0x430($t1)
/*  f1132e0:	44825000 */ 	mtc1	$v0,$f10
/*  f1132e4:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f1132e8:	04410005 */ 	bgez	$v0,.L0f113300
/*  f1132ec:	46805420 */ 	cvt.s.w	$f16,$f10
/*  f1132f0:	3c014f80 */ 	lui	$at,0x4f80
/*  f1132f4:	44819000 */ 	mtc1	$at,$f18
/*  f1132f8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1132fc:	46128400 */ 	add.s	$f16,$f16,$f18
.L0f113300:
/*  f113300:	46148102 */ 	mul.s	$f4,$f16,$f20
/*  f113304:	8e0a0458 */ 	lw	$t2,0x458($s0)
/*  f113308:	3c013f00 */ 	lui	$at,0x3f00
/*  f11330c:	44814000 */ 	mtc1	$at,$f8
/*  f113310:	01520019 */ 	multu	$t2,$s2
/*  f113314:	3c017f1b */ 	lui	$at,%hi(var7f1b3a24)
/*  f113318:	c42a3a24 */ 	lwc1	$f10,%lo(var7f1b3a24)($at)
/*  f11331c:	46082181 */ 	sub.s	$f6,$f4,$f8
/*  f113320:	3c013f80 */ 	lui	$at,0x3f80
/*  f113324:	44818000 */ 	mtc1	$at,$f16
/*  f113328:	460a3482 */ 	mul.s	$f18,$f6,$f10
/*  f11332c:	00005812 */ 	mflo	$t3
/*  f113330:	020b6021 */ 	addu	$t4,$s0,$t3
/*  f113334:	e5920440 */ 	swc1	$f18,0x440($t4)
/*  f113338:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f11333c:	8e0d0458 */ 	lw	$t5,0x458($s0)
/*  f113340:	01b20019 */ 	multu	$t5,$s2
/*  f113344:	00007012 */ 	mflo	$t6
/*  f113348:	020e7821 */ 	addu	$t7,$s0,$t6
/*  f11334c:	e5f00444 */ 	swc1	$f16,0x444($t7)
/*  f113350:	8e380284 */ 	lw	$t8,0x284($s1)
/*  f113354:	8f190458 */ 	lw	$t9,0x458($t8)
/*  f113358:	13200027 */ 	beqz	$t9,.L0f1133f8
/*  f11335c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113360:	0c004b70 */ 	jal	random
/*  f113364:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113368:	44822000 */ 	mtc1	$v0,$f4
/*  f11336c:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f113370:	04410005 */ 	bgez	$v0,.L0f113388
/*  f113374:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f113378:	3c014f80 */ 	lui	$at,0x4f80
/*  f11337c:	44813000 */ 	mtc1	$at,$f6
/*  f113380:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113384:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f113388:
/*  f113388:	8e080458 */ 	lw	$t0,0x458($s0)
/*  f11338c:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f113390:	3c017f1b */ 	lui	$at,%hi(var7f1b3a28)
/*  f113394:	01120019 */ 	multu	$t0,$s2
/*  f113398:	c4323a28 */ 	lwc1	$f18,%lo(var7f1b3a28)($at)
/*  f11339c:	46125402 */ 	mul.s	$f16,$f10,$f18
/*  f1133a0:	00004812 */ 	mflo	$t1
/*  f1133a4:	02095021 */ 	addu	$t2,$s0,$t1
/*  f1133a8:	0c004b70 */ 	jal	random
/*  f1133ac:	e550042c */ 	swc1	$f16,0x42c($t2)
/*  f1133b0:	44822000 */ 	mtc1	$v0,$f4
/*  f1133b4:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f1133b8:	04410005 */ 	bgez	$v0,.L0f1133d0
/*  f1133bc:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f1133c0:	3c014f80 */ 	lui	$at,0x4f80
/*  f1133c4:	44814000 */ 	mtc1	$at,$f8
/*  f1133c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1133cc:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f1133d0:
/*  f1133d0:	8e0b0458 */ 	lw	$t3,0x458($s0)
/*  f1133d4:	46143282 */ 	mul.s	$f10,$f6,$f20
/*  f1133d8:	3c017f1b */ 	lui	$at,%hi(var7f1b3a2c)
/*  f1133dc:	01720019 */ 	multu	$t3,$s2
/*  f1133e0:	c4323a2c */ 	lwc1	$f18,%lo(var7f1b3a2c)($at)
/*  f1133e4:	46125402 */ 	mul.s	$f16,$f10,$f18
/*  f1133e8:	00006012 */ 	mflo	$t4
/*  f1133ec:	020c6821 */ 	addu	$t5,$s0,$t4
/*  f1133f0:	10000026 */ 	beqz	$zero,.L0f11348c
/*  f1133f4:	e5b00448 */ 	swc1	$f16,0x448($t5)
.L0f1133f8:
/*  f1133f8:	0c004b70 */ 	jal	random
/*  f1133fc:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113400:	44822000 */ 	mtc1	$v0,$f4
/*  f113404:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f113408:	04410005 */ 	bgez	$v0,.L0f113420
/*  f11340c:	46802220 */ 	cvt.s.w	$f8,$f4
/*  f113410:	3c014f80 */ 	lui	$at,0x4f80
/*  f113414:	44813000 */ 	mtc1	$at,$f6
/*  f113418:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11341c:	46064200 */ 	add.s	$f8,$f8,$f6
.L0f113420:
/*  f113420:	8e0e0458 */ 	lw	$t6,0x458($s0)
/*  f113424:	46144282 */ 	mul.s	$f10,$f8,$f20
/*  f113428:	3c017f1b */ 	lui	$at,%hi(var7f1b3a30)
/*  f11342c:	01d20019 */ 	multu	$t6,$s2
/*  f113430:	c4323a30 */ 	lwc1	$f18,%lo(var7f1b3a30)($at)
/*  f113434:	46125402 */ 	mul.s	$f16,$f10,$f18
/*  f113438:	00007812 */ 	mflo	$t7
/*  f11343c:	020fc021 */ 	addu	$t8,$s0,$t7
/*  f113440:	0c004b70 */ 	jal	random
/*  f113444:	e710042c */ 	swc1	$f16,0x42c($t8)
/*  f113448:	44822000 */ 	mtc1	$v0,$f4
/*  f11344c:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f113450:	04410005 */ 	bgez	$v0,.L0f113468
/*  f113454:	468021a0 */ 	cvt.s.w	$f6,$f4
/*  f113458:	3c014f80 */ 	lui	$at,0x4f80
/*  f11345c:	44814000 */ 	mtc1	$at,$f8
/*  f113460:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113464:	46083180 */ 	add.s	$f6,$f6,$f8
.L0f113468:
/*  f113468:	8e190458 */ 	lw	$t9,0x458($s0)
/*  f11346c:	46143282 */ 	mul.s	$f10,$f6,$f20
/*  f113470:	3c017f1b */ 	lui	$at,%hi(var7f1b3a34)
/*  f113474:	03320019 */ 	multu	$t9,$s2
/*  f113478:	c4323a34 */ 	lwc1	$f18,%lo(var7f1b3a34)($at)
/*  f11347c:	46125402 */ 	mul.s	$f16,$f10,$f18
/*  f113480:	00004012 */ 	mflo	$t0
/*  f113484:	02084821 */ 	addu	$t1,$s0,$t0
/*  f113488:	e5300448 */ 	swc1	$f16,0x448($t1)
.L0f11348c:
/*  f11348c:	8e300284 */ 	lw	$s0,0x284($s1)
/*  f113490:	240b0001 */ 	addiu	$t3,$zero,0x1
/*  f113494:	8e0a0458 */ 	lw	$t2,0x458($s0)
/*  f113498:	016a6023 */ 	subu	$t4,$t3,$t2
/*  f11349c:	ae0c0458 */ 	sw	$t4,0x458($s0)
/*  f1134a0:	8fbf002c */ 	lw	$ra,0x2c($sp)
/*  f1134a4:	8fb20028 */ 	lw	$s2,0x28($sp)
/*  f1134a8:	8fb10024 */ 	lw	$s1,0x24($sp)
/*  f1134ac:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f1134b0:	d7b40018 */ 	ldc1	$f20,0x18($sp)
/*  f1134b4:	03e00008 */ 	jr	$ra
/*  f1134b8:	27bd0030 */ 	addiu	$sp,$sp,0x30
);

GLOBAL_ASM(
glabel func0f1134bc
/*  f1134bc:	3c05800a */ 	lui	$a1,%hi(g_Vars)
/*  f1134c0:	24a59fc0 */ 	addiu	$a1,$a1,%lo(g_Vars)
/*  f1134c4:	8ca20284 */ 	lw	$v0,0x284($a1)
/*  f1134c8:	8c4e03a0 */ 	lw	$t6,0x3a0($v0)
/*  f1134cc:	51c0000e */ 	beqzl	$t6,.L0f113508
/*  f1134d0:	8ca80034 */ 	lw	$t0,0x34($a1)
/*  f1134d4:	44800000 */ 	mtc1	$zero,$f0
/*  f1134d8:	3c017f1b */ 	lui	$at,%hi(var7f1b3a38)
/*  f1134dc:	c4223a38 */ 	lwc1	$f2,%lo(var7f1b3a38)($at)
/*  f1134e0:	e44003e4 */ 	swc1	$f0,0x3e4($v0)
/*  f1134e4:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*  f1134e8:	8caf0284 */ 	lw	$t7,0x284($a1)
/*  f1134ec:	46022183 */ 	div.s	$f6,$f4,$f2
/*  f1134f0:	e5e603e8 */ 	swc1	$f6,0x3e8($t7)
/*  f1134f4:	8cb80284 */ 	lw	$t8,0x284($a1)
/*  f1134f8:	e70003ec */ 	swc1	$f0,0x3ec($t8)
/*  f1134fc:	8cb90284 */ 	lw	$t9,0x284($a1)
/*  f113500:	af2003a0 */ 	sw	$zero,0x3a0($t9)
/*  f113504:	8ca80034 */ 	lw	$t0,0x34($a1)
.L0f113508:
/*  f113508:	3c017f1b */ 	lui	$at,%hi(var7f1b3a3c)
/*  f11350c:	c4223a3c */ 	lwc1	$f2,%lo(var7f1b3a3c)($at)
/*  f113510:	1900001a */ 	blez	$t0,.L0f11357c
/*  f113514:	00001825 */ 	or	$v1,$zero,$zero
/*  f113518:	3c017f1b */ 	lui	$at,%hi(var7f1b3a40)
/*  f11351c:	c4203a40 */ 	lwc1	$f0,%lo(var7f1b3a40)($at)
/*  f113520:	8ca20284 */ 	lw	$v0,0x284($a1)
.L0f113524:
/*  f113524:	c4880000 */ 	lwc1	$f8,0x0($a0)
/*  f113528:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f11352c:	c44a03e4 */ 	lwc1	$f10,0x3e4($v0)
/*  f113530:	460a0402 */ 	mul.s	$f16,$f0,$f10
/*  f113534:	46104480 */ 	add.s	$f18,$f8,$f16
/*  f113538:	e45203e4 */ 	swc1	$f18,0x3e4($v0)
/*  f11353c:	8ca20284 */ 	lw	$v0,0x284($a1)
/*  f113540:	c4840004 */ 	lwc1	$f4,0x4($a0)
/*  f113544:	c44603e8 */ 	lwc1	$f6,0x3e8($v0)
/*  f113548:	46060282 */ 	mul.s	$f10,$f0,$f6
/*  f11354c:	460a2200 */ 	add.s	$f8,$f4,$f10
/*  f113550:	e44803e8 */ 	swc1	$f8,0x3e8($v0)
/*  f113554:	8ca20284 */ 	lw	$v0,0x284($a1)
/*  f113558:	c4900008 */ 	lwc1	$f16,0x8($a0)
/*  f11355c:	c45203ec */ 	lwc1	$f18,0x3ec($v0)
/*  f113560:	46120182 */ 	mul.s	$f6,$f0,$f18
/*  f113564:	46068100 */ 	add.s	$f4,$f16,$f6
/*  f113568:	e44403ec */ 	swc1	$f4,0x3ec($v0)
/*  f11356c:	8ca90034 */ 	lw	$t1,0x34($a1)
/*  f113570:	0069082a */ 	slt	$at,$v1,$t1
/*  f113574:	5420ffeb */ 	bnezl	$at,.L0f113524
/*  f113578:	8ca20284 */ 	lw	$v0,0x284($a1)
.L0f11357c:
/*  f11357c:	8ca20284 */ 	lw	$v0,0x284($a1)
/*  f113580:	c44a03e4 */ 	lwc1	$f10,0x3e4($v0)
/*  f113584:	46025202 */ 	mul.s	$f8,$f10,$f2
/*  f113588:	e44803c0 */ 	swc1	$f8,0x3c0($v0)
/*  f11358c:	8ca20284 */ 	lw	$v0,0x284($a1)
/*  f113590:	c45203e8 */ 	lwc1	$f18,0x3e8($v0)
/*  f113594:	46029402 */ 	mul.s	$f16,$f18,$f2
/*  f113598:	e45003c4 */ 	swc1	$f16,0x3c4($v0)
/*  f11359c:	8ca20284 */ 	lw	$v0,0x284($a1)
/*  f1135a0:	c44603ec */ 	lwc1	$f6,0x3ec($v0)
/*  f1135a4:	46023102 */ 	mul.s	$f4,$f6,$f2
/*  f1135a8:	03e00008 */ 	jr	$ra
/*  f1135ac:	e44403c8 */ 	swc1	$f4,0x3c8($v0)
);

GLOBAL_ASM(
glabel func0f1135b0
/*  f1135b0:	3c06800a */ 	lui	$a2,%hi(g_Vars)
/*  f1135b4:	24c69fc0 */ 	addiu	$a2,$a2,%lo(g_Vars)
/*  f1135b8:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f1135bc:	3c013f80 */ 	lui	$at,0x3f80
/*  f1135c0:	8c4e03a4 */ 	lw	$t6,0x3a4($v0)
/*  f1135c4:	51c00028 */ 	beqzl	$t6,.L0f113668
/*  f1135c8:	8cd80034 */ 	lw	$t8,0x34($a2)
/*  f1135cc:	44810000 */ 	mtc1	$at,$f0
/*  f1135d0:	c44603b0 */ 	lwc1	$f6,0x3b0($v0)
/*  f1135d4:	c4840000 */ 	lwc1	$f4,0x0($a0)
/*  f1135d8:	46060201 */ 	sub.s	$f8,$f0,$f6
/*  f1135dc:	46082283 */ 	div.s	$f10,$f4,$f8
/*  f1135e0:	e44a03f0 */ 	swc1	$f10,0x3f0($v0)
/*  f1135e4:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f1135e8:	c4900004 */ 	lwc1	$f16,0x4($a0)
/*  f1135ec:	c45203b0 */ 	lwc1	$f18,0x3b0($v0)
/*  f1135f0:	46120181 */ 	sub.s	$f6,$f0,$f18
/*  f1135f4:	46068103 */ 	div.s	$f4,$f16,$f6
/*  f1135f8:	e44403f4 */ 	swc1	$f4,0x3f4($v0)
/*  f1135fc:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f113600:	c4880008 */ 	lwc1	$f8,0x8($a0)
/*  f113604:	c44a03b0 */ 	lwc1	$f10,0x3b0($v0)
/*  f113608:	460a0481 */ 	sub.s	$f18,$f0,$f10
/*  f11360c:	46124403 */ 	div.s	$f16,$f8,$f18
/*  f113610:	e45003f8 */ 	swc1	$f16,0x3f8($v0)
/*  f113614:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f113618:	c4a60000 */ 	lwc1	$f6,0x0($a1)
/*  f11361c:	c44403b0 */ 	lwc1	$f4,0x3b0($v0)
/*  f113620:	46040281 */ 	sub.s	$f10,$f0,$f4
/*  f113624:	460a3203 */ 	div.s	$f8,$f6,$f10
/*  f113628:	e44803fc */ 	swc1	$f8,0x3fc($v0)
/*  f11362c:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f113630:	c4b20004 */ 	lwc1	$f18,0x4($a1)
/*  f113634:	c45003b0 */ 	lwc1	$f16,0x3b0($v0)
/*  f113638:	46100101 */ 	sub.s	$f4,$f0,$f16
/*  f11363c:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f113640:	e4460400 */ 	swc1	$f6,0x400($v0)
/*  f113644:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f113648:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f11364c:	c44803b0 */ 	lwc1	$f8,0x3b0($v0)
/*  f113650:	46080401 */ 	sub.s	$f16,$f0,$f8
/*  f113654:	46105483 */ 	div.s	$f18,$f10,$f16
/*  f113658:	e4520404 */ 	swc1	$f18,0x404($v0)
/*  f11365c:	8ccf0284 */ 	lw	$t7,0x284($a2)
/*  f113660:	ade003a4 */ 	sw	$zero,0x3a4($t7)
/*  f113664:	8cd80034 */ 	lw	$t8,0x34($a2)
.L0f113668:
/*  f113668:	3c013f80 */ 	lui	$at,0x3f80
/*  f11366c:	44810000 */ 	mtc1	$at,$f0
/*  f113670:	1b000030 */ 	blez	$t8,.L0f113734
/*  f113674:	00001825 */ 	or	$v1,$zero,$zero
/*  f113678:	8cc20284 */ 	lw	$v0,0x284($a2)
.L0f11367c:
/*  f11367c:	c48a0000 */ 	lwc1	$f10,0x0($a0)
/*  f113680:	24630001 */ 	addiu	$v1,$v1,0x1
/*  f113684:	c44403b0 */ 	lwc1	$f4,0x3b0($v0)
/*  f113688:	c44603f0 */ 	lwc1	$f6,0x3f0($v0)
/*  f11368c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f113690:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f113694:	e45003f0 */ 	swc1	$f16,0x3f0($v0)
/*  f113698:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f11369c:	c48a0004 */ 	lwc1	$f10,0x4($a0)
/*  f1136a0:	c45203b0 */ 	lwc1	$f18,0x3b0($v0)
/*  f1136a4:	c44403f4 */ 	lwc1	$f4,0x3f4($v0)
/*  f1136a8:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f1136ac:	46065200 */ 	add.s	$f8,$f10,$f6
/*  f1136b0:	e44803f4 */ 	swc1	$f8,0x3f4($v0)
/*  f1136b4:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f1136b8:	c48a0008 */ 	lwc1	$f10,0x8($a0)
/*  f1136bc:	c45003b0 */ 	lwc1	$f16,0x3b0($v0)
/*  f1136c0:	c45203f8 */ 	lwc1	$f18,0x3f8($v0)
/*  f1136c4:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f1136c8:	46045180 */ 	add.s	$f6,$f10,$f4
/*  f1136cc:	e44603f8 */ 	swc1	$f6,0x3f8($v0)
/*  f1136d0:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f1136d4:	c4aa0000 */ 	lwc1	$f10,0x0($a1)
/*  f1136d8:	c44803b0 */ 	lwc1	$f8,0x3b0($v0)
/*  f1136dc:	c45003fc */ 	lwc1	$f16,0x3fc($v0)
/*  f1136e0:	46104482 */ 	mul.s	$f18,$f8,$f16
/*  f1136e4:	46125100 */ 	add.s	$f4,$f10,$f18
/*  f1136e8:	e44403fc */ 	swc1	$f4,0x3fc($v0)
/*  f1136ec:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f1136f0:	c4aa0004 */ 	lwc1	$f10,0x4($a1)
/*  f1136f4:	c44603b0 */ 	lwc1	$f6,0x3b0($v0)
/*  f1136f8:	c4480400 */ 	lwc1	$f8,0x400($v0)
/*  f1136fc:	46083402 */ 	mul.s	$f16,$f6,$f8
/*  f113700:	46105480 */ 	add.s	$f18,$f10,$f16
/*  f113704:	e4520400 */ 	swc1	$f18,0x400($v0)
/*  f113708:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f11370c:	c4aa0008 */ 	lwc1	$f10,0x8($a1)
/*  f113710:	c44403b0 */ 	lwc1	$f4,0x3b0($v0)
/*  f113714:	c4460404 */ 	lwc1	$f6,0x404($v0)
/*  f113718:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f11371c:	46085400 */ 	add.s	$f16,$f10,$f8
/*  f113720:	e4500404 */ 	swc1	$f16,0x404($v0)
/*  f113724:	8cd90034 */ 	lw	$t9,0x34($a2)
/*  f113728:	0079082a */ 	slt	$at,$v1,$t9
/*  f11372c:	5420ffd3 */ 	bnezl	$at,.L0f11367c
/*  f113730:	8cc20284 */ 	lw	$v0,0x284($a2)
.L0f113734:
/*  f113734:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f113738:	c44403b0 */ 	lwc1	$f4,0x3b0($v0)
/*  f11373c:	c45203f0 */ 	lwc1	$f18,0x3f0($v0)
/*  f113740:	46040181 */ 	sub.s	$f6,$f0,$f4
/*  f113744:	46069282 */ 	mul.s	$f10,$f18,$f6
/*  f113748:	e44a03cc */ 	swc1	$f10,0x3cc($v0)
/*  f11374c:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f113750:	c45003b0 */ 	lwc1	$f16,0x3b0($v0)
/*  f113754:	c44803f4 */ 	lwc1	$f8,0x3f4($v0)
/*  f113758:	46100101 */ 	sub.s	$f4,$f0,$f16
/*  f11375c:	46044482 */ 	mul.s	$f18,$f8,$f4
/*  f113760:	e45203d0 */ 	swc1	$f18,0x3d0($v0)
/*  f113764:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f113768:	c44a03b0 */ 	lwc1	$f10,0x3b0($v0)
/*  f11376c:	c44603f8 */ 	lwc1	$f6,0x3f8($v0)
/*  f113770:	460a0401 */ 	sub.s	$f16,$f0,$f10
/*  f113774:	46103202 */ 	mul.s	$f8,$f6,$f16
/*  f113778:	e44803d4 */ 	swc1	$f8,0x3d4($v0)
/*  f11377c:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f113780:	c45203b0 */ 	lwc1	$f18,0x3b0($v0)
/*  f113784:	c44403fc */ 	lwc1	$f4,0x3fc($v0)
/*  f113788:	46120281 */ 	sub.s	$f10,$f0,$f18
/*  f11378c:	460a2182 */ 	mul.s	$f6,$f4,$f10
/*  f113790:	e44603d8 */ 	swc1	$f6,0x3d8($v0)
/*  f113794:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f113798:	c44803b0 */ 	lwc1	$f8,0x3b0($v0)
/*  f11379c:	c4500400 */ 	lwc1	$f16,0x400($v0)
/*  f1137a0:	46080481 */ 	sub.s	$f18,$f0,$f8
/*  f1137a4:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f1137a8:	e44403dc */ 	swc1	$f4,0x3dc($v0)
/*  f1137ac:	8cc20284 */ 	lw	$v0,0x284($a2)
/*  f1137b0:	c44603b0 */ 	lwc1	$f6,0x3b0($v0)
/*  f1137b4:	c44a0404 */ 	lwc1	$f10,0x404($v0)
/*  f1137b8:	46060201 */ 	sub.s	$f8,$f0,$f6
/*  f1137bc:	46085402 */ 	mul.s	$f16,$f10,$f8
/*  f1137c0:	03e00008 */ 	jr	$ra
/*  f1137c4:	e45003e0 */ 	swc1	$f16,0x3e0($v0)
);

GLOBAL_ASM(
glabel func0f1137c8
/*  f1137c8:	3c03800a */ 	lui	$v1,%hi(g_Vars)
/*  f1137cc:	24639fc0 */ 	addiu	$v1,$v1,%lo(g_Vars)
/*  f1137d0:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f1137d4:	3c013f80 */ 	lui	$at,0x3f80
/*  f1137d8:	c44003b0 */ 	lwc1	$f0,0x3b0($v0)
/*  f1137dc:	46006032 */ 	c.eq.s	$f12,$f0
/*  f1137e0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1137e4:	4501002d */ 	bc1t	.L0f11389c
/*  f1137e8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1137ec:	44817000 */ 	mtc1	$at,$f14
/*  f1137f0:	c44403f0 */ 	lwc1	$f4,0x3f0($v0)
/*  f1137f4:	46007181 */ 	sub.s	$f6,$f14,$f0
/*  f1137f8:	460c7081 */ 	sub.s	$f2,$f14,$f12
/*  f1137fc:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f113800:	46024283 */ 	div.s	$f10,$f8,$f2
/*  f113804:	e44a03f0 */ 	swc1	$f10,0x3f0($v0)
/*  f113808:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f11380c:	c45203b0 */ 	lwc1	$f18,0x3b0($v0)
/*  f113810:	c45003f4 */ 	lwc1	$f16,0x3f4($v0)
/*  f113814:	46127101 */ 	sub.s	$f4,$f14,$f18
/*  f113818:	46048182 */ 	mul.s	$f6,$f16,$f4
/*  f11381c:	46023203 */ 	div.s	$f8,$f6,$f2
/*  f113820:	e44803f4 */ 	swc1	$f8,0x3f4($v0)
/*  f113824:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f113828:	c45203b0 */ 	lwc1	$f18,0x3b0($v0)
/*  f11382c:	c44a03f8 */ 	lwc1	$f10,0x3f8($v0)
/*  f113830:	46127401 */ 	sub.s	$f16,$f14,$f18
/*  f113834:	46105102 */ 	mul.s	$f4,$f10,$f16
/*  f113838:	46022183 */ 	div.s	$f6,$f4,$f2
/*  f11383c:	e44603f8 */ 	swc1	$f6,0x3f8($v0)
/*  f113840:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f113844:	c45203b0 */ 	lwc1	$f18,0x3b0($v0)
/*  f113848:	c44803fc */ 	lwc1	$f8,0x3fc($v0)
/*  f11384c:	46127281 */ 	sub.s	$f10,$f14,$f18
/*  f113850:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f113854:	46028103 */ 	div.s	$f4,$f16,$f2
/*  f113858:	e44403fc */ 	swc1	$f4,0x3fc($v0)
/*  f11385c:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f113860:	c45203b0 */ 	lwc1	$f18,0x3b0($v0)
/*  f113864:	c4460400 */ 	lwc1	$f6,0x400($v0)
/*  f113868:	46127201 */ 	sub.s	$f8,$f14,$f18
/*  f11386c:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f113870:	46025403 */ 	div.s	$f16,$f10,$f2
/*  f113874:	e4500400 */ 	swc1	$f16,0x400($v0)
/*  f113878:	8c620284 */ 	lw	$v0,0x284($v1)
/*  f11387c:	c45203b0 */ 	lwc1	$f18,0x3b0($v0)
/*  f113880:	c4440404 */ 	lwc1	$f4,0x404($v0)
/*  f113884:	46127181 */ 	sub.s	$f6,$f14,$f18
/*  f113888:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f11388c:	46024283 */ 	div.s	$f10,$f8,$f2
/*  f113890:	e44a0404 */ 	swc1	$f10,0x404($v0)
/*  f113894:	8c6e0284 */ 	lw	$t6,0x284($v1)
/*  f113898:	e5cc03b0 */ 	swc1	$f12,0x3b0($t6)
.L0f11389c:
/*  f11389c:	03e00008 */ 	jr	$ra
/*  f1138a0:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1138a4
/*  f1138a4:	27bdff18 */ 	addiu	$sp,$sp,-232
/*  f1138a8:	3c0f8007 */ 	lui	$t7,%hi(var80075c30)
/*  f1138ac:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1138b0:	afb00018 */ 	sw	$s0,0x18($sp)
/*  f1138b4:	e7ac00e8 */ 	swc1	$f12,0xe8($sp)
/*  f1138b8:	e7ae00ec */ 	swc1	$f14,0xec($sp)
/*  f1138bc:	25ef5c30 */ 	addiu	$t7,$t7,%lo(var80075c30)
/*  f1138c0:	8de10000 */ 	lw	$at,0x0($t7)
/*  f1138c4:	27ae00dc */ 	addiu	$t6,$sp,0xdc
/*  f1138c8:	8de80004 */ 	lw	$t0,0x4($t7)
/*  f1138cc:	adc10000 */ 	sw	$at,0x0($t6)
/*  f1138d0:	8de10008 */ 	lw	$at,0x8($t7)
/*  f1138d4:	3c0a8007 */ 	lui	$t2,%hi(var80075c3c)
/*  f1138d8:	254a5c3c */ 	addiu	$t2,$t2,%lo(var80075c3c)
/*  f1138dc:	adc80004 */ 	sw	$t0,0x4($t6)
/*  f1138e0:	adc10008 */ 	sw	$at,0x8($t6)
/*  f1138e4:	8d410000 */ 	lw	$at,0x0($t2)
/*  f1138e8:	27a900d0 */ 	addiu	$t1,$sp,0xd0
/*  f1138ec:	8d4d0004 */ 	lw	$t5,0x4($t2)
/*  f1138f0:	ad210000 */ 	sw	$at,0x0($t1)
/*  f1138f4:	8d410008 */ 	lw	$at,0x8($t2)
/*  f1138f8:	3c188007 */ 	lui	$t8,%hi(var80075c48)
/*  f1138fc:	27185c48 */ 	addiu	$t8,$t8,%lo(var80075c48)
/*  f113900:	ad2d0004 */ 	sw	$t5,0x4($t1)
/*  f113904:	ad210008 */ 	sw	$at,0x8($t1)
/*  f113908:	8f010000 */ 	lw	$at,0x0($t8)
/*  f11390c:	27b900c4 */ 	addiu	$t9,$sp,0xc4
/*  f113910:	8f080004 */ 	lw	$t0,0x4($t8)
/*  f113914:	af210000 */ 	sw	$at,0x0($t9)
/*  f113918:	8f010008 */ 	lw	$at,0x8($t8)
/*  f11391c:	3c10800a */ 	lui	$s0,%hi(g_Vars)
/*  f113920:	44802000 */ 	mtc1	$zero,$f4
/*  f113924:	26109fc0 */ 	addiu	$s0,$s0,%lo(g_Vars)
/*  f113928:	af280004 */ 	sw	$t0,0x4($t9)
/*  f11392c:	af210008 */ 	sw	$at,0x8($t9)
/*  f113930:	8e0c0284 */ 	lw	$t4,0x284($s0)
/*  f113934:	e7a400c0 */ 	swc1	$f4,0xc0($sp)
/*  f113938:	8d8b047c */ 	lw	$t3,0x47c($t4)
/*  f11393c:	0c008de5 */ 	jal	func00023794
/*  f113940:	85640000 */ 	lh	$a0,0x0($t3)
/*  f113944:	50400088 */ 	beqzl	$v0,.L0f113b68
/*  f113948:	44800000 */ 	mtc1	$zero,$f0
/*  f11394c:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f113950:	0c0074a2 */ 	jal	func0001d288
/*  f113954:	2484045c */ 	addiu	$a0,$a0,0x45c
/*  f113958:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f11395c:	e7a000c0 */ 	swc1	$f0,0xc0($sp)
/*  f113960:	3c0d8007 */ 	lui	$t5,%hi(var80075c54)
/*  f113964:	8c4303ac */ 	lw	$v1,0x3ac($v0)
/*  f113968:	25ad5c54 */ 	addiu	$t5,$t5,%lo(var80075c54)
/*  f11396c:	25ae003c */ 	addiu	$t6,$t5,0x3c
/*  f113970:	14600024 */ 	bnez	$v1,.L0f113a04
/*  f113974:	27aa0080 */ 	addiu	$t2,$sp,0x80
/*  f113978:	3c017f1b */ 	lui	$at,%hi(var7f1b3a44)
/*  f11397c:	c4263a44 */ 	lwc1	$f6,%lo(var7f1b3a44)($at)
/*  f113980:	3c017f1b */ 	lui	$at,%hi(var7f1b3a48)
/*  f113984:	4600303c */ 	c.lt.s	$f6,$f0
/*  f113988:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11398c:	45000005 */ 	bc1f	.L0f1139a4
/*  f113990:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113994:	3c013f80 */ 	lui	$at,0x3f80
/*  f113998:	44814000 */ 	mtc1	$at,$f8
/*  f11399c:	10000015 */ 	beqz	$zero,.L0f1139f4
/*  f1139a0:	e44803b8 */ 	swc1	$f8,0x3b8($v0)
.L0f1139a4:
/*  f1139a4:	c4223a48 */ 	lwc1	$f2,%lo(var7f1b3a48)($at)
/*  f1139a8:	3c017f1b */ 	lui	$at,%hi(var7f1b3a58)
/*  f1139ac:	4600103c */ 	c.lt.s	$f2,$f0
/*  f1139b0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1139b4:	4500000d */ 	bc1f	.L0f1139ec
/*  f1139b8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1139bc:	46020281 */ 	sub.s	$f10,$f0,$f2
/*  f1139c0:	3c017f1b */ 	lui	$at,%hi(var7f1b3a4c)
/*  f1139c4:	c4303a4c */ 	lwc1	$f16,%lo(var7f1b3a4c)($at)
/*  f1139c8:	3c017f1b */ 	lui	$at,%hi(var7f1b3a50)
/*  f1139cc:	c4243a50 */ 	lwc1	$f4,%lo(var7f1b3a50)($at)
/*  f1139d0:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f1139d4:	3c017f1b */ 	lui	$at,%hi(var7f1b3a54)
/*  f1139d8:	c4283a54 */ 	lwc1	$f8,%lo(var7f1b3a54)($at)
/*  f1139dc:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f1139e0:	46083280 */ 	add.s	$f10,$f6,$f8
/*  f1139e4:	10000003 */ 	beqz	$zero,.L0f1139f4
/*  f1139e8:	e44a03b8 */ 	swc1	$f10,0x3b8($v0)
.L0f1139ec:
/*  f1139ec:	c4303a58 */ 	lwc1	$f16,%lo(var7f1b3a58)($at)
/*  f1139f0:	e45003b8 */ 	swc1	$f16,0x3b8($v0)
.L0f1139f4:
/*  f1139f4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f1139f8:	c45203b8 */ 	lwc1	$f18,0x3b8($v0)
/*  f1139fc:	10000012 */ 	beqz	$zero,.L0f113a48
/*  f113a00:	e45203bc */ 	swc1	$f18,0x3bc($v0)
.L0f113a04:
/*  f113a04:	24010001 */ 	addiu	$at,$zero,0x1
/*  f113a08:	14610008 */ 	bne	$v1,$at,.L0f113a2c
/*  f113a0c:	3c017f1b */ 	lui	$at,%hi(var7f1b3a5c)
/*  f113a10:	c4243a5c */ 	lwc1	$f4,%lo(var7f1b3a5c)($at)
/*  f113a14:	3c013f00 */ 	lui	$at,0x3f00
/*  f113a18:	44813000 */ 	mtc1	$at,$f6
/*  f113a1c:	e44403b8 */ 	swc1	$f4,0x3b8($v0)
/*  f113a20:	8e090284 */ 	lw	$t1,0x284($s0)
/*  f113a24:	10000008 */ 	beqz	$zero,.L0f113a48
/*  f113a28:	e52603bc */ 	swc1	$f6,0x3bc($t1)
.L0f113a2c:
/*  f113a2c:	3c013f80 */ 	lui	$at,0x3f80
/*  f113a30:	44814000 */ 	mtc1	$at,$f8
/*  f113a34:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113a38:	e44803b8 */ 	swc1	$f8,0x3b8($v0)
/*  f113a3c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113a40:	c44a03b8 */ 	lwc1	$f10,0x3b8($v0)
/*  f113a44:	e44a03bc */ 	swc1	$f10,0x3bc($v0)
.L0f113a48:
/*  f113a48:	8da10000 */ 	lw	$at,0x0($t5)
/*  f113a4c:	25ad000c */ 	addiu	$t5,$t5,0xc
/*  f113a50:	254a000c */ 	addiu	$t2,$t2,0xc
/*  f113a54:	ad41fff4 */ 	sw	$at,-0xc($t2)
/*  f113a58:	8da1fff8 */ 	lw	$at,-0x8($t5)
/*  f113a5c:	ad41fff8 */ 	sw	$at,-0x8($t2)
/*  f113a60:	8da1fffc */ 	lw	$at,-0x4($t5)
/*  f113a64:	15aefff8 */ 	bne	$t5,$t6,.L0f113a48
/*  f113a68:	ad41fffc */ 	sw	$at,-0x4($t2)
/*  f113a6c:	8da10000 */ 	lw	$at,0x0($t5)
/*  f113a70:	3c188007 */ 	lui	$t8,%hi(var80075c94)
/*  f113a74:	27185c94 */ 	addiu	$t8,$t8,%lo(var80075c94)
/*  f113a78:	ad410000 */ 	sw	$at,0x0($t2)
/*  f113a7c:	8f010000 */ 	lw	$at,0x0($t8)
/*  f113a80:	27b90034 */ 	addiu	$t9,$sp,0x34
/*  f113a84:	8f0c0004 */ 	lw	$t4,0x4($t8)
/*  f113a88:	af210000 */ 	sw	$at,0x0($t9)
/*  f113a8c:	8f010008 */ 	lw	$at,0x8($t8)
/*  f113a90:	af2c0004 */ 	sw	$t4,0x4($t9)
/*  f113a94:	0c0078aa */ 	jal	func0001e2a8
/*  f113a98:	af210008 */ 	sw	$at,0x8($t9)
/*  f113a9c:	8e0b0284 */ 	lw	$t3,0x284($s0)
/*  f113aa0:	afa20030 */ 	sw	$v0,0x30($sp)
/*  f113aa4:	00002025 */ 	or	$a0,$zero,$zero
/*  f113aa8:	0c0078a7 */ 	jal	func0001e29c
/*  f113aac:	ad6003a8 */ 	sw	$zero,0x3a8($t3)
/*  f113ab0:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f113ab4:	8e050034 */ 	lw	$a1,0x34($s0)
/*  f113ab8:	24060001 */ 	addiu	$a2,$zero,0x1
/*  f113abc:	0c007b86 */ 	jal	func0001ee18
/*  f113ac0:	2484045c */ 	addiu	$a0,$a0,0x45c
/*  f113ac4:	0c0078a7 */ 	jal	func0001e29c
/*  f113ac8:	8fa40030 */ 	lw	$a0,0x30($sp)
/*  f113acc:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f113ad0:	0c006cef */ 	jal	func0001b3bc
/*  f113ad4:	2484045c */ 	addiu	$a0,$a0,0x45c
/*  f113ad8:	0c00566c */ 	jal	func000159b0
/*  f113adc:	27a40040 */ 	addiu	$a0,$sp,0x40
/*  f113ae0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113ae4:	27a90040 */ 	addiu	$t1,$sp,0x40
/*  f113ae8:	afa90080 */ 	sw	$t1,0x80($sp)
/*  f113aec:	244f0510 */ 	addiu	$t7,$v0,0x510
/*  f113af0:	afaf0090 */ 	sw	$t7,0x90($sp)
/*  f113af4:	27a40080 */ 	addiu	$a0,$sp,0x80
/*  f113af8:	0c0073af */ 	jal	func0001cebc
/*  f113afc:	2445045c */ 	addiu	$a1,$v0,0x45c
/*  f113b00:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113b04:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f113b08:	c4500418 */ 	lwc1	$f16,0x418($v0)
/*  f113b0c:	e4500408 */ 	swc1	$f16,0x408($v0)
/*  f113b10:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113b14:	c452041c */ 	lwc1	$f18,0x41c($v0)
/*  f113b18:	e452040c */ 	swc1	$f18,0x40c($v0)
/*  f113b1c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113b20:	c4440420 */ 	lwc1	$f4,0x420($v0)
/*  f113b24:	e4440410 */ 	swc1	$f4,0x410($v0)
/*  f113b28:	8e040284 */ 	lw	$a0,0x284($s0)
/*  f113b2c:	0c006b43 */ 	jal	func0001ad0c
/*  f113b30:	2484045c */ 	addiu	$a0,$a0,0x45c
/*  f113b34:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113b38:	c7a60034 */ 	lwc1	$f6,0x34($sp)
/*  f113b3c:	c7b0003c */ 	lwc1	$f16,0x3c($sp)
/*  f113b40:	c4480540 */ 	lwc1	$f8,0x540($v0)
/*  f113b44:	27a50034 */ 	addiu	$a1,$sp,0x34
/*  f113b48:	2444045c */ 	addiu	$a0,$v0,0x45c
/*  f113b4c:	46083281 */ 	sub.s	$f10,$f6,$f8
/*  f113b50:	e7aa0034 */ 	swc1	$f10,0x34($sp)
/*  f113b54:	c4520548 */ 	lwc1	$f18,0x548($v0)
/*  f113b58:	46128101 */ 	sub.s	$f4,$f16,$f18
/*  f113b5c:	0c006b4d */ 	jal	func0001ad34
/*  f113b60:	e7a4003c */ 	swc1	$f4,0x3c($sp)
/*  f113b64:	44800000 */ 	mtc1	$zero,$f0
.L0f113b68:
/*  f113b68:	c7a600c0 */ 	lwc1	$f6,0xc0($sp)
/*  f113b6c:	4606003c */ 	c.lt.s	$f0,$f6
/*  f113b70:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113b74:	4502006d */ 	bc1fl	.L0f113d2c
/*  f113b78:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113b7c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113b80:	c7aa00ec */ 	lwc1	$f10,0xec($sp)
/*  f113b84:	c4480540 */ 	lwc1	$f8,0x540($v0)
/*  f113b88:	460a4400 */ 	add.s	$f16,$f8,$f10
/*  f113b8c:	e4500540 */ 	swc1	$f16,0x540($v0)
/*  f113b90:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113b94:	c7a400e8 */ 	lwc1	$f4,0xe8($sp)
/*  f113b98:	c4520548 */ 	lwc1	$f18,0x548($v0)
/*  f113b9c:	46049182 */ 	mul.s	$f6,$f18,$f4
/*  f113ba0:	e4460548 */ 	swc1	$f6,0x548($v0)
/*  f113ba4:	8e0e0034 */ 	lw	$t6,0x34($s0)
/*  f113ba8:	59c0000c */ 	blezl	$t6,.L0f113bdc
/*  f113bac:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113bb0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113bb4:	c60a004c */ 	lwc1	$f10,0x4c($s0)
/*  f113bb8:	c4480540 */ 	lwc1	$f8,0x540($v0)
/*  f113bbc:	460a4403 */ 	div.s	$f16,$f8,$f10
/*  f113bc0:	e4500540 */ 	swc1	$f16,0x540($v0)
/*  f113bc4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113bc8:	c604004c */ 	lwc1	$f4,0x4c($s0)
/*  f113bcc:	c4520548 */ 	lwc1	$f18,0x548($v0)
/*  f113bd0:	46049183 */ 	div.s	$f6,$f18,$f4
/*  f113bd4:	e4460548 */ 	swc1	$f6,0x548($v0)
/*  f113bd8:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f113bdc:
/*  f113bdc:	c4480540 */ 	lwc1	$f8,0x540($v0)
/*  f113be0:	c44a03b8 */ 	lwc1	$f10,0x3b8($v0)
/*  f113be4:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f113be8:	e7b000dc */ 	swc1	$f16,0xdc($sp)
/*  f113bec:	c4520544 */ 	lwc1	$f18,0x544($v0)
/*  f113bf0:	c4400414 */ 	lwc1	$f0,0x414($v0)
/*  f113bf4:	c44603b8 */ 	lwc1	$f6,0x3b8($v0)
/*  f113bf8:	46009101 */ 	sub.s	$f4,$f18,$f0
/*  f113bfc:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f113c00:	46004280 */ 	add.s	$f10,$f8,$f0
/*  f113c04:	e7aa00e0 */ 	swc1	$f10,0xe0($sp)
/*  f113c08:	c45203b8 */ 	lwc1	$f18,0x3b8($v0)
/*  f113c0c:	c4500548 */ 	lwc1	$f16,0x548($v0)
/*  f113c10:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f113c14:	e7a400e4 */ 	swc1	$f4,0xe4($sp)
/*  f113c18:	8c4d03ac */ 	lw	$t5,0x3ac($v0)
/*  f113c1c:	05a20032 */ 	bltzl	$t5,.L0f113ce8
/*  f113c20:	c4520530 */ 	lwc1	$f18,0x530($v0)
/*  f113c24:	c4460530 */ 	lwc1	$f6,0x530($v0)
/*  f113c28:	c44803bc */ 	lwc1	$f8,0x3bc($v0)
/*  f113c2c:	3c013f80 */ 	lui	$at,0x3f80
/*  f113c30:	44810000 */ 	mtc1	$at,$f0
/*  f113c34:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f113c38:	8e080038 */ 	lw	$t0,0x38($s0)
/*  f113c3c:	e7aa00d0 */ 	swc1	$f10,0xd0($sp)
/*  f113c40:	c45203b8 */ 	lwc1	$f18,0x3b8($v0)
/*  f113c44:	c4500534 */ 	lwc1	$f16,0x534($v0)
/*  f113c48:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f113c4c:	e7a400d4 */ 	swc1	$f4,0xd4($sp)
/*  f113c50:	c4460538 */ 	lwc1	$f6,0x538($v0)
/*  f113c54:	c44a03b8 */ 	lwc1	$f10,0x3b8($v0)
/*  f113c58:	46003201 */ 	sub.s	$f8,$f6,$f0
/*  f113c5c:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f113c60:	46008480 */ 	add.s	$f18,$f16,$f0
/*  f113c64:	e7b200d8 */ 	swc1	$f18,0xd8($sp)
/*  f113c68:	c44603b8 */ 	lwc1	$f6,0x3b8($v0)
/*  f113c6c:	c4440520 */ 	lwc1	$f4,0x520($v0)
/*  f113c70:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f113c74:	e7a800c4 */ 	swc1	$f8,0xc4($sp)
/*  f113c78:	c44a0524 */ 	lwc1	$f10,0x524($v0)
/*  f113c7c:	c45203b8 */ 	lwc1	$f18,0x3b8($v0)
/*  f113c80:	46005401 */ 	sub.s	$f16,$f10,$f0
/*  f113c84:	46128102 */ 	mul.s	$f4,$f16,$f18
/*  f113c88:	46002180 */ 	add.s	$f6,$f4,$f0
/*  f113c8c:	e7a600c8 */ 	swc1	$f6,0xc8($sp)
/*  f113c90:	c44a03b8 */ 	lwc1	$f10,0x3b8($v0)
/*  f113c94:	c4480528 */ 	lwc1	$f8,0x528($v0)
/*  f113c98:	460a4402 */ 	mul.s	$f16,$f8,$f10
/*  f113c9c:	e7b000cc */ 	swc1	$f16,0xcc($sp)
/*  f113ca0:	8c4a03b4 */ 	lw	$t2,0x3b4($v0)
/*  f113ca4:	0148c821 */ 	addu	$t9,$t2,$t0
/*  f113ca8:	ac5903b4 */ 	sw	$t9,0x3b4($v0)
/*  f113cac:	8e180284 */ 	lw	$t8,0x284($s0)
/*  f113cb0:	8f0c03b4 */ 	lw	$t4,0x3b4($t8)
/*  f113cb4:	2981003d */ 	slti	$at,$t4,0x3d
/*  f113cb8:	14200005 */ 	bnez	$at,.L0f113cd0
/*  f113cbc:	3c017f1b */ 	lui	$at,%hi(var7f1b3a60)
/*  f113cc0:	0fc44df2 */ 	jal	func0f1137c8
/*  f113cc4:	c42c3a60 */ 	lwc1	$f12,%lo(var7f1b3a60)($at)
/*  f113cc8:	10000087 */ 	beqz	$zero,.L0f113ee8
/*  f113ccc:	00000000 */ 	sll	$zero,$zero,0x0
.L0f113cd0:
/*  f113cd0:	3c017f1b */ 	lui	$at,%hi(var7f1b3a64)
/*  f113cd4:	0fc44df2 */ 	jal	func0f1137c8
/*  f113cd8:	c42c3a64 */ 	lwc1	$f12,%lo(var7f1b3a64)($at)
/*  f113cdc:	10000082 */ 	beqz	$zero,.L0f113ee8
/*  f113ce0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113ce4:	c4520530 */ 	lwc1	$f18,0x530($v0)
.L0f113ce8:
/*  f113ce8:	3c017f1b */ 	lui	$at,%hi(var7f1b3a68)
/*  f113cec:	c42c3a68 */ 	lwc1	$f12,%lo(var7f1b3a68)($at)
/*  f113cf0:	e7b200d0 */ 	swc1	$f18,0xd0($sp)
/*  f113cf4:	c4440534 */ 	lwc1	$f4,0x534($v0)
/*  f113cf8:	e7a400d4 */ 	swc1	$f4,0xd4($sp)
/*  f113cfc:	c4460538 */ 	lwc1	$f6,0x538($v0)
/*  f113d00:	e7a600d8 */ 	swc1	$f6,0xd8($sp)
/*  f113d04:	c4480520 */ 	lwc1	$f8,0x520($v0)
/*  f113d08:	e7a800c4 */ 	swc1	$f8,0xc4($sp)
/*  f113d0c:	c44a0524 */ 	lwc1	$f10,0x524($v0)
/*  f113d10:	e7aa00c8 */ 	swc1	$f10,0xc8($sp)
/*  f113d14:	c4500528 */ 	lwc1	$f16,0x528($v0)
/*  f113d18:	0fc44df2 */ 	jal	func0f1137c8
/*  f113d1c:	e7b000cc */ 	swc1	$f16,0xcc($sp)
/*  f113d20:	10000071 */ 	beqz	$zero,.L0f113ee8
/*  f113d24:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113d28:	8e020284 */ 	lw	$v0,0x284($s0)
.L0f113d2c:
/*  f113d2c:	3c017f1b */ 	lui	$at,%hi(var7f1b3a6c)
/*  f113d30:	c4520418 */ 	lwc1	$f18,0x418($v0)
/*  f113d34:	e4520408 */ 	swc1	$f18,0x408($v0)
/*  f113d38:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113d3c:	c444041c */ 	lwc1	$f4,0x41c($v0)
/*  f113d40:	e444040c */ 	swc1	$f4,0x40c($v0)
/*  f113d44:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113d48:	c4460420 */ 	lwc1	$f6,0x420($v0)
/*  f113d4c:	e4460410 */ 	swc1	$f6,0x410($v0)
/*  f113d50:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113d54:	e7a000dc */ 	swc1	$f0,0xdc($sp)
/*  f113d58:	c4480414 */ 	lwc1	$f8,0x414($v0)
/*  f113d5c:	e7a000e4 */ 	swc1	$f0,0xe4($sp)
/*  f113d60:	e7a800e0 */ 	swc1	$f8,0xe0($sp)
/*  f113d64:	ac4003b4 */ 	sw	$zero,0x3b4($v0)
/*  f113d68:	0fc44df2 */ 	jal	func0f1137c8
/*  f113d6c:	c42c3a6c */ 	lwc1	$f12,%lo(var7f1b3a6c)($at)
/*  f113d70:	0fc331a0 */ 	jal	func0f0cc680
/*  f113d74:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113d78:	1040005b */ 	beqz	$v0,.L0f113ee8
/*  f113d7c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113d80:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113d84:	3c017f1b */ 	lui	$at,%hi(var7f1b3a70)
/*  f113d88:	c42a3a70 */ 	lwc1	$f10,%lo(var7f1b3a70)($at)
/*  f113d8c:	c4500198 */ 	lwc1	$f16,0x198($v0)
/*  f113d90:	3c017f1b */ 	lui	$at,%hi(var7f1b3a74)
/*  f113d94:	c4243a74 */ 	lwc1	$f4,%lo(var7f1b3a74)($at)
/*  f113d98:	46105482 */ 	mul.s	$f18,$f10,$f16
/*  f113d9c:	c608004c */ 	lwc1	$f8,0x4c($s0)
/*  f113da0:	c4500424 */ 	lwc1	$f16,0x424($v0)
/*  f113da4:	3c013f80 */ 	lui	$at,0x3f80
/*  f113da8:	46122180 */ 	add.s	$f6,$f4,$f18
/*  f113dac:	44819000 */ 	mtc1	$at,$f18
/*  f113db0:	46083282 */ 	mul.s	$f10,$f6,$f8
/*  f113db4:	460a8100 */ 	add.s	$f4,$f16,$f10
/*  f113db8:	e4440424 */ 	swc1	$f4,0x424($v0)
/*  f113dbc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113dc0:	c4400424 */ 	lwc1	$f0,0x424($v0)
/*  f113dc4:	4600903e */ 	c.le.s	$f18,$f0
/*  f113dc8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113dcc:	4502000c */ 	bc1fl	.L0f113e00
/*  f113dd0:	8c430458 */ 	lw	$v1,0x458($v0)
/*  f113dd4:	0fc44c8f */ 	jal	func0f11323c
/*  f113dd8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113ddc:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113de0:	3c013f80 */ 	lui	$at,0x3f80
/*  f113de4:	44814000 */ 	mtc1	$at,$f8
/*  f113de8:	c4460424 */ 	lwc1	$f6,0x424($v0)
/*  f113dec:	46083401 */ 	sub.s	$f16,$f6,$f8
/*  f113df0:	e4500424 */ 	swc1	$f16,0x424($v0)
/*  f113df4:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113df8:	c4400424 */ 	lwc1	$f0,0x424($v0)
/*  f113dfc:	8c430458 */ 	lw	$v1,0x458($v0)
.L0f113e00:
/*  f113e00:	44060000 */ 	mfc1	$a2,$f0
/*  f113e04:	27a700d0 */ 	addiu	$a3,$sp,0xd0
/*  f113e08:	00035880 */ 	sll	$t3,$v1,0x2
/*  f113e0c:	01635823 */ 	subu	$t3,$t3,$v1
/*  f113e10:	000b1880 */ 	sll	$v1,$t3,0x2
/*  f113e14:	00034823 */ 	negu	$t1,$v1
/*  f113e18:	00492821 */ 	addu	$a1,$v0,$t1
/*  f113e1c:	00432021 */ 	addu	$a0,$v0,$v1
/*  f113e20:	24840428 */ 	addiu	$a0,$a0,0x428
/*  f113e24:	0fc25ac8 */ 	jal	func0f096b20
/*  f113e28:	24a50434 */ 	addiu	$a1,$a1,0x434
/*  f113e2c:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113e30:	3c0140a0 */ 	lui	$at,0x40a0
/*  f113e34:	44810000 */ 	mtc1	$at,$f0
/*  f113e38:	c4440198 */ 	lwc1	$f4,0x198($v0)
/*  f113e3c:	3c013f80 */ 	lui	$at,0x3f80
/*  f113e40:	44811000 */ 	mtc1	$at,$f2
/*  f113e44:	46040482 */ 	mul.s	$f18,$f0,$f4
/*  f113e48:	c7aa00d0 */ 	lwc1	$f10,0xd0($sp)
/*  f113e4c:	c7b000d4 */ 	lwc1	$f16,0xd4($sp)
/*  f113e50:	27a700c4 */ 	addiu	$a3,$sp,0xc4
/*  f113e54:	46121180 */ 	add.s	$f6,$f2,$f18
/*  f113e58:	46065202 */ 	mul.s	$f8,$f10,$f6
/*  f113e5c:	e7a800d0 */ 	swc1	$f8,0xd0($sp)
/*  f113e60:	c4440198 */ 	lwc1	$f4,0x198($v0)
/*  f113e64:	46040482 */ 	mul.s	$f18,$f0,$f4
/*  f113e68:	46121280 */ 	add.s	$f10,$f2,$f18
/*  f113e6c:	460a8182 */ 	mul.s	$f6,$f16,$f10
/*  f113e70:	e7a600d4 */ 	swc1	$f6,0xd4($sp)
/*  f113e74:	8c430458 */ 	lw	$v1,0x458($v0)
/*  f113e78:	8c460424 */ 	lw	$a2,0x424($v0)
/*  f113e7c:	00037880 */ 	sll	$t7,$v1,0x2
/*  f113e80:	01e37823 */ 	subu	$t7,$t7,$v1
/*  f113e84:	000f1880 */ 	sll	$v1,$t7,0x2
/*  f113e88:	00037023 */ 	negu	$t6,$v1
/*  f113e8c:	004e2821 */ 	addu	$a1,$v0,$t6
/*  f113e90:	00432021 */ 	addu	$a0,$v0,$v1
/*  f113e94:	24840440 */ 	addiu	$a0,$a0,0x440
/*  f113e98:	0fc25ac8 */ 	jal	func0f096b20
/*  f113e9c:	24a5044c */ 	addiu	$a1,$a1,0x44c
/*  f113ea0:	8e020284 */ 	lw	$v0,0x284($s0)
/*  f113ea4:	3c0140a0 */ 	lui	$at,0x40a0
/*  f113ea8:	44810000 */ 	mtc1	$at,$f0
/*  f113eac:	c4440198 */ 	lwc1	$f4,0x198($v0)
/*  f113eb0:	3c013f80 */ 	lui	$at,0x3f80
/*  f113eb4:	44814000 */ 	mtc1	$at,$f8
/*  f113eb8:	46040482 */ 	mul.s	$f18,$f0,$f4
/*  f113ebc:	c7aa00c4 */ 	lwc1	$f10,0xc4($sp)
/*  f113ec0:	44812000 */ 	mtc1	$at,$f4
/*  f113ec4:	46124400 */ 	add.s	$f16,$f8,$f18
/*  f113ec8:	46105182 */ 	mul.s	$f6,$f10,$f16
/*  f113ecc:	c7b000cc */ 	lwc1	$f16,0xcc($sp)
/*  f113ed0:	e7a600c4 */ 	swc1	$f6,0xc4($sp)
/*  f113ed4:	c4480198 */ 	lwc1	$f8,0x198($v0)
/*  f113ed8:	46080482 */ 	mul.s	$f18,$f0,$f8
/*  f113edc:	46122280 */ 	add.s	$f10,$f4,$f18
/*  f113ee0:	460a8182 */ 	mul.s	$f6,$f16,$f10
/*  f113ee4:	e7a600cc */ 	swc1	$f6,0xcc($sp)
.L0f113ee8:
/*  f113ee8:	0fc44d2f */ 	jal	func0f1134bc
/*  f113eec:	27a400dc */ 	addiu	$a0,$sp,0xdc
/*  f113ef0:	27a400d0 */ 	addiu	$a0,$sp,0xd0
/*  f113ef4:	0fc44d6c */ 	jal	func0f1135b0
/*  f113ef8:	27a500c4 */ 	addiu	$a1,$sp,0xc4
/*  f113efc:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f113f00:	8fb00018 */ 	lw	$s0,0x18($sp)
/*  f113f04:	27bd00e8 */ 	addiu	$sp,$sp,0xe8
/*  f113f08:	03e00008 */ 	jr	$ra
/*  f113f0c:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f113f10
/*  f113f10:	3c08800a */ 	lui	$t0,0x800a
/*  f113f14:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f113f18:	27bdffd0 */ 	addiu	$sp,$sp,-48
/*  f113f1c:	afbf0024 */ 	sw	$ra,0x24($sp)
/*  f113f20:	afb00020 */ 	sw	$s0,0x20($sp)
/*  f113f24:	8d0e00bc */ 	lw	$t6,0xbc($t0)
/*  f113f28:	3c058007 */ 	lui	$a1,%hi(var80075c00)
/*  f113f2c:	24a55c00 */ 	addiu	$a1,$a1,%lo(var80075c00)
/*  f113f30:	c4a40024 */ 	lwc1	$f4,0x24($a1)
/*  f113f34:	8dcf0004 */ 	lw	$t7,0x4($t6)
/*  f113f38:	3c108007 */ 	lui	$s0,%hi(var80075c00)
/*  f113f3c:	46046302 */ 	mul.s	$f12,$f12,$f4
/*  f113f40:	26105c00 */ 	addiu	$s0,$s0,%lo(var80075c00)
/*  f113f44:	00001025 */ 	or	$v0,$zero,$zero
/*  f113f48:	24030002 */ 	addiu	$v1,$zero,0x2
/*  f113f4c:	afaf002c */ 	sw	$t7,0x2c($sp)
.L0f113f50:
/*  f113f50:	c600000c */ 	lwc1	$f0,0xc($s0)
/*  f113f54:	c6060014 */ 	lwc1	$f6,0x14($s0)
/*  f113f58:	46060202 */ 	mul.s	$f8,$f0,$f6
/*  f113f5c:	4608603e */ 	c.le.s	$f12,$f8
/*  f113f60:	00000000 */ 	sll	$zero,$zero,0x0
/*  f113f64:	4502004a */ 	bc1fl	.L0f114090
/*  f113f68:	24420001 */ 	addiu	$v0,$v0,0x1
/*  f113f6c:	8d0403ac */ 	lw	$a0,0x3ac($t0)
/*  f113f70:	3c013f00 */ 	lui	$at,0x3f00
/*  f113f74:	5044003a */ 	beql	$v0,$a0,.L0f114060
/*  f113f78:	46006303 */ 	div.s	$f12,$f12,$f0
/*  f113f7c:	44807000 */ 	mtc1	$zero,$f14
/*  f113f80:	04800010 */ 	bltz	$a0,.L0f113fc4
/*  f113f84:	0004c080 */ 	sll	$t8,$a0,0x2
/*  f113f88:	0304c023 */ 	subu	$t8,$t8,$a0
/*  f113f8c:	8d19047c */ 	lw	$t9,0x47c($t0)
/*  f113f90:	0018c0c0 */ 	sll	$t8,$t8,0x3
/*  f113f94:	00b81821 */ 	addu	$v1,$a1,$t8
/*  f113f98:	c4600004 */ 	lwc1	$f0,0x4($v1)
/*  f113f9c:	c4720008 */ 	lwc1	$f18,0x8($v1)
/*  f113fa0:	c72a000c */ 	lwc1	$f10,0xc($t9)
/*  f113fa4:	c6020004 */ 	lwc1	$f2,0x4($s0)
/*  f113fa8:	46009101 */ 	sub.s	$f4,$f18,$f0
/*  f113fac:	c6060008 */ 	lwc1	$f6,0x8($s0)
/*  f113fb0:	46005401 */ 	sub.s	$f16,$f10,$f0
/*  f113fb4:	46023201 */ 	sub.s	$f8,$f6,$f2
/*  f113fb8:	46048383 */ 	div.s	$f14,$f16,$f4
/*  f113fbc:	460e4282 */ 	mul.s	$f10,$f8,$f14
/*  f113fc0:	46025380 */ 	add.s	$f14,$f10,$f2
.L0f113fc4:
/*  f113fc4:	8d09047c */ 	lw	$t1,0x47c($t0)
/*  f113fc8:	44819000 */ 	mtc1	$at,$f18
/*  f113fcc:	3c014140 */ 	lui	$at,0x4140
/*  f113fd0:	81260008 */ 	lb	$a2,0x8($t1)
/*  f113fd4:	44818000 */ 	mtc1	$at,$f16
/*  f113fd8:	44077000 */ 	mfc1	$a3,$f14
/*  f113fdc:	e7ac0030 */ 	swc1	$f12,0x30($sp)
/*  f113fe0:	afa20028 */ 	sw	$v0,0x28($sp)
/*  f113fe4:	2504045c */ 	addiu	$a0,$t0,0x45c
/*  f113fe8:	86050000 */ 	lh	$a1,0x0($s0)
/*  f113fec:	e7b20010 */ 	swc1	$f18,0x10($sp)
/*  f113ff0:	0c007733 */ 	jal	func0001dccc
/*  f113ff4:	e7b00014 */ 	swc1	$f16,0x14($sp)
/*  f113ff8:	3c04800a */ 	lui	$a0,%hi(var800a045c)
/*  f113ffc:	8c84a244 */ 	lw	$a0,-0x5dbc($a0)
/*  f114000:	8e050004 */ 	lw	$a1,0x4($s0)
/*  f114004:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f114008:	0c00777b */ 	jal	func0001ddec
/*  f11400c:	2484045c */ 	addiu	$a0,$a0,%lo(var800a045c)
/*  f114010:	3c04800a */ 	lui	$a0,%hi(var800a045c)
/*  f114014:	8c84a244 */ 	lw	$a0,-0x5dbc($a0)
/*  f114018:	8e050008 */ 	lw	$a1,0x8($s0)
/*  f11401c:	0c007787 */ 	jal	func0001de1c
/*  f114020:	2484045c */ 	addiu	$a0,$a0,%lo(var800a045c)
/*  f114024:	3c04800a */ 	lui	$a0,%hi(var800a045c)
/*  f114028:	8c84a244 */ 	lw	$a0,-0x5dbc($a0)
/*  f11402c:	3c057f11 */ 	lui	$a1,0x7f11
/*  f114030:	24a53220 */ 	addiu	$a1,$a1,0x3220
/*  f114034:	0c0077a6 */ 	jal	func0001de98
/*  f114038:	2484045c */ 	addiu	$a0,$a0,%lo(var800a045c)
/*  f11403c:	3c0a800a */ 	lui	$t2,0x800a
/*  f114040:	8fa20028 */ 	lw	$v0,0x28($sp)
/*  f114044:	8d4aa244 */ 	lw	$t2,-0x5dbc($t2)
/*  f114048:	c7ac0030 */ 	lwc1	$f12,0x30($sp)
/*  f11404c:	3c08800a */ 	lui	$t0,0x800a
/*  f114050:	ad4203ac */ 	sw	$v0,0x3ac($t2)
/*  f114054:	c600000c */ 	lwc1	$f0,0xc($s0)
/*  f114058:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f11405c:	46006303 */ 	div.s	$f12,$f12,$f0
.L0f114060:
/*  f114060:	3c013f00 */ 	lui	$at,0x3f00
/*  f114064:	44812000 */ 	mtc1	$at,$f4
/*  f114068:	2504045c */ 	addiu	$a0,$t0,0x45c
/*  f11406c:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f114070:	46046182 */ 	mul.s	$f6,$f12,$f4
/*  f114074:	44053000 */ 	mfc1	$a1,$f6
/*  f114078:	0c0077ac */ 	jal	func0001deb0
/*  f11407c:	00000000 */ 	sll	$zero,$zero,0x0
/*  f114080:	3c08800a */ 	lui	$t0,0x800a
/*  f114084:	10000004 */ 	beqz	$zero,.L0f114098
/*  f114088:	8d08a244 */ 	lw	$t0,-0x5dbc($t0)
/*  f11408c:	24420001 */ 	addiu	$v0,$v0,0x1
.L0f114090:
/*  f114090:	1443ffaf */ 	bne	$v0,$v1,.L0f113f50
/*  f114094:	26100018 */ 	addiu	$s0,$s0,0x18
.L0f114098:
/*  f114098:	8d0b047c */ 	lw	$t3,0x47c($t0)
/*  f11409c:	8fac002c */ 	lw	$t4,0x2c($sp)
/*  f1140a0:	c568000c */ 	lwc1	$f8,0xc($t3)
/*  f1140a4:	e588018c */ 	swc1	$f8,0x18c($t4)
/*  f1140a8:	8fbf0024 */ 	lw	$ra,0x24($sp)
/*  f1140ac:	8fb00020 */ 	lw	$s0,0x20($sp)
/*  f1140b0:	27bd0030 */ 	addiu	$sp,$sp,0x30
/*  f1140b4:	03e00008 */ 	jr	$ra
/*  f1140b8:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f1140bc
/*  f1140bc:	3c013f00 */ 	lui	$at,0x3f00
/*  f1140c0:	44877000 */ 	mtc1	$a3,$f14
/*  f1140c4:	44812000 */ 	mtc1	$at,$f4
/*  f1140c8:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f1140cc:	44866000 */ 	mtc1	$a2,$f12
/*  f1140d0:	46047182 */ 	mul.s	$f6,$f14,$f4
/*  f1140d4:	afa40020 */ 	sw	$a0,0x20($sp)
/*  f1140d8:	3c04800a */ 	lui	$a0,%hi(var800a045c)
/*  f1140dc:	3c014140 */ 	lui	$at,0x4140
/*  f1140e0:	44814000 */ 	mtc1	$at,$f8
/*  f1140e4:	8c84a244 */ 	lw	$a0,-0x5dbc($a0)
/*  f1140e8:	afbf001c */ 	sw	$ra,0x1c($sp)
/*  f1140ec:	afa50024 */ 	sw	$a1,0x24($sp)
/*  f1140f0:	44076000 */ 	mfc1	$a3,$f12
/*  f1140f4:	8fa60024 */ 	lw	$a2,0x24($sp)
/*  f1140f8:	87a50022 */ 	lh	$a1,0x22($sp)
/*  f1140fc:	e7a60010 */ 	swc1	$f6,0x10($sp)
/*  f114100:	2484045c */ 	addiu	$a0,$a0,%lo(var800a045c)
/*  f114104:	0c007733 */ 	jal	func0001dccc
/*  f114108:	e7a80014 */ 	swc1	$f8,0x14($sp)
/*  f11410c:	3c0f800a */ 	lui	$t7,0x800a
/*  f114110:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f114114:	240effff */ 	addiu	$t6,$zero,-1
/*  f114118:	adee03ac */ 	sw	$t6,0x3ac($t7)
/*  f11411c:	8fbf001c */ 	lw	$ra,0x1c($sp)
/*  f114120:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f114124:	03e00008 */ 	jr	$ra
/*  f114128:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11412c
/*  f11412c:	3c013f00 */ 	lui	$at,0x3f00
/*  f114130:	44812000 */ 	mtc1	$at,$f4
/*  f114134:	3c04800a */ 	lui	$a0,%hi(var800a045c)
/*  f114138:	8c84a244 */ 	lw	$a0,-0x5dbc($a0)
/*  f11413c:	46046182 */ 	mul.s	$f6,$f12,$f4
/*  f114140:	27bdffe8 */ 	addiu	$sp,$sp,-24
/*  f114144:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f114148:	24060000 */ 	addiu	$a2,$zero,0x0
/*  f11414c:	2484045c */ 	addiu	$a0,$a0,%lo(var800a045c)
/*  f114150:	44053000 */ 	mfc1	$a1,$f6
/*  f114154:	0c0077ac */ 	jal	func0001deb0
/*  f114158:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11415c:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f114160:	27bd0018 */ 	addiu	$sp,$sp,0x18
/*  f114164:	03e00008 */ 	jr	$ra
/*  f114168:	00000000 */ 	sll	$zero,$zero,0x0
);

GLOBAL_ASM(
glabel func0f11416c
/*  f11416c:	3c02800a */ 	lui	$v0,0x800a
/*  f114170:	8c42a244 */ 	lw	$v0,-0x5dbc($v0)
/*  f114174:	27bdffe0 */ 	addiu	$sp,$sp,-32
/*  f114178:	afbf0014 */ 	sw	$ra,0x14($sp)
/*  f11417c:	8c4e03ac */ 	lw	$t6,0x3ac($v0)
/*  f114180:	3c017f1b */ 	lui	$at,%hi(var7f1b3a78)
/*  f114184:	05c20027 */ 	bltzl	$t6,.L0f114224
/*  f114188:	44800000 */ 	mtc1	$zero,$f0
/*  f11418c:	c4440198 */ 	lwc1	$f4,0x198($v0)
/*  f114190:	c4263a78 */ 	lwc1	$f6,%lo(var7f1b3a78)($at)
/*  f114194:	3c017f1b */ 	lui	$at,%hi(var7f1b3a7c)
/*  f114198:	c42a3a7c */ 	lwc1	$f10,%lo(var7f1b3a7c)($at)
/*  f11419c:	46062202 */ 	mul.s	$f8,$f4,$f6
/*  f1141a0:	2444045c */ 	addiu	$a0,$v0,0x45c
/*  f1141a4:	460a4080 */ 	add.s	$f2,$f8,$f10
/*  f1141a8:	0c0074a2 */ 	jal	func0001d288
/*  f1141ac:	e7a2001c */ 	swc1	$f2,0x1c($sp)
/*  f1141b0:	44808000 */ 	mtc1	$zero,$f16
/*  f1141b4:	c7a2001c */ 	lwc1	$f2,0x1c($sp)
/*  f1141b8:	3c0f800a */ 	lui	$t7,0x800a
/*  f1141bc:	4600803c */ 	c.lt.s	$f16,$f0
/*  f1141c0:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1141c4:	45000014 */ 	bc1f	.L0f114218
/*  f1141c8:	00000000 */ 	sll	$zero,$zero,0x0
/*  f1141cc:	8defa244 */ 	lw	$t7,-0x5dbc($t7)
/*  f1141d0:	3c088007 */ 	lui	$t0,%hi(var80075c00)
/*  f1141d4:	25085c00 */ 	addiu	$t0,$t0,%lo(var80075c00)
/*  f1141d8:	8df803ac */ 	lw	$t8,0x3ac($t7)
/*  f1141dc:	0018c880 */ 	sll	$t9,$t8,0x2
/*  f1141e0:	0338c823 */ 	subu	$t9,$t9,$t8
/*  f1141e4:	0019c8c0 */ 	sll	$t9,$t9,0x3
/*  f1141e8:	03281021 */ 	addu	$v0,$t9,$t0
/*  f1141ec:	c4520008 */ 	lwc1	$f18,0x8($v0)
/*  f1141f0:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*  f1141f4:	46049181 */ 	sub.s	$f6,$f18,$f4
/*  f1141f8:	46060303 */ 	div.s	$f12,$f0,$f6
/*  f1141fc:	4602603c */ 	c.lt.s	$f12,$f2
/*  f114200:	00000000 */ 	sll	$zero,$zero,0x0
/*  f114204:	45000002 */ 	bc1f	.L0f114210
/*  f114208:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11420c:	46001306 */ 	mov.s	$f12,$f2
.L0f114210:
/*  f114210:	10000005 */ 	beqz	$zero,.L0f114228
/*  f114214:	46006006 */ 	mov.s	$f0,$f12
.L0f114218:
/*  f114218:	10000003 */ 	beqz	$zero,.L0f114228
/*  f11421c:	46001006 */ 	mov.s	$f0,$f2
/*  f114220:	44800000 */ 	mtc1	$zero,$f0
.L0f114224:
/*  f114224:	00000000 */ 	sll	$zero,$zero,0x0
.L0f114228:
/*  f114228:	8fbf0014 */ 	lw	$ra,0x14($sp)
/*  f11422c:	27bd0020 */ 	addiu	$sp,$sp,0x20
/*  f114230:	03e00008 */ 	jr	$ra
/*  f114234:	00000000 */ 	sll	$zero,$zero,0x0
/*  f114238:	00000000 */ 	sll	$zero,$zero,0x0
/*  f11423c:	00000000 */ 	sll	$zero,$zero,0x0
);
