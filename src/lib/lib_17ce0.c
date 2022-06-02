#include <ultra64.h>
#include "constants.h"
#include "game/atan2f.h"
#include "game/padhalllv.h"
#include "bss.h"
#include "lib/mtx.h"
#include "data.h"
#include "types.h"

u32 var8005ef20 = 0xfe000000;

GLOBAL_ASM(
glabel func00017ce0
/*    17ce0:	3c03800a */ 	lui	$v1,%hi(g_BgPortals)
/*    17ce4:	8c634cc8 */ 	lw	$v1,%lo(g_BgPortals)($v1)
/*    17ce8:	000470c0 */ 	sll	$t6,$a0,0x3
/*    17cec:	3c013f80 */ 	lui	$at,0x3f80
/*    17cf0:	006e7821 */ 	addu	$t7,$v1,$t6
/*    17cf4:	95f80000 */ 	lhu	$t8,0x0($t7)
/*    17cf8:	44815000 */ 	mtc1	$at,$f10
/*    17cfc:	3c014f80 */ 	lui	$at,0x4f80
/*    17d00:	03031021 */ 	addu	$v0,$t8,$v1
/*    17d04:	c4440004 */ 	lwc1	$f4,0x4($v0)
/*    17d08:	2443000c */ 	addiu	$v1,$v0,0xc
/*    17d0c:	24070001 */ 	addiu	$a3,$zero,0x1
/*    17d10:	e4a40000 */ 	swc1	$f4,0x0($a1)
/*    17d14:	c4460008 */ 	lwc1	$f6,0x8($v0)
/*    17d18:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*    17d1c:	c448000c */ 	lwc1	$f8,0xc($v0)
/*    17d20:	e4a80008 */ 	swc1	$f8,0x8($a1)
/*    17d24:	90460000 */ 	lbu	$a2,0x0($v0)
/*    17d28:	44868000 */ 	mtc1	$a2,$f16
/*    17d2c:	04c10004 */ 	bgez	$a2,.L00017d40
/*    17d30:	468084a0 */ 	cvt.s.w	$f18,$f16
/*    17d34:	44812000 */ 	mtc1	$at,$f4
/*    17d38:	00000000 */ 	nop
/*    17d3c:	46049480 */ 	add.s	$f18,$f18,$f4
.L00017d40:
/*    17d40:	28c10002 */ 	slti	$at,$a2,0x2
/*    17d44:	14200013 */ 	bnez	$at,.L00017d94
/*    17d48:	46125003 */ 	div.s	$f0,$f10,$f18
/*    17d4c:	c4a60000 */ 	lwc1	$f6,0x0($a1)
.L00017d50:
/*    17d50:	c4680004 */ 	lwc1	$f8,0x4($v1)
/*    17d54:	c4a40004 */ 	lwc1	$f4,0x4($a1)
/*    17d58:	24e70001 */ 	addiu	$a3,$a3,0x1
/*    17d5c:	46083400 */ 	add.s	$f16,$f6,$f8
/*    17d60:	c4a60008 */ 	lwc1	$f6,0x8($a1)
/*    17d64:	2463000c */ 	addiu	$v1,$v1,12
/*    17d68:	e4b00000 */ 	swc1	$f16,0x0($a1)
/*    17d6c:	c46afffc */ 	lwc1	$f10,-0x4($v1)
/*    17d70:	460a2480 */ 	add.s	$f18,$f4,$f10
/*    17d74:	e4b20004 */ 	swc1	$f18,0x4($a1)
/*    17d78:	c4680000 */ 	lwc1	$f8,0x0($v1)
/*    17d7c:	46083400 */ 	add.s	$f16,$f6,$f8
/*    17d80:	e4b00008 */ 	swc1	$f16,0x8($a1)
/*    17d84:	90590000 */ 	lbu	$t9,0x0($v0)
/*    17d88:	00f9082a */ 	slt	$at,$a3,$t9
/*    17d8c:	5420fff0 */ 	bnezl	$at,.L00017d50
/*    17d90:	c4a60000 */ 	lwc1	$f6,0x0($a1)
.L00017d94:
/*    17d94:	c4a40000 */ 	lwc1	$f4,0x0($a1)
/*    17d98:	c4b20004 */ 	lwc1	$f18,0x4($a1)
/*    17d9c:	c4a80008 */ 	lwc1	$f8,0x8($a1)
/*    17da0:	46002282 */ 	mul.s	$f10,$f4,$f0
/*    17da4:	00000000 */ 	nop
/*    17da8:	46009182 */ 	mul.s	$f6,$f18,$f0
/*    17dac:	00000000 */ 	nop
/*    17db0:	46004402 */ 	mul.s	$f16,$f8,$f0
/*    17db4:	e4aa0000 */ 	swc1	$f10,0x0($a1)
/*    17db8:	e4a60004 */ 	swc1	$f6,0x4($a1)
/*    17dbc:	03e00008 */ 	jr	$ra
/*    17dc0:	e4b00008 */ 	swc1	$f16,0x8($a1)
);

#if VERSION < VERSION_NTSC_1_0
GLOBAL_ASM(
glabel func00018e34nb
/*    18e34:	3c0e800b */ 	lui	$t6,0x800b
/*    18e38:	8dce9448 */ 	lw	$t6,-0x6bb8($t6)
/*    18e3c:	000478c0 */ 	sll	$t7,$a0,0x3
/*    18e40:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    18e44:	93020006 */ 	lbu	$v0,0x6($t8)
/*    18e48:	30590002 */ 	andi	$t9,$v0,0x2
/*    18e4c:	03e00008 */ 	jr	$ra
/*    18e50:	03201025 */ 	or	$v0,$t9,$zero
/*    18e54:	3c0e800b */ 	lui	$t6,0x800b
/*    18e58:	8dce9448 */ 	lw	$t6,-0x6bb8($t6)
/*    18e5c:	000478c0 */ 	sll	$t7,$a0,0x3
/*    18e60:	01cf1021 */ 	addu	$v0,$t6,$t7
/*    18e64:	90580006 */ 	lbu	$t8,0x6($v0)
/*    18e68:	37190002 */ 	ori	$t9,$t8,0x2
/*    18e6c:	03e00008 */ 	jr	$ra
/*    18e70:	a0590006 */ 	sb	$t9,0x6($v0)
/*    18e74:	3c0e800b */ 	lui	$t6,0x800b
/*    18e78:	8dce9448 */ 	lw	$t6,-0x6bb8($t6)
/*    18e7c:	000478c0 */ 	sll	$t7,$a0,0x3
/*    18e80:	01cf1021 */ 	addu	$v0,$t6,$t7
/*    18e84:	90580006 */ 	lbu	$t8,0x6($v0)
/*    18e88:	331900fd */ 	andi	$t9,$t8,0xfd
/*    18e8c:	03e00008 */ 	jr	$ra
/*    18e90:	a0590006 */ 	sb	$t9,0x6($v0)
);
#endif

GLOBAL_ASM(
glabel func00017dc4
/*    17dc4:	afa50004 */ 	sw	$a1,0x4($sp)
/*    17dc8:	848f0000 */ 	lh	$t7,0x0($a0)
/*    17dcc:	00053400 */ 	sll	$a2,$a1,0x10
/*    17dd0:	00067403 */ 	sra	$t6,$a2,0x10
/*    17dd4:	2407ffff */ 	addiu	$a3,$zero,-1
/*    17dd8:	01c03025 */ 	or	$a2,$t6,$zero
/*    17ddc:	10ef000c */ 	beq	$a3,$t7,.L00017e10
/*    17de0:	00001025 */ 	or	$v0,$zero,$zero
/*    17de4:	0000c040 */ 	sll	$t8,$zero,0x1
/*    17de8:	00981821 */ 	addu	$v1,$a0,$t8
/*    17dec:	84650000 */ 	lh	$a1,0x0($v1)
.L00017df0:
/*    17df0:	10c5000d */ 	beq	$a2,$a1,.L00017e28
/*    17df4:	24420001 */ 	addiu	$v0,$v0,0x1
/*    17df8:	28410010 */ 	slti	$at,$v0,0x10
/*    17dfc:	10200004 */ 	beqz	$at,.L00017e10
/*    17e00:	24630002 */ 	addiu	$v1,$v1,0x2
/*    17e04:	84650000 */ 	lh	$a1,0x0($v1)
/*    17e08:	14e5fff9 */ 	bne	$a3,$a1,.L00017df0
/*    17e0c:	00000000 */ 	nop
.L00017e10:
/*    17e10:	2841000f */ 	slti	$at,$v0,0xf
/*    17e14:	10200004 */ 	beqz	$at,.L00017e28
/*    17e18:	0002c840 */ 	sll	$t9,$v0,0x1
/*    17e1c:	00991821 */ 	addu	$v1,$a0,$t9
/*    17e20:	a4660000 */ 	sh	$a2,0x0($v1)
/*    17e24:	a4670002 */ 	sh	$a3,0x2($v1)
.L00017e28:
/*    17e28:	03e00008 */ 	jr	$ra
/*    17e2c:	00000000 */ 	nop
);

s32 portal00017e30(s32 portalnum, struct coord *arg1, struct coord *arg2)
{
	s32 i;
	struct coord sp60;
	struct portalvertices *pvertices;
	struct coord *curr;
	struct coord *next;
	struct coord sp48;
	u8 lastside;
	f32 sp40[1];
	struct coord sp34;
	f32 value1;
	f32 value2;
	f32 tmp;
	u32 stack;

	lastside = 0;
	pvertices = (struct portalvertices *)((u32)g_BgPortals + g_BgPortals[portalnum].verticesoffset);
	value1 = arg1->f[0] * (var800a4ccc + portalnum)->coord.f[0] + arg1->f[1] * (var800a4ccc + portalnum)->coord.f[1] + arg1->f[2] * (var800a4ccc + portalnum)->coord.f[2];
	value2 = arg2->f[0] * (var800a4ccc + portalnum)->coord.f[0] + arg2->f[1] * (var800a4ccc + portalnum)->coord.f[1] + arg2->f[2] * (var800a4ccc + portalnum)->coord.f[2];

	if (value1 < (var800a4ccc + portalnum)->unk0c) {
		if (value2 < (var800a4ccc + portalnum)->unk0c) {
			return 0;
		}
	} else if ((var800a4ccc + portalnum)->unk10 < value1 && (var800a4ccc + portalnum)->unk10 < value2) {
		return 0;
	}

	sp60.f[0] = arg2->f[0] - arg1->f[0];
	sp60.f[1] = arg2->f[1] - arg1->f[1];
	sp60.f[2] = arg2->f[2] - arg1->f[2];

	var8007fcb4 = (value1 + value2) * 0.5f - (var800a4ccc + portalnum)->unk0c;

	curr = &pvertices->vertices[0];
	next = &pvertices->vertices[1];

	for (i = 0; i < pvertices->count; i++) {
		if (i + 1 == pvertices->count) {
			next = &pvertices->vertices[0];
		}

		sp48.f[0] = next->f[0] - curr->f[0];
		sp48.f[1] = next->f[1] - curr->f[1];
		sp48.f[2] = next->f[2] - curr->f[2];

		sp34.f[0] = sp48.f[1] * sp60.f[2] - sp48.f[2] * sp60.f[1];
		sp34.f[1] = sp48.f[2] * sp60.f[0] - sp48.f[0] * sp60.f[2];
		sp34.f[2] = sp48.f[0] * sp60.f[1] - sp48.f[1] * sp60.f[0];

		tmp = sp34.f[0] * sp34.f[0] + sp34.f[1] * sp34.f[1] + sp34.f[2] * sp34.f[2];

		if (tmp == 0.0f) {
			return 0;
		}

		sp40[0] = sp34.f[0] * curr->f[0] + sp34.f[1] * curr->f[1] + sp34.f[2] * curr->f[2];
		tmp = sp34.f[0] * arg1->f[0] + sp34.f[1] * arg1->f[1] + sp34.f[2] * arg1->f[2];

		if (tmp < sp40[0]) {
			if (lastside == 2) {
				return 0;
			}

			lastside = 1;
		} else {
			if (lastside == 1) {
				return 0;
			}

			lastside = 2;
		}

		curr++;
		next++;
	}

	return (value1 < (var800a4ccc + portalnum)->unk0c) ? 1 : 2;
}

GLOBAL_ASM(
glabel func00018148
/*    18148:	27bdff30 */ 	addiu	$sp,$sp,-208
/*    1814c:	afa400d0 */ 	sw	$a0,0xd0($sp)
/*    18150:	afa500d4 */ 	sw	$a1,0xd4($sp)
/*    18154:	afbf003c */ 	sw	$ra,0x3c($sp)
/*    18158:	afbe0038 */ 	sw	$s8,0x38($sp)
/*    1815c:	afb70034 */ 	sw	$s7,0x34($sp)
/*    18160:	afb60030 */ 	sw	$s6,0x30($sp)
/*    18164:	afb5002c */ 	sw	$s5,0x2c($sp)
/*    18168:	afb40028 */ 	sw	$s4,0x28($sp)
/*    1816c:	afb30024 */ 	sw	$s3,0x24($sp)
/*    18170:	afb20020 */ 	sw	$s2,0x20($sp)
/*    18174:	afb1001c */ 	sw	$s1,0x1c($sp)
/*    18178:	afb00018 */ 	sw	$s0,0x18($sp)
/*    1817c:	afa700dc */ 	sw	$a3,0xdc($sp)
/*    18180:	27a5006c */ 	addiu	$a1,$sp,0x6c
/*    18184:	2404ffff */ 	addiu	$a0,$zero,-1
/*    18188:	27a8009c */ 	addiu	$t0,$sp,0x9c
/*    1818c:	27a2005c */ 	addiu	$v0,$sp,0x5c
/*    18190:	00c01825 */ 	or	$v1,$a2,$zero
.L00018194:
/*    18194:	846e0000 */ 	lh	$t6,0x0($v1)
/*    18198:	24420002 */ 	addiu	$v0,$v0,0x2
/*    1819c:	0045082b */ 	sltu	$at,$v0,$a1
/*    181a0:	a50e0000 */ 	sh	$t6,0x0($t0)
/*    181a4:	846f0000 */ 	lh	$t7,0x0($v1)
/*    181a8:	25080002 */ 	addiu	$t0,$t0,0x2
/*    181ac:	a44ffffe */ 	sh	$t7,-0x2($v0)
/*    181b0:	84780000 */ 	lh	$t8,0x0($v1)
/*    181b4:	14980003 */ 	bne	$a0,$t8,.L000181c4
/*    181b8:	00000000 */ 	nop
/*    181bc:	10000004 */ 	b	.L000181d0
/*    181c0:	0000b825 */ 	or	$s7,$zero,$zero
.L000181c4:
/*    181c4:	1420fff3 */ 	bnez	$at,.L00018194
/*    181c8:	24630002 */ 	addiu	$v1,$v1,0x2
/*    181cc:	0000b825 */ 	or	$s7,$zero,$zero
.L000181d0:
/*    181d0:	3c198006 */ 	lui	$t9,%hi(var8005ef20)
/*    181d4:	9339ef20 */ 	lbu	$t9,%lo(var8005ef20)($t9)
/*    181d8:	3c018006 */ 	lui	$at,%hi(var8005ef20)
/*    181dc:	27be007c */ 	addiu	$s8,$sp,0x7c
/*    181e0:	27290001 */ 	addiu	$t1,$t9,0x1
/*    181e4:	a029ef20 */ 	sb	$t1,%lo(var8005ef20)($at)
/*    181e8:	240100ff */ 	addiu	$at,$zero,0xff
/*    181ec:	312a00ff */ 	andi	$t2,$t1,0xff
/*    181f0:	15410010 */ 	bne	$t2,$at,.L00018234
/*    181f4:	3c14800a */ 	lui	$s4,%hi(g_BgPortals)
/*    181f8:	3c038008 */ 	lui	$v1,%hi(g_NumPortalThings)
/*    181fc:	8c63fc40 */ 	lw	$v1,%lo(g_NumPortalThings)($v1)
/*    18200:	3c0b800a */ 	lui	$t3,%hi(g_Vars+0x520)
/*    18204:	2562a4e0 */ 	addiu	$v0,$t3,%lo(g_Vars+0x520)
/*    18208:	18600008 */ 	blez	$v1,.L0001822c
/*    1820c:	00036040 */ 	sll	$t4,$v1,0x1
/*    18210:	01822821 */ 	addu	$a1,$t4,$v0
/*    18214:	240300ff */ 	addiu	$v1,$zero,0xff
.L00018218:
/*    18218:	24420002 */ 	addiu	$v0,$v0,0x2
/*    1821c:	0045082b */ 	sltu	$at,$v0,$a1
/*    18220:	1420fffd */ 	bnez	$at,.L00018218
/*    18224:	a043fffe */ 	sb	$v1,-0x2($v0)
/*    18228:	0000b825 */ 	or	$s7,$zero,$zero
.L0001822c:
/*    1822c:	3c018006 */ 	lui	$at,%hi(var8005ef20)
/*    18230:	a020ef20 */ 	sb	$zero,%lo(var8005ef20)($at)
.L00018234:
/*    18234:	26944cc8 */ 	addiu	$s4,$s4,%lo(g_BgPortals)
/*    18238:	87b5009c */ 	lh	$s5,0x9c($sp)
.L0001823c:
/*    1823c:	a7a4007c */ 	sh	$a0,0x7c($sp)
/*    18240:	00006840 */ 	sll	$t5,$zero,0x1
/*    18244:	12a40058 */ 	beq	$s5,$a0,.L000183a8
/*    18248:	27ae009c */ 	addiu	$t6,$sp,0x9c
/*    1824c:	01ae7821 */ 	addu	$t7,$t5,$t6
/*    18250:	afaf0044 */ 	sw	$t7,0x44($sp)
/*    18254:	0015c8c0 */ 	sll	$t9,$s5,0x3
.L00018258:
/*    18258:	0335c821 */ 	addu	$t9,$t9,$s5
/*    1825c:	3c18800a */ 	lui	$t8,%hi(g_Rooms)
/*    18260:	8f184928 */ 	lw	$t8,%lo(g_Rooms)($t8)
/*    18264:	0019c880 */ 	sll	$t9,$t9,0x2
/*    18268:	0335c823 */ 	subu	$t9,$t9,$s5
/*    1826c:	0019c880 */ 	sll	$t9,$t9,0x2
/*    18270:	03191021 */ 	addu	$v0,$t8,$t9
/*    18274:	8449000e */ 	lh	$t1,0xe($v0)
/*    18278:	80560005 */ 	lb	$s6,0x5($v0)
/*    1827c:	3c0c800a */ 	lui	$t4,%hi(g_RoomPortals)
/*    18280:	8d8c4ce0 */ 	lw	$t4,%lo(g_RoomPortals)($t4)
/*    18284:	00095040 */ 	sll	$t2,$t1,0x1
/*    18288:	1ac0003e */ 	blez	$s6,.L00018384
/*    1828c:	014c9821 */ 	addu	$s3,$t2,$t4
.L00018290:
/*    18290:	86720000 */ 	lh	$s2,0x0($s3)
/*    18294:	3c0d800a */ 	lui	$t5,%hi(g_Vars+0x520)
/*    18298:	25ada4e0 */ 	addiu	$t5,$t5,%lo(g_Vars+0x520)
/*    1829c:	00125840 */ 	sll	$t3,$s2,0x1
/*    182a0:	016d8821 */ 	addu	$s1,$t3,$t5
/*    182a4:	3c028006 */ 	lui	$v0,%hi(var8005ef20)
/*    182a8:	9042ef20 */ 	lbu	$v0,%lo(var8005ef20)($v0)
/*    182ac:	922e0000 */ 	lbu	$t6,0x0($s1)
/*    182b0:	02402025 */ 	or	$a0,$s2,$zero
/*    182b4:	504e0007 */ 	beql	$v0,$t6,.L000182d4
/*    182b8:	92230001 */ 	lbu	$v1,0x1($s1)
/*    182bc:	a2220000 */ 	sb	$v0,0x0($s1)
/*    182c0:	8fa500d0 */ 	lw	$a1,0xd0($sp)
/*    182c4:	0c005f8c */ 	jal	portal00017e30
/*    182c8:	8fa600d4 */ 	lw	$a2,0xd4($sp)
/*    182cc:	a2220001 */ 	sb	$v0,0x1($s1)
/*    182d0:	92230001 */ 	lbu	$v1,0x1($s1)
.L000182d4:
/*    182d4:	24010001 */ 	addiu	$at,$zero,0x1
/*    182d8:	50600026 */ 	beqzl	$v1,.L00018374
/*    182dc:	26f70001 */ 	addiu	$s7,$s7,0x1
/*    182e0:	54610012 */ 	bnel	$v1,$at,.L0001832c
/*    182e4:	24010002 */ 	addiu	$at,$zero,0x2
/*    182e8:	8e8f0000 */ 	lw	$t7,0x0($s4)
/*    182ec:	001280c0 */ 	sll	$s0,$s2,0x3
/*    182f0:	03c02025 */ 	or	$a0,$s8,$zero
/*    182f4:	01f01021 */ 	addu	$v0,$t7,$s0
/*    182f8:	84580002 */ 	lh	$t8,0x2($v0)
/*    182fc:	56b8000b */ 	bnel	$s5,$t8,.L0001832c
/*    18300:	24010002 */ 	addiu	$at,$zero,0x2
/*    18304:	0c005f71 */ 	jal	func00017dc4
/*    18308:	84450004 */ 	lh	$a1,0x4($v0)
/*    1830c:	8e990000 */ 	lw	$t9,0x0($s4)
/*    18310:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*    18314:	03304821 */ 	addu	$t1,$t9,$s0
/*    18318:	0c005f71 */ 	jal	func00017dc4
/*    1831c:	85250004 */ 	lh	$a1,0x4($t1)
/*    18320:	a2200001 */ 	sb	$zero,0x1($s1)
/*    18324:	300300ff */ 	andi	$v1,$zero,0xff
/*    18328:	24010002 */ 	addiu	$at,$zero,0x2
.L0001832c:
/*    1832c:	54610011 */ 	bnel	$v1,$at,.L00018374
/*    18330:	26f70001 */ 	addiu	$s7,$s7,0x1
/*    18334:	8e8a0000 */ 	lw	$t2,0x0($s4)
/*    18338:	001280c0 */ 	sll	$s0,$s2,0x3
/*    1833c:	03c02025 */ 	or	$a0,$s8,$zero
/*    18340:	01501021 */ 	addu	$v0,$t2,$s0
/*    18344:	844c0004 */ 	lh	$t4,0x4($v0)
/*    18348:	56ac000a */ 	bnel	$s5,$t4,.L00018374
/*    1834c:	26f70001 */ 	addiu	$s7,$s7,0x1
/*    18350:	0c005f71 */ 	jal	func00017dc4
/*    18354:	84450002 */ 	lh	$a1,0x2($v0)
/*    18358:	8e8b0000 */ 	lw	$t3,0x0($s4)
/*    1835c:	27a4005c */ 	addiu	$a0,$sp,0x5c
/*    18360:	01706821 */ 	addu	$t5,$t3,$s0
/*    18364:	0c005f71 */ 	jal	func00017dc4
/*    18368:	85a50002 */ 	lh	$a1,0x2($t5)
/*    1836c:	a2200001 */ 	sb	$zero,0x1($s1)
/*    18370:	26f70001 */ 	addiu	$s7,$s7,0x1
.L00018374:
/*    18374:	16f6ffc6 */ 	bne	$s7,$s6,.L00018290
/*    18378:	26730002 */ 	addiu	$s3,$s3,0x2
/*    1837c:	0000b825 */ 	or	$s7,$zero,$zero
/*    18380:	2404ffff */ 	addiu	$a0,$zero,-1
.L00018384:
/*    18384:	8fae0044 */ 	lw	$t6,0x44($sp)
/*    18388:	27b800bc */ 	addiu	$t8,$sp,0xbc
/*    1838c:	25cf0002 */ 	addiu	$t7,$t6,0x2
/*    18390:	afaf0044 */ 	sw	$t7,0x44($sp)
/*    18394:	85f50000 */ 	lh	$s5,0x0($t7)
/*    18398:	52a40004 */ 	beql	$s5,$a0,.L000183ac
/*    1839c:	87b9007c */ 	lh	$t9,0x7c($sp)
/*    183a0:	55f8ffad */ 	bnel	$t7,$t8,.L00018258
/*    183a4:	0015c8c0 */ 	sll	$t9,$s5,0x3
.L000183a8:
/*    183a8:	87b9007c */ 	lh	$t9,0x7c($sp)
.L000183ac:
/*    183ac:	27a8009c */ 	addiu	$t0,$sp,0x9c
/*    183b0:	27a3007c */ 	addiu	$v1,$sp,0x7c
/*    183b4:	5099000f */ 	beql	$a0,$t9,.L000183f4
/*    183b8:	87ac009c */ 	lh	$t4,0x9c($sp)
.L000183bc:
/*    183bc:	84620000 */ 	lh	$v0,0x0($v1)
/*    183c0:	24630002 */ 	addiu	$v1,$v1,0x2
/*    183c4:	27a9009c */ 	addiu	$t1,$sp,0x9c
/*    183c8:	14820003 */ 	bne	$a0,$v0,.L000183d8
/*    183cc:	a5020000 */ 	sh	$v0,0x0($t0)
/*    183d0:	10000004 */ 	b	.L000183e4
/*    183d4:	0000b825 */ 	or	$s7,$zero,$zero
.L000183d8:
/*    183d8:	1469fff8 */ 	bne	$v1,$t1,.L000183bc
/*    183dc:	25080002 */ 	addiu	$t0,$t0,0x2
/*    183e0:	0000b825 */ 	or	$s7,$zero,$zero
.L000183e4:
/*    183e4:	87aa007c */ 	lh	$t2,0x7c($sp)
/*    183e8:	548aff94 */ 	bnel	$a0,$t2,.L0001823c
/*    183ec:	87b5009c */ 	lh	$s5,0x9c($sp)
/*    183f0:	87ac009c */ 	lh	$t4,0x9c($sp)
.L000183f4:
/*    183f4:	27ab009c */ 	addiu	$t3,$sp,0x9c
/*    183f8:	8fad00dc */ 	lw	$t5,0xdc($sp)
/*    183fc:	508c0010 */ 	beql	$a0,$t4,.L00018440
/*    18400:	8fae00dc */ 	lw	$t6,0xdc($sp)
/*    18404:	00172040 */ 	sll	$a0,$s7,0x1
/*    18408:	008b4021 */ 	addu	$t0,$a0,$t3
/*    1840c:	01a41821 */ 	addu	$v1,$t5,$a0
/*    18410:	2404ffff */ 	addiu	$a0,$zero,-1
/*    18414:	85020000 */ 	lh	$v0,0x0($t0)
/*    18418:	26f70001 */ 	addiu	$s7,$s7,0x1
.L0001841c:
/*    1841c:	2ae10007 */ 	slti	$at,$s7,0x7
/*    18420:	25080002 */ 	addiu	$t0,$t0,0x2
/*    18424:	24630002 */ 	addiu	$v1,$v1,0x2
/*    18428:	10200004 */ 	beqz	$at,.L0001843c
/*    1842c:	a462fffe */ 	sh	$v0,-0x2($v1)
/*    18430:	85020000 */ 	lh	$v0,0x0($t0)
/*    18434:	5482fff9 */ 	bnel	$a0,$v0,.L0001841c
/*    18438:	26f70001 */ 	addiu	$s7,$s7,0x1
.L0001843c:
/*    1843c:	8fae00dc */ 	lw	$t6,0xdc($sp)
.L00018440:
/*    18440:	8fa600e0 */ 	lw	$a2,0xe0($sp)
/*    18444:	00177840 */ 	sll	$t7,$s7,0x1
/*    18448:	01cfc021 */ 	addu	$t8,$t6,$t7
/*    1844c:	10c00013 */ 	beqz	$a2,.L0001849c
/*    18450:	a7040000 */ 	sh	$a0,0x0($t8)
/*    18454:	8fa500e4 */ 	lw	$a1,0xe4($sp)
/*    18458:	0000b825 */ 	or	$s7,$zero,$zero
/*    1845c:	27a2005c */ 	addiu	$v0,$sp,0x5c
/*    18460:	18a0000b */ 	blez	$a1,.L00018490
/*    18464:	00c01825 */ 	or	$v1,$a2,$zero
/*    18468:	2404ffff */ 	addiu	$a0,$zero,-1
.L0001846c:
/*    1846c:	84590000 */ 	lh	$t9,0x0($v0)
/*    18470:	24420002 */ 	addiu	$v0,$v0,0x2
/*    18474:	a4790000 */ 	sh	$t9,0x0($v1)
/*    18478:	8449fffe */ 	lh	$t1,-0x2($v0)
/*    1847c:	50890005 */ 	beql	$a0,$t1,.L00018494
/*    18480:	00175040 */ 	sll	$t2,$s7,0x1
/*    18484:	26f70001 */ 	addiu	$s7,$s7,0x1
/*    18488:	16e5fff8 */ 	bne	$s7,$a1,.L0001846c
/*    1848c:	24630002 */ 	addiu	$v1,$v1,0x2
.L00018490:
/*    18490:	00175040 */ 	sll	$t2,$s7,0x1
.L00018494:
/*    18494:	00ca6021 */ 	addu	$t4,$a2,$t2
/*    18498:	a5840000 */ 	sh	$a0,0x0($t4)
.L0001849c:
/*    1849c:	8fbf003c */ 	lw	$ra,0x3c($sp)
/*    184a0:	8fb00018 */ 	lw	$s0,0x18($sp)
/*    184a4:	8fb1001c */ 	lw	$s1,0x1c($sp)
/*    184a8:	8fb20020 */ 	lw	$s2,0x20($sp)
/*    184ac:	8fb30024 */ 	lw	$s3,0x24($sp)
/*    184b0:	8fb40028 */ 	lw	$s4,0x28($sp)
/*    184b4:	8fb5002c */ 	lw	$s5,0x2c($sp)
/*    184b8:	8fb60030 */ 	lw	$s6,0x30($sp)
/*    184bc:	8fb70034 */ 	lw	$s7,0x34($sp)
/*    184c0:	8fbe0038 */ 	lw	$s8,0x38($sp)
/*    184c4:	03e00008 */ 	jr	$ra
/*    184c8:	27bd00d0 */ 	addiu	$sp,$sp,0xd0
);
