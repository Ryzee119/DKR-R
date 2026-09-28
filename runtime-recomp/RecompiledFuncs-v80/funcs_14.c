#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8007AB24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AB24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007AB28: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8007AB2C: jr          $ra
    // 0x8007AB30: sb          $a0, 0x62E4($at)
    MEM_B(0X62E4, ctx->r1) = ctx->r4;
    return;
    // 0x8007AB30: sb          $a0, 0x62E4($at)
    MEM_B(0X62E4, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void viewport_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066CDC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80066CE0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80066CE4: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80066CE8: addiu       $ra, $ra, 0xCE4
    ctx->r31 = ADD32(ctx->r31, 0XCE4);
    // 0x80066CEC: lw          $v0, 0x0($ra)
    ctx->r2 = MEM_W(ctx->r31, 0X0);
    // 0x80066CF0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80066CF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80066CF8: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80066CFC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80066D00: jal         0x8000E184
    // 0x80066D04: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    is_player_two_in_control(rdram, ctx);
        goto after_0;
    // 0x80066D04: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_0:
    // 0x80066D08: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80066D0C: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80066D10: beq         $v0, $zero, L_80066D34
    if (ctx->r2 == 0) {
        // 0x80066D14: addiu       $ra, $ra, 0xCE4
        ctx->r31 = ADD32(ctx->r31, 0XCE4);
            goto L_80066D34;
    }
    // 0x80066D14: addiu       $ra, $ra, 0xCE4
    ctx->r31 = ADD32(ctx->r31, 0XCE4);
    // 0x80066D18: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80066D1C: lw          $t6, 0xCE0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE0);
    // 0x80066D20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80066D24: bne         $t6, $zero, L_80066D34
    if (ctx->r14 != 0) {
        // 0x80066D28: nop
    
            goto L_80066D34;
    }
    // 0x80066D28: nop

    // 0x80066D2C: sw          $t7, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r15;
    // 0x80066D30: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80066D34:
    // 0x80066D34: jal         0x8007A520
    // 0x80066D38: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    fb_size(rdram, ctx);
        goto after_1;
    // 0x80066D38: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    after_1:
    // 0x80066D3C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80066D40: addiu       $t3, $zero, 0x34
    ctx->r11 = ADD32(0, 0X34);
    // 0x80066D44: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066D48: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80066D4C: addiu       $t2, $t2, -0x2F9C
    ctx->r10 = ADD32(ctx->r10, -0X2F9C);
    // 0x80066D50: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80066D54: srl         $t0, $v0, 16
    ctx->r8 = S32(U32(ctx->r2) >> 16);
    // 0x80066D58: addiu       $ra, $ra, 0xCE4
    ctx->r31 = ADD32(ctx->r31, 0XCE4);
    // 0x80066D5C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80066D60: srl         $a3, $t0, 1
    ctx->r7 = S32(U32(ctx->r8) >> 1);
    // 0x80066D64: mflo        $t8
    ctx->r24 = lo;
    // 0x80066D68: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80066D6C: lw          $t6, 0x30($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X30);
    // 0x80066D70: nop

    // 0x80066D74: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80066D78: beq         $t7, $zero, L_80066F0C
    if (ctx->r15 == 0) {
        // 0x80066D7C: nop
    
            goto L_80066F0C;
    }
    // 0x80066D7C: nop

    // 0x80066D80: lw          $t8, 0x0($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X0);
    // 0x80066D84: sw          $t1, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r9;
    // 0x80066D88: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80066D8C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80066D90: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80066D94: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80066D98: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80066D9C: lw          $t6, 0x0($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X0);
    // 0x80066DA0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80066DA4: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066DAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80066DB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80066DB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80066DB8: mflo        $t7
    ctx->r15 = lo;
    // 0x80066DBC: addu        $v1, $t2, $t7
    ctx->r3 = ADD32(ctx->r10, ctx->r15);
    // 0x80066DC0: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x80066DC4: nop

    // 0x80066DC8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80066DCC: nop

    // 0x80066DD0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80066DD4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80066DD8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80066DDC: nop

    // 0x80066DE0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80066DE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80066DE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80066DEC: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80066DF0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80066DF4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80066DF8: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x80066DFC: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80066E00: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80066E04: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80066E08: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80066E0C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80066E10: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80066E14: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80066E18: nop

    // 0x80066E1C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80066E20: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80066E24: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80066E28: nop

    // 0x80066E2C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80066E30: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80066E34: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80066E38: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80066E3C: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80066E40: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80066E44: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80066E48: lw          $t9, 0x0($ra)
    ctx->r25 = MEM_W(ctx->r31, 0X0);
    // 0x80066E4C: nop

    // 0x80066E50: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80066E54: mflo        $t8
    ctx->r24 = lo;
    // 0x80066E58: addu        $v1, $t2, $t8
    ctx->r3 = ADD32(ctx->r10, ctx->r24);
    // 0x80066E5C: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x80066E60: nop

    // 0x80066E64: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80066E68: lw          $t6, 0x28($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X28);
    // 0x80066E6C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80066E70: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80066E74: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80066E78: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80066E7C: nop

    // 0x80066E80: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80066E84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80066E88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80066E8C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80066E90: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80066E94: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80066E98: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80066E9C: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80066EA0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80066EA4: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80066EA8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80066EAC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80066EB0: nop

    // 0x80066EB4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80066EB8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80066EBC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80066EC0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80066EC4: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80066EC8: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80066ECC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80066ED0: jal         0x80068158
    // 0x80066ED4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    viewport_rsp_set(rdram, ctx);
        goto after_2;
    // 0x80066ED4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80066ED8: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80066EDC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80066EE0: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80066EE4: addiu       $ra, $ra, 0xCE4
    ctx->r31 = ADD32(ctx->r31, 0XCE4);
    // 0x80066EE8: beq         $a1, $zero, L_80066F00
    if (ctx->r5 == 0) {
        // 0x80066EEC: sw          $t6, 0x0($ra)
        MEM_W(0X0, ctx->r31) = ctx->r14;
            goto L_80066F00;
    }
    // 0x80066EEC: sw          $t6, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r14;
    // 0x80066EF0: jal         0x80067D3C
    // 0x80066EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80067D3C(rdram, ctx);
        goto after_3;
    // 0x80066EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80066EF8: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80066EFC: addiu       $ra, $ra, 0xCE4
    ctx->r31 = ADD32(ctx->r31, 0XCE4);
L_80066F00:
    // 0x80066F00: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80066F04: b           L_80067A2C
    // 0x80066F08: sw          $t8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r24;
        goto L_80067A2C;
    // 0x80066F08: sw          $t8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r24;
L_80066F0C:
    // 0x80066F0C: lw          $v1, 0xCE0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XCE0);
    // 0x80066F10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80066F14: bne         $v1, $a0, L_80066F20
    if (ctx->r3 != ctx->r4) {
        // 0x80066F18: andi        $t1, $v0, 0xFFFF
        ctx->r9 = ctx->r2 & 0XFFFF;
            goto L_80066F20;
    }
    // 0x80066F18: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x80066F1C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80066F20:
    // 0x80066F20: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80066F24: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80066F28: srl         $a2, $t1, 1
    ctx->r6 = S32(U32(ctx->r9) >> 1);
    // 0x80066F2C: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x80066F30: bne         $t2, $zero, L_80066F40
    if (ctx->r10 != 0) {
        // 0x80066F34: sw          $a3, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r7;
            goto L_80066F40;
    }
    // 0x80066F34: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    // 0x80066F38: addiu       $t7, $zero, 0x91
    ctx->r15 = ADD32(0, 0X91);
    // 0x80066F3C: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
L_80066F40:
    // 0x80066F40: beq         $v1, $zero, L_80066F74
    if (ctx->r3 == 0) {
        // 0x80066F44: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80066F74;
    }
    // 0x80066F44: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80066F48: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80066F4C: beq         $v1, $t3, L_8006704C
    if (ctx->r3 == ctx->r11) {
        // 0x80066F50: nop
    
            goto L_8006704C;
    }
    // 0x80066F50: nop

    // 0x80066F54: beq         $v1, $a0, L_8006724C
    if (ctx->r3 == ctx->r4) {
        // 0x80066F58: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_8006724C;
    }
    // 0x80066F58: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80066F5C: beq         $v1, $a1, L_80067444
    if (ctx->r3 == ctx->r5) {
        // 0x80066F60: srl         $t7, $a2, 1
        ctx->r15 = S32(U32(ctx->r6) >> 1);
            goto L_80067444;
    }
    // 0x80066F60: srl         $t7, $a2, 1
    ctx->r15 = S32(U32(ctx->r6) >> 1);
    // 0x80066F64: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80066F68: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80066F6C: b           L_800679E4
    // 0x80066F70: nop

        goto L_800679E4;
    // 0x80066F70: nop

L_80066F74:
    // 0x80066F74: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80066F78: bne         $t2, $zero, L_80066F84
    if (ctx->r10 != 0) {
        // 0x80066F7C: or          $t3, $t9, $zero
        ctx->r11 = ctx->r25 | 0;
            goto L_80066F84;
    }
    // 0x80066F7C: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x80066F80: addiu       $t3, $t9, -0x12
    ctx->r11 = ADD32(ctx->r25, -0X12);
L_80066F84:
    // 0x80066F84: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80066F88: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80066F8C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80066F90: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80066F94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80066F98: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80066F9C: lui         $t8, 0xED00
    ctx->r24 = S32(0XED00 << 16);
    // 0x80066FA0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80066FA4: bgez        $t1, L_80066FBC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80066FA8: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80066FBC;
    }
    // 0x80066FA8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80066FAC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80066FB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80066FB4: nop

    // 0x80066FB8: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80066FBC:
    // 0x80066FBC: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80066FC0: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80066FC4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80066FC8: nop

    // 0x80066FCC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80066FD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80066FD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80066FD8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80066FDC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80066FE0: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80066FE4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80066FE8: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80066FEC: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80066FF0: bgez        $t0, L_80067004
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80066FF4: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80067004;
    }
    // 0x80066FF4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80066FF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80066FFC: nop

    // 0x80067000: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80067004:
    // 0x80067004: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80067008: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8006700C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80067010: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80067014: nop

    // 0x80067018: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8006701C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067020: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067024: nop

    // 0x80067028: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8006702C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80067030: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80067034: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067038: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8006703C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80067040: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067044: b           L_800679E4
    // 0x80067048: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
        goto L_800679E4;
    // 0x80067048: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
L_8006704C:
    // 0x8006704C: lw          $t3, 0x0($ra)
    ctx->r11 = MEM_W(ctx->r31, 0X0);
    // 0x80067050: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80067054: bne         $t3, $zero, L_8006712C
    if (ctx->r11 != 0) {
        // 0x80067058: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_8006712C;
    }
    // 0x80067058: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8006705C: srl         $v0, $t0, 2
    ctx->r2 = S32(U32(ctx->r8) >> 2);
    // 0x80067060: bne         $t2, $zero, L_8006706C
    if (ctx->r10 != 0) {
        // 0x80067064: or          $t3, $v0, $zero
        ctx->r11 = ctx->r2 | 0;
            goto L_8006706C;
    }
    // 0x80067064: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80067068: addiu       $t3, $v0, -0xC
    ctx->r11 = ADD32(ctx->r2, -0XC);
L_8006706C:
    // 0x8006706C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80067070: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80067074: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80067078: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8006707C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067080: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80067084: lui         $t8, 0xED00
    ctx->r24 = S32(0XED00 << 16);
    // 0x80067088: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8006708C: bgez        $t1, L_800670A4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80067090: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800670A4;
    }
    // 0x80067090: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80067094: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067098: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006709C: nop

    // 0x800670A0: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800670A4:
    // 0x800670A4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800670A8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800670AC: nop

    // 0x800670B0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800670B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800670B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800670BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800670C0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800670C4: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800670C8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800670CC: srl         $t6, $t0, 7
    ctx->r14 = S32(U32(ctx->r8) >> 7);
    // 0x800670D0: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800670D4: subu        $t7, $a3, $t6
    ctx->r15 = SUB32(ctx->r7, ctx->r14);
    // 0x800670D8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800670DC: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x800670E0: bgez        $t7, L_800670F4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800670E4: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800670F4;
    }
    // 0x800670E4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800670E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800670EC: nop

    // 0x800670F0: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_800670F4:
    // 0x800670F4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800670F8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800670FC: nop

    // 0x80067100: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067104: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067108: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006710C: nop

    // 0x80067110: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80067114: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80067118: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8006711C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80067120: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80067124: b           L_80067238
    // 0x80067128: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_80067238;
    // 0x80067128: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_8006712C:
    // 0x8006712C: srl         $v1, $t0, 7
    ctx->r3 = S32(U32(ctx->r8) >> 7);
    // 0x80067130: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80067134: addu        $t7, $a3, $v1
    ctx->r15 = ADD32(ctx->r7, ctx->r3);
    // 0x80067138: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8006713C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067140: srl         $t6, $t0, 2
    ctx->r14 = S32(U32(ctx->r8) >> 2);
    // 0x80067144: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80067148: addu        $t3, $a3, $t6
    ctx->r11 = ADD32(ctx->r7, ctx->r14);
    // 0x8006714C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80067150: bgez        $t7, L_80067168
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80067154: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80067168;
    }
    // 0x80067154: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80067158: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006715C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067160: nop

    // 0x80067164: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_80067168:
    // 0x80067168: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8006716C: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80067170: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067174: nop

    // 0x80067178: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8006717C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067180: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067184: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80067188: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8006718C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80067190: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80067194: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80067198: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8006719C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800671A0: bgez        $t1, L_800671B8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800671A4: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800671B8;
    }
    // 0x800671A4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800671A8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800671AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800671B0: nop

    // 0x800671B4: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800671B8:
    // 0x800671B8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800671BC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800671C0: nop

    // 0x800671C4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800671C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800671CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800671D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800671D4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800671D8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800671DC: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800671E0: subu        $t9, $t0, $v1
    ctx->r25 = SUB32(ctx->r8, ctx->r3);
    // 0x800671E4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800671E8: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800671EC: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x800671F0: bgez        $t9, L_80067204
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800671F4: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80067204;
    }
    // 0x800671F4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800671F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800671FC: nop

    // 0x80067200: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80067204:
    // 0x80067204: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80067208: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8006720C: nop

    // 0x80067210: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067214: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067218: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006721C: nop

    // 0x80067220: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80067224: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80067228: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8006722C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80067230: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80067234: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
L_80067238:
    // 0x80067238: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8006723C: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067240: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80067244: b           L_800679E4
    // 0x80067248: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
        goto L_800679E4;
    // 0x80067248: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_8006724C:
    // 0x8006724C: lw          $t8, 0x0($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X0);
    // 0x80067250: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80067254: bne         $t8, $zero, L_80067320
    if (ctx->r24 != 0) {
        // 0x80067258: lui         $t2, 0x8000
        ctx->r10 = S32(0X8000 << 16);
            goto L_80067320;
    }
    // 0x80067258: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x8006725C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80067260: srl         $t6, $t1, 8
    ctx->r14 = S32(U32(ctx->r9) >> 8);
    // 0x80067264: subu        $t8, $a2, $t6
    ctx->r24 = SUB32(ctx->r6, ctx->r14);
    // 0x80067268: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8006726C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80067270: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80067274: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067278: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8006727C: lui         $t9, 0xED00
    ctx->r25 = S32(0XED00 << 16);
    // 0x80067280: srl         $a1, $t1, 2
    ctx->r5 = S32(U32(ctx->r9) >> 2);
    // 0x80067284: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80067288: bgez        $t8, L_800672A0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8006728C: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800672A0;
    }
    // 0x8006728C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80067290: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067294: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067298: nop

    // 0x8006729C: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800672A0:
    // 0x800672A0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800672A4: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800672A8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800672AC: nop

    // 0x800672B0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800672B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800672B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800672BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800672C0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800672C4: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800672C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800672CC: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800672D0: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x800672D4: bgez        $t0, L_800672E8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800672D8: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800672E8;
    }
    // 0x800672D8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800672DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800672E0: nop

    // 0x800672E4: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_800672E8:
    // 0x800672E8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800672EC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800672F0: nop

    // 0x800672F4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800672F8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800672FC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067300: nop

    // 0x80067304: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80067308: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8006730C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80067310: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80067314: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80067318: b           L_80067434
    // 0x8006731C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
        goto L_80067434;
    // 0x8006731C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_80067320:
    // 0x80067320: srl         $a0, $t1, 8
    ctx->r4 = S32(U32(ctx->r9) >> 8);
    // 0x80067324: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80067328: addu        $t6, $a2, $a0
    ctx->r14 = ADD32(ctx->r6, ctx->r4);
    // 0x8006732C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80067330: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80067334: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067338: srl         $t9, $t1, 2
    ctx->r25 = S32(U32(ctx->r9) >> 2);
    // 0x8006733C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80067340: addu        $a1, $a2, $t9
    ctx->r5 = ADD32(ctx->r6, ctx->r25);
    // 0x80067344: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80067348: bgez        $t6, L_80067360
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006734C: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80067360;
    }
    // 0x8006734C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80067350: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067354: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067358: nop

    // 0x8006735C: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_80067360:
    // 0x80067360: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067364: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80067368: nop

    // 0x8006736C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80067370: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067374: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067378: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x8006737C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80067380: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80067384: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80067388: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8006738C: subu        $t9, $t1, $a0
    ctx->r25 = SUB32(ctx->r9, ctx->r4);
    // 0x80067390: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80067394: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80067398: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8006739C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800673A0: bgez        $t9, L_800673B8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800673A4: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800673B8;
    }
    // 0x800673A4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800673A8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800673AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800673B0: nop

    // 0x800673B4: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800673B8:
    // 0x800673B8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800673BC: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x800673C0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800673C4: nop

    // 0x800673C8: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800673CC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800673D0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800673D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800673D8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800673DC: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800673E0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800673E4: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800673E8: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800673EC: bgez        $t0, L_80067400
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800673F0: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80067400;
    }
    // 0x800673F0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800673F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800673F8: nop

    // 0x800673FC: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80067400:
    // 0x80067400: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80067404: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80067408: nop

    // 0x8006740C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80067410: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067414: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067418: nop

    // 0x8006741C: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80067420: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80067424: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80067428: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8006742C: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80067430: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
L_80067434:
    // 0x80067434: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067438: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8006743C: b           L_800679E4
    // 0x80067440: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
        goto L_800679E4;
    // 0x80067440: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
L_80067444:
    // 0x80067444: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80067448: lw          $v0, 0x0($ra)
    ctx->r2 = MEM_W(ctx->r31, 0X0);
    // 0x8006744C: srl         $t9, $t6, 1
    ctx->r25 = S32(U32(ctx->r14) >> 1);
    // 0x80067450: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x80067454: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x80067458: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8006745C: beq         $v0, $zero, L_80067484
    if (ctx->r2 == 0) {
        // 0x80067460: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_80067484;
    }
    // 0x80067460: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80067464: beq         $v0, $t3, L_800675EC
    if (ctx->r2 == ctx->r11) {
        // 0x80067468: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_800675EC;
    }
    // 0x80067468: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8006746C: beq         $v0, $a0, L_80067714
    if (ctx->r2 == ctx->r4) {
        // 0x80067470: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80067714;
    }
    // 0x80067470: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80067474: beq         $v0, $a1, L_80067838
    if (ctx->r2 == ctx->r5) {
        // 0x80067478: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80067838;
    }
    // 0x80067478: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8006747C: b           L_800679B4
    // 0x80067480: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
        goto L_800679B4;
    // 0x80067480: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_80067484:
    // 0x80067484: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80067488: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8006748C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80067490: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067494: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80067498: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8006749C: bgez        $zero, L_800674B4
    if (SIGNED(0) >= 0) {
        // 0x800674A0: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800674B4;
    }
    // 0x800674A0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800674A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800674A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800674AC: nop

    // 0x800674B0: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800674B4:
    // 0x800674B4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800674B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800674BC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800674C0: nop

    // 0x800674C4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800674C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800674CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800674D0: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800674D4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800674D8: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800674DC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800674E0: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800674E4: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800674E8: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800674EC: bgez        $zero, L_80067504
    if (SIGNED(0) >= 0) {
        // 0x800674F0: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80067504;
    }
    // 0x800674F0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800674F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800674F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800674FC: nop

    // 0x80067500: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_80067504:
    // 0x80067504: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80067508: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8006750C: nop

    // 0x80067510: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067514: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067518: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006751C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067520: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80067524: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80067528: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8006752C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80067530: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80067534: srl         $t7, $t1, 8
    ctx->r15 = S32(U32(ctx->r9) >> 8);
    // 0x80067538: subu        $t6, $a2, $t7
    ctx->r14 = SUB32(ctx->r6, ctx->r15);
    // 0x8006753C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80067540: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80067544: bgez        $t6, L_80067558
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80067548: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80067558;
    }
    // 0x80067548: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006754C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067550: nop

    // 0x80067554: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_80067558:
    // 0x80067558: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8006755C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80067560: nop

    // 0x80067564: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80067568: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8006756C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067570: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067574: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80067578: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8006757C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80067580: srl         $t8, $t0, 7
    ctx->r24 = S32(U32(ctx->r8) >> 7);
    // 0x80067584: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80067588: subu        $t9, $a3, $t8
    ctx->r25 = SUB32(ctx->r7, ctx->r24);
    // 0x8006758C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80067590: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x80067594: bgez        $t9, L_800675A8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80067598: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800675A8;
    }
    // 0x80067598: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006759C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800675A0: nop

    // 0x800675A4: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800675A8:
    // 0x800675A8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800675AC: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800675B0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800675B4: nop

    // 0x800675B8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800675BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800675C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800675C4: nop

    // 0x800675C8: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800675CC: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800675D0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800675D4: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800675D8: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800675DC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800675E0: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x800675E4: b           L_800679B4
    // 0x800675E8: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
        goto L_800679B4;
    // 0x800675E8: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_800675EC:
    // 0x800675EC: srl         $a0, $t1, 8
    ctx->r4 = S32(U32(ctx->r9) >> 8);
    // 0x800675F0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800675F4: addu        $t6, $a2, $a0
    ctx->r14 = ADD32(ctx->r6, ctx->r4);
    // 0x800675F8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800675FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067600: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80067604: or          $t4, $a2, $zero
    ctx->r12 = ctx->r6 | 0;
    // 0x80067608: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8006760C: bgez        $t6, L_80067624
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80067610: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80067624;
    }
    // 0x80067610: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80067614: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067618: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006761C: nop

    // 0x80067620: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80067624:
    // 0x80067624: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80067628: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8006762C: nop

    // 0x80067630: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067634: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067638: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006763C: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80067640: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80067644: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80067648: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8006764C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80067650: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80067654: addu        $t7, $a2, $a2
    ctx->r15 = ADD32(ctx->r6, ctx->r6);
    // 0x80067658: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x8006765C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80067660: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80067664: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80067668: bgez        $t8, L_80067680
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8006766C: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80067680;
    }
    // 0x8006766C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80067670: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067674: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067678: nop

    // 0x8006767C: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_80067680:
    // 0x80067680: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80067684: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80067688: nop

    // 0x8006768C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80067690: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067694: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067698: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006769C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800676A0: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800676A4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800676A8: srl         $t6, $t0, 7
    ctx->r14 = S32(U32(ctx->r8) >> 7);
    // 0x800676AC: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x800676B0: subu        $t9, $a3, $t6
    ctx->r25 = SUB32(ctx->r7, ctx->r14);
    // 0x800676B4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800676B8: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800676BC: bgez        $t9, L_800676D0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800676C0: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800676D0;
    }
    // 0x800676C0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800676C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800676C8: nop

    // 0x800676CC: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_800676D0:
    // 0x800676D0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800676D4: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800676D8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800676DC: nop

    // 0x800676E0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800676E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800676E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800676EC: nop

    // 0x800676F0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800676F4: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800676F8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800676FC: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80067700: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x80067704: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80067708: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x8006770C: b           L_800679B4
    // 0x80067710: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
        goto L_800679B4;
    // 0x80067710: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_80067714:
    // 0x80067714: srl         $v1, $t0, 7
    ctx->r3 = S32(U32(ctx->r8) >> 7);
    // 0x80067718: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8006771C: addu        $t8, $a3, $v1
    ctx->r24 = ADD32(ctx->r7, ctx->r3);
    // 0x80067720: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80067724: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80067728: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8006772C: or          $t5, $a3, $zero
    ctx->r13 = ctx->r7 | 0;
    // 0x80067730: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80067734: bgez        $t8, L_8006774C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80067738: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8006774C;
    }
    // 0x80067738: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006773C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067740: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067744: nop

    // 0x80067748: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_8006774C:
    // 0x8006774C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067750: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067754: nop

    // 0x80067758: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8006775C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067760: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067764: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80067768: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8006776C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80067770: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80067774: srl         $t9, $t1, 8
    ctx->r25 = S32(U32(ctx->r9) >> 8);
    // 0x80067778: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8006777C: subu        $t7, $a2, $t9
    ctx->r15 = SUB32(ctx->r6, ctx->r25);
    // 0x80067780: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80067784: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80067788: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8006778C: bgez        $t7, L_800677A4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80067790: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800677A4;
    }
    // 0x80067790: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80067794: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80067798: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006779C: nop

    // 0x800677A0: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800677A4:
    // 0x800677A4: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800677A8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800677AC: nop

    // 0x800677B0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800677B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800677B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800677BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800677C0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800677C4: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800677C8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800677CC: addu        $t6, $a3, $a3
    ctx->r14 = ADD32(ctx->r7, ctx->r7);
    // 0x800677D0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800677D4: subu        $t8, $t6, $v1
    ctx->r24 = SUB32(ctx->r14, ctx->r3);
    // 0x800677D8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800677DC: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x800677E0: bgez        $t8, L_800677F4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800677E4: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800677F4;
    }
    // 0x800677E4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800677E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800677EC: nop

    // 0x800677F0: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_800677F4:
    // 0x800677F4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800677F8: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800677FC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067800: nop

    // 0x80067804: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067808: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8006780C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067810: nop

    // 0x80067814: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80067818: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8006781C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80067820: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80067824: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80067828: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8006782C: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x80067830: b           L_800679B4
    // 0x80067834: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
        goto L_800679B4;
    // 0x80067834: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_80067838:
    // 0x80067838: srl         $a0, $t1, 8
    ctx->r4 = S32(U32(ctx->r9) >> 8);
    // 0x8006783C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80067840: addu        $t7, $a2, $a0
    ctx->r15 = ADD32(ctx->r6, ctx->r4);
    // 0x80067844: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80067848: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006784C: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80067850: or          $t4, $a2, $zero
    ctx->r12 = ctx->r6 | 0;
    // 0x80067854: or          $t5, $a3, $zero
    ctx->r13 = ctx->r7 | 0;
    // 0x80067858: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8006785C: srl         $v1, $t0, 7
    ctx->r3 = S32(U32(ctx->r8) >> 7);
    // 0x80067860: bgez        $t7, L_80067878
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80067864: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80067878;
    }
    // 0x80067864: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80067868: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006786C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067870: nop

    // 0x80067874: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_80067878:
    // 0x80067878: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8006787C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80067880: nop

    // 0x80067884: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80067888: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8006788C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067890: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80067894: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80067898: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8006789C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800678A0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800678A4: addu        $t9, $a3, $v1
    ctx->r25 = ADD32(ctx->r7, ctx->r3);
    // 0x800678A8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800678AC: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800678B0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800678B4: bgez        $t9, L_800678CC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800678B8: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800678CC;
    }
    // 0x800678B8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800678BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800678C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800678C4: nop

    // 0x800678C8: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_800678CC:
    // 0x800678CC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800678D0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800678D4: nop

    // 0x800678D8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800678DC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800678E0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800678E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800678E8: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800678EC: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800678F0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800678F4: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800678F8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800678FC: addu        $t7, $a2, $a2
    ctx->r15 = ADD32(ctx->r6, ctx->r6);
    // 0x80067900: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x80067904: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80067908: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8006790C: bgez        $t8, L_80067920
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80067910: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80067920;
    }
    // 0x80067910: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80067914: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067918: nop

    // 0x8006791C: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_80067920:
    // 0x80067920: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067924: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80067928: nop

    // 0x8006792C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80067930: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067934: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80067938: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006793C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80067940: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80067944: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80067948: addu        $t9, $a3, $a3
    ctx->r25 = ADD32(ctx->r7, ctx->r7);
    // 0x8006794C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80067950: subu        $t6, $t9, $v1
    ctx->r14 = SUB32(ctx->r25, ctx->r3);
    // 0x80067954: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80067958: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8006795C: bgez        $t6, L_80067970
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80067960: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80067970;
    }
    // 0x80067960: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80067964: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80067968: nop

    // 0x8006796C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80067970:
    // 0x80067970: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80067974: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x80067978: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8006797C: nop

    // 0x80067980: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80067984: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80067988: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8006798C: nop

    // 0x80067990: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80067994: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80067998: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8006799C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800679A0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800679A4: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800679A8: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x800679AC: nop

    // 0x800679B0: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_800679B4:
    // 0x800679B4: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800679B8: addu        $v0, $t5, $t9
    ctx->r2 = ADD32(ctx->r13, ctx->r25);
    // 0x800679BC: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800679C0: bne         $t2, $zero, L_800679E4
    if (ctx->r10 != 0) {
        // 0x800679C4: addu        $a3, $t4, $t8
        ctx->r7 = ADD32(ctx->r12, ctx->r24);
            goto L_800679E4;
    }
    // 0x800679C4: addu        $a3, $t4, $t8
    ctx->r7 = ADD32(ctx->r12, ctx->r24);
    // 0x800679C8: lw          $t6, 0x0($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X0);
    // 0x800679CC: addiu       $t3, $v0, -0x6
    ctx->r11 = ADD32(ctx->r2, -0X6);
    // 0x800679D0: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800679D4: beq         $at, $zero, L_800679E4
    if (ctx->r1 == 0) {
        // 0x800679D8: nop
    
            goto L_800679E4;
    }
    // 0x800679D8: nop

    // 0x800679DC: b           L_800679E4
    // 0x800679E0: addiu       $t3, $v0, -0x14
    ctx->r11 = ADD32(ctx->r2, -0X14);
        goto L_800679E4;
    // 0x800679E0: addiu       $t3, $v0, -0x14
    ctx->r11 = ADD32(ctx->r2, -0X14);
L_800679E4:
    // 0x800679E4: bne         $t2, $zero, L_800679F0
    if (ctx->r10 != 0) {
        // 0x800679E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800679F0;
    }
    // 0x800679E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800679EC: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
L_800679F0:
    // 0x800679F0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800679F4: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800679F8: jal         0x80068158
    // 0x800679FC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    viewport_rsp_set(rdram, ctx);
        goto after_4;
    // 0x800679FC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_4:
    // 0x80067A00: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80067A04: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80067A08: beq         $a1, $zero, L_80067A20
    if (ctx->r5 == 0) {
        // 0x80067A0C: addiu       $ra, $ra, 0xCE4
        ctx->r31 = ADD32(ctx->r31, 0XCE4);
            goto L_80067A20;
    }
    // 0x80067A0C: addiu       $ra, $ra, 0xCE4
    ctx->r31 = ADD32(ctx->r31, 0XCE4);
    // 0x80067A10: jal         0x80067D3C
    // 0x80067A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80067D3C(rdram, ctx);
        goto after_5;
    // 0x80067A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80067A18: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80067A1C: addiu       $ra, $ra, 0xCE4
    ctx->r31 = ADD32(ctx->r31, 0XCE4);
L_80067A20:
    // 0x80067A20: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80067A24: nop

    // 0x80067A28: sw          $t7, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r15;
L_80067A2C:
    // 0x80067A2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80067A30: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80067A34: jr          $ra
    // 0x80067A38: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80067A38: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8001790C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001790C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80017910: lw          $a2, -0x500C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X500C);
    // 0x80017914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017918: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
L_8001791C:
    // 0x8001791C: addu        $v1, $t6, $a2
    ctx->r3 = ADD32(ctx->r14, ctx->r6);
    // 0x80017920: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80017924: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80017928: beq         $t7, $zero, L_8001795C
    if (ctx->r15 == 0) {
        // 0x8001792C: sll         $t0, $v0, 16
        ctx->r8 = S32(ctx->r2 << 16);
            goto L_8001795C;
    }
    // 0x8001792C: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x80017930: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x80017934: nop

    // 0x80017938: bne         $a0, $t8, L_8001795C
    if (ctx->r4 != ctx->r24) {
        // 0x8001793C: nop
    
            goto L_8001795C;
    }
    // 0x8001793C: nop

    // 0x80017940: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x80017944: nop

    // 0x80017948: bne         $a1, $t9, L_80017960
    if (ctx->r5 != ctx->r25) {
        // 0x8001794C: sra         $v0, $t0, 16
        ctx->r2 = S32(SIGNED(ctx->r8) >> 16);
            goto L_80017960;
    }
    // 0x8001794C: sra         $v0, $t0, 16
    ctx->r2 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80017950: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80017954: jr          $ra
    // 0x80017958: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80017958: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001795C:
    // 0x8001795C: sra         $v0, $t0, 16
    ctx->r2 = S32(SIGNED(ctx->r8) >> 16);
L_80017960:
    // 0x80017960: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80017964: bne         $at, $zero, L_8001791C
    if (ctx->r1 != 0) {
        // 0x80017968: sll         $t6, $v0, 6
        ctx->r14 = S32(ctx->r2 << 6);
            goto L_8001791C;
    }
    // 0x80017968: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x8001796C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017970: jr          $ra
    // 0x80017974: nop

    return;
    // 0x80017974: nop

;}
RECOMP_FUNC void load_texture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AE74: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8007AE78: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8007AE7C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007AE80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007AE84: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8007AE88: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007AE8C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007AE90: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007AE94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007AE98: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8007AE9C: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8007AEA0: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8007AEA4: beq         $t7, $zero, L_8007AEB8
    if (ctx->r15 == 0) {
        // 0x8007AEA8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007AEB8;
    }
    // 0x8007AEA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007AEAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007AEB0: andi        $t0, $t6, 0x7FFF
    ctx->r8 = ctx->r14 & 0X7FFF;
    // 0x8007AEB4: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_8007AEB8:
    // 0x8007AEB8: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8007AEBC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007AEC0: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x8007AEC4: lw          $t8, 0x6338($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6338);
    // 0x8007AEC8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007AECC: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8007AED0: beq         $at, $zero, L_8007AEE0
    if (ctx->r1 == 0) {
        // 0x8007AED4: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8007AEE0;
    }
    // 0x8007AED4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007AED8: bgez        $t0, L_8007AEE4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8007AEDC: nop
    
            goto L_8007AEE4;
    }
    // 0x8007AEDC: nop

L_8007AEE0:
    // 0x8007AEE0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8007AEE4:
    // 0x8007AEE4: lw          $v0, 0x6330($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6330);
    // 0x8007AEE8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007AEEC: blez        $v0, L_8007AF38
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007AEF0: lui         $s4, 0x8012
        ctx->r20 = S32(0X8012 << 16);
            goto L_8007AF38;
    }
    // 0x8007AEF0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8007AEF4: lw          $a0, 0x6328($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6328);
    // 0x8007AEF8: nop

    // 0x8007AEFC: sll         $t2, $s1, 3
    ctx->r10 = S32(ctx->r17 << 3);
L_8007AF00:
    // 0x8007AF00: addu        $v1, $a0, $t2
    ctx->r3 = ADD32(ctx->r4, ctx->r10);
    // 0x8007AF04: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8007AF08: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007AF0C: bne         $s0, $t3, L_8007AF30
    if (ctx->r16 != ctx->r11) {
        // 0x8007AF10: slt         $at, $s1, $v0
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8007AF30;
    }
    // 0x8007AF10: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007AF14: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8007AF18: nop

    // 0x8007AF1C: lbu         $t4, 0x5($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X5);
    // 0x8007AF20: nop

    // 0x8007AF24: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8007AF28: b           L_8007B29C
    // 0x8007AF2C: sb          $t5, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r13;
        goto L_8007B29C;
    // 0x8007AF2C: sb          $t5, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r13;
L_8007AF30:
    // 0x8007AF30: bne         $at, $zero, L_8007AF00
    if (ctx->r1 != 0) {
        // 0x8007AF34: sll         $t2, $s1, 3
        ctx->r10 = S32(ctx->r17 << 3);
            goto L_8007AF00;
    }
    // 0x8007AF34: sll         $t2, $s1, 3
    ctx->r10 = S32(ctx->r17 << 3);
L_8007AF38:
    // 0x8007AF38: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007AF3C: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x8007AF40: lw          $t6, 0x6320($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6320);
    // 0x8007AF44: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8007AF48: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8007AF4C: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x8007AF50: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8007AF54: addiu       $s4, $s4, 0x636C
    ctx->r20 = ADD32(ctx->r20, 0X636C);
    // 0x8007AF58: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x8007AF5C: subu        $t9, $t8, $s2
    ctx->r25 = SUB32(ctx->r24, ctx->r18);
    // 0x8007AF60: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x8007AF64: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8007AF68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8007AF6C: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x8007AF70: jal         0x80076E68
    // 0x8007AF74: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    asset_load(rdram, ctx);
        goto after_0;
    // 0x8007AF74: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x8007AF78: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8007AF7C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8007AF80: lhu         $s1, 0x12($v1)
    ctx->r17 = MEM_HU(ctx->r3, 0X12);
    // 0x8007AF84: lbu         $t4, 0x1D($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X1D);
    // 0x8007AF88: sra         $t2, $s1, 8
    ctx->r10 = S32(SIGNED(ctx->r17) >> 8);
    // 0x8007AF8C: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8007AF90: bne         $t4, $zero, L_8007AFE8
    if (ctx->r12 != 0) {
        // 0x8007AF94: or          $s1, $t3, $zero
        ctx->r17 = ctx->r11 | 0;
            goto L_8007AFE8;
    }
    // 0x8007AF94: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
    // 0x8007AF98: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x8007AF9C: addu        $t5, $t5, $t3
    ctx->r13 = ADD32(ctx->r13, ctx->r11);
    // 0x8007AFA0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007AFA4: lw          $a1, -0x1840($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X1840);
    // 0x8007AFA8: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x8007AFAC: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x8007AFB0: jal         0x80070D10
    // 0x8007AFB4: or          $s4, $t3, $zero
    ctx->r20 = ctx->r11 | 0;
    mempool_alloc(rdram, ctx);
        goto after_1;
    // 0x8007AFB4: or          $s4, $t3, $zero
    ctx->r20 = ctx->r11 | 0;
    after_1:
    // 0x8007AFB8: bne         $v0, $zero, L_8007AFC8
    if (ctx->r2 != 0) {
        // 0x8007AFBC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8007AFC8;
    }
    // 0x8007AFBC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8007AFC0: b           L_8007B29C
    // 0x8007AFC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007B29C;
    // 0x8007AFC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007AFC8:
    // 0x8007AFC8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8007AFCC: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8007AFD0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8007AFD4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8007AFD8: jal         0x80076E68
    // 0x8007AFDC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    asset_load(rdram, ctx);
        goto after_2;
    // 0x8007AFDC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_2:
    // 0x8007AFE0: b           L_8007B08C
    // 0x8007AFE4: nop

        goto L_8007B08C;
    // 0x8007AFE4: nop

L_8007AFE8:
    // 0x8007AFE8: jal         0x800C61AC
    // 0x8007AFEC: addiu       $a0, $v1, 0x20
    ctx->r4 = ADD32(ctx->r3, 0X20);
    byteswap32(rdram, ctx);
        goto after_3;
    // 0x8007AFEC: addiu       $a0, $v1, 0x20
    ctx->r4 = ADD32(ctx->r3, 0X20);
    after_3:
    // 0x8007AFF0: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
    // 0x8007AFF4: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x8007AFF8: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8007AFFC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007B000: addiu       $t7, $v0, 0x20
    ctx->r15 = ADD32(ctx->r2, 0X20);
    // 0x8007B004: lw          $a1, -0x1840($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X1840);
    // 0x8007B008: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
    // 0x8007B00C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x8007B010: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8007B014: jal         0x80070D10
    // 0x8007B018: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
    mempool_alloc(rdram, ctx);
        goto after_4;
    // 0x8007B018: or          $s4, $s1, $zero
    ctx->r20 = ctx->r17 | 0;
    after_4:
    // 0x8007B01C: bne         $v0, $zero, L_8007B02C
    if (ctx->r2 != 0) {
        // 0x8007B020: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8007B02C;
    }
    // 0x8007B020: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8007B024: b           L_8007B29C
    // 0x8007B028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007B29C;
    // 0x8007B028: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B02C:
    // 0x8007B02C: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8007B030: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x8007B034: addu        $t2, $s3, $t9
    ctx->r10 = ADD32(ctx->r19, ctx->r25);
    // 0x8007B038: subu        $v0, $t2, $t3
    ctx->r2 = SUB32(ctx->r10, ctx->r11);
    // 0x8007B03C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8007B040: bgez        $v0, L_8007B054
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8007B044: andi        $t4, $v0, 0xF
        ctx->r12 = ctx->r2 & 0XF;
            goto L_8007B054;
    }
    // 0x8007B044: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x8007B048: beq         $t4, $zero, L_8007B054
    if (ctx->r12 == 0) {
        // 0x8007B04C: nop
    
            goto L_8007B054;
    }
    // 0x8007B04C: nop

    // 0x8007B050: addiu       $t4, $t4, -0x10
    ctx->r12 = ADD32(ctx->r12, -0X10);
L_8007B054:
    // 0x8007B054: subu        $a1, $v0, $t4
    ctx->r5 = SUB32(ctx->r2, ctx->r12);
    // 0x8007B058: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8007B05C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8007B060: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007B064: jal         0x80076E68
    // 0x8007B068: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    asset_load(rdram, ctx);
        goto after_5;
    // 0x8007B068: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    after_5:
    // 0x8007B06C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8007B070: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8007B074: jal         0x800C6218
    // 0x8007B078: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    gzip_inflate(rdram, ctx);
        goto after_6;
    // 0x8007B078: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_6:
    // 0x8007B07C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8007B080: nop

    // 0x8007B084: addiu       $t6, $t5, -0x20
    ctx->r14 = ADD32(ctx->r13, -0X20);
    // 0x8007B088: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
L_8007B08C:
    // 0x8007B08C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B090: lw          $v0, 0x6330($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6330);
    // 0x8007B094: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8007B098: blez        $v0, L_8007B0DC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007B09C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8007B0DC;
    }
    // 0x8007B09C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007B0A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007B0A4: lw          $a0, 0x6328($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6328);
    // 0x8007B0A8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007B0AC: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
L_8007B0B0:
    // 0x8007B0B0: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8007B0B4: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8007B0B8: nop

    // 0x8007B0BC: bne         $v1, $t2, L_8007B0C8
    if (ctx->r3 != ctx->r10) {
        // 0x8007B0C0: nop
    
            goto L_8007B0C8;
    }
    // 0x8007B0C0: nop

    // 0x8007B0C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
L_8007B0C8:
    // 0x8007B0C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007B0CC: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007B0D0: bne         $at, $zero, L_8007B0B0
    if (ctx->r1 != 0) {
        // 0x8007B0D4: sll         $t8, $s1, 3
        ctx->r24 = S32(ctx->r17 << 3);
            goto L_8007B0B0;
    }
    // 0x8007B0D4: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
    // 0x8007B0D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8007B0DC:
    // 0x8007B0DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007B0E0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007B0E4: lw          $a0, 0x6328($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6328);
    // 0x8007B0E8: bne         $a1, $v1, L_8007B0FC
    if (ctx->r5 != ctx->r3) {
        // 0x8007B0EC: addiu       $t4, $v0, 0x1
        ctx->r12 = ADD32(ctx->r2, 0X1);
            goto L_8007B0FC;
    }
    // 0x8007B0EC: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8007B0F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B0F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007B0F8: sw          $t4, 0x6330($at)
    MEM_W(0X6330, ctx->r1) = ctx->r12;
L_8007B0FC:
    // 0x8007B0FC: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x8007B100: addu        $t5, $a0, $t3
    ctx->r13 = ADD32(ctx->r4, ctx->r11);
    // 0x8007B104: sw          $s0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r16;
    // 0x8007B108: lw          $t6, 0x6328($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6328);
    // 0x8007B10C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007B110: addu        $t7, $t6, $t3
    ctx->r15 = ADD32(ctx->r14, ctx->r11);
    // 0x8007B114: sw          $s3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r19;
    // 0x8007B118: lbu         $a2, 0x2($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X2);
    // 0x8007B11C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007B120: andi        $t8, $a2, 0xF
    ctx->r24 = ctx->r6 & 0XF;
    // 0x8007B124: bne         $t8, $at, L_8007B1A0
    if (ctx->r24 != ctx->r1) {
        // 0x8007B128: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_8007B1A0;
    }
    // 0x8007B128: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8007B12C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8007B130: addiu       $s2, $s2, 0x6344
    ctx->r18 = ADD32(ctx->r18, 0X6344);
    // 0x8007B134: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8007B138: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8007B13C: bne         $t9, $zero, L_8007B190
    if (ctx->r25 != 0) {
        // 0x8007B140: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8007B190;
    }
    // 0x8007B140: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007B144: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007B148: lw          $t4, 0x6340($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6340);
    // 0x8007B14C: lw          $t2, 0x632C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X632C);
    // 0x8007B150: lh          $a2, 0x8($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X8);
    // 0x8007B154: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x8007B158: jal         0x80076E68
    // 0x8007B15C: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    asset_load(rdram, ctx);
        goto after_7;
    // 0x8007B15C: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    after_7:
    // 0x8007B160: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007B164: lw          $t3, 0x6340($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6340);
    // 0x8007B168: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8007B16C: sh          $t3, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r11;
    // 0x8007B170: lw          $t5, 0x6340($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6340);
    // 0x8007B174: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007B178: addiu       $t6, $t5, 0x20
    ctx->r14 = ADD32(ctx->r13, 0X20);
    // 0x8007B17C: sw          $t6, 0x6340($at)
    MEM_W(0X6340, ctx->r1) = ctx->r14;
    // 0x8007B180: lbu         $a2, 0x2($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X2);
    // 0x8007B184: nop

    // 0x8007B188: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007B18C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_8007B190:
    // 0x8007B190: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007B194: lw          $v1, 0x6340($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6340);
    // 0x8007B198: nop

    // 0x8007B19C: addiu       $v1, $v1, -0x20
    ctx->r3 = ADD32(ctx->r3, -0X20);
L_8007B1A0:
    // 0x8007B1A0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8007B1A4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8007B1A8: bne         $a2, $at, L_8007B204
    if (ctx->r6 != ctx->r1) {
        // 0x8007B1AC: addiu       $s2, $s2, 0x6344
        ctx->r18 = ADD32(ctx->r18, 0X6344);
            goto L_8007B204;
    }
    // 0x8007B1AC: addiu       $s2, $s2, 0x6344
    ctx->r18 = ADD32(ctx->r18, 0X6344);
    // 0x8007B1B0: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8007B1B4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8007B1B8: lw          $s0, 0x6340($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6340);
    // 0x8007B1BC: bne         $t8, $zero, L_8007B200
    if (ctx->r24 != 0) {
        // 0x8007B1C0: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8007B200;
    }
    // 0x8007B1C0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8007B1C4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007B1C8: lw          $t9, 0x632C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X632C);
    // 0x8007B1CC: lh          $a2, 0x8($s3)
    ctx->r6 = MEM_H(ctx->r19, 0X8);
    // 0x8007B1D0: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x8007B1D4: jal         0x80076E68
    // 0x8007B1D8: addu        $a1, $t9, $s0
    ctx->r5 = ADD32(ctx->r25, ctx->r16);
    asset_load(rdram, ctx);
        goto after_8;
    // 0x8007B1D8: addu        $a1, $t9, $s0
    ctx->r5 = ADD32(ctx->r25, ctx->r16);
    after_8:
    // 0x8007B1DC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007B1E0: addiu       $v1, $v1, 0x6340
    ctx->r3 = ADD32(ctx->r3, 0X6340);
    // 0x8007B1E4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8007B1E8: nop

    // 0x8007B1EC: sh          $t2, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r10;
    // 0x8007B1F0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8007B1F4: nop

    // 0x8007B1F8: addiu       $s0, $t4, 0x80
    ctx->r16 = ADD32(ctx->r12, 0X80);
    // 0x8007B1FC: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
L_8007B200:
    // 0x8007B200: addiu       $v1, $s0, -0x80
    ctx->r3 = ADD32(ctx->r16, -0X80);
L_8007B204:
    // 0x8007B204: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x8007B208: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x8007B20C: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x8007B210: jal         0x80071850
    // 0x8007B214: addu        $a0, $s3, $t5
    ctx->r4 = ADD32(ctx->r19, ctx->r13);
    align16(rdram, ctx);
        goto after_9;
    // 0x8007B214: addu        $a0, $s3, $t5
    ctx->r4 = ADD32(ctx->r19, ctx->r13);
    after_9:
    // 0x8007B218: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8007B21C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8007B220: blez        $s4, L_8007B260
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8007B224: or          $s0, $s3, $zero
        ctx->r16 = ctx->r19 | 0;
            goto L_8007B260;
    }
    // 0x8007B224: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
L_8007B228:
    // 0x8007B228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007B22C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8007B230: jal         0x8007D0F4
    // 0x8007B234: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    material_init(rdram, ctx);
        goto after_10;
    // 0x8007B234: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    after_10:
    // 0x8007B238: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8007B23C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007B240: bltz        $v1, L_8007B250
    if (SIGNED(ctx->r3) < 0) {
        // 0x8007B244: nop
    
            goto L_8007B250;
    }
    // 0x8007B244: nop

    // 0x8007B248: sh          $v1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r3;
    // 0x8007B24C: addiu       $s2, $s2, 0x30
    ctx->r18 = ADD32(ctx->r18, 0X30);
L_8007B250:
    // 0x8007B250: lh          $t6, 0x16($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X16);
    // 0x8007B254: addiu       $s2, $s2, 0x60
    ctx->r18 = ADD32(ctx->r18, 0X60);
    // 0x8007B258: bne         $s1, $s4, L_8007B228
    if (ctx->r17 != ctx->r20) {
        // 0x8007B25C: addu        $s0, $s0, $t6
        ctx->r16 = ADD32(ctx->r16, ctx->r14);
            goto L_8007B228;
    }
    // 0x8007B25C: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
L_8007B260:
    // 0x8007B260: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007B264: lw          $t7, 0x6340($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6340);
    // 0x8007B268: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007B26C: slti        $at, $t7, 0x280
    ctx->r1 = SIGNED(ctx->r15) < 0X280 ? 1 : 0;
    // 0x8007B270: bne         $at, $zero, L_8007B280
    if (ctx->r1 != 0) {
        // 0x8007B274: nop
    
            goto L_8007B280;
    }
    // 0x8007B274: nop

    // 0x8007B278: b           L_8007B29C
    // 0x8007B27C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007B29C;
    // 0x8007B27C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B280:
    // 0x8007B280: lw          $t8, 0x6330($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6330);
    // 0x8007B284: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x8007B288: slti        $at, $t8, 0x2BD
    ctx->r1 = SIGNED(ctx->r24) < 0X2BD ? 1 : 0;
    // 0x8007B28C: bne         $at, $zero, L_8007B29C
    if (ctx->r1 != 0) {
        // 0x8007B290: nop
    
            goto L_8007B29C;
    }
    // 0x8007B290: nop

    // 0x8007B294: b           L_8007B29C
    // 0x8007B298: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007B29C;
    // 0x8007B298: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007B29C:
    // 0x8007B29C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B2A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007B2A4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007B2A8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007B2AC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8007B2B0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007B2B4: jr          $ra
    // 0x8007B2B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8007B2B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void input_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_netplay_prepare_controller_init(uint8_t*, recomp_context*); dkr_netplay_prepare_controller_init(rdram, ctx);
    // 0x8006A10C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006A110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A114: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A118: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006A11C: addiu       $a1, $a1, 0x10F8
    ctx->r5 = ADD32(ctx->r5, 0X10F8);
    // 0x8006A120: addiu       $a0, $a0, 0x10E0
    ctx->r4 = ADD32(ctx->r4, 0X10E0);
    // 0x8006A124: jal         0x800C8820
    // 0x8006A128: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8006A128: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8006A12C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006A130: lw          $a2, 0x10FC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X10FC);
    // 0x8006A134: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006A138: addiu       $a1, $a1, 0x10E0
    ctx->r5 = ADD32(ctx->r5, 0X10E0);
    // 0x8006A13C: jal         0x800CCBB0
    // 0x8006A140: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8006A140: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_1:
    // 0x8006A144: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A148: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006A14C: addiu       $a2, $a2, 0x1100
    ctx->r6 = ADD32(ctx->r6, 0X1100);
    // 0x8006A150: addiu       $a0, $a0, 0x10E0
    ctx->r4 = ADD32(ctx->r4, 0X10E0);
    // 0x8006A154: jal         0x800CCC20
    // 0x8006A158: addiu       $a1, $sp, 0x23
    ctx->r5 = ADD32(ctx->r29, 0X23);
    osContInit_recomp(rdram, ctx);
        goto after_2;
    // 0x8006A158: addiu       $a1, $sp, 0x23
    ctx->r5 = ADD32(ctx->r29, 0X23);
    after_2:
    // 0x8006A15C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A160: jal         0x800CCFE0
    // 0x8006A164: addiu       $a0, $a0, 0x10E0
    ctx->r4 = ADD32(ctx->r4, 0X10E0);
    osContStartReadData_recomp(rdram, ctx);
        goto after_3;
    // 0x8006A164: addiu       $a0, $a0, 0x10E0
    ctx->r4 = ADD32(ctx->r4, 0X10E0);
    after_3:
    // 0x8006A168: jal         0x8006A434
    // 0x8006A16C: nop

    input_assign_players(rdram, ctx);
        goto after_4;
    // 0x8006A16C: nop

    after_4:
    // 0x8006A170: lbu         $v0, 0x23($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X23);
    // 0x8006A174: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8006A178: addiu       $v1, $v1, -0x2D00
    ctx->r3 = ADD32(ctx->r3, -0X2D00);
    // 0x8006A17C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8006A180: beq         $t6, $zero, L_8006A1A8
    if (ctx->r14 == 0) {
        // 0x8006A184: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_8006A1A8;
    }
    // 0x8006A184: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8006A188: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006A18C: lbu         $t7, 0x1103($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X1103);
    // 0x8006A190: nop

    // 0x8006A194: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x8006A198: bne         $t8, $zero, L_8006A1AC
    if (ctx->r24 != 0) {
        // 0x8006A19C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8006A1AC;
    }
    // 0x8006A19C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8006A1A0: b           L_8006A1B4
    // 0x8006A1A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006A1B4;
    // 0x8006A1A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A1A8:
    // 0x8006A1A8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_8006A1AC:
    // 0x8006A1AC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006A1B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006A1B4:
    // 0x8006A1B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A1B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006A1BC: jr          $ra
    // 0x8006A1C0: nop

    return;
    // 0x8006A1C0: nop

;}
RECOMP_FUNC void calc_and_alloc_heap_for_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E3BC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006E3C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E3C4: jal         0x8006A6B0
    // 0x8006E3C8: nop

    level_global_init(rdram, ctx);
        goto after_0;
    // 0x8006E3C8: nop

    after_0:
    // 0x8006E3CC: jal         0x8009C154
    // 0x8006E3D0: nop

    reset_character_id_slots(rdram, ctx);
        goto after_1;
    // 0x8006E3D0: nop

    after_1:
    // 0x8006E3D4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8006E3D8: jal         0x8006B224
    // 0x8006E3DC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    level_count(rdram, ctx);
        goto after_2;
    // 0x8006E3DC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x8006E3E0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8006E3E4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E3E8: addiu       $v1, $zero, 0x118
    ctx->r3 = ADD32(0, 0X118);
    // 0x8006E3EC: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8006E3F0: addu        $a2, $v1, $t6
    ctx->r6 = ADD32(ctx->r3, ctx->r14);
    // 0x8006E3F4: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8006E3F8: addu        $t0, $a2, $t8
    ctx->r8 = ADD32(ctx->r6, ctx->r24);
    // 0x8006E3FC: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x8006E400: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8006E404: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8006E408: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8006E40C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8006E410: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x8006E414: addu        $ra, $t5, $v0
    ctx->r31 = ADD32(ctx->r13, ctx->r2);
    // 0x8006E418: addu        $t9, $ra, $v0
    ctx->r25 = ADD32(ctx->r31, ctx->r2);
    // 0x8006E41C: addu        $t7, $t9, $v0
    ctx->r15 = ADD32(ctx->r25, ctx->r2);
    // 0x8006E420: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8006E424: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8006E428: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8006E42C: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x8006E430: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    // 0x8006E434: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8006E438: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x8006E43C: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x8006E440: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x8006E444: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x8006E448: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8006E44C: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x8006E450: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x8006E454: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x8006E458: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8006E45C: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8006E460: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8006E464: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8006E468: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8006E46C: jal         0x80070C9C
    // 0x8006E470: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8006E470: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
    // 0x8006E474: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8006E478: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006E47C: addiu       $a0, $a0, 0x3510
    ctx->r4 = ADD32(ctx->r4, 0X3510);
    // 0x8006E480: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8006E484: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8006E488: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8006E48C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E490: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8006E494: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006E498: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8006E49C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8006E4A0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8006E4A4: nop

    // 0x8006E4A8: sh          $zero, 0x14($t8)
    MEM_H(0X14, ctx->r24) = 0;
    // 0x8006E4AC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E4B0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8006E4B4: nop

    // 0x8006E4B8: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E4BC: sw          $t6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r14;
    // 0x8006E4C0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E4C4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E4C8: nop

    // 0x8006E4CC: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E4D0: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x8006E4D4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E4D8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8006E4DC: nop

    // 0x8006E4E0: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E4E4: sw          $t6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r14;
    // 0x8006E4E8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E4EC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8006E4F0: nop

    // 0x8006E4F4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E4F8: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x8006E4FC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E500: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8006E504: nop

    // 0x8006E508: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E50C: sw          $t6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r14;
    // 0x8006E510: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E514: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8006E518: nop

    // 0x8006E51C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E520: sw          $t8, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r24;
    // 0x8006E524: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E528: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8006E52C: nop

    // 0x8006E530: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E534: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
    // 0x8006E538: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E53C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8006E540: nop

    // 0x8006E544: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E548: sw          $t8, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r24;
    // 0x8006E54C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E550: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x8006E554: nop

    // 0x8006E558: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E55C: sw          $t6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r14;
    // 0x8006E560: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E564: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8006E568: nop

    // 0x8006E56C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E570: sw          $t8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r24;
    // 0x8006E574: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E578: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8006E57C: nop

    // 0x8006E580: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006E584: sw          $t6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r14;
    // 0x8006E588: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8006E58C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8006E590: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006E594: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006E598: sw          $t8, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r24;
    // 0x8006E59C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8006E5A0: addiu       $t9, $t9, 0x1250
    ctx->r25 = ADD32(ctx->r25, 0X1250);
    // 0x8006E5A4: sw          $t9, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->r25;
    // 0x8006E5A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E5AC: addiu       $t7, $zero, 0x107
    ctx->r15 = ADD32(0, 0X107);
    // 0x8006E5B0: sw          $t7, -0x2C84($at)
    MEM_W(-0X2C84, ctx->r1) = ctx->r15;
    // 0x8006E5B4: jr          $ra
    // 0x8006E5B8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006E5B8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void sound_distance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001CB8: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80001CBC: lw          $t7, 0x5D20($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5D20);
    // 0x80001CC0: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001CC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80001CC8: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80001CCC: beq         $at, $zero, L_80001CDC
    if (ctx->r1 == 0) {
        // 0x80001CD0: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80001CDC;
    }
    // 0x80001CD0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80001CD4: jr          $ra
    // 0x80001CD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80001CD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80001CDC:
    // 0x80001CDC: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80001CE0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80001CE4: lw          $t8, 0x5D18($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5D18);
    // 0x80001CE8: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x80001CEC: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80001CF0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80001CF4: lhu         $v0, 0x6($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X6);
    // 0x80001CF8: nop

    // 0x80001CFC: jr          $ra
    // 0x80001D00: nop

    return;
    // 0x80001D00: nop

;}
RECOMP_FUNC void obj_door_open(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800235D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800235D4: jr          $ra
    // 0x800235D8: sb          $a0, -0x522B($at)
    MEM_B(-0X522B, ctx->r1) = ctx->r4;
    return;
    // 0x800235D8: sb          $a0, -0x522B($at)
    MEM_B(-0X522B, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void free_particle_buffers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE374: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE378: lw          $a0, 0x2CA8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2CA8);
    // 0x800AE37C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE380: beq         $a0, $zero, L_800AE398
    if (ctx->r4 == 0) {
        // 0x800AE384: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AE398;
    }
    // 0x800AE384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE388: jal         0x80071140
    // 0x800AE38C: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800AE38C: nop

    after_0:
    // 0x800AE390: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE394: sw          $zero, 0x2CA8($at)
    MEM_W(0X2CA8, ctx->r1) = 0;
L_800AE398:
    // 0x800AE398: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE39C: lw          $a0, 0x2CB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2CB4);
    // 0x800AE3A0: nop

    // 0x800AE3A4: beq         $a0, $zero, L_800AE3BC
    if (ctx->r4 == 0) {
        // 0x800AE3A8: nop
    
            goto L_800AE3BC;
    }
    // 0x800AE3A8: nop

    // 0x800AE3AC: jal         0x80071140
    // 0x800AE3B0: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800AE3B0: nop

    after_1:
    // 0x800AE3B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE3B8: sw          $zero, 0x2CB4($at)
    MEM_W(0X2CB4, ctx->r1) = 0;
L_800AE3BC:
    // 0x800AE3BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE3C0: lw          $a0, 0x2CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2CC0);
    // 0x800AE3C4: nop

    // 0x800AE3C8: beq         $a0, $zero, L_800AE3E0
    if (ctx->r4 == 0) {
        // 0x800AE3CC: nop
    
            goto L_800AE3E0;
    }
    // 0x800AE3CC: nop

    // 0x800AE3D0: jal         0x80071140
    // 0x800AE3D4: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800AE3D4: nop

    after_2:
    // 0x800AE3D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE3DC: sw          $zero, 0x2CC0($at)
    MEM_W(0X2CC0, ctx->r1) = 0;
L_800AE3E0:
    // 0x800AE3E0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE3E4: lw          $a0, 0x2CCC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2CCC);
    // 0x800AE3E8: nop

    // 0x800AE3EC: beq         $a0, $zero, L_800AE404
    if (ctx->r4 == 0) {
        // 0x800AE3F0: nop
    
            goto L_800AE404;
    }
    // 0x800AE3F0: nop

    // 0x800AE3F4: jal         0x80071140
    // 0x800AE3F8: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x800AE3F8: nop

    after_3:
    // 0x800AE3FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE400: sw          $zero, 0x2CCC($at)
    MEM_W(0X2CCC, ctx->r1) = 0;
L_800AE404:
    // 0x800AE404: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE408: lw          $a0, 0x2CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2CD8);
    // 0x800AE40C: nop

    // 0x800AE410: beq         $a0, $zero, L_800AE42C
    if (ctx->r4 == 0) {
        // 0x800AE414: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800AE42C;
    }
    // 0x800AE414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE418: jal         0x80071140
    // 0x800AE41C: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x800AE41C: nop

    after_4:
    // 0x800AE420: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE424: sw          $zero, 0x2CD8($at)
    MEM_W(0X2CD8, ctx->r1) = 0;
    // 0x800AE428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AE42C:
    // 0x800AE42C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE430: jr          $ra
    // 0x800AE434: nop

    return;
    // 0x800AE434: nop

;}
RECOMP_FUNC void fb_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A98C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007A990: addiu       $v1, $v1, 0x62D0
    ctx->r3 = ADD32(ctx->r3, 0X62D0);
    // 0x8007A994: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007A998: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8007A99C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007A9A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007A9A4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007A9A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007A9AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007A9B0: beq         $v0, $zero, L_8007A9CC
    if (ctx->r2 == 0) {
        // 0x8007A9B4: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_8007A9CC;
    }
    // 0x8007A9B4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8007A9B8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8007A9BC: bne         $t6, $zero, L_8007A9CC
    if (ctx->r14 != 0) {
        // 0x8007A9C0: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8007A9CC;
    }
    // 0x8007A9C0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007A9C4: jal         0x800D1D10
    // 0x8007A9C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViBlack_recomp(rdram, ctx);
        goto after_0;
    // 0x8007A9C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
L_8007A9CC:
    // 0x8007A9CC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8007A9D0: beq         $s1, $at, L_8007A9E0
    if (ctx->r17 == ctx->r1) {
        // 0x8007A9D4: nop
    
            goto L_8007A9E0;
    }
    // 0x8007A9D4: nop

    // 0x8007A9D8: jal         0x8007AB9C
    // 0x8007A9DC: nop

    fb_swap(rdram, ctx);
        goto after_1;
    // 0x8007A9DC: nop

    after_1:
L_8007A9E0:
    // 0x8007A9E0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8007A9E4: addiu       $s2, $s2, 0x61A0
    ctx->r18 = ADD32(ctx->r18, 0X61A0);
    // 0x8007A9E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007A9EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007A9F0: jal         0x800C8BB0
    // 0x8007A9F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x8007A9F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8007A9F8: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x8007A9FC: beq         $v0, $s1, L_8007AA28
    if (ctx->r2 == ctx->r17) {
        // 0x8007AA00: nop
    
            goto L_8007AA28;
    }
    // 0x8007AA00: nop

L_8007AA04:
    // 0x8007AA04: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007AA08: andi        $t8, $s0, 0xFF
    ctx->r24 = ctx->r16 & 0XFF;
    // 0x8007AA0C: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x8007AA10: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007AA14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007AA18: jal         0x800C8BB0
    // 0x8007AA1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x8007AA1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8007AA20: bne         $v0, $s1, L_8007AA04
    if (ctx->r2 != ctx->r17) {
        // 0x8007AA24: nop
    
            goto L_8007AA04;
    }
    // 0x8007AA24: nop

L_8007AA28:
    // 0x8007AA28: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8007AA2C: addiu       $s1, $s1, 0x6309
    ctx->r17 = ADD32(ctx->r17, 0X6309);
    // 0x8007AA30: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x8007AA34: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8007AA38: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007AA3C: beq         $at, $zero, L_8007AA88
    if (ctx->r1 == 0) {
        // 0x8007AA40: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8007AA88;
    }
    // 0x8007AA40: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007AA44: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007AA48: addiu       $a2, $a2, 0x6308
    ctx->r6 = ADD32(ctx->r6, 0X6308);
    // 0x8007AA4C: lbu         $a1, 0x0($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X0);
    // 0x8007AA50: nop

    // 0x8007AA54: slti        $at, $a1, 0x14
    ctx->r1 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
    // 0x8007AA58: beq         $at, $zero, L_8007AA6C
    if (ctx->r1 == 0) {
        // 0x8007AA5C: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8007AA6C;
    }
    // 0x8007AA5C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8007AA60: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x8007AA64: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x8007AA68: andi        $v0, $t9, 0xFF
    ctx->r2 = ctx->r25 & 0XFF;
L_8007AA6C:
    // 0x8007AA6C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8007AA70: bne         $v0, $at, L_8007AABC
    if (ctx->r2 != ctx->r1) {
        // 0x8007AA74: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8007AABC;
    }
    // 0x8007AA74: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007AA78: sb          $s0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r16;
    // 0x8007AA7C: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8007AA80: b           L_8007AAB8
    // 0x8007AA84: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
        goto L_8007AAB8;
    // 0x8007AA84: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_8007AA88:
    // 0x8007AA88: addiu       $a2, $a2, 0x6308
    ctx->r6 = ADD32(ctx->r6, 0X6308);
    // 0x8007AA8C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007AA90: beq         $at, $zero, L_8007AAB8
    if (ctx->r1 == 0) {
        // 0x8007AA94: sb          $zero, 0x0($a2)
        MEM_B(0X0, ctx->r6) = 0;
            goto L_8007AAB8;
    }
    // 0x8007AA94: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8007AA98: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007AA9C: lbu         $t0, 0x62E4($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X62E4);
    // 0x8007AAA0: nop

    // 0x8007AAA4: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007AAA8: bne         $at, $zero, L_8007AABC
    if (ctx->r1 != 0) {
        // 0x8007AAAC: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8007AABC;
    }
    // 0x8007AAAC: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007AAB0: sb          $s0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r16;
    // 0x8007AAB4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_8007AAB8:
    // 0x8007AAB8: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_8007AABC:
    // 0x8007AABC: beq         $at, $zero, L_8007AAE8
    if (ctx->r1 == 0) {
        // 0x8007AAC0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8007AAE8;
    }
L_8007AAC0:
    // 0x8007AAC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007AAC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007AAC8: jal         0x800C8BB0
    // 0x8007AACC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x8007AACC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8007AAD0: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x8007AAD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007AAD8: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x8007AADC: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007AAE0: bne         $at, $zero, L_8007AAC0
    if (ctx->r1 != 0) {
        // 0x8007AAE4: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_8007AAC0;
    }
    // 0x8007AAE4: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_8007AAE8:
    // 0x8007AAE8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007AAEC: lw          $a0, 0x62D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X62D8);
    // 0x8007AAF0: jal         0x800D2420
    // 0x8007AAF4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_5;
    // 0x8007AAF4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_5:
    // 0x8007AAF8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007AAFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007AB00: jal         0x800C8BB0
    // 0x8007AB04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x8007AB04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8007AB08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007AB0C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8007AB10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007AB14: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007AB18: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007AB1C: jr          $ra
    // 0x8007AB20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007AB20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void debug_text_bounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6E50: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800B6E54: lhu         $v0, 0x7CD0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7CD0);
    // 0x800B6E58: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800B6E5C: slti        $at, $v0, 0x141
    ctx->r1 = SIGNED(ctx->r2) < 0X141 ? 1 : 0;
    // 0x800B6E60: beq         $at, $zero, L_800B6E84
    if (ctx->r1 == 0) {
        // 0x800B6E64: addiu       $t9, $v0, -0x20
        ctx->r25 = ADD32(ctx->r2, -0X20);
            goto L_800B6E84;
    }
    // 0x800B6E64: addiu       $t9, $v0, -0x20
    ctx->r25 = ADD32(ctx->r2, -0X20);
    // 0x800B6E68: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800B6E6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B6E70: sw          $t6, 0x7CBC($at)
    MEM_W(0X7CBC, ctx->r1) = ctx->r14;
    // 0x800B6E74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B6E78: addiu       $t7, $v0, -0x10
    ctx->r15 = ADD32(ctx->r2, -0X10);
    // 0x800B6E7C: b           L_800B6E94
    // 0x800B6E80: sw          $t7, 0x7CC0($at)
    MEM_W(0X7CC0, ctx->r1) = ctx->r15;
        goto L_800B6E94;
    // 0x800B6E80: sw          $t7, 0x7CC0($at)
    MEM_W(0X7CC0, ctx->r1) = ctx->r15;
L_800B6E84:
    // 0x800B6E84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B6E88: sw          $t8, 0x7CBC($at)
    MEM_W(0X7CBC, ctx->r1) = ctx->r24;
    // 0x800B6E8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B6E90: sw          $t9, 0x7CC0($at)
    MEM_W(0X7CC0, ctx->r1) = ctx->r25;
L_800B6E94:
    // 0x800B6E94: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800B6E98: lhu         $v0, 0x7CD2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7CD2);
    // 0x800B6E9C: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x800B6EA0: slti        $at, $v0, 0xF1
    ctx->r1 = SIGNED(ctx->r2) < 0XF1 ? 1 : 0;
    // 0x800B6EA4: beq         $at, $zero, L_800B6EC8
    if (ctx->r1 == 0) {
        // 0x800B6EA8: addiu       $t3, $v0, -0x20
        ctx->r11 = ADD32(ctx->r2, -0X20);
            goto L_800B6EC8;
    }
    // 0x800B6EA8: addiu       $t3, $v0, -0x20
    ctx->r11 = ADD32(ctx->r2, -0X20);
    // 0x800B6EAC: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800B6EB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B6EB4: sw          $t0, 0x7CC4($at)
    MEM_W(0X7CC4, ctx->r1) = ctx->r8;
    // 0x800B6EB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B6EBC: addiu       $t1, $v0, -0x10
    ctx->r9 = ADD32(ctx->r2, -0X10);
    // 0x800B6EC0: jr          $ra
    // 0x800B6EC4: sw          $t1, 0x7CC8($at)
    MEM_W(0X7CC8, ctx->r1) = ctx->r9;
    return;
    // 0x800B6EC4: sw          $t1, 0x7CC8($at)
    MEM_W(0X7CC8, ctx->r1) = ctx->r9;
L_800B6EC8:
    // 0x800B6EC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B6ECC: sw          $t2, 0x7CC4($at)
    MEM_W(0X7CC4, ctx->r1) = ctx->r10;
    // 0x800B6ED0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B6ED4: sw          $t3, 0x7CC8($at)
    MEM_W(0X7CC8, ctx->r1) = ctx->r11;
    // 0x800B6ED8: jr          $ra
    // 0x800B6EDC: nop

    return;
    // 0x800B6EDC: nop

;}
RECOMP_FUNC void dmacopy_doubleword(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_80070B04:
    // 0x80070B04: ld          $t0, 0x0($a0)
    ctx->r8 = LD(ctx->r4, 0X0);
    // 0x80070B08: ld          $t1, 0x8($a0)
    ctx->r9 = LD(ctx->r4, 0X8);
    // 0x80070B0C: addi        $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80070B10: addi        $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80070B14: sd          $t0, -0x10($a1)
    SD(ctx->r8, -0X10, ctx->r5);
    // 0x80070B18: bne         $a1, $a2, L_80070B04
    if (ctx->r5 != ctx->r6) {
        // 0x80070B1C: sd          $t1, -0x8($a1)
        SD(ctx->r9, -0X8, ctx->r5);
            goto L_80070B04;
    }
    // 0x80070B1C: sd          $t1, -0x8($a1)
    SD(ctx->r9, -0X8, ctx->r5);
    // 0x80070B20: jr          $ra
    // 0x80070B24: nop

    return;
    // 0x80070B24: nop

;}
RECOMP_FUNC void timetrial_valid_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B288: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001B28C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B290: jal         0x800599A8
    // 0x8001B294: nop

    timetrial_map_id(rdram, ctx);
        goto after_0;
    // 0x8001B294: nop

    after_0:
    // 0x8001B298: jal         0x8006BD88
    // 0x8001B29C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    level_id(rdram, ctx);
        goto after_1;
    // 0x8001B29C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8001B2A0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B2A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B2A8: beq         $v0, $t6, L_8001B2B8
    if (ctx->r2 == ctx->r14) {
        // 0x8001B2AC: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8001B2B8;
    }
    // 0x8001B2AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001B2B0: b           L_8001B2D8
    // 0x8001B2B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001B2D8;
    // 0x8001B2B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B2B8:
    // 0x8001B2B8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8001B2BC: lh          $t8, -0x38D8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X38D8);
    // 0x8001B2C0: lh          $t7, -0x517E($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X517E);
    // 0x8001B2C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001B2C8: beq         $t7, $t8, L_8001B2D8
    if (ctx->r15 == ctx->r24) {
        // 0x8001B2CC: nop
    
            goto L_8001B2D8;
    }
    // 0x8001B2CC: nop

    // 0x8001B2D0: b           L_8001B2D8
    // 0x8001B2D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001B2D8;
    // 0x8001B2D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B2D8:
    // 0x8001B2D8: jr          $ra
    // 0x8001B2DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001B2DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void obj_init_animobject(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EFA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001EFA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001EFAC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001EFB0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001EFB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001EFB8: lw          $s1, 0x3C($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X3C);
    // 0x8001EFBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001EFC0: lbu         $t7, 0xB($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0XB);
    // 0x8001EFC4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001EFC8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8001EFCC: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8001EFD0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001EFD4: lw          $s0, 0x64($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X64);
    // 0x8001EFD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001EFDC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001EFE0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8001EFE4: bc1f        L_8001EFF4
    if (!c1cs) {
        // 0x8001EFE8: nop
    
            goto L_8001EFF4;
    }
    // 0x8001EFE8: nop

    // 0x8001EFEC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001EFF0: nop

L_8001EFF4:
    // 0x8001EFF4: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8001EFF8: lw          $t8, 0x40($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X40);
    // 0x8001EFFC: nop

    // 0x8001F000: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8001F004: sw          $zero, 0x78($a1)
    MEM_W(0X78, ctx->r5) = 0;
    // 0x8001F008: sw          $zero, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = 0;
    // 0x8001F00C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001F010: swc1        $f10, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f10.u32l;
    // 0x8001F014: lb          $v0, 0x22($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X22);
    // 0x8001F018: nop

    // 0x8001F01C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8001F020: bne         $at, $zero, L_8001F03C
    if (ctx->r1 != 0) {
        // 0x8001F024: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8001F03C;
    }
    // 0x8001F024: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8001F028: beq         $at, $zero, L_8001F03C
    if (ctx->r1 == 0) {
        // 0x8001F02C: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8001F03C;
    }
    // 0x8001F02C: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8001F030: sw          $t9, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->r25;
    // 0x8001F034: lb          $v0, 0x22($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X22);
    // 0x8001F038: nop

L_8001F03C:
    // 0x8001F03C: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8001F040: bne         $at, $zero, L_8001F054
    if (ctx->r1 != 0) {
        // 0x8001F044: slti        $at, $v0, 0x12
        ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
            goto L_8001F054;
    }
    // 0x8001F044: slti        $at, $v0, 0x12
    ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x8001F048: beq         $at, $zero, L_8001F054
    if (ctx->r1 == 0) {
        // 0x8001F04C: addiu       $t0, $v0, -0x9
        ctx->r8 = ADD32(ctx->r2, -0X9);
            goto L_8001F054;
    }
    // 0x8001F04C: addiu       $t0, $v0, -0x9
    ctx->r8 = ADD32(ctx->r2, -0X9);
    // 0x8001F050: sw          $t0, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->r8;
L_8001F054:
    // 0x8001F054: lwc1        $f16, 0xC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8001F058: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001F05C: swc1        $f16, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f16.u32l;
    // 0x8001F060: lwc1        $f18, 0x10($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8001F064: nop

    // 0x8001F068: swc1        $f18, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f18.u32l;
    // 0x8001F06C: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8001F070: nop

    // 0x8001F074: swc1        $f4, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f4.u32l;
    // 0x8001F078: lh          $t1, 0x0($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X0);
    // 0x8001F07C: nop

    // 0x8001F080: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x8001F084: lh          $t2, 0x4($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X4);
    // 0x8001F088: nop

    // 0x8001F08C: sh          $t2, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r10;
    // 0x8001F090: lh          $t3, 0x2($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X2);
    // 0x8001F094: nop

    // 0x8001F098: sh          $t3, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r11;
    // 0x8001F09C: sh          $zero, 0x26($s0)
    MEM_H(0X26, ctx->r16) = 0;
    // 0x8001F0A0: lb          $t4, 0x21($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X21);
    // 0x8001F0A4: nop

    // 0x8001F0A8: sb          $t4, 0x3D($s0)
    MEM_B(0X3D, ctx->r16) = ctx->r12;
    // 0x8001F0AC: lb          $t5, 0x10($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X10);
    // 0x8001F0B0: nop

    // 0x8001F0B4: sh          $t5, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r13;
    // 0x8001F0B8: lb          $t6, 0x14($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X14);
    // 0x8001F0BC: lwc1        $f16, 0x566C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X566C);
    // 0x8001F0C0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8001F0C4: lwc1        $f17, 0x5668($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X5668);
    // 0x8001F0C8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001F0CC: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8001F0D0: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x8001F0D4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8001F0D8: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8001F0DC: lh          $a0, 0xE($s1)
    ctx->r4 = MEM_H(ctx->r17, 0XE);
    // 0x8001F0E0: jal         0x8000C8B4
    // 0x8001F0E4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    normalise_time(rdram, ctx);
        goto after_0;
    // 0x8001F0E4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8001F0E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F0EC: sh          $v0, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r2;
    // 0x8001F0F0: lb          $t7, 0x12($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X12);
    // 0x8001F0F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001F0F8: sb          $t7, 0x3B($a1)
    MEM_B(0X3B, ctx->r5) = ctx->r15;
    // 0x8001F0FC: lbu         $t8, 0x16($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X16);
    // 0x8001F100: nop

    // 0x8001F104: sh          $t8, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r24;
    // 0x8001F108: lb          $t9, 0x17($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X17);
    // 0x8001F10C: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8001F110: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8001F114: nop

    // 0x8001F118: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001F11C: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8001F120: lbu         $t0, 0x18($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X18);
    // 0x8001F124: nop

    // 0x8001F128: sb          $t0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r8;
    // 0x8001F12C: lbu         $t1, 0x19($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X19);
    // 0x8001F130: nop

    // 0x8001F134: sb          $t1, 0x2E($s0)
    MEM_B(0X2E, ctx->r16) = ctx->r9;
    // 0x8001F138: lb          $t2, 0x2C($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X2C);
    // 0x8001F13C: nop

    // 0x8001F140: sb          $t2, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r10;
    // 0x8001F144: lb          $t3, 0x2D($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X2D);
    // 0x8001F148: nop

    // 0x8001F14C: sb          $t3, 0x3F($s0)
    MEM_B(0X3F, ctx->r16) = ctx->r11;
    // 0x8001F150: lb          $t4, 0x1A($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X1A);
    // 0x8001F154: nop

    // 0x8001F158: sb          $t4, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r12;
    // 0x8001F15C: lb          $t5, 0x1B($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X1B);
    // 0x8001F160: nop

    // 0x8001F164: sb          $t5, 0x32($s0)
    MEM_B(0X32, ctx->r16) = ctx->r13;
    // 0x8001F168: lb          $t6, 0x1C($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X1C);
    // 0x8001F16C: nop

    // 0x8001F170: sb          $t6, 0x33($s0)
    MEM_B(0X33, ctx->r16) = ctx->r14;
    // 0x8001F174: lb          $t7, 0x20($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X20);
    // 0x8001F178: sb          $zero, 0x2D($s0)
    MEM_B(0X2D, ctx->r16) = 0;
    // 0x8001F17C: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8001F180: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8001F184: sb          $t7, 0x34($s0)
    MEM_B(0X34, ctx->r16) = ctx->r15;
    // 0x8001F188: sw          $zero, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = 0;
    // 0x8001F18C: lh          $a0, 0x24($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X24);
    // 0x8001F190: jal         0x8000C8B4
    // 0x8001F194: nop

    normalise_time(rdram, ctx);
        goto after_1;
    // 0x8001F194: nop

    after_1:
    // 0x8001F198: sh          $v0, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r2;
    // 0x8001F19C: lb          $t8, 0x26($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X26);
    // 0x8001F1A0: nop

    // 0x8001F1A4: sb          $t8, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r24;
    // 0x8001F1A8: lb          $v1, 0x13($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X13);
    // 0x8001F1AC: nop

    // 0x8001F1B0: bltz        $v1, L_8001F1BC
    if (SIGNED(ctx->r3) < 0) {
        // 0x8001F1B4: nop
    
            goto L_8001F1BC;
    }
    // 0x8001F1B4: nop

    // 0x8001F1B8: sb          $v1, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r3;
L_8001F1BC:
    // 0x8001F1BC: lb          $t9, 0x1F($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X1F);
    // 0x8001F1C0: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x8001F1C4: sb          $t9, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r25;
    // 0x8001F1C8: lbu         $t0, 0x1E($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X1E);
    // 0x8001F1CC: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8001F1D0: sb          $t0, 0x38($s0)
    MEM_B(0X38, ctx->r16) = ctx->r8;
    // 0x8001F1D4: lb          $t1, 0x29($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X29);
    // 0x8001F1D8: nop

    // 0x8001F1DC: sb          $t1, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r9;
    // 0x8001F1E0: lb          $t2, 0x2E($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X2E);
    // 0x8001F1E4: nop

    // 0x8001F1E8: sb          $t2, 0x40($s0)
    MEM_B(0X40, ctx->r16) = ctx->r10;
    // 0x8001F1EC: lb          $t3, 0x2F($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X2F);
    // 0x8001F1F0: nop

    // 0x8001F1F4: sb          $t3, 0x41($s0)
    MEM_B(0X41, ctx->r16) = ctx->r11;
    // 0x8001F1F8: lb          $t4, 0x2B($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X2B);
    // 0x8001F1FC: sb          $t5, 0x42($s0)
    MEM_B(0X42, ctx->r16) = ctx->r13;
    // 0x8001F200: beq         $a0, $zero, L_8001F210
    if (ctx->r4 == 0) {
        // 0x8001F204: sb          $t4, 0x3C($s0)
        MEM_B(0X3C, ctx->r16) = ctx->r12;
            goto L_8001F210;
    }
    // 0x8001F204: sb          $t4, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r12;
    // 0x8001F208: jal         0x8000488C
    // 0x8001F20C: nop

    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x8001F20C: nop

    after_2:
L_8001F210:
    // 0x8001F210: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x8001F214: lb          $t6, 0x30($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X30);
    // 0x8001F218: sw          $s2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r18;
    // 0x8001F21C: sb          $zero, 0x45($s0)
    MEM_B(0X45, ctx->r16) = 0;
    // 0x8001F220: sb          $t6, 0x43($s0)
    MEM_B(0X43, ctx->r16) = ctx->r14;
    // 0x8001F224: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001F228: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001F22C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F230: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001F234: jr          $ra
    // 0x8001F238: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001F238: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_trigger_emitter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFE5C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AFE60: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AFE64: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800AFE68: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800AFE6C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800AFE70: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800AFE74: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800AFE78: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800AFE7C: lh          $v0, 0x4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X4);
    // 0x800AFE80: lw          $s4, 0x0($a1)
    ctx->r20 = MEM_W(ctx->r5, 0X0);
    // 0x800AFE84: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    // 0x800AFE88: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800AFE8C: beq         $t6, $zero, L_800AFEDC
    if (ctx->r14 == 0) {
        // 0x800AFE90: or          $s5, $a0, $zero
        ctx->r21 = ctx->r4 | 0;
            goto L_800AFEDC;
    }
    // 0x800AFE90: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800AFE94: jal         0x800B0BAC
    // 0x800AFE98: nop

    create_line_particle(rdram, ctx);
        goto after_0;
    // 0x800AFE98: nop

    after_0:
    // 0x800AFE9C: beq         $v0, $zero, L_800AFEAC
    if (ctx->r2 == 0) {
        // 0x800AFEA0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800AFEAC;
    }
    // 0x800AFEA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800AFEA4: jal         0x8000E9D0
    // 0x800AFEA8: nop

    add_particle_to_entity_list(rdram, ctx);
        goto after_1;
    // 0x800AFEA8: nop

    after_1:
L_800AFEAC:
    // 0x800AFEAC: lbu         $v0, 0x6($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X6);
    // 0x800AFEB0: lh          $t7, 0x4($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X4);
    // 0x800AFEB4: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x800AFEB8: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800AFEBC: andi        $t8, $t7, 0xDFFF
    ctx->r24 = ctx->r15 & 0XDFFF;
    // 0x800AFEC0: bne         $at, $zero, L_800AFED4
    if (ctx->r1 != 0) {
        // 0x800AFEC4: sh          $t8, 0x4($s2)
        MEM_H(0X4, ctx->r18) = ctx->r24;
            goto L_800AFED4;
    }
    // 0x800AFEC4: sh          $t8, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r24;
    // 0x800AFEC8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800AFECC: b           L_800AFFEC
    // 0x800AFED0: sb          $t9, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r25;
        goto L_800AFFEC;
    // 0x800AFED0: sb          $t9, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r25;
L_800AFED4:
    // 0x800AFED4: b           L_800AFFEC
    // 0x800AFED8: sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
        goto L_800AFFEC;
    // 0x800AFED8: sb          $v0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r2;
L_800AFEDC:
    // 0x800AFEDC: andi        $t0, $v0, 0x400
    ctx->r8 = ctx->r2 & 0X400;
    // 0x800AFEE0: beq         $t0, $zero, L_800AFF60
    if (ctx->r8 == 0) {
        // 0x800AFEE4: nop
    
            goto L_800AFF60;
    }
    // 0x800AFEE4: nop

    // 0x800AFEE8: lbu         $t1, 0x6($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X6);
    // 0x800AFEEC: lbu         $t2, 0x7($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X7);
    // 0x800AFEF0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800AFEF4: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800AFEF8: beq         $at, $zero, L_800AFFF0
    if (ctx->r1 == 0) {
        // 0x800AFEFC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800AFFF0;
    }
    // 0x800AFEFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AFF00: jal         0x800B0698
    // 0x800AFF04: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    create_point_particle(rdram, ctx);
        goto after_2;
    // 0x800AFF04: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800AFF08: lh          $t3, 0x4($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X4);
    // 0x800AFF0C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800AFF10: andi        $t4, $t3, 0xDFFF
    ctx->r12 = ctx->r11 & 0XDFFF;
    // 0x800AFF14: beq         $v0, $zero, L_800AFFEC
    if (ctx->r2 == 0) {
        // 0x800AFF18: sh          $t4, 0x4($s2)
        MEM_H(0X4, ctx->r18) = ctx->r12;
            goto L_800AFFEC;
    }
    // 0x800AFF18: sh          $t4, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r12;
    // 0x800AFF1C: jal         0x8000E9D0
    // 0x800AFF20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    add_particle_to_entity_list(rdram, ctx);
        goto after_3;
    // 0x800AFF20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800AFF24: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x800AFF28: lbu         $t5, 0x6($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X6);
    // 0x800AFF2C: ori         $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 | 0X2000;
    // 0x800AFF30: sw          $t7, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r15;
    // 0x800AFF34: sb          $t5, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r13;
    // 0x800AFF38: lbu         $t9, 0x6($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X6);
    // 0x800AFF3C: lw          $t8, 0xC($s2)
    ctx->r24 = MEM_W(ctx->r18, 0XC);
    // 0x800AFF40: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800AFF44: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800AFF48: sw          $s0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r16;
    // 0x800AFF4C: lbu         $t2, 0x6($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X6);
    // 0x800AFF50: nop

    // 0x800AFF54: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800AFF58: b           L_800AFFEC
    // 0x800AFF5C: sb          $t3, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r11;
        goto L_800AFFEC;
    // 0x800AFF5C: sb          $t3, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r11;
L_800AFF60:
    // 0x800AFF60: lh          $v0, 0xA($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XA);
    // 0x800AFF64: lh          $v1, 0x40($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X40);
    // 0x800AFF68: addiu       $s3, $zero, -0x2001
    ctx->r19 = ADD32(0, -0X2001);
    // 0x800AFF6C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AFF70: bne         $at, $zero, L_800AFFEC
    if (ctx->r1 != 0) {
        // 0x800AFF74: subu        $t4, $v0, $v1
        ctx->r12 = SUB32(ctx->r2, ctx->r3);
            goto L_800AFFEC;
    }
    // 0x800AFF74: subu        $t4, $v0, $v1
    ctx->r12 = SUB32(ctx->r2, ctx->r3);
L_800AFF78:
    // 0x800AFF78: sh          $t4, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r12;
    // 0x800AFF7C: lh          $t5, 0x42($s4)
    ctx->r13 = MEM_H(ctx->r20, 0X42);
    // 0x800AFF80: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800AFF84: blez        $t5, L_800AFFD4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800AFF88: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800AFFD4;
    }
    // 0x800AFF88: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800AFF8C:
    // 0x800AFF8C: jal         0x800B1130
    // 0x800AFF90: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    create_general_particle(rdram, ctx);
        goto after_4;
    // 0x800AFF90: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x800AFF94: beq         $v0, $zero, L_800AFFB0
    if (ctx->r2 == 0) {
        // 0x800AFF98: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800AFFB0;
    }
    // 0x800AFF98: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800AFF9C: jal         0x8000E9D0
    // 0x800AFFA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    add_particle_to_entity_list(rdram, ctx);
        goto after_5;
    // 0x800AFFA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x800AFFA4: lh          $a1, 0xA($s2)
    ctx->r5 = MEM_H(ctx->r18, 0XA);
    // 0x800AFFA8: jal         0x800B22FC
    // 0x800AFFAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    particle_update(rdram, ctx);
        goto after_6;
    // 0x800AFFAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_800AFFB0:
    // 0x800AFFB0: lh          $t6, 0x4($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X4);
    // 0x800AFFB4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AFFB8: and         $t7, $t6, $s3
    ctx->r15 = ctx->r14 & ctx->r19;
    // 0x800AFFBC: sh          $t7, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r15;
    // 0x800AFFC0: lh          $t9, 0x42($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X42);
    // 0x800AFFC4: nop

    // 0x800AFFC8: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AFFCC: bne         $at, $zero, L_800AFF8C
    if (ctx->r1 != 0) {
        // 0x800AFFD0: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800AFF8C;
    }
    // 0x800AFFD0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800AFFD4:
    // 0x800AFFD4: lh          $v0, 0xA($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XA);
    // 0x800AFFD8: lh          $v1, 0x40($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X40);
    // 0x800AFFDC: nop

    // 0x800AFFE0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AFFE4: beq         $at, $zero, L_800AFF78
    if (ctx->r1 == 0) {
        // 0x800AFFE8: subu        $t4, $v0, $v1
        ctx->r12 = SUB32(ctx->r2, ctx->r3);
            goto L_800AFF78;
    }
    // 0x800AFFE8: subu        $t4, $v0, $v1
    ctx->r12 = SUB32(ctx->r2, ctx->r3);
L_800AFFEC:
    // 0x800AFFEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800AFFF0:
    // 0x800AFFF0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800AFFF4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800AFFF8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800AFFFC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800B0000: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800B0004: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800B0008: jr          $ra
    // 0x800B000C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800B000C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void safe_mark_write_save_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EC48: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006EC4C: lw          $t6, 0x34EC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X34EC);
    // 0x8006EC50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EC54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EC58: bne         $t6, $zero, L_8006EC9C
    if (ctx->r14 != 0) {
        // 0x8006EC5C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8006EC9C;
    }
    // 0x8006EC5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006EC60: jal         0x8009C2D0
    // 0x8006EC64: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x8006EC64: nop

    after_0:
    // 0x8006EC68: bne         $v0, $zero, L_8006EC9C
    if (ctx->r2 != 0) {
        // 0x8006EC6C: addiu       $at, $zero, -0xC01
        ctx->r1 = ADD32(0, -0XC01);
            goto L_8006EC9C;
    }
    // 0x8006EC6C: addiu       $at, $zero, -0xC01
    ctx->r1 = ADD32(0, -0XC01);
    // 0x8006EC70: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EC74: addiu       $v0, $v0, -0x2C84
    ctx->r2 = ADD32(ctx->r2, -0X2C84);
    // 0x8006EC78: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8006EC7C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8006EC80: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8006EC84: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x8006EC88: sll         $t3, $t2, 10
    ctx->r11 = S32(ctx->r10 << 10);
    // 0x8006EC8C: ori         $t0, $t8, 0x40
    ctx->r8 = ctx->r24 | 0X40;
    // 0x8006EC90: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8006EC94: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x8006EC98: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8006EC9C:
    // 0x8006EC9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006ECA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006ECA4: jr          $ra
    // 0x8006ECA8: nop

    return;
    // 0x8006ECA8: nop

;}
RECOMP_FUNC void input_held(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A528: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A52C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8006A530: lbu         $t6, 0x1150($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1150);
    // 0x8006A534: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A538: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006A53C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8006A540: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006A544: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8006A548: lhu         $v0, 0x1110($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1110);
    // 0x8006A54C: jr          $ra
    // 0x8006A550: nop

    return;
    // 0x8006A550: nop

;}
RECOMP_FUNC void adventuretrack_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093A0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80093A10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093A14: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80093A18: jal         0x8009C4A8
    // 0x80093A1C: addiu       $a0, $a0, 0xFB4
    ctx->r4 = ADD32(ctx->r4, 0XFB4);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x80093A1C: addiu       $a0, $a0, 0xFB4
    ctx->r4 = ADD32(ctx->r4, 0XFB4);
    after_0:
    // 0x80093A20: jal         0x800C422C
    // 0x80093A24: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_1;
    // 0x80093A24: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80093A28: jal         0x80000B28
    // 0x80093A2C: nop

    music_change_on(rdram, ctx);
        goto after_2;
    // 0x80093A2C: nop

    after_2:
    // 0x80093A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80093A34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80093A38: jr          $ra
    // 0x80093A3C: nop

    return;
    // 0x80093A3C: nop

;}
RECOMP_FUNC void main_game_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_apply_launch_magic_codes(uint8_t*, recomp_context*); extern void dkr_telemetry_simulation_tick(uint8_t*, recomp_context*); dkr_apply_launch_magic_codes(rdram, ctx); dkr_telemetry_simulation_tick(rdram, ctx);
    // 0x8006C60C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C610: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C614: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8006C618: jal         0x800CD260
    // 0x8006C61C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    osSetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x8006C61C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x8006C620: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006C624: lw          $t6, -0x2C80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2C80);
    // 0x8006C628: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006C62C: bne         $t6, $at, L_8006C6AC
    if (ctx->r14 != ctx->r1) {
        // 0x8006C630: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8006C6AC;
    }
    // 0x8006C630: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006C634: lw          $t7, 0x34E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X34E8);
    // 0x8006C638: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006C63C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006C640: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8006C644: lw          $t9, 0x11F0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F0);
    // 0x8006C648: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C64C: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    // 0x8006C650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006C654: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006C658: jal         0x8007A2D0
    // 0x8006C65C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    rsp_segment(rdram, ctx);
        goto after_1;
    // 0x8006C65C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    after_1:
    // 0x8006C660: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C664: lw          $a2, 0x62D4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X62D4);
    // 0x8006C668: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C66C: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    // 0x8006C670: jal         0x8007A2D0
    // 0x8006C674: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rsp_segment(rdram, ctx);
        goto after_2;
    // 0x8006C674: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8006C678: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C67C: lw          $a2, 0x62E0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X62E0);
    // 0x8006C680: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C684: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    // 0x8006C688: jal         0x8007A2D0
    // 0x8006C68C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    rsp_segment(rdram, ctx);
        goto after_3;
    // 0x8006C68C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x8006C690: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C694: lw          $a2, 0x62D4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X62D4);
    // 0x8006C698: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C69C: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    // 0x8006C6A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8006C6A4: jal         0x8007A2D0
    // 0x8006C6A8: addiu       $a2, $a2, -0x500
    ctx->r6 = ADD32(ctx->r6, -0X500);
    rsp_segment(rdram, ctx);
        goto after_4;
    // 0x8006C6A8: addiu       $a2, $a2, -0x500
    ctx->r6 = ADD32(ctx->r6, -0X500);
    after_4:
L_8006C6AC:
    // 0x8006C6AC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8006C6B0: lb          $v1, -0x2C10($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X2C10);
    // 0x8006C6B4: nop

    // 0x8006C6B8: bne         $v1, $zero, L_8006C70C
    if (ctx->r3 != 0) {
        // 0x8006C6BC: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8006C70C;
    }
    // 0x8006C6BC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006C6C0: lw          $t0, 0x34E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X34E8);
    // 0x8006C6C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C6C8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8006C6CC: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8006C6D0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C6D4: lw          $a1, 0x11F8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X11F8);
    // 0x8006C6D8: lw          $a0, 0x11F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11F0);
    // 0x8006C6DC: jal         0x80077450
    // 0x8006C6E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gfxtask_run_xbus(rdram, ctx);
        goto after_5;
    // 0x8006C6E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8006C6E4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006C6E8: addiu       $a3, $a3, 0x34E8
    ctx->r7 = ADD32(ctx->r7, 0X34E8);
    // 0x8006C6EC: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x8006C6F0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8006C6F4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8006C6F8: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8006C6FC: andi        $t5, $t3, 0x1
    ctx->r13 = ctx->r11 & 0X1;
    // 0x8006C700: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x8006C704: lb          $v1, -0x2C10($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X2C10);
    // 0x8006C708: nop

L_8006C70C:
    // 0x8006C70C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006C710: beq         $v1, $zero, L_8006C724
    if (ctx->r3 == 0) {
        // 0x8006C714: addiu       $a3, $a3, 0x34E8
        ctx->r7 = ADD32(ctx->r7, 0X34E8);
            goto L_8006C724;
    }
    // 0x8006C714: addiu       $a3, $a3, 0x34E8
    ctx->r7 = ADD32(ctx->r7, 0X34E8);
    // 0x8006C718: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8006C71C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C720: sb          $t6, -0x2C10($at)
    MEM_B(-0X2C10, ctx->r1) = ctx->r14;
L_8006C724:
    extern void dkr_presentation_frame_begin(uint8_t*, recomp_context*); dkr_presentation_frame_begin(rdram, ctx);
    // 0x8006C724: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8006C728: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006C72C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8006C730: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8006C734: lw          $t8, 0x11F0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11F0);
    // 0x8006C738: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C73C: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    // 0x8006C740: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006C744: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8006C748: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8006C74C: lw          $t9, 0x1200($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1200);
    // 0x8006C750: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006C754: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C758: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8006C75C: lw          $t0, 0x1210($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1210);
    // 0x8006C760: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006C764: sw          $t9, 0x1208($at)
    MEM_W(0X1208, ctx->r1) = ctx->r25;
    // 0x8006C768: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C76C: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x8006C770: lw          $t1, 0x1220($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1220);
    // 0x8006C774: sw          $t0, 0x1218($at)
    MEM_W(0X1218, ctx->r1) = ctx->r8;
    // 0x8006C778: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C77C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006C780: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006C784: jal         0x8007A2D0
    // 0x8006C788: sw          $t1, 0x1228($at)
    MEM_W(0X1228, ctx->r1) = ctx->r9;
    rsp_segment(rdram, ctx);
        goto after_6;
    // 0x8006C788: sw          $t1, 0x1228($at)
    MEM_W(0X1228, ctx->r1) = ctx->r9;
    after_6:
    // 0x8006C78C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C790: lw          $a2, 0x62D8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X62D8);
    // 0x8006C794: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C798: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    // 0x8006C79C: jal         0x8007A2D0
    // 0x8006C7A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rsp_segment(rdram, ctx);
        goto after_7;
    // 0x8006C7A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8006C7A4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C7A8: lw          $a2, 0x62E0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X62E0);
    // 0x8006C7AC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C7B0: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    // 0x8006C7B4: jal         0x8007A2D0
    // 0x8006C7B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    rsp_segment(rdram, ctx);
        goto after_8;
    // 0x8006C7B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x8006C7BC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C7C0: lw          $a2, 0x62D8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X62D8);
    // 0x8006C7C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C7C8: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    // 0x8006C7CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8006C7D0: jal         0x8007A2D0
    // 0x8006C7D4: addiu       $a2, $a2, -0x500
    ctx->r6 = ADD32(ctx->r6, -0X500);
    rsp_segment(rdram, ctx);
        goto after_9;
    // 0x8006C7D4: addiu       $a2, $a2, -0x500
    ctx->r6 = ADD32(ctx->r6, -0X500);
    after_9:
    // 0x8006C7D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C7DC: jal         0x800780DC
    // 0x8006C7E0: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    rsp_init(rdram, ctx);
        goto after_10;
    // 0x8006C7E0: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    after_10:
    // 0x8006C7E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C7E8: jal         0x80078054
    // 0x8006C7EC: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    rdp_init(rdram, ctx);
        goto after_11;
    // 0x8006C7EC: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    after_11:
    // 0x8006C7F0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C7F4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C7F8: addiu       $a1, $a1, 0x1208
    ctx->r5 = ADD32(ctx->r5, 0X1208);
    // 0x8006C7FC: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    // 0x8006C800: jal         0x80077B9C
    // 0x8006C804: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bgdraw_render(rdram, ctx);
        goto after_12;
    // 0x8006C804: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x8006C808: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006C80C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006C810: lw          $a1, -0x2BFC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2BFC);
    // 0x8006C814: lw          $a0, -0x2C84($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2C84);
    // 0x8006C818: jal         0x8006A1C4
    // 0x8006C81C: nop

    input_update(rdram, ctx);
        goto after_13;
    // 0x8006C81C: nop

    after_13:
    // 0x8006C820: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C824: jal         0x800B76DC
    // 0x8006C828: sw          $v0, -0x2C84($at)
    MEM_W(-0X2C84, ctx->r1) = ctx->r2;
    get_lockup_status(rdram, ctx);
        goto after_14;
    // 0x8006C828: sw          $v0, -0x2C84($at)
    MEM_W(-0X2C84, ctx->r1) = ctx->r2;
    after_14:
    // 0x8006C82C: beq         $v0, $zero, L_8006C848
    if (ctx->r2 == 0) {
        // 0x8006C830: nop
    
            goto L_8006C848;
    }
    // 0x8006C830: nop

    // 0x8006C834: jal         0x800B7810
    // 0x8006C838: nop

    render_epc_lock_up_display(rdram, ctx);
        goto after_15;
    // 0x8006C838: nop

    after_15:
    // 0x8006C83C: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8006C840: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C844: sw          $t2, 0x34EC($at)
    MEM_W(0X34EC, ctx->r1) = ctx->r10;
L_8006C848:
    // 0x8006C848: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8006C84C: lb          $t3, -0x2C60($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X2C60);
    // 0x8006C850: nop

    // 0x8006C854: beq         $t3, $zero, L_8006C88C
    if (ctx->r11 == 0) {
        // 0x8006C858: lui         $v1, 0x98
        ctx->r3 = S32(0X98 << 16);
            goto L_8006C88C;
    }
    // 0x8006C858: lui         $v1, 0x98
    ctx->r3 = S32(0X98 << 16);
    // 0x8006C85C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006C860: ori         $v1, $v1, 0x9680
    ctx->r3 = ctx->r3 | 0X9680;
L_8006C864:
    // 0x8006C864: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8006C868: bne         $v0, $v1, L_8006C864
    if (ctx->r2 != ctx->r3) {
        // 0x8006C86C: nop
    
            goto L_8006C864;
    }
    // 0x8006C86C: nop

    // 0x8006C870: lui         $at, 0x131
    ctx->r1 = S32(0X131 << 16);
    // 0x8006C874: ori         $at, $at, 0x2D01
    ctx->r1 = ctx->r1 | 0X2D01;
    // 0x8006C878: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8006C87C: bne         $at, $zero, L_8006C88C
    if (ctx->r1 != 0) {
        // 0x8006C880: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006C88C;
    }
    // 0x8006C880: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006C884: jal         0x800B5EDC
    // 0x8006C888: addiu       $a0, $a0, 0x7134
    ctx->r4 = ADD32(ctx->r4, 0X7134);
    render_printf(rdram, ctx);
        goto after_16;
    // 0x8006C888: addiu       $a0, $a0, 0x7134
    ctx->r4 = ADD32(ctx->r4, 0X7134);
    after_16:
L_8006C88C:
    // 0x8006C88C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006C890: lw          $v0, 0x34EC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X34EC);
    // 0x8006C894: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006C898: beq         $v0, $at, L_8006C8C8
    if (ctx->r2 == ctx->r1) {
        // 0x8006C89C: nop
    
            goto L_8006C8C8;
    }
    // 0x8006C89C: nop

    // 0x8006C8A0: beq         $v0, $zero, L_8006C8EC
    if (ctx->r2 == 0) {
        // 0x8006C8A4: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006C8EC;
    }
    // 0x8006C8A4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006C8A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006C8AC: beq         $v0, $at, L_8006C8D8
    if (ctx->r2 == ctx->r1) {
        // 0x8006C8B0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006C8D8;
    }
    // 0x8006C8B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006C8B4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006C8B8: beq         $v0, $at, L_8006C900
    if (ctx->r2 == ctx->r1) {
        // 0x8006C8BC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8006C900;
    }
    // 0x8006C8BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006C8C0: b           L_8006C90C
    // 0x8006C8C4: nop

        goto L_8006C90C;
    // 0x8006C8C4: nop

L_8006C8C8:
    // 0x8006C8C8: jal         0x8006F43C
    // 0x8006C8CC: nop

    mode_intro(rdram, ctx);
        goto after_17;
    // 0x8006C8CC: nop

    after_17:
    // 0x8006C8D0: b           L_8006C90C
    // 0x8006C8D4: nop

        goto L_8006C90C;
    // 0x8006C8D4: nop

L_8006C8D8:
    // 0x8006C8D8: lw          $a0, -0x2BFC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2BFC);
    // 0x8006C8DC: jal         0x8006DCF8
    // 0x8006C8E0: nop

    mode_menu(rdram, ctx);
        goto after_18;
    // 0x8006C8E0: nop

    after_18:
    // 0x8006C8E4: b           L_8006C90C
    // 0x8006C8E8: nop

        goto L_8006C90C;
    // 0x8006C8E8: nop

L_8006C8EC:
    // 0x8006C8EC: lw          $a0, -0x2BFC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2BFC);
    // 0x8006C8F0: jal         0x8006CCF0
    // 0x8006C8F4: nop

    mode_game(rdram, ctx);
        goto after_19;
    // 0x8006C8F4: nop

    after_19:
    // 0x8006C8F8: b           L_8006C90C
    // 0x8006C8FC: nop

        goto L_8006C90C;
    // 0x8006C8FC: nop

L_8006C900:
    // 0x8006C900: lw          $a0, -0x2BFC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2BFC);
    // 0x8006C904: jal         0x800B77D4
    // 0x8006C908: nop

    mode_lockup(rdram, ctx);
        goto after_20;
    // 0x8006C908: nop

    after_20:
L_8006C90C:
    extern void dkr_netplay_authoritative_frame_commit(uint8_t*, recomp_context*); extern void dkr_magic_codes_frame_complete(uint8_t*, recomp_context*); dkr_netplay_authoritative_frame_commit(rdram, ctx); dkr_magic_codes_frame_complete(rdram, ctx);
    // 0x8006C90C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006C910: lbu         $a0, -0x2BF9($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X2BF9);
    // 0x8006C914: jal         0x80000D00
    // 0x8006C918: nop

    sound_update_queue(rdram, ctx);
        goto after_21;
    // 0x8006C918: nop

    after_21:
    // 0x8006C91C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C920: jal         0x800B5F78
    // 0x8006C924: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    debug_text_print(rdram, ctx);
        goto after_22;
    // 0x8006C924: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    after_22:
    // 0x8006C928: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C92C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C930: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C934: addiu       $a2, $a2, 0x1218
    ctx->r6 = ADD32(ctx->r6, 0X1218);
    // 0x8006C938: addiu       $a1, $a1, 0x1208
    ctx->r5 = ADD32(ctx->r5, 0X1208);
    // 0x8006C93C: jal         0x800C56FC
    // 0x8006C940: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    render_dialogue_boxes(rdram, ctx);
        goto after_23;
    // 0x8006C940: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    after_23:
    // 0x8006C944: jal         0x800C5620
    // 0x8006C948: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    dialogue_close(rdram, ctx);
        goto after_24;
    // 0x8006C948: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_24:
    // 0x8006C94C: jal         0x800C5494
    // 0x8006C950: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    dialogue_clear(rdram, ctx);
        goto after_25;
    // 0x8006C950: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_25:
    // 0x8006C954: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006C958: lw          $a0, -0x2BFC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2BFC);
    // 0x8006C95C: jal         0x800C0494
    // 0x8006C960: nop

    transition_update(rdram, ctx);
        goto after_26;
    // 0x8006C960: nop

    after_26:
    // 0x8006C964: beq         $v0, $zero, L_8006C984
    if (ctx->r2 == 0) {
        // 0x8006C968: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8006C984;
    }
    // 0x8006C968: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C96C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006C970: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006C974: addiu       $a2, $a2, 0x1218
    ctx->r6 = ADD32(ctx->r6, 0X1218);
    // 0x8006C978: addiu       $a1, $a1, 0x1208
    ctx->r5 = ADD32(ctx->r5, 0X1208);
    // 0x8006C97C: jal         0x800C05C8
    // 0x8006C980: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    transition_render(rdram, ctx);
        goto after_27;
    // 0x8006C980: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    after_27:
L_8006C984:
    // 0x8006C984: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006C988: lw          $t4, 0x3520($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3520);
    // 0x8006C98C: nop

    // 0x8006C990: slti        $at, $t4, 0x8
    ctx->r1 = SIGNED(ctx->r12) < 0X8 ? 1 : 0;
    // 0x8006C994: bne         $at, $zero, L_8006C9BC
    if (ctx->r1 != 0) {
        // 0x8006C998: nop
    
            goto L_8006C9BC;
    }
    // 0x8006C998: nop

    // 0x8006C99C: jal         0x8006F4C8
    // 0x8006C9A0: nop

    is_controller_missing(rdram, ctx);
        goto after_28;
    // 0x8006C9A0: nop

    after_28:
    // 0x8006C9A4: beq         $v0, $zero, L_8006C9BC
    if (ctx->r2 == 0) {
        // 0x8006C9A8: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8006C9BC;
    }
    // 0x8006C9A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C9AC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006C9B0: lw          $a1, -0x2BFC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2BFC);
    // 0x8006C9B4: jal         0x800829F8
    // 0x8006C9B8: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    menu_missing_controller(rdram, ctx);
        goto after_29;
    // 0x8006C9B8: addiu       $a0, $a0, 0x11F8
    ctx->r4 = ADD32(ctx->r4, 0X11F8);
    after_29:
L_8006C9BC:
    // 0x8006C9BC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006C9C0: lw          $v0, 0x11F8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X11F8);
    // 0x8006C9C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C9C8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8006C9CC: sw          $t5, 0x11F8($at)
    MEM_W(0X11F8, ctx->r1) = ctx->r13;
    // 0x8006C9D0: lui         $t6, 0xE900
    ctx->r14 = S32(0XE900 << 16);
    // 0x8006C9D4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8006C9D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006C9DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006C9E0: lw          $v0, 0x11F8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X11F8);
    // 0x8006C9E4: lui         $t8, 0xB800
    ctx->r24 = S32(0XB800 << 16);
    // 0x8006C9E8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8006C9EC: sw          $t7, 0x11F8($at)
    MEM_W(0X11F8, ctx->r1) = ctx->r15;
    // 0x8006C9F0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006C9F4: jal         0x80066610
    // 0x8006C9F8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    copy_viewports_to_stack(rdram, ctx);
        goto after_30;
    // 0x8006C9F8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    after_30:
    // 0x8006C9FC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006CA00: lb          $t9, -0x2C10($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X2C10);
    // 0x8006CA04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006CA08: beq         $t9, $at, L_8006CA34
    if (ctx->r25 == ctx->r1) {
        // 0x8006CA0C: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_8006CA34;
    }
    // 0x8006CA0C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006CA10: lb          $t0, -0x2C74($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2C74);
    // 0x8006CA14: nop

    // 0x8006CA18: bne         $t0, $zero, L_8006CA3C
    if (ctx->r8 != 0) {
        // 0x8006CA1C: nop
    
            goto L_8006CA3C;
    }
    // 0x8006CA1C: nop

    // 0x8006CA20: jal         0x80077A54
    // 0x8006CA24: nop

    gfxtask_wait(rdram, ctx);
        goto after_31;
    // 0x8006CA24: nop

    after_31:
    // 0x8006CA28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CA2C: b           L_8006CA3C
    // 0x8006CA30: sw          $v0, -0x2C80($at)
    MEM_W(-0X2C80, ctx->r1) = ctx->r2;
        goto L_8006CA3C;
    // 0x8006CA30: sw          $v0, -0x2C80($at)
    MEM_W(-0X2C80, ctx->r1) = ctx->r2;
L_8006CA34:
    // 0x8006CA34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CA38: sb          $zero, -0x2C10($at)
    MEM_B(-0X2C10, ctx->r1) = 0;
L_8006CA3C:
    // 0x8006CA3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CA40: jal         0x80071198
    // 0x8006CA44: sb          $zero, -0x2C74($at)
    MEM_B(-0X2C74, ctx->r1) = 0;
    mempool_free_queue_clear(rdram, ctx);
        goto after_32;
    // 0x8006CA44: sb          $zero, -0x2C74($at)
    MEM_B(-0X2C74, ctx->r1) = 0;
    after_32:
    // 0x8006CA48: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006CA4C: lb          $t1, 0x3515($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X3515);
    // 0x8006CA50: nop

    // 0x8006CA54: bne         $t1, $zero, L_8006CA64
    if (ctx->r9 != 0) {
        // 0x8006CA58: nop
    
            goto L_8006CA64;
    }
    // 0x8006CA58: nop

    // 0x8006CA5C: jal         0x80066520
    // 0x8006CA60: nop

    disable_cutscene_camera(rdram, ctx);
        goto after_33;
    // 0x8006CA60: nop

    after_33:
L_8006CA64:
    // 0x8006CA64: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8006CA68: lb          $t2, -0x2C10($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X2C10);
    // 0x8006CA6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006CA70: bne         $t2, $at, L_8006CAA8
    if (ctx->r10 != ctx->r1) {
        // 0x8006CA74: lui         $t3, 0x8000
        ctx->r11 = S32(0X8000 << 16);
            goto L_8006CAA8;
    }
    // 0x8006CA74: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8006CA78: lw          $t3, 0x300($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X300);
    // 0x8006CA7C: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x8006CA80: bne         $t3, $zero, L_8006CA90
    if (ctx->r11 != 0) {
        // 0x8006CA84: ori         $v0, $v0, 0x5800
        ctx->r2 = ctx->r2 | 0X5800;
            goto L_8006CA90;
    }
    // 0x8006CA84: ori         $v0, $v0, 0x5800
    ctx->r2 = ctx->r2 | 0X5800;
    // 0x8006CA88: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x8006CA8C: ori         $v0, $v0, 0x9400
    ctx->r2 = ctx->r2 | 0X9400;
L_8006CA90:
    // 0x8006CA90: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006CA94: lw          $a1, 0x62D4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X62D4);
    // 0x8006CA98: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006CA9C: lw          $a0, 0x62D8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X62D8);
    // 0x8006CAA0: jal         0x80070B04
    // 0x8006CAA4: addu        $a2, $a1, $v0
    ctx->r6 = ADD32(ctx->r5, ctx->r2);
    dmacopy_doubleword(rdram, ctx);
        goto after_34;
    // 0x8006CAA4: addu        $a2, $a1, $v0
    ctx->r6 = ADD32(ctx->r5, ctx->r2);
    after_34:
L_8006CAA8:
    // 0x8006CAA8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CAAC: lw          $a0, -0x2C80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2C80);
    // 0x8006CAB0: jal         0x8007A98C
    // 0x8006CAB4: nop

    fb_update(rdram, ctx);
        goto after_35;
    // 0x8006CAB4: nop

    after_35:
    // 0x8006CAB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CABC: sw          $v0, -0x2BFC($at)
    MEM_W(-0X2BFC, ctx->r1) = ctx->r2;
    // 0x8006CAC0: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x8006CAC4: bne         $at, $zero, L_8006CAD4
    if (ctx->r1 != 0) {
        // 0x8006CAC8: addiu       $t4, $zero, 0x6
        ctx->r12 = ADD32(0, 0X6);
            goto L_8006CAD4;
    }
    // 0x8006CAC8: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x8006CACC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CAD0: sw          $t4, -0x2BFC($at)
    MEM_W(-0X2BFC, ctx->r1) = ctx->r12;
L_8006CAD4:
    // 0x8006CAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CAD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CADC: jr          $ra
    // 0x8006CAE0: nop

    return;
    // 0x8006CAE0: nop

;}
RECOMP_FUNC void gfxtask_run_fifo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077734: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80077738: addiu       $v1, $v1, -0x1B28
    ctx->r3 = ADD32(ctx->r3, -0X1B28);
    // 0x8007773C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80077740: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077744: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80077748: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007774C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80077750: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80077754: addiu       $t7, $t7, 0x6020
    ctx->r15 = ADD32(ctx->r15, 0X6020);
    // 0x80077758: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007775C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80077760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077764: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80077768: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8007776C: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x80077770: bne         $t8, $at, L_8007777C
    if (ctx->r24 != ctx->r1) {
        // 0x80077774: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8007777C;
    }
    // 0x80077774: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80077778: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8007777C:
    // 0x8007777C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80077780: subu        $t0, $a1, $a0
    ctx->r8 = SUB32(ctx->r5, ctx->r4);
    // 0x80077784: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80077788: addiu       $v0, $v0, -0x7B40
    ctx->r2 = ADD32(ctx->r2, -0X7B40);
    // 0x8007778C: sra         $t1, $t0, 3
    ctx->r9 = S32(SIGNED(ctx->r8) >> 3);
    // 0x80077790: addiu       $t5, $t5, -0x7A70
    ctx->r13 = ADD32(ctx->r13, -0X7A70);
    // 0x80077794: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80077798: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8007779C: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800777A0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800777A4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800777A8: subu        $t6, $t5, $v0
    ctx->r14 = SUB32(ctx->r13, ctx->r2);
    // 0x800777AC: addiu       $t7, $t7, -0x6870
    ctx->r15 = ADD32(ctx->r15, -0X6870);
    // 0x800777B0: addiu       $t8, $t8, -0x5C60
    ctx->r24 = ADD32(ctx->r24, -0X5C60);
    // 0x800777B4: sw          $t2, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r10;
    // 0x800777B8: sw          $t3, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r11;
    // 0x800777BC: sw          $t4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r12;
    // 0x800777C0: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x800777C4: sw          $t8, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r24;
    // 0x800777C8: sw          $t6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r14;
    // 0x800777CC: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x800777D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800777D4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800777D8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800777DC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800777E0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800777E4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800777E8: sw          $t9, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r25;
    // 0x800777EC: addiu       $t0, $t0, 0x42A0
    ctx->r8 = ADD32(ctx->r8, 0X42A0);
    // 0x800777F0: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x800777F4: addiu       $t2, $t2, 0x46A0
    ctx->r10 = ADD32(ctx->r10, 0X46A0);
    // 0x800777F8: addiu       $t3, $t3, 0x5EA0
    ctx->r11 = ADD32(ctx->r11, 0X5EA0);
    // 0x800777FC: addiu       $t4, $t4, 0x71B0
    ctx->r12 = ADD32(ctx->r12, 0X71B0);
    // 0x80077800: addiu       $t5, $zero, 0xA00
    ctx->r13 = ADD32(0, 0XA00);
    // 0x80077804: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80077808: addiu       $t7, $t7, 0x5ED8
    ctx->r15 = ADD32(ctx->r15, 0X5ED8);
    // 0x8007780C: addiu       $t8, $t8, -0x1B70
    ctx->r24 = ADD32(ctx->r24, -0X1B70);
    // 0x80077810: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x80077814: sw          $v0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r2;
    // 0x80077818: sw          $t0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r8;
    // 0x8007781C: sw          $t1, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r9;
    // 0x80077820: sw          $t2, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r10;
    // 0x80077824: sw          $t3, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r11;
    // 0x80077828: sw          $t4, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r12;
    // 0x8007782C: sw          $t5, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r13;
    // 0x80077830: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80077834: sw          $t6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r14;
    // 0x80077838: sw          $t7, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r15;
    // 0x8007783C: sw          $t8, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->r24;
    // 0x80077840: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80077844: lw          $t9, 0x62D4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X62D4);
    // 0x80077848: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x8007784C: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x80077850: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80077854: sw          $v0, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->r2;
    // 0x80077858: sw          $v0, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->r2;
    // 0x8007785C: sw          $v1, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->r3;
    // 0x80077860: sw          $v1, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r3;
    // 0x80077864: sw          $zero, 0x68($a3)
    MEM_W(0X68, ctx->r7) = 0;
    // 0x80077868: sw          $t9, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r25;
    // 0x8007786C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80077870: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80077874: beq         $t0, $zero, L_80077880
    if (ctx->r8 == 0) {
        // 0x80077878: addiu       $t1, $t1, 0x5EA0
        ctx->r9 = ADD32(ctx->r9, 0X5EA0);
            goto L_80077880;
    }
    // 0x80077878: addiu       $t1, $t1, 0x5EA0
    ctx->r9 = ADD32(ctx->r9, 0X5EA0);
    // 0x8007787C: sw          $t1, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r9;
L_80077880:
    // 0x80077880: jal         0x800D18A0
    // 0x80077884: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80077884: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80077888: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007788C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80077890: lw          $a0, 0x6100($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6100);
    // 0x80077894: jal         0x800C8E30
    // 0x80077898: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80077898: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8007789C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800778A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800778A4: beq         $t2, $zero, L_800778B8
    if (ctx->r10 == 0) {
        // 0x800778A8: addiu       $a0, $a0, 0x5EA0
        ctx->r4 = ADD32(ctx->r4, 0X5EA0);
            goto L_800778B8;
    }
    // 0x800778A8: addiu       $a0, $a0, 0x5EA0
    ctx->r4 = ADD32(ctx->r4, 0X5EA0);
    // 0x800778AC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800778B0: jal         0x800C8BB0
    // 0x800778B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800778B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_800778B8:
    // 0x800778B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800778BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800778C0: jr          $ra
    // 0x800778C4: nop

    return;
    // 0x800778C4: nop

;}
RECOMP_FUNC void set_camera_shake_by_distance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069E14: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80069E18: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80069E1C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80069E20: addiu       $s2, $s2, 0xCE0
    ctx->r18 = ADD32(ctx->r18, 0XCE0);
    // 0x80069E24: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80069E28: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x80069E2C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80069E30: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80069E34: mtc1        $a2, $f28
    ctx->f28.u32l = ctx->r6;
    // 0x80069E38: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80069E3C: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80069E40: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80069E44: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80069E48: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80069E4C: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x80069E50: mov.s       $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    ctx->f26.fl = ctx->f14.fl;
    // 0x80069E54: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80069E58: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80069E5C: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80069E60: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80069E64: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80069E68: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80069E6C: bltz        $t6, L_80069EE8
    if (SIGNED(ctx->r14) < 0) {
        // 0x80069E70: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80069EE8;
    }
    // 0x80069E70: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80069E74: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80069E78: lwc1        $f22, 0x60($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80069E7C: addiu       $s0, $s0, 0xAC0
    ctx->r16 = ADD32(ctx->r16, 0XAC0);
L_80069E80:
    // 0x80069E80: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80069E84: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80069E88: sub.s       $f0, $f24, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x80069E8C: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80069E90: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80069E94: sub.s       $f2, $f26, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f26.fl - ctx->f6.fl;
    // 0x80069E98: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80069E9C: sub.s       $f14, $f28, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f28.fl - ctx->f8.fl;
    // 0x80069EA0: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80069EA4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80069EA8: jal         0x800C9AD0
    // 0x80069EAC: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80069EAC: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x80069EB0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80069EB4: nop

    // 0x80069EB8: bc1f        L_80069ED4
    if (!c1cs) {
        // 0x80069EBC: nop
    
            goto L_80069ED4;
    }
    // 0x80069EBC: nop

    // 0x80069EC0: sub.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x80069EC4: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80069EC8: nop

    // 0x80069ECC: div.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80069ED0: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
L_80069ED4:
    // 0x80069ED4: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80069ED8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80069EDC: slt         $at, $t7, $s1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80069EE0: beq         $at, $zero, L_80069E80
    if (ctx->r1 == 0) {
        // 0x80069EE4: addiu       $s0, $s0, 0x44
        ctx->r16 = ADD32(ctx->r16, 0X44);
            goto L_80069E80;
    }
    // 0x80069EE4: addiu       $s0, $s0, 0x44
    ctx->r16 = ADD32(ctx->r16, 0X44);
L_80069EE8:
    // 0x80069EE8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80069EEC: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80069EF0: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80069EF4: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80069EF8: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80069EFC: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80069F00: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80069F04: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80069F08: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80069F0C: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80069F10: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80069F14: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80069F18: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80069F1C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80069F20: jr          $ra
    // 0x80069F24: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80069F24: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8007C660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C660: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007C664: andi        $t7, $a0, 0x8000
    ctx->r15 = ctx->r4 & 0X8000;
    // 0x8007C668: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8007C66C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8007C670: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8007C674: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8007C678: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8007C67C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007C680: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007C684: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007C688: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007C68C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007C690: beq         $t7, $zero, L_8007C6A0
    if (ctx->r15 == 0) {
        // 0x8007C694: sw          $a0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r4;
            goto L_8007C6A0;
    }
    // 0x8007C694: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8007C698: b           L_8007C830
    // 0x8007C69C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C830;
    // 0x8007C69C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C6A0:
    // 0x8007C6A0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8007C6A4: addiu       $s3, $s3, 0x6370
    ctx->r19 = ADD32(ctx->r19, 0X6370);
    // 0x8007C6A8: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8007C6AC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8007C6B0: bne         $t8, $zero, L_8007C818
    if (ctx->r24 != 0) {
        // 0x8007C6B4: addiu       $s0, $s0, 0x6338
        ctx->r16 = ADD32(ctx->r16, 0X6338);
            goto L_8007C818;
    }
    // 0x8007C6B4: addiu       $s0, $s0, 0x6338
    ctx->r16 = ADD32(ctx->r16, 0X6338);
    // 0x8007C6B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8007C6BC: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007C6C0: jal         0x80070C9C
    // 0x8007C6C4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8007C6C4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    after_0:
    // 0x8007C6C8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8007C6CC: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8007C6D0: blez        $t9, L_8007C700
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8007C6D4: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8007C700;
    }
    // 0x8007C6D4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8007C6D8:
    // 0x8007C6D8: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8007C6DC: nop

    // 0x8007C6E0: addu        $t1, $t0, $s4
    ctx->r9 = ADD32(ctx->r8, ctx->r20);
    // 0x8007C6E4: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x8007C6E8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8007C6EC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8007C6F0: slt         $at, $s4, $t2
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007C6F4: bne         $at, $zero, L_8007C6D8
    if (ctx->r1 != 0) {
        // 0x8007C6F8: nop
    
            goto L_8007C6D8;
    }
    // 0x8007C6F8: nop

    // 0x8007C6FC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8007C700:
    // 0x8007C700: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8007C704: addiu       $fp, $fp, 0x6354
    ctx->r30 = ADD32(ctx->r30, 0X6354);
    // 0x8007C708: lw          $t3, 0x0($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X0);
    // 0x8007C70C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8007C710: blez        $t3, L_8007C818
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8007C714: lui         $s7, 0x8012
        ctx->r23 = S32(0X8012 << 16);
            goto L_8007C818;
    }
    // 0x8007C714: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8007C718: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8007C71C: addiu       $s6, $s6, 0x6350
    ctx->r22 = ADD32(ctx->r22, 0X6350);
    // 0x8007C720: addiu       $s7, $s7, 0x6348
    ctx->r23 = ADD32(ctx->r23, 0X6348);
    // 0x8007C724: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8007C728:
    // 0x8007C728: lw          $t4, 0x0($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X0);
    // 0x8007C72C: lw          $s1, 0x0($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X0);
    // 0x8007C730: addu        $v0, $t4, $s5
    ctx->r2 = ADD32(ctx->r12, ctx->r21);
    // 0x8007C734: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007C738: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8007C73C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8007C740: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007C744: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8007C748: jal         0x80076E68
    // 0x8007C74C: subu        $a3, $t5, $a2
    ctx->r7 = SUB32(ctx->r13, ctx->r6);
    asset_load(rdram, ctx);
        goto after_1;
    // 0x8007C74C: subu        $a3, $t5, $a2
    ctx->r7 = SUB32(ctx->r13, ctx->r6);
    after_1:
    // 0x8007C750: lh          $t6, 0x2($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2);
    // 0x8007C754: nop

    // 0x8007C758: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8007C75C: lbu         $v1, 0xC($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0XC);
    // 0x8007C760: nop

    // 0x8007C764: blez        $v1, L_8007C804
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007C768: andi        $a0, $v1, 0x3
        ctx->r4 = ctx->r3 & 0X3;
            goto L_8007C804;
    }
    // 0x8007C768: andi        $a0, $v1, 0x3
    ctx->r4 = ctx->r3 & 0X3;
    // 0x8007C76C: beq         $a0, $zero, L_8007C79C
    if (ctx->r4 == 0) {
        // 0x8007C770: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8007C79C;
    }
    // 0x8007C770: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007C774:
    // 0x8007C774: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8007C778: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x8007C77C: nop

    // 0x8007C780: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8007C784: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x8007C788: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007C78C: bne         $v0, $s0, L_8007C774
    if (ctx->r2 != ctx->r16) {
        // 0x8007C790: sb          $s2, 0x0($t1)
        MEM_B(0X0, ctx->r9) = ctx->r18;
            goto L_8007C774;
    }
    // 0x8007C790: sb          $s2, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r18;
    // 0x8007C794: beq         $s0, $v1, L_8007C804
    if (ctx->r16 == ctx->r3) {
        // 0x8007C798: nop
    
            goto L_8007C804;
    }
    // 0x8007C798: nop

L_8007C79C:
    // 0x8007C79C: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x8007C7A0: lh          $t3, 0x0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X0);
    // 0x8007C7A4: nop

    // 0x8007C7A8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8007C7AC: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8007C7B0: sb          $s2, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r18;
    // 0x8007C7B4: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x8007C7B8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8007C7BC: nop

    // 0x8007C7C0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007C7C4: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x8007C7C8: sb          $s2, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r18;
    // 0x8007C7CC: lh          $t1, 0x0($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X0);
    // 0x8007C7D0: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x8007C7D4: nop

    // 0x8007C7D8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8007C7DC: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x8007C7E0: sb          $s2, 0x2($t3)
    MEM_B(0X2, ctx->r11) = ctx->r18;
    // 0x8007C7E4: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x8007C7E8: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8007C7EC: nop

    // 0x8007C7F0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8007C7F4: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8007C7F8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8007C7FC: bne         $s0, $v1, L_8007C79C
    if (ctx->r16 != ctx->r3) {
        // 0x8007C800: sb          $s2, 0x3($t7)
        MEM_B(0X3, ctx->r15) = ctx->r18;
            goto L_8007C79C;
    }
    // 0x8007C800: sb          $s2, 0x3($t7)
    MEM_B(0X3, ctx->r15) = ctx->r18;
L_8007C804:
    // 0x8007C804: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8007C808: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8007C80C: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8007C810: bne         $at, $zero, L_8007C728
    if (ctx->r1 != 0) {
        // 0x8007C814: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_8007C728;
    }
    // 0x8007C814: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8007C818:
    // 0x8007C818: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8007C81C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8007C820: nop

    // 0x8007C824: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8007C828: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x8007C82C: nop

L_8007C830:
    // 0x8007C830: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8007C834: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007C838: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C83C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007C840: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8007C844: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007C848: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C84C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8007C850: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8007C854: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8007C858: jr          $ra
    // 0x8007C85C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8007C85C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mempool_alloc_fixed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070EF8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80070EFC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80070F00: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80070F04: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80070F08: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80070F0C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80070F10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80070F14: jal         0x8006F510
    // 0x80070F18: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80070F18: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_0:
    // 0x80070F1C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80070F20: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80070F24: addiu       $v0, $v0, 0x3580
    ctx->r2 = ADD32(ctx->r2, 0X3580);
    // 0x80070F28: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80070F2C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80070F30: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80070F34: bne         $t7, $t8, L_80070F50
    if (ctx->r15 != ctx->r24) {
        // 0x80070F38: andi        $t9, $s2, 0xF
        ctx->r25 = ctx->r18 & 0XF;
            goto L_80070F50;
    }
    // 0x80070F38: andi        $t9, $s2, 0xF
    ctx->r25 = ctx->r18 & 0XF;
    // 0x80070F3C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80070F40: jal         0x8006F53C
    // 0x80070F44: nop

    interrupts_enable(rdram, ctx);
        goto after_1;
    // 0x80070F44: nop

    after_1:
    // 0x80070F48: b           L_80071098
    // 0x80070F4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80071098;
    // 0x80070F4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80070F50:
    // 0x80070F50: beq         $t9, $zero, L_80070F64
    if (ctx->r25 == 0) {
        // 0x80070F54: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80070F64;
    }
    // 0x80070F54: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80070F58: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80070F5C: and         $t2, $s2, $at
    ctx->r10 = ctx->r18 & ctx->r1;
    // 0x80070F60: addiu       $s2, $t2, 0x10
    ctx->r18 = ADD32(ctx->r10, 0X10);
L_80070F64:
    // 0x80070F64: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80070F68: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80070F6C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_80070F70:
    // 0x80070F70: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070F74: mflo        $t3
    ctx->r11 = lo;
    // 0x80070F78: addu        $v1, $t3, $t1
    ctx->r3 = ADD32(ctx->r11, ctx->r9);
    // 0x80070F7C: lh          $t4, 0x8($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X8);
    // 0x80070F80: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80070F84: bne         $t4, $zero, L_80071078
    if (ctx->r12 != 0) {
        // 0x80070F88: nop
    
            goto L_80071078;
    }
    // 0x80070F88: nop

    // 0x80070F8C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80070F90: nop

    // 0x80070F94: sltu        $at, $s1, $a0
    ctx->r1 = ctx->r17 < ctx->r4 ? 1 : 0;
    // 0x80070F98: bne         $at, $zero, L_80071078
    if (ctx->r1 != 0) {
        // 0x80070F9C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80071078;
    }
    // 0x80070F9C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80070FA0: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x80070FA4: addu        $t7, $s1, $s2
    ctx->r15 = ADD32(ctx->r17, ctx->r18);
    // 0x80070FA8: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80070FAC: sltu        $at, $t6, $t7
    ctx->r1 = ctx->r14 < ctx->r15 ? 1 : 0;
    // 0x80070FB0: bne         $at, $zero, L_80071078
    if (ctx->r1 != 0) {
        // 0x80070FB4: nop
    
            goto L_80071078;
    }
    // 0x80070FB4: nop

    // 0x80070FB8: bne         $s1, $a0, L_80071004
    if (ctx->r17 != ctx->r4) {
        // 0x80070FBC: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80071004;
    }
    // 0x80070FBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80070FC0: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80070FC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80070FC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80070FCC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80070FD0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80070FD4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80070FD8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x80070FDC: jal         0x8007178C
    // 0x80070FE0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    mempool_slot_assign(rdram, ctx);
        goto after_2;
    // 0x80070FE0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_2:
    // 0x80070FE4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80070FE8: jal         0x8006F53C
    // 0x80070FEC: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x80070FEC: nop

    after_3:
    // 0x80070FF0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80070FF4: nop

    // 0x80070FF8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80070FFC: b           L_8007109C
    // 0x80071000: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8007109C;
    // 0x80071000: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80071004:
    // 0x80071004: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80071008: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007100C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80071010: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80071014: subu        $a2, $s1, $v0
    ctx->r6 = SUB32(ctx->r17, ctx->r2);
    // 0x80071018: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8007101C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80071020: jal         0x8007178C
    // 0x80071024: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    mempool_slot_assign(rdram, ctx);
        goto after_4;
    // 0x80071024: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_4:
    // 0x80071028: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8007102C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80071030: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80071034: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80071038: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8007103C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80071040: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80071044: jal         0x8007178C
    // 0x80071048: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    mempool_slot_assign(rdram, ctx);
        goto after_5;
    // 0x80071048: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_5:
    // 0x8007104C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80071050: jal         0x8006F53C
    // 0x80071054: nop

    interrupts_enable(rdram, ctx);
        goto after_6;
    // 0x80071054: nop

    after_6:
    // 0x80071058: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8007105C: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071060: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80071064: mflo        $t4
    ctx->r12 = lo;
    // 0x80071068: addu        $t5, $t4, $t1
    ctx->r13 = ADD32(ctx->r12, ctx->r9);
    // 0x8007106C: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x80071070: b           L_8007109C
    // 0x80071074: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8007109C;
    // 0x80071074: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80071078:
    // 0x80071078: lh          $s0, 0xC($a1)
    ctx->r16 = MEM_H(ctx->r5, 0XC);
    // 0x8007107C: nop

    // 0x80071080: bne         $s0, $a2, L_80070F70
    if (ctx->r16 != ctx->r6) {
        // 0x80071084: nop
    
            goto L_80070F70;
    }
    // 0x80071084: nop

    // 0x80071088: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8007108C: jal         0x8006F53C
    // 0x80071090: nop

    interrupts_enable(rdram, ctx);
        goto after_7;
    // 0x80071090: nop

    after_7:
    // 0x80071094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80071098:
    // 0x80071098: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8007109C:
    // 0x8007109C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800710A0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800710A4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800710A8: jr          $ra
    // 0x800710AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800710AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void lights_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031BB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031BBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031BC0: jal         0x80031B60
    // 0x80031BC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    lights_free(rdram, ctx);
        goto after_0;
    // 0x80031BC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80031BC8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80031BCC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80031BD0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80031BD4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80031BD8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80031BDC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80031BE0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80031BE4: addiu       $a2, $a2, -0x36A8
    ctx->r6 = ADD32(ctx->r6, -0X36A8);
    // 0x80031BE8: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x80031BEC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80031BF0: sll         $a0, $t7, 2
    ctx->r4 = S32(ctx->r15 << 2);
    // 0x80031BF4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80031BF8: jal         0x80070C9C
    // 0x80031BFC: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80031BFC: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    after_1:
    // 0x80031C00: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80031C04: addiu       $a2, $a2, -0x36A8
    ctx->r6 = ADD32(ctx->r6, -0X36A8);
    // 0x80031C08: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80031C0C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80031C10: sll         $t3, $t0, 4
    ctx->r11 = S32(ctx->r8 << 4);
    // 0x80031C14: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80031C18: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x80031C1C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80031C20: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80031C24: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80031C28: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80031C2C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80031C30: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80031C34: addu        $t6, $t6, $t0
    ctx->r14 = ADD32(ctx->r14, ctx->r8);
    // 0x80031C38: addiu       $t1, $t1, -0x36A0
    ctx->r9 = ADD32(ctx->r9, -0X36A0);
    // 0x80031C3C: addiu       $a3, $a3, -0x36B0
    ctx->r7 = ADD32(ctx->r7, -0X36B0);
    // 0x80031C40: addiu       $a1, $a1, -0x36AC
    ctx->r5 = ADD32(ctx->r5, -0X36AC);
    // 0x80031C44: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80031C48: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80031C4C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80031C50: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80031C54: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80031C58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80031C5C: sw          $t7, -0x369C($at)
    MEM_W(-0X369C, ctx->r1) = ctx->r15;
    // 0x80031C60: blez        $t0, L_80031C9C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80031C64: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80031C9C;
    }
    // 0x80031C64: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80031C68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80031C6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80031C70:
    // 0x80031C70: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80031C74: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80031C78: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80031C7C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x80031C80: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80031C84: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80031C88: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80031C8C: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80031C90: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80031C94: bne         $at, $zero, L_80031C70
    if (ctx->r1 != 0) {
        // 0x80031C98: addiu       $a0, $a0, 0x88
        ctx->r4 = ADD32(ctx->r4, 0X88);
            goto L_80031C70;
    }
    // 0x80031C98: addiu       $a0, $a0, 0x88
    ctx->r4 = ADD32(ctx->r4, 0X88);
L_80031C9C:
    // 0x80031C9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031CA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031CA4: jr          $ra
    // 0x80031CA8: nop

    return;
    // 0x80031CA8: nop

;}
RECOMP_FUNC void menu_caution_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C3FC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008C400: addiu       $v1, $v1, -0xB84
    ctx->r3 = ADD32(ctx->r3, -0XB84);
    // 0x8008C404: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008C408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C40C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C410: beq         $v0, $zero, L_8008C424
    if (ctx->r2 == 0) {
        // 0x8008C414: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8008C424;
    }
    // 0x8008C414: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008C418: addu        $t7, $v0, $a0
    ctx->r15 = ADD32(ctx->r2, ctx->r4);
    // 0x8008C41C: b           L_8008C46C
    // 0x8008C420: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
        goto L_8008C46C;
    // 0x8008C420: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8008C424:
    // 0x8008C424: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008C428: lw          $t8, 0x63C4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X63C4);
    // 0x8008C42C: nop

    // 0x8008C430: bgtz        $t8, L_8008C46C
    if (SIGNED(ctx->r24) > 0) {
        // 0x8008C434: nop
    
            goto L_8008C46C;
    }
    // 0x8008C434: nop

    // 0x8008C438: jal         0x8006A554
    // 0x8008C43C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8008C43C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8008C440: andi        $t9, $v0, 0xD000
    ctx->r25 = ctx->r2 & 0XD000;
    // 0x8008C444: beq         $t9, $zero, L_8008C46C
    if (ctx->r25 == 0) {
        // 0x8008C448: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008C46C;
    }
    // 0x8008C448: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008C44C: jal         0x80001D04
    // 0x8008C450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8008C450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8008C454: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008C458: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C45C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C460: sw          $t0, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r8;
    // 0x8008C464: jal         0x800C01D8
    // 0x8008C468: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_2;
    // 0x8008C468: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_2:
L_8008C46C:
    // 0x8008C46C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008C470: addiu       $v1, $v1, -0xB84
    ctx->r3 = ADD32(ctx->r3, -0XB84);
    // 0x8008C474: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008C478: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008C47C: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8008C480: beq         $at, $zero, L_8008C4A0
    if (ctx->r1 == 0) {
        // 0x8008C484: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_8008C4A0;
    }
    // 0x8008C484: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008C488: addiu       $a1, $a1, -0x28
    ctx->r5 = ADD32(ctx->r5, -0X28);
    // 0x8008C48C: jal         0x800821EC
    // 0x8008C490: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    draw_menu_elements(rdram, ctx);
        goto after_3;
    // 0x8008C490: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x8008C494: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008C498: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8008C49C: nop

L_8008C4A0:
    // 0x8008C4A0: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8008C4A4: bne         $at, $zero, L_8008C4BC
    if (ctx->r1 != 0) {
        // 0x8008C4A8: nop
    
            goto L_8008C4BC;
    }
    // 0x8008C4A8: nop

    // 0x8008C4AC: jal         0x8008C4E8
    // 0x8008C4B0: nop

    caution_free(rdram, ctx);
        goto after_4;
    // 0x8008C4B0: nop

    after_4:
    // 0x8008C4B4: jal         0x800813D0
    // 0x8008C4B8: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    menu_init(rdram, ctx);
        goto after_5;
    // 0x8008C4B8: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_5:
L_8008C4BC:
    // 0x8008C4BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C4C0: addiu       $v1, $v1, 0x63C4
    ctx->r3 = ADD32(ctx->r3, 0X63C4);
    // 0x8008C4C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008C4C8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8008C4CC: blez        $v0, L_8008C4D8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008C4D0: subu        $t2, $v0, $t1
        ctx->r10 = SUB32(ctx->r2, ctx->r9);
            goto L_8008C4D8;
    }
    // 0x8008C4D0: subu        $t2, $v0, $t1
    ctx->r10 = SUB32(ctx->r2, ctx->r9);
    // 0x8008C4D4: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_8008C4D8:
    // 0x8008C4D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C4DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C4E0: jr          $ra
    // 0x8008C4E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8008C4E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void fb_mode_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A4C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A4C4: jr          $ra
    // 0x8007A4C8: sw          $a0, 0x62CC($at)
    MEM_W(0X62CC, ctx->r1) = ctx->r4;
    return;
    // 0x8007A4C8: sw          $a0, 0x62CC($at)
    MEM_W(0X62CC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void input_player_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A4F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A4FC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006A500: lbu         $v0, 0x1150($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1150);
    // 0x8006A504: jr          $ra
    // 0x8006A508: nop

    return;
    // 0x8006A508: nop

;}
RECOMP_FUNC void bgload_active(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C73E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C73E4: lw          $v0, 0x3770($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3770);
    // 0x800C73E8: jr          $ra
    // 0x800C73EC: nop

    return;
    // 0x800C73EC: nop

;}
RECOMP_FUNC void aitable_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C168: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006C16C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C170: lw          $a0, 0x11C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11C0);
    // 0x8006C174: jal         0x80071140
    // 0x8006C178: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x8006C178: nop

    after_0:
    // 0x8006C17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C184: jr          $ra
    // 0x8006C188: nop

    return;
    // 0x8006C188: nop

;}
RECOMP_FUNC void func_8009D324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D324: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D328: jr          $ra
    // 0x8009D32C: sb          $zero, -0xB28($at)
    MEM_B(-0XB28, ctx->r1) = 0;
    return;
    // 0x8009D32C: sb          $zero, -0xB28($at)
    MEM_B(-0XB28, ctx->r1) = 0;
;}
RECOMP_FUNC void alEvtqPostEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C91AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C91B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C91B4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C91B8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C91BC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800C91C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C91C4: jal         0x800C9A30
    // 0x800C91C8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C91C8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C91CC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800C91D0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800C91D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800C91D8: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x800C91DC: bne         $t0, $zero, L_800C91F4
    if (ctx->r8 != 0) {
        // 0x800C91E0: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_800C91F4;
    }
    // 0x800C91E0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800C91E4: jal         0x800C9A30
    // 0x800C91E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800C91E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800C91EC: b           L_800C92C4
    // 0x800C91F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C92C4;
    // 0x800C91F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C91F4:
    // 0x800C91F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C91F8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800C91FC: jal         0x800C8760
    // 0x800C9200: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    alUnlink(rdram, ctx);
        goto after_2;
    // 0x800C9200: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800C9204: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9208: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800C920C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800C9210: jal         0x800D3820
    // 0x800C9214: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    alCopy(rdram, ctx);
        goto after_3;
    // 0x800C9214: addiu       $a1, $t0, 0xC
    ctx->r5 = ADD32(ctx->r8, 0XC);
    after_3:
    // 0x800C9218: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800C921C: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800C9220: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800C9224: bne         $a3, $at, L_800C9234
    if (ctx->r7 != ctx->r1) {
        // 0x800C9228: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_800C9234;
    }
    // 0x800C9228: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800C922C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800C9230: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800C9234:
    // 0x800C9234: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800C9238: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800C923C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800C9240: beq         $v0, $at, L_800C92B8
    if (ctx->r2 == ctx->r1) {
        // 0x800C9244: addiu       $a1, $v0, 0x8
        ctx->r5 = ADD32(ctx->r2, 0X8);
            goto L_800C92B8;
    }
    // 0x800C9244: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
L_800C9248:
    // 0x800C9248: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800C924C: bnel        $v0, $zero, L_800C927C
    if (ctx->r2 != 0) {
        // 0x800C9250: lw          $v1, 0x8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X8);
            goto L_800C927C;
    }
    goto skip_0;
    // 0x800C9250: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x800C9254: beql        $t8, $zero, L_800C9268
    if (ctx->r24 == 0) {
        // 0x800C9258: sw          $a3, 0x8($t0)
        MEM_W(0X8, ctx->r8) = ctx->r7;
            goto L_800C9268;
    }
    goto skip_1;
    // 0x800C9258: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    skip_1:
    // 0x800C925C: b           L_800C9268
    // 0x800C9260: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
        goto L_800C9268;
    // 0x800C9260: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x800C9264: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
L_800C9268:
    // 0x800C9268: jal         0x800C8790
    // 0x800C926C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    alLink(rdram, ctx);
        goto after_4;
    // 0x800C926C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_4:
    // 0x800C9270: b           L_800C92B8
    // 0x800C9274: nop

        goto L_800C92B8;
    // 0x800C9274: nop

    // 0x800C9278: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
L_800C927C:
    // 0x800C927C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9280: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C9284: beql        $at, $zero, L_800C92B0
    if (ctx->r1 == 0) {
        // 0x800C9288: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800C92B0;
    }
    goto skip_2;
    // 0x800C9288: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    skip_2:
    // 0x800C928C: sw          $a3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r7;
    // 0x800C9290: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x800C9294: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800C9298: subu        $t1, $t9, $a3
    ctx->r9 = SUB32(ctx->r25, ctx->r7);
    // 0x800C929C: jal         0x800C8790
    // 0x800C92A0: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    alLink(rdram, ctx);
        goto after_5;
    // 0x800C92A0: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    after_5:
    // 0x800C92A4: b           L_800C92B8
    // 0x800C92A8: nop

        goto L_800C92B8;
    // 0x800C92A8: nop

    // 0x800C92AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800C92B0:
    // 0x800C92B0: bne         $v0, $zero, L_800C9248
    if (ctx->r2 != 0) {
        // 0x800C92B4: subu        $a3, $a3, $v1
        ctx->r7 = SUB32(ctx->r7, ctx->r3);
            goto L_800C9248;
    }
    // 0x800C92B4: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
L_800C92B8:
    // 0x800C92B8: jal         0x800C9A30
    // 0x800C92BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_6;
    // 0x800C92BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_6:
    // 0x800C92C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C92C4:
    // 0x800C92C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C92C8: jr          $ra
    // 0x800C92CC: nop

    return;
    // 0x800C92CC: nop

;}
RECOMP_FUNC void bgdraw_chequer_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800787F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800787F4: jr          $ra
    // 0x800787F8: sw          $zero, -0x1B34($at)
    MEM_W(-0X1B34, ctx->r1) = 0;
    return;
    // 0x800787F8: sw          $zero, -0x1B34($at)
    MEM_W(-0X1B34, ctx->r1) = 0;
;}
RECOMP_FUNC void func_8001E45C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E45C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E460: addiu       $v0, $v0, -0x5186
    ctx->r2 = ADD32(ctx->r2, -0X5186);
    // 0x8001E464: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8001E468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E46C: beq         $a0, $t6, L_8001E4A4
    if (ctx->r4 == ctx->r14) {
        // 0x8001E470: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8001E4A4;
    }
    // 0x8001E470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E474: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x8001E478: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E47C: sw          $zero, -0x5254($at)
    MEM_W(-0X5254, ctx->r1) = 0;
    // 0x8001E480: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E484: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001E488: jal         0x8006DA0C
    // 0x8001E48C: sb          $t7, -0x5182($at)
    MEM_B(-0X5182, ctx->r1) = ctx->r15;
    get_game_mode(rdram, ctx);
        goto after_0;
    // 0x8001E48C: sb          $t7, -0x5182($at)
    MEM_B(-0X5182, ctx->r1) = ctx->r15;
    after_0:
    // 0x8001E490: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001E494: bne         $v0, $at, L_8001E4A8
    if (ctx->r2 != ctx->r1) {
        // 0x8001E498: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001E4A8;
    }
    // 0x8001E498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E49C: jal         0x8006F42C
    // 0x8001E4A0: nop

    set_frame_blackout_timer(rdram, ctx);
        goto after_1;
    // 0x8001E4A0: nop

    after_1:
L_8001E4A4:
    // 0x8001E4A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E4A8:
    // 0x8001E4A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E4AC: jr          $ra
    // 0x8001E4B0: nop

    return;
    // 0x8001E4B0: nop

;}
RECOMP_FUNC void func_80026E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026E54: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x80026E58: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80026E5C: sll         $s5, $a0, 16
    ctx->r21 = S32(ctx->r4 << 16);
    // 0x80026E60: sra         $t6, $s5, 16
    ctx->r14 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80026E64: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80026E68: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80026E6C: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x80026E70: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x80026E74: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80026E78: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x80026E7C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80026E80: or          $s5, $t6, $zero
    ctx->r21 = ctx->r14 | 0;
    // 0x80026E84: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80026E88: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80026E8C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80026E90: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80026E94: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80026E98: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80026E9C: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80026EA0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80026EA4: beq         $at, $zero, L_8002714C
    if (ctx->r1 == 0) {
        // 0x80026EA8: sw          $a0, 0x108($sp)
        MEM_W(0X108, ctx->r29) = ctx->r4;
            goto L_8002714C;
    }
    // 0x80026EA8: sw          $a0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r4;
    // 0x80026EAC: beq         $t6, $zero, L_8002714C
    if (ctx->r14 == 0) {
        // 0x80026EB0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002714C;
    }
    // 0x80026EB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80026EB4: blez        $t6, L_80026FEC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80026EB8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80026FEC;
    }
    // 0x80026EB8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80026EBC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80026EC0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80026EC4: lw          $a3, -0x2B88($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2B88);
    // 0x80026EC8: lw          $t0, -0x2B84($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2B84);
    // 0x80026ECC: addiu       $s4, $sp, 0x94
    ctx->r20 = ADD32(ctx->r29, 0X94);
    // 0x80026ED0: addiu       $s2, $sp, 0x60
    ctx->r18 = ADD32(ctx->r29, 0X60);
    // 0x80026ED4: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
L_80026ED8:
    // 0x80026ED8: addu        $t7, $s0, $s3
    ctx->r15 = ADD32(ctx->r16, ctx->r19);
    // 0x80026EDC: lb          $t8, 0x0($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X0);
    // 0x80026EE0: nop

    // 0x80026EE4: sll         $t9, $t8, 17
    ctx->r25 = S32(ctx->r24 << 17);
    // 0x80026EE8: sra         $t2, $t9, 16
    ctx->r10 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80026EEC: addu        $a0, $t2, $t0
    ctx->r4 = ADD32(ctx->r10, ctx->r8);
    // 0x80026EF0: lb          $t3, 0x0($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X0);
    // 0x80026EF4: lb          $t5, 0x1($a0)
    ctx->r13 = MEM_B(ctx->r4, 0X1);
    // 0x80026EF8: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80026EFC: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80026F00: addu        $v1, $t4, $a3
    ctx->r3 = ADD32(ctx->r12, ctx->r7);
    // 0x80026F04: addu        $a2, $t6, $a3
    ctx->r6 = ADD32(ctx->r14, ctx->r7);
    // 0x80026F08: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80026F0C: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x80026F10: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80026F14: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80026F18: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80026F1C: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80026F20: lh          $t2, 0x2($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X2);
    // 0x80026F24: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80026F28: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80026F2C: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80026F30: c.eq.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl == ctx->f14.fl;
    // 0x80026F34: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80026F38: bc1t        L_8002714C
    if (c1cs) {
        // 0x80026F3C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8002714C;
    }
    // 0x80026F3C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80026F40: sub.s       $f0, $f2, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80026F44: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80026F48: sub.s       $f4, $f2, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f20.fl;
    // 0x80026F4C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80026F50: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80026F54: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80026F58: sll         $t5, $v0, 16
    ctx->r13 = S32(ctx->r2 << 16);
    // 0x80026F5C: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80026F60: addu        $t4, $s4, $t3
    ctx->r12 = ADD32(ctx->r20, ctx->r11);
    // 0x80026F64: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80026F68: addu        $v1, $s4, $t8
    ctx->r3 = ADD32(ctx->r20, ctx->r24);
    // 0x80026F6C: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80026F70: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x80026F74: addu        $t9, $s2, $s0
    ctx->r25 = ADD32(ctx->r18, ctx->r16);
    // 0x80026F78: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80026F7C: sll         $t2, $v0, 16
    ctx->r10 = S32(ctx->r2 << 16);
    // 0x80026F80: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80026F84: sub.s       $f6, $f22, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f14.fl;
    // 0x80026F88: sra         $v0, $t2, 16
    ctx->r2 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80026F8C: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80026F90: nop

    // 0x80026F94: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80026F98: sub.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80026F9C: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x80026FA0: lwc1        $f4, -0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0X4);
    // 0x80026FA4: sb          $s0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r16;
    // 0x80026FA8: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80026FAC: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80026FB0: addu        $t5, $s4, $t4
    ctx->r13 = ADD32(ctx->r20, ctx->r12);
    // 0x80026FB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80026FB8: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x80026FBC: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80026FC0: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80026FC4: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80026FC8: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80026FCC: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x80026FD0: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80026FD4: lwc1        $f18, -0x4($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, -0X4);
    // 0x80026FD8: nop

    // 0x80026FDC: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80026FE0: bne         $at, $zero, L_80026ED8
    if (ctx->r1 != 0) {
        // 0x80026FE4: swc1        $f8, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
            goto L_80026ED8;
    }
    // 0x80026FE4: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80026FE8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80026FEC:
    // 0x80026FEC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80026FF0: addiu       $s2, $sp, 0x60
    ctx->r18 = ADD32(ctx->r29, 0X60);
    // 0x80026FF4: addiu       $s4, $sp, 0x94
    ctx->r20 = ADD32(ctx->r29, 0X94);
    // 0x80026FF8: addiu       $s1, $s5, -0x1
    ctx->r17 = ADD32(ctx->r21, -0X1);
L_80026FFC:
    // 0x80026FFC: blez        $s1, L_8002707C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80027000: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8002707C;
    }
    // 0x80027000: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80027004: addu        $v1, $s2, $s0
    ctx->r3 = ADD32(ctx->r18, ctx->r16);
L_80027008:
    // 0x80027008: lb          $t8, 0x1($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X1);
    // 0x8002700C: lb          $t3, 0x0($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X0);
    // 0x80027010: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80027014: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80027018: addu        $t5, $a1, $t4
    ctx->r13 = ADD32(ctx->r5, ctx->r12);
    // 0x8002701C: addu        $t2, $a1, $t9
    ctx->r10 = ADD32(ctx->r5, ctx->r25);
    // 0x80027020: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80027024: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80027028: addu        $a0, $s0, $s3
    ctx->r4 = ADD32(ctx->r16, ctx->r19);
    // 0x8002702C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80027030: nop

    // 0x80027034: bc1f        L_80027060
    if (!c1cs) {
        // 0x80027038: nop
    
            goto L_80027060;
    }
    // 0x80027038: nop

    // 0x8002703C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80027040: lb          $t6, 0x1($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1);
    // 0x80027044: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x80027048: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x8002704C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80027050: lb          $t7, 0x1($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X1);
    // 0x80027054: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80027058: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x8002705C: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_80027060:
    // 0x80027060: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80027064: sll         $t8, $s0, 16
    ctx->r24 = S32(ctx->r16 << 16);
    // 0x80027068: sra         $s0, $t8, 16
    ctx->r16 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8002706C: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80027070: bne         $at, $zero, L_80027008
    if (ctx->r1 != 0) {
        // 0x80027074: addu        $v1, $s2, $s0
        ctx->r3 = ADD32(ctx->r18, ctx->r16);
            goto L_80027008;
    }
    // 0x80027074: addu        $v1, $s2, $s0
    ctx->r3 = ADD32(ctx->r18, ctx->r16);
    // 0x80027078: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002707C:
    // 0x8002707C: beq         $a2, $zero, L_80026FFC
    if (ctx->r6 == 0) {
        // 0x80027080: nop
    
            goto L_80026FFC;
    }
    // 0x80027080: nop

    // 0x80027084: blez        $s1, L_8002714C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80027088: lui         $s6, 0x8012
        ctx->r22 = S32(0X8012 << 16);
            goto L_8002714C;
    }
    // 0x80027088: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8002708C: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80027090: addiu       $s5, $s5, -0x2B88
    ctx->r21 = ADD32(ctx->r21, -0X2B88);
    // 0x80027094: addiu       $s6, $s6, -0x2B84
    ctx->r22 = ADD32(ctx->r22, -0X2B84);
    // 0x80027098: addu        $a0, $s0, $s3
    ctx->r4 = ADD32(ctx->r16, ctx->r19);
L_8002709C:
    // 0x8002709C: lb          $t2, 0x0($a0)
    ctx->r10 = MEM_B(ctx->r4, 0X0);
    // 0x800270A0: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    // 0x800270A4: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800270A8: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x800270AC: lb          $t5, 0x0($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X0);
    // 0x800270B0: lw          $a3, 0x0($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X0);
    // 0x800270B4: lb          $t3, 0x1($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X1);
    // 0x800270B8: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800270BC: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x800270C0: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800270C4: lb          $v0, 0x6($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X6);
    // 0x800270C8: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x800270CC: lb          $t6, 0x0($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X0);
    // 0x800270D0: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x800270D4: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800270D8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800270DC: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x800270E0: lb          $v1, 0x6($t8)
    ctx->r3 = MEM_B(ctx->r24, 0X6);
    // 0x800270E4: sra         $v0, $t9, 24
    ctx->r2 = S32(SIGNED(ctx->r25) >> 24);
    // 0x800270E8: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x800270EC: sll         $t2, $t9, 24
    ctx->r10 = S32(ctx->r25 << 24);
    // 0x800270F0: beq         $v0, $zero, L_80027134
    if (ctx->r2 == 0) {
        // 0x800270F4: sra         $t3, $t2, 24
        ctx->r11 = S32(SIGNED(ctx->r10) >> 24);
            goto L_80027134;
    }
    // 0x800270F4: sra         $t3, $t2, 24
    ctx->r11 = S32(SIGNED(ctx->r10) >> 24);
    // 0x800270F8: bne         $t3, $zero, L_80027134
    if (ctx->r11 != 0) {
        // 0x800270FC: addu        $v1, $s2, $s0
        ctx->r3 = ADD32(ctx->r18, ctx->r16);
            goto L_80027134;
    }
    // 0x800270FC: addu        $v1, $s2, $s0
    ctx->r3 = ADD32(ctx->r18, ctx->r16);
    // 0x80027100: lb          $t4, 0x0($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X0);
    // 0x80027104: lb          $t7, 0x1($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X1);
    // 0x80027108: sll         $t5, $t4, 17
    ctx->r13 = S32(ctx->r12 << 17);
    // 0x8002710C: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x80027110: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80027114: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80027118: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x8002711C: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x80027120: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80027124: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80027128: addu        $a0, $s4, $t2
    ctx->r4 = ADD32(ctx->r20, ctx->r10);
    // 0x8002712C: jal         0x80027184
    // 0x80027130: addu        $a1, $s4, $t3
    ctx->r5 = ADD32(ctx->r20, ctx->r11);
    void_generate_primitive(rdram, ctx);
        goto after_0;
    // 0x80027130: addu        $a1, $s4, $t3
    ctx->r5 = ADD32(ctx->r20, ctx->r11);
    after_0:
L_80027134:
    // 0x80027134: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80027138: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x8002713C: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80027140: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80027144: bne         $at, $zero, L_8002709C
    if (ctx->r1 != 0) {
        // 0x80027148: addu        $a0, $s0, $s3
        ctx->r4 = ADD32(ctx->r16, ctx->r19);
            goto L_8002709C;
    }
    // 0x80027148: addu        $a0, $s0, $s3
    ctx->r4 = ADD32(ctx->r16, ctx->r19);
L_8002714C:
    // 0x8002714C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80027150: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80027154: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80027158: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002715C: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80027160: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80027164: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80027168: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8002716C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80027170: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80027174: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80027178: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8002717C: jr          $ra
    // 0x80027180: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x80027180: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void copy_controller_pak_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076388: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8007638C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80076390: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80076394: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80076398: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8007639C: jal         0x800758DC
    // 0x800763A0: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x800763A0: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    after_0:
    // 0x800763A4: beq         $v0, $zero, L_800763C8
    if (ctx->r2 == 0) {
        // 0x800763A8: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_800763C8;
    }
    // 0x800763A8: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x800763AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800763B0: jal         0x80075AEC
    // 0x800763B4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x800763B4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_1:
    // 0x800763B8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800763BC: sll         $t6, $s0, 30
    ctx->r14 = S32(ctx->r16 << 30);
    // 0x800763C0: b           L_800764D8
    // 0x800763C4: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
        goto L_800764D8;
    // 0x800763C4: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
L_800763C8:
    // 0x800763C8: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x800763CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800763D0: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x800763D4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800763D8: addiu       $t8, $t8, 0x4018
    ctx->r24 = ADD32(ctx->r24, 0X4018);
    // 0x800763DC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800763E0: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x800763E4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800763E8: jal         0x800D0580
    // 0x800763EC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    osPfsFileState_recomp(rdram, ctx);
        goto after_2;
    // 0x800763EC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x800763F0: beq         $v0, $zero, L_80076414
    if (ctx->r2 == 0) {
        // 0x800763F4: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80076414;
    }
    // 0x800763F4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800763F8: jal         0x80075AEC
    // 0x800763FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_3;
    // 0x800763FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80076400: sll         $v0, $s0, 30
    ctx->r2 = S32(ctx->r16 << 30);
    // 0x80076404: ori         $t9, $v0, 0x9
    ctx->r25 = ctx->r2 | 0X9;
    // 0x80076408: b           L_800764D8
    // 0x8007640C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800764D8;
    // 0x8007640C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80076410: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_80076414:
    // 0x80076414: jal         0x80070C9C
    // 0x80076418: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x80076418: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_4:
    // 0x8007641C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x80076420: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80076424: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80076428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007642C: jal         0x80076610
    // 0x80076430: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_5;
    // 0x80076430: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x80076434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076438: jal         0x80075AEC
    // 0x8007643C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_6;
    // 0x8007643C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_6:
    // 0x80076440: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80076444: addiu       $a0, $sp, 0x42
    ctx->r4 = ADD32(ctx->r29, 0X42);
    // 0x80076448: beq         $v1, $zero, L_8007646C
    if (ctx->r3 == 0) {
        // 0x8007644C: addiu       $a2, $zero, 0x10
        ctx->r6 = ADD32(0, 0X10);
            goto L_8007646C;
    }
    // 0x8007644C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80076450: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80076454: jal         0x80071140
    // 0x80076458: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x80076458: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_7:
    // 0x8007645C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80076460: sll         $t0, $s0, 30
    ctx->r8 = S32(ctx->r16 << 30);
    // 0x80076464: b           L_800764D8
    // 0x80076468: or          $v0, $t0, $v1
    ctx->r2 = ctx->r8 | ctx->r3;
        goto L_800764D8;
    // 0x80076468: or          $v0, $t0, $v1
    ctx->r2 = ctx->r8 | ctx->r3;
L_8007646C:
    // 0x8007646C: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x80076470: jal         0x8007698C
    // 0x80076474: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    font_codes_to_string(rdram, ctx);
        goto after_8;
    // 0x80076474: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x80076478: addiu       $a0, $sp, 0x3E
    ctx->r4 = ADD32(ctx->r29, 0X3E);
    // 0x8007647C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80076480: jal         0x8007698C
    // 0x80076484: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    font_codes_to_string(rdram, ctx);
        goto after_9;
    // 0x80076484: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_9:
    // 0x80076488: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8007648C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80076490: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80076494: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80076498: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8007649C: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x800764A0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800764A4: jal         0x800766D4
    // 0x800764A8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    write_controller_pak_file(rdram, ctx);
        goto after_10;
    // 0x800764A8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_10:
    // 0x800764AC: beq         $v0, $zero, L_800764C4
    if (ctx->r2 == 0) {
        // 0x800764B0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800764C4;
    }
    // 0x800764B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800764B4: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x800764B8: nop

    // 0x800764BC: sll         $t4, $t3, 30
    ctx->r12 = S32(ctx->r11 << 30);
    // 0x800764C0: or          $v1, $v0, $t4
    ctx->r3 = ctx->r2 | ctx->r12;
L_800764C4:
    // 0x800764C4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800764C8: jal         0x80071140
    // 0x800764CC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_11;
    // 0x800764CC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_11:
    // 0x800764D0: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800764D4: nop

L_800764D8:
    // 0x800764D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800764DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800764E0: jr          $ra
    // 0x800764E4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800764E4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void gfxtask_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078108: jal         0x8007957C
    // 0x8007810C: nop

    osScGetInterruptQ(rdram, ctx);
        goto after_0;
    // 0x8007810C: nop

    after_0:
    // 0x80078110: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80078114: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80078118: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007811C: sw          $v0, 0x6100($at)
    MEM_W(0X6100, ctx->r1) = ctx->r2;
    // 0x80078120: addiu       $a1, $a1, 0x5EB8
    ctx->r5 = ADD32(ctx->r5, 0X5EB8);
    // 0x80078124: addiu       $a0, $a0, 0x5EA0
    ctx->r4 = ADD32(ctx->r4, 0X5EA0);
    // 0x80078128: jal         0x800C8820
    // 0x8007812C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x8007812C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80078130: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80078134: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80078138: addiu       $a1, $a1, 0x5EF0
    ctx->r5 = ADD32(ctx->r5, 0X5EF0);
    // 0x8007813C: addiu       $a0, $a0, 0x5EC0
    ctx->r4 = ADD32(ctx->r4, 0X5EC0);
    // 0x80078140: jal         0x800C8820
    // 0x80078144: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x80078144: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x80078148: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007814C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80078150: addiu       $a1, $a1, 0x5F10
    ctx->r5 = ADD32(ctx->r5, 0X5F10);
    // 0x80078154: addiu       $a0, $a0, 0x5ED8
    ctx->r4 = ADD32(ctx->r4, 0X5ED8);
    // 0x80078158: jal         0x800C8820
    // 0x8007815C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x8007815C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x80078160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078168: jr          $ra
    // 0x8007816C: nop

    return;
    // 0x8007816C: nop

;}
RECOMP_FUNC void get_next_particle_table(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B44D4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B44D8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800B44DC: addiu       $v1, $t6, 0x1
    ctx->r3 = ADD32(ctx->r14, 0X1);
    // 0x800B44E0: addiu       $a1, $a1, 0x2CE8
    ctx->r5 = ADD32(ctx->r5, 0X2CE8);
    // 0x800B44E4: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800B44E8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B44EC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B44F0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B44F4: bne         $at, $zero, L_800B4514
    if (ctx->r1 != 0) {
        // 0x800B44F8: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_800B4514;
    }
    // 0x800B44F8: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_800B44FC:
    // 0x800B44FC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B4500: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B4504: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800B4508: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B450C: beq         $at, $zero, L_800B44FC
    if (ctx->r1 == 0) {
        // 0x800B4510: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_800B44FC;
    }
    // 0x800B4510: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_800B4514:
    // 0x800B4514: lw          $t9, 0x2CF0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2CF0);
    // 0x800B4518: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800B451C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B4520: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800B4524: jr          $ra
    // 0x800B4528: nop

    return;
    // 0x800B4528: nop

;}
RECOMP_FUNC void set_scene_viewport_num(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800249E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800249E4: sw          $a0, -0x2C84($at)
    MEM_W(-0X2C84, ctx->r1) = ctx->r4;
    // 0x800249E8: jr          $ra
    // 0x800249EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800249EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void mempool_get_pool(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800715EC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800715F0: lw          $v1, 0x35C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X35C0);
    // 0x800715F4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800715F8: blez        $v1, L_80071644
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800715FC: sll         $t6, $v1, 4
        ctx->r14 = S32(ctx->r3 << 4);
            goto L_80071644;
    }
    // 0x800715FC: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x80071600: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80071604: addiu       $t7, $t7, 0x3580
    ctx->r15 = ADD32(ctx->r15, 0X3580);
    // 0x80071608: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_8007160C:
    // 0x8007160C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80071610: nop

    // 0x80071614: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80071618: beq         $at, $zero, L_80071638
    if (ctx->r1 == 0) {
        // 0x8007161C: nop
    
            goto L_80071638;
    }
    // 0x8007161C: nop

    // 0x80071620: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x80071624: nop

    // 0x80071628: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8007162C: sltu        $at, $a1, $t9
    ctx->r1 = ctx->r5 < ctx->r25 ? 1 : 0;
    // 0x80071630: bne         $at, $zero, L_80071644
    if (ctx->r1 != 0) {
        // 0x80071634: nop
    
            goto L_80071644;
    }
    // 0x80071634: nop

L_80071638:
    // 0x80071638: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8007163C: bgtz        $v1, L_8007160C
    if (SIGNED(ctx->r3) > 0) {
        // 0x80071640: addiu       $v0, $v0, -0x10
        ctx->r2 = ADD32(ctx->r2, -0X10);
            goto L_8007160C;
    }
    // 0x80071640: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
L_80071644:
    // 0x80071644: jr          $ra
    // 0x80071648: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80071648: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void obj_elevation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C418: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C41C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001C420: lwc1        $f2, 0x5640($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X5640);
    // 0x8001C424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001C428: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001C42C: addiu       $a0, $a0, -0x50E8
    ctx->r4 = ADD32(ctx->r4, -0X50E8);
    // 0x8001C430: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
L_8001C434:
    // 0x8001C434: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8001C438: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8001C43C: nop

    // 0x8001C440: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8001C444: nop

    // 0x8001C448: bc1t        L_8001C46C
    if (c1cs) {
        // 0x8001C44C: nop
    
            goto L_8001C46C;
    }
    // 0x8001C44C: nop

    // 0x8001C450: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8001C454: nop

    // 0x8001C458: bc1f        L_8001C46C
    if (!c1cs) {
        // 0x8001C45C: nop
    
            goto L_8001C46C;
    }
    // 0x8001C45C: nop

    // 0x8001C460: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x8001C464: sra         $t8, $v1, 16
    ctx->r24 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001C468: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_8001C46C:
    // 0x8001C46C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001C470: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8001C474: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8001C478: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8001C47C: bne         $at, $zero, L_8001C434
    if (ctx->r1 != 0) {
        // 0x8001C480: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8001C434;
    }
    // 0x8001C480: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001C484: jr          $ra
    // 0x8001C488: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001C488: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void trackmenu_active(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E790: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008E794: lw          $v0, 0x97C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X97C);
    // 0x8008E798: jr          $ra
    // 0x8008E79C: nop

    return;
    // 0x8008E79C: nop

;}
RECOMP_FUNC void init_object_interaction_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FD20: sw          $a1, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->r5;
    // 0x8000FD24: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8000FD28: sb          $t6, 0x13($a1)
    MEM_B(0X13, ctx->r5) = ctx->r14;
    // 0x8000FD2C: jr          $ra
    // 0x8000FD30: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    return;
    // 0x8000FD30: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
;}
RECOMP_FUNC void __alCSeqNextDelta(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C83EC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800C83F0: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x800C83F4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800C83F8: bne         $t6, $zero, L_800C8408
    if (ctx->r14 != 0) {
        // 0x800C83FC: lw          $v0, 0x10($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X10);
            goto L_800C8408;
    }
    // 0x800C83FC: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x800C8400: jr          $ra
    // 0x800C8404: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C8404: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C8408:
    // 0x800C8408: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C840C: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x800C8410: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
L_800C8414:
    // 0x800C8414: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x800C8418: srlv        $t7, $a1, $a2
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r6 & 31));
    // 0x800C841C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C8420: beql        $t8, $zero, L_800C8464
    if (ctx->r24 == 0) {
        // 0x800C8424: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800C8464;
    }
    goto skip_0;
    // 0x800C8424: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_0:
    // 0x800C8428: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800C842C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C8430: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800C8434: beql        $t3, $zero, L_800C8450
    if (ctx->r11 == 0) {
        // 0x800C8438: lw          $t0, 0xB8($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XB8);
            goto L_800C8450;
    }
    goto skip_1;
    // 0x800C8438: lw          $t0, 0xB8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XB8);
    skip_1:
    // 0x800C843C: lw          $t4, 0xB8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XB8);
    // 0x800C8440: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C8444: sw          $t5, 0xB8($a3)
    MEM_W(0XB8, ctx->r7) = ctx->r13;
    // 0x800C8448: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800C844C: lw          $t0, 0xB8($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XB8);
L_800C8450:
    // 0x800C8450: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800C8454: beql        $at, $zero, L_800C8464
    if (ctx->r1 == 0) {
        // 0x800C8458: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800C8464;
    }
    goto skip_2;
    // 0x800C8458: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_2:
    // 0x800C845C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800C8460: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800C8464:
    // 0x800C8464: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C8468: beq         $t8, $zero, L_800C84A8
    if (ctx->r24 == 0) {
        // 0x800C846C: addiu       $t6, $a2, 0x2
        ctx->r14 = ADD32(ctx->r6, 0X2);
            goto L_800C84A8;
    }
    // 0x800C846C: addiu       $t6, $a2, 0x2
    ctx->r14 = ADD32(ctx->r6, 0X2);
    // 0x800C8470: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800C8474: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C8478: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800C847C: beql        $t3, $zero, L_800C8498
    if (ctx->r11 == 0) {
        // 0x800C8480: lw          $t0, 0xBC($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XBC);
            goto L_800C8498;
    }
    goto skip_3;
    // 0x800C8480: lw          $t0, 0xBC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XBC);
    skip_3:
    // 0x800C8484: lw          $t4, 0xBC($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XBC);
    // 0x800C8488: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C848C: sw          $t5, 0xBC($a3)
    MEM_W(0XBC, ctx->r7) = ctx->r13;
    // 0x800C8490: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800C8494: lw          $t0, 0xBC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XBC);
L_800C8498:
    // 0x800C8498: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800C849C: beql        $at, $zero, L_800C84AC
    if (ctx->r1 == 0) {
        // 0x800C84A0: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800C84AC;
    }
    goto skip_4;
    // 0x800C84A0: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_4:
    // 0x800C84A4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800C84A8:
    // 0x800C84A8: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800C84AC:
    // 0x800C84AC: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C84B0: beq         $t8, $zero, L_800C84F0
    if (ctx->r24 == 0) {
        // 0x800C84B4: addiu       $t6, $a2, 0x3
        ctx->r14 = ADD32(ctx->r6, 0X3);
            goto L_800C84F0;
    }
    // 0x800C84B4: addiu       $t6, $a2, 0x3
    ctx->r14 = ADD32(ctx->r6, 0X3);
    // 0x800C84B8: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800C84BC: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C84C0: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800C84C4: beql        $t3, $zero, L_800C84E0
    if (ctx->r11 == 0) {
        // 0x800C84C8: lw          $t0, 0xC0($a3)
        ctx->r8 = MEM_W(ctx->r7, 0XC0);
            goto L_800C84E0;
    }
    goto skip_5;
    // 0x800C84C8: lw          $t0, 0xC0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC0);
    skip_5:
    // 0x800C84CC: lw          $t4, 0xC0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC0);
    // 0x800C84D0: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C84D4: sw          $t5, 0xC0($a3)
    MEM_W(0XC0, ctx->r7) = ctx->r13;
    // 0x800C84D8: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800C84DC: lw          $t0, 0xC0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC0);
L_800C84E0:
    // 0x800C84E0: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x800C84E4: beql        $at, $zero, L_800C84F4
    if (ctx->r1 == 0) {
        // 0x800C84E8: srlv        $t7, $a1, $t6
        ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
            goto L_800C84F4;
    }
    goto skip_6;
    // 0x800C84E8: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
    skip_6:
    // 0x800C84EC: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800C84F0:
    // 0x800C84F0: srlv        $t7, $a1, $t6
    ctx->r15 = S32(U32(ctx->r5) >> (ctx->r14 & 31));
L_800C84F4:
    // 0x800C84F4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C84F8: beql        $t8, $zero, L_800C8538
    if (ctx->r24 == 0) {
        // 0x800C84FC: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800C8538;
    }
    goto skip_7;
    // 0x800C84FC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_7:
    // 0x800C8500: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x800C8504: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800C8508: addu        $a3, $a0, $t9
    ctx->r7 = ADD32(ctx->r4, ctx->r25);
    // 0x800C850C: beql        $t3, $zero, L_800C8524
    if (ctx->r11 == 0) {
        // 0x800C8510: lw          $a1, 0xC4($a3)
        ctx->r5 = MEM_W(ctx->r7, 0XC4);
            goto L_800C8524;
    }
    goto skip_8;
    // 0x800C8510: lw          $a1, 0xC4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC4);
    skip_8:
    // 0x800C8514: lw          $t4, 0xC4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0XC4);
    // 0x800C8518: subu        $t5, $t4, $v0
    ctx->r13 = SUB32(ctx->r12, ctx->r2);
    // 0x800C851C: sw          $t5, 0xC4($a3)
    MEM_W(0XC4, ctx->r7) = ctx->r13;
    // 0x800C8520: lw          $a1, 0xC4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC4);
L_800C8524:
    // 0x800C8524: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800C8528: beql        $at, $zero, L_800C8538
    if (ctx->r1 == 0) {
        // 0x800C852C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800C8538;
    }
    goto skip_9;
    // 0x800C852C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_9:
    // 0x800C8530: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800C8534: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_800C8538:
    // 0x800C8538: bnel        $a2, $t2, L_800C8414
    if (ctx->r6 != ctx->r10) {
        // 0x800C853C: lw          $a1, 0x4($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X4);
            goto L_800C8414;
    }
    goto skip_10;
    // 0x800C853C: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    skip_10:
    // 0x800C8540: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800C8544: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x800C8548: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C854C: jr          $ra
    // 0x800C8550: nop

    return;
    // 0x800C8550: nop

;}
RECOMP_FUNC void set_camera_shake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069F28: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80069F2C: lw          $v1, 0xCE0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XCE0);
    // 0x80069F30: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069F34: bltz        $v1, L_80069F5C
    if (SIGNED(ctx->r3) < 0) {
        // 0x80069F38: addiu       $v0, $t6, 0xAC0
        ctx->r2 = ADD32(ctx->r14, 0XAC0);
            goto L_80069F5C;
    }
    // 0x80069F38: addiu       $v0, $t6, 0xAC0
    ctx->r2 = ADD32(ctx->r14, 0XAC0);
    // 0x80069F3C: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80069F40: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80069F44: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80069F48: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
L_80069F4C:
    // 0x80069F4C: addiu       $v0, $v0, 0x44
    ctx->r2 = ADD32(ctx->r2, 0X44);
    // 0x80069F50: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80069F54: beq         $at, $zero, L_80069F4C
    if (ctx->r1 == 0) {
        // 0x80069F58: swc1        $f12, -0x14($v0)
        MEM_W(-0X14, ctx->r2) = ctx->f12.u32l;
            goto L_80069F4C;
    }
    // 0x80069F58: swc1        $f12, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->f12.u32l;
L_80069F5C:
    // 0x80069F5C: jr          $ra
    // 0x80069F60: nop

    return;
    // 0x80069F60: nop

;}
RECOMP_FUNC void filename_enter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097D10: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80097D14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80097D18: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80097D1C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80097D20: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80097D24: jal         0x8006A554
    // 0x80097D28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x80097D28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80097D2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80097D30: jal         0x8006A59C
    // 0x80097D34: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    input_clamp_stick_x(rdram, ctx);
        goto after_1;
    // 0x80097D34: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80097D38: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80097D3C: slti        $at, $v0, -0x22
    ctx->r1 = SIGNED(ctx->r2) < -0X22 ? 1 : 0;
    // 0x80097D40: bne         $at, $zero, L_80097D58
    if (ctx->r1 != 0) {
        // 0x80097D44: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80097D58;
    }
    // 0x80097D44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80097D48: slti        $at, $v0, 0x23
    ctx->r1 = SIGNED(ctx->r2) < 0X23 ? 1 : 0;
    // 0x80097D4C: beq         $at, $zero, L_80097D58
    if (ctx->r1 == 0) {
        // 0x80097D50: nop
    
            goto L_80097D58;
    }
    // 0x80097D50: nop

    // 0x80097D54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80097D58:
    // 0x80097D58: bgez        $a0, L_80097DC4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80097D5C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_80097DC4;
    }
    // 0x80097D5C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80097D60: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80097D64: addiu       $v0, $v0, 0x6C3C
    ctx->r2 = ADD32(ctx->r2, 0X6C3C);
    // 0x80097D68: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80097D6C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80097D70: bltz        $t6, L_80097D84
    if (SIGNED(ctx->r14) < 0) {
        // 0x80097D74: addiu       $v1, $v1, 0x6C34
        ctx->r3 = ADD32(ctx->r3, 0X6C34);
            goto L_80097D84;
    }
    // 0x80097D74: addiu       $v1, $v1, 0x6C34
    ctx->r3 = ADD32(ctx->r3, 0X6C34);
    // 0x80097D78: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80097D7C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80097D80: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80097D84:
    // 0x80097D84: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80097D88: addiu       $v1, $v1, 0x6C34
    ctx->r3 = ADD32(ctx->r3, 0X6C34);
    // 0x80097D8C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80097D90: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80097D94: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80097D98: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x80097D9C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80097DA0: beq         $t3, $t2, L_80097E44
    if (ctx->r11 == ctx->r10) {
        // 0x80097DA4: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_80097E44;
    }
    // 0x80097DA4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80097DA8: slti        $at, $t2, 0x1C
    ctx->r1 = SIGNED(ctx->r10) < 0X1C ? 1 : 0;
    // 0x80097DAC: beq         $at, $zero, L_80097DBC
    if (ctx->r1 == 0) {
        // 0x80097DB0: addiu       $t4, $v0, -0x6
        ctx->r12 = ADD32(ctx->r2, -0X6);
            goto L_80097DBC;
    }
    // 0x80097DB0: addiu       $t4, $v0, -0x6
    ctx->r12 = ADD32(ctx->r2, -0X6);
    // 0x80097DB4: b           L_80097E44
    // 0x80097DB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80097E44;
    // 0x80097DB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80097DBC:
    // 0x80097DBC: b           L_80097E44
    // 0x80097DC0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
        goto L_80097E44;
    // 0x80097DC0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_80097DC4:
    // 0x80097DC4: blez        $a0, L_80097E30
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80097DC8: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80097E30;
    }
    // 0x80097DC8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80097DCC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80097DD0: addiu       $v0, $v0, 0x6C3C
    ctx->r2 = ADD32(ctx->r2, 0X6C3C);
    // 0x80097DD4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80097DD8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80097DDC: bgtz        $t5, L_80097DF0
    if (SIGNED(ctx->r13) > 0) {
        // 0x80097DE0: addiu       $v1, $v1, 0x6C34
        ctx->r3 = ADD32(ctx->r3, 0X6C34);
            goto L_80097DF0;
    }
    // 0x80097DE0: addiu       $v1, $v1, 0x6C34
    ctx->r3 = ADD32(ctx->r3, 0X6C34);
    // 0x80097DE4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80097DE8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80097DEC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80097DF0:
    // 0x80097DF0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80097DF4: addiu       $v1, $v1, 0x6C34
    ctx->r3 = ADD32(ctx->r3, 0X6C34);
    // 0x80097DF8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80097DFC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80097E00: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80097E04: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80097E08: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80097E0C: beq         $t2, $t9, L_80097E44
    if (ctx->r10 == ctx->r25) {
        // 0x80097E10: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80097E44;
    }
    // 0x80097E10: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80097E14: slti        $at, $t9, 0x1C
    ctx->r1 = SIGNED(ctx->r25) < 0X1C ? 1 : 0;
    // 0x80097E18: beq         $at, $zero, L_80097E28
    if (ctx->r1 == 0) {
        // 0x80097E1C: addiu       $t3, $v0, -0x6
        ctx->r11 = ADD32(ctx->r2, -0X6);
            goto L_80097E28;
    }
    // 0x80097E1C: addiu       $t3, $v0, -0x6
    ctx->r11 = ADD32(ctx->r2, -0X6);
    // 0x80097E20: b           L_80097E44
    // 0x80097E24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80097E44;
    // 0x80097E24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80097E28:
    // 0x80097E28: b           L_80097E44
    // 0x80097E2C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
        goto L_80097E44;
    // 0x80097E2C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80097E30:
    // 0x80097E30: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80097E34: addiu       $v1, $v1, 0x6C34
    ctx->r3 = ADD32(ctx->r3, 0X6C34);
    // 0x80097E38: addiu       $v0, $v0, 0x6C3C
    ctx->r2 = ADD32(ctx->r2, 0X6C3C);
    // 0x80097E3C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80097E40: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80097E44:
    // 0x80097E44: lw          $a1, 0x6C6C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6C6C);
    // 0x80097E48: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80097E4C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80097E50: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80097E54: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80097E58: blez        $t5, L_80097F5C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80097E5C: cvt.s.w     $f20, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80097F5C;
    }
    // 0x80097E5C: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80097E60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80097E64: lwc1        $f0, 0x6C50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6C50);
    // 0x80097E68: lui         $at, 0x41F8
    ctx->r1 = S32(0X41F8 << 16);
    // 0x80097E6C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80097E70: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80097E74: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80097E78: addiu       $v0, $v0, 0x6C50
    ctx->r2 = ADD32(ctx->r2, 0X6C50);
L_80097E7C:
    // 0x80097E7C: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x80097E80: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80097E84: bc1f        L_80097E9C
    if (!c1cs) {
        // 0x80097E88: nop
    
            goto L_80097E9C;
    }
    // 0x80097E88: nop

    // 0x80097E8C: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80097E90: sub.s       $f12, $f20, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x80097E94: b           L_80097EA8
    // 0x80097E98: sub.s       $f14, $f20, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f6.fl;
        goto L_80097EA8;
    // 0x80097E98: sub.s       $f14, $f20, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f6.fl;
L_80097E9C:
    // 0x80097E9C: add.s       $f8, $f20, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f20.fl + ctx->f2.fl;
    // 0x80097EA0: sub.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80097EA4: sub.s       $f14, $f20, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f20.fl - ctx->f0.fl;
L_80097EA8:
    // 0x80097EA8: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80097EAC: nop

    // 0x80097EB0: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80097EB4: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80097EB8: nop

    // 0x80097EBC: bc1f        L_80097ECC
    if (!c1cs) {
        // 0x80097EC0: nop
    
            goto L_80097ECC;
    }
    // 0x80097EC0: nop

    // 0x80097EC4: b           L_80097ED0
    // 0x80097EC8: mov.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.fl = ctx->f12.fl;
        goto L_80097ED0;
    // 0x80097EC8: mov.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.fl = ctx->f12.fl;
L_80097ECC:
    // 0x80097ECC: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
L_80097ED0:
    // 0x80097ED0: lwc1        $f6, -0x7A94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7A94);
    // 0x80097ED4: nop

    // 0x80097ED8: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80097EDC: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80097EE0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80097EE4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80097EE8: nop

    // 0x80097EEC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80097EF0: nop

    // 0x80097EF4: bc1f        L_80097F1C
    if (!c1cs) {
        // 0x80097EF8: nop
    
            goto L_80097F1C;
    }
    // 0x80097EF8: nop

L_80097EFC:
    // 0x80097EFC: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80097F00: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80097F04: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80097F08: nop

    // 0x80097F0C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80097F10: nop

    // 0x80097F14: bc1t        L_80097EFC
    if (c1cs) {
        // 0x80097F18: nop
    
            goto L_80097EFC;
    }
    // 0x80097F18: nop

L_80097F1C:
    // 0x80097F1C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80097F20: nop

    // 0x80097F24: bc1f        L_80097F50
    if (!c1cs) {
        // 0x80097F28: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_80097F50;
    }
    // 0x80097F28: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_80097F2C:
    // 0x80097F2C: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80097F30: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80097F34: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80097F38: nop

    // 0x80097F3C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80097F40: nop

    // 0x80097F44: bc1t        L_80097F2C
    if (c1cs) {
        // 0x80097F48: nop
    
            goto L_80097F2C;
    }
    // 0x80097F48: nop

    // 0x80097F4C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
L_80097F50:
    // 0x80097F50: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80097F54: bne         $v1, $t6, L_80097E7C
    if (ctx->r3 != ctx->r14) {
        // 0x80097F58: nop
    
            goto L_80097E7C;
    }
    // 0x80097F58: nop

L_80097F5C:
    // 0x80097F5C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80097F60: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80097F64: addiu       $a3, $a3, 0x6C78
    ctx->r7 = ADD32(ctx->r7, 0X6C78);
    // 0x80097F68: addiu       $v1, $v1, 0xFA0
    ctx->r3 = ADD32(ctx->r3, 0XFA0);
    // 0x80097F6C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80097F70: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80097F74: andi        $t7, $t0, 0x9000
    ctx->r15 = ctx->r8 & 0X9000;
    // 0x80097F78: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80097F7C: beq         $at, $zero, L_80098170
    if (ctx->r1 == 0) {
        // 0x80097F80: andi        $t4, $t0, 0x9000
        ctx->r12 = ctx->r8 & 0X9000;
            goto L_80098170;
    }
    // 0x80097F80: andi        $t4, $t0, 0x9000
    ctx->r12 = ctx->r8 & 0X9000;
    // 0x80097F84: beq         $t7, $zero, L_800980D8
    if (ctx->r15 == 0) {
        // 0x80097F88: andi        $t7, $t0, 0x4000
        ctx->r15 = ctx->r8 & 0X4000;
            goto L_800980D8;
    }
    // 0x80097F88: andi        $t7, $t0, 0x4000
    ctx->r15 = ctx->r8 & 0X4000;
    // 0x80097F8C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80097F90: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80097F94: slti        $at, $t1, 0x1D
    ctx->r1 = SIGNED(ctx->r9) < 0X1D ? 1 : 0;
    // 0x80097F98: beq         $at, $zero, L_80098010
    if (ctx->r1 == 0) {
        // 0x80097F9C: addiu       $t0, $t0, 0x6C74
        ctx->r8 = ADD32(ctx->r8, 0X6C74);
            goto L_80098010;
    }
    // 0x80097F9C: addiu       $t0, $t0, 0x6C74
    ctx->r8 = ADD32(ctx->r8, 0X6C74);
    // 0x80097FA0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80097FA4: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80097FA8: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x80097FAC: lbu         $t8, 0xF6C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0XF6C);
    // 0x80097FB0: addu        $t2, $t9, $v0
    ctx->r10 = ADD32(ctx->r25, ctx->r2);
    // 0x80097FB4: sb          $t8, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r24;
    // 0x80097FB8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80097FBC: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80097FC0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80097FC4: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80097FC8: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x80097FCC: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x80097FD0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80097FD4: jal         0x80001D04
    // 0x80097FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80097FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80097FDC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80097FE0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80097FE4: addiu       $a3, $a3, 0x6C78
    ctx->r7 = ADD32(ctx->r7, 0X6C78);
    // 0x80097FE8: addiu       $v1, $v1, 0xFA0
    ctx->r3 = ADD32(ctx->r3, 0XFA0);
    // 0x80097FEC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80097FF0: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80097FF4: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x80097FF8: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80097FFC: bne         $at, $zero, L_800981C0
    if (ctx->r1 != 0) {
        // 0x80098000: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800981C0;
    }
    // 0x80098000: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80098004: lw          $t3, 0x6C6C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6C6C);
    // 0x80098008: b           L_800981C0
    // 0x8009800C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
        goto L_800981C0;
    // 0x8009800C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
L_80098010:
    // 0x80098010: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x80098014: bne         $t1, $at, L_80098050
    if (ctx->r9 != ctx->r1) {
        // 0x80098018: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80098050;
    }
    // 0x80098018: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009801C: blez        $v0, L_80098040
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80098020: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_80098040;
    }
    // 0x80098020: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80098024: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80098028: addiu       $t0, $t0, 0x6C74
    ctx->r8 = ADD32(ctx->r8, 0X6C74);
    // 0x8009802C: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80098030: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80098034: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80098038: addu        $t7, $t5, $t4
    ctx->r15 = ADD32(ctx->r13, ctx->r12);
    // 0x8009803C: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
L_80098040:
    // 0x80098040: jal         0x80001D04
    // 0x80098044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x80098044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80098048: b           L_800981C4
    // 0x8009804C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
        goto L_800981C4;
    // 0x8009804C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_80098050:
    // 0x80098050: bne         $v0, $zero, L_80098074
    if (ctx->r2 != 0) {
        // 0x80098054: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80098074;
    }
    // 0x80098054: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80098058: addiu       $t0, $t0, 0x6C74
    ctx->r8 = ADD32(ctx->r8, 0X6C74);
    // 0x8009805C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80098060: nop

    // 0x80098064: lbu         $t8, 0x0($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X0);
    // 0x80098068: nop

    // 0x8009806C: bne         $t8, $zero, L_800980B0
    if (ctx->r24 != 0) {
        // 0x80098070: nop
    
            goto L_800980B0;
    }
    // 0x80098070: nop

L_80098074:
    // 0x80098074: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80098078: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8009807C: addiu       $t0, $t0, 0x6C74
    ctx->r8 = ADD32(ctx->r8, 0X6C74);
    // 0x80098080: beq         $at, $zero, L_800980B0
    if (ctx->r1 == 0) {
        // 0x80098084: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800980B0;
    }
    // 0x80098084: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80098088: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
L_8009808C:
    // 0x8009808C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80098090: nop

    // 0x80098094: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80098098: sb          $v0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r2;
    // 0x8009809C: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x800980A0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800980A4: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800980A8: bne         $at, $zero, L_8009808C
    if (ctx->r1 != 0) {
        // 0x800980AC: nop
    
            goto L_8009808C;
    }
    // 0x800980AC: nop

L_800980B0:
    // 0x800980B0: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800980B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800980B8: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800980BC: jal         0x80001D04
    // 0x800980C0: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x800980C0: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    after_4:
    // 0x800980C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800980C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800980CC: b           L_800981C0
    // 0x800980D0: sw          $t6, 0x6C48($at)
    MEM_W(0X6C48, ctx->r1) = ctx->r14;
        goto L_800981C0;
    // 0x800980D0: sw          $t6, 0x6C48($at)
    MEM_W(0X6C48, ctx->r1) = ctx->r14;
    // 0x800980D4: andi        $t7, $t0, 0x4000
    ctx->r15 = ctx->r8 & 0X4000;
L_800980D8:
    // 0x800980D8: beq         $t7, $zero, L_80098114
    if (ctx->r15 == 0) {
        // 0x800980DC: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80098114;
    }
    // 0x800980DC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800980E0: blez        $v0, L_800980F4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800980E4: addiu       $t0, $t0, 0x6C74
        ctx->r8 = ADD32(ctx->r8, 0X6C74);
            goto L_800980F4;
    }
    // 0x800980E4: addiu       $t0, $t0, 0x6C74
    ctx->r8 = ADD32(ctx->r8, 0X6C74);
    // 0x800980E8: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800980EC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800980F0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800980F4:
    // 0x800980F4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800980F8: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x800980FC: addu        $t2, $t8, $v0
    ctx->r10 = ADD32(ctx->r24, ctx->r2);
    // 0x80098100: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
    // 0x80098104: jal         0x80001D04
    // 0x80098108: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x80098108: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8009810C: b           L_800981C4
    // 0x80098110: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
        goto L_800981C4;
    // 0x80098110: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_80098114:
    // 0x80098114: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80098118: bgez        $a0, L_80098124
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8009811C: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80098124;
    }
    // 0x8009811C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80098120: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80098124:
    // 0x80098124: blez        $a0, L_80098130
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80098128: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80098130;
    }
    // 0x80098128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009812C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80098130:
    // 0x80098130: bgez        $v0, L_8009813C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80098134: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8009813C;
    }
    // 0x80098134: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80098138: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
L_8009813C:
    // 0x8009813C: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x80098140: bne         $at, $zero, L_8009814C
    if (ctx->r1 != 0) {
        // 0x80098144: nop
    
            goto L_8009814C;
    }
    // 0x80098144: nop

    // 0x80098148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009814C:
    // 0x8009814C: beq         $v0, $t1, L_800981C0
    if (ctx->r2 == ctx->r9) {
        // 0x80098150: nop
    
            goto L_800981C0;
    }
    // 0x80098150: nop

    // 0x80098154: jal         0x80001D04
    // 0x80098158: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x80098158: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_6:
    // 0x8009815C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80098160: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80098164: lw          $t3, 0x6C6C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6C6C);
    // 0x80098168: b           L_800981C0
    // 0x8009816C: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
        goto L_800981C0;
    // 0x8009816C: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
L_80098170:
    // 0x80098170: beq         $t4, $zero, L_80098194
    if (ctx->r12 == 0) {
        // 0x80098174: andi        $t6, $t0, 0x4000
        ctx->r14 = ctx->r8 & 0X4000;
            goto L_80098194;
    }
    // 0x80098174: andi        $t6, $t0, 0x4000
    ctx->r14 = ctx->r8 & 0X4000;
    // 0x80098178: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009817C: jal         0x80001D04
    // 0x80098180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_7;
    // 0x80098180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80098184: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80098188: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009818C: b           L_800981C0
    // 0x80098190: sw          $t5, 0x6C48($at)
    MEM_W(0X6C48, ctx->r1) = ctx->r13;
        goto L_800981C0;
    // 0x80098190: sw          $t5, 0x6C48($at)
    MEM_W(0X6C48, ctx->r1) = ctx->r13;
L_80098194:
    // 0x80098194: beq         $t6, $zero, L_800981C0
    if (ctx->r14 == 0) {
        // 0x80098198: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800981C0;
    }
    // 0x80098198: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8009819C: addiu       $t0, $t0, 0x6C74
    ctx->r8 = ADD32(ctx->r8, 0X6C74);
    // 0x800981A0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800981A4: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800981A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800981AC: addu        $t2, $t9, $t7
    ctx->r10 = ADD32(ctx->r25, ctx->r15);
    // 0x800981B0: sb          $zero, 0x0($t2)
    MEM_B(0X0, ctx->r10) = 0;
    // 0x800981B4: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x800981B8: jal         0x80001D04
    // 0x800981BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800981BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
L_800981C0:
    // 0x800981C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_800981C4:
    // 0x800981C4: jal         0x80097918
    // 0x800981C8: nop

    filename_render(rdram, ctx);
        goto after_9;
    // 0x800981C8: nop

    after_9:
    // 0x800981CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800981D0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800981D4: lw          $v0, 0x6C48($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6C48);
    // 0x800981D8: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800981DC: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800981E0: jr          $ra
    // 0x800981E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800981E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void obj_loop_pigrocketeer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042998: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004299C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800429A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800429A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800429A8: jal         0x8001F460
    // 0x800429AC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x800429AC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_0:
    // 0x800429B0: jal         0x8000BF44
    // 0x800429B4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    racerfx_get_boost(rdram, ctx);
        goto after_1;
    // 0x800429B4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_1:
    // 0x800429B8: beq         $v0, $zero, L_80042A10
    if (ctx->r2 == 0) {
        // 0x800429BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80042A10;
    }
    // 0x800429BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800429C0: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x800429C4: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
    // 0x800429C8: beq         $v1, $zero, L_80042A0C
    if (ctx->r3 == 0) {
        // 0x800429CC: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_80042A0C;
    }
    // 0x800429CC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800429D0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800429D4: lbu         $t6, 0x72($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X72);
    // 0x800429D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800429DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800429E0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800429E4: sb          $t8, 0x72($v1)
    MEM_B(0X72, ctx->r3) = ctx->r24;
    // 0x800429E8: sb          $t9, 0x70($v1)
    MEM_B(0X70, ctx->r3) = ctx->r25;
    // 0x800429EC: swc1        $f4, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f4.u32l;
    // 0x800429F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800429F4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800429F8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800429FC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80042A00: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80042A04: jal         0x8000B750
    // 0x80042A08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8000B750(rdram, ctx);
        goto after_2;
    // 0x80042A08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
L_80042A0C:
    // 0x80042A0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80042A10:
    // 0x80042A10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80042A14: jr          $ra
    // 0x80042A18: nop

    return;
    // 0x80042A18: nop

;}
RECOMP_FUNC void transition_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C05C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C05CC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C05D0: lw          $t6, 0x31AC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31AC);
    // 0x800C05D4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C05D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C05DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C05E0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C05E4: beq         $t6, $zero, L_800C0710
    if (ctx->r14 == 0) {
        // 0x800C05E8: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800C0710;
    }
    // 0x800C05E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C05EC: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800C05F0: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800C05F4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C05F8: bne         $t7, $zero, L_800C061C
    if (ctx->r15 != 0) {
        // 0x800C05FC: nop
    
            goto L_800C061C;
    }
    // 0x800C05FC: nop

    // 0x800C0600: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C0604: lwc1        $f12, -0x6CF8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6CF8);
    // 0x800C0608: jal         0x80067F20
    // 0x800C060C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    set_ortho_matrix_height(rdram, ctx);
        goto after_0;
    // 0x800C060C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C0610: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800C0614: b           L_800C0634
    // 0x800C0618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0634;
    // 0x800C0618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C061C:
    // 0x800C061C: lwc1        $f12, -0x6CF4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6CF4);
    // 0x800C0620: jal         0x80067F20
    // 0x800C0624: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    set_ortho_matrix_height(rdram, ctx);
        goto after_1;
    // 0x800C0624: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x800C0628: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800C062C: nop

    // 0x800C0630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0634:
    extern void dkr_transition_cover_begin(uint8_t*, recomp_context*); dkr_transition_cover_begin(rdram, ctx);
    // 0x800C0634: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C0638: jal         0x80067F2C
    // 0x800C063C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    mtx_ortho(rdram, ctx);
        goto after_2;
    // 0x800C063C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_2:
    extern void dkr_transition_cover_end(uint8_t*, recomp_context*); dkr_transition_cover_end(rdram, ctx);
    // 0x800C0640: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C0644: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C0648: jal         0x80067F20
    // 0x800C064C: nop

    set_ortho_matrix_height(rdram, ctx);
        goto after_3;
    // 0x800C064C: nop

    after_3:
    // 0x800C0650: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C0654: lw          $t8, -0x58D0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X58D0);
    // 0x800C0658: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800C065C: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x800C0660: beq         $at, $zero, L_800C0704
    if (ctx->r1 == 0) {
        // 0x800C0664: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800C0704;
    }
    // 0x800C0664: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800C0668: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C066C: addu        $at, $at, $t8
    gpr jr_addend_800C0678 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800C0670: lw          $t8, -0x6CF0($at)
    ctx->r24 = ADD32(ctx->r1, -0X6CF0);
    // 0x800C0674: nop

    // 0x800C0678: jr          $t8
    // 0x800C067C: nop

    switch (jr_addend_800C0678 >> 2) {
        case 0: goto L_800C0680; break;
        case 1: goto L_800C0694; break;
        case 2: goto L_800C06A8; break;
        case 3: goto L_800C06BC; break;
        case 4: goto L_800C06D0; break;
        case 5: goto L_800C06E4; break;
        case 6: goto L_800C06F8; break;
        default: switch_error(__func__, 0x800C0678, 0x800E9310);
    }
    // 0x800C067C: nop

L_800C0680:
    // 0x800C0680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0684: jal         0x800C0A08
    // 0x800C0688: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_fullscreen(rdram, ctx);
        goto after_4;
    // 0x800C0688: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x800C068C: b           L_800C0708
    // 0x800C0690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0708;
    // 0x800C0690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0694:
    // 0x800C0694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0698: jal         0x800C13E4
    // 0x800C069C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_barndoor_hor(rdram, ctx);
        goto after_5;
    // 0x800C069C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x800C06A0: b           L_800C0708
    // 0x800C06A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0708;
    // 0x800C06A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C06A8:
    // 0x800C06A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C06AC: jal         0x800C14DC
    // 0x800C06B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_barndoor_vert(rdram, ctx);
        goto after_6;
    // 0x800C06B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x800C06B4: b           L_800C0708
    // 0x800C06B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0708;
    // 0x800C06B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C06BC:
    // 0x800C06BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C06C0: jal         0x800C2274
    // 0x800C06C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_circle(rdram, ctx);
        goto after_7;
    // 0x800C06C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x800C06C8: b           L_800C0708
    // 0x800C06CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0708;
    // 0x800C06CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C06D0:
    // 0x800C06D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C06D4: jal         0x800C23F8
    // 0x800C06D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_waves(rdram, ctx);
        goto after_8;
    // 0x800C06D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x800C06DC: b           L_800C0708
    // 0x800C06E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0708;
    // 0x800C06E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C06E4:
    // 0x800C06E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C06E8: jal         0x800C2548
    // 0x800C06EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_barndoor_diag(rdram, ctx);
        goto after_9;
    // 0x800C06EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x800C06F0: b           L_800C0708
    // 0x800C06F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800C0708;
    // 0x800C06F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C06F8:
    // 0x800C06F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C06FC: jal         0x800C28E8
    // 0x800C0700: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    transition_render_blank(rdram, ctx);
        goto after_10;
    // 0x800C0700: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
L_800C0704:
    // 0x800C0704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C0708:
    extern void dkr_transition_interpolation_end(uint8_t*, recomp_context*); dkr_transition_interpolation_end(rdram, ctx);
    // 0x800C0708: jal         0x80066CDC
    // 0x800C070C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    viewport_main(rdram, ctx);
        goto after_11;
    // 0x800C070C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_11:
L_800C0710:
    // 0x800C0710: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0714: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C0718: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C071C: jr          $ra
    // 0x800C0720: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C0720: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void material_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B4E8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007B4EC: addiu       $t3, $t3, 0x6382
    ctx->r11 = ADD32(ctx->r11, 0X6382);
    // 0x8007B4F0: lh          $v1, 0x0($t3)
    ctx->r3 = MEM_H(ctx->r11, 0X0);
    // 0x8007B4F4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007B4F8: beq         $a1, $zero, L_8007B5BC
    if (ctx->r5 == 0) {
        // 0x8007B4FC: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8007B5BC;
    }
    // 0x8007B4FC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007B500: beq         $a3, $zero, L_8007B538
    if (ctx->r7 == 0) {
        // 0x8007B504: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_8007B538;
    }
    // 0x8007B504: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007B508: lhu         $t6, 0x12($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X12);
    // 0x8007B50C: nop

    // 0x8007B510: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8007B514: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8007B518: beq         $at, $zero, L_8007B538
    if (ctx->r1 == 0) {
        // 0x8007B51C: nop
    
            goto L_8007B538;
    }
    // 0x8007B51C: nop

    // 0x8007B520: lh          $t9, 0x16($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X16);
    // 0x8007B524: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8007B528: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B52C: mflo        $t6
    ctx->r14 = lo;
    // 0x8007B530: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x8007B534: nop

L_8007B538:
    // 0x8007B538: addiu       $t4, $t4, 0x637C
    ctx->r12 = ADD32(ctx->r12, 0X637C);
    // 0x8007B53C: lh          $t7, 0x6($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X6);
    // 0x8007B540: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8007B544: or          $a2, $a2, $t7
    ctx->r6 = ctx->r6 | ctx->r15;
    // 0x8007B548: beq         $a1, $t8, L_8007B598
    if (ctx->r5 == ctx->r24) {
        // 0x8007B54C: nop
    
            goto L_8007B598;
    }
    // 0x8007B54C: nop

    // 0x8007B550: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007B554: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007B558: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007B55C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007B560: lh          $t2, 0xA($a1)
    ctx->r10 = MEM_H(ctx->r5, 0XA);
    // 0x8007B564: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8007B568: andi        $t6, $t2, 0xFF
    ctx->r14 = ctx->r10 & 0XFF;
    // 0x8007B56C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8007B570: sll         $t9, $t2, 3
    ctx->r25 = S32(ctx->r10 << 3);
    // 0x8007B574: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8007B578: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8007B57C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8007B580: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007B584: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x8007B588: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8007B58C: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x8007B590: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007B594: sw          $a1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r5;
L_8007B598:
    // 0x8007B598: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007B59C: addiu       $t2, $t2, 0x6380
    ctx->r10 = ADD32(ctx->r10, 0X6380);
    // 0x8007B5A0: lh          $t6, 0x0($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X0);
    // 0x8007B5A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007B5A8: bne         $t6, $zero, L_8007B5DC
    if (ctx->r14 != 0) {
        // 0x8007B5AC: nop
    
            goto L_8007B5DC;
    }
    // 0x8007B5AC: nop

    // 0x8007B5B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007B5B4: b           L_8007B5DC
    // 0x8007B5B8: sh          $t7, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r15;
        goto L_8007B5DC;
    // 0x8007B5B8: sh          $t7, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r15;
L_8007B5BC:
    // 0x8007B5BC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007B5C0: addiu       $t2, $t2, 0x6380
    ctx->r10 = ADD32(ctx->r10, 0X6380);
    // 0x8007B5C4: lh          $t9, 0x0($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X0);
    // 0x8007B5C8: nop

    // 0x8007B5CC: beq         $t9, $zero, L_8007B5DC
    if (ctx->r25 == 0) {
        // 0x8007B5D0: nop
    
            goto L_8007B5DC;
    }
    // 0x8007B5D0: nop

    // 0x8007B5D4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007B5D8: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
L_8007B5DC:
    // 0x8007B5DC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8007B5E0: addiu       $t4, $t4, 0x6384
    ctx->r12 = ADD32(ctx->r12, 0X6384);
    // 0x8007B5E4: lh          $t8, 0x0($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X0);
    // 0x8007B5E8: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8007B5EC: beq         $t8, $zero, L_8007B600
    if (ctx->r24 == 0) {
        // 0x8007B5F0: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8007B600;
    }
    // 0x8007B5F0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007B5F4: andi        $t6, $a2, 0x827
    ctx->r14 = ctx->r6 & 0X827;
    // 0x8007B5F8: b           L_8007B610
    // 0x8007B5FC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
        goto L_8007B610;
    // 0x8007B5FC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
L_8007B600:
    // 0x8007B600: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8007B604: ori         $at, $at, 0x93F
    ctx->r1 = ctx->r1 | 0X93F;
    // 0x8007B608: and         $t7, $a2, $at
    ctx->r15 = ctx->r6 & ctx->r1;
    // 0x8007B60C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_8007B610:
    // 0x8007B610: lw          $t9, 0x6378($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6378);
    // 0x8007B614: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8007B618: nor         $t8, $t9, $zero
    ctx->r24 = ~(ctx->r25 | 0);
    // 0x8007B61C: and         $a2, $a2, $t8
    ctx->r6 = ctx->r6 & ctx->r24;
    // 0x8007B620: sll         $t6, $a2, 4
    ctx->r14 = S32(ctx->r6 << 4);
    // 0x8007B624: bgez        $t6, L_8007B63C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8007B628: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_8007B63C;
    }
    // 0x8007B628: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8007B62C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8007B630: and         $t7, $a2, $at
    ctx->r15 = ctx->r6 & ctx->r1;
    // 0x8007B634: b           L_8007B648
    // 0x8007B638: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
        goto L_8007B648;
    // 0x8007B638: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_8007B63C:
    // 0x8007B63C: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x8007B640: and         $t9, $a2, $at
    ctx->r25 = ctx->r6 & ctx->r1;
    // 0x8007B644: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
L_8007B648:
    // 0x8007B648: addiu       $a3, $a3, 0x6374
    ctx->r7 = ADD32(ctx->r7, 0X6374);
    // 0x8007B64C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8007B650: nop

    // 0x8007B654: bne         $a2, $t5, L_8007B664
    if (ctx->r6 != ctx->r13) {
        // 0x8007B658: nop
    
            goto L_8007B664;
    }
    // 0x8007B658: nop

    // 0x8007B65C: beq         $v1, $zero, L_8007BA54
    if (ctx->r3 == 0) {
        // 0x8007B660: nop
    
            goto L_8007BA54;
    }
    // 0x8007B660: nop

L_8007B664:
    // 0x8007B664: beq         $t0, $zero, L_8007B690
    if (ctx->r8 == 0) {
        // 0x8007B668: and         $t0, $a2, $a1
        ctx->r8 = ctx->r6 & ctx->r5;
            goto L_8007B690;
    }
    // 0x8007B668: and         $t0, $a2, $a1
    ctx->r8 = ctx->r6 & ctx->r5;
    // 0x8007B66C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007B670: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8007B674: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007B678: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007B67C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007B680: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007B684: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8007B688: nop

    // 0x8007B68C: and         $t0, $a2, $a1
    ctx->r8 = ctx->r6 & ctx->r5;
L_8007B690:
    // 0x8007B690: and         $t7, $t5, $a1
    ctx->r15 = ctx->r13 & ctx->r5;
    // 0x8007B694: bne         $t7, $t0, L_8007B6AC
    if (ctx->r15 != ctx->r8) {
        // 0x8007B698: nop
    
            goto L_8007B6AC;
    }
    // 0x8007B698: nop

    // 0x8007B69C: lh          $t9, 0x0($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X0);
    // 0x8007B6A0: nop

    // 0x8007B6A4: beq         $t9, $zero, L_8007B718
    if (ctx->r25 == 0) {
        // 0x8007B6A8: andi        $t9, $a2, 0x2
        ctx->r25 = ctx->r6 & 0X2;
            goto L_8007B718;
    }
    // 0x8007B6A8: andi        $t9, $a2, 0x2
    ctx->r25 = ctx->r6 & 0X2;
L_8007B6AC:
    // 0x8007B6AC: bne         $t0, $zero, L_8007B6C4
    if (ctx->r8 != 0) {
        // 0x8007B6B0: lui         $t7, 0xB600
        ctx->r15 = S32(0XB600 << 16);
            goto L_8007B6C4;
    }
    // 0x8007B6B0: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8007B6B4: lh          $t8, 0x0($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X0);
    // 0x8007B6B8: nop

    // 0x8007B6BC: beq         $t8, $zero, L_8007B6E8
    if (ctx->r24 == 0) {
        // 0x8007B6C0: nop
    
            goto L_8007B6E8;
    }
    // 0x8007B6C0: nop

L_8007B6C4:
    // 0x8007B6C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007B6C8: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8007B6CC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007B6D0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007B6D4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007B6D8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007B6DC: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8007B6E0: b           L_8007B718
    // 0x8007B6E4: andi        $t9, $a2, 0x2
    ctx->r25 = ctx->r6 & 0X2;
        goto L_8007B718;
    // 0x8007B6E4: andi        $t9, $a2, 0x2
    ctx->r25 = ctx->r6 & 0X2;
L_8007B6E8:
    // 0x8007B6E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007B6EC: lui         $v1, 0xB700
    ctx->r3 = S32(0XB700 << 16);
    // 0x8007B6F0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8007B6F4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007B6F8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007B6FC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8007B700: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8007B704: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8007B708: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x8007B70C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x8007B710: nop

    // 0x8007B714: andi        $t9, $a2, 0x2
    ctx->r25 = ctx->r6 & 0X2;
L_8007B718:
    // 0x8007B718: andi        $t8, $t5, 0x2
    ctx->r24 = ctx->r13 & 0X2;
    // 0x8007B71C: lui         $v1, 0xB700
    ctx->r3 = S32(0XB700 << 16);
    // 0x8007B720: bne         $t8, $t9, L_8007B738
    if (ctx->r24 != ctx->r25) {
        // 0x8007B724: sw          $t9, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r25;
            goto L_8007B738;
    }
    // 0x8007B724: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x8007B728: lh          $t6, 0x0($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X0);
    // 0x8007B72C: nop

    // 0x8007B730: beq         $t6, $zero, L_8007B77C
    if (ctx->r14 == 0) {
        // 0x8007B734: nop
    
            goto L_8007B77C;
    }
    // 0x8007B734: nop

L_8007B738:
    // 0x8007B738: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8007B73C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007B740: beq         $t9, $zero, L_8007B764
    if (ctx->r25 == 0) {
        // 0x8007B744: nop
    
            goto L_8007B764;
    }
    // 0x8007B744: nop

    // 0x8007B748: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007B74C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007B750: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007B754: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007B758: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007B75C: b           L_8007B77C
    // 0x8007B760: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
        goto L_8007B77C;
    // 0x8007B760: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_8007B764:
    // 0x8007B764: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007B768: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x8007B76C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007B770: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007B774: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007B778: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8007B77C:
    // 0x8007B77C: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x8007B780: sh          $zero, 0x0($t3)
    MEM_H(0X0, ctx->r11) = 0;
    // 0x8007B784: bne         $t7, $zero, L_8007B800
    if (ctx->r15 != 0) {
        // 0x8007B788: sw          $a2, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r6;
            goto L_8007B800;
    }
    // 0x8007B788: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x8007B78C: beq         $t0, $zero, L_8007B7CC
    if (ctx->r8 == 0) {
        // 0x8007B790: lui         $t6, 0x702
        ctx->r14 = S32(0X702 << 16);
            goto L_8007B7CC;
    }
    // 0x8007B790: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x8007B794: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007B798: lui         $t9, 0x702
    ctx->r25 = S32(0X702 << 16);
    // 0x8007B79C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007B7A0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007B7A4: ori         $t9, $t9, 0x10
    ctx->r25 = ctx->r25 | 0X10;
    // 0x8007B7A8: andi        $t8, $a2, 0x3
    ctx->r24 = ctx->r6 & 0X3;
    // 0x8007B7AC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007B7B0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007B7B4: sll         $t7, $t8, 4
    ctx->r15 = S32(ctx->r24 << 4);
    // 0x8007B7B8: addu        $t6, $t7, $t1
    ctx->r14 = ADD32(ctx->r15, ctx->r9);
    // 0x8007B7BC: addiu       $t9, $t9, -0x1118
    ctx->r25 = ADD32(ctx->r25, -0X1118);
    // 0x8007B7C0: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8007B7C4: b           L_8007BA54
    // 0x8007B7C8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_8007BA54;
    // 0x8007B7C8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_8007B7CC:
    // 0x8007B7CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007B7D0: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x8007B7D4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007B7D8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007B7DC: andi        $t9, $a2, 0xF
    ctx->r25 = ctx->r6 & 0XF;
    // 0x8007B7E0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007B7E4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007B7E8: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x8007B7EC: addu        $t7, $t8, $t1
    ctx->r15 = ADD32(ctx->r24, ctx->r9);
    // 0x8007B7F0: addiu       $t6, $t6, -0x10D8
    ctx->r14 = ADD32(ctx->r14, -0X10D8);
    // 0x8007B7F4: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x8007B7F8: b           L_8007BA54
    // 0x8007B7FC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
        goto L_8007BA54;
    // 0x8007B7FC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_8007B800:
    // 0x8007B800: lh          $t8, 0x0($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X0);
    // 0x8007B804: andi        $t7, $a2, 0x800
    ctx->r15 = ctx->r6 & 0X800;
    // 0x8007B808: beq         $t8, $zero, L_8007B8C8
    if (ctx->r24 == 0) {
        // 0x8007B80C: andi        $t9, $a2, 0x800
        ctx->r25 = ctx->r6 & 0X800;
            goto L_8007B8C8;
    }
    // 0x8007B80C: andi        $t9, $a2, 0x800
    ctx->r25 = ctx->r6 & 0X800;
    // 0x8007B810: beq         $t7, $zero, L_8007B888
    if (ctx->r15 == 0) {
        // 0x8007B814: andi        $t6, $a2, 0x20
        ctx->r14 = ctx->r6 & 0X20;
            goto L_8007B888;
    }
    // 0x8007B814: andi        $t6, $a2, 0x20
    ctx->r14 = ctx->r6 & 0X20;
    // 0x8007B818: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8007B81C: andi        $t9, $a2, 0x1
    ctx->r25 = ctx->r6 & 0X1;
    // 0x8007B820: beq         $t6, $zero, L_8007B884
    if (ctx->r14 == 0) {
        // 0x8007B824: andi        $t8, $a2, 0x4
        ctx->r24 = ctx->r6 & 0X4;
            goto L_8007B884;
    }
    // 0x8007B824: andi        $t8, $a2, 0x4
    ctx->r24 = ctx->r6 & 0X4;
    // 0x8007B828: beq         $t9, $zero, L_8007B834
    if (ctx->r25 == 0) {
        // 0x8007B82C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8007B834;
    }
    // 0x8007B82C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007B830: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8007B834:
    // 0x8007B834: beq         $t8, $zero, L_8007B844
    if (ctx->r24 == 0) {
        // 0x8007B838: andi        $t6, $a2, 0x20
        ctx->r14 = ctx->r6 & 0X20;
            goto L_8007B844;
    }
    // 0x8007B838: andi        $t6, $a2, 0x20
    ctx->r14 = ctx->r6 & 0X20;
    // 0x8007B83C: ori         $t7, $a1, 0x2
    ctx->r15 = ctx->r5 | 0X2;
    // 0x8007B840: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8007B844:
    // 0x8007B844: beq         $t6, $zero, L_8007B854
    if (ctx->r14 == 0) {
        // 0x8007B848: lui         $t7, 0x702
        ctx->r15 = S32(0X702 << 16);
            goto L_8007B854;
    }
    // 0x8007B848: lui         $t7, 0x702
    ctx->r15 = S32(0X702 << 16);
    // 0x8007B84C: ori         $t9, $a1, 0x4
    ctx->r25 = ctx->r5 | 0X4;
    // 0x8007B850: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_8007B854:
    // 0x8007B854: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007B858: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8007B85C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007B860: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007B864: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007B868: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8007B86C: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x8007B870: addiu       $t8, $t8, -0xFD8
    ctx->r24 = ADD32(ctx->r24, -0XFD8);
    // 0x8007B874: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007B878: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8007B87C: b           L_8007BA54
    // 0x8007B880: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_8007BA54;
    // 0x8007B880: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8007B884:
    // 0x8007B884: andi        $t6, $a2, 0x20
    ctx->r14 = ctx->r6 & 0X20;
L_8007B888:
    // 0x8007B888: beq         $t6, $zero, L_8007B894
    if (ctx->r14 == 0) {
        // 0x8007B88C: xori        $t9, $a2, 0x20
        ctx->r25 = ctx->r6 ^ 0X20;
            goto L_8007B894;
    }
    // 0x8007B88C: xori        $t9, $a2, 0x20
    ctx->r25 = ctx->r6 ^ 0X20;
    // 0x8007B890: ori         $a2, $t9, 0x8
    ctx->r6 = ctx->r25 | 0X8;
L_8007B894:
    // 0x8007B894: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007B898: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x8007B89C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007B8A0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007B8A4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007B8A8: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x8007B8AC: sll         $t9, $a2, 4
    ctx->r25 = S32(ctx->r6 << 4);
    // 0x8007B8B0: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x8007B8B4: addiu       $t7, $t7, -0xF58
    ctx->r15 = ADD32(ctx->r15, -0XF58);
    // 0x8007B8B8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007B8BC: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x8007B8C0: b           L_8007BA54
    // 0x8007B8C4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_8007BA54;
    // 0x8007B8C4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8007B8C8:
    // 0x8007B8C8: beq         $t9, $zero, L_8007B950
    if (ctx->r25 == 0) {
        // 0x8007B8CC: andi        $t6, $a2, 0x10
        ctx->r14 = ctx->r6 & 0X10;
            goto L_8007B950;
    }
    // 0x8007B8CC: andi        $t6, $a2, 0x10
    ctx->r14 = ctx->r6 & 0X10;
    // 0x8007B8D0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8007B8D4: andi        $t7, $a2, 0x1
    ctx->r15 = ctx->r6 & 0X1;
    // 0x8007B8D8: beq         $t8, $zero, L_8007B950
    if (ctx->r24 == 0) {
        // 0x8007B8DC: nop
    
            goto L_8007B950;
    }
    // 0x8007B8DC: nop

    // 0x8007B8E0: beq         $t7, $zero, L_8007B8EC
    if (ctx->r15 == 0) {
        // 0x8007B8E4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8007B8EC;
    }
    // 0x8007B8E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007B8E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8007B8EC:
    // 0x8007B8EC: andi        $t6, $a2, 0x4
    ctx->r14 = ctx->r6 & 0X4;
    // 0x8007B8F0: beq         $t6, $zero, L_8007B900
    if (ctx->r14 == 0) {
        // 0x8007B8F4: andi        $t8, $a2, 0x8
        ctx->r24 = ctx->r6 & 0X8;
            goto L_8007B900;
    }
    // 0x8007B8F4: andi        $t8, $a2, 0x8
    ctx->r24 = ctx->r6 & 0X8;
    // 0x8007B8F8: ori         $t9, $a1, 0x2
    ctx->r25 = ctx->r5 | 0X2;
    // 0x8007B8FC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_8007B900:
    // 0x8007B900: beq         $t8, $zero, L_8007B910
    if (ctx->r24 == 0) {
        // 0x8007B904: andi        $t6, $a2, 0x20
        ctx->r14 = ctx->r6 & 0X20;
            goto L_8007B910;
    }
    // 0x8007B904: andi        $t6, $a2, 0x20
    ctx->r14 = ctx->r6 & 0X20;
    // 0x8007B908: ori         $t7, $a1, 0x4
    ctx->r15 = ctx->r5 | 0X4;
    // 0x8007B90C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8007B910:
    // 0x8007B910: beq         $t6, $zero, L_8007B920
    if (ctx->r14 == 0) {
        // 0x8007B914: lui         $t7, 0x702
        ctx->r15 = S32(0X702 << 16);
            goto L_8007B920;
    }
    // 0x8007B914: lui         $t7, 0x702
    ctx->r15 = S32(0X702 << 16);
    // 0x8007B918: ori         $t9, $a1, 0x8
    ctx->r25 = ctx->r5 | 0X8;
    // 0x8007B91C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_8007B920:
    // 0x8007B920: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007B924: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8007B928: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007B92C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007B930: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007B934: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8007B938: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x8007B93C: addiu       $t8, $t8, -0x1218
    ctx->r24 = ADD32(ctx->r24, -0X1218);
    // 0x8007B940: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007B944: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8007B948: b           L_8007BA54
    // 0x8007B94C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_8007BA54;
    // 0x8007B94C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8007B950:
    // 0x8007B950: beq         $t6, $zero, L_8007B9A0
    if (ctx->r14 == 0) {
        // 0x8007B954: addiu       $at, $zero, -0x801
        ctx->r1 = ADD32(0, -0X801);
            goto L_8007B9A0;
    }
    // 0x8007B954: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x8007B958: andi        $v0, $a2, 0x7
    ctx->r2 = ctx->r6 & 0X7;
    // 0x8007B95C: andi        $t9, $a2, 0x8
    ctx->r25 = ctx->r6 & 0X8;
    // 0x8007B960: beq         $t9, $zero, L_8007B96C
    if (ctx->r25 == 0) {
        // 0x8007B964: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8007B96C;
    }
    // 0x8007B964: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007B968: ori         $a1, $v0, 0x8
    ctx->r5 = ctx->r2 | 0X8;
L_8007B96C:
    // 0x8007B96C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007B970: lui         $t7, 0x702
    ctx->r15 = S32(0X702 << 16);
    // 0x8007B974: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007B978: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007B97C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007B980: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8007B984: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8007B988: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x8007B98C: addiu       $t8, $t8, -0x1318
    ctx->r24 = ADD32(ctx->r24, -0X1318);
    // 0x8007B990: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007B994: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8007B998: b           L_8007BA54
    // 0x8007B99C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_8007BA54;
    // 0x8007B99C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8007B9A0:
    // 0x8007B9A0: and         $t6, $a2, $at
    ctx->r14 = ctx->r6 & ctx->r1;
    // 0x8007B9A4: and         $t9, $t6, $a1
    ctx->r25 = ctx->r14 & ctx->r5;
    // 0x8007B9A8: beq         $t9, $zero, L_8007BA24
    if (ctx->r25 == 0) {
        // 0x8007B9AC: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_8007BA24;
    }
    // 0x8007B9AC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8007B9B0: andi        $v0, $t6, 0x3
    ctx->r2 = ctx->r14 & 0X3;
    // 0x8007B9B4: andi        $t8, $t6, 0x100
    ctx->r24 = ctx->r14 & 0X100;
    // 0x8007B9B8: beq         $t8, $zero, L_8007B9C8
    if (ctx->r24 == 0) {
        // 0x8007B9BC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8007B9C8;
    }
    // 0x8007B9BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007B9C0: b           L_8007B9F0
    // 0x8007B9C4: ori         $a1, $v0, 0x4
    ctx->r5 = ctx->r2 | 0X4;
        goto L_8007B9F0;
    // 0x8007B9C4: ori         $a1, $v0, 0x4
    ctx->r5 = ctx->r2 | 0X4;
L_8007B9C8:
    // 0x8007B9C8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007B9CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007B9D0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007B9D4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007B9D8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007B9DC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8007B9E0: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x8007B9E4: nop

    // 0x8007B9E8: ori         $t8, $t9, 0x2
    ctx->r24 = ctx->r25 | 0X2;
    // 0x8007B9EC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_8007B9F0:
    // 0x8007B9F0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007B9F4: lui         $t6, 0x702
    ctx->r14 = S32(0X702 << 16);
    // 0x8007B9F8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007B9FC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007BA00: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007BA04: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x8007BA08: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x8007BA0C: addu        $t8, $t9, $t1
    ctx->r24 = ADD32(ctx->r25, ctx->r9);
    // 0x8007BA10: addiu       $t7, $t7, -0x1838
    ctx->r15 = ADD32(ctx->r15, -0X1838);
    // 0x8007BA14: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007BA18: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x8007BA1C: b           L_8007BA54
    // 0x8007BA20: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_8007BA54;
    // 0x8007BA20: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8007BA24:
    // 0x8007BA24: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BA28: lui         $t8, 0x702
    ctx->r24 = S32(0X702 << 16);
    // 0x8007BA2C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007BA30: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007BA34: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007BA38: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x8007BA3C: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x8007BA40: addu        $t6, $t7, $t1
    ctx->r14 = ADD32(ctx->r15, ctx->r9);
    // 0x8007BA44: addiu       $t9, $t9, -0x1718
    ctx->r25 = ADD32(ctx->r25, -0X1718);
    // 0x8007BA48: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007BA4C: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8007BA50: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_8007BA54:
    // 0x8007BA54: jr          $ra
    // 0x8007BA58: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8007BA58: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void results_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096978: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8009697C: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80096980: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80096984: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80096988: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8009698C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80096990: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80096994: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80096998: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8009699C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800969A0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800969A4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800969A8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800969AC: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800969B0: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x800969B4: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800969B8: jal         0x8006EA90
    // 0x800969BC: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x800969BC: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    after_0:
    // 0x800969C0: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800969C4: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800969C8: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x800969CC: bne         $t6, $zero, L_800969D8
    if (ctx->r14 != 0) {
        // 0x800969D0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800969D8;
    }
    // 0x800969D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800969D4: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
L_800969D8:
    // 0x800969D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800969DC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800969E0: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x800969E4: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x800969E8: jal         0x80067F2C
    // 0x800969EC: sw          $v1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r3;
    mtx_ortho(rdram, ctx);
        goto after_1;
    // 0x800969EC: sw          $v1, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r3;
    after_1:
    // 0x800969F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800969F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800969F8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800969FC: nop

    // 0x80096A00: bc1f        L_80096A0C
    if (!c1cs) {
        // 0x80096A04: nop
    
            goto L_80096A0C;
    }
    // 0x80096A04: nop

    // 0x80096A08: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80096A0C:
    // 0x80096A0C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80096A10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80096A14: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80096A18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80096A1C: bc1f        L_80096A28
    if (!c1cs) {
        // 0x80096A20: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_80096A28;
    }
    // 0x80096A20: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80096A24: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80096A28:
    // 0x80096A28: sub.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x80096A2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80096A30: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80096A34: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80096A38: addiu       $s0, $s0, -0x89C
    ctx->r16 = ADD32(ctx->r16, -0X89C);
    // 0x80096A3C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80096A40: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80096A44: nop

    // 0x80096A48: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80096A4C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80096A50: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80096A54: nop

    // 0x80096A58: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80096A5C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80096A60: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80096A64: jal         0x800C42EC
    // 0x80096A68: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    set_text_font(rdram, ctx);
        goto after_2;
    // 0x80096A68: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    after_2:
    // 0x80096A6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80096A70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80096A74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80096A78: jal         0x800C43CC
    // 0x80096A7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_3;
    // 0x80096A7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80096A80: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80096A84: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80096A88: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80096A8C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80096A90: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80096A94: jal         0x800C4384
    // 0x80096A98: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x80096A98: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_4:
    // 0x80096A9C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80096AA0: lw          $t0, -0xB60($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XB60);
    // 0x80096AA4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80096AA8: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80096AAC: lw          $a3, 0x84($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X84);
    // 0x80096AB0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80096AB4: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80096AB8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80096ABC: jal         0x800C4440
    // 0x80096AC0: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x80096AC0: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    after_5:
    // 0x80096AC4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80096AC8: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80096ACC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80096AD0: lw          $v0, -0xB44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB44);
    // 0x80096AD4: addiu       $t5, $zero, 0xA0
    ctx->r13 = ADD32(0, 0XA0);
    // 0x80096AD8: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80096ADC: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80096AE0: subu        $s5, $t5, $t4
    ctx->r21 = SUB32(ctx->r13, ctx->r12);
    // 0x80096AE4: sw          $s5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r21;
    // 0x80096AE8: blez        $v0, L_80096BD4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80096AEC: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_80096BD4;
    }
    // 0x80096AEC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80096AF0: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80096AF4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80096AF8: addiu       $t9, $zero, 0x36
    ctx->r25 = ADD32(0, 0X36);
    // 0x80096AFC: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80096B00: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80096B04: lw          $s0, 0x84($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X84);
    // 0x80096B08: addiu       $s2, $s2, 0xAF0
    ctx->r18 = ADD32(ctx->r18, 0XAF0);
    // 0x80096B0C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80096B10: addiu       $s3, $zero, 0x17F
    ctx->r19 = ADD32(0, 0X17F);
    // 0x80096B14: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80096B18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80096B1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80096B20: nop

    // 0x80096B24: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80096B28: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80096B2C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80096B30: subu        $s1, $t9, $t8
    ctx->r17 = SUB32(ctx->r25, ctx->r24);
    // 0x80096B34: nop

L_80096B38:
    // 0x80096B38: lb          $t0, 0x5A($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X5A);
    // 0x80096B3C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80096B40: bne         $t0, $zero, L_80096B7C
    if (ctx->r8 != 0) {
        // 0x80096B44: addiu       $a0, $a0, 0x63A0
        ctx->r4 = ADD32(ctx->r4, 0X63A0);
            goto L_80096B7C;
    }
    // 0x80096B44: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80096B48: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80096B4C: lw          $v0, 0x63BC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63BC);
    // 0x80096B50: nop

    // 0x80096B54: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80096B58: beq         $at, $zero, L_80096B70
    if (ctx->r1 == 0) {
        // 0x80096B5C: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_80096B70;
    }
    // 0x80096B5C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80096B60: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80096B64: addiu       $t2, $t1, 0x80
    ctx->r10 = ADD32(ctx->r9, 0X80);
    // 0x80096B68: b           L_80096B84
    // 0x80096B6C: sw          $t2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r10;
        goto L_80096B84;
    // 0x80096B6C: sw          $t2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r10;
L_80096B70:
    // 0x80096B70: subu        $t5, $s3, $t3
    ctx->r13 = SUB32(ctx->r19, ctx->r11);
    // 0x80096B74: b           L_80096B84
    // 0x80096B78: sw          $t5, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r13;
        goto L_80096B84;
    // 0x80096B78: sw          $t5, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r13;
L_80096B7C:
    // 0x80096B7C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80096B80: sw          $t4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r12;
L_80096B84:
    // 0x80096B84: lb          $t6, 0x59($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X59);
    // 0x80096B88: lbu         $v0, 0xA3($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XA3);
    // 0x80096B8C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80096B90: addu        $t9, $s2, $t7
    ctx->r25 = ADD32(ctx->r18, ctx->r15);
    { extern uint32_t dkr_legacy_character_portrait_lookup(uint8_t*, recomp_context*, uint32_t); uint32_t cell = dkr_legacy_character_portrait_lookup(rdram, ctx, (uint32_t)ctx->r16); if (cell) ctx->r25 = (int32_t)cell; }
    // 0x80096B94: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80096B98: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80096B9C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80096BA0: addiu       $a2, $s5, -0x14
    ctx->r6 = ADD32(ctx->r21, -0X14);
    // 0x80096BA4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80096BA8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80096BAC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80096BB0: jal         0x80078AB8
    // 0x80096BB4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    texrect_draw(rdram, ctx);
        goto after_6;
    // 0x80096BB4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_6:
    // 0x80096BB8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80096BBC: lw          $t0, -0xB44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XB44);
    // 0x80096BC0: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80096BC4: slt         $at, $s6, $t0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80096BC8: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80096BCC: bne         $at, $zero, L_80096B38
    if (ctx->r1 != 0) {
        // 0x80096BD0: addiu       $s5, $s5, 0x40
        ctx->r21 = ADD32(ctx->r21, 0X40);
            goto L_80096B38;
    }
    // 0x80096BD0: addiu       $s5, $s5, 0x40
    ctx->r21 = ADD32(ctx->r21, 0X40);
L_80096BD4:
    // 0x80096BD4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80096BD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80096BDC: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x80096BE0: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80096BE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80096BE8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80096BEC: nop

    // 0x80096BF0: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80096BF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80096BF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80096BFC: nop

    // 0x80096C00: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80096C04: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x80096C08: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80096C0C: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x80096C10: jal         0x800C42EC
    // 0x80096C14: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
    set_text_font(rdram, ctx);
        goto after_7;
    // 0x80096C14: sw          $t5, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r13;
    after_7:
    // 0x80096C18: lw          $v1, 0x98($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X98);
    // 0x80096C1C: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x80096C20: addiu       $v1, $v1, 0x68
    ctx->r3 = ADD32(ctx->r3, 0X68);
    // 0x80096C24: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80096C28: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80096C2C: addiu       $t4, $zero, 0x68
    ctx->r12 = ADD32(0, 0X68);
    // 0x80096C30: addiu       $t7, $t7, 0xBCC
    ctx->r15 = ADD32(ctx->r15, 0XBCC);
    // 0x80096C34: addiu       $t6, $v1, 0x4
    ctx->r14 = ADD32(ctx->r3, 0X4);
    // 0x80096C38: addiu       $t9, $v1, 0x2
    ctx->r25 = ADD32(ctx->r3, 0X2);
    // 0x80096C3C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80096C40: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80096C44: addiu       $t0, $v0, -0x22
    ctx->r8 = ADD32(ctx->r2, -0X22);
    // 0x80096C48: addiu       $t1, $v0, -0x20
    ctx->r9 = ADD32(ctx->r2, -0X20);
    // 0x80096C4C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80096C50: sw          $t4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r12;
    // 0x80096C54: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80096C58: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x80096C5C: addiu       $s3, $s3, -0x8A4
    ctx->r19 = ADD32(ctx->r19, -0X8A4);
    // 0x80096C60: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x80096C64: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x80096C68: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x80096C6C: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x80096C70: sw          $zero, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = 0;
    // 0x80096C74: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x80096C78: addiu       $s7, $zero, 0x64
    ctx->r23 = ADD32(0, 0X64);
L_80096C7C:
    // 0x80096C7C: lw          $s5, 0xA4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XA4);
    // 0x80096C80: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80096C84: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80096C88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80096C8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80096C90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80096C94: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80096C98: jal         0x800C4384
    // 0x80096C9C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_8;
    // 0x80096C9C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    after_8:
    // 0x80096CA0: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80096CA4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80096CA8: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80096CAC: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80096CB0: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80096CB4: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x80096CB8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80096CBC: jal         0x800C4440
    // 0x80096CC0: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    draw_text(rdram, ctx);
        goto after_9;
    // 0x80096CC0: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    after_9:
    // 0x80096CC4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80096CC8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80096CCC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80096CD0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80096CD4: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x80096CD8: jal         0x800C4384
    // 0x80096CDC: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    set_text_colour(rdram, ctx);
        goto after_10;
    // 0x80096CDC: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    after_10:
    // 0x80096CE0: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80096CE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80096CE8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80096CEC: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x80096CF0: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80096CF4: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    // 0x80096CF8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80096CFC: jal         0x800C4440
    // 0x80096D00: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    draw_text(rdram, ctx);
        goto after_11;
    // 0x80096D00: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    after_11:
    // 0x80096D04: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80096D08: jal         0x8007B3D0
    // 0x80096D0C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    rendermode_reset(rdram, ctx);
        goto after_12;
    // 0x80096D0C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    after_12:
    // 0x80096D10: jal         0x80068508
    // 0x80096D14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_13;
    // 0x80096D14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x80096D18: jal         0x8007BF1C
    // 0x80096D1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_14;
    // 0x80096D1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x80096D20: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80096D24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096D28: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80096D2C: sb          $v0, -0xB5C($at)
    MEM_B(-0XB5C, ctx->r1) = ctx->r2;
    // 0x80096D30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096D34: sb          $t9, -0xB58($at)
    MEM_B(-0XB58, ctx->r1) = ctx->r25;
    // 0x80096D38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096D3C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80096D40: lw          $t8, -0xB44($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB44);
    // 0x80096D44: sb          $v0, -0xB54($at)
    MEM_B(-0XB54, ctx->r1) = ctx->r2;
    // 0x80096D48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096D4C: blez        $t8, L_80096F08
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80096D50: sb          $v0, -0xB50($at)
        MEM_B(-0XB50, ctx->r1) = ctx->r2;
            goto L_80096F08;
    }
    // 0x80096D50: sb          $v0, -0xB50($at)
    MEM_B(-0XB50, ctx->r1) = ctx->r2;
    // 0x80096D54: lw          $t3, 0xA8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA8);
    // 0x80096D58: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x80096D5C: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x80096D60: subu        $t4, $t5, $t3
    ctx->r12 = SUB32(ctx->r13, ctx->r11);
    // 0x80096D64: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80096D68: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x80096D6C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80096D70: cvt.s.w     $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    ctx->f22.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80096D74: addu        $s4, $t0, $t2
    ctx->r20 = ADD32(ctx->r8, ctx->r10);
L_80096D78:
    // 0x80096D78: lhu         $s1, 0x5C($s4)
    ctx->r17 = MEM_HU(ctx->r20, 0X5C);
    // 0x80096D7C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80096D80: slti        $at, $s1, 0x3E8
    ctx->r1 = SIGNED(ctx->r17) < 0X3E8 ? 1 : 0;
    // 0x80096D84: bne         $at, $zero, L_80096D90
    if (ctx->r1 != 0) {
        // 0x80096D88: addiu       $t8, $s5, -0xAC
        ctx->r24 = ADD32(ctx->r21, -0XAC);
            goto L_80096D90;
    }
    // 0x80096D88: addiu       $t8, $s5, -0xAC
    ctx->r24 = ADD32(ctx->r21, -0XAC);
    // 0x80096D8C: addiu       $s1, $zero, 0x3E7
    ctx->r17 = ADD32(0, 0X3E7);
L_80096D90:
    // 0x80096D90: div         $zero, $s1, $s7
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r23)));
    // 0x80096D94: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80096D98: bne         $s7, $zero, L_80096DA4
    if (ctx->r23 != 0) {
        // 0x80096D9C: nop
    
            goto L_80096DA4;
    }
    // 0x80096D9C: nop

    // 0x80096DA0: break       7
    do_break(2148101536);
L_80096DA4:
    // 0x80096DA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80096DA8: bne         $s7, $at, L_80096DBC
    if (ctx->r23 != ctx->r1) {
        // 0x80096DAC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80096DBC;
    }
    // 0x80096DAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80096DB0: bne         $s1, $at, L_80096DBC
    if (ctx->r17 != ctx->r1) {
        // 0x80096DB4: nop
    
            goto L_80096DBC;
    }
    // 0x80096DB4: nop

    // 0x80096DB8: break       6
    do_break(2148101560);
L_80096DBC:
    // 0x80096DBC: swc1        $f22, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f22.u32l;
    // 0x80096DC0: mflo        $v0
    ctx->r2 = lo;
    // 0x80096DC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80096DC8: nop

    // 0x80096DCC: multu       $v0, $s7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096DD0: mflo        $t6
    ctx->r14 = lo;
    // 0x80096DD4: subu        $s1, $s1, $t6
    ctx->r17 = SUB32(ctx->r17, ctx->r14);
    // 0x80096DD8: nop

    // 0x80096DDC: div         $zero, $s1, $fp
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r30))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r30)));
    // 0x80096DE0: bne         $fp, $zero, L_80096DEC
    if (ctx->r30 != 0) {
        // 0x80096DE4: nop
    
            goto L_80096DEC;
    }
    // 0x80096DE4: nop

    // 0x80096DE8: break       7
    do_break(2148101608);
L_80096DEC:
    // 0x80096DEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80096DF0: bne         $fp, $at, L_80096E04
    if (ctx->r30 != ctx->r1) {
        // 0x80096DF4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80096E04;
    }
    // 0x80096DF4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80096DF8: bne         $s1, $at, L_80096E04
    if (ctx->r17 != ctx->r1) {
        // 0x80096DFC: nop
    
            goto L_80096E04;
    }
    // 0x80096DFC: nop

    // 0x80096E00: break       6
    do_break(2148101632);
L_80096E04:
    // 0x80096E04: mflo        $v1
    ctx->r3 = lo;
    // 0x80096E08: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x80096E0C: nop

    // 0x80096E10: multu       $v1, $fp
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80096E14: mflo        $t7
    ctx->r15 = lo;
    // 0x80096E18: subu        $s1, $s1, $t7
    ctx->r17 = SUB32(ctx->r17, ctx->r15);
    // 0x80096E1C: blez        $a1, L_80096E84
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80096E20: nop
    
            goto L_80096E84;
    }
    // 0x80096E20: nop

    // 0x80096E24: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80096E28: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x80096E2C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80096E30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80096E34: swc1        $f6, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f6.u32l;
    // 0x80096E38: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80096E3C: jal         0x8009CA60
    // 0x80096E40: sh          $a1, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r5;
    menu_element_render(rdram, ctx);
        goto after_15;
    // 0x80096E40: sh          $a1, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r5;
    after_15:
    // 0x80096E44: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80096E48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80096E4C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80096E50: nop

    // 0x80096E54: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x80096E58: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80096E5C: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80096E60: jal         0x8009CA60
    // 0x80096E64: sh          $s2, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r18;
    menu_element_render(rdram, ctx);
        goto after_16;
    // 0x80096E64: sh          $s2, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r18;
    after_16:
    // 0x80096E68: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80096E6C: nop

    // 0x80096E70: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80096E74: nop

    // 0x80096E78: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80096E7C: b           L_80096EDC
    // 0x80096E80: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_80096EDC;
    // 0x80096E80: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_80096E84:
    // 0x80096E84: blez        $s2, L_80096ECC
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80096E88: addiu       $t6, $s5, -0xA0
        ctx->r14 = ADD32(ctx->r21, -0XA0);
            goto L_80096ECC;
    }
    // 0x80096E88: addiu       $t6, $s5, -0xA0
    ctx->r14 = ADD32(ctx->r21, -0XA0);
    // 0x80096E8C: addiu       $t5, $s5, -0xA6
    ctx->r13 = ADD32(ctx->r21, -0XA6);
    // 0x80096E90: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80096E94: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x80096E98: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80096E9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80096EA0: swc1        $f6, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f6.u32l;
    // 0x80096EA4: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x80096EA8: jal         0x8009CA60
    // 0x80096EAC: sh          $s2, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r18;
    menu_element_render(rdram, ctx);
        goto after_17;
    // 0x80096EAC: sh          $s2, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r18;
    after_17:
    // 0x80096EB0: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80096EB4: nop

    // 0x80096EB8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80096EBC: nop

    // 0x80096EC0: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x80096EC4: b           L_80096EDC
    // 0x80096EC8: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_80096EDC;
    // 0x80096EC8: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_80096ECC:
    // 0x80096ECC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80096ED0: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80096ED4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80096ED8: swc1        $f18, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f18.u32l;
L_80096EDC:
    // 0x80096EDC: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80096EE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80096EE4: jal         0x8009CA60
    // 0x80096EE8: sh          $s1, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r17;
    menu_element_render(rdram, ctx);
        goto after_18;
    // 0x80096EE8: sh          $s1, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r17;
    after_18:
    // 0x80096EEC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80096EF0: lw          $t8, -0xB44($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB44);
    // 0x80096EF4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80096EF8: slt         $at, $s6, $t8
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80096EFC: addiu       $s4, $s4, 0x18
    ctx->r20 = ADD32(ctx->r20, 0X18);
    // 0x80096F00: bne         $at, $zero, L_80096D78
    if (ctx->r1 != 0) {
        // 0x80096F04: addiu       $s5, $s5, 0x40
        ctx->r21 = ADD32(ctx->r21, 0X40);
            goto L_80096D78;
    }
    // 0x80096F04: addiu       $s5, $s5, 0x40
    ctx->r21 = ADD32(ctx->r21, 0X40);
L_80096F08:
    // 0x80096F08: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x80096F0C: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x80096F10: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x80096F14: addiu       $t0, $t1, 0x11
    ctx->r8 = ADD32(ctx->r9, 0X11);
    // 0x80096F18: addiu       $t5, $t2, 0x11
    ctx->r13 = ADD32(ctx->r10, 0X11);
    // 0x80096F1C: addiu       $t4, $t3, 0x11
    ctx->r12 = ADD32(ctx->r11, 0X11);
    // 0x80096F20: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
    // 0x80096F24: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x80096F28: sw          $t0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r8;
    // 0x80096F2C: jal         0x80068508
    // 0x80096F30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_19;
    // 0x80096F30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
    // 0x80096F34: jal         0x8007BF1C
    // 0x80096F38: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_20;
    // 0x80096F38: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_20:
    // 0x80096F3C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80096F40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096F44: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x80096F48: sb          $t6, -0xB58($at)
    MEM_B(-0XB58, ctx->r1) = ctx->r14;
    // 0x80096F4C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80096F50: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80096F54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096F58: sb          $zero, -0xB50($at)
    MEM_B(-0XB50, ctx->r1) = 0;
    // 0x80096F5C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80096F60: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80096F64: addiu       $t1, $t8, 0x4
    ctx->r9 = ADD32(ctx->r24, 0X4);
    // 0x80096F68: addiu       $t2, $t0, -0x40
    ctx->r10 = ADD32(ctx->r8, -0X40);
    // 0x80096F6C: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x80096F70: sw          $t1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r9;
    // 0x80096F74: bne         $at, $zero, L_80096C7C
    if (ctx->r1 != 0) {
        // 0x80096F78: sw          $t9, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->r25;
            goto L_80096C7C;
    }
    // 0x80096F78: sw          $t9, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r25;
    // 0x80096F7C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80096F80: lw          $t5, 0x63E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X63E0);
    // 0x80096F84: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80096F88: blez        $t5, L_80097268
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80096F8C: addiu       $s1, $s1, 0x6C14
        ctx->r17 = ADD32(ctx->r17, 0X6C14);
            goto L_80097268;
    }
    // 0x80096F8C: addiu       $s1, $s1, 0x6C14
    ctx->r17 = ADD32(ctx->r17, 0X6C14);
    // 0x80096F90: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80096F94: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80096F98: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80096F9C: jal         0x800C56D0
    // 0x80096FA0: sw          $t4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r12;
    clear_dialogue_box_open_flag(rdram, ctx);
        goto after_21;
    // 0x80096FA0: sw          $t4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r12;
    after_21:
    // 0x80096FA4: jal         0x800C5494
    // 0x80096FA8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_22;
    // 0x80096FA8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_22:
    // 0x80096FAC: lw          $v0, 0x98($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X98);
    // 0x80096FB0: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80096FB4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80096FB8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80096FBC: addiu       $t8, $t7, 0xCC
    ctx->r24 = ADD32(ctx->r15, 0XCC);
    // 0x80096FC0: subu        $a2, $v0, $t6
    ctx->r6 = SUB32(ctx->r2, ctx->r14);
    // 0x80096FC4: addiu       $a2, $a2, 0xC4
    ctx->r6 = ADD32(ctx->r6, 0XC4);
    // 0x80096FC8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80096FCC: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80096FD0: jal         0x800C4EDC
    // 0x80096FD4: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_23;
    // 0x80096FD4: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    after_23:
    // 0x80096FD8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80096FDC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x80096FE0: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80096FE4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80096FE8: jal         0x800C4FBC
    // 0x80096FEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_24;
    // 0x80096FEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_24:
    // 0x80096FF0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80096FF4: jal         0x800C4F7C
    // 0x80096FF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_25;
    // 0x80096FF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x80096FFC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80097000: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80097004: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80097008: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8009700C: jal         0x800C5050
    // 0x80097010: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_26;
    // 0x80097010: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_26:
    // 0x80097014: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80097018: lw          $v0, 0x63BC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63BC);
    // 0x8009701C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80097020: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x80097024: slti        $at, $t1, 0x100
    ctx->r1 = SIGNED(ctx->r9) < 0X100 ? 1 : 0;
    // 0x80097028: bne         $at, $zero, L_80097038
    if (ctx->r1 != 0) {
        // 0x8009702C: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80097038;
    }
    // 0x8009702C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80097030: addiu       $t0, $zero, 0x1FF
    ctx->r8 = ADD32(0, 0X1FF);
    // 0x80097034: subu        $v0, $t0, $t1
    ctx->r2 = SUB32(ctx->r8, ctx->r9);
L_80097038:
    // 0x80097038: addiu       $s0, $s0, 0x988
    ctx->r16 = ADD32(ctx->r16, 0X988);
    // 0x8009703C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80097040: lw          $t9, 0xA8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA8);
    // 0x80097044: beq         $t2, $zero, L_8009719C
    if (ctx->r10 == 0) {
        // 0x80097048: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_8009719C;
    }
    // 0x80097048: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8009704C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80097050: lw          $t3, -0xB60($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XB60);
    // 0x80097054: addiu       $t5, $t9, -0x18
    ctx->r13 = ADD32(ctx->r25, -0X18);
    // 0x80097058: sw          $t5, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r13;
    // 0x8009705C: lw          $a3, 0x210($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X210);
    // 0x80097060: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80097064: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80097068: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8009706C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80097070: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // 0x80097074: addiu       $a2, $t5, 0x8
    ctx->r6 = ADD32(ctx->r13, 0X8);
    // 0x80097078: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009707C: jal         0x800C5168
    // 0x80097080: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    render_dialogue_text(rdram, ctx);
        goto after_27;
    // 0x80097080: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    after_27:
    // 0x80097084: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80097088: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009708C: bne         $t7, $at, L_800970C0
    if (ctx->r15 != ctx->r1) {
        // 0x80097090: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_800970C0;
    }
    // 0x80097090: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80097094: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x80097098: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009709C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800970A0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800970A4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800970A8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800970AC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800970B0: jal         0x800C5000
    // 0x800970B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    set_current_text_colour(rdram, ctx);
        goto after_28;
    // 0x800970B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_28:
    // 0x800970B8: b           L_800970DC
    // 0x800970BC: nop

        goto L_800970DC;
    // 0x800970BC: nop

L_800970C0:
    // 0x800970C0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800970C4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800970C8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800970CC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800970D0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800970D4: jal         0x800C5000
    // 0x800970D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_29;
    // 0x800970D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_29:
L_800970DC:
    // 0x800970DC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800970E0: lw          $t2, -0xB60($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB60);
    // 0x800970E4: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x800970E8: lw          $a3, 0x218($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X218);
    // 0x800970EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800970F0: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x800970F4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800970F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800970FC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80097100: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80097104: jal         0x800C5168
    // 0x80097108: addiu       $a2, $a2, 0x1A
    ctx->r6 = ADD32(ctx->r6, 0X1A);
    render_dialogue_text(rdram, ctx);
        goto after_30;
    // 0x80097108: addiu       $a2, $a2, 0x1A
    ctx->r6 = ADD32(ctx->r6, 0X1A);
    after_30:
    // 0x8009710C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80097110: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80097114: bne         $t3, $at, L_80097148
    if (ctx->r11 != ctx->r1) {
        // 0x80097118: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80097148;
    }
    // 0x80097118: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009711C: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    // 0x80097120: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80097124: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80097128: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009712C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80097130: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80097134: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80097138: jal         0x800C5000
    // 0x8009713C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    set_current_text_colour(rdram, ctx);
        goto after_31;
    // 0x8009713C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_31:
    // 0x80097140: b           L_80097164
    // 0x80097144: nop

        goto L_80097164;
    // 0x80097144: nop

L_80097148:
    // 0x80097148: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009714C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80097150: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80097154: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80097158: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009715C: jal         0x800C5000
    // 0x80097160: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_32;
    // 0x80097160: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_32:
L_80097164:
    // 0x80097164: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80097168: lw          $t8, -0xB60($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB60);
    // 0x8009716C: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x80097170: lw          $a3, 0x154($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X154);
    // 0x80097174: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80097178: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x8009717C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80097180: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80097184: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80097188: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009718C: jal         0x800C5168
    // 0x80097190: addiu       $a2, $a2, 0x2A
    ctx->r6 = ADD32(ctx->r6, 0X2A);
    render_dialogue_text(rdram, ctx);
        goto after_33;
    // 0x80097190: addiu       $a2, $a2, 0x2A
    ctx->r6 = ADD32(ctx->r6, 0X2A);
    after_33:
    // 0x80097194: b           L_80097260
    // 0x80097198: nop

        goto L_80097260;
    // 0x80097198: nop

L_8009719C:
    // 0x8009719C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800971A0: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x800971A4: blez        $t9, L_80097260
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800971A8: sw          $t2, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->r10;
            goto L_80097260;
    }
    // 0x800971A8: sw          $t2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r10;
    // 0x800971AC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800971B0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800971B4: addiu       $s2, $s2, 0x6A68
    ctx->r18 = ADD32(ctx->r18, 0X6A68);
    // 0x800971B8: addiu       $s0, $s0, 0x6BF0
    ctx->r16 = ADD32(ctx->r16, 0X6BF0);
    // 0x800971BC: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
L_800971C0:
    // 0x800971C0: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800971C4: lw          $v0, 0xA0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA0);
    // 0x800971C8: bne         $s6, $t5, L_800971FC
    if (ctx->r22 != ctx->r13) {
        // 0x800971CC: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_800971FC;
    }
    // 0x800971CC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800971D0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800971D4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800971D8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800971DC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800971E0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800971E4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800971E8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800971EC: jal         0x800C5000
    // 0x800971F0: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    set_current_text_colour(rdram, ctx);
        goto after_34;
    // 0x800971F0: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    after_34:
    // 0x800971F4: b           L_80097220
    // 0x800971F8: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
        goto L_80097220;
    // 0x800971F8: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
L_800971FC:
    // 0x800971FC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80097200: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80097204: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80097208: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009720C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80097210: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80097214: jal         0x800C5000
    // 0x80097218: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    set_current_text_colour(rdram, ctx);
        goto after_35;
    // 0x80097218: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    after_35:
    // 0x8009721C: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
L_80097220:
    // 0x80097220: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80097224: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80097228: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8009722C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80097230: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80097234: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80097238: jal         0x800C5168
    // 0x8009723C: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    render_dialogue_text(rdram, ctx);
        goto after_36;
    // 0x8009723C: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_36:
    // 0x80097240: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80097244: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80097248: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8009724C: slt         $at, $s6, $t0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80097250: addiu       $t1, $t8, 0x10
    ctx->r9 = ADD32(ctx->r24, 0X10);
    // 0x80097254: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80097258: bne         $at, $zero, L_800971C0
    if (ctx->r1 != 0) {
        // 0x8009725C: sw          $t1, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->r9;
            goto L_800971C0;
    }
    // 0x8009725C: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
L_80097260:
    // 0x80097260: jal         0x800C55F4
    // 0x80097264: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    open_dialogue_box(rdram, ctx);
        goto after_37;
    // 0x80097264: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_37:
L_80097268:
    // 0x80097268: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8009726C: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80097270: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80097274: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80097278: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8009727C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80097280: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80097284: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80097288: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8009728C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80097290: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80097294: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80097298: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8009729C: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800972A0: jr          $ra
    // 0x800972A4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800972A4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_80021104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021104: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80021108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002110C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80021110: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x80021114: lw          $v1, 0x1C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1C);
    // 0x80021118: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x8002111C: bne         $t6, $at, L_80021144
    if (ctx->r14 != ctx->r1) {
        // 0x80021120: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80021144;
    }
    // 0x80021120: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80021124: addiu       $v0, $v0, -0x52C2
    ctx->r2 = ADD32(ctx->r2, -0X52C2);
    // 0x80021128: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x8002112C: nop

    // 0x80021130: sb          $t7, 0x44($a1)
    MEM_B(0X44, ctx->r5) = ctx->r15;
    // 0x80021134: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x80021138: nop

    // 0x8002113C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80021140: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
L_80021144:
    // 0x80021144: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80021148: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8002114C: lb          $a0, 0x22($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X22);
    // 0x80021150: nop

    // 0x80021154: bne         $a0, $at, L_800211D8
    if (ctx->r4 != ctx->r1) {
        // 0x80021158: slti        $at, $a0, 0xA
        ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
            goto L_800211D8;
    }
    // 0x80021158: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x8002115C: lb          $a0, 0x30($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X30);
    // 0x80021160: jal         0x800665E8
    // 0x80021164: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    set_active_camera(rdram, ctx);
        goto after_0;
    // 0x80021164: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x80021168: jal         0x80069CFC
    // 0x8002116C: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_1;
    // 0x8002116C: nop

    after_1:
    // 0x80021170: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80021174: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80021178: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x8002117C: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
    // 0x80021180: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80021184: nop

    // 0x80021188: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
    // 0x8002118C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80021190: nop

    // 0x80021194: swc1        $f8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f8.u32l;
    // 0x80021198: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x8002119C: nop

    // 0x800211A0: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x800211A4: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x800211A8: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x800211AC: nop

    // 0x800211B0: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800211B4: sh          $t5, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r13;
    // 0x800211B8: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800211BC: nop

    // 0x800211C0: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x800211C4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800211C8: nop

    // 0x800211CC: lb          $a0, 0x22($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X22);
    // 0x800211D0: nop

    // 0x800211D4: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
L_800211D8:
    // 0x800211D8: bne         $at, $zero, L_8002124C
    if (ctx->r1 != 0) {
        // 0x800211DC: slti        $at, $a0, 0x12
        ctx->r1 = SIGNED(ctx->r4) < 0X12 ? 1 : 0;
            goto L_8002124C;
    }
    // 0x800211DC: slti        $at, $a0, 0x12
    ctx->r1 = SIGNED(ctx->r4) < 0X12 ? 1 : 0;
    // 0x800211E0: beq         $at, $zero, L_8002124C
    if (ctx->r1 == 0) {
        // 0x800211E4: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8002124C;
    }
    // 0x800211E4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800211E8: lw          $t8, -0x511C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X511C);
    // 0x800211EC: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800211F0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800211F4: lw          $v0, -0x28($t0)
    ctx->r2 = MEM_W(ctx->r8, -0X28);
    // 0x800211F8: nop

    // 0x800211FC: beq         $v0, $zero, L_80021250
    if (ctx->r2 == 0) {
        // 0x80021200: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80021250;
    }
    // 0x80021200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80021204: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80021208: nop

    // 0x8002120C: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x80021210: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80021214: nop

    // 0x80021218: swc1        $f16, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
    // 0x8002121C: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80021220: nop

    // 0x80021224: swc1        $f18, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f18.u32l;
    // 0x80021228: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x8002122C: nop

    // 0x80021230: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x80021234: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x80021238: nop

    // 0x8002123C: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x80021240: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x80021244: nop

    // 0x80021248: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
L_8002124C:
    // 0x8002124C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80021250:
    // 0x80021250: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80021254: jr          $ra
    // 0x80021258: nop

    return;
    // 0x80021258: nop

;}
