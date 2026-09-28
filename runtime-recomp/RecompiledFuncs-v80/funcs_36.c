#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void static_3_800C7CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7CA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7CA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7CAC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800C7CB0: jal         0x800C7BE0
    // 0x800C7CB4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C7BE0(rdram, ctx);
        goto after_0;
    // 0x800C7CB4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x800C7CB8: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800C7CBC: beq         $t6, $zero, L_800C7CE8
    if (ctx->r14 == 0) {
        // 0x800C7CC0: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_800C7CE8;
    }
    // 0x800C7CC0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800C7CC4: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
L_800C7CC8:
    // 0x800C7CC8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800C7CCC: jal         0x800C7BE0
    // 0x800C7CD0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C7BE0(rdram, ctx);
        goto after_1;
    // 0x800C7CD0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x800C7CD4: sll         $t7, $t1, 7
    ctx->r15 = S32(ctx->r9 << 7);
    // 0x800C7CD8: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x800C7CDC: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
    // 0x800C7CE0: bne         $t9, $zero, L_800C7CC8
    if (ctx->r25 != 0) {
        // 0x800C7CE4: addu        $t1, $t7, $t8
        ctx->r9 = ADD32(ctx->r15, ctx->r24);
            goto L_800C7CC8;
    }
    // 0x800C7CE4: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
L_800C7CE8:
    // 0x800C7CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7CEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7CF0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800C7CF4: jr          $ra
    // 0x800C7CF8: nop

    return;
    // 0x800C7CF8: nop

    // 0x800C7CFC: jr          $ra
    // 0x800C7D00: nop

    return;
    // 0x800C7D00: nop

;}
RECOMP_FUNC void static_3_800CAC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAC5C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800CAC60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CAC64: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800CAC68: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800CAC6C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800CAC70: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800CAC74: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800CAC78: nop

    // 0x800CAC7C: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x800CAC80: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800CAC84: nop

    // 0x800CAC88: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800CAC8C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CAC90: nop

    // 0x800CAC94: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800CAC98: nop

    // 0x800CAC9C: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800CACA0: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800CACA4: nop

    // 0x800CACA8: bne         $t0, $zero, L_800CACBC
    if (ctx->r8 != 0) {
        // 0x800CACAC: nop
    
            goto L_800CACBC;
    }
    // 0x800CACAC: nop

    // 0x800CACB0: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x800CACB4: b           L_800CB0F4
    // 0x800CACB8: nop

        goto L_800CB0F4;
    // 0x800CACB8: nop

L_800CACBC:
    // 0x800CACBC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800CACC0: nop

    // 0x800CACC4: beq         $t1, $zero, L_800CACD4
    if (ctx->r9 == 0) {
        // 0x800CACC8: nop
    
            goto L_800CACD4;
    }
    // 0x800CACC8: nop

    // 0x800CACCC: b           L_800CACEC
    // 0x800CACD0: nop

        goto L_800CACEC;
    // 0x800CACD0: nop

L_800CACD4:
    // 0x800CACD4: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CACD8: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800CACDC: addiu       $a1, $a1, -0x6A58
    ctx->r5 = ADD32(ctx->r5, -0X6A58);
    // 0x800CACE0: addiu       $a0, $a0, -0x6A60
    ctx->r4 = ADD32(ctx->r4, -0X6A60);
    // 0x800CACE4: jal         0x800B6F40
    // 0x800CACE8: addiu       $a2, $zero, 0x175
    ctx->r6 = ADD32(0, 0X175);
    __assert_recomp(rdram, ctx);
        goto after_0;
    // 0x800CACE8: addiu       $a2, $zero, 0x175
    ctx->r6 = ADD32(0, 0X175);
    after_0:
L_800CACEC:
    // 0x800CACEC: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800CACF0: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800CACF4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800CACF8: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x800CACFC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800CAD00: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x800CAD04: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x800CAD08: jalr        $t9
    // 0x800CAD0C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CAD0C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_1:
    // 0x800CAD10: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800CAD14: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800CAD18: nop

    // 0x800CAD1C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800CAD20: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800CAD24: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x800CAD28: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800CAD2C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800CAD30: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800CAD34: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CAD38: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800CAD3C: or          $t0, $t8, $at
    ctx->r8 = ctx->r24 | ctx->r1;
    // 0x800CAD40: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800CAD44: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CAD48: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800CAD4C: lh          $t2, 0x0($t3)
    ctx->r10 = MEM_H(ctx->r11, 0X0);
    // 0x800CAD50: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800CAD54: addiu       $t9, $t2, 0x440
    ctx->r25 = ADD32(ctx->r10, 0X440);
    // 0x800CAD58: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x800CAD5C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800CAD60: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x800CAD64: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800CAD68: or          $t0, $t5, $t8
    ctx->r8 = ctx->r13 | ctx->r24;
    // 0x800CAD6C: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800CAD70: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800CAD74: nop

    // 0x800CAD78: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800CAD7C: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x800CAD80: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800CAD84: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CAD88: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800CAD8C: lh          $t4, 0x0($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X0);
    // 0x800CAD90: lui         $at, 0x808
    ctx->r1 = S32(0X808 << 16);
    // 0x800CAD94: addiu       $t6, $t4, 0x580
    ctx->r14 = ADD32(ctx->r12, 0X580);
    // 0x800CAD98: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800CAD9C: or          $t5, $t7, $at
    ctx->r13 = ctx->r15 | ctx->r1;
    // 0x800CADA0: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x800CADA4: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CADA8: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800CADAC: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800CADB0: nop

    // 0x800CADB4: addiu       $t9, $t1, 0x6C0
    ctx->r25 = ADD32(ctx->r9, 0X6C0);
    // 0x800CADB8: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x800CADBC: addiu       $t3, $t1, 0x800
    ctx->r11 = ADD32(ctx->r9, 0X800);
    // 0x800CADC0: andi        $t2, $t3, 0xFFFF
    ctx->r10 = ctx->r11 & 0XFFFF;
    // 0x800CADC4: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x800CADC8: or          $t7, $t2, $t6
    ctx->r15 = ctx->r10 | ctx->r14;
    // 0x800CADCC: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x800CADD0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CADD4: nop

    // 0x800CADD8: lw          $t0, 0x38($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X38);
    // 0x800CADDC: nop

    // 0x800CADE0: beq         $t0, $zero, L_800CB088
    if (ctx->r8 == 0) {
        // 0x800CADE4: nop
    
            goto L_800CB088;
    }
    // 0x800CADE4: nop

    // 0x800CADE8: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800CADEC: nop

    // 0x800CADF0: sw          $zero, 0x38($t3)
    MEM_W(0X38, ctx->r11) = 0;
    // 0x800CADF4: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800CADF8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800CADFC: lh          $t9, 0x18($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X18);
    // 0x800CAE00: lh          $t6, 0x1A($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X1A);
    // 0x800CAE04: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x800CAE08: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x800CAE0C: lh          $t2, 0x37A0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X37A0);
    // 0x800CAE10: nop

    // 0x800CAE14: multu       $t2, $t6
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CAE18: mflo        $t7
    ctx->r15 = lo;
    // 0x800CAE1C: sra         $t5, $t7, 15
    ctx->r13 = S32(SIGNED(ctx->r15) >> 15);
    // 0x800CAE20: sh          $t5, 0x28($t1)
    MEM_H(0X28, ctx->r9) = ctx->r13;
    // 0x800CAE24: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CAE28: nop

    // 0x800CAE2C: lh          $t0, 0x1C($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X1C);
    // 0x800CAE30: lh          $t3, 0x28($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X28);
    // 0x800CAE34: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x800CAE38: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800CAE3C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800CAE40: addiu       $t4, $t8, 0x24
    ctx->r12 = ADD32(ctx->r24, 0X24);
    // 0x800CAE44: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800CAE48: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800CAE4C: cvt.d.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.d = CVT_D_W(ctx->f4.u32l);
    // 0x800CAE50: jal         0x800CB2D4
    // 0x800CAE54: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    static_3_800CB2D4(rdram, ctx);
        goto after_2;
    // 0x800CAE54: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    after_2:
    // 0x800CAE58: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800CAE5C: nop

    // 0x800CAE60: sh          $v0, 0x26($t2)
    MEM_H(0X26, ctx->r10) = ctx->r2;
    // 0x800CAE64: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800CAE68: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800CAE6C: lh          $t7, 0x18($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X18);
    // 0x800CAE70: lh          $t3, 0x1A($t6)
    ctx->r11 = MEM_H(ctx->r14, 0X1A);
    // 0x800CAE74: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800CAE78: sll         $t1, $t5, 1
    ctx->r9 = S32(ctx->r13 << 1);
    // 0x800CAE7C: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800CAE80: lh          $t0, 0x389E($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X389E);
    // 0x800CAE84: nop

    // 0x800CAE88: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CAE8C: mflo        $t9
    ctx->r25 = lo;
    // 0x800CAE90: sra         $t8, $t9, 15
    ctx->r24 = S32(SIGNED(ctx->r25) >> 15);
    // 0x800CAE94: sh          $t8, 0x2E($t6)
    MEM_H(0X2E, ctx->r14) = ctx->r24;
    // 0x800CAE98: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800CAE9C: nop

    // 0x800CAEA0: lh          $t2, 0x1E($t4)
    ctx->r10 = MEM_H(ctx->r12, 0X1E);
    // 0x800CAEA4: lh          $t7, 0x2E($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X2E);
    // 0x800CAEA8: lw          $t5, 0x34($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X34);
    // 0x800CAEAC: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800CAEB0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800CAEB4: addiu       $t1, $t4, 0x2A
    ctx->r9 = ADD32(ctx->r12, 0X2A);
    // 0x800CAEB8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800CAEBC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800CAEC0: cvt.d.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.d = CVT_D_W(ctx->f8.u32l);
    // 0x800CAEC4: jal         0x800CB2D4
    // 0x800CAEC8: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    static_3_800CB2D4(rdram, ctx);
        goto after_3;
    // 0x800CAEC8: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    after_3:
    // 0x800CAECC: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800CAED0: nop

    // 0x800CAED4: sh          $v0, 0x2C($t0)
    MEM_H(0X2C, ctx->r8) = ctx->r2;
    // 0x800CAED8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800CAEDC: nop

    // 0x800CAEE0: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x800CAEE4: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x800CAEE8: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x800CAEEC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CAEF0: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800CAEF4: lh          $t6, 0x1C($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X1C);
    // 0x800CAEF8: lui         $at, 0x906
    ctx->r1 = S32(0X906 << 16);
    // 0x800CAEFC: andi        $t2, $t6, 0xFFFF
    ctx->r10 = ctx->r14 & 0XFFFF;
    // 0x800CAF00: or          $t7, $t2, $at
    ctx->r15 = ctx->r10 | ctx->r1;
    // 0x800CAF04: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800CAF08: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800CAF0C: nop

    // 0x800CAF10: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800CAF14: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800CAF18: nop

    // 0x800CAF1C: addiu       $t0, $t1, 0x8
    ctx->r8 = ADD32(ctx->r9, 0X8);
    // 0x800CAF20: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800CAF24: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800CAF28: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800CAF2C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800CAF30: lh          $t9, 0x1E($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X1E);
    // 0x800CAF34: lui         $at, 0x904
    ctx->r1 = S32(0X904 << 16);
    // 0x800CAF38: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800CAF3C: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800CAF40: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800CAF44: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800CAF48: nop

    // 0x800CAF4C: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800CAF50: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800CAF54: nop

    // 0x800CAF58: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x800CAF5C: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800CAF60: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800CAF64: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800CAF68: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800CAF6C: lh          $t0, 0x28($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X28);
    // 0x800CAF70: lui         $at, 0x902
    ctx->r1 = S32(0X902 << 16);
    // 0x800CAF74: andi        $t3, $t0, 0xFFFF
    ctx->r11 = ctx->r8 & 0XFFFF;
    // 0x800CAF78: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x800CAF7C: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x800CAF80: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800CAF84: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800CAF88: lh          $t2, 0x26($t6)
    ctx->r10 = MEM_H(ctx->r14, 0X26);
    // 0x800CAF8C: lhu         $t4, 0x24($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0X24);
    // 0x800CAF90: andi        $t7, $t2, 0xFFFF
    ctx->r15 = ctx->r10 & 0XFFFF;
    // 0x800CAF94: sll         $t5, $t7, 16
    ctx->r13 = S32(ctx->r15 << 16);
    // 0x800CAF98: andi        $t1, $t4, 0xFFFF
    ctx->r9 = ctx->r12 & 0XFFFF;
    // 0x800CAF9C: or          $t0, $t5, $t1
    ctx->r8 = ctx->r13 | ctx->r9;
    // 0x800CAFA0: sw          $t0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r8;
    // 0x800CAFA4: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800CAFA8: nop

    // 0x800CAFAC: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x800CAFB0: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800CAFB4: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800CAFB8: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800CAFBC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800CAFC0: lh          $t7, 0x2E($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X2E);
    // 0x800CAFC4: lui         $at, 0x900
    ctx->r1 = S32(0X900 << 16);
    // 0x800CAFC8: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x800CAFCC: or          $t4, $t6, $at
    ctx->r12 = ctx->r14 | ctx->r1;
    // 0x800CAFD0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800CAFD4: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800CAFD8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800CAFDC: lh          $t0, 0x2C($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X2C);
    // 0x800CAFE0: lhu         $t8, 0x2A($t1)
    ctx->r24 = MEM_HU(ctx->r9, 0X2A);
    // 0x800CAFE4: andi        $t3, $t0, 0xFFFF
    ctx->r11 = ctx->r8 & 0XFFFF;
    // 0x800CAFE8: sll         $t9, $t3, 16
    ctx->r25 = S32(ctx->r11 << 16);
    // 0x800CAFEC: andi        $t2, $t8, 0xFFFF
    ctx->r10 = ctx->r24 & 0XFFFF;
    // 0x800CAFF0: or          $t7, $t9, $t2
    ctx->r15 = ctx->r25 | ctx->r10;
    // 0x800CAFF4: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800CAFF8: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800CAFFC: nop

    // 0x800CB000: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800CB004: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800CB008: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800CB00C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800CB010: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800CB014: lh          $t3, 0x20($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X20);
    // 0x800CB018: lui         $at, 0x908
    ctx->r1 = S32(0X908 << 16);
    // 0x800CB01C: andi        $t1, $t3, 0xFFFF
    ctx->r9 = ctx->r11 & 0XFFFF;
    // 0x800CB020: or          $t8, $t1, $at
    ctx->r24 = ctx->r9 | ctx->r1;
    // 0x800CB024: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800CB028: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800CB02C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800CB030: lh          $t7, 0x22($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X22);
    // 0x800CB034: nop

    // 0x800CB038: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x800CB03C: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x800CB040: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB044: nop

    // 0x800CB048: addiu       $t0, $t5, 0x8
    ctx->r8 = ADD32(ctx->r13, 0X8);
    // 0x800CB04C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800CB050: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800CB054: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800CB058: lui         $t3, 0x309
    ctx->r11 = S32(0X309 << 16);
    // 0x800CB05C: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x800CB060: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CB064: nop

    // 0x800CB068: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    // 0x800CB06C: jal         0x800C8CF0
    // 0x800CB070: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800CB070: nop

    after_4:
    // 0x800CB074: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800CB078: nop

    // 0x800CB07C: sw          $v0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r2;
    // 0x800CB080: b           L_800CB0C8
    // 0x800CB084: nop

        goto L_800CB0C8;
    // 0x800CB084: nop

L_800CB088:
    // 0x800CB088: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB08C: nop

    // 0x800CB090: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x800CB094: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x800CB098: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800CB09C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800CB0A0: lui         $t6, 0x308
    ctx->r14 = S32(0X308 << 16);
    // 0x800CB0A4: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800CB0A8: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800CB0AC: nop

    // 0x800CB0B0: lw          $a0, 0x14($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X14);
    // 0x800CB0B4: jal         0x800C8CF0
    // 0x800CB0B8: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x800CB0B8: nop

    after_5:
    // 0x800CB0BC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800CB0C0: nop

    // 0x800CB0C4: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
L_800CB0C8:
    // 0x800CB0C8: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800CB0CC: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800CB0D0: lh          $t1, 0x0($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X0);
    // 0x800CB0D4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800CB0D8: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x800CB0DC: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x800CB0E0: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB0E4: b           L_800CB0F4
    // 0x800CB0E8: nop

        goto L_800CB0F4;
    // 0x800CB0E8: nop

    // 0x800CB0EC: b           L_800CB0F4
    // 0x800CB0F0: nop

        goto L_800CB0F4;
    // 0x800CB0F0: nop

L_800CB0F4:
    // 0x800CB0F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB0F8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800CB0FC: jr          $ra
    // 0x800CB100: nop

    return;
    // 0x800CB100: nop

;}
RECOMP_FUNC void static_3_800CB498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB498: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800CB49C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800CB4A0: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800CB4A4: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x800CB4A8: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800CB4AC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800CB4B0: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x800CB4B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CB4B8: bgez        $a3, L_800CB4D0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800CB4BC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800CB4D0;
    }
    // 0x800CB4BC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CB4C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CB4C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800CB4C8: nop

    // 0x800CB4CC: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800CB4D0:
    // 0x800CB4D0: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800CB4D4: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x800CB4D8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800CB4DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800CB4E0: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800CB4E4: nop

    // 0x800CB4E8: div.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x800CB4EC: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x800CB4F0: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x800CB4F4: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x800CB4F8: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB4FC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CB500: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800CB504: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800CB508: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800CB50C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CB510: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x800CB514: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800CB518: nop

    // 0x800CB51C: div.d       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f6.d);
    // 0x800CB520: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x800CB524: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x800CB528: b           L_800CB538
    // 0x800CB52C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800CB538;
    // 0x800CB52C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800CB530: b           L_800CB538
    // 0x800CB534: nop

        goto L_800CB538;
    // 0x800CB534: nop

L_800CB538:
    // 0x800CB538: jr          $ra
    // 0x800CB53C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800CB53C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void static_3_800CBAC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBAC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CBAC4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800CBAC8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800CBACC: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800CBAD0: sll         $t8, $s5, 16
    ctx->r24 = S32(ctx->r21 << 16);
    // 0x800CBAD4: sra         $s5, $t8, 16
    ctx->r21 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800CBAD8: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CBADC: blez        $s1, L_800CBB48
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800CBAE0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800CBB48;
    }
    // 0x800CBAE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CBAE4: lw          $t9, 0x30($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X30);
    // 0x800CBAE8: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x800CBAEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CBAF0: jalr        $t9
    // 0x800CBAF4: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CBAF4: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    after_0:
    // 0x800CBAF8: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800CBAFC: addu        $s1, $s1, $a2
    ctx->r17 = ADD32(ctx->r17, ctx->r6);
    // 0x800CBB00: andi        $t6, $s3, 0xFFFF
    ctx->r14 = ctx->r19 & 0XFFFF;
    // 0x800CBB04: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CBB08: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CBB0C: andi        $t8, $s1, 0x7
    ctx->r24 = ctx->r17 & 0X7;
    // 0x800CBB10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CBB14: subu        $t9, $s1, $t8
    ctx->r25 = SUB32(ctx->r17, ctx->r24);
    // 0x800CBB18: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800CBB1C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800CBB20: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CBB24: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800CBB28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800CBB2C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800CBB30: subu        $t9, $v0, $a2
    ctx->r25 = SUB32(ctx->r2, ctx->r6);
    // 0x800CBB34: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800CBB38: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800CBB3C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800CBB40: b           L_800CBB4C
    // 0x800CBB44: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800CBB4C;
    // 0x800CBB44: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800CBB48:
    // 0x800CBB48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800CBB4C:
    // 0x800CBB4C: andi        $t6, $s4, 0x2
    ctx->r14 = ctx->r20 & 0X2;
    // 0x800CBB50: beq         $t6, $zero, L_800CBB78
    if (ctx->r14 == 0) {
        // 0x800CBB54: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_800CBB78;
    }
    // 0x800CBB54: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800CBB58: lui         $t7, 0xF00
    ctx->r15 = S32(0XF00 << 16);
    // 0x800CBB5C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CBB60: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x800CBB64: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800CBB68: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CBB6C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800CBB70: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800CBB74: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800CBB78:
    // 0x800CBB78: addu        $t6, $s3, $a2
    ctx->r14 = ADD32(ctx->r19, ctx->r6);
    // 0x800CBB7C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800CBB80: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CBB84: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800CBB88: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800CBB8C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800CBB90: sll         $t7, $s6, 1
    ctx->r15 = S32(ctx->r22 << 1);
    // 0x800CBB94: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800CBB98: sll         $t6, $s5, 16
    ctx->r14 = S32(ctx->r21 << 16);
    // 0x800CBB9C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800CBBA0: andi        $t7, $s4, 0xFF
    ctx->r15 = ctx->r20 & 0XFF;
    // 0x800CBBA4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CBBA8: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800CBBAC: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800CBBB0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800CBBB4: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800CBBB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CBBBC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800CBBC0: lw          $t9, 0x14($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X14);
    // 0x800CBBC4: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800CBBC8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CBBCC: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800CBBD0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800CBBD4: sw          $zero, 0x40($s2)
    MEM_W(0X40, ctx->r18) = 0;
    // 0x800CBBD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CBBDC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CBBE0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800CBBE4: jr          $ra
    // 0x800CBBE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800CBBE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void static_3_800D1728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1728: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D172C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800D1730: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800D1734: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x800D1738: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800D173C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D1740: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D1744: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800D1748: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800D174C: sb          $t6, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r14;
    // 0x800D1750: jal         0x800D5FDC
    // 0x800D1754: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_0;
    // 0x800D1754: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x800D1758: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D175C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800D1760: beq         $t8, $zero, L_800D1770
    if (ctx->r24 == 0) {
        // 0x800D1764: nop
    
            goto L_800D1770;
    }
    // 0x800D1764: nop

    // 0x800D1768: b           L_800D17D8
    // 0x800D176C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800D17D8;
    // 0x800D176C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800D1770:
    // 0x800D1770: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800D1774:
    // 0x800D1774: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800D1778: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800D177C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800D1780: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800D1784: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x800D1788: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800D178C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D1790: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800D1794: jal         0x800CD8F0
    // 0x800D1798: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_1;
    // 0x800D1798: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x800D179C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D17A0: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800D17A4: bne         $t3, $zero, L_800D17C0
    if (ctx->r11 != 0) {
        // 0x800D17A8: nop
    
            goto L_800D17C0;
    }
    // 0x800D17A8: nop

    // 0x800D17AC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800D17B0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800D17B4: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x800D17B8: bne         $at, $zero, L_800D1774
    if (ctx->r1 != 0) {
        // 0x800D17BC: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_800D1774;
    }
    // 0x800D17BC: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_800D17C0:
    // 0x800D17C0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800D17C4: sb          $zero, 0x65($t6)
    MEM_B(0X65, ctx->r14) = 0;
    // 0x800D17C8: jal         0x800D5FDC
    // 0x800D17CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_2;
    // 0x800D17CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800D17D0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D17D4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_800D17D8:
    // 0x800D17D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D17DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D17E0: jr          $ra
    // 0x800D17E4: nop

    return;
    // 0x800D17E4: nop

    // 0x800D17E8: nop

    // 0x800D17EC: nop

;}
RECOMP_FUNC void static_3_800D38A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D38A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D38A4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x800D38A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D38AC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800D38B0: slti        $at, $t6, 0x26
    ctx->r1 = SIGNED(ctx->r14) < 0X26 ? 1 : 0;
    // 0x800D38B4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800D38B8: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800D38BC: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x800D38C0: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x800D38C4: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800D38C8: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x800D38CC: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800D38D0: bne         $at, $zero, L_800D38FC
    if (ctx->r1 != 0) {
        // 0x800D38D4: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800D38FC;
    }
    // 0x800D38D4: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800D38D8: addiu       $t7, $t6, -0x45
    ctx->r15 = ADD32(ctx->r14, -0X45);
    // 0x800D38DC: sltiu       $at, $t7, 0x34
    ctx->r1 = ctx->r15 < 0X34 ? 1 : 0;
    // 0x800D38E0: beq         $at, $zero, L_800D3EE8
    if (ctx->r1 == 0) {
        // 0x800D38E4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800D3EE8;
    }
    // 0x800D38E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D38E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D38EC: addu        $at, $at, $t7
    gpr jr_addend_800D38F4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800D38F0: lw          $t7, -0x691C($at)
    ctx->r15 = ADD32(ctx->r1, -0X691C);
    // 0x800D38F4: jr          $t7
    // 0x800D38F8: nop

    switch (jr_addend_800D38F4 >> 2) {
        case 0: goto L_800D3C08; break;
        case 1: goto L_800D3EE8; break;
        case 2: goto L_800D3C08; break;
        case 3: goto L_800D3EE8; break;
        case 4: goto L_800D3EE8; break;
        case 5: goto L_800D3EE8; break;
        case 6: goto L_800D3EE8; break;
        case 7: goto L_800D3EE8; break;
        case 8: goto L_800D3EE8; break;
        case 9: goto L_800D3EE8; break;
        case 10: goto L_800D3EE8; break;
        case 11: goto L_800D3EE8; break;
        case 12: goto L_800D3EE8; break;
        case 13: goto L_800D3EE8; break;
        case 14: goto L_800D3EE8; break;
        case 15: goto L_800D3EE8; break;
        case 16: goto L_800D3EE8; break;
        case 17: goto L_800D3EE8; break;
        case 18: goto L_800D3EE8; break;
        case 19: goto L_800D3AB8; break;
        case 20: goto L_800D3EE8; break;
        case 21: goto L_800D3EE8; break;
        case 22: goto L_800D3EE8; break;
        case 23: goto L_800D3EE8; break;
        case 24: goto L_800D3EE8; break;
        case 25: goto L_800D3EE8; break;
        case 26: goto L_800D3EE8; break;
        case 27: goto L_800D3EE8; break;
        case 28: goto L_800D3EE8; break;
        case 29: goto L_800D3EE8; break;
        case 30: goto L_800D3910; break;
        case 31: goto L_800D3948; break;
        case 32: goto L_800D3C08; break;
        case 33: goto L_800D3C08; break;
        case 34: goto L_800D3C08; break;
        case 35: goto L_800D3EE8; break;
        case 36: goto L_800D3948; break;
        case 37: goto L_800D3EE8; break;
        case 38: goto L_800D3EE8; break;
        case 39: goto L_800D3EE8; break;
        case 40: goto L_800D3EE8; break;
        case 41: goto L_800D3D6C; break;
        case 42: goto L_800D3AB8; break;
        case 43: goto L_800D3E3C; break;
        case 44: goto L_800D3EE8; break;
        case 45: goto L_800D3EE8; break;
        case 46: goto L_800D3E84; break;
        case 47: goto L_800D3EE8; break;
        case 48: goto L_800D3AB8; break;
        case 49: goto L_800D3EE8; break;
        case 50: goto L_800D3EE8; break;
        case 51: goto L_800D3AB8; break;
        default: switch_error(__func__, 0x800D38F4, 0x800E96E4);
    }
    // 0x800D38F8: nop

L_800D38FC:
    // 0x800D38FC: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x800D3900: beql        $v1, $at, L_800D3ECC
    if (ctx->r3 == ctx->r1) {
        // 0x800D3904: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800D3ECC;
    }
    goto skip_0;
    // 0x800D3904: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x800D3908: b           L_800D3EEC
    // 0x800D390C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
        goto L_800D3EEC;
    // 0x800D390C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_800D3910:
    // 0x800D3910: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800D3914: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D3918: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x800D391C: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x800D3920: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800D3924: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D3928: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D392C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800D3930: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x800D3934: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800D3938: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800D393C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800D3940: b           L_800D3F00
    // 0x800D3944: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_800D3F00;
    // 0x800D3944: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_800D3948:
    // 0x800D3948: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800D394C: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800D3950: bnel        $v0, $at, L_800D3988
    if (ctx->r2 != ctx->r1) {
        // 0x800D3954: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800D3988;
    }
    goto skip_1;
    // 0x800D3954: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_1:
    // 0x800D3958: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800D395C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D3960: addiu       $t7, $t9, 0x3
    ctx->r15 = ADD32(ctx->r25, 0X3);
    // 0x800D3964: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800D3968: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800D396C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D3970: lw          $t7, -0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X4);
    // 0x800D3974: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800D3978: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D397C: b           L_800D39E4
    // 0x800D3980: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800D39E4;
    // 0x800D3980: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800D3984: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800D3988:
    // 0x800D3988: bnel        $v0, $at, L_800D39C0
    if (ctx->r2 != ctx->r1) {
        // 0x800D398C: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_800D39C0;
    }
    goto skip_2;
    // 0x800D398C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_2:
    // 0x800D3990: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800D3994: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D3998: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x800D399C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800D39A0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800D39A4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D39A8: lw          $t8, -0x8($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X8);
    // 0x800D39AC: lw          $t9, -0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4);
    // 0x800D39B0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D39B4: b           L_800D39E4
    // 0x800D39B8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800D39E4;
    // 0x800D39B8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800D39BC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_800D39C0:
    // 0x800D39C0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D39C4: addiu       $t6, $t7, 0x3
    ctx->r14 = ADD32(ctx->r15, 0X3);
    // 0x800D39C8: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x800D39CC: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800D39D0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D39D4: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x800D39D8: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800D39DC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D39E0: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_800D39E4:
    // 0x800D39E4: lbu         $t7, 0x34($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X34);
    // 0x800D39E8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800D39EC: bnel        $t7, $at, L_800D3A10
    if (ctx->r15 != ctx->r1) {
        // 0x800D39F0: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_800D3A10;
    }
    goto skip_3;
    // 0x800D39F0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x800D39F4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800D39F8: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800D39FC: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800D3A00: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800D3A04: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D3A08: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800D3A0C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_800D3A10:
    // 0x800D3A10: bgtzl       $t6, L_800D3A4C
    if (SIGNED(ctx->r14) > 0) {
        // 0x800D3A14: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_800D3A4C;
    }
    goto skip_4;
    // 0x800D3A14: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_4:
    // 0x800D3A18: bltzl       $t6, L_800D3A2C
    if (SIGNED(ctx->r14) < 0) {
        // 0x800D3A1C: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_800D3A2C;
    }
    goto skip_5;
    // 0x800D3A1C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_5:
    // 0x800D3A20: b           L_800D3A4C
    // 0x800D3A24: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
        goto L_800D3A4C;
    // 0x800D3A24: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x800D3A28: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_800D3A2C:
    // 0x800D3A2C: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x800D3A30: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x800D3A34: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800D3A38: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D3A3C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800D3A40: b           L_800D3A9C
    // 0x800D3A44: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
        goto L_800D3A9C;
    // 0x800D3A44: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800D3A48: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_800D3A4C:
    // 0x800D3A4C: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x800D3A50: beq         $t8, $zero, L_800D3A78
    if (ctx->r24 == 0) {
        // 0x800D3A54: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_800D3A78;
    }
    // 0x800D3A54: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800D3A58: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D3A5C: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x800D3A60: addu        $t9, $a3, $t7
    ctx->r25 = ADD32(ctx->r7, ctx->r15);
    // 0x800D3A64: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800D3A68: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800D3A6C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800D3A70: b           L_800D3A9C
    // 0x800D3A74: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
        goto L_800D3A9C;
    // 0x800D3A74: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
L_800D3A78:
    // 0x800D3A78: beql        $t6, $zero, L_800D3AA0
    if (ctx->r14 == 0) {
        // 0x800D3A7C: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_800D3AA0;
    }
    goto skip_6;
    // 0x800D3A7C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_6:
    // 0x800D3A80: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800D3A84: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x800D3A88: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800D3A8C: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800D3A90: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D3A94: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800D3A98: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800D3A9C:
    // 0x800D3A9C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_800D3AA0:
    // 0x800D3AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D3AA4: addu        $t7, $t9, $a3
    ctx->r15 = ADD32(ctx->r25, ctx->r7);
    // 0x800D3AA8: jal         0x800D6700
    // 0x800D3AAC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_0;
    // 0x800D3AAC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_0:
    // 0x800D3AB0: b           L_800D3F04
    // 0x800D3AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D3F04;
    // 0x800D3AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3AB8:
    // 0x800D3AB8: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800D3ABC: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800D3AC0: bnel        $v0, $at, L_800D3AF8
    if (ctx->r2 != ctx->r1) {
        // 0x800D3AC4: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800D3AF8;
    }
    goto skip_7;
    // 0x800D3AC4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_7:
    // 0x800D3AC8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800D3ACC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D3AD0: addiu       $t8, $t6, 0x3
    ctx->r24 = ADD32(ctx->r14, 0X3);
    // 0x800D3AD4: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800D3AD8: addiu       $t7, $t9, 0x4
    ctx->r15 = ADD32(ctx->r25, 0X4);
    // 0x800D3ADC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D3AE0: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x800D3AE4: sra         $t6, $t8, 31
    ctx->r14 = S32(SIGNED(ctx->r24) >> 31);
    // 0x800D3AE8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800D3AEC: b           L_800D3B54
    // 0x800D3AF0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_800D3B54;
    // 0x800D3AF0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800D3AF4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800D3AF8:
    // 0x800D3AF8: bnel        $v0, $at, L_800D3B30
    if (ctx->r2 != ctx->r1) {
        // 0x800D3AFC: lw          $t6, 0x0($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X0);
            goto L_800D3B30;
    }
    goto skip_8;
    // 0x800D3AFC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    skip_8:
    // 0x800D3B00: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800D3B04: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D3B08: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x800D3B0C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800D3B10: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800D3B14: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D3B18: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800D3B1C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x800D3B20: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800D3B24: b           L_800D3B54
    // 0x800D3B28: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_800D3B54;
    // 0x800D3B28: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D3B2C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
L_800D3B30:
    // 0x800D3B30: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D3B34: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x800D3B38: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800D3B3C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800D3B40: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D3B44: lw          $t7, -0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X4);
    // 0x800D3B48: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800D3B4C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D3B50: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800D3B54:
    // 0x800D3B54: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800D3B58: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800D3B5C: bne         $v0, $at, L_800D3B7C
    if (ctx->r2 != ctx->r1) {
        // 0x800D3B60: nop
    
            goto L_800D3B7C;
    }
    // 0x800D3B60: nop

    // 0x800D3B64: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800D3B68: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800D3B6C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800D3B70: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800D3B74: b           L_800D3B94
    // 0x800D3B78: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800D3B94;
    // 0x800D3B78: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800D3B7C:
    // 0x800D3B7C: bnel        $v0, $zero, L_800D3B98
    if (ctx->r2 != 0) {
        // 0x800D3B80: lw          $t7, 0x30($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X30);
            goto L_800D3B98;
    }
    goto skip_9;
    // 0x800D3B80: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    skip_9:
    // 0x800D3B84: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800D3B88: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800D3B8C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D3B90: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800D3B94:
    // 0x800D3B94: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
L_800D3B98:
    // 0x800D3B98: andi        $t6, $t7, 0x8
    ctx->r14 = ctx->r15 & 0X8;
    // 0x800D3B9C: beql        $t6, $zero, L_800D3BF0
    if (ctx->r14 == 0) {
        // 0x800D3BA0: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800D3BF0;
    }
    goto skip_10;
    // 0x800D3BA0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_10:
    // 0x800D3BA4: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800D3BA8: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x800D3BAC: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800D3BB0: addu        $t7, $a3, $t9
    ctx->r15 = ADD32(ctx->r7, ctx->r25);
    // 0x800D3BB4: sb          $t8, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r24;
    // 0x800D3BB8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D3BBC: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800D3BC0: beq         $v1, $at, L_800D3BD4
    if (ctx->r3 == ctx->r1) {
        // 0x800D3BC4: sw          $t9, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r25;
            goto L_800D3BD4;
    }
    // 0x800D3BC4: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800D3BC8: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x800D3BCC: bnel        $v1, $at, L_800D3BF0
    if (ctx->r3 != ctx->r1) {
        // 0x800D3BD0: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800D3BF0;
    }
    goto skip_11;
    // 0x800D3BD0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_11:
L_800D3BD4:
    // 0x800D3BD4: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800D3BD8: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800D3BDC: sb          $a1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r5;
    // 0x800D3BE0: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D3BE4: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800D3BE8: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800D3BEC: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_800D3BF0:
    // 0x800D3BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D3BF4: addu        $t7, $t8, $a3
    ctx->r15 = ADD32(ctx->r24, ctx->r7);
    // 0x800D3BF8: jal         0x800D6700
    // 0x800D3BFC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_1;
    // 0x800D3BFC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_1:
    // 0x800D3C00: b           L_800D3F04
    // 0x800D3C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D3F04;
    // 0x800D3C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3C08:
    // 0x800D3C08: lbu         $t6, 0x34($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X34);
    // 0x800D3C0C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x800D3C10: bnel        $t6, $at, L_800D3C78
    if (ctx->r14 != ctx->r1) {
        // 0x800D3C14: lw          $v0, 0x0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X0);
            goto L_800D3C78;
    }
    goto skip_12;
    // 0x800D3C14: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    skip_12:
    // 0x800D3C18: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800D3C1C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800D3C20: beq         $t9, $zero, L_800D3C38
    if (ctx->r25 == 0) {
        // 0x800D3C24: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D3C38;
    }
    // 0x800D3C24: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D3C28: addiu       $t8, $v1, 0x7
    ctx->r24 = ADD32(ctx->r3, 0X7);
    // 0x800D3C2C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800D3C30: b           L_800D3C68
    // 0x800D3C34: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
        goto L_800D3C68;
    // 0x800D3C34: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
L_800D3C38:
    // 0x800D3C38: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x800D3C3C: beq         $t7, $zero, L_800D3C54
    if (ctx->r15 == 0) {
        // 0x800D3C40: addiu       $t9, $v0, 0x7
        ctx->r25 = ADD32(ctx->r2, 0X7);
            goto L_800D3C54;
    }
    // 0x800D3C40: addiu       $t9, $v0, 0x7
    ctx->r25 = ADD32(ctx->r2, 0X7);
    // 0x800D3C44: addiu       $t6, $v1, 0xA
    ctx->r14 = ADD32(ctx->r3, 0XA);
    // 0x800D3C48: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D3C4C: b           L_800D3C64
    // 0x800D3C50: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
        goto L_800D3C64;
    // 0x800D3C50: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
L_800D3C54:
    // 0x800D3C54: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D3C58: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800D3C5C: addiu       $a0, $t8, 0x8
    ctx->r4 = ADD32(ctx->r24, 0X8);
    // 0x800D3C60: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_800D3C64:
    // 0x800D3C64: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D3C68:
    // 0x800D3C68: ldc1        $f4, -0x8($v0)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r2, -0X8);
    // 0x800D3C6C: b           L_800D3CCC
    // 0x800D3C70: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
        goto L_800D3CCC;
    // 0x800D3C70: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
    // 0x800D3C74: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_800D3C78:
    // 0x800D3C78: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800D3C7C: beq         $t6, $zero, L_800D3C94
    if (ctx->r14 == 0) {
        // 0x800D3C80: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D3C94;
    }
    // 0x800D3C80: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D3C84: addiu       $t9, $v1, 0x7
    ctx->r25 = ADD32(ctx->r3, 0X7);
    // 0x800D3C88: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D3C8C: b           L_800D3CC4
    // 0x800D3C90: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
        goto L_800D3CC4;
    // 0x800D3C90: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
L_800D3C94:
    // 0x800D3C94: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x800D3C98: beq         $t8, $zero, L_800D3CB0
    if (ctx->r24 == 0) {
        // 0x800D3C9C: addiu       $t6, $v0, 0x7
        ctx->r14 = ADD32(ctx->r2, 0X7);
            goto L_800D3CB0;
    }
    // 0x800D3C9C: addiu       $t6, $v0, 0x7
    ctx->r14 = ADD32(ctx->r2, 0X7);
    // 0x800D3CA0: addiu       $t7, $v1, 0xA
    ctx->r15 = ADD32(ctx->r3, 0XA);
    // 0x800D3CA4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D3CA8: b           L_800D3CC0
    // 0x800D3CAC: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
        goto L_800D3CC0;
    // 0x800D3CAC: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
L_800D3CB0:
    // 0x800D3CB0: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D3CB4: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x800D3CB8: addiu       $a0, $t9, 0x8
    ctx->r4 = ADD32(ctx->r25, 0X8);
    // 0x800D3CBC: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_800D3CC0:
    // 0x800D3CC0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D3CC4:
    // 0x800D3CC4: ldc1        $f6, -0x8($v0)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r2, -0X8);
    // 0x800D3CC8: sdc1        $f6, 0x0($s0)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X0, ctx->r16);
L_800D3CCC:
    // 0x800D3CCC: lhu         $t7, 0x0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X0);
    // 0x800D3CD0: andi        $t6, $t7, 0x8000
    ctx->r14 = ctx->r15 & 0X8000;
    // 0x800D3CD4: beql        $t6, $zero, L_800D3D00
    if (ctx->r14 == 0) {
        // 0x800D3CD8: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_800D3D00;
    }
    goto skip_13;
    // 0x800D3CD8: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_13:
    // 0x800D3CDC: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800D3CE0: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800D3CE4: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800D3CE8: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800D3CEC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D3CF0: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800D3CF4: b           L_800D3D50
    // 0x800D3CF8: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_800D3D50;
    // 0x800D3CF8: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
    // 0x800D3CFC: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_800D3D00:
    // 0x800D3D00: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x800D3D04: beq         $t9, $zero, L_800D3D2C
    if (ctx->r25 == 0) {
        // 0x800D3D08: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_800D3D2C;
    }
    // 0x800D3D08: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800D3D0C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D3D10: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x800D3D14: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x800D3D18: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800D3D1C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800D3D20: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800D3D24: b           L_800D3D50
    // 0x800D3D28: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_800D3D50;
    // 0x800D3D28: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_800D3D2C:
    // 0x800D3D2C: beql        $t7, $zero, L_800D3D54
    if (ctx->r15 == 0) {
        // 0x800D3D30: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800D3D54;
    }
    goto skip_14;
    // 0x800D3D30: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_14:
    // 0x800D3D34: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800D3D38: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800D3D3C: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x800D3D40: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800D3D44: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D3D48: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800D3D4C: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
L_800D3D50:
    // 0x800D3D50: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_800D3D54:
    // 0x800D3D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D3D58: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x800D3D5C: jal         0x800D6F10
    // 0x800D3D60: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Ldtob(rdram, ctx);
        goto after_2;
    // 0x800D3D60: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_2:
    // 0x800D3D64: b           L_800D3F04
    // 0x800D3D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D3F04;
    // 0x800D3D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3D6C:
    // 0x800D3D6C: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800D3D70: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800D3D74: bnel        $v0, $at, L_800D3DA8
    if (ctx->r2 != ctx->r1) {
        // 0x800D3D78: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_800D3DA8;
    }
    goto skip_15;
    // 0x800D3D78: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    skip_15:
    // 0x800D3D7C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800D3D80: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D3D84: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x800D3D88: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800D3D8C: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800D3D90: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D3D94: lw          $t9, -0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, -0X4);
    // 0x800D3D98: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800D3D9C: b           L_800D3F00
    // 0x800D3DA0: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
        goto L_800D3F00;
    // 0x800D3DA0: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x800D3DA4: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
L_800D3DA8:
    // 0x800D3DA8: bnel        $v0, $at, L_800D3DDC
    if (ctx->r2 != ctx->r1) {
        // 0x800D3DAC: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800D3DDC;
    }
    goto skip_16;
    // 0x800D3DAC: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_16:
    // 0x800D3DB0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800D3DB4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D3DB8: addiu       $t6, $t8, 0x3
    ctx->r14 = ADD32(ctx->r24, 0X3);
    // 0x800D3DBC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800D3DC0: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x800D3DC4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D3DC8: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x800D3DCC: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x800D3DD0: b           L_800D3F00
    // 0x800D3DD4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
        goto L_800D3F00;
    // 0x800D3DD4: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800D3DD8: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800D3DDC:
    // 0x800D3DDC: bnel        $v0, $at, L_800D3E18
    if (ctx->r2 != ctx->r1) {
        // 0x800D3DE0: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_800D3E18;
    }
    goto skip_17;
    // 0x800D3DE0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_17:
    // 0x800D3DE4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800D3DE8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D3DEC: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x800D3DF0: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800D3DF4: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800D3DF8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D3DFC: lw          $t6, -0x4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4);
    // 0x800D3E00: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800D3E04: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800D3E08: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800D3E0C: b           L_800D3F00
    // 0x800D3E10: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
        goto L_800D3F00;
    // 0x800D3E10: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800D3E14: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_800D3E18:
    // 0x800D3E18: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D3E1C: addiu       $t8, $t7, 0x3
    ctx->r24 = ADD32(ctx->r15, 0X3);
    // 0x800D3E20: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800D3E24: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800D3E28: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D3E2C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x800D3E30: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800D3E34: b           L_800D3F00
    // 0x800D3E38: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_800D3F00;
    // 0x800D3E38: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_800D3E3C:
    // 0x800D3E3C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800D3E40: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D3E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D3E48: addiu       $t6, $t9, 0x3
    ctx->r14 = ADD32(ctx->r25, 0X3);
    // 0x800D3E4C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800D3E50: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800D3E54: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800D3E58: lw          $t6, -0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X4);
    // 0x800D3E5C: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D3E60: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x800D3E64: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800D3E68: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800D3E6C: addu        $t6, $t7, $a3
    ctx->r14 = ADD32(ctx->r15, ctx->r7);
    // 0x800D3E70: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D3E74: jal         0x800D6700
    // 0x800D3E78: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Litob(rdram, ctx);
        goto after_3;
    // 0x800D3E78: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_3:
    // 0x800D3E7C: b           L_800D3F04
    // 0x800D3E80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D3F04;
    // 0x800D3E80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3E84:
    // 0x800D3E84: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800D3E88: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D3E8C: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x800D3E90: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800D3E94: addiu       $t6, $t7, 0x4
    ctx->r14 = ADD32(ctx->r15, 0X4);
    // 0x800D3E98: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D3E9C: lw          $a0, -0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, -0X4);
    // 0x800D3EA0: jal         0x800CE19C
    // 0x800D3EA4: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    strlen_recomp(rdram, ctx);
        goto after_4;
    // 0x800D3EA4: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    after_4:
    // 0x800D3EA8: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x800D3EAC: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800D3EB0: bltz        $v1, L_800D3F00
    if (SIGNED(ctx->r3) < 0) {
        // 0x800D3EB4: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800D3F00;
    }
    // 0x800D3EB4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D3EB8: beql        $at, $zero, L_800D3F04
    if (ctx->r1 == 0) {
        // 0x800D3EBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3F04;
    }
    goto skip_18;
    // 0x800D3EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_18:
    // 0x800D3EC0: b           L_800D3F00
    // 0x800D3EC4: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
        goto L_800D3F00;
    // 0x800D3EC4: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x800D3EC8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_800D3ECC:
    // 0x800D3ECC: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x800D3ED0: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x800D3ED4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800D3ED8: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D3EDC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800D3EE0: b           L_800D3F00
    // 0x800D3EE4: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_800D3F00;
    // 0x800D3EE4: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800D3EE8:
    // 0x800D3EE8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_800D3EEC:
    // 0x800D3EEC: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x800D3EF0: sb          $a1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r5;
    // 0x800D3EF4: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D3EF8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800D3EFC: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800D3F00:
    // 0x800D3F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3F04:
    // 0x800D3F04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3F08: jr          $ra
    // 0x800D3F0C: nop

    return;
    // 0x800D3F0C: nop

;}
RECOMP_FUNC void static_3_800D69A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D69A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D69A4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800D69A8: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800D69AC: sra         $s2, $t6, 16
    ctx->r18 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D69B0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D69B4: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800D69B8: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D69BC: andi        $t6, $s4, 0xFF
    ctx->r14 = ctx->r20 & 0XFF;
    // 0x800D69C0: sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    // 0x800D69C4: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x800D69C8: bgtz        $s3, L_800D69DC
    if (SIGNED(ctx->r19) > 0) {
        // 0x800D69CC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800D69DC;
    }
    // 0x800D69CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D69D0: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800D69D4: addiu       $s1, $s1, -0x6750
    ctx->r17 = ADD32(ctx->r17, -0X6750);
    // 0x800D69D8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800D69DC:
    // 0x800D69DC: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x800D69E0: beq         $v0, $s4, L_800D6A14
    if (ctx->r2 == ctx->r20) {
        // 0x800D69E4: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_800D6A14;
    }
    // 0x800D69E4: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x800D69E8: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x800D69EC: beq         $a0, $v1, L_800D69F8
    if (ctx->r4 == ctx->r3) {
        // 0x800D69F0: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_800D69F8;
    }
    // 0x800D69F0: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800D69F4: bne         $v1, $at, L_800D6C50
    if (ctx->r3 != ctx->r1) {
        // 0x800D69F8: slti        $at, $s2, -0x4
        ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
            goto L_800D6C50;
    }
L_800D69F8:
    // 0x800D69F8: slti        $at, $s2, -0x4
    ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
    // 0x800D69FC: bne         $at, $zero, L_800D6C50
    if (ctx->r1 != 0) {
        // 0x800D6A00: nop
    
            goto L_800D6C50;
    }
    // 0x800D6A00: nop

    // 0x800D6A04: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800D6A08: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D6A0C: beq         $at, $zero, L_800D6C50
    if (ctx->r1 == 0) {
        // 0x800D6A10: nop
    
            goto L_800D6C50;
    }
    // 0x800D6A10: nop

L_800D6A14:
    // 0x800D6A14: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D6A18: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x800D6A1C: beq         $v0, $v1, L_800D6A58
    if (ctx->r2 == ctx->r3) {
        // 0x800D6A20: sra         $s2, $t8, 16
        ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
            goto L_800D6A58;
    }
    // 0x800D6A20: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D6A24: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x800D6A28: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D6A2C: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x800D6A30: bne         $t7, $zero, L_800D6A48
    if (ctx->r15 != 0) {
        // 0x800D6A34: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800D6A48;
    }
    // 0x800D6A34: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D6A38: beql        $at, $zero, L_800D6A4C
    if (ctx->r1 == 0) {
        // 0x800D6A3C: subu        $t8, $v0, $s2
        ctx->r24 = SUB32(ctx->r2, ctx->r18);
            goto L_800D6A4C;
    }
    goto skip_0;
    // 0x800D6A3C: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
    skip_0:
    // 0x800D6A40: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x800D6A44: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_800D6A48:
    // 0x800D6A48: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
L_800D6A4C:
    // 0x800D6A4C: bgez        $t8, L_800D6A58
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D6A50: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_800D6A58;
    }
    // 0x800D6A50: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x800D6A54: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_800D6A58:
    // 0x800D6A58: bgtz        $s2, L_800D6B28
    if (SIGNED(ctx->r18) > 0) {
        // 0x800D6A5C: slt         $at, $s3, $s2
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_800D6B28;
    }
    // 0x800D6A5C: slt         $at, $s3, $s2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800D6A60: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800D6A64: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D6A68: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800D6A6C: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x800D6A70: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800D6A74: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800D6A78: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D6A7C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D6A80: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D6A84: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800D6A88: bgtz        $v0, L_800D6AA0
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D6A8C: sw          $t8, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r24;
            goto L_800D6AA0;
    }
    // 0x800D6A8C: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x800D6A90: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x800D6A94: andi        $t9, $t6, 0x8
    ctx->r25 = ctx->r14 & 0X8;
    // 0x800D6A98: beql        $t9, $zero, L_800D6AC8
    if (ctx->r25 == 0) {
        // 0x800D6A9C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800D6AC8;
    }
    goto skip_1;
    // 0x800D6A9C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
L_800D6AA0:
    // 0x800D6AA0: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800D6AA4: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x800D6AA8: addiu       $t7, $zero, 0x2E
    ctx->r15 = ADD32(0, 0X2E);
    // 0x800D6AAC: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x800D6AB0: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
    // 0x800D6AB4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D6AB8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D6ABC: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800D6AC0: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800D6AC4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_800D6AC8:
    // 0x800D6AC8: beql        $at, $zero, L_800D6AE4
    if (ctx->r1 == 0) {
        // 0x800D6ACC: addu        $t8, $v0, $s2
        ctx->r24 = ADD32(ctx->r2, ctx->r18);
            goto L_800D6AE4;
    }
    goto skip_2;
    // 0x800D6ACC: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
    skip_2:
    // 0x800D6AD0: negu        $s2, $v0
    ctx->r18 = SUB32(0, ctx->r2);
    // 0x800D6AD4: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x800D6AD8: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800D6ADC: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x800D6AE0: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
L_800D6AE4:
    // 0x800D6AE4: slt         $at, $t8, $s3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800D6AE8: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x800D6AEC: beq         $at, $zero, L_800D6B00
    if (ctx->r1 == 0) {
        // 0x800D6AF0: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_800D6B00;
    }
    // 0x800D6AF0: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x800D6AF4: sll         $s3, $t8, 16
    ctx->r19 = S32(ctx->r24 << 16);
    // 0x800D6AF8: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800D6AFC: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800D6B00:
    // 0x800D6B00: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800D6B04: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800D6B08: sw          $s3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r19;
    // 0x800D6B0C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800D6B10: jal         0x800CE170
    // 0x800D6B14: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x800D6B14: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x800D6B18: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x800D6B1C: subu        $t6, $t8, $s3
    ctx->r14 = SUB32(ctx->r24, ctx->r19);
    // 0x800D6B20: b           L_800D6EAC
    // 0x800D6B24: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
        goto L_800D6EAC;
    // 0x800D6B24: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
L_800D6B28:
    // 0x800D6B28: beq         $at, $zero, L_800D6BA0
    if (ctx->r1 == 0) {
        // 0x800D6B2C: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800D6BA0;
    }
    // 0x800D6B2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D6B30: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800D6B34: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800D6B38: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D6B3C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800D6B40: jal         0x800CE170
    // 0x800D6B44: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x800D6B44: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_1:
    // 0x800D6B48: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D6B4C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D6B50: subu        $t7, $s2, $s3
    ctx->r15 = SUB32(ctx->r18, ctx->r19);
    // 0x800D6B54: addu        $t6, $t8, $s3
    ctx->r14 = ADD32(ctx->r24, ctx->r19);
    // 0x800D6B58: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800D6B5C: bgtz        $v0, L_800D6B74
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D6B60: sw          $t7, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r15;
            goto L_800D6B74;
    }
    // 0x800D6B60: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x800D6B64: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800D6B68: andi        $t8, $t9, 0x8
    ctx->r24 = ctx->r25 & 0X8;
    // 0x800D6B6C: beq         $t8, $zero, L_800D6B98
    if (ctx->r24 == 0) {
        // 0x800D6B70: nop
    
            goto L_800D6B98;
    }
    // 0x800D6B70: nop

L_800D6B74:
    // 0x800D6B74: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800D6B78: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800D6B7C: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800D6B80: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800D6B84: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x800D6B88: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x800D6B8C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D6B90: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800D6B94: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_800D6B98:
    // 0x800D6B98: b           L_800D6EAC
    // 0x800D6B9C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
        goto L_800D6EAC;
    // 0x800D6B9C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
L_800D6BA0:
    // 0x800D6BA0: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x800D6BA4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D6BA8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800D6BAC: jal         0x800CE170
    // 0x800D6BB0: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_2;
    // 0x800D6BB0: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    after_2:
    // 0x800D6BB4: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D6BB8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D6BBC: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x800D6BC0: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800D6BC4: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x800D6BC8: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
    // 0x800D6BCC: bgtz        $v0, L_800D6BE4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D6BD0: sra         $s3, $t6, 16
        ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
            goto L_800D6BE4;
    }
    // 0x800D6BD0: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D6BD4: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x800D6BD8: andi        $t9, $t7, 0x8
    ctx->r25 = ctx->r15 & 0X8;
    // 0x800D6BDC: beql        $t9, $zero, L_800D6C0C
    if (ctx->r25 == 0) {
        // 0x800D6BE0: slt         $at, $v0, $s3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_800D6C0C;
    }
    goto skip_3;
    // 0x800D6BE0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    skip_3:
L_800D6BE4:
    // 0x800D6BE4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800D6BE8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D6BEC: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800D6BF0: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800D6BF4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800D6BF8: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D6BFC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D6C00: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800D6C04: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800D6C08: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
L_800D6C0C:
    // 0x800D6C0C: beq         $at, $zero, L_800D6C20
    if (ctx->r1 == 0) {
        // 0x800D6C10: addu        $a1, $s2, $s1
        ctx->r5 = ADD32(ctx->r18, ctx->r17);
            goto L_800D6C20;
    }
    // 0x800D6C10: addu        $a1, $s2, $s1
    ctx->r5 = ADD32(ctx->r18, ctx->r17);
    // 0x800D6C14: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800D6C18: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800D6C1C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800D6C20:
    // 0x800D6C20: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800D6C24: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D6C28: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800D6C2C: jal         0x800CE170
    // 0x800D6C30: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x800D6C30: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_3:
    // 0x800D6C34: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D6C38: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800D6C3C: addu        $t6, $t7, $s3
    ctx->r14 = ADD32(ctx->r15, ctx->r19);
    // 0x800D6C40: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x800D6C44: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800D6C48: b           L_800D6EAC
    // 0x800D6C4C: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
        goto L_800D6EAC;
    // 0x800D6C4C: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
L_800D6C50:
    // 0x800D6C50: beq         $a0, $v1, L_800D6C60
    if (ctx->r4 == ctx->r3) {
        // 0x800D6C54: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_800D6C60;
    }
    // 0x800D6C54: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800D6C58: bnel        $v1, $at, L_800D6CA0
    if (ctx->r3 != ctx->r1) {
        // 0x800D6C5C: lw          $t8, 0x8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X8);
            goto L_800D6CA0;
    }
    goto skip_4;
    // 0x800D6C5C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    skip_4:
L_800D6C60:
    // 0x800D6C60: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D6C64: addiu       $s4, $zero, 0x45
    ctx->r20 = ADD32(0, 0X45);
    // 0x800D6C68: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D6C6C: beql        $at, $zero, L_800D6C80
    if (ctx->r1 == 0) {
        // 0x800D6C70: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800D6C80;
    }
    goto skip_5;
    // 0x800D6C70: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    skip_5:
    // 0x800D6C74: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x800D6C78: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800D6C7C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_800D6C80:
    // 0x800D6C80: bgez        $t7, L_800D6C8C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800D6C84: sw          $t7, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r15;
            goto L_800D6C8C;
    }
    // 0x800D6C84: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x800D6C88: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_800D6C8C:
    // 0x800D6C8C: bne         $a0, $v1, L_800D6C9C
    if (ctx->r4 != ctx->r3) {
        // 0x800D6C90: nop
    
            goto L_800D6C9C;
    }
    // 0x800D6C90: nop

    // 0x800D6C94: b           L_800D6C9C
    // 0x800D6C98: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
        goto L_800D6C9C;
    // 0x800D6C98: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
L_800D6C9C:
    // 0x800D6C9C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
L_800D6CA0:
    // 0x800D6CA0: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D6CA4: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x800D6CA8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D6CAC: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x800D6CB0: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x800D6CB4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D6CB8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D6CBC: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800D6CC0: bgtz        $v0, L_800D6CD8
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D6CC4: sw          $t7, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r15;
            goto L_800D6CD8;
    }
    // 0x800D6CC4: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800D6CC8: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800D6CCC: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x800D6CD0: beq         $t6, $zero, L_800D6CFC
    if (ctx->r14 == 0) {
        // 0x800D6CD4: nop
    
            goto L_800D6CFC;
    }
    // 0x800D6CD4: nop

L_800D6CD8:
    // 0x800D6CD8: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800D6CDC: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800D6CE0: addiu       $t8, $zero, 0x2E
    ctx->r24 = ADD32(0, 0X2E);
    // 0x800D6CE4: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800D6CE8: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800D6CEC: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D6CF0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D6CF4: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800D6CF8: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
L_800D6CFC:
    // 0x800D6CFC: blezl       $v0, L_800D6D58
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D6D00: lw          $t6, 0x8($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8);
            goto L_800D6D58;
    }
    goto skip_6;
    // 0x800D6D00: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    skip_6:
    // 0x800D6D04: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800D6D08: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800D6D0C: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D6D10: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800D6D14: beq         $at, $zero, L_800D6D28
    if (ctx->r1 == 0) {
        // 0x800D6D18: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800D6D28;
    }
    // 0x800D6D18: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D6D1C: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800D6D20: sra         $t7, $s3, 16
    ctx->r15 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800D6D24: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
L_800D6D28:
    // 0x800D6D28: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800D6D2C: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D6D30: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800D6D34: jal         0x800CE170
    // 0x800D6D38: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_4;
    // 0x800D6D38: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_4:
    // 0x800D6D3C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x800D6D40: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800D6D44: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x800D6D48: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x800D6D4C: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800D6D50: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x800D6D54: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
L_800D6D58:
    // 0x800D6D58: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D6D5C: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x800D6D60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D6D64: bltz        $s2, L_800D6D7C
    if (SIGNED(ctx->r18) < 0) {
        // 0x800D6D68: sb          $s4, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r20;
            goto L_800D6D7C;
    }
    // 0x800D6D68: sb          $s4, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r20;
    // 0x800D6D6C: addiu       $t9, $zero, 0x2B
    ctx->r25 = ADD32(0, 0X2B);
    // 0x800D6D70: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x800D6D74: b           L_800D6D98
    // 0x800D6D78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800D6D98;
    // 0x800D6D78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800D6D7C:
    // 0x800D6D7C: negu        $s2, $s2
    ctx->r18 = SUB32(0, ctx->r18);
    // 0x800D6D80: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800D6D84: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x800D6D88: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D6D8C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800D6D90: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D6D94: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_800D6D98:
    // 0x800D6D98: slti        $at, $s2, 0x64
    ctx->r1 = SIGNED(ctx->r18) < 0X64 ? 1 : 0;
    // 0x800D6D9C: bnel        $at, $zero, L_800D6E48
    if (ctx->r1 != 0) {
        // 0x800D6DA0: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_800D6E48;
    }
    goto skip_7;
    // 0x800D6DA0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    skip_7:
    // 0x800D6DA4: slti        $at, $s2, 0x3E8
    ctx->r1 = SIGNED(ctx->r18) < 0X3E8 ? 1 : 0;
    // 0x800D6DA8: bne         $at, $zero, L_800D6DF8
    if (ctx->r1 != 0) {
        // 0x800D6DAC: addiu       $v0, $zero, 0x3E8
        ctx->r2 = ADD32(0, 0X3E8);
            goto L_800D6DF8;
    }
    // 0x800D6DAC: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x800D6DB0: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800D6DB4: bne         $v0, $zero, L_800D6DC0
    if (ctx->r2 != 0) {
        // 0x800D6DB8: nop
    
            goto L_800D6DC0;
    }
    // 0x800D6DB8: nop

    // 0x800D6DBC: break       7
    do_break(2148363708);
L_800D6DC0:
    // 0x800D6DC0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D6DC4: bne         $v0, $at, L_800D6DD8
    if (ctx->r2 != ctx->r1) {
        // 0x800D6DC8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D6DD8;
    }
    // 0x800D6DC8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D6DCC: bne         $s2, $at, L_800D6DD8
    if (ctx->r18 != ctx->r1) {
        // 0x800D6DD0: nop
    
            goto L_800D6DD8;
    }
    // 0x800D6DD0: nop

    // 0x800D6DD4: break       6
    do_break(2148363732);
L_800D6DD8:
    // 0x800D6DD8: mfhi        $s2
    ctx->r18 = hi;
    // 0x800D6DDC: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800D6DE0: mflo        $t9
    ctx->r25 = lo;
    // 0x800D6DE4: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800D6DE8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D6DEC: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800D6DF0: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800D6DF4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800D6DF8:
    // 0x800D6DF8: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x800D6DFC: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800D6E00: bne         $v0, $zero, L_800D6E0C
    if (ctx->r2 != 0) {
        // 0x800D6E04: nop
    
            goto L_800D6E0C;
    }
    // 0x800D6E04: nop

    // 0x800D6E08: break       7
    do_break(2148363784);
L_800D6E0C:
    // 0x800D6E0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D6E10: bne         $v0, $at, L_800D6E24
    if (ctx->r2 != ctx->r1) {
        // 0x800D6E14: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D6E24;
    }
    // 0x800D6E14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D6E18: bne         $s2, $at, L_800D6E24
    if (ctx->r18 != ctx->r1) {
        // 0x800D6E1C: nop
    
            goto L_800D6E24;
    }
    // 0x800D6E1C: nop

    // 0x800D6E20: break       6
    do_break(2148363808);
L_800D6E24:
    // 0x800D6E24: mfhi        $s2
    ctx->r18 = hi;
    // 0x800D6E28: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800D6E2C: mflo        $t9
    ctx->r25 = lo;
    // 0x800D6E30: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800D6E34: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D6E38: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800D6E3C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800D6E40: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D6E44: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800D6E48:
    // 0x800D6E48: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800D6E4C: bne         $v0, $zero, L_800D6E58
    if (ctx->r2 != 0) {
        // 0x800D6E50: nop
    
            goto L_800D6E58;
    }
    // 0x800D6E50: nop

    // 0x800D6E54: break       7
    do_break(2148363860);
L_800D6E58:
    // 0x800D6E58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D6E5C: bne         $v0, $at, L_800D6E70
    if (ctx->r2 != ctx->r1) {
        // 0x800D6E60: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D6E70;
    }
    // 0x800D6E60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D6E64: bne         $s2, $at, L_800D6E70
    if (ctx->r18 != ctx->r1) {
        // 0x800D6E68: nop
    
            goto L_800D6E70;
    }
    // 0x800D6E68: nop

    // 0x800D6E6C: break       6
    do_break(2148363884);
L_800D6E70:
    // 0x800D6E70: mfhi        $s2
    ctx->r18 = hi;
    // 0x800D6E74: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800D6E78: mflo        $t9
    ctx->r25 = lo;
    // 0x800D6E7C: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800D6E80: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D6E84: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x800D6E88: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800D6E8C: sb          $t9, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r25;
    // 0x800D6E90: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800D6E94: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800D6E98: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D6E9C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800D6EA0: subu        $t6, $s1, $t8
    ctx->r14 = SUB32(ctx->r17, ctx->r24);
    // 0x800D6EA4: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x800D6EA8: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_800D6EAC:
    // 0x800D6EAC: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x800D6EB0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800D6EB4: andi        $t6, $t8, 0x14
    ctx->r14 = ctx->r24 & 0X14;
    // 0x800D6EB8: bnel        $t6, $at, L_800D6EFC
    if (ctx->r14 != ctx->r1) {
        // 0x800D6EBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D6EFC;
    }
    goto skip_8;
    // 0x800D6EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x800D6EC0: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D6EC4: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800D6EC8: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x800D6ECC: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x800D6ED0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800D6ED4: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x800D6ED8: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800D6EDC: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x800D6EE0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800D6EE4: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x800D6EE8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800D6EEC: beq         $at, $zero, L_800D6EF8
    if (ctx->r1 == 0) {
        // 0x800D6EF0: subu        $t7, $v1, $v0
        ctx->r15 = SUB32(ctx->r3, ctx->r2);
            goto L_800D6EF8;
    }
    // 0x800D6EF0: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x800D6EF4: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
L_800D6EF8:
    // 0x800D6EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D6EFC:
    // 0x800D6EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D6F00: jr          $ra
    // 0x800D6F04: nop

    return;
    // 0x800D6F04: nop

    // 0x800D6F08: jr          $ra
    // 0x800D6F0C: nop

    return;
    // 0x800D6F0C: nop

;}
RECOMP_FUNC void static_3_80063A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063A34: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80063A38: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80063A3C: beq         $v0, $zero, L_80063A7C
    if (ctx->r2 == 0) {
        // 0x80063A40: addiu       $t8, $zero, 0x1E8
        ctx->r24 = ADD32(0, 0X1E8);
            goto L_80063A7C;
    }
    // 0x80063A40: addiu       $t8, $zero, 0x1E8
    ctx->r24 = ADD32(0, 0X1E8);
    // 0x80063A44: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80063A48: nop

    // 0x80063A4C: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80063A50: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80063A54: nop

    // 0x80063A58: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80063A5C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80063A60: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80063A64: nop

    // 0x80063A68: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80063A6C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80063A70: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80063A74: jr          $ra
    // 0x80063A78: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    return;
    // 0x80063A78: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
L_80063A7C:
    // 0x80063A7C: sw          $t8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r24;
    // 0x80063A80: jr          $ra
    // 0x80063A84: nop

    return;
    // 0x80063A84: nop

    // 0x80063A88: nop

    // 0x80063A8C: nop

;}
RECOMP_FUNC void static_3_80063984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063984: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80063988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006398C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80063990: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80063994: jal         0x800C9A30
    // 0x80063998: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80063998: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8006399C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800639A0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800639A4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800639A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800639AC: beq         $v1, $at, L_80063A18
    if (ctx->r3 == ctx->r1) {
        // 0x800639B0: addiu       $a1, $v1, 0x8
        ctx->r5 = ADD32(ctx->r3, 0X8);
            goto L_80063A18;
    }
    // 0x800639B0: addiu       $a1, $v1, 0x8
    ctx->r5 = ADD32(ctx->r3, 0X8);
L_800639B4:
    // 0x800639B4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800639B8: nop

    // 0x800639BC: bne         $a0, $zero, L_800639D4
    if (ctx->r4 != 0) {
        // 0x800639C0: nop
    
            goto L_800639D4;
    }
    // 0x800639C0: nop

    // 0x800639C4: jal         0x800C8790
    // 0x800639C8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    alLink(rdram, ctx);
        goto after_1;
    // 0x800639C8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x800639CC: b           L_80063A1C
    // 0x800639D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_80063A1C;
    // 0x800639D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800639D4:
    // 0x800639D4: lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X8);
    // 0x800639D8: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800639DC: nop

    // 0x800639E0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800639E4: beq         $at, $zero, L_80063A04
    if (ctx->r1 == 0) {
        // 0x800639E8: subu        $t7, $v0, $v1
        ctx->r15 = SUB32(ctx->r2, ctx->r3);
            goto L_80063A04;
    }
    // 0x800639E8: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
    // 0x800639EC: subu        $t6, $v1, $v0
    ctx->r14 = SUB32(ctx->r3, ctx->r2);
    // 0x800639F0: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x800639F4: jal         0x800C8790
    // 0x800639F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800639F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x800639FC: b           L_80063A1C
    // 0x80063A00: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_80063A1C;
    // 0x80063A00: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80063A04:
    // 0x80063A04: sw          $t7, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r15;
    // 0x80063A08: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x80063A0C: nop

    // 0x80063A10: bne         $a1, $zero, L_800639B4
    if (ctx->r5 != 0) {
        // 0x80063A14: nop
    
            goto L_800639B4;
    }
    // 0x80063A14: nop

L_80063A18:
    // 0x80063A18: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80063A1C:
    // 0x80063A1C: jal         0x800C9A30
    // 0x80063A20: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x80063A20: nop

    after_3:
    // 0x80063A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063A28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80063A2C: jr          $ra
    // 0x80063A30: nop

    return;
    // 0x80063A30: nop

;}
RECOMP_FUNC void static_3_800CB2D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB2D4: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800CB2D8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800CB2DC: nop

    // 0x800CB2E0: bne         $t6, $zero, L_800CB328
    if (ctx->r14 != 0) {
        // 0x800CB2E4: nop
    
            goto L_800CB328;
    }
    // 0x800CB2E4: nop

    // 0x800CB2E8: c.le.d      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.d <= ctx->f14.d;
    // 0x800CB2EC: nop

    // 0x800CB2F0: bc1f        L_800CB314
    if (!c1cs) {
        // 0x800CB2F4: nop
    
            goto L_800CB314;
    }
    // 0x800CB2F4: nop

    // 0x800CB2F8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800CB2FC: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x800CB300: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800CB304: b           L_800CB490
    // 0x800CB308: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
        goto L_800CB490;
    // 0x800CB308: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
    // 0x800CB30C: b           L_800CB328
    // 0x800CB310: nop

        goto L_800CB328;
    // 0x800CB310: nop

L_800CB314:
    // 0x800CB314: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800CB318: nop

    // 0x800CB31C: sh          $zero, 0x0($t9)
    MEM_H(0X0, ctx->r25) = 0;
    // 0x800CB320: b           L_800CB490
    // 0x800CB324: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
        goto L_800CB490;
    // 0x800CB324: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
L_800CB328:
    // 0x800CB328: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800CB32C: sub.d       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f14.d - ctx->f12.d;
    // 0x800CB330: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800CB334: nop

    // 0x800CB338: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CB33C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800CB340: nop

    // 0x800CB344: div.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800CB348: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
    // 0x800CB34C: swc1        $f17, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f_odd[(17 - 1) * 2];
    // 0x800CB350: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800CB354: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800CB358: lwc1        $f19, 0x0($sp)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB35C: lwc1        $f18, 0x4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB360: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CB364: nop

    // 0x800CB368: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x800CB36C: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x800CB370: swc1        $f9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x800CB374: lwc1        $f5, 0x0($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB378: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB37C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x800CB380: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800CB384: nop

    // 0x800CB388: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x800CB38C: nop

    // 0x800CB390: bc1f        L_800CB3BC
    if (!c1cs) {
        // 0x800CB394: nop
    
            goto L_800CB3BC;
    }
    // 0x800CB394: nop

    // 0x800CB398: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800CB39C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800CB3A0: lwc1        $f17, 0x0($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB3A4: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB3A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800CB3AC: nop

    // 0x800CB3B0: sub.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f16.d - ctx->f18.d;
    // 0x800CB3B4: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x800CB3B8: swc1        $f7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
L_800CB3BC:
    // 0x800CB3BC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800CB3C0: lwc1        $f9, 0x0($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB3C4: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800CB3C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800CB3CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800CB3D0: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB3D4: nop

    // 0x800CB3D8: cvt.w.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_D(ctx->f8.d);
    // 0x800CB3DC: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800CB3E0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800CB3E4: sh          $t2, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r10;
    // 0x800CB3E8: nop

    // 0x800CB3EC: lh          $t3, 0xE($sp)
    ctx->r11 = MEM_H(ctx->r29, 0XE);
    // 0x800CB3F0: lwc1        $f11, 0x0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB3F4: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800CB3F8: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB3FC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800CB400: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB404: lwc1        $f5, -0x6A08($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X6A08);
    // 0x800CB408: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x800CB40C: lwc1        $f4, -0x6A04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6A04);
    // 0x800CB410: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x800CB414: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800CB418: mul.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x800CB41C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800CB420: nop

    // 0x800CB424: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800CB428: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800CB42C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800CB430: nop

    // 0x800CB434: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x800CB438: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x800CB43C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800CB440: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800CB444: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CB448: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800CB44C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800CB450: lwc1        $f11, 0x0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB454: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800CB458: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800CB45C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800CB460: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB464: nop

    // 0x800CB468: cvt.w.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_D(ctx->f10.d);
    // 0x800CB46C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800CB470: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800CB474: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x800CB478: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800CB47C: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800CB480: b           L_800CB490
    // 0x800CB484: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800CB490;
    // 0x800CB484: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800CB488: b           L_800CB490
    // 0x800CB48C: nop

        goto L_800CB490;
    // 0x800CB48C: nop

L_800CB490:
    // 0x800CB490: jr          $ra
    // 0x800CB494: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800CB494: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
