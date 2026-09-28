#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void get_collision_normal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ACD4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002ACD8: lwc1        $f4, -0x4F1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4F1C);
    // 0x8002ACDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002ACE0: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8002ACE4: lwc1        $f6, -0x4F18($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4F18);
    // 0x8002ACE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002ACEC: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x8002ACF0: lwc1        $f8, -0x4F14($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4F14);
    // 0x8002ACF4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002ACF8: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x8002ACFC: lw          $v0, -0x4F10($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4F10);
    // 0x8002AD00: jr          $ra
    // 0x8002AD04: nop

    return;
    // 0x8002AD04: nop

;}
RECOMP_FUNC void alCSeqTicksToSec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8380: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800C8384: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800C8388: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C838C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C8390: bgez        $a2, L_800C83A4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C8394: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800C83A4;
    }
    // 0x800C8394: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C8398: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C839C: nop

    // 0x800C83A0: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800C83A4:
    // 0x800C83A4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C83A8: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C83AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C83B0: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x800C83B4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800C83B8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800C83BC: bgez        $t7, L_800C83D0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C83C0: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800C83D0;
    }
    // 0x800C83C0: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C83C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C83C8: nop

    // 0x800C83CC: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_800C83D0:
    // 0x800C83D0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C83D4: ldc1        $f18, -0x6B48($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X6B48);
    // 0x800C83D8: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x800C83DC: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800C83E0: div.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x800C83E4: jr          $ra
    // 0x800C83E8: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    return;
    // 0x800C83E8: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
;}
RECOMP_FUNC void set_dialogue_box_unused_flag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C564C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5650: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5654: lw          $t6, -0x5818($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5818);
    // 0x800C5658: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C565C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C5660: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5664: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C5668: nop

    // 0x800C566C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x800C5670: jr          $ra
    // 0x800C5674: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C5674: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void mtxf_mul(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F768: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006F76C: sdc1        $f2, 0x0($sp)
    CHECK_FR(ctx, 2);
    SD(ctx->f2.u64, 0X0, ctx->r29);
    // 0x8006F770: ori         $t0, $zero, 0x4
    ctx->r8 = 0 | 0X4;
L_8006F774:
    // 0x8006F774: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006F778: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8006F77C: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006F780: lwc1        $f12, 0x10($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8006F784: mul.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006F788: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006F78C: lwc1        $f14, 0x20($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8006F790: mul.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006F794: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8006F798: lwc1        $f16, 0x30($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X30);
    // 0x8006F79C: mul.s       $f14, $f6, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006F7A0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8006F7A4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8006F7A8: mul.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8006F7AC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8006F7B0: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006F7B4: lwc1        $f12, 0x14($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8006F7B8: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006F7BC: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8006F7C0: mul.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006F7C4: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8006F7C8: lwc1        $f14, 0x24($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8006F7CC: mul.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006F7D0: lwc1        $f16, 0x34($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8006F7D4: swc1        $f18, -0x10($a2)
    MEM_W(-0X10, ctx->r6) = ctx->f18.u32l;
    // 0x8006F7D8: mul.s       $f14, $f6, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006F7DC: nop

    // 0x8006F7E0: mul.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8006F7E4: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006F7E8: lwc1        $f12, 0x18($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8006F7EC: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006F7F0: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8006F7F4: mul.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006F7F8: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8006F7FC: lwc1        $f14, 0x28($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8006F800: mul.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006F804: lwc1        $f16, 0x38($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X38);
    // 0x8006F808: swc1        $f18, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->f18.u32l;
    // 0x8006F80C: mul.s       $f14, $f6, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006F810: nop

    // 0x8006F814: mul.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8006F818: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006F81C: lwc1        $f12, 0x1C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8006F820: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006F824: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8006F828: mul.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006F82C: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8006F830: lwc1        $f14, 0x2C($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8006F834: mul.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006F838: lwc1        $f16, 0x3C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x8006F83C: swc1        $f18, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->f18.u32l;
    // 0x8006F840: mul.s       $f14, $f6, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006F844: nop

    // 0x8006F848: mul.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8006F84C: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006F850: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006F854: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8006F858: swc1        $f18, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f18.u32l;
    // 0x8006F85C: bnel        $t0, $zero, L_8006F774
    if (ctx->r8 != 0) {
        // 0x8006F860: nop
    
            goto L_8006F774;
    }
    goto skip_0;
    // 0x8006F860: nop

    skip_0:
    // 0x8006F864: ldc1        $f2, 0x0($sp)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r29, 0X0);
    // 0x8006F868: jr          $ra
    // 0x8006F86C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006F86C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void music_jingle_volume_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001B0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001B14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001B18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001B1C: jal         0x8000317C
    // 0x80001B20: sb          $a0, -0x39C4($at)
    MEM_B(-0X39C4, ctx->r1) = ctx->r4;
    sndp_get_global_volume(rdram, ctx);
        goto after_0;
    // 0x80001B20: sb          $a0, -0x39C4($at)
    MEM_B(-0X39C4, ctx->r1) = ctx->r4;
    after_0:
    // 0x80001B24: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80001B28: lbu         $t7, -0x39C4($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X39C4);
    // 0x80001B2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001B30: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001B34: lw          $a0, -0x39CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39CC);
    // 0x80001B38: mflo        $a1
    ctx->r5 = lo;
    // 0x80001B3C: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80001B40: jal         0x800C7850
    // 0x80001B44: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_1;
    // 0x80001B44: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    after_1:
    // 0x80001B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001B4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001B50: jr          $ra
    // 0x80001B54: nop

    return;
    // 0x80001B54: nop

;}
RECOMP_FUNC void leveltable_vehicle_default(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; if (dkr_legacy_track_menu(rdram, ctx, 10U, dkr_legacy_fields, 0U)) return; }
    // 0x8006B0AC: blez        $a0, L_8006B0EC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006B0B0: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006B0EC;
    }
    // 0x8006B0B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B0B4: lw          $t6, 0x1170($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1170);
    // 0x8006B0B8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006B0BC: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006B0C0: beq         $at, $zero, L_8006B0EC
    if (ctx->r1 == 0) {
        // 0x8006B0C4: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006B0EC;
    }
    // 0x8006B0C4: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006B0C8: lw          $t7, 0x117C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X117C);
    // 0x8006B0CC: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8006B0D0: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006B0D4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006B0D8: lb          $v0, 0x2($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X2);
    // 0x8006B0DC: nop

    // 0x8006B0E0: andi        $t0, $v0, 0xF
    ctx->r8 = ctx->r2 & 0XF;
    // 0x8006B0E4: jr          $ra
    // 0x8006B0E8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x8006B0E8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8006B0EC:
    // 0x8006B0EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006B0F0: jr          $ra
    // 0x8006B0F4: nop

    return;
    // 0x8006B0F4: nop

;}
RECOMP_FUNC void obj_init_bananacreator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D3EC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003D3F0: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8003D3F4: jr          $ra
    // 0x8003D3F8: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    return;
    // 0x8003D3F8: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void timetrial_ghost_read(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059E40: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80059E44: lb          $a1, -0x2A64($a1)
    ctx->r5 = MEM_B(ctx->r5, -0X2A64);
    // 0x80059E48: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80059E4C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80059E50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059E54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80059E58: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x80059E5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80059E60: jal         0x8001B3AC
    // 0x80059E64: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    timetrial_staff_ghost_check(rdram, ctx);
        goto after_0;
    // 0x80059E64: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80059E68: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80059E6C: beq         $v0, $zero, L_80059E78
    if (ctx->r2 == 0) {
        // 0x80059E70: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80059E78;
    }
    // 0x80059E70: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80059E74: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80059E78:
    // 0x80059E78: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x80059E7C: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80059E80: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80059E84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80059E88: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80059E8C: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x80059E90: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80059E94: bne         $t8, $zero, L_80059ED0
    if (ctx->r24 != 0) {
        // 0x80059E98: div.s       $f2, $f0, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
            goto L_80059ED0;
    }
    // 0x80059E98: div.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80059E9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80059EA0: bne         $a1, $at, L_80059ED0
    if (ctx->r5 != ctx->r1) {
        // 0x80059EA4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80059ED0;
    }
    // 0x80059EA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80059EA8: lwc1        $f11, 0x6930($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6930);
    // 0x80059EAC: lwc1        $f10, 0x6934($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6934);
    // 0x80059EB0: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80059EB4: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80059EB8: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x80059EBC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80059EC0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80059EC4: nop

    // 0x80059EC8: div.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80059ECC: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
L_80059ED0:
    // 0x80059ED0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80059ED4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80059ED8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80059EDC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059EE0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059EE4: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80059EE8: cvt.w.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80059EEC: lh          $t5, -0x2A60($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X2A60);
    // 0x80059EF0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80059EF4: addiu       $t7, $t5, -0x2
    ctx->r15 = ADD32(ctx->r13, -0X2);
    // 0x80059EF8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80059EFC: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80059F00: bne         $at, $zero, L_80059F10
    if (ctx->r1 != 0) {
        // 0x80059F04: sw          $v1, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r3;
            goto L_80059F10;
    }
    // 0x80059F04: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x80059F08: b           L_8005A3A0
    // 0x80059F0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A3A0;
    // 0x80059F0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80059F10:
    // 0x80059F10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80059F14: beq         $a1, $at, L_80059F5C
    if (ctx->r5 == ctx->r1) {
        // 0x80059F18: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_80059F5C;
    }
    // 0x80059F18: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80059F1C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80059F20: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80059F24: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x80059F28: jal         0x8006BD88
    // 0x80059F2C: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    level_id(rdram, ctx);
        goto after_1;
    // 0x80059F2C: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80059F30: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80059F34: lh          $t8, -0x2A54($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2A54);
    // 0x80059F38: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80059F3C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80059F40: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80059F44: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80059F48: beq         $v0, $t8, L_80059F5C
    if (ctx->r2 == ctx->r24) {
        // 0x80059F4C: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_80059F5C;
    }
    // 0x80059F4C: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80059F50: b           L_8005A3A0
    // 0x80059F54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A3A0;
    // 0x80059F54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80059F58: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
L_80059F5C:
    // 0x80059F5C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80059F60: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80059F64: addu        $ra, $ra, $t9
    ctx->r31 = ADD32(ctx->r31, ctx->r25);
    // 0x80059F68: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x80059F6C: lw          $ra, -0x2A70($ra)
    ctx->r31 = MEM_W(ctx->r31, -0X2A70);
    // 0x80059F70: subu        $t6, $t6, $t1
    ctx->r14 = SUB32(ctx->r14, ctx->r9);
    // 0x80059F74: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80059F78: addiu       $a3, $sp, 0x84
    ctx->r7 = ADD32(ctx->r29, 0X84);
    // 0x80059F7C: addiu       $t0, $sp, 0x74
    ctx->r8 = ADD32(ctx->r29, 0X74);
    // 0x80059F80: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x80059F84: addiu       $t4, $sp, 0x74
    ctx->r12 = ADD32(ctx->r29, 0X74);
    // 0x80059F88: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80059F8C: addu        $t2, $ra, $t6
    ctx->r10 = ADD32(ctx->r31, ctx->r14);
L_80059F90:
    // 0x80059F90: bne         $t1, $t3, L_80059FFC
    if (ctx->r9 != ctx->r11) {
        // 0x80059F94: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_80059FFC;
    }
    // 0x80059F94: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80059F98: lh          $v1, 0xC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XC);
    // 0x80059F9C: lh          $t8, 0x18($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X18);
    // 0x80059FA0: addu        $t7, $v1, $v1
    ctx->r15 = ADD32(ctx->r3, ctx->r3);
    // 0x80059FA4: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80059FA8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80059FAC: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80059FB0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80059FB4: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x80059FB8: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    // 0x80059FBC: lh          $t7, 0xE($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XE);
    // 0x80059FC0: addu        $t6, $a0, $a0
    ctx->r14 = ADD32(ctx->r4, ctx->r4);
    // 0x80059FC4: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80059FC8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80059FCC: nop

    // 0x80059FD0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80059FD4: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x80059FD8: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x80059FDC: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x80059FE0: addu        $t9, $a1, $a1
    ctx->r25 = ADD32(ctx->r5, ctx->r5);
    // 0x80059FE4: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x80059FE8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80059FEC: nop

    // 0x80059FF0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80059FF4: b           L_8005A0B4
    // 0x80059FF8: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
        goto L_8005A0B4;
    // 0x80059FF8: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
L_80059FFC:
    // 0x80059FFC: slt         $at, $t1, $t5
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8005A000: bne         $at, $zero, L_8005A06C
    if (ctx->r1 != 0) {
        // 0x8005A004: nop
    
            goto L_8005A06C;
    }
    // 0x8005A004: nop

    // 0x8005A008: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x8005A00C: lh          $t9, -0xC($v0)
    ctx->r25 = MEM_H(ctx->r2, -0XC);
    // 0x8005A010: addu        $t8, $v1, $v1
    ctx->r24 = ADD32(ctx->r3, ctx->r3);
    // 0x8005A014: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x8005A018: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8005A01C: nop

    // 0x8005A020: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005A024: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x8005A028: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    // 0x8005A02C: lh          $t8, -0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, -0XA);
    // 0x8005A030: addu        $t7, $a0, $a0
    ctx->r15 = ADD32(ctx->r4, ctx->r4);
    // 0x8005A034: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8005A038: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8005A03C: nop

    // 0x8005A040: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005A044: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x8005A048: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x8005A04C: lh          $t7, -0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X8);
    // 0x8005A050: addu        $t6, $a1, $a1
    ctx->r14 = ADD32(ctx->r5, ctx->r5);
    // 0x8005A054: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8005A058: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8005A05C: nop

    // 0x8005A060: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005A064: b           L_8005A0B4
    // 0x8005A068: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
        goto L_8005A0B4;
    // 0x8005A068: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
L_8005A06C:
    // 0x8005A06C: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8005A070: nop

    // 0x8005A074: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8005A078: nop

    // 0x8005A07C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005A080: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x8005A084: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x8005A088: nop

    // 0x8005A08C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8005A090: nop

    // 0x8005A094: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005A098: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x8005A09C: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8005A0A0: nop

    // 0x8005A0A4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8005A0A8: nop

    // 0x8005A0AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005A0B0: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
L_8005A0B4:
    // 0x8005A0B4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8005A0B8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8005A0BC: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8005A0C0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8005A0C4: bne         $a2, $t4, L_80059F90
    if (ctx->r6 != ctx->r12) {
        // 0x8005A0C8: addiu       $t2, $t2, 0xC
        ctx->r10 = ADD32(ctx->r10, 0XC);
            goto L_80059F90;
    }
    // 0x8005A0C8: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8005A0CC: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8005A0D0: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x8005A0D4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8005A0D8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005A0DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005A0E0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8005A0E4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005A0E8: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8005A0EC: addu        $v0, $ra, $t9
    ctx->r2 = ADD32(ctx->r31, ctx->r25);
    // 0x8005A0F0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8005A0F4: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8005A0F8: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    // 0x8005A0FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005A100: jal         0x80022540
    // 0x8005A104: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    catmull_rom_interpolation(rdram, ctx);
        goto after_2;
    // 0x8005A104: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    after_2:
    // 0x8005A108: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005A10C: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8005A110: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8005A114: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x8005A118: jal         0x80022540
    // 0x8005A11C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_3;
    // 0x8005A11C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8005A120: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005A124: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8005A128: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8005A12C: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8005A130: jal         0x80022540
    // 0x8005A134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_4;
    // 0x8005A134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8005A138: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8005A13C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8005A140: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005A144: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x8005A148: lh          $a0, 0xA($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XA);
    // 0x8005A14C: addiu       $a2, $v0, 0xC
    ctx->r6 = ADD32(ctx->r2, 0XC);
    // 0x8005A150: lh          $t6, 0xA($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XA);
    // 0x8005A154: andi        $t7, $a0, 0xFFFF
    ctx->r15 = ctx->r4 & 0XFFFF;
    // 0x8005A158: ori         $a3, $zero, 0x8001
    ctx->r7 = 0 | 0X8001;
    // 0x8005A15C: subu        $v1, $t6, $t7
    ctx->r3 = SUB32(ctx->r14, ctx->r15);
    // 0x8005A160: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8005A164: bne         $at, $zero, L_8005A174
    if (ctx->r1 != 0) {
        // 0x8005A168: lui         $t0, 0xFFFF
        ctx->r8 = S32(0XFFFF << 16);
            goto L_8005A174;
    }
    // 0x8005A168: lui         $t0, 0xFFFF
    ctx->r8 = S32(0XFFFF << 16);
    // 0x8005A16C: ori         $t0, $t0, 0x1
    ctx->r8 = ctx->r8 | 0X1;
    // 0x8005A170: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
L_8005A174:
    // 0x8005A174: lui         $t0, 0xFFFF
    ctx->r8 = S32(0XFFFF << 16);
    // 0x8005A178: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005A17C: beq         $at, $zero, L_8005A18C
    if (ctx->r1 == 0) {
        // 0x8005A180: ori         $t0, $t0, 0x1
        ctx->r8 = ctx->r8 | 0X1;
            goto L_8005A18C;
    }
    // 0x8005A180: ori         $t0, $t0, 0x1
    ctx->r8 = ctx->r8 | 0X1;
    // 0x8005A184: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x8005A188: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
L_8005A18C:
    // 0x8005A18C: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x8005A190: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x8005A194: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005A198: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8005A19C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8005A1A0: nop

    // 0x8005A1A4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8005A1A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005A1AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005A1B0: nop

    // 0x8005A1B4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8005A1B8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8005A1BC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8005A1C0: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x8005A1C4: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x8005A1C8: lh          $a1, 0x8($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X8);
    // 0x8005A1CC: lh          $t8, 0x8($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X8);
    // 0x8005A1D0: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x8005A1D4: subu        $v1, $t8, $t6
    ctx->r3 = SUB32(ctx->r24, ctx->r14);
    // 0x8005A1D8: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8005A1DC: bne         $at, $zero, L_8005A1EC
    if (ctx->r1 != 0) {
        // 0x8005A1E0: slti        $at, $v1, -0x8000
        ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
            goto L_8005A1EC;
    }
    // 0x8005A1E0: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005A1E4: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8005A1E8: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
L_8005A1EC:
    // 0x8005A1EC: beq         $at, $zero, L_8005A1F8
    if (ctx->r1 == 0) {
        // 0x8005A1F0: nop
    
            goto L_8005A1F8;
    }
    // 0x8005A1F0: nop

    // 0x8005A1F4: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
L_8005A1F8:
    // 0x8005A1F8: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8005A1FC: nop

    // 0x8005A200: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005A204: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8005A208: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005A20C: nop

    // 0x8005A210: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8005A214: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005A218: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005A21C: nop

    // 0x8005A220: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8005A224: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8005A228: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005A22C: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8005A230: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8005A234: lh          $a0, 0x6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X6);
    // 0x8005A238: lh          $t9, 0x6($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X6);
    // 0x8005A23C: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x8005A240: subu        $v1, $t9, $t8
    ctx->r3 = SUB32(ctx->r25, ctx->r24);
    // 0x8005A244: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8005A248: bne         $at, $zero, L_8005A258
    if (ctx->r1 != 0) {
        // 0x8005A24C: slti        $at, $v1, -0x8000
        ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
            goto L_8005A258;
    }
    // 0x8005A24C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005A250: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8005A254: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
L_8005A258:
    // 0x8005A258: beq         $at, $zero, L_8005A264
    if (ctx->r1 == 0) {
        // 0x8005A25C: nop
    
            goto L_8005A264;
    }
    // 0x8005A25C: nop

    // 0x8005A260: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
L_8005A264:
    // 0x8005A264: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8005A268: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005A26C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005A270: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005A274: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8005A278: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8005A27C: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x8005A280: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8005A284: nop

    // 0x8005A288: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8005A28C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005A290: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005A294: nop

    // 0x8005A298: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8005A29C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8005A2A0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005A2A4: addu        $t6, $a0, $t8
    ctx->r14 = ADD32(ctx->r4, ctx->r24);
    // 0x8005A2A8: sh          $t6, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r14;
    // 0x8005A2AC: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    // 0x8005A2B0: jal         0x80029F18
    // 0x8005A2B4: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_5;
    // 0x8005A2B4: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    after_5:
    // 0x8005A2B8: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8005A2BC: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005A2C0: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // 0x8005A2C4: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8005A2C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A2CC: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x8005A2D0: bne         $t5, $t9, L_8005A3A0
    if (ctx->r13 != ctx->r25) {
        // 0x8005A2D4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005A3A0;
    }
    // 0x8005A2D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A2D8: lwc1        $f13, 0x6938($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, 0X6938);
    // 0x8005A2DC: lwc1        $f12, 0x693C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X693C);
    // 0x8005A2E0: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8005A2E4: c.le.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d <= ctx->f0.d;
    // 0x8005A2E8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8005A2EC: bc1f        L_8005A2FC
    if (!c1cs) {
        // 0x8005A2F0: lui         $at, 0x4058
        ctx->r1 = S32(0X4058 << 16);
            goto L_8005A2FC;
    }
    // 0x8005A2F0: lui         $at, 0x4058
    ctx->r1 = S32(0X4058 << 16);
    // 0x8005A2F4: b           L_8005A39C
    // 0x8005A2F8: sb          $zero, 0x1F7($v0)
    MEM_B(0X1F7, ctx->r2) = 0;
        goto L_8005A39C;
    // 0x8005A2F8: sb          $zero, 0x1F7($v0)
    MEM_B(0X1F7, ctx->r2) = 0;
L_8005A2FC:
    // 0x8005A2FC: sub.d       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f12.d - ctx->f0.d;
    // 0x8005A300: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005A304: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005A308: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005A30C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8005A310: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8005A314: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8005A318: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005A31C: nop

    // 0x8005A320: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x8005A324: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8005A328: nop

    // 0x8005A32C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8005A330: beq         $t6, $zero, L_8005A380
    if (ctx->r14 == 0) {
        // 0x8005A334: nop
    
            goto L_8005A380;
    }
    // 0x8005A334: nop

    // 0x8005A338: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005A33C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005A340: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005A344: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x8005A348: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005A34C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005A350: nop

    // 0x8005A354: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x8005A358: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8005A35C: nop

    // 0x8005A360: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x8005A364: bne         $t6, $zero, L_8005A378
    if (ctx->r14 != 0) {
        // 0x8005A368: nop
    
            goto L_8005A378;
    }
    // 0x8005A368: nop

    // 0x8005A36C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8005A370: b           L_8005A390
    // 0x8005A374: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_8005A390;
    // 0x8005A374: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_8005A378:
    // 0x8005A378: b           L_8005A390
    // 0x8005A37C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8005A390;
    // 0x8005A37C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_8005A380:
    // 0x8005A380: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8005A384: nop

    // 0x8005A388: bltz        $t6, L_8005A378
    if (SIGNED(ctx->r14) < 0) {
        // 0x8005A38C: nop
    
            goto L_8005A378;
    }
    // 0x8005A38C: nop

L_8005A390:
    // 0x8005A390: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8005A394: sb          $t6, 0x1F7($v0)
    MEM_B(0X1F7, ctx->r2) = ctx->r14;
    // 0x8005A398: nop

L_8005A39C:
    // 0x8005A39C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A3A0:
    // 0x8005A3A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A3A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005A3A8: jr          $ra
    // 0x8005A3AC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8005A3AC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void gfxtask_wait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077A54: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80077A58: lw          $t6, -0x1B24($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1B24);
    // 0x80077A5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80077A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077A64: bne         $t6, $zero, L_80077A74
    if (ctx->r14 != 0) {
        // 0x80077A68: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_80077A74;
    }
    // 0x80077A68: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80077A6C: b           L_80077A9C
    // 0x80077A70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80077A9C;
    // 0x80077A70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80077A74:
    // 0x80077A74: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077A78: addiu       $a0, $a0, 0x5ED8
    ctx->r4 = ADD32(ctx->r4, 0X5ED8);
    // 0x80077A7C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80077A80: jal         0x800C8BB0
    // 0x80077A84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80077A84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80077A88: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80077A8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80077A90: sw          $zero, -0x1B24($at)
    MEM_W(-0X1B24, ctx->r1) = 0;
    // 0x80077A94: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
    // 0x80077A98: nop

L_80077A9C:
    // 0x80077A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077AA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80077AA4: jr          $ra
    // 0x80077AA8: nop

    return;
    // 0x80077AA8: nop

;}
RECOMP_FUNC void guMtxIdent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D49C8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800D49CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D49D0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800D49D4: jal         0x800D4940
    // 0x800D49D8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800D49D8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800D49DC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800D49E0: jal         0x800D4840
    // 0x800D49E4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800D49E4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x800D49E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D49EC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800D49F0: jr          $ra
    // 0x800D49F4: nop

    return;
    // 0x800D49F4: nop

;}
RECOMP_FUNC void charselect_music_channels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_character_select_animation_tick(uint8_t*, recomp_context*); dkr_character_select_animation_tick(rdram, ctx);
    // 0x8008C168: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008C16C: addiu       $a1, $a1, 0x63C0
    ctx->r5 = ADD32(ctx->r5, 0X63C0);
    // 0x8008C170: lb          $v0, 0x1($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1);
    // 0x8008C174: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008C178: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008C17C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008C180: blez        $v0, L_8008C260
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008C184: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8008C260;
    }
    // 0x8008C184: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008C188: subu        $t7, $v0, $a0
    ctx->r15 = SUB32(ctx->r2, ctx->r4);
    // 0x8008C18C: sb          $t7, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r15;
    // 0x8008C190: lb          $t8, 0x1($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X1);
    // 0x8008C194: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008C198: bgtz        $t8, L_8008C260
    if (SIGNED(ctx->r24) > 0) {
        // 0x8008C19C: addiu       $s0, $s0, 0x63B8
        ctx->r16 = ADD32(ctx->r16, 0X63B8);
            goto L_8008C260;
    }
    // 0x8008C19C: addiu       $s0, $s0, 0x63B8
    ctx->r16 = ADD32(ctx->r16, 0X63B8);
    // 0x8008C1A0: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8008C1A4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C1A8: bltz        $v0, L_8008C1E4
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008C1AC: sll         $t9, $v0, 1
        ctx->r25 = S32(ctx->r2 << 1);
            goto L_8008C1E4;
    }
    // 0x8008C1AC: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x8008C1B0: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8008C1B4: lbu         $a0, -0x24C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X24C);
    // 0x8008C1B8: jal         0x80001114
    // 0x8008C1BC: nop

    music_channel_off(rdram, ctx);
        goto after_0;
    // 0x8008C1BC: nop

    after_0:
    // 0x8008C1C0: lb          $t0, 0x0($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X0);
    // 0x8008C1C4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C1C8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8008C1CC: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8008C1D0: lbu         $a0, -0x24B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X24B);
    // 0x8008C1D4: jal         0x80001114
    // 0x8008C1D8: nop

    music_channel_off(rdram, ctx);
        goto after_1;
    // 0x8008C1D8: nop

    after_1:
    // 0x8008C1DC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008C1E0: addiu       $a1, $a1, 0x63C0
    ctx->r5 = ADD32(ctx->r5, 0X63C0);
L_8008C1E4:
    // 0x8008C1E4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C1E8: addiu       $v1, $v1, 0x63B4
    ctx->r3 = ADD32(ctx->r3, 0X63B4);
    // 0x8008C1EC: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8008C1F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C1F4: bltz        $v0, L_8008C208
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008C1F8: sb          $v0, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r2;
            goto L_8008C208;
    }
    // 0x8008C1F8: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x8008C1FC: lh          $t2, 0x2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2);
    // 0x8008C200: nop

    // 0x8008C204: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
L_8008C208:
    // 0x8008C208: lb          $t3, 0x0($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X0);
    // 0x8008C20C: nop

    // 0x8008C210: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x8008C214: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8008C218: nop

    // 0x8008C21C: bltz        $v0, L_8008C260
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008C220: sll         $t5, $v0, 1
        ctx->r13 = S32(ctx->r2 << 1);
            goto L_8008C260;
    }
    // 0x8008C220: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x8008C224: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x8008C228: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x8008C22C: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
    // 0x8008C230: lbu         $a0, -0x24C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X24C);
    // 0x8008C234: jal         0x80001170
    // 0x8008C238: nop

    music_channel_on(rdram, ctx);
        goto after_2;
    // 0x8008C238: nop

    after_2:
    // 0x8008C23C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C240: addiu       $v1, $v1, 0x63B4
    ctx->r3 = ADD32(ctx->r3, 0X63B4);
    // 0x8008C244: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x8008C248: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C24C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8008C250: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8008C254: lbu         $a0, -0x24B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X24B);
    // 0x8008C258: jal         0x80001170
    // 0x8008C25C: nop

    music_channel_on(rdram, ctx);
        goto after_3;
    // 0x8008C25C: nop

    after_3:
L_8008C260:
    // 0x8008C260: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C264: addiu       $v1, $v1, 0x63B4
    ctx->r3 = ADD32(ctx->r3, 0X63B4);
    // 0x8008C268: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8008C26C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008C270: bltz        $v0, L_8008C2F0
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008C274: addiu       $s0, $s0, 0x63B8
        ctx->r16 = ADD32(ctx->r16, 0X63B8);
            goto L_8008C2F0;
    }
    // 0x8008C274: addiu       $s0, $s0, 0x63B8
    ctx->r16 = ADD32(ctx->r16, 0X63B8);
    // 0x8008C278: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8008C27C: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x8008C280: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8008C284: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8008C288: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x8008C28C: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    // 0x8008C290: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x8008C294: slti        $at, $a2, 0x80
    ctx->r1 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // 0x8008C298: bne         $at, $zero, L_8008C2B0
    if (ctx->r1 != 0) {
        // 0x8008C29C: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008C2B0;
    }
    // 0x8008C29C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C2A0: addiu       $t2, $zero, 0x7F
    ctx->r10 = ADD32(0, 0X7F);
    // 0x8008C2A4: sh          $t2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r10;
    // 0x8008C2A8: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    // 0x8008C2AC: nop

L_8008C2B0:
    // 0x8008C2B0: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8008C2B4: lbu         $a0, -0x24C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X24C);
    // 0x8008C2B8: jal         0x80001268
    // 0x8008C2BC: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_4;
    // 0x8008C2BC: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    after_4:
    // 0x8008C2C0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C2C4: addiu       $v1, $v1, 0x63B4
    ctx->r3 = ADD32(ctx->r3, 0X63B4);
    // 0x8008C2C8: lb          $t4, 0x0($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X0);
    // 0x8008C2CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C2D0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8008C2D4: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x8008C2D8: lbu         $a0, -0x24B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X24B);
    // 0x8008C2DC: lbu         $a1, 0x3($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X3);
    // 0x8008C2E0: jal         0x80001268
    // 0x8008C2E4: nop

    music_channel_fade_set(rdram, ctx);
        goto after_5;
    // 0x8008C2E4: nop

    after_5:
    // 0x8008C2E8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C2EC: addiu       $v1, $v1, 0x63B4
    ctx->r3 = ADD32(ctx->r3, 0X63B4);
L_8008C2F0:
    // 0x8008C2F0: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8008C2F4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008C2F8: bltz        $v0, L_8008C3A4
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008C2FC: sll         $t9, $t7, 2
        ctx->r25 = S32(ctx->r15 << 2);
            goto L_8008C3A4;
    }
    // 0x8008C2FC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8008C300: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x8008C304: lb          $t0, 0x0($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X0);
    // 0x8008C308: subu        $t8, $t6, $t9
    ctx->r24 = SUB32(ctx->r14, ctx->r25);
    // 0x8008C30C: beq         $t0, $v0, L_8008C390
    if (ctx->r8 == ctx->r2) {
        // 0x8008C310: sh          $t8, 0x2($s0)
        MEM_H(0X2, ctx->r16) = ctx->r24;
            goto L_8008C390;
    }
    // 0x8008C310: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x8008C314: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x8008C318: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x8008C31C: bgez        $v1, L_8008C360
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8008C320: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008C360;
    }
    // 0x8008C320: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C324: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    // 0x8008C328: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C32C: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8008C330: lbu         $a0, -0x24C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X24C);
    // 0x8008C334: jal         0x80001114
    // 0x8008C338: nop

    music_channel_off(rdram, ctx);
        goto after_6;
    // 0x8008C338: nop

    after_6:
    // 0x8008C33C: lb          $t2, 0x0($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X0);
    // 0x8008C340: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C344: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8008C348: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8008C34C: lbu         $a0, -0x24B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X24B);
    // 0x8008C350: jal         0x80001114
    // 0x8008C354: nop

    music_channel_off(rdram, ctx);
        goto after_7;
    // 0x8008C354: nop

    after_7:
    // 0x8008C358: b           L_8008C394
    // 0x8008C35C: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
        goto L_8008C394;
    // 0x8008C35C: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
L_8008C360:
    // 0x8008C360: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x8008C364: lbu         $a0, -0x24C($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X24C);
    // 0x8008C368: jal         0x80001268
    // 0x8008C36C: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_8;
    // 0x8008C36C: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    after_8:
    // 0x8008C370: lb          $t5, 0x0($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X0);
    // 0x8008C374: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C378: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x8008C37C: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8008C380: lbu         $a0, -0x24B($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X24B);
    // 0x8008C384: lbu         $a1, 0x3($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X3);
    // 0x8008C388: jal         0x80001268
    // 0x8008C38C: nop

    music_channel_fade_set(rdram, ctx);
        goto after_9;
    // 0x8008C38C: nop

    after_9:
L_8008C390:
    // 0x8008C390: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
L_8008C394:
    // 0x8008C394: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8008C398: bgez        $t6, L_8008C3A8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8008C39C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008C3A8;
    }
    // 0x8008C39C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C3A0: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
L_8008C3A4:
    // 0x8008C3A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008C3A8:
    // 0x8008C3A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008C3AC: jr          $ra
    // 0x8008C3B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8008C3B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void aitable_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C18C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006C190: lw          $v0, 0x11C0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X11C0);
    // 0x8006C194: jr          $ra
    // 0x8006C198: nop

    return;
    // 0x8006C198: nop

;}
RECOMP_FUNC void level_global_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A6B0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8006A6B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006A6B8: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006A6BC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006A6C0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006A6C4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006A6C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006A6CC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006A6D0: jal         0x80070C9C
    // 0x8006A6D4: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8006A6D4: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    after_0:
    // 0x8006A6D8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8006A6DC: jal         0x80076C58
    // 0x8006A6E0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    asset_table_load(rdram, ctx);
        goto after_1;
    // 0x8006A6E0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_1:
    // 0x8006A6E4: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8006A6E8: addiu       $s3, $s3, 0x1160
    ctx->r19 = ADD32(ctx->r19, 0X1160);
    // 0x8006A6EC: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8006A6F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A6F4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006A6F8: addiu       $v1, $v1, 0x1180
    ctx->r3 = ADD32(ctx->r3, 0X1180);
    // 0x8006A6FC: addiu       $v0, $v0, 0x11C0
    ctx->r2 = ADD32(ctx->r2, 0X11C0);
L_8006A700:
    // 0x8006A700: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8006A704: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x8006A708: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x8006A70C: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x8006A710: bne         $v1, $v0, L_8006A700
    if (ctx->r3 != ctx->r2) {
        // 0x8006A714: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_8006A700;
    }
    // 0x8006A714: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8006A718: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8006A71C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006A720: addiu       $t2, $t2, 0x1170
    ctx->r10 = ADD32(ctx->r10, 0X1170);
    // 0x8006A724: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x8006A728: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x8006A72C: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8006A730: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8006A734: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8006A738: beq         $t3, $t8, L_8006A760
    if (ctx->r11 == ctx->r24) {
        // 0x8006A73C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8006A760;
    }
    // 0x8006A73C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006A740: addiu       $t9, $a2, 0x1
    ctx->r25 = ADD32(ctx->r6, 0X1);
L_8006A744:
    // 0x8006A744: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x8006A748: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x8006A74C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8006A750: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8006A754: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8006A758: bne         $t3, $t6, L_8006A744
    if (ctx->r11 != ctx->r14) {
        // 0x8006A75C: addiu       $t9, $a2, 0x1
        ctx->r25 = ADD32(ctx->r6, 0X1);
            goto L_8006A744;
    }
    // 0x8006A75C: addiu       $t9, $a2, 0x1
    ctx->r25 = ADD32(ctx->r6, 0X1);
L_8006A760:
    // 0x8006A760: addiu       $t7, $a2, -0x1
    ctx->r15 = ADD32(ctx->r6, -0X1);
    // 0x8006A764: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006A768: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8006A76C: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006A770: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8006A774: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006A778: jal         0x80070C9C
    // 0x8006A77C: sll         $a0, $t8, 1
    ctx->r4 = S32(ctx->r24 << 1);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x8006A77C: sll         $a0, $t8, 1
    ctx->r4 = S32(ctx->r24 << 1);
    after_2:
    // 0x8006A780: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006A784: addiu       $t2, $t2, 0x1170
    ctx->r10 = ADD32(ctx->r10, 0X1170);
    // 0x8006A788: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8006A78C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8006A790: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006A794: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006A798: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006A79C: addiu       $s0, $s0, 0x1168
    ctx->r16 = ADD32(ctx->r16, 0X1168);
    // 0x8006A7A0: addiu       $t1, $t1, 0x1174
    ctx->r9 = ADD32(ctx->r9, 0X1174);
    // 0x8006A7A4: addiu       $t0, $t0, 0x117C
    ctx->r8 = ADD32(ctx->r8, 0X117C);
    // 0x8006A7A8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8006A7AC: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8006A7B0: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8006A7B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006A7B8: blez        $t4, L_8006A8E8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8006A7BC: sw          $t9, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r25;
            goto L_8006A8E8;
    }
    // 0x8006A7BC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8006A7C0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8006A7C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8006A7C8:
    // 0x8006A7C8: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x8006A7CC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8006A7D0: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x8006A7D4: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x8006A7D8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8006A7DC: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x8006A7E0: jal         0x80076E68
    // 0x8006A7E4: addiu       $a3, $zero, 0xC4
    ctx->r7 = ADD32(0, 0XC4);
    asset_load(rdram, ctx);
        goto after_3;
    // 0x8006A7E4: addiu       $a3, $zero, 0xC4
    ctx->r7 = ADD32(0, 0XC4);
    after_3:
    // 0x8006A7E8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8006A7EC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006A7F0: addiu       $t1, $t1, 0x1174
    ctx->r9 = ADD32(ctx->r9, 0X1174);
    // 0x8006A7F4: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8006A7F8: lb          $a0, 0x0($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X0);
    // 0x8006A7FC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8006A800: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006A804: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006A808: slt         $at, $t7, $a0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8006A80C: addiu       $t2, $t2, 0x1170
    ctx->r10 = ADD32(ctx->r10, 0X1170);
    // 0x8006A810: beq         $at, $zero, L_8006A81C
    if (ctx->r1 == 0) {
        // 0x8006A814: addiu       $t0, $t0, 0x117C
        ctx->r8 = ADD32(ctx->r8, 0X117C);
            goto L_8006A81C;
    }
    // 0x8006A814: addiu       $t0, $t0, 0x117C
    ctx->r8 = ADD32(ctx->r8, 0X117C);
    // 0x8006A818: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
L_8006A81C:
    // 0x8006A81C: lb          $a0, 0x4C($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X4C);
    // 0x8006A820: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006A824: bltz        $a0, L_8006A850
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006A828: slti        $at, $a0, 0x10
        ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
            goto L_8006A850;
    }
    // 0x8006A828: slti        $at, $a0, 0x10
    ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x8006A82C: beq         $at, $zero, L_8006A850
    if (ctx->r1 == 0) {
        // 0x8006A830: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006A850;
    }
    // 0x8006A830: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006A834: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006A838: addiu       $t9, $t9, 0x1180
    ctx->r25 = ADD32(ctx->r25, 0X1180);
    // 0x8006A83C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8006A840: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8006A844: nop

    // 0x8006A848: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8006A84C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8006A850:
    // 0x8006A850: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8006A854: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x8006A858: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006A85C: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x8006A860: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8006A864: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8006A868: lb          $t4, 0x4C($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X4C);
    // 0x8006A86C: addu        $t7, $t5, $v1
    ctx->r15 = ADD32(ctx->r13, ctx->r3);
    // 0x8006A870: sb          $t4, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r12;
    // 0x8006A874: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8006A878: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8006A87C: lb          $t9, 0x4E($t6)
    ctx->r25 = MEM_B(ctx->r14, 0X4E);
    // 0x8006A880: addu        $t7, $t4, $v1
    ctx->r15 = ADD32(ctx->r12, ctx->r3);
    // 0x8006A884: sll         $t5, $t9, 4
    ctx->r13 = S32(ctx->r25 << 4);
    // 0x8006A888: sb          $t5, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r13;
    // 0x8006A88C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8006A890: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8006A894: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8006A898: lb          $t4, 0x4D($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X4D);
    // 0x8006A89C: lb          $t8, 0x2($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X2);
    // 0x8006A8A0: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x8006A8A4: or          $t7, $t8, $t5
    ctx->r15 = ctx->r24 | ctx->r13;
    // 0x8006A8A8: sb          $t7, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r15;
    // 0x8006A8AC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8006A8B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006A8B4: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x8006A8B8: sb          $t6, 0x3($t4)
    MEM_B(0X3, ctx->r12) = ctx->r14;
    // 0x8006A8BC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8006A8C0: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8006A8C4: lh          $t5, 0xB0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0XB0);
    // 0x8006A8C8: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x8006A8CC: sh          $t5, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r13;
    // 0x8006A8D0: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8006A8D4: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006A8D8: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006A8DC: bne         $at, $zero, L_8006A7C8
    if (ctx->r1 != 0) {
        // 0x8006A8E0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8006A7C8;
    }
    // 0x8006A8E0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8006A8E4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8006A8E8:
    // 0x8006A8E8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8006A8EC: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006A8F0: addiu       $a0, $t4, 0x1
    ctx->r4 = ADD32(ctx->r12, 0X1);
    // 0x8006A8F4: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
    // 0x8006A8F8: jal         0x80070C9C
    // 0x8006A8FC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x8006A8FC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_4:
    // 0x8006A900: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006A904: addiu       $t1, $t1, 0x1174
    ctx->r9 = ADD32(ctx->r9, 0X1174);
    // 0x8006A908: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8006A90C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A910: addiu       $a0, $a0, 0x1178
    ctx->r4 = ADD32(ctx->r4, 0X1178);
    // 0x8006A914: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006A918: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006A91C: addiu       $t2, $t2, 0x1170
    ctx->r10 = ADD32(ctx->r10, 0X1170);
    // 0x8006A920: addiu       $t0, $t0, 0x117C
    ctx->r8 = ADD32(ctx->r8, 0X117C);
    // 0x8006A924: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8006A928: blez        $t7, L_8006A958
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8006A92C: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_8006A958;
    }
    // 0x8006A92C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_8006A930:
    // 0x8006A930: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8006A934: nop

    // 0x8006A938: addu        $t9, $t5, $s1
    ctx->r25 = ADD32(ctx->r13, ctx->r17);
    // 0x8006A93C: sb          $t3, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r11;
    // 0x8006A940: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8006A944: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006A948: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006A94C: bne         $at, $zero, L_8006A930
    if (ctx->r1 != 0) {
        // 0x8006A950: nop
    
            goto L_8006A930;
    }
    // 0x8006A950: nop

    // 0x8006A954: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8006A958:
    // 0x8006A958: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x8006A95C: nop

    // 0x8006A960: blez        $a2, L_8006A9B8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8006A964: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006A9B8;
    }
    // 0x8006A964: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006A968: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_8006A96C:
    // 0x8006A96C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8006A970: nop

    // 0x8006A974: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x8006A978: lb          $t8, 0x1($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1);
    // 0x8006A97C: nop

    // 0x8006A980: bne         $a1, $t8, L_8006A9A4
    if (ctx->r5 != ctx->r24) {
        // 0x8006A984: nop
    
            goto L_8006A9A4;
    }
    // 0x8006A984: nop

    // 0x8006A988: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8006A98C: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x8006A990: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006A994: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x8006A998: sb          $s1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r17;
    // 0x8006A99C: lw          $a2, 0x1170($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1170);
    // 0x8006A9A0: nop

L_8006A9A4:
    // 0x8006A9A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006A9A8: slt         $at, $s1, $a2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8006A9AC: bne         $at, $zero, L_8006A96C
    if (ctx->r1 != 0) {
        // 0x8006A9B0: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006A96C;
    }
    // 0x8006A9B0: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006A9B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8006A9B8:
    // 0x8006A9B8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8006A9BC: jal         0x80071140
    // 0x8006A9C0: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x8006A9C0: nop

    after_5:
    // 0x8006A9C4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8006A9C8: jal         0x80071140
    // 0x8006A9CC: nop

    mempool_free(rdram, ctx);
        goto after_6;
    // 0x8006A9CC: nop

    after_6:
    // 0x8006A9D0: jal         0x80076C58
    // 0x8006A9D4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    asset_table_load(rdram, ctx);
        goto after_7;
    // 0x8006A9D4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_7:
    // 0x8006A9D8: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8006A9DC: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8006A9E0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8006A9E4: beq         $t3, $a2, L_8006A9FC
    if (ctx->r11 == ctx->r6) {
        // 0x8006A9E8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8006A9FC;
    }
    // 0x8006A9E8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8006A9EC:
    // 0x8006A9EC: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8006A9F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006A9F4: bne         $t3, $t6, L_8006A9EC
    if (ctx->r11 != ctx->r14) {
        // 0x8006A9F8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8006A9EC;
    }
    // 0x8006A9F8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8006A9FC:
    // 0x8006A9FC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8006AA00: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
    // 0x8006AA04: addu        $t4, $v1, $a0
    ctx->r12 = ADD32(ctx->r3, ctx->r4);
    // 0x8006AA08: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8006AA0C: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006AA10: subu        $a3, $t8, $a2
    ctx->r7 = SUB32(ctx->r24, ctx->r6);
    // 0x8006AA14: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    // 0x8006AA18: jal         0x80070C9C
    // 0x8006AA1C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x8006AA1C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_8:
    // 0x8006AA20: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006AA24: addiu       $v1, $v1, 0x116C
    ctx->r3 = ADD32(ctx->r3, 0X116C);
    // 0x8006AA28: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8006AA2C: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006AA30: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8006AA34: jal         0x80070C9C
    // 0x8006AA38: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_9;
    // 0x8006AA38: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_9:
    // 0x8006AA3C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8006AA40: addiu       $s0, $s0, -0x2CF0
    ctx->r16 = ADD32(ctx->r16, -0X2CF0);
    // 0x8006AA44: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8006AA48: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8006AA4C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x8006AA50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8006AA54: jal         0x80076E68
    // 0x8006AA58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    asset_load(rdram, ctx);
        goto after_10;
    // 0x8006AA58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8006AA5C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006AA60: addiu       $v1, $v1, 0x116C
    ctx->r3 = ADD32(ctx->r3, 0X116C);
    // 0x8006AA64: blez        $s1, L_8006AB3C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8006AA68: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8006AB3C;
    }
    // 0x8006AA68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8006AA6C: andi        $a1, $s1, 0x3
    ctx->r5 = ctx->r17 & 0X3;
    // 0x8006AA70: beq         $a1, $zero, L_8006AAAC
    if (ctx->r5 == 0) {
        // 0x8006AA74: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8006AAAC;
    }
    // 0x8006AA74: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8006AA78: sll         $v0, $zero, 2
    ctx->r2 = S32(0 << 2);
L_8006AA7C:
    // 0x8006AA7C: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8006AA80: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8006AA84: addu        $t5, $t7, $v0
    ctx->r13 = ADD32(ctx->r15, ctx->r2);
    // 0x8006AA88: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8006AA8C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8006AA90: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8006AA94: addu        $t4, $t9, $t6
    ctx->r12 = ADD32(ctx->r25, ctx->r14);
    // 0x8006AA98: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x8006AA9C: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x8006AAA0: bne         $a0, $a3, L_8006AA7C
    if (ctx->r4 != ctx->r7) {
        // 0x8006AAA4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8006AA7C;
    }
    // 0x8006AAA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8006AAA8: beq         $a3, $s1, L_8006AB3C
    if (ctx->r7 == ctx->r17) {
        // 0x8006AAAC: sll         $v0, $a3, 2
        ctx->r2 = S32(ctx->r7 << 2);
            goto L_8006AB3C;
    }
L_8006AAAC:
    // 0x8006AAAC: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x8006AAB0: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
L_8006AAB4:
    // 0x8006AAB4: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x8006AAB8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8006AABC: addu        $t9, $t5, $v0
    ctx->r25 = ADD32(ctx->r13, ctx->r2);
    // 0x8006AAC0: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8006AAC4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8006AAC8: addu        $t4, $t6, $t8
    ctx->r12 = ADD32(ctx->r14, ctx->r24);
    // 0x8006AACC: addu        $t5, $t7, $v0
    ctx->r13 = ADD32(ctx->r15, ctx->r2);
    // 0x8006AAD0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8006AAD4: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8006AAD8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8006AADC: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x8006AAE0: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x8006AAE4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8006AAE8: addu        $t9, $t5, $v0
    ctx->r25 = ADD32(ctx->r13, ctx->r2);
    // 0x8006AAEC: addu        $t4, $t8, $t7
    ctx->r12 = ADD32(ctx->r24, ctx->r15);
    // 0x8006AAF0: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x8006AAF4: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8006AAF8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8006AAFC: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x8006AB00: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x8006AB04: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8006AB08: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x8006AB0C: addu        $t4, $t7, $t5
    ctx->r12 = ADD32(ctx->r15, ctx->r13);
    // 0x8006AB10: sw          $t4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r12;
    // 0x8006AB14: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8006AB18: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8006AB1C: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x8006AB20: lw          $t5, 0xC($t7)
    ctx->r13 = MEM_W(ctx->r15, 0XC);
    // 0x8006AB24: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8006AB28: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x8006AB2C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8006AB30: addu        $t4, $t5, $t9
    ctx->r12 = ADD32(ctx->r13, ctx->r25);
    // 0x8006AB34: bne         $v0, $a0, L_8006AAB4
    if (ctx->r2 != ctx->r4) {
        // 0x8006AB38: sw          $t4, 0xC($t8)
        MEM_W(0XC, ctx->r24) = ctx->r12;
            goto L_8006AAB4;
    }
    // 0x8006AB38: sw          $t4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r12;
L_8006AB3C:
    // 0x8006AB3C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8006AB40: jal         0x80071140
    // 0x8006AB44: nop

    mempool_free(rdram, ctx);
        goto after_11;
    // 0x8006AB44: nop

    after_11:
    // 0x8006AB48: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006AB4C: lw          $a0, -0x2CDC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2CDC);
    // 0x8006AB50: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006AB54: blez        $a0, L_8006AB7C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006AB58: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006AB7C;
    }
    // 0x8006AB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006AB5C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8006AB60: addiu       $a1, $a1, -0x7EA8
    ctx->r5 = ADD32(ctx->r5, -0X7EA8);
L_8006AB64:
    // 0x8006AB64: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x8006AB68: lbu         $t5, 0x0($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X0);
    // 0x8006AB6C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006AB70: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8006AB74: bne         $at, $zero, L_8006AB64
    if (ctx->r1 != 0) {
        // 0x8006AB78: addu        $v1, $v1, $t5
        ctx->r3 = ADD32(ctx->r3, ctx->r13);
            goto L_8006AB64;
    }
    // 0x8006AB78: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
L_8006AB7C:
    // 0x8006AB7C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006AB80: lw          $t9, -0x2CE0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2CE0);
    // 0x8006AB84: nop

    // 0x8006AB88: beq         $v1, $t9, L_8006AB9C
    if (ctx->r3 == ctx->r25) {
        // 0x8006AB8C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006AB9C;
    }
    // 0x8006AB8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006AB90: jal         0x8006A6A0
    // 0x8006AB94: nop

    drm_disable_input(rdram, ctx);
        goto after_12;
    // 0x8006AB94: nop

    after_12:
    // 0x8006AB98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006AB9C:
    // 0x8006AB9C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006ABA0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006ABA4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006ABA8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006ABAC: jr          $ra
    // 0x8006ABB0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8006ABB0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void racer_sound_hovercraft(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80005D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005D10: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80005D14: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80005D18: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80005D1C: jal         0x8001139C
    // 0x80005D20: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    get_race_countdown(rdram, ctx);
        goto after_0;
    // 0x80005D20: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x80005D24: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80005D28: bne         $v0, $zero, L_80005D54
    if (ctx->r2 != 0) {
        // 0x80005D2C: nop
    
            goto L_80005D54;
    }
    // 0x80005D2C: nop

    // 0x80005D30: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80005D34: lwc1        $f2, 0x24($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80005D38: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80005D3C: nop

    // 0x80005D40: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80005D44: jal         0x800C9AD0
    // 0x80005D48: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80005D48: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x80005D4C: b           L_80005D5C
    // 0x80005D50: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
        goto L_80005D5C;
    // 0x80005D50: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
L_80005D54:
    // 0x80005D54: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80005D58: nop

L_80005D5C:
    // 0x80005D5C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80005D60: addiu       $t1, $t1, -0x63C8
    ctx->r9 = ADD32(ctx->r9, -0X63C8);
    // 0x80005D64: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80005D68: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80005D6C: lwc1        $f14, 0xD4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XD4);
    // 0x80005D70: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80005D74: beq         $t7, $zero, L_80005DDC
    if (ctx->r15 == 0) {
        // 0x80005D78: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80005DDC;
    }
    // 0x80005D78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80005D7C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80005D80: lwc1        $f8, 0xB0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XB0);
    // 0x80005D84: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80005D88: nop

    // 0x80005D8C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80005D90: lwc1        $f10, 0xA4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80005D94: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80005D98: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80005D9C: swc1        $f8, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f8.u32l;
    // 0x80005DA0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80005DA4: nop

    // 0x80005DA8: lwc1        $f2, 0xC8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC8);
    // 0x80005DAC: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80005DB0: nop

    // 0x80005DB4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80005DB8: nop

    // 0x80005DBC: bc1f        L_80005E10
    if (!c1cs) {
        // 0x80005DC0: nop
    
            goto L_80005E10;
    }
    // 0x80005DC0: nop

    // 0x80005DC4: swc1        $f2, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f2.u32l;
    // 0x80005DC8: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80005DCC: nop

    // 0x80005DD0: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80005DD4: b           L_80005E14
    // 0x80005DD8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
        goto L_80005E14;
    // 0x80005DD8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80005DDC:
    // 0x80005DDC: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80005DE0: lwc1        $f4, 0xB4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XB4);
    // 0x80005DE4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80005DE8: nop

    // 0x80005DEC: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80005DF0: lwc1        $f10, 0xA4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80005DF4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80005DF8: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80005DFC: swc1        $f4, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f4.u32l;
    // 0x80005E00: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80005E04: nop

    // 0x80005E08: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80005E0C: nop

L_80005E10:
    // 0x80005E10: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80005E14:
    // 0x80005E14: nop

    // 0x80005E18: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80005E1C: nop

    // 0x80005E20: bc1f        L_80005E2C
    if (!c1cs) {
        // 0x80005E24: nop
    
            goto L_80005E2C;
    }
    // 0x80005E24: nop

    // 0x80005E28: swc1        $f2, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f2.u32l;
L_80005E2C:
    // 0x80005E2C: lw          $a0, -0x63C4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X63C4);
    // 0x80005E30: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80005E34: lh          $t2, 0x196($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X196);
    // 0x80005E38: lh          $t4, 0x1A0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X1A0);
    // 0x80005E3C: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80005E40: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80005E44: subu        $v0, $t3, $t5
    ctx->r2 = SUB32(ctx->r11, ctx->r13);
    // 0x80005E48: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
    // 0x80005E4C: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80005E50: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80005E54: bne         $at, $zero, L_80005E64
    if (ctx->r1 != 0) {
        // 0x80005E58: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80005E64;
    }
    // 0x80005E58: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80005E5C: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80005E60: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80005E64:
    // 0x80005E64: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x80005E68: beq         $at, $zero, L_80005E74
    if (ctx->r1 == 0) {
        // 0x80005E6C: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80005E74;
    }
    // 0x80005E6C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80005E70: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80005E74:
    // 0x80005E74: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80005E78: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80005E7C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80005E80: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80005E84: jal         0x800707C4
    // 0x80005E88: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x80005E88: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80005E8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80005E90: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005E94: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80005E98: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80005E9C: bc1f        L_80005EA8
    if (!c1cs) {
        // 0x80005EA0: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80005EA8;
    }
    // 0x80005EA0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80005EA4: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_80005EA8:
    // 0x80005EA8: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80005EAC: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80005EB0: jal         0x80066510
    // 0x80005EB4: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_3;
    // 0x80005EB4: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80005EB8: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80005EBC: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005EC0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80005EC4: bne         $v0, $zero, L_80005F24
    if (ctx->r2 != 0) {
        // 0x80005EC8: nop
    
            goto L_80005F24;
    }
    // 0x80005EC8: nop

    // 0x80005ECC: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80005ED0: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80005ED4: jal         0x8001139C
    // 0x80005ED8: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    get_race_countdown(rdram, ctx);
        goto after_4;
    // 0x80005ED8: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x80005EDC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80005EE0: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80005EE4: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005EE8: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80005EEC: bne         $v0, $zero, L_80005F24
    if (ctx->r2 != 0) {
        // 0x80005EF0: addiu       $t1, $t1, -0x63C8
        ctx->r9 = ADD32(ctx->r9, -0X63C8);
            goto L_80005F24;
    }
    // 0x80005EF0: addiu       $t1, $t1, -0x63C8
    ctx->r9 = ADD32(ctx->r9, -0X63C8);
    // 0x80005EF4: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80005EF8: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x80005EFC: lwc1        $f10, 0xBC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XBC);
    // 0x80005F00: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80005F04: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80005F08: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80005F0C: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80005F10: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80005F14: nop

    // 0x80005F18: div.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f10.d);
    // 0x80005F1C: b           L_80005F2C
    // 0x80005F20: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
        goto L_80005F2C;
    // 0x80005F20: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
L_80005F24:
    // 0x80005F24: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80005F28: nop

L_80005F2C:
    // 0x80005F2C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80005F30: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x80005F34: jal         0x800A0190
    // 0x80005F38: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    race_starting(rdram, ctx);
        goto after_5;
    // 0x80005F38: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x80005F3C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80005F40: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005F44: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80005F48: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80005F4C: bne         $v0, $zero, L_80005F64
    if (ctx->r2 != 0) {
        // 0x80005F50: addiu       $t1, $t1, -0x63C8
        ctx->r9 = ADD32(ctx->r9, -0X63C8);
            goto L_80005F64;
    }
    // 0x80005F50: addiu       $t1, $t1, -0x63C8
    ctx->r9 = ADD32(ctx->r9, -0X63C8);
    // 0x80005F54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80005F58: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80005F5C: nop

    // 0x80005F60: swc1        $f4, 0xA4($t8)
    MEM_W(0XA4, ctx->r24) = ctx->f4.u32l;
L_80005F64:
    // 0x80005F64: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80005F68: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80005F6C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80005F70: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80005F74: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80005F78: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80005F7C: bc1f        L_80005F90
    if (!c1cs) {
        // 0x80005F80: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80005F90;
    }
    // 0x80005F80: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80005F84: sub.d       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f0.d - ctx->f2.d;
    // 0x80005F88: b           L_80005F98
    // 0x80005F8C: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
        goto L_80005F98;
    // 0x80005F8C: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
L_80005F90:
    // 0x80005F90: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80005F94: nop

L_80005F98:
    // 0x80005F98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80005F9C: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80005FA0: c.eq.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d == ctx->f8.d;
    // 0x80005FA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005FA8: bc1t        L_8000607C
    if (c1cs) {
        // 0x80005FAC: nop
    
            goto L_8000607C;
    }
    // 0x80005FAC: nop

    // 0x80005FB0: lw          $a0, -0x63C4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X63C4);
    // 0x80005FB4: nop

    // 0x80005FB8: lb          $v0, 0x185($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X185);
    // 0x80005FBC: nop

    // 0x80005FC0: beq         $v0, $zero, L_8000607C
    if (ctx->r2 == 0) {
        // 0x80005FC4: nop
    
            goto L_8000607C;
    }
    // 0x80005FC4: nop

    // 0x80005FC8: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80005FCC: beq         $at, $zero, L_80005FDC
    if (ctx->r1 == 0) {
        // 0x80005FD0: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_80005FDC;
    }
    // 0x80005FD0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80005FD4: b           L_80005FDC
    // 0x80005FD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80005FDC;
    // 0x80005FD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80005FDC:
    // 0x80005FDC: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80005FE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005FE4: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x80005FE8: lwc1        $f5, 0x4C50($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X4C50);
    // 0x80005FEC: lwc1        $f4, 0x4C54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4C54);
    // 0x80005FF0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80005FF4: mul.d       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x80005FF8: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80005FFC: sll         $t9, $a1, 6
    ctx->r25 = S32(ctx->r5 << 6);
    // 0x80006000: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80006004: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80006008: nop

    // 0x8000600C: bc1f        L_80006048
    if (!c1cs) {
        // 0x80006010: nop
    
            goto L_80006048;
    }
    // 0x80006010: nop

    // 0x80006014: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80006018: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000601C: cvt.d.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.d = CVT_D_W(ctx->f8.u32l);
    // 0x80006020: nop

    // 0x80006024: div.d       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f6.d);
    // 0x80006028: add.d       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f2.d + ctx->f4.d;
    // 0x8000602C: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80006030: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x80006034: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006038: lw          $a0, -0x63C4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X63C4);
    // 0x8000603C: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006040: b           L_800060B4
    // 0x80006044: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
        goto L_800060B4;
    // 0x80006044: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
L_80006048:
    // 0x80006048: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x8000604C: nop

    // 0x80006050: bc1f        L_80006074
    if (!c1cs) {
        // 0x80006054: nop
    
            goto L_80006074;
    }
    // 0x80006054: nop

    // 0x80006058: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x8000605C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80006060: swc1        $f6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f6.u32l;
    // 0x80006064: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006068: lw          $a0, -0x63C4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X63C4);
    // 0x8000606C: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006070: nop

L_80006074:
    // 0x80006074: b           L_800060B4
    // 0x80006078: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
        goto L_800060B4;
    // 0x80006078: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
L_8000607C:
    // 0x8000607C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006080: lwc1        $f9, 0x4C58($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X4C58);
    // 0x80006084: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006088: lwc1        $f8, 0x4C5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4C5C);
    // 0x8000608C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80006090: mul.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80006094: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80006098: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8000609C: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
    // 0x800060A0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800060A4: lw          $a0, -0x63C4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X63C4);
    // 0x800060A8: lwc1        $f10, 0x3C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x800060AC: nop

    // 0x800060B0: add.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
L_800060B4:
    // 0x800060B4: lwc1        $f8, 0xCC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XCC);
    // 0x800060B8: lwc1        $f10, 0xA4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x800060BC: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800060C0: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x800060C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800060C8: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800060CC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800060D0: beq         $t2, $at, L_8000612C
    if (ctx->r10 == ctx->r1) {
        // 0x800060D4: add.s       $f14, $f14, $f8
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
            goto L_8000612C;
    }
    // 0x800060D4: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x800060D8: lb          $t4, 0x1E2($a0)
    ctx->r12 = MEM_B(ctx->r4, 0X1E2);
    // 0x800060DC: nop

    // 0x800060E0: bne         $t4, $zero, L_8000612C
    if (ctx->r12 != 0) {
        // 0x800060E4: nop
    
            goto L_8000612C;
    }
    // 0x800060E4: nop

    // 0x800060E8: lb          $t3, 0x1E5($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X1E5);
    // 0x800060EC: nop

    // 0x800060F0: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x800060F4: beq         $at, $zero, L_8000612C
    if (ctx->r1 == 0) {
        // 0x800060F8: nop
    
            goto L_8000612C;
    }
    // 0x800060F8: nop

    // 0x800060FC: jal         0x8001139C
    // 0x80006100: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    get_race_countdown(rdram, ctx);
        goto after_6;
    // 0x80006100: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_6:
    // 0x80006104: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80006108: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000610C: bne         $v0, $zero, L_8000612C
    if (ctx->r2 != 0) {
        // 0x80006110: addiu       $t1, $t1, -0x63C8
        ctx->r9 = ADD32(ctx->r9, -0X63C8);
            goto L_8000612C;
    }
    // 0x80006110: addiu       $t1, $t1, -0x63C8
    ctx->r9 = ADD32(ctx->r9, -0X63C8);
    // 0x80006114: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006118: lwc1        $f5, 0x4C60($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X4C60);
    // 0x8000611C: lwc1        $f4, 0x4C64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4C64);
    // 0x80006120: cvt.d.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.d = CVT_D_S(ctx->f14.fl);
    // 0x80006124: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x80006128: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
L_8000612C:
    // 0x8000612C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006130: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80006134: lwc1        $f0, 0x5C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80006138: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8000613C: sub.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80006140: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006144: div.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80006148: add.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8000614C: swc1        $f4, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f4.u32l;
    // 0x80006150: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006154: lwc1        $f10, 0x4C6C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4C6C);
    // 0x80006158: lwc1        $f0, 0x5C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x8000615C: lwc1        $f11, 0x4C68($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X4C68);
    // 0x80006160: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80006164: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80006168: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000616C: bc1f        L_80006190
    if (!c1cs) {
        // 0x80006170: nop
    
            goto L_80006190;
    }
    // 0x80006170: nop

    // 0x80006174: lwc1        $f6, 0x4C70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4C70);
    // 0x80006178: nop

    // 0x8000617C: swc1        $f6, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f6.u32l;
    // 0x80006180: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006184: nop

    // 0x80006188: lwc1        $f0, 0x5C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x8000618C: nop

L_80006190:
    // 0x80006190: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006194: lwc1        $f4, 0x4C74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4C74);
    // 0x80006198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000619C: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800061A0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800061A4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800061A8: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x800061AC: nop

    // 0x800061B0: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800061B4: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x800061B8: nop

    // 0x800061BC: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x800061C0: beq         $a1, $zero, L_8000620C
    if (ctx->r5 == 0) {
        // 0x800061C4: nop
    
            goto L_8000620C;
    }
    // 0x800061C4: nop

    // 0x800061C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800061CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800061D0: sub.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800061D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800061D8: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x800061DC: nop

    // 0x800061E0: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800061E4: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x800061E8: nop

    // 0x800061EC: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x800061F0: bne         $a1, $zero, L_80006204
    if (ctx->r5 != 0) {
        // 0x800061F4: nop
    
            goto L_80006204;
    }
    // 0x800061F4: nop

    // 0x800061F8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800061FC: b           L_8000621C
    // 0x80006200: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_8000621C;
    // 0x80006200: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_80006204:
    // 0x80006204: b           L_8000621C
    // 0x80006208: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_8000621C;
    // 0x80006208: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_8000620C:
    // 0x8000620C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80006210: nop

    // 0x80006214: bltz        $a1, L_80006204
    if (SIGNED(ctx->r5) < 0) {
        // 0x80006218: nop
    
            goto L_80006204;
    }
    // 0x80006218: nop

L_8000621C:
    // 0x8000621C: lhu         $t7, 0x18($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X18);
    // 0x80006220: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    // 0x80006224: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80006228: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000622C: bne         $at, $zero, L_80006260
    if (ctx->r1 != 0) {
        // 0x80006230: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80006260;
    }
    // 0x80006230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80006234:
    // 0x80006234: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80006238: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8000623C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80006240: addu        $t2, $v1, $t9
    ctx->r10 = ADD32(ctx->r3, ctx->r25);
    // 0x80006244: lhu         $t4, 0x18($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X18);
    // 0x80006248: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8000624C: slt         $at, $a0, $t4
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80006250: bne         $at, $zero, L_80006260
    if (ctx->r1 != 0) {
        // 0x80006254: slti        $at, $t8, 0x4
        ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
            goto L_80006260;
    }
    // 0x80006254: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x80006258: bne         $at, $zero, L_80006234
    if (ctx->r1 != 0) {
        // 0x8000625C: nop
    
            goto L_80006234;
    }
    // 0x8000625C: nop

L_80006260:
    // 0x80006260: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80006264: bne         $v0, $at, L_8000627C
    if (ctx->r2 != ctx->r1) {
        // 0x80006268: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000627C;
    }
    // 0x80006268: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000626C: addu        $t3, $v1, $v0
    ctx->r11 = ADD32(ctx->r3, ctx->r2);
    // 0x80006270: lbu         $t0, 0x2C($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0X2C);
    // 0x80006274: b           L_8000638C
    // 0x80006278: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
        goto L_8000638C;
    // 0x80006278: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
L_8000627C:
    // 0x8000627C: beq         $a1, $zero, L_80006290
    if (ctx->r5 == 0) {
        // 0x80006280: lui         $at, 0x4F80
        ctx->r1 = S32(0X4F80 << 16);
            goto L_80006290;
    }
    // 0x80006280: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80006284: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80006288: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x8000628C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80006290:
    // 0x80006290: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80006294: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80006298: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x8000629C: lhu         $a2, 0x18($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X18);
    // 0x800062A0: addu        $t2, $v1, $t9
    ctx->r10 = ADD32(ctx->r3, ctx->r25);
    // 0x800062A4: lhu         $t4, 0x1A($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X1A);
    // 0x800062A8: subu        $t8, $a0, $a2
    ctx->r24 = SUB32(ctx->r4, ctx->r6);
    // 0x800062AC: subu        $t3, $t4, $a2
    ctx->r11 = SUB32(ctx->r12, ctx->r6);
    // 0x800062B0: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800062B4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800062B8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800062BC: addu        $t6, $v1, $a1
    ctx->r14 = ADD32(ctx->r3, ctx->r5);
    // 0x800062C0: addu        $t5, $v1, $v0
    ctx->r13 = ADD32(ctx->r3, ctx->r2);
    // 0x800062C4: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800062C8: lbu         $a3, 0x2C($t5)
    ctx->r7 = MEM_BU(ctx->r13, 0X2C);
    // 0x800062CC: lbu         $t7, 0x2D($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2D);
    // 0x800062D0: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800062D4: subu        $t8, $t7, $a3
    ctx->r24 = SUB32(ctx->r15, ctx->r7);
    // 0x800062D8: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800062DC: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x800062E0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800062E4: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800062E8: bgez        $a3, L_800062FC
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800062EC: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800062FC;
    }
    // 0x800062EC: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800062F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800062F4: nop

    // 0x800062F8: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800062FC:
    // 0x800062FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006300: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80006304: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80006308: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8000630C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80006310: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80006314: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80006318: nop

    // 0x8000631C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80006320: beq         $t0, $zero, L_8000636C
    if (ctx->r8 == 0) {
        // 0x80006324: nop
    
            goto L_8000636C;
    }
    // 0x80006324: nop

    // 0x80006328: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000632C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80006330: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80006334: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80006338: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8000633C: nop

    // 0x80006340: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80006344: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80006348: nop

    // 0x8000634C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80006350: bne         $t0, $zero, L_80006364
    if (ctx->r8 != 0) {
        // 0x80006354: nop
    
            goto L_80006364;
    }
    // 0x80006354: nop

    // 0x80006358: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8000635C: b           L_8000637C
    // 0x80006360: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_8000637C;
    // 0x80006360: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80006364:
    // 0x80006364: b           L_8000637C
    // 0x80006368: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_8000637C;
    // 0x80006368: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8000636C:
    // 0x8000636C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80006370: nop

    // 0x80006374: bltz        $t0, L_80006364
    if (SIGNED(ctx->r8) < 0) {
        // 0x80006378: nop
    
            goto L_80006364;
    }
    // 0x80006378: nop

L_8000637C:
    // 0x8000637C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80006380: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x80006384: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x80006388: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
L_8000638C:
    // 0x8000638C: lwc1        $f0, 0x54($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X54);
    // 0x80006390: bgez        $t0, L_800063A8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80006394: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800063A8;
    }
    // 0x80006394: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80006398: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000639C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800063A0: nop

    // 0x800063A4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800063A8:
    // 0x800063A8: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800063AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800063B0: div.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800063B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800063B8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800063BC: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800063C0: swc1        $f8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f8.u32l;
    // 0x800063C4: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800063C8: nop

    // 0x800063CC: swc1        $f6, 0x60($t4)
    MEM_W(0X60, ctx->r12) = ctx->f6.u32l;
    // 0x800063D0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800063D4: nop

    // 0x800063D8: swc1        $f10, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->f10.u32l;
    // 0x800063DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800063E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800063E4: jr          $ra
    // 0x800063E8: nop

    return;
    // 0x800063E8: nop

;}
RECOMP_FUNC void ghostmenu_generate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009963C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80099640: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80099644: addiu       $t1, $t1, 0x64D4
    ctx->r9 = ADD32(ctx->r9, 0X64D4);
    // 0x80099648: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009964C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80099650: jal         0x8001E29C
    // 0x80099654: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80099654: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_0:
    // 0x80099658: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009965C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80099660: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80099664: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80099668: addiu       $t1, $t1, 0x64D4
    ctx->r9 = ADD32(ctx->r9, 0X64D4);
    // 0x8009966C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80099670: addiu       $t3, $t3, 0x6540
    ctx->r11 = ADD32(ctx->r11, 0X6540);
    // 0x80099674: addiu       $ra, $ra, 0x64EC
    ctx->r31 = ADD32(ctx->r31, 0X64EC);
    // 0x80099678: addiu       $a3, $a3, 0x64DC
    ctx->r7 = ADD32(ctx->r7, 0X64DC);
    // 0x8009967C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80099680: addiu       $t5, $sp, 0x44
    ctx->r13 = ADD32(ctx->r29, 0X44);
    // 0x80099684: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_80099688:
    // 0x80099688: lbu         $a0, 0x0($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X0);
    // 0x8009968C: nop

    // 0x80099690: beq         $a1, $a0, L_8009971C
    if (ctx->r5 == ctx->r4) {
        // 0x80099694: nop
    
            goto L_8009971C;
    }
    // 0x80099694: nop

    // 0x80099698: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8009969C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800996A0: beq         $a1, $t6, L_800996E0
    if (ctx->r5 == ctx->r14) {
        // 0x800996A4: addu        $t7, $v0, $t0
        ctx->r15 = ADD32(ctx->r2, ctx->r8);
            goto L_800996E0;
    }
    // 0x800996A4: addu        $t7, $v0, $t0
    ctx->r15 = ADD32(ctx->r2, ctx->r8);
    // 0x800996A8: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800996AC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800996B0: beq         $t7, $a0, L_800996E0
    if (ctx->r15 == ctx->r4) {
        // 0x800996B4: addu        $t7, $v0, $t0
        ctx->r15 = ADD32(ctx->r2, ctx->r8);
            goto L_800996E0;
    }
    // 0x800996B4: addu        $t7, $v0, $t0
    ctx->r15 = ADD32(ctx->r2, ctx->r8);
L_800996B8:
    // 0x800996B8: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    // 0x800996BC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800996C0: beq         $a1, $t8, L_800996DC
    if (ctx->r5 == ctx->r24) {
        // 0x800996C4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800996DC;
    }
    // 0x800996C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800996C8: addu        $t9, $a2, $t0
    ctx->r25 = ADD32(ctx->r6, ctx->r8);
    // 0x800996CC: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x800996D0: nop

    // 0x800996D4: bne         $t6, $a0, L_800996B8
    if (ctx->r14 != ctx->r4) {
        // 0x800996D8: nop
    
            goto L_800996B8;
    }
    // 0x800996D8: nop

L_800996DC:
    // 0x800996DC: addu        $t7, $v0, $t0
    ctx->r15 = ADD32(ctx->r2, ctx->r8);
L_800996E0:
    // 0x800996E0: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800996E4: addu        $t6, $ra, $t2
    ctx->r14 = ADD32(ctx->r31, ctx->r10);
    // 0x800996E8: beq         $a1, $t8, L_8009971C
    if (ctx->r5 == ctx->r24) {
        // 0x800996EC: nop
    
            goto L_8009971C;
    }
    // 0x800996EC: nop

    // 0x800996F0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800996F4: sll         $t8, $t0, 3
    ctx->r24 = S32(ctx->r8 << 3);
    // 0x800996F8: addu        $t9, $t3, $t4
    ctx->r25 = ADD32(ctx->r11, ctx->r12);
    // 0x800996FC: sb          $t2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r10;
    // 0x80099700: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80099704: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80099708: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8009970C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80099710: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
    // 0x80099714: addiu       $t8, $t4, 0x1
    ctx->r24 = ADD32(ctx->r12, 0X1);
    // 0x80099718: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
L_8009971C:
    // 0x8009971C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80099720: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x80099724: bne         $at, $zero, L_80099688
    if (ctx->r1 != 0) {
        // 0x80099728: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80099688;
    }
    // 0x80099728: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8009972C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80099730: lhu         $a3, 0x46($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X46);
    // 0x80099734: addiu       $t2, $t4, -0x1
    ctx->r10 = ADD32(ctx->r12, -0X1);
    // 0x80099738: blez        $t2, L_80099830
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8009973C: nop
    
            goto L_80099830;
    }
    // 0x8009973C: nop

    // 0x80099740: lhu         $a0, 0x44($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X44);
    // 0x80099744: nop

L_80099748:
    // 0x80099748: blez        $t2, L_8009981C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8009974C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8009981C;
    }
    // 0x8009974C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80099750: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x80099754: beq         $v0, $zero, L_80099790
    if (ctx->r2 == 0) {
        // 0x80099758: slt         $at, $a3, $a0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80099790;
    }
    // 0x80099758: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8009975C: beq         $at, $zero, L_8009978C
    if (ctx->r1 == 0) {
        // 0x80099760: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8009978C;
    }
    // 0x80099760: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80099764: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80099768: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009976C: lbu         $t6, 0x6541($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X6541);
    // 0x80099770: lbu         $a2, 0x6540($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X6540);
    // 0x80099774: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80099778: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009977C: andi        $a0, $a3, 0xFFFF
    ctx->r4 = ctx->r7 & 0XFFFF;
    // 0x80099780: andi        $a3, $a1, 0xFFFF
    ctx->r7 = ctx->r5 & 0XFFFF;
    // 0x80099784: sb          $t6, 0x6540($at)
    MEM_B(0X6540, ctx->r1) = ctx->r14;
    // 0x80099788: sb          $a2, 0x6541($at)
    MEM_B(0X6541, ctx->r1) = ctx->r6;
L_8009978C:
    // 0x8009978C: beq         $t0, $t2, L_8009981C
    if (ctx->r8 == ctx->r10) {
        // 0x80099790: sll         $t9, $t0, 1
        ctx->r25 = S32(ctx->r8 << 1);
            goto L_8009981C;
    }
L_80099790:
    // 0x80099790: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x80099794: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x80099798: addu        $v1, $t9, $t7
    ctx->r3 = ADD32(ctx->r25, ctx->r15);
    // 0x8009979C: sh          $a0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r4;
    // 0x800997A0: sh          $a3, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r7;
L_800997A4:
    // 0x800997A4: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x800997A8: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x800997AC: addu        $v0, $t3, $t0
    ctx->r2 = ADD32(ctx->r11, ctx->r8);
    // 0x800997B0: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800997B4: beq         $at, $zero, L_800997DC
    if (ctx->r1 == 0) {
        // 0x800997B8: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800997DC;
    }
    // 0x800997B8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800997BC: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x800997C0: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800997C4: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x800997C8: andi        $a0, $t1, 0xFFFF
    ctx->r4 = ctx->r9 & 0XFFFF;
    // 0x800997CC: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x800997D0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800997D4: sb          $a2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r6;
    // 0x800997D8: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
L_800997DC:
    // 0x800997DC: lhu         $t1, 0x4($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X4);
    // 0x800997E0: addu        $v0, $t3, $t0
    ctx->r2 = ADD32(ctx->r11, ctx->r8);
    // 0x800997E4: slt         $at, $t1, $a3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800997E8: beq         $at, $zero, L_80099808
    if (ctx->r1 == 0) {
        // 0x800997EC: nop
    
            goto L_80099808;
    }
    // 0x800997EC: nop

    // 0x800997F0: lbu         $a2, 0x1($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X1);
    // 0x800997F4: lbu         $t6, 0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2);
    // 0x800997F8: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x800997FC: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
    // 0x80099800: sb          $a2, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r6;
    // 0x80099804: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
L_80099808:
    // 0x80099808: lhu         $a0, 0x44($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X44);
    // 0x8009980C: lhu         $a3, 0x46($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X46);
    // 0x80099810: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80099814: bne         $t0, $t2, L_800997A4
    if (ctx->r8 != ctx->r10) {
        // 0x80099818: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800997A4;
    }
    // 0x80099818: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8009981C:
    // 0x8009981C: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80099820: bgtz        $t2, L_80099748
    if (SIGNED(ctx->r10) > 0) {
        // 0x80099824: nop
    
            goto L_80099748;
    }
    // 0x80099824: nop

    // 0x80099828: sh          $a3, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r7;
    // 0x8009982C: sh          $a0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r4;
L_80099830:
    // 0x80099830: blez        $t4, L_800998D0
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80099834: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800998D0;
    }
    // 0x80099834: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80099838: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009983C: addiu       $v1, $t9, 0x6520
    ctx->r3 = ADD32(ctx->r25, 0X6520);
    // 0x80099840: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80099844: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80099848: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009984C: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x80099850: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80099854: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80099858: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009985C: addiu       $t0, $t0, 0x64DC
    ctx->r8 = ADD32(ctx->r8, 0X64DC);
    // 0x80099860: addiu       $t1, $t1, 0x64E4
    ctx->r9 = ADD32(ctx->r9, 0X64E4);
    // 0x80099864: addiu       $t2, $t2, 0x64F8
    ctx->r10 = ADD32(ctx->r10, 0X64F8);
    // 0x80099868: addu        $t3, $t7, $v1
    ctx->r11 = ADD32(ctx->r15, ctx->r3);
    // 0x8009986C: addiu       $a3, $a3, 0x6518
    ctx->r7 = ADD32(ctx->r7, 0X6518);
    // 0x80099870: addiu       $a2, $a2, 0x6510
    ctx->r6 = ADD32(ctx->r6, 0X6510);
    // 0x80099874: addiu       $a1, $a1, 0x6540
    ctx->r5 = ADD32(ctx->r5, 0X6540);
    // 0x80099878: addiu       $a0, $a0, 0x6508
    ctx->r4 = ADD32(ctx->r4, 0X6508);
L_8009987C:
    // 0x8009987C: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80099880: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80099884: addu        $t8, $t0, $v0
    ctx->r24 = ADD32(ctx->r8, ctx->r2);
    // 0x80099888: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x8009988C: addu        $t7, $t1, $v0
    ctx->r15 = ADD32(ctx->r9, ctx->r2);
    // 0x80099890: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x80099894: addu        $t8, $ra, $v0
    ctx->r24 = ADD32(ctx->r31, ctx->r2);
    // 0x80099898: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x8009989C: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x800998A0: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x800998A4: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x800998A8: addu        $t9, $t2, $t7
    ctx->r25 = ADD32(ctx->r10, ctx->r15);
    // 0x800998AC: lhu         $t8, 0x0($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X0);
    // 0x800998B0: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x800998B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800998B8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800998BC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800998C0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800998C4: sb          $t6, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r14;
    // 0x800998C8: bne         $at, $zero, L_8009987C
    if (ctx->r1 != 0) {
        // 0x800998CC: sh          $t8, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r24;
            goto L_8009987C;
    }
    // 0x800998CC: sh          $t8, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r24;
L_800998D0:
    // 0x800998D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800998D4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800998D8: jr          $ra
    // 0x800998DC: nop

    return;
    // 0x800998DC: nop

;}
RECOMP_FUNC void racer_sound_disable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007F88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007F8C: jr          $ra
    // 0x80007F90: sb          $zero, -0x3930($at)
    MEM_B(-0X3930, ctx->r1) = 0;
    return;
    // 0x80007F90: sb          $zero, -0x3930($at)
    MEM_B(-0X3930, ctx->r1) = 0;
;}
RECOMP_FUNC void render_dialogue_boxes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_hud_dialogue_pass_begin(uint8_t*, recomp_context*); dkr_hud_dialogue_pass_begin(rdram, ctx);
    // 0x800C56FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C5700: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C5704: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800C5708: addiu       $s0, $s0, 0x36E8
    ctx->r16 = ADD32(ctx->r16, 0X36E8);
    // 0x800C570C: lb          $t6, 0x0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X0);
    // 0x800C5710: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800C5714: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800C5718: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C571C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C5720: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800C5724: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x800C5728: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C572C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C5730: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C5734: beq         $t6, $zero, L_800C5770
    if (ctx->r14 == 0) {
        // 0x800C5738: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_800C5770;
    }
    // 0x800C5738: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C573C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C5740: addiu       $v0, $v0, -0x580C
    ctx->r2 = ADD32(ctx->r2, -0X580C);
    // 0x800C5744: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x800C5748: nop

    // 0x800C574C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800C5750: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800C5754: lb          $t9, 0x0($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X0);
    // 0x800C5758: nop

    // 0x800C575C: bne         $t9, $zero, L_800C5770
    if (ctx->r25 != 0) {
        // 0x800C5760: nop
    
            goto L_800C5770;
    }
    // 0x800C5760: nop

    // 0x800C5764: jal         0x8009E9A8
    // 0x800C5768: nop

    dialogue_close_stub(rdram, ctx);
        goto after_0;
    // 0x800C5768: nop

    after_0:
    // 0x800C576C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_800C5770:
    // 0x800C5770: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800C5774: addiu       $s3, $s3, -0x5818
    ctx->r19 = ADD32(ctx->r19, -0X5818);
    // 0x800C5778: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800C577C: addiu       $s1, $zero, 0x28
    ctx->r17 = ADD32(0, 0X28);
    // 0x800C5780: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
L_800C5784:
    // 0x800C5784: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800C5788: nop

    // 0x800C578C: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800C5790: lhu         $v0, 0x1E($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X1E);
    // 0x800C5794: nop

    // 0x800C5798: andi        $t2, $v0, 0x8000
    ctx->r10 = ctx->r2 & 0X8000;
    // 0x800C579C: beq         $t2, $zero, L_800C57D8
    if (ctx->r10 == 0) {
        // 0x800C57A0: andi        $t3, $v0, 0x4000
        ctx->r11 = ctx->r2 & 0X4000;
            goto L_800C57D8;
    }
    // 0x800C57A0: andi        $t3, $v0, 0x4000
    ctx->r11 = ctx->r2 & 0X4000;
    // 0x800C57A4: beq         $t3, $zero, L_800C57C8
    if (ctx->r11 == 0) {
        // 0x800C57A8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C57C8;
    }
    // 0x800C57A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C57AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C57B0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800C57B4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800C57B8: jal         0x800C5B58
    // 0x800C57BC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    render_dialogue_box(rdram, ctx);
        goto after_1;
    // 0x800C57BC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x800C57C0: b           L_800C57DC
    // 0x800C57C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800C57DC;
    // 0x800C57C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C57C8:
    // 0x800C57C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C57CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C57D0: jal         0x800C5B58
    // 0x800C57D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    render_dialogue_box(rdram, ctx);
        goto after_2;
    // 0x800C57D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
L_800C57D8:
    // 0x800C57D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C57DC:
    // 0x800C57DC: bne         $s0, $s4, L_800C5784
    if (ctx->r16 != ctx->r20) {
        // 0x800C57E0: addiu       $s1, $s1, 0x28
        ctx->r17 = ADD32(ctx->r17, 0X28);
            goto L_800C5784;
    }
    // 0x800C57E0: addiu       $s1, $s1, 0x28
    ctx->r17 = ADD32(ctx->r17, 0X28);
    // 0x800C57E4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C57E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C57EC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C57F0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C57F4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C57F8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C57FC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5800: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    extern void dkr_hud_dialogue_pass_end(uint8_t*, recomp_context*); dkr_hud_dialogue_pass_end(rdram, ctx);
    // 0x800C5804: jr          $ra
    // 0x800C5808: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C5808: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void vec3s_reflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F9B8: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x8006F9BC: lh          $t3, 0x0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X0);
    // 0x8006F9C0: lh          $t1, 0x2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2);
    // 0x8006F9C4: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x8006F9C8: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F9CC: lh          $t2, 0x4($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X4);
    // 0x8006F9D0: lh          $t5, 0x4($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X4);
    // 0x8006F9D4: mflo        $t6
    ctx->r14 = lo;
    // 0x8006F9D8: nop

    // 0x8006F9DC: nop

    // 0x8006F9E0: mult        $t1, $t4
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F9E4: mflo        $t7
    ctx->r15 = lo;
    // 0x8006F9E8: add         $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8006F9EC: nop

    // 0x8006F9F0: mult        $t2, $t5
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F9F4: mflo        $t8
    ctx->r24 = lo;
    // 0x8006F9F8: add         $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8006F9FC: sra         $t6, $t6, 12
    ctx->r14 = S32(SIGNED(ctx->r14) >> 12);
    // 0x8006FA00: mult        $t6, $t3
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FA04: mflo        $t3
    ctx->r11 = lo;
    // 0x8006FA08: sra         $t3, $t3, 13
    ctx->r11 = S32(SIGNED(ctx->r11) >> 13);
    // 0x8006FA0C: sub         $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x8006FA10: mult        $t6, $t4
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FA14: sh          $t3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r11;
    // 0x8006FA18: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FA1C: sra         $t4, $t4, 13
    ctx->r12 = S32(SIGNED(ctx->r12) >> 13);
    // 0x8006FA20: sub         $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8006FA24: mult        $t6, $t5
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FA28: sh          $t4, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r12;
    // 0x8006FA2C: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FA30: sra         $t5, $t5, 13
    ctx->r13 = S32(SIGNED(ctx->r13) >> 13);
    // 0x8006FA34: sub         $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x8006FA38: jr          $ra
    // 0x8006FA3C: sh          $t5, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r13;
    return;
    // 0x8006FA3C: sh          $t5, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r13;
;}
RECOMP_FUNC void set_rectangle_texture_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF0F0: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x800AF0F4: nop

    // 0x800AF0F8: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800AF0FC: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800AF100: lbu         $a1, 0x0($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X0);
    // 0x800AF104: lbu         $a3, 0x1($a2)
    ctx->r7 = MEM_BU(ctx->r6, 0X1);
    // 0x800AF108: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800AF10C: sll         $t8, $a1, 5
    ctx->r24 = S32(ctx->r5 << 5);
    // 0x800AF110: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800AF114: sll         $t1, $a3, 5
    ctx->r9 = S32(ctx->r7 << 5);
    // 0x800AF118: sh          $t1, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r9;
    // 0x800AF11C: sh          $t8, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r24;
    // 0x800AF120: sh          $t8, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r24;
    // 0x800AF124: sh          $t8, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r24;
    // 0x800AF128: sh          $t1, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r9;
    // 0x800AF12C: jr          $ra
    // 0x800AF130: sh          $t8, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r24;
    return;
    // 0x800AF130: sh          $t8, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void interrupts_disable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F510: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006F514: lb          $t0, -0x2BD0($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2BD0);
    // 0x8006F518: beq         $t0, $zero, L_8006F534
    if (ctx->r8 == 0) {
        // 0x8006F51C: mfc0        $t0, Status
        ctx->r8 = cop0_status_read(ctx);
            goto L_8006F534;
    }
    // 0x8006F51C: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x8006F520: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8006F524: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8006F528: mtc0        $t1, Status
    cop0_status_write(ctx, ctx->r9);    // 0x8006F52C: andi        $v0, $t0, 0x1
    ctx->r2 = ctx->r8 & 0X1;
    // 0x8006F530: nop

L_8006F534:
    // 0x8006F534: jr          $ra
    // 0x8006F538: nop

    return;
    // 0x8006F538: nop

;}
RECOMP_FUNC void func_8000B750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B750: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8000B754: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000B758: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000B75C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000B760: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000B764: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x8000B768: bne         $a1, $at, L_8000B788
    if (ctx->r5 != ctx->r1) {
        // 0x8000B76C: sw          $a3, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r7;
            goto L_8000B788;
    }
    // 0x8000B76C: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x8000B770: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000B774: addiu       $v1, $v1, -0x38A0
    ctx->r3 = ADD32(ctx->r3, -0X38A0);
    // 0x8000B778: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
    // 0x8000B77C: nop

    // 0x8000B780: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x8000B784: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_8000B788:
    // 0x8000B788: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000B78C: addiu       $v1, $v1, -0x38A0
    ctx->r3 = ADD32(ctx->r3, -0X38A0);
    // 0x8000B790: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8000B794: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8000B798: bgez        $t7, L_8000B7A4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8000B79C: nop
    
            goto L_8000B7A4;
    }
    // 0x8000B79C: nop

    // 0x8000B7A0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8000B7A4:
    // 0x8000B7A4: bltz        $s0, L_8000BAD0
    if (SIGNED(ctx->r16) < 0) {
        // 0x8000B7A8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8000BAD0;
    }
    // 0x8000B7A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B7AC: beq         $at, $zero, L_8000BACC
    if (ctx->r1 == 0) {
        // 0x8000B7B0: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_8000BACC;
    }
    // 0x8000B7B0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8000B7B4: jal         0x8001E29C
    // 0x8000B7B8: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8000B7B8: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000B7BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000B7C0: addiu       $t6, $t6, -0x4FE0
    ctx->r14 = ADD32(ctx->r14, -0X4FE0);
    // 0x8000B7C4: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x8000B7C8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8000B7CC: addu        $t2, $t5, $t6
    ctx->r10 = ADD32(ctx->r13, ctx->r14);
    // 0x8000B7D0: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8000B7D4: sll         $t9, $s0, 7
    ctx->r25 = S32(ctx->r16 << 7);
    // 0x8000B7D8: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x8000B7DC: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
    // 0x8000B7E0: sll         $t8, $a1, 7
    ctx->r24 = S32(ctx->r5 << 7);
    // 0x8000B7E4: addu        $t4, $t8, $v0
    ctx->r12 = ADD32(ctx->r24, ctx->r2);
    // 0x8000B7E8: beq         $a3, $zero, L_8000BACC
    if (ctx->r7 == 0) {
        // 0x8000B7EC: or          $t3, $v1, $zero
        ctx->r11 = ctx->r3 | 0;
            goto L_8000BACC;
    }
    // 0x8000B7EC: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x8000B7F0: beq         $a2, $zero, L_8000B818
    if (ctx->r6 == 0) {
        // 0x8000B7F4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8000B818;
    }
    // 0x8000B7F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000B7F8: beq         $a2, $at, L_8000B820
    if (ctx->r6 == ctx->r1) {
        // 0x8000B7FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000B820;
    }
    // 0x8000B7FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000B800: beq         $a2, $at, L_8000B828
    if (ctx->r6 == ctx->r1) {
        // 0x8000B804: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_8000B828;
    }
    // 0x8000B804: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8000B808: beq         $a2, $at, L_8000B830
    if (ctx->r6 == ctx->r1) {
        // 0x8000B80C: addiu       $v0, $v1, 0x48
        ctx->r2 = ADD32(ctx->r3, 0X48);
            goto L_8000B830;
    }
    // 0x8000B80C: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
    // 0x8000B810: b           L_8000B830
    // 0x8000B814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B830;
    // 0x8000B814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000B818:
    // 0x8000B818: b           L_8000B830
    // 0x8000B81C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8000B830;
    // 0x8000B81C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000B820:
    // 0x8000B820: b           L_8000B830
    // 0x8000B824: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
        goto L_8000B830;
    // 0x8000B824: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
L_8000B828:
    // 0x8000B828: b           L_8000B830
    // 0x8000B82C: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
        goto L_8000B830;
    // 0x8000B82C: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
L_8000B830:
    // 0x8000B830: beq         $v0, $zero, L_8000BAB8
    if (ctx->r2 == 0) {
        // 0x8000B834: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8000BAB8;
    }
    // 0x8000B834: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B838: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8000B83C: sb          $a2, -0x4FB8($at)
    MEM_B(-0X4FB8, ctx->r1) = ctx->r6;
    // 0x8000B840: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B844: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8000B848: sb          $a1, -0x4FA8($at)
    MEM_B(-0X4FA8, ctx->r1) = ctx->r5;
    // 0x8000B84C: lbu         $t7, 0x70($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X70);
    // 0x8000B850: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000B854: bne         $t7, $at, L_8000BA18
    if (ctx->r15 != ctx->r1) {
        // 0x8000B858: lw          $a0, 0x80($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X80);
            goto L_8000BA18;
    }
    // 0x8000B858: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x8000B85C: lbu         $t8, 0x72($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X72);
    // 0x8000B860: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x8000B864: sll         $t9, $t8, 28
    ctx->r25 = S32(ctx->r24 << 28);
    // 0x8000B868: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8000B86C: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x8000B870: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x8000B874: jal         0x800707F8
    // 0x8000B878: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x8000B878: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_1:
    // 0x8000B87C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8000B880: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8000B884: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8000B888: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8000B88C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8000B890: lwc1        $f12, 0x74($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X74);
    // 0x8000B894: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8000B898: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8000B89C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8000B8A0: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8000B8A4: mul.s       $f2, $f10, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8000B8A8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8000B8AC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8000B8B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000B8B4: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8000B8B8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8000B8BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000B8C0: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x8000B8C4: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8000B8C8: addiu       $t1, $t1, -0x4FFC
    ctx->r9 = ADD32(ctx->r9, -0X4FFC);
    // 0x8000B8CC: mul.s       $f14, $f4, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8000B8D0: bne         $v1, $at, L_8000B8F4
    if (ctx->r3 != ctx->r1) {
        // 0x8000B8D4: addiu       $t0, $t0, -0x5004
        ctx->r8 = ADD32(ctx->r8, -0X5004);
            goto L_8000B8F4;
    }
    // 0x8000B8D4: addiu       $t0, $t0, -0x5004
    ctx->r8 = ADD32(ctx->r8, -0X5004);
    // 0x8000B8D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000B8DC: lwc1        $f0, 0x5130($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5130);
    // 0x8000B8E0: nop

    // 0x8000B8E4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8000B8E8: nop

    // 0x8000B8EC: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8000B8F0: nop

L_8000B8F4:
    // 0x8000B8F4: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8000B8F8: bne         $at, $zero, L_8000B91C
    if (ctx->r1 != 0) {
        // 0x8000B8FC: addiu       $t6, $zero, -0x8000
        ctx->r14 = ADD32(0, -0X8000);
            goto L_8000B91C;
    }
    // 0x8000B8FC: addiu       $t6, $zero, -0x8000
    ctx->r14 = ADD32(0, -0X8000);
    // 0x8000B900: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000B904: lwc1        $f0, 0x5134($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5134);
    // 0x8000B908: nop

    // 0x8000B90C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8000B910: nop

    // 0x8000B914: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8000B918: nop

L_8000B91C:
    // 0x8000B91C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000B920: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000B924: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x8000B928: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000B92C: lw          $v1, -0x4FF8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4FF8);
    // 0x8000B930: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x8000B934: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000B938: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8000B93C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8000B940: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8000B944: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000B948: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000B94C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8000B950: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000B954: lw          $t8, -0x38B4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X38B4);
    // 0x8000B958: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
    // 0x8000B95C: sh          $t6, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r14;
    // 0x8000B960: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8000B964: sh          $zero, 0x52($sp)
    MEM_H(0X52, ctx->r29) = 0;
    // 0x8000B968: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x8000B96C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000B970: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x8000B974: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x8000B978: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x8000B97C: addu        $a0, $t8, $t5
    ctx->r4 = ADD32(ctx->r24, ctx->r13);
    // 0x8000B980: lbu         $t8, 0x72($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X72);
    // 0x8000B984: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8000B988: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8000B98C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8000B990: sll         $t5, $t8, 12
    ctx->r13 = S32(ctx->r24 << 12);
    // 0x8000B994: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8000B998: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x8000B99C: lw          $t7, 0x7C($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X7C);
    // 0x8000B9A0: lw          $t6, -0x38AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X38AC);
    // 0x8000B9A4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8000B9A8: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x8000B9AC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8000B9B0: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8000B9B4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8000B9B8: jal         0x8000B38C
    // 0x8000B9BC: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    func_8000B38C(rdram, ctx);
        goto after_2;
    // 0x8000B9BC: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    after_2:
    // 0x8000B9C0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8000B9C4: addiu       $t0, $t0, -0x5004
    ctx->r8 = ADD32(ctx->r8, -0X5004);
    // 0x8000B9C8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8000B9CC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000B9D0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8000B9D4: addiu       $t1, $t1, -0x4FFC
    ctx->r9 = ADD32(ctx->r9, -0X4FFC);
    // 0x8000B9D8: sll         $t6, $s0, 28
    ctx->r14 = S32(ctx->r16 << 28);
    // 0x8000B9DC: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x8000B9E0: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8000B9E4: or          $t5, $t6, $t8
    ctx->r13 = ctx->r14 | ctx->r24;
    // 0x8000B9E8: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8000B9EC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8000B9F0: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x8000B9F4: sw          $t9, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = ctx->r25;
    // 0x8000B9F8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8000B9FC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8000BA00: addiu       $t5, $t8, 0x9
    ctx->r13 = ADD32(ctx->r24, 0X9);
    // 0x8000BA04: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8000BA08: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8000BA0C: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x8000BA10: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8000BA14: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
L_8000BA18:
    // 0x8000BA18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000BA1C: sw          $a0, 0x78($a3)
    MEM_W(0X78, ctx->r7) = ctx->r4;
    // 0x8000BA20: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8000BA24: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x8000BA28: swc1        $f0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f0.u32l;
    // 0x8000BA2C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8000BA30: nop

    // 0x8000BA34: swc1        $f0, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f0.u32l;
    // 0x8000BA38: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x8000BA3C: nop

    // 0x8000BA40: swc1        $f0, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f0.u32l;
    // 0x8000BA44: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000BA48: nop

    // 0x8000BA4C: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x8000BA50: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000BA54: nop

    // 0x8000BA58: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x8000BA5C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000BA60: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x8000BA64: jal         0x80070320
    // 0x8000BA68: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    vec3f_rotate(rdram, ctx);
        goto after_3;
    // 0x8000BA68: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x8000BA6C: jal         0x80011560
    // 0x8000BA70: nop

    ignore_bounds_check(rdram, ctx);
        goto after_4;
    // 0x8000BA70: nop

    after_4:
    // 0x8000BA74: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    // 0x8000BA78: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000BA7C: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000BA80: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8000BA84: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000BA88: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8000BA8C: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8000BA90: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000BA94: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8000BA98: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8000BA9C: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000BAA0: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8000BAA4: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8000BAA8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8000BAAC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8000BAB0: jal         0x80011570
    // 0x8000BAB4: nop

    move_object(rdram, ctx);
        goto after_5;
    // 0x8000BAB4: nop

    after_5:
L_8000BAB8:
    // 0x8000BAB8: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x8000BABC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BAC0: beq         $t7, $zero, L_8000BACC
    if (ctx->r15 == 0) {
        // 0x8000BAC4: addu        $at, $at, $s0
        ctx->r1 = ADD32(ctx->r1, ctx->r16);
            goto L_8000BACC;
    }
    // 0x8000BAC4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8000BAC8: sb          $zero, -0x4F98($at)
    MEM_B(-0X4F98, ctx->r1) = 0;
L_8000BACC:
    // 0x8000BACC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000BAD0:
    // 0x8000BAD0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000BAD4: jr          $ra
    // 0x8000BAD8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8000BAD8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void level_music_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BD10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BD14: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006BD18: lw          $t6, 0x1168($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1168);
    // 0x8006BD1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BD20: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8006BD24: lbu         $t7, 0x52($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X52);
    // 0x8006BD28: nop

    // 0x8006BD2C: beq         $t7, $zero, L_8006BD7C
    if (ctx->r15 == 0) {
        // 0x8006BD30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006BD7C;
    }
    // 0x8006BD30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BD34: jal         0x800012E8
    // 0x8006BD38: nop

    music_channel_reset_all(rdram, ctx);
        goto after_0;
    // 0x8006BD38: nop

    after_0:
    // 0x8006BD3C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006BD40: lw          $t8, 0x1168($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1168);
    // 0x8006BD44: nop

    // 0x8006BD48: lbu         $a0, 0x52($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X52);
    // 0x8006BD4C: jal         0x80000B34
    // 0x8006BD50: nop

    music_play(rdram, ctx);
        goto after_1;
    // 0x8006BD50: nop

    after_1:
    // 0x8006BD54: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8006BD58: jal         0x800014BC
    // 0x8006BD5C: nop

    music_tempo_set_relative(rdram, ctx);
        goto after_2;
    // 0x8006BD5C: nop

    after_2:
    // 0x8006BD60: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006BD64: lw          $t9, 0x1168($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1168);
    // 0x8006BD68: nop

    // 0x8006BD6C: lhu         $a0, 0x54($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X54);
    // 0x8006BD70: jal         0x80001074
    // 0x8006BD74: nop

    music_dynamic_set(rdram, ctx);
        goto after_3;
    // 0x8006BD74: nop

    after_3:
    // 0x8006BD78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006BD7C:
    // 0x8006BD7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BD80: jr          $ra
    // 0x8006BD84: nop

    return;
    // 0x8006BD84: nop

;}
RECOMP_FUNC void render_dialogue_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5168: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x800C516C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C5170: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C5174: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C5178: sw          $a1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r5;
    // 0x800C517C: sw          $a2, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r6;
    // 0x800C5180: bne         $a3, $zero, L_800C5190
    if (ctx->r7 != 0) {
        // 0x800C5184: sw          $a3, 0x154($sp)
        MEM_W(0X154, ctx->r29) = ctx->r7;
            goto L_800C5190;
    }
    // 0x800C5184: sw          $a3, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r7;
    // 0x800C5188: b           L_800C5418
    // 0x800C518C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C5418;
    // 0x800C518C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C5190:
    // 0x800C5190: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C5194: lw          $a0, -0x5814($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5814);
    // 0x800C5198: sll         $t7, $zero, 5
    ctx->r15 = S32(0 << 5);
    // 0x800C519C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C51A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C51A4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800C51A8: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
L_800C51AC:
    // 0x800C51AC: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800C51B0: sll         $t9, $v1, 5
    ctx->r25 = S32(ctx->r3 << 5);
    // 0x800C51B4: bne         $a1, $t8, L_800C51C0
    if (ctx->r5 != ctx->r24) {
        // 0x800C51B8: nop
    
            goto L_800C51C0;
    }
    // 0x800C51B8: nop

    // 0x800C51BC: addu        $a3, $t9, $a0
    ctx->r7 = ADD32(ctx->r25, ctx->r4);
L_800C51C0:
    // 0x800C51C0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C51C4: slti        $at, $v1, 0x40
    ctx->r1 = SIGNED(ctx->r3) < 0X40 ? 1 : 0;
    // 0x800C51C8: beq         $at, $zero, L_800C51D8
    if (ctx->r1 == 0) {
        // 0x800C51CC: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_800C51D8;
    }
    // 0x800C51CC: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800C51D0: beq         $a3, $zero, L_800C51AC
    if (ctx->r7 == 0) {
        // 0x800C51D4: nop
    
            goto L_800C51AC;
    }
    // 0x800C51D4: nop

L_800C51D8:
    // 0x800C51D8: beq         $a3, $zero, L_800C5414
    if (ctx->r7 == 0) {
        // 0x800C51DC: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_800C5414;
    }
    // 0x800C51DC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800C51E0: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x800C51E4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C51E8: lw          $t3, -0x5818($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5818);
    // 0x800C51EC: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x800C51F0: addu        $t2, $t2, $s0
    ctx->r10 = ADD32(ctx->r10, ctx->r16);
    // 0x800C51F4: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800C51F8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800C51FC: bne         $t4, $v0, L_800C5214
    if (ctx->r12 != ctx->r2) {
        // 0x800C5200: addu        $t0, $t2, $t3
        ctx->r8 = ADD32(ctx->r10, ctx->r11);
            goto L_800C5214;
    }
    // 0x800C5200: addu        $t0, $t2, $t3
    ctx->r8 = ADD32(ctx->r10, ctx->r11);
    // 0x800C5204: lh          $t5, 0xC($t0)
    ctx->r13 = MEM_H(ctx->r8, 0XC);
    // 0x800C5208: nop

    // 0x800C520C: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800C5210: sw          $t6, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r14;
L_800C5214:
    // 0x800C5214: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800C5218: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C521C: bne         $t7, $v0, L_800C5234
    if (ctx->r15 != ctx->r2) {
        // 0x800C5220: nop
    
            goto L_800C5234;
    }
    // 0x800C5220: nop

    // 0x800C5224: lh          $t8, 0xE($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XE);
    // 0x800C5228: nop

    // 0x800C522C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800C5230: sw          $t9, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r25;
L_800C5234:
    // 0x800C5234: lbu         $v0, 0x1D($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X1D);
    // 0x800C5238: lw          $v1, 0x15C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X15C);
    // 0x800C523C: beq         $a1, $v0, L_800C52FC
    if (ctx->r5 == ctx->r2) {
        // 0x800C5240: sll         $t2, $v0, 10
        ctx->r10 = S32(ctx->r2 << 10);
            goto L_800C52FC;
    }
    // 0x800C5240: sll         $t2, $v0, 10
    ctx->r10 = S32(ctx->r2 << 10);
    // 0x800C5244: lw          $t3, -0x581C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X581C);
    // 0x800C5248: andi        $t4, $v1, 0x5
    ctx->r12 = ctx->r3 & 0X5;
    // 0x800C524C: beq         $t4, $zero, L_800C52BC
    if (ctx->r12 == 0) {
        // 0x800C5250: addu        $t1, $t2, $t3
        ctx->r9 = ADD32(ctx->r10, ctx->r11);
            goto L_800C52BC;
    }
    // 0x800C5250: addu        $t1, $t2, $t3
    ctx->r9 = ADD32(ctx->r10, ctx->r11);
    // 0x800C5254: lw          $a2, 0x158($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X158);
    // 0x800C5258: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800C525C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800C5260: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C5264: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800C5268: jal         0x800C5F60
    // 0x800C526C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    parse_string_with_number(rdram, ctx);
        goto after_0;
    // 0x800C526C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_0:
    // 0x800C5270: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C5274: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x800C5278: lbu         $a2, 0x1D($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X1D);
    // 0x800C527C: jal         0x800C4DA0
    // 0x800C5280: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    get_text_width(rdram, ctx);
        goto after_1;
    // 0x800C5280: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x800C5284: lw          $v1, 0x15C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X15C);
    // 0x800C5288: lw          $a0, 0x14C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X14C);
    // 0x800C528C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800C5290: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C5294: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5298: andi        $t5, $v1, 0x1
    ctx->r13 = ctx->r3 & 0X1;
    // 0x800C529C: beq         $t5, $zero, L_800C52B4
    if (ctx->r13 == 0) {
        // 0x800C52A0: sra         $t6, $v0, 1
        ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800C52B4;
    }
    // 0x800C52A0: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800C52A4: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800C52A8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C52AC: b           L_800C52BC
    // 0x800C52B0: sw          $a0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r4;
        goto L_800C52BC;
    // 0x800C52B0: sw          $a0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r4;
L_800C52B4:
    // 0x800C52B4: subu        $a0, $a0, $t6
    ctx->r4 = SUB32(ctx->r4, ctx->r14);
    // 0x800C52B8: sw          $a0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r4;
L_800C52BC:
    // 0x800C52BC: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x800C52C0: beq         $t7, $zero, L_800C52E0
    if (ctx->r15 == 0) {
        // 0x800C52C4: andi        $t4, $v1, 0x8
        ctx->r12 = ctx->r3 & 0X8;
            goto L_800C52E0;
    }
    // 0x800C52C4: andi        $t4, $v1, 0x8
    ctx->r12 = ctx->r3 & 0X8;
    // 0x800C52C8: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x800C52CC: lhu         $t9, 0x22($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X22);
    // 0x800C52D0: nop

    // 0x800C52D4: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x800C52D8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C52DC: sw          $t3, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r11;
L_800C52E0:
    // 0x800C52E0: beq         $t4, $zero, L_800C52FC
    if (ctx->r12 == 0) {
        // 0x800C52E4: nop
    
            goto L_800C52FC;
    }
    // 0x800C52E4: nop

    // 0x800C52E8: lhu         $t6, 0x22($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0X22);
    // 0x800C52EC: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800C52F0: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800C52F4: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x800C52F8: sw          $t8, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r24;
L_800C52FC:
    // 0x800C52FC: lw          $a0, 0x24($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X24);
    // 0x800C5300: lw          $s0, 0x158($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X158);
    // 0x800C5304: bne         $a0, $zero, L_800C5318
    if (ctx->r4 != 0) {
        // 0x800C5308: addiu       $v1, $t0, 0x24
        ctx->r3 = ADD32(ctx->r8, 0X24);
            goto L_800C5318;
    }
    // 0x800C5308: addiu       $v1, $t0, 0x24
    ctx->r3 = ADD32(ctx->r8, 0X24);
    // 0x800C530C: sw          $a3, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r7;
    // 0x800C5310: b           L_800C5364
    // 0x800C5314: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800C5364;
    // 0x800C5314: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800C5318:
    // 0x800C5318: beq         $a0, $zero, L_800C535C
    if (ctx->r4 == 0) {
        // 0x800C531C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800C535C;
    }
    // 0x800C531C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800C5320: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x800C5324: nop

    // 0x800C5328: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C532C: beq         $at, $zero, L_800C535C
    if (ctx->r1 == 0) {
        // 0x800C5330: nop
    
            goto L_800C535C;
    }
    // 0x800C5330: nop

L_800C5334:
    // 0x800C5334: addiu       $v1, $v0, 0x1C
    ctx->r3 = ADD32(ctx->r2, 0X1C);
    // 0x800C5338: lw          $v0, 0x1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1C);
    // 0x800C533C: nop

    // 0x800C5340: beq         $v0, $zero, L_800C535C
    if (ctx->r2 == 0) {
        // 0x800C5344: nop
    
            goto L_800C535C;
    }
    // 0x800C5344: nop

    // 0x800C5348: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x800C534C: nop

    // 0x800C5350: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800C5354: bne         $at, $zero, L_800C5334
    if (ctx->r1 != 0) {
        // 0x800C5358: nop
    
            goto L_800C5334;
    }
    // 0x800C5358: nop

L_800C535C:
    // 0x800C535C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800C5360: sw          $v0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r2;
L_800C5364:
    // 0x800C5364: sb          $s0, 0x1($a3)
    MEM_B(0X1, ctx->r7) = ctx->r16;
    // 0x800C5368: lw          $t3, 0x154($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X154);
    // 0x800C536C: nop

    // 0x800C5370: sw          $t3, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r11;
    // 0x800C5374: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x800C5378: nop

    // 0x800C537C: sh          $t4, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r12;
    // 0x800C5380: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x800C5384: sh          $zero, 0xC($a3)
    MEM_H(0XC, ctx->r7) = 0;
    // 0x800C5388: sh          $zero, 0xE($a3)
    MEM_H(0XE, ctx->r7) = 0;
    // 0x800C538C: sh          $t6, 0xA($a3)
    MEM_H(0XA, ctx->r7) = ctx->r14;
    // 0x800C5390: lbu         $t5, 0x14($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X14);
    // 0x800C5394: nop

    // 0x800C5398: sb          $t5, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r13;
    // 0x800C539C: lbu         $t7, 0x15($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X15);
    // 0x800C53A0: nop

    // 0x800C53A4: sb          $t7, 0x11($a3)
    MEM_B(0X11, ctx->r7) = ctx->r15;
    // 0x800C53A8: lbu         $t8, 0x16($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X16);
    // 0x800C53AC: nop

    // 0x800C53B0: sb          $t8, 0x12($a3)
    MEM_B(0X12, ctx->r7) = ctx->r24;
    // 0x800C53B4: lbu         $t9, 0x17($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X17);
    // 0x800C53B8: nop

    // 0x800C53BC: sb          $t9, 0x13($a3)
    MEM_B(0X13, ctx->r7) = ctx->r25;
    // 0x800C53C0: lbu         $t2, 0x18($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X18);
    // 0x800C53C4: nop

    // 0x800C53C8: sb          $t2, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r10;
    // 0x800C53CC: lbu         $t3, 0x19($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X19);
    // 0x800C53D0: nop

    // 0x800C53D4: sb          $t3, 0x15($a3)
    MEM_B(0X15, ctx->r7) = ctx->r11;
    // 0x800C53D8: lbu         $t4, 0x1A($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X1A);
    // 0x800C53DC: nop

    // 0x800C53E0: sb          $t4, 0x16($a3)
    MEM_B(0X16, ctx->r7) = ctx->r12;
    // 0x800C53E4: lbu         $t6, 0x1B($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X1B);
    // 0x800C53E8: nop

    // 0x800C53EC: sb          $t6, 0x17($a3)
    MEM_B(0X17, ctx->r7) = ctx->r14;
    // 0x800C53F0: lbu         $t5, 0x1C($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X1C);
    // 0x800C53F4: nop

    // 0x800C53F8: sb          $t5, 0x18($a3)
    MEM_B(0X18, ctx->r7) = ctx->r13;
    // 0x800C53FC: lbu         $t7, 0x1D($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X1D);
    // 0x800C5400: nop

    // 0x800C5404: sb          $t7, 0x19($a3)
    MEM_B(0X19, ctx->r7) = ctx->r15;
    // 0x800C5408: lhu         $t8, 0x1E($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X1E);
    // 0x800C540C: nop

    // 0x800C5410: sh          $t8, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r24;
L_800C5414:
    // 0x800C5414: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800C5418:
    // 0x800C5418: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C541C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C5420: jr          $ra
    // 0x800C5424: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x800C5424: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void func_8006C300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C300: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006C304: addiu       $a0, $a0, -0x2CD0
    ctx->r4 = ADD32(ctx->r4, -0X2CD0);
    // 0x8006C308: lb          $v1, 0x0($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X0);
    // 0x8006C30C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006C310: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8006C314: bne         $at, $zero, L_8006C324
    if (ctx->r1 != 0) {
        // 0x8006C318: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006C324;
    }
    // 0x8006C318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006C31C: jr          $ra
    // 0x8006C320: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    return;
    // 0x8006C320: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
L_8006C324:
    // 0x8006C324: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006C328: jr          $ra
    // 0x8006C32C: nop

    return;
    // 0x8006C32C: nop

;}
RECOMP_FUNC void alEnvmixerParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAA7C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CAA80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CAA84: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800CAA88: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800CAA8C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800CAA90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CAA94: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800CAA98: nop

    // 0x800CAA9C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800CAAA0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800CAAA4: nop

    // 0x800CAAA8: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800CAAAC: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800CAAB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CAAB4: beq         $s0, $at, L_800CABEC
    if (ctx->r16 == ctx->r1) {
        // 0x800CAAB8: nop
    
            goto L_800CABEC;
    }
    // 0x800CAAB8: nop

    // 0x800CAABC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CAAC0: beq         $s0, $at, L_800CAAE8
    if (ctx->r16 == ctx->r1) {
        // 0x800CAAC4: nop
    
            goto L_800CAAE8;
    }
    // 0x800CAAC4: nop

    // 0x800CAAC8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800CAACC: beq         $s0, $at, L_800CAB3C
    if (ctx->r16 == ctx->r1) {
        // 0x800CAAD0: nop
    
            goto L_800CAB3C;
    }
    // 0x800CAAD0: nop

    // 0x800CAAD4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800CAAD8: beq         $s0, $at, L_800CABA0
    if (ctx->r16 == ctx->r1) {
        // 0x800CAADC: nop
    
            goto L_800CABA0;
    }
    // 0x800CAADC: nop

    // 0x800CAAE0: b           L_800CAC04
    // 0x800CAAE4: nop

        goto L_800CAC04;
    // 0x800CAAE4: nop

L_800CAAE8:
    // 0x800CAAE8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800CAAEC: nop

    // 0x800CAAF0: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x800CAAF4: nop

    // 0x800CAAF8: beq         $t9, $zero, L_800CAB14
    if (ctx->r25 == 0) {
        // 0x800CAAFC: nop
    
            goto L_800CAB14;
    }
    // 0x800CAAFC: nop

    // 0x800CAB00: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800CAB04: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800CAB08: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x800CAB0C: b           L_800CAB24
    // 0x800CAB10: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
        goto L_800CAB24;
    // 0x800CAB10: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
L_800CAB14:
    // 0x800CAB14: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800CAB18: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800CAB1C: nop

    // 0x800CAB20: sw          $t3, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r11;
L_800CAB24:
    // 0x800CAB24: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800CAB28: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800CAB2C: nop

    // 0x800CAB30: sw          $t5, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->r13;
    // 0x800CAB34: b           L_800CAC3C
    // 0x800CAB38: nop

        goto L_800CAC3C;
    // 0x800CAB38: nop

L_800CAB3C:
    // 0x800CAB3C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800CAB40: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800CAB44: sw          $t7, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->r15;
    // 0x800CAB48: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800CAB4C: nop

    // 0x800CAB50: sw          $zero, 0x48($t9)
    MEM_W(0X48, ctx->r25) = 0;
    // 0x800CAB54: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800CAB58: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800CAB5C: sh          $t1, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = ctx->r9;
    // 0x800CAB60: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800CAB64: nop

    // 0x800CAB68: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800CAB6C: nop

    // 0x800CAB70: beq         $t3, $zero, L_800CAB98
    if (ctx->r11 == 0) {
        // 0x800CAB74: nop
    
            goto L_800CAB98;
    }
    // 0x800CAB74: nop

    // 0x800CAB78: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800CAB7C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800CAB80: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800CAB84: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800CAB88: lw          $t9, 0x8($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X8);
    // 0x800CAB8C: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800CAB90: jalr        $t9
    // 0x800CAB94: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CAB94: nop

    after_0:
L_800CAB98:
    // 0x800CAB98: b           L_800CAC3C
    // 0x800CAB9C: nop

        goto L_800CAC3C;
    // 0x800CAB9C: nop

L_800CABA0:
    // 0x800CABA0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800CABA4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CABA8: sw          $t6, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->r14;
    // 0x800CABAC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800CABB0: nop

    // 0x800CABB4: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x800CABB8: nop

    // 0x800CABBC: beq         $t1, $zero, L_800CABE4
    if (ctx->r9 == 0) {
        // 0x800CABC0: nop
    
            goto L_800CABE4;
    }
    // 0x800CABC0: nop

    // 0x800CABC4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800CABC8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800CABCC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800CABD0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CABD4: lw          $t9, 0x8($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X8);
    // 0x800CABD8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800CABDC: jalr        $t9
    // 0x800CABE0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CABE0: nop

    after_1:
L_800CABE4:
    // 0x800CABE4: b           L_800CAC3C
    // 0x800CABE8: nop

        goto L_800CAC3C;
    // 0x800CABE8: nop

L_800CABEC:
    // 0x800CABEC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800CABF0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800CABF4: nop

    // 0x800CABF8: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800CABFC: b           L_800CAC3C
    // 0x800CAC00: nop

        goto L_800CAC3C;
    // 0x800CAC00: nop

L_800CAC04:
    // 0x800CAC04: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800CAC08: nop

    // 0x800CAC0C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800CAC10: nop

    // 0x800CAC14: beq         $t6, $zero, L_800CAC3C
    if (ctx->r14 == 0) {
        // 0x800CAC18: nop
    
            goto L_800CAC3C;
    }
    // 0x800CAC18: nop

    // 0x800CAC1C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800CAC20: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800CAC24: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800CAC28: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800CAC2C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800CAC30: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800CAC34: jalr        $t9
    // 0x800CAC38: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800CAC38: nop

    after_2:
L_800CAC3C:
    // 0x800CAC3C: b           L_800CAC4C
    // 0x800CAC40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CAC4C;
    // 0x800CAC40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CAC44: b           L_800CAC4C
    // 0x800CAC48: nop

        goto L_800CAC4C;
    // 0x800CAC48: nop

L_800CAC4C:
    // 0x800CAC4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CAC50: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CAC54: jr          $ra
    // 0x800CAC58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800CAC58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void menu_boot_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008860C: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80088610: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80088614: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80088618: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008861C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80088620: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80088624: bne         $t6, $zero, L_80088630
    if (ctx->r14 != 0) {
        // 0x80088628: addiu       $v1, $zero, 0x78
        ctx->r3 = ADD32(0, 0X78);
            goto L_80088630;
    }
    // 0x80088628: addiu       $v1, $zero, 0x78
    ctx->r3 = ADD32(0, 0X78);
    // 0x8008862C: addiu       $v1, $zero, 0x84
    ctx->r3 = ADD32(0, 0X84);
L_80088630:
    // 0x80088630: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80088634: lw          $v0, 0x6C20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6C20);
    // 0x80088638: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8008863C: beq         $v0, $zero, L_80088664
    if (ctx->r2 == 0) {
        // 0x80088640: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80088664;
    }
    // 0x80088640: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80088644: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80088648: beq         $v0, $at, L_800886B0
    if (ctx->r2 == ctx->r1) {
        // 0x8008864C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800886B0;
    }
    // 0x8008864C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80088650: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80088654: beq         $v0, $at, L_80088718
    if (ctx->r2 == ctx->r1) {
        // 0x80088658: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_80088718;
    }
    // 0x80088658: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8008865C: b           L_8008876C
    // 0x80088660: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
        goto L_8008876C;
    // 0x80088660: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
L_80088664:
    // 0x80088664: addiu       $v1, $v1, 0x6C18
    ctx->r3 = ADD32(ctx->r3, 0X6C18);
    // 0x80088668: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008866C: nop

    // 0x80088670: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80088674: beq         $at, $zero, L_80088694
    if (ctx->r1 == 0) {
        // 0x80088678: addu        $t7, $v0, $a1
        ctx->r15 = ADD32(ctx->r2, ctx->r5);
            goto L_80088694;
    }
    // 0x80088678: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x8008867C: slti        $at, $t7, 0x21
    ctx->r1 = SIGNED(ctx->r15) < 0X21 ? 1 : 0;
    // 0x80088680: bne         $at, $zero, L_80088768
    if (ctx->r1 != 0) {
        // 0x80088684: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80088768;
    }
    // 0x80088684: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80088688: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x8008868C: b           L_80088768
    // 0x80088690: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_80088768;
    // 0x80088690: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_80088694:
    // 0x80088694: jal         0x800887E8
    // 0x80088698: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    bootscreen_init_cpak(rdram, ctx);
        goto after_0;
    // 0x80088698: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008869C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800886A0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800886A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800886A8: b           L_80088768
    // 0x800886AC: sw          $t0, 0x6C20($at)
    MEM_W(0X6C20, ctx->r1) = ctx->r8;
        goto L_80088768;
    // 0x800886AC: sw          $t0, 0x6C20($at)
    MEM_W(0X6C20, ctx->r1) = ctx->r8;
L_800886B0:
    // 0x800886B0: addiu       $v1, $v1, 0x6C18
    ctx->r3 = ADD32(ctx->r3, 0X6C18);
    // 0x800886B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800886B8: nop

    // 0x800886BC: slti        $at, $v0, 0x8C
    ctx->r1 = SIGNED(ctx->r2) < 0X8C ? 1 : 0;
    // 0x800886C0: beq         $at, $zero, L_800886E4
    if (ctx->r1 == 0) {
        // 0x800886C4: addu        $t1, $v0, $a1
        ctx->r9 = ADD32(ctx->r2, ctx->r5);
            goto L_800886E4;
    }
    // 0x800886C4: addu        $t1, $v0, $a1
    ctx->r9 = ADD32(ctx->r2, ctx->r5);
    // 0x800886C8: slti        $at, $t1, 0x8D
    ctx->r1 = SIGNED(ctx->r9) < 0X8D ? 1 : 0;
    // 0x800886CC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800886D0: bne         $at, $zero, L_80088704
    if (ctx->r1 != 0) {
        // 0x800886D4: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80088704;
    }
    // 0x800886D4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800886D8: addiu       $v0, $zero, 0x8C
    ctx->r2 = ADD32(0, 0X8C);
    // 0x800886DC: b           L_80088704
    // 0x800886E0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80088704;
    // 0x800886E0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800886E4:
    // 0x800886E4: jal         0x800887C4
    // 0x800886E8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    bootscreen_free(rdram, ctx);
        goto after_1;
    // 0x800886E8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x800886EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800886F0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800886F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800886F8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800886FC: lw          $v0, 0x6C18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6C18);
    // 0x80088700: sw          $t3, 0x6C20($at)
    MEM_W(0X6C20, ctx->r1) = ctx->r11;
L_80088704:
    // 0x80088704: slti        $at, $v0, 0x81
    ctx->r1 = SIGNED(ctx->r2) < 0X81 ? 1 : 0;
    // 0x80088708: bne         $at, $zero, L_8008876C
    if (ctx->r1 != 0) {
        // 0x8008870C: slti        $at, $a3, 0x12C
        ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
            goto L_8008876C;
    }
    // 0x8008870C: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
    // 0x80088710: b           L_80088768
    // 0x80088714: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
        goto L_80088768;
    // 0x80088714: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
L_80088718:
    // 0x80088718: lw          $t4, -0xB84($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB84);
    // 0x8008871C: nop

    // 0x80088720: beq         $t4, $zero, L_80088754
    if (ctx->r12 == 0) {
        // 0x80088724: addiu       $a3, $zero, 0x12C
        ctx->r7 = ADD32(0, 0X12C);
            goto L_80088754;
    }
    // 0x80088724: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
    // 0x80088728: jal         0x800C018C
    // 0x8008872C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    check_fadeout_transition(rdram, ctx);
        goto after_2;
    // 0x8008872C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_2:
    // 0x80088730: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80088734: bne         $v0, $zero, L_80088750
    if (ctx->r2 != 0) {
        // 0x80088738: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80088750;
    }
    // 0x80088738: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008873C: addiu       $a0, $a0, -0x894
    ctx->r4 = ADD32(ctx->r4, -0X894);
    // 0x80088740: jal         0x800C01D8
    // 0x80088744: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x80088744: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_3:
    // 0x80088748: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8008874C: nop

L_80088750:
    // 0x80088750: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
L_80088754:
    // 0x80088754: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80088758: jal         0x800890AC
    // 0x8008875C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    menu_controller_pak_loop(rdram, ctx);
        goto after_4;
    // 0x8008875C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x80088760: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80088764: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80088768:
    // 0x80088768: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
L_8008876C:
    // 0x8008876C: beq         $at, $zero, L_800887B4
    if (ctx->r1 == 0) {
        // 0x80088770: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800887B4;
    }
    // 0x80088770: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088774: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80088778: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8008877C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80088780: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80088784: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80088788: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8008878C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80088790: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80088794: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80088798: addiu       $a1, $a1, -0x824
    ctx->r5 = ADD32(ctx->r5, -0X824);
    // 0x8008879C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x800887A0: jal         0x80078AB8
    // 0x800887A4: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    texrect_draw(rdram, ctx);
        goto after_5;
    // 0x800887A4: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    after_5:
    // 0x800887A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800887AC: jal         0x8007B3D0
    // 0x800887B0: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    rendermode_reset(rdram, ctx);
        goto after_6;
    // 0x800887B0: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    after_6:
L_800887B4:
    // 0x800887B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800887B8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800887BC: jr          $ra
    // 0x800887C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800887C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8000E79C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E79C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000E7A0: lw          $a2, -0x5140($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5140);
    // 0x8000E7A4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000E7A8: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8000E7AC: addiu       $t8, $t8, -0x5160
    ctx->r24 = ADD32(ctx->r24, -0X5160);
    // 0x8000E7B0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000E7B4: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8000E7B8: lbu         $v1, 0x1($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X1);
    // 0x8000E7BC: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x8000E7C0: addu        $t1, $t0, $t8
    ctx->r9 = ADD32(ctx->r8, ctx->r24);
    // 0x8000E7C4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8000E7C8: lw          $t5, -0x5150($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5150);
    // 0x8000E7CC: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x8000E7D0: andi        $t7, $v1, 0x3F
    ctx->r15 = ctx->r3 & 0X3F;
    // 0x8000E7D4: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000E7D8: addu        $a3, $t9, $t5
    ctx->r7 = ADD32(ctx->r25, ctx->r13);
    // 0x8000E7DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000E7E0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8000E7E4: beq         $at, $zero, L_8000E820
    if (ctx->r1 == 0) {
        // 0x8000E7E8: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8000E820;
    }
    // 0x8000E7E8: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8000E7EC: addu        $t0, $a0, $t6
    ctx->r8 = ADD32(ctx->r4, ctx->r14);
    // 0x8000E7F0: sltu        $at, $t0, $a3
    ctx->r1 = ctx->r8 < ctx->r7 ? 1 : 0;
    // 0x8000E7F4: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x8000E7F8: beq         $at, $zero, L_8000E858
    if (ctx->r1 == 0) {
        // 0x8000E7FC: or          $t2, $a3, $zero
        ctx->r10 = ctx->r7 | 0;
            goto L_8000E858;
    }
    // 0x8000E7FC: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
L_8000E800:
    // 0x8000E800: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x8000E804: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000E808: sltu        $at, $t0, $t2
    ctx->r1 = ctx->r8 < ctx->r10 ? 1 : 0;
    // 0x8000E80C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000E810: bne         $at, $zero, L_8000E800
    if (ctx->r1 != 0) {
        // 0x8000E814: sb          $t6, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r14;
            goto L_8000E800;
    }
    // 0x8000E814: sb          $t6, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r14;
    // 0x8000E818: b           L_8000E85C
    // 0x8000E81C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_8000E85C;
    // 0x8000E81C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000E820:
    // 0x8000E820: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000E824: beq         $at, $zero, L_8000E858
    if (ctx->r1 == 0) {
        // 0x8000E828: addu        $t7, $a3, $v1
        ctx->r15 = ADD32(ctx->r7, ctx->r3);
            goto L_8000E858;
    }
    // 0x8000E828: addu        $t7, $a3, $v1
    ctx->r15 = ADD32(ctx->r7, ctx->r3);
    // 0x8000E82C: subu        $a2, $t7, $v0
    ctx->r6 = SUB32(ctx->r15, ctx->r2);
    // 0x8000E830: addu        $t2, $a0, $v1
    ctx->r10 = ADD32(ctx->r4, ctx->r3);
    // 0x8000E834: sltu        $at, $t2, $a2
    ctx->r1 = ctx->r10 < ctx->r6 ? 1 : 0;
    // 0x8000E838: beq         $at, $zero, L_8000E858
    if (ctx->r1 == 0) {
        // 0x8000E83C: or          $t0, $a3, $zero
        ctx->r8 = ctx->r7 | 0;
            goto L_8000E858;
    }
    // 0x8000E83C: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
L_8000E840:
    // 0x8000E840: lbu         $t8, -0x1($t0)
    ctx->r24 = MEM_BU(ctx->r8, -0X1);
    // 0x8000E844: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8000E848: sltu        $at, $t2, $a2
    ctx->r1 = ctx->r10 < ctx->r6 ? 1 : 0;
    // 0x8000E84C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8000E850: bne         $at, $zero, L_8000E840
    if (ctx->r1 != 0) {
        // 0x8000E854: sb          $t8, 0x0($a2)
        MEM_B(0X0, ctx->r6) = ctx->r24;
            goto L_8000E840;
    }
    // 0x8000E854: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
L_8000E858:
    // 0x8000E858: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000E85C:
    // 0x8000E85C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000E860: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_8000E864:
    // 0x8000E864: lbu         $t9, 0x0($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X0);
    // 0x8000E868: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000E86C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000E870: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8000E874: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000E878: bne         $at, $zero, L_8000E864
    if (ctx->r1 != 0) {
        // 0x8000E87C: sb          $t9, -0x1($a3)
        MEM_B(-0X1, ctx->r7) = ctx->r25;
            goto L_8000E864;
    }
    // 0x8000E87C: sb          $t9, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r25;
    // 0x8000E880: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8000E884: nop

    // 0x8000E888: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8000E88C: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x8000E890: jr          $ra
    // 0x8000E894: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    return;
    // 0x8000E894: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
;}
RECOMP_FUNC void texrect_draw_scaled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_hud_rect_begin(uint8_t*, recomp_context*, int); dkr_hud_rect_begin(rdram, ctx, 1);
    // 0x80078D00: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80078D04: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80078D08: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80078D0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80078D10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80078D14: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80078D18: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80078D1C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80078D20: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80078D24: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80078D28: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80078D2C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80078D30: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80078D34: sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // 0x80078D38: jal         0x8007A520
    // 0x80078D3C: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80078D3C: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    after_0:
    extern void dkr_hud_rect_extent(uint8_t*, recomp_context*); dkr_hud_rect_extent(rdram, ctx);
    // 0x80078D40: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x80078D44: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80078D48: andi        $t6, $t1, 0xFF
    ctx->r14 = ctx->r9 & 0XFF;
    // 0x80078D4C: bne         $t6, $at, L_80078D74
    if (ctx->r14 != ctx->r1) {
        // 0x80078D50: lw          $t0, 0xCC($sp)
        ctx->r8 = MEM_W(ctx->r29, 0XCC);
            goto L_80078D74;
    }
    // 0x80078D50: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x80078D54: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x80078D58: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80078D5C: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x80078D60: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80078D64: addiu       $t6, $t6, -0x1958
    ctx->r14 = ADD32(ctx->r14, -0X1958);
    // 0x80078D68: b           L_80078D88
    // 0x80078D6C: addu        $a3, $t9, $t6
    ctx->r7 = ADD32(ctx->r25, ctx->r14);
        goto L_80078D88;
    // 0x80078D6C: addu        $a3, $t9, $t6
    ctx->r7 = ADD32(ctx->r25, ctx->r14);
    // 0x80078D70: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
L_80078D74:
    // 0x80078D74: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80078D78: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x80078D7C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80078D80: addiu       $t6, $t6, -0x1918
    ctx->r14 = ADD32(ctx->r14, -0X1918);
    // 0x80078D84: addu        $a3, $t9, $t6
    ctx->r7 = ADD32(ctx->r25, ctx->r14);
L_80078D88:
    // 0x80078D88: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80078D8C: lwc1        $f0, 0xC0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80078D90: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x80078D94: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80078D98: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80078D9C: addiu       $t9, $t9, -0x1990
    ctx->r25 = ADD32(ctx->r25, -0X1990);
    // 0x80078DA0: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80078DA4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80078DA8: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80078DAC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80078DB0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80078DB4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80078DB8: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80078DBC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80078DC0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80078DC4: lui         $t7, 0x702
    ctx->r15 = S32(0X702 << 16);
    // 0x80078DC8: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x80078DCC: addu        $t8, $a3, $at
    ctx->r24 = ADD32(ctx->r7, ctx->r1);
    // 0x80078DD0: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80078DD4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80078DD8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80078DDC: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80078DE0: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x80078DE4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80078DE8: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80078DEC: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x80078DF0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80078DF4: lwc1        $f2, 0xC4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80078DF8: lw          $ra, 0x0($s2)
    ctx->r31 = MEM_W(ctx->r18, 0X0);
    // 0x80078DFC: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80078E00: beq         $ra, $zero, L_800792E0
    if (ctx->r31 == 0) {
        // 0x80078E04: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_800792E0;
    }
    // 0x80078E04: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80078E08: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80078E0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80078E10: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80078E14: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80078E18: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x80078E1C: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80078E20: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80078E24: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80078E28: lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X80);
    // 0x80078E2C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80078E30: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80078E34: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80078E38: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80078E3C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80078E40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80078E44: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80078E48: mfc1        $s7, $f10
    ctx->r23 = (int32_t)ctx->f10.u32l;
    // 0x80078E4C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80078E50: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x80078E54: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x80078E58: andi        $s5, $t0, 0x1000
    ctx->r21 = ctx->r8 & 0X1000;
    // 0x80078E5C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80078E60: andi        $s6, $t0, 0x2000
    ctx->r22 = ctx->r8 & 0X2000;
    // 0x80078E64: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80078E68: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80078E6C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80078E70: nop

    // 0x80078E74: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80078E78: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80078E7C: mfc1        $fp, $f6
    ctx->r30 = (int32_t)ctx->f6.u32l;
    // 0x80078E80: nop

L_80078E84:
    // 0x80078E84: bne         $s5, $zero, L_80078ED0
    if (ctx->r21 != 0) {
        // 0x80078E88: nop
    
            goto L_80078ED0;
    }
    // 0x80078E88: nop

    // 0x80078E8C: lh          $t7, 0x4($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X4);
    // 0x80078E90: nop

    // 0x80078E94: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80078E98: nop

    // 0x80078E9C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80078EA0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80078EA4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80078EA8: nop

    // 0x80078EAC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80078EB0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80078EB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80078EB8: nop

    // 0x80078EBC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80078EC0: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80078EC4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80078EC8: b           L_80078F54
    // 0x80078ECC: addu        $t3, $t9, $s7
    ctx->r11 = ADD32(ctx->r25, ctx->r23);
        goto L_80078F54;
    // 0x80078ECC: addu        $t3, $t9, $s7
    ctx->r11 = ADD32(ctx->r25, ctx->r23);
L_80078ED0:
    // 0x80078ED0: lh          $t6, 0x4($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4);
    // 0x80078ED4: lbu         $t9, 0x0($ra)
    ctx->r25 = MEM_BU(ctx->r31, 0X0);
    // 0x80078ED8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80078EDC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80078EE0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80078EE4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80078EE8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80078EEC: nop

    // 0x80078EF0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80078EF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80078EF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80078EFC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80078F00: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80078F04: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80078F08: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80078F0C: subu        $s2, $s7, $t8
    ctx->r18 = SUB32(ctx->r23, ctx->r24);
    // 0x80078F10: bgez        $t9, L_80078F24
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80078F14: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80078F24;
    }
    // 0x80078F14: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80078F18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80078F1C: nop

    // 0x80078F20: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80078F24:
    // 0x80078F24: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80078F28: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80078F2C: nop

    // 0x80078F30: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80078F34: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80078F38: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80078F3C: nop

    // 0x80078F40: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80078F44: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80078F48: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80078F4C: subu        $t3, $s2, $t7
    ctx->r11 = SUB32(ctx->r18, ctx->r15);
    // 0x80078F50: nop

L_80078F54:
    // 0x80078F54: bne         $s6, $zero, L_80078FA0
    if (ctx->r22 != 0) {
        // 0x80078F58: nop
    
            goto L_80078FA0;
    }
    // 0x80078F58: nop

    // 0x80078F5C: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x80078F60: nop

    // 0x80078F64: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80078F68: nop

    // 0x80078F6C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80078F70: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80078F74: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80078F78: nop

    // 0x80078F7C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80078F80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80078F84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80078F88: nop

    // 0x80078F8C: cvt.w.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80078F90: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80078F94: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80078F98: b           L_80079024
    // 0x80078F9C: addu        $t2, $t6, $fp
    ctx->r10 = ADD32(ctx->r14, ctx->r30);
        goto L_80079024;
    // 0x80078F9C: addu        $t2, $t6, $fp
    ctx->r10 = ADD32(ctx->r14, ctx->r30);
L_80078FA0:
    // 0x80078FA0: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x80078FA4: lbu         $t6, 0x1($ra)
    ctx->r14 = MEM_BU(ctx->r31, 0X1);
    // 0x80078FA8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80078FAC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80078FB0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80078FB4: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80078FB8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80078FBC: nop

    // 0x80078FC0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80078FC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80078FC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80078FCC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80078FD0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80078FD4: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80078FD8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80078FDC: subu        $s3, $fp, $t9
    ctx->r19 = SUB32(ctx->r30, ctx->r25);
    // 0x80078FE0: bgez        $t6, L_80078FF4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80078FE4: cvt.s.w     $f18, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80078FF4;
    }
    // 0x80078FE4: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80078FE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80078FEC: nop

    // 0x80078FF0: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_80078FF4:
    // 0x80078FF4: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80078FF8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80078FFC: nop

    // 0x80079000: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80079004: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80079008: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007900C: nop

    // 0x80079010: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80079014: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80079018: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8007901C: subu        $t2, $s3, $t8
    ctx->r10 = SUB32(ctx->r19, ctx->r24);
    // 0x80079020: nop

L_80079024:
    // 0x80079024: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80079028: sra         $t6, $v0, 16
    ctx->r14 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007902C: slt         $at, $t3, $t9
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80079030: beq         $at, $zero, L_800792C8
    if (ctx->r1 == 0) {
        // 0x80079034: andi        $t7, $t6, 0xFFFF
        ctx->r15 = ctx->r14 & 0XFFFF;
            goto L_800792C8;
    }
    // 0x80079034: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80079038: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007903C: slt         $at, $t2, $t8
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80079040: beq         $at, $zero, L_800792C8
    if (ctx->r1 == 0) {
        // 0x80079044: nop
    
            goto L_800792C8;
    }
    // 0x80079044: nop

    // 0x80079048: bne         $s5, $zero, L_800790A0
    if (ctx->r21 != 0) {
        // 0x8007904C: nop
    
            goto L_800790A0;
    }
    // 0x8007904C: nop

    // 0x80079050: lbu         $t9, 0x0($ra)
    ctx->r25 = MEM_BU(ctx->r31, 0X0);
    // 0x80079054: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80079058: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8007905C: bgez        $t9, L_80079070
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80079060: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80079070;
    }
    // 0x80079060: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80079064: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80079068: nop

    // 0x8007906C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80079070:
    // 0x80079070: mul.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80079074: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80079078: nop

    // 0x8007907C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80079080: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80079084: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80079088: nop

    // 0x8007908C: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80079090: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80079094: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80079098: addu        $s2, $t7, $t3
    ctx->r18 = ADD32(ctx->r15, ctx->r11);
    // 0x8007909C: nop

L_800790A0:
    // 0x800790A0: bne         $s6, $zero, L_800790F8
    if (ctx->r22 != 0) {
        // 0x800790A4: nop
    
            goto L_800790F8;
    }
    // 0x800790A4: nop

    // 0x800790A8: lbu         $t8, 0x1($ra)
    ctx->r24 = MEM_BU(ctx->r31, 0X1);
    // 0x800790AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800790B0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800790B4: bgez        $t8, L_800790C8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800790B8: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800790C8;
    }
    // 0x800790B8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800790BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800790C0: nop

    // 0x800790C4: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_800790C8:
    // 0x800790C8: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800790CC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800790D0: nop

    // 0x800790D4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800790D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800790DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800790E0: nop

    // 0x800790E4: cvt.w.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800790E8: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800790EC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800790F0: addu        $s3, $t6, $t2
    ctx->r19 = ADD32(ctx->r14, ctx->r10);
    // 0x800790F4: nop

L_800790F8:
    // 0x800790F8: blez        $s2, L_800792C8
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800790FC: nop
    
            goto L_800792C8;
    }
    // 0x800790FC: nop

    // 0x80079100: blez        $s3, L_800792C8
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80079104: slt         $at, $t3, $s2
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_800792C8;
    }
    // 0x80079104: slt         $at, $t3, $s2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80079108: beq         $at, $zero, L_800792C8
    if (ctx->r1 == 0) {
        // 0x8007910C: slt         $at, $t2, $s3
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_800792C8;
    }
    // 0x8007910C: slt         $at, $t2, $s3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80079110: beq         $at, $zero, L_800792C8
    if (ctx->r1 == 0) {
        // 0x80079114: nop
    
            goto L_800792C8;
    }
    // 0x80079114: nop

    // 0x80079118: lbu         $v1, 0x0($ra)
    ctx->r3 = MEM_BU(ctx->r31, 0X0);
    // 0x8007911C: subu        $t8, $s2, $t3
    ctx->r24 = SUB32(ctx->r18, ctx->r11);
    // 0x80079120: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80079124: sll         $t7, $v1, 12
    ctx->r15 = S32(ctx->r3 << 12);
    // 0x80079128: div         $zero, $t7, $t8
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r24)));
    // 0x8007912C: andi        $t9, $s2, 0xFFF
    ctx->r25 = ctx->r18 & 0XFFF;
    // 0x80079130: bne         $t8, $zero, L_8007913C
    if (ctx->r24 != 0) {
        // 0x80079134: nop
    
            goto L_8007913C;
    }
    // 0x80079134: nop

    // 0x80079138: break       7
    do_break(2147979576);
L_8007913C:
    // 0x8007913C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80079140: bne         $t8, $at, L_80079154
    if (ctx->r24 != ctx->r1) {
        // 0x80079144: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80079154;
    }
    // 0x80079144: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80079148: bne         $t7, $at, L_80079154
    if (ctx->r15 != ctx->r1) {
        // 0x8007914C: nop
    
            goto L_80079154;
    }
    // 0x8007914C: nop

    // 0x80079150: break       6
    do_break(2147979600);
L_80079154:
    // 0x80079154: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80079158: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8007915C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80079160: andi        $t8, $s3, 0xFFF
    ctx->r24 = ctx->r19 & 0XFFF;
    // 0x80079164: or          $s4, $t7, $t8
    ctx->r20 = ctx->r15 | ctx->r24;
    // 0x80079168: lbu         $a0, 0x1($ra)
    ctx->r4 = MEM_BU(ctx->r31, 0X1);
    // 0x8007916C: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80079170: subu        $t6, $s3, $t2
    ctx->r14 = SUB32(ctx->r19, ctx->r10);
    // 0x80079174: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80079178: negu        $t7, $t3
    ctx->r15 = SUB32(0, ctx->r11);
    // 0x8007917C: mflo        $t4
    ctx->r12 = lo;
    // 0x80079180: beq         $s5, $zero, L_80079194
    if (ctx->r21 == 0) {
        // 0x80079184: nop
    
            goto L_80079194;
    }
    // 0x80079184: nop

    // 0x80079188: sll         $t5, $v1, 5
    ctx->r13 = S32(ctx->r3 << 5);
    // 0x8007918C: b           L_80079194
    // 0x80079190: negu        $t4, $t4
    ctx->r12 = SUB32(0, ctx->r12);
        goto L_80079194;
    // 0x80079190: negu        $t4, $t4
    ctx->r12 = SUB32(0, ctx->r12);
L_80079194:
    // 0x80079194: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x80079198: sll         $t9, $v1, 12
    ctx->r25 = S32(ctx->r3 << 12);
    // 0x8007919C: div         $zero, $t9, $t6
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r14)));
    // 0x800791A0: bne         $t6, $zero, L_800791AC
    if (ctx->r14 != 0) {
        // 0x800791A4: nop
    
            goto L_800791AC;
    }
    // 0x800791A4: nop

    // 0x800791A8: break       7
    do_break(2147979688);
L_800791AC:
    // 0x800791AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800791B0: bne         $t6, $at, L_800791C4
    if (ctx->r14 != ctx->r1) {
        // 0x800791B4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800791C4;
    }
    // 0x800791B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800791B8: bne         $t9, $at, L_800791C4
    if (ctx->r25 != ctx->r1) {
        // 0x800791BC: nop
    
            goto L_800791C4;
    }
    // 0x800791BC: nop

    // 0x800791C0: break       6
    do_break(2147979712);
L_800791C4:
    // 0x800791C4: negu        $t6, $t2
    ctx->r14 = SUB32(0, ctx->r10);
    // 0x800791C8: mflo        $a3
    ctx->r7 = lo;
    // 0x800791CC: beq         $s6, $zero, L_800791E0
    if (ctx->r22 == 0) {
        // 0x800791D0: nop
    
            goto L_800791E0;
    }
    // 0x800791D0: nop

    // 0x800791D4: sll         $t0, $v1, 5
    ctx->r8 = S32(ctx->r3 << 5);
    // 0x800791D8: b           L_800791E0
    // 0x800791DC: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
        goto L_800791E0;
    // 0x800791DC: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
L_800791E0:
    // 0x800791E0: bgez        $t3, L_800791FC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800791E4: nop
    
            goto L_800791FC;
    }
    // 0x800791E4: nop

    // 0x800791E8: multu       $t7, $t4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800791EC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800791F0: mflo        $t8
    ctx->r24 = lo;
    // 0x800791F4: sra         $t9, $t8, 7
    ctx->r25 = S32(SIGNED(ctx->r24) >> 7);
    // 0x800791F8: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
L_800791FC:
    // 0x800791FC: bgez        $t2, L_80079218
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80079200: nop
    
            goto L_80079218;
    }
    // 0x80079200: nop

    // 0x80079204: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80079208: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8007920C: mflo        $t7
    ctx->r15 = lo;
    // 0x80079210: sra         $t8, $t7, 7
    ctx->r24 = S32(SIGNED(ctx->r15) >> 7);
    // 0x80079214: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
L_80079218:
    // 0x80079218: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8007921C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80079220: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80079224: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80079228: lh          $a1, 0xA($ra)
    ctx->r5 = MEM_H(ctx->r31, 0XA);
    // 0x8007922C: nop

    // 0x80079230: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80079234: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80079238: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x8007923C: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80079240: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80079244: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80079248: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007924C: lw          $t9, 0xC($ra)
    ctx->r25 = MEM_W(ctx->r31, 0XC);
    // 0x80079250: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80079254: addu        $t8, $t9, $at
    ctx->r24 = ADD32(ctx->r25, ctx->r1);
    // 0x80079258: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007925C: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80079260: andi        $t7, $t3, 0xFFF
    ctx->r15 = ctx->r11 & 0XFFF;
    // 0x80079264: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x80079268: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8007926C: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80079270: andi        $t8, $t2, 0xFFF
    ctx->r24 = ctx->r10 & 0XFFF;
    // 0x80079274: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80079278: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x8007927C: sw          $s4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r20;
    // 0x80079280: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80079284: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x80079288: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x8007928C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80079290: andi        $t7, $t0, 0xFFFF
    ctx->r15 = ctx->r8 & 0XFFFF;
    // 0x80079294: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80079298: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8007929C: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800792A0: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x800792A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800792A8: lui         $t6, 0xB200
    ctx->r14 = S32(0XB200 << 16);
    // 0x800792AC: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x800792B0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800792B4: andi        $t8, $a3, 0xFFFF
    ctx->r24 = ctx->r7 & 0XFFFF;
    // 0x800792B8: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x800792BC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800792C0: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800792C4: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
L_800792C8:
    // 0x800792C8: lw          $ra, 0x8($s1)
    ctx->r31 = MEM_W(ctx->r17, 0X8);
    // 0x800792CC: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800792D0: bne         $ra, $zero, L_80078E84
    if (ctx->r31 != 0) {
        // 0x800792D4: nop
    
            goto L_80078E84;
    }
    // 0x800792D4: nop

    // 0x800792D8: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x800792DC: sw          $s2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r18;
L_800792E0:
    // 0x800792E0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800792E4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800792E8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800792EC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800792F0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800792F4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800792F8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800792FC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80079300: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80079304: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80079308: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8007930C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80079310: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80079314: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80079318: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8007931C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80079320: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80079324: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80079328: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007932C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80079330: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80079334: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80079338: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    extern void dkr_hud_rect_end(uint8_t*, recomp_context*); dkr_hud_rect_end(rdram, ctx);
    // 0x8007933C: jr          $ra
    // 0x80079340: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80079340: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void block_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A29C: bltz        $a0, L_8002A2C0
    if (SIGNED(ctx->r4) < 0) {
        // 0x8002A2A0: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8002A2C0;
    }
    // 0x8002A2A0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8002A2A4: lw          $v1, -0x36E8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X36E8);
    // 0x8002A2A8: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x8002A2AC: lh          $t6, 0x1A($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1A);
    // 0x8002A2B0: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8002A2B4: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002A2B8: beq         $at, $zero, L_8002A2C8
    if (ctx->r1 == 0) {
        // 0x8002A2BC: nop
    
            goto L_8002A2C8;
    }
    // 0x8002A2BC: nop

L_8002A2C0:
    // 0x8002A2C0: jr          $ra
    // 0x8002A2C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002A2C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002A2C8:
    // 0x8002A2C8: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8002A2CC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002A2D0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002A2D4: jr          $ra
    // 0x8002A2D8: nop

    return;
    // 0x8002A2D8: nop

;}
RECOMP_FUNC void obj_butterfly_node(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016C68: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80016C6C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80016C70: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80016C74: addiu       $s6, $s6, -0x51A4
    ctx->r22 = ADD32(ctx->r22, -0X51A4);
    // 0x80016C78: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x80016C7C: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80016C80: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80016C84: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x80016C88: mtc1        $a3, $f26
    ctx->f26.u32l = ctx->r7;
    // 0x80016C8C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80016C90: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80016C94: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80016C98: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80016C9C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80016CA0: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80016CA4: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x80016CA8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80016CAC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80016CB0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80016CB4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80016CB8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80016CBC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80016CC0: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80016CC4: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80016CC8: blez        $t6, L_80016D9C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80016CCC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80016D9C;
    }
    // 0x80016CCC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80016CD0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80016CD4: lw          $s3, 0x68($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X68);
    // 0x80016CD8: addiu       $s4, $s4, -0x51A8
    ctx->r20 = ADD32(ctx->r20, -0X51A8);
    // 0x80016CDC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80016CE0: addiu       $s5, $zero, 0x55
    ctx->r21 = ADD32(0, 0X55);
L_80016CE4:
    // 0x80016CE4: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80016CE8: nop

    // 0x80016CEC: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80016CF0: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x80016CF4: nop

    // 0x80016CF8: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x80016CFC: nop

    // 0x80016D00: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x80016D04: bne         $t0, $zero, L_80016D88
    if (ctx->r8 != 0) {
        // 0x80016D08: nop
    
            goto L_80016D88;
    }
    // 0x80016D08: nop

    // 0x80016D0C: lh          $t1, 0x48($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X48);
    // 0x80016D10: nop

    // 0x80016D14: bne         $s5, $t1, L_80016D88
    if (ctx->r21 != ctx->r9) {
        // 0x80016D18: nop
    
            goto L_80016D88;
    }
    // 0x80016D18: nop

    // 0x80016D1C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80016D20: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80016D24: sub.s       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x80016D28: bne         $s3, $zero, L_80016D5C
    if (ctx->r19 != 0) {
        // 0x80016D2C: sub.s       $f14, $f6, $f22
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f22.fl;
            goto L_80016D5C;
    }
    // 0x80016D2C: sub.s       $f14, $f6, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x80016D30: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80016D34: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80016D38: sub.s       $f0, $f8, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x80016D3C: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80016D40: nop

    // 0x80016D44: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80016D48: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80016D4C: jal         0x800C9AD0
    // 0x80016D50: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80016D50: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x80016D54: b           L_80016D74
    // 0x80016D58: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
        goto L_80016D74;
    // 0x80016D58: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
L_80016D5C:
    // 0x80016D5C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80016D60: nop

    // 0x80016D64: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80016D68: jal         0x800C9AD0
    // 0x80016D6C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80016D6C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_1:
    // 0x80016D70: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
L_80016D74:
    // 0x80016D74: nop

    // 0x80016D78: bc1f        L_80016D88
    if (!c1cs) {
        // 0x80016D7C: nop
    
            goto L_80016D88;
    }
    // 0x80016D7C: nop

    // 0x80016D80: b           L_80016DA0
    // 0x80016D84: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80016DA0;
    // 0x80016D84: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80016D88:
    // 0x80016D88: lw          $t2, 0x0($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X0);
    // 0x80016D8C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80016D90: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80016D94: bne         $at, $zero, L_80016CE4
    if (ctx->r1 != 0) {
        // 0x80016D98: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80016CE4;
    }
    // 0x80016D98: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80016D9C:
    // 0x80016D9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80016DA0:
    // 0x80016DA0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80016DA4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80016DA8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80016DAC: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80016DB0: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016DB4: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80016DB8: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016DBC: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80016DC0: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80016DC4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80016DC8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80016DCC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80016DD0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80016DD4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80016DD8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80016DDC: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80016DE0: jr          $ra
    // 0x80016DE4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80016DE4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void clear_game_progress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E994: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006E998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E99C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8006E9A0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006E9A4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8006E9A8: jal         0x8006B224
    // 0x8006E9AC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    level_count(rdram, ctx);
        goto after_0;
    // 0x8006E9AC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8006E9B0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8006E9B4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006E9B8: sb          $t6, 0x4B($a2)
    MEM_B(0X4B, ctx->r6) = ctx->r14;
    // 0x8006E9BC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8006E9C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006E9C4: blez        $t7, L_8006E9F4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8006E9C8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006E9F4;
    }
    // 0x8006E9C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8006E9CC:
    // 0x8006E9CC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8006E9D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006E9D4: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8006E9D8: sh          $zero, 0x0($t9)
    MEM_H(0X0, ctx->r25) = 0;
    // 0x8006E9DC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8006E9E0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8006E9E4: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8006E9E8: bne         $at, $zero, L_8006E9CC
    if (ctx->r1 != 0) {
        // 0x8006E9EC: nop
    
            goto L_8006E9CC;
    }
    // 0x8006E9EC: nop

    // 0x8006E9F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006E9F4:
    // 0x8006E9F4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E9F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006E9FC: blez        $t1, L_8006EA28
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8006EA00: nop
    
            goto L_8006EA28;
    }
    // 0x8006EA00: nop

L_8006EA04:
    // 0x8006EA04: lw          $t2, 0x4($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X4);
    // 0x8006EA08: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006EA0C: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8006EA10: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8006EA14: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8006EA18: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8006EA1C: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8006EA20: bne         $at, $zero, L_8006EA04
    if (ctx->r1 != 0) {
        // 0x8006EA24: nop
    
            goto L_8006EA04;
    }
    // 0x8006EA24: nop

L_8006EA28:
    // 0x8006EA28: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x8006EA2C: sh          $zero, 0xA($a2)
    MEM_H(0XA, ctx->r6) = 0;
    // 0x8006EA30: sh          $zero, 0xC($a2)
    MEM_H(0XC, ctx->r6) = 0;
    // 0x8006EA34: sh          $zero, 0xE($a2)
    MEM_H(0XE, ctx->r6) = 0;
    // 0x8006EA38: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x8006EA3C: sh          $zero, 0x14($a2)
    MEM_H(0X14, ctx->r6) = 0;
    // 0x8006EA40: sb          $zero, 0x16($a2)
    MEM_B(0X16, ctx->r6) = 0;
    // 0x8006EA44: sb          $zero, 0x17($a2)
    MEM_B(0X17, ctx->r6) = 0;
    // 0x8006EA48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EA4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006EA50: jr          $ra
    // 0x8006EA54: nop

    return;
    // 0x8006EA54: nop

;}
RECOMP_FUNC void alEnvmixerPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA0D0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800CA0D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CA0D8: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800CA0DC: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800CA0E0: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800CA0E4: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800CA0E8: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800CA0EC: nop

    // 0x800CA0F0: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x800CA0F4: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x800CA0F8: nop

    // 0x800CA0FC: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x800CA100: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800CA104: nop

    // 0x800CA108: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800CA10C: sh          $zero, 0x46($sp)
    MEM_H(0X46, ctx->r29) = 0;
    // 0x800CA110: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
    // 0x800CA114: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA118: nop

    // 0x800CA11C: lw          $t0, 0x3C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X3C);
    // 0x800CA120: nop

    // 0x800CA124: beq         $t0, $zero, L_800CA9CC
    if (ctx->r8 == 0) {
        // 0x800CA128: nop
    
            goto L_800CA9CC;
    }
    // 0x800CA128: nop

L_800CA12C:
    // 0x800CA12C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800CA130: nop

    // 0x800CA134: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x800CA138: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CA13C: nop

    // 0x800CA140: lw          $t3, 0x3C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X3C);
    // 0x800CA144: nop

    // 0x800CA148: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800CA14C: nop

    // 0x800CA150: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800CA154: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800CA158: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800CA15C: nop

    // 0x800CA160: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x800CA164: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800CA168: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CA16C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x800CA170: nop

    // 0x800CA174: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800CA178: beq         $at, $zero, L_800CA188
    if (ctx->r1 == 0) {
        // 0x800CA17C: nop
    
            goto L_800CA188;
    }
    // 0x800CA17C: nop

    // 0x800CA180: b           L_800CA9CC
    // 0x800CA184: nop

        goto L_800CA9CC;
    // 0x800CA184: nop

L_800CA188:
    // 0x800CA188: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800CA18C: nop

    // 0x800CA190: bltz        $t0, L_800CA1A0
    if (SIGNED(ctx->r8) < 0) {
        // 0x800CA194: nop
    
            goto L_800CA1A0;
    }
    // 0x800CA194: nop

    // 0x800CA198: b           L_800CA1B8
    // 0x800CA19C: nop

        goto L_800CA1B8;
    // 0x800CA19C: nop

L_800CA1A0:
    // 0x800CA1A0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CA1A4: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800CA1A8: addiu       $a1, $a1, -0x6A90
    ctx->r5 = ADD32(ctx->r5, -0X6A90);
    // 0x800CA1AC: addiu       $a0, $a0, -0x6AA0
    ctx->r4 = ADD32(ctx->r4, -0X6AA0);
    // 0x800CA1B0: jal         0x800B6F40
    // 0x800CA1B4: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    __assert_recomp(rdram, ctx);
        goto after_0;
    // 0x800CA1B4: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    after_0:
L_800CA1B8:
    // 0x800CA1B8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800CA1BC: nop

    // 0x800CA1C0: slti        $at, $t1, 0xA1
    ctx->r1 = SIGNED(ctx->r9) < 0XA1 ? 1 : 0;
    // 0x800CA1C4: beq         $at, $zero, L_800CA1D4
    if (ctx->r1 == 0) {
        // 0x800CA1C8: nop
    
            goto L_800CA1D4;
    }
    // 0x800CA1C8: nop

    // 0x800CA1CC: b           L_800CA1EC
    // 0x800CA1D0: nop

        goto L_800CA1EC;
    // 0x800CA1D0: nop

L_800CA1D4:
    // 0x800CA1D4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CA1D8: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800CA1DC: addiu       $a1, $a1, -0x6A68
    ctx->r5 = ADD32(ctx->r5, -0X6A68);
    // 0x800CA1E0: addiu       $a0, $a0, -0x6A88
    ctx->r4 = ADD32(ctx->r4, -0X6A88);
    // 0x800CA1E4: jal         0x800B6F40
    // 0x800CA1E8: addiu       $a2, $zero, 0x69
    ctx->r6 = ADD32(0, 0X69);
    __assert_recomp(rdram, ctx);
        goto after_1;
    // 0x800CA1E8: addiu       $a2, $zero, 0x69
    ctx->r6 = ADD32(0, 0X69);
    after_1:
L_800CA1EC:
    // 0x800CA1EC: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CA1F0: nop

    // 0x800CA1F4: lw          $t3, 0x3C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X3C);
    // 0x800CA1F8: nop

    // 0x800CA1FC: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x800CA200: nop

    // 0x800CA204: sltiu       $at, $t4, 0x11
    ctx->r1 = ctx->r12 < 0X11 ? 1 : 0;
    // 0x800CA208: beq         $at, $zero, L_800CA8C4
    if (ctx->r1 == 0) {
        // 0x800CA20C: nop
    
            goto L_800CA8C4;
    }
    // 0x800CA20C: nop

    // 0x800CA210: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800CA214: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CA218: addu        $at, $at, $t4
    gpr jr_addend_800CA224 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800CA21C: lw          $t4, -0x6A50($at)
    ctx->r12 = ADD32(ctx->r1, -0X6A50);
    // 0x800CA220: nop

    // 0x800CA224: jr          $t4
    // 0x800CA228: nop

    switch (jr_addend_800CA224 >> 2) {
        case 0: goto L_800CA870; break;
        case 1: goto L_800CA8C4; break;
        case 2: goto L_800CA8C4; break;
        case 3: goto L_800CA8C4; break;
        case 4: goto L_800CA8C4; break;
        case 5: goto L_800CA8C4; break;
        case 6: goto L_800CA8C4; break;
        case 7: goto L_800CA8C4; break;
        case 8: goto L_800CA8C4; break;
        case 9: goto L_800CA8C4; break;
        case 10: goto L_800CA8C4; break;
        case 11: goto L_800CA460; break;
        case 12: goto L_800CA460; break;
        case 13: goto L_800CA22C; break;
        case 14: goto L_800CA7A8; break;
        case 15: goto L_800CA828; break;
        case 16: goto L_800CA460; break;
        default: switch_error(__func__, 0x800CA224, 0x800E95B0);
    }
    // 0x800CA228: nop

L_800CA22C:
    // 0x800CA22C: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CA230: nop

    // 0x800CA234: lw          $t6, 0x3C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X3C);
    // 0x800CA238: nop

    // 0x800CA23C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800CA240: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800CA244: nop

    // 0x800CA248: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800CA24C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800CA250: nop

    // 0x800CA254: lh          $t9, 0xA($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XA);
    // 0x800CA258: nop

    // 0x800CA25C: beq         $t9, $zero, L_800CA27C
    if (ctx->r25 == 0) {
        // 0x800CA260: nop
    
            goto L_800CA27C;
    }
    // 0x800CA260: nop

    // 0x800CA264: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CA268: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800CA26C: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x800CA270: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CA274: jalr        $t9
    // 0x800CA278: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800CA278: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_2:
L_800CA27C:
    // 0x800CA27C: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800CA280: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800CA284: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x800CA288: lw          $a2, 0x18($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X18);
    // 0x800CA28C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800CA290: jalr        $t9
    // 0x800CA294: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800CA294: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_3:
    // 0x800CA298: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CA29C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CA2A0: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x800CA2A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CA2A8: jalr        $t9
    // 0x800CA2AC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800CA2AC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_4:
    // 0x800CA2B0: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CA2B4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800CA2B8: sw          $t4, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->r12;
    // 0x800CA2BC: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800CA2C0: nop

    // 0x800CA2C4: sw          $zero, 0x30($t6)
    MEM_W(0X30, ctx->r14) = 0;
    // 0x800CA2C8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800CA2CC: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CA2D0: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x800CA2D4: nop

    // 0x800CA2D8: sw          $t8, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r24;
    // 0x800CA2DC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800CA2E0: nop

    // 0x800CA2E4: lh          $t1, 0x10($t2)
    ctx->r9 = MEM_H(ctx->r10, 0X10);
    // 0x800CA2E8: nop

    // 0x800CA2EC: addu        $t3, $t1, $t1
    ctx->r11 = ADD32(ctx->r9, ctx->r9);
    // 0x800CA2F0: bgez        $t3, L_800CA300
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800CA2F4: sra         $t9, $t3, 1
        ctx->r25 = S32(SIGNED(ctx->r11) >> 1);
            goto L_800CA300;
    }
    // 0x800CA2F4: sra         $t9, $t3, 1
    ctx->r25 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800CA2F8: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x800CA2FC: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_800CA300:
    // 0x800CA300: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800CA304: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800CA308: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CA30C: nop

    // 0x800CA310: sh          $t4, 0x1A($t5)
    MEM_H(0X1A, ctx->r13) = ctx->r12;
    // 0x800CA314: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800CA318: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CA31C: lbu         $t7, 0x12($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X12);
    // 0x800CA320: nop

    // 0x800CA324: sh          $t7, 0x18($t8)
    MEM_H(0X18, ctx->r24) = ctx->r15;
    // 0x800CA328: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800CA32C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800CA330: lbu         $t2, 0x13($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X13);
    // 0x800CA334: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA338: sll         $t1, $t2, 1
    ctx->r9 = S32(ctx->r10 << 1);
    // 0x800CA33C: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x800CA340: lh          $t3, 0x37A0($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X37A0);
    // 0x800CA344: nop

    // 0x800CA348: sh          $t3, 0x20($t9)
    MEM_H(0X20, ctx->r25) = ctx->r11;
    // 0x800CA34C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800CA350: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800CA354: lbu         $t5, 0x13($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X13);
    // 0x800CA358: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CA35C: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x800CA360: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800CA364: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800CA368: lh          $t8, 0x389E($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X389E);
    // 0x800CA36C: nop

    // 0x800CA370: sh          $t8, 0x22($t0)
    MEM_H(0X22, ctx->r8) = ctx->r24;
    // 0x800CA374: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800CA378: nop

    // 0x800CA37C: lw          $t1, 0x14($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X14);
    // 0x800CA380: nop

    // 0x800CA384: beq         $t1, $zero, L_800CA3A8
    if (ctx->r9 == 0) {
        // 0x800CA388: nop
    
            goto L_800CA3A8;
    }
    // 0x800CA388: nop

    // 0x800CA38C: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA390: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800CA394: sh          $t3, 0x1C($t9)
    MEM_H(0X1C, ctx->r25) = ctx->r11;
    // 0x800CA398: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CA39C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800CA3A0: b           L_800CA40C
    // 0x800CA3A4: sh          $t4, 0x1E($t5)
    MEM_H(0X1E, ctx->r13) = ctx->r12;
        goto L_800CA40C;
    // 0x800CA3A4: sh          $t4, 0x1E($t5)
    MEM_H(0X1E, ctx->r13) = ctx->r12;
L_800CA3A8:
    // 0x800CA3A8: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800CA3AC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800CA3B0: lh          $t7, 0x18($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X18);
    // 0x800CA3B4: lh          $t2, 0x1A($t6)
    ctx->r10 = MEM_H(ctx->r14, 0X1A);
    // 0x800CA3B8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800CA3BC: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800CA3C0: lh          $t0, 0x37A0($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X37A0);
    // 0x800CA3C4: nop

    // 0x800CA3C8: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA3CC: mflo        $t1
    ctx->r9 = lo;
    // 0x800CA3D0: sra         $t3, $t1, 15
    ctx->r11 = S32(SIGNED(ctx->r9) >> 15);
    // 0x800CA3D4: sh          $t3, 0x1C($t6)
    MEM_H(0X1C, ctx->r14) = ctx->r11;
    // 0x800CA3D8: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA3DC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800CA3E0: lh          $t4, 0x18($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X18);
    // 0x800CA3E4: lh          $t0, 0x1A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X1A);
    // 0x800CA3E8: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800CA3EC: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x800CA3F0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800CA3F4: lh          $t8, 0x389E($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X389E);
    // 0x800CA3F8: nop

    // 0x800CA3FC: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA400: mflo        $t2
    ctx->r10 = lo;
    // 0x800CA404: sra         $t1, $t2, 15
    ctx->r9 = S32(SIGNED(ctx->r10) >> 15);
    // 0x800CA408: sh          $t1, 0x1E($t9)
    MEM_H(0X1E, ctx->r25) = ctx->r9;
L_800CA40C:
    // 0x800CA40C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800CA410: nop

    // 0x800CA414: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x800CA418: nop

    // 0x800CA41C: beq         $t6, $zero, L_800CA458
    if (ctx->r14 == 0) {
        // 0x800CA420: nop
    
            goto L_800CA458;
    }
    // 0x800CA420: nop

    // 0x800CA424: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800CA428: nop

    // 0x800CA42C: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x800CA430: nop

    // 0x800CA434: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800CA438: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800CA43C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800CA440: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800CA444: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800CA448: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x800CA44C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800CA450: jalr        $t9
    // 0x800CA454: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x800CA454: nop

    after_5:
L_800CA458:
    // 0x800CA458: b           L_800CA92C
    // 0x800CA45C: nop

        goto L_800CA92C;
    // 0x800CA45C: nop

L_800CA460:
    // 0x800CA460: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800CA464: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800CA468: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800CA46C: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800CA470: addiu       $a1, $sp, 0x56
    ctx->r5 = ADD32(ctx->r29, 0X56);
    // 0x800CA474: addiu       $a2, $sp, 0x46
    ctx->r6 = ADD32(ctx->r29, 0X46);
    // 0x800CA478: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800CA47C: jal         0x800CAC5C
    // 0x800CA480: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    static_3_800CAC5C(rdram, ctx);
        goto after_6;
    // 0x800CA480: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_6:
    // 0x800CA484: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800CA488: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CA48C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800CA490: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x800CA494: nop

    // 0x800CA498: addu        $t6, $t1, $t3
    ctx->r14 = ADD32(ctx->r9, ctx->r11);
    // 0x800CA49C: sw          $t6, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r14;
    // 0x800CA4A0: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CA4A4: nop

    // 0x800CA4A8: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x800CA4AC: lw          $t7, 0x34($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X34);
    // 0x800CA4B0: nop

    // 0x800CA4B4: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800CA4B8: bne         $at, $zero, L_800CA560
    if (ctx->r1 != 0) {
        // 0x800CA4BC: nop
    
            goto L_800CA560;
    }
    // 0x800CA4BC: nop

    // 0x800CA4C0: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA4C4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800CA4C8: lh          $t8, 0x18($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X18);
    // 0x800CA4CC: lh          $t3, 0x1A($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X1A);
    // 0x800CA4D0: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x800CA4D4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800CA4D8: lh          $t1, 0x37A0($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X37A0);
    // 0x800CA4DC: nop

    // 0x800CA4E0: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA4E4: mflo        $t6
    ctx->r14 = lo;
    // 0x800CA4E8: sra         $t2, $t6, 15
    ctx->r10 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800CA4EC: sh          $t2, 0x28($t9)
    MEM_H(0X28, ctx->r25) = ctx->r10;
    // 0x800CA4F0: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CA4F4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800CA4F8: lh          $t5, 0x18($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X18);
    // 0x800CA4FC: lh          $t1, 0x1A($t4)
    ctx->r9 = MEM_H(ctx->r12, 0X1A);
    // 0x800CA500: negu        $t7, $t5
    ctx->r15 = SUB32(0, ctx->r13);
    // 0x800CA504: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800CA508: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800CA50C: lh          $t0, 0x389E($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X389E);
    // 0x800CA510: nop

    // 0x800CA514: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA518: mflo        $t3
    ctx->r11 = lo;
    // 0x800CA51C: sra         $t6, $t3, 15
    ctx->r14 = S32(SIGNED(ctx->r11) >> 15);
    // 0x800CA520: sh          $t6, 0x2E($t4)
    MEM_H(0X2E, ctx->r12) = ctx->r14;
    // 0x800CA524: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CA528: nop

    // 0x800CA52C: lw          $t9, 0x34($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X34);
    // 0x800CA530: nop

    // 0x800CA534: sw          $t9, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r25;
    // 0x800CA538: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CA53C: nop

    // 0x800CA540: lh          $t7, 0x28($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X28);
    // 0x800CA544: nop

    // 0x800CA548: sh          $t7, 0x1C($t5)
    MEM_H(0X1C, ctx->r13) = ctx->r15;
    // 0x800CA54C: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CA550: nop

    // 0x800CA554: lh          $t0, 0x2E($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X2E);
    // 0x800CA558: b           L_800CA600
    // 0x800CA55C: sh          $t0, 0x1E($t8)
    MEM_H(0X1E, ctx->r24) = ctx->r8;
        goto L_800CA600;
    // 0x800CA55C: sh          $t0, 0x1E($t8)
    MEM_H(0X1E, ctx->r24) = ctx->r8;
L_800CA560:
    // 0x800CA560: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800CA564: nop

    // 0x800CA568: lh          $t3, 0x1C($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X1C);
    // 0x800CA56C: lw          $a1, 0x30($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X30);
    // 0x800CA570: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800CA574: lh          $a2, 0x26($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X26);
    // 0x800CA578: lhu         $a3, 0x24($t1)
    ctx->r7 = MEM_HU(ctx->r9, 0X24);
    // 0x800CA57C: jal         0x800CB498
    // 0x800CA580: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    static_3_800CB498(rdram, ctx);
        goto after_7;
    // 0x800CA580: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_7:
    // 0x800CA584: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800CA588: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA58C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800CA590: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800CA594: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800CA598: nop

    // 0x800CA59C: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800CA5A0: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800CA5A4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800CA5A8: sh          $t4, 0x1C($t9)
    MEM_H(0X1C, ctx->r25) = ctx->r12;
    // 0x800CA5AC: nop

    // 0x800CA5B0: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CA5B4: nop

    // 0x800CA5B8: lh          $t7, 0x1E($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X1E);
    // 0x800CA5BC: lw          $a1, 0x30($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X30);
    // 0x800CA5C0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800CA5C4: lh          $a2, 0x2C($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X2C);
    // 0x800CA5C8: lhu         $a3, 0x2A($t2)
    ctx->r7 = MEM_HU(ctx->r10, 0X2A);
    // 0x800CA5CC: jal         0x800CB498
    // 0x800CA5D0: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    static_3_800CB498(rdram, ctx);
        goto after_8;
    // 0x800CA5D0: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_8:
    // 0x800CA5D4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800CA5D8: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CA5DC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800CA5E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800CA5E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800CA5E8: nop

    // 0x800CA5EC: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800CA5F0: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x800CA5F4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800CA5F8: sh          $t0, 0x1E($t8)
    MEM_H(0X1E, ctx->r24) = ctx->r8;
    // 0x800CA5FC: nop

L_800CA600:
    // 0x800CA600: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CA604: nop

    // 0x800CA608: lh          $t1, 0x1C($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X1C);
    // 0x800CA60C: nop

    // 0x800CA610: bne         $t1, $zero, L_800CA624
    if (ctx->r9 != 0) {
        // 0x800CA614: nop
    
            goto L_800CA624;
    }
    // 0x800CA614: nop

    // 0x800CA618: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CA61C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CA620: sh          $t6, 0x1C($t4)
    MEM_H(0X1C, ctx->r12) = ctx->r14;
L_800CA624:
    // 0x800CA624: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA628: nop

    // 0x800CA62C: lh          $t7, 0x1E($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X1E);
    // 0x800CA630: nop

    // 0x800CA634: bne         $t7, $zero, L_800CA648
    if (ctx->r15 != 0) {
        // 0x800CA638: nop
    
            goto L_800CA648;
    }
    // 0x800CA638: nop

    // 0x800CA63C: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CA640: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800CA644: sh          $t2, 0x1E($t5)
    MEM_H(0X1E, ctx->r13) = ctx->r10;
L_800CA648:
    // 0x800CA648: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CA64C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800CA650: lw          $t8, 0x3C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X3C);
    // 0x800CA654: nop

    // 0x800CA658: lh          $t3, 0x8($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X8);
    // 0x800CA65C: nop

    // 0x800CA660: bne         $t3, $at, L_800CA684
    if (ctx->r11 != ctx->r1) {
        // 0x800CA664: nop
    
            goto L_800CA684;
    }
    // 0x800CA664: nop

    // 0x800CA668: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800CA66C: nop

    // 0x800CA670: lw          $t6, 0x3C($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X3C);
    // 0x800CA674: nop

    // 0x800CA678: lw          $t4, 0xC($t6)
    ctx->r12 = MEM_W(ctx->r14, 0XC);
    // 0x800CA67C: nop

    // 0x800CA680: sh          $t4, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r12;
L_800CA684:
    // 0x800CA684: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA688: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800CA68C: lw          $t7, 0x3C($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X3C);
    // 0x800CA690: nop

    // 0x800CA694: lh          $t2, 0x8($t7)
    ctx->r10 = MEM_H(ctx->r15, 0X8);
    // 0x800CA698: nop

    // 0x800CA69C: bne         $t2, $at, L_800CA718
    if (ctx->r10 != ctx->r1) {
        // 0x800CA6A0: nop
    
            goto L_800CA718;
    }
    // 0x800CA6A0: nop

    // 0x800CA6A4: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CA6A8: nop

    // 0x800CA6AC: sw          $zero, 0x30($t5)
    MEM_W(0X30, ctx->r13) = 0;
    // 0x800CA6B0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CA6B4: nop

    // 0x800CA6B8: lw          $t8, 0x3C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X3C);
    // 0x800CA6BC: nop

    // 0x800CA6C0: lw          $t3, 0xC($t8)
    ctx->r11 = MEM_W(ctx->r24, 0XC);
    // 0x800CA6C4: nop

    // 0x800CA6C8: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x800CA6CC: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800CA6D0: nop

    // 0x800CA6D4: addu        $t4, $t6, $t6
    ctx->r12 = ADD32(ctx->r14, ctx->r14);
    // 0x800CA6D8: bgez        $t4, L_800CA6E8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800CA6DC: sra         $t1, $t4, 1
        ctx->r9 = S32(SIGNED(ctx->r12) >> 1);
            goto L_800CA6E8;
    }
    // 0x800CA6DC: sra         $t1, $t4, 1
    ctx->r9 = S32(SIGNED(ctx->r12) >> 1);
    // 0x800CA6E0: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x800CA6E4: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_800CA6E8:
    // 0x800CA6E8: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x800CA6EC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800CA6F0: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800CA6F4: nop

    // 0x800CA6F8: sh          $t9, 0x1A($t7)
    MEM_H(0X1A, ctx->r15) = ctx->r25;
    // 0x800CA6FC: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CA700: nop

    // 0x800CA704: lw          $t5, 0x3C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X3C);
    // 0x800CA708: nop

    // 0x800CA70C: lw          $t0, 0x10($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X10);
    // 0x800CA710: nop

    // 0x800CA714: sw          $t0, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r8;
L_800CA718:
    // 0x800CA718: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CA71C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800CA720: lw          $t3, 0x3C($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X3C);
    // 0x800CA724: nop

    // 0x800CA728: lh          $t6, 0x8($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X8);
    // 0x800CA72C: nop

    // 0x800CA730: bne         $t6, $at, L_800CA794
    if (ctx->r14 != ctx->r1) {
        // 0x800CA734: nop
    
            goto L_800CA794;
    }
    // 0x800CA734: nop

    // 0x800CA738: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CA73C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800CA740: lw          $t1, 0x3C($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X3C);
    // 0x800CA744: nop

    // 0x800CA748: lw          $t9, 0xC($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XC);
    // 0x800CA74C: nop

    // 0x800CA750: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x800CA754: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x800CA758: lh          $t5, 0x37A0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X37A0);
    // 0x800CA75C: nop

    // 0x800CA760: sh          $t5, 0x20($t4)
    MEM_H(0X20, ctx->r12) = ctx->r13;
    // 0x800CA764: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CA768: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800CA76C: lw          $t2, 0x3C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X3C);
    // 0x800CA770: nop

    // 0x800CA774: lw          $t8, 0xC($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XC);
    // 0x800CA778: nop

    // 0x800CA77C: negu        $t3, $t8
    ctx->r11 = SUB32(0, ctx->r24);
    // 0x800CA780: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x800CA784: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x800CA788: lh          $t1, 0x389E($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X389E);
    // 0x800CA78C: nop

    // 0x800CA790: sh          $t1, 0x22($t0)
    MEM_H(0X22, ctx->r8) = ctx->r9;
L_800CA794:
    // 0x800CA794: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800CA798: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800CA79C: sw          $t9, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->r25;
    // 0x800CA7A0: b           L_800CA92C
    // 0x800CA7A4: nop

        goto L_800CA92C;
    // 0x800CA7A4: nop

L_800CA7A8:
    // 0x800CA7A8: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CA7AC: nop

    // 0x800CA7B0: lw          $t4, 0x3C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X3C);
    // 0x800CA7B4: nop

    // 0x800CA7B8: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800CA7BC: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800CA7C0: nop

    // 0x800CA7C4: lh          $t8, 0xA($t2)
    ctx->r24 = MEM_H(ctx->r10, 0XA);
    // 0x800CA7C8: nop

    // 0x800CA7CC: beq         $t8, $zero, L_800CA7EC
    if (ctx->r24 == 0) {
        // 0x800CA7D0: nop
    
            goto L_800CA7EC;
    }
    // 0x800CA7D0: nop

    // 0x800CA7D4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CA7D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800CA7DC: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x800CA7E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CA7E4: jalr        $t9
    // 0x800CA7E8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x800CA7E8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_9:
L_800CA7EC:
    // 0x800CA7EC: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800CA7F0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800CA7F4: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x800CA7F8: lw          $a2, 0xC($t1)
    ctx->r6 = MEM_W(ctx->r9, 0XC);
    // 0x800CA7FC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800CA800: jalr        $t9
    // 0x800CA804: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_10;
    // 0x800CA804: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_10:
    // 0x800CA808: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CA80C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CA810: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x800CA814: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CA818: jalr        $t9
    // 0x800CA81C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x800CA81C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_11:
    // 0x800CA820: b           L_800CA92C
    // 0x800CA824: nop

        goto L_800CA92C;
    // 0x800CA824: nop

L_800CA828:
    // 0x800CA828: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800CA82C: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x800CA830: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800CA834: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800CA838: addiu       $a1, $sp, 0x56
    ctx->r5 = ADD32(ctx->r29, 0X56);
    // 0x800CA83C: addiu       $a2, $sp, 0x46
    ctx->r6 = ADD32(ctx->r29, 0X46);
    // 0x800CA840: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CA844: jal         0x800CAC5C
    // 0x800CA848: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    static_3_800CAC5C(rdram, ctx);
        goto after_12;
    // 0x800CA848: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_12:
    // 0x800CA84C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800CA850: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CA854: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800CA858: lw          $t9, 0x8($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X8);
    // 0x800CA85C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CA860: jalr        $t9
    // 0x800CA864: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_13;
    // 0x800CA864: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_13:
    // 0x800CA868: b           L_800CA92C
    // 0x800CA86C: nop

        goto L_800CA92C;
    // 0x800CA86C: nop

L_800CA870:
    // 0x800CA870: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800CA874: lw          $t2, 0x3780($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3780);
    // 0x800CA878: nop

    // 0x800CA87C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800CA880: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CA884: nop

    // 0x800CA888: lw          $t3, 0x3C($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X3C);
    // 0x800CA88C: nop

    // 0x800CA890: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800CA894: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800CA898: nop

    // 0x800CA89C: lw          $t6, 0xC($t1)
    ctx->r14 = MEM_W(ctx->r9, 0XC);
    // 0x800CA8A0: nop

    // 0x800CA8A4: sw          $zero, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = 0;
    // 0x800CA8A8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800CA8AC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800CA8B0: lw          $a1, 0xC($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XC);
    // 0x800CA8B4: jal         0x8006571C
    // 0x800CA8B8: nop

    _freePVoice(rdram, ctx);
        goto after_14;
    // 0x800CA8B8: nop

    after_14:
    // 0x800CA8BC: b           L_800CA92C
    // 0x800CA8C0: nop

        goto L_800CA92C;
    // 0x800CA8C0: nop

L_800CA8C4:
    // 0x800CA8C4: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800CA8C8: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x800CA8CC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800CA8D0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800CA8D4: addiu       $a1, $sp, 0x56
    ctx->r5 = ADD32(ctx->r29, 0X56);
    // 0x800CA8D8: addiu       $a2, $sp, 0x46
    ctx->r6 = ADD32(ctx->r29, 0X46);
    // 0x800CA8DC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CA8E0: jal         0x800CAC5C
    // 0x800CA8E4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    static_3_800CAC5C(rdram, ctx);
        goto after_15;
    // 0x800CA8E4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_15:
    // 0x800CA8E8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800CA8EC: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CA8F0: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800CA8F4: lw          $t9, 0x30($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X30);
    // 0x800CA8F8: nop

    // 0x800CA8FC: addu        $t8, $t9, $t2
    ctx->r24 = ADD32(ctx->r25, ctx->r10);
    // 0x800CA900: sw          $t8, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r24;
    // 0x800CA904: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CA908: nop

    // 0x800CA90C: lw          $t1, 0x3C($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X3C);
    // 0x800CA910: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x800CA914: lh          $a1, 0x8($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X8);
    // 0x800CA918: lw          $a2, 0xC($t1)
    ctx->r6 = MEM_W(ctx->r9, 0XC);
    // 0x800CA91C: jalr        $t9
    // 0x800CA920: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_16;
    // 0x800CA920: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_16:
    // 0x800CA924: b           L_800CA92C
    // 0x800CA928: nop

        goto L_800CA92C;
    // 0x800CA928: nop

L_800CA92C:
    // 0x800CA92C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800CA930: lh          $t6, 0x46($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X46);
    // 0x800CA934: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    // 0x800CA938: addu        $t5, $t6, $t7
    ctx->r13 = ADD32(ctx->r14, ctx->r15);
    // 0x800CA93C: sh          $t5, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r13;
    // 0x800CA940: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x800CA944: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CA948: nop

    // 0x800CA94C: subu        $t4, $t2, $t8
    ctx->r12 = SUB32(ctx->r10, ctx->r24);
    // 0x800CA950: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x800CA954: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800CA958: nop

    // 0x800CA95C: lw          $t3, 0x3C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X3C);
    // 0x800CA960: nop

    // 0x800CA964: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800CA968: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA96C: nop

    // 0x800CA970: lw          $t0, 0x3C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X3C);
    // 0x800CA974: nop

    // 0x800CA978: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800CA97C: nop

    // 0x800CA980: sw          $t6, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r14;
    // 0x800CA984: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800CA988: nop

    // 0x800CA98C: lw          $t5, 0x3C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X3C);
    // 0x800CA990: nop

    // 0x800CA994: bne         $t5, $zero, L_800CA9A8
    if (ctx->r13 != 0) {
        // 0x800CA998: nop
    
            goto L_800CA9A8;
    }
    // 0x800CA998: nop

    // 0x800CA99C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CA9A0: nop

    // 0x800CA9A4: sw          $zero, 0x40($t2)
    MEM_W(0X40, ctx->r10) = 0;
L_800CA9A8:
    // 0x800CA9A8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800CA9AC: jal         0x8006569C
    // 0x800CA9B0: nop

    __freeParam(rdram, ctx);
        goto after_17;
    // 0x800CA9B0: nop

    after_17:
    // 0x800CA9B4: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CA9B8: nop

    // 0x800CA9BC: lw          $t4, 0x3C($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X3C);
    // 0x800CA9C0: nop

    // 0x800CA9C4: bne         $t4, $zero, L_800CA12C
    if (ctx->r12 != 0) {
        // 0x800CA9C8: nop
    
            goto L_800CA12C;
    }
    // 0x800CA9C8: nop

L_800CA9CC:
    // 0x800CA9CC: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800CA9D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CA9D4: lw          $t3, 0x48($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X48);
    // 0x800CA9D8: nop

    // 0x800CA9DC: bne         $t3, $at, L_800CAA24
    if (ctx->r11 != ctx->r1) {
        // 0x800CA9E0: nop
    
            goto L_800CAA24;
    }
    // 0x800CA9E0: nop

    // 0x800CA9E4: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800CA9E8: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800CA9EC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800CA9F0: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800CA9F4: addiu       $a1, $sp, 0x56
    ctx->r5 = ADD32(ctx->r29, 0X56);
    // 0x800CA9F8: addiu       $a2, $sp, 0x46
    ctx->r6 = ADD32(ctx->r29, 0X46);
    // 0x800CA9FC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800CAA00: jal         0x800CAC5C
    // 0x800CAA04: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    static_3_800CAC5C(rdram, ctx);
        goto after_18;
    // 0x800CAA04: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_18:
    // 0x800CAA08: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800CAA0C: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CAA10: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800CAA14: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x800CAA18: nop

    // 0x800CAA1C: addu        $t2, $t7, $t5
    ctx->r10 = ADD32(ctx->r15, ctx->r13);
    // 0x800CAA20: sw          $t2, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r10;
L_800CAA24:
    // 0x800CAA24: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CAA28: nop

    // 0x800CAA2C: lw          $t4, 0x30($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X30);
    // 0x800CAA30: lw          $t1, 0x34($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X34);
    // 0x800CAA34: nop

    // 0x800CAA38: slt         $at, $t1, $t4
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800CAA3C: beq         $at, $zero, L_800CAA58
    if (ctx->r1 == 0) {
        // 0x800CAA40: nop
    
            goto L_800CAA58;
    }
    // 0x800CAA40: nop

    // 0x800CAA44: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CAA48: nop

    // 0x800CAA4C: lw          $t0, 0x34($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X34);
    // 0x800CAA50: nop

    // 0x800CAA54: sw          $t0, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r8;
L_800CAA58:
    // 0x800CAA58: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800CAA5C: b           L_800CAA6C
    // 0x800CAA60: nop

        goto L_800CAA6C;
    // 0x800CAA60: nop

    // 0x800CAA64: b           L_800CAA6C
    // 0x800CAA68: nop

        goto L_800CAA6C;
    // 0x800CAA68: nop

L_800CAA6C:
    // 0x800CAA6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CAA70: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800CAA74: jr          $ra
    // 0x800CAA78: nop

    return;
    // 0x800CAA78: nop

;}
RECOMP_FUNC void move_particle_with_acceleration(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3358: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800B335C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800B3360: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800B3364: addiu       $s2, $s2, 0x7C80
    ctx->r18 = ADD32(ctx->r18, 0X7C80);
    // 0x800B3368: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800B336C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B3370: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B3374: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B3378: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B337C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B3380: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800B3384: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B3388: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800B338C: beq         $t6, $zero, L_800B348C
    if (ctx->r14 == 0) {
        // 0x800B3390: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_800B348C;
    }
    // 0x800B3390: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800B3394: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B3398: addiu       $s3, $sp, 0x38
    ctx->r19 = ADD32(ctx->r29, 0X38);
L_800B339C:
    // 0x800B339C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B33A0: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B33A4: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B33A8: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B33AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B33B0: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B33B4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B33B8: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B33BC: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800B33C0: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800B33C4: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800B33C8: lh          $t8, 0x62($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X62);
    // 0x800B33CC: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x800B33D0: lh          $t1, 0x64($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X64);
    // 0x800B33D4: lh          $t3, 0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4);
    // 0x800B33D8: lh          $t4, 0x66($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X66);
    // 0x800B33DC: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x800B33E0: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x800B33E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B33E8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B33EC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B33F0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B33F4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800B33F8: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x800B33FC: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x800B3400: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800B3404: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x800B3408: sh          $t5, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r13;
    // 0x800B340C: swc1        $f20, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f20.u32l;
    // 0x800B3410: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800B3414: swc1        $f20, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f20.u32l;
    // 0x800B3418: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800B341C: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x800B3420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3424: jal         0x80070320
    // 0x800B3428: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x800B3428: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x800B342C: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B3430: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B3434: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B3438: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B343C: lwc1        $f10, 0x68($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800B3440: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x800B3444: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B3448: nop

    // 0x800B344C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B3450: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B3454: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x800B3458: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B345C: nop

    // 0x800B3460: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800B3464: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x800B3468: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B346C: nop

    // 0x800B3470: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B3474: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800B3478: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800B347C: nop

    // 0x800B3480: slt         $v0, $s1, $t6
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B3484: bne         $v0, $zero, L_800B339C
    if (ctx->r2 != 0) {
        // 0x800B3488: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800B339C;
    }
    // 0x800B3488: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800B348C:
    // 0x800B348C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3490: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800B3494: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800B3498: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800B349C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800B34A0: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800B34A4: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800B34A8: jr          $ra
    // 0x800B34AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800B34AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void alSynNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065130: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80065134: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80065138: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8006513C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80065140: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80065144: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80065148: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8006514C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80065150: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80065154: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80065158: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006515C: lw          $s7, 0x14($a1)
    ctx->r23 = MEM_W(ctx->r5, 0X14);
    // 0x80065160: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80065164: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80065168: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x8006516C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x80065170: sw          $t6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r14;
    // 0x80065174: lw          $t7, 0x18($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X18);
    // 0x80065178: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x8006517C: sw          $t8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r24;
    // 0x80065180: sw          $t7, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r15;
    // 0x80065184: lw          $t9, 0x10($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10);
    // 0x80065188: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8006518C: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x80065190: addiu       $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
    // 0x80065194: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x80065198: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8006519C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800651A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800651A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800651A8: jal         0x800C77F0
    // 0x800651AC: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800651AC: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_0:
    // 0x800651B0: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800651B4: jal         0x800650E4
    // 0x800651B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    alSaveNew(rdram, ctx);
        goto after_1;
    // 0x800651B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800651BC: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800651C0: addiu       $t2, $zero, 0x4C
    ctx->r10 = ADD32(0, 0X4C);
    // 0x800651C4: sw          $t1, 0x38($s6)
    MEM_W(0X38, ctx->r22) = ctx->r9;
    // 0x800651C8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800651CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800651D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800651D4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x800651D8: jal         0x800C77F0
    // 0x800651DC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x800651DC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x800651E0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800651E4: sw          $v0, 0x34($s6)
    MEM_W(0X34, ctx->r22) = ctx->r2;
    // 0x800651E8: sw          $t3, 0x40($s6)
    MEM_W(0X40, ctx->r22) = ctx->r11;
    // 0x800651EC: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x800651F0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800651F4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800651F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800651FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065200: jal         0x800C77F0
    // 0x80065204: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x80065204: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_3:
    // 0x80065208: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x8006520C: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    // 0x80065210: jal         0x80065024
    // 0x80065214: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alAuxBusNew(rdram, ctx);
        goto after_4;
    // 0x80065214: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80065218: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x8006521C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80065220: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80065224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065228: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006522C: jal         0x800C77F0
    // 0x80065230: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x80065230: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_5:
    // 0x80065234: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x80065238: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    // 0x8006523C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80065240: jal         0x80065024
    // 0x80065244: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    alAuxBusNew(rdram, ctx);
        goto after_6;
    // 0x80065244: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    after_6:
    // 0x80065248: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8006524C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80065250: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065254: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065258: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x8006525C: jal         0x800C77F0
    // 0x80065260: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_7;
    // 0x80065260: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80065264: sw          $v0, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r2;
    // 0x80065268: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x8006526C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80065270: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80065274: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006527C: jal         0x800C77F0
    // 0x80065280: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_8;
    // 0x80065280: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_8:
    // 0x80065284: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x80065288: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    // 0x8006528C: jal         0x80065084
    // 0x80065290: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alMainBusNew(rdram, ctx);
        goto after_9;
    // 0x80065290: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x80065294: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80065298: or          $s1, $fp, $zero
    ctx->r17 = ctx->r30 | 0;
    // 0x8006529C: addiu       $s2, $zero, 0x4C
    ctx->r18 = ADD32(0, 0X4C);
L_800652A0:
    // 0x800652A0: lbu         $t8, 0x1C($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X1C);
    // 0x800652A4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800652A8: beq         $t8, $zero, L_800652CC
    if (ctx->r24 == 0) {
        // 0x800652AC: sll         $a1, $s0, 16
        ctx->r5 = S32(ctx->r16 << 16);
            goto L_800652CC;
    }
    // 0x800652AC: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x800652B0: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800652B4: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800652B8: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x800652BC: jal         0x80065860
    // 0x800652C0: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    alSynAllocFX(rdram, ctx);
        goto after_10;
    // 0x800652C0: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_10:
    // 0x800652C4: b           L_800652F0
    // 0x800652C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800652F0;
    // 0x800652C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800652CC:
    // 0x800652CC: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800652D0: lw          $t0, 0x34($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X34);
    // 0x800652D4: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x800652D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800652DC: mflo        $t1
    ctx->r9 = lo;
    // 0x800652E0: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    // 0x800652E4: jal         0x800CC390
    // 0x800652E8: nop

    alMainBusParam(rdram, ctx);
        goto after_11;
    // 0x800652E8: nop

    after_11:
    // 0x800652EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800652F0:
    // 0x800652F0: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x800652F4: bne         $at, $zero, L_800652A0
    if (ctx->r1 != 0) {
        // 0x800652F8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800652A0;
    }
    // 0x800652F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800652FC: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
    // 0x80065300: sw          $zero, 0x8($s6)
    MEM_W(0X8, ctx->r22) = 0;
    // 0x80065304: sw          $zero, 0x14($s6)
    MEM_W(0X14, ctx->r22) = 0;
    // 0x80065308: sw          $zero, 0x18($s6)
    MEM_W(0X18, ctx->r22) = 0;
    // 0x8006530C: sw          $zero, 0xC($s6)
    MEM_W(0XC, ctx->r22) = 0;
    // 0x80065310: sw          $zero, 0x10($s6)
    MEM_W(0X10, ctx->r22) = 0;
    // 0x80065314: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x80065318: addiu       $t2, $zero, 0xE0
    ctx->r10 = ADD32(0, 0XE0);
    // 0x8006531C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80065320: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065328: jal         0x800C77F0
    // 0x8006532C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_12;
    // 0x8006532C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_12:
    // 0x80065330: lw          $t3, 0x4($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X4);
    // 0x80065334: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80065338: blez        $t3, L_800653FC
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8006533C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800653FC;
    }
    // 0x8006533C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80065340: addiu       $a1, $s6, 0x4
    ctx->r5 = ADD32(ctx->r22, 0X4);
    // 0x80065344: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x80065348: addiu       $s2, $v0, 0x8C
    ctx->r18 = ADD32(ctx->r2, 0X8C);
    // 0x8006534C: addiu       $s3, $v0, 0x58
    ctx->r19 = ADD32(ctx->r2, 0X58);
    // 0x80065350: addiu       $s4, $v0, 0x10
    ctx->r20 = ADD32(ctx->r2, 0X10);
L_80065354:
    // 0x80065354: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80065358: or          $s5, $s1, $zero
    ctx->r21 = ctx->r17 | 0;
    // 0x8006535C: jal         0x800C8790
    // 0x80065360: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    alLink(rdram, ctx);
        goto after_13;
    // 0x80065360: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80065364: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x80065368: lw          $a1, 0x24($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X24);
    // 0x8006536C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80065370: jal         0x80064EF8
    // 0x80065374: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alLoadNew(rdram, ctx);
        goto after_14;
    // 0x80065374: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_14:
    // 0x80065378: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8006537C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80065380: jal         0x800CB540
    // 0x80065384: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alLoadParam(rdram, ctx);
        goto after_15;
    // 0x80065384: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x80065388: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8006538C: jal         0x80064F9C
    // 0x80065390: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    alResampleNew(rdram, ctx);
        goto after_16;
    // 0x80065390: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_16:
    // 0x80065394: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80065398: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006539C: jal         0x800CC090
    // 0x800653A0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    alResampleParam(rdram, ctx);
        goto after_17;
    // 0x800653A0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_17:
    // 0x800653A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800653A8: jal         0x80064E54
    // 0x800653AC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    alEnvmixerNew(rdram, ctx);
        goto after_18;
    // 0x800653AC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_18:
    // 0x800653B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800653B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800653B8: jal         0x800CAA7C
    // 0x800653BC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEnvmixerParam(rdram, ctx);
        goto after_19;
    // 0x800653BC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_19:
    // 0x800653C0: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x800653C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800653C8: jal         0x800659D4
    // 0x800653CC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    alAuxBusParam(rdram, ctx);
        goto after_20;
    // 0x800653CC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_20:
    // 0x800653D0: addiu       $t4, $s5, 0x8C
    ctx->r12 = ADD32(ctx->r21, 0X8C);
    // 0x800653D4: sw          $t4, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r12;
    // 0x800653D8: lw          $t5, 0x4($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X4);
    // 0x800653DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800653E0: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800653E4: addiu       $s1, $s1, 0xE0
    ctx->r17 = ADD32(ctx->r17, 0XE0);
    // 0x800653E8: addiu       $s2, $s2, 0xE0
    ctx->r18 = ADD32(ctx->r18, 0XE0);
    // 0x800653EC: addiu       $s3, $s3, 0xE0
    ctx->r19 = ADD32(ctx->r19, 0XE0);
    // 0x800653F0: bne         $at, $zero, L_80065354
    if (ctx->r1 != 0) {
        // 0x800653F4: addiu       $s4, $s4, 0xE0
        ctx->r20 = ADD32(ctx->r20, 0XE0);
            goto L_80065354;
    }
    // 0x800653F4: addiu       $s4, $s4, 0xE0
    ctx->r20 = ADD32(ctx->r20, 0XE0);
    // 0x800653F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800653FC:
    // 0x800653FC: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80065400: lw          $a2, 0x30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X30);
    // 0x80065404: jal         0x800CC4E0
    // 0x80065408: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    alSaveParam(rdram, ctx);
        goto after_21;
    // 0x80065408: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x8006540C: lw          $a3, 0x8($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X8);
    // 0x80065410: addiu       $t6, $zero, 0x1C
    ctx->r14 = ADD32(0, 0X1C);
    // 0x80065414: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80065418: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006541C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065420: jal         0x800C77F0
    // 0x80065424: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_22;
    // 0x80065424: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_22:
    // 0x80065428: sw          $zero, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = 0;
    // 0x8006542C: lw          $t7, 0x8($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X8);
    // 0x80065430: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80065434: blez        $t7, L_80065460
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80065438: nop
    
            goto L_80065460;
    }
    // 0x80065438: nop

L_8006543C:
    // 0x8006543C: lw          $t8, 0x2C($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X2C);
    // 0x80065440: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80065444: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80065448: sw          $v1, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->r3;
    // 0x8006544C: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x80065450: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x80065454: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80065458: bne         $at, $zero, L_8006543C
    if (ctx->r1 != 0) {
        // 0x8006545C: nop
    
            goto L_8006543C;
    }
    // 0x8006545C: nop

L_80065460:
    // 0x80065460: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
    // 0x80065464: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80065468: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8006546C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80065470: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80065474: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80065478: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8006547C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80065480: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80065484: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80065488: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006548C: jr          $ra
    // 0x80065490: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80065490: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void hud_render_player(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_netplay_presentation_random_begin(uint8_t*, recomp_context*); dkr_netplay_presentation_random_begin(rdram, ctx);
    // 0x800A01A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A01A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A01A8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800A01AC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800A01B0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    extern void dkr_hud_player_pass_begin(uint8_t*, recomp_context*); dkr_hud_player_pass_begin(rdram, ctx);
    // 0x800A01B4: jal         0x80066220
    // 0x800A01B8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    get_current_viewport(rdram, ctx);
        goto after_0;
    // 0x800A01B8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A01BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A01C0: lbu         $t6, 0x718A($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X718A);
    // 0x800A01C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A01C8: beq         $t6, $zero, L_800A01E8
    if (ctx->r14 == 0) {
        // 0x800A01CC: sw          $v0, 0x6D08($at)
        MEM_W(0X6D08, ctx->r1) = ctx->r2;
            goto L_800A01E8;
    }
    // 0x800A01CC: sw          $v0, 0x6D08($at)
    MEM_W(0X6D08, ctx->r1) = ctx->r2;
    // 0x800A01D0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A01D4: lw          $t7, 0x6D08($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D08);
    // 0x800A01D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A01DC: jal         0x8001BB18
    // 0x800A01E0: subu        $a0, $t8, $t7
    ctx->r4 = SUB32(ctx->r24, ctx->r15);
    get_racer_object_by_port(rdram, ctx);
        goto after_1;
    // 0x800A01E0: subu        $a0, $t8, $t7
    ctx->r4 = SUB32(ctx->r24, ctx->r15);
    after_1:
    // 0x800A01E4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_800A01E8:
    // 0x800A01E8: jal         0x8006BDB0
    // 0x800A01EC: nop

    level_header(rdram, ctx);
        goto after_2;
    // 0x800A01EC: nop

    after_2:
    // 0x800A01F0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800A01F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A01F8: bne         $t9, $zero, L_800A0220
    if (ctx->r25 != 0) {
        // 0x800A01FC: sw          $v0, 0x6D60($at)
        MEM_W(0X6D60, ctx->r1) = ctx->r2;
            goto L_800A0220;
    }
    // 0x800A01FC: sw          $v0, 0x6D60($at)
    MEM_W(0X6D60, ctx->r1) = ctx->r2;
    // 0x800A0200: jal         0x8001E440
    // 0x800A0204: nop

    cutscene_id(rdram, ctx);
        goto after_3;
    // 0x800A0204: nop

    after_3:
    // 0x800A0208: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A020C: bne         $v0, $at, L_800A0224
    if (ctx->r2 != ctx->r1) {
        // 0x800A0210: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_800A0224;
    }
    // 0x800A0210: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0214: jal         0x8001BB18
    // 0x800A0218: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object_by_port(rdram, ctx);
        goto after_4;
    // 0x800A0218: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800A021C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_800A0220:
    // 0x800A0220: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_800A0224:
    // 0x800A0224: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A0228: beq         $t0, $zero, L_800A0B68
    if (ctx->r8 == 0) {
        // 0x800A022C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A0B68;
    }
    // 0x800A022C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A0230: lw          $t1, 0x6D60($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6D60);
    // 0x800A0234: nop

    // 0x800A0238: lbu         $t2, 0xBC($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XBC);
    // 0x800A023C: nop

    // 0x800A0240: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x800A0244: bne         $t3, $zero, L_800A0B68
    if (ctx->r11 != 0) {
        // 0x800A0248: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A0B68;
    }
    // 0x800A0248: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A024C: jal         0x8006DA0C
    // 0x800A0250: nop

    get_game_mode(rdram, ctx);
        goto after_5;
    // 0x800A0250: nop

    after_5:
    // 0x800A0254: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800A0258: beq         $v0, $v1, L_800A0B64
    if (ctx->r2 == ctx->r3) {
        // 0x800A025C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800A0B64;
    }
    // 0x800A025C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0260: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800A0264: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800A0268: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800A026C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800A0270: sw          $t5, 0x6CFC($at)
    MEM_W(0X6CFC, ctx->r1) = ctx->r13;
    // 0x800A0274: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800A0278: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A027C: sw          $t8, 0x6D00($at)
    MEM_W(0X6D00, ctx->r1) = ctx->r24;
    // 0x800A0280: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800A0284: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0288: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A028C: lb          $t0, 0x6CD1($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X6CD1);
    // 0x800A0290: sw          $t9, 0x6D04($at)
    MEM_W(0X6D04, ctx->r1) = ctx->r25;
    // 0x800A0294: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0298: beq         $t0, $zero, L_800A02DC
    if (ctx->r8 == 0) {
        // 0x800A029C: sw          $zero, 0x7180($at)
        MEM_W(0X7180, ctx->r1) = 0;
            goto L_800A02DC;
    }
    // 0x800A029C: sw          $zero, 0x7180($at)
    MEM_W(0X7180, ctx->r1) = 0;
    // 0x800A02A0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A02A4: addiu       $a2, $a2, 0x6CD0
    ctx->r6 = ADD32(ctx->r6, 0X6CD0);
    // 0x800A02A8: lb          $t1, 0x0($a2)
    ctx->r9 = MEM_B(ctx->r6, 0X0);
    // 0x800A02AC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800A02B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A02B4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800A02B8: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
    // 0x800A02BC: lb          $t4, 0x0($a2)
    ctx->r12 = MEM_B(ctx->r6, 0X0);
    // 0x800A02C0: lbu         $v0, 0x718B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X718B);
    // 0x800A02C4: nop

    // 0x800A02C8: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800A02CC: beq         $at, $zero, L_800A030C
    if (ctx->r1 == 0) {
        // 0x800A02D0: nop
    
            goto L_800A030C;
    }
    // 0x800A02D0: nop

    // 0x800A02D4: b           L_800A030C
    // 0x800A02D8: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
        goto L_800A030C;
    // 0x800A02D8: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
L_800A02DC:
    // 0x800A02DC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A02E0: addiu       $a2, $a2, 0x6CD0
    ctx->r6 = ADD32(ctx->r6, 0X6CD0);
    // 0x800A02E4: lb          $t5, 0x0($a2)
    ctx->r13 = MEM_B(ctx->r6, 0X0);
    // 0x800A02E8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800A02EC: nop

    // 0x800A02F0: subu        $t8, $t5, $t6
    ctx->r24 = SUB32(ctx->r13, ctx->r14);
    // 0x800A02F4: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    // 0x800A02F8: lb          $t7, 0x0($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X0);
    // 0x800A02FC: nop

    // 0x800A0300: bgez        $t7, L_800A030C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800A0304: nop
    
            goto L_800A030C;
    }
    // 0x800A0304: nop

    // 0x800A0308: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
L_800A030C:
    // 0x800A030C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A0310: lb          $t9, 0x6CD2($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X6CD2);
    // 0x800A0314: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0318: bne         $t9, $zero, L_800A0B64
    if (ctx->r25 != 0) {
        // 0x800A031C: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800A0B64;
    }
    // 0x800A031C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A0320: lbu         $t1, 0x718A($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X718A);
    // 0x800A0324: lw          $v0, 0x64($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X64);
    // 0x800A0328: beq         $t1, $zero, L_800A0344
    if (ctx->r9 == 0) {
        // 0x800A032C: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800A0344;
    }
    // 0x800A032C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A0330: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x800A0334: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0338: subu        $t3, $v1, $t2
    ctx->r11 = SUB32(ctx->r3, ctx->r10);
    // 0x800A033C: b           L_800A0350
    // 0x800A0340: sw          $t3, 0x6D10($at)
    MEM_W(0X6D10, ctx->r1) = ctx->r11;
        goto L_800A0350;
    // 0x800A0340: sw          $t3, 0x6D10($at)
    MEM_W(0X6D10, ctx->r1) = ctx->r11;
L_800A0344:
    // 0x800A0344: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x800A0348: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A034C: sw          $t4, 0x6D10($at)
    MEM_W(0X6D10, ctx->r1) = ctx->r12;
L_800A0350:
    // 0x800A0350: lw          $t5, 0x6D08($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D08);
    // 0x800A0354: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A0358: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800A035C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x800A0360: lw          $t8, 0x6CE0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6CE0);
    // 0x800A0364: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0368: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800A036C: jal         0x8001E440
    // 0x800A0370: sw          $t8, 0x6CDC($at)
    MEM_W(0X6CDC, ctx->r1) = ctx->r24;
    cutscene_id(rdram, ctx);
        goto after_6;
    // 0x800A0370: sw          $t8, 0x6CDC($at)
    MEM_W(0X6CDC, ctx->r1) = ctx->r24;
    after_6:
    // 0x800A0374: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A0378: beq         $v0, $at, L_800A05A8
    if (ctx->r2 == ctx->r1) {
        // 0x800A037C: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800A05A8;
    }
    // 0x800A037C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A0380: lw          $t7, 0x6D0C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D0C);
    // 0x800A0384: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0388: bne         $t7, $zero, L_800A0448
    if (ctx->r15 != 0) {
        // 0x800A038C: nop
    
            goto L_800A0448;
    }
    // 0x800A038C: nop

    // 0x800A0390: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0394: lw          $a0, 0x6D10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6D10);
    // 0x800A0398: jal         0x8006A554
    // 0x800A039C: nop

    input_pressed(rdram, ctx);
        goto after_7;
    // 0x800A039C: nop

    after_7:
    // 0x800A03A0: andi        $t9, $v0, 0x4
    ctx->r25 = ctx->r2 & 0X4;
    // 0x800A03A4: beq         $t9, $zero, L_800A050C
    if (ctx->r25 == 0) {
        // 0x800A03A8: nop
    
            goto L_800A050C;
    }
    // 0x800A03A8: nop

    // 0x800A03AC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800A03B0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A03B4: lb          $t1, 0x1D8($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X1D8);
    // 0x800A03B8: nop

    // 0x800A03BC: bne         $t1, $zero, L_800A050C
    if (ctx->r9 != 0) {
        // 0x800A03C0: nop
    
            goto L_800A050C;
    }
    // 0x800A03C0: nop

    // 0x800A03C4: lw          $t2, 0x6D60($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6D60);
    // 0x800A03C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A03CC: lb          $v0, 0x4C($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X4C);
    // 0x800A03D0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A03D4: beq         $v0, $zero, L_800A03E4
    if (ctx->r2 == 0) {
        // 0x800A03D8: nop
    
            goto L_800A03E4;
    }
    // 0x800A03D8: nop

    // 0x800A03DC: bne         $v0, $at, L_800A050C
    if (ctx->r2 != ctx->r1) {
        // 0x800A03E0: nop
    
            goto L_800A050C;
    }
    // 0x800A03E0: nop

L_800A03E4:
    // 0x800A03E4: lbu         $t3, 0x6D34($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X6D34);
    // 0x800A03E8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A03EC: beq         $t3, $zero, L_800A050C
    if (ctx->r11 == 0) {
        // 0x800A03F0: addiu       $v0, $v0, 0x2790
        ctx->r2 = ADD32(ctx->r2, 0X2790);
            goto L_800A050C;
    }
    // 0x800A03F0: addiu       $v0, $v0, 0x2790
    ctx->r2 = ADD32(ctx->r2, 0X2790);
    // 0x800A03F4: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x800A03F8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800A03FC: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x800A0400: andi        $a0, $t6, 0xFF
    ctx->r4 = ctx->r14 & 0XFF;
    // 0x800A0404: addiu       $a0, $a0, 0x14F
    ctx->r4 = ADD32(ctx->r4, 0X14F);
    // 0x800A0408: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x800A040C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800A0410: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800A0414: jal         0x80001D04
    // 0x800A0418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800A0418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x800A041C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A0420: addiu       $v0, $v0, 0x2790
    ctx->r2 = ADD32(ctx->r2, 0X2790);
    // 0x800A0424: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800A0428: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x800A042C: beq         $t7, $zero, L_800A0440
    if (ctx->r15 == 0) {
        // 0x800A0430: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800A0440;
    }
    // 0x800A0430: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A0434: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A0438: b           L_800A050C
    // 0x800A043C: sb          $t9, 0x27B8($at)
    MEM_B(0X27B8, ctx->r1) = ctx->r25;
        goto L_800A050C;
    // 0x800A043C: sb          $t9, 0x27B8($at)
    MEM_B(0X27B8, ctx->r1) = ctx->r25;
L_800A0440:
    // 0x800A0440: b           L_800A050C
    // 0x800A0444: sb          $zero, 0x27B8($at)
    MEM_B(0X27B8, ctx->r1) = 0;
        goto L_800A050C;
    // 0x800A0444: sb          $zero, 0x27B8($at)
    MEM_B(0X27B8, ctx->r1) = 0;
L_800A0448:
    // 0x800A0448: lw          $a0, 0x6D10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6D10);
    // 0x800A044C: jal         0x8006A554
    // 0x800A0450: nop

    input_pressed(rdram, ctx);
        goto after_9;
    // 0x800A0450: nop

    after_9:
    // 0x800A0454: andi        $t0, $v0, 0x4
    ctx->r8 = ctx->r2 & 0X4;
    // 0x800A0458: beq         $t0, $zero, L_800A050C
    if (ctx->r8 == 0) {
        // 0x800A045C: nop
    
            goto L_800A050C;
    }
    // 0x800A045C: nop

    // 0x800A0460: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800A0464: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A0468: lb          $t2, 0x1D8($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X1D8);
    // 0x800A046C: nop

    // 0x800A0470: bne         $t2, $zero, L_800A050C
    if (ctx->r10 != 0) {
        // 0x800A0474: nop
    
            goto L_800A050C;
    }
    // 0x800A0474: nop

    // 0x800A0478: lw          $t3, 0x6D60($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6D60);
    // 0x800A047C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A0480: lb          $t5, 0x4C($t3)
    ctx->r13 = MEM_B(ctx->r11, 0X4C);
    // 0x800A0484: nop

    // 0x800A0488: andi        $t4, $t5, 0x40
    ctx->r12 = ctx->r13 & 0X40;
    // 0x800A048C: bne         $t4, $zero, L_800A050C
    if (ctx->r12 != 0) {
        // 0x800A0490: nop
    
            goto L_800A050C;
    }
    // 0x800A0490: nop

    // 0x800A0494: lbu         $t6, 0x6D34($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X6D34);
    // 0x800A0498: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A049C: beq         $t6, $zero, L_800A050C
    if (ctx->r14 == 0) {
        // 0x800A04A0: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800A050C;
    }
    // 0x800A04A0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800A04A4: lw          $t8, 0x6D0C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6D0C);
    // 0x800A04A8: lh          $t0, 0x0($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X0);
    // 0x800A04AC: addiu       $t9, $t9, 0x2794
    ctx->r25 = ADD32(ctx->r25, 0X2794);
    // 0x800A04B0: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800A04B4: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x800A04B8: addu        $v0, $v1, $t0
    ctx->r2 = ADD32(ctx->r3, ctx->r8);
    // 0x800A04BC: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800A04C0: nop

    // 0x800A04C4: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800A04C8: beq         $at, $zero, L_800A04D8
    if (ctx->r1 == 0) {
        // 0x800A04CC: addiu       $t2, $a0, 0x1
        ctx->r10 = ADD32(ctx->r4, 0X1);
            goto L_800A04D8;
    }
    // 0x800A04CC: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
    // 0x800A04D0: b           L_800A04DC
    // 0x800A04D4: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
        goto L_800A04DC;
    // 0x800A04D4: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
L_800A04D8:
    // 0x800A04D8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_800A04DC:
    // 0x800A04DC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A04E0: addiu       $t7, $zero, 0x150
    ctx->r15 = ADD32(0, 0X150);
    // 0x800A04E4: lh          $t5, 0x0($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X0);
    // 0x800A04E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A04EC: addu        $t4, $v1, $t5
    ctx->r12 = ADD32(ctx->r3, ctx->r13);
    // 0x800A04F0: lbu         $t6, 0x0($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X0);
    // 0x800A04F4: nop

    // 0x800A04F8: sltiu       $t8, $t6, 0x1
    ctx->r24 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800A04FC: subu        $a0, $t7, $t8
    ctx->r4 = SUB32(ctx->r15, ctx->r24);
    // 0x800A0500: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x800A0504: jal         0x80001D04
    // 0x800A0508: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800A0508: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_10:
L_800A050C:
    // 0x800A050C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0510: lw          $a0, 0x6D10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6D10);
    // 0x800A0514: jal         0x8006A554
    // 0x800A0518: nop

    input_pressed(rdram, ctx);
        goto after_11;
    // 0x800A0518: nop

    after_11:
    // 0x800A051C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A0520: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x800A0524: beq         $t1, $zero, L_800A05A8
    if (ctx->r9 == 0) {
        // 0x800A0528: addiu       $a2, $a2, 0x6CD0
        ctx->r6 = ADD32(ctx->r6, 0X6CD0);
            goto L_800A05A8;
    }
    // 0x800A0528: addiu       $a2, $a2, 0x6CD0
    ctx->r6 = ADD32(ctx->r6, 0X6CD0);
    // 0x800A052C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800A0530: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A0534: lb          $t2, 0x1D8($t0)
    ctx->r10 = MEM_B(ctx->r8, 0X1D8);
    // 0x800A0538: nop

    // 0x800A053C: bne         $t2, $zero, L_800A05A8
    if (ctx->r10 != 0) {
        // 0x800A0540: nop
    
            goto L_800A05A8;
    }
    // 0x800A0540: nop

    // 0x800A0544: lbu         $t3, 0x6D34($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X6D34);
    // 0x800A0548: nop

    // 0x800A054C: beq         $t3, $zero, L_800A05A8
    if (ctx->r11 == 0) {
        // 0x800A0550: nop
    
            goto L_800A05A8;
    }
    // 0x800A0550: nop

    // 0x800A0554: lb          $t5, 0x0($a2)
    ctx->r13 = MEM_B(ctx->r6, 0X0);
    // 0x800A0558: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A055C: bne         $t5, $zero, L_800A05A8
    if (ctx->r13 != 0) {
        // 0x800A0560: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_800A05A8;
    }
    // 0x800A0560: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A0564: lw          $t4, 0x6D0C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6D0C);
    // 0x800A0568: addiu       $t6, $t6, 0x27A4
    ctx->r14 = ADD32(ctx->r14, 0X27A4);
    // 0x800A056C: addu        $v0, $t4, $t6
    ctx->r2 = ADD32(ctx->r12, ctx->r14);
    // 0x800A0570: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x800A0574: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A0578: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x800A057C: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800A0580: lb          $t1, 0x0($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X0);
    // 0x800A0584: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A0588: bne         $t1, $zero, L_800A05A0
    if (ctx->r9 != 0) {
        // 0x800A058C: addiu       $a0, $zero, 0x5E
        ctx->r4 = ADD32(0, 0X5E);
            goto L_800A05A0;
    }
    // 0x800A058C: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    // 0x800A0590: jal         0x80001D04
    // 0x800A0594: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    sound_play(rdram, ctx);
        goto after_12;
    // 0x800A0594: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_12:
    // 0x800A0598: b           L_800A05A8
    // 0x800A059C: nop

        goto L_800A05A8;
    // 0x800A059C: nop

L_800A05A0:
    // 0x800A05A0: jal         0x80001D04
    // 0x800A05A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x800A05A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
L_800A05A8:
    // 0x800A05A8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A05AC: lb          $t0, 0x6CD4($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X6CD4);
    // 0x800A05B0: nop

    // 0x800A05B4: bne         $t0, $zero, L_800A0648
    if (ctx->r8 != 0) {
        // 0x800A05B8: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800A0648;
    }
    // 0x800A05B8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A05BC: lw          $t2, 0x6D60($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6D60);
    // 0x800A05C0: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x800A05C4: lb          $v0, 0x4C($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X4C);
    // 0x800A05C8: nop

    // 0x800A05CC: andi        $t3, $v0, 0x40
    ctx->r11 = ctx->r2 & 0X40;
    // 0x800A05D0: bne         $t3, $zero, L_800A05EC
    if (ctx->r11 != 0) {
        // 0x800A05D4: nop
    
            goto L_800A05EC;
    }
    // 0x800A05D4: nop

    // 0x800A05D8: beq         $v0, $zero, L_800A05EC
    if (ctx->r2 == 0) {
        // 0x800A05DC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A05EC;
    }
    // 0x800A05DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A05E0: beq         $v0, $at, L_800A05EC
    if (ctx->r2 == ctx->r1) {
        // 0x800A05E4: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800A05EC;
    }
    // 0x800A05E4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A05E8: bne         $v0, $at, L_800A0620
    if (ctx->r2 != ctx->r1) {
        // 0x800A05EC: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800A0620;
    }
L_800A05EC:
    // 0x800A05EC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A05F0: addiu       $v0, $v0, 0x2770
    ctx->r2 = ADD32(ctx->r2, 0X2770);
    // 0x800A05F4: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // 0x800A05F8: jal         0x80001844
    // 0x800A05FC: sb          $v1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r3;
    music_stop(rdram, ctx);
        goto after_14;
    // 0x800A05FC: sb          $v1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r3;
    after_14:
    // 0x800A0600: jal         0x800012E8
    // 0x800A0604: nop

    music_channel_reset_all(rdram, ctx);
        goto after_15;
    // 0x800A0604: nop

    after_15:
    // 0x800A0608: jal         0x80000B34
    // 0x800A060C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    music_play(rdram, ctx);
        goto after_16;
    // 0x800A060C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_16:
    // 0x800A0610: jal         0x8000318C
    // 0x800A0614: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_17;
    // 0x800A0614: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_17:
    // 0x800A0618: b           L_800A0630
    // 0x800A061C: nop

        goto L_800A0630;
    // 0x800A061C: nop

L_800A0620:
    // 0x800A0620: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A0624: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A0628: jal         0x8006BD10
    // 0x800A062C: nop

    level_music_start(rdram, ctx);
        goto after_18;
    // 0x800A062C: nop

    after_18:
L_800A0630:
    // 0x800A0630: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A0634: addiu       $v0, $v0, 0x6CD4
    ctx->r2 = ADD32(ctx->r2, 0X6CD4);
    // 0x800A0638: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x800A063C: nop

    // 0x800A0640: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800A0644: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
L_800A0648:
    // 0x800A0648: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A064C: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A0650: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A0654: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800A0658: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800A065C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800A0660: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A0664: jal         0x800780DC
    // 0x800A0668: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    rsp_init(rdram, ctx);
        goto after_19;
    // 0x800A0668: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    after_19:
    // 0x800A066C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0670: jal         0x80078054
    // 0x800A0674: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    rdp_init(rdram, ctx);
        goto after_20;
    // 0x800A0674: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    after_20:
    // 0x800A0678: jal         0x8007AE28
    // 0x800A067C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    tex_enable_modes(rdram, ctx);
        goto after_21;
    // 0x800A067C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_21:
    // 0x800A0680: jal         0x8007AE0C
    // 0x800A0684: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    tex_disable_modes(rdram, ctx);
        goto after_22;
    // 0x800A0684: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_22:
    // 0x800A0688: jal         0x8007BF1C
    // 0x800A068C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_23;
    // 0x800A068C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_23:
    // 0x800A0690: jal         0x80066510
    // 0x800A0694: nop

    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_24;
    // 0x800A0694: nop

    after_24:
    // 0x800A0698: bne         $v0, $zero, L_800A0834
    if (ctx->r2 != 0) {
        // 0x800A069C: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800A0834;
    }
    // 0x800A069C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A06A0: lbu         $t7, 0x6D34($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X6D34);
    // 0x800A06A4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800A06A8: bne         $t7, $zero, L_800A0834
    if (ctx->r15 != 0) {
        // 0x800A06AC: nop
    
            goto L_800A0834;
    }
    // 0x800A06AC: nop

    // 0x800A06B0: lh          $t1, 0x0($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X0);
    // 0x800A06B4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A06B8: bne         $t1, $zero, L_800A0834
    if (ctx->r9 != 0) {
        // 0x800A06BC: nop
    
            goto L_800A0834;
    }
    // 0x800A06BC: nop

    // 0x800A06C0: lbu         $t0, 0x6D35($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X6D35);
    // 0x800A06C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A06C8: beq         $t0, $zero, L_800A07B0
    if (ctx->r8 == 0) {
        // 0x800A06CC: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800A07B0;
    }
    // 0x800A06CC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A06D0: addiu       $v0, $v0, 0x6D2C
    ctx->r2 = ADD32(ctx->r2, 0X6D2C);
    // 0x800A06D4: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x800A06D8: jal         0x800707C4
    // 0x800A06DC: nop

    sins_f(rdram, ctx);
        goto after_25;
    // 0x800A06DC: nop

    after_25:
    // 0x800A06E0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A06E4: addiu       $a0, $a0, 0x6D30
    ctx->r4 = ADD32(ctx->r4, 0X6D30);
    // 0x800A06E8: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A06EC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800A06F0: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A06F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A06F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A06FC: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800A0700: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A0704: addiu       $v0, $v0, 0x6D2C
    ctx->r2 = ADD32(ctx->r2, 0X6D2C);
    // 0x800A0708: sll         $t6, $t4, 11
    ctx->r14 = S32(ctx->r12 << 11);
    // 0x800A070C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A0710: nop

    // 0x800A0714: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A0718: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A071C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A0720: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0724: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A0728: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800A072C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A0730: sw          $t3, 0x6D28($at)
    MEM_W(0X6D28, ctx->r1) = ctx->r11;
    // 0x800A0734: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
    // 0x800A0738: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800A073C: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x800A0740: andi        $v1, $t8, 0xFFFF
    ctx->r3 = ctx->r24 & 0XFFFF;
    // 0x800A0744: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800A0748: bne         $at, $zero, L_800A0834
    if (ctx->r1 != 0) {
        // 0x800A074C: sh          $t8, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r24;
            goto L_800A0834;
    }
    // 0x800A074C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800A0750: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800A0754: addu        $t7, $v1, $at
    ctx->r15 = ADD32(ctx->r3, ctx->r1);
    // 0x800A0758: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A075C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A0760: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800A0764: div.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800A0768: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A076C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A0770: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A0774: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800A0778: addiu       $v1, $v1, 0x6D24
    ctx->r3 = ADD32(ctx->r3, 0X6D24);
    // 0x800A077C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0780: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800A0784: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x800A0788: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A078C: nop

    // 0x800A0790: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A0794: c.le.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d <= ctx->f4.d;
    // 0x800A0798: nop

    // 0x800A079C: bc1f        L_800A0834
    if (!c1cs) {
        // 0x800A07A0: nop
    
            goto L_800A0834;
    }
    // 0x800A07A0: nop

    // 0x800A07A4: sb          $t9, 0x6D34($at)
    MEM_B(0X6D34, ctx->r1) = ctx->r25;
    // 0x800A07A8: b           L_800A0834
    // 0x800A07AC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800A0834;
    // 0x800A07AC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800A07B0:
    // 0x800A07B0: lb          $t1, 0x6CD4($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X6CD4);
    // 0x800A07B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A07B8: bne         $t1, $at, L_800A07DC
    if (ctx->r9 != ctx->r1) {
        // 0x800A07BC: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_800A07DC;
    }
    // 0x800A07BC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A07C0: jal         0x80001D04
    // 0x800A07C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_26;
    // 0x800A07C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x800A07C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A07CC: lb          $t0, 0x6CD4($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X6CD4);
    // 0x800A07D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A07D4: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800A07D8: sb          $t2, 0x6CD4($at)
    MEM_B(0X6CD4, ctx->r1) = ctx->r10;
L_800A07DC:
    // 0x800A07DC: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800A07E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A07E4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800A07E8: addiu       $v1, $v1, 0x6D24
    ctx->r3 = ADD32(ctx->r3, 0X6D24);
    // 0x800A07EC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800A07F0: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800A07F4: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A07F8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800A07FC: subu        $v0, $t3, $t5
    ctx->r2 = SUB32(ctx->r11, ctx->r13);
    // 0x800A0800: bgez        $v0, L_800A0810
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A0804: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800A0810;
    }
    // 0x800A0804: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800A0808: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800A080C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A0810:
    // 0x800A0810: bne         $v0, $zero, L_800A0834
    if (ctx->r2 != 0) {
        // 0x800A0814: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800A0834;
    }
    // 0x800A0814: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A0818: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A081C: sb          $t8, 0x6D35($at)
    MEM_B(0X6D35, ctx->r1) = ctx->r24;
    // 0x800A0820: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x800A0824: jal         0x80001D04
    // 0x800A0828: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_27;
    // 0x800A0828: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x800A082C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0830: sw          $zero, 0x6D28($at)
    MEM_W(0X6D28, ctx->r1) = 0;
L_800A0834:
    // 0x800A0834: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A0838: addiu       $a1, $a1, 0x6CFC
    ctx->r5 = ADD32(ctx->r5, 0X6CFC);
    // 0x800A083C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A0840: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800A0844: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800A0848: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800A084C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800A0850: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800A0854: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A0858: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800A085C: jal         0x800A7A60
    // 0x800A0860: nop

    hud_magnet_reticle(rdram, ctx);
        goto after_28;
    // 0x800A0860: nop

    after_28:
    // 0x800A0864: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0868: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A086C: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A0870: jal         0x80067F2C
    // 0x800A0874: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    mtx_ortho(rdram, ctx);
        goto after_29;
    // 0x800A0874: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    after_29:
    // 0x800A0878: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A087C: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A0880: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A0884: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x800A0888: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800A088C: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800A0890: addiu       $t4, $zero, -0x100
    ctx->r12 = ADD32(0, -0X100);
    // 0x800A0894: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800A0898: jal         0x8001139C
    // 0x800A089C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    get_race_countdown(rdram, ctx);
        goto after_30;
    // 0x800A089C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_30:
    // 0x800A08A0: sra         $a0, $v0, 1
    ctx->r4 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800A08A4: jal         0x8000E4D8
    // 0x800A08A8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    is_in_time_trial(rdram, ctx);
        goto after_31;
    // 0x800A08A8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_31:
    // 0x800A08AC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A08B0: beq         $v0, $zero, L_800A08D0
    if (ctx->r2 == 0) {
        // 0x800A08B4: nop
    
            goto L_800A08D0;
    }
    // 0x800A08B4: nop

    // 0x800A08B8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A08BC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A08C0: jal         0x800A277C
    // 0x800A08C4: nop

    hud_main_time_trial(rdram, ctx);
        goto after_32;
    // 0x800A08C4: nop

    after_32:
    // 0x800A08C8: b           L_800A0A08
    // 0x800A08CC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0A08;
    // 0x800A08CC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A08D0:
    // 0x800A08D0: jal         0x8001E440
    // 0x800A08D4: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    cutscene_id(rdram, ctx);
        goto after_33;
    // 0x800A08D4: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_33:
    // 0x800A08D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A08DC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A08E0: bne         $v0, $at, L_800A090C
    if (ctx->r2 != ctx->r1) {
        // 0x800A08E4: nop
    
            goto L_800A090C;
    }
    // 0x800A08E4: nop

    // 0x800A08E8: jal         0x80068508
    // 0x800A08EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_34;
    // 0x800A08EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_34:
    // 0x800A08F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A08F4: jal         0x800A718C
    // 0x800A08F8: nop

    hud_balloons(rdram, ctx);
        goto after_35;
    // 0x800A08F8: nop

    after_35:
    // 0x800A08FC: jal         0x80068508
    // 0x800A0900: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_36;
    // 0x800A0900: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_36:
    // 0x800A0904: b           L_800A0A08
    // 0x800A0908: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0A08;
    // 0x800A0908: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A090C:
    // 0x800A090C: jal         0x8006BD98
    // 0x800A0910: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    level_type(rdram, ctx);
        goto after_37;
    // 0x800A0910: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_37:
    // 0x800A0914: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A0918: beq         $v0, $zero, L_800A0950
    if (ctx->r2 == 0) {
        // 0x800A091C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A0950;
    }
    // 0x800A091C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A0920: beq         $v0, $at, L_800A0950
    if (ctx->r2 == ctx->r1) {
        // 0x800A0924: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800A0950;
    }
    // 0x800A0924: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A0928: beq         $v0, $at, L_800A0994
    if (ctx->r2 == ctx->r1) {
        // 0x800A092C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800A0994;
    }
    // 0x800A092C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A0930: beq         $v0, $at, L_800A09C4
    if (ctx->r2 == ctx->r1) {
        // 0x800A0934: addiu       $at, $zero, 0x41
        ctx->r1 = ADD32(0, 0X41);
            goto L_800A09C4;
    }
    // 0x800A0934: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800A0938: beq         $v0, $at, L_800A09AC
    if (ctx->r2 == ctx->r1) {
        // 0x800A093C: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_800A09AC;
    }
    // 0x800A093C: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x800A0940: beq         $v0, $at, L_800A09E0
    if (ctx->r2 == ctx->r1) {
        // 0x800A0944: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_800A09E0;
    }
    // 0x800A0944: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0948: b           L_800A09F8
    // 0x800A094C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
        goto L_800A09F8;
    // 0x800A094C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
L_800A0950:
    // 0x800A0950: jal         0x8002341C
    // 0x800A0954: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    is_taj_challenge(rdram, ctx);
        goto after_38;
    // 0x800A0954: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_38:
    // 0x800A0958: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A095C: beq         $v0, $zero, L_800A0980
    if (ctx->r2 == 0) {
        // 0x800A0960: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_800A0980;
    }
    // 0x800A0960: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0964: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0968: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A096C: jal         0x800A263C
    // 0x800A0970: nop

    hud_main_taj(rdram, ctx);
        goto after_39;
    // 0x800A0970: nop

    after_39:
    // 0x800A0974: b           L_800A0A08
    // 0x800A0978: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0A08;
    // 0x800A0978: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A097C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
L_800A0980:
    // 0x800A0980: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A0984: jal         0x800A0DC0
    // 0x800A0988: nop

    hud_main_race(rdram, ctx);
        goto after_40;
    // 0x800A0988: nop

    after_40:
    // 0x800A098C: b           L_800A0A08
    // 0x800A0990: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0A08;
    // 0x800A0990: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A0994:
    // 0x800A0994: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0998: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A099C: jal         0x800A258C
    // 0x800A09A0: nop

    hud_main_boss(rdram, ctx);
        goto after_41;
    // 0x800A09A0: nop

    after_41:
    // 0x800A09A4: b           L_800A0A08
    // 0x800A09A8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0A08;
    // 0x800A09A8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A09AC:
    // 0x800A09AC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A09B0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A09B4: jal         0x800A1248
    // 0x800A09B8: nop

    hud_main_treasure(rdram, ctx);
        goto after_42;
    // 0x800A09B8: nop

    after_42:
    // 0x800A09BC: b           L_800A0A08
    // 0x800A09C0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0A08;
    // 0x800A09C0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A09C4:
    // 0x800A09C4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A09C8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A09CC: jal         0x800A1C04
    // 0x800A09D0: nop

    hud_main_battle(rdram, ctx);
        goto after_43;
    // 0x800A09D0: nop

    after_43:
    // 0x800A09D4: b           L_800A0A08
    // 0x800A09D8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0A08;
    // 0x800A09D8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A09DC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
L_800A09E0:
    // 0x800A09E0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A09E4: jal         0x800A1428
    // 0x800A09E8: nop

    hud_main_eggs(rdram, ctx);
        goto after_44;
    // 0x800A09E8: nop

    after_44:
    // 0x800A09EC: b           L_800A0A08
    // 0x800A09F0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0A08;
    // 0x800A09F0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A09F4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
L_800A09F8:
    // 0x800A09F8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800A09FC: jal         0x800A26C8
    // 0x800A0A00: nop

    hud_main_hub(rdram, ctx);
        goto after_45;
    // 0x800A0A00: nop

    after_45:
    // 0x800A0A04: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A0A08:
    // 0x800A0A08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A0A0C: lb          $t5, 0x1D8($t3)
    ctx->r13 = MEM_B(ctx->r11, 0X1D8);
    // 0x800A0A10: nop

    // 0x800A0A14: bne         $t5, $at, L_800A0AC8
    if (ctx->r13 != ctx->r1) {
        // 0x800A0A18: nop
    
            goto L_800A0AC8;
    }
    // 0x800A0A18: nop

    // 0x800A0A1C: jal         0x80068508
    // 0x800A0A20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_46;
    // 0x800A0A20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_46:
    // 0x800A0A24: jal         0x8000E4D8
    // 0x800A0A28: nop

    is_in_time_trial(rdram, ctx);
        goto after_47;
    // 0x800A0A28: nop

    after_47:
    // 0x800A0A2C: beq         $v0, $zero, L_800A0A4C
    if (ctx->r2 == 0) {
        // 0x800A0A30: nop
    
            goto L_800A0A4C;
    }
    // 0x800A0A30: nop

    // 0x800A0A34: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0A38: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800A0A3C: jal         0x800A6E30
    // 0x800A0A40: nop

    hud_time_trial_finish(rdram, ctx);
        goto after_48;
    // 0x800A0A40: nop

    after_48:
    // 0x800A0A44: b           L_800A0AC0
    // 0x800A0A48: nop

        goto L_800A0AC0;
    // 0x800A0A48: nop

L_800A0A4C:
    // 0x800A0A4C: jal         0x80066210
    // 0x800A0A50: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_49;
    // 0x800A0A50: nop

    after_49:
    // 0x800A0A54: bne         $v0, $zero, L_800A0AB4
    if (ctx->r2 != 0) {
        // 0x800A0A58: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800A0AB4;
    }
    // 0x800A0A58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0A5C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800A0A60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A0A64: lh          $t8, 0x1AC($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X1AC);
    // 0x800A0A68: nop

    // 0x800A0A6C: bne         $t8, $at, L_800A0AB4
    if (ctx->r24 != ctx->r1) {
        // 0x800A0A70: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800A0AB4;
    }
    // 0x800A0A70: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0A74: jal         0x8009EC80
    // 0x800A0A78: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_50;
    // 0x800A0A78: nop

    after_50:
    // 0x800A0A7C: beq         $v0, $zero, L_800A0A9C
    if (ctx->r2 == 0) {
        // 0x800A0A80: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800A0A9C;
    }
    // 0x800A0A80: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0A84: jal         0x8006BD98
    // 0x800A0A88: nop

    level_type(rdram, ctx);
        goto after_51;
    // 0x800A0A88: nop

    after_51:
    // 0x800A0A8C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A0A90: bne         $v0, $at, L_800A0AB4
    if (ctx->r2 != ctx->r1) {
        // 0x800A0A94: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800A0AB4;
    }
    // 0x800A0A94: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0A98: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_800A0A9C:
    // 0x800A0A9C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800A0AA0: jal         0x800A497C
    // 0x800A0AA4: nop

    hud_race_finish_1player(rdram, ctx);
        goto after_52;
    // 0x800A0AA4: nop

    after_52:
    // 0x800A0AA8: b           L_800A0AC0
    // 0x800A0AAC: nop

        goto L_800A0AC0;
    // 0x800A0AAC: nop

    // 0x800A0AB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_800A0AB4:
    // 0x800A0AB4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800A0AB8: jal         0x800A6254
    // 0x800A0ABC: nop

    hud_race_finish_multiplayer(rdram, ctx);
        goto after_53;
    // 0x800A0ABC: nop

    after_53:
L_800A0AC0:
    // 0x800A0AC0: jal         0x80068508
    // 0x800A0AC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_54;
    // 0x800A0AC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_54:
L_800A0AC8:
    // 0x800A0AC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0ACC: sb          $zero, 0x6CD1($at)
    MEM_B(0X6CD1, ctx->r1) = 0;
    // 0x800A0AD0: jal         0x8007BF1C
    // 0x800A0AD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_55;
    // 0x800A0AD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_55:
    // 0x800A0AD8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A0ADC: lw          $v0, 0x7180($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7180);
    // 0x800A0AE0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A0AE4: beq         $v0, $zero, L_800A0B2C
    if (ctx->r2 == 0) {
        // 0x800A0AE8: addiu       $a1, $a1, 0x6D80
        ctx->r5 = ADD32(ctx->r5, 0X6D80);
            goto L_800A0B2C;
    }
    // 0x800A0AE8: addiu       $a1, $a1, 0x6D80
    ctx->r5 = ADD32(ctx->r5, 0X6D80);
    // 0x800A0AEC: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800A0AF0: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x800A0AF4: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800A0AF8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0AFC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A0B00: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A0B04: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A0B08: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A0B0C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800A0B10: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800A0B14: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800A0B18: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800A0B1C: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A0B20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A0B24: jal         0x80078AB8
    // 0x800A0B28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    texrect_draw(rdram, ctx);
        goto after_56;
    // 0x800A0B28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_56:
L_800A0B2C:
    // 0x800A0B2C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A0B30: lw          $t3, 0x6CFC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6CFC);
    // 0x800A0B34: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800A0B38: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A0B3C: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x800A0B40: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800A0B44: lw          $t6, 0x6D00($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D00);
    // 0x800A0B48: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A0B4C: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800A0B50: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800A0B54: lw          $t7, 0x6D04($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D04);
    // 0x800A0B58: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800A0B5C: jal         0x8007AE28
    // 0x800A0B60: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    tex_enable_modes(rdram, ctx);
        goto after_57;
    // 0x800A0B60: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    after_57:
L_800A0B64:
    // 0x800A0B64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A0B68:
    extern void dkr_hud_player_pass_end(uint8_t*, recomp_context*); extern void dkr_netplay_presentation_random_end(uint8_t*, recomp_context*); dkr_hud_player_pass_end(rdram, ctx); dkr_netplay_presentation_random_end(rdram, ctx);
    // 0x800A0B68: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A0B6C: jr          $ra
    // 0x800A0B70: nop

    return;
    // 0x800A0B70: nop

;}
RECOMP_FUNC void get_text_width(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4DA0: bne         $a0, $zero, L_800C4DB0
    if (ctx->r4 != 0) {
        // 0x800C4DA4: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800C4DB0;
    }
    // 0x800C4DA4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C4DA8: jr          $ra
    // 0x800C4DAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C4DAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C4DB0:
    // 0x800C4DB0: bgez        $a2, L_800C4DCC
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C4DB4: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800C4DCC;
    }
    // 0x800C4DB4: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800C4DB8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C4DBC: lw          $t6, -0x5818($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5818);
    // 0x800C4DC0: nop

    // 0x800C4DC4: lbu         $a2, 0x1D($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X1D);
    // 0x800C4DC8: nop

L_800C4DCC:
    // 0x800C4DCC: lw          $t8, -0x581C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X581C);
    // 0x800C4DD0: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x800C4DD4: sll         $t7, $a2, 10
    ctx->r15 = S32(ctx->r6 << 10);
    // 0x800C4DD8: beq         $t9, $zero, L_800C4ED0
    if (ctx->r25 == 0) {
        // 0x800C4DDC: addu        $v0, $t7, $t8
        ctx->r2 = ADD32(ctx->r15, ctx->r24);
            goto L_800C4ED0;
    }
    // 0x800C4DDC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800C4DE0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C4DE4: lw          $t2, -0x5810($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5810);
    // 0x800C4DE8: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x800C4DEC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C4DF0: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800C4DF4: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x800C4DF8: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
L_800C4DFC:
    // 0x800C4DFC: slti        $at, $a2, 0x21
    ctx->r1 = SIGNED(ctx->r6) < 0X21 ? 1 : 0;
    // 0x800C4E00: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800C4E04: bne         $at, $zero, L_800C4E18
    if (ctx->r1 != 0) {
        // 0x800C4E08: or          $t1, $a2, $zero
        ctx->r9 = ctx->r6 | 0;
            goto L_800C4E18;
    }
    // 0x800C4E08: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
    // 0x800C4E0C: slti        $at, $a2, 0x80
    ctx->r1 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // 0x800C4E10: bne         $at, $zero, L_800C4E70
    if (ctx->r1 != 0) {
        // 0x800C4E14: addiu       $a2, $t1, -0x20
        ctx->r6 = ADD32(ctx->r9, -0X20);
            goto L_800C4E70;
    }
    // 0x800C4E14: addiu       $a2, $t1, -0x20
    ctx->r6 = ADD32(ctx->r9, -0X20);
L_800C4E18:
    // 0x800C4E18: bne         $t3, $t1, L_800C4E64
    if (ctx->r11 != ctx->r9) {
        // 0x800C4E1C: nop
    
            goto L_800C4E64;
    }
    // 0x800C4E1C: nop

    // 0x800C4E20: lhu         $a2, 0x26($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X26);
    // 0x800C4E24: nop

    // 0x800C4E28: div         $zero, $v1, $a2
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r6)));
    // 0x800C4E2C: addu        $t5, $v1, $a2
    ctx->r13 = ADD32(ctx->r3, ctx->r6);
    // 0x800C4E30: bne         $a2, $zero, L_800C4E3C
    if (ctx->r6 != 0) {
        // 0x800C4E34: nop
    
            goto L_800C4E3C;
    }
    // 0x800C4E34: nop

    // 0x800C4E38: break       7
    do_break(2148290104);
L_800C4E3C:
    // 0x800C4E3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C4E40: bne         $a2, $at, L_800C4E54
    if (ctx->r6 != ctx->r1) {
        // 0x800C4E44: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C4E54;
    }
    // 0x800C4E44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C4E48: bne         $v1, $at, L_800C4E54
    if (ctx->r3 != ctx->r1) {
        // 0x800C4E4C: nop
    
            goto L_800C4E54;
    }
    // 0x800C4E4C: nop

    // 0x800C4E50: break       6
    do_break(2148290128);
L_800C4E54:
    // 0x800C4E54: mfhi        $t6
    ctx->r14 = hi;
    // 0x800C4E58: subu        $v1, $t5, $t6
    ctx->r3 = SUB32(ctx->r13, ctx->r14);
    // 0x800C4E5C: b           L_800C4EAC
    // 0x800C4E60: nop

        goto L_800C4EAC;
    // 0x800C4E60: nop

L_800C4E64:
    // 0x800C4E64: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x800C4E68: b           L_800C4EAC
    // 0x800C4E6C: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
        goto L_800C4EAC;
    // 0x800C4E6C: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
L_800C4E70:
    // 0x800C4E70: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x800C4E74: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800C4E78: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800C4E7C: lbu         $t5, 0x100($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X100);
    // 0x800C4E80: nop

    // 0x800C4E84: beq         $t4, $t5, L_800C4EAC
    if (ctx->r12 == ctx->r13) {
        // 0x800C4E88: nop
    
            goto L_800C4EAC;
    }
    // 0x800C4E88: nop

    // 0x800C4E8C: lhu         $a2, 0x20($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X20);
    // 0x800C4E90: nop

    // 0x800C4E94: bne         $a2, $zero, L_800C4EA8
    if (ctx->r6 != 0) {
        // 0x800C4E98: nop
    
            goto L_800C4EA8;
    }
    // 0x800C4E98: nop

    // 0x800C4E9C: lbu         $t6, 0x101($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X101);
    // 0x800C4EA0: b           L_800C4EAC
    // 0x800C4EA4: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
        goto L_800C4EAC;
    // 0x800C4EA4: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
L_800C4EA8:
    // 0x800C4EA8: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
L_800C4EAC:
    // 0x800C4EAC: beq         $t2, $zero, L_800C4EC0
    if (ctx->r10 == 0) {
        // 0x800C4EB0: nop
    
            goto L_800C4EC0;
    }
    // 0x800C4EB0: nop

    // 0x800C4EB4: beq         $v1, $a0, L_800C4EC0
    if (ctx->r3 == ctx->r4) {
        // 0x800C4EB8: nop
    
            goto L_800C4EC0;
    }
    // 0x800C4EB8: nop

    // 0x800C4EBC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_800C4EC0:
    // 0x800C4EC0: lbu         $t0, 0x1($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X1);
    // 0x800C4EC4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C4EC8: bne         $t0, $zero, L_800C4DFC
    if (ctx->r8 != 0) {
        // 0x800C4ECC: andi        $a2, $t0, 0xFF
        ctx->r6 = ctx->r8 & 0XFF;
            goto L_800C4DFC;
    }
    // 0x800C4ECC: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
L_800C4ED0:
    // 0x800C4ED0: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // 0x800C4ED4: jr          $ra
    // 0x800C4ED8: nop

    return;
    // 0x800C4ED8: nop

;}
RECOMP_FUNC void obj_loop_ainode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D02C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003D030: jr          $ra
    // 0x8003D034: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003D034: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_disable_emitter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF6E4: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x800AF6E8: sll         $t7, $a1, 5
    ctx->r15 = S32(ctx->r5 << 5);
    // 0x800AF6EC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800AF6F0: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x800AF6F4: nop

    // 0x800AF6F8: andi        $t9, $t8, 0x7FFF
    ctx->r25 = ctx->r24 & 0X7FFF;
    // 0x800AF6FC: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x800AF700: lh          $t0, 0x1A($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X1A);
    // 0x800AF704: nop

    // 0x800AF708: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800AF70C: jr          $ra
    // 0x800AF710: sh          $t1, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r9;
    return;
    // 0x800AF710: sh          $t1, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8002EEEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EEEC: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x8002EEF0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002EEF4: lw          $v0, -0x2F3C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2F3C);
    // 0x8002EEF8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002EEFC: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x8002EF00: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x8002EF04: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8002EF08: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8002EF0C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8002EF10: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8002EF14: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8002EF18: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8002EF1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002EF20: lwc1        $f0, -0x2F24($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2F24);
    // 0x8002EF24: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002EF28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002EF2C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002EF30: lwc1        $f2, -0x2F20($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2F20);
    // 0x8002EF34: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x8002EF38: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EF3C: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8002EF40: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8002EF44: addiu       $s7, $s7, -0x2F48
    ctx->r23 = ADD32(ctx->r23, -0X2F48);
    // 0x8002EF48: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x8002EF4C: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002EF50: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8002EF54: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8002EF58: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002EF5C: swc1        $f18, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f18.u32l;
    // 0x8002EF60: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EF64: addiu       $t8, $t8, -0x3748
    ctx->r24 = ADD32(ctx->r24, -0X3748);
    // 0x8002EF68: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8002EF6C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002EF70: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x8002EF74: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002EF78: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8002EF7C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8002EF80: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x8002EF84: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    // 0x8002EF88: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EF8C: lw          $a3, 0x98($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X98);
    // 0x8002EF90: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8002EF94: addiu       $a1, $a1, -0x3C48
    ctx->r5 = ADD32(ctx->r5, -0X3C48);
    // 0x8002EF98: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x8002EF9C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002EFA0: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8002EFA4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002EFA8: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8002EFAC: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
    // 0x8002EFB0: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EFB4: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002EFB8: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8002EFBC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8002EFC0: swc1        $f10, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f10.u32l;
    // 0x8002EFC4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8002EFC8: jal         0x800BDC80
    // 0x8002EFCC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800BDC80(rdram, ctx);
        goto after_0;
    // 0x8002EFCC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8002EFD0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8002EFD4: blez        $v0, L_8002F274
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002EFD8: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8002F274;
    }
    // 0x8002EFD8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8002EFDC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8002EFE0: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8002EFE4: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002EFE8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002EFEC: addiu       $s1, $s1, -0x2F44
    ctx->r17 = ADD32(ctx->r17, -0X2F44);
    // 0x8002EFF0: addiu       $s3, $s3, -0x4EE0
    ctx->r19 = ADD32(ctx->r19, -0X4EE0);
    // 0x8002EFF4: addiu       $s5, $s5, -0x3DD0
    ctx->r21 = ADD32(ctx->r21, -0X3DD0);
    // 0x8002EFF8: addiu       $s0, $s0, -0x3C48
    ctx->r16 = ADD32(ctx->r16, -0X3C48);
    // 0x8002EFFC: addiu       $s2, $sp, 0xD8
    ctx->r18 = ADD32(ctx->r29, 0XD8);
    // 0x8002F000: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8002F004:
    // 0x8002F004: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x8002F008: lh          $v1, 0x8($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X8);
    // 0x8002F00C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8002F010: lh          $a2, -0x2F32($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X2F32);
    // 0x8002F014: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002F018: beq         $at, $zero, L_8002F028
    if (ctx->r1 == 0) {
        // 0x8002F01C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8002F028;
    }
    // 0x8002F01C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002F020: b           L_8002F038
    // 0x8002F024: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_8002F038;
    // 0x8002F024: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_8002F028:
    // 0x8002F028: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002F02C: beq         $at, $zero, L_8002F038
    if (ctx->r1 == 0) {
        // 0x8002F030: nop
    
            goto L_8002F038;
    }
    // 0x8002F030: nop

    // 0x8002F034: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8002F038:
    // 0x8002F038: lh          $v0, 0xE($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE);
    // 0x8002F03C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002F040: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002F044: beq         $at, $zero, L_8002F058
    if (ctx->r1 == 0) {
        // 0x8002F048: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8002F058;
    }
    // 0x8002F048: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002F04C: b           L_8002F064
    // 0x8002F050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8002F064;
    // 0x8002F050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002F054: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_8002F058:
    // 0x8002F058: beq         $at, $zero, L_8002F068
    if (ctx->r1 == 0) {
        // 0x8002F05C: slt         $at, $a2, $a0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8002F068;
    }
    // 0x8002F05C: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002F060: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8002F064:
    // 0x8002F064: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
L_8002F068:
    // 0x8002F068: bne         $at, $zero, L_8002F264
    if (ctx->r1 != 0) {
        // 0x8002F06C: nop
    
            goto L_8002F264;
    }
    // 0x8002F06C: nop

    // 0x8002F070: lh          $t9, -0x2F34($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X2F34);
    // 0x8002F074: addiu       $v0, $sp, 0xA8
    ctx->r2 = ADD32(ctx->r29, 0XA8);
    // 0x8002F078: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002F07C: bne         $at, $zero, L_8002F264
    if (ctx->r1 != 0) {
        // 0x8002F080: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_8002F264;
    }
    // 0x8002F080: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002F084: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8002F088: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x8002F08C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8002F090: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8002F094: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002F098: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x8002F09C: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x8002F0A0: mtc1        $t8, $f14
    ctx->f14.u32l = ctx->r24;
    // 0x8002F0A4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002F0A8: mtc1        $t9, $f12
    ctx->f12.u32l = ctx->r25;
    // 0x8002F0AC: lh          $t6, 0xC($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XC);
    // 0x8002F0B0: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x8002F0B4: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8002F0B8: lh          $t7, 0x10($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X10);
    // 0x8002F0BC: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    // 0x8002F0C0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8002F0C4: swc1        $f18, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f18.u32l;
    // 0x8002F0C8: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002F0CC: swc1        $f16, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f16.u32l;
    // 0x8002F0D0: swc1        $f14, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f14.u32l;
    // 0x8002F0D4: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002F0D8: swc1        $f12, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f12.u32l;
    // 0x8002F0DC: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x8002F0E0: swc1        $f8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f8.u32l;
L_8002F0E4:
    // 0x8002F0E4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002F0E8: bne         $v0, $s2, L_8002F0E4
    if (ctx->r2 != ctx->r18) {
        // 0x8002F0EC: sh          $t0, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r8;
            goto L_8002F0E4;
    }
    // 0x8002F0EC: sh          $t0, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r8;
    // 0x8002F0F0: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x8002F0F4: sll         $t6, $s4, 4
    ctx->r14 = S32(ctx->r20 << 4);
    // 0x8002F0F8: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8002F0FC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002F100: addiu       $t8, $t8, -0x3748
    ctx->r24 = ADD32(ctx->r24, -0X3748);
    // 0x8002F104: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8002F108: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8002F10C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8002F110: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x8002F114: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8002F118: jal         0x8002FF6C
    // 0x8002F11C: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    func_8002FF6C(rdram, ctx);
        goto after_1;
    // 0x8002F11C: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    after_1:
    // 0x8002F120: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002F124: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8002F128: addiu       $t5, $t5, -0x4EE8
    ctx->r13 = ADD32(ctx->r13, -0X4EE8);
    // 0x8002F12C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8002F130: bne         $at, $zero, L_8002F264
    if (ctx->r1 != 0) {
        // 0x8002F134: or          $ra, $v0, $zero
        ctx->r31 = ctx->r2 | 0;
            goto L_8002F264;
    }
    // 0x8002F134: or          $ra, $v0, $zero
    ctx->r31 = ctx->r2 | 0;
    // 0x8002F138: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x8002F13C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002F140: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8002F144: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x8002F148: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002F14C: addiu       $t7, $t7, -0x3DC8
    ctx->r15 = ADD32(ctx->r15, -0X3DC8);
    // 0x8002F150: addu        $t3, $t6, $t7
    ctx->r11 = ADD32(ctx->r14, ctx->r15);
    // 0x8002F154: sb          $zero, 0x1($t3)
    MEM_B(0X1, ctx->r11) = 0;
    // 0x8002F158: blez        $v0, L_8002F258
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002F15C: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_8002F258;
    }
    // 0x8002F15C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8002F160: addiu       $a3, $sp, 0xA8
    ctx->r7 = ADD32(ctx->r29, 0XA8);
L_8002F164:
    // 0x8002F164: lh          $v1, 0xE($a3)
    ctx->r3 = MEM_H(ctx->r7, 0XE);
    // 0x8002F168: addu        $t7, $t3, $t1
    ctx->r15 = ADD32(ctx->r11, ctx->r9);
    // 0x8002F16C: bgez        $v1, L_8002F238
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002F170: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8002F238;
    }
    // 0x8002F170: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002F174: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8002F178: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x8002F17C: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    // 0x8002F180: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002F184: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002F188: addiu       $t6, $t6, -0x3DC8
    ctx->r14 = ADD32(ctx->r14, -0X3DC8);
    // 0x8002F18C: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x8002F190: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8002F194: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002F198: blez        $a2, L_8002F1FC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8002F19C: addu        $t2, $t9, $t6
        ctx->r10 = ADD32(ctx->r25, ctx->r14);
            goto L_8002F1FC;
    }
    // 0x8002F19C: addu        $t2, $t9, $t6
    ctx->r10 = ADD32(ctx->r25, ctx->r14);
    // 0x8002F1A0: sll         $t7, $zero, 4
    ctx->r15 = S32(0 << 4);
    // 0x8002F1A4: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002F1A8: addu        $a0, $s3, $t7
    ctx->r4 = ADD32(ctx->r19, ctx->r15);
L_8002F1AC:
    // 0x8002F1AC: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002F1B0: nop

    // 0x8002F1B4: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x8002F1B8: nop

    // 0x8002F1BC: bc1f        L_8002F1E4
    if (!c1cs) {
        // 0x8002F1C0: nop
    
            goto L_8002F1E4;
    }
    // 0x8002F1C0: nop

    // 0x8002F1C4: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8002F1C8: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002F1CC: nop

    // 0x8002F1D0: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8002F1D4: nop

    // 0x8002F1D8: bc1f        L_8002F1E4
    if (!c1cs) {
        // 0x8002F1DC: nop
    
            goto L_8002F1E4;
    }
    // 0x8002F1DC: nop

    // 0x8002F1E0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8002F1E4:
    // 0x8002F1E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002F1E8: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002F1EC: beq         $at, $zero, L_8002F1FC
    if (ctx->r1 == 0) {
        // 0x8002F1F0: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8002F1FC;
    }
    // 0x8002F1F0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8002F1F4: beq         $a1, $t0, L_8002F1AC
    if (ctx->r5 == ctx->r8) {
        // 0x8002F1F8: nop
    
            goto L_8002F1AC;
    }
    // 0x8002F1F8: nop

L_8002F1FC:
    // 0x8002F1FC: bne         $a1, $t0, L_8002F230
    if (ctx->r5 != ctx->r8) {
        // 0x8002F200: sll         $t8, $a2, 4
        ctx->r24 = S32(ctx->r6 << 4);
            goto L_8002F230;
    }
    // 0x8002F200: sll         $t8, $a2, 4
    ctx->r24 = S32(ctx->r6 << 4);
    // 0x8002F204: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002F208: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8002F20C: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002F210: addu        $v1, $s3, $t8
    ctx->r3 = ADD32(ctx->r19, ctx->r24);
    // 0x8002F214: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x8002F218: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8002F21C: sb          $a2, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r6;
    // 0x8002F220: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x8002F224: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x8002F228: b           L_8002F24C
    // 0x8002F22C: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
        goto L_8002F24C;
    // 0x8002F22C: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
L_8002F230:
    // 0x8002F230: b           L_8002F24C
    // 0x8002F234: sb          $a1, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r5;
        goto L_8002F24C;
    // 0x8002F234: sb          $a1, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r5;
L_8002F238:
    // 0x8002F238: sb          $v1, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r3;
    // 0x8002F23C: lbu         $t8, 0x1($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X1);
    // 0x8002F240: sllv        $t6, $t9, $t1
    ctx->r14 = S32(ctx->r25 << (ctx->r9 & 31));
    // 0x8002F244: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8002F248: sb          $t7, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r15;
L_8002F24C:
    // 0x8002F24C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8002F250: bne         $t1, $ra, L_8002F164
    if (ctx->r9 != ctx->r31) {
        // 0x8002F254: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8002F164;
    }
    // 0x8002F254: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_8002F258:
    // 0x8002F258: addiu       $t9, $t4, 0x1
    ctx->r25 = ADD32(ctx->r12, 0X1);
    // 0x8002F25C: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
    // 0x8002F260: sb          $v0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r2;
L_8002F264:
    // 0x8002F264: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8002F268: slt         $at, $s4, $s6
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8002F26C: bne         $at, $zero, L_8002F004
    if (ctx->r1 != 0) {
        // 0x8002F270: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_8002F004;
    }
    // 0x8002F270: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_8002F274:
    // 0x8002F274: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x8002F278: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002F27C: addu        $t6, $t8, $s6
    ctx->r14 = ADD32(ctx->r24, ctx->r22);
    // 0x8002F280: sw          $t6, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r14;
    // 0x8002F284: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x8002F288: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x8002F28C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8002F290: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8002F294: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8002F298: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8002F29C: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8002F2A0: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8002F2A4: jr          $ra
    // 0x8002F2A8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x8002F2A8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void func_800535C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800535C4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800535C8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800535CC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800535D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800535D4: lh          $t6, 0x1A0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A0);
    // 0x800535D8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800535DC: addiu       $a1, $a1, -0x2AF0
    ctx->r5 = ADD32(ctx->r5, -0X2AF0);
    // 0x800535E0: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800535E4: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x800535E8: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x800535EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800535F0: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x800535F4: sh          $t9, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r25;
    // 0x800535F8: lh          $t0, 0x1A4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X1A4);
    // 0x800535FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80053600: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80053604: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x80053608: sh          $t1, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r9;
    // 0x8005360C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80053610: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x80053614: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x80053618: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x8005361C: jal         0x8006FE74
    // 0x80053620: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_0;
    // 0x80053620: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    after_0:
    // 0x80053624: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80053628: addiu       $t2, $s0, 0xA0
    ctx->r10 = ADD32(ctx->r16, 0XA0);
    // 0x8005362C: addiu       $t3, $s0, 0xA4
    ctx->r11 = ADD32(ctx->r16, 0XA4);
    // 0x80053630: addiu       $t4, $s0, 0x9C
    ctx->r12 = ADD32(ctx->r16, 0X9C);
    // 0x80053634: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80053638: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005363C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80053640: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80053644: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80053648: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8005364C: jal         0x8006F64C
    // 0x80053650: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x80053650: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    after_1:
    // 0x80053654: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80053658: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8005365C: jr          $ra
    // 0x80053660: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80053660: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void music_channel_fade_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000126C: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x80001270: slti        $at, $a3, 0x10
    ctx->r1 = SIGNED(ctx->r7) < 0X10 ? 1 : 0;
    // 0x80001274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001278: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000127C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001280: beq         $at, $zero, L_80001298
    if (ctx->r1 == 0) {
        // 0x80001284: andi        $a2, $a1, 0xFF
        ctx->r6 = ctx->r5 & 0XFF;
            goto L_80001298;
    }
    // 0x80001284: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x80001288: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000128C: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x80001290: jal         0x80063BA0
    // 0x80001294: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    alCSPSetFadeIn(rdram, ctx);
        goto after_0;
    // 0x80001294: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    after_0:
L_80001298:
    // 0x80001298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000129C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800012A0: jr          $ra
    // 0x800012A4: nop

    return;
    // 0x800012A4: nop

;}
RECOMP_FUNC void rumble_kill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072708: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8007270C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80072710: jr          $ra
    // 0x80072714: sw          $t6, -0x1B74($at)
    MEM_W(-0X1B74, ctx->r1) = ctx->r14;
    return;
    // 0x80072714: sw          $t6, -0x1B74($at)
    MEM_W(-0X1B74, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void cubic_spline_interpolation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002263C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80022640: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80022644: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80022648: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002264C: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80022650: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x80022654: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x80022658: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002265C: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80022660: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80022664: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80022668: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002266C: cvt.d.s     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f12.d = CVT_D_S(ctx->f6.fl);
    // 0x80022670: mul.d       $f14, $f8, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f14.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x80022674: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80022678: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8002267C: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x80022680: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80022684: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80022688: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002268C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80022690: mul.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x80022694: lui         $at, 0xBFF8
    ctx->r1 = S32(0XBFF8 << 16);
    // 0x80022698: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8002269C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800226A0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800226A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800226A8: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800226AC: add.d       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f14.d + ctx->f8.d;
    // 0x800226B0: lui         $at, 0xC004
    ctx->r1 = S32(0XC004 << 16);
    // 0x800226B4: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800226B8: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x800226BC: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x800226C0: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x800226C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800226C8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800226CC: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x800226D0: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x800226D4: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800226D8: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x800226DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800226E0: add.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f12.d + ctx->f8.d;
    // 0x800226E4: add.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f10.d + ctx->f4.d;
    // 0x800226E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800226EC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800226F0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800226F4: mul.d       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x800226F8: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    // 0x800226FC: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x80022700: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80022704: mul.d       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x80022708: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8002270C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80022710: add.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f8.d + ctx->f14.d;
    // 0x80022714: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80022718: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002271C: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    // 0x80022720: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80022724: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80022728: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002272C: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x80022730: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80022734: nop

    // 0x80022738: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8002273C: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80022740: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80022744: nop

    // 0x80022748: mul.s       $f10, $f12, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x8002274C: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80022750: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x80022754: add.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80022758: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x8002275C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80022760: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80022764: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80022768: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8002276C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80022770: add.s       $f2, $f10, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80022774: jr          $ra
    // 0x80022778: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80022778: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void ainode_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D214: bltz        $a0, L_8001D23C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001D218: slti        $at, $a0, 0x80
        ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
            goto L_8001D23C;
    }
    // 0x8001D218: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x8001D21C: beq         $at, $zero, L_8001D23C
    if (ctx->r1 == 0) {
        // 0x8001D220: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001D23C;
    }
    // 0x8001D220: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001D224: lw          $t6, -0x50FC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X50FC);
    // 0x8001D228: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8001D22C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001D230: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001D234: jr          $ra
    // 0x8001D238: nop

    return;
    // 0x8001D238: nop

L_8001D23C:
    // 0x8001D23C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001D240: jr          $ra
    // 0x8001D244: nop

    return;
    // 0x8001D244: nop

;}
RECOMP_FUNC void obj_bridge_pos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E36C: lui         $at, 0xC6FA
    ctx->r1 = S32(0XC6FA << 16);
    // 0x8001E370: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001E374: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8001E378: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8001E37C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8001E380: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8001E384: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E388: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x8001E38C: lw          $v1, -0x51A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X51A4);
    // 0x8001E390: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001E394: blez        $v1, L_8001E434
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E398: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001E434;
    }
    // 0x8001E398: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E39C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001E3A0: addiu       $t1, $t1, -0x51A8
    ctx->r9 = ADD32(ctx->r9, -0X51A8);
    // 0x8001E3A4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001E3A8: addiu       $t2, $zero, 0x27
    ctx->r10 = ADD32(0, 0X27);
L_8001E3AC:
    // 0x8001E3AC: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8001E3B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E3B4: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x8001E3B8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8001E3BC: nop

    // 0x8001E3C0: beq         $a0, $zero, L_8001E42C
    if (ctx->r4 == 0) {
        // 0x8001E3C4: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E42C;
    }
    // 0x8001E3C4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E3C8: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x8001E3CC: nop

    // 0x8001E3D0: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8001E3D4: bne         $t9, $zero, L_8001E42C
    if (ctx->r25 != 0) {
        // 0x8001E3D8: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E42C;
    }
    // 0x8001E3D8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E3DC: lh          $t3, 0x48($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X48);
    // 0x8001E3E0: nop

    // 0x8001E3E4: bne         $t2, $t3, L_8001E42C
    if (ctx->r10 != ctx->r11) {
        // 0x8001E3E8: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E42C;
    }
    // 0x8001E3E8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E3EC: lw          $t4, 0x78($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X78);
    // 0x8001E3F0: nop

    // 0x8001E3F4: bne         $s0, $t4, L_8001E42C
    if (ctx->r16 != ctx->r12) {
        // 0x8001E3F8: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E42C;
    }
    // 0x8001E3F8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E3FC: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001E400: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E404: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8001E408: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8001E40C: nop

    // 0x8001E410: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x8001E414: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8001E418: nop

    // 0x8001E41C: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x8001E420: lw          $v1, -0x51A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X51A4);
    // 0x8001E424: nop

    // 0x8001E428: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E42C:
    // 0x8001E42C: bne         $at, $zero, L_8001E3AC
    if (ctx->r1 != 0) {
        // 0x8001E430: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8001E3AC;
    }
    // 0x8001E430: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_8001E434:
    // 0x8001E434: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8001E438: jr          $ra
    // 0x8001E43C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8001E43C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void optionscreen_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800841B8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800841BC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800841C0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800841C4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800841C8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800841CC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800841D0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800841D4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800841D8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800841DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800841E0: jal         0x800C42EC
    // 0x800841E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_0;
    // 0x800841E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x800841E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800841EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800841F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800841F4: jal         0x800C43CC
    // 0x800841F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_1;
    // 0x800841F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800841FC: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x80084200: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80084204: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084208: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008420C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084210: jal         0x800C4384
    // 0x80084214: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x80084214: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x80084218: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008421C: addiu       $s0, $s0, -0xB60
    ctx->r16 = ADD32(ctx->r16, -0XB60);
    // 0x80084220: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80084224: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80084228: addiu       $s6, $s6, 0x63A0
    ctx->r22 = ADD32(ctx->r22, 0X63A0);
    // 0x8008422C: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80084230: lw          $a3, 0x90($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X90);
    // 0x80084234: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80084238: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8008423C: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x80084240: jal         0x800C4440
    // 0x80084244: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_3;
    // 0x80084244: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_3:
    // 0x80084248: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008424C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80084250: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80084254: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80084258: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008425C: jal         0x800C4384
    // 0x80084260: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x80084260: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80084264: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80084268: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8008426C: lw          $a3, 0x90($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X90);
    // 0x80084270: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80084274: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80084278: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008427C: jal         0x800C4440
    // 0x80084280: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x80084280: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_5:
    // 0x80084284: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80084288: addiu       $s2, $zero, 0x4C
    ctx->r18 = ADD32(0, 0X4C);
    // 0x8008428C: jal         0x800C42EC
    // 0x80084290: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_6;
    // 0x80084290: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80084294: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80084298: lw          $t2, -0x5F0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5F0);
    // 0x8008429C: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x800842A0: beq         $t2, $zero, L_80084334
    if (ctx->r10 == 0) {
        // 0x800842A4: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_80084334;
    }
    // 0x800842A4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800842A8: addiu       $t4, $t4, -0x5F0
    ctx->r12 = ADD32(ctx->r12, -0X5F0);
    // 0x800842AC: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800842B0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800842B4: addiu       $s3, $s3, -0xBA0
    ctx->r19 = ADD32(ctx->r19, -0XBA0);
    // 0x800842B8: addiu       $s4, $s4, 0x63BC
    ctx->r20 = ADD32(ctx->r20, 0X63BC);
    // 0x800842BC: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
    // 0x800842C0: addiu       $s5, $zero, 0x1FF
    ctx->r21 = ADD32(0, 0X1FF);
L_800842C4:
    // 0x800842C4: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800842C8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800842CC: bne         $s1, $t5, L_800842F0
    if (ctx->r17 != ctx->r13) {
        // 0x800842D0: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_800842F0;
    }
    // 0x800842D0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800842D4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800842D8: nop

    // 0x800842DC: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x800842E0: bne         $at, $zero, L_800842F4
    if (ctx->r1 != 0) {
        // 0x800842E4: sll         $a3, $v0, 3
        ctx->r7 = S32(ctx->r2 << 3);
            goto L_800842F4;
    }
    // 0x800842E4: sll         $a3, $v0, 3
    ctx->r7 = S32(ctx->r2 << 3);
    // 0x800842E8: b           L_800842F4
    // 0x800842EC: subu        $a3, $s5, $a3
    ctx->r7 = SUB32(ctx->r21, ctx->r7);
        goto L_800842F4;
    // 0x800842EC: subu        $a3, $s5, $a3
    ctx->r7 = SUB32(ctx->r21, ctx->r7);
L_800842F0:
    // 0x800842F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800842F4:
    // 0x800842F4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800842F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800842FC: jal         0x800C4384
    // 0x80084300: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x80084300: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_7:
    // 0x80084304: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80084308: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8008430C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80084310: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80084314: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80084318: jal         0x800C4440
    // 0x8008431C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_8;
    // 0x8008431C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_8:
    // 0x80084320: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80084324: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80084328: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8008432C: bne         $t8, $zero, L_800842C4
    if (ctx->r24 != 0) {
        // 0x80084330: addiu       $s2, $s2, 0x1C
        ctx->r18 = ADD32(ctx->r18, 0X1C);
            goto L_800842C4;
    }
    // 0x80084330: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
L_80084334:
    // 0x80084334: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80084338: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008433C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80084340: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80084344: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80084348: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8008434C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80084350: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80084354: jr          $ra
    // 0x80084358: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80084358: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void divider_clear_coverage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077268: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007726C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077270: jal         0x8007A520
    // 0x80077274: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80077274: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80077278: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8007727C: srl         $a1, $v0, 16
    ctx->r5 = S32(U32(ctx->r2) >> 16);
    // 0x80077280: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80077284: srl         $t6, $a1, 7
    ctx->r14 = S32(U32(ctx->r5) >> 7);
    // 0x80077288: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8007728C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80077290: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x80077294: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80077298: ori         $t7, $t7, 0x1402
    ctx->r15 = ctx->r15 | 0X1402;
    // 0x8007729C: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // 0x800772A0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800772A4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800772A8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800772AC: srl         $t8, $a2, 8
    ctx->r24 = S32(U32(ctx->r6) >> 8);
    // 0x800772B0: sll         $ra, $t8, 2
    ctx->r31 = S32(ctx->r24 << 2);
    // 0x800772B4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800772B8: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x800772BC: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x800772C0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800772C4: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800772C8: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x800772CC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800772D0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800772D4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800772D8: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x800772DC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800772E0: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x800772E4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800772E8: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x800772EC: ori         $t9, $t9, 0x4240
    ctx->r25 = ctx->r25 | 0X4240;
    // 0x800772F0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800772F4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800772F8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800772FC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80077300: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80077304: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80077308: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007730C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80077310: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80077314: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80077318: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007731C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80077320: jal         0x80066210
    // 0x80077324: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    cam_get_viewport_layout(rdram, ctx);
        goto after_1;
    // 0x80077324: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x80077328: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8007732C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80077330: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80077334: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80077338: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007733C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80077340: beq         $v0, $at, L_80077368
    if (ctx->r2 == ctx->r1) {
        // 0x80077344: lui         $t0, 0xF600
        ctx->r8 = S32(0XF600 << 16);
            goto L_80077368;
    }
    // 0x80077344: lui         $t0, 0xF600
    ctx->r8 = S32(0XF600 << 16);
    // 0x80077348: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007734C: beq         $v0, $at, L_800773B0
    if (ctx->r2 == ctx->r1) {
        // 0x80077350: lui         $t0, 0xF600
        ctx->r8 = S32(0XF600 << 16);
            goto L_800773B0;
    }
    // 0x80077350: lui         $t0, 0xF600
    ctx->r8 = S32(0XF600 << 16);
    // 0x80077354: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80077358: beq         $v0, $at, L_800773B0
    if (ctx->r2 == ctx->r1) {
        // 0x8007735C: nop
    
            goto L_800773B0;
    }
    // 0x8007735C: nop

    // 0x80077360: b           L_8007743C
    // 0x80077364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8007743C;
    // 0x80077364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80077368:
    // 0x80077368: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007736C: srl         $t9, $t4, 1
    ctx->r25 = S32(U32(ctx->r12) >> 1);
    // 0x80077370: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80077374: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80077378: srl         $t6, $t2, 1
    ctx->r14 = S32(U32(ctx->r10) >> 1);
    // 0x8007737C: andi        $t7, $t5, 0x3FF
    ctx->r15 = ctx->r13 & 0X3FF;
    // 0x80077380: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x80077384: subu        $v0, $t9, $t6
    ctx->r2 = SUB32(ctx->r25, ctx->r14);
    // 0x80077388: addu        $t6, $v0, $t2
    ctx->r14 = ADD32(ctx->r2, ctx->r10);
    // 0x8007738C: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x80077390: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x80077394: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80077398: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8007739C: andi        $t7, $v0, 0x3FF
    ctx->r15 = ctx->r2 & 0X3FF;
    // 0x800773A0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800773A4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800773A8: b           L_80077438
    // 0x800773AC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_80077438;
    // 0x800773AC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800773B0:
    // 0x800773B0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800773B4: srl         $t6, $t4, 1
    ctx->r14 = S32(U32(ctx->r12) >> 1);
    // 0x800773B8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800773BC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800773C0: srl         $t7, $t2, 1
    ctx->r15 = S32(U32(ctx->r10) >> 1);
    // 0x800773C4: andi        $t9, $t5, 0x3FF
    ctx->r25 = ctx->r13 & 0X3FF;
    // 0x800773C8: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x800773CC: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x800773D0: addu        $t7, $v0, $t2
    ctx->r15 = ADD32(ctx->r2, ctx->r10);
    // 0x800773D4: andi        $t9, $t7, 0x3FF
    ctx->r25 = ctx->r15 & 0X3FF;
    // 0x800773D8: or          $t6, $t8, $t0
    ctx->r14 = ctx->r24 | ctx->r8;
    // 0x800773DC: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800773E0: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800773E4: andi        $t9, $v0, 0x3FF
    ctx->r25 = ctx->r2 & 0X3FF;
    // 0x800773E8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800773EC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800773F0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800773F4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800773F8: srl         $t7, $t5, 1
    ctx->r15 = S32(U32(ctx->r13) >> 1);
    // 0x800773FC: srl         $t9, $ra, 1
    ctx->r25 = S32(U32(ctx->r31) >> 1);
    // 0x80077400: subu        $a2, $t7, $t9
    ctx->r6 = SUB32(ctx->r15, ctx->r25);
    // 0x80077404: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80077408: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007740C: addu        $t6, $a2, $ra
    ctx->r14 = ADD32(ctx->r6, ctx->r31);
    // 0x80077410: andi        $t8, $t6, 0x3FF
    ctx->r24 = ctx->r14 & 0X3FF;
    // 0x80077414: sll         $t7, $t8, 14
    ctx->r15 = S32(ctx->r24 << 14);
    // 0x80077418: andi        $t6, $t4, 0x3FF
    ctx->r14 = ctx->r12 & 0X3FF;
    // 0x8007741C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80077420: or          $t9, $t7, $t0
    ctx->r25 = ctx->r15 | ctx->r8;
    // 0x80077424: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80077428: andi        $t6, $a2, 0x3FF
    ctx->r14 = ctx->r6 & 0X3FF;
    // 0x8007742C: sll         $t9, $t6, 14
    ctx->r25 = S32(ctx->r14 << 14);
    // 0x80077430: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80077434: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_80077438:
    // 0x80077438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007743C:
    // 0x8007743C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80077440: jr          $ra
    // 0x80077444: nop

    return;
    // 0x80077444: nop

;}
RECOMP_FUNC void should_taj_teleport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052188: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005218C: addiu       $v1, $v1, -0x2A7E
    ctx->r3 = ADD32(ctx->r3, -0X2A7E);
    // 0x80052190: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x80052194: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80052198: bne         $t6, $at, L_800521AC
    if (ctx->r14 != ctx->r1) {
        // 0x8005219C: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800521AC;
    }
    // 0x8005219C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800521A0: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x800521A4: jr          $ra
    // 0x800521A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800521A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800521AC:
    // 0x800521AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800521B0: jr          $ra
    // 0x800521B4: nop

    return;
    // 0x800521B4: nop

;}
RECOMP_FUNC void obj_loop_animcar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800387CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800387D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800387D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800387D8: lw          $v0, 0x78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X78);
    // 0x800387DC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800387E0: beq         $v0, $zero, L_800387FC
    if (ctx->r2 == 0) {
        // 0x800387E4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800387FC;
    }
    // 0x800387E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800387E8: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x800387EC: jal         0x8001BAC8
    // 0x800387F0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x800387F0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x800387F4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800387F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800387FC:
    // 0x800387FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80038800: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80038804: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80038808: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8003880C: jal         0x8001F460
    // 0x80038810: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8001F460(rdram, ctx);
        goto after_1;
    // 0x80038810: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80038814: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80038818: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8003881C: lh          $t6, 0x6($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X6);
    // 0x80038820: sw          $v0, 0x7C($a3)
    MEM_W(0X7C, ctx->r7) = ctx->r2;
    // 0x80038824: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x80038828: bne         $v0, $zero, L_80038844
    if (ctx->r2 != 0) {
        // 0x8003882C: sh          $t7, 0x6($a3)
        MEM_H(0X6, ctx->r7) = ctx->r15;
            goto L_80038844;
    }
    // 0x8003882C: sh          $t7, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r15;
    // 0x80038830: beq         $v1, $zero, L_80038848
    if (ctx->r3 == 0) {
        // 0x80038834: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038848;
    }
    // 0x80038834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038838: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x8003883C: nop

    // 0x80038840: sw          $a3, 0x148($v0)
    MEM_W(0X148, ctx->r2) = ctx->r7;
L_80038844:
    // 0x80038844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80038848:
    // 0x80038848: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003884C: jr          $ra
    // 0x80038850: nop

    return;
    // 0x80038850: nop

;}
RECOMP_FUNC void hud_course_arrows(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0EB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A0EB8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A0EBC: lbu         $t6, 0x2790($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2790);
    // 0x800A0EC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A0EC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A0EC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A0ECC: beq         $t6, $zero, L_800A1238
    if (ctx->r14 == 0) {
        // 0x800A0ED0: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800A1238;
    }
    // 0x800A0ED0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A0ED4: lb          $v0, 0x1F9($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1F9);
    // 0x800A0ED8: nop

    // 0x800A0EDC: blez        $v0, L_800A10F4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A0EE0: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_800A10F4;
    }
    // 0x800A0EE0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800A0EE4: lbu         $v1, 0x1F8($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1F8);
    // 0x800A0EE8: subu        $t9, $v0, $a1
    ctx->r25 = SUB32(ctx->r2, ctx->r5);
    // 0x800A0EEC: beq         $v1, $zero, L_800A10DC
    if (ctx->r3 == 0) {
        // 0x800A0EF0: sb          $t9, 0x1F9($a0)
        MEM_B(0X1F9, ctx->r4) = ctx->r25;
            goto L_800A10DC;
    }
    // 0x800A0EF0: sb          $t9, 0x1F9($a0)
    MEM_B(0X1F9, ctx->r4) = ctx->r25;
    // 0x800A0EF4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A0EF8: lw          $s0, 0x6CDC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6CDC);
    // 0x800A0EFC: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x800A0F00: sltiu       $at, $t1, 0x8
    ctx->r1 = ctx->r9 < 0X8 ? 1 : 0;
    // 0x800A0F04: beq         $at, $zero, L_800A0FBC
    if (ctx->r1 == 0) {
        // 0x800A0F08: addiu       $s0, $s0, 0x420
        ctx->r16 = ADD32(ctx->r16, 0X420);
            goto L_800A0FBC;
    }
    // 0x800A0F08: addiu       $s0, $s0, 0x420
    ctx->r16 = ADD32(ctx->r16, 0X420);
    // 0x800A0F0C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800A0F10: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A0F14: addu        $at, $at, $t1
    gpr jr_addend_800A0F20 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800A0F18: lw          $t1, -0x7908($at)
    ctx->r9 = ADD32(ctx->r1, -0X7908);
    // 0x800A0F1C: nop

    // 0x800A0F20: jr          $t1
    // 0x800A0F24: nop

    switch (jr_addend_800A0F20 >> 2) {
        case 0: goto L_800A0F28; break;
        case 1: goto L_800A0F38; break;
        case 2: goto L_800A0F48; break;
        case 3: goto L_800A0F58; break;
        case 4: goto L_800A0F6C; break;
        case 5: goto L_800A0F80; break;
        case 6: goto L_800A0F94; break;
        case 7: goto L_800A0FAC; break;
        default: switch_error(__func__, 0x800A0F20, 0x800E86F8);
    }
    // 0x800A0F24: nop

L_800A0F28:
    // 0x800A0F28: addiu       $t2, $zero, 0x21
    ctx->r10 = ADD32(0, 0X21);
    // 0x800A0F2C: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
    // 0x800A0F30: b           L_800A0FC8
    // 0x800A0F34: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_800A0FC8;
    // 0x800A0F34: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800A0F38:
    // 0x800A0F38: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x800A0F3C: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
    // 0x800A0F40: b           L_800A0FC8
    // 0x800A0F44: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_800A0FC8;
    // 0x800A0F44: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800A0F48:
    // 0x800A0F48: addiu       $t4, $zero, 0x1F
    ctx->r12 = ADD32(0, 0X1F);
    // 0x800A0F4C: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
    // 0x800A0F50: b           L_800A0FC8
    // 0x800A0F54: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_800A0FC8;
    // 0x800A0F54: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800A0F58:
    // 0x800A0F58: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800A0F5C: addiu       $t5, $zero, 0x21
    ctx->r13 = ADD32(0, 0X21);
    // 0x800A0F60: sh          $t5, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r13;
    // 0x800A0F64: b           L_800A0FC8
    // 0x800A0F68: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_800A0FC8;
    // 0x800A0F68: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_800A0F6C:
    // 0x800A0F6C: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800A0F70: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800A0F74: sh          $t6, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r14;
    // 0x800A0F78: b           L_800A0FC8
    // 0x800A0F7C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_800A0FC8;
    // 0x800A0F7C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_800A0F80:
    // 0x800A0F80: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800A0F84: addiu       $t8, $zero, 0x1F
    ctx->r24 = ADD32(0, 0X1F);
    // 0x800A0F88: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
    // 0x800A0F8C: b           L_800A0FC8
    // 0x800A0F90: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_800A0FC8;
    // 0x800A0F90: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_800A0F94:
    // 0x800A0F94: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800A0F98: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x800A0F9C: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x800A0FA0: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x800A0FA4: b           L_800A0FC8
    // 0x800A0FA8: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
        goto L_800A0FC8;
    // 0x800A0FA8: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
L_800A0FAC:
    // 0x800A0FAC: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x800A0FB0: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
    // 0x800A0FB4: b           L_800A0FC8
    // 0x800A0FB8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_800A0FC8;
    // 0x800A0FB8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800A0FBC:
    // 0x800A0FBC: addiu       $t1, $zero, 0x1D
    ctx->r9 = ADD32(0, 0X1D);
    // 0x800A0FC0: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
    // 0x800A0FC4: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800A0FC8:
    // 0x800A0FC8: jal         0x8009C30C
    // 0x800A0FCC: nop

    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x800A0FCC: nop

    after_0:
    // 0x800A0FD0: andi        $t2, $v0, 0x4
    ctx->r10 = ctx->r2 & 0X4;
    // 0x800A0FD4: beq         $t2, $zero, L_800A1008
    if (ctx->r10 == 0) {
        // 0x800A0FD8: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800A1008;
    }
    // 0x800A0FD8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A0FDC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800A0FE0: nop

    // 0x800A0FE4: lbu         $t3, 0x1F8($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X1F8);
    // 0x800A0FE8: nop

    // 0x800A0FEC: slti        $at, $t3, 0x1E
    ctx->r1 = SIGNED(ctx->r11) < 0X1E ? 1 : 0;
    // 0x800A0FF0: beq         $at, $zero, L_800A1008
    if (ctx->r1 == 0) {
        // 0x800A0FF4: nop
    
            goto L_800A1008;
    }
    // 0x800A0FF4: nop

    // 0x800A0FF8: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x800A0FFC: ori         $t5, $zero, 0x8000
    ctx->r13 = 0 | 0X8000;
    // 0x800A1000: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x800A1004: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
L_800A1008:
    // 0x800A1008: lw          $t8, 0x6D0C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6D0C);
    // 0x800A100C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800A1010: bne         $t8, $zero, L_800A10DC
    if (ctx->r24 != 0) {
        // 0x800A1014: nop
    
            goto L_800A10DC;
    }
    // 0x800A1014: nop

    // 0x800A1018: lb          $t9, 0x1D8($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X1D8);
    // 0x800A101C: nop

    // 0x800A1020: bne         $t9, $zero, L_800A10DC
    if (ctx->r25 != 0) {
        // 0x800A1024: nop
    
            goto L_800A10DC;
    }
    // 0x800A1024: nop

    // 0x800A1028: lbu         $t7, 0x1F8($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X1F8);
    // 0x800A102C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800A1030: beq         $t7, $zero, L_800A10DC
    if (ctx->r15 == 0) {
        // 0x800A1034: nop
    
            goto L_800A10DC;
    }
    // 0x800A1034: nop

    // 0x800A1038: lbu         $t1, 0x27B8($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X27B8);
    // 0x800A103C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A1040: bne         $t1, $zero, L_800A10DC
    if (ctx->r9 != 0) {
        // 0x800A1044: addiu       $a0, $a0, 0x6CFC
        ctx->r4 = ADD32(ctx->r4, 0X6CFC);
            goto L_800A10DC;
    }
    // 0x800A1044: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A1048: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A104C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A1050: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800A1054: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800A1058: addiu       $t5, $zero, -0x60
    ctx->r13 = ADD32(0, -0X60);
    // 0x800A105C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A1060: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A1064: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A1068: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A106C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800A1070: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800A1074: jal         0x800AA600
    // 0x800A1078: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A1078: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    after_1:
    // 0x800A107C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A1080: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A1084: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A1088: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A108C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A1090: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x800A1094: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A1098: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A109C: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A10A0: jal         0x800AA600
    // 0x800A10A4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A10A4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x800A10A8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A10AC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A10B0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800A10B4: addiu       $a1, $a1, 0x6CFC
    ctx->r5 = ADD32(ctx->r5, 0X6CFC);
    // 0x800A10B8: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x800A10BC: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x800A10C0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A10C4: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A10C8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800A10CC: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800A10D0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800A10D4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800A10D8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800A10DC:
    // 0x800A10DC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A10E0: lbu         $v0, 0x27B8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X27B8);
    // 0x800A10E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A10E8: b           L_800A1108
    // 0x800A10EC: addiu       $a1, $a1, 0x6CFC
    ctx->r5 = ADD32(ctx->r5, 0X6CFC);
        goto L_800A1108;
    // 0x800A10EC: addiu       $a1, $a1, 0x6CFC
    ctx->r5 = ADD32(ctx->r5, 0X6CFC);
    // 0x800A10F0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
L_800A10F4:
    // 0x800A10F4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A10F8: sb          $zero, 0x1F9($t9)
    MEM_B(0X1F9, ctx->r25) = 0;
    // 0x800A10FC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A1100: lbu         $v0, 0x27B8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X27B8);
    // 0x800A1104: addiu       $a1, $a1, 0x6CFC
    ctx->r5 = ADD32(ctx->r5, 0X6CFC);
L_800A1108:
    // 0x800A1108: beq         $v0, $zero, L_800A1238
    if (ctx->r2 == 0) {
        // 0x800A110C: andi        $t7, $v0, 0x20
        ctx->r15 = ctx->r2 & 0X20;
            goto L_800A1238;
    }
    // 0x800A110C: andi        $t7, $v0, 0x20
    ctx->r15 = ctx->r2 & 0X20;
    // 0x800A1110: beq         $t7, $zero, L_800A1210
    if (ctx->r15 == 0) {
        // 0x800A1114: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800A1210;
    }
    // 0x800A1114: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A1118: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A111C: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800A1120: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800A1124: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x800A1128: addiu       $t3, $zero, -0x60
    ctx->r11 = ADD32(0, -0X60);
    // 0x800A112C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A1130: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800A1134: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800A1138: lw          $s0, 0x6CDC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6CDC);
    // 0x800A113C: addiu       $t5, $zero, 0x1D
    ctx->r13 = ADD32(0, 0X1D);
    // 0x800A1140: addiu       $s0, $s0, 0x420
    ctx->r16 = ADD32(ctx->r16, 0X420);
    // 0x800A1144: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x800A1148: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x800A114C: jal         0x8009C30C
    // 0x800A1150: sh          $t5, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r13;
    get_filtered_cheats(rdram, ctx);
        goto after_3;
    // 0x800A1150: sh          $t5, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r13;
    after_3:
    // 0x800A1154: andi        $t4, $v0, 0x4
    ctx->r12 = ctx->r2 & 0X4;
    // 0x800A1158: beq         $t4, $zero, L_800A118C
    if (ctx->r12 == 0) {
        // 0x800A115C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A118C;
    }
    // 0x800A115C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A1160: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800A1164: nop

    // 0x800A1168: lbu         $t8, 0x1F8($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X1F8);
    // 0x800A116C: nop

    // 0x800A1170: slti        $at, $t8, 0x1E
    ctx->r1 = SIGNED(ctx->r24) < 0X1E ? 1 : 0;
    // 0x800A1174: beq         $at, $zero, L_800A118C
    if (ctx->r1 == 0) {
        // 0x800A1178: nop
    
            goto L_800A118C;
    }
    // 0x800A1178: nop

    // 0x800A117C: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x800A1180: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x800A1184: subu        $t1, $t7, $t9
    ctx->r9 = SUB32(ctx->r15, ctx->r25);
    // 0x800A1188: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
L_800A118C:
    // 0x800A118C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A1190: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A1194: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A1198: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A119C: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A11A0: jal         0x800AA600
    // 0x800A11A4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A11A4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x800A11A8: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A11AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A11B0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A11B4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A11B8: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800A11BC: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x800A11C0: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A11C4: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A11C8: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A11CC: jal         0x800AA600
    // 0x800A11D0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A11D0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_5:
    // 0x800A11D4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A11D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A11DC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A11E0: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x800A11E4: lw          $v0, 0x6CFC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CFC);
    // 0x800A11E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A11EC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800A11F0: sw          $t2, 0x6CFC($at)
    MEM_W(0X6CFC, ctx->r1) = ctx->r10;
    // 0x800A11F4: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A11F8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800A11FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A1200: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800A1204: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800A1208: lbu         $a0, 0x27B8($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X27B8);
    // 0x800A120C: nop

L_800A1210:
    // 0x800A1210: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800A1214: nop

    // 0x800A1218: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800A121C: beq         $at, $zero, L_800A1230
    if (ctx->r1 == 0) {
        // 0x800A1220: subu        $t6, $a0, $t4
        ctx->r14 = SUB32(ctx->r4, ctx->r12);
            goto L_800A1230;
    }
    // 0x800A1220: subu        $t6, $a0, $t4
    ctx->r14 = SUB32(ctx->r4, ctx->r12);
    // 0x800A1224: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A1228: b           L_800A1238
    // 0x800A122C: sb          $t6, 0x27B8($at)
    MEM_B(0X27B8, ctx->r1) = ctx->r14;
        goto L_800A1238;
    // 0x800A122C: sb          $t6, 0x27B8($at)
    MEM_B(0X27B8, ctx->r1) = ctx->r14;
L_800A1230:
    // 0x800A1230: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A1234: sb          $zero, 0x27B8($at)
    MEM_B(0X27B8, ctx->r1) = 0;
L_800A1238:
    // 0x800A1238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A123C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A1240: jr          $ra
    // 0x800A1244: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A1244: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
