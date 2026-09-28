#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void obj_init_racer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DAB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004DAB4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004DAB8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004DABC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DAC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004DAC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004DAC8: sw          $zero, -0x2AC4($at)
    MEM_W(-0X2AC4, ctx->r1) = 0;
    // 0x8004DACC: lh          $t6, 0xC($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XC);
    // 0x8004DAD0: lw          $s0, 0x64($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X64);
    // 0x8004DAD4: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x8004DAD8: lh          $t7, 0xA($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XA);
    // 0x8004DADC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8004DAE0: sh          $t7, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r15;
    // 0x8004DAE4: lh          $t8, 0x8($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X8);
    // 0x8004DAE8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8004DAEC: sh          $t8, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r24;
    // 0x8004DAF0: lh          $a2, 0xE($a1)
    ctx->r6 = MEM_H(ctx->r5, 0XE);
    // 0x8004DAF4: sb          $zero, 0x194($s0)
    MEM_B(0X194, ctx->r16) = 0;
    // 0x8004DAF8: swc1        $f2, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f2.u32l;
    // 0x8004DAFC: bltz        $a2, L_8004DB40
    if (SIGNED(ctx->r6) < 0) {
        // 0x8004DB00: swc1        $f2, 0x90($s0)
        MEM_W(0X90, ctx->r16) = ctx->f2.u32l;
            goto L_8004DB40;
    }
    // 0x8004DB00: swc1        $f2, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f2.u32l;
    // 0x8004DB04: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x8004DB08: beq         $at, $zero, L_8004DB40
    if (ctx->r1 == 0) {
        // 0x8004DB0C: nop
    
            goto L_8004DB40;
    }
    // 0x8004DB0C: nop

    // 0x8004DB10: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004DB14: jal         0x8000E158
    // 0x8004DB18: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    is_race_started_by_player_two(rdram, ctx);
        goto after_0;
    // 0x8004DB18: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004DB1C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8004DB20: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8004DB24: beq         $v0, $zero, L_8004DB34
    if (ctx->r2 == 0) {
        // 0x8004DB28: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8004DB34;
    }
    // 0x8004DB28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004DB2C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004DB30: subu        $a2, $t9, $a2
    ctx->r6 = SUB32(ctx->r25, ctx->r6);
L_8004DB34:
    // 0x8004DB34: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004DB38: b           L_8004DB44
    // 0x8004DB3C: sh          $a2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r6;
        goto L_8004DB44;
    // 0x8004DB3C: sh          $a2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r6;
L_8004DB40:
    // 0x8004DB40: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
L_8004DB44:
    // 0x8004DB44: lh          $t2, 0x0($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X0);
    // 0x8004DB48: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8004DB4C: sh          $t2, 0x1A0($s0)
    MEM_H(0X1A0, ctx->r16) = ctx->r10;
    // 0x8004DB50: lh          $t3, 0x4($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X4);
    // 0x8004DB54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004DB58: lh          $t4, 0x1A0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X1A0);
    // 0x8004DB5C: sh          $t3, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r11;
    // 0x8004DB60: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x8004DB64: sh          $t4, 0x196($s0)
    MEM_H(0X196, ctx->r16) = ctx->r12;
    // 0x8004DB68: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8004DB6C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8004DB70: swc1        $f6, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f6.u32l;
    // 0x8004DB74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004DB78: lwc1        $f8, 0x10($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8004DB7C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8004DB80: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8004DB84: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004DB88: swc1        $f10, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f10.u32l;
    // 0x8004DB8C: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8004DB90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8004DB94: swc1        $f16, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f16.u32l;
    // 0x8004DB98: lwc1        $f18, 0xC($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8004DB9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004DBA0: swc1        $f18, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f18.u32l;
    // 0x8004DBA4: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8004DBA8: nop

    // 0x8004DBAC: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8004DBB0: swc1        $f6, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f6.u32l;
    // 0x8004DBB4: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8004DBB8: nop

    // 0x8004DBBC: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    // 0x8004DBC0: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8004DBC4: nop

    // 0x8004DBC8: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
    // 0x8004DBCC: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8004DBD0: nop

    // 0x8004DBD4: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8004DBD8: swc1        $f18, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f18.u32l;
    // 0x8004DBDC: lwc1        $f4, 0x14($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8004DBE0: nop

    // 0x8004DBE4: swc1        $f4, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f4.u32l;
    // 0x8004DBE8: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8004DBEC: nop

    // 0x8004DBF0: swc1        $f6, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f6.u32l;
    // 0x8004DBF4: lwc1        $f8, 0x10($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8004DBF8: nop

    // 0x8004DBFC: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8004DC00: swc1        $f10, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->f10.u32l;
    // 0x8004DC04: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8004DC08: nop

    // 0x8004DC0C: swc1        $f16, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f16.u32l;
    // 0x8004DC10: lwc1        $f18, 0xC($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8004DC14: nop

    // 0x8004DC18: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
    // 0x8004DC1C: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8004DC20: nop

    // 0x8004DC24: swc1        $f4, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f4.u32l;
    // 0x8004DC28: lwc1        $f6, 0x14($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8004DC2C: nop

    // 0x8004DC30: swc1        $f6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
    // 0x8004DC34: lw          $t5, 0x4C($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X4C);
    // 0x8004DC38: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8004DC3C: nop

    // 0x8004DC40: swc1        $f8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f8.u32l;
    // 0x8004DC44: lw          $t6, 0x4C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X4C);
    // 0x8004DC48: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x8004DC4C: nop

    // 0x8004DC50: swc1        $f10, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f10.u32l;
    // 0x8004DC54: lw          $t7, 0x4C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4C);
    // 0x8004DC58: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8004DC5C: nop

    // 0x8004DC60: swc1        $f16, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f16.u32l;
    // 0x8004DC64: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x8004DC68: sb          $t8, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = ctx->r24;
    // 0x8004DC6C: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x8004DC70: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x8004DC74: sh          $t9, 0x1AA($s0)
    MEM_H(0X1AA, ctx->r16) = ctx->r25;
    // 0x8004DC78: sh          $t1, 0x1AE($s0)
    MEM_H(0X1AE, ctx->r16) = ctx->r9;
    // 0x8004DC7C: sb          $t2, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r10;
    // 0x8004DC80: swc1        $f2, 0xA8($s0)
    MEM_W(0XA8, ctx->r16) = ctx->f2.u32l;
    // 0x8004DC84: sb          $zero, 0x1FD($s0)
    MEM_B(0X1FD, ctx->r16) = 0;
    // 0x8004DC88: sw          $zero, 0x178($s0)
    MEM_W(0X178, ctx->r16) = 0;
    // 0x8004DC8C: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
    // 0x8004DC90: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x8004DC94: sw          $zero, 0x218($s0)
    MEM_W(0X218, ctx->r16) = 0;
    // 0x8004DC98: sw          $zero, 0x220($s0)
    MEM_W(0X220, ctx->r16) = 0;
    // 0x8004DC9C: beq         $v0, $at, L_8004DD4C
    if (ctx->r2 == ctx->r1) {
        // 0x8004DCA0: sw          $zero, 0x21C($s0)
        MEM_W(0X21C, ctx->r16) = 0;
            goto L_8004DD4C;
    }
    // 0x8004DCA0: sw          $zero, 0x21C($s0)
    MEM_W(0X21C, ctx->r16) = 0;
    // 0x8004DCA4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004DCA8: addiu       $v0, $v0, -0x2A7E
    ctx->r2 = ADD32(ctx->r2, -0X2A7E);
    // 0x8004DCAC: lb          $t3, 0x0($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X0);
    // 0x8004DCB0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8004DCB4: bne         $t3, $zero, L_8004DD4C
    if (ctx->r11 != 0) {
        // 0x8004DCB8: nop
    
            goto L_8004DD4C;
    }
    // 0x8004DCB8: nop

    // 0x8004DCBC: jal         0x800665E8
    // 0x8004DCC0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    set_active_camera(rdram, ctx);
        goto after_1;
    // 0x8004DCC0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_1:
    // 0x8004DCC4: jal         0x80069CFC
    // 0x8004DCC8: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_2;
    // 0x8004DCC8: nop

    after_2:
    // 0x8004DCCC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8004DCD0: addiu       $v1, $v1, -0x2AF8
    ctx->r3 = ADD32(ctx->r3, -0X2AF8);
    // 0x8004DCD4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004DCD8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8004DCDC: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8004DCE0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8004DCE4: addiu       $t5, $zero, 0x400
    ctx->r13 = ADD32(0, 0X400);
    // 0x8004DCE8: sh          $t5, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r13;
    // 0x8004DCEC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8004DCF0: lh          $t7, 0x196($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X196);
    // 0x8004DCF4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8004DCF8: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x8004DCFC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8004DD00: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004DD04: sh          $zero, 0x36($t9)
    MEM_H(0X36, ctx->r25) = 0;
    // 0x8004DD08: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8004DD0C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004DD10: sb          $t0, 0x3C($t1)
    MEM_B(0X3C, ctx->r9) = ctx->r8;
    // 0x8004DD14: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8004DD18: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8004DD1C: sb          $t0, 0x3D($t2)
    MEM_B(0X3D, ctx->r10) = ctx->r8;
    // 0x8004DD20: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8004DD24: nop

    // 0x8004DD28: sb          $t0, 0x3E($t3)
    MEM_B(0X3E, ctx->r11) = ctx->r8;
    // 0x8004DD2C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8004DD30: nop

    // 0x8004DD34: sb          $t0, 0x3F($t4)
    MEM_B(0X3F, ctx->r12) = ctx->r8;
    // 0x8004DD38: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8004DD3C: jal         0x80057A40
    // 0x8004DD40: swc1        $f18, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f18.u32l;
    update_player_camera(rdram, ctx);
        goto after_3;
    // 0x8004DD40: swc1        $f18, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f18.u32l;
    after_3:
    // 0x8004DD44: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8004DD48: nop

L_8004DD4C:
    // 0x8004DD4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004DD50: addiu       $v0, $v0, -0x2A7E
    ctx->r2 = ADD32(ctx->r2, -0X2A7E);
    // 0x8004DD54: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8004DD58: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8004DD5C: bne         $t6, $zero, L_8004DD7C
    if (ctx->r14 != 0) {
        // 0x8004DD60: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8004DD7C;
    }
    // 0x8004DD60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004DD64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DD68: sb          $zero, -0x2A7D($at)
    MEM_B(-0X2A7D, ctx->r1) = 0;
    // 0x8004DD6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DD70: sh          $zero, -0x2A7A($at)
    MEM_H(-0X2A7A, ctx->r1) = 0;
    // 0x8004DD74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DD78: sb          $zero, -0x2A7C($at)
    MEM_B(-0X2A7C, ctx->r1) = 0;
L_8004DD7C:
    // 0x8004DD7C: lw          $t8, 0x4C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X4C);
    // 0x8004DD80: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8004DD84: sh          $t7, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r15;
    // 0x8004DD88: lw          $t9, 0x4C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4C);
    // 0x8004DD8C: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x8004DD90: sb          $zero, 0x11($t9)
    MEM_B(0X11, ctx->r25) = 0;
    // 0x8004DD94: lw          $t2, 0x4C($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X4C);
    // 0x8004DD98: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8004DD9C: sb          $t1, 0x10($t2)
    MEM_B(0X10, ctx->r10) = ctx->r9;
    // 0x8004DDA0: lw          $t4, 0x4C($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X4C);
    // 0x8004DDA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DDA8: sb          $t3, 0x12($t4)
    MEM_B(0X12, ctx->r12) = ctx->r11;
    // 0x8004DDAC: sb          $zero, 0x1EE($s0)
    MEM_B(0X1EE, ctx->r16) = 0;
    // 0x8004DDB0: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x8004DDB4: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8004DDB8: bne         $t5, $zero, L_8004DDC4
    if (ctx->r13 != 0) {
        // 0x8004DDBC: addiu       $t7, $zero, 0x64
        ctx->r15 = ADD32(0, 0X64);
            goto L_8004DDC4;
    }
    // 0x8004DDBC: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8004DDC0: sb          $t0, 0x1F7($s0)
    MEM_B(0X1F7, ctx->r16) = ctx->r8;
L_8004DDC4:
    // 0x8004DDC4: sh          $zero, -0x2AA0($at)
    MEM_H(-0X2AA0, ctx->r1) = 0;
    // 0x8004DDC8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8004DDCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004DDD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DDD4: swc1        $f4, -0x2ABC($at)
    MEM_W(-0X2ABC, ctx->r1) = ctx->f4.u32l;
    // 0x8004DDD8: sb          $t6, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r14;
    // 0x8004DDDC: sh          $t7, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r15;
    // 0x8004DDE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DDE4: sb          $zero, -0x2A80($at)
    MEM_B(-0X2A80, ctx->r1) = 0;
    // 0x8004DDE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DDEC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8004DDF0: sb          $zero, -0x2A74($at)
    MEM_B(-0X2A74, ctx->r1) = 0;
    // 0x8004DDF4: sb          $zero, -0x2A73($at)
    MEM_B(-0X2A73, ctx->r1) = 0;
    // 0x8004DDF8: sb          $zero, -0x2A72($at)
    MEM_B(-0X2A72, ctx->r1) = 0;
    // 0x8004DDFC: sb          $zero, -0x2A71($at)
    MEM_B(-0X2A71, ctx->r1) = 0;
    // 0x8004DE00: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8004DE04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004DE08: jal         0x80043ECC
    // 0x8004DE0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    increment_ai_behaviour_chances(rdram, ctx);
        goto after_4;
    // 0x8004DE0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8004DE10: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8004DE14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DE18: sb          $v0, -0x2A7D($at)
    MEM_B(-0X2A7D, ctx->r1) = ctx->r2;
    // 0x8004DE1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004DE20: sb          $zero, -0x2A7B($at)
    MEM_B(-0X2A7B, ctx->r1) = 0;
    // 0x8004DE24: sb          $zero, 0x20A($s0)
    MEM_B(0X20A, ctx->r16) = 0;
    // 0x8004DE28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004DE2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004DE30: jr          $ra
    // 0x8004DE34: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8004DE34: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void get_projection_matrix_s16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069DB0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80069DB4: jr          $ra
    // 0x80069DB8: addiu       $v0, $v0, 0xFE0
    ctx->r2 = ADD32(ctx->r2, 0XFE0);
    return;
    // 0x80069DB8: addiu       $v0, $v0, 0xFE0
    ctx->r2 = ADD32(ctx->r2, 0XFE0);
;}
RECOMP_FUNC void obj_init_midifade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041A90: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x80041A94: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80041A98: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80041A9C: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80041AA0: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x80041AA4: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80041AA8: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80041AAC: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80041AB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80041AB4: sll         $t8, $t7, 10
    ctx->r24 = S32(ctx->r15 << 10);
    // 0x80041AB8: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x80041ABC: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x80041AC0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80041AC4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80041AC8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80041ACC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80041AD0: lw          $t0, 0x64($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X64);
    // 0x80041AD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80041AD8: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80041ADC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80041AE0: bc1f        L_80041AEC
    if (!c1cs) {
        // 0x80041AE4: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80041AEC;
    }
    // 0x80041AE4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80041AE8: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
L_80041AEC:
    // 0x80041AEC: nop

    // 0x80041AF0: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80041AF4: lw          $t2, 0x40($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X40);
    // 0x80041AF8: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x80041AFC: lwc1        $f8, 0xC($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80041B00: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80041B04: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x80041B08: addiu       $a1, $sp, 0xE0
    ctx->r5 = ADD32(ctx->r29, 0XE0);
    // 0x80041B0C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80041B10: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80041B14: sh          $t3, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r11;
    // 0x80041B18: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80041B1C: nop

    // 0x80041B20: sh          $t4, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = ctx->r12;
    // 0x80041B24: lh          $t5, 0x4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4);
    // 0x80041B28: swc1        $f22, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f22.u32l;
    // 0x80041B2C: sw          $t0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r8;
    // 0x80041B30: sw          $a2, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r6;
    // 0x80041B34: swc1        $f20, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f20.u32l;
    // 0x80041B38: swc1        $f20, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f20.u32l;
    // 0x80041B3C: swc1        $f20, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f20.u32l;
    // 0x80041B40: jal         0x8006FC30
    // 0x80041B44: sh          $t5, 0xE4($sp)
    MEM_H(0XE4, ctx->r29) = ctx->r13;
    mtxf_from_transform(rdram, ctx);
        goto after_0;
    // 0x80041B44: sh          $t5, 0xE4($sp)
    MEM_H(0XE4, ctx->r29) = ctx->r13;
    after_0:
    // 0x80041B48: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80041B4C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80041B50: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80041B54: addiu       $t6, $sp, 0xDC
    ctx->r14 = ADD32(ctx->r29, 0XDC);
    // 0x80041B58: addiu       $t7, $sp, 0xD8
    ctx->r15 = ADD32(ctx->r29, 0XD8);
    // 0x80041B5C: addiu       $t8, $sp, 0xD4
    ctx->r24 = ADD32(ctx->r29, 0XD4);
    // 0x80041B60: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80041B64: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80041B68: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80041B6C: jal         0x8006F64C
    // 0x80041B70: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x80041B70: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    after_1:
    // 0x80041B74: lw          $t0, 0xFC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XFC);
    // 0x80041B78: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80041B7C: lw          $a0, 0x104($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X104);
    // 0x80041B80: swc1        $f4, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f4.u32l;
    // 0x80041B84: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80041B88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80041B8C: swc1        $f6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f6.u32l;
    // 0x80041B90: lwc1        $f8, 0xD4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80041B94: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80041B98: swc1        $f8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f8.u32l;
    // 0x80041B9C: lwc1        $f4, 0xDC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x80041BA0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80041BA4: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80041BA8: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80041BAC: lwc1        $f10, 0xD8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x80041BB0: nop

    // 0x80041BB4: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80041BB8: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80041BBC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80041BC0: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80041BC4: nop

    // 0x80041BC8: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80041BCC: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80041BD0: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x80041BD4: swc1        $f6, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f6.u32l;
    // 0x80041BD8: lbu         $t9, 0x1A($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1A);
    // 0x80041BDC: nop

    // 0x80041BE0: sb          $t9, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r25;
    // 0x80041BE4: lbu         $t1, 0x1B($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X1B);
    // 0x80041BE8: nop

    // 0x80041BEC: sb          $t1, 0x40($t0)
    MEM_B(0X40, ctx->r8) = ctx->r9;
L_80041BF0:
    // 0x80041BF0: lbu         $t2, 0xA($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XA);
    // 0x80041BF4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80041BF8: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x80041BFC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80041C00: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80041C04: bne         $at, $zero, L_80041BF0
    if (ctx->r1 != 0) {
        // 0x80041C08: sb          $t2, 0x2F($v1)
        MEM_B(0X2F, ctx->r3) = ctx->r10;
            goto L_80041BF0;
    }
    // 0x80041C08: sb          $t2, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = ctx->r10;
    // 0x80041C0C: lw          $t3, 0x68($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X68);
    // 0x80041C10: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80041C14: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x80041C18: nop

    // 0x80041C1C: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80041C20: nop

    // 0x80041C24: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x80041C28: lh          $a3, 0x24($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X24);
    // 0x80041C2C: addiu       $v1, $a2, 0xA
    ctx->r3 = ADD32(ctx->r6, 0XA);
    // 0x80041C30: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x80041C34: lh          $t5, 0x2($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X2);
    // 0x80041C38: lh          $t6, 0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X4);
    // 0x80041C3C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80041C40: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80041C44: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80041C48: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80041C4C: sll         $a1, $a3, 2
    ctx->r5 = S32(ctx->r7 << 2);
    // 0x80041C50: addu        $a1, $a1, $a3
    ctx->r5 = ADD32(ctx->r5, ctx->r7);
    // 0x80041C54: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80041C58: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x80041C5C: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x80041C60: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80041C64: addiu       $a0, $a2, 0xA
    ctx->r4 = ADD32(ctx->r6, 0XA);
    // 0x80041C68: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x80041C6C: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    // 0x80041C70: bne         $at, $zero, L_80041D38
    if (ctx->r1 != 0) {
        // 0x80041C74: mov.s       $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
            goto L_80041D38;
    }
    // 0x80041C74: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
L_80041C78:
    // 0x80041C78: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80041C7C: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x80041C80: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80041C84: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80041C88: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80041C8C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80041C90: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80041C94: nop

    // 0x80041C98: bc1f        L_80041CA4
    if (!c1cs) {
        // 0x80041C9C: nop
    
            goto L_80041CA4;
    }
    // 0x80041C9C: nop

    // 0x80041CA0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_80041CA4:
    // 0x80041CA4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80041CA8: nop

    // 0x80041CAC: bc1f        L_80041CB8
    if (!c1cs) {
        // 0x80041CB0: nop
    
            goto L_80041CB8;
    }
    // 0x80041CB0: nop

    // 0x80041CB4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80041CB8:
    // 0x80041CB8: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80041CBC: nop

    // 0x80041CC0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80041CC4: nop

    // 0x80041CC8: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80041CCC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80041CD0: nop

    // 0x80041CD4: bc1f        L_80041CE0
    if (!c1cs) {
        // 0x80041CD8: nop
    
            goto L_80041CE0;
    }
    // 0x80041CD8: nop

    // 0x80041CDC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_80041CE0:
    // 0x80041CE0: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80041CE4: nop

    // 0x80041CE8: bc1f        L_80041CF4
    if (!c1cs) {
        // 0x80041CEC: nop
    
            goto L_80041CF4;
    }
    // 0x80041CEC: nop

    // 0x80041CF0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80041CF4:
    // 0x80041CF4: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x80041CF8: nop

    // 0x80041CFC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80041D00: nop

    // 0x80041D04: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80041D08: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80041D0C: nop

    // 0x80041D10: bc1f        L_80041D1C
    if (!c1cs) {
        // 0x80041D14: nop
    
            goto L_80041D1C;
    }
    // 0x80041D14: nop

    // 0x80041D18: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
L_80041D1C:
    // 0x80041D1C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80041D20: nop

    // 0x80041D24: bc1f        L_80041D30
    if (!c1cs) {
        // 0x80041D28: nop
    
            goto L_80041D30;
    }
    // 0x80041D28: nop

    // 0x80041D2C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80041D30:
    // 0x80041D30: bne         $at, $zero, L_80041C78
    if (ctx->r1 != 0) {
        // 0x80041D34: addiu       $a0, $a0, 0xA
        ctx->r4 = ADD32(ctx->r4, 0XA);
            goto L_80041C78;
    }
    // 0x80041D34: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
L_80041D38:
    // 0x80041D38: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80041D3C: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x80041D40: swc1        $f14, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f14.u32l;
    // 0x80041D44: swc1        $f12, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f12.u32l;
    // 0x80041D48: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
    // 0x80041D4C: jal         0x800707F8
    // 0x80041D50: sw          $t0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r8;
    coss_f(rdram, ctx);
        goto after_2;
    // 0x80041D50: sw          $t0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r8;
    after_2:
    // 0x80041D54: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x80041D58: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80041D5C: jal         0x800707C4
    // 0x80041D60: nop

    sins_f(rdram, ctx);
        goto after_3;
    // 0x80041D60: nop

    after_3:
    // 0x80041D64: lwc1        $f14, 0x80($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80041D68: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80041D6C: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80041D70: mul.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x80041D74: mov.s       $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    ctx->f18.fl = ctx->f14.fl;
    // 0x80041D78: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80041D7C: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80041D80: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80041D84: lw          $t0, 0xFC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XFC);
    // 0x80041D88: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80041D8C: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80041D90: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80041D94: mov.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.fl = ctx->f2.fl;
    // 0x80041D98: mul.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80041D9C: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80041DA0: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80041DA4: add.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80041DA8: mul.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80041DAC: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80041DB0: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80041DB4: bc1f        L_80041DC8
    if (!c1cs) {
        // 0x80041DB8: sub.s       $f12, $f6, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
            goto L_80041DC8;
    }
    // 0x80041DB8: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80041DBC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80041DC0: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80041DC4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_80041DC8:
    // 0x80041DC8: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80041DCC: nop

    // 0x80041DD0: bc1f        L_80041DE4
    if (!c1cs) {
        // 0x80041DD4: nop
    
            goto L_80041DE4;
    }
    // 0x80041DD4: nop

    // 0x80041DD8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80041DDC: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x80041DE0: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
L_80041DE4:
    // 0x80041DE4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80041DE8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80041DEC: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80041DF0: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80041DF4: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x80041DF8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80041DFC: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80041E00: mul.s       $f10, $f4, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80041E04: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80041E08: swc1        $f8, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f8.u32l;
    // 0x80041E0C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80041E10: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80041E14: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80041E18: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80041E1C: swc1        $f8, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f8.u32l;
    // 0x80041E20: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80041E24: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80041E28: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80041E2C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80041E30: swc1        $f8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f8.u32l;
    // 0x80041E34: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80041E38: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80041E3C: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80041E40: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80041E44: swc1        $f8, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->f8.u32l;
    // 0x80041E48: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80041E4C: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80041E50: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80041E54: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x80041E58: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80041E5C: swc1        $f8, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->f8.u32l;
    // 0x80041E60: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80041E64: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80041E68: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80041E6C: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80041E70: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80041E74: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80041E78: jr          $ra
    // 0x80041E7C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x80041E7C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void tex_enable_modes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AE28: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007AE2C: addiu       $v0, $v0, 0x6378
    ctx->r2 = ADD32(ctx->r2, 0X6378);
    // 0x8007AE30: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8007AE34: nor         $t7, $a0, $zero
    ctx->r15 = ~(ctx->r4 | 0);
    // 0x8007AE38: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8007AE3C: jr          $ra
    // 0x8007AE40: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x8007AE40: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void play_footstep_sounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800113CC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800113D0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800113D4: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x800113D8: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x800113DC: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800113E0: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800113E4: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800113E8: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800113EC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800113F0: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800113F4: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800113F8: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800113FC: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80011400: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80011404: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80011408: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001140C: lbu         $t6, 0x5B($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X5B);
    // 0x80011410: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80011414: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80011418: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x8001141C: beq         $at, $zero, L_80011520
    if (ctx->r1 == 0) {
        // 0x80011420: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80011520;
    }
    // 0x80011420: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80011424: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x80011428: lbu         $a0, 0x5C($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X5C);
    // 0x8001142C: jal         0x8001E29C
    // 0x80011430: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80011430: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    after_0:
    // 0x80011434: lb          $t8, 0x1($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1);
    // 0x80011438: lb          $t0, 0x2($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X2);
    // 0x8001143C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80011440: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80011444: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80011448: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001144C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80011450: lh          $s4, 0x18($s1)
    ctx->r20 = MEM_H(ctx->r17, 0X18);
    // 0x80011454: lb          $s2, 0x0($v0)
    ctx->r18 = MEM_B(ctx->r2, 0X0);
    // 0x80011458: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8001145C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80011460: sra         $t1, $s3, 4
    ctx->r9 = S32(SIGNED(ctx->r19) >> 4);
    // 0x80011464: mul.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80011468: sra         $t2, $s4, 4
    ctx->r10 = S32(SIGNED(ctx->r20) >> 4);
    // 0x8001146C: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80011470: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
    // 0x80011474: or          $s4, $t2, $zero
    ctx->r20 = ctx->r10 | 0;
    // 0x80011478: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001147C: blez        $s2, L_80011520
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80011480: cvt.s.w     $f22, $f10
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80011520;
    }
    // 0x80011480: cvt.s.w     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80011484: lw          $s5, 0x80($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X80);
    // 0x80011488: nop

    // 0x8001148C: addu        $t3, $s0, $s6
    ctx->r11 = ADD32(ctx->r16, ctx->r22);
L_80011490:
    // 0x80011490: lb          $v0, 0x3($t3)
    ctx->r2 = MEM_B(ctx->r11, 0X3);
    // 0x80011494: nop

    // 0x80011498: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001149C: bne         $at, $zero, L_800114A8
    if (ctx->r1 != 0) {
        // 0x800114A0: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800114A8;
    }
    // 0x800114A0: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800114A4: bne         $at, $zero, L_800114BC
    if (ctx->r1 != 0) {
        // 0x800114A8: slt         $at, $v0, $s4
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_800114BC;
    }
L_800114A8:
    // 0x800114A8: slt         $at, $v0, $s4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800114AC: bne         $at, $zero, L_80011510
    if (ctx->r1 != 0) {
        // 0x800114B0: slt         $at, $v0, $s3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_80011510;
    }
    // 0x800114B0: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800114B4: beq         $at, $zero, L_80011510
    if (ctx->r1 == 0) {
        // 0x800114B8: nop
    
            goto L_80011510;
    }
    // 0x800114B8: nop

L_800114BC:
    // 0x800114BC: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800114C0: lwc1        $f14, 0x10($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800114C4: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x800114C8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800114CC: jal         0x80069E14
    // 0x800114D0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    set_camera_shake_by_distance(rdram, ctx);
        goto after_1;
    // 0x800114D0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_1:
    // 0x800114D4: andi        $t4, $s0, 0x1
    ctx->r12 = ctx->r16 & 0X1;
    // 0x800114D8: beq         $t4, $zero, L_800114E8
    if (ctx->r12 == 0) {
        // 0x800114DC: addiu       $t5, $zero, 0x4
        ctx->r13 = ADD32(0, 0X4);
            goto L_800114E8;
    }
    // 0x800114DC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800114E0: b           L_800114EC
    // 0x800114E4: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
        goto L_800114EC;
    // 0x800114E4: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
L_800114E8:
    // 0x800114E8: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_800114EC:
    // 0x800114EC: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x800114F0: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x800114F4: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x800114F8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800114FC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80011500: jal         0x80009558
    // 0x80011504: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_2;
    // 0x80011504: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_2:
    // 0x80011508: addiu       $v1, $s0, 0x1
    ctx->r3 = ADD32(ctx->r16, 0X1);
    // 0x8001150C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_80011510:
    // 0x80011510: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80011514: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80011518: bne         $at, $zero, L_80011490
    if (ctx->r1 != 0) {
        // 0x8001151C: addu        $t3, $s0, $s6
        ctx->r11 = ADD32(ctx->r16, ctx->r22);
            goto L_80011490;
    }
    // 0x8001151C: addu        $t3, $s0, $s6
    ctx->r11 = ADD32(ctx->r16, ctx->r22);
L_80011520:
    // 0x80011520: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80011524: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80011528: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001152C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80011530: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80011534: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80011538: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8001153C: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80011540: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80011544: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80011548: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x8001154C: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x80011550: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80011554: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80011558: jr          $ra
    // 0x8001155C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001155C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void hud_setting(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8458: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A845C: lw          $t6, 0x6D0C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D0C);
    // 0x800A8460: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A8464: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800A8468: lb          $v0, 0x27A4($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X27A4);
    // 0x800A846C: jr          $ra
    // 0x800A8470: nop

    return;
    // 0x800A8470: nop

;}
RECOMP_FUNC void hud_visibility(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB1D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AB1D8: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x800AB1DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB1E0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800AB1E4: jr          $ra
    // 0x800AB1E8: sb          $t8, 0x6CD2($at)
    MEM_B(0X6CD2, ctx->r1) = ctx->r24;
    return;
    // 0x800AB1E8: sb          $t8, 0x6CD2($at)
    MEM_B(0X6CD2, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void is_postrace_viewport_active(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EAB0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006EAB4: lb          $v0, 0x3516($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3516);
    // 0x8006EAB8: jr          $ra
    // 0x8006EABC: nop

    return;
    // 0x8006EABC: nop

;}
RECOMP_FUNC void __freeParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006569C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800656A0: lw          $v0, 0x3780($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3780);
    // 0x800656A4: nop

    // 0x800656A8: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x800656AC: nop

    // 0x800656B0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800656B4: jr          $ra
    // 0x800656B8: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
    return;
    // 0x800656B8: sw          $a0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void func_80060C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060C58: bne         $a1, $a3, L_80060C74
    if (ctx->r5 != ctx->r7) {
        // 0x80060C5C: lw          $v1, 0x10($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X10);
            goto L_80060C74;
    }
    // 0x80060C5C: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80060C60: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80060C64: nop

    // 0x80060C68: beq         $a2, $v1, L_80060C88
    if (ctx->r6 == ctx->r3) {
        // 0x80060C6C: nop
    
            goto L_80060C88;
    }
    // 0x80060C6C: nop

    // 0x80060C70: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
L_80060C74:
    // 0x80060C74: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80060C78: bne         $a1, $v1, L_80060C90
    if (ctx->r5 != ctx->r3) {
        // 0x80060C7C: nop
    
            goto L_80060C90;
    }
    // 0x80060C7C: nop

    // 0x80060C80: bne         $a2, $a3, L_80060C90
    if (ctx->r6 != ctx->r7) {
        // 0x80060C84: nop
    
            goto L_80060C90;
    }
    // 0x80060C84: nop

L_80060C88:
    // 0x80060C88: jr          $ra
    // 0x80060C8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80060C8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060C90:
    // 0x80060C90: multu       $a3, $t5
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060C94: mflo        $t6
    ctx->r14 = lo;
    // 0x80060C98: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x80060C9C: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x80060CA0: multu       $a1, $t5
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060CA4: addiu       $t2, $t1, -0x4
    ctx->r10 = ADD32(ctx->r9, -0X4);
    // 0x80060CA8: addiu       $t8, $t1, 0x4
    ctx->r24 = ADD32(ctx->r9, 0X4);
    // 0x80060CAC: mflo        $t7
    ctx->r15 = lo;
    // 0x80060CB0: addu        $t0, $t7, $a0
    ctx->r8 = ADD32(ctx->r15, ctx->r4);
    // 0x80060CB4: lh          $t3, 0x0($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X0);
    // 0x80060CB8: nop

    // 0x80060CBC: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80060CC0: beq         $at, $zero, L_80060DA8
    if (ctx->r1 == 0) {
        // 0x80060CC4: slt         $at, $t3, $t8
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
            goto L_80060DA8;
    }
    // 0x80060CC4: slt         $at, $t3, $t8
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80060CC8: beq         $at, $zero, L_80060DA8
    if (ctx->r1 == 0) {
        // 0x80060CCC: nop
    
            goto L_80060DA8;
    }
    // 0x80060CCC: nop

    // 0x80060CD0: lh          $a3, 0x2($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X2);
    // 0x80060CD4: lh          $a1, 0x2($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X2);
    // 0x80060CD8: addiu       $t9, $a3, -0x4
    ctx->r25 = ADD32(ctx->r7, -0X4);
    // 0x80060CDC: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80060CE0: beq         $at, $zero, L_80060DA8
    if (ctx->r1 == 0) {
        // 0x80060CE4: addiu       $t6, $a3, 0x4
        ctx->r14 = ADD32(ctx->r7, 0X4);
            goto L_80060DA8;
    }
    // 0x80060CE4: addiu       $t6, $a3, 0x4
    ctx->r14 = ADD32(ctx->r7, 0X4);
    // 0x80060CE8: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80060CEC: beq         $at, $zero, L_80060DA8
    if (ctx->r1 == 0) {
        // 0x80060CF0: nop
    
            goto L_80060DA8;
    }
    // 0x80060CF0: nop

    // 0x80060CF4: lh          $a3, 0x4($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X4);
    // 0x80060CF8: lh          $a1, 0x4($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X4);
    // 0x80060CFC: addiu       $t7, $a3, -0x4
    ctx->r15 = ADD32(ctx->r7, -0X4);
    // 0x80060D00: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80060D04: beq         $at, $zero, L_80060DA8
    if (ctx->r1 == 0) {
        // 0x80060D08: addiu       $t8, $a3, 0x4
        ctx->r24 = ADD32(ctx->r7, 0X4);
            goto L_80060DA8;
    }
    // 0x80060D08: addiu       $t8, $a3, 0x4
    ctx->r24 = ADD32(ctx->r7, 0X4);
    // 0x80060D0C: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80060D10: beq         $at, $zero, L_80060DA8
    if (ctx->r1 == 0) {
        // 0x80060D14: nop
    
            goto L_80060DA8;
    }
    // 0x80060D14: nop

    // 0x80060D18: multu       $v1, $t5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060D1C: mflo        $t9
    ctx->r25 = lo;
    // 0x80060D20: addu        $a3, $t9, $a0
    ctx->r7 = ADD32(ctx->r25, ctx->r4);
    // 0x80060D24: lh          $t4, 0x0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X0);
    // 0x80060D28: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060D2C: addiu       $t7, $t4, -0x4
    ctx->r15 = ADD32(ctx->r12, -0X4);
    // 0x80060D30: addiu       $t8, $t4, 0x4
    ctx->r24 = ADD32(ctx->r12, 0X4);
    // 0x80060D34: mflo        $t6
    ctx->r14 = lo;
    // 0x80060D38: addu        $a1, $t6, $a0
    ctx->r5 = ADD32(ctx->r14, ctx->r4);
    // 0x80060D3C: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x80060D40: nop

    // 0x80060D44: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80060D48: beq         $at, $zero, L_80060E9C
    if (ctx->r1 == 0) {
        // 0x80060D4C: slt         $at, $t0, $t8
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
            goto L_80060E9C;
    }
    // 0x80060D4C: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80060D50: beq         $at, $zero, L_80060EA0
    if (ctx->r1 == 0) {
        // 0x80060D54: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80060EA0;
    }
    // 0x80060D54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80060D58: lh          $t3, 0x2($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2);
    // 0x80060D5C: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x80060D60: addiu       $t9, $t3, -0x4
    ctx->r25 = ADD32(ctx->r11, -0X4);
    // 0x80060D64: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80060D68: beq         $at, $zero, L_80060E9C
    if (ctx->r1 == 0) {
        // 0x80060D6C: addiu       $t6, $t3, 0x4
        ctx->r14 = ADD32(ctx->r11, 0X4);
            goto L_80060E9C;
    }
    // 0x80060D6C: addiu       $t6, $t3, 0x4
    ctx->r14 = ADD32(ctx->r11, 0X4);
    // 0x80060D70: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80060D74: beq         $at, $zero, L_80060EA0
    if (ctx->r1 == 0) {
        // 0x80060D78: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80060EA0;
    }
    // 0x80060D78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80060D7C: lh          $t3, 0x4($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X4);
    // 0x80060D80: lh          $v1, 0x4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X4);
    // 0x80060D84: addiu       $t7, $t3, -0x4
    ctx->r15 = ADD32(ctx->r11, -0X4);
    // 0x80060D88: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80060D8C: beq         $at, $zero, L_80060E9C
    if (ctx->r1 == 0) {
        // 0x80060D90: addiu       $t8, $t3, 0x4
        ctx->r24 = ADD32(ctx->r11, 0X4);
            goto L_80060E9C;
    }
    // 0x80060D90: addiu       $t8, $t3, 0x4
    ctx->r24 = ADD32(ctx->r11, 0X4);
    // 0x80060D94: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80060D98: beq         $at, $zero, L_80060EA0
    if (ctx->r1 == 0) {
        // 0x80060D9C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80060EA0;
    }
    // 0x80060D9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80060DA0: jr          $ra
    // 0x80060DA4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80060DA4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80060DA8:
    // 0x80060DA8: multu       $v1, $t5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060DAC: mflo        $t9
    ctx->r25 = lo;
    // 0x80060DB0: addu        $a3, $t9, $a0
    ctx->r7 = ADD32(ctx->r25, ctx->r4);
    // 0x80060DB4: lh          $t4, 0x0($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X0);
    // 0x80060DB8: nop

    // 0x80060DBC: addiu       $t6, $t4, -0x4
    ctx->r14 = ADD32(ctx->r12, -0X4);
    // 0x80060DC0: slt         $at, $t6, $t3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80060DC4: beq         $at, $zero, L_80060E9C
    if (ctx->r1 == 0) {
        // 0x80060DC8: addiu       $t7, $t4, 0x4
        ctx->r15 = ADD32(ctx->r12, 0X4);
            goto L_80060E9C;
    }
    // 0x80060DC8: addiu       $t7, $t4, 0x4
    ctx->r15 = ADD32(ctx->r12, 0X4);
    // 0x80060DCC: slt         $at, $t3, $t7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80060DD0: beq         $at, $zero, L_80060E9C
    if (ctx->r1 == 0) {
        // 0x80060DD4: nop
    
            goto L_80060E9C;
    }
    // 0x80060DD4: nop

    // 0x80060DD8: lh          $t3, 0x2($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X2);
    // 0x80060DDC: lh          $a1, 0x2($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X2);
    // 0x80060DE0: addiu       $t8, $t3, -0x4
    ctx->r24 = ADD32(ctx->r11, -0X4);
    // 0x80060DE4: slt         $at, $t8, $a1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80060DE8: beq         $at, $zero, L_80060E9C
    if (ctx->r1 == 0) {
        // 0x80060DEC: addiu       $t9, $t3, 0x4
        ctx->r25 = ADD32(ctx->r11, 0X4);
            goto L_80060E9C;
    }
    // 0x80060DEC: addiu       $t9, $t3, 0x4
    ctx->r25 = ADD32(ctx->r11, 0X4);
    // 0x80060DF0: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80060DF4: beq         $at, $zero, L_80060E9C
    if (ctx->r1 == 0) {
        // 0x80060DF8: nop
    
            goto L_80060E9C;
    }
    // 0x80060DF8: nop

    // 0x80060DFC: lh          $t3, 0x4($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X4);
    // 0x80060E00: lh          $a1, 0x4($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X4);
    // 0x80060E04: addiu       $t6, $t3, -0x4
    ctx->r14 = ADD32(ctx->r11, -0X4);
    // 0x80060E08: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80060E0C: beq         $at, $zero, L_80060E9C
    if (ctx->r1 == 0) {
        // 0x80060E10: addiu       $t7, $t3, 0x4
        ctx->r15 = ADD32(ctx->r11, 0X4);
            goto L_80060E9C;
    }
    // 0x80060E10: addiu       $t7, $t3, 0x4
    ctx->r15 = ADD32(ctx->r11, 0X4);
    // 0x80060E14: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80060E18: beq         $at, $zero, L_80060E9C
    if (ctx->r1 == 0) {
        // 0x80060E1C: nop
    
            goto L_80060E9C;
    }
    // 0x80060E1C: nop

    // 0x80060E20: multu       $a2, $t5
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060E24: addiu       $t9, $t1, 0x4
    ctx->r25 = ADD32(ctx->r9, 0X4);
    // 0x80060E28: mflo        $t8
    ctx->r24 = lo;
    // 0x80060E2C: addu        $a1, $t8, $a0
    ctx->r5 = ADD32(ctx->r24, ctx->r4);
    // 0x80060E30: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x80060E34: nop

    // 0x80060E38: slt         $at, $t2, $t0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80060E3C: beq         $at, $zero, L_80060E9C
    if (ctx->r1 == 0) {
        // 0x80060E40: slt         $at, $t0, $t9
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_80060E9C;
    }
    // 0x80060E40: slt         $at, $t0, $t9
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80060E44: beq         $at, $zero, L_80060E9C
    if (ctx->r1 == 0) {
        // 0x80060E48: nop
    
            goto L_80060E9C;
    }
    // 0x80060E48: nop

    // 0x80060E4C: lh          $a3, 0x2($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X2);
    // 0x80060E50: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x80060E54: addiu       $t6, $a3, -0x4
    ctx->r14 = ADD32(ctx->r7, -0X4);
    // 0x80060E58: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80060E5C: beq         $at, $zero, L_80060E9C
    if (ctx->r1 == 0) {
        // 0x80060E60: addiu       $t7, $a3, 0x4
        ctx->r15 = ADD32(ctx->r7, 0X4);
            goto L_80060E9C;
    }
    // 0x80060E60: addiu       $t7, $a3, 0x4
    ctx->r15 = ADD32(ctx->r7, 0X4);
    // 0x80060E64: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80060E68: beq         $at, $zero, L_80060E9C
    if (ctx->r1 == 0) {
        // 0x80060E6C: nop
    
            goto L_80060E9C;
    }
    // 0x80060E6C: nop

    // 0x80060E70: lh          $a3, 0x4($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X4);
    // 0x80060E74: lh          $v1, 0x4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X4);
    // 0x80060E78: addiu       $t8, $a3, -0x4
    ctx->r24 = ADD32(ctx->r7, -0X4);
    // 0x80060E7C: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80060E80: beq         $at, $zero, L_80060E9C
    if (ctx->r1 == 0) {
        // 0x80060E84: addiu       $t9, $a3, 0x4
        ctx->r25 = ADD32(ctx->r7, 0X4);
            goto L_80060E9C;
    }
    // 0x80060E84: addiu       $t9, $a3, 0x4
    ctx->r25 = ADD32(ctx->r7, 0X4);
    // 0x80060E88: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80060E8C: beq         $at, $zero, L_80060EA0
    if (ctx->r1 == 0) {
        // 0x80060E90: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80060EA0;
    }
    // 0x80060E90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80060E94: jr          $ra
    // 0x80060E98: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80060E98: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80060E9C:
    // 0x80060E9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060EA0:
    // 0x80060EA0: jr          $ra
    // 0x80060EA4: nop

    return;
    // 0x80060EA4: nop

;}
RECOMP_FUNC void racer_sound_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007F94: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80007F98: lbu         $v0, -0x3930($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3930);
    // 0x80007F9C: jr          $ra
    // 0x80007FA0: nop

    return;
    // 0x80007FA0: nop

;}
RECOMP_FUNC void hud_time_trial_message(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6DB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A6DB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A6DBC: jal         0x8006EA90
    // 0x800A6DC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x800A6DC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A6DC4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800A6DC8: nop

    // 0x800A6DCC: beq         $v1, $zero, L_800A6E24
    if (ctx->r3 == 0) {
        // 0x800A6DD0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A6E24;
    }
    // 0x800A6DD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A6DD4: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800A6DD8: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    // 0x800A6DDC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800A6DE0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800A6DE4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800A6DE8: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800A6DEC: lb          $t9, 0x58($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X58);
    // 0x800A6DF0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A6DF4: andi        $t0, $t9, 0x80
    ctx->r8 = ctx->r25 & 0X80;
    // 0x800A6DF8: beq         $t0, $zero, L_800A6E18
    if (ctx->r8 == 0) {
        // 0x800A6DFC: nop
    
            goto L_800A6E18;
    }
    // 0x800A6DFC: nop

    // 0x800A6E00: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A6E04: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    // 0x800A6E08: jal         0x80001D04
    // 0x800A6E0C: addiu       $a0, $zero, 0x145
    ctx->r4 = ADD32(0, 0X145);
    sound_play(rdram, ctx);
        goto after_1;
    // 0x800A6E0C: addiu       $a0, $zero, 0x145
    ctx->r4 = ADD32(0, 0X145);
    after_1:
    // 0x800A6E10: b           L_800A6E24
    // 0x800A6E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A6E24;
    // 0x800A6E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A6E18:
    // 0x800A6E18: jal         0x80001D04
    // 0x800A6E1C: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    sound_play(rdram, ctx);
        goto after_2;
    // 0x800A6E1C: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    after_2:
    // 0x800A6E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A6E24:
    // 0x800A6E24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A6E28: jr          $ra
    // 0x800A6E2C: nop

    return;
    // 0x800A6E2C: nop

;}
RECOMP_FUNC void music_next(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001954: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80001958: lbu         $v1, -0x39A4($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X39A4);
    // 0x8000195C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001960: beq         $v1, $zero, L_80001970
    if (ctx->r3 == 0) {
        // 0x80001964: nop
    
            goto L_80001970;
    }
    // 0x80001964: nop

    // 0x80001968: jr          $ra
    // 0x8000196C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000196C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80001970:
    // 0x80001970: lbu         $v0, 0x5D04($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5D04);
    // 0x80001974: nop

    // 0x80001978: jr          $ra
    // 0x8000197C: nop

    return;
    // 0x8000197C: nop

;}
RECOMP_FUNC void setup_particle_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B03C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B03C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B03C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B03CC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B03D0: lh          $t6, 0x18($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X18);
    // 0x800B03D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B03D8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B03DC: nop

    // 0x800B03E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B03E4: swc1        $f6, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f6.u32l;
    // 0x800B03E8: lh          $t7, 0x1A($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X1A);
    // 0x800B03EC: nop

    // 0x800B03F0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800B03F4: nop

    // 0x800B03F8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B03FC: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x800B0400: lh          $t8, 0x1C($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X1C);
    // 0x800B0404: nop

    // 0x800B0408: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800B040C: nop

    // 0x800B0410: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B0414: swc1        $f18, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f18.u32l;
    // 0x800B0418: lwc1        $f4, 0x58($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X58);
    // 0x800B041C: nop

    // 0x800B0420: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x800B0424: lw          $t9, 0x5C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X5C);
    // 0x800B0428: nop

    // 0x800B042C: sll         $t0, $t9, 12
    ctx->r8 = S32(ctx->r25 << 12);
    // 0x800B0430: bgez        $t0, L_800B0484
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800B0434: nop
    
            goto L_800B0484;
    }
    // 0x800B0434: nop

    // 0x800B0438: lw          $a1, 0x94($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X94);
    // 0x800B043C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B0440: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B0444: jal         0x8006F94C
    // 0x800B0448: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x800B0448: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_0:
    // 0x800B044C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800B0450: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B0454: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B0458: lwc1        $f17, -0x7448($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X7448);
    // 0x800B045C: lwc1        $f16, -0x7444($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7444);
    // 0x800B0460: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B0464: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x800B0468: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800B046C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800B0470: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B0474: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0478: add.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f6.d + ctx->f18.d;
    // 0x800B047C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800B0480: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_800B0484:
    // 0x800B0484: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x800B0488: nop

    // 0x800B048C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800B0490: beq         $t2, $zero, L_800B05EC
    if (ctx->r10 == 0) {
        // 0x800B0494: nop
    
            goto L_800B05EC;
    }
    // 0x800B0494: nop

    // 0x800B0498: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B049C: nop

    // 0x800B04A0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800B04A4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800B04A8: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B04AC: nop

    // 0x800B04B0: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x800B04B4: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x800B04B8: lw          $v1, 0x5C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X5C);
    // 0x800B04BC: nop

    // 0x800B04C0: andi        $t3, $v1, 0x1
    ctx->r11 = ctx->r3 & 0X1;
    // 0x800B04C4: beq         $t3, $zero, L_800B0524
    if (ctx->r11 == 0) {
        // 0x800B04C8: andi        $t4, $v1, 0x6
        ctx->r12 = ctx->r3 & 0X6;
            goto L_800B0524;
    }
    // 0x800B04C8: andi        $t4, $v1, 0x6
    ctx->r12 = ctx->r3 & 0X6;
    // 0x800B04CC: lw          $a1, 0x60($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X60);
    // 0x800B04D0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B04D4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B04D8: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B04DC: jal         0x8006F94C
    // 0x800B04E0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x800B04E0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_1:
    // 0x800B04E4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800B04E8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B04EC: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B04F0: lwc1        $f11, -0x7440($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X7440);
    // 0x800B04F4: lwc1        $f10, -0x743C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X743C);
    // 0x800B04F8: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800B04FC: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B0500: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B0504: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0508: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B050C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800B0510: add.d       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f6.d + ctx->f16.d;
    // 0x800B0514: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0518: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x800B051C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x800B0520: andi        $t4, $v1, 0x6
    ctx->r12 = ctx->r3 & 0X6;
L_800B0524:
    // 0x800B0524: beq         $t4, $zero, L_800B05AC
    if (ctx->r12 == 0) {
        // 0x800B0528: addiu       $a0, $a2, 0xC
        ctx->r4 = ADD32(ctx->r6, 0XC);
            goto L_800B05AC;
    }
    // 0x800B0528: addiu       $a0, $a2, 0xC
    ctx->r4 = ADD32(ctx->r6, 0XC);
    // 0x800B052C: lh          $t5, 0xC($a2)
    ctx->r13 = MEM_H(ctx->r6, 0XC);
    // 0x800B0530: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    // 0x800B0534: beq         $t6, $zero, L_800B056C
    if (ctx->r14 == 0) {
        // 0x800B0538: sh          $t5, 0x28($sp)
        MEM_H(0X28, ctx->r29) = ctx->r13;
            goto L_800B056C;
    }
    // 0x800B0538: sh          $t5, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r13;
    // 0x800B053C: lh          $a1, 0x64($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X64);
    // 0x800B0540: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800B0544: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B0548: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B054C: jal         0x8006F94C
    // 0x800B0550: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800B0550: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_2:
    // 0x800B0554: lh          $t7, 0x28($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X28);
    // 0x800B0558: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B055C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800B0560: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800B0564: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800B0568: sh          $t8, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r24;
L_800B056C:
    // 0x800B056C: lh          $t9, 0xE($a2)
    ctx->r25 = MEM_H(ctx->r6, 0XE);
    // 0x800B0570: andi        $t0, $v1, 0x4
    ctx->r8 = ctx->r3 & 0X4;
    // 0x800B0574: beq         $t0, $zero, L_800B0598
    if (ctx->r8 == 0) {
        // 0x800B0578: sh          $t9, 0x2A($sp)
        MEM_H(0X2A, ctx->r29) = ctx->r25;
            goto L_800B0598;
    }
    // 0x800B0578: sh          $t9, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r25;
    // 0x800B057C: lh          $a1, 0x66($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X66);
    // 0x800B0580: jal         0x8006F94C
    // 0x800B0584: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_3;
    // 0x800B0584: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_3:
    // 0x800B0588: lh          $t1, 0x2A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X2A);
    // 0x800B058C: nop

    // 0x800B0590: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800B0594: sh          $t2, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r10;
L_800B0598:
    // 0x800B0598: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800B059C: jal         0x80070490
    // 0x800B05A0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    vec3f_rotate_py(rdram, ctx);
        goto after_4;
    // 0x800B05A0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x800B05A4: b           L_800B05B8
    // 0x800B05A8: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
        goto L_800B05B8;
    // 0x800B05A8: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
L_800B05AC:
    // 0x800B05AC: jal         0x80070320
    // 0x800B05B0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    vec3f_rotate(rdram, ctx);
        goto after_5;
    // 0x800B05B0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x800B05B4: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
L_800B05B8:
    // 0x800B05B8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800B05BC: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800B05C0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B05C4: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800B05C8: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x800B05CC: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800B05D0: nop

    // 0x800B05D4: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B05D8: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x800B05DC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B05E0: nop

    // 0x800B05E4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B05E8: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
L_800B05EC:
    // 0x800B05EC: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x800B05F0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B05F4: beq         $v0, $at, L_800B0610
    if (ctx->r2 == ctx->r1) {
        // 0x800B05F8: nop
    
            goto L_800B0610;
    }
    // 0x800B05F8: nop

    // 0x800B05FC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800B0600: jal         0x80070320
    // 0x800B0604: addiu       $a1, $s0, 0x4C
    ctx->r5 = ADD32(ctx->r16, 0X4C);
    vec3f_rotate(rdram, ctx);
        goto after_6;
    // 0x800B0604: addiu       $a1, $s0, 0x4C
    ctx->r5 = ADD32(ctx->r16, 0X4C);
    after_6:
    // 0x800B0608: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x800B060C: nop

L_800B0610:
    // 0x800B0610: lwc1        $f16, 0x4C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800B0614: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800B0618: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800B061C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B0620: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x800B0624: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x800B0628: bne         $v0, $at, L_800B063C
    if (ctx->r2 != ctx->r1) {
        // 0x800B062C: swc1        $f8, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
            goto L_800B063C;
    }
    // 0x800B062C: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x800B0630: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800B0634: jal         0x80070320
    // 0x800B0638: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    vec3f_rotate(rdram, ctx);
        goto after_7;
    // 0x800B0638: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    after_7:
L_800B063C:
    // 0x800B063C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800B0640: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B0644: lwc1        $f4, 0xC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC);
    // 0x800B0648: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B064C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B0650: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B0654: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x800B0658: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800B065C: nop

    // 0x800B0660: lwc1        $f18, 0x10($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X10);
    // 0x800B0664: nop

    // 0x800B0668: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B066C: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x800B0670: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800B0674: nop

    // 0x800B0678: lwc1        $f4, 0x14($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X14);
    // 0x800B067C: nop

    // 0x800B0680: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B0684: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x800B0688: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B068C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B0690: jr          $ra
    // 0x800B0694: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B0694: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void path_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011390: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80011394: jr          $ra
    // 0x80011398: sw          $zero, -0x5254($at)
    MEM_W(-0X5254, ctx->r1) = 0;
    return;
    // 0x80011398: sw          $zero, -0x5254($at)
    MEM_W(-0X5254, ctx->r1) = 0;
;}
RECOMP_FUNC void savemenu_input_source(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800874D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800874D4: andi        $t6, $a0, 0x4000
    ctx->r14 = ctx->r4 & 0X4000;
    // 0x800874D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800874DC: beq         $t6, $zero, L_80087528
    if (ctx->r14 == 0) {
        // 0x800874E0: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_80087528;
    }
    // 0x800874E0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800874E4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800874E8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800874EC: lw          $t8, 0x6A10($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A10);
    // 0x800874F0: lw          $t7, 0x6A14($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A14);
    // 0x800874F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800874F8: beq         $t7, $t8, L_80087510
    if (ctx->r15 == ctx->r24) {
        // 0x800874FC: sw          $zero, 0x63E0($at)
        MEM_W(0X63E0, ctx->r1) = 0;
            goto L_80087510;
    }
    // 0x800874FC: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
    // 0x80087500: jal         0x800871D8
    // 0x80087504: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    savemenu_render_error(rdram, ctx);
        goto after_0;
    // 0x80087504: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x80087508: b           L_800875D8
    // 0x8008750C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800875D8;
    // 0x8008750C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087510:
    // 0x80087510: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80087514: jal         0x80001D04
    // 0x80087518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80087518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8008751C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80087520: b           L_800875D4
    // 0x80087524: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
        goto L_800875D4;
    // 0x80087524: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_80087528:
    // 0x80087528: andi        $t0, $a0, 0x9000
    ctx->r8 = ctx->r4 & 0X9000;
    // 0x8008752C: beq         $t0, $zero, L_8008754C
    if (ctx->r8 == 0) {
        // 0x80087530: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008754C;
    }
    // 0x80087530: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80087534: jal         0x80001D04
    // 0x80087538: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80087538: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8008753C: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80087540: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087544: b           L_800875D4
    // 0x80087548: sw          $t1, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r9;
        goto L_800875D4;
    // 0x80087548: sw          $t1, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r9;
L_8008754C:
    // 0x8008754C: bgez        $a1, L_8008758C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80087550: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8008758C;
    }
    // 0x80087550: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087554: addiu       $v0, $v0, 0x6BD4
    ctx->r2 = ADD32(ctx->r2, 0X6BD4);
    // 0x80087558: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8008755C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80087560: blez        $t2, L_8008758C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80087564: nop
    
            goto L_8008758C;
    }
    // 0x80087564: nop

    // 0x80087568: jal         0x80001D04
    // 0x8008756C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x8008756C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80087570: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087574: addiu       $v0, $v0, 0x6BD4
    ctx->r2 = ADD32(ctx->r2, 0X6BD4);
    // 0x80087578: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8008757C: nop

    // 0x80087580: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80087584: b           L_800875D4
    // 0x80087588: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_800875D4;
    // 0x80087588: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8008758C:
    // 0x8008758C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087590: blez        $a1, L_800875D4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80087594: addiu       $v0, $v0, 0x6BD4
        ctx->r2 = ADD32(ctx->r2, 0X6BD4);
            goto L_800875D4;
    }
    // 0x80087594: addiu       $v0, $v0, 0x6BD4
    ctx->r2 = ADD32(ctx->r2, 0X6BD4);
    // 0x80087598: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008759C: lw          $t6, 0x6A08($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A08);
    // 0x800875A0: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800875A4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800875A8: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800875AC: beq         $at, $zero, L_800875D4
    if (ctx->r1 == 0) {
        // 0x800875B0: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_800875D4;
    }
    // 0x800875B0: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800875B4: jal         0x80001D04
    // 0x800875B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x800875B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800875BC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800875C0: addiu       $v0, $v0, 0x6BD4
    ctx->r2 = ADD32(ctx->r2, 0X6BD4);
    // 0x800875C4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800875C8: nop

    // 0x800875CC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800875D0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_800875D4:
    // 0x800875D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800875D8:
    // 0x800875D8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800875DC: jr          $ra
    // 0x800875E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800875E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void set_dialogue_font(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4F7C: bltz        $a0, L_800C4FB4
    if (SIGNED(ctx->r4) < 0) {
        // 0x800C4F80: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C4FB4;
    }
    // 0x800C4F80: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C4F84: beq         $at, $zero, L_800C4FB4
    if (ctx->r1 == 0) {
        // 0x800C4F88: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C4FB4;
    }
    // 0x800C4F88: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C4F8C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C4F90: lw          $t8, -0x5820($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5820);
    // 0x800C4F94: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C4F98: lw          $t7, -0x5818($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5818);
    // 0x800C4F9C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C4FA0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C4FA4: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C4FA8: beq         $at, $zero, L_800C4FB4
    if (ctx->r1 == 0) {
        // 0x800C4FAC: addu        $v0, $t6, $t7
        ctx->r2 = ADD32(ctx->r14, ctx->r15);
            goto L_800C4FB4;
    }
    // 0x800C4FAC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C4FB0: sb          $a1, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = ctx->r5;
L_800C4FB4:
    // 0x800C4FB4: jr          $ra
    // 0x800C4FB8: nop

    return;
    // 0x800C4FB8: nop

;}
RECOMP_FUNC void alAdpcmPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBBEC: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800CBBF0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800CBBF4: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x800CBBF8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800CBBFC: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x800CBC00: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800CBC04: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800CBC08: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800CBC0C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800CBC10: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800CBC14: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800CBC18: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800CBC1C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800CBC20: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800CBC24: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x800CBC28: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800CBC2C: bne         $a2, $zero, L_800CBC3C
    if (ctx->r6 != 0) {
        // 0x800CBC30: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_800CBC3C;
    }
    // 0x800CBC30: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800CBC34: b           L_800CC05C
    // 0x800CBC38: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
        goto L_800CC05C;
    // 0x800CBC38: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
L_800CBC3C:
    // 0x800CBC3C: lw          $t6, 0x2C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X2C);
    // 0x800CBC40: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CBC44: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CBC48: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    // 0x800CBC4C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800CBC50: lui         $at, 0xB00
    ctx->r1 = S32(0XB00 << 16);
    // 0x800CBC54: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800CBC58: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800CBC5C: lw          $t9, 0x28($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X28);
    // 0x800CBC60: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800CBC64: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CBC68: lw          $t6, 0x10($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X10);
    // 0x800CBC6C: addiu       $t2, $a1, 0x8
    ctx->r10 = ADD32(ctx->r5, 0X8);
    // 0x800CBC70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CBC74: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800CBC78: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800CBC7C: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800CBC80: lw          $v1, 0x38($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X38);
    // 0x800CBC84: lw          $a0, 0x20($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X20);
    // 0x800CBC88: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x800CBC8C: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x800CBC90: sltu        $t1, $a0, $t9
    ctx->r9 = ctx->r4 < ctx->r25 ? 1 : 0;
    // 0x800CBC94: beq         $t1, $zero, L_800CBCA8
    if (ctx->r9 == 0) {
        // 0x800CBC98: addiu       $t7, $zero, 0x10
        ctx->r15 = ADD32(0, 0X10);
            goto L_800CBCA8;
    }
    // 0x800CBC98: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x800CBC9C: lw          $t1, 0x24($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X24);
    // 0x800CBCA0: sltu        $t6, $zero, $t1
    ctx->r14 = 0 < ctx->r9 ? 1 : 0;
    // 0x800CBCA4: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
L_800CBCA8:
    // 0x800CBCA8: beq         $t1, $zero, L_800CBCB8
    if (ctx->r9 == 0) {
        // 0x800CBCAC: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800CBCB8;
    }
    // 0x800CBCAC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800CBCB0: b           L_800CBCB8
    // 0x800CBCB4: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
        goto L_800CBCB8;
    // 0x800CBCB4: subu        $a1, $a0, $v1
    ctx->r5 = SUB32(ctx->r4, ctx->r3);
L_800CBCB8:
    // 0x800CBCB8: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800CBCBC: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800CBCC0: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800CBCC4: beq         $v1, $zero, L_800CBCD4
    if (ctx->r3 == 0) {
        // 0x800CBCC8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800CBCD4;
    }
    // 0x800CBCC8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800CBCCC: b           L_800CBCD4
    // 0x800CBCD0: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
        goto L_800CBCD4;
    // 0x800CBCD0: subu        $a2, $t7, $v1
    ctx->r6 = SUB32(ctx->r15, ctx->r3);
L_800CBCD4:
    // 0x800CBCD4: subu        $a0, $a1, $a2
    ctx->r4 = SUB32(ctx->r5, ctx->r6);
    // 0x800CBCD8: bgez        $a0, L_800CBCE4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800CBCDC: nop
    
            goto L_800CBCE4;
    }
    // 0x800CBCDC: nop

    // 0x800CBCE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800CBCE4:
    // 0x800CBCE4: beq         $t1, $zero, L_800CBEEC
    if (ctx->r9 == 0) {
        // 0x800CBCE8: addiu       $fp, $a0, 0xF
        ctx->r30 = ADD32(ctx->r4, 0XF);
            goto L_800CBEEC;
    }
    // 0x800CBCE8: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800CBCEC: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800CBCF0: sra         $t8, $fp, 4
    ctx->r24 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800CBCF4: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x800CBCF8: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800CBCFC: sll         $t1, $t8, 3
    ctx->r9 = S32(ctx->r24 << 3);
    // 0x800CBD00: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x800CBD04: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800CBD08: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800CBD0C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800CBD10: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800CBD14: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x800CBD18: or          $fp, $t8, $zero
    ctx->r30 = ctx->r24 | 0;
    // 0x800CBD1C: jal         0x800CBAC0
    // 0x800CBD20: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    static_3_800CBAC0(rdram, ctx);
        goto after_0;
    // 0x800CBD20: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_0:
    // 0x800CBD24: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800CBD28: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800CBD2C: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800CBD30: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800CBD34: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800CBD38: beq         $v1, $zero, L_800CBD54
    if (ctx->r3 == 0) {
        // 0x800CBD3C: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800CBD54;
    }
    // 0x800CBD3C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800CBD40: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x800CBD44: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800CBD48: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800CBD4C: b           L_800CBD60
    // 0x800CBD50: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
        goto L_800CBD60;
    // 0x800CBD50: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_800CBD54:
    // 0x800CBD54: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x800CBD58: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x800CBD5C: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
L_800CBD60:
    // 0x800CBD60: lw          $v0, 0x1C($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X1C);
    // 0x800CBD64: lw          $t7, 0x28($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X28);
    // 0x800CBD68: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CBD6C: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x800CBD70: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800CBD74: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800CBD78: srl         $t9, $v0, 4
    ctx->r25 = S32(U32(ctx->r2) >> 4);
    // 0x800CBD7C: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x800CBD80: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x800CBD84: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800CBD88: addiu       $t9, $t7, 0x9
    ctx->r25 = ADD32(ctx->r15, 0X9);
    // 0x800CBD8C: sw          $t9, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r25;
    // 0x800CBD90: sw          $v0, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r2;
    // 0x800CBD94: beq         $at, $zero, L_800CBEBC
    if (ctx->r1 == 0) {
        // 0x800CBD98: lh          $a2, 0x0($a3)
        ctx->r6 = MEM_H(ctx->r7, 0X0);
            goto L_800CBEBC;
    }
    // 0x800CBD98: lh          $a2, 0x0($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X0);
    // 0x800CBD9C: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
L_800CBDA0:
    // 0x800CBDA0: addiu       $t8, $fp, 0x1
    ctx->r24 = ADD32(ctx->r30, 0X1);
    // 0x800CBDA4: sll         $t6, $t8, 5
    ctx->r14 = S32(ctx->r24 << 5);
    // 0x800CBDA8: lw          $v0, 0x24($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X24);
    // 0x800CBDAC: addu        $a3, $t6, $a2
    ctx->r7 = ADD32(ctx->r14, ctx->r6);
    // 0x800CBDB0: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x800CBDB4: and         $t7, $a3, $at
    ctx->r15 = ctx->r7 & ctx->r1;
    // 0x800CBDB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CBDBC: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x800CBDC0: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800CBDC4: beq         $v0, $at, L_800CBDD8
    if (ctx->r2 == ctx->r1) {
        // 0x800CBDC8: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_800CBDD8;
    }
    // 0x800CBDC8: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800CBDCC: beq         $v0, $zero, L_800CBDD8
    if (ctx->r2 == 0) {
        // 0x800CBDD0: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800CBDD8;
    }
    // 0x800CBDD0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800CBDD4: sw          $t9, 0x24($s7)
    MEM_W(0X24, ctx->r23) = ctx->r25;
L_800CBDD8:
    // 0x800CBDD8: lw          $t8, 0x20($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X20);
    // 0x800CBDDC: lw          $t6, 0x1C($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X1C);
    // 0x800CBDE0: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800CBDE4: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800CBDE8: subu        $v0, $t8, $t6
    ctx->r2 = SUB32(ctx->r24, ctx->r14);
    // 0x800CBDEC: sltu        $at, $t0, $v0
    ctx->r1 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x800CBDF0: beq         $at, $zero, L_800CBE00
    if (ctx->r1 == 0) {
        // 0x800CBDF4: sll         $s5, $a3, 16
        ctx->r21 = S32(ctx->r7 << 16);
            goto L_800CBE00;
    }
    // 0x800CBDF4: sll         $s5, $a3, 16
    ctx->r21 = S32(ctx->r7 << 16);
    // 0x800CBDF8: b           L_800CBE04
    // 0x800CBDFC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
        goto L_800CBE04;
    // 0x800CBDFC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_800CBE00:
    // 0x800CBE00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800CBE04:
    // 0x800CBE04: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x800CBE08: sra         $t8, $s5, 16
    ctx->r24 = S32(SIGNED(ctx->r21) >> 16);
    // 0x800CBE0C: or          $s5, $t8, $zero
    ctx->r21 = ctx->r24 | 0;
    // 0x800CBE10: addu        $a0, $a1, $t7
    ctx->r4 = ADD32(ctx->r5, ctx->r15);
    // 0x800CBE14: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800CBE18: bgez        $a0, L_800CBE24
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800CBE1C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800CBE24;
    }
    // 0x800CBE1C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800CBE20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800CBE24:
    // 0x800CBE24: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800CBE28: addiu       $fp, $a0, 0xF
    ctx->r30 = ADD32(ctx->r4, 0XF);
    // 0x800CBE2C: sra         $t9, $fp, 4
    ctx->r25 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800CBE30: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x800CBE34: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800CBE38: ori         $t6, $s4, 0x2
    ctx->r14 = ctx->r20 | 0X2;
    // 0x800CBE3C: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x800CBE40: or          $s1, $t1, $zero
    ctx->r17 = ctx->r9 | 0;
    // 0x800CBE44: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800CBE48: or          $fp, $t9, $zero
    ctx->r30 = ctx->r25 | 0;
    // 0x800CBE4C: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800CBE50: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    // 0x800CBE54: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x800CBE58: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x800CBE5C: jal         0x800CBAC0
    // 0x800CBE60: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    static_3_800CBAC0(rdram, ctx);
        goto after_1;
    // 0x800CBE60: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    after_1:
    // 0x800CBE64: lw          $t7, 0x3C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X3C);
    // 0x800CBE68: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    // 0x800CBE6C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CBE70: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800CBE74: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CBE78: addu        $t8, $t9, $a3
    ctx->r24 = ADD32(ctx->r25, ctx->r7);
    // 0x800CBE7C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800CBE80: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800CBE84: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800CBE88: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x800CBE8C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CBE90: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800CBE94: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800CBE98: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x800CBE9C: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800CBEA0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CBEA4: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800CBEA8: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800CBEAC: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CBEB0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800CBEB4: bne         $at, $zero, L_800CBDA0
    if (ctx->r1 != 0) {
        // 0x800CBEB8: addiu       $t2, $v0, 0x8
        ctx->r10 = ADD32(ctx->r2, 0X8);
            goto L_800CBDA0;
    }
    // 0x800CBEB8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
L_800CBEBC:
    // 0x800CBEBC: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x800CBEC0: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x800CBEC4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800CBEC8: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800CBECC: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800CBED0: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x800CBED4: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800CBED8: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800CBEDC: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800CBEE0: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x800CBEE4: b           L_800CC05C
    // 0x800CBEE8: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_800CC05C;
    // 0x800CBEE8: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_800CBEEC:
    // 0x800CBEEC: lw          $v0, 0x28($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X28);
    // 0x800CBEF0: sra         $t7, $fp, 4
    ctx->r15 = S32(SIGNED(ctx->r30) >> 4);
    // 0x800CBEF4: lw          $t9, 0x44($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X44);
    // 0x800CBEF8: sll         $t1, $t7, 3
    ctx->r9 = S32(ctx->r15 << 3);
    // 0x800CBEFC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800CBF00: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x800CBF04: or          $fp, $t7, $zero
    ctx->r30 = ctx->r15 | 0;
    // 0x800CBF08: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800CBF0C: addu        $t3, $t9, $t1
    ctx->r11 = ADD32(ctx->r25, ctx->r9);
    // 0x800CBF10: subu        $t6, $t3, $t8
    ctx->r14 = SUB32(ctx->r11, ctx->r24);
    // 0x800CBF14: subu        $v1, $t6, $t7
    ctx->r3 = SUB32(ctx->r14, ctx->r15);
    // 0x800CBF18: bgez        $v1, L_800CBF24
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800CBF1C: sll         $a1, $fp, 4
        ctx->r5 = S32(ctx->r30 << 4);
            goto L_800CBF24;
    }
    // 0x800CBF1C: sll         $a1, $fp, 4
    ctx->r5 = S32(ctx->r30 << 4);
    // 0x800CBF20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800CBF24:
    // 0x800CBF24: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x800CBF28: mflo        $v0
    ctx->r2 = lo;
    // 0x800CBF2C: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x800CBF30: addu        $t4, $a1, $a2
    ctx->r12 = ADD32(ctx->r5, ctx->r6);
    // 0x800CBF34: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800CBF38: beq         $at, $zero, L_800CBF44
    if (ctx->r1 == 0) {
        // 0x800CBF3C: or          $s0, $t2, $zero
        ctx->r16 = ctx->r10 | 0;
            goto L_800CBF44;
    }
    // 0x800CBF3C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x800CBF40: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
L_800CBF44:
    // 0x800CBF44: andi        $t8, $a0, 0xF
    ctx->r24 = ctx->r4 & 0XF;
    // 0x800CBF48: subu        $t6, $a0, $t8
    ctx->r14 = SUB32(ctx->r4, ctx->r24);
    // 0x800CBF4C: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800CBF50: beq         $at, $zero, L_800CC000
    if (ctx->r1 == 0) {
        // 0x800CBF54: subu        $a2, $t1, $v1
        ctx->r6 = SUB32(ctx->r9, ctx->r3);
            goto L_800CC000;
    }
    // 0x800CBF54: subu        $a2, $t1, $v1
    ctx->r6 = SUB32(ctx->r9, ctx->r3);
    // 0x800CBF58: lh          $s5, 0x0($a3)
    ctx->r21 = MEM_H(ctx->r7, 0X0);
    // 0x800CBF5C: lw          $s4, 0x40($s7)
    ctx->r20 = MEM_W(ctx->r23, 0X40);
    // 0x800CBF60: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800CBF64: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    // 0x800CBF68: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x800CBF6C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x800CBF70: sw          $t0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r8;
    // 0x800CBF74: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x800CBF78: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x800CBF7C: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x800CBF80: subu        $s6, $a1, $a0
    ctx->r22 = SUB32(ctx->r5, ctx->r4);
    // 0x800CBF84: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800CBF88: jal         0x800CBAC0
    // 0x800CBF8C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    static_3_800CBAC0(rdram, ctx);
        goto after_2;
    // 0x800CBF8C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_2:
    // 0x800CBF90: lw          $v1, 0x3C($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X3C);
    // 0x800CBF94: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x800CBF98: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    // 0x800CBF9C: lw          $t0, 0xB8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB8);
    // 0x800CBFA0: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x800CBFA4: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800CBFA8: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x800CBFAC: beq         $v1, $zero, L_800CBFC8
    if (ctx->r3 == 0) {
        // 0x800CBFB0: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800CBFC8;
    }
    // 0x800CBFB0: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800CBFB4: lh          $t7, 0x0($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X0);
    // 0x800CBFB8: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x800CBFBC: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800CBFC0: b           L_800CBFD4
    // 0x800CBFC4: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
        goto L_800CBFD4;
    // 0x800CBFC4: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
L_800CBFC8:
    // 0x800CBFC8: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x800CBFCC: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x800CBFD0: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
L_800CBFD4:
    // 0x800CBFD4: lw          $t9, 0x3C($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X3C);
    // 0x800CBFD8: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x800CBFDC: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800CBFE0: andi        $t6, $t8, 0xF
    ctx->r14 = ctx->r24 & 0XF;
    // 0x800CBFE4: lw          $t8, 0x44($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X44);
    // 0x800CBFE8: sw          $t6, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = ctx->r14;
    // 0x800CBFEC: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800CBFF0: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800CBFF4: sw          $t9, 0x38($s7)
    MEM_W(0X38, ctx->r23) = ctx->r25;
    // 0x800CBFF8: b           L_800CC008
    // 0x800CBFFC: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
        goto L_800CC008;
    // 0x800CBFFC: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
L_800CC000:
    // 0x800CC000: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x800CC004: sw          $t3, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r11;
L_800CC008:
    // 0x800CC008: beq         $a0, $zero, L_800CC058
    if (ctx->r4 == 0) {
        // 0x800CC00C: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_800CC058;
    }
    // 0x800CC00C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800CC010: beq         $t5, $zero, L_800CC028
    if (ctx->r13 == 0) {
        // 0x800CC014: sw          $zero, 0x3C($s7)
        MEM_W(0X3C, ctx->r23) = 0;
            goto L_800CC028;
    }
    // 0x800CC014: sw          $zero, 0x3C($s7)
    MEM_W(0X3C, ctx->r23) = 0;
    // 0x800CC018: subu        $v1, $t4, $a0
    ctx->r3 = SUB32(ctx->r12, ctx->r4);
    // 0x800CC01C: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x800CC020: b           L_800CC02C
    // 0x800CC024: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_800CC02C;
    // 0x800CC024: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_800CC028:
    // 0x800CC028: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800CC02C:
    // 0x800CC02C: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x800CC030: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CC034: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CC038: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800CC03C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800CC040: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800CC044: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CC048: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x800CC04C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800CC050: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CC054: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
L_800CC058:
    // 0x800CC058: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800CC05C:
    // 0x800CC05C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800CC060: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800CC064: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800CC068: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800CC06C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800CC070: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800CC074: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800CC078: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800CC07C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800CC080: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800CC084: jr          $ra
    // 0x800CC088: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x800CC088: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void music_table_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000216C: beq         $a0, $zero, L_80002180
    if (ctx->r4 == 0) {
        // 0x80002170: lui         $t6, 0x8011
        ctx->r14 = S32(0X8011 << 16);
            goto L_80002180;
    }
    // 0x80002170: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80002174: lw          $t6, 0x5D1C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5D1C);
    // 0x80002178: nop

    // 0x8000217C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_80002180:
    // 0x80002180: beq         $a1, $zero, L_80002194
    if (ctx->r5 == 0) {
        // 0x80002184: lui         $t7, 0x8011
        ctx->r15 = S32(0X8011 << 16);
            goto L_80002194;
    }
    // 0x80002184: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80002188: lw          $t7, 0x5D2C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5D2C);
    // 0x8000218C: nop

    // 0x80002190: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_80002194:
    // 0x80002194: beq         $a2, $zero, L_800021A8
    if (ctx->r6 == 0) {
        // 0x80002198: lui         $t8, 0x8011
        ctx->r24 = S32(0X8011 << 16);
            goto L_800021A8;
    }
    // 0x80002198: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8000219C: lw          $t8, 0x5D24($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5D24);
    // 0x800021A0: nop

    // 0x800021A4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_800021A8:
    // 0x800021A8: jr          $ra
    // 0x800021AC: nop

    return;
    // 0x800021AC: nop

;}
RECOMP_FUNC void debug_render_checkpoints(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BB68: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001BB6C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8001BB70: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8001BB74: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8001BB78: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8001BB7C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001BB80: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001BB84: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001BB88: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8001BB8C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001BB90: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8001BB94: jal         0x8007B4C8
    // 0x8001BB98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    material_set_no_tex_offset(rdram, ctx);
        goto after_0;
    // 0x8001BB98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8001BB9C: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8001BBA0: addiu       $s4, $s4, -0x5130
    ctx->r20 = ADD32(ctx->r20, -0X5130);
    // 0x8001BBA4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8001BBA8: nop

    // 0x8001BBAC: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8001BBB0: bne         $at, $zero, L_8001BC24
    if (ctx->r1 != 0) {
        // 0x8001BBB4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8001BC24;
    }
    // 0x8001BBB4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001BBB8: blez        $v0, L_8001BBF0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001BBBC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001BBF0;
    }
    // 0x8001BBBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001BBC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8001BBC4:
    // 0x8001BBC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001BBC8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8001BBCC: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8001BBD0: jal         0x8001BC40
    // 0x8001BBD4: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    debug_render_checkpoint_node(rdram, ctx);
        goto after_1;
    // 0x8001BBD4: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_1:
    // 0x8001BBD8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8001BBDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001BBE0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001BBE4: bne         $at, $zero, L_8001BBC4
    if (ctx->r1 != 0) {
        // 0x8001BBE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001BBC4;
    }
    // 0x8001BBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001BBEC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001BBF0:
    // 0x8001BBF0: blez        $v0, L_8001BC20
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001BBF4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001BC20;
    }
    // 0x8001BBF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8001BBF8:
    // 0x8001BBF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001BBFC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8001BC00: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x8001BC04: jal         0x8001BC40
    // 0x8001BC08: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    debug_render_checkpoint_node(rdram, ctx);
        goto after_2;
    // 0x8001BC08: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_2:
    // 0x8001BC0C: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x8001BC10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001BC14: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001BC18: bne         $at, $zero, L_8001BBF8
    if (ctx->r1 != 0) {
        // 0x8001BC1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001BBF8;
    }
    // 0x8001BC1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8001BC20:
    // 0x8001BC20: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8001BC24:
    // 0x8001BC24: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001BC28: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8001BC2C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8001BC30: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8001BC34: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8001BC38: jr          $ra
    // 0x8001BC3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8001BC3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void trophyround_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098754: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80098758: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009875C: jal         0x800C422C
    // 0x80098760: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x80098760: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80098764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009876C: jr          $ra
    // 0x80098770: nop

    return;
    // 0x80098770: nop

;}
RECOMP_FUNC void obj_init_skycontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CF58: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CF5C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003CF60: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003CF64: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CF68: nop

    // 0x8003CF6C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003CF70: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x8003CF74: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CF78: nop

    // 0x8003CF7C: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003CF80: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x8003CF84: nop

    // 0x8003CF88: sw          $t1, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r9;
    // 0x8003CF8C: lbu         $t2, 0x9($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X9);
    // 0x8003CF90: jr          $ra
    // 0x8003CF94: sw          $t2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r10;
    return;
    // 0x8003CF94: sw          $t2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void mtxf_from_translation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800705F8: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800705FC: addiu       $t1, $t0, 0x40
    ctx->r9 = ADD32(ctx->r8, 0X40);
L_80070600:
    // 0x80070600: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80070604: bne         $t1, $t0, L_80070600
    if (ctx->r9 != ctx->r8) {
        // 0x80070608: sw          $zero, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = 0;
            goto L_80070600;
    }
    // 0x80070608: sw          $zero, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = 0;
    // 0x8007060C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80070610: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80070614: nop

    // 0x80070618: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x8007061C: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x80070620: swc1        $f18, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f18.u32l;
    // 0x80070624: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x80070628: sw          $a1, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r5;
    // 0x8007062C: sw          $a2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r6;
    // 0x80070630: jr          $ra
    // 0x80070634: sw          $a3, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r7;
    return;
    // 0x80070634: sw          $a3, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void obj_loop_torch_mist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034B4C: lw          $t7, 0x78($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X78);
    // 0x80034B50: lh          $t6, 0x18($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X18);
    // 0x80034B54: multu       $t7, $a1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80034B58: mflo        $t8
    ctx->r24 = lo;
    // 0x80034B5C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80034B60: jr          $ra
    // 0x80034B64: sh          $t9, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r25;
    return;
    // 0x80034B64: sh          $t9, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void sound_jingle_tempo_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800017D4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800017D8: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800017DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800017E0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800017E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800017E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800017EC: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800017F0: lwc1        $f16, 0x49EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X49EC);
    // 0x800017F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800017F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800017FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001800: lw          $a0, -0x39CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39CC);
    // 0x80001804: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80001808: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000180C: nop

    // 0x80001810: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80001814: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001818: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000181C: nop

    // 0x80001820: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80001824: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80001828: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000182C: jal         0x800C79E0
    // 0x80001830: nop

    alCSPSetTempo(rdram, ctx);
        goto after_0;
    // 0x80001830: nop

    after_0:
    // 0x80001834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000183C: jr          $ra
    // 0x80001840: nop

    return;
    // 0x80001840: nop

;}
RECOMP_FUNC void func_80000C68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000C6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80000C70: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80000C74: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000C78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000C7C: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x80000C80: jal         0x80063A90
    // 0x80000C84: nop

    func_80063A90(rdram, ctx);
        goto after_0;
    // 0x80000C84: nop

    after_0:
    // 0x80000C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000C8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000C90: jr          $ra
    // 0x80000C94: nop

    return;
    // 0x80000C94: nop

;}
RECOMP_FUNC void update_camera_hovercraft(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048E64: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80048E68: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x80048E6C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80048E70: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80048E74: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80048E78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80048E7C: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x80048E80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80048E84: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    // 0x80048E88: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80048E8C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80048E90: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80048E94: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x80048E98: jal         0x80066210
    // 0x80048E9C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x80048E9C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80048EA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80048EA4: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80048EA8: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80048EAC: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80048EB0: bne         $v0, $a2, L_80048ED4
    if (ctx->r2 != ctx->r6) {
        // 0x80048EB4: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80048ED4;
    }
    // 0x80048EB4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80048EB8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80048EBC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80048EC0: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x80048EC4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80048EC8: addiu       $t7, $zero, 0x280
    ctx->r15 = ADD32(0, 0X280);
    // 0x80048ECC: b           L_80048EF0
    // 0x80048ED0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_80048EF0;
    // 0x80048ED0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80048ED4:
    // 0x80048ED4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80048ED8: bne         $at, $zero, L_80048EF0
    if (ctx->r1 != 0) {
        // 0x80048EDC: lui         $at, 0x4302
        ctx->r1 = S32(0X4302 << 16);
            goto L_80048EF0;
    }
    // 0x80048EDC: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80048EE0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80048EE4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80048EE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80048EEC: nop

L_80048EF0:
    // 0x80048EF0: addiu       $s0, $s0, -0x2AF8
    ctx->r16 = ADD32(ctx->r16, -0X2AF8);
    // 0x80048EF4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80048EF8: lwc1        $f16, 0xB8($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XB8);
    // 0x80048EFC: lbu         $v0, 0x3B($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X3B);
    // 0x80048F00: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80048F04: beq         $v0, $a2, L_80048F24
    if (ctx->r2 == ctx->r6) {
        // 0x80048F08: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80048F24;
    }
    // 0x80048F08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80048F0C: beq         $v0, $at, L_80048F34
    if (ctx->r2 == ctx->r1) {
        // 0x80048F10: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80048F34;
    }
    // 0x80048F10: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80048F14: beq         $v0, $at, L_80048F54
    if (ctx->r2 == ctx->r1) {
        // 0x80048F18: lui         $at, 0x4254
        ctx->r1 = S32(0X4254 << 16);
            goto L_80048F54;
    }
    // 0x80048F18: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x80048F1C: b           L_80048F88
    // 0x80048F20: lb          $t8, 0x1E4($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1E4);
        goto L_80048F88;
    // 0x80048F20: lb          $t8, 0x1E4($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1E4);
L_80048F24:
    // 0x80048F24: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80048F28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80048F2C: b           L_80048F84
    // 0x80048F30: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
        goto L_80048F84;
    // 0x80048F30: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
L_80048F34:
    // 0x80048F34: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80048F38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80048F3C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80048F40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80048F44: sub.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x80048F48: b           L_80048F84
    // 0x80048F4C: sub.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f8.fl;
        goto L_80048F84;
    // 0x80048F4C: sub.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80048F50: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
L_80048F54:
    // 0x80048F54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80048F58: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80048F5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80048F60: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80048F64: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80048F68: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80048F6C: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x80048F70: sub.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x80048F74: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80048F78: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80048F7C: sub.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80048F80: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_80048F84:
    // 0x80048F84: lb          $t8, 0x1E4($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1E4);
L_80048F88:
    // 0x80048F88: nop

    // 0x80048F8C: bne         $t8, $zero, L_80049044
    if (ctx->r24 != 0) {
        // 0x80048F90: nop
    
            goto L_80049044;
    }
    // 0x80048F90: nop

    // 0x80048F94: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80048F98: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80048F9C: lh          $v0, 0x2($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X2);
    // 0x80048FA0: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80048FA4: blez        $v0, L_80048FC8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80048FA8: nop
    
            goto L_80048FC8;
    }
    // 0x80048FA8: nop

    // 0x80048FAC: addiu       $v0, $v0, -0x61C
    ctx->r2 = ADD32(ctx->r2, -0X61C);
    // 0x80048FB0: bgez        $v0, L_80048FC0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80048FB4: sra         $t0, $v0, 1
        ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80048FC0;
    }
    // 0x80048FB4: sra         $t0, $v0, 1
    ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80048FB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80048FBC: sra         $t0, $v0, 1
    ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
L_80048FC0:
    // 0x80048FC0: b           L_80048FD8
    // 0x80048FC4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_80048FD8;
    // 0x80048FC4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80048FC8:
    // 0x80048FC8: addiu       $v0, $v0, 0x61C
    ctx->r2 = ADD32(ctx->r2, 0X61C);
    // 0x80048FCC: blez        $v0, L_80048FD8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80048FD0: nop
    
            goto L_80048FD8;
    }
    // 0x80048FD0: nop

    // 0x80048FD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80048FD8:
    // 0x80048FD8: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x80048FDC: subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
    // 0x80048FE0: andi        $t2, $a0, 0xFFFF
    ctx->r10 = ctx->r4 & 0XFFFF;
    // 0x80048FE4: subu        $v1, $v0, $t2
    ctx->r3 = SUB32(ctx->r2, ctx->r10);
    // 0x80048FE8: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80048FEC: bne         $at, $zero, L_80048FFC
    if (ctx->r1 != 0) {
        // 0x80048FF0: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80048FFC;
    }
    // 0x80048FF0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80048FF4: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80048FF8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80048FFC:
    // 0x80048FFC: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80049000: beq         $at, $zero, L_8004900C
    if (ctx->r1 == 0) {
        // 0x80049004: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004900C;
    }
    // 0x80049004: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80049008: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004900C:
    // 0x8004900C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80049010: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80049014: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80049018: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004901C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80049020: nop

    // 0x80049024: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80049028: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x8004902C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80049030: multu       $v1, $t4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80049034: mflo        $t5
    ctx->r13 = lo;
    // 0x80049038: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8004903C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80049040: sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
L_80049044:
    // 0x80049044: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x80049048: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x8004904C: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x80049050: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80049054: jal         0x80066210
    // 0x80049058: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    cam_get_viewport_layout(rdram, ctx);
        goto after_1;
    // 0x80049058: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8004905C: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80049060: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80049064: lwc1        $f0, 0x2C($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x80049068: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8004906C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80049070: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x80049074: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80049078: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004907C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80049080: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80049084: bc1f        L_800490D4
    if (!c1cs) {
        // 0x80049088: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_800490D4;
    }
    // 0x80049088: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8004908C: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80049090: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80049094: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80049098: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004909C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800490A0: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800490A4: lwc1        $f11, 0x6498($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6498);
    // 0x800490A8: lwc1        $f10, 0x649C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X649C);
    // 0x800490AC: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x800490B0: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800490B4: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x800490B8: nop

    // 0x800490BC: bc1f        L_800490CC
    if (!c1cs) {
        // 0x800490C0: nop
    
            goto L_800490CC;
    }
    // 0x800490C0: nop

    // 0x800490C4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800490C8: nop

L_800490CC:
    // 0x800490CC: sub.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800490D0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_800490D4:
    // 0x800490D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800490D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800490DC: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800490E0: lw          $t8, -0x2AC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AC0);
    // 0x800490E4: nop

    // 0x800490E8: bne         $t8, $zero, L_8004913C
    if (ctx->r24 != 0) {
        // 0x800490EC: add.s       $f14, $f14, $f8
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
            goto L_8004913C;
    }
    // 0x800490EC: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x800490F0: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x800490F4: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x800490F8: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x800490FC: jal         0x8000C8B4
    // 0x80049100: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    normalise_time(rdram, ctx);
        goto after_2;
    // 0x80049100: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80049104: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80049108: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8004910C: lb          $v1, 0x1D3($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1D3);
    // 0x80049110: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80049114: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80049118: beq         $at, $zero, L_8004912C
    if (ctx->r1 == 0) {
        // 0x8004911C: lui         $at, 0xC1F0
        ctx->r1 = S32(0XC1F0 << 16);
            goto L_8004912C;
    }
    // 0x8004911C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80049120: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80049124: b           L_8004913C
    // 0x80049128: nop

        goto L_8004913C;
    // 0x80049128: nop

L_8004912C:
    // 0x8004912C: blez        $v1, L_8004913C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80049130: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8004913C;
    }
    // 0x80049130: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80049134: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80049138: nop

L_8004913C:
    // 0x8004913C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80049140: lw          $t9, -0x2AC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AC0);
    // 0x80049144: nop

    // 0x80049148: slti        $at, $t9, 0x51
    ctx->r1 = SIGNED(ctx->r25) < 0X51 ? 1 : 0;
    // 0x8004914C: bne         $at, $zero, L_8004916C
    if (ctx->r1 != 0) {
        // 0x80049150: nop
    
            goto L_8004916C;
    }
    // 0x80049150: nop

    // 0x80049154: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80049158: nop

    // 0x8004915C: swc1        $f14, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f14.u32l;
    // 0x80049160: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80049164: nop

    // 0x80049168: swc1        $f18, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f18.u32l;
L_8004916C:
    // 0x8004916C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80049170: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80049174: lwc1        $f0, 0x1C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80049178: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x8004917C: sub.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80049180: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80049184: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80049188: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x8004918C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80049190: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x80049194: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80049198: swc1        $f6, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f6.u32l;
    // 0x8004919C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800491A0: nop

    // 0x800491A4: lwc1        $f2, 0x20($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800491A8: nop

    // 0x800491AC: sub.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800491B0: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x800491B4: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x800491B8: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x800491BC: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x800491C0: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x800491C4: swc1        $f4, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f4.u32l;
    // 0x800491C8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800491CC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800491D0: lh          $t3, 0x2($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X2);
    // 0x800491D4: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x800491D8: subu        $a0, $t3, $t4
    ctx->r4 = SUB32(ctx->r11, ctx->r12);
    // 0x800491DC: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800491E0: jal         0x800707C4
    // 0x800491E4: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    sins_f(rdram, ctx);
        goto after_3;
    // 0x800491E4: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_3:
    // 0x800491E8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800491EC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800491F0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800491F4: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x800491F8: nop

    // 0x800491FC: subu        $a0, $t8, $t9
    ctx->r4 = SUB32(ctx->r24, ctx->r25);
    // 0x80049200: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x80049204: jal         0x800707F8
    // 0x80049208: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    coss_f(rdram, ctx);
        goto after_4;
    // 0x80049208: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    after_4:
    // 0x8004920C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80049210: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80049214: lwc1        $f10, 0x1C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80049218: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8004921C: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80049220: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80049224: ori         $t3, $zero, 0x8000
    ctx->r11 = 0 | 0X8000;
    // 0x80049228: lh          $t2, 0x196($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X196);
    // 0x8004922C: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80049230: subu        $a0, $t3, $t2
    ctx->r4 = SUB32(ctx->r11, ctx->r10);
    // 0x80049234: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x80049238: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8004923C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80049240: jal         0x800707C4
    // 0x80049244: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    sins_f(rdram, ctx);
        goto after_5;
    // 0x80049244: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x80049248: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8004924C: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80049250: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80049254: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x80049258: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004925C: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x80049260: lh          $t7, 0x196($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X196);
    // 0x80049264: nop

    // 0x80049268: subu        $a0, $t8, $t7
    ctx->r4 = SUB32(ctx->r24, ctx->r15);
    // 0x8004926C: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80049270: jal         0x800707F8
    // 0x80049274: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    coss_f(rdram, ctx);
        goto after_6;
    // 0x80049274: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_6:
    // 0x80049278: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8004927C: lh          $t3, -0x2A7A($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X2A7A);
    // 0x80049280: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80049284: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80049288: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004928C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80049290: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80049294: lwc1        $f8, 0x1C($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x80049298: lui         $at, 0x4620
    ctx->r1 = S32(0X4620 << 16);
    // 0x8004929C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800492A0: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800492A4: nop

    // 0x800492A8: div.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800492AC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800492B0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800492B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800492B8: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800492BC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800492C0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800492C4: sub.d       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f6.d - ctx->f10.d;
    // 0x800492C8: lwc1        $f6, 0x38($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X38);
    // 0x800492CC: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
    // 0x800492D0: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800492D4: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800492D8: nop

    // 0x800492DC: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800492E0: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800492E4: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x800492E8: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
    // 0x800492EC: lwc1        $f6, 0x30($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X30);
    // 0x800492F0: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800492F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800492F8: lwc1        $f12, 0xC8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x800492FC: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80049300: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80049304: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80049308: lh          $a0, 0x196($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X196);
    // 0x8004930C: mul.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80049310: sub.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80049314: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80049318: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x8004931C: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80049320: sll         $t2, $a0, 16
    ctx->r10 = S32(ctx->r4 << 16);
    // 0x80049324: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80049328: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8004932C: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x80049330: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80049334: sub.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d - ctx->f10.d;
    // 0x80049338: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8004933C: swc1        $f6, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f6.u32l;
    // 0x80049340: jal         0x800707C4
    // 0x80049344: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    sins_f(rdram, ctx);
        goto after_7;
    // 0x80049344: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x80049348: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x8004934C: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80049350: lwc1        $f8, 0xC8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x80049354: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80049358: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8004935C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80049360: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80049364: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80049368: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8004936C: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80049370: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80049374: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80049378: swc1        $f8, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f8.u32l;
    // 0x8004937C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80049380: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80049384: lwc1        $f12, 0x10($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80049388: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8004938C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80049390: sub.s       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x80049394: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80049398: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8004939C: nop

    // 0x800493A0: bc1f        L_800493C0
    if (!c1cs) {
        // 0x800493A4: nop
    
            goto L_800493C0;
    }
    // 0x800493A4: nop

    // 0x800493A8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800493AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800493B0: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800493B4: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800493B8: b           L_8004941C
    // 0x800493BC: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
        goto L_8004941C;
    // 0x800493BC: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
L_800493C0:
    // 0x800493C0: lw          $t6, -0x2AC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AC4);
    // 0x800493C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800493C8: bne         $t6, $at, L_800493E8
    if (ctx->r14 != ctx->r1) {
        // 0x800493CC: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_800493E8;
    }
    // 0x800493CC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800493D0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800493D4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800493D8: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800493DC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800493E0: b           L_80049400
    // 0x800493E4: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
        goto L_80049400;
    // 0x800493E4: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_800493E8:
    // 0x800493E8: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x800493EC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800493F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800493F4: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x800493F8: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800493FC: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
L_80049400:
    // 0x80049400: lb          $t8, 0x1D3($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1D3);
    // 0x80049404: nop

    // 0x80049408: beq         $t8, $zero, L_8004941C
    if (ctx->r24 == 0) {
        // 0x8004940C: nop
    
            goto L_8004941C;
    }
    // 0x8004940C: nop

    // 0x80049410: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80049414: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x80049418: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_8004941C:
    // 0x8004941C: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80049420: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80049424: swc1        $f4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f4.u32l;
    // 0x80049428: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8004942C: nop

    // 0x80049430: sh          $zero, 0x4($t7)
    MEM_H(0X4, ctx->r15) = 0;
    // 0x80049434: lw          $t9, -0x2AC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AC0);
    // 0x80049438: nop

    // 0x8004943C: beq         $t9, $zero, L_80049454
    if (ctx->r25 == 0) {
        // 0x80049440: nop
    
            goto L_80049454;
    }
    // 0x80049440: nop

    // 0x80049444: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80049448: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8004944C: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80049450: swc1        $f8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f8.u32l;
L_80049454:
    // 0x80049454: lh          $a0, 0x196($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X196);
    // 0x80049458: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x8004945C: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x80049460: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x80049464: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80049468: jal         0x800707F8
    // 0x8004946C: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    coss_f(rdram, ctx);
        goto after_8;
    // 0x8004946C: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    after_8:
    // 0x80049470: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80049474: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80049478: lwc1        $f10, 0x14($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X14);
    // 0x8004947C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80049480: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80049484: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80049488: swc1        $f4, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f4.u32l;
    // 0x8004948C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80049490: lh          $t5, 0x196($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X196);
    // 0x80049494: nop

    // 0x80049498: sh          $t5, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r13;
    // 0x8004949C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800494A0: nop

    // 0x800494A4: lwc1        $f12, 0xC($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800494A8: lwc1        $f14, 0x10($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800494AC: lw          $a2, 0x14($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X14);
    // 0x800494B0: jal         0x80029F18
    // 0x800494B4: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_9;
    // 0x800494B4: nop

    after_9:
    // 0x800494B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800494BC: beq         $v0, $at, L_800494D4
    if (ctx->r2 == ctx->r1) {
        // 0x800494C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800494D4;
    }
    // 0x800494C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800494C4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800494C8: nop

    // 0x800494CC: sh          $v0, 0x34($t8)
    MEM_H(0X34, ctx->r24) = ctx->r2;
    // 0x800494D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800494D4:
    // 0x800494D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800494D8: jr          $ra
    // 0x800494DC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800494DC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void tex_palette_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EF64: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007EF68: lw          $t8, 0x632C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X632C);
    // 0x8007EF6C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8007EF70: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8007EF74: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8007EF78: jr          $ra
    // 0x8007EF7C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    return;
    // 0x8007EF7C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
;}
RECOMP_FUNC void func_8002F2AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F2AC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002F2B0: lw          $v1, -0x4EE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4EE8);
    // 0x8002F2B4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002F2B8: blez        $v1, L_8002F35C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002F2BC: addiu       $a0, $t6, -0x4EE0
        ctx->r4 = ADD32(ctx->r14, -0X4EE0);
            goto L_8002F35C;
    }
    // 0x8002F2BC: addiu       $a0, $t6, -0x4EE0
    ctx->r4 = ADD32(ctx->r14, -0X4EE0);
    // 0x8002F2C0: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x8002F2C4: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x8002F2C8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8002F2CC: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8002F2D0: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x8002F2D4: lwc1        $f18, -0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, -0X10);
    // 0x8002F2D8: beq         $at, $zero, L_8002F328
    if (ctx->r1 == 0) {
        // 0x8002F2DC: nop
    
            goto L_8002F328;
    }
    // 0x8002F2DC: nop

L_8002F2E0:
    // 0x8002F2E0: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F2E4: lwc1        $f14, -0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, -0X8);
    // 0x8002F2E8: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8002F2EC: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002F2F0: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002F2F4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002F2F8: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8002F2FC: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002F300: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8002F304: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x8002F308: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8002F30C: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8002F310: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8002F314: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x8002F318: nop

    // 0x8002F31C: div.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8002F320: bne         $at, $zero, L_8002F2E0
    if (ctx->r1 != 0) {
        // 0x8002F324: swc1        $f8, -0x1C($a0)
        MEM_W(-0X1C, ctx->r4) = ctx->f8.u32l;
            goto L_8002F2E0;
    }
    // 0x8002F324: swc1        $f8, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = ctx->f8.u32l;
L_8002F328:
    // 0x8002F328: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F32C: lwc1        $f14, -0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, -0X8);
    // 0x8002F330: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8002F334: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002F338: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002F33C: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002F340: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8002F344: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8002F348: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8002F34C: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x8002F350: nop

    // 0x8002F354: div.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8002F358: swc1        $f8, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->f8.u32l;
L_8002F35C:
    // 0x8002F35C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002F360: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002F364: addiu       $t0, $t0, -0x4CD0
    ctx->r8 = ADD32(ctx->r8, -0X4CD0);
    // 0x8002F368: addiu       $a1, $a1, -0x4CE0
    ctx->r5 = ADD32(ctx->r5, -0X4CE0);
    // 0x8002F36C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8002F370:
    // 0x8002F370: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x8002F374: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002F378: blez        $a2, L_8002F42C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8002F37C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8002F42C;
    }
    // 0x8002F37C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8002F380: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002F384: addiu       $t9, $t9, -0x4CD0
    ctx->r25 = ADD32(ctx->r25, -0X4CD0);
    // 0x8002F388: sll         $t8, $v0, 5
    ctx->r24 = S32(ctx->r2 << 5);
    // 0x8002F38C: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x8002F390: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002F394: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002F398: lw          $v0, 0xC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC);
    // 0x8002F39C: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002F3A0: beq         $at, $zero, L_8002F3F4
    if (ctx->r1 == 0) {
        // 0x8002F3A4: nop
    
            goto L_8002F3F4;
    }
    // 0x8002F3A4: nop

L_8002F3A8:
    // 0x8002F3A8: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F3AC: lwc1        $f14, 0x8($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002F3B0: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8002F3B4: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002F3B8: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002F3BC: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002F3C0: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8002F3C4: lwc1        $f18, 0x20($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X20);
    // 0x8002F3C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002F3CC: lw          $v0, 0x2C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X2C);
    // 0x8002F3D0: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8002F3D4: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002F3D8: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8002F3DC: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x8002F3E0: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x8002F3E4: nop

    // 0x8002F3E8: div.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8002F3EC: bne         $at, $zero, L_8002F3A8
    if (ctx->r1 != 0) {
        // 0x8002F3F0: swc1        $f8, -0x1C($a3)
        MEM_W(-0X1C, ctx->r7) = ctx->f8.u32l;
            goto L_8002F3A8;
    }
    // 0x8002F3F0: swc1        $f8, -0x1C($a3)
    MEM_W(-0X1C, ctx->r7) = ctx->f8.u32l;
L_8002F3F4:
    // 0x8002F3F4: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002F3F8: lwc1        $f14, 0x8($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002F3FC: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8002F400: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002F404: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002F408: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002F40C: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8002F410: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x8002F414: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8002F418: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8002F41C: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x8002F420: nop

    // 0x8002F424: div.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8002F428: swc1        $f8, -0x1C($a3)
    MEM_W(-0X1C, ctx->r7) = ctx->f8.u32l;
L_8002F42C:
    // 0x8002F42C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8002F430: bne         $a1, $t0, L_8002F370
    if (ctx->r5 != ctx->r8) {
        // 0x8002F434: addiu       $a0, $a0, 0x20
        ctx->r4 = ADD32(ctx->r4, 0X20);
            goto L_8002F370;
    }
    // 0x8002F434: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8002F438: jr          $ra
    // 0x8002F43C: nop

    return;
    // 0x8002F43C: nop

;}
RECOMP_FUNC void load_level_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DB3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006DB40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006DB44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006DB48: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006DB4C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006DB50: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006DB54: jal         0x800710B0
    // 0x8006DB58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_0;
    // 0x8006DB58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8006DB5C: jal         0x80065EA0
    // 0x8006DB60: nop

    cam_init(rdram, ctx);
        goto after_1;
    // 0x8006DB60: nop

    after_1:
    // 0x8006DB64: jal         0x800C3048
    // 0x8006DB68: nop

    load_game_text_table(rdram, ctx);
        goto after_2;
    // 0x8006DB68: nop

    after_2:
    // 0x8006DB6C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8006DB70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006DB74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8006DB78: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8006DB7C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8006DB80: jal         0x8006B250
    // 0x8006DB84: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    level_load(rdram, ctx);
        goto after_3;
    // 0x8006DB84: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x8006DB88: jal         0x80066210
    // 0x8006DB8C: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_4;
    // 0x8006DB8C: nop

    after_4:
    // 0x8006DB90: jal         0x8009ECF0
    // 0x8006DB94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    hud_init(rdram, ctx);
        goto after_5;
    // 0x8006DB94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8006DB98: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x8006DB9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8006DBA0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8006DBA4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8006DBA8: addiu       $a2, $zero, 0x6E
    ctx->r6 = ADD32(0, 0X6E);
    // 0x8006DBAC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x8006DBB0: jal         0x800AE728
    // 0x8006DBB4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    init_particle_buffers(rdram, ctx);
        goto after_6;
    // 0x8006DBB4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_6:
    // 0x8006DBB8: jal         0x8001BF20
    // 0x8006DBBC: nop

    ainode_update(rdram, ctx);
        goto after_7;
    // 0x8006DBBC: nop

    after_7:
    // 0x8006DBC0: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8006DBC4: jal         0x800CD260
    // 0x8006DBC8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    osSetTime_recomp(rdram, ctx);
        goto after_8;
    // 0x8006DBC8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x8006DBCC: jal         0x800710B0
    // 0x8006DBD0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_9;
    // 0x8006DBD0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_9:
    // 0x8006DBD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DBD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006DBDC: jr          $ra
    // 0x8006DBE0: nop

    return;
    // 0x8006DBE0: nop

;}
RECOMP_FUNC void alSynAddPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C93D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C93D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C93D8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C93DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800C93E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C93E4: jal         0x800C9A30
    // 0x800C93E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C93E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C93EC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800C93F0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800C93F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C93F8: lw          $t6, 0x20($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X20);
    // 0x800C93FC: sw          $t6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r14;
    // 0x800C9400: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800C9404: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800C9408: jal         0x800C9A30
    // 0x800C940C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800C940C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    after_1:
    // 0x800C9410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9418: jr          $ra
    // 0x800C941C: nop

    return;
    // 0x800C941C: nop

;}
RECOMP_FUNC void level_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BEFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BF00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BF04: jal         0x8006C164
    // 0x8006BF08: nop

    aitable_free(rdram, ctx);
        goto after_0;
    // 0x8006BF08: nop

    after_0:
    // 0x8006BF0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006BF10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006BF14: jal         0x80077B34
    // 0x8006BF18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bgdraw_primcolour(rdram, ctx);
        goto after_1;
    // 0x8006BF18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8006BF1C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006BF20: lw          $a0, 0x1168($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1168);
    // 0x8006BF24: jal         0x80071140
    // 0x8006BF28: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x8006BF28: nop

    after_2:
    // 0x8006BF2C: jal         0x800049D8
    // 0x8006BF30: nop

    sndp_stop_all_looped(rdram, ctx);
        goto after_3;
    // 0x8006BF30: nop

    after_3:
    // 0x8006BF34: jal         0x80001844
    // 0x8006BF38: nop

    music_stop(rdram, ctx);
        goto after_4;
    // 0x8006BF38: nop

    after_4:
    // 0x8006BF3C: jal         0x800018E0
    // 0x8006BF40: nop

    music_jingle_stop(rdram, ctx);
        goto after_5;
    // 0x8006BF40: nop

    after_5:
    // 0x8006BF44: jal         0x800012E8
    // 0x8006BF48: nop

    music_channel_reset_all(rdram, ctx);
        goto after_6;
    // 0x8006BF48: nop

    after_6:
    // 0x8006BF4C: jal         0x80031B60
    // 0x8006BF50: nop

    lights_free(rdram, ctx);
        goto after_7;
    // 0x8006BF50: nop

    after_7:
    // 0x8006BF54: jal         0x8002C7D4
    // 0x8006BF58: nop

    free_track(rdram, ctx);
        goto after_8;
    // 0x8006BF58: nop

    after_8:
    // 0x8006BF5C: jal         0x80008174
    // 0x8006BF60: nop

    audspat_reset(rdram, ctx);
        goto after_9;
    // 0x8006BF60: nop

    after_9:
    // 0x8006BF64: jal         0x80000968
    // 0x8006BF68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_change(rdram, ctx);
        goto after_10;
    // 0x8006BF68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x8006BF6C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006BF70: lw          $v0, 0x1168($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1168);
    // 0x8006BF74: nop

    // 0x8006BF78: lh          $t6, 0x90($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X90);
    // 0x8006BF7C: nop

    // 0x8006BF80: blez        $t6, L_8006BF9C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8006BF84: nop
    
            goto L_8006BF9C;
    }
    // 0x8006BF84: nop

    // 0x8006BF88: jal         0x800AB35C
    // 0x8006BF8C: nop

    weather_free(rdram, ctx);
        goto after_11;
    // 0x8006BF8C: nop

    after_11:
    // 0x8006BF90: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006BF94: lw          $v0, 0x1168($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1168);
    // 0x8006BF98: nop

L_8006BF9C:
    // 0x8006BF9C: lb          $t7, 0x49($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X49);
    // 0x8006BFA0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006BFA4: bne         $t7, $at, L_8006BFBC
    if (ctx->r15 != ctx->r1) {
        // 0x8006BFA8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006BFBC;
    }
    // 0x8006BFA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BFAC: lw          $a0, 0xA4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XA4);
    // 0x8006BFB0: jal         0x8007B2BC
    // 0x8006BFB4: nop

    tex_free(rdram, ctx);
        goto after_12;
    // 0x8006BFB4: nop

    after_12:
    // 0x8006BFB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006BFBC:
    // 0x8006BFBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BFC0: jr          $ra
    // 0x8006BFC4: nop

    return;
    // 0x8006BFC4: nop

;}
RECOMP_FUNC void obj_loop_gbparkwarden(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003ACA0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003ACA4: jr          $ra
    // 0x8003ACA8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003ACA8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void sound_update_queue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000D00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80000D04: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80000D08: addiu       $a1, $a1, 0x5D3C
    ctx->r5 = ADD32(ctx->r5, 0X5D3C);
    // 0x80000D0C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80000D10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80000D14: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x80000D18: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80000D1C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80000D20: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80000D24: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80000D28: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80000D2C: blez        $v1, L_80000DBC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80000D30: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_80000DBC;
    }
    // 0x80000D30: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80000D34: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80000D38: addiu       $v0, $v0, 0x5D38
    ctx->r2 = ADD32(ctx->r2, 0X5D38);
    // 0x80000D3C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80000D40: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80000D44: addu        $t8, $t6, $s0
    ctx->r24 = ADD32(ctx->r14, ctx->r16);
    // 0x80000D48: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80000D4C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80000D50: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000D54: addiu       $a0, $a0, -0x39B0
    ctx->r4 = ADD32(ctx->r4, -0X39B0);
    // 0x80000D58: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80000D5C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80000D60: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80000D64: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80000D68: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80000D6C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80000D70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80000D74: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x80000D78: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80000D7C: nop

    // 0x80000D80: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80000D84: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x80000D88: nop

    // 0x80000D8C: bc1f        L_80000DA4
    if (!c1cs) {
        // 0x80000D90: nop
    
            goto L_80000DA4;
    }
    // 0x80000D90: nop

    // 0x80000D94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80000D98: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80000D9C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80000DA0: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
L_80000DA4:
    // 0x80000DA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000DA8: lbu         $a0, -0x39C8($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X39C8);
    // 0x80000DAC: jal         0x80001990
    // 0x80000DB0: nop

    music_volume_set(rdram, ctx);
        goto after_0;
    // 0x80000DB0: nop

    after_0:
    // 0x80000DB4: b           L_80000E44
    // 0x80000DB8: nop

        goto L_80000E44;
    // 0x80000DB8: nop

L_80000DBC:
    // 0x80000DBC: bgez        $v1, L_80000E44
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80000DC0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80000E44;
    }
    // 0x80000DC0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80000DC4: addiu       $v0, $v0, 0x5D38
    ctx->r2 = ADD32(ctx->r2, 0X5D38);
    // 0x80000DC8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80000DCC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80000DD0: subu        $t1, $t9, $s0
    ctx->r9 = SUB32(ctx->r25, ctx->r16);
    // 0x80000DD4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80000DD8: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80000DDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80000DE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80000DE4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80000DE8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000DEC: addiu       $a0, $a0, -0x39B0
    ctx->r4 = ADD32(ctx->r4, -0X39B0);
    // 0x80000DF0: div.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80000DF4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80000DF8: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80000DFC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80000E00: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80000E04: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80000E08: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80000E0C: nop

    // 0x80000E10: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80000E14: c.lt.d      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.d < ctx->f18.d;
    // 0x80000E18: nop

    // 0x80000E1C: bc1f        L_80000E34
    if (!c1cs) {
        // 0x80000E20: nop
    
            goto L_80000E34;
    }
    // 0x80000E20: nop

    // 0x80000E24: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80000E28: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80000E2C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80000E30: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
L_80000E34:
    // 0x80000E34: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000E38: lbu         $a0, -0x39C8($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X39C8);
    // 0x80000E3C: jal         0x80001990
    // 0x80000E40: nop

    music_volume_set(rdram, ctx);
        goto after_1;
    // 0x80000E40: nop

    after_1:
L_80000E44:
    // 0x80000E44: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80000E48: addiu       $s3, $s3, -0x39A8
    ctx->r19 = ADD32(ctx->r19, -0X39A8);
    // 0x80000E4C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80000E50: nop

    // 0x80000E54: blez        $v0, L_80000EFC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80000E58: nop
    
            goto L_80000EFC;
    }
    // 0x80000E58: nop

    // 0x80000E5C: blez        $v0, L_80000EFC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80000E60: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80000EFC;
    }
    // 0x80000E60: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80000E64: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80000E68: addiu       $s1, $s1, 0x5D48
    ctx->r17 = ADD32(ctx->r17, 0X5D48);
    // 0x80000E6C: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
L_80000E70:
    // 0x80000E70: lh          $t2, 0x2($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X2);
    // 0x80000E74: nop

    // 0x80000E78: subu        $t3, $t2, $s4
    ctx->r11 = SUB32(ctx->r10, ctx->r20);
    // 0x80000E7C: sh          $t3, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r11;
    // 0x80000E80: lh          $t4, 0x2($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X2);
    // 0x80000E84: nop

    // 0x80000E88: bgtz        $t4, L_80000EE8
    if (SIGNED(ctx->r12) > 0) {
        // 0x80000E8C: nop
    
            goto L_80000EE8;
    }
    // 0x80000E8C: nop

    // 0x80000E90: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x80000E94: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x80000E98: jal         0x80001D04
    // 0x80000E9C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80000E9C: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    after_2:
    // 0x80000EA0: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80000EA4: nop

    // 0x80000EA8: addiu       $v0, $t5, -0x1
    ctx->r2 = ADD32(ctx->r13, -0X1);
    // 0x80000EAC: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80000EB0: beq         $at, $zero, L_80000EF0
    if (ctx->r1 == 0) {
        // 0x80000EB4: sw          $v0, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->r2;
            goto L_80000EF0;
    }
    // 0x80000EB4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80000EB8: lhu         $t7, 0x8($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X8);
    // 0x80000EBC: lh          $t8, 0xA($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XA);
    // 0x80000EC0: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x80000EC4: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
    // 0x80000EC8: sh          $t8, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r24;
    // 0x80000ECC: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x80000ED0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80000ED4:
    // 0x80000ED4: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80000ED8: bne         $at, $zero, L_80000ED4
    if (ctx->r1 != 0) {
        // 0x80000EDC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80000ED4;
    }
    // 0x80000EDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80000EE0: b           L_80000EF4
    // 0x80000EE4: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
        goto L_80000EF4;
    // 0x80000EE4: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
L_80000EE8:
    // 0x80000EE8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80000EEC: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_80000EF0:
    // 0x80000EF0: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
L_80000EF4:
    // 0x80000EF4: bne         $at, $zero, L_80000E70
    if (ctx->r1 != 0) {
        // 0x80000EF8: nop
    
            goto L_80000E70;
    }
    // 0x80000EF8: nop

L_80000EFC:
    // 0x80000EFC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80000F00: addiu       $s0, $s0, -0x39D0
    ctx->r16 = ADD32(ctx->r16, -0X39D0);
    // 0x80000F04: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80000F08: lw          $a1, 0x5CFC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5CFC);
    // 0x80000F0C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80000F10: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80000F14: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80000F18: addiu       $a3, $a3, 0x5D88
    ctx->r7 = ADD32(ctx->r7, 0X5D88);
    // 0x80000F1C: jal         0x8000232C
    // 0x80000F20: addiu       $a2, $a2, -0x39A4
    ctx->r6 = ADD32(ctx->r6, -0X39A4);
    music_sequence_init(rdram, ctx);
        goto after_3;
    // 0x80000F20: addiu       $a2, $a2, -0x39A4
    ctx->r6 = ADD32(ctx->r6, -0X39A4);
    after_3:
    // 0x80000F24: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000F28: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80000F2C: lw          $a1, 0x5D00($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5D00);
    // 0x80000F30: lw          $a0, -0x39CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39CC);
    // 0x80000F34: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80000F38: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80000F3C: addiu       $a3, $a3, 0x5E80
    ctx->r7 = ADD32(ctx->r7, 0X5E80);
    // 0x80000F40: jal         0x8000232C
    // 0x80000F44: addiu       $a2, $a2, -0x39A0
    ctx->r6 = ADD32(ctx->r6, -0X39A0);
    music_sequence_init(rdram, ctx);
        goto after_4;
    // 0x80000F44: addiu       $a2, $a2, -0x39A0
    ctx->r6 = ADD32(ctx->r6, -0X39A0);
    after_4:
    // 0x80000F48: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80000F4C: addiu       $s1, $s1, 0x5D30
    ctx->r17 = ADD32(ctx->r17, 0X5D30);
    // 0x80000F50: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
    // 0x80000F54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80000F58: bne         $t0, $at, L_80000FC0
    if (ctx->r8 != ctx->r1) {
        // 0x80000F5C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80000FC0;
    }
    // 0x80000F5C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80000F60: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80000F64: nop

    // 0x80000F68: lw          $t1, 0x18($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X18);
    // 0x80000F6C: nop

    // 0x80000F70: beq         $t1, $zero, L_80000FC0
    if (ctx->r9 == 0) {
        // 0x80000F74: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80000FC0;
    }
    // 0x80000F74: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80000F78: jal         0x800C7890
    // 0x80000F7C: nop

    alCSPGetTempo(rdram, ctx);
        goto after_5;
    // 0x80000F7C: nop

    after_5:
    // 0x80000F80: lui         $t2, 0x393
    ctx->r10 = S32(0X393 << 16);
    // 0x80000F84: ori         $t2, $t2, 0x8700
    ctx->r10 = ctx->r10 | 0X8700;
    // 0x80000F88: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x80000F8C: bne         $v0, $zero, L_80000F98
    if (ctx->r2 != 0) {
        // 0x80000F90: nop
    
            goto L_80000F98;
    }
    // 0x80000F90: nop

    // 0x80000F94: break       7
    do_break(2147487636);
L_80000F98:
    // 0x80000F98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80000F9C: bne         $v0, $at, L_80000FB0
    if (ctx->r2 != ctx->r1) {
        // 0x80000FA0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80000FB0;
    }
    // 0x80000FA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80000FA4: bne         $t2, $at, L_80000FB0
    if (ctx->r10 != ctx->r1) {
        // 0x80000FA8: nop
    
            goto L_80000FB0;
    }
    // 0x80000FA8: nop

    // 0x80000FAC: break       6
    do_break(2147487660);
L_80000FB0:
    // 0x80000FB0: mflo        $t3
    ctx->r11 = lo;
    // 0x80000FB4: sh          $t3, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r11;
    // 0x80000FB8: nop

    extern void dkr_audio_mix_tick(uint8_t*, recomp_context*); dkr_audio_mix_tick(rdram, ctx);
    // 0x80000FBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80000FC0:
    // 0x80000FC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80000FC4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80000FC8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80000FCC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80000FD0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80000FD4: jr          $ra
    // 0x80000FD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80000FD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void set_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030664: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80030668: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x8003066C: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80030670: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80030674: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80030678: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8003067C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80030680: andi        $t1, $a3, 0xFF
    ctx->r9 = ctx->r7 & 0XFF;
    // 0x80030684: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80030688: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8003068C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80030690: beq         $at, $zero, L_800306B0
    if (ctx->r1 == 0) {
        // 0x80030694: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_800306B0;
    }
    // 0x80030694: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80030698: sll         $a1, $t9, 16
    ctx->r5 = S32(ctx->r25 << 16);
    // 0x8003069C: sll         $a2, $t7, 16
    ctx->r6 = S32(ctx->r15 << 16);
    // 0x800306A0: sra         $t2, $a1, 16
    ctx->r10 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800306A4: sra         $t3, $a2, 16
    ctx->r11 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800306A8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x800306AC: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
L_800306B0:
    // 0x800306B0: slti        $at, $a2, 0x400
    ctx->r1 = SIGNED(ctx->r6) < 0X400 ? 1 : 0;
    // 0x800306B4: bne         $at, $zero, L_800306C0
    if (ctx->r1 != 0) {
        // 0x800306B8: sll         $t5, $a0, 3
        ctx->r13 = S32(ctx->r4 << 3);
            goto L_800306C0;
    }
    // 0x800306B8: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x800306BC: addiu       $a2, $zero, 0x3FF
    ctx->r6 = ADD32(0, 0X3FF);
L_800306C0:
    // 0x800306C0: addiu       $v0, $a2, -0x5
    ctx->r2 = ADD32(ctx->r6, -0X5);
    // 0x800306C4: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800306C8: bne         $at, $zero, L_800306DC
    if (ctx->r1 != 0) {
        // 0x800306CC: subu        $t5, $t5, $a0
        ctx->r13 = SUB32(ctx->r13, ctx->r4);
            goto L_800306DC;
    }
    // 0x800306CC: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800306D0: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x800306D4: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800306D8: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
L_800306DC:
    // 0x800306DC: lbu         $v1, 0x13($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X13);
    // 0x800306E0: lbu         $t0, 0x17($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X17);
    // 0x800306E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800306E8: addiu       $t6, $t6, -0x2C78
    ctx->r14 = ADD32(ctx->r14, -0X2C78);
    // 0x800306EC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800306F0: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x800306F4: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x800306F8: sll         $t1, $a1, 16
    ctx->r9 = S32(ctx->r5 << 16);
    // 0x800306FC: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x80030700: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x80030704: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x80030708: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x8003070C: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80030710: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80030714: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x80030718: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x8003071C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80030720: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80030724: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x80030728: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x8003072C: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x80030730: sb          $a3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r7;
    // 0x80030734: sh          $a1, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r5;
    // 0x80030738: sh          $a2, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r6;
    // 0x8003073C: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80030740: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x80030744: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80030748: jr          $ra
    // 0x8003074C: sb          $t0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r8;
    return;
    // 0x8003074C: sb          $t0, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r8;
;}
RECOMP_FUNC void mark_to_write_flap_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EBC4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EBC8: addiu       $v0, $v0, -0x2C84
    ctx->r2 = ADD32(ctx->r2, -0X2C84);
    // 0x8006EBCC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EBD0: nop

    // 0x8006EBD4: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x8006EBD8: jr          $ra
    // 0x8006EBDC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EBDC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void __CSPPostNextSeqEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800629CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800629D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800629D4: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x800629D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800629DC: bne         $t6, $at, L_80062A2C
    if (ctx->r14 != ctx->r1) {
        // 0x800629E0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80062A2C;
    }
    // 0x800629E0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800629E4: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x800629E8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800629EC: beq         $a0, $zero, L_80062A30
    if (ctx->r4 == 0) {
        // 0x800629F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80062A30;
    }
    // 0x800629F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800629F4: jal         0x800C83EC
    // 0x800629F8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    __alCSeqNextDelta(rdram, ctx);
        goto after_0;
    // 0x800629F8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x800629FC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80062A00: beq         $v0, $zero, L_80062A30
    if (ctx->r2 == 0) {
        // 0x80062A04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80062A30;
    }
    // 0x80062A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80062A08: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x80062A0C: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x80062A10: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80062A14: addiu       $a0, $a3, 0x48
    ctx->r4 = ADD32(ctx->r7, 0X48);
    // 0x80062A18: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80062A1C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80062A20: mflo        $a2
    ctx->r6 = lo;
    // 0x80062A24: jal         0x800C91AC
    // 0x80062A28: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x80062A28: nop

    after_1:
L_80062A2C:
    // 0x80062A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80062A30:
    // 0x80062A30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80062A34: jr          $ra
    // 0x80062A38: nop

    return;
    // 0x80062A38: nop

;}
RECOMP_FUNC void obj_loop_animator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800377E4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800377E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800377EC: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x800377F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800377F4: lh          $t0, 0x4($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X4);
    // 0x800377F8: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
    // 0x800377FC: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037800: lh          $t8, 0x8($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X8);
    // 0x80037804: mflo        $t0
    ctx->r8 = lo;
    // 0x80037808: sll         $t6, $t0, 4
    ctx->r14 = S32(ctx->r8 << 4);
    // 0x8003780C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80037810: multu       $t1, $a1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037814: lh          $t6, 0xA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA);
    // 0x80037818: sh          $t9, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r25;
    // 0x8003781C: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
    // 0x80037820: nop

    // 0x80037824: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x80037828: sh          $t8, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r24;
    // 0x8003782C: sra         $t0, $v0, 4
    ctx->r8 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80037830: mflo        $t1
    ctx->r9 = lo;
    // 0x80037834: sll         $t7, $t1, 4
    ctx->r15 = S32(ctx->r9 << 4);
    // 0x80037838: addu        $t7, $t6, $t7
    ctx->r15 = ADD32(ctx->r14, ctx->r15);
    // 0x8003783C: sh          $t7, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r15;
    // 0x80037840: lh          $a2, 0xA($v1)
    ctx->r6 = MEM_H(ctx->r3, 0XA);
    // 0x80037844: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80037848: andi        $t9, $a2, 0xF
    ctx->r25 = ctx->r6 & 0XF;
    // 0x8003784C: sh          $t9, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r25;
    // 0x80037850: beq         $t6, $at, L_80037A08
    if (ctx->r14 == ctx->r1) {
        // 0x80037854: sra         $t1, $a2, 4
        ctx->r9 = S32(SIGNED(ctx->r6) >> 4);
            goto L_80037A08;
    }
    // 0x80037854: sra         $t1, $a2, 4
    ctx->r9 = S32(SIGNED(ctx->r6) >> 4);
    // 0x80037858: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8003785C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80037860: jal         0x8002C7C4
    // 0x80037864: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    get_current_level_model(rdram, ctx);
        goto after_0;
    // 0x80037864: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_0:
    // 0x80037868: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8003786C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80037870: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80037874: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80037878: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8003787C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80037880: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80037884: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80037888: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x8003788C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80037890: lw          $t6, 0xC($t2)
    ctx->r14 = MEM_W(ctx->r10, 0XC);
    // 0x80037894: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x80037898: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8003789C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800378A0: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x800378A4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800378A8: lh          $t4, 0x4($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X4);
    // 0x800378AC: lh          $t3, 0x10($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X10);
    // 0x800378B0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800378B4: beq         $t5, $at, L_80037A0C
    if (ctx->r13 == ctx->r1) {
        // 0x800378B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80037A0C;
    }
    // 0x800378B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800378BC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800378C0: sll         $t8, $t5, 3
    ctx->r24 = S32(ctx->r13 << 3);
    // 0x800378C4: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x800378C8: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    // 0x800378CC: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800378D0: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800378D4: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x800378D8: sll         $a1, $v1, 7
    ctx->r5 = S32(ctx->r3 << 7);
    // 0x800378DC: beq         $at, $zero, L_80037A08
    if (ctx->r1 == 0) {
        // 0x800378E0: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80037A08;
    }
    // 0x800378E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800378E4:
    // 0x800378E4: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x800378E8: sll         $t8, $a2, 4
    ctx->r24 = S32(ctx->r6 << 4);
    // 0x800378EC: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x800378F0: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800378F4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800378F8: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x800378FC: bne         $t7, $zero, L_80037A00
    if (ctx->r15 != 0) {
        // 0x80037900: nop
    
            goto L_80037A00;
    }
    // 0x80037900: nop

    // 0x80037904: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x80037908: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x8003790C: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80037910: beq         $at, $zero, L_8003793C
    if (ctx->r1 == 0) {
        // 0x80037914: sll         $a3, $a0, 1
        ctx->r7 = S32(ctx->r4 << 1);
            goto L_8003793C;
    }
    // 0x80037914: sll         $a3, $a0, 1
    ctx->r7 = S32(ctx->r4 << 1);
    // 0x80037918: subu        $t8, $v1, $a1
    ctx->r24 = SUB32(ctx->r3, ctx->r5);
    // 0x8003791C: lh          $t6, 0xA($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA);
    // 0x80037920: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x80037924: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x80037928: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x8003792C: subu        $t8, $t9, $a1
    ctx->r24 = SUB32(ctx->r25, ctx->r5);
    // 0x80037930: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x80037934: sh          $t7, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r15;
    // 0x80037938: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
L_8003793C:
    // 0x8003793C: bgez        $v1, L_80037960
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80037940: addu        $t6, $v1, $a1
        ctx->r14 = ADD32(ctx->r3, ctx->r5);
            goto L_80037960;
    }
    // 0x80037940: addu        $t6, $v1, $a1
    ctx->r14 = ADD32(ctx->r3, ctx->r5);
    // 0x80037944: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x80037948: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x8003794C: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x80037950: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x80037954: addu        $t6, $t8, $a1
    ctx->r14 = ADD32(ctx->r24, ctx->r5);
    // 0x80037958: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x8003795C: sh          $t6, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r14;
L_80037960:
    // 0x80037960: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80037964: nop

    // 0x80037968: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003796C: beq         $at, $zero, L_80037994
    if (ctx->r1 == 0) {
        // 0x80037970: subu        $t7, $v1, $a0
        ctx->r15 = SUB32(ctx->r3, ctx->r4);
            goto L_80037994;
    }
    // 0x80037970: subu        $t7, $v1, $a0
    ctx->r15 = SUB32(ctx->r3, ctx->r4);
    // 0x80037974: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x80037978: lh          $t6, 0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC);
    // 0x8003797C: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x80037980: subu        $t8, $t9, $a0
    ctx->r24 = SUB32(ctx->r25, ctx->r4);
    // 0x80037984: subu        $t7, $t6, $a0
    ctx->r15 = SUB32(ctx->r14, ctx->r4);
    // 0x80037988: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x8003798C: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
    // 0x80037990: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
L_80037994:
    // 0x80037994: bgez        $v1, L_800379BC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80037998: addu        $t9, $v1, $a0
        ctx->r25 = ADD32(ctx->r3, ctx->r4);
            goto L_800379BC;
    }
    // 0x80037998: addu        $t9, $v1, $a0
    ctx->r25 = ADD32(ctx->r3, ctx->r4);
    // 0x8003799C: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x800379A0: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x800379A4: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x800379A8: addu        $t6, $t8, $a0
    ctx->r14 = ADD32(ctx->r24, ctx->r4);
    // 0x800379AC: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x800379B0: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800379B4: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x800379B8: sh          $t9, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r25;
L_800379BC:
    // 0x800379BC: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x800379C0: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x800379C4: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800379C8: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x800379CC: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x800379D0: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x800379D4: addu        $t6, $t8, $t1
    ctx->r14 = ADD32(ctx->r24, ctx->r9);
    // 0x800379D8: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x800379DC: sh          $t6, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r14;
    // 0x800379E0: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x800379E4: lh          $t6, 0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC);
    // 0x800379E8: addu        $t7, $v1, $t0
    ctx->r15 = ADD32(ctx->r3, ctx->r8);
    // 0x800379EC: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x800379F0: addu        $t8, $t9, $t0
    ctx->r24 = ADD32(ctx->r25, ctx->r8);
    // 0x800379F4: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800379F8: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
    // 0x800379FC: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
L_80037A00:
    // 0x80037A00: bne         $a2, $t3, L_800378E4
    if (ctx->r6 != ctx->r11) {
        // 0x80037A04: nop
    
            goto L_800378E4;
    }
    // 0x80037A04: nop

L_80037A08:
    // 0x80037A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80037A0C:
    // 0x80037A0C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80037A10: jr          $ra
    // 0x80037A14: nop

    return;
    // 0x80037A14: nop

;}
RECOMP_FUNC void filename_trim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800977D0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800977D4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800977D8: beq         $t6, $zero, L_8009786C
    if (ctx->r14 == 0) {
        // 0x800977DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8009786C;
    }
    // 0x800977DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800977E0: lbu         $a2, 0x0($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X0);
    // 0x800977E4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800977E8: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
L_800977EC:
    // 0x800977EC: bne         $t0, $a2, L_80097850
    if (ctx->r8 != ctx->r6) {
        // 0x800977F0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80097850;
    }
    // 0x800977F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800977F4: lbu         $a2, 0x1($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X1);
    // 0x800977F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800977FC: bne         $t0, $a2, L_80097814
    if (ctx->r8 != ctx->r6) {
        // 0x80097800: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80097814;
    }
    // 0x80097800: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80097804:
    // 0x80097804: lbu         $a2, 0x1($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X1);
    // 0x80097808: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009780C: beq         $t0, $a2, L_80097804
    if (ctx->r8 == ctx->r6) {
        // 0x80097810: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80097804;
    }
    // 0x80097810: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80097814:
    // 0x80097814: beq         $a2, $zero, L_80097864
    if (ctx->r6 == 0) {
        // 0x80097818: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80097864;
    }
    // 0x80097818: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8009781C: beq         $at, $zero, L_80097864
    if (ctx->r1 == 0) {
        // 0x80097820: nop
    
            goto L_80097864;
    }
    // 0x80097820: nop

    // 0x80097824: addu        $a2, $v1, $a0
    ctx->r6 = ADD32(ctx->r3, ctx->r4);
L_80097828:
    // 0x80097828: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x8009782C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80097830: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80097834: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80097838: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8009783C: bne         $at, $zero, L_80097828
    if (ctx->r1 != 0) {
        // 0x80097840: sb          $t7, -0x1($a3)
        MEM_B(-0X1, ctx->r7) = ctx->r15;
            goto L_80097828;
    }
    // 0x80097840: sb          $t7, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r15;
    // 0x80097844: lbu         $a2, 0x0($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X0);
    // 0x80097848: b           L_80097864
    // 0x8009784C: nop

        goto L_80097864;
    // 0x8009784C: nop

L_80097850:
    // 0x80097850: sb          $a2, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r6;
    // 0x80097854: lbu         $a2, 0x1($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X1);
    // 0x80097858: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8009785C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80097860: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80097864:
    // 0x80097864: bne         $a2, $zero, L_800977EC
    if (ctx->r6 != 0) {
        // 0x80097868: nop
    
            goto L_800977EC;
    }
    // 0x80097868: nop

L_8009786C:
    // 0x8009786C: jr          $ra
    // 0x80097870: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
    return;
    // 0x80097870: sb          $zero, 0x0($a3)
    MEM_B(0X0, ctx->r7) = 0;
;}
RECOMP_FUNC void postrace_offsets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081E54: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80081E58: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80081E5C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80081E60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081E64: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80081E68: sw          $a0, -0x868($at)
    MEM_W(-0X868, ctx->r1) = ctx->r4;
    // 0x80081E6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081E70: sw          $zero, -0x86C($at)
    MEM_W(-0X86C, ctx->r1) = 0;
    // 0x80081E74: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80081E78: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80081E7C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80081E80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80081E84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80081E88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80081E8C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80081E90: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80081E94: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80081E98: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80081E9C: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80081EA0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80081EA4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80081EA8: addiu       $v0, $v0, 0x6858
    ctx->r2 = ADD32(ctx->r2, 0X6858);
    // 0x80081EAC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80081EB0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80081EB4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80081EB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80081EBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80081EC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081EC4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80081EC8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80081ECC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80081ED0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x80081ED4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80081ED8: sw          $t9, 0x685C($at)
    MEM_W(0X685C, ctx->r1) = ctx->r25;
    // 0x80081EDC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80081EE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081EE4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80081EE8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80081EEC: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80081EF0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80081EF4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80081EF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081EFC: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80081F00: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80081F04: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80081F08: sw          $t1, 0x6860($at)
    MEM_W(0X6860, ctx->r1) = ctx->r9;
    // 0x80081F0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081F10: sw          $zero, 0x6854($at)
    MEM_W(0X6854, ctx->r1) = 0;
    // 0x80081F14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081F18: sw          $t2, -0x864($at)
    MEM_W(-0X864, ctx->r1) = ctx->r10;
    // 0x80081F1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081F20: sw          $t3, -0x860($at)
    MEM_W(-0X860, ctx->r1) = ctx->r11;
    // 0x80081F24: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80081F28: nop

    // 0x80081F2C: blez        $t4, L_80081F40
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80081F30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80081F40;
    }
    // 0x80081F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081F34: jal         0x80001D04
    // 0x80081F38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80081F38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80081F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80081F40:
    // 0x80081F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80081F44: jr          $ra
    // 0x80081F48: nop

    return;
    // 0x80081F48: nop

;}
RECOMP_FUNC void gzip_inflate_codes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7040: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C7044: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x800C7048: sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // 0x800C704C: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x800C7050: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x800C7054: addiu       $t3, $t3, -0x6B74
    ctx->r11 = ADD32(ctx->r11, -0X6B74);
    // 0x800C7058: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800C705C: sll         $t0, $a3, 1
    ctx->r8 = S32(ctx->r7 << 1);
    // 0x800C7060: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800C7064: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800C7068: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C706C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C7070: addu        $v1, $t3, $v0
    ctx->r3 = ADD32(ctx->r11, ctx->r2);
    // 0x800C7074: addu        $t1, $t3, $t0
    ctx->r9 = ADD32(ctx->r11, ctx->r8);
    // 0x800C7078: lw          $s2, 0x3768($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X3768);
    // 0x800C707C: lw          $s1, 0x376C($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X376C);
    // 0x800C7080: lw          $t9, -0x5530($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5530);
    // 0x800C7084: lw          $s0, -0x552C($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X552C);
    // 0x800C7088: lhu         $t5, 0x0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X0);
    // 0x800C708C: lhu         $t4, 0x0($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X0);
L_800C7090:
    // 0x800C7090: sltu        $at, $s0, $a2
    ctx->r1 = ctx->r16 < ctx->r6 ? 1 : 0;
L_800C7094:
    // 0x800C7094: beql        $at, $zero, L_800C70BC
    if (ctx->r1 == 0) {
        // 0x800C7098: and         $v0, $t9, $t5
        ctx->r2 = ctx->r25 & ctx->r13;
            goto L_800C70BC;
    }
    goto skip_0;
    // 0x800C7098: and         $v0, $t9, $t5
    ctx->r2 = ctx->r25 & ctx->r13;
    skip_0:
L_800C709C:
    // 0x800C709C: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C70A0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C70A4: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C70A8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C70AC: slt         $at, $s0, $a2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800C70B0: bne         $at, $zero, L_800C709C
    if (ctx->r1 != 0) {
        // 0x800C70B4: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C709C;
    }
    // 0x800C70B4: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
    // 0x800C70B8: and         $v0, $t9, $t5
    ctx->r2 = ctx->r25 & ctx->r13;
L_800C70BC:
    // 0x800C70BC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C70C0: addu        $t7, $a0, $v0
    ctx->r15 = ADD32(ctx->r4, ctx->r2);
    // 0x800C70C4: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800C70C8: slti        $at, $t8, 0x11
    ctx->r1 = SIGNED(ctx->r24) < 0X11 ? 1 : 0;
    // 0x800C70CC: bnel        $at, $zero, L_800C7138
    if (ctx->r1 != 0) {
        // 0x800C70D0: lbu         $v0, 0x1($t7)
        ctx->r2 = MEM_BU(ctx->r15, 0X1);
            goto L_800C7138;
    }
    goto skip_1;
    // 0x800C70D0: lbu         $v0, 0x1($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1);
    skip_1:
    // 0x800C70D4: lb          $v1, 0x1($t7)
    ctx->r3 = MEM_B(ctx->r15, 0X1);
L_800C70D8:
    // 0x800C70D8: addi        $t8, $t8, -0x10
    ctx->r24 = ADD32(ctx->r24, -0X10);
    // 0x800C70DC: sub         $s0, $s0, $v1
    ctx->r16 = SUB32(ctx->r16, ctx->r3);
    // 0x800C70E0: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x800C70E4: beq         $at, $zero, L_800C7108
    if (ctx->r1 == 0) {
        // 0x800C70E8: srlv        $t9, $t9, $v1
        ctx->r25 = S32(U32(ctx->r25) >> (ctx->r3 & 31));
            goto L_800C7108;
    }
    // 0x800C70E8: srlv        $t9, $t9, $v1
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r3 & 31));
L_800C70EC:
    // 0x800C70EC: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C70F0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C70F4: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C70F8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C70FC: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C7100: bne         $at, $zero, L_800C70EC
    if (ctx->r1 != 0) {
        // 0x800C7104: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C70EC;
    }
    // 0x800C7104: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
L_800C7108:
    // 0x800C7108: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
    // 0x800C710C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800C7110: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x800C7114: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800C7118: and         $t1, $t1, $t9
    ctx->r9 = ctx->r9 & ctx->r25;
    // 0x800C711C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C7120: add         $t7, $t0, $t1
    ctx->r15 = ADD32(ctx->r8, ctx->r9);
    // 0x800C7124: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800C7128: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x800C712C: beql        $at, $zero, L_800C70D8
    if (ctx->r1 == 0) {
        // 0x800C7130: lb          $v1, 0x1($t7)
        ctx->r3 = MEM_B(ctx->r15, 0X1);
            goto L_800C70D8;
    }
    goto skip_2;
    // 0x800C7130: lb          $v1, 0x1($t7)
    ctx->r3 = MEM_B(ctx->r15, 0X1);
    skip_2:
    // 0x800C7134: lbu         $v0, 0x1($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1);
L_800C7138:
    // 0x800C7138: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800C713C: srlv        $t9, $t9, $v0
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r2 & 31));
    // 0x800C7140: bne         $t8, $at, L_800C7158
    if (ctx->r24 != ctx->r1) {
        // 0x800C7144: sub         $s0, $s0, $v0
        ctx->r16 = SUB32(ctx->r16, ctx->r2);
            goto L_800C7158;
    }
    // 0x800C7144: sub         $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800C7148: lhu         $v0, 0x4($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X4);
    // 0x800C714C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C7150: j           L_800C7090
    // 0x800C7154: sb          $v0, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r2;
        goto L_800C7090;
    // 0x800C7154: sb          $v0, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r2;
L_800C7158:
    // 0x800C7158: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800C715C: beq         $t8, $at, L_800C7300
    if (ctx->r24 == ctx->r1) {
        // 0x800C7160: sltu        $at, $s0, $t8
        ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
            goto L_800C7300;
    }
    // 0x800C7160: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x800C7164: beql        $at, $zero, L_800C718C
    if (ctx->r1 == 0) {
        // 0x800C7168: sll         $v0, $t8, 1
        ctx->r2 = S32(ctx->r24 << 1);
            goto L_800C718C;
    }
    goto skip_3;
    // 0x800C7168: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
    skip_3:
L_800C716C:
    // 0x800C716C: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C7170: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C7174: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C7178: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C717C: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C7180: bne         $at, $zero, L_800C716C
    if (ctx->r1 != 0) {
        // 0x800C7184: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C716C;
    }
    // 0x800C7184: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
    // 0x800C7188: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
L_800C718C:
    // 0x800C718C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800C7190: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x800C7194: lhu         $t0, 0x4($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X4);
    // 0x800C7198: sub         $s0, $s0, $t8
    ctx->r16 = SUB32(ctx->r16, ctx->r24);
    // 0x800C719C: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
    // 0x800C71A0: and         $t1, $t1, $t9
    ctx->r9 = ctx->r9 & ctx->r25;
    // 0x800C71A4: srlv        $t9, $t9, $t8
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r24 & 31));
    // 0x800C71A8: beq         $at, $zero, L_800C71CC
    if (ctx->r1 == 0) {
        // 0x800C71AC: addu        $t6, $t0, $t1
        ctx->r14 = ADD32(ctx->r8, ctx->r9);
            goto L_800C71CC;
    }
    // 0x800C71AC: addu        $t6, $t0, $t1
    ctx->r14 = ADD32(ctx->r8, ctx->r9);
L_800C71B0:
    // 0x800C71B0: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C71B4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C71B8: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C71BC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C71C0: slt         $at, $s0, $a3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C71C4: bne         $at, $zero, L_800C71B0
    if (ctx->r1 != 0) {
        // 0x800C71C8: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C71B0;
    }
    // 0x800C71C8: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
L_800C71CC:
    // 0x800C71CC: and         $v0, $t4, $t9
    ctx->r2 = ctx->r12 & ctx->r25;
    // 0x800C71D0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C71D4: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x800C71D8: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800C71DC: slti        $at, $t8, 0x11
    ctx->r1 = SIGNED(ctx->r24) < 0X11 ? 1 : 0;
    // 0x800C71E0: bnel        $at, $zero, L_800C724C
    if (ctx->r1 != 0) {
        // 0x800C71E4: lbu         $v0, 0x1($t7)
        ctx->r2 = MEM_BU(ctx->r15, 0X1);
            goto L_800C724C;
    }
    goto skip_4;
    // 0x800C71E4: lbu         $v0, 0x1($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1);
    skip_4:
    // 0x800C71E8: lbu         $t0, 0x1($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X1);
L_800C71EC:
    // 0x800C71EC: addi        $t8, $t8, -0x10
    ctx->r24 = ADD32(ctx->r24, -0X10);
    // 0x800C71F0: sub         $s0, $s0, $t0
    ctx->r16 = SUB32(ctx->r16, ctx->r8);
    // 0x800C71F4: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x800C71F8: beq         $at, $zero, L_800C721C
    if (ctx->r1 == 0) {
        // 0x800C71FC: srlv        $t9, $t9, $t0
        ctx->r25 = S32(U32(ctx->r25) >> (ctx->r8 & 31));
            goto L_800C721C;
    }
    // 0x800C71FC: srlv        $t9, $t9, $t0
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r8 & 31));
L_800C7200:
    // 0x800C7200: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C7204: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C7208: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C720C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C7210: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C7214: bne         $at, $zero, L_800C7200
    if (ctx->r1 != 0) {
        // 0x800C7218: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C7200;
    }
    // 0x800C7218: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
L_800C721C:
    // 0x800C721C: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
    // 0x800C7220: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800C7224: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x800C7228: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800C722C: and         $t1, $t1, $t9
    ctx->r9 = ctx->r9 & ctx->r25;
    // 0x800C7230: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800C7234: addu        $t7, $t0, $t1
    ctx->r15 = ADD32(ctx->r8, ctx->r9);
    // 0x800C7238: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x800C723C: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x800C7240: beql        $at, $zero, L_800C71EC
    if (ctx->r1 == 0) {
        // 0x800C7244: lbu         $t0, 0x1($t7)
        ctx->r8 = MEM_BU(ctx->r15, 0X1);
            goto L_800C71EC;
    }
    goto skip_5;
    // 0x800C7244: lbu         $t0, 0x1($t7)
    ctx->r8 = MEM_BU(ctx->r15, 0X1);
    skip_5:
    // 0x800C7248: lbu         $v0, 0x1($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1);
L_800C724C:
    // 0x800C724C: sub         $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
    // 0x800C7250: sltu        $at, $s0, $t8
    ctx->r1 = ctx->r16 < ctx->r24 ? 1 : 0;
    // 0x800C7254: beq         $at, $zero, L_800C7278
    if (ctx->r1 == 0) {
        // 0x800C7258: srlv        $t9, $t9, $v0
        ctx->r25 = S32(U32(ctx->r25) >> (ctx->r2 & 31));
            goto L_800C7278;
    }
    // 0x800C7258: srlv        $t9, $t9, $v0
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r2 & 31));
L_800C725C:
    // 0x800C725C: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800C7260: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C7264: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C7268: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800C726C: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C7270: bne         $at, $zero, L_800C725C
    if (ctx->r1 != 0) {
        // 0x800C7274: or          $t9, $t9, $v0
        ctx->r25 = ctx->r25 | ctx->r2;
            goto L_800C725C;
    }
    // 0x800C7274: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
L_800C7278:
    // 0x800C7278: sll         $v0, $t8, 1
    ctx->r2 = S32(ctx->r24 << 1);
    // 0x800C727C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800C7280: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x800C7284: lhu         $v1, 0x4($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0X4);
    // 0x800C7288: andi        $v0, $t6, 0x3
    ctx->r2 = ctx->r14 & 0X3;
    // 0x800C728C: and         $t1, $t1, $t9
    ctx->r9 = ctx->r9 & ctx->r25;
    // 0x800C7290: sub         $t0, $s1, $v1
    ctx->r8 = SUB32(ctx->r17, ctx->r3);
    // 0x800C7294: sub         $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x800C7298: srlv        $t9, $t9, $t8
    ctx->r25 = S32(U32(ctx->r25) >> (ctx->r24 & 31));
    // 0x800C729C: beq         $v0, $zero, L_800C72C8
    if (ctx->r2 == 0) {
        // 0x800C72A0: sub         $s0, $s0, $t8
        ctx->r16 = SUB32(ctx->r16, ctx->r24);
            goto L_800C72C8;
    }
    // 0x800C72A0: sub         $s0, $s0, $t8
    ctx->r16 = SUB32(ctx->r16, ctx->r24);
    // 0x800C72A4: sub         $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
L_800C72A8:
    // 0x800C72A8: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x800C72AC: addi        $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800C72B0: addi        $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800C72B4: addi        $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C72B8: bne         $v0, $zero, L_800C72A8
    if (ctx->r2 != 0) {
        // 0x800C72BC: sb          $t2, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r10;
            goto L_800C72A8;
    }
    // 0x800C72BC: sb          $t2, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r10;
    // 0x800C72C0: beql        $t6, $zero, L_800C7094
    if (ctx->r14 == 0) {
        // 0x800C72C4: sltu        $at, $s0, $a2
        ctx->r1 = ctx->r16 < ctx->r6 ? 1 : 0;
            goto L_800C7094;
    }
    goto skip_6;
    // 0x800C72C4: sltu        $at, $s0, $a2
    ctx->r1 = ctx->r16 < ctx->r6 ? 1 : 0;
    skip_6:
L_800C72C8:
    // 0x800C72C8: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x800C72CC: addiu       $t6, $t6, -0x4
    ctx->r14 = ADD32(ctx->r14, -0X4);
    // 0x800C72D0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800C72D4: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x800C72D8: lbu         $v1, -0x3($t0)
    ctx->r3 = MEM_BU(ctx->r8, -0X3);
    // 0x800C72DC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800C72E0: sb          $v1, -0x3($s1)
    MEM_B(-0X3, ctx->r17) = ctx->r3;
    // 0x800C72E4: lbu         $t1, -0x2($t0)
    ctx->r9 = MEM_BU(ctx->r8, -0X2);
    // 0x800C72E8: sb          $t1, -0x2($s1)
    MEM_B(-0X2, ctx->r17) = ctx->r9;
    // 0x800C72EC: lbu         $t2, -0x1($t0)
    ctx->r10 = MEM_BU(ctx->r8, -0X1);
    // 0x800C72F0: bne         $t6, $zero, L_800C72C8
    if (ctx->r14 != 0) {
        // 0x800C72F4: sb          $t2, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r10;
            goto L_800C72C8;
    }
    // 0x800C72F4: sb          $t2, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r10;
    // 0x800C72F8: j           L_800C7090
    // 0x800C72FC: nop

        goto L_800C7090;
    // 0x800C72FC: nop

L_800C7300:
    // 0x800C7300: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C7304: sw          $s2, 0x3768($at)
    MEM_W(0X3768, ctx->r1) = ctx->r18;
    // 0x800C7308: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C730C: sw          $s1, 0x376C($at)
    MEM_W(0X376C, ctx->r1) = ctx->r17;
    // 0x800C7310: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C7314: sw          $t9, -0x5530($at)
    MEM_W(-0X5530, ctx->r1) = ctx->r25;
    // 0x800C7318: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C731C: sw          $s0, -0x552C($at)
    MEM_W(-0X552C, ctx->r1) = ctx->r16;
    // 0x800C7320: lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X8);
    // 0x800C7324: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x800C7328: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x800C732C: jr          $ra
    // 0x800C7330: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C7330: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void obj_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010994: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80010998: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001099C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800109A0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800109A4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800109A8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800109AC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800109B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800109B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800109B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800109BC: jal         0x800245B4
    // 0x800109C0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_800245B4(rdram, ctx);
        goto after_0;
    // 0x800109C0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_0:
    // 0x800109C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800109C8: lw          $v0, -0x5250($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5250);
    // 0x800109CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800109D0: blez        $v0, L_80010A08
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800109D4: sw          $v0, -0x5248($at)
        MEM_W(-0X5248, ctx->r1) = ctx->r2;
            goto L_80010A08;
    }
    // 0x800109D4: sw          $v0, -0x5248($at)
    MEM_W(-0X5248, ctx->r1) = ctx->r2;
    // 0x800109D8: jal         0x800A0190
    // 0x800109DC: nop

    race_starting(rdram, ctx);
        goto after_1;
    // 0x800109DC: nop

    after_1:
    // 0x800109E0: beq         $v0, $zero, L_80010A08
    if (ctx->r2 == 0) {
        // 0x800109E4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80010A08;
    }
    // 0x800109E4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800109E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800109EC: addiu       $a0, $a0, -0x5250
    ctx->r4 = ADD32(ctx->r4, -0X5250);
    // 0x800109F0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800109F4: addiu       $v1, $v1, -0x5244
    ctx->r3 = ADD32(ctx->r3, -0X5244);
    // 0x800109F8: subu        $v0, $t6, $s4
    ctx->r2 = SUB32(ctx->r14, ctx->r20);
    // 0x800109FC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80010A00: b           L_80010A28
    // 0x80010A04: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_80010A28;
    // 0x80010A04: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80010A08:
    // 0x80010A08: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80010A0C: addiu       $v1, $v1, -0x5244
    ctx->r3 = ADD32(ctx->r3, -0X5244);
    // 0x80010A10: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80010A14: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80010A18: addu        $t9, $t8, $s4
    ctx->r25 = ADD32(ctx->r24, ctx->r20);
    // 0x80010A1C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80010A20: lw          $v0, -0x5250($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5250);
    // 0x80010A24: nop

L_80010A28:
    // 0x80010A28: bgtz        $v0, L_80010A38
    if (SIGNED(ctx->r2) > 0) {
        // 0x80010A2C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80010A38;
    }
    // 0x80010A2C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80010A30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80010A34: sw          $zero, -0x5250($at)
    MEM_W(-0X5250, ctx->r1) = 0;
L_80010A38:
    // 0x80010A38: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80010A3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80010A40: addiu       $v0, $v0, -0x52DF
    ctx->r2 = ADD32(ctx->r2, -0X52DF);
    // 0x80010A44: sb          $zero, -0x52C3($at)
    MEM_B(-0X52C3, ctx->r1) = 0;
    // 0x80010A48: lb          $t0, 0x0($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X0);
    // 0x80010A4C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80010A50: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x80010A54: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x80010A58: lb          $t3, 0x0($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X0);
    // 0x80010A5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80010A60: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80010A64: addiu       $a0, $a0, -0x5110
    ctx->r4 = ADD32(ctx->r4, -0X5110);
    // 0x80010A68: sb          $zero, -0x52DE($at)
    MEM_B(-0X52DE, ctx->r1) = 0;
    // 0x80010A6C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80010A70: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80010A74: blez        $t4, L_80010AFC
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80010A78: lui         $s5, 0x8012
        ctx->r21 = S32(0X8012 << 16);
            goto L_80010AFC;
    }
    // 0x80010A78: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80010A7C: addiu       $s5, $s5, -0x511C
    ctx->r21 = ADD32(ctx->r21, -0X511C);
    // 0x80010A80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80010A84:
    // 0x80010A84: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x80010A88: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010A8C: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x80010A90: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80010A94: nop

    // 0x80010A98: lw          $a1, 0x64($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X64);
    // 0x80010A9C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80010AA0: nop

    // 0x80010AA4: swc1        $f4, 0x5C($a1)
    MEM_W(0X5C, ctx->r5) = ctx->f4.u32l;
    // 0x80010AA8: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x80010AAC: nop

    // 0x80010AB0: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80010AB4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80010AB8: nop

    // 0x80010ABC: lwc1        $f6, 0x10($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80010AC0: nop

    // 0x80010AC4: swc1        $f6, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f6.u32l;
    // 0x80010AC8: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x80010ACC: nop

    // 0x80010AD0: addu        $t0, $t1, $v1
    ctx->r8 = ADD32(ctx->r9, ctx->r3);
    // 0x80010AD4: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80010AD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80010ADC: lwc1        $f8, 0x14($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X14);
    // 0x80010AE0: nop

    // 0x80010AE4: swc1        $f8, 0x64($a1)
    MEM_W(0X64, ctx->r5) = ctx->f8.u32l;
    // 0x80010AE8: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80010AEC: nop

    // 0x80010AF0: slt         $at, $s3, $t3
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80010AF4: bne         $at, $zero, L_80010A84
    if (ctx->r1 != 0) {
        // 0x80010AF8: nop
    
            goto L_80010A84;
    }
    // 0x80010AF8: nop

L_80010AFC:
    // 0x80010AFC: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80010B00: jal         0x800142B8
    // 0x80010B04: addiu       $s5, $s5, -0x511C
    ctx->r21 = ADD32(ctx->r21, -0X511C);
    obj_tick_anims(rdram, ctx);
        goto after_2;
    // 0x80010B04: addiu       $s5, $s5, -0x511C
    ctx->r21 = ADD32(ctx->r21, -0X511C);
    after_2:
    // 0x80010B08: jal         0x800155B8
    // 0x80010B0C: nop

    process_object_interactions(rdram, ctx);
        goto after_3;
    // 0x80010B0C: nop

    after_3:
    // 0x80010B10: jal         0x8001E89C
    // 0x80010B14: nop

    func_8001E89C(rdram, ctx);
        goto after_4;
    // 0x80010B14: nop

    after_4:
    // 0x80010B18: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80010B1C: addiu       $s3, $s3, -0x5190
    ctx->r19 = ADD32(ctx->r19, -0X5190);
    // 0x80010B20: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x80010B24: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80010B28: blez        $t4, L_80010B68
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80010B2C: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80010B68;
    }
    // 0x80010B2C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80010B30: addiu       $s0, $s0, -0x5194
    ctx->r16 = ADD32(ctx->r16, -0X5194);
    // 0x80010B34: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80010B38:
    // 0x80010B38: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80010B3C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80010B40: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x80010B44: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80010B48: jal         0x80023F48
    // 0x80010B4C: nop

    run_object_loop_func(rdram, ctx);
        goto after_5;
    // 0x80010B4C: nop

    after_5:
    // 0x80010B50: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80010B54: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80010B58: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80010B5C: bne         $at, $zero, L_80010B38
    if (ctx->r1 != 0) {
        // 0x80010B60: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80010B38;
    }
    // 0x80010B60: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80010B64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80010B68:
    // 0x80010B68: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80010B6C: addiu       $s0, $s0, -0x5194
    ctx->r16 = ADD32(ctx->r16, -0X5194);
    // 0x80010B70: jal         0x8001E6EC
    // 0x80010B74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001E6EC(rdram, ctx);
        goto after_6;
    // 0x80010B74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80010B78: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80010B7C: nop

    // 0x80010B80: blez        $t8, L_80010BB4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80010B84: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80010BB4;
    }
    // 0x80010B84: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80010B88:
    // 0x80010B88: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80010B8C: nop

    // 0x80010B90: addu        $t1, $t9, $s2
    ctx->r9 = ADD32(ctx->r25, ctx->r18);
    // 0x80010B94: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80010B98: jal         0x8001709C
    // 0x80010B9C: nop

    obj_collision_transform(rdram, ctx);
        goto after_7;
    // 0x80010B9C: nop

    after_7:
    // 0x80010BA0: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80010BA4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80010BA8: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80010BAC: bne         $at, $zero, L_80010B88
    if (ctx->r1 != 0) {
        // 0x80010BB0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80010B88;
    }
    // 0x80010BB0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80010BB4:
    // 0x80010BB4: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80010BB8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80010BBC: lw          $s3, -0x51A4($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X51A4);
    // 0x80010BC0: lw          $s1, -0x51A0($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X51A0);
    // 0x80010BC4: nop

    // 0x80010BC8: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80010BCC: beq         $at, $zero, L_80010D00
    if (ctx->r1 == 0) {
        // 0x80010BD0: sll         $s2, $s1, 2
        ctx->r18 = S32(ctx->r17 << 2);
            goto L_80010D00;
    }
    // 0x80010BD0: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
    // 0x80010BD4: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x80010BD8: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80010BDC: addiu       $s6, $s6, -0x51A8
    ctx->r22 = ADD32(ctx->r22, -0X51A8);
    // 0x80010BE0: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80010BE4: addiu       $s1, $zero, 0x21
    ctx->r17 = ADD32(0, 0X21);
L_80010BE8:
    // 0x80010BE8: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x80010BEC: nop

    // 0x80010BF0: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x80010BF4: lw          $s0, 0x0($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X0);
    // 0x80010BF8: nop

    // 0x80010BFC: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x80010C00: nop

    // 0x80010C04: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x80010C08: bne         $t6, $zero, L_80010CF0
    if (ctx->r14 != 0) {
        // 0x80010C0C: lw          $t3, 0x38($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X38);
            goto L_80010CF0;
    }
    // 0x80010C0C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80010C10: lh          $v0, 0x48($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X48);
    // 0x80010C14: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80010C18: beq         $s1, $v0, L_80010CF0
    if (ctx->r17 == ctx->r2) {
        // 0x80010C1C: lw          $t3, 0x38($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X38);
            goto L_80010CF0;
    }
    // 0x80010C1C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80010C20: beq         $v0, $at, L_80010CEC
    if (ctx->r2 == ctx->r1) {
        // 0x80010C24: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_80010CEC;
    }
    // 0x80010C24: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80010C28: beq         $v0, $at, L_80010CF0
    if (ctx->r2 == ctx->r1) {
        // 0x80010C2C: lw          $t3, 0x38($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X38);
            goto L_80010CF0;
    }
    // 0x80010C2C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80010C30: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80010C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010C38: beq         $v0, $zero, L_80010C60
    if (ctx->r2 == 0) {
        // 0x80010C3C: nop
    
            goto L_80010C60;
    }
    // 0x80010C3C: nop

    // 0x80010C40: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    // 0x80010C44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80010C48: beq         $t7, $at, L_80010C68
    if (ctx->r15 == ctx->r1) {
        // 0x80010C4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80010C68;
    }
    // 0x80010C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010C50: jal         0x80023F48
    // 0x80010C54: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    run_object_loop_func(rdram, ctx);
        goto after_8;
    // 0x80010C54: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_8:
    // 0x80010C58: b           L_80010C6C
    // 0x80010C5C: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
        goto L_80010C6C;
    // 0x80010C5C: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
L_80010C60:
    // 0x80010C60: jal         0x80023F48
    // 0x80010C64: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    run_object_loop_func(rdram, ctx);
        goto after_9;
    // 0x80010C64: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_9:
L_80010C68:
    // 0x80010C68: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
L_80010C6C:
    // 0x80010C6C: nop

    // 0x80010C70: lb          $t8, 0x53($a2)
    ctx->r24 = MEM_B(ctx->r6, 0X53);
    // 0x80010C74: nop

    // 0x80010C78: bne         $t8, $zero, L_80010CF0
    if (ctx->r24 != 0) {
        // 0x80010C7C: lw          $t3, 0x38($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X38);
            goto L_80010CF0;
    }
    // 0x80010C7C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80010C80: lb          $a0, 0x55($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X55);
    // 0x80010C84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80010C88: blez        $a0, L_80010CD4
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80010C8C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80010CD4;
    }
    // 0x80010C8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80010C90:
    // 0x80010C90: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x80010C94: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80010C98: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x80010C9C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80010CA0: nop

    // 0x80010CA4: beq         $v1, $zero, L_80010CCC
    if (ctx->r3 == 0) {
        // 0x80010CA8: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80010CCC;
    }
    // 0x80010CA8: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80010CAC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80010CB0: nop

    // 0x80010CB4: sh          $s4, 0x52($t0)
    MEM_H(0X52, ctx->r8) = ctx->r20;
    // 0x80010CB8: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x80010CBC: nop

    // 0x80010CC0: lb          $a0, 0x55($a2)
    ctx->r4 = MEM_B(ctx->r6, 0X55);
    // 0x80010CC4: nop

    // 0x80010CC8: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
L_80010CCC:
    // 0x80010CCC: bne         $at, $zero, L_80010C90
    if (ctx->r1 != 0) {
        // 0x80010CD0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80010C90;
    }
    // 0x80010CD0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80010CD4:
    // 0x80010CD4: lbu         $t2, 0x72($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X72);
    // 0x80010CD8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80010CDC: beq         $t2, $at, L_80010CEC
    if (ctx->r10 == ctx->r1) {
        // 0x80010CE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80010CEC;
    }
    // 0x80010CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010CE4: jal         0x80014090
    // 0x80010CE8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80014090(rdram, ctx);
        goto after_10;
    // 0x80010CE8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_10:
L_80010CEC:
    // 0x80010CEC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
L_80010CF0:
    // 0x80010CF0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80010CF4: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80010CF8: bne         $at, $zero, L_80010BE8
    if (ctx->r1 != 0) {
        // 0x80010CFC: nop
    
            goto L_80010BE8;
    }
    // 0x80010CFC: nop

L_80010D00:
    // 0x80010D00: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80010D04: lw          $t4, -0x5110($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5110);
    // 0x80010D08: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80010D0C: addiu       $s6, $s6, -0x51A8
    ctx->r22 = ADD32(ctx->r22, -0X51A8);
    // 0x80010D10: blez        $t4, L_80010D4C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80010D14: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80010D4C;
    }
    // 0x80010D14: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80010D18: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80010D1C:
    // 0x80010D1C: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x80010D20: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80010D24: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x80010D28: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80010D2C: jal         0x8004DE38
    // 0x80010D30: nop

    update_player_racer(rdram, ctx);
        goto after_11;
    // 0x80010D30: nop

    after_11:
    // 0x80010D34: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80010D38: lw          $t7, -0x5110($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5110);
    // 0x80010D3C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80010D40: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80010D44: bne         $at, $zero, L_80010D1C
    if (ctx->r1 != 0) {
        // 0x80010D48: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80010D1C;
    }
    // 0x80010D48: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80010D4C:
    // 0x80010D4C: jal         0x8006BD98
    // 0x80010D50: nop

    level_type(rdram, ctx);
        goto after_12;
    // 0x80010D50: nop

    after_12:
    // 0x80010D54: bne         $v0, $zero, L_80010DC8
    if (ctx->r2 != 0) {
        // 0x80010D58: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_80010DC8;
    }
    // 0x80010D58: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80010D5C: lw          $a3, -0x5110($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5110);
    // 0x80010D60: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80010D64: blez        $a3, L_80010DC8
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80010D68: addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
            goto L_80010DC8;
    }
    // 0x80010D68: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80010D6C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80010D70: addiu       $s0, $s0, -0x5118
    ctx->r16 = ADD32(ctx->r16, -0X5118);
L_80010D74:
    // 0x80010D74: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80010D78: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x80010D7C: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80010D80: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80010D84: nop

    // 0x80010D88: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x80010D8C: nop

    // 0x80010D90: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x80010D94: nop

    // 0x80010D98: beq         $s2, $t0, L_80010DBC
    if (ctx->r18 == ctx->r8) {
        // 0x80010D9C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80010DBC;
    }
    // 0x80010D9C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80010DA0: jal         0x80043ECC
    // 0x80010DA4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    increment_ai_behaviour_chances(rdram, ctx);
        goto after_13;
    // 0x80010DA4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_13:
    // 0x80010DA8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80010DAC: lw          $a3, -0x5110($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5110);
    // 0x80010DB0: nop

    // 0x80010DB4: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x80010DB8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80010DBC:
    // 0x80010DBC: slt         $at, $s1, $a3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80010DC0: bne         $at, $zero, L_80010D74
    if (ctx->r1 != 0) {
        // 0x80010DC4: nop
    
            goto L_80010D74;
    }
    // 0x80010DC4: nop

L_80010DC8:
    // 0x80010DC8: jal         0x8000BADC
    // 0x80010DCC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    racerfx_update(rdram, ctx);
        goto after_14;
    // 0x80010DCC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_14:
    // 0x80010DD0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80010DD4: lw          $s1, -0x51A0($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X51A0);
    // 0x80010DD8: nop

    // 0x80010DDC: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80010DE0: beq         $at, $zero, L_80010E58
    if (ctx->r1 == 0) {
        // 0x80010DE4: sll         $s2, $s1, 2
        ctx->r18 = S32(ctx->r17 << 2);
            goto L_80010E58;
    }
    // 0x80010DE4: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
    // 0x80010DE8: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
L_80010DEC:
    // 0x80010DEC: lw          $t2, 0x0($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X0);
    // 0x80010DF0: nop

    // 0x80010DF4: addu        $t3, $t2, $s2
    ctx->r11 = ADD32(ctx->r10, ctx->r18);
    // 0x80010DF8: lw          $s0, 0x0($t3)
    ctx->r16 = MEM_W(ctx->r11, 0X0);
    // 0x80010DFC: nop

    // 0x80010E00: lh          $t4, 0x6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X6);
    // 0x80010E04: nop

    // 0x80010E08: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x80010E0C: bne         $t5, $zero, L_80010E24
    if (ctx->r13 != 0) {
        // 0x80010E10: nop
    
            goto L_80010E24;
    }
    // 0x80010E10: nop

    // 0x80010E14: lh          $t6, 0x48($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X48);
    // 0x80010E18: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80010E1C: beq         $t6, $at, L_80010E34
    if (ctx->r14 == ctx->r1) {
        // 0x80010E20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80010E34;
    }
    // 0x80010E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80010E24:
    // 0x80010E24: lh          $t7, 0x48($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X48);
    // 0x80010E28: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80010E2C: bne         $t7, $at, L_80010E48
    if (ctx->r15 != ctx->r1) {
        // 0x80010E30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80010E48;
    }
    // 0x80010E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80010E34:
    // 0x80010E34: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80010E38: jal         0x80023F48
    // 0x80010E3C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    run_object_loop_func(rdram, ctx);
        goto after_15;
    // 0x80010E3C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_15:
    // 0x80010E40: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80010E44: nop

L_80010E48:
    // 0x80010E48: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80010E4C: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80010E50: bne         $at, $zero, L_80010DEC
    if (ctx->r1 != 0) {
        // 0x80010E54: nop
    
            goto L_80010DEC;
    }
    // 0x80010E54: nop

L_80010E58:
    // 0x80010E58: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80010E5C: lw          $t8, -0x519C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X519C);
    // 0x80010E60: nop

    // 0x80010E64: blez        $t8, L_80010EC8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80010E68: lui         $s1, 0x8012
        ctx->r17 = S32(0X8012 << 16);
            goto L_80010EC8;
    }
    // 0x80010E68: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80010E6C: lw          $s1, -0x51A0($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X51A0);
    // 0x80010E70: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x80010E74: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80010E78: beq         $at, $zero, L_80010EC8
    if (ctx->r1 == 0) {
        // 0x80010E7C: sll         $s2, $s1, 2
        ctx->r18 = S32(ctx->r17 << 2);
            goto L_80010EC8;
    }
    // 0x80010E7C: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
L_80010E80:
    // 0x80010E80: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x80010E84: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80010E88: addu        $t1, $t9, $s2
    ctx->r9 = ADD32(ctx->r25, ctx->r18);
    // 0x80010E8C: lw          $s0, 0x0($t1)
    ctx->r16 = MEM_W(ctx->r9, 0X0);
    // 0x80010E90: nop

    // 0x80010E94: lh          $t0, 0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X6);
    // 0x80010E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80010E9C: andi        $t2, $t0, 0x8000
    ctx->r10 = ctx->r8 & 0X8000;
    // 0x80010EA0: beq         $t2, $zero, L_80010EB8
    if (ctx->r10 == 0) {
        // 0x80010EA4: nop
    
            goto L_80010EB8;
    }
    // 0x80010EA4: nop

    // 0x80010EA8: jal         0x800B22FC
    // 0x80010EAC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    particle_update(rdram, ctx);
        goto after_16;
    // 0x80010EAC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_16:
    // 0x80010EB0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80010EB4: nop

L_80010EB8:
    // 0x80010EB8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80010EBC: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80010EC0: bne         $at, $zero, L_80010E80
    if (ctx->r1 != 0) {
        // 0x80010EC4: nop
    
            goto L_80010E80;
    }
    // 0x80010EC4: nop

L_80010EC8:
    // 0x80010EC8: jal         0x80032398
    // 0x80010ECC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    light_update_all(rdram, ctx);
        goto after_17;
    // 0x80010ECC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_17:
    // 0x80010ED0: jal         0x80032C6C
    // 0x80010ED4: nop

    light_count(rdram, ctx);
        goto after_18;
    // 0x80010ED4: nop

    after_18:
    // 0x80010ED8: blez        $v0, L_80010F58
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80010EDC: lui         $s1, 0x8012
        ctx->r17 = S32(0X8012 << 16);
            goto L_80010F58;
    }
    // 0x80010EDC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80010EE0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80010EE4: lw          $v0, -0x51A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51A4);
    // 0x80010EE8: lw          $s1, -0x51A0($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X51A0);
    // 0x80010EEC: nop

    // 0x80010EF0: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80010EF4: beq         $at, $zero, L_80010F58
    if (ctx->r1 == 0) {
        // 0x80010EF8: sll         $s2, $s1, 2
        ctx->r18 = S32(ctx->r17 << 2);
            goto L_80010F58;
    }
    // 0x80010EF8: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
L_80010EFC:
    // 0x80010EFC: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x80010F00: nop

    // 0x80010F04: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x80010F08: lw          $s0, 0x0($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X0);
    // 0x80010F0C: nop

    // 0x80010F10: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x80010F14: nop

    // 0x80010F18: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x80010F1C: bne         $t6, $zero, L_80010F48
    if (ctx->r14 != 0) {
        // 0x80010F20: nop
    
            goto L_80010F48;
    }
    // 0x80010F20: nop

    // 0x80010F24: lw          $t7, 0x54($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X54);
    // 0x80010F28: nop

    // 0x80010F2C: beq         $t7, $zero, L_80010F48
    if (ctx->r15 == 0) {
        // 0x80010F30: nop
    
            goto L_80010F48;
    }
    // 0x80010F30: nop

    // 0x80010F34: jal         0x80032C7C
    // 0x80010F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    light_update_shading(rdram, ctx);
        goto after_19;
    // 0x80010F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80010F3C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80010F40: lw          $v0, -0x51A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51A4);
    // 0x80010F44: nop

L_80010F48:
    // 0x80010F48: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80010F4C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80010F50: bne         $at, $zero, L_80010EFC
    if (ctx->r1 != 0) {
        // 0x80010F54: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80010EFC;
    }
    // 0x80010F54: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80010F58:
    // 0x80010F58: jal         0x8001E6EC
    // 0x80010F5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8001E6EC(rdram, ctx);
        goto after_20;
    // 0x80010F5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x80010F60: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80010F64: lb          $t8, -0x5109($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X5109);
    // 0x80010F68: nop

    // 0x80010F6C: beq         $t8, $zero, L_80010F7C
    if (ctx->r24 == 0) {
        // 0x80010F70: nop
    
            goto L_80010F7C;
    }
    // 0x80010F70: nop

    // 0x80010F74: jal         0x80022948
    // 0x80010F78: nop

    mode_init_taj_race(rdram, ctx);
        goto after_21;
    // 0x80010F78: nop

    after_21:
L_80010F7C:
    // 0x80010F7C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80010F80: addiu       $s0, $s0, -0x5254
    ctx->r16 = ADD32(ctx->r16, -0X5254);
    // 0x80010F84: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80010F88: nop

    // 0x80010F8C: bne         $t9, $zero, L_80010FB4
    if (ctx->r25 != 0) {
        // 0x80010F90: nop
    
            goto L_80010FB4;
    }
    // 0x80010F90: nop

    // 0x80010F94: jal         0x8001004C
    // 0x80010F98: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_22;
    // 0x80010F98: nop

    after_22:
    // 0x80010F9C: jal         0x80017E98
    // 0x80010FA0: nop

    checkpoint_update_all(rdram, ctx);
        goto after_23;
    // 0x80010FA0: nop

    after_23:
    // 0x80010FA4: jal         0x8001BC54
    // 0x80010FA8: nop

    spectate_update(rdram, ctx);
        goto after_24;
    // 0x80010FA8: nop

    after_24:
    // 0x80010FAC: jal         0x8001E93C
    // 0x80010FB0: nop

    func_8001E93C(rdram, ctx);
        goto after_25;
    // 0x80010FB0: nop

    after_25:
L_80010FB4:
    // 0x80010FB4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80010FB8: lw          $a3, -0x5110($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5110);
    // 0x80010FBC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80010FC0: beq         $a3, $zero, L_80011004
    if (ctx->r7 == 0) {
        // 0x80010FC4: nop
    
            goto L_80011004;
    }
    // 0x80010FC4: nop

    // 0x80010FC8: lh          $t1, -0x52B2($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X52B2);
    // 0x80010FCC: nop

    // 0x80010FD0: bne         $t1, $zero, L_80010FF0
    if (ctx->r9 != 0) {
        // 0x80010FD4: nop
    
            goto L_80010FF0;
    }
    // 0x80010FD4: nop

    // 0x80010FD8: jal         0x80019808
    // 0x80010FDC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    race_check_finish(rdram, ctx);
        goto after_26;
    // 0x80010FDC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_26:
    // 0x80010FE0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80010FE4: lw          $a3, -0x5110($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5110);
    // 0x80010FE8: b           L_80011004
    // 0x80010FEC: nop

        goto L_80011004;
    // 0x80010FEC: nop

L_80010FF0:
    // 0x80010FF0: jal         0x8001A8F4
    // 0x80010FF4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    race_transition_adventure(rdram, ctx);
        goto after_27;
    // 0x80010FF4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_27:
    // 0x80010FF8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80010FFC: lw          $a3, -0x5110($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5110);
    // 0x80011000: nop

L_80011004:
    // 0x80011004: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80011008: lw          $a0, -0x5114($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5114);
    // 0x8001100C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80011010: jal         0x80008438
    // 0x80011014: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    audspat_update_all(rdram, ctx);
        goto after_28;
    // 0x80011014: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_28:
    // 0x80011018: mtc1        $s4, $f10
    ctx->f10.u32l = ctx->r20;
    // 0x8001101C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011020: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80011024: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80011028: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001102C: swc1        $f16, -0x5258($at)
    MEM_W(-0X5258, ctx->r1) = ctx->f16.u32l;
    // 0x80011030: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80011034: sb          $zero, -0x52DC($at)
    MEM_B(-0X52DC, ctx->r1) = 0;
    // 0x80011038: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001103C: jal         0x8000E2B4
    // 0x80011040: sb          $zero, -0x52AD($at)
    MEM_B(-0X52AD, ctx->r1) = 0;
    transform_player_vehicle(rdram, ctx);
        goto after_29;
    // 0x80011040: sb          $zero, -0x52AD($at)
    MEM_B(-0X52AD, ctx->r1) = 0;
    after_29:
    // 0x80011044: jal         0x8009CFB0
    // 0x80011048: nop

    dialogue_try_close(rdram, ctx);
        goto after_30;
    // 0x80011048: nop

    after_30:
    // 0x8001104C: jal         0x800179D0
    // 0x80011050: nop

    func_800179D0(rdram, ctx);
        goto after_31;
    // 0x80011050: nop

    after_31:
    // 0x80011054: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80011058: addiu       $v1, $v1, -0x5100
    ctx->r3 = ADD32(ctx->r3, -0X5100);
    // 0x8001105C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80011060: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80011064: bne         $v0, $at, L_80011100
    if (ctx->r2 != ctx->r1) {
        // 0x80011068: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80011100;
    }
    // 0x80011068: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001106C: lw          $t2, -0x5250($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5250);
    // 0x80011070: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x80011074: bne         $t2, $at, L_8001110C
    if (ctx->r10 != ctx->r1) {
        // 0x80011078: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8001110C;
    }
    // 0x80011078: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001107C: lh          $t3, -0x5186($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X5186);
    // 0x80011080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011084: bne         $t3, $zero, L_8001110C
    if (ctx->r11 != 0) {
        // 0x80011088: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001110C;
    }
    // 0x80011088: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001108C: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_80011090:
    // 0x80011090: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80011094: jal         0x8006A554
    // 0x80011098: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    input_pressed(rdram, ctx);
        goto after_32;
    // 0x80011098: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_32:
    // 0x8001109C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800110A0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800110A4: bne         $s3, $s0, L_80011090
    if (ctx->r19 != ctx->r16) {
        // 0x800110A8: or          $a1, $a1, $v0
        ctx->r5 = ctx->r5 | ctx->r2;
            goto L_80011090;
    }
    // 0x800110A8: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x800110AC: andi        $t4, $a1, 0x8000
    ctx->r12 = ctx->r5 & 0X8000;
    // 0x800110B0: beq         $t4, $zero, L_800110C8
    if (ctx->r12 == 0) {
        // 0x800110B4: andi        $t5, $a1, 0x4000
        ctx->r13 = ctx->r5 & 0X4000;
            goto L_800110C8;
    }
    // 0x800110B4: andi        $t5, $a1, 0x4000
    ctx->r13 = ctx->r5 & 0X4000;
    // 0x800110B8: jal         0x8001E45C
    // 0x800110BC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    func_8001E45C(rdram, ctx);
        goto after_33;
    // 0x800110BC: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_33:
    // 0x800110C0: b           L_80011110
    // 0x800110C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80011110;
    // 0x800110C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800110C8:
    // 0x800110C8: beq         $t5, $zero, L_80011110
    if (ctx->r13 == 0) {
        // 0x800110CC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80011110;
    }
    // 0x800110CC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800110D0: jal         0x8009962C
    // 0x800110D4: nop

    get_trophy_race_world_id(rdram, ctx);
        goto after_34;
    // 0x800110D4: nop

    after_34:
    // 0x800110D8: bne         $v0, $zero, L_80011110
    if (ctx->r2 != 0) {
        // 0x800110DC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80011110;
    }
    // 0x800110DC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800110E0: jal         0x8009C2D0
    // 0x800110E4: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_35;
    // 0x800110E4: nop

    after_35:
    // 0x800110E8: bne         $v0, $zero, L_80011110
    if (ctx->r2 != 0) {
        // 0x800110EC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80011110;
    }
    // 0x800110EC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800110F0: jal         0x8006F140
    // 0x800110F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    level_transition_begin(rdram, ctx);
        goto after_36;
    // 0x800110F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_36:
    // 0x800110F8: b           L_80011110
    // 0x800110FC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80011110;
    // 0x800110FC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80011100:
    // 0x80011100: bne         $v0, $zero, L_8001110C
    if (ctx->r2 != 0) {
        // 0x80011104: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8001110C;
    }
    // 0x80011104: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80011108: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_8001110C:
    // 0x8001110C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80011110:
    // 0x80011110: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80011114: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80011118: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001111C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80011120: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80011124: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80011128: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001112C: jr          $ra
    // 0x80011130: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80011130: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void obj_init_fireball_octoweapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033F44: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80033F48: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80033F4C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80033F50: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80033F54: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80033F58: jr          $ra
    // 0x80033F5C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    return;
    // 0x80033F5C: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
;}
RECOMP_FUNC void timetrial_load_staff_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B2F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001B2F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B2F8: jal         0x8006B0AC
    // 0x8001B2FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    leveltable_vehicle_default(rdram, ctx);
        goto after_0;
    // 0x8001B2FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001B300: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001B304: addiu       $a1, $a1, -0x517C
    ctx->r5 = ADD32(ctx->r5, -0X517C);
    // 0x8001B308: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x8001B30C: jal         0x80076C58
    // 0x8001B310: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    asset_table_load(rdram, ctx);
        goto after_1;
    // 0x8001B310: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_1:
    // 0x8001B314: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001B318: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001B31C: addiu       $a1, $a1, -0x517C
    ctx->r5 = ADD32(ctx->r5, -0X517C);
    // 0x8001B320: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8001B324: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001B328: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_8001B32C:
    // 0x8001B32C: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8001B330: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001B334: bne         $a2, $t6, L_8001B35C
    if (ctx->r6 != ctx->r14) {
        // 0x8001B338: nop
    
            goto L_8001B35C;
    }
    // 0x8001B338: nop

    // 0x8001B33C: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x8001B340: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    // 0x8001B344: nop

    // 0x8001B348: bne         $t7, $t8, L_8001B35C
    if (ctx->r15 != ctx->r24) {
        // 0x8001B34C: nop
    
            goto L_8001B35C;
    }
    // 0x8001B34C: nop

    // 0x8001B350: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8001B354: b           L_8001B36C
    // 0x8001B358: nop

        goto L_8001B36C;
    // 0x8001B358: nop

L_8001B35C:
    // 0x8001B35C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8001B360: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8001B364: bne         $a3, $v0, L_8001B32C
    if (ctx->r7 != ctx->r2) {
        // 0x8001B368: nop
    
            goto L_8001B32C;
    }
    // 0x8001B368: nop

L_8001B36C:
    // 0x8001B36C: beq         $a3, $v0, L_8001B390
    if (ctx->r7 == ctx->r2) {
        // 0x8001B370: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8001B390;
    }
    // 0x8001B370: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001B374: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8001B378: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x8001B37C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001B380: addiu       $a2, $a2, -0x5180
    ctx->r6 = ADD32(ctx->r6, -0X5180);
    // 0x8001B384: jal         0x80059A68
    // 0x8001B388: subu        $a1, $t9, $a0
    ctx->r5 = SUB32(ctx->r25, ctx->r4);
    load_tt_ghost(rdram, ctx);
        goto after_2;
    // 0x8001B388: subu        $a1, $t9, $a0
    ctx->r5 = SUB32(ctx->r25, ctx->r4);
    after_2:
    // 0x8001B38C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8001B390:
    // 0x8001B390: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8001B394: jal         0x80071140
    // 0x8001B398: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    mempool_free(rdram, ctx);
        goto after_3;
    // 0x8001B398: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_3:
    // 0x8001B39C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B3A0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B3A4: jr          $ra
    // 0x8001B3A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001B3A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void race_is_adventure_2P(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C19C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006C1A0: lb          $v0, -0x2CE8($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2CE8);
    // 0x8006C1A4: jr          $ra
    // 0x8006C1A8: nop

    return;
    // 0x8006C1A8: nop

;}
RECOMP_FUNC void mempool_init_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070B30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070B34: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80070B38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070B3C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80070B40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80070B44: addiu       $a0, $a0, -0x2C10
    ctx->r4 = ADD32(ctx->r4, -0X2C10);
    // 0x80070B48: lui         $t7, 0x8040
    ctx->r15 = S32(0X8040 << 16);
    // 0x80070B4C: sw          $t6, 0x35C0($at)
    MEM_W(0X35C0, ctx->r1) = ctx->r14;
    extern void dkr_legacy_heap_capacity(uint8_t*, recomp_context*); dkr_legacy_heap_capacity(rdram, ctx);
    // 0x80070B50: subu        $a1, $t7, $a0
    ctx->r5 = SUB32(ctx->r15, ctx->r4);
    // 0x80070B54: jal         0x80070BE4
    // 0x80070B58: addiu       $a2, $zero, 0x640
    ctx->r6 = ADD32(0, 0X640);
    mempool_init(rdram, ctx);
        goto after_0;
    // 0x80070B58: addiu       $a2, $zero, 0x640
    ctx->r6 = ADD32(0, 0X640);
    after_0:
    // 0x80070B5C: jal         0x800710B0
    // 0x80070B60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_1;
    // 0x80070B60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80070B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070B68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80070B6C: sw          $zero, 0x3DC8($at)
    MEM_W(0X3DC8, ctx->r1) = 0;
    // 0x80070B70: jr          $ra
    // 0x80070B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80070B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void alCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3820: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800D3824: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800D3828: blez        $a2, L_800D388C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800D382C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800D388C;
    }
    // 0x800D382C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800D3830: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x800D3834: beq         $a1, $zero, L_800D385C
    if (ctx->r5 == 0) {
        // 0x800D3838: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800D385C;
    }
    // 0x800D3838: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800D383C:
    // 0x800D383C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800D3840: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800D3844: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800D3848: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800D384C: bne         $a0, $a3, L_800D383C
    if (ctx->r4 != ctx->r7) {
        // 0x800D3850: sb          $t6, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r14;
            goto L_800D383C;
    }
    // 0x800D3850: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x800D3854: beq         $a3, $a2, L_800D388C
    if (ctx->r7 == ctx->r6) {
        // 0x800D3858: nop
    
            goto L_800D388C;
    }
    // 0x800D3858: nop

L_800D385C:
    // 0x800D385C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800D3860: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800D3864: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800D3868: sb          $t7, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r15;
    // 0x800D386C: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800D3870: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D3874: sb          $t8, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r24;
    // 0x800D3878: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x800D387C: sb          $t9, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r25;
    // 0x800D3880: lbu         $t0, -0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X1);
    // 0x800D3884: bne         $a3, $a2, L_800D385C
    if (ctx->r7 != ctx->r6) {
        // 0x800D3888: sb          $t0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r8;
            goto L_800D385C;
    }
    // 0x800D3888: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
L_800D388C:
    // 0x800D388C: jr          $ra
    // 0x800D3890: nop

    return;
    // 0x800D3890: nop

;}
RECOMP_FUNC void menu_adventure_track_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092C84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80092C88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80092C8C: jal         0x8006EA90
    // 0x80092C90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80092C90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80092C94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092C98: sw          $zero, -0xB3C($at)
    MEM_W(-0XB3C, ctx->r1) = 0;
    // 0x80092C9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80092CA0: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x80092CA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092CA8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80092CAC: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x80092CB0: lw          $t6, 0x4C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4C);
    // 0x80092CB4: nop

    // 0x80092CB8: lb          $s0, 0x2($t6)
    ctx->r16 = MEM_B(ctx->r14, 0X2);
    // 0x80092CBC: jal         0x8006B0AC
    // 0x80092CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_vehicle_default(rdram, ctx);
        goto after_1;
    // 0x80092CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80092CC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80092CC8: sb          $v0, 0x69C0($at)
    MEM_B(0X69C0, ctx->r1) = ctx->r2;
    // 0x80092CCC: jal         0x8006B14C
    // 0x80092CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_type(rdram, ctx);
        goto after_2;
    // 0x80092CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80092CD4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80092CD8: beq         $v0, $at, L_80092D18
    if (ctx->r2 == ctx->r1) {
        // 0x80092CDC: sll         $t4, $s0, 1
        ctx->r12 = S32(ctx->r16 << 1);
            goto L_80092D18;
    }
    // 0x80092CDC: sll         $t4, $s0, 1
    ctx->r12 = S32(ctx->r16 << 1);
    // 0x80092CE0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80092CE4: beq         $v0, $at, L_80092D18
    if (ctx->r2 == ctx->r1) {
        // 0x80092CE8: andi        $t7, $v0, 0x40
        ctx->r15 = ctx->r2 & 0X40;
            goto L_80092D18;
    }
    // 0x80092CE8: andi        $t7, $v0, 0x40
    ctx->r15 = ctx->r2 & 0X40;
    // 0x80092CEC: bne         $t7, $zero, L_80092D4C
    if (ctx->r15 != 0) {
        // 0x80092CF0: sll         $t6, $s0, 1
        ctx->r14 = S32(ctx->r16 << 1);
            goto L_80092D4C;
    }
    // 0x80092CF0: sll         $t6, $s0, 1
    ctx->r14 = S32(ctx->r16 << 1);
    // 0x80092CF4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80092CF8: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80092CFC: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80092D00: nop

    // 0x80092D04: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80092D08: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80092D0C: nop

    // 0x80092D10: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x80092D14: bne         $t3, $zero, L_80092D4C
    if (ctx->r11 != 0) {
        // 0x80092D18: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80092D4C;
    }
L_80092D18:
    // 0x80092D18: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80092D1C: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x80092D20: lh          $v0, 0x758($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X758);
    // 0x80092D24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80092D28: beq         $v0, $at, L_80092D3C
    if (ctx->r2 == ctx->r1) {
        // 0x80092D2C: andi        $a0, $v0, 0xFFFF
        ctx->r4 = ctx->r2 & 0XFFFF;
            goto L_80092D3C;
    }
    // 0x80092D2C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80092D30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80092D34: jal         0x80000FDC
    // 0x80092D38: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_3;
    // 0x80092D38: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
L_80092D3C:
    // 0x80092D3C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80092D40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80092D44: b           L_80092E58
    // 0x80092D48: sw          $t5, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r13;
        goto L_80092E58;
    // 0x80092D48: sw          $t5, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r13;
L_80092D4C:
    // 0x80092D4C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80092D50: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80092D54: lh          $v0, 0x758($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X758);
    // 0x80092D58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80092D5C: beq         $v0, $at, L_80092D70
    if (ctx->r2 == ctx->r1) {
        // 0x80092D60: andi        $a0, $v0, 0xFFFF
        ctx->r4 = ctx->r2 & 0XFFFF;
            goto L_80092D70;
    }
    // 0x80092D60: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80092D64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80092D68: jal         0x80000FDC
    // 0x80092D6C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_4;
    // 0x80092D6C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_4:
L_80092D70:
    // 0x80092D70: jal         0x80000BE0
    // 0x80092D74: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_5;
    // 0x80092D74: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_5:
    // 0x80092D78: jal         0x80000B34
    // 0x80092D7C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_6;
    // 0x80092D7C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_6:
    // 0x80092D80: jal         0x80000B18
    // 0x80092D84: nop

    music_change_off(rdram, ctx);
        goto after_7;
    // 0x80092D84: nop

    after_7:
    // 0x80092D88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80092D8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80092D90: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
    // 0x80092D94: jal         0x8009C674
    // 0x80092D98: addiu       $a0, $a0, 0xFB4
    ctx->r4 = ADD32(ctx->r4, 0XFB4);
    menu_assetgroup_load(rdram, ctx);
        goto after_8;
    // 0x80092D98: addiu       $a0, $a0, 0xFB4
    ctx->r4 = ADD32(ctx->r4, 0XFB4);
    after_8:
    // 0x80092D9C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80092DA0: jal         0x8009C8A4
    // 0x80092DA4: addiu       $a0, $a0, 0xFD8
    ctx->r4 = ADD32(ctx->r4, 0XFD8);
    menu_imagegroup_load(rdram, ctx);
        goto after_9;
    // 0x80092DA4: addiu       $a0, $a0, 0xFD8
    ctx->r4 = ADD32(ctx->r4, 0XFD8);
    after_9:
    // 0x80092DA8: jal         0x8008E45C
    // 0x80092DAC: nop

    menu_init_vehicle_textures(rdram, ctx);
        goto after_10;
    // 0x80092DAC: nop

    after_10:
    // 0x80092DB0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80092DB4: addiu       $v0, $v0, 0x6550
    ctx->r2 = ADD32(ctx->r2, 0X6550);
    // 0x80092DB8: lw          $t7, 0x7C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X7C);
    // 0x80092DBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092DC0: sw          $t7, 0x4D4($at)
    MEM_W(0X4D4, ctx->r1) = ctx->r15;
    // 0x80092DC4: lw          $t8, 0x78($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X78);
    // 0x80092DC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092DCC: sw          $t8, 0x4E4($at)
    MEM_W(0X4E4, ctx->r1) = ctx->r24;
    // 0x80092DD0: lw          $t9, 0x84($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X84);
    // 0x80092DD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092DD8: sw          $t9, 0x4F4($at)
    MEM_W(0X4F4, ctx->r1) = ctx->r25;
    // 0x80092DDC: lw          $t0, 0x80($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X80);
    // 0x80092DE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092DE4: sw          $t0, 0x504($at)
    MEM_W(0X504, ctx->r1) = ctx->r8;
    // 0x80092DE8: lw          $t1, 0x8C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8C);
    // 0x80092DEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092DF0: sw          $t1, 0x514($at)
    MEM_W(0X514, ctx->r1) = ctx->r9;
    // 0x80092DF4: lw          $t2, 0x88($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X88);
    // 0x80092DF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092DFC: sw          $t2, 0x524($at)
    MEM_W(0X524, ctx->r1) = ctx->r10;
    // 0x80092E00: lw          $t3, 0xC0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC0);
    // 0x80092E04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092E08: sw          $t3, 0x5B4($at)
    MEM_W(0X5B4, ctx->r1) = ctx->r11;
    // 0x80092E0C: lw          $t4, 0x178($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X178);
    // 0x80092E10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092E14: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80092E18: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    // 0x80092E1C: jal         0x800C01D8
    // 0x80092E20: sw          $t4, 0x614($at)
    MEM_W(0X614, ctx->r1) = ctx->r12;
    transition_begin(rdram, ctx);
        goto after_11;
    // 0x80092E20: sw          $t4, 0x614($at)
    MEM_W(0X614, ctx->r1) = ctx->r12;
    after_11:
    // 0x80092E24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80092E28: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x80092E2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092E30: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x80092E34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80092E38: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x80092E3C: sw          $t5, 0x980($at)
    MEM_W(0X980, ctx->r1) = ctx->r13;
    // 0x80092E40: jal         0x800C4170
    // 0x80092E44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_12;
    // 0x80092E44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_12:
    // 0x80092E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80092E4C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80092E50: jal         0x8006E2E8
    // 0x80092E54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    load_level_for_menu(rdram, ctx);
        goto after_13;
    // 0x80092E54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
L_80092E58:
    // 0x80092E58: jal         0x800C5494
    // 0x80092E5C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_14;
    // 0x80092E5C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_14:
    // 0x80092E60: jal         0x8006B14C
    // 0x80092E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_type(rdram, ctx);
        goto after_15;
    // 0x80092E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80092E68: andi        $t6, $v0, 0x40
    ctx->r14 = ctx->r2 & 0X40;
    // 0x80092E6C: beq         $t6, $zero, L_80092E88
    if (ctx->r14 == 0) {
        // 0x80092E70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80092E88;
    }
    // 0x80092E70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80092E74: jal         0x8006B190
    // 0x80092E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_world(rdram, ctx);
        goto after_16;
    // 0x80092E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80092E7C: jal         0x800C31EC
    // 0x80092E80: addiu       $a0, $v0, 0x3B
    ctx->r4 = ADD32(ctx->r2, 0X3B);
    set_current_text(rdram, ctx);
        goto after_17;
    // 0x80092E80: addiu       $a0, $v0, 0x3B
    ctx->r4 = ADD32(ctx->r2, 0X3B);
    after_17:
    // 0x80092E84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80092E88:
    // 0x80092E88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80092E8C: jr          $ra
    // 0x80092E90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80092E90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void draw_menu_elements(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800821EC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800821F0: swc1        $f20, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f20.u32l;
    // 0x800821F4: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800821F8: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800821FC: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80082200: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80082204: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80082208: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8008220C: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80082210: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80082214: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80082218: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8008221C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80082220: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80082224: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80082228: swc1        $f23, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8008222C: swc1        $f22, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f22.u32l;
    // 0x80082230: swc1        $f21, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80082234: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80082238: beq         $a0, $at, L_80082878
    if (ctx->r4 == ctx->r1) {
        // 0x8008223C: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_80082878;
    }
    // 0x8008223C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80082240: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80082244: addiu       $s6, $s6, 0x63A0
    ctx->r22 = ADD32(ctx->r22, 0X63A0);
    // 0x80082248: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008224C: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x80082250: jal         0x80067F2C
    // 0x80082254: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x80082254: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_0:
    // 0x80082258: lw          $s1, 0x14($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X14);
    // 0x8008225C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80082260: beq         $s1, $zero, L_80082838
    if (ctx->r17 == 0) {
        // 0x80082264: lui         $s7, 0x800E
        ctx->r23 = S32(0X800E << 16);
            goto L_80082838;
    }
    // 0x80082264: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x80082268: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8008226C: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x80082270: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80082274: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80082278: addiu       $s4, $s4, -0x8A4
    ctx->r20 = ADD32(ctx->r20, -0X8A4);
    // 0x8008227C: addiu       $fp, $fp, -0x864
    ctx->r30 = ADD32(ctx->r30, -0X864);
    // 0x80082280: addiu       $s7, $s7, -0x860
    ctx->r23 = ADD32(ctx->r23, -0X860);
L_80082284:
    // 0x80082284: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80082288: addiu       $t7, $t7, 0x6850
    ctx->r15 = ADD32(ctx->r15, 0X6850);
    // 0x8008228C: beq         $t7, $s1, L_80082828
    if (ctx->r15 == ctx->r17) {
        // 0x80082290: nop
    
            goto L_80082828;
    }
    // 0x80082290: nop

    // 0x80082294: bne         $a0, $zero, L_80082320
    if (ctx->r4 != 0) {
        // 0x80082298: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80082320;
    }
    // 0x80082298: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008229C: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800822A0: lh          $t8, 0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4);
    // 0x800822A4: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x800822A8: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x800822AC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800822B0: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x800822B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800822B8: subu        $t3, $t2, $v1
    ctx->r11 = SUB32(ctx->r10, ctx->r3);
    // 0x800822BC: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800822C0: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800822C4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800822C8: nop

    // 0x800822CC: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800822D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800822D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800822D8: nop

    // 0x800822DC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800822E0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800822E4: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800822E8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800822EC: addu        $s2, $t1, $v0
    ctx->r18 = ADD32(ctx->r9, ctx->r2);
    // 0x800822F0: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800822F4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800822F8: nop

    // 0x800822FC: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80082300: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80082304: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80082308: nop

    // 0x8008230C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80082310: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x80082314: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80082318: b           L_800823BC
    // 0x8008231C: addu        $s3, $t5, $v1
    ctx->r19 = ADD32(ctx->r13, ctx->r3);
        goto L_800823BC;
    // 0x8008231C: addu        $s3, $t5, $v1
    ctx->r19 = ADD32(ctx->r13, ctx->r3);
L_80082320:
    // 0x80082320: bne         $a0, $at, L_80082338
    if (ctx->r4 != ctx->r1) {
        // 0x80082324: nop
    
            goto L_80082338;
    }
    // 0x80082324: nop

    // 0x80082328: lh          $s2, 0x4($s0)
    ctx->r18 = MEM_H(ctx->r16, 0X4);
    // 0x8008232C: lh          $s3, 0x6($s0)
    ctx->r19 = MEM_H(ctx->r16, 0X6);
    // 0x80082330: b           L_800823C0
    // 0x80082334: lbu         $t4, 0x13($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X13);
        goto L_800823C0;
    // 0x80082334: lbu         $t4, 0x13($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X13);
L_80082338:
    // 0x80082338: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x8008233C: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    // 0x80082340: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
    // 0x80082344: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x80082348: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8008234C: lh          $t0, 0xA($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XA);
    // 0x80082350: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80082354: subu        $t1, $t0, $v1
    ctx->r9 = SUB32(ctx->r8, ctx->r3);
    // 0x80082358: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8008235C: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80082360: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80082364: nop

    // 0x80082368: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8008236C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80082370: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80082374: nop

    // 0x80082378: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8008237C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80082380: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80082384: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082388: addu        $s2, $t9, $v0
    ctx->r18 = ADD32(ctx->r25, ctx->r2);
    // 0x8008238C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80082390: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80082394: nop

    // 0x80082398: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8008239C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800823A0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800823A4: nop

    // 0x800823A8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800823AC: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800823B0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800823B4: addu        $s3, $t3, $v1
    ctx->r19 = ADD32(ctx->r11, ctx->r3);
    // 0x800823B8: nop

L_800823BC:
    // 0x800823BC: lbu         $t4, 0x13($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X13);
L_800823C0:
    // 0x800823C0: nop

    // 0x800823C4: sltiu       $at, $t4, 0x8
    ctx->r1 = ctx->r12 < 0X8 ? 1 : 0;
    // 0x800823C8: beq         $at, $zero, L_80082828
    if (ctx->r1 == 0) {
        // 0x800823CC: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80082828;
    }
    // 0x800823CC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800823D0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800823D4: addu        $at, $at, $t4
    gpr jr_addend_800823E0 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800823D8: lw          $t4, -0x7C94($at)
    ctx->r12 = ADD32(ctx->r1, -0X7C94);
    // 0x800823DC: nop

    // 0x800823E0: jr          $t4
    // 0x800823E4: nop

    switch (jr_addend_800823E0 >> 2) {
        case 0: goto L_800823E8; break;
        case 1: goto L_80082454; break;
        case 2: goto L_800824B8; break;
        case 3: goto L_80082524; break;
        case 4: goto L_8008256C; break;
        case 5: goto L_80082608; break;
        case 6: goto L_80082760; break;
        case 7: goto L_800827C0; break;
        default: switch_error(__func__, 0x800823E0, 0x800E836C);
    }
    // 0x800823E4: nop

L_800823E8:
    // 0x800823E8: lh          $a0, 0x18($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X18);
    // 0x800823EC: lh          $a1, 0x1A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1A);
    // 0x800823F0: lh          $a2, 0x1C($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X1C);
    // 0x800823F4: lh          $a3, 0x1E($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X1E);
    // 0x800823F8: jal         0x800C43CC
    // 0x800823FC: nop

    set_text_background_colour(rdram, ctx);
        goto after_1;
    // 0x800823FC: nop

    after_1:
    // 0x80082400: lbu         $t5, 0x10($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X10);
    // 0x80082404: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    // 0x80082408: lbu         $a1, 0xD($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XD);
    // 0x8008240C: lbu         $a2, 0xE($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0XE);
    // 0x80082410: lbu         $a3, 0xF($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0XF);
    // 0x80082414: jal         0x800C4384
    // 0x80082418: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x80082418: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x8008241C: lbu         $a0, 0x11($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X11);
    // 0x80082420: jal         0x800C42EC
    // 0x80082424: nop

    set_text_font(rdram, ctx);
        goto after_3;
    // 0x80082424: nop

    after_3:
    // 0x80082428: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x8008242C: lbu         $t7, 0x12($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X12);
    // 0x80082430: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80082434: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082438: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8008243C: addu        $a2, $s3, $t6
    ctx->r6 = ADD32(ctx->r19, ctx->r14);
    // 0x80082440: jal         0x800C4440
    // 0x80082444: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    draw_text(rdram, ctx);
        goto after_4;
    // 0x80082444: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_4:
    // 0x80082448: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8008244C: b           L_8008282C
    // 0x80082450: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_8008282C;
    // 0x80082450: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80082454:
    // 0x80082454: beq         $s5, $zero, L_80082464
    if (ctx->r21 == 0) {
        // 0x80082458: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80082464;
    }
    // 0x80082458: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8008245C: jal         0x8007B3D0
    // 0x80082460: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    rendermode_reset(rdram, ctx);
        goto after_5;
    // 0x80082460: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    after_5:
L_80082464:
    // 0x80082464: lbu         $t8, 0x10($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X10);
    // 0x80082468: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008246C: sw          $t8, -0x89C($at)
    MEM_W(-0X89C, ctx->r1) = ctx->r24;
    // 0x80082470: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80082474: lbu         $t2, 0xD($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XD);
    // 0x80082478: lbu         $a3, 0xC($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0XC);
    // 0x8008247C: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    // 0x80082480: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80082484: lbu         $t3, 0xE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XE);
    // 0x80082488: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x8008248C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80082490: lbu         $t4, 0x11($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X11);
    // 0x80082494: negu        $t0, $s3
    ctx->r8 = SUB32(0, ctx->r19);
    // 0x80082498: subu        $a2, $t0, $t1
    ctx->r6 = SUB32(ctx->r8, ctx->r9);
    // 0x8008249C: addiu       $a2, $a2, 0x78
    ctx->r6 = ADD32(ctx->r6, 0X78);
    // 0x800824A0: addiu       $a1, $s2, -0xA0
    ctx->r5 = ADD32(ctx->r18, -0XA0);
    // 0x800824A4: jal         0x80081800
    // 0x800824A8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    menu_timestamp_render(rdram, ctx);
        goto after_6;
    // 0x800824A8: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_6:
    // 0x800824AC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800824B0: b           L_8008282C
    // 0x800824B4: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_8008282C;
    // 0x800824B4: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_800824B8:
    // 0x800824B8: beq         $s5, $zero, L_800824D0
    if (ctx->r21 == 0) {
        // 0x800824BC: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800824D0;
    }
    // 0x800824BC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800824C0: jal         0x8007B3D0
    // 0x800824C4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    rendermode_reset(rdram, ctx);
        goto after_7;
    // 0x800824C4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    after_7:
    // 0x800824C8: lw          $s1, 0x14($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X14);
    // 0x800824CC: nop

L_800824D0:
    // 0x800824D0: lbu         $t7, 0xD($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XD);
    // 0x800824D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800824D8: lbu         $a3, 0xC($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0XC);
    // 0x800824DC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800824E0: lbu         $t8, 0xE($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XE);
    // 0x800824E4: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x800824E8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800824EC: lbu         $t9, 0x10($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X10);
    // 0x800824F0: negu        $t5, $s3
    ctx->r13 = SUB32(0, ctx->r19);
    // 0x800824F4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800824F8: lbu         $t0, 0x11($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X11);
    // 0x800824FC: subu        $a2, $t5, $t6
    ctx->r6 = SUB32(ctx->r13, ctx->r14);
    // 0x80082500: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80082504: lbu         $t1, 0x12($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X12);
    // 0x80082508: addiu       $a2, $a2, 0x78
    ctx->r6 = ADD32(ctx->r6, 0X78);
    // 0x8008250C: addiu       $a1, $s2, -0xA0
    ctx->r5 = ADD32(ctx->r18, -0XA0);
    // 0x80082510: jal         0x80081C04
    // 0x80082514: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    menu_number_render(rdram, ctx);
        goto after_8;
    // 0x80082514: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_8:
    // 0x80082518: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8008251C: b           L_8008282C
    // 0x80082520: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_8008282C;
    // 0x80082520: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80082524:
    // 0x80082524: lbu         $t3, 0xC($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XC);
    // 0x80082528: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x8008252C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80082530: lbu         $t4, 0xD($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XD);
    // 0x80082534: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082538: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8008253C: lbu         $t5, 0xE($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XE);
    // 0x80082540: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80082544: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80082548: lbu         $t6, 0x10($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X10);
    // 0x8008254C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80082550: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80082554: addu        $a3, $s3, $t2
    ctx->r7 = ADD32(ctx->r19, ctx->r10);
    // 0x80082558: jal         0x80078AB8
    // 0x8008255C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    texrect_draw(rdram, ctx);
        goto after_9;
    // 0x8008255C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_9:
    // 0x80082560: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80082564: b           L_8008282C
    // 0x80082568: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_8008282C;
    // 0x80082568: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_8008256C:
    // 0x8008256C: lh          $t9, 0x18($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X18);
    // 0x80082570: mtc1        $s2, $f16
    ctx->f16.u32l = ctx->r18;
    // 0x80082574: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80082578: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x8008257C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082580: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x80082584: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80082588: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8008258C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082590: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80082594: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80082598: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8008259C: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800825A0: lh          $t0, 0x1A($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X1A);
    // 0x800825A4: nop

    // 0x800825A8: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x800825AC: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800825B0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800825B4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800825B8: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800825BC: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x800825C0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800825C4: lbu         $t3, 0xD($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XD);
    // 0x800825C8: lbu         $t1, 0xC($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XC);
    // 0x800825CC: lbu         $t6, 0xE($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XE);
    // 0x800825D0: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800825D4: sll         $t2, $t1, 24
    ctx->r10 = S32(ctx->r9 << 24);
    // 0x800825D8: lbu         $t9, 0x10($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X10);
    // 0x800825DC: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x800825E0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800825E4: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x800825E8: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x800825EC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800825F0: lbu         $t1, 0x12($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X12);
    // 0x800825F4: jal         0x80078D00
    // 0x800825F8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    texrect_draw_scaled(rdram, ctx);
        goto after_10;
    // 0x800825F8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_10:
    // 0x800825FC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80082600: b           L_8008282C
    // 0x80082604: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_8008282C;
    // 0x80082604: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80082608:
    // 0x80082608: beq         $s5, $zero, L_80082618
    if (ctx->r21 == 0) {
        // 0x8008260C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80082618;
    }
    // 0x8008260C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082610: jal         0x8007B3D0
    // 0x80082614: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    rendermode_reset(rdram, ctx);
        goto after_11;
    // 0x80082614: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    after_11:
L_80082618:
    // 0x80082618: jal         0x80068508
    // 0x8008261C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_12;
    // 0x8008261C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x80082620: jal         0x8007BF1C
    // 0x80082624: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_13;
    // 0x80082624: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80082628: addiu       $t3, $s2, -0xA0
    ctx->r11 = ADD32(ctx->r18, -0XA0);
    // 0x8008262C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80082630: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x80082634: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082638: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x8008263C: sll         $t6, $t4, 5
    ctx->r14 = S32(ctx->r12 << 5);
    // 0x80082640: addu        $t5, $t2, $t6
    ctx->r13 = ADD32(ctx->r10, ctx->r14);
    // 0x80082644: swc1        $f6, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f6.u32l;
    // 0x80082648: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x8008264C: negu        $t7, $s3
    ctx->r15 = SUB32(0, ctx->r19);
    // 0x80082650: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80082654: addiu       $t0, $t9, 0x78
    ctx->r8 = ADD32(ctx->r25, 0X78);
    // 0x80082658: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8008265C: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x80082660: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80082664: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80082668: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x8008266C: addu        $t2, $t1, $t4
    ctx->r10 = ADD32(ctx->r9, ctx->r12);
    // 0x80082670: swc1        $f10, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->f10.u32l;
    // 0x80082674: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80082678: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x8008267C: lbu         $t6, 0x11($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X11);
    // 0x80082680: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80082684: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x80082688: sh          $t6, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r14;
    // 0x8008268C: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x80082690: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80082694: lh          $t0, 0x18($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X18);
    // 0x80082698: sll         $t4, $t1, 5
    ctx->r12 = S32(ctx->r9 << 5);
    // 0x8008269C: addu        $t2, $t3, $t4
    ctx->r10 = ADD32(ctx->r11, ctx->r12);
    // 0x800826A0: sh          $t0, 0x4($t2)
    MEM_H(0X4, ctx->r10) = ctx->r8;
    // 0x800826A4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800826A8: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800826AC: lh          $t7, 0x1A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A);
    // 0x800826B0: sll         $t6, $t8, 5
    ctx->r14 = S32(ctx->r24 << 5);
    // 0x800826B4: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x800826B8: sh          $t7, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r15;
    // 0x800826BC: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x800826C0: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800826C4: lh          $t1, 0x1C($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1C);
    // 0x800826C8: sll         $t0, $t4, 5
    ctx->r8 = S32(ctx->r12 << 5);
    // 0x800826CC: addu        $t2, $t3, $t0
    ctx->r10 = ADD32(ctx->r11, ctx->r8);
    // 0x800826D0: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x800826D4: lh          $t8, 0x1E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1E);
    // 0x800826D8: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x800826DC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800826E0: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800826E4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800826E8: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800826EC: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x800826F0: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x800826F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800826F8: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
    // 0x800826FC: lbu         $t4, 0xC($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XC);
    // 0x80082700: nop

    // 0x80082704: sb          $t4, -0xB5C($at)
    MEM_B(-0XB5C, ctx->r1) = ctx->r12;
    // 0x80082708: lbu         $t3, 0xD($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XD);
    // 0x8008270C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082710: sb          $t3, -0xB58($at)
    MEM_B(-0XB58, ctx->r1) = ctx->r11;
    // 0x80082714: lbu         $t0, 0xE($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XE);
    // 0x80082718: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008271C: sb          $t0, -0xB54($at)
    MEM_B(-0XB54, ctx->r1) = ctx->r8;
    // 0x80082720: lbu         $t1, 0xF($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XF);
    // 0x80082724: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082728: sb          $t1, -0xB50($at)
    MEM_B(-0XB50, ctx->r1) = ctx->r9;
    // 0x8008272C: lbu         $t2, 0x10($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X10);
    // 0x80082730: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082734: sw          $t2, -0x89C($at)
    MEM_W(-0X89C, ctx->r1) = ctx->r10;
    // 0x80082738: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x8008273C: jal         0x8009CA60
    // 0x80082740: nop

    menu_element_render(rdram, ctx);
        goto after_14;
    // 0x80082740: nop

    after_14:
    // 0x80082744: jal         0x80068508
    // 0x80082748: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_15;
    // 0x80082748: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x8008274C: jal         0x8007BF1C
    // 0x80082750: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_16;
    // 0x80082750: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x80082754: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80082758: b           L_8008282C
    // 0x8008275C: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_8008282C;
    // 0x8008275C: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_80082760:
    // 0x80082760: lh          $t6, 0x1A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A);
    // 0x80082764: lh          $a3, 0x18($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X18);
    // 0x80082768: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008276C: lh          $t5, 0x1C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1C);
    // 0x80082770: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80082774: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80082778: lh          $t7, 0x1E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1E);
    // 0x8008277C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082780: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80082784: lbu         $t9, 0xC($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XC);
    // 0x80082788: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8008278C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80082790: lbu         $t4, 0xD($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XD);
    // 0x80082794: addu        $a2, $s3, $t8
    ctx->r6 = ADD32(ctx->r19, ctx->r24);
    // 0x80082798: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8008279C: lbu         $t3, 0xE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XE);
    // 0x800827A0: nop

    // 0x800827A4: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800827A8: lbu         $t0, 0x10($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X10);
    // 0x800827AC: jal         0x80080E90
    // 0x800827B0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    func_80080E90(rdram, ctx);
        goto after_17;
    // 0x800827B0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_17:
    // 0x800827B4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800827B8: b           L_8008282C
    // 0x800827BC: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
        goto L_8008282C;
    // 0x800827BC: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_800827C0:
    // 0x800827C0: lh          $t2, 0x1A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X1A);
    // 0x800827C4: lh          $a3, 0x18($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X18);
    // 0x800827C8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800827CC: lh          $t8, 0x1C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1C);
    // 0x800827D0: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x800827D4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800827D8: lh          $t6, 0x1E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1E);
    // 0x800827DC: addu        $a2, $s3, $t1
    ctx->r6 = ADD32(ctx->r19, ctx->r9);
    // 0x800827E0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800827E4: lbu         $t9, 0xD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XD);
    // 0x800827E8: lbu         $t5, 0xC($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XC);
    // 0x800827EC: lbu         $t0, 0xE($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XE);
    // 0x800827F0: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x800827F4: sll         $t7, $t5, 24
    ctx->r15 = S32(ctx->r13 << 24);
    // 0x800827F8: lbu         $t8, 0x10($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X10);
    // 0x800827FC: or          $t3, $t7, $t4
    ctx->r11 = ctx->r15 | ctx->r12;
    // 0x80082800: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x80082804: or          $t2, $t3, $t1
    ctx->r10 = ctx->r11 | ctx->r9;
    // 0x80082808: or          $t6, $t2, $t8
    ctx->r14 = ctx->r10 | ctx->r24;
    // 0x8008280C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80082810: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80082814: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80082818: jal         0x80080580
    // 0x8008281C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80080580(rdram, ctx);
        goto after_18;
    // 0x8008281C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_18:
    // 0x80082820: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80082824: nop

L_80082828:
    // 0x80082828: lw          $s1, 0x34($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X34);
L_8008282C:
    // 0x8008282C: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x80082830: bne         $s1, $zero, L_80082284
    if (ctx->r17 != 0) {
        // 0x80082834: nop
    
            goto L_80082284;
    }
    // 0x80082834: nop

L_80082838:
    // 0x80082838: beq         $s5, $zero, L_8008284C
    if (ctx->r21 == 0) {
        // 0x8008283C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8008284C;
    }
    // 0x8008283C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80082840: jal         0x8007B3D0
    // 0x80082844: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    rendermode_reset(rdram, ctx);
        goto after_19;
    // 0x80082844: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_19:
    // 0x80082848: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_8008284C:
    // 0x8008284C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082850: sb          $v0, -0xB5C($at)
    MEM_B(-0XB5C, ctx->r1) = ctx->r2;
    // 0x80082854: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082858: sb          $v0, -0xB58($at)
    MEM_B(-0XB58, ctx->r1) = ctx->r2;
    // 0x8008285C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082860: sb          $v0, -0xB54($at)
    MEM_B(-0XB54, ctx->r1) = ctx->r2;
    // 0x80082864: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082868: sb          $zero, -0xB50($at)
    MEM_B(-0XB50, ctx->r1) = 0;
    // 0x8008286C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082870: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80082874: sw          $t5, -0x89C($at)
    MEM_W(-0X89C, ctx->r1) = ctx->r13;
L_80082878:
    // 0x80082878: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8008287C: lwc1        $f21, 0x38($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80082880: lwc1        $f20, 0x3C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80082884: lwc1        $f23, 0x40($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80082888: lwc1        $f22, 0x44($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8008288C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80082890: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80082894: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80082898: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8008289C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800828A0: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800828A4: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800828A8: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800828AC: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800828B0: jr          $ra
    // 0x800828B4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800828B4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void obj_loop_seamonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CF0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003CF10: jr          $ra
    // 0x8003CF14: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003CF14: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
