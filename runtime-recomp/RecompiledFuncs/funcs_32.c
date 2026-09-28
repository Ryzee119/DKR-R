#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void get_race_start_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800113AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800113B0: lw          $v0, -0x5248($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5248);
    // 0x800113B4: jr          $ra
    // 0x800113B8: nop

    return;
    // 0x800113B8: nop

;}
RECOMP_FUNC void rain_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD2C4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800AD2C8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800AD2CC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800AD2D0: bne         $t6, $zero, L_800AD31C
    if (ctx->r14 != 0) {
        // 0x800AD2D4: lui         $a2, 0x800E
        ctx->r6 = S32(0X800E << 16);
            goto L_800AD31C;
    }
    // 0x800AD2D4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800AD2D8: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x800AD2DC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800AD2E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800AD2E4: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800AD2E8: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800AD2EC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AD2F0: addiu       $v1, $v1, 0x2C78
    ctx->r3 = ADD32(ctx->r3, 0X2C78);
    // 0x800AD2F4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AD2F8: nop

    // 0x800AD2FC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AD300: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD304: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD308: nop

    // 0x800AD30C: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800AD310: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AD314: b           L_800AD360
    // 0x800AD318: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
        goto L_800AD360;
    // 0x800AD318: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
L_800AD31C:
    // 0x800AD31C: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x800AD320: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800AD324: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AD328: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x800AD32C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800AD330: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AD334: addiu       $v1, $v1, 0x2C78
    ctx->r3 = ADD32(ctx->r3, 0X2C78);
    // 0x800AD338: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AD33C: nop

    // 0x800AD340: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AD344: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AD348: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AD34C: nop

    // 0x800AD350: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800AD354: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AD358: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800AD35C: nop

L_800AD360:
    // 0x800AD360: addiu       $a2, $a2, 0x2C68
    ctx->r6 = ADD32(ctx->r6, 0X2C68);
    // 0x800AD364: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x800AD368: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AD36C: lw          $t0, 0x2C60($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2C60);
    // 0x800AD370: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800AD374: subu        $t1, $a0, $t0
    ctx->r9 = SUB32(ctx->r4, ctx->r8);
    // 0x800AD378: div         $zero, $t1, $v0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r2)));
    // 0x800AD37C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AD380: addiu       $a3, $a3, 0x2C74
    ctx->r7 = ADD32(ctx->r7, 0X2C74);
    // 0x800AD384: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800AD388: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x800AD38C: bne         $v0, $zero, L_800AD398
    if (ctx->r2 != 0) {
        // 0x800AD390: nop
    
            goto L_800AD398;
    }
    // 0x800AD390: nop

    // 0x800AD394: break       7
    do_break(2148193172);
L_800AD398:
    // 0x800AD398: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AD39C: bne         $v0, $at, L_800AD3B0
    if (ctx->r2 != ctx->r1) {
        // 0x800AD3A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AD3B0;
    }
    // 0x800AD3A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AD3A4: bne         $t1, $at, L_800AD3B0
    if (ctx->r9 != ctx->r1) {
        // 0x800AD3A8: nop
    
            goto L_800AD3B0;
    }
    // 0x800AD3A8: nop

    // 0x800AD3AC: break       6
    do_break(2148193196);
L_800AD3B0:
    // 0x800AD3B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD3B4: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x800AD3B8: mflo        $t2
    ctx->r10 = lo;
    // 0x800AD3BC: sw          $t2, 0x2C64($at)
    MEM_W(0X2C64, ctx->r1) = ctx->r10;
    // 0x800AD3C0: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x800AD3C4: lw          $t4, 0x2C6C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2C6C);
    // 0x800AD3C8: nop

    // 0x800AD3CC: subu        $t5, $a1, $t4
    ctx->r13 = SUB32(ctx->r5, ctx->r12);
    // 0x800AD3D0: div         $zero, $t5, $v0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r2)));
    // 0x800AD3D4: bne         $v0, $zero, L_800AD3E0
    if (ctx->r2 != 0) {
        // 0x800AD3D8: nop
    
            goto L_800AD3E0;
    }
    // 0x800AD3D8: nop

    // 0x800AD3DC: break       7
    do_break(2148193244);
L_800AD3E0:
    // 0x800AD3E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AD3E4: bne         $v0, $at, L_800AD3F8
    if (ctx->r2 != ctx->r1) {
        // 0x800AD3E8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AD3F8;
    }
    // 0x800AD3E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AD3EC: bne         $t5, $at, L_800AD3F8
    if (ctx->r13 != ctx->r1) {
        // 0x800AD3F0: nop
    
            goto L_800AD3F8;
    }
    // 0x800AD3F0: nop

    // 0x800AD3F4: break       6
    do_break(2148193268);
L_800AD3F8:
    // 0x800AD3F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD3FC: mflo        $t6
    ctx->r14 = lo;
    // 0x800AD400: sw          $t6, 0x2C70($at)
    MEM_W(0X2C70, ctx->r1) = ctx->r14;
    // 0x800AD404: jr          $ra
    // 0x800AD408: nop

    return;
    // 0x800AD408: nop

;}
RECOMP_FUNC void sndp_handle_event(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003470: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x80003474: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80003478: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8000347C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80003480: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80003484: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80003488: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8000348C: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80003490: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80003494: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80003498: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000349C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800034A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800034A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800034A8: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
    // 0x800034AC: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x800034B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800034B4: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x800034B8: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800034BC: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
L_800034C0:
    // 0x800034C0: nop

    // 0x800034C4: beq         $t7, $zero, L_800034E8
    if (ctx->r15 == 0) {
        // 0x800034C8: nop
    
            goto L_800034E8;
    }
    // 0x800034C8: nop

    // 0x800034CC: sw          $s1, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r17;
    // 0x800034D0: lhu         $t8, 0x0($s5)
    ctx->r24 = MEM_HU(ctx->r21, 0X0);
    // 0x800034D4: nop

    // 0x800034D8: sh          $t8, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r24;
    // 0x800034DC: lw          $t9, 0x8($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X8);
    // 0x800034E0: addiu       $s5, $sp, 0x9C
    ctx->r21 = ADD32(ctx->r29, 0X9C);
    // 0x800034E4: sw          $t9, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r25;
L_800034E8:
    // 0x800034E8: lw          $s1, 0x4($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X4);
    // 0x800034EC: nop

    // 0x800034F0: lw          $s2, 0x8($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X8);
    // 0x800034F4: nop

    // 0x800034F8: bne         $s2, $zero, L_80003510
    if (ctx->r18 != 0) {
        // 0x800034FC: addiu       $a0, $sp, 0x72
        ctx->r4 = ADD32(ctx->r29, 0X72);
            goto L_80003510;
    }
    // 0x800034FC: addiu       $a0, $sp, 0x72
    ctx->r4 = ADD32(ctx->r29, 0X72);
    // 0x80003500: jal         0x800042CC
    // 0x80003504: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    sndp_get_state_counts(rdram, ctx);
        goto after_0;
    // 0x80003504: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    after_0:
    // 0x80003508: b           L_800040E0
    // 0x8000350C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800040E0;
    // 0x8000350C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80003510:
    // 0x80003510: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80003514: lw          $s6, 0x4($s2)
    ctx->r22 = MEM_W(ctx->r18, 0X4);
    // 0x80003518: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x8000351C: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x80003520: nop

    // 0x80003524: slti        $at, $v1, 0x101
    ctx->r1 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
    // 0x80003528: bne         $at, $zero, L_8000355C
    if (ctx->r1 != 0) {
        // 0x8000352C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8000355C;
    }
    // 0x8000352C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80003530: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x80003534: beq         $v0, $at, L_8000400C
    if (ctx->r2 == ctx->r1) {
        // 0x80003538: addiu       $at, $zero, 0x400
        ctx->r1 = ADD32(0, 0X400);
            goto L_8000400C;
    }
    // 0x80003538: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x8000353C: beq         $v0, $at, L_80003A0C
    if (ctx->r2 == ctx->r1) {
        // 0x80003540: addiu       $at, $zero, 0x800
        ctx->r1 = ADD32(0, 0X800);
            goto L_80003A0C;
    }
    // 0x80003540: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x80003544: beq         $v0, $at, L_80003D78
    if (ctx->r2 == ctx->r1) {
        // 0x80003548: addiu       $at, $zero, 0x1000
        ctx->r1 = ADD32(0, 0X1000);
            goto L_80003D78;
    }
    // 0x80003548: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x8000354C: beq         $v0, $at, L_80003A10
    if (ctx->r2 == ctx->r1) {
        // 0x80003550: addiu       $at, $zero, 0x1000
        ctx->r1 = ADD32(0, 0X1000);
            goto L_80003A10;
    }
    // 0x80003550: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x80003554: b           L_80004094
    // 0x80003558: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
        goto L_80004094;
    // 0x80003558: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_8000355C:
    // 0x8000355C: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x80003560: bne         $at, $zero, L_80003580
    if (ctx->r1 != 0) {
        // 0x80003564: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_80003580;
    }
    // 0x80003564: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80003568: beq         $v0, $at, L_80003FF0
    if (ctx->r2 == ctx->r1) {
        // 0x8000356C: addiu       $at, $zero, 0x100
        ctx->r1 = ADD32(0, 0X100);
            goto L_80003FF0;
    }
    // 0x8000356C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x80003570: beq         $v0, $at, L_80003C08
    if (ctx->r2 == ctx->r1) {
        // 0x80003574: nop
    
            goto L_80003C08;
    }
    // 0x80003574: nop

    // 0x80003578: b           L_80004094
    // 0x8000357C: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
        goto L_80004094;
    // 0x8000357C: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_80003580:
    // 0x80003580: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x80003584: bne         $at, $zero, L_800035A0
    if (ctx->r1 != 0) {
        // 0x80003588: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_800035A0;
    }
    // 0x80003588: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8000358C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80003590: beq         $v0, $at, L_80003E8C
    if (ctx->r2 == ctx->r1) {
        // 0x80003594: nop
    
            goto L_80003E8C;
    }
    // 0x80003594: nop

    // 0x80003598: b           L_80004094
    // 0x8000359C: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
        goto L_80004094;
    // 0x8000359C: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_800035A0:
    // 0x800035A0: sltiu       $at, $t1, 0x10
    ctx->r1 = ctx->r9 < 0X10 ? 1 : 0;
    // 0x800035A4: beq         $at, $zero, L_80004090
    if (ctx->r1 == 0) {
        // 0x800035A8: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80004090;
    }
    // 0x800035A8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800035AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800035B0: addu        $at, $at, $t1
    gpr jr_addend_800035BC = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800035B4: lw          $t1, 0x4BB0($at)
    ctx->r9 = ADD32(ctx->r1, 0X4BB0);
    // 0x800035B8: nop

    // 0x800035BC: jr          $t1
    // 0x800035C0: nop

    switch (jr_addend_800035BC >> 2) {
        case 0: goto L_800035C4; break;
        case 1: goto L_80003A0C; break;
        case 2: goto L_80004090; break;
        case 3: goto L_80003B2C; break;
        case 4: goto L_80004090; break;
        case 5: goto L_80004090; break;
        case 6: goto L_80004090; break;
        case 7: goto L_80003C8C; break;
        case 8: goto L_80004090; break;
        case 9: goto L_80004090; break;
        case 10: goto L_80004090; break;
        case 11: goto L_80004090; break;
        case 12: goto L_80004090; break;
        case 13: goto L_80004090; break;
        case 14: goto L_80004090; break;
        case 15: goto L_80003BA4; break;
        default: switch_error(__func__, 0x800035BC, 0x800E4BB0);
    }
    // 0x800035C0: nop

L_800035C4:
    // 0x800035C4: lbu         $v0, 0x3F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3F);
    // 0x800035C8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800035CC: beq         $v0, $at, L_800035E0
    if (ctx->r2 == ctx->r1) {
        // 0x800035D0: lui         $t3, 0x800E
        ctx->r11 = S32(0X800E << 16);
            goto L_800035E0;
    }
    // 0x800035D0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800035D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800035D8: bne         $v0, $at, L_800040E0
    if (ctx->r2 != ctx->r1) {
        // 0x800035DC: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800040E0;
    }
    // 0x800035DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800035E0:
    // 0x800035E0: sh          $zero, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = 0;
    // 0x800035E4: lbu         $t2, 0x36($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X36);
    // 0x800035E8: sb          $zero, 0xCC($sp)
    MEM_B(0XCC, ctx->r29) = 0;
    // 0x800035EC: sh          $t2, 0xC8($sp)
    MEM_H(0XC8, ctx->r29) = ctx->r10;
    // 0x800035F0: lw          $t4, 0x48($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X48);
    // 0x800035F4: lh          $t3, -0x393C($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X393C);
    // 0x800035F8: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x800035FC: slt         $s0, $t3, $t4
    ctx->r16 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80003600: xori        $s0, $s0, 0x1
    ctx->r16 = ctx->r16 ^ 0X1;
    // 0x80003604: beq         $s0, $zero, L_80003620
    if (ctx->r16 == 0) {
        // 0x80003608: nop
    
            goto L_80003620;
    }
    // 0x80003608: nop

    // 0x8000360C: lbu         $t5, 0x3E($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003610: nop

    // 0x80003614: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x80003618: beq         $t6, $zero, L_80003634
    if (ctx->r14 == 0) {
        // 0x8000361C: lw          $t7, 0x7C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X7C);
            goto L_80003634;
    }
    // 0x8000361C: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_80003620:
    // 0x80003620: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003624: jal         0x800C9508
    // 0x80003628: addiu       $a2, $sp, 0xC8
    ctx->r6 = ADD32(ctx->r29, 0XC8);
    alSynAllocVoice(rdram, ctx);
        goto after_1;
    // 0x80003628: addiu       $a2, $sp, 0xC8
    ctx->r6 = ADD32(ctx->r29, 0XC8);
    after_1:
    // 0x8000362C: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80003630: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
L_80003634:
    // 0x80003634: sll         $a2, $fp, 16
    ctx->r6 = S32(ctx->r30 << 16);
    // 0x80003638: beq         $t7, $zero, L_80003650
    if (ctx->r15 == 0) {
        // 0x8000363C: sra         $t8, $a2, 16
        ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
            goto L_80003650;
    }
    // 0x8000363C: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80003640: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003644: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x80003648: jal         0x80065A80
    // 0x8000364C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    func_80065A80(rdram, ctx);
        goto after_2;
    // 0x8000364C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_2:
L_80003650:
    // 0x80003650: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80003654: lbu         $v0, 0x3E($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003658: bne         $t9, $zero, L_8000377C
    if (ctx->r25 != 0) {
        // 0x8000365C: addiu       $s3, $s1, 0xC
        ctx->r19 = ADD32(ctx->r17, 0XC);
            goto L_8000377C;
    }
    // 0x8000365C: addiu       $s3, $s1, 0xC
    ctx->r19 = ADD32(ctx->r17, 0XC);
    // 0x80003660: andi        $t0, $v0, 0x12
    ctx->r8 = ctx->r2 & 0X12;
    // 0x80003664: bne         $t0, $zero, L_8000367C
    if (ctx->r8 != 0) {
        // 0x80003668: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_8000367C;
    }
    // 0x80003668: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8000366C: lw          $t1, 0x38($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X38);
    // 0x80003670: nop

    // 0x80003674: blez        $t1, L_800036A4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80003678: nop
    
            goto L_800036A4;
    }
    // 0x80003678: nop

L_8000367C:
    // 0x8000367C: lw          $t3, 0x38($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X38);
    // 0x80003680: sb          $t2, 0x3F($s1)
    MEM_B(0X3F, ctx->r17) = ctx->r10;
    // 0x80003684: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80003688: sw          $t4, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r12;
    // 0x8000368C: addiu       $a0, $s7, 0x14
    ctx->r4 = ADD32(ctx->r23, 0X14);
    // 0x80003690: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80003694: jal         0x800C91AC
    // 0x80003698: ori         $a2, $zero, 0x8235
    ctx->r6 = 0 | 0X8235;
    alEvtqPostEvent(rdram, ctx);
        goto after_3;
    // 0x80003698: ori         $a2, $zero, 0x8235
    ctx->r6 = 0 | 0X8235;
    after_3:
    // 0x8000369C: b           L_800040E0
    // 0x800036A0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800040E0;
    // 0x800036A0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800036A4:
    // 0x800036A4: beq         $s0, $zero, L_8000376C
    if (ctx->r16 == 0) {
        // 0x800036A8: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8000376C;
    }
    // 0x800036A8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800036AC: lw          $v0, -0x394C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X394C);
    // 0x800036B0: addiu       $s4, $sp, 0x5C
    ctx->r20 = ADD32(ctx->r29, 0X5C);
    // 0x800036B4: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x800036B8: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_800036BC:
    // 0x800036BC: lbu         $t5, 0x36($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X36);
    // 0x800036C0: lbu         $t6, 0x36($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X36);
    // 0x800036C4: nop

    // 0x800036C8: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800036CC: bne         $at, $zero, L_80003724
    if (ctx->r1 != 0) {
        // 0x800036D0: nop
    
            goto L_80003724;
    }
    // 0x800036D0: nop

    // 0x800036D4: lbu         $t7, 0x3F($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3F);
    // 0x800036D8: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x800036DC: beq         $s2, $t7, L_80003724
    if (ctx->r18 == ctx->r15) {
        // 0x800036E0: addiu       $a0, $s7, 0x14
        ctx->r4 = ADD32(ctx->r23, 0X14);
            goto L_80003724;
    }
    // 0x800036E0: addiu       $a0, $s7, 0x14
    ctx->r4 = ADD32(ctx->r23, 0X14);
    // 0x800036E4: sh          $t8, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r24;
    // 0x800036E8: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x800036EC: sb          $s3, 0x3F($v0)
    MEM_B(0X3F, ctx->r2) = ctx->r19;
    // 0x800036F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800036F4: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x800036F8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800036FC: jal         0x800C91AC
    // 0x80003700: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    alEvtqPostEvent(rdram, ctx);
        goto after_4;
    // 0x80003700: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    after_4:
    // 0x80003704: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x80003708: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x8000370C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80003710: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    // 0x80003714: jal         0x800C9650
    // 0x80003718: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    alSynSetVol(rdram, ctx);
        goto after_5;
    // 0x80003718: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    after_5:
    // 0x8000371C: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x80003720: nop

L_80003724:
    // 0x80003724: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80003728: beq         $s0, $zero, L_80003738
    if (ctx->r16 == 0) {
        // 0x8000372C: nop
    
            goto L_80003738;
    }
    // 0x8000372C: nop

    // 0x80003730: bne         $v0, $zero, L_800036BC
    if (ctx->r2 != 0) {
        // 0x80003734: nop
    
            goto L_800036BC;
    }
    // 0x80003734: nop

L_80003738:
    // 0x80003738: bne         $s0, $zero, L_8000375C
    if (ctx->r16 != 0) {
        // 0x8000373C: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8000375C;
    }
    // 0x8000373C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80003740: sw          $t9, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r25;
    // 0x80003744: addiu       $a0, $s7, 0x14
    ctx->r4 = ADD32(ctx->r23, 0X14);
    // 0x80003748: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000374C: jal         0x800C91AC
    // 0x80003750: addiu       $a2, $zero, 0x3E9
    ctx->r6 = ADD32(0, 0X3E9);
    alEvtqPostEvent(rdram, ctx);
        goto after_6;
    // 0x80003750: addiu       $a2, $zero, 0x3E9
    ctx->r6 = ADD32(0, 0X3E9);
    after_6:
    // 0x80003754: b           L_800040E0
    // 0x80003758: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800040E0;
    // 0x80003758: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8000375C:
    // 0x8000375C: jal         0x8000410C
    // 0x80003760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_end(rdram, ctx);
        goto after_7;
    // 0x80003760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80003764: b           L_800040E0
    // 0x80003768: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800040E0;
    // 0x80003768: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8000376C:
    // 0x8000376C: jal         0x8000410C
    // 0x80003770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_end(rdram, ctx);
        goto after_8;
    // 0x80003770: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80003774: b           L_800040E0
    // 0x80003778: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800040E0;
    // 0x80003778: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8000377C:
    // 0x8000377C: ori         $t0, $v0, 0x4
    ctx->r8 = ctx->r2 | 0X4;
    // 0x80003780: sb          $t0, 0x3E($s1)
    MEM_B(0X3E, ctx->r17) = ctx->r8;
    // 0x80003784: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x80003788: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x8000378C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80003790: jal         0x800C96F0
    // 0x80003794: addiu       $s4, $s7, 0x14
    ctx->r20 = ADD32(ctx->r23, 0X14);
    alSynStartVoice(rdram, ctx);
        goto after_9;
    // 0x80003794: addiu       $s4, $s7, 0x14
    ctx->r20 = ADD32(ctx->r23, 0X14);
    after_9:
    // 0x80003798: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000379C: sb          $t1, 0x3F($s1)
    MEM_B(0X3F, ctx->r17) = ctx->r9;
    // 0x800037A0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800037A4: lh          $t2, -0x393C($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X393C);
    // 0x800037A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800037AC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800037B0: sh          $t3, -0x393C($at)
    MEM_H(-0X393C, ctx->r1) = ctx->r11;
    // 0x800037B4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800037B8: lwc1        $f8, 0x2C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800037BC: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800037C0: lwc1        $f16, 0x28($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800037C4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800037C8: lh          $t3, 0x34($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X34);
    // 0x800037CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800037D0: lbu         $t2, 0xC($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XC);
    // 0x800037D4: lbu         $t7, 0x2($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X2);
    // 0x800037D8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800037DC: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800037E0: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x800037E4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800037E8: lw          $t6, -0x63D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X63D8);
    // 0x800037EC: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800037F0: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x800037F4: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800037F8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800037FC: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80003800: mflo        $t4
    ctx->r12 = lo;
    // 0x80003804: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80003808: nop

    // 0x8000380C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80003810: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80003814: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80003818: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x8000381C: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80003820: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80003824: lbu         $t5, 0xD($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0XD);
    // 0x80003828: mfc1        $s0, $f4
    ctx->r16 = (int32_t)ctx->f4.u32l;
    // 0x8000382C: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003830: mflo        $t7
    ctx->r15 = lo;
    // 0x80003834: nop

    // 0x80003838: nop

    // 0x8000383C: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80003840: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80003844: mflo        $t8
    ctx->r24 = lo;
    // 0x80003848: nop

    // 0x8000384C: nop

    // 0x80003850: multu       $t1, $t8
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003854: mflo        $a0
    ctx->r4 = lo;
    // 0x80003858: nop

    // 0x8000385C: nop

    // 0x80003860: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80003864: mflo        $t6
    ctx->r14 = lo;
    // 0x80003868: addiu       $a0, $t6, -0x1
    ctx->r4 = ADD32(ctx->r14, -0X1);
    // 0x8000386C: bgez        $a0, L_8000387C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80003870: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8000387C;
    }
    // 0x80003870: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80003874: b           L_8000387C
    // 0x80003878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000387C;
    // 0x80003878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000387C:
    // 0x8000387C: lw          $t9, -0x3940($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3940);
    // 0x80003880: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003884: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003888: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8000388C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80003890: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80003894: mflo        $v0
    ctx->r2 = lo;
    // 0x80003898: srl         $t0, $v0, 8
    ctx->r8 = S32(U32(ctx->r2) >> 8);
    // 0x8000389C: jal         0x800C9650
    // 0x800038A0: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    alSynSetVol(rdram, ctx);
        goto after_10;
    // 0x800038A0: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    after_10:
    // 0x800038A4: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
    // 0x800038A8: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x800038AC: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800038B0: sra         $t2, $a2, 16
    ctx->r10 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800038B4: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x800038B8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800038BC: jal         0x800C9650
    // 0x800038C0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    alSynSetVol(rdram, ctx);
        goto after_11;
    // 0x800038C0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_11:
    // 0x800038C4: lbu         $t3, 0x3C($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X3C);
    // 0x800038C8: lbu         $t4, 0xC($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0XC);
    // 0x800038CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800038D0: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x800038D4: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x800038D8: blez        $v1, L_800038E8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800038DC: addiu       $a2, $zero, 0x7F
        ctx->r6 = ADD32(0, 0X7F);
            goto L_800038E8;
    }
    // 0x800038DC: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x800038E0: b           L_800038E8
    // 0x800038E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800038E8;
    // 0x800038E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800038E8:
    // 0x800038E8: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x800038EC: beq         $at, $zero, L_8000390C
    if (ctx->r1 == 0) {
        // 0x800038F0: nop
    
            goto L_8000390C;
    }
    // 0x800038F0: nop

    // 0x800038F4: blez        $v1, L_80003904
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800038F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80003904;
    }
    // 0x800038F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800038FC: b           L_8000390C
    // 0x80003900: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
        goto L_8000390C;
    // 0x80003900: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
L_80003904:
    // 0x80003904: b           L_8000390C
    // 0x80003908: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
        goto L_8000390C;
    // 0x80003908: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_8000390C:
    // 0x8000390C: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003910: jal         0x80065B20
    // 0x80003914: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    alSynSetPan(rdram, ctx);
        goto after_12;
    // 0x80003914: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_12:
    // 0x80003918: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8000391C: lwc1        $f8, 0x28($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80003920: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003924: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80003928: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8000392C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80003930: jal         0x800C9780
    // 0x80003934: nop

    alSynSetPitch(rdram, ctx);
        goto after_13;
    // 0x80003934: nop

    after_13:
    // 0x80003938: lbu         $t7, 0x3($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X3);
    // 0x8000393C: lbu         $t5, 0x3D($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X3D);
    // 0x80003940: andi        $t1, $t7, 0xF
    ctx->r9 = ctx->r15 & 0XF;
    // 0x80003944: addu        $v1, $t5, $t1
    ctx->r3 = ADD32(ctx->r13, ctx->r9);
    // 0x80003948: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8000394C: bgez        $t8, L_8000395C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80003950: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_8000395C;
    }
    // 0x80003950: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80003954: b           L_80003960
    // 0x80003958: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003960;
    // 0x80003958: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000395C:
    // 0x8000395C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80003960:
    // 0x80003960: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80003964: bne         $at, $zero, L_80003974
    if (ctx->r1 != 0) {
        // 0x80003968: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_80003974;
    }
    // 0x80003968: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8000396C: b           L_80003988
    // 0x80003970: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
        goto L_80003988;
    // 0x80003970: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_80003974:
    // 0x80003974: bgez        $v1, L_80003984
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80003978: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80003984;
    }
    // 0x80003978: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000397C: b           L_80003984
    // 0x80003980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003984;
    // 0x80003980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003984:
    // 0x80003984: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80003988:
    // 0x80003988: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x8000398C: jal         0x800C9810
    // 0x80003990: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    alSynSetFXMix(rdram, ctx);
        goto after_14;
    // 0x80003990: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    after_14:
    // 0x80003994: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x80003998: sh          $t6, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r14;
    // 0x8000399C: sw          $s1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r17;
    // 0x800039A0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800039A4: lwc1        $f4, 0x2C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800039A8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800039AC: lwc1        $f8, 0x28($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800039B0: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800039B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800039B8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800039BC: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x800039C0: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800039C4: nop

    // 0x800039C8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800039CC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800039D0: nop

    // 0x800039D4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800039D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800039DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800039E0: nop

    // 0x800039E4: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800039E8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800039EC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800039F0: jal         0x800C91AC
    // 0x800039F4: nop

    alEvtqPostEvent(rdram, ctx);
        goto after_15;
    // 0x800039F4: nop

    after_15:
    // 0x800039F8: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x800039FC: nop

    // 0x80003A00: andi        $t3, $v0, 0x2D1
    ctx->r11 = ctx->r2 & 0X2D1;
    // 0x80003A04: b           L_80004094
    // 0x80003A08: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_80004094;
    // 0x80003A08: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80003A0C:
    // 0x80003A0C: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
L_80003A10:
    // 0x80003A10: bne         $v1, $at, L_80003A2C
    if (ctx->r3 != ctx->r1) {
        // 0x80003A14: nop
    
            goto L_80003A2C;
    }
    // 0x80003A14: nop

    // 0x80003A18: lbu         $t4, 0x3E($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003A1C: nop

    // 0x80003A20: andi        $t7, $t4, 0x2
    ctx->r15 = ctx->r12 & 0X2;
    // 0x80003A24: beq         $t7, $zero, L_80003B24
    if (ctx->r15 == 0) {
        // 0x80003A28: nop
    
            goto L_80003B24;
    }
    // 0x80003A28: nop

L_80003A2C:
    // 0x80003A2C: lbu         $v0, 0x3F($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003A30: addiu       $s4, $s7, 0x14
    ctx->r20 = ADD32(ctx->r23, 0X14);
    // 0x80003A34: beq         $v0, $fp, L_80003A58
    if (ctx->r2 == ctx->r30) {
        // 0x80003A38: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80003A58;
    }
    // 0x80003A38: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003A3C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80003A40: beq         $v0, $at, L_80003B00
    if (ctx->r2 == ctx->r1) {
        // 0x80003A44: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80003B00;
    }
    // 0x80003A44: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80003A48: beq         $v0, $at, L_80003B00
    if (ctx->r2 == ctx->r1) {
        // 0x80003A4C: nop
    
            goto L_80003B00;
    }
    // 0x80003A4C: nop

    // 0x80003A50: b           L_80003B14
    // 0x80003A54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
        goto L_80003B14;
    // 0x80003A54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80003A58:
    // 0x80003A58: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80003A5C: jal         0x800041FC
    // 0x80003A60: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    static_3_800041FC(rdram, ctx);
        goto after_16;
    // 0x80003A60: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_16:
    // 0x80003A64: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80003A68: lwc1        $f6, 0x28($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80003A6C: lw          $t1, 0x8($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X8);
    // 0x80003A70: lwc1        $f10, 0x2C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80003A74: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80003A78: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003A7C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80003A80: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003A84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80003A88: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80003A8C: nop

    // 0x80003A90: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80003A94: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80003A98: nop

    // 0x80003A9C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80003AA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80003AA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80003AA8: nop

    // 0x80003AAC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80003AB0: mfc1        $s0, $f18
    ctx->r16 = (int32_t)ctx->f18.u32l;
    // 0x80003AB4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80003AB8: jal         0x800C9650
    // 0x80003ABC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    alSynSetVol(rdram, ctx);
        goto after_17;
    // 0x80003ABC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_17:
    // 0x80003AC0: beq         $s0, $zero, L_80003AEC
    if (ctx->r16 == 0) {
        // 0x80003AC4: addiu       $t6, $zero, 0x80
        ctx->r14 = ADD32(0, 0X80);
            goto L_80003AEC;
    }
    // 0x80003AC4: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x80003AC8: sh          $t6, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r14;
    // 0x80003ACC: sw          $s1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r17;
    // 0x80003AD0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003AD4: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80003AD8: jal         0x800C91AC
    // 0x80003ADC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_18;
    // 0x80003ADC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_18:
    // 0x80003AE0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80003AE4: b           L_80003AF4
    // 0x80003AE8: sb          $t9, 0x3F($s1)
    MEM_B(0X3F, ctx->r17) = ctx->r25;
        goto L_80003AF4;
    // 0x80003AE8: sb          $t9, 0x3F($s1)
    MEM_B(0X3F, ctx->r17) = ctx->r25;
L_80003AEC:
    // 0x80003AEC: jal         0x8000410C
    // 0x80003AF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_end(rdram, ctx);
        goto after_19;
    // 0x80003AF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
L_80003AF4:
    // 0x80003AF4: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x80003AF8: b           L_80003B14
    // 0x80003AFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
        goto L_80003B14;
    // 0x80003AFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80003B00:
    // 0x80003B00: jal         0x8000410C
    // 0x80003B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_end(rdram, ctx);
        goto after_20;
    // 0x80003B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x80003B08: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x80003B0C: nop

    // 0x80003B10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80003B14:
    // 0x80003B14: bne         $v1, $at, L_80003B24
    if (ctx->r3 != ctx->r1) {
        // 0x80003B18: addiu       $t0, $zero, 0x1000
        ctx->r8 = ADD32(0, 0X1000);
            goto L_80003B24;
    }
    // 0x80003B18: addiu       $t0, $zero, 0x1000
    ctx->r8 = ADD32(0, 0X1000);
    // 0x80003B1C: sh          $t0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r8;
    // 0x80003B20: andi        $v1, $t0, 0xFFFF
    ctx->r3 = ctx->r8 & 0XFFFF;
L_80003B24:
    // 0x80003B24: b           L_80004094
    // 0x80003B28: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
        goto L_80004094;
    // 0x80003B28: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_80003B2C:
    // 0x80003B2C: lw          $t2, 0x8($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X8);
    // 0x80003B30: lbu         $t3, 0x3F($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003B34: sb          $t2, 0x3C($s1)
    MEM_B(0X3C, ctx->r17) = ctx->r10;
    // 0x80003B38: bne         $fp, $t3, L_80003B90
    if (ctx->r30 != ctx->r11) {
        // 0x80003B3C: nop
    
            goto L_80003B90;
    }
    // 0x80003B3C: nop

    // 0x80003B40: lbu         $t7, 0xC($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0XC);
    // 0x80003B44: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x80003B48: addu        $v1, $t4, $t7
    ctx->r3 = ADD32(ctx->r12, ctx->r15);
    // 0x80003B4C: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x80003B50: blez        $v1, L_80003B60
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80003B54: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80003B60;
    }
    // 0x80003B54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003B58: b           L_80003B60
    // 0x80003B5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80003B60;
    // 0x80003B5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80003B60:
    // 0x80003B60: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x80003B64: beq         $at, $zero, L_80003B84
    if (ctx->r1 == 0) {
        // 0x80003B68: addiu       $a2, $zero, 0x7F
        ctx->r6 = ADD32(0, 0X7F);
            goto L_80003B84;
    }
    // 0x80003B68: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
    // 0x80003B6C: blez        $v1, L_80003B7C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80003B70: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80003B7C;
    }
    // 0x80003B70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003B74: b           L_80003B84
    // 0x80003B78: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
        goto L_80003B84;
    // 0x80003B78: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
L_80003B7C:
    // 0x80003B7C: b           L_80003B84
    // 0x80003B80: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
        goto L_80003B84;
    // 0x80003B80: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_80003B84:
    // 0x80003B84: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003B88: jal         0x80065B20
    // 0x80003B8C: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    alSynSetPan(rdram, ctx);
        goto after_21;
    // 0x80003B8C: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    after_21:
L_80003B90:
    // 0x80003B90: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003B94: nop

    // 0x80003B98: andi        $t5, $v0, 0x2D1
    ctx->r13 = ctx->r2 & 0X2D1;
    // 0x80003B9C: b           L_80004094
    // 0x80003BA0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_80004094;
    // 0x80003BA0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80003BA4:
    // 0x80003BA4: lwc1        $f4, 0x8($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80003BA8: lbu         $t1, 0x3F($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003BAC: swc1        $f4, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f4.u32l;
    // 0x80003BB0: bne         $fp, $t1, L_80003BF4
    if (ctx->r30 != ctx->r9) {
        // 0x80003BB4: nop
    
            goto L_80003BF4;
    }
    // 0x80003BB4: nop

    // 0x80003BB8: lwc1        $f6, 0x2C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80003BBC: lwc1        $f8, 0x28($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80003BC0: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003BC4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80003BC8: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003BCC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80003BD0: jal         0x800C9780
    // 0x80003BD4: nop

    alSynSetPitch(rdram, ctx);
        goto after_22;
    // 0x80003BD4: nop

    after_22:
    // 0x80003BD8: lbu         $t8, 0x3E($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003BDC: nop

    // 0x80003BE0: andi        $t6, $t8, 0x20
    ctx->r14 = ctx->r24 & 0X20;
    // 0x80003BE4: beq         $t6, $zero, L_80003BF4
    if (ctx->r14 == 0) {
        // 0x80003BE8: nop
    
            goto L_80003BF4;
    }
    // 0x80003BE8: nop

    // 0x80003BEC: jal         0x8000418C
    // 0x80003BF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_apply_pitch_slide(rdram, ctx);
        goto after_23;
    // 0x80003BF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
L_80003BF4:
    // 0x80003BF4: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003BF8: nop

    // 0x80003BFC: andi        $t9, $v0, 0x2D1
    ctx->r25 = ctx->r2 & 0X2D1;
    // 0x80003C00: b           L_80004094
    // 0x80003C04: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80004094;
    // 0x80003C04: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80003C08:
    // 0x80003C08: lw          $t0, 0x8($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X8);
    // 0x80003C0C: lbu         $t2, 0x3F($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003C10: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003C14: bne         $fp, $t2, L_80003C78
    if (ctx->r30 != ctx->r10) {
        // 0x80003C18: sb          $t0, 0x3D($s1)
        MEM_B(0X3D, ctx->r17) = ctx->r8;
            goto L_80003C78;
    }
    // 0x80003C18: sb          $t0, 0x3D($s1)
    MEM_B(0X3D, ctx->r17) = ctx->r8;
    // 0x80003C1C: lbu         $t4, 0x3($s6)
    ctx->r12 = MEM_BU(ctx->r22, 0X3);
    // 0x80003C20: andi        $t3, $t0, 0xFF
    ctx->r11 = ctx->r8 & 0XFF;
    // 0x80003C24: andi        $t7, $t4, 0xF
    ctx->r15 = ctx->r12 & 0XF;
    // 0x80003C28: addu        $v1, $t3, $t7
    ctx->r3 = ADD32(ctx->r11, ctx->r15);
    // 0x80003C2C: sll         $t5, $v1, 3
    ctx->r13 = S32(ctx->r3 << 3);
    // 0x80003C30: bgez        $t5, L_80003C40
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80003C34: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_80003C40;
    }
    // 0x80003C34: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x80003C38: b           L_80003C44
    // 0x80003C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003C44;
    // 0x80003C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003C40:
    // 0x80003C40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80003C44:
    // 0x80003C44: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80003C48: bne         $at, $zero, L_80003C58
    if (ctx->r1 != 0) {
        // 0x80003C4C: nop
    
            goto L_80003C58;
    }
    // 0x80003C4C: nop

    // 0x80003C50: b           L_80003C6C
    // 0x80003C54: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
        goto L_80003C6C;
    // 0x80003C54: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_80003C58:
    // 0x80003C58: bgez        $v1, L_80003C68
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80003C5C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80003C68;
    }
    // 0x80003C5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80003C60: b           L_80003C68
    // 0x80003C64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003C68;
    // 0x80003C64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003C68:
    // 0x80003C68: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80003C6C:
    // 0x80003C6C: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003C70: jal         0x800C9810
    // 0x80003C74: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    alSynSetFXMix(rdram, ctx);
        goto after_24;
    // 0x80003C74: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    after_24:
L_80003C78:
    // 0x80003C78: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003C7C: nop

    // 0x80003C80: andi        $t1, $v0, 0x2D1
    ctx->r9 = ctx->r2 & 0X2D1;
    // 0x80003C84: b           L_80004094
    // 0x80003C88: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_80004094;
    // 0x80003C88: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80003C8C:
    // 0x80003C8C: lw          $t8, 0x8($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X8);
    // 0x80003C90: lbu         $t6, 0x3F($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003C94: sh          $t8, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r24;
    // 0x80003C98: bne         $fp, $t6, L_80003D64
    if (ctx->r30 != ctx->r14) {
        // 0x80003C9C: nop
    
            goto L_80003D64;
    }
    // 0x80003C9C: nop

    // 0x80003CA0: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80003CA4: lh          $t8, 0x34($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X34);
    // 0x80003CA8: lbu         $t1, 0xD($t5)
    ctx->r9 = MEM_BU(ctx->r13, 0XD);
    // 0x80003CAC: lbu         $t0, 0x2($s6)
    ctx->r8 = MEM_BU(ctx->r22, 0X2);
    // 0x80003CB0: multu       $t1, $t8
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003CB4: andi        $t2, $t0, 0x3F
    ctx->r10 = ctx->r8 & 0X3F;
    // 0x80003CB8: lbu         $t0, 0xD($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0XD);
    // 0x80003CBC: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80003CC0: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x80003CC4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80003CC8: lw          $t9, -0x63D8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X63D8);
    // 0x80003CCC: nop

    // 0x80003CD0: addu        $t3, $t9, $t4
    ctx->r11 = ADD32(ctx->r25, ctx->r12);
    // 0x80003CD4: lh          $t7, 0x0($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X0);
    // 0x80003CD8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80003CDC: mflo        $t6
    ctx->r14 = lo;
    // 0x80003CE0: nop

    // 0x80003CE4: nop

    // 0x80003CE8: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003CEC: mflo        $t2
    ctx->r10 = lo;
    // 0x80003CF0: nop

    // 0x80003CF4: nop

    // 0x80003CF8: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80003CFC: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80003D00: mflo        $t9
    ctx->r25 = lo;
    // 0x80003D04: nop

    // 0x80003D08: nop

    // 0x80003D0C: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003D10: mflo        $a0
    ctx->r4 = lo;
    // 0x80003D14: nop

    // 0x80003D18: nop

    // 0x80003D1C: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80003D20: mflo        $t4
    ctx->r12 = lo;
    // 0x80003D24: addiu       $a0, $t4, -0x1
    ctx->r4 = ADD32(ctx->r12, -0X1);
    // 0x80003D28: bgez        $a0, L_80003D38
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80003D2C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80003D38;
    }
    // 0x80003D2C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80003D30: b           L_80003D38
    // 0x80003D34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003D38;
    // 0x80003D34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003D38:
    // 0x80003D38: lw          $t3, -0x3940($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3940);
    // 0x80003D3C: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003D40: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003D44: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003D48: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    // 0x80003D4C: mflo        $v0
    ctx->r2 = lo;
    // 0x80003D50: srl         $t5, $v0, 8
    ctx->r13 = S32(U32(ctx->r2) >> 8);
    // 0x80003D54: sll         $a2, $t5, 16
    ctx->r6 = S32(ctx->r13 << 16);
    // 0x80003D58: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80003D5C: jal         0x800C9650
    // 0x80003D60: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    alSynSetVol(rdram, ctx);
        goto after_25;
    // 0x80003D60: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    after_25:
L_80003D64:
    // 0x80003D64: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003D68: nop

    // 0x80003D6C: andi        $t8, $v0, 0x2D1
    ctx->r24 = ctx->r2 & 0X2D1;
    // 0x80003D70: b           L_80004094
    // 0x80003D74: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_80004094;
    // 0x80003D74: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80003D78:
    // 0x80003D78: lbu         $t6, 0x3F($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X3F);
    // 0x80003D7C: nop

    // 0x80003D80: bne         $fp, $t6, L_80003E84
    if (ctx->r30 != ctx->r14) {
        // 0x80003D84: nop
    
            goto L_80003E84;
    }
    // 0x80003D84: nop

    // 0x80003D88: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80003D8C: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80003D90: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x80003D94: lwc1        $f8, 0x2C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80003D98: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80003D9C: lh          $t6, 0x34($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X34);
    // 0x80003DA0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80003DA4: lbu         $t8, 0xD($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XD);
    // 0x80003DA8: lbu         $t9, 0x2($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X2);
    // 0x80003DAC: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80003DB0: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003DB4: andi        $t4, $t9, 0x3F
    ctx->r12 = ctx->r25 & 0X3F;
    // 0x80003DB8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80003DBC: lw          $t7, -0x63D8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X63D8);
    // 0x80003DC0: sll         $t3, $t4, 1
    ctx->r11 = S32(ctx->r12 << 1);
    // 0x80003DC4: addu        $t5, $t7, $t3
    ctx->r13 = ADD32(ctx->r15, ctx->r11);
    // 0x80003DC8: lh          $t1, 0x0($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X0);
    // 0x80003DCC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80003DD0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80003DD4: mflo        $t0
    ctx->r8 = lo;
    // 0x80003DD8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80003DDC: nop

    // 0x80003DE0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80003DE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80003DE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80003DEC: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x80003DF0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80003DF4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80003DF8: lbu         $t2, 0xD($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0XD);
    // 0x80003DFC: mfc1        $s0, $f16
    ctx->r16 = (int32_t)ctx->f16.u32l;
    // 0x80003E00: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003E04: mflo        $t9
    ctx->r25 = lo;
    // 0x80003E08: nop

    // 0x80003E0C: nop

    // 0x80003E10: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80003E14: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80003E18: mflo        $t4
    ctx->r12 = lo;
    // 0x80003E1C: nop

    // 0x80003E20: nop

    // 0x80003E24: multu       $t1, $t4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003E28: mflo        $a0
    ctx->r4 = lo;
    // 0x80003E2C: nop

    // 0x80003E30: nop

    // 0x80003E34: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80003E38: mflo        $t7
    ctx->r15 = lo;
    // 0x80003E3C: addiu       $a0, $t7, -0x1
    ctx->r4 = ADD32(ctx->r15, -0X1);
    // 0x80003E40: bgez        $a0, L_80003E50
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80003E44: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80003E50;
    }
    // 0x80003E44: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80003E48: b           L_80003E50
    // 0x80003E4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003E50;
    // 0x80003E4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003E50:
    // 0x80003E50: lw          $t3, -0x3940($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3940);
    // 0x80003E54: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003E58: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003E5C: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003E60: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80003E64: mflo        $v0
    ctx->r2 = lo;
    // 0x80003E68: srl         $t5, $v0, 8
    ctx->r13 = S32(U32(ctx->r2) >> 8);
    // 0x80003E6C: sll         $a2, $t5, 16
    ctx->r6 = S32(ctx->r13 << 16);
    // 0x80003E70: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80003E74: jal         0x800C9650
    // 0x80003E78: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    alSynSetVol(rdram, ctx);
        goto after_26;
    // 0x80003E78: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_26:
    // 0x80003E7C: lhu         $v1, 0x0($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X0);
    // 0x80003E80: nop

L_80003E84:
    // 0x80003E84: b           L_80004094
    // 0x80003E88: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
        goto L_80004094;
    // 0x80003E88: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_80003E8C:
    // 0x80003E8C: lbu         $t6, 0x3E($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003E90: nop

    // 0x80003E94: andi        $t0, $t6, 0x2
    ctx->r8 = ctx->r14 & 0X2;
    // 0x80003E98: bne         $t0, $zero, L_80003FDC
    if (ctx->r8 != 0) {
        // 0x80003E9C: nop
    
            goto L_80003FDC;
    }
    // 0x80003E9C: nop

    // 0x80003EA0: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80003EA4: lh          $t8, 0x34($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X34);
    // 0x80003EA8: lbu         $t5, 0xD($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XD);
    // 0x80003EAC: lbu         $t0, 0xD($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0XD);
    // 0x80003EB0: multu       $t5, $t8
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003EB4: lbu         $t9, 0x2($s6)
    ctx->r25 = MEM_BU(ctx->r22, 0X2);
    // 0x80003EB8: addiu       $at, $zero, 0x3F01
    ctx->r1 = ADD32(0, 0X3F01);
    // 0x80003EBC: andi        $t1, $t9, 0x3F
    ctx->r9 = ctx->r25 & 0X3F;
    // 0x80003EC0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80003EC4: lw          $t2, -0x63D8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X63D8);
    // 0x80003EC8: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x80003ECC: addu        $t7, $t2, $t4
    ctx->r15 = ADD32(ctx->r10, ctx->r12);
    // 0x80003ED0: lh          $t3, 0x0($t7)
    ctx->r11 = MEM_H(ctx->r15, 0X0);
    // 0x80003ED4: addiu       $s4, $s7, 0x14
    ctx->r20 = ADD32(ctx->r23, 0X14);
    // 0x80003ED8: mflo        $t6
    ctx->r14 = lo;
    // 0x80003EDC: nop

    // 0x80003EE0: nop

    // 0x80003EE4: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003EE8: mflo        $t9
    ctx->r25 = lo;
    // 0x80003EEC: nop

    // 0x80003EF0: nop

    // 0x80003EF4: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80003EF8: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80003EFC: mflo        $t1
    ctx->r9 = lo;
    // 0x80003F00: nop

    // 0x80003F04: nop

    // 0x80003F08: multu       $t3, $t1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003F0C: mflo        $a0
    ctx->r4 = lo;
    // 0x80003F10: nop

    // 0x80003F14: nop

    // 0x80003F18: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80003F1C: mflo        $t2
    ctx->r10 = lo;
    // 0x80003F20: addiu       $a0, $t2, -0x1
    ctx->r4 = ADD32(ctx->r10, -0X1);
    // 0x80003F24: bgez        $a0, L_80003F34
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80003F28: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80003F34;
    }
    // 0x80003F28: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80003F2C: b           L_80003F34
    // 0x80003F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003F34;
    // 0x80003F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003F34:
    // 0x80003F34: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x80003F38: lwc1        $f6, 0x28($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80003F3C: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80003F40: lwc1        $f10, 0x2C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80003F44: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80003F48: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80003F4C: lw          $t4, -0x3940($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3940);
    // 0x80003F50: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80003F54: multu       $v0, $t4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003F58: lw          $a0, 0x38($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X38);
    // 0x80003F5C: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x80003F60: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80003F64: mflo        $v0
    ctx->r2 = lo;
    // 0x80003F68: srl         $t7, $v0, 8
    ctx->r15 = S32(U32(ctx->r2) >> 8);
    // 0x80003F6C: sll         $a2, $t7, 16
    ctx->r6 = S32(ctx->r15 << 16);
    // 0x80003F70: sra         $t6, $a2, 16
    ctx->r14 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80003F74: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80003F78: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80003F7C: nop

    // 0x80003F80: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80003F84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80003F88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80003F8C: nop

    // 0x80003F90: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80003F94: mfc1        $s0, $f18
    ctx->r16 = (int32_t)ctx->f18.u32l;
    // 0x80003F98: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80003F9C: jal         0x800C9650
    // 0x80003FA0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    alSynSetVol(rdram, ctx);
        goto after_27;
    // 0x80003FA0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_27:
    // 0x80003FA4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80003FA8: sh          $t0, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r8;
    // 0x80003FAC: sw          $s1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r17;
    // 0x80003FB0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003FB4: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x80003FB8: jal         0x800C91AC
    // 0x80003FBC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_28;
    // 0x80003FBC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_28:
    // 0x80003FC0: lbu         $t9, 0x3E($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X3E);
    // 0x80003FC4: nop

    // 0x80003FC8: andi        $t3, $t9, 0x20
    ctx->r11 = ctx->r25 & 0X20;
    // 0x80003FCC: beq         $t3, $zero, L_80003FDC
    if (ctx->r11 == 0) {
        // 0x80003FD0: nop
    
            goto L_80003FDC;
    }
    // 0x80003FD0: nop

    // 0x80003FD4: jal         0x8000418C
    // 0x80003FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_apply_pitch_slide(rdram, ctx);
        goto after_29;
    // 0x80003FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_29:
L_80003FDC:
    // 0x80003FDC: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003FE0: nop

    // 0x80003FE4: andi        $t1, $v0, 0x2D1
    ctx->r9 = ctx->r2 & 0X2D1;
    // 0x80003FE8: b           L_80004094
    // 0x80003FEC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_80004094;
    // 0x80003FEC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80003FF0:
    // 0x80003FF0: jal         0x8000410C
    // 0x80003FF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    sndp_end(rdram, ctx);
        goto after_30;
    // 0x80003FF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_30:
    // 0x80003FF8: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80003FFC: nop

    // 0x80004000: andi        $t2, $v0, 0x2D1
    ctx->r10 = ctx->r2 & 0X2D1;
    // 0x80004004: b           L_80004094
    // 0x80004008: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_80004094;
    // 0x80004008: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8000400C:
    // 0x8000400C: lbu         $t4, 0x3E($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X3E);
    // 0x80004010: nop

    // 0x80004014: andi        $t7, $t4, 0x10
    ctx->r15 = ctx->r12 & 0X10;
    // 0x80004018: beq         $t7, $zero, L_8000407C
    if (ctx->r15 == 0) {
        // 0x8000401C: nop
    
            goto L_8000407C;
    }
    // 0x8000401C: nop

    // 0x80004020: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x80004024: lh          $a1, 0xA($s5)
    ctx->r5 = MEM_H(ctx->r21, 0XA);
    // 0x80004028: lw          $a2, 0x30($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X30);
    // 0x8000402C: jal         0x80004638
    // 0x80004030: nop

    sndp_play(rdram, ctx);
        goto after_31;
    // 0x80004030: nop

    after_31:
    // 0x80004034: beq         $v0, $zero, L_8000407C
    if (ctx->r2 == 0) {
        // 0x80004038: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000407C;
    }
    // 0x80004038: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000403C: lh          $a2, 0x34($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X34);
    // 0x80004040: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80004044: jal         0x800049F8
    // 0x80004048: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    sndp_set_param(rdram, ctx);
        goto after_32;
    // 0x80004048: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_32:
    // 0x8000404C: lbu         $a2, 0x3C($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X3C);
    // 0x80004050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004054: jal         0x800049F8
    // 0x80004058: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sndp_set_param(rdram, ctx);
        goto after_33;
    // 0x80004058: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_33:
    // 0x8000405C: lbu         $a2, 0x3D($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X3D);
    // 0x80004060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004064: jal         0x800049F8
    // 0x80004068: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    sndp_set_param(rdram, ctx);
        goto after_34;
    // 0x80004068: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    after_34:
    // 0x8000406C: lw          $a2, 0x2C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2C);
    // 0x80004070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004074: jal         0x800049F8
    // 0x80004078: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_35;
    // 0x80004078: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_35:
L_8000407C:
    // 0x8000407C: lhu         $v0, 0x0($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X0);
    // 0x80004080: nop

    // 0x80004084: andi        $t5, $v0, 0x2D1
    ctx->r13 = ctx->r2 & 0X2D1;
    // 0x80004088: b           L_80004094
    // 0x8000408C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_80004094;
    // 0x8000408C: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_80004090:
    // 0x80004090: andi        $v0, $v1, 0x2D1
    ctx->r2 = ctx->r3 & 0X2D1;
L_80004094:
    // 0x80004094: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x80004098: nop

    // 0x8000409C: beq         $v1, $zero, L_800040BC
    if (ctx->r3 == 0) {
        // 0x800040A0: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_800040BC;
    }
    // 0x800040A0: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x800040A4: bne         $v0, $zero, L_800040C0
    if (ctx->r2 != 0) {
        // 0x800040A8: lw          $t0, 0x80($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X80);
            goto L_800040C0;
    }
    // 0x800040A8: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x800040AC: lbu         $t8, 0x3E($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3E);
    // 0x800040B0: nop

    // 0x800040B4: andi        $t6, $t8, 0x1
    ctx->r14 = ctx->r24 & 0X1;
    // 0x800040B8: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
L_800040BC:
    // 0x800040BC: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
L_800040C0:
    // 0x800040C0: nop

    // 0x800040C4: bne         $t0, $zero, L_800040E0
    if (ctx->r8 != 0) {
        // 0x800040C8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800040E0;
    }
    // 0x800040C8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800040CC: beq         $v1, $zero, L_800040E0
    if (ctx->r3 == 0) {
        // 0x800040D0: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800040E0;
    }
    // 0x800040D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800040D4: beq         $v0, $zero, L_800034C0
    if (ctx->r2 == 0) {
        // 0x800040D8: lw          $t7, 0x74($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X74);
            goto L_800034C0;
    }
    // 0x800040D8: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x800040DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800040E0:
    // 0x800040E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800040E4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800040E8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800040EC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800040F0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800040F4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800040F8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800040FC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80004100: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80004104: jr          $ra
    // 0x80004108: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80004108: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void cheatlist_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A56C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8008A570: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8008A574: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8008A578: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8008A57C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8008A580: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8008A584: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8008A588: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8008A58C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8008A590: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8008A594: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8008A598: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8008A59C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008A5A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008A5A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008A5A8: jal         0x800C43CC
    // 0x8008A5AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_0;
    // 0x8008A5AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8008A5B0: jal         0x800C42EC
    // 0x8008A5B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_1;
    // 0x8008A5B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x8008A5B8: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8008A5BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008A5C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008A5C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008A5C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008A5CC: jal         0x800C4384
    // 0x8008A5D0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x8008A5D0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x8008A5D4: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x8008A5D8: addiu       $s7, $s7, -0xB60
    ctx->r23 = ADD32(ctx->r23, -0XB60);
    // 0x8008A5DC: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x8008A5E0: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8008A5E4: addiu       $s5, $s5, 0x63A0
    ctx->r21 = ADD32(ctx->r21, 0X63A0);
    // 0x8008A5E8: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8008A5EC: lw          $a3, 0x50($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X50);
    // 0x8008A5F0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008A5F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008A5F8: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x8008A5FC: jal         0x800C4440
    // 0x8008A600: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_3;
    // 0x8008A600: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_3:
    // 0x8008A604: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008A608: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8008A60C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008A610: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008A614: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008A618: jal         0x800C4384
    // 0x8008A61C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x8008A61C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8008A620: lw          $t0, 0x0($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X0);
    // 0x8008A624: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8008A628: lw          $a3, 0x50($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X50);
    // 0x8008A62C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008A630: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008A634: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008A638: jal         0x800C4440
    // 0x8008A63C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x8008A63C: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_5:
    // 0x8008A640: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008A644: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008A648: lw          $v1, -0x264($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X264);
    // 0x8008A64C: addiu       $a0, $a0, 0x6C80
    ctx->r4 = ADD32(ctx->r4, 0X6C80);
    // 0x8008A650: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008A654: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008A658: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8008A65C:
    // 0x8008A65C: and         $t2, $v0, $v1
    ctx->r10 = ctx->r2 & ctx->r3;
    // 0x8008A660: beq         $t2, $zero, L_8008A678
    if (ctx->r10 == 0) {
        // 0x8008A664: sll         $t5, $v0, 1
        ctx->r13 = S32(ctx->r2 << 1);
            goto L_8008A678;
    }
    // 0x8008A664: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x8008A668: sll         $t3, $s3, 1
    ctx->r11 = S32(ctx->r19 << 1);
    // 0x8008A66C: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8008A670: sh          $s0, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r16;
    // 0x8008A674: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8008A678:
    // 0x8008A678: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008A67C: slti        $at, $s0, 0x20
    ctx->r1 = SIGNED(ctx->r16) < 0X20 ? 1 : 0;
    // 0x8008A680: bne         $at, $zero, L_8008A65C
    if (ctx->r1 != 0) {
        // 0x8008A684: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_8008A65C;
    }
    // 0x8008A684: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8008A688: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8008A68C: lw          $fp, 0x63BC($fp)
    ctx->r30 = MEM_W(ctx->r30, 0X63BC);
    // 0x8008A690: addiu       $s2, $zero, 0x36
    ctx->r18 = ADD32(0, 0X36);
    // 0x8008A694: sll         $t6, $fp, 3
    ctx->r14 = S32(ctx->r30 << 3);
    // 0x8008A698: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x8008A69C: bne         $at, $zero, L_8008A6AC
    if (ctx->r1 != 0) {
        // 0x8008A6A0: or          $fp, $t6, $zero
        ctx->r30 = ctx->r14 | 0;
            goto L_8008A6AC;
    }
    // 0x8008A6A0: or          $fp, $t6, $zero
    ctx->r30 = ctx->r14 | 0;
    // 0x8008A6A4: addiu       $t7, $zero, 0x1FF
    ctx->r15 = ADD32(0, 0X1FF);
    // 0x8008A6A8: subu        $fp, $t7, $t6
    ctx->r30 = SUB32(ctx->r15, ctx->r14);
L_8008A6AC:
    // 0x8008A6AC: jal         0x800C42EC
    // 0x8008A6B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_6;
    // 0x8008A6B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8008A6B4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008A6B8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008A6BC: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008A6C0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008A6C4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008A6C8: jal         0x800C4384
    // 0x8008A6CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x8008A6CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x8008A6D0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008A6D4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008A6D8: lw          $t9, 0x6C70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6C70);
    // 0x8008A6DC: lw          $v1, 0x63E0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X63E0);
    // 0x8008A6E0: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8008A6E4: lw          $s6, 0x6C30($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X6C30);
    // 0x8008A6E8: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x8008A6EC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008A6F0: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x8008A6F4: beq         $at, $zero, L_8008A824
    if (ctx->r1 == 0) {
        // 0x8008A6F8: addiu       $s6, $s6, 0x2
        ctx->r22 = ADD32(ctx->r22, 0X2);
            goto L_8008A824;
    }
    // 0x8008A6F8: addiu       $s6, $s6, 0x2
    ctx->r22 = ADD32(ctx->r22, 0X2);
    // 0x8008A6FC: slt         $at, $v1, $s3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8008A700: beq         $at, $zero, L_8008A824
    if (ctx->r1 == 0) {
        // 0x8008A704: sll         $t0, $v1, 1
        ctx->r8 = S32(ctx->r3 << 1);
            goto L_8008A824;
    }
    // 0x8008A704: sll         $t0, $v1, 1
    ctx->r8 = S32(ctx->r3 << 1);
    // 0x8008A708: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008A70C: addiu       $t1, $t1, 0x6C80
    ctx->r9 = ADD32(ctx->r9, 0X6C80);
    // 0x8008A710: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008A714: addiu       $s4, $s4, 0x6C46
    ctx->r20 = ADD32(ctx->r20, 0X6C46);
    // 0x8008A718: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
L_8008A71C:
    // 0x8008A71C: lh          $t2, 0x0($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X0);
    // 0x8008A720: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008A724: bne         $s0, $t2, L_8008A740
    if (ctx->r16 != ctx->r10) {
        // 0x8008A728: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008A740;
    }
    // 0x8008A728: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008A72C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8008A730: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8008A734: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008A738: jal         0x800C4384
    // 0x8008A73C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    set_text_colour(rdram, ctx);
        goto after_8;
    // 0x8008A73C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_8:
L_8008A740:
    // 0x8008A740: lh          $t5, 0x0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X0);
    // 0x8008A744: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008A748: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8008A74C: addu        $t7, $s6, $t6
    ctx->r15 = ADD32(ctx->r22, ctx->r14);
    // 0x8008A750: lhu         $t8, 0x2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X2);
    // 0x8008A754: lw          $t9, 0x6C30($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6C30);
    // 0x8008A758: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008A75C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008A760: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x8008A764: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8008A768: jal         0x800C4440
    // 0x8008A76C: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    draw_text(rdram, ctx);
        goto after_9;
    // 0x8008A76C: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    after_9:
    // 0x8008A770: lh          $t0, 0x0($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X0);
    // 0x8008A774: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008A778: lw          $t3, -0x268($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X268);
    // 0x8008A77C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8008A780: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x8008A784: and         $t4, $t2, $t3
    ctx->r12 = ctx->r10 & ctx->r11;
    // 0x8008A788: beq         $t4, $zero, L_8008A7B4
    if (ctx->r12 == 0) {
        // 0x8008A78C: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8008A7B4;
    }
    // 0x8008A78C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008A790: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x8008A794: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008A798: lw          $a3, 0x54($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X54);
    // 0x8008A79C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008A7A0: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8008A7A4: jal         0x800C4440
    // 0x8008A7A8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_10;
    // 0x8008A7A8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_10:
    // 0x8008A7AC: b           L_8008A7D0
    // 0x8008A7B0: lh          $t7, 0x0($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X0);
        goto L_8008A7D0;
    // 0x8008A7B0: lh          $t7, 0x0($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X0);
L_8008A7B4:
    // 0x8008A7B4: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8008A7B8: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8008A7BC: lw          $a3, 0x58($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X58);
    // 0x8008A7C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008A7C4: jal         0x800C4440
    // 0x8008A7C8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_11;
    // 0x8008A7C8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_11:
    // 0x8008A7CC: lh          $t7, 0x0($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X0);
L_8008A7D0:
    // 0x8008A7D0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008A7D4: bne         $s0, $t7, L_8008A7F0
    if (ctx->r16 != ctx->r15) {
        // 0x8008A7D8: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008A7F0;
    }
    // 0x8008A7D8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008A7DC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008A7E0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008A7E4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008A7E8: jal         0x800C4384
    // 0x8008A7EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_12;
    // 0x8008A7EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
L_8008A7F0:
    // 0x8008A7F0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008A7F4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008A7F8: lw          $t1, 0x6C70($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6C70);
    // 0x8008A7FC: lw          $t9, 0x63E0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X63E0);
    // 0x8008A800: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008A804: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x8008A808: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008A80C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8008A810: beq         $at, $zero, L_8008A824
    if (ctx->r1 == 0) {
        // 0x8008A814: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_8008A824;
    }
    // 0x8008A814: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x8008A818: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8008A81C: bne         $at, $zero, L_8008A71C
    if (ctx->r1 != 0) {
        // 0x8008A820: nop
    
            goto L_8008A71C;
    }
    // 0x8008A820: nop

L_8008A824:
    // 0x8008A824: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008A828: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008A82C: beq         $at, $zero, L_8008A880
    if (ctx->r1 == 0) {
        // 0x8008A830: addiu       $s4, $s4, 0x6C46
        ctx->r20 = ADD32(ctx->r20, 0X6C46);
            goto L_8008A880;
    }
    // 0x8008A830: addiu       $s4, $s4, 0x6C46
    ctx->r20 = ADD32(ctx->r20, 0X6C46);
    // 0x8008A834: lh          $t0, 0x0($s4)
    ctx->r8 = MEM_H(ctx->r20, 0X0);
    // 0x8008A838: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008A83C: bne         $s3, $t0, L_8008A858
    if (ctx->r19 != ctx->r8) {
        // 0x8008A840: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008A858;
    }
    // 0x8008A840: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008A844: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8008A848: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008A84C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008A850: jal         0x800C4384
    // 0x8008A854: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    set_text_colour(rdram, ctx);
        goto after_13;
    // 0x8008A854: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_13:
L_8008A858:
    // 0x8008A858: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x8008A85C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8008A860: lw          $a3, 0x14($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X14);
    // 0x8008A864: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008A868: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008A86C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8008A870: jal         0x800C4440
    // 0x8008A874: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_14;
    // 0x8008A874: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_14:
    // 0x8008A878: b           L_8008A8CC
    // 0x8008A87C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_8008A8CC;
    // 0x8008A87C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8008A880:
    // 0x8008A880: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008A884: lw          $t5, 0x63BC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X63BC);
    // 0x8008A888: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008A88C: andi        $t6, $t5, 0x8
    ctx->r14 = ctx->r13 & 0X8;
    // 0x8008A890: beq         $t6, $zero, L_8008A8C8
    if (ctx->r14 == 0) {
        // 0x8008A894: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_8008A8C8;
    }
    // 0x8008A894: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008A898: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8008A89C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008A8A0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008A8A4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8008A8A8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8008A8AC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8008A8B0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8008A8B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008A8B8: addiu       $a1, $a1, 0x43C
    ctx->r5 = ADD32(ctx->r5, 0X43C);
    // 0x8008A8BC: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x8008A8C0: jal         0x80078AB8
    // 0x8008A8C4: addiu       $a3, $s2, 0x8
    ctx->r7 = ADD32(ctx->r18, 0X8);
    texrect_draw(rdram, ctx);
        goto after_15;
    // 0x8008A8C4: addiu       $a3, $s2, 0x8
    ctx->r7 = ADD32(ctx->r18, 0X8);
    after_15:
L_8008A8C8:
    // 0x8008A8C8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8008A8CC:
    // 0x8008A8CC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8008A8D0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8008A8D4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8008A8D8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8008A8DC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8008A8E0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8008A8E4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8008A8E8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8008A8EC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8008A8F0: jr          $ra
    // 0x8008A8F4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8008A8F4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void cam_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065EA0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80065EA4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80065EA8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80065EAC: addiu       $t7, $t7, 0xD70
    ctx->r15 = ADD32(ctx->r15, 0XD70);
    // 0x80065EB0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80065EB4: addiu       $a0, $a0, 0xDA0
    ctx->r4 = ADD32(ctx->r4, 0XDA0);
    // 0x80065EB8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80065EBC: sll         $t9, $v1, 6
    ctx->r25 = S32(ctx->r3 << 6);
    // 0x80065EC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80065EC4: sw          $a0, 0xD70($at)
    MEM_W(0XD70, ctx->r1) = ctx->r4;
    // 0x80065EC8: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80065ECC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80065ED0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80065ED4: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x80065ED8: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x80065EDC: addiu       $t0, $v1, 0x3
    ctx->r8 = ADD32(ctx->r3, 0X3);
    // 0x80065EE0: addiu       $t6, $v1, 0x2
    ctx->r14 = ADD32(ctx->r3, 0X2);
    // 0x80065EE4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80065EE8: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x80065EEC: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x80065EF0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80065EF4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80065EF8: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80065EFC: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80065F00: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x80065F04: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80065F08: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80065F0C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80065F10: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80065F14: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x80065F18: addiu       $s1, $s1, 0xCE4
    ctx->r17 = ADD32(ctx->r17, 0XCE4);
    // 0x80065F1C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80065F20: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    // 0x80065F24: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
L_80065F28:
    // 0x80065F28: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x80065F2C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80065F30: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80065F34: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80065F38: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x80065F3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80065F40: jal         0x800663DC
    // 0x80065F44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    camera_reset(rdram, ctx);
        goto after_0;
    // 0x80065F44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80065F48: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80065F4C: bne         $s0, $s2, L_80065F28
    if (ctx->r16 != ctx->r18) {
        // 0x80065F50: addiu       $t3, $zero, 0xB4
        ctx->r11 = ADD32(0, 0XB4);
            goto L_80065F28;
    }
    // 0x80065F50: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x80065F54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80065F58: sb          $zero, 0xD14($at)
    MEM_B(0XD14, ctx->r1) = 0;
    // 0x80065F5C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80065F60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80065F64: sw          $zero, 0xD1C($at)
    MEM_W(0XD1C, ctx->r1) = 0;
    // 0x80065F68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80065F6C: sw          $zero, 0xD20($at)
    MEM_W(0XD20, ctx->r1) = 0;
    // 0x80065F70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80065F74: sw          $zero, 0xCE0($at)
    MEM_W(0XCE0, ctx->r1) = 0;
    // 0x80065F78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80065F7C: sw          $zero, 0xD0C($at)
    MEM_W(0XD0C, ctx->r1) = 0;
    // 0x80065F80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80065F84: sw          $zero, 0xD18($at)
    MEM_W(0XD18, ctx->r1) = 0;
    // 0x80065F88: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80065F8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80065F90: addiu       $a0, $a0, -0x2FA0
    ctx->r4 = ADD32(ctx->r4, -0X2FA0);
    // 0x80065F94: lui         $v1, 0xA460
    ctx->r3 = S32(0XA460 << 16);
    // 0x80065F98: sb          $zero, 0xD15($at)
    MEM_B(0XD15, ctx->r1) = 0;
    // 0x80065F9C: ori         $v1, $v1, 0x10
    ctx->r3 = ctx->r3 | 0X10;
    // 0x80065FA0: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x80065FA4: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    // 0x80065FA8: lui         $t6, 0xB000
    ctx->r14 = S32(0XB000 << 16);
    // 0x80065FAC: andi        $t4, $v0, 0x3
    ctx->r12 = ctx->r2 & 0X3;
    // 0x80065FB0: beq         $t4, $zero, L_80065FCC
    if (ctx->r12 == 0) {
        // 0x80065FB4: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80065FCC;
    }
    // 0x80065FB4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
L_80065FB8:
    // 0x80065FB8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80065FBC: nop

    // 0x80065FC0: andi        $t5, $v0, 0x3
    ctx->r13 = ctx->r2 & 0X3;
    // 0x80065FC4: bne         $t5, $zero, L_80065FB8
    if (ctx->r13 != 0) {
        // 0x80065FC8: nop
    
            goto L_80065FB8;
    }
    // 0x80065FC8: nop

L_80065FCC:
    // 0x80065FCC: addiu       $t7, $zero, -0x769B
    ctx->r15 = ADD32(0, -0X769B);
    // 0x80065FD0: ori         $at, $zero, 0x8965
    ctx->r1 = 0 | 0X8965;
    // 0x80065FD4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80065FD8: beq         $t8, $at, L_80065FE8
    if (ctx->r24 == ctx->r1) {
        // 0x80065FDC: addiu       $s0, $s0, 0xEE0
        ctx->r16 = ADD32(ctx->r16, 0XEE0);
            goto L_80065FE8;
    }
    // 0x80065FDC: addiu       $s0, $s0, 0xEE0
    ctx->r16 = ADD32(ctx->r16, 0XEE0);
    // 0x80065FE0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80065FE4: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
L_80065FE8:
    // 0x80065FE8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80065FEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80065FF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80065FF4: lwc1        $f6, 0x709C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X709C);
    // 0x80065FF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80065FFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80066000: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80066004: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x80066008: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x8006600C: addiu       $a1, $a1, 0xD6C
    ctx->r5 = ADD32(ctx->r5, 0XD6C);
    // 0x80066010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066014: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80066018: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8006601C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80066020: jal         0x800CC920
    // 0x80066024: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_1;
    // 0x80066024: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80066028: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006602C: addiu       $a1, $a1, 0xFE0
    ctx->r5 = ADD32(ctx->r5, 0XFE0);
    // 0x80066030: jal         0x8006F870
    // 0x80066034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mtxf_to_mtx(rdram, ctx);
        goto after_2;
    // 0x80066034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80066038: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8006603C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80066040: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80066044: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066048: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006604C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80066050: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80066054: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80066058: jr          $ra
    // 0x8006605C: swc1        $f10, 0xD10($at)
    MEM_W(0XD10, ctx->r1) = ctx->f10.u32l;
    return;
    // 0x8006605C: swc1        $f10, 0xD10($at)
    MEM_W(0XD10, ctx->r1) = ctx->f10.u32l;
;}
RECOMP_FUNC void move_particle_basic_parent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3140: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800B3144: lw          $v0, 0x7C80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C80);
    // 0x800B3148: nop

    // 0x800B314C: slt         $v1, $zero, $v0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B3150: beq         $v1, $zero, L_800B31E0
    if (ctx->r3 == 0) {
        // 0x800B3154: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800B31E0;
    }
    // 0x800B3154: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800B3158:
    // 0x800B3158: lwc1        $f4, 0x4C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800B315C: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800B3160: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800B3164: lwc1        $f10, 0x50($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800B3168: lwc1        $f18, 0x68($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X68);
    // 0x800B316C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B3170: lwc1        $f6, 0x54($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800B3174: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800B3178: swc1        $f8, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f8.u32l;
    // 0x800B317C: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800B3180: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
    // 0x800B3184: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800B3188: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800B318C: lh          $t7, 0x62($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X62);
    // 0x800B3190: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x800B3194: lh          $t0, 0x64($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X64);
    // 0x800B3198: lh          $t2, 0x4($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X4);
    // 0x800B319C: lh          $t3, 0x66($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X66);
    // 0x800B31A0: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B31A4: lwc1        $f18, 0x28($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800B31A8: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x800B31AC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B31B0: slt         $v1, $zero, $v0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B31B4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B31B8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800B31BC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B31C0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800B31C4: swc1        $f10, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f10.u32l;
    // 0x800B31C8: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x800B31CC: sh          $t1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r9;
    // 0x800B31D0: sh          $t4, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r12;
    // 0x800B31D4: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x800B31D8: bne         $v1, $zero, L_800B3158
    if (ctx->r3 != 0) {
        // 0x800B31DC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800B3158;
    }
    // 0x800B31DC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800B31E0:
    // 0x800B31E0: lwc1        $f6, 0x4C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800B31E4: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800B31E8: lwc1        $f10, 0x54($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800B31EC: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x800B31F0: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x800B31F4: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x800B31F8: beq         $v0, $zero, L_800B3238
    if (ctx->r2 == 0) {
        // 0x800B31FC: swc1        $f10, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
            goto L_800B3238;
    }
    // 0x800B31FC: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800B3200: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800B3204: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800B3208: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800B320C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3210: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800B3214: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x800B3218: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800B321C: nop

    // 0x800B3220: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3224: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800B3228: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800B322C: nop

    // 0x800B3230: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3234: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
L_800B3238:
    // 0x800B3238: jr          $ra
    // 0x800B323C: nop

    return;
    // 0x800B323C: nop

;}
RECOMP_FUNC void mtxf_transform_point(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F64C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8006F650: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006F654: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8006F658: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8006F65C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006F660: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x8006F664: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8006F668: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8006F66C: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8006F670: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8006F674: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8006F678: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8006F67C: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8006F680: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8006F684: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x8006F688: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006F68C: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8006F690: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x8006F694: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8006F698: lwc1        $f18, 0x24($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8006F69C: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8006F6A0: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8006F6A4: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8006F6A8: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8006F6AC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8006F6B0: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8006F6B4: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x8006F6B8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006F6BC: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8006F6C0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8006F6C4: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006F6C8: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8006F6CC: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006F6D0: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8006F6D4: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8006F6D8: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8006F6DC: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8006F6E0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006F6E4: jr          $ra
    // 0x8006F6E8: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    return;
    // 0x8006F6E8: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
;}
RECOMP_FUNC void obj_init_snowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038248: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003824C: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80038250: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80038254: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80038258: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x8003825C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80038260: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x80038264: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80038268: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8003826C: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x80038270: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x80038274: jr          $ra
    // 0x80038278: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    return;
    // 0x80038278: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
;}
RECOMP_FUNC void screenimage_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F640: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007F644: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007F648: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8007F64C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007F650: jal         0x80076C58
    // 0x8007F654: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x8007F654: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_0:
    // 0x8007F658: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8007F65C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8007F660: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007F664: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007F668: beq         $a0, $t6, L_8007F680
    if (ctx->r4 == ctx->r14) {
        // 0x8007F66C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007F680;
    }
    // 0x8007F66C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007F670:
    // 0x8007F670: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8007F674: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007F678: bne         $a0, $t7, L_8007F670
    if (ctx->r4 != ctx->r15) {
        // 0x8007F67C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8007F670;
    }
    // 0x8007F67C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8007F680:
    // 0x8007F680: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8007F684: bne         $v1, $zero, L_8007F69C
    if (ctx->r3 != 0) {
        // 0x8007F688: nop
    
            goto L_8007F69C;
    }
    // 0x8007F688: nop

    // 0x8007F68C: jal         0x80071140
    // 0x8007F690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_1;
    // 0x8007F690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8007F694: b           L_8007F704
    // 0x8007F698: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
        goto L_8007F704;
    // 0x8007F698: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
L_8007F69C:
    // 0x8007F69C: bltz        $t0, L_8007F6A8
    if (SIGNED(ctx->r8) < 0) {
        // 0x8007F6A0: slt         $at, $t0, $v1
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8007F6A8;
    }
    // 0x8007F6A0: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F6A4: bne         $at, $zero, L_8007F6B8
    if (ctx->r1 != 0) {
        // 0x8007F6A8: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8007F6B8;
    }
L_8007F6A8:
    // 0x8007F6A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007F6AC: jal         0x800C9D54
    // 0x8007F6B0: addiu       $a0, $a0, 0x7C90
    ctx->r4 = ADD32(ctx->r4, 0X7C90);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8007F6B0: addiu       $a0, $a0, 0x7C90
    ctx->r4 = ADD32(ctx->r4, 0X7C90);
    after_2:
    // 0x8007F6B4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8007F6B8:
    // 0x8007F6B8: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8007F6BC: addu        $v0, $s0, $t8
    ctx->r2 = ADD32(ctx->r16, ctx->r24);
    // 0x8007F6C0: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007F6C4: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8007F6C8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8007F6CC: subu        $a0, $t9, $a2
    ctx->r4 = SUB32(ctx->r25, ctx->r6);
    // 0x8007F6D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8007F6D4: jal         0x80070C9C
    // 0x8007F6D8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8007F6D8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x8007F6DC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8007F6E0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8007F6E4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8007F6E8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8007F6EC: jal         0x80076E68
    // 0x8007F6F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_4;
    // 0x8007F6F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8007F6F4: jal         0x80071140
    // 0x8007F6F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x8007F6F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8007F6FC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8007F700: nop

L_8007F704:
    // 0x8007F704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007F708: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007F70C: jr          $ra
    // 0x8007F710: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007F710: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void update_object_stack_trace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B76B8: bltz        $a0, L_800B76D4
    if (SIGNED(ctx->r4) < 0) {
        // 0x800B76BC: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_800B76D4;
    }
    // 0x800B76BC: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800B76C0: beq         $at, $zero, L_800B76D4
    if (ctx->r1 == 0) {
        // 0x800B76C4: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800B76D4;
    }
    // 0x800B76C4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800B76C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B76CC: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B76D0: sw          $a1, -0x6050($at)
    MEM_W(-0X6050, ctx->r1) = ctx->r5;
L_800B76D4:
    // 0x800B76D4: jr          $ra
    // 0x800B76D8: nop

    return;
    // 0x800B76D8: nop

;}
RECOMP_FUNC void set_next_taj_challenge_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D330: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009D334: jr          $ra
    // 0x8009D338: sb          $a0, -0xB24($at)
    MEM_B(-0XB24, ctx->r1) = ctx->r4;
    return;
    // 0x8009D338: sb          $a0, -0xB24($at)
    MEM_B(-0XB24, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void music_channel_pan_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800011A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800011AC: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x800011B0: slti        $at, $a3, 0x10
    ctx->r1 = SIGNED(ctx->r7) < 0X10 ? 1 : 0;
    // 0x800011B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800011B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800011BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800011C0: beq         $at, $zero, L_800011D8
    if (ctx->r1 == 0) {
        // 0x800011C4: andi        $a2, $a1, 0xFF
        ctx->r6 = ctx->r5 & 0XFF;
            goto L_800011D8;
    }
    // 0x800011C4: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x800011C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800011CC: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x800011D0: jal         0x800C78E0
    // 0x800011D4: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    alCSPSetChlPan(rdram, ctx);
        goto after_0;
    // 0x800011D4: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    after_0:
L_800011D8:
    // 0x800011D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800011DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800011E0: jr          $ra
    // 0x800011E4: nop

    return;
    // 0x800011E4: nop

;}
RECOMP_FUNC void alSynAllocVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9508: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C950C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C9510: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C9514: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C9518: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800C951C: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x800C9520: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800C9524: sh          $t6, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r14;
    // 0x800C9528: lbu         $t7, 0x4($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X4);
    // 0x800C952C: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800C9530: sh          $t7, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r15;
    // 0x800C9534: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x800C9538: sh          $zero, 0x14($a1)
    MEM_H(0X14, ctx->r5) = 0;
    // 0x800C953C: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800C9540: sh          $t8, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r24;
    // 0x800C9544: lh          $a2, 0x0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X0);
    // 0x800C9548: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800C954C: jal         0x800C9420
    // 0x800C9550: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _allocatePVoice(rdram, ctx);
        goto after_0;
    // 0x800C9550: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800C9554: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9558: beql        $t9, $zero, L_800C9630
    if (ctx->r25 == 0) {
        // 0x800C955C: lw          $v0, 0x2C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X2C);
            goto L_800C9630;
    }
    goto skip_0;
    // 0x800C955C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x800C9560: beq         $v0, $zero, L_800C9614
    if (ctx->r2 == 0) {
        // 0x800C9564: lw          $a0, 0xC($t9)
        ctx->r4 = MEM_W(ctx->r25, 0XC);
            goto L_800C9614;
    }
    // 0x800C9564: lw          $a0, 0xC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XC);
    // 0x800C9568: addiu       $t0, $zero, 0x200
    ctx->r8 = ADD32(0, 0X200);
    // 0x800C956C: sw          $t0, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = ctx->r8;
    // 0x800C9570: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9574: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800C9578: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x800C957C: jal         0x80065668
    // 0x800C9580: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    __allocParam(rdram, ctx);
        goto after_1;
    // 0x800C9580: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x800C9584: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800C9588: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C958C: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x800C9590: lw          $t4, 0x1C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1C);
    // 0x800C9594: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x800C9598: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800C959C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800C95A0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800C95A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C95A8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C95AC: lw          $t7, 0xD8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XD8);
    // 0x800C95B0: addiu       $t8, $t7, -0x40
    ctx->r24 = ADD32(ctx->r15, -0X40);
    // 0x800C95B4: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x800C95B8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C95BC: jalr        $t9
    // 0x800C95C0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800C95C0: nop

    after_2:
    // 0x800C95C4: jal         0x80065668
    // 0x800C95C8: nop

    __allocParam(rdram, ctx);
        goto after_3;
    // 0x800C95C8: nop

    after_3:
    // 0x800C95CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C95D0: beq         $v0, $zero, L_800C961C
    if (ctx->r2 == 0) {
        // 0x800C95D4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C961C;
    }
    // 0x800C95D4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C95D8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C95DC: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800C95E0: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x800C95E4: lw          $t1, 0x1C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1C);
    // 0x800C95E8: lw          $t3, 0xD8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XD8);
    // 0x800C95EC: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x800C95F0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C95F4: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800C95F8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800C95FC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9600: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9604: jalr        $t9
    // 0x800C9608: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800C9608: nop

    after_4:
    // 0x800C960C: b           L_800C9620
    // 0x800C9610: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_800C9620;
    // 0x800C9610: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800C9614:
    // 0x800C9614: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9618: sw          $zero, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = 0;
L_800C961C:
    // 0x800C961C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_800C9620:
    // 0x800C9620: sw          $s0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r16;
    // 0x800C9624: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9628: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x800C962C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_800C9630:
    // 0x800C9630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9634: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C9638: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C963C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800C9640: jr          $ra
    // 0x800C9644: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C9644: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80021600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021600: addiu       $sp, $sp, -0x160
    ctx->r29 = ADD32(ctx->r29, -0X160);
    // 0x80021604: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80021608: lh          $t6, -0x5186($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X5186);
    // 0x8002160C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80021610: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80021614: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80021618: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8002161C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80021620: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80021624: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80021628: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8002162C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80021630: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80021634: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80021638: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8002163C: bgez        $t6, L_8002164C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80021640: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8002164C;
    }
    // 0x80021640: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80021644: b           L_80022508
    // 0x80021648: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80022508;
    // 0x80021648: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002164C:
    // 0x8002164C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80021650: lh          $v1, -0x5188($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X5188);
    // 0x80021654: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80021658: blez        $v1, L_800216B0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002165C: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_800216B0;
    }
    // 0x8002165C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80021660: addiu       $a2, $a2, -0x518C
    ctx->r6 = ADD32(ctx->r6, -0X518C);
    // 0x80021664: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80021668: nop

    // 0x8002166C: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80021670: nop

    // 0x80021674: lw          $t8, 0x7C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X7C);
    // 0x80021678: nop

    // 0x8002167C: beq         $a1, $t8, L_800216B0
    if (ctx->r5 == ctx->r24) {
        // 0x80021680: nop
    
            goto L_800216B0;
    }
    // 0x80021680: nop

L_80021684:
    // 0x80021684: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80021688: slt         $at, $s7, $v1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002168C: beq         $at, $zero, L_800216B0
    if (ctx->r1 == 0) {
        // 0x80021690: sll         $t9, $s7, 2
        ctx->r25 = S32(ctx->r23 << 2);
            goto L_800216B0;
    }
    // 0x80021690: sll         $t9, $s7, 2
    ctx->r25 = S32(ctx->r23 << 2);
    // 0x80021694: addu        $t3, $a3, $t9
    ctx->r11 = ADD32(ctx->r7, ctx->r25);
    // 0x80021698: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8002169C: nop

    // 0x800216A0: lw          $t5, 0x7C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X7C);
    // 0x800216A4: nop

    // 0x800216A8: bne         $a1, $t5, L_80021684
    if (ctx->r5 != ctx->r13) {
        // 0x800216AC: nop
    
            goto L_80021684;
    }
    // 0x800216AC: nop

L_800216B0:
    // 0x800216B0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800216B4: slt         $at, $s7, $v1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800216B8: bne         $at, $zero, L_800216C8
    if (ctx->r1 != 0) {
        // 0x800216BC: addiu       $a2, $a2, -0x518C
        ctx->r6 = ADD32(ctx->r6, -0X518C);
            goto L_800216C8;
    }
    // 0x800216BC: addiu       $a2, $a2, -0x518C
    ctx->r6 = ADD32(ctx->r6, -0X518C);
    // 0x800216C0: b           L_80022508
    // 0x800216C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80022508;
    // 0x800216C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800216C8:
    // 0x800216C8: addiu       $t6, $s7, 0x1
    ctx->r14 = ADD32(ctx->r23, 0X1);
    // 0x800216CC: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800216D0: beq         $at, $zero, L_80021728
    if (ctx->r1 == 0) {
        // 0x800216D4: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_80021728;
    }
    // 0x800216D4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800216D8: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800216DC: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x800216E0: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800216E4: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800216E8: addu        $v0, $s7, $s5
    ctx->r2 = ADD32(ctx->r23, ctx->r21);
    // 0x800216EC: lw          $t3, 0x7C($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X7C);
    // 0x800216F0: nop

    // 0x800216F4: bne         $a1, $t3, L_80021728
    if (ctx->r5 != ctx->r11) {
        // 0x800216F8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80021728;
    }
    // 0x800216F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800216FC:
    // 0x800216FC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021700: beq         $at, $zero, L_80021728
    if (ctx->r1 == 0) {
        // 0x80021704: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_80021728;
    }
    // 0x80021704: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80021708: sll         $t4, $s5, 2
    ctx->r12 = S32(ctx->r21 << 2);
    // 0x8002170C: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x80021710: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80021714: nop

    // 0x80021718: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x8002171C: nop

    // 0x80021720: beq         $a1, $t7, L_800216FC
    if (ctx->r5 == ctx->r15) {
        // 0x80021724: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800216FC;
    }
    // 0x80021724: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80021728:
    // 0x80021728: slti        $at, $s5, 0x2
    ctx->r1 = SIGNED(ctx->r21) < 0X2 ? 1 : 0;
    // 0x8002172C: beq         $at, $zero, L_8002173C
    if (ctx->r1 == 0) {
        // 0x80021730: sll         $t8, $s7, 2
        ctx->r24 = S32(ctx->r23 << 2);
            goto L_8002173C;
    }
    // 0x80021730: sll         $t8, $s7, 2
    ctx->r24 = S32(ctx->r23 << 2);
    // 0x80021734: b           L_80022508
    // 0x80021738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80022508;
    // 0x80021738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002173C:
    // 0x8002173C: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80021740: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x80021744: addu        $t3, $a3, $t8
    ctx->r11 = ADD32(ctx->r7, ctx->r24);
    // 0x80021748: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8002174C: addiu       $s2, $sp, 0x124
    ctx->r18 = ADD32(ctx->r29, 0X124);
    // 0x80021750: lw          $t4, 0x64($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X64);
    // 0x80021754: addiu       $s3, $sp, 0x110
    ctx->r19 = ADD32(ctx->r29, 0X110);
    // 0x80021758: bne         $t4, $zero, L_80021768
    if (ctx->r12 != 0) {
        // 0x8002175C: sw          $t4, 0x154($sp)
        MEM_W(0X154, ctx->r29) = ctx->r12;
            goto L_80021768;
    }
    // 0x8002175C: sw          $t4, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r12;
    // 0x80021760: b           L_80022508
    // 0x80021764: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80022508;
    // 0x80021764: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80021768:
    // 0x80021768: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x8002176C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80021770: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x80021774: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80021778: sw          $t7, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r15;
    // 0x8002177C: lw          $t8, 0x40($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X40);
    // 0x80021780: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80021784: lwc1        $f6, 0xC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80021788: sll         $t9, $s7, 2
    ctx->r25 = S32(ctx->r23 << 2);
    // 0x8002178C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80021790: nop

    // 0x80021794: div.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x80021798: addu        $t3, $a3, $t9
    ctx->r11 = ADD32(ctx->r7, ctx->r25);
    // 0x8002179C: sll         $t4, $s5, 2
    ctx->r12 = S32(ctx->r21 << 2);
    // 0x800217A0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800217A4: slti        $at, $s5, 0x3
    ctx->r1 = SIGNED(ctx->r21) < 0X3 ? 1 : 0;
    // 0x800217A8: lw          $t8, 0x15C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X15C);
    // 0x800217AC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800217B0: addiu       $s4, $sp, 0xFC
    ctx->r20 = ADD32(ctx->r29, 0XFC);
    // 0x800217B4: addiu       $fp, $sp, 0xBC
    ctx->r30 = ADD32(ctx->r29, 0XBC);
    // 0x800217B8: addiu       $s6, $sp, 0xA8
    ctx->r22 = ADD32(ctx->r29, 0XA8);
    // 0x800217BC: addiu       $t1, $sp, 0x94
    ctx->r9 = ADD32(ctx->r29, 0X94);
    // 0x800217C0: addiu       $s1, $sp, 0xD0
    ctx->r17 = ADD32(ctx->r29, 0XD0);
    // 0x800217C4: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x800217C8: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    // 0x800217CC: lw          $t6, -0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X4);
    // 0x800217D0: nop

    // 0x800217D4: lw          $a1, 0x3C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X3C);
    // 0x800217D8: bne         $at, $zero, L_800217FC
    if (ctx->r1 != 0) {
        // 0x800217DC: nop
    
            goto L_800217FC;
    }
    // 0x800217DC: nop

    // 0x800217E0: lb          $v0, 0x1D($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1D);
    // 0x800217E4: addiu       $t7, $s5, -0x1
    ctx->r15 = ADD32(ctx->r21, -0X1);
    // 0x800217E8: bltz        $v0, L_800217FC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800217EC: slt         $at, $v0, $t7
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
            goto L_800217FC;
    }
    // 0x800217EC: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800217F0: beq         $at, $zero, L_800217FC
    if (ctx->r1 == 0) {
        // 0x800217F4: nop
    
            goto L_800217FC;
    }
    // 0x800217F4: nop

    // 0x800217F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800217FC:
    // 0x800217FC: lh          $s0, 0x26($t8)
    ctx->r16 = MEM_H(ctx->r24, 0X26);
    // 0x80021800: sw          $v1, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r3;
    // 0x80021804: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80021808:
    // 0x80021808: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002180C: bne         $s0, $at, L_800219BC
    if (ctx->r16 != ctx->r1) {
        // 0x80021810: slt         $at, $s0, $s5
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
            goto L_800219BC;
    }
    // 0x80021810: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80021814: lw          $t9, 0x138($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X138);
    // 0x80021818: addu        $t3, $s7, $s5
    ctx->r11 = ADD32(ctx->r23, ctx->r21);
    // 0x8002181C: beq         $t9, $zero, L_80021904
    if (ctx->r25 == 0) {
        // 0x80021820: sll         $t4, $t3, 2
        ctx->r12 = S32(ctx->r11 << 2);
            goto L_80021904;
    }
    // 0x80021820: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80021824: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80021828: nop

    // 0x8002182C: addu        $v0, $a3, $t3
    ctx->r2 = ADD32(ctx->r7, ctx->r11);
    // 0x80021830: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80021834: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x80021838: lwc1        $f0, 0xC($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0XC);
    // 0x8002183C: lwc1        $f4, 0xC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80021840: nop

    // 0x80021844: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80021848: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8002184C: swc1        $f10, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f10.u32l;
    // 0x80021850: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80021854: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80021858: lwc1        $f2, 0x10($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8002185C: lwc1        $f6, 0x10($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80021860: nop

    // 0x80021864: sub.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80021868: add.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8002186C: swc1        $f8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f8.u32l;
    // 0x80021870: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80021874: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80021878: lwc1        $f12, 0x14($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8002187C: lwc1        $f10, 0x14($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80021880: nop

    // 0x80021884: sub.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80021888: add.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x8002188C: swc1        $f4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f4.u32l;
    // 0x80021890: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80021894: nop

    // 0x80021898: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8002189C: nop

    // 0x800218A0: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800218A4: nop

    // 0x800218A8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800218AC: swc1        $f10, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f10.u32l;
    // 0x800218B0: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800218B4: nop

    // 0x800218B8: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x800218BC: nop

    // 0x800218C0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800218C4: nop

    // 0x800218C8: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800218CC: swc1        $f4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f4.u32l;
    // 0x800218D0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800218D4: nop

    // 0x800218D8: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x800218DC: nop

    // 0x800218E0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800218E4: nop

    // 0x800218E8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800218EC: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x800218F0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800218F4: nop

    // 0x800218F8: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800218FC: b           L_80021CD4
    // 0x80021900: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
        goto L_80021CD4;
    // 0x80021900: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_80021904:
    // 0x80021904: addu        $v0, $a3, $t4
    ctx->r2 = ADD32(ctx->r7, ctx->r12);
    // 0x80021908: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x8002190C: nop

    // 0x80021910: lwc1        $f4, 0xC($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80021914: nop

    // 0x80021918: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x8002191C: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x80021920: nop

    // 0x80021924: lwc1        $f8, 0x10($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80021928: nop

    // 0x8002192C: swc1        $f8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f8.u32l;
    // 0x80021930: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x80021934: nop

    // 0x80021938: lwc1        $f10, 0x14($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X14);
    // 0x8002193C: nop

    // 0x80021940: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    // 0x80021944: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x80021948: nop

    // 0x8002194C: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80021950: nop

    // 0x80021954: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80021958: nop

    // 0x8002195C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021960: swc1        $f4, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f4.u32l;
    // 0x80021964: lw          $t3, -0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, -0X4);
    // 0x80021968: nop

    // 0x8002196C: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80021970: nop

    // 0x80021974: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80021978: nop

    // 0x8002197C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021980: swc1        $f10, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f10.u32l;
    // 0x80021984: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x80021988: nop

    // 0x8002198C: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x80021990: nop

    // 0x80021994: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80021998: nop

    // 0x8002199C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800219A0: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x800219A4: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x800219A8: nop

    // 0x800219AC: lwc1        $f8, 0x8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800219B0: b           L_80021CD4
    // 0x800219B4: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
        goto L_80021CD4;
    // 0x800219B4: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x800219B8: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
L_800219BC:
    // 0x800219BC: bne         $at, $zero, L_80021BC8
    if (ctx->r1 != 0) {
        // 0x800219C0: addu        $a2, $s0, $s7
        ctx->r6 = ADD32(ctx->r16, ctx->r23);
            goto L_80021BC8;
    }
    // 0x800219C0: addu        $a2, $s0, $s7
    ctx->r6 = ADD32(ctx->r16, ctx->r23);
    // 0x800219C4: lw          $t8, 0x138($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X138);
    // 0x800219C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800219CC: bne         $t8, $at, L_80021AFC
    if (ctx->r24 != ctx->r1) {
        // 0x800219D0: addu        $v0, $s5, $s7
        ctx->r2 = ADD32(ctx->r21, ctx->r23);
            goto L_80021AFC;
    }
    // 0x800219D0: addu        $v0, $s5, $s7
    ctx->r2 = ADD32(ctx->r21, ctx->r23);
    // 0x800219D4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800219D8: addu        $t3, $a3, $t9
    ctx->r11 = ADD32(ctx->r7, ctx->r25);
    // 0x800219DC: lw          $t4, -0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, -0X4);
    // 0x800219E0: sll         $a2, $v0, 2
    ctx->r6 = S32(ctx->r2 << 2);
    // 0x800219E4: lw          $a1, 0x3C($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X3C);
    // 0x800219E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800219EC: lb          $t5, 0x22($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X22);
    // 0x800219F0: addiu       $s0, $s5, -0x1
    ctx->r16 = ADD32(ctx->r21, -0X1);
    // 0x800219F4: bne         $t5, $at, L_80021A38
    if (ctx->r13 != ctx->r1) {
        // 0x800219F8: addiu       $a2, $a2, -0x4
        ctx->r6 = ADD32(ctx->r6, -0X4);
            goto L_80021A38;
    }
    // 0x800219F8: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800219FC: lw          $t6, 0x15C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X15C);
    // 0x80021A00: nop

    // 0x80021A04: lb          $a0, 0x30($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X30);
    // 0x80021A08: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80021A0C: jal         0x800665E8
    // 0x80021A10: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    set_active_camera(rdram, ctx);
        goto after_0;
    // 0x80021A10: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80021A14: jal         0x80069CFC
    // 0x80021A18: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_1;
    // 0x80021A18: nop

    after_1:
    // 0x80021A1C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80021A20: lw          $a3, -0x518C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X518C);
    // 0x80021A24: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x80021A28: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80021A2C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80021A30: b           L_80021A44
    // 0x80021A34: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
        goto L_80021A44;
    // 0x80021A34: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
L_80021A38:
    // 0x80021A38: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x80021A3C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80021A40: nop

L_80021A44:
    // 0x80021A44: lw          $t7, -0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, -0X4);
    // 0x80021A48: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80021A4C: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80021A50: nop

    // 0x80021A54: sub.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80021A58: add.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80021A5C: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x80021A60: lw          $t8, -0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, -0X4);
    // 0x80021A64: lwc1        $f2, 0x10($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80021A68: lwc1        $f8, 0x10($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80021A6C: nop

    // 0x80021A70: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80021A74: add.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80021A78: swc1        $f6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f6.u32l;
    // 0x80021A7C: lw          $t9, -0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, -0X4);
    // 0x80021A80: lwc1        $f12, 0x14($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80021A84: lwc1        $f4, 0x14($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80021A88: nop

    // 0x80021A8C: sub.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x80021A90: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x80021A94: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    // 0x80021A98: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    // 0x80021A9C: nop

    // 0x80021AA0: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80021AA4: nop

    // 0x80021AA8: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021AAC: swc1        $f4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f4.u32l;
    // 0x80021AB0: lh          $t4, 0x4($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X4);
    // 0x80021AB4: nop

    // 0x80021AB8: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80021ABC: nop

    // 0x80021AC0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021AC4: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80021AC8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80021ACC: nop

    // 0x80021AD0: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x80021AD4: nop

    // 0x80021AD8: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80021ADC: nop

    // 0x80021AE0: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021AE4: swc1        $f4, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f4.u32l;
    // 0x80021AE8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80021AEC: nop

    // 0x80021AF0: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80021AF4: b           L_80021CD4
    // 0x80021AF8: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
        goto L_80021CD4;
    // 0x80021AF8: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
L_80021AFC:
    // 0x80021AFC: lw          $t7, 0x138($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X138);
    // 0x80021B00: nop

    // 0x80021B04: addu        $t8, $s7, $t7
    ctx->r24 = ADD32(ctx->r23, ctx->r15);
    // 0x80021B08: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80021B0C: subu        $t3, $t9, $s5
    ctx->r11 = SUB32(ctx->r25, ctx->r21);
    // 0x80021B10: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80021B14: addu        $v0, $a3, $t4
    ctx->r2 = ADD32(ctx->r7, ctx->r12);
    // 0x80021B18: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80021B1C: nop

    // 0x80021B20: lwc1        $f10, 0xC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XC);
    // 0x80021B24: nop

    // 0x80021B28: swc1        $f10, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f10.u32l;
    // 0x80021B2C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80021B30: nop

    // 0x80021B34: lwc1        $f6, 0x10($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X10);
    // 0x80021B38: nop

    // 0x80021B3C: swc1        $f6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f6.u32l;
    // 0x80021B40: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80021B44: nop

    // 0x80021B48: lwc1        $f4, 0x14($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X14);
    // 0x80021B4C: nop

    // 0x80021B50: swc1        $f4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f4.u32l;
    // 0x80021B54: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80021B58: nop

    // 0x80021B5C: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80021B60: nop

    // 0x80021B64: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80021B68: nop

    // 0x80021B6C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021B70: swc1        $f10, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f10.u32l;
    // 0x80021B74: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80021B78: nop

    // 0x80021B7C: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x80021B80: nop

    // 0x80021B84: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80021B88: nop

    // 0x80021B8C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021B90: swc1        $f4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f4.u32l;
    // 0x80021B94: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80021B98: nop

    // 0x80021B9C: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x80021BA0: nop

    // 0x80021BA4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80021BA8: nop

    // 0x80021BAC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021BB0: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80021BB4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80021BB8: nop

    // 0x80021BBC: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x80021BC0: b           L_80021CD4
    // 0x80021BC4: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
        goto L_80021CD4;
    // 0x80021BC4: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_80021BC8:
    // 0x80021BC8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80021BCC: addu        $a0, $a3, $t8
    ctx->r4 = ADD32(ctx->r7, ctx->r24);
    // 0x80021BD0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80021BD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80021BD8: lw          $a1, 0x3C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X3C);
    // 0x80021BDC: lw          $t3, 0x15C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X15C);
    // 0x80021BE0: lb          $t9, 0x22($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X22);
    // 0x80021BE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80021BE8: bne         $t9, $at, L_80021C2C
    if (ctx->r25 != ctx->r1) {
        // 0x80021BEC: nop
    
            goto L_80021C2C;
    }
    // 0x80021BEC: nop

    // 0x80021BF0: lb          $a0, 0x30($t3)
    ctx->r4 = MEM_B(ctx->r11, 0X30);
    // 0x80021BF4: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80021BF8: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x80021BFC: jal         0x800665E8
    // 0x80021C00: sw          $a1, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r5;
    set_active_camera(rdram, ctx);
        goto after_2;
    // 0x80021C00: sw          $a1, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r5;
    after_2:
    // 0x80021C04: jal         0x80069CFC
    // 0x80021C08: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_3;
    // 0x80021C08: nop

    after_3:
    // 0x80021C0C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80021C10: lw          $a3, -0x518C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X518C);
    // 0x80021C14: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x80021C18: lw          $a1, 0x150($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X150);
    // 0x80021C1C: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80021C20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80021C24: b           L_80021C2C
    // 0x80021C28: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
        goto L_80021C2C;
    // 0x80021C28: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
L_80021C2C:
    // 0x80021C2C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80021C30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80021C34: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x80021C38: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80021C3C: nop

    // 0x80021C40: swc1        $f8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f8.u32l;
    // 0x80021C44: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80021C48: nop

    // 0x80021C4C: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    // 0x80021C50: lh          $t4, 0x2($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X2);
    // 0x80021C54: nop

    // 0x80021C58: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80021C5C: nop

    // 0x80021C60: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021C64: swc1        $f4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f4.u32l;
    // 0x80021C68: lh          $t5, 0x4($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X4);
    // 0x80021C6C: nop

    // 0x80021C70: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80021C74: nop

    // 0x80021C78: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80021C7C: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80021C80: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80021C84: nop

    // 0x80021C88: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80021C8C: nop

    // 0x80021C90: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80021C94: nop

    // 0x80021C98: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80021C9C: swc1        $f4, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->f4.u32l;
    // 0x80021CA0: lb          $t7, 0x22($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X22);
    // 0x80021CA4: nop

    // 0x80021CA8: bne         $t7, $at, L_80021CC0
    if (ctx->r15 != ctx->r1) {
        // 0x80021CAC: nop
    
            goto L_80021CC0;
    }
    // 0x80021CAC: nop

    // 0x80021CB0: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80021CB4: nop

    // 0x80021CB8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80021CBC: swc1        $f10, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f10.u32l;
L_80021CC0:
    // 0x80021CC0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80021CC4: nop

    // 0x80021CC8: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80021CCC: nop

    // 0x80021CD0: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_80021CD4:
    // 0x80021CD4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80021CD8: addiu       $t9, $sp, 0xE4
    ctx->r25 = ADD32(ctx->r29, 0XE4);
    // 0x80021CDC: sltu        $at, $s1, $t9
    ctx->r1 = ctx->r17 < ctx->r25 ? 1 : 0;
    // 0x80021CE0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80021CE4: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80021CE8: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80021CEC: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80021CF0: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80021CF4: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80021CF8: bne         $at, $zero, L_80021808
    if (ctx->r1 != 0) {
        // 0x80021CFC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80021808;
    }
    // 0x80021CFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80021D00: lw          $t3, 0x15C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X15C);
    // 0x80021D04: addiu       $s0, $sp, 0x124
    ctx->r16 = ADD32(ctx->r29, 0X124);
    // 0x80021D08: lb          $t4, 0x3F($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X3F);
    // 0x80021D0C: lwc1        $f0, 0x0($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80021D10: bne         $t4, $zero, L_80021D68
    if (ctx->r12 != 0) {
        // 0x80021D14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80021D68;
    }
    // 0x80021D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021D18: addiu       $s0, $sp, 0x124
    ctx->r16 = ADD32(ctx->r29, 0X124);
    // 0x80021D1C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80021D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021D24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021D28: jal         0x80022540
    // 0x80021D2C: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_4;
    // 0x80021D2C: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80021D30: addiu       $s1, $sp, 0x110
    ctx->r17 = ADD32(ctx->r29, 0X110);
    // 0x80021D34: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021D38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021D3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021D40: jal         0x80022540
    // 0x80021D44: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_5;
    // 0x80021D44: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80021D48: addiu       $s2, $sp, 0xFC
    ctx->r18 = ADD32(ctx->r29, 0XFC);
    // 0x80021D4C: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021D50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021D54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021D58: jal         0x80022540
    // 0x80021D5C: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_6;
    // 0x80021D5C: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x80021D60: b           L_80021DAC
    // 0x80021D64: swc1        $f0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f0.u32l;
        goto L_80021DAC;
    // 0x80021D64: swc1        $f0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f0.u32l;
L_80021D68:
    // 0x80021D68: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80021D6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021D70: jal         0x80022888
    // 0x80021D74: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    lerp(rdram, ctx);
        goto after_7;
    // 0x80021D74: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x80021D78: addiu       $s1, $sp, 0x110
    ctx->r17 = ADD32(ctx->r29, 0X110);
    // 0x80021D7C: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021D80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021D88: jal         0x80022888
    // 0x80021D8C: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    lerp(rdram, ctx);
        goto after_8;
    // 0x80021D8C: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x80021D90: addiu       $s2, $sp, 0xFC
    ctx->r18 = ADD32(ctx->r29, 0XFC);
    // 0x80021D94: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021D98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021D9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021DA0: jal         0x80022888
    // 0x80021DA4: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    lerp(rdram, ctx);
        goto after_9;
    // 0x80021DA4: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x80021DA8: swc1        $f0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f0.u32l;
L_80021DAC:
    // 0x80021DAC: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x80021DB0: lwc1        $f4, 0xF8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80021DB4: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80021DB8: lwc1        $f6, 0xF4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80021DBC: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80021DC0: swc1        $f10, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f10.u32l;
    // 0x80021DC4: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80021DC8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80021DCC: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80021DD0: lwc1        $f6, 0xF0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80021DD4: swc1        $f8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f8.u32l;
    // 0x80021DD8: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80021DDC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80021DE0: sub.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80021DE4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80021DE8: jal         0x80011570
    // 0x80021DEC: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    move_object(rdram, ctx);
        goto after_10;
    // 0x80021DEC: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x80021DF0: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021DF4: addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // 0x80021DF8: jal         0x80022540
    // 0x80021DFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_11;
    // 0x80021DFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80021E00: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80021E04: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x80021E08: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80021E0C: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x80021E10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80021E14: lwc1        $f8, 0xC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80021E18: nop

    // 0x80021E1C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80021E20: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x80021E24: lw          $t8, 0x15C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X15C);
    // 0x80021E28: nop

    // 0x80021E2C: lbu         $v0, 0x2E($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X2E);
    // 0x80021E30: nop

    // 0x80021E34: beq         $v0, $at, L_80022504
    if (ctx->r2 == ctx->r1) {
        // 0x80021E38: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80022504;
    }
    // 0x80021E38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80021E3C: beq         $v0, $at, L_80021E54
    if (ctx->r2 == ctx->r1) {
        // 0x80021E40: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80021E54;
    }
    // 0x80021E40: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80021E44: beq         $v0, $at, L_80021FA0
    if (ctx->r2 == ctx->r1) {
        // 0x80021E48: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80021FA0;
    }
    // 0x80021E48: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80021E4C: b           L_800220D0
    // 0x80021E50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800220D0;
    // 0x80021E50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80021E54:
    // 0x80021E54: lw          $t9, 0x15C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X15C);
    // 0x80021E58: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021E5C: lb          $t3, 0x3F($t9)
    ctx->r11 = MEM_B(ctx->r25, 0X3F);
    // 0x80021E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021E64: bne         $t3, $zero, L_80021EB0
    if (ctx->r11 != 0) {
        // 0x80021E68: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80021EB0;
    }
    // 0x80021E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021E6C: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021E74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021E78: jal         0x8002263C
    // 0x80021E7C: addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    cubic_spline_interpolation(rdram, ctx);
        goto after_12;
    // 0x80021E7C: addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    after_12:
    // 0x80021E80: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021E84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021E88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021E8C: jal         0x8002263C
    // 0x80021E90: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    cubic_spline_interpolation(rdram, ctx);
        goto after_13;
    // 0x80021E90: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    after_13:
    // 0x80021E94: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021E98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021EA0: jal         0x8002263C
    // 0x80021EA4: addiu       $a3, $sp, 0xF0
    ctx->r7 = ADD32(ctx->r29, 0XF0);
    cubic_spline_interpolation(rdram, ctx);
        goto after_14;
    // 0x80021EA4: addiu       $a3, $sp, 0xF0
    ctx->r7 = ADD32(ctx->r29, 0XF0);
    after_14:
    // 0x80021EA8: b           L_80021EE4
    // 0x80021EAC: lwc1        $f20, 0xF8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XF8);
        goto L_80021EE4;
    // 0x80021EAC: lwc1        $f20, 0xF8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XF8);
L_80021EB0:
    // 0x80021EB0: jal         0x800228B0
    // 0x80021EB4: addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    lerp_and_get_derivative(rdram, ctx);
        goto after_15;
    // 0x80021EB4: addiu       $a3, $sp, 0xF8
    ctx->r7 = ADD32(ctx->r29, 0XF8);
    after_15:
    // 0x80021EB8: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021EBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021EC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021EC4: jal         0x800228B0
    // 0x80021EC8: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    lerp_and_get_derivative(rdram, ctx);
        goto after_16;
    // 0x80021EC8: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    after_16:
    // 0x80021ECC: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80021ED0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80021ED4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021ED8: jal         0x800228B0
    // 0x80021EDC: addiu       $a3, $sp, 0xF0
    ctx->r7 = ADD32(ctx->r29, 0XF0);
    lerp_and_get_derivative(rdram, ctx);
        goto after_17;
    // 0x80021EDC: addiu       $a3, $sp, 0xF0
    ctx->r7 = ADD32(ctx->r29, 0XF0);
    after_17:
    // 0x80021EE0: lwc1        $f20, 0xF8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XF8);
L_80021EE4:
    // 0x80021EE4: lwc1        $f2, 0xF4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80021EE8: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80021EEC: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80021EF0: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80021EF4: nop

    // 0x80021EF8: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80021EFC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80021F00: jal         0x800C9AD0
    // 0x80021F04: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_18;
    // 0x80021F04: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_18:
    // 0x80021F08: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80021F0C: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80021F10: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x80021F14: nop

    // 0x80021F18: bc1t        L_80021F60
    if (c1cs) {
        // 0x80021F1C: nop
    
            goto L_80021F60;
    }
    // 0x80021F1C: nop

    // 0x80021F20: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80021F24: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80021F28: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80021F2C: nop

    // 0x80021F30: div.d       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x80021F34: lwc1        $f20, 0xF8($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80021F38: lwc1        $f2, 0xF4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80021F3C: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80021F40: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80021F44: mul.s       $f20, $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f12.fl);
    // 0x80021F48: nop

    // 0x80021F4C: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80021F50: swc1        $f20, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f20.u32l;
    // 0x80021F54: mul.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80021F58: swc1        $f2, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f2.u32l;
    // 0x80021F5C: swc1        $f14, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f14.u32l;
L_80021F60:
    // 0x80021F60: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80021F64: lwc1        $f12, 0xF8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80021F68: jal         0x80070750
    // 0x80021F6C: nop

    arctan2_f(rdram, ctx);
        goto after_19;
    // 0x80021F6C: nop

    after_19:
    // 0x80021F70: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80021F74: lw          $t5, 0x154($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X154);
    // 0x80021F78: addu        $t4, $v0, $at
    ctx->r12 = ADD32(ctx->r2, ctx->r1);
    // 0x80021F7C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80021F80: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x80021F84: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80021F88: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80021F8C: jal         0x80070750
    // 0x80021F90: nop

    arctan2_f(rdram, ctx);
        goto after_20;
    // 0x80021F90: nop

    after_20:
    // 0x80021F94: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x80021F98: b           L_80022504
    // 0x80021F9C: sh          $v0, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r2;
        goto L_80022504;
    // 0x80021F9C: sh          $v0, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r2;
L_80021FA0:
    // 0x80021FA0: lh          $v1, -0x5188($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X5188);
    // 0x80021FA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80021FA8: blez        $v1, L_80021FFC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80021FAC: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_80021FFC;
    }
    // 0x80021FAC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80021FB0: lw          $a3, -0x518C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X518C);
    // 0x80021FB4: lw          $t6, 0x15C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X15C);
    // 0x80021FB8: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80021FBC: lb          $v0, 0x3E($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X3E);
    // 0x80021FC0: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x80021FC4: nop

    // 0x80021FC8: beq         $v0, $t9, L_80021FFC
    if (ctx->r2 == ctx->r25) {
        // 0x80021FCC: nop
    
            goto L_80021FFC;
    }
    // 0x80021FCC: nop

L_80021FD0:
    // 0x80021FD0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80021FD4: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80021FD8: beq         $at, $zero, L_80021FFC
    if (ctx->r1 == 0) {
        // 0x80021FDC: sll         $t3, $a1, 2
        ctx->r11 = S32(ctx->r5 << 2);
            goto L_80021FFC;
    }
    // 0x80021FDC: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80021FE0: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x80021FE4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80021FE8: nop

    // 0x80021FEC: lw          $t7, 0x7C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X7C);
    // 0x80021FF0: nop

    // 0x80021FF4: bne         $v0, $t7, L_80021FD0
    if (ctx->r2 != ctx->r15) {
        // 0x80021FF8: nop
    
            goto L_80021FD0;
    }
    // 0x80021FF8: nop

L_80021FFC:
    // 0x80021FFC: beq         $a1, $v1, L_80022504
    if (ctx->r5 == ctx->r3) {
        // 0x80022000: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80022504;
    }
    // 0x80022000: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80022004: lw          $t6, -0x518C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X518C);
    // 0x80022008: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8002200C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80022010: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x80022014: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x80022018: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
    // 0x8002201C: nop

    // 0x80022020: beq         $v1, $zero, L_80022508
    if (ctx->r3 == 0) {
        // 0x80022024: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80022508;
    }
    // 0x80022024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80022028: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002202C: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80022030: nop

    // 0x80022034: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80022038: swc1        $f10, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f10.u32l;
    // 0x8002203C: lwc1        $f6, 0x10($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X10);
    // 0x80022040: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80022044: nop

    // 0x80022048: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8002204C: swc1        $f4, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f4.u32l;
    // 0x80022050: lwc1        $f8, 0x14($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X14);
    // 0x80022054: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80022058: lwc1        $f4, 0xF8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x8002205C: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80022060: lwc1        $f8, 0xF4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x80022064: mul.s       $f10, $f4, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80022068: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    // 0x8002206C: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80022070: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x80022074: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80022078: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8002207C: jal         0x800C9AD0
    // 0x80022080: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_21;
    // 0x80022080: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_21:
    // 0x80022084: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80022088: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x8002208C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80022090: lwc1        $f12, 0xF8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x80022094: bc1f        L_80022504
    if (!c1cs) {
        // 0x80022098: swc1        $f0, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
            goto L_80022504;
    }
    // 0x80022098: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    // 0x8002209C: jal         0x80070750
    // 0x800220A0: nop

    arctan2_f(rdram, ctx);
        goto after_22;
    // 0x800220A0: nop

    after_22:
    // 0x800220A4: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x800220A8: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800220AC: addu        $t5, $v0, $at
    ctx->r13 = ADD32(ctx->r2, ctx->r1);
    // 0x800220B0: sh          $t5, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r13;
    // 0x800220B4: lwc1        $f14, 0xEC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800220B8: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800220BC: jal         0x80070750
    // 0x800220C0: nop

    arctan2_f(rdram, ctx);
        goto after_23;
    // 0x800220C0: nop

    after_23:
    // 0x800220C4: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x800220C8: b           L_80022504
    // 0x800220CC: sh          $v0, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r2;
        goto L_80022504;
    // 0x800220CC: sh          $v0, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r2;
L_800220D0:
    // 0x800220D0: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x800220D4: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x800220D8: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x800220DC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800220E0: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x800220E4: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x800220E8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800220EC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800220F0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800220F4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800220F8: addiu       $fp, $sp, 0xC0
    ctx->r30 = ADD32(ctx->r29, 0XC0);
    // 0x800220FC: addiu       $s6, $sp, 0xAC
    ctx->r22 = ADD32(ctx->r29, 0XAC);
    // 0x80022100: addiu       $t1, $sp, 0x98
    ctx->r9 = ADD32(ctx->r29, 0X98);
    // 0x80022104: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x80022108: addiu       $t0, $sp, 0xA8
    ctx->r8 = ADD32(ctx->r29, 0XA8);
    // 0x8002210C: addiu       $a3, $sp, 0xBC
    ctx->r7 = ADD32(ctx->r29, 0XBC);
    // 0x80022110: addiu       $a2, $sp, 0xD0
    ctx->r6 = ADD32(ctx->r29, 0XD0);
L_80022114:
    // 0x80022114: lwc1        $f6, 0x0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80022118: lwc1        $f8, -0x4($fp)
    ctx->f8.u32l = MEM_W(ctx->r30, -0X4);
    // 0x8002211C: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80022120: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80022124: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x80022128: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x8002212C: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x80022130: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x80022134: bc1f        L_8002214C
    if (!c1cs) {
        // 0x80022138: subu        $a0, $t2, $a1
        ctx->r4 = SUB32(ctx->r10, ctx->r5);
            goto L_8002214C;
    }
    // 0x80022138: subu        $a0, $t2, $a1
    ctx->r4 = SUB32(ctx->r10, ctx->r5);
    // 0x8002213C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80022140: sub.d       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f4.d - ctx->f14.d;
    // 0x80022144: b           L_80022168
    // 0x80022148: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
        goto L_80022168;
    // 0x80022148: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_8002214C:
    // 0x8002214C: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x80022150: nop

    // 0x80022154: bc1f        L_80022168
    if (!c1cs) {
        // 0x80022158: nop
    
            goto L_80022168;
    }
    // 0x80022158: nop

    // 0x8002215C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80022160: add.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f6.d + ctx->f14.d;
    // 0x80022164: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_80022168:
    // 0x80022168: beq         $at, $zero, L_800221EC
    if (ctx->r1 == 0) {
        // 0x8002216C: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_800221EC;
    }
    // 0x8002216C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80022170: andi        $t8, $a0, 0x3
    ctx->r24 = ctx->r4 & 0X3;
    // 0x80022174: beq         $t8, $zero, L_800221A4
    if (ctx->r24 == 0) {
        // 0x80022178: addu        $v1, $t8, $a1
        ctx->r3 = ADD32(ctx->r24, ctx->r5);
            goto L_800221A4;
    }
    // 0x80022178: addu        $v1, $t8, $a1
    ctx->r3 = ADD32(ctx->r24, ctx->r5);
    // 0x8002217C: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80022180: addiu       $t3, $sp, 0xBC
    ctx->r11 = ADD32(ctx->r29, 0XBC);
    // 0x80022184: addu        $v0, $t9, $t3
    ctx->r2 = ADD32(ctx->r25, ctx->r11);
L_80022188:
    // 0x80022188: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002218C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80022190: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80022194: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022198: bne         $v1, $s0, L_80022188
    if (ctx->r3 != ctx->r16) {
        // 0x8002219C: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80022188;
    }
    // 0x8002219C: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800221A0: beq         $s0, $t2, L_800221E8
    if (ctx->r16 == ctx->r10) {
        // 0x800221A4: sll         $t4, $s0, 2
        ctx->r12 = S32(ctx->r16 << 2);
            goto L_800221E8;
    }
L_800221A4:
    // 0x800221A4: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x800221A8: addiu       $t5, $sp, 0xBC
    ctx->r13 = ADD32(ctx->r29, 0XBC);
    // 0x800221AC: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
L_800221B0:
    // 0x800221B0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800221B4: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800221B8: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800221BC: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800221C0: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800221C4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800221C8: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800221CC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800221D0: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800221D4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800221D8: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800221DC: swc1        $f8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800221E0: bne         $v0, $a2, L_800221B0
    if (ctx->r2 != ctx->r6) {
        // 0x800221E4: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_800221B0;
    }
    // 0x800221E4: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
L_800221E8:
    // 0x800221E8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
L_800221EC:
    // 0x800221EC: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800221F0: lwc1        $f8, -0x4($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, -0X4);
    // 0x800221F4: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800221F8: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800221FC: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x80022200: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80022204: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x80022208: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x8002220C: bc1f        L_80022224
    if (!c1cs) {
        // 0x80022210: addiu       $t7, $zero, 0x5
        ctx->r15 = ADD32(0, 0X5);
            goto L_80022224;
    }
    // 0x80022210: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80022214: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80022218: sub.d       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f4.d - ctx->f14.d;
    // 0x8002221C: b           L_80022240
    // 0x80022220: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
        goto L_80022240;
    // 0x80022220: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80022224:
    // 0x80022224: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x80022228: nop

    // 0x8002222C: bc1f        L_80022240
    if (!c1cs) {
        // 0x80022230: nop
    
            goto L_80022240;
    }
    // 0x80022230: nop

    // 0x80022234: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80022238: add.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f6.d + ctx->f14.d;
    // 0x8002223C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_80022240:
    // 0x80022240: beq         $at, $zero, L_800222C4
    if (ctx->r1 == 0) {
        // 0x80022244: subu        $a0, $t7, $a1
        ctx->r4 = SUB32(ctx->r15, ctx->r5);
            goto L_800222C4;
    }
    // 0x80022244: subu        $a0, $t7, $a1
    ctx->r4 = SUB32(ctx->r15, ctx->r5);
    // 0x80022248: andi        $t6, $a0, 0x3
    ctx->r14 = ctx->r4 & 0X3;
    // 0x8002224C: beq         $t6, $zero, L_8002227C
    if (ctx->r14 == 0) {
        // 0x80022250: addu        $v1, $t6, $a1
        ctx->r3 = ADD32(ctx->r14, ctx->r5);
            goto L_8002227C;
    }
    // 0x80022250: addu        $v1, $t6, $a1
    ctx->r3 = ADD32(ctx->r14, ctx->r5);
    // 0x80022254: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80022258: addiu       $t9, $sp, 0xA8
    ctx->r25 = ADD32(ctx->r29, 0XA8);
    // 0x8002225C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
L_80022260:
    // 0x80022260: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80022264: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80022268: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002226C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022270: bne         $v1, $s0, L_80022260
    if (ctx->r3 != ctx->r16) {
        // 0x80022274: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80022260;
    }
    // 0x80022274: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80022278: beq         $s0, $t2, L_800222C0
    if (ctx->r16 == ctx->r10) {
        // 0x8002227C: sll         $t3, $s0, 2
        ctx->r11 = S32(ctx->r16 << 2);
            goto L_800222C0;
    }
L_8002227C:
    // 0x8002227C: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80022280: addiu       $t4, $sp, 0xA8
    ctx->r12 = ADD32(ctx->r29, 0XA8);
    // 0x80022284: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
L_80022288:
    // 0x80022288: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002228C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80022290: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80022294: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80022298: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002229C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800222A0: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800222A4: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800222A8: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800222AC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800222B0: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800222B4: swc1        $f8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800222B8: bne         $v0, $a3, L_80022288
    if (ctx->r2 != ctx->r7) {
        // 0x800222BC: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80022288;
    }
    // 0x800222BC: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
L_800222C0:
    // 0x800222C0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
L_800222C4:
    // 0x800222C4: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800222C8: lwc1        $f8, -0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, -0X4);
    // 0x800222CC: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x800222D0: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800222D4: subu        $a0, $t5, $a1
    ctx->r4 = SUB32(ctx->r13, ctx->r5);
    // 0x800222D8: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x800222DC: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x800222E0: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x800222E4: bc1f        L_800222FC
    if (!c1cs) {
        // 0x800222E8: slti        $at, $a1, 0x5
        ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
            goto L_800222FC;
    }
    // 0x800222E8: slti        $at, $a1, 0x5
    ctx->r1 = SIGNED(ctx->r5) < 0X5 ? 1 : 0;
    // 0x800222EC: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800222F0: sub.d       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f4.d - ctx->f14.d;
    // 0x800222F4: b           L_80022318
    // 0x800222F8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
        goto L_80022318;
    // 0x800222F8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800222FC:
    // 0x800222FC: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x80022300: nop

    // 0x80022304: bc1f        L_80022318
    if (!c1cs) {
        // 0x80022308: nop
    
            goto L_80022318;
    }
    // 0x80022308: nop

    // 0x8002230C: cvt.d.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.d = CVT_D_S(ctx->f16.fl);
    // 0x80022310: add.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f6.d + ctx->f14.d;
    // 0x80022314: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_80022318:
    // 0x80022318: beq         $at, $zero, L_80022394
    if (ctx->r1 == 0) {
        // 0x8002231C: andi        $t7, $a0, 0x3
        ctx->r15 = ctx->r4 & 0X3;
            goto L_80022394;
    }
    // 0x8002231C: andi        $t7, $a0, 0x3
    ctx->r15 = ctx->r4 & 0X3;
    // 0x80022320: beq         $t7, $zero, L_80022350
    if (ctx->r15 == 0) {
        // 0x80022324: addu        $v1, $t7, $a1
        ctx->r3 = ADD32(ctx->r15, ctx->r5);
            goto L_80022350;
    }
    // 0x80022324: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x80022328: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8002232C: addiu       $t8, $sp, 0x94
    ctx->r24 = ADD32(ctx->r29, 0X94);
    // 0x80022330: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
L_80022334:
    // 0x80022334: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80022338: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002233C: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80022340: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022344: bne         $v1, $s0, L_80022334
    if (ctx->r3 != ctx->r16) {
        // 0x80022348: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80022334;
    }
    // 0x80022348: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x8002234C: beq         $s0, $t2, L_80022394
    if (ctx->r16 == ctx->r10) {
        // 0x80022350: sll         $t9, $s0, 2
        ctx->r25 = S32(ctx->r16 << 2);
            goto L_80022394;
    }
L_80022350:
    // 0x80022350: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80022354: addiu       $t3, $sp, 0x94
    ctx->r11 = ADD32(ctx->r29, 0X94);
    // 0x80022358: addu        $v0, $t9, $t3
    ctx->r2 = ADD32(ctx->r25, ctx->r11);
L_8002235C:
    // 0x8002235C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80022360: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80022364: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80022368: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002236C: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80022370: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80022374: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80022378: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8002237C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80022380: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80022384: add.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80022388: swc1        $f8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8002238C: bne         $v0, $t0, L_8002235C
    if (ctx->r2 != ctx->r8) {
        // 0x80022390: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_8002235C;
    }
    // 0x80022390: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
L_80022394:
    // 0x80022394: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80022398: bne         $a1, $t2, L_80022114
    if (ctx->r5 != ctx->r10) {
        // 0x8002239C: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_80022114;
    }
    // 0x8002239C: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800223A0: lw          $t4, 0x15C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X15C);
    // 0x800223A4: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x800223A8: lb          $t5, 0x3F($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X3F);
    // 0x800223AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800223B0: bne         $t5, $zero, L_80022460
    if (ctx->r13 != 0) {
        // 0x800223B4: addiu       $a0, $sp, 0xBC
        ctx->r4 = ADD32(ctx->r29, 0XBC);
            goto L_80022460;
    }
    // 0x800223B4: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    // 0x800223B8: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x800223BC: jal         0x80022540
    // 0x800223C0: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    catmull_rom_interpolation(rdram, ctx);
        goto after_24;
    // 0x800223C0: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    after_24:
    // 0x800223C4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800223C8: lw          $t8, 0x154($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X154);
    // 0x800223CC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800223D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800223D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800223D8: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x800223DC: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800223E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800223E4: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800223E8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800223EC: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x800223F0: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x800223F4: jal         0x80022540
    // 0x800223F8: nop

    catmull_rom_interpolation(rdram, ctx);
        goto after_25;
    // 0x800223F8: nop

    after_25:
    // 0x800223FC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80022400: lw          $t4, 0x154($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X154);
    // 0x80022404: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80022408: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002240C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022410: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x80022414: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80022418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002241C: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80022420: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80022424: sh          $t3, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r11;
    // 0x80022428: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x8002242C: jal         0x80022540
    // 0x80022430: nop

    catmull_rom_interpolation(rdram, ctx);
        goto after_26;
    // 0x80022430: nop

    after_26:
    // 0x80022434: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80022438: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x8002243C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80022440: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022444: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022448: nop

    // 0x8002244C: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80022450: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80022454: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80022458: b           L_80022504
    // 0x8002245C: sh          $t7, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r15;
        goto L_80022504;
    // 0x8002245C: sh          $t7, 0x4($t6)
    MEM_H(0X4, ctx->r14) = ctx->r15;
L_80022460:
    // 0x80022460: jal         0x80022888
    // 0x80022464: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lerp(rdram, ctx);
        goto after_27;
    // 0x80022464: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x80022468: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002246C: lw          $t3, 0x154($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X154);
    // 0x80022470: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80022474: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022478: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002247C: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x80022480: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80022484: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80022488: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8002248C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80022490: sh          $t9, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r25;
    // 0x80022494: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x80022498: jal         0x80022888
    // 0x8002249C: nop

    lerp(rdram, ctx);
        goto after_28;
    // 0x8002249C: nop

    after_28:
    // 0x800224A0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800224A4: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x800224A8: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800224AC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800224B0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800224B4: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x800224B8: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800224BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800224C0: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800224C4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800224C8: sh          $t5, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r13;
    // 0x800224CC: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x800224D0: jal         0x80022888
    // 0x800224D4: nop

    lerp(rdram, ctx);
        goto after_29;
    // 0x800224D4: nop

    after_29:
    // 0x800224D8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800224DC: lw          $t9, 0x154($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X154);
    // 0x800224E0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800224E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800224E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800224EC: nop

    // 0x800224F0: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800224F4: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800224F8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800224FC: sh          $t8, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r24;
    // 0x80022500: nop

L_80022504:
    // 0x80022504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80022508:
    // 0x80022508: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002250C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80022510: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80022514: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80022518: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8002251C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80022520: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80022524: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80022528: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8002252C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80022530: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80022534: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80022538: jr          $ra
    // 0x8002253C: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
    return;
    // 0x8002253C: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
;}
RECOMP_FUNC void get_previous_particle_table(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B452C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B4530: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B4534: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x800B4538: bgez        $v1, L_800B4560
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800B453C: sw          $v1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r3;
            goto L_800B4560;
    }
    // 0x800B453C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800B4540: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B4544: addiu       $v0, $v0, 0x2CE8
    ctx->r2 = ADD32(ctx->r2, 0X2CE8);
L_800B4548:
    // 0x800B4548: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B454C: nop

    // 0x800B4550: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800B4554: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B4558: bltz        $t9, L_800B4548
    if (SIGNED(ctx->r25) < 0) {
        // 0x800B455C: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_800B4548;
    }
    // 0x800B455C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_800B4560:
    // 0x800B4560: lw          $t0, 0x2CF0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2CF0);
    // 0x800B4564: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800B4568: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B456C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800B4570: jr          $ra
    // 0x800B4574: nop

    return;
    // 0x800B4574: nop

;}
RECOMP_FUNC void decrypt_magic_codes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C2D8: sra         $a2, $a1, 2
    ctx->r6 = S32(SIGNED(ctx->r5) >> 2);
    // 0x8000C2DC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8000C2E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000C2E4: blez        $a2, L_8000C458
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8000C2E8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000C458;
    }
    // 0x8000C2E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000C2EC:
    // 0x8000C2EC: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x8000C2F0: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C2F4: andi        $t7, $t6, 0xC0
    ctx->r15 = ctx->r14 & 0XC0;
    // 0x8000C2F8: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x8000C2FC: sra         $t8, $t7, 6
    ctx->r24 = S32(SIGNED(ctx->r15) >> 6);
    // 0x8000C300: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x8000C304: andi        $t1, $t9, 0xC0
    ctx->r9 = ctx->r25 & 0XC0;
    // 0x8000C308: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x8000C30C: andi        $t4, $t3, 0xC0
    ctx->r12 = ctx->r11 & 0XC0;
    // 0x8000C310: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x8000C314: andi        $t9, $t7, 0xC0
    ctx->r25 = ctx->r15 & 0XC0;
    // 0x8000C318: sra         $t8, $t9, 4
    ctx->r24 = S32(SIGNED(ctx->r25) >> 4);
    // 0x8000C31C: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x8000C320: or          $t1, $t6, $t8
    ctx->r9 = ctx->r14 | ctx->r24;
    // 0x8000C324: sb          $t1, 0x0($sp)
    MEM_B(0X0, ctx->r29) = ctx->r9;
    // 0x8000C328: lbu         $t3, 0x3($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X3);
    // 0x8000C32C: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C330: andi        $t4, $t3, 0x30
    ctx->r12 = ctx->r11 & 0X30;
    // 0x8000C334: sra         $t2, $t4, 4
    ctx->r10 = S32(SIGNED(ctx->r12) >> 4);
    // 0x8000C338: lbu         $t4, 0x2($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X2);
    // 0x8000C33C: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8000C340: andi        $t7, $t5, 0x30
    ctx->r15 = ctx->r13 & 0X30;
    // 0x8000C344: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8000C348: or          $t6, $t2, $t9
    ctx->r14 = ctx->r10 | ctx->r25;
    // 0x8000C34C: andi        $t5, $t4, 0x30
    ctx->r13 = ctx->r12 & 0X30;
    // 0x8000C350: andi        $t1, $t8, 0x30
    ctx->r9 = ctx->r24 & 0X30;
    // 0x8000C354: or          $t3, $t6, $t1
    ctx->r11 = ctx->r14 | ctx->r9;
    // 0x8000C358: sra         $t7, $t5, 2
    ctx->r15 = S32(SIGNED(ctx->r13) >> 2);
    // 0x8000C35C: or          $t2, $t3, $t7
    ctx->r10 = ctx->r11 | ctx->r15;
    // 0x8000C360: sb          $t2, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r10;
    // 0x8000C364: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C368: lbu         $t9, 0x3($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X3);
    // 0x8000C36C: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x8000C370: andi        $t4, $t1, 0xC
    ctx->r12 = ctx->r9 & 0XC;
    // 0x8000C374: andi        $t8, $t9, 0xC
    ctx->r24 = ctx->r25 & 0XC;
    // 0x8000C378: lbu         $t1, 0x2($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2);
    // 0x8000C37C: sra         $t6, $t8, 2
    ctx->r14 = S32(SIGNED(ctx->r24) >> 2);
    // 0x8000C380: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8000C384: andi        $t2, $t7, 0xC
    ctx->r10 = ctx->r15 & 0XC;
    // 0x8000C388: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x8000C38C: or          $t3, $t6, $t5
    ctx->r11 = ctx->r14 | ctx->r13;
    // 0x8000C390: or          $t8, $t3, $t9
    ctx->r24 = ctx->r11 | ctx->r25;
    // 0x8000C394: andi        $t4, $t1, 0xC
    ctx->r12 = ctx->r9 & 0XC;
    // 0x8000C398: or          $t6, $t8, $t4
    ctx->r14 = ctx->r24 | ctx->r12;
    // 0x8000C39C: sb          $t6, 0x2($sp)
    MEM_B(0X2, ctx->r29) = ctx->r14;
    // 0x8000C3A0: lbu         $t5, 0x3($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X3);
    // 0x8000C3A4: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8000C3A8: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C3AC: andi        $t7, $t5, 0x3
    ctx->r15 = ctx->r13 & 0X3;
    // 0x8000C3B0: andi        $t4, $t8, 0x3
    ctx->r12 = ctx->r24 & 0X3;
    // 0x8000C3B4: sll         $t9, $t3, 6
    ctx->r25 = S32(ctx->r11 << 6);
    // 0x8000C3B8: lbu         $t2, 0x2($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2);
    // 0x8000C3BC: lbu         $a0, 0x0($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X0);
    // 0x8000C3C0: or          $t1, $t7, $t9
    ctx->r9 = ctx->r15 | ctx->r25;
    // 0x8000C3C4: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x8000C3C8: or          $t5, $t1, $t6
    ctx->r13 = ctx->r9 | ctx->r14;
    // 0x8000C3CC: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x8000C3D0: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x8000C3D4: andi        $t1, $a0, 0xAA
    ctx->r9 = ctx->r4 & 0XAA;
    // 0x8000C3D8: andi        $t8, $a0, 0x55
    ctx->r24 = ctx->r4 & 0X55;
    // 0x8000C3DC: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x8000C3E0: sll         $t4, $t8, 1
    ctx->r12 = S32(ctx->r24 << 1);
    // 0x8000C3E4: sra         $t6, $t1, 1
    ctx->r14 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8000C3E8: sb          $t9, 0x3($sp)
    MEM_B(0X3, ctx->r29) = ctx->r25;
    // 0x8000C3EC: or          $t2, $t4, $t6
    ctx->r10 = ctx->r12 | ctx->r14;
    // 0x8000C3F0: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x8000C3F4: lbu         $a1, 0x1($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1);
    // 0x8000C3F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000C3FC: andi        $t3, $a1, 0x55
    ctx->r11 = ctx->r5 & 0X55;
    // 0x8000C400: andi        $t7, $a1, 0xAA
    ctx->r15 = ctx->r5 & 0XAA;
    // 0x8000C404: sra         $t9, $t7, 1
    ctx->r25 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8000C408: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x8000C40C: or          $t8, $t5, $t9
    ctx->r24 = ctx->r13 | ctx->r25;
    // 0x8000C410: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8000C414: lbu         $a3, 0x2($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2);
    // 0x8000C418: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000C41C: andi        $t1, $a3, 0x55
    ctx->r9 = ctx->r7 & 0X55;
    // 0x8000C420: andi        $t6, $a3, 0xAA
    ctx->r14 = ctx->r7 & 0XAA;
    // 0x8000C424: sra         $t2, $t6, 1
    ctx->r10 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8000C428: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x8000C42C: or          $t3, $t4, $t2
    ctx->r11 = ctx->r12 | ctx->r10;
    // 0x8000C430: sb          $t3, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r11;
    // 0x8000C434: lbu         $t0, 0x3($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3);
    // 0x8000C438: nop

    // 0x8000C43C: andi        $t7, $t0, 0x55
    ctx->r15 = ctx->r8 & 0X55;
    // 0x8000C440: andi        $t9, $t0, 0xAA
    ctx->r25 = ctx->r8 & 0XAA;
    // 0x8000C444: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8000C448: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x8000C44C: or          $t1, $t5, $t8
    ctx->r9 = ctx->r13 | ctx->r24;
    // 0x8000C450: bne         $v1, $a2, L_8000C2EC
    if (ctx->r3 != ctx->r6) {
        // 0x8000C454: sb          $t1, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r9;
            goto L_8000C2EC;
    }
    // 0x8000C454: sb          $t1, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r9;
L_8000C458:
    // 0x8000C458: jr          $ra
    // 0x8000C45C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8000C45C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void tex_init_textures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AC70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007AC74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007AC78: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007AC7C: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007AC80: jal         0x80070C9C
    // 0x8007AC84: addiu       $a0, $zero, 0x15E0
    ctx->r4 = ADD32(0, 0X15E0);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8007AC84: addiu       $a0, $zero, 0x15E0
    ctx->r4 = ADD32(0, 0X15E0);
    after_0:
    // 0x8007AC88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007AC8C: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007AC90: sw          $v0, 0x6328($at)
    MEM_W(0X6328, ctx->r1) = ctx->r2;
    // 0x8007AC94: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007AC98: jal         0x80070C9C
    // 0x8007AC9C: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x8007AC9C: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    after_1:
    // 0x8007ACA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007ACA4: sw          $v0, 0x632C($at)
    MEM_W(0X632C, ctx->r1) = ctx->r2;
    // 0x8007ACA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007ACAC: sw          $zero, 0x6330($at)
    MEM_W(0X6330, ctx->r1) = 0;
    // 0x8007ACB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007ACB4: sw          $zero, 0x6340($at)
    MEM_W(0X6340, ctx->r1) = 0;
    // 0x8007ACB8: jal         0x80076C58
    // 0x8007ACBC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    asset_table_load(rdram, ctx);
        goto after_2;
    // 0x8007ACBC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_2:
    // 0x8007ACC0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007ACC4: addiu       $a1, $a1, 0x6320
    ctx->r5 = ADD32(ctx->r5, 0X6320);
    // 0x8007ACC8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8007ACCC: jal         0x80076C58
    // 0x8007ACD0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    asset_table_load(rdram, ctx);
        goto after_3;
    // 0x8007ACD0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x8007ACD4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007ACD8: addiu       $a1, $a1, 0x6320
    ctx->r5 = ADD32(ctx->r5, 0X6320);
    // 0x8007ACDC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8007ACE0: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8007ACE4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8007ACE8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8007ACEC: beq         $a3, $t6, L_8007AD08
    if (ctx->r7 == ctx->r14) {
        // 0x8007ACF0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007AD08;
    }
    // 0x8007ACF0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007ACF4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007ACF8:
    // 0x8007ACF8: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8007ACFC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007AD00: bne         $a3, $t7, L_8007ACF8
    if (ctx->r7 != ctx->r15) {
        // 0x8007AD04: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8007ACF8;
    }
    // 0x8007AD04: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8007AD08:
    // 0x8007AD08: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007AD0C: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    // 0x8007AD10: addiu       $a2, $a2, 0x6338
    ctx->r6 = ADD32(ctx->r6, 0X6338);
    // 0x8007AD14: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8007AD18: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x8007AD1C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8007AD20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007AD24: beq         $a3, $t8, L_8007AD40
    if (ctx->r7 == ctx->r24) {
        // 0x8007AD28: lui         $a1, 0xFF00
        ctx->r5 = S32(0XFF00 << 16);
            goto L_8007AD40;
    }
    // 0x8007AD28: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007AD2C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007AD30:
    // 0x8007AD30: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8007AD34: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007AD38: bne         $a3, $t9, L_8007AD30
    if (ctx->r7 != ctx->r25) {
        // 0x8007AD3C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8007AD30;
    }
    // 0x8007AD3C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8007AD40:
    // 0x8007AD40: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8007AD44: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x8007AD48: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    // 0x8007AD4C: jal         0x80070C9C
    // 0x8007AD50: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x8007AD50: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    after_4:
    // 0x8007AD54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007AD58: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007AD5C: sw          $v0, 0x634C($at)
    MEM_W(0X634C, ctx->r1) = ctx->r2;
    // 0x8007AD60: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007AD64: jal         0x80070C9C
    // 0x8007AD68: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x8007AD68: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_5:
    // 0x8007AD6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007AD70: sw          $v0, 0x6350($at)
    MEM_W(0X6350, ctx->r1) = ctx->r2;
    // 0x8007AD74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007AD78: sw          $zero, 0x6358($at)
    MEM_W(0X6358, ctx->r1) = 0;
    // 0x8007AD7C: jal         0x80076C58
    // 0x8007AD80: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    asset_table_load(rdram, ctx);
        goto after_6;
    // 0x8007AD80: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_6:
    // 0x8007AD84: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007AD88: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8007AD8C: addiu       $a2, $a2, 0x6354
    ctx->r6 = ADD32(ctx->r6, 0X6354);
    // 0x8007AD90: addiu       $a1, $a1, 0x6348
    ctx->r5 = ADD32(ctx->r5, 0X6348);
    // 0x8007AD94: sll         $t0, $zero, 2
    ctx->r8 = S32(0 << 2);
    // 0x8007AD98: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8007AD9C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8007ADA0: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8007ADA4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8007ADA8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8007ADAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8007ADB0: beq         $a3, $t2, L_8007ADD8
    if (ctx->r7 == ctx->r10) {
        // 0x8007ADB4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007ADD8;
    }
    // 0x8007ADB4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007ADB8: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
L_8007ADBC:
    // 0x8007ADBC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007ADC0: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x8007ADC4: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x8007ADC8: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8007ADCC: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x8007ADD0: bne         $a3, $t6, L_8007ADBC
    if (ctx->r7 != ctx->r14) {
        // 0x8007ADD4: addiu       $t3, $v1, 0x1
        ctx->r11 = ADD32(ctx->r3, 0X1);
            goto L_8007ADBC;
    }
    // 0x8007ADD4: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
L_8007ADD8:
    // 0x8007ADD8: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8007ADDC: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8007ADE0: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8007ADE4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8007ADE8: jal         0x80070C9C
    // 0x8007ADEC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x8007ADEC: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_7:
    // 0x8007ADF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007ADF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007ADF8: sw          $v0, 0x636C($at)
    MEM_W(0X636C, ctx->r1) = ctx->r2;
    // 0x8007ADFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007AE00: sw          $zero, 0x6344($at)
    MEM_W(0X6344, ctx->r1) = 0;
    // 0x8007AE04: jr          $ra
    // 0x8007AE08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007AE08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void music_voicelimit_change_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C1C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80000C20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000C24: jr          $ra
    // 0x80000C28: sb          $t6, -0x3990($at)
    MEM_B(-0X3990, ctx->r1) = ctx->r14;
    return;
    // 0x80000C28: sb          $t6, -0x3990($at)
    MEM_B(-0X3990, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void rumble_set_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072424: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80072428: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8007242C: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80072430: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80072434: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80072438: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8007243C: slti        $at, $t8, 0x13
    ctx->r1 = SIGNED(ctx->r24) < 0X13 ? 1 : 0;
    // 0x80072440: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80072444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072448: beq         $at, $zero, L_80072568
    if (ctx->r1 == 0) {
        // 0x8007244C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80072568;
    }
    // 0x8007244C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80072450: bltz        $t7, L_80072568
    if (SIGNED(ctx->r15) < 0) {
        // 0x80072454: slti        $at, $t7, 0x4
        ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
            goto L_80072568;
    }
    // 0x80072454: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80072458: beq         $at, $zero, L_8007256C
    if (ctx->r1 == 0) {
        // 0x8007245C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007256C;
    }
    // 0x8007245C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072460: sh          $t7, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r15;
    // 0x80072464: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80072468: jal         0x80072250
    // 0x8007246C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    input_get_id(rdram, ctx);
        goto after_0;
    // 0x8007246C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80072470: andi        $t9, $v0, 0xFFFF
    ctx->r25 = ctx->r2 & 0XFFFF;
    // 0x80072474: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80072478: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8007247C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80072480: addiu       $t1, $t1, 0x41B8
    ctx->r9 = ADD32(ctx->r9, 0X41B8);
    // 0x80072484: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80072488: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x8007248C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80072490: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x80072494: lh          $a0, 0x22($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X22);
    // 0x80072498: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007249C: bne         $a2, $t2, L_800724D0
    if (ctx->r6 != ctx->r10) {
        // 0x800724A0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800724D0;
    }
    // 0x800724A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800724A4: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
    // 0x800724A8: addiu       $t4, $zero, -0x12C
    ctx->r12 = ADD32(0, -0X12C);
    // 0x800724AC: bgez        $t3, L_800724B8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800724B0: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800724B8;
    }
    // 0x800724B0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800724B4: sh          $t4, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r12;
L_800724B8:
    // 0x800724B8: lw          $t5, 0x41E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X41E0);
    // 0x800724BC: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800724C0: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800724C4: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x800724C8: b           L_80072568
    // 0x800724CC: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
        goto L_80072568;
    // 0x800724CC: sh          $t9, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r25;
L_800724D0:
    // 0x800724D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800724D4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800724D8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800724DC: nop

    // 0x800724E0: bc1f        L_800724EC
    if (!c1cs) {
        // 0x800724E4: nop
    
            goto L_800724EC;
    }
    // 0x800724E4: nop

    // 0x800724E8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_800724EC:
    // 0x800724EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800724F0: nop

    // 0x800724F4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800724F8: nop

    // 0x800724FC: bc1f        L_80072508
    if (!c1cs) {
        // 0x80072500: nop
    
            goto L_80072508;
    }
    // 0x80072500: nop

    // 0x80072504: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80072508:
    // 0x80072508: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
    // 0x8007250C: lw          $t0, 0x41E0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X41E0);
    // 0x80072510: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80072514: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x80072518: lh          $a3, 0x0($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X0);
    // 0x8007251C: nop

    // 0x80072520: beq         $a3, $zero, L_8007256C
    if (ctx->r7 == 0) {
        // 0x80072524: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007256C;
    }
    // 0x80072524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072528: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8007252C: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80072530: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80072534: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80072538: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8007253C: nop

    // 0x80072540: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80072544: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80072548: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007254C: nop

    // 0x80072550: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80072554: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80072558: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8007255C: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80072560: jal         0x80072578
    // 0x80072564: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    rumble_start(rdram, ctx);
        goto after_1;
    // 0x80072564: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    after_1:
L_80072568:
    // 0x80072568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007256C:
    // 0x8007256C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80072570: jr          $ra
    // 0x80072574: nop

    return;
    // 0x80072574: nop

;}
RECOMP_FUNC void increment_ai_behaviour_chances(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043ECC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80043ED0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80043ED4: bne         $a0, $zero, L_80043EF8
    if (ctx->r4 != 0) {
        // 0x80043ED8: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80043EF8;
    }
    // 0x80043ED8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80043EDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043EE0: sb          $zero, -0x2A46($at)
    MEM_B(-0X2A46, ctx->r1) = 0;
    // 0x80043EE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043EE8: sb          $zero, -0x2A45($at)
    MEM_B(-0X2A45, ctx->r1) = 0;
    // 0x80043EEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043EF0: b           L_80044160
    // 0x80043EF4: sb          $zero, -0x2A44($at)
    MEM_B(-0X2A44, ctx->r1) = 0;
        goto L_80044160;
    // 0x80043EF4: sb          $zero, -0x2A44($at)
    MEM_B(-0X2A44, ctx->r1) = 0;
L_80043EF8:
    // 0x80043EF8: jal         0x8006C18C
    // 0x80043EFC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    aitable_get(rdram, ctx);
        goto after_0;
    // 0x80043EFC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80043F00: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80043F04: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80043F08: lb          $t6, 0x1D3($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1D3);
    // 0x80043F0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043F10: beq         $t6, $zero, L_80043F7C
    if (ctx->r14 == 0) {
        // 0x80043F14: addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
            goto L_80043F7C;
    }
    // 0x80043F14: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80043F18: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80043F1C: lb          $t7, -0x2A45($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X2A45);
    // 0x80043F20: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80043F24: bne         $t7, $zero, L_80043F54
    if (ctx->r15 != 0) {
        // 0x80043F28: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_80043F54;
    }
    // 0x80043F28: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80043F2C: lb          $t8, 0x14($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X14);
    // 0x80043F30: lb          $t9, 0x16($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X16);
    // 0x80043F34: lb          $t1, 0x15($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X15);
    // 0x80043F38: lb          $t2, 0x17($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X17);
    // 0x80043F3C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80043F40: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80043F44: sb          $t0, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r8;
    // 0x80043F48: sb          $t3, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r11;
    // 0x80043F4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043F50: sb          $t4, -0x2A45($at)
    MEM_B(-0X2A45, ctx->r1) = ctx->r12;
L_80043F54:
    // 0x80043F54: lw          $t5, -0x2AD8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AD8);
    // 0x80043F58: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80043F5C: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x80043F60: bne         $t6, $zero, L_80043FBC
    if (ctx->r14 != 0) {
        // 0x80043F64: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_80043FBC;
    }
    // 0x80043F64: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80043F68: lb          $t7, -0x2A46($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X2A46);
    // 0x80043F6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043F70: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80043F74: b           L_80043FBC
    // 0x80043F78: sb          $t9, -0x2A46($at)
    MEM_B(-0X2A46, ctx->r1) = ctx->r25;
        goto L_80043FBC;
    // 0x80043F78: sb          $t9, -0x2A46($at)
    MEM_B(-0X2A46, ctx->r1) = ctx->r25;
L_80043F7C:
    // 0x80043F7C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80043F80: lb          $t0, -0x2A46($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2A46);
    // 0x80043F84: sb          $zero, -0x2A45($at)
    MEM_B(-0X2A45, ctx->r1) = 0;
    // 0x80043F88: slti        $at, $t0, 0x15
    ctx->r1 = SIGNED(ctx->r8) < 0X15 ? 1 : 0;
    // 0x80043F8C: bne         $at, $zero, L_80043FB4
    if (ctx->r1 != 0) {
        // 0x80043F90: nop
    
            goto L_80043FB4;
    }
    // 0x80043F90: nop

    // 0x80043F94: lb          $t1, 0x8($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X8);
    // 0x80043F98: lb          $t2, 0xA($v0)
    ctx->r10 = MEM_B(ctx->r2, 0XA);
    // 0x80043F9C: lb          $t4, 0x9($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X9);
    // 0x80043FA0: lb          $t5, 0xB($v0)
    ctx->r13 = MEM_B(ctx->r2, 0XB);
    // 0x80043FA4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80043FA8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80043FAC: sb          $t3, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r11;
    // 0x80043FB0: sb          $t6, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r14;
L_80043FB4:
    // 0x80043FB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043FB8: sb          $zero, -0x2A46($at)
    MEM_B(-0X2A46, ctx->r1) = 0;
L_80043FBC:
    // 0x80043FBC: lb          $t7, 0x173($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X173);
    // 0x80043FC0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80043FC4: beq         $t7, $zero, L_80044018
    if (ctx->r15 == 0) {
        // 0x80043FC8: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80044018;
    }
    // 0x80043FC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80043FCC: lb          $v1, 0x174($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X174);
    // 0x80043FD0: lb          $t8, -0x2A44($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X2A44);
    // 0x80043FD4: nop

    // 0x80043FD8: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80043FDC: beq         $at, $zero, L_8004400C
    if (ctx->r1 == 0) {
        // 0x80043FE0: nop
    
            goto L_8004400C;
    }
    // 0x80043FE0: nop

    // 0x80043FE4: lb          $t9, 0xC($v0)
    ctx->r25 = MEM_B(ctx->r2, 0XC);
    // 0x80043FE8: lb          $t0, 0xE($v0)
    ctx->r8 = MEM_B(ctx->r2, 0XE);
    // 0x80043FEC: lb          $t2, 0xD($v0)
    ctx->r10 = MEM_B(ctx->r2, 0XD);
    // 0x80043FF0: lb          $t3, 0xF($v0)
    ctx->r11 = MEM_B(ctx->r2, 0XF);
    // 0x80043FF4: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80043FF8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80043FFC: sb          $t1, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r9;
    // 0x80044000: sb          $t4, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r12;
    // 0x80044004: lb          $v1, 0x174($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X174);
    // 0x80044008: nop

L_8004400C:
    // 0x8004400C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044010: b           L_8004401C
    // 0x80044014: sb          $v1, -0x2A44($at)
    MEM_B(-0X2A44, ctx->r1) = ctx->r3;
        goto L_8004401C;
    // 0x80044014: sb          $v1, -0x2A44($at)
    MEM_B(-0X2A44, ctx->r1) = ctx->r3;
L_80044018:
    // 0x80044018: sb          $zero, -0x2A44($at)
    MEM_B(-0X2A44, ctx->r1) = 0;
L_8004401C:
    // 0x8004401C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80044020: jal         0x8001E29C
    // 0x80044024: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x80044024: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80044028: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004402C: lw          $t5, -0x2AD0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AD0);
    // 0x80044030: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80044034: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80044038: andi        $t6, $t5, 0x2000
    ctx->r14 = ctx->r13 & 0X2000;
    // 0x8004403C: beq         $t6, $zero, L_800440C8
    if (ctx->r14 == 0) {
        // 0x80044040: nop
    
            goto L_800440C8;
    }
    // 0x80044040: nop

    // 0x80044044: lb          $t7, 0x173($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X173);
    // 0x80044048: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8004404C: beq         $t7, $zero, L_800440C8
    if (ctx->r15 == 0) {
        // 0x80044050: nop
    
            goto L_800440C8;
    }
    // 0x80044050: nop

    // 0x80044054: lb          $v1, 0x174($a1)
    ctx->r3 = MEM_B(ctx->r5, 0X174);
    // 0x80044058: nop

    // 0x8004405C: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80044060: beq         $at, $zero, L_8004408C
    if (ctx->r1 == 0) {
        // 0x80044064: nop
    
            goto L_8004408C;
    }
    // 0x80044064: nop

    // 0x80044068: lb          $t8, 0x172($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X172);
    // 0x8004406C: nop

    // 0x80044070: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80044074: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80044078: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x8004407C: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x80044080: lb          $a0, 0x0($t1)
    ctx->r4 = MEM_B(ctx->r9, 0X0);
    // 0x80044084: b           L_80044098
    // 0x80044088: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
        goto L_80044098;
    // 0x80044088: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
L_8004408C:
    // 0x8004408C: lb          $a0, 0x172($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X172);
    // 0x80044090: nop

    // 0x80044094: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
L_80044098:
    // 0x80044098: lb          $t2, -0x3270($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X3270);
    // 0x8004409C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800440A0: bne         $t2, $at, L_800440CC
    if (ctx->r10 != ctx->r1) {
        // 0x800440A4: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_800440CC;
    }
    // 0x800440A4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800440A8: lb          $t3, 0x10($a2)
    ctx->r11 = MEM_B(ctx->r6, 0X10);
    // 0x800440AC: lb          $t4, 0x12($a2)
    ctx->r12 = MEM_B(ctx->r6, 0X12);
    // 0x800440B0: lb          $t6, 0x11($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X11);
    // 0x800440B4: lb          $t7, 0x13($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X13);
    // 0x800440B8: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800440BC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800440C0: sb          $t5, 0x10($a2)
    MEM_B(0X10, ctx->r6) = ctx->r13;
    // 0x800440C4: sb          $t8, 0x11($a2)
    MEM_B(0X11, ctx->r6) = ctx->r24;
L_800440C8:
    // 0x800440C8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800440CC:
    // 0x800440CC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x800440D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800440D4: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
L_800440D8:
    // 0x800440D8: lb          $v1, 0xC($v0)
    ctx->r3 = MEM_B(ctx->r2, 0XC);
    // 0x800440DC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800440E0: slti        $at, $v1, 0x65
    ctx->r1 = SIGNED(ctx->r3) < 0X65 ? 1 : 0;
    // 0x800440E4: beq         $at, $zero, L_800440F4
    if (ctx->r1 == 0) {
        // 0x800440E8: nop
    
            goto L_800440F4;
    }
    // 0x800440E8: nop

    // 0x800440EC: bgez        $v1, L_800440F8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800440F0: nop
    
            goto L_800440F8;
    }
    // 0x800440F0: nop

L_800440F4:
    // 0x800440F4: sb          $a0, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r4;
L_800440F8:
    // 0x800440F8: lb          $v1, 0x8($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X8);
    // 0x800440FC: nop

    // 0x80044100: slti        $at, $v1, 0x65
    ctx->r1 = SIGNED(ctx->r3) < 0X65 ? 1 : 0;
    // 0x80044104: beq         $at, $zero, L_80044114
    if (ctx->r1 == 0) {
        // 0x80044108: nop
    
            goto L_80044114;
    }
    // 0x80044108: nop

    // 0x8004410C: bgez        $v1, L_80044118
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80044110: nop
    
            goto L_80044118;
    }
    // 0x80044110: nop

L_80044114:
    // 0x80044114: sb          $a0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r4;
L_80044118:
    // 0x80044118: lb          $v1, 0x14($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X14);
    // 0x8004411C: nop

    // 0x80044120: slti        $at, $v1, 0x65
    ctx->r1 = SIGNED(ctx->r3) < 0X65 ? 1 : 0;
    // 0x80044124: beq         $at, $zero, L_80044134
    if (ctx->r1 == 0) {
        // 0x80044128: nop
    
            goto L_80044134;
    }
    // 0x80044128: nop

    // 0x8004412C: bgez        $v1, L_80044138
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80044130: nop
    
            goto L_80044138;
    }
    // 0x80044130: nop

L_80044134:
    // 0x80044134: sb          $a0, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r4;
L_80044138:
    // 0x80044138: lb          $v1, 0x10($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X10);
    // 0x8004413C: nop

    // 0x80044140: slti        $at, $v1, 0x65
    ctx->r1 = SIGNED(ctx->r3) < 0X65 ? 1 : 0;
    // 0x80044144: beq         $at, $zero, L_80044154
    if (ctx->r1 == 0) {
        // 0x80044148: nop
    
            goto L_80044154;
    }
    // 0x80044148: nop

    // 0x8004414C: bgez        $v1, L_80044158
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80044150: nop
    
            goto L_80044158;
    }
    // 0x80044150: nop

L_80044154:
    // 0x80044154: sb          $a0, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r4;
L_80044158:
    // 0x80044158: bne         $a1, $a2, L_800440D8
    if (ctx->r5 != ctx->r6) {
        // 0x8004415C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800440D8;
    }
    // 0x8004415C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80044160:
    // 0x80044160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044164: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80044168: jr          $ra
    // 0x8004416C: nop

    return;
    // 0x8004416C: nop

;}
RECOMP_FUNC void gfxtask_run_fifo2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800778C8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800778CC: addiu       $v1, $v1, -0x1B2C
    ctx->r3 = ADD32(ctx->r3, -0X1B2C);
    // 0x800778D0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800778D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800778D8: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800778DC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800778E0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800778E4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800778E8: addiu       $t7, $t7, 0x5F40
    ctx->r15 = ADD32(ctx->r15, 0X5F40);
    // 0x800778EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800778F0: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x800778F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800778F8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800778FC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80077900: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x80077904: bne         $t8, $at, L_80077910
    if (ctx->r24 != ctx->r1) {
        // 0x80077908: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80077910;
    }
    // 0x80077908: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007790C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80077910:
    // 0x80077910: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80077914: subu        $t0, $a1, $a0
    ctx->r8 = SUB32(ctx->r5, ctx->r4);
    // 0x80077918: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007791C: addiu       $v0, $v0, -0x7B40
    ctx->r2 = ADD32(ctx->r2, -0X7B40);
    // 0x80077920: sra         $t1, $t0, 3
    ctx->r9 = S32(SIGNED(ctx->r8) >> 3);
    // 0x80077924: addiu       $t5, $t5, -0x7A70
    ctx->r13 = ADD32(ctx->r13, -0X7A70);
    // 0x80077928: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007792C: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x80077930: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80077934: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80077938: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8007793C: subu        $t6, $t5, $v0
    ctx->r14 = SUB32(ctx->r13, ctx->r2);
    // 0x80077940: addiu       $t7, $t7, -0x6870
    ctx->r15 = ADD32(ctx->r15, -0X6870);
    // 0x80077944: addiu       $t8, $t8, -0x5C60
    ctx->r24 = ADD32(ctx->r24, -0X5C60);
    // 0x80077948: sw          $t2, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r10;
    // 0x8007794C: sw          $t3, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r11;
    // 0x80077950: sw          $t4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r12;
    // 0x80077954: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x80077958: sw          $t8, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r24;
    // 0x8007795C: sw          $t6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r14;
    // 0x80077960: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x80077964: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80077968: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8007796C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80077970: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80077974: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80077978: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007797C: sw          $v0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r2;
    // 0x80077980: sw          $t9, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r25;
    // 0x80077984: addiu       $t0, $t0, 0x42A0
    ctx->r8 = ADD32(ctx->r8, 0X42A0);
    // 0x80077988: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x8007798C: addiu       $t2, $t2, 0x46A0
    ctx->r10 = ADD32(ctx->r10, 0X46A0);
    // 0x80077990: addiu       $t3, $t3, 0x5EA0
    ctx->r11 = ADD32(ctx->r11, 0X5EA0);
    // 0x80077994: addiu       $t4, $t4, 0x71B0
    ctx->r12 = ADD32(ctx->r12, 0X71B0);
    // 0x80077998: addiu       $t5, $zero, 0xA00
    ctx->r13 = ADD32(0, 0XA00);
    // 0x8007799C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x800779A0: addiu       $t7, $t7, 0x5ED8
    ctx->r15 = ADD32(ctx->r15, 0X5ED8);
    // 0x800779A4: addiu       $t8, $t8, -0x1B70
    ctx->r24 = ADD32(ctx->r24, -0X1B70);
    // 0x800779A8: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x800779AC: sw          $t0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r8;
    // 0x800779B0: sw          $t1, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r9;
    // 0x800779B4: sw          $t2, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r10;
    // 0x800779B8: sw          $t3, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r11;
    // 0x800779BC: sw          $t4, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r12;
    // 0x800779C0: sw          $t5, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r13;
    // 0x800779C4: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800779C8: sw          $t6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r14;
    // 0x800779CC: sw          $t7, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r15;
    // 0x800779D0: sw          $t8, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->r24;
    // 0x800779D4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800779D8: lw          $t9, 0x62D4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X62D4);
    // 0x800779DC: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x800779E0: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x800779E4: sw          $v0, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->r2;
    // 0x800779E8: sw          $v0, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->r2;
    // 0x800779EC: sw          $t9, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r25;
    // 0x800779F0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800779F4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800779F8: beq         $t0, $zero, L_80077A08
    if (ctx->r8 == 0) {
        // 0x800779FC: nop
    
            goto L_80077A08;
    }
    // 0x800779FC: nop

    // 0x80077A00: sw          $v0, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->r2;
    // 0x80077A04: sw          $v0, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r2;
L_80077A08:
    // 0x80077A08: sw          $zero, 0x68($a3)
    MEM_W(0X68, ctx->r7) = 0;
    // 0x80077A0C: jal         0x800D18A0
    // 0x80077A10: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x80077A10: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80077A14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077A18: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80077A1C: lw          $a0, 0x6100($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6100);
    // 0x80077A20: jal         0x800C8E30
    // 0x80077A24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80077A24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80077A28: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80077A2C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077A30: beq         $t1, $zero, L_80077A44
    if (ctx->r9 == 0) {
        // 0x80077A34: addiu       $a0, $a0, 0x5ED8
        ctx->r4 = ADD32(ctx->r4, 0X5ED8);
            goto L_80077A44;
    }
    // 0x80077A34: addiu       $a0, $a0, 0x5ED8
    ctx->r4 = ADD32(ctx->r4, 0X5ED8);
    // 0x80077A38: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80077A3C: jal         0x800C8BB0
    // 0x80077A40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80077A40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_80077A44:
    // 0x80077A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077A48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80077A4C: jr          $ra
    // 0x80077A50: nop

    return;
    // 0x80077A50: nop

;}
RECOMP_FUNC void music_sequence_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800022BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800022C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800022C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800022C8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800022CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800022D0: sb          $a2, 0x1B($sp)
    MEM_B(0X1B, ctx->r29) = ctx->r6;
    // 0x800022D4: jal         0x80002570
    // 0x800022D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    music_sequence_stop(rdram, ctx);
        goto after_0;
    // 0x800022D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800022DC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800022E0: lw          $t6, 0x5CF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5CF8);
    // 0x800022E4: lbu         $a2, 0x1B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X1B);
    // 0x800022E8: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x800022EC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800022F0: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800022F4: beq         $at, $zero, L_8000231C
    if (ctx->r1 == 0) {
        // 0x800022F8: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8000231C;
    }
    // 0x800022F8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800022FC: lw          $t9, -0x39D0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X39D0);
    // 0x80002300: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002304: bne         $t8, $t9, L_80002318
    if (ctx->r24 != ctx->r25) {
        // 0x80002308: nop
    
            goto L_80002318;
    }
    // 0x80002308: nop

    // 0x8000230C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002310: b           L_8000231C
    // 0x80002314: sb          $a2, -0x39A4($at)
    MEM_B(-0X39A4, ctx->r1) = ctx->r6;
        goto L_8000231C;
    // 0x80002314: sb          $a2, -0x39A4($at)
    MEM_B(-0X39A4, ctx->r1) = ctx->r6;
L_80002318:
    // 0x80002318: sb          $a2, -0x39A0($at)
    MEM_B(-0X39A0, ctx->r1) = ctx->r6;
L_8000231C:
    // 0x8000231C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002320: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002324: jr          $ra
    // 0x80002328: nop

    return;
    // 0x80002328: nop

;}
RECOMP_FUNC void func_80045C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045C48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045C4C: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x80045C50: sw          $zero, -0x2AD8($at)
    MEM_W(-0X2AD8, ctx->r1) = 0;
    // 0x80045C54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045C58: sw          $zero, -0x2AD4($at)
    MEM_W(-0X2AD4, ctx->r1) = 0;
    // 0x80045C5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045C60: sw          $zero, -0x2AD0($at)
    MEM_W(-0X2AD0, ctx->r1) = 0;
    // 0x80045C64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045C68: sw          $zero, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = 0;
    // 0x80045C6C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80045C70: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80045C74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045C78: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80045C7C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80045C80: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80045C84: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80045C88: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80045C8C: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    // 0x80045C90: sw          $a2, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r6;
    // 0x80045C94: sw          $zero, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = 0;
    // 0x80045C98: jal         0x8001BA64
    // 0x80045C9C: sw          $zero, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = 0;
    get_checkpoint_count(rdram, ctx);
        goto after_0;
    // 0x80045C9C: sw          $zero, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = 0;
    after_0:
    // 0x80045CA0: bne         $v0, $zero, L_80045CB8
    if (ctx->r2 != 0) {
        // 0x80045CA4: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80045CB8;
    }
    // 0x80045CA4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80045CA8: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    // 0x80045CAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045CB0: b           L_80046504
    // 0x80045CB4: sw          $t6, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = ctx->r14;
        goto L_80046504;
    // 0x80045CB4: sw          $t6, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = ctx->r14;
L_80045CB8:
    // 0x80045CB8: lwc1        $f4, 0xA8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x80045CBC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80045CC0: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80045CC4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80045CC8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80045CCC: sub.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d - ctx->f6.d;
    // 0x80045CD0: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80045CD4: cvt.s.d     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f20.fl = CVT_S_D(ctx->f8.d);
    // 0x80045CD8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80045CDC: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x80045CE0: lb          $s0, 0x192($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X192);
    // 0x80045CE4: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x80045CE8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80045CEC: bc1f        L_80045D00
    if (!c1cs) {
        // 0x80045CF0: addiu       $s0, $s0, -0x2
        ctx->r16 = ADD32(ctx->r16, -0X2);
            goto L_80045D00;
    }
    // 0x80045CF0: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
    // 0x80045CF4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80045CF8: nop

    // 0x80045CFC: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
L_80045D00:
    // 0x80045D00: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80045D04: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x80045D08: bc1f        L_80045D1C
    if (!c1cs) {
        // 0x80045D0C: addiu       $a3, $sp, 0xA0
        ctx->r7 = ADD32(ctx->r29, 0XA0);
            goto L_80045D1C;
    }
    // 0x80045D0C: addiu       $a3, $sp, 0xA0
    ctx->r7 = ADD32(ctx->r29, 0XA0);
    // 0x80045D10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80045D14: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80045D18: nop

L_80045D1C:
    // 0x80045D1C: bgez        $s0, L_80045D28
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80045D20: addiu       $v1, $sp, 0x90
        ctx->r3 = ADD32(ctx->r29, 0X90);
            goto L_80045D28;
    }
    // 0x80045D20: addiu       $v1, $sp, 0x90
    ctx->r3 = ADD32(ctx->r29, 0X90);
    // 0x80045D24: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_80045D28:
    // 0x80045D28: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80045D2C: bne         $at, $zero, L_80045D38
    if (ctx->r1 != 0) {
        // 0x80045D30: nop
    
            goto L_80045D38;
    }
    // 0x80045D30: nop

    // 0x80045D34: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
L_80045D38:
    // 0x80045D38: lbu         $a1, 0x1C8($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1C8);
    // 0x80045D3C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80045D40: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80045D44: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80045D48: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80045D4C: jal         0x8001BA1C
    // 0x80045D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_1;
    // 0x80045D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80045D54: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80045D58: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80045D5C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80045D60: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80045D64: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80045D68: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x80045D6C: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80045D70: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80045D74: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x80045D78: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80045D7C: nop

    // 0x80045D80: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80045D84: lbu         $t7, 0x1C9($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1C9);
    // 0x80045D88: nop

    // 0x80045D8C: bne         $t7, $zero, L_80045E6C
    if (ctx->r15 != 0) {
        // 0x80045D90: nop
    
            goto L_80045E6C;
    }
    // 0x80045D90: nop

    // 0x80045D94: lb          $t8, 0x1CA($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X1CA);
    // 0x80045D98: addu        $t2, $sp, $t0
    ctx->r10 = ADD32(ctx->r29, ctx->r8);
    // 0x80045D9C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80045DA0: lb          $t1, 0x2E($t9)
    ctx->r9 = MEM_B(ctx->r25, 0X2E);
    // 0x80045DA4: addu        $t6, $sp, $t0
    ctx->r14 = ADD32(ctx->r29, ctx->r8);
    // 0x80045DA8: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80045DAC: nop

    // 0x80045DB0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80045DB4: swc1        $f10, 0x74($t2)
    MEM_W(0X74, ctx->r10) = ctx->f10.u32l;
    // 0x80045DB8: lb          $t3, 0x1CA($s1)
    ctx->r11 = MEM_B(ctx->r17, 0X1CA);
    // 0x80045DBC: nop

    // 0x80045DC0: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80045DC4: lb          $t5, 0x32($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X32);
    // 0x80045DC8: nop

    // 0x80045DCC: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80045DD0: nop

    // 0x80045DD4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80045DD8: swc1        $f4, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->f4.u32l;
    // 0x80045DDC: lb          $t7, 0x1CA($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X1CA);
    // 0x80045DE0: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80045DE4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80045DE8: lb          $t9, 0x2E($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X2E);
    // 0x80045DEC: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80045DF0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80045DF4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80045DF8: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80045DFC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80045E00: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80045E04: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80045E08: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x80045E0C: lb          $t1, 0x1CA($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1CA);
    // 0x80045E10: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80045E14: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80045E18: lb          $t3, 0x32($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X32);
    // 0x80045E1C: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80045E20: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80045E24: nop

    // 0x80045E28: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80045E2C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80045E30: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80045E34: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x80045E38: lb          $t4, 0x1CA($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X1CA);
    // 0x80045E3C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80045E40: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80045E44: lb          $t6, 0x2E($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X2E);
    // 0x80045E48: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80045E4C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80045E50: neg.s       $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = -ctx->f8.fl;
    // 0x80045E54: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80045E58: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80045E5C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80045E60: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80045E64: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80045E68: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
L_80045E6C:
    // 0x80045E6C: bne         $s0, $s2, L_80045E78
    if (ctx->r16 != ctx->r18) {
        // 0x80045E70: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_80045E78;
    }
    // 0x80045E70: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80045E74: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80045E78:
    // 0x80045E78: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80045E7C: addiu       $t7, $sp, 0xA0
    ctx->r15 = ADD32(ctx->r29, 0XA0);
    // 0x80045E80: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x80045E84: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80045E88: bne         $at, $zero, L_80045D38
    if (ctx->r1 != 0) {
        // 0x80045E8C: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80045D38;
    }
    // 0x80045E8C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80045E90: lbu         $v0, 0x1C9($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1C9);
    // 0x80045E94: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x80045E98: bne         $v0, $zero, L_80045F24
    if (ctx->r2 != 0) {
        // 0x80045E9C: nop
    
            goto L_80045F24;
    }
    // 0x80045E9C: nop

    // 0x80045EA0: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80045EA4: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80045EA8: nop

    // 0x80045EAC: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80045EB0: mul.s       $f10, $f18, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80045EB4: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80045EB8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80045EBC: nop

    // 0x80045EC0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80045EC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80045EC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80045ECC: nop

    // 0x80045ED0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80045ED4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80045ED8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80045EDC: sh          $t9, 0x1BA($s1)
    MEM_H(0X1BA, ctx->r17) = ctx->r25;
    // 0x80045EE0: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80045EE4: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80045EE8: nop

    // 0x80045EEC: sub.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80045EF0: mul.s       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80045EF4: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80045EF8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80045EFC: nop

    // 0x80045F00: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80045F04: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80045F08: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80045F0C: nop

    // 0x80045F10: cvt.w.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80045F14: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80045F18: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80045F1C: sh          $t2, 0x1BC($s1)
    MEM_H(0X1BC, ctx->r17) = ctx->r10;
    // 0x80045F20: nop

L_80045F24:
    // 0x80045F24: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80045F28: jal         0x8002277C
    // 0x80045F2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_derivative(rdram, ctx);
        goto after_2;
    // 0x80045F2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80045F30: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80045F34: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80045F38: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x80045F3C: jal         0x8002277C
    // 0x80045F40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_derivative(rdram, ctx);
        goto after_3;
    // 0x80045F40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80045F44: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80045F48: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80045F4C: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x80045F50: jal         0x8002277C
    // 0x80045F54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_derivative(rdram, ctx);
        goto after_4;
    // 0x80045F54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80045F58: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80045F5C: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80045F60: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80045F64: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80045F68: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80045F6C: nop

    // 0x80045F70: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80045F74: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80045F78: jal         0x800C9AD0
    // 0x80045F7C: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x80045F7C: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_5:
    // 0x80045F80: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80045F84: nop

    // 0x80045F88: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x80045F8C: nop

    // 0x80045F90: bc1t        L_80045FC8
    if (c1cs) {
        // 0x80045F94: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80045FC8;
    }
    // 0x80045F94: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80045F98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80045F9C: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80045FA0: div.s       $f20, $f8, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80045FA4: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80045FA8: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80045FAC: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80045FB0: nop

    // 0x80045FB4: mul.s       $f18, $f6, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80045FB8: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80045FBC: mul.s       $f14, $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80045FC0: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x80045FC4: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
L_80045FC8:
    // 0x80045FC8: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80045FCC: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80045FD0: jal         0x80070750
    // 0x80045FD4: nop

    arctan2_f(rdram, ctx);
        goto after_6;
    // 0x80045FD4: nop

    after_6:
    // 0x80045FD8: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80045FDC: addu        $s0, $v0, $at
    ctx->r16 = ADD32(ctx->r2, ctx->r1);
    // 0x80045FE0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80045FE4: andi        $t3, $s0, 0xFFFF
    ctx->r11 = ctx->r16 & 0XFFFF;
    // 0x80045FE8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80045FEC: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80045FF0: jal         0x80070750
    // 0x80045FF4: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    arctan2_f(rdram, ctx);
        goto after_7;
    // 0x80045FF4: or          $s0, $t3, $zero
    ctx->r16 = ctx->r11 | 0;
    after_7:
    // 0x80045FF8: lh          $t4, 0x1BE($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X1BE);
    // 0x80045FFC: lh          $t5, 0x1C0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X1C0);
    // 0x80046000: sh          $t4, 0x1C2($s1)
    MEM_H(0X1C2, ctx->r17) = ctx->r12;
    // 0x80046004: lh          $t6, 0x1C2($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X1C2);
    // 0x80046008: ori         $t0, $zero, 0x8001
    ctx->r8 = 0 | 0X8001;
    // 0x8004600C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80046010: subu        $a0, $s0, $t7
    ctx->r4 = SUB32(ctx->r16, ctx->r15);
    // 0x80046014: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80046018: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004601C: sh          $s0, 0x1BE($s1)
    MEM_H(0X1BE, ctx->r17) = ctx->r16;
    // 0x80046020: sh          $a1, 0x1C0($s1)
    MEM_H(0X1C0, ctx->r17) = ctx->r5;
    // 0x80046024: bne         $at, $zero, L_80046038
    if (ctx->r1 != 0) {
        // 0x80046028: sh          $t5, 0x1C4($s1)
        MEM_H(0X1C4, ctx->r17) = ctx->r13;
            goto L_80046038;
    }
    // 0x80046028: sh          $t5, 0x1C4($s1)
    MEM_H(0X1C4, ctx->r17) = ctx->r13;
    // 0x8004602C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80046030: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80046034: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_80046038:
    // 0x80046038: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x8004603C: beq         $at, $zero, L_80046048
    if (ctx->r1 == 0) {
        // 0x80046040: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80046048;
    }
    // 0x80046040: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80046044: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_80046048:
    // 0x80046048: lh          $t8, 0x1C4($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X1C4);
    // 0x8004604C: sra         $t1, $a0, 3
    ctx->r9 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80046050: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80046054: subu        $v1, $a1, $t9
    ctx->r3 = SUB32(ctx->r5, ctx->r25);
    // 0x80046058: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004605C: bne         $at, $zero, L_80046070
    if (ctx->r1 != 0) {
        // 0x80046060: negu        $t2, $t1
        ctx->r10 = SUB32(0, ctx->r9);
            goto L_80046070;
    }
    // 0x80046060: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x80046064: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80046068: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004606C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80046070:
    // 0x80046070: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80046074: beq         $at, $zero, L_80046080
    if (ctx->r1 == 0) {
        // 0x80046078: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80046080;
    }
    // 0x80046078: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004607C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80046080:
    // 0x80046080: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046084: sw          $t2, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = ctx->r10;
    // 0x80046088: sra         $t3, $v1, 3
    ctx->r11 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8004608C: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x80046090: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046094: sw          $t4, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = ctx->r12;
    // 0x80046098: lh          $t5, 0x1A0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X1A0);
    // 0x8004609C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800460A0: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800460A4: subu        $a0, $s0, $t6
    ctx->r4 = SUB32(ctx->r16, ctx->r14);
    // 0x800460A8: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800460AC: bne         $at, $zero, L_800460BC
    if (ctx->r1 != 0) {
        // 0x800460B0: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800460BC;
    }
    // 0x800460B0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800460B4: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800460B8: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_800460BC:
    // 0x800460BC: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x800460C0: beq         $at, $zero, L_800460CC
    if (ctx->r1 == 0) {
        // 0x800460C4: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800460CC;
    }
    // 0x800460C4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800460C8: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_800460CC:
    // 0x800460CC: slti        $at, $a0, 0x3001
    ctx->r1 = SIGNED(ctx->r4) < 0X3001 ? 1 : 0;
    // 0x800460D0: beq         $at, $zero, L_800460DC
    if (ctx->r1 == 0) {
        // 0x800460D4: slti        $at, $a0, -0x3000
        ctx->r1 = SIGNED(ctx->r4) < -0X3000 ? 1 : 0;
            goto L_800460DC;
    }
    // 0x800460D4: slti        $at, $a0, -0x3000
    ctx->r1 = SIGNED(ctx->r4) < -0X3000 ? 1 : 0;
    // 0x800460D8: beq         $at, $zero, L_800460E4
    if (ctx->r1 == 0) {
        // 0x800460DC: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800460E4;
    }
L_800460DC:
    // 0x800460DC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800460E0: sw          $t7, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r15;
L_800460E4:
    // 0x800460E4: lwc1        $f4, 0xA8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x800460E8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800460EC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800460F0: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x800460F4: sub.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d - ctx->f10.d;
    // 0x800460F8: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x800460FC: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x80046100: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80046104: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x80046108: lb          $s0, 0x192($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X192);
    // 0x8004610C: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    // 0x80046110: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80046114: bc1f        L_80046128
    if (!c1cs) {
        // 0x80046118: addiu       $s0, $s0, -0x2
        ctx->r16 = ADD32(ctx->r16, -0X2);
            goto L_80046128;
    }
    // 0x80046118: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
    // 0x8004611C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80046120: nop

    // 0x80046124: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
L_80046128:
    // 0x80046128: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8004612C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80046130: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x80046134: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80046138: nop

    // 0x8004613C: bc1f        L_8004614C
    if (!c1cs) {
        // 0x80046140: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8004614C;
    }
    // 0x80046140: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80046144: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80046148: nop

L_8004614C:
    // 0x8004614C: beq         $t8, $zero, L_8004615C
    if (ctx->r24 == 0) {
        // 0x80046150: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8004615C;
    }
    // 0x80046150: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80046154: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80046158: nop

L_8004615C:
    // 0x8004615C: lbu         $t9, 0x1C9($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X1C9);
    // 0x80046160: nop

    // 0x80046164: beq         $t9, $zero, L_80046244
    if (ctx->r25 == 0) {
        // 0x80046168: nop
    
            goto L_80046244;
    }
    // 0x80046168: nop

    // 0x8004616C: bgez        $s0, L_80046178
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80046170: addiu       $a2, $sp, 0xB0
        ctx->r6 = ADD32(ctx->r29, 0XB0);
            goto L_80046178;
    }
    // 0x80046170: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x80046174: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
L_80046178:
    // 0x80046178: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8004617C: bne         $at, $zero, L_80046188
    if (ctx->r1 != 0) {
        // 0x80046180: addiu       $a3, $sp, 0xA0
        ctx->r7 = ADD32(ctx->r29, 0XA0);
            goto L_80046188;
    }
    // 0x80046180: addiu       $a3, $sp, 0xA0
    ctx->r7 = ADD32(ctx->r29, 0XA0);
    // 0x80046184: subu        $s0, $s0, $s2
    ctx->r16 = SUB32(ctx->r16, ctx->r18);
L_80046188:
    // 0x80046188: addiu       $v1, $sp, 0x90
    ctx->r3 = ADD32(ctx->r29, 0X90);
L_8004618C:
    // 0x8004618C: lbu         $a1, 0x1C8($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1C8);
    // 0x80046190: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80046194: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80046198: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x8004619C: jal         0x8001BA1C
    // 0x800461A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_8;
    // 0x800461A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800461A4: lh          $t1, 0x1BA($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X1BA);
    // 0x800461A8: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800461AC: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800461B0: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x800461B4: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800461B8: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800461BC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800461C0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800461C4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800461C8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800461CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800461D0: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800461D4: addiu       $t4, $sp, 0xA0
    ctx->r12 = ADD32(ctx->r29, 0XA0);
    // 0x800461D8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800461DC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800461E0: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800461E4: swc1        $f18, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f18.u32l;
    // 0x800461E8: lh          $t2, 0x1BC($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X1BC);
    // 0x800461EC: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800461F0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800461F4: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800461F8: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800461FC: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80046200: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80046204: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x80046208: lh          $t3, 0x1BA($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X1BA);
    // 0x8004620C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80046210: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80046214: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80046218: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x8004621C: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80046220: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80046224: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80046228: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004622C: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80046230: bne         $s0, $s2, L_8004623C
    if (ctx->r16 != ctx->r18) {
        // 0x80046234: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_8004623C;
    }
    // 0x80046234: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x80046238: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8004623C:
    // 0x8004623C: bne         $v1, $t4, L_8004618C
    if (ctx->r3 != ctx->r12) {
        // 0x80046240: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_8004618C;
    }
    // 0x80046240: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_80046244:
    // 0x80046244: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80046248: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x8004624C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80046250: jal         0x8002263C
    // 0x80046254: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    cubic_spline_interpolation(rdram, ctx);
        goto after_9;
    // 0x80046254: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    after_9:
    // 0x80046258: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8004625C: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x80046260: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x80046264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80046268: jal         0x8002263C
    // 0x8004626C: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    cubic_spline_interpolation(rdram, ctx);
        goto after_10;
    // 0x8004626C: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_10:
    // 0x80046270: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80046274: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x80046278: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x8004627C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80046280: jal         0x8002263C
    // 0x80046284: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    cubic_spline_interpolation(rdram, ctx);
        goto after_11;
    // 0x80046284: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_11:
    // 0x80046288: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8004628C: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80046290: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80046294: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80046298: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x8004629C: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800462A0: nop

    // 0x800462A4: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800462A8: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800462AC: jal         0x800C9AD0
    // 0x800462B0: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_12;
    // 0x800462B0: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    after_12:
    // 0x800462B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800462B8: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800462BC: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800462C0: nop

    // 0x800462C4: bc1t        L_80046300
    if (c1cs) {
        // 0x800462C8: lw          $v0, 0xE8($sp)
        ctx->r2 = MEM_W(ctx->r29, 0XE8);
            goto L_80046300;
    }
    // 0x800462C8: lw          $v0, 0xE8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE8);
    // 0x800462CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800462D0: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800462D4: div.s       $f20, $f8, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800462D8: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800462DC: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800462E0: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800462E4: nop

    // 0x800462E8: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800462EC: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x800462F0: mul.s       $f14, $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x800462F4: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x800462F8: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    // 0x800462FC: lw          $v0, 0xE8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE8);
L_80046300:
    // 0x80046300: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80046304: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80046308: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8004630C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80046310: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80046314: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80046318: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8004631C: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    // 0x80046320: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80046324: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80046328: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8004632C: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80046330: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80046334: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80046338: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8004633C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80046340: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80046344: jal         0x80070750
    // 0x80046348: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    arctan2_f(rdram, ctx);
        goto after_13;
    // 0x80046348: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    after_13:
    // 0x8004634C: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80046350: addu        $s0, $v0, $at
    ctx->r16 = ADD32(ctx->r2, ctx->r1);
    // 0x80046354: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80046358: andi        $t5, $s0, 0xFFFF
    ctx->r13 = ctx->r16 & 0XFFFF;
    // 0x8004635C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80046360: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80046364: jal         0x80070750
    // 0x80046368: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    arctan2_f(rdram, ctx);
        goto after_14;
    // 0x80046368: or          $s0, $t5, $zero
    ctx->r16 = ctx->r13 | 0;
    after_14:
    // 0x8004636C: lh          $a1, 0x1A0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X1A0);
    // 0x80046370: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80046374: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80046378: subu        $a0, $s0, $t6
    ctx->r4 = SUB32(ctx->r16, ctx->r14);
    // 0x8004637C: slt         $at, $a0, $at
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80046380: bne         $at, $zero, L_80046394
    if (ctx->r1 != 0) {
        // 0x80046384: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80046394;
    }
    // 0x80046384: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80046388: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004638C: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80046390: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_80046394:
    // 0x80046394: slti        $at, $a0, -0x8000
    ctx->r1 = SIGNED(ctx->r4) < -0X8000 ? 1 : 0;
    // 0x80046398: beq         $at, $zero, L_800463A4
    if (ctx->r1 == 0) {
        // 0x8004639C: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800463A4;
    }
    // 0x8004639C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800463A0: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_800463A4:
    // 0x800463A4: lw          $t8, 0xE8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE8);
    // 0x800463A8: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x800463AC: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x800463B0: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800463B4: andi        $t1, $t9, 0xFFFF
    ctx->r9 = ctx->r25 & 0XFFFF;
    // 0x800463B8: subu        $v1, $t7, $t1
    ctx->r3 = SUB32(ctx->r15, ctx->r9);
    // 0x800463BC: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800463C0: bne         $at, $zero, L_800463D4
    if (ctx->r1 != 0) {
        // 0x800463C4: negu        $a0, $a0
        ctx->r4 = SUB32(0, ctx->r4);
            goto L_800463D4;
    }
    // 0x800463C4: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x800463C8: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800463CC: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800463D0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800463D4:
    // 0x800463D4: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800463D8: beq         $at, $zero, L_800463E8
    if (ctx->r1 == 0) {
        // 0x800463DC: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_800463E8;
    }
    // 0x800463DC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800463E0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800463E4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800463E8:
    // 0x800463E8: lb          $a2, 0x1D6($s1)
    ctx->r6 = MEM_B(ctx->r17, 0X1D6);
    // 0x800463EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800463F0: bne         $a2, $at, L_800463FC
    if (ctx->r6 != ctx->r1) {
        // 0x800463F4: negu        $v1, $v1
        ctx->r3 = SUB32(0, ctx->r3);
            goto L_800463FC;
    }
    // 0x800463F4: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x800463F8: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800463FC:
    // 0x800463FC: bne         $a3, $a2, L_8004641C
    if (ctx->r7 != ctx->r6) {
        // 0x80046400: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8004641C;
    }
    // 0x80046400: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046404: lb          $t2, 0x1D4($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X1D4);
    // 0x80046408: sra         $t3, $a0, 1
    ctx->r11 = S32(SIGNED(ctx->r4) >> 1);
    // 0x8004640C: bne         $t2, $zero, L_8004641C
    if (ctx->r10 != 0) {
        // 0x80046410: subu        $t4, $a1, $t3
        ctx->r12 = SUB32(ctx->r5, ctx->r11);
            goto L_8004641C;
    }
    // 0x80046410: subu        $t4, $a1, $t3
    ctx->r12 = SUB32(ctx->r5, ctx->r11);
    // 0x80046414: lb          $a2, 0x1D6($s1)
    ctx->r6 = MEM_B(ctx->r17, 0X1D6);
    // 0x80046418: sh          $t4, 0x1A0($s1)
    MEM_H(0X1A0, ctx->r17) = ctx->r12;
L_8004641C:
    // 0x8004641C: beq         $a2, $a3, L_80046484
    if (ctx->r6 == ctx->r7) {
        // 0x80046420: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_80046484;
    }
    // 0x80046420: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80046424: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80046428: beq         $a2, $at, L_80046478
    if (ctx->r6 == ctx->r1) {
        // 0x8004642C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80046478;
    }
    // 0x8004642C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80046430: beq         $a2, $at, L_800464A0
    if (ctx->r6 == ctx->r1) {
        // 0x80046434: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800464A0;
    }
    // 0x80046434: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80046438: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8004643C: beq         $a2, $at, L_800464C4
    if (ctx->r6 == ctx->r1) {
        // 0x80046440: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800464C4;
    }
    // 0x80046440: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80046444: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80046448: lw          $t5, -0x2ACC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2ACC);
    // 0x8004644C: srav        $t6, $a0, $v0
    ctx->r14 = S32(SIGNED(ctx->r4) >> (ctx->r2 & 31));
    // 0x80046450: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80046454: lw          $t9, -0x2AC8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2AC8);
    // 0x80046458: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004645C: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x80046460: sw          $t8, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = ctx->r24;
    // 0x80046464: srav        $t7, $v1, $v0
    ctx->r15 = S32(SIGNED(ctx->r3) >> (ctx->r2 & 31));
    // 0x80046468: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004646C: addu        $t1, $t9, $t7
    ctx->r9 = ADD32(ctx->r25, ctx->r15);
    // 0x80046470: b           L_800464F4
    // 0x80046474: sw          $t1, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = ctx->r9;
        goto L_800464F4;
    // 0x80046474: sw          $t1, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = ctx->r9;
L_80046478:
    // 0x80046478: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004647C: b           L_800464F4
    // 0x80046480: sw          $zero, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = 0;
        goto L_800464F4;
    // 0x80046480: sw          $zero, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = 0;
L_80046484:
    // 0x80046484: lw          $t2, -0x2ACC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2ACC);
    // 0x80046488: sw          $zero, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = 0;
    // 0x8004648C: srav        $t3, $a0, $v0
    ctx->r11 = S32(SIGNED(ctx->r4) >> (ctx->r2 & 31));
    // 0x80046490: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80046494: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80046498: b           L_800464F4
    // 0x8004649C: sw          $t4, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = ctx->r12;
        goto L_800464F4;
    // 0x8004649C: sw          $t4, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = ctx->r12;
L_800464A0:
    // 0x800464A0: lw          $t5, -0x2ACC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2ACC);
    // 0x800464A4: addiu       $t6, $v0, 0x1F
    ctx->r14 = ADD32(ctx->r2, 0X1F);
    // 0x800464A8: srav        $t8, $a0, $t6
    ctx->r24 = S32(SIGNED(ctx->r4) >> (ctx->r14 & 31));
    // 0x800464AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800464B0: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800464B4: sw          $t9, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = ctx->r25;
    // 0x800464B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800464BC: b           L_800464F4
    // 0x800464C0: sw          $zero, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = 0;
        goto L_800464F4;
    // 0x800464C0: sw          $zero, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = 0;
L_800464C4:
    // 0x800464C4: lw          $t7, -0x2ACC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2ACC);
    // 0x800464C8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800464CC: srav        $t1, $a0, $v0
    ctx->r9 = S32(SIGNED(ctx->r4) >> (ctx->r2 & 31));
    // 0x800464D0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800464D4: lw          $t3, -0x2AC8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AC8);
    // 0x800464D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800464DC: addu        $t2, $t7, $t1
    ctx->r10 = ADD32(ctx->r15, ctx->r9);
    // 0x800464E0: sw          $t2, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = ctx->r10;
    // 0x800464E4: srav        $t4, $v1, $v0
    ctx->r12 = S32(SIGNED(ctx->r3) >> (ctx->r2 & 31));
    // 0x800464E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800464EC: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x800464F0: sw          $t6, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = ctx->r14;
L_800464F4:
    // 0x800464F4: lw          $a0, 0xE8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE8);
    // 0x800464F8: lw          $a2, 0xF0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF0);
    // 0x800464FC: jal         0x80042D20
    // 0x80046500: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80042D20(rdram, ctx);
        goto after_15;
    // 0x80046500: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_15:
L_80046504:
    // 0x80046504: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80046508: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8004650C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80046510: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80046514: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80046518: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8004651C: jr          $ra
    // 0x80046520: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x80046520: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void obj_loop_overridepos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037D60: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80037D64: jr          $ra
    // 0x80037D68: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80037D68: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void waves_visibility(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8C04: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800B8C08: lw          $t2, -0x5F30($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5F30);
    // 0x800B8C0C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800B8C10: lw          $t0, -0x5F58($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5F58);
    // 0x800B8C14: subu        $t6, $a0, $t2
    ctx->r14 = SUB32(ctx->r4, ctx->r10);
    // 0x800B8C18: div         $zero, $t6, $t0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r8)));
    // 0x800B8C1C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800B8C20: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800B8C24: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800B8C28: lw          $t4, -0x5F2C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5F2C);
    // 0x800B8C2C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800B8C30: lw          $t1, -0x5F54($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5F54);
    // 0x800B8C34: subu        $t7, $a2, $t4
    ctx->r15 = SUB32(ctx->r6, ctx->r12);
    // 0x800B8C38: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800B8C3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B8C40: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B8C44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B8C48: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800B8C4C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800B8C50: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B8C54: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800B8C58: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B8C5C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800B8C60: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800B8C64: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800B8C68: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800B8C6C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800B8C70: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B8C74: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B8C78: bne         $t0, $zero, L_800B8C84
    if (ctx->r8 != 0) {
        // 0x800B8C7C: nop
    
            goto L_800B8C84;
    }
    // 0x800B8C7C: nop

    // 0x800B8C80: break       7
    do_break(2148240512);
L_800B8C84:
    // 0x800B8C84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B8C88: bne         $t0, $at, L_800B8C9C
    if (ctx->r8 != ctx->r1) {
        // 0x800B8C8C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B8C9C;
    }
    // 0x800B8C8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B8C90: bne         $t6, $at, L_800B8C9C
    if (ctx->r14 != ctx->r1) {
        // 0x800B8C94: nop
    
            goto L_800B8C9C;
    }
    // 0x800B8C94: nop

    // 0x800B8C98: break       6
    do_break(2148240536);
L_800B8C9C:
    // 0x800B8C9C: mflo        $a1
    ctx->r5 = lo;
    // 0x800B8CA0: addiu       $v1, $v1, -0x5A00
    ctx->r3 = ADD32(ctx->r3, -0X5A00);
    // 0x800B8CA4: addiu       $a0, $a0, -0x58E0
    ctx->r4 = ADD32(ctx->r4, -0X58E0);
    // 0x800B8CA8: div         $zero, $t7, $t1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r9)));
    // 0x800B8CAC: bne         $t1, $zero, L_800B8CB8
    if (ctx->r9 != 0) {
        // 0x800B8CB0: nop
    
            goto L_800B8CB8;
    }
    // 0x800B8CB0: nop

    // 0x800B8CB4: break       7
    do_break(2148240564);
L_800B8CB8:
    // 0x800B8CB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B8CBC: bne         $t1, $at, L_800B8CD0
    if (ctx->r9 != ctx->r1) {
        // 0x800B8CC0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B8CD0;
    }
    // 0x800B8CC0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B8CC4: bne         $t7, $at, L_800B8CD0
    if (ctx->r15 != ctx->r1) {
        // 0x800B8CC8: nop
    
            goto L_800B8CD0;
    }
    // 0x800B8CC8: nop

    // 0x800B8CCC: break       6
    do_break(2148240588);
L_800B8CD0:
    // 0x800B8CD0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8CD4: sh          $t8, -0x5A18($at)
    MEM_H(-0X5A18, ctx->r1) = ctx->r24;
    // 0x800B8CD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B8CDC: sh          $t9, -0x5A0C($at)
    MEM_H(-0X5A0C, ctx->r1) = ctx->r25;
    // 0x800B8CE0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B8CE4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800B8CE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800B8CEC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B8CF0: mflo        $s7
    ctx->r23 = lo;
    // 0x800B8CF4: nop

    // 0x800B8CF8: nop

L_800B8CFC:
    // 0x800B8CFC: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x800B8D00: sh          $v0, -0x30($v1)
    MEM_H(-0X30, ctx->r3) = ctx->r2;
    // 0x800B8D04: sh          $v0, -0x24($v1)
    MEM_H(-0X24, ctx->r3) = ctx->r2;
    // 0x800B8D08: sh          $v0, -0x18($v1)
    MEM_H(-0X18, ctx->r3) = ctx->r2;
    // 0x800B8D0C: bne         $v1, $a0, L_800B8CFC
    if (ctx->r3 != ctx->r4) {
        // 0x800B8D10: sh          $v0, -0xC($v1)
        MEM_H(-0XC, ctx->r3) = ctx->r2;
            goto L_800B8CFC;
    }
    // 0x800B8D10: sh          $v0, -0xC($v1)
    MEM_H(-0XC, ctx->r3) = ctx->r2;
    // 0x800B8D14: addiu       $t3, $t3, -0x6038
    ctx->r11 = ADD32(ctx->r11, -0X6038);
    // 0x800B8D18: lw          $t6, 0x28($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X28);
    // 0x800B8D1C: nop

    // 0x800B8D20: beq         $t6, $zero, L_800B9044
    if (ctx->r14 == 0) {
        // 0x800B8D24: nop
    
            goto L_800B9044;
    }
    // 0x800B8D24: nop

    // 0x800B8D28: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8D2C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800B8D30: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B8D34: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800B8D38: addiu       $s2, $s2, 0x317C
    ctx->r18 = ADD32(ctx->r18, 0X317C);
    // 0x800B8D3C: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x800B8D40: addiu       $ra, $zero, 0x1C
    ctx->r31 = ADD32(0, 0X1C);
    // 0x800B8D44: mflo        $t7
    ctx->r15 = lo;
    // 0x800B8D48: subu        $t8, $s0, $t7
    ctx->r24 = SUB32(ctx->r16, ctx->r15);
    // 0x800B8D4C: subu        $s0, $t8, $t2
    ctx->r16 = SUB32(ctx->r24, ctx->r10);
    // 0x800B8D50: multu       $s7, $t1
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8D54: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x800B8D58: slt         $at, $t7, $s0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800B8D5C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B8D60: sra         $t8, $t1, 1
    ctx->r24 = S32(SIGNED(ctx->r9) >> 1);
    // 0x800B8D64: addiu       $s0, $s0, -0x5A18
    ctx->r16 = ADD32(ctx->r16, -0X5A18);
    // 0x800B8D68: mflo        $t9
    ctx->r25 = lo;
    // 0x800B8D6C: subu        $t6, $a2, $t9
    ctx->r14 = SUB32(ctx->r6, ctx->r25);
    // 0x800B8D70: beq         $at, $zero, L_800B8D80
    if (ctx->r1 == 0) {
        // 0x800B8D74: subu        $a2, $t6, $t4
        ctx->r6 = SUB32(ctx->r14, ctx->r12);
            goto L_800B8D80;
    }
    // 0x800B8D74: subu        $a2, $t6, $t4
    ctx->r6 = SUB32(ctx->r14, ctx->r12);
    // 0x800B8D78: b           L_800B8D84
    // 0x800B8D7C: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
        goto L_800B8D84;
    // 0x800B8D7C: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
L_800B8D80:
    // 0x800B8D80: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_800B8D84:
    // 0x800B8D84: slt         $at, $t8, $a2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800B8D88: beq         $at, $zero, L_800B8D98
    if (ctx->r1 == 0) {
        // 0x800B8D8C: nop
    
            goto L_800B8D98;
    }
    // 0x800B8D8C: nop

    // 0x800B8D90: b           L_800B8D98
    // 0x800B8D94: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
        goto L_800B8D98;
    // 0x800B8D94: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
L_800B8D98:
    // 0x800B8D98: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    // 0x800B8D9C: nop

    // 0x800B8DA0: sra         $v0, $a0, 1
    ctx->r2 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800B8DA4: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800B8DA8: subu        $v1, $v1, $t9
    ctx->r3 = SUB32(ctx->r3, ctx->r25);
    // 0x800B8DAC: bgez        $v1, L_800B8DC0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800B8DB0: sll         $t6, $v0, 4
        ctx->r14 = S32(ctx->r2 << 4);
            goto L_800B8DC0;
    }
    // 0x800B8DB0: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
L_800B8DB4:
    // 0x800B8DB4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800B8DB8: bltz        $v1, L_800B8DB4
    if (SIGNED(ctx->r3) < 0) {
        // 0x800B8DBC: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_800B8DB4;
    }
    // 0x800B8DBC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_800B8DC0:
    // 0x800B8DC0: subu        $s4, $s4, $t6
    ctx->r20 = SUB32(ctx->r20, ctx->r14);
    // 0x800B8DC4: bgez        $s4, L_800B8DD8
    if (SIGNED(ctx->r20) >= 0) {
        // 0x800B8DC8: nop
    
            goto L_800B8DD8;
    }
    // 0x800B8DC8: nop

L_800B8DCC:
    // 0x800B8DCC: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    // 0x800B8DD0: bltz        $s4, L_800B8DCC
    if (SIGNED(ctx->r20) < 0) {
        // 0x800B8DD4: addiu       $s7, $s7, -0x1
        ctx->r23 = ADD32(ctx->r23, -0X1);
            goto L_800B8DCC;
    }
    // 0x800B8DD4: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
L_800B8DD8:
    // 0x800B8DD8: blez        $a0, L_800B91E8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B8DDC: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_800B91E8;
    }
    // 0x800B8DDC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800B8DE0: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800B8DE4: addiu       $fp, $fp, -0x5F28
    ctx->r30 = ADD32(ctx->r30, -0X5F28);
    // 0x800B8DE8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
L_800B8DEC:
    // 0x800B8DEC: bltz        $s7, L_800B9014
    if (SIGNED(ctx->r23) < 0) {
        // 0x800B8DF0: sw          $v1, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r3;
            goto L_800B9014;
    }
    // 0x800B8DF0: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x800B8DF4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B8DF8: lw          $t7, -0x5F24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5F24);
    // 0x800B8DFC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x800B8E00: slt         $at, $s7, $t7
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B8E04: beq         $at, $zero, L_800B9014
    if (ctx->r1 == 0) {
        // 0x800B8E08: nop
    
            goto L_800B9014;
    }
    // 0x800B8E08: nop

    // 0x800B8E0C: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800B8E10: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800B8E14: multu       $s7, $t8
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8E18: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
    // 0x800B8E1C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B8E20: mflo        $t9
    ctx->r25 = lo;
    // 0x800B8E24: addu        $t2, $t9, $s3
    ctx->r10 = ADD32(ctx->r25, ctx->r19);
    // 0x800B8E28: blez        $a0, L_800B9014
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B8E2C: nop
    
            goto L_800B9014;
    }
    // 0x800B8E2C: nop

L_800B8E30:
    // 0x800B8E30: bltz        $s3, L_800B8FE8
    if (SIGNED(ctx->r19) < 0) {
        // 0x800B8E34: nop
    
            goto L_800B8FE8;
    }
    // 0x800B8E34: nop

    // 0x800B8E38: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x800B8E3C: sll         $t7, $s7, 2
    ctx->r15 = S32(ctx->r23 << 2);
    // 0x800B8E40: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B8E44: beq         $at, $zero, L_800B8FE8
    if (ctx->r1 == 0) {
        // 0x800B8E48: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800B8FE8;
    }
    // 0x800B8E48: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800B8E4C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800B8E50: lw          $t8, -0x5F18($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5F18);
    // 0x800B8E54: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B8E58: sllv        $t6, $t9, $s3
    ctx->r14 = S32(ctx->r25 << (ctx->r19 & 31));
    // 0x800B8E5C: and         $t7, $t8, $t6
    ctx->r15 = ctx->r24 & ctx->r14;
    // 0x800B8E60: beq         $t7, $zero, L_800B8FE8
    if (ctx->r15 == 0) {
        // 0x800B8E64: nop
    
            goto L_800B8FE8;
    }
    // 0x800B8E64: nop

    // 0x800B8E68: multu       $s6, $a0
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8E6C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B8E70: lw          $t9, 0x30D4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30D4);
    // 0x800B8E74: sll         $t8, $t2, 2
    ctx->r24 = S32(ctx->r10 << 2);
    // 0x800B8E78: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B8E7C: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
    // 0x800B8E80: lw          $t6, 0x30E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30E0);
    // 0x800B8E84: addu        $t4, $t5, $s4
    ctx->r12 = ADD32(ctx->r13, ctx->r20);
    // 0x800B8E88: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800B8E8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B8E90: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B8E94: mflo        $t7
    ctx->r15 = lo;
    // 0x800B8E98: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800B8E9C: sll         $t7, $s5, 1
    ctx->r15 = S32(ctx->r21 << 1);
    // 0x800B8EA0: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800B8EA4: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x800B8EA8: lh          $t9, 0x0($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X0);
    // 0x800B8EAC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800B8EB0: sllv        $t8, $t9, $t4
    ctx->r24 = S32(ctx->r25 << (ctx->r12 & 31));
    // 0x800B8EB4: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800B8EB8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800B8EBC: lw          $t0, -0x5F20($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5F20);
    // 0x800B8EC0: nop

    // 0x800B8EC4: blez        $t0, L_800B8FE8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B8EC8: nop
    
            goto L_800B8FE8;
    }
    // 0x800B8EC8: nop

    // 0x800B8ECC: lw          $t1, 0x30D8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30D8);
    // 0x800B8ED0: nop

L_800B8ED4:
    // 0x800B8ED4: multu       $v0, $ra
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8ED8: mflo        $t9
    ctx->r25 = lo;
    // 0x800B8EDC: addu        $a2, $t1, $t9
    ctx->r6 = ADD32(ctx->r9, ctx->r25);
    // 0x800B8EE0: lw          $t7, 0xC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XC);
    // 0x800B8EE4: nop

    // 0x800B8EE8: bne         $t2, $t7, L_800B8FD8
    if (ctx->r10 != ctx->r15) {
        // 0x800B8EEC: nop
    
            goto L_800B8FD8;
    }
    // 0x800B8EEC: nop

    // 0x800B8EF0: multu       $a3, $s1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8EF4: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800B8EF8: sra         $t6, $t4, 3
    ctx->r14 = S32(SIGNED(ctx->r12) >> 3);
    // 0x800B8EFC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800B8F00: mflo        $t8
    ctx->r24 = lo;
    // 0x800B8F04: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
    // 0x800B8F08: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800B8F0C: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8F10: sh          $t6, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r14;
    // 0x800B8F14: mflo        $t7
    ctx->r15 = lo;
    // 0x800B8F18: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x800B8F1C: lh          $t8, 0x12($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X12);
    // 0x800B8F20: beq         $t5, $zero, L_800B8F70
    if (ctx->r13 == 0) {
        // 0x800B8F24: sh          $t8, 0x4($v1)
        MEM_H(0X4, ctx->r3) = ctx->r24;
            goto L_800B8F70;
    }
    // 0x800B8F24: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x800B8F28: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x800B8F2C: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x800B8F30: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x800B8F34: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x800B8F38: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x800B8F3C: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800B8F40: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x800B8F44: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800B8F48: nop

    // 0x800B8F4C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B8F50: bne         $at, $zero, L_800B8F70
    if (ctx->r1 != 0) {
        // 0x800B8F54: subu        $t6, $v0, $a0
        ctx->r14 = SUB32(ctx->r2, ctx->r4);
            goto L_800B8F70;
    }
    // 0x800B8F54: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
L_800B8F58:
    // 0x800B8F58: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x800B8F5C: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800B8F60: nop

    // 0x800B8F64: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B8F68: beq         $at, $zero, L_800B8F58
    if (ctx->r1 == 0) {
        // 0x800B8F6C: subu        $t6, $v0, $a0
        ctx->r14 = SUB32(ctx->r2, ctx->r4);
            goto L_800B8F58;
    }
    // 0x800B8F6C: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
L_800B8F70:
    // 0x800B8F70: lh          $t9, 0x10($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X10);
    // 0x800B8F74: beq         $s4, $zero, L_800B8FD4
    if (ctx->r20 == 0) {
        // 0x800B8F78: sh          $t9, 0x6($v1)
        MEM_H(0X6, ctx->r3) = ctx->r25;
            goto L_800B8FD4;
    }
    // 0x800B8F78: sh          $t9, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r25;
    // 0x800B8F7C: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x800B8F80: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B8F84: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x800B8F88: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800B8F8C: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8F90: lh          $t6, 0x6($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X6);
    // 0x800B8F94: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x800B8F98: mflo        $t9
    ctx->r25 = lo;
    // 0x800B8F9C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800B8FA0: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800B8FA4: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
    // 0x800B8FA8: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    // 0x800B8FAC: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x800B8FB0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B8FB4: bne         $at, $zero, L_800B8FD4
    if (ctx->r1 != 0) {
        // 0x800B8FB8: subu        $t9, $v0, $a0
        ctx->r25 = SUB32(ctx->r2, ctx->r4);
            goto L_800B8FD4;
    }
    // 0x800B8FB8: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
L_800B8FBC:
    // 0x800B8FBC: sh          $t9, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r25;
    // 0x800B8FC0: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    // 0x800B8FC4: nop

    // 0x800B8FC8: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B8FCC: beq         $at, $zero, L_800B8FBC
    if (ctx->r1 == 0) {
        // 0x800B8FD0: subu        $t9, $v0, $a0
        ctx->r25 = SUB32(ctx->r2, ctx->r4);
            goto L_800B8FBC;
    }
    // 0x800B8FD0: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
L_800B8FD4:
    // 0x800B8FD4: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
L_800B8FD8:
    // 0x800B8FD8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B8FDC: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B8FE0: bne         $at, $zero, L_800B8ED4
    if (ctx->r1 != 0) {
        // 0x800B8FE4: nop
    
            goto L_800B8ED4;
    }
    // 0x800B8FE4: nop

L_800B8FE8:
    // 0x800B8FE8: addiu       $t5, $t5, 0x8
    ctx->r13 = ADD32(ctx->r13, 0X8);
    // 0x800B8FEC: slti        $at, $t5, 0x9
    ctx->r1 = SIGNED(ctx->r13) < 0X9 ? 1 : 0;
    // 0x800B8FF0: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    // 0x800B8FF4: bne         $at, $zero, L_800B9008
    if (ctx->r1 != 0) {
        // 0x800B8FF8: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800B9008;
    }
    // 0x800B8FF8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800B8FFC: addiu       $t5, $t5, -0x10
    ctx->r13 = ADD32(ctx->r13, -0X10);
    // 0x800B9000: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800B9004: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_800B9008:
    // 0x800B9008: slt         $at, $s5, $a0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B900C: bne         $at, $zero, L_800B8E30
    if (ctx->r1 != 0) {
        // 0x800B9010: nop
    
            goto L_800B8E30;
    }
    // 0x800B9010: nop

L_800B9014:
    // 0x800B9014: addiu       $s4, $s4, 0x10
    ctx->r20 = ADD32(ctx->r20, 0X10);
    // 0x800B9018: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800B901C: slti        $at, $s4, 0x11
    ctx->r1 = SIGNED(ctx->r20) < 0X11 ? 1 : 0;
    // 0x800B9020: bne         $at, $zero, L_800B9030
    if (ctx->r1 != 0) {
        // 0x800B9024: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_800B9030;
    }
    // 0x800B9024: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800B9028: addiu       $s4, $s4, -0x20
    ctx->r20 = ADD32(ctx->r20, -0X20);
    // 0x800B902C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_800B9030:
    // 0x800B9030: slt         $at, $s6, $a0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B9034: bne         $at, $zero, L_800B8DEC
    if (ctx->r1 != 0) {
        // 0x800B9038: nop
    
            goto L_800B8DEC;
    }
    // 0x800B9038: nop

    // 0x800B903C: b           L_800B91EC
    // 0x800B9040: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
        goto L_800B91EC;
    // 0x800B9040: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
L_800B9044:
    // 0x800B9044: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    // 0x800B9048: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800B904C: sra         $v0, $a0, 1
    ctx->r2 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800B9050: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // 0x800B9054: blez        $a0, L_800B91E8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B9058: subu        $s7, $s7, $v0
        ctx->r23 = SUB32(ctx->r23, ctx->r2);
            goto L_800B91E8;
    }
    // 0x800B9058: subu        $s7, $s7, $v0
    ctx->r23 = SUB32(ctx->r23, ctx->r2);
    // 0x800B905C: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800B9060: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800B9064: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B9068: addiu       $s0, $s0, -0x5A18
    ctx->r16 = ADD32(ctx->r16, -0X5A18);
    // 0x800B906C: addiu       $s2, $s2, 0x317C
    ctx->r18 = ADD32(ctx->r18, 0X317C);
    // 0x800B9070: addiu       $fp, $fp, -0x5F28
    ctx->r30 = ADD32(ctx->r30, -0X5F28);
    // 0x800B9074: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800B9078: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x800B907C: addiu       $ra, $zero, 0x1C
    ctx->r31 = ADD32(0, 0X1C);
L_800B9080:
    // 0x800B9080: bltz        $s7, L_800B91D8
    if (SIGNED(ctx->r23) < 0) {
        // 0x800B9084: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800B91D8;
    }
    // 0x800B9084: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800B9088: lw          $t8, -0x5F24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5F24);
    // 0x800B908C: nop

    // 0x800B9090: slt         $at, $s7, $t8
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B9094: beq         $at, $zero, L_800B91D8
    if (ctx->r1 == 0) {
        // 0x800B9098: nop
    
            goto L_800B91D8;
    }
    // 0x800B9098: nop

    // 0x800B909C: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800B90A0: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800B90A4: multu       $s7, $t7
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B90A8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B90AC: mflo        $t9
    ctx->r25 = lo;
    // 0x800B90B0: addu        $t2, $t9, $s3
    ctx->r10 = ADD32(ctx->r25, ctx->r19);
    // 0x800B90B4: blez        $a0, L_800B91D8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B90B8: nop
    
            goto L_800B91D8;
    }
    // 0x800B90B8: nop

L_800B90BC:
    // 0x800B90BC: bltz        $s3, L_800B91C0
    if (SIGNED(ctx->r19) < 0) {
        // 0x800B90C0: nop
    
            goto L_800B91C0;
    }
    // 0x800B90C0: nop

    // 0x800B90C4: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800B90C8: sll         $t7, $s7, 2
    ctx->r15 = S32(ctx->r23 << 2);
    // 0x800B90CC: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B90D0: beq         $at, $zero, L_800B91C0
    if (ctx->r1 == 0) {
        // 0x800B90D4: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_800B91C0;
    }
    // 0x800B90D4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B90D8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x800B90DC: lw          $t9, -0x5F18($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5F18);
    // 0x800B90E0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B90E4: sllv        $t8, $t6, $s3
    ctx->r24 = S32(ctx->r14 << (ctx->r19 & 31));
    // 0x800B90E8: and         $t7, $t9, $t8
    ctx->r15 = ctx->r25 & ctx->r24;
    // 0x800B90EC: beq         $t7, $zero, L_800B91C0
    if (ctx->r15 == 0) {
        // 0x800B90F0: nop
    
            goto L_800B91C0;
    }
    // 0x800B90F0: nop

    // 0x800B90F4: multu       $s6, $a0
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B90F8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B90FC: lw          $t6, 0x30E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30E0);
    // 0x800B9100: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800B9104: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B9108: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B910C: mflo        $t9
    ctx->r25 = lo;
    // 0x800B9110: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x800B9114: sll         $t9, $s5, 1
    ctx->r25 = S32(ctx->r21 << 1);
    // 0x800B9118: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800B911C: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800B9120: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800B9124: lw          $t7, 0x30D4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30D4);
    // 0x800B9128: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x800B912C: sll         $t9, $t2, 2
    ctx->r25 = S32(ctx->r10 << 2);
    // 0x800B9130: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800B9134: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800B9138: lw          $t0, -0x5F20($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5F20);
    // 0x800B913C: nop

    // 0x800B9140: blez        $t0, L_800B91C0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800B9144: nop
    
            goto L_800B91C0;
    }
    // 0x800B9144: nop

    // 0x800B9148: lw          $t1, 0x30D8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X30D8);
    // 0x800B914C: nop

L_800B9150:
    // 0x800B9150: multu       $v0, $ra
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9154: mflo        $t7
    ctx->r15 = lo;
    // 0x800B9158: addu        $a2, $t1, $t7
    ctx->r6 = ADD32(ctx->r9, ctx->r15);
    // 0x800B915C: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x800B9160: nop

    // 0x800B9164: bne         $t2, $t9, L_800B91B0
    if (ctx->r10 != ctx->r25) {
        // 0x800B9168: nop
    
            goto L_800B91B0;
    }
    // 0x800B9168: nop

    // 0x800B916C: multu       $a3, $s1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9170: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800B9174: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800B9178: mflo        $t8
    ctx->r24 = lo;
    // 0x800B917C: addu        $v1, $s0, $t8
    ctx->r3 = ADD32(ctx->r16, ctx->r24);
    // 0x800B9180: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x800B9184: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B9188: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x800B918C: lh          $t6, 0x12($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X12);
    // 0x800B9190: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
    // 0x800B9194: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x800B9198: lh          $t7, 0x10($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X10);
    // 0x800B919C: nop

    // 0x800B91A0: sh          $t7, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r15;
    // 0x800B91A4: mflo        $t8
    ctx->r24 = lo;
    // 0x800B91A8: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x800B91AC: nop

L_800B91B0:
    // 0x800B91B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B91B4: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B91B8: bne         $at, $zero, L_800B9150
    if (ctx->r1 != 0) {
        // 0x800B91BC: nop
    
            goto L_800B9150;
    }
    // 0x800B91BC: nop

L_800B91C0:
    // 0x800B91C0: lw          $a0, 0x24($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X24);
    // 0x800B91C4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800B91C8: slt         $at, $s5, $a0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B91CC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800B91D0: bne         $at, $zero, L_800B90BC
    if (ctx->r1 != 0) {
        // 0x800B91D4: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_800B90BC;
    }
    // 0x800B91D4: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_800B91D8:
    // 0x800B91D8: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800B91DC: slt         $at, $s6, $a0
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B91E0: bne         $at, $zero, L_800B9080
    if (ctx->r1 != 0) {
        // 0x800B91E4: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_800B9080;
    }
    // 0x800B91E4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_800B91E8:
    // 0x800B91E8: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
L_800B91EC:
    // 0x800B91EC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x800B91F0: jal         0x800BA288
    // 0x800B91F4: nop

    func_800BA288(rdram, ctx);
        goto after_0;
    // 0x800B91F4: nop

    after_0:
    extern void dkr_stabilise_persistent_water_transition(uint8_t*, recomp_context*); dkr_stabilise_persistent_water_transition(rdram, ctx);
    // 0x800B91F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800B91FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B9200: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B9204: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B9208: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B920C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B9210: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800B9214: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800B9218: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800B921C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800B9220: jr          $ra
    // 0x800B9224: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800B9224: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _Printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3F10: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x800D3F14: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800D3F18: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800D3F1C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800D3F20: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800D3F24: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D3F28: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D3F2C: sw          $a3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r7;
    // 0x800D3F30: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800D3F34: lui         $s6, 0x800F
    ctx->r22 = S32(0X800F << 16);
    // 0x800D3F38: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800D3F3C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800D3F40: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800D3F44: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800D3F48: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800D3F4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D3F50: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D3F54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D3F58: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    // 0x800D3F5C: sw          $zero, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = 0;
    // 0x800D3F60: addiu       $s7, $s7, 0x48C0
    ctx->r23 = ADD32(ctx->r23, 0X48C0);
    // 0x800D3F64: addiu       $s6, $s6, -0x693C
    ctx->r22 = ADD32(ctx->r22, -0X693C);
    // 0x800D3F68: addiu       $s5, $s5, 0x48E4
    ctx->r21 = ADD32(ctx->r21, 0X48E4);
    // 0x800D3F6C: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
L_800D3F70:
    // 0x800D3F70: lbu         $s0, 0x0($a3)
    ctx->r16 = MEM_BU(ctx->r7, 0X0);
    // 0x800D3F74: addiu       $s2, $a3, 0x1
    ctx->r18 = ADD32(ctx->r7, 0X1);
    // 0x800D3F78: addiu       $v1, $zero, 0x25
    ctx->r3 = ADD32(0, 0X25);
    // 0x800D3F7C: blez        $s0, L_800D3FA4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D3F80: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D3FA4;
    }
    // 0x800D3F80: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_800D3F84:
    // 0x800D3F84: bnel        $v1, $s0, L_800D3F98
    if (ctx->r3 != ctx->r16) {
        // 0x800D3F88: lbu         $s0, 0x0($s2)
        ctx->r16 = MEM_BU(ctx->r18, 0X0);
            goto L_800D3F98;
    }
    goto skip_0;
    // 0x800D3F88: lbu         $s0, 0x0($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X0);
    skip_0:
    // 0x800D3F8C: b           L_800D3FA4
    // 0x800D3F90: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_800D3FA4;
    // 0x800D3F90: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800D3F94: lbu         $s0, 0x0($s2)
    ctx->r16 = MEM_BU(ctx->r18, 0X0);
L_800D3F98:
    // 0x800D3F98: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D3F9C: bgtz        $s0, L_800D3F84
    if (SIGNED(ctx->r16) > 0) {
        // 0x800D3FA0: nop
    
            goto L_800D3F84;
    }
    // 0x800D3FA0: nop

L_800D3FA4:
    // 0x800D3FA4: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
    // 0x800D3FA8: blez        $v0, L_800D3FDC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D3FAC: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_800D3FDC;
    }
    // 0x800D3FAC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800D3FB0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800D3FB4: jalr        $s4
    // 0x800D3FB8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x800D3FB8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_0:
    // 0x800D3FBC: beq         $v0, $zero, L_800D3FD4
    if (ctx->r2 == 0) {
        // 0x800D3FC0: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D3FD4;
    }
    // 0x800D3FC0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D3FC4: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x800D3FC8: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800D3FCC: b           L_800D3FDC
    // 0x800D3FD0: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
        goto L_800D3FDC;
    // 0x800D3FD0: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
L_800D3FD4:
    // 0x800D3FD4: b           L_800D4524
    // 0x800D3FD8: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4524;
    // 0x800D3FD8: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D3FDC:
    // 0x800D3FDC: bne         $s0, $zero, L_800D3FEC
    if (ctx->r16 != 0) {
        // 0x800D3FE0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800D3FEC;
    }
    // 0x800D3FE0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D3FE4: b           L_800D4524
    // 0x800D3FE8: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4524;
    // 0x800D3FE8: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D3FEC:
    // 0x800D3FEC: sw          $zero, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = 0;
    // 0x800D3FF0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x800D3FF4: jal         0x800CE1C4
    // 0x800D3FF8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    strchr_recomp(rdram, ctx);
        goto after_1;
    // 0x800D3FF8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x800D3FFC: beq         $v0, $zero, L_800D403C
    if (ctx->r2 == 0) {
        // 0x800D4000: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800D403C;
    }
    // 0x800D4000: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800D4004:
    // 0x800D4004: subu        $t9, $s0, $s6
    ctx->r25 = SUB32(ctx->r16, ctx->r22);
    // 0x800D4008: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800D400C: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800D4010: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800D4014: lw          $t7, -0x6934($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6934);
    // 0x800D4018: lw          $t8, 0xD8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD8);
    // 0x800D401C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D4020: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800D4024: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x800D4028: sw          $t9, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r25;
    // 0x800D402C: jal         0x800CE1C4
    // 0x800D4030: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    strchr_recomp(rdram, ctx);
        goto after_2;
    // 0x800D4030: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_2:
    // 0x800D4034: bne         $v0, $zero, L_800D4004
    if (ctx->r2 != 0) {
        // 0x800D4038: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800D4004;
    }
    // 0x800D4038: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800D403C:
    // 0x800D403C: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x800D4040: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x800D4044: lw          $t8, 0xEC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XEC);
    // 0x800D4048: bne         $v0, $t6, L_800D4090
    if (ctx->r2 != ctx->r14) {
        // 0x800D404C: lui         $a0, 0x800F
        ctx->r4 = S32(0X800F << 16);
            goto L_800D4090;
    }
    // 0x800D404C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D4050: addiu       $t7, $t8, 0x3
    ctx->r15 = ADD32(ctx->r24, 0X3);
    // 0x800D4054: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D4058: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x800D405C: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800D4060: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
    // 0x800D4064: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x800D4068: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D406C: bgez        $t8, L_800D4088
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D4070: sw          $t8, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->r24;
            goto L_800D4088;
    }
    // 0x800D4070: sw          $t8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r24;
    // 0x800D4074: lw          $t6, 0xD8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD8);
    // 0x800D4078: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x800D407C: sw          $t7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r15;
    // 0x800D4080: ori         $t9, $t6, 0x4
    ctx->r25 = ctx->r14 | 0X4;
    // 0x800D4084: sw          $t9, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r25;
L_800D4088:
    // 0x800D4088: b           L_800D40EC
    // 0x800D408C: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_800D40EC;
    // 0x800D408C: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_800D4090:
    // 0x800D4090: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
    // 0x800D4094: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x800D4098: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800D409C: bne         $at, $zero, L_800D40EC
    if (ctx->r1 != 0) {
        // 0x800D40A0: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800D40EC;
    }
    // 0x800D40A0: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800D40A4: beql        $at, $zero, L_800D40F0
    if (ctx->r1 == 0) {
        // 0x800D40A8: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800D40F0;
    }
    goto skip_1;
    // 0x800D40A8: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_1:
    // 0x800D40AC: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
L_800D40B0:
    // 0x800D40B0: slti        $at, $t8, 0x3E7
    ctx->r1 = SIGNED(ctx->r24) < 0X3E7 ? 1 : 0;
    // 0x800D40B4: beql        $at, $zero, L_800D40D4
    if (ctx->r1 == 0) {
        // 0x800D40B8: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_800D40D4;
    }
    goto skip_2;
    // 0x800D40B8: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_2:
    // 0x800D40BC: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D40C0: mflo        $t7
    ctx->r15 = lo;
    // 0x800D40C4: addu        $t6, $a1, $t7
    ctx->r14 = ADD32(ctx->r5, ctx->r15);
    // 0x800D40C8: addiu       $t9, $t6, -0x30
    ctx->r25 = ADD32(ctx->r14, -0X30);
    // 0x800D40CC: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x800D40D0: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_800D40D4:
    // 0x800D40D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D40D8: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800D40DC: bne         $at, $zero, L_800D40EC
    if (ctx->r1 != 0) {
        // 0x800D40E0: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800D40EC;
    }
    // 0x800D40E0: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800D40E4: bnel        $at, $zero, L_800D40B0
    if (ctx->r1 != 0) {
        // 0x800D40E8: lw          $t8, 0xD0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XD0);
            goto L_800D40B0;
    }
    goto skip_3;
    // 0x800D40E8: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    skip_3:
L_800D40EC:
    // 0x800D40EC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_800D40F0:
    // 0x800D40F0: beq         $a1, $at, L_800D4104
    if (ctx->r5 == ctx->r1) {
        // 0x800D40F4: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_800D4104;
    }
    // 0x800D40F4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800D40F8: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
    // 0x800D40FC: b           L_800D4198
    // 0x800D4100: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_800D4198;
    // 0x800D4100: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_800D4104:
    // 0x800D4104: lbu         $t7, 0x1($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1);
    // 0x800D4108: lw          $t6, 0xEC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XEC);
    // 0x800D410C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D4110: bne         $v0, $t7, L_800D413C
    if (ctx->r2 != ctx->r15) {
        // 0x800D4114: addiu       $t9, $t6, 0x3
        ctx->r25 = ADD32(ctx->r14, 0X3);
            goto L_800D413C;
    }
    // 0x800D4114: addiu       $t9, $t6, 0x3
    ctx->r25 = ADD32(ctx->r14, 0X3);
    // 0x800D4118: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D411C: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800D4120: addiu       $t7, $t8, 0x4
    ctx->r15 = ADD32(ctx->r24, 0X4);
    // 0x800D4124: sw          $t7, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r15;
    // 0x800D4128: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x800D412C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D4130: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    // 0x800D4134: b           L_800D4198
    // 0x800D4138: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_800D4198;
    // 0x800D4138: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_800D413C:
    // 0x800D413C: sw          $zero, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = 0;
    // 0x800D4140: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x800D4144: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800D4148: bne         $at, $zero, L_800D4198
    if (ctx->r1 != 0) {
        // 0x800D414C: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800D4198;
    }
    // 0x800D414C: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800D4150: beq         $at, $zero, L_800D4198
    if (ctx->r1 == 0) {
        // 0x800D4154: nop
    
            goto L_800D4198;
    }
    // 0x800D4154: nop

    // 0x800D4158: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
L_800D415C:
    // 0x800D415C: slti        $at, $t9, 0x3E7
    ctx->r1 = SIGNED(ctx->r25) < 0X3E7 ? 1 : 0;
    // 0x800D4160: beql        $at, $zero, L_800D4180
    if (ctx->r1 == 0) {
        // 0x800D4164: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_800D4180;
    }
    goto skip_4;
    // 0x800D4164: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_4:
    // 0x800D4168: multu       $t9, $fp
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D416C: mflo        $t7
    ctx->r15 = lo;
    // 0x800D4170: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800D4174: addiu       $t6, $t8, -0x30
    ctx->r14 = ADD32(ctx->r24, -0X30);
    // 0x800D4178: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    // 0x800D417C: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_800D4180:
    // 0x800D4180: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D4184: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800D4188: bne         $at, $zero, L_800D4198
    if (ctx->r1 != 0) {
        // 0x800D418C: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800D4198;
    }
    // 0x800D418C: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800D4190: bnel        $at, $zero, L_800D415C
    if (ctx->r1 != 0) {
        // 0x800D4194: lw          $t9, 0xCC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XCC);
            goto L_800D415C;
    }
    goto skip_5;
    // 0x800D4194: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    skip_5:
L_800D4198:
    // 0x800D4198: jal         0x800CE1C4
    // 0x800D419C: addiu       $a0, $a0, -0x6940
    ctx->r4 = ADD32(ctx->r4, -0X6940);
    strchr_recomp(rdram, ctx);
        goto after_3;
    // 0x800D419C: addiu       $a0, $a0, -0x6940
    ctx->r4 = ADD32(ctx->r4, -0X6940);
    after_3:
    // 0x800D41A0: beq         $v0, $zero, L_800D41B8
    if (ctx->r2 == 0) {
        // 0x800D41A4: addiu       $s0, $sp, 0xA8
        ctx->r16 = ADD32(ctx->r29, 0XA8);
            goto L_800D41B8;
    }
    // 0x800D41A4: addiu       $s0, $sp, 0xA8
    ctx->r16 = ADD32(ctx->r29, 0XA8);
    // 0x800D41A8: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x800D41AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D41B0: b           L_800D41BC
    // 0x800D41B4: sb          $t9, 0xDC($sp)
    MEM_B(0XDC, ctx->r29) = ctx->r25;
        goto L_800D41BC;
    // 0x800D41B4: sb          $t9, 0xDC($sp)
    MEM_B(0XDC, ctx->r29) = ctx->r25;
L_800D41B8:
    // 0x800D41B8: sb          $zero, 0xDC($sp)
    MEM_B(0XDC, ctx->r29) = 0;
L_800D41BC:
    // 0x800D41BC: lbu         $t7, 0xDC($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XDC);
    // 0x800D41C0: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // 0x800D41C4: addiu       $a2, $sp, 0xEC
    ctx->r6 = ADD32(ctx->r29, 0XEC);
    // 0x800D41C8: bne         $v0, $t7, L_800D41E8
    if (ctx->r2 != ctx->r15) {
        // 0x800D41CC: addiu       $a3, $sp, 0x7C
        ctx->r7 = ADD32(ctx->r29, 0X7C);
            goto L_800D41E8;
    }
    // 0x800D41CC: addiu       $a3, $sp, 0x7C
    ctx->r7 = ADD32(ctx->r29, 0X7C);
    // 0x800D41D0: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x800D41D4: addiu       $t6, $zero, 0x4C
    ctx->r14 = ADD32(0, 0X4C);
    // 0x800D41D8: bne         $v0, $t8, L_800D41E8
    if (ctx->r2 != ctx->r24) {
        // 0x800D41DC: nop
    
            goto L_800D41E8;
    }
    // 0x800D41DC: nop

    // 0x800D41E0: sb          $t6, 0xDC($sp)
    MEM_B(0XDC, ctx->r29) = ctx->r14;
    // 0x800D41E4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800D41E8:
    // 0x800D41E8: jal         0x800D38A0
    // 0x800D41EC: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    static_3_800D38A0(rdram, ctx);
        goto after_4;
    // 0x800D41EC: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_4:
    // 0x800D41F0: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800D41F4: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800D41F8: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x800D41FC: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800D4200: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800D4204: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800D4208: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x800D420C: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800D4210: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x800D4214: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800D4218: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800D421C: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800D4220: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
    // 0x800D4224: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800D4228: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x800D422C: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x800D4230: bne         $t8, $zero, L_800D429C
    if (ctx->r24 != 0) {
        // 0x800D4234: slt         $t6, $zero, $t9
        ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_800D429C;
    }
    // 0x800D4234: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D4238: beql        $t6, $zero, L_800D42A0
    if (ctx->r14 == 0) {
        // 0x800D423C: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_800D42A0;
    }
    goto skip_6;
    // 0x800D423C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_6:
    // 0x800D4240: beq         $t6, $zero, L_800D429C
    if (ctx->r14 == 0) {
        // 0x800D4244: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800D429C;
    }
    // 0x800D4244: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800D4248: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800D424C:
    // 0x800D424C: bne         $at, $zero, L_800D425C
    if (ctx->r1 != 0) {
        // 0x800D4250: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D425C;
    }
    // 0x800D4250: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D4254: b           L_800D425C
    // 0x800D4258: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800D425C;
    // 0x800D4258: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800D425C:
    // 0x800D425C: blez        $s0, L_800D4290
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D4260: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D4290;
    }
    // 0x800D4260: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D4264: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800D4268: jalr        $s4
    // 0x800D426C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_5;
    // 0x800D426C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x800D4270: beq         $v0, $zero, L_800D4288
    if (ctx->r2 == 0) {
        // 0x800D4274: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4288;
    }
    // 0x800D4274: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D4278: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x800D427C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800D4280: b           L_800D4290
    // 0x800D4284: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D4290;
    // 0x800D4284: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D4288:
    // 0x800D4288: b           L_800D4524
    // 0x800D428C: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4524;
    // 0x800D428C: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D4290:
    // 0x800D4290: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800D4294: bgtzl       $s1, L_800D424C
    if (SIGNED(ctx->r17) > 0) {
        // 0x800D4298: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800D424C;
    }
    goto skip_7;
    // 0x800D4298: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_7:
L_800D429C:
    // 0x800D429C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_800D42A0:
    // 0x800D42A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D42A4: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x800D42A8: blezl       $t9, L_800D42E0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800D42AC: lw          $t9, 0xB8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB8);
            goto L_800D42E0;
    }
    goto skip_8;
    // 0x800D42AC: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    skip_8:
    // 0x800D42B0: jalr        $s4
    // 0x800D42B4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_6;
    // 0x800D42B4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_6:
    // 0x800D42B8: beq         $v0, $zero, L_800D42D4
    if (ctx->r2 == 0) {
        // 0x800D42BC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D42D4;
    }
    // 0x800D42BC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D42C0: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x800D42C4: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800D42C8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800D42CC: b           L_800D42DC
    // 0x800D42D0: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D42DC;
    // 0x800D42D0: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D42D4:
    // 0x800D42D4: b           L_800D4524
    // 0x800D42D8: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4524;
    // 0x800D42D8: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D42DC:
    // 0x800D42DC: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
L_800D42E0:
    // 0x800D42E0: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D42E4: beql        $t6, $zero, L_800D434C
    if (ctx->r14 == 0) {
        // 0x800D42E8: lw          $t9, 0xBC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XBC);
            goto L_800D434C;
    }
    goto skip_9;
    // 0x800D42E8: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    skip_9:
    // 0x800D42EC: beq         $t6, $zero, L_800D4348
    if (ctx->r14 == 0) {
        // 0x800D42F0: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800D4348;
    }
    // 0x800D42F0: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800D42F4: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800D42F8:
    // 0x800D42F8: bne         $at, $zero, L_800D4308
    if (ctx->r1 != 0) {
        // 0x800D42FC: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D4308;
    }
    // 0x800D42FC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D4300: b           L_800D4308
    // 0x800D4304: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800D4308;
    // 0x800D4304: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800D4308:
    // 0x800D4308: blez        $s0, L_800D433C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D430C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D433C;
    }
    // 0x800D430C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D4310: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D4314: jalr        $s4
    // 0x800D4318: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_7;
    // 0x800D4318: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x800D431C: beq         $v0, $zero, L_800D4334
    if (ctx->r2 == 0) {
        // 0x800D4320: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4334;
    }
    // 0x800D4320: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D4324: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x800D4328: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800D432C: b           L_800D433C
    // 0x800D4330: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D433C;
    // 0x800D4330: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D4334:
    // 0x800D4334: b           L_800D4524
    // 0x800D4338: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4524;
    // 0x800D4338: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D433C:
    // 0x800D433C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800D4340: bgtzl       $s1, L_800D42F8
    if (SIGNED(ctx->r17) > 0) {
        // 0x800D4344: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800D42F8;
    }
    goto skip_10;
    // 0x800D4344: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_10:
L_800D4348:
    // 0x800D4348: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
L_800D434C:
    // 0x800D434C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D4350: lw          $a1, 0xB0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB0);
    // 0x800D4354: blezl       $t9, L_800D438C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800D4358: lw          $t9, 0xC0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XC0);
            goto L_800D438C;
    }
    goto skip_11;
    // 0x800D4358: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    skip_11:
    // 0x800D435C: jalr        $s4
    // 0x800D4360: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_8;
    // 0x800D4360: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_8:
    // 0x800D4364: beq         $v0, $zero, L_800D4380
    if (ctx->r2 == 0) {
        // 0x800D4368: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4380;
    }
    // 0x800D4368: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D436C: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x800D4370: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800D4374: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800D4378: b           L_800D4388
    // 0x800D437C: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D4388;
    // 0x800D437C: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D4380:
    // 0x800D4380: b           L_800D4524
    // 0x800D4384: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4524;
    // 0x800D4384: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D4388:
    // 0x800D4388: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
L_800D438C:
    // 0x800D438C: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D4390: beql        $t6, $zero, L_800D43F8
    if (ctx->r14 == 0) {
        // 0x800D4394: lw          $t9, 0xC4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XC4);
            goto L_800D43F8;
    }
    goto skip_12;
    // 0x800D4394: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    skip_12:
    // 0x800D4398: beq         $t6, $zero, L_800D43F4
    if (ctx->r14 == 0) {
        // 0x800D439C: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800D43F4;
    }
    // 0x800D439C: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800D43A0: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800D43A4:
    // 0x800D43A4: bne         $at, $zero, L_800D43B4
    if (ctx->r1 != 0) {
        // 0x800D43A8: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D43B4;
    }
    // 0x800D43A8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D43AC: b           L_800D43B4
    // 0x800D43B0: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800D43B4;
    // 0x800D43B0: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800D43B4:
    // 0x800D43B4: blez        $s0, L_800D43E8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D43B8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D43E8;
    }
    // 0x800D43B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D43BC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D43C0: jalr        $s4
    // 0x800D43C4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_9;
    // 0x800D43C4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x800D43C8: beq         $v0, $zero, L_800D43E0
    if (ctx->r2 == 0) {
        // 0x800D43CC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D43E0;
    }
    // 0x800D43CC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D43D0: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x800D43D4: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800D43D8: b           L_800D43E8
    // 0x800D43DC: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D43E8;
    // 0x800D43DC: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D43E0:
    // 0x800D43E0: b           L_800D4524
    // 0x800D43E4: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4524;
    // 0x800D43E4: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D43E8:
    // 0x800D43E8: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800D43EC: bgtzl       $s1, L_800D43A4
    if (SIGNED(ctx->r17) > 0) {
        // 0x800D43F0: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800D43A4;
    }
    goto skip_13;
    // 0x800D43F0: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_13:
L_800D43F4:
    // 0x800D43F4: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
L_800D43F8:
    // 0x800D43F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D43FC: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800D4400: blez        $t9, L_800D4438
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800D4404: lw          $t7, 0xBC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XBC);
            goto L_800D4438;
    }
    // 0x800D4404: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800D4408: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800D440C: jalr        $s4
    // 0x800D4410: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_10;
    // 0x800D4410: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_10:
    // 0x800D4414: beq         $v0, $zero, L_800D4430
    if (ctx->r2 == 0) {
        // 0x800D4418: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4430;
    }
    // 0x800D4418: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D441C: lw          $t8, 0xD4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD4);
    // 0x800D4420: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800D4424: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800D4428: b           L_800D4438
    // 0x800D442C: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
        goto L_800D4438;
    // 0x800D442C: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
L_800D4430:
    // 0x800D4430: b           L_800D4524
    // 0x800D4434: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4524;
    // 0x800D4434: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D4438:
    // 0x800D4438: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800D443C: slt         $t8, $zero, $t9
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800D4440: beql        $t8, $zero, L_800D44A8
    if (ctx->r24 == 0) {
        // 0x800D4444: lw          $t9, 0xD8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD8);
            goto L_800D44A8;
    }
    goto skip_14;
    // 0x800D4444: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    skip_14:
    // 0x800D4448: beq         $t8, $zero, L_800D44A4
    if (ctx->r24 == 0) {
        // 0x800D444C: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800D44A4;
    }
    // 0x800D444C: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800D4450: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800D4454:
    // 0x800D4454: bne         $at, $zero, L_800D4464
    if (ctx->r1 != 0) {
        // 0x800D4458: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D4464;
    }
    // 0x800D4458: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D445C: b           L_800D4464
    // 0x800D4460: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800D4464;
    // 0x800D4460: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800D4464:
    // 0x800D4464: blez        $s0, L_800D4498
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D4468: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D4498;
    }
    // 0x800D4468: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D446C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D4470: jalr        $s4
    // 0x800D4474: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_11;
    // 0x800D4474: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_11:
    // 0x800D4478: beq         $v0, $zero, L_800D4490
    if (ctx->r2 == 0) {
        // 0x800D447C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4490;
    }
    // 0x800D447C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D4480: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x800D4484: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x800D4488: b           L_800D4498
    // 0x800D448C: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
        goto L_800D4498;
    // 0x800D448C: sw          $t7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r15;
L_800D4490:
    // 0x800D4490: b           L_800D4524
    // 0x800D4494: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4524;
    // 0x800D4494: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D4498:
    // 0x800D4498: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800D449C: bgtzl       $s1, L_800D4454
    if (SIGNED(ctx->r17) > 0) {
        // 0x800D44A0: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800D4454;
    }
    goto skip_15;
    // 0x800D44A0: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_15:
L_800D44A4:
    // 0x800D44A4: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
L_800D44A8:
    // 0x800D44A8: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x800D44AC: andi        $t8, $t9, 0x4
    ctx->r24 = ctx->r25 & 0X4;
    // 0x800D44B0: beq         $t8, $zero, L_800D451C
    if (ctx->r24 == 0) {
        // 0x800D44B4: slt         $t7, $zero, $t6
        ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_800D451C;
    }
    // 0x800D44B4: slt         $t7, $zero, $t6
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800D44B8: beq         $t7, $zero, L_800D451C
    if (ctx->r15 == 0) {
        // 0x800D44BC: nop
    
            goto L_800D451C;
    }
    // 0x800D44BC: nop

    // 0x800D44C0: beq         $t7, $zero, L_800D451C
    if (ctx->r15 == 0) {
        // 0x800D44C4: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_800D451C;
    }
    // 0x800D44C4: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800D44C8: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800D44CC:
    // 0x800D44CC: bne         $at, $zero, L_800D44DC
    if (ctx->r1 != 0) {
        // 0x800D44D0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800D44DC;
    }
    // 0x800D44D0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800D44D4: b           L_800D44DC
    // 0x800D44D8: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800D44DC;
    // 0x800D44D8: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800D44DC:
    // 0x800D44DC: blez        $s0, L_800D4510
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D44E0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800D4510;
    }
    // 0x800D44E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D44E4: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800D44E8: jalr        $s4
    // 0x800D44EC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_12;
    // 0x800D44EC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
    // 0x800D44F0: beq         $v0, $zero, L_800D4508
    if (ctx->r2 == 0) {
        // 0x800D44F4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800D4508;
    }
    // 0x800D44F4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D44F8: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x800D44FC: addu        $t8, $t9, $s0
    ctx->r24 = ADD32(ctx->r25, ctx->r16);
    // 0x800D4500: b           L_800D4510
    // 0x800D4504: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
        goto L_800D4510;
    // 0x800D4504: sw          $t8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r24;
L_800D4508:
    // 0x800D4508: b           L_800D4524
    // 0x800D450C: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
        goto L_800D4524;
    // 0x800D450C: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
L_800D4510:
    // 0x800D4510: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800D4514: bgtzl       $s1, L_800D44CC
    if (SIGNED(ctx->r17) > 0) {
        // 0x800D4518: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800D44CC;
    }
    goto skip_16;
    // 0x800D4518: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_16:
L_800D451C:
    // 0x800D451C: b           L_800D3F70
    // 0x800D4520: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
        goto L_800D3F70;
    // 0x800D4520: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
L_800D4524:
    // 0x800D4524: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800D4528: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D452C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4530: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D4534: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D4538: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D453C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800D4540: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800D4544: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800D4548: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800D454C: jr          $ra
    // 0x800D4550: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x800D4550: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_80084854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084854: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80084858: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008485C: addiu       $a1, $a1, 0x69E0
    ctx->r5 = ADD32(ctx->r5, 0X69E0);
    // 0x80084860: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80084864: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80084868: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8008486C: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80084870: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80084874: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80084878: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8008487C: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80084880: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80084884: lw          $s3, -0x544($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X544);
    // 0x80084888: slti        $at, $t6, 0x30
    ctx->r1 = SIGNED(ctx->r14) < 0X30 ? 1 : 0;
    // 0x8008488C: bne         $at, $zero, L_800848A8
    if (ctx->r1 != 0) {
        // 0x80084890: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800848A8;
    }
    // 0x80084890: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80084894: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x80084898: nop

    // 0x8008489C: slti        $at, $t7, 0x3A
    ctx->r1 = SIGNED(ctx->r15) < 0X3A ? 1 : 0;
    // 0x800848A0: bne         $at, $zero, L_800848D4
    if (ctx->r1 != 0) {
        // 0x800848A4: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_800848D4;
    }
    // 0x800848A4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_800848A8:
    // 0x800848A8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800848AC: addu        $t8, $v1, $s1
    ctx->r24 = ADD32(ctx->r3, ctx->r17);
    // 0x800848B0: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x800848B4: nop

    // 0x800848B8: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x800848BC: bne         $at, $zero, L_800848A8
    if (ctx->r1 != 0) {
        // 0x800848C0: nop
    
            goto L_800848A8;
    }
    // 0x800848C0: nop

    // 0x800848C4: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x800848C8: beq         $at, $zero, L_800848A8
    if (ctx->r1 == 0) {
        // 0x800848CC: nop
    
            goto L_800848A8;
    }
    // 0x800848CC: nop

    // 0x800848D0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_800848D4:
    // 0x800848D4: div         $zero, $s3, $a0
    lo = S32(S64(S32(ctx->r19)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r19)) % S64(S32(ctx->r4)));
    // 0x800848D8: addu        $t0, $v1, $s1
    ctx->r8 = ADD32(ctx->r3, ctx->r17);
    // 0x800848DC: bne         $a0, $zero, L_800848E8
    if (ctx->r4 != 0) {
        // 0x800848E0: nop
    
            goto L_800848E8;
    }
    // 0x800848E0: nop

    // 0x800848E4: break       7
    do_break(2148026596);
L_800848E8:
    // 0x800848E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800848EC: bne         $a0, $at, L_80084900
    if (ctx->r4 != ctx->r1) {
        // 0x800848F0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80084900;
    }
    // 0x800848F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800848F4: bne         $s3, $at, L_80084900
    if (ctx->r19 != ctx->r1) {
        // 0x800848F8: nop
    
            goto L_80084900;
    }
    // 0x800848F8: nop

    // 0x800848FC: break       6
    do_break(2148026620);
L_80084900:
    // 0x80084900: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80084904: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80084908: addiu       $s2, $s2, 0x63A0
    ctx->r18 = ADD32(ctx->r18, 0X63A0);
    // 0x8008490C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80084910: mflo        $v0
    ctx->r2 = lo;
    // 0x80084914: addiu       $t9, $v0, 0x30
    ctx->r25 = ADD32(ctx->r2, 0X30);
    // 0x80084918: sb          $t9, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r25;
    // 0x8008491C: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80084920: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80084924: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80084928: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x8008492C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80084930: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x80084934: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80084938: mflo        $t1
    ctx->r9 = lo;
    // 0x8008493C: subu        $s3, $s3, $t1
    ctx->r19 = SUB32(ctx->r19, ctx->r9);
    // 0x80084940: addiu       $t2, $s3, 0x30
    ctx->r10 = ADD32(ctx->r19, 0X30);
    // 0x80084944: sb          $t2, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r10;
    // 0x80084948: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8008494C: lw          $s3, 0x63BC($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X63BC);
    // 0x80084950: nop

    // 0x80084954: sll         $t5, $s3, 3
    ctx->r13 = S32(ctx->r19 << 3);
    // 0x80084958: slti        $at, $t5, 0x100
    ctx->r1 = SIGNED(ctx->r13) < 0X100 ? 1 : 0;
    // 0x8008495C: bne         $at, $zero, L_8008496C
    if (ctx->r1 != 0) {
        // 0x80084960: or          $s3, $t5, $zero
        ctx->r19 = ctx->r13 | 0;
            goto L_8008496C;
    }
    // 0x80084960: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
    // 0x80084964: addiu       $t6, $zero, 0x1FF
    ctx->r14 = ADD32(0, 0X1FF);
    // 0x80084968: subu        $s3, $t6, $t5
    ctx->r19 = SUB32(ctx->r14, ctx->r13);
L_8008496C:
    // 0x8008496C: lw          $t7, -0x538($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X538);
    // 0x80084970: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084974: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80084978: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8008497C: lw          $t9, 0x69D0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X69D0);
    // 0x80084980: jal         0x80067F2C
    // 0x80084984: sw          $t9, -0x5B8($at)
    MEM_W(-0X5B8, ctx->r1) = ctx->r25;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x80084984: sw          $t9, -0x5B8($at)
    MEM_W(-0X5B8, ctx->r1) = ctx->r25;
    after_0:
    // 0x80084988: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8008498C: lw          $t0, 0x300($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X300);
    // 0x80084990: lui         $s1, 0xFFC0
    ctx->r17 = S32(0XFFC0 << 16);
    // 0x80084994: bne         $t0, $zero, L_800849A4
    if (ctx->r8 != 0) {
        // 0x80084998: ori         $s1, $s1, 0x40FF
        ctx->r17 = ctx->r17 | 0X40FF;
            goto L_800849A4;
    }
    // 0x80084998: ori         $s1, $s1, 0x40FF
    ctx->r17 = ctx->r17 | 0X40FF;
    // 0x8008499C: b           L_800849A8
    // 0x800849A0: addiu       $s0, $zero, 0x65
    ctx->r16 = ADD32(0, 0X65);
        goto L_800849A8;
    // 0x800849A0: addiu       $s0, $zero, 0x65
    ctx->r16 = ADD32(0, 0X65);
L_800849A4:
    // 0x800849A4: addiu       $s0, $zero, 0x71
    ctx->r16 = ADD32(0, 0X71);
L_800849A8:
    // 0x800849A8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800849AC: lw          $t5, 0x6660($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6660);
    // 0x800849B0: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x800849B4: addiu       $t3, $zero, 0xE
    ctx->r11 = ADD32(0, 0XE);
    // 0x800849B8: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x800849BC: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800849C0: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800849C4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800849C8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800849CC: subu        $a2, $t1, $s0
    ctx->r6 = SUB32(ctx->r9, ctx->r16);
    // 0x800849D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800849D4: addiu       $a1, $zero, -0x48
    ctx->r5 = ADD32(0, -0X48);
    // 0x800849D8: addiu       $a3, $zero, 0x90
    ctx->r7 = ADD32(0, 0X90);
    // 0x800849DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800849E0: jal         0x80080580
    // 0x800849E4: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    func_80080580(rdram, ctx);
        goto after_1;
    // 0x800849E4: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_1:
    // 0x800849E8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800849EC: lw          $t0, 0x6660($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6660);
    // 0x800849F0: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x800849F4: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x800849F8: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x800849FC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80084A00: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80084A04: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80084A08: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80084A0C: subu        $a2, $t6, $s0
    ctx->r6 = SUB32(ctx->r14, ctx->r16);
    // 0x80084A10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084A14: addiu       $a1, $zero, -0x48
    ctx->r5 = ADD32(0, -0X48);
    // 0x80084A18: addiu       $a3, $zero, 0x90
    ctx->r7 = ADD32(0, 0X90);
    // 0x80084A1C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80084A20: jal         0x80080580
    // 0x80084A24: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_80080580(rdram, ctx);
        goto after_2;
    // 0x80084A24: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_2:
    // 0x80084A28: jal         0x80080BC8
    // 0x80084A2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80080BC8(rdram, ctx);
        goto after_3;
    // 0x80084A2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80084A30: jal         0x800C5494
    // 0x80084A34: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_4;
    // 0x80084A34: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_4:
    // 0x80084A38: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80084A3C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80084A40: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80084A44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084A48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084A4C: jal         0x800C4FBC
    // 0x80084A50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_5;
    // 0x80084A50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80084A54: addiu       $t3, $zero, 0x7B
    ctx->r11 = ADD32(0, 0X7B);
    // 0x80084A58: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80084A5C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80084A60: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    // 0x80084A64: addiu       $a2, $zero, 0x75
    ctx->r6 = ADD32(0, 0X75);
    // 0x80084A68: jal         0x800C4EDC
    // 0x80084A6C: addiu       $a3, $zero, 0xE2
    ctx->r7 = ADD32(0, 0XE2);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_6;
    // 0x80084A6C: addiu       $a3, $zero, 0xE2
    ctx->r7 = ADD32(0, 0XE2);
    after_6:
    // 0x80084A70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80084A74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084A78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084A7C: jal         0x800C5B58
    // 0x80084A80: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_7;
    // 0x80084A80: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_7:
    // 0x80084A84: addiu       $t2, $zero, 0xA3
    ctx->r10 = ADD32(0, 0XA3);
    // 0x80084A88: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80084A8C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80084A90: addiu       $a1, $zero, 0x5E
    ctx->r5 = ADD32(0, 0X5E);
    // 0x80084A94: addiu       $a2, $zero, 0x9D
    ctx->r6 = ADD32(0, 0X9D);
    // 0x80084A98: jal         0x800C4EDC
    // 0x80084A9C: addiu       $a3, $zero, 0xE2
    ctx->r7 = ADD32(0, 0XE2);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_8;
    // 0x80084A9C: addiu       $a3, $zero, 0xE2
    ctx->r7 = ADD32(0, 0XE2);
    after_8:
    // 0x80084AA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80084AA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084AA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084AAC: jal         0x800C5B58
    // 0x80084AB0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_9;
    // 0x80084AB0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_9:
    // 0x80084AB4: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80084AB8: lw          $a2, -0x540($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X540);
    // 0x80084ABC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80084AC0: addiu       $s0, $s0, 0x42C
    ctx->r16 = ADD32(ctx->r16, 0X42C);
    // 0x80084AC4: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80084AC8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80084ACC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80084AD0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80084AD4: sra         $t4, $a2, 1
    ctx->r12 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80084AD8: addiu       $a2, $t4, 0x60
    ctx->r6 = ADD32(ctx->r12, 0X60);
    // 0x80084ADC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80084AE0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80084AE4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80084AE8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80084AEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80084AF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80084AF4: jal         0x80078AB8
    // 0x80084AF8: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    texrect_draw(rdram, ctx);
        goto after_10;
    // 0x80084AF8: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    after_10:
    // 0x80084AFC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80084B00: lw          $a2, -0x53C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X53C);
    // 0x80084B04: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80084B08: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80084B0C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80084B10: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80084B14: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80084B18: addiu       $a2, $t9, 0x60
    ctx->r6 = ADD32(ctx->r25, 0X60);
    // 0x80084B1C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80084B20: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80084B24: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80084B28: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80084B2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80084B30: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80084B34: jal         0x80078AB8
    // 0x80084B38: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    texrect_draw(rdram, ctx);
        goto after_11;
    // 0x80084B38: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    after_11:
    // 0x80084B3C: jal         0x8007B3D0
    // 0x80084B40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    rendermode_reset(rdram, ctx);
        goto after_12;
    // 0x80084B40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_12:
    // 0x80084B44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084B48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084B4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084B50: jal         0x800C43CC
    // 0x80084B54: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_13;
    // 0x80084B54: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
    // 0x80084B58: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80084B5C: lw          $t4, 0x63E0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X63E0);
    // 0x80084B60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80084B64: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x80084B68: beq         $at, $zero, L_80084B80
    if (ctx->r1 == 0) {
        // 0x80084B6C: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_80084B80;
    }
    // 0x80084B6C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80084B70: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80084B74: lh          $s1, 0x6C46($s1)
    ctx->r17 = MEM_H(ctx->r17, 0X6C46);
    // 0x80084B78: b           L_80084BB4
    // 0x80084B7C: nop

        goto L_80084BB4;
    // 0x80084B7C: nop

L_80084B80:
    // 0x80084B80: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80084B84: lh          $v0, 0x6C46($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6C46);
    // 0x80084B88: nop

    // 0x80084B8C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80084B90: beq         $at, $zero, L_80084BA4
    if (ctx->r1 == 0) {
        // 0x80084B94: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80084BA4;
    }
    // 0x80084B94: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80084B98: b           L_80084BB4
    // 0x80084B9C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_80084BB4;
    // 0x80084B9C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80084BA0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80084BA4:
    // 0x80084BA4: bne         $v0, $at, L_80084BB4
    if (ctx->r2 != ctx->r1) {
        // 0x80084BA8: addiu       $s1, $zero, 0x3
        ctx->r17 = ADD32(0, 0X3);
            goto L_80084BB4;
    }
    // 0x80084BA8: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x80084BAC: b           L_80084BB4
    // 0x80084BB0: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
        goto L_80084BB4;
    // 0x80084BB0: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
L_80084BB4:
    // 0x80084BB4: lw          $t5, -0x5B8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5B8);
    // 0x80084BB8: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x80084BBC: beq         $t5, $zero, L_80084C58
    if (ctx->r13 == 0) {
        // 0x80084BC0: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_80084C58;
    }
    // 0x80084BC0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80084BC4: addiu       $t7, $t7, -0x5C4
    ctx->r15 = ADD32(ctx->r15, -0X5C4);
    // 0x80084BC8: sll         $t8, $s1, 4
    ctx->r24 = S32(ctx->r17 << 4);
    // 0x80084BCC: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80084BD0: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80084BD4: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
L_80084BD8:
    // 0x80084BD8: lbu         $a0, 0x9($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9);
    // 0x80084BDC: jal         0x800C42EC
    // 0x80084BE0: nop

    set_text_font(rdram, ctx);
        goto after_14;
    // 0x80084BE0: nop

    after_14:
    // 0x80084BE4: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80084BE8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80084BEC: bne         $s0, $t0, L_80084C10
    if (ctx->r16 != ctx->r8) {
        // 0x80084BF0: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80084C10;
    }
    // 0x80084BF0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80084BF4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80084BF8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80084BFC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80084C00: jal         0x800C4384
    // 0x80084C04: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    set_text_colour(rdram, ctx);
        goto after_15;
    // 0x80084C04: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_15:
    // 0x80084C08: b           L_80084C30
    // 0x80084C0C: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
        goto L_80084C30;
    // 0x80084C0C: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
L_80084C10:
    // 0x80084C10: lbu         $t3, 0x8($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X8);
    // 0x80084C14: lbu         $a0, 0x4($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X4);
    // 0x80084C18: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80084C1C: lbu         $a2, 0x6($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X6);
    // 0x80084C20: lbu         $a3, 0x7($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X7);
    // 0x80084C24: jal         0x800C4384
    // 0x80084C28: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    set_text_colour(rdram, ctx);
        goto after_16;
    // 0x80084C28: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_16:
    // 0x80084C2C: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
L_80084C30:
    // 0x80084C30: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x80084C34: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x80084C38: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x80084C3C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80084C40: jal         0x800C4440
    // 0x80084C44: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    draw_text(rdram, ctx);
        goto after_17;
    // 0x80084C44: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_17:
    // 0x80084C48: lw          $t4, 0x1C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C);
    // 0x80084C4C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80084C50: bne         $t4, $zero, L_80084BD8
    if (ctx->r12 != 0) {
        // 0x80084C54: nop
    
            goto L_80084BD8;
    }
    // 0x80084C54: nop

L_80084C58:
    // 0x80084C58: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80084C5C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80084C60: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80084C64: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80084C68: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80084C6C: jr          $ra
    // 0x80084C70: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80084C70: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void __vsPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AAAC: lbu         $t7, 0x31($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X31);
    // 0x8000AAB0: lw          $t6, 0x60($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X60);
    // 0x8000AAB4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000AAB8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000AABC: lw          $t1, 0x20($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20);
    // 0x8000AAC0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000AAC4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8000AAC8: lbu         $t0, 0x7($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X7);
    // 0x8000AACC: lbu         $t2, 0xC($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XC);
    // 0x8000AAD0: nop

    // 0x8000AAD4: addu        $v1, $t0, $t2
    ctx->r3 = ADD32(ctx->r8, ctx->r10);
    // 0x8000AAD8: addiu       $v1, $v1, -0x40
    ctx->r3 = ADD32(ctx->r3, -0X40);
    // 0x8000AADC: bgtz        $v1, L_8000AAEC
    if (SIGNED(ctx->r3) > 0) {
        // 0x8000AAE0: slti        $at, $v1, 0x7F
        ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
            goto L_8000AAEC;
    }
    // 0x8000AAE0: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
    // 0x8000AAE4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000AAE8: slti        $at, $v1, 0x7F
    ctx->r1 = SIGNED(ctx->r3) < 0X7F ? 1 : 0;
L_8000AAEC:
    // 0x8000AAEC: bne         $at, $zero, L_8000AAF8
    if (ctx->r1 != 0) {
        // 0x8000AAF0: nop
    
            goto L_8000AAF8;
    }
    // 0x8000AAF0: nop

    // 0x8000AAF4: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_8000AAF8:
    // 0x8000AAF8: jr          $ra
    // 0x8000AAFC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    return;
    // 0x8000AAFC: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
;}
RECOMP_FUNC void mtx_get_modelmtx_s16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066204: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80066208: jr          $ra
    // 0x8006620C: addiu       $v0, $v0, 0x10A0
    ctx->r2 = ADD32(ctx->r2, 0X10A0);
    return;
    // 0x8006620C: addiu       $v0, $v0, 0x10A0
    ctx->r2 = ADD32(ctx->r2, 0X10A0);
;}
RECOMP_FUNC void render_level_segment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_level_segment_interpolation_begin(uint8_t*, recomp_context*); dkr_level_segment_interpolation_begin(rdram, ctx);
    // 0x80029658: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8002965C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80029660: lw          $t6, -0x36E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X36E8);
    // 0x80029664: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80029668: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8002966C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80029670: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80029674: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80029678: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002967C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80029680: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80029684: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80029688: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002968C: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x80029690: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x80029694: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80029698: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8002969C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800296A0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800296A4: beq         $a1, $zero, L_800296D0
    if (ctx->r5 == 0) {
        // 0x800296A8: sw          $t9, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = ctx->r25;
            goto L_800296D0;
    }
    // 0x800296A8: sw          $t9, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r25;
    // 0x800296AC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800296B0: lw          $t4, -0x2C7C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2C7C);
    // 0x800296B4: nop

    // 0x800296B8: beq         $t4, $zero, L_800296D0
    if (ctx->r12 == 0) {
        // 0x800296BC: nop
    
            goto L_800296D0;
    }
    // 0x800296BC: nop

    // 0x800296C0: jal         0x800B9228
    // 0x800296C4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    waves_block_hq(rdram, ctx);
        goto after_0;
    // 0x800296C4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_0:
    // 0x800296C8: b           L_800296D4
    // 0x800296CC: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
        goto L_800296D4;
    // 0x800296CC: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
L_800296D0:
    // 0x800296D0: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
L_800296D4:
    // 0x800296D4: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    // 0x800296D8: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x800296DC: beq         $t5, $zero, L_800296FC
    if (ctx->r13 == 0) {
        // 0x800296E0: lui         $fp, 0x8000
        ctx->r30 = S32(0X8000 << 16);
            goto L_800296FC;
    }
    // 0x800296E0: lui         $fp, 0x8000
    ctx->r30 = S32(0X8000 << 16);
    // 0x800296E4: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800296E8: nop

    // 0x800296EC: lh          $t7, 0x20($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X20);
    // 0x800296F0: lbu         $v0, 0x40($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X40);
    // 0x800296F4: b           L_80029708
    // 0x800296F8: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
        goto L_80029708;
    // 0x800296F8: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
L_800296FC:
    // 0x800296FC: lbu         $t3, 0x40($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X40);
    // 0x80029700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80029704: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
L_80029708:
    // 0x80029708: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x8002970C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80029710: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80029714: beq         $at, $zero, L_80029AC8
    if (ctx->r1 == 0) {
        // 0x80029718: sll         $t2, $v0, 2
        ctx->r10 = S32(ctx->r2 << 2);
            goto L_80029AC8;
    }
    // 0x80029718: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x8002971C: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x80029720: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80029724: addiu       $s2, $s2, -0x4F60
    ctx->r18 = ADD32(ctx->r18, -0X4F60);
    // 0x80029728: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
L_8002972C:
    // 0x8002972C: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x80029730: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80029734: lw          $t5, 0xC($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XC);
    // 0x80029738: nop

    // 0x8002973C: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    // 0x80029740: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x80029744: nop

    // 0x80029748: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x8002974C: bne         $v0, $zero, L_80029AB8
    if (ctx->r2 != 0) {
        // 0x80029750: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_80029AB8;
    }
    // 0x80029750: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80029754: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80029758: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8002975C: bne         $v0, $at, L_8002976C
    if (ctx->r2 != ctx->r1) {
        // 0x80029760: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8002976C;
    }
    // 0x80029760: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80029764: b           L_80029794
    // 0x80029768: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
        goto L_80029794;
    // 0x80029768: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8002976C:
    // 0x8002976C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80029770: lw          $t6, -0x36E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X36E8);
    // 0x80029774: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x80029778: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8002977C: nop

    // 0x80029780: addu        $t3, $t7, $t8
    ctx->r11 = ADD32(ctx->r15, ctx->r24);
    // 0x80029784: lw          $s5, 0x0($t3)
    ctx->r21 = MEM_W(ctx->r11, 0X0);
    // 0x80029788: nop

    // 0x8002978C: lh          $a2, 0x6($s5)
    ctx->r6 = MEM_H(ctx->r21, 0X6);
    // 0x80029790: nop

L_80029794:
    // 0x80029794: ori         $t4, $s1, 0xA
    ctx->r12 = ctx->r17 | 0XA;
    // 0x80029798: andi        $t9, $t4, 0x10
    ctx->r25 = ctx->r12 & 0X10;
    // 0x8002979C: bne         $t9, $zero, L_800297BC
    if (ctx->r25 != 0) {
        // 0x800297A0: or          $s1, $t4, $zero
        ctx->r17 = ctx->r12 | 0;
            goto L_800297BC;
    }
    // 0x800297A0: or          $s1, $t4, $zero
    ctx->r17 = ctx->r12 | 0;
    // 0x800297A4: andi        $t5, $t4, 0x800
    ctx->r13 = ctx->r12 & 0X800;
    // 0x800297A8: bne         $t5, $zero, L_800297BC
    if (ctx->r13 != 0) {
        // 0x800297AC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_800297BC;
    }
    // 0x800297AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800297B0: lw          $t6, -0x4F04($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4F04);
    // 0x800297B4: nop

    // 0x800297B8: or          $s1, $t4, $t6
    ctx->r17 = ctx->r12 | ctx->r14;
L_800297BC:
    // 0x800297BC: andi        $t7, $a2, 0x4
    ctx->r15 = ctx->r6 & 0X4;
    // 0x800297C0: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x800297C4: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800297C8: bne         $t7, $zero, L_800297D4
    if (ctx->r15 != 0) {
        // 0x800297CC: andi        $t8, $s1, 0x2000
        ctx->r24 = ctx->r17 & 0X2000;
            goto L_800297D4;
    }
    // 0x800297CC: andi        $t8, $s1, 0x2000
    ctx->r24 = ctx->r17 & 0X2000;
    // 0x800297D0: beq         $t8, $zero, L_800297E0
    if (ctx->r24 == 0) {
        // 0x800297D4: andi        $t3, $s1, 0x800
        ctx->r11 = ctx->r17 & 0X800;
            goto L_800297E0;
    }
L_800297D4:
    // 0x800297D4: andi        $t3, $s1, 0x800
    ctx->r11 = ctx->r17 & 0X800;
    // 0x800297D8: beq         $t3, $zero, L_800297E4
    if (ctx->r11 == 0) {
        // 0x800297DC: nop
    
            goto L_800297E4;
    }
    // 0x800297DC: nop

L_800297E0:
    // 0x800297E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800297E4:
    // 0x800297E4: beq         $t4, $zero, L_800297F8
    if (ctx->r12 == 0) {
        // 0x800297E8: andi        $t6, $s1, 0x2000
        ctx->r14 = ctx->r17 & 0X2000;
            goto L_800297F8;
    }
    // 0x800297E8: andi        $t6, $s1, 0x2000
    ctx->r14 = ctx->r17 & 0X2000;
    // 0x800297EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800297F0: andi        $t9, $a0, 0x1
    ctx->r25 = ctx->r4 & 0X1;
    // 0x800297F4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_800297F8:
    // 0x800297F8: beq         $t5, $zero, L_8002980C
    if (ctx->r13 == 0) {
        // 0x800297FC: nop
    
            goto L_8002980C;
    }
    // 0x800297FC: nop

    // 0x80029800: beq         $t6, $zero, L_8002980C
    if (ctx->r14 == 0) {
        // 0x80029804: nop
    
            goto L_8002980C;
    }
    // 0x80029804: nop

    // 0x80029808: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8002980C:
    // 0x8002980C: beq         $a0, $zero, L_80029ABC
    if (ctx->r4 == 0) {
        // 0x80029810: lw          $t7, 0x70($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X70);
            goto L_80029ABC;
    }
    // 0x80029810: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    extern void dkr_surface_interpolation_begin(uint8_t*, recomp_context*); dkr_surface_interpolation_begin(rdram, ctx);
    // 0x80029814: lh          $v0, 0x2($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X2);
    // 0x80029818: lw          $t3, 0xAC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XAC);
    // 0x8002981C: lh          $v1, 0x4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X4);
    // 0x80029820: lh          $t7, 0xE($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XE);
    // 0x80029824: lh          $t8, 0x10($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X10);
    // 0x80029828: lbu         $a3, 0x7($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X7);
    // 0x8002982C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80029830: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80029834: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x80029838: sra         $a0, $s1, 28
    ctx->r4 = S32(SIGNED(ctx->r17) >> 28);
    // 0x8002983C: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x80029840: subu        $s3, $t7, $v0
    ctx->r19 = SUB32(ctx->r15, ctx->r2);
    // 0x80029844: subu        $s4, $t8, $v1
    ctx->r20 = SUB32(ctx->r24, ctx->r3);
    // 0x80029848: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8002984C: andi        $t8, $a0, 0x7
    ctx->r24 = ctx->r4 & 0X7;
    // 0x80029850: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x80029854: sll         $t7, $a3, 14
    ctx->r15 = S32(ctx->r7 << 14);
    // 0x80029858: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x8002985C: addu        $s6, $t4, $t9
    ctx->r22 = ADD32(ctx->r12, ctx->r25);
    // 0x80029860: beq         $t8, $zero, L_800298C4
    if (ctx->r24 == 0) {
        // 0x80029864: addu        $s7, $t5, $t6
        ctx->r23 = ADD32(ctx->r13, ctx->r14);
            goto L_800298C4;
    }
    // 0x80029864: addu        $s7, $t5, $t6
    ctx->r23 = ADD32(ctx->r13, ctx->r14);
    // 0x80029868: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x8002986C: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80029870: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x80029874: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x80029878: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8002987C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80029880: lw          $t3, -0x36E4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X36E4);
    // 0x80029884: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x80029888: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8002988C: lw          $v0, 0x70($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X70);
    // 0x80029890: nop

    // 0x80029894: lbu         $t9, 0x10($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X10);
    // 0x80029898: lbu         $t8, 0x13($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X13);
    // 0x8002989C: sll         $t3, $t9, 24
    ctx->r11 = S32(ctx->r25 << 24);
    // 0x800298A0: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    // 0x800298A4: or          $t5, $t8, $t3
    ctx->r13 = ctx->r24 | ctx->r11;
    // 0x800298A8: lbu         $t3, 0x12($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X12);
    // 0x800298AC: sll         $t4, $t7, 16
    ctx->r12 = S32(ctx->r15 << 16);
    // 0x800298B0: or          $t9, $t5, $t4
    ctx->r25 = ctx->r13 | ctx->r12;
    // 0x800298B4: sll         $t6, $t3, 8
    ctx->r14 = S32(ctx->r11 << 8);
    // 0x800298B8: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800298BC: b           L_800298E0
    // 0x800298C0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800298E0;
    // 0x800298C0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800298C4:
    // 0x800298C4: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x800298C8: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x800298CC: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x800298D0: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x800298D4: addiu       $t8, $zero, -0x100
    ctx->r24 = ADD32(0, -0X100);
    // 0x800298D8: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800298DC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
L_800298E0:
    // 0x800298E0: sll         $t3, $s1, 13
    ctx->r11 = S32(ctx->r17 << 13);
    // 0x800298E4: bgez        $t3, L_80029A00
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800298E8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80029A00;
    }
    // 0x800298E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800298EC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800298F0: lw          $t9, -0x36E4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X36E4);
    // 0x800298F4: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x800298F8: lw          $t6, 0xAC($t9)
    ctx->r14 = MEM_W(ctx->r25, 0XAC);
    // 0x800298FC: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80029900: lw          $t0, 0x8($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X8);
    // 0x80029904: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80029908: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x8002990C: sll         $t4, $v0, 24
    ctx->r12 = S32(ctx->r2 << 24);
    // 0x80029910: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80029914: or          $t3, $t4, $t8
    ctx->r11 = ctx->r12 | ctx->r24;
    // 0x80029918: sll         $t9, $v0, 8
    ctx->r25 = S32(ctx->r2 << 8);
    // 0x8002991C: or          $t6, $t3, $t9
    ctx->r14 = ctx->r11 | ctx->r25;
    // 0x80029920: or          $t7, $t6, $v0
    ctx->r15 = ctx->r14 | ctx->r2;
    // 0x80029924: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80029928: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8002992C: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80029930: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80029934: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x80029938: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002993C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80029940: jal         0x8007BA5C
    // 0x80029944: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    material_set_blinking_lights(rdram, ctx);
        goto after_1;
    // 0x80029944: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x80029948: addu        $v1, $s6, $fp
    ctx->r3 = ADD32(ctx->r22, ctx->r30);
    // 0x8002994C: addiu       $t4, $s3, -0x1
    ctx->r12 = ADD32(ctx->r19, -0X1);
    // 0x80029950: sll         $t8, $t4, 3
    ctx->r24 = S32(ctx->r12 << 3);
    // 0x80029954: andi        $t3, $v1, 0x6
    ctx->r11 = ctx->r3 & 0X6;
    // 0x80029958: or          $t9, $t8, $t3
    ctx->r25 = ctx->r24 | ctx->r11;
    // 0x8002995C: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80029960: sll         $t4, $s3, 3
    ctx->r12 = S32(ctx->r19 << 3);
    // 0x80029964: addu        $t8, $t4, $s3
    ctx->r24 = ADD32(ctx->r12, ctx->r19);
    // 0x80029968: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x8002996C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80029970: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x80029974: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80029978: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x8002997C: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x80029980: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80029984: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x80029988: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8002998C: or          $t5, $t7, $at
    ctx->r13 = ctx->r15 | ctx->r1;
    // 0x80029990: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80029994: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x80029998: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8002999C: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x800299A0: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x800299A4: addiu       $t8, $s4, -0x1
    ctx->r24 = ADD32(ctx->r20, -0X1);
    // 0x800299A8: sll         $t3, $t8, 4
    ctx->r11 = S32(ctx->r24 << 4);
    // 0x800299AC: ori         $t9, $t3, 0x1
    ctx->r25 = ctx->r11 | 0X1;
    // 0x800299B0: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x800299B4: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x800299B8: andi        $t5, $t9, 0xFF
    ctx->r13 = ctx->r25 & 0XFF;
    // 0x800299BC: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800299C0: sll         $t4, $s4, 4
    ctx->r12 = S32(ctx->r20 << 4);
    // 0x800299C4: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800299C8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800299CC: andi        $t8, $t4, 0xFFFF
    ctx->r24 = ctx->r12 & 0XFFFF;
    // 0x800299D0: or          $t3, $t7, $t8
    ctx->r11 = ctx->r15 | ctx->r24;
    // 0x800299D4: addu        $t9, $s7, $fp
    ctx->r25 = ADD32(ctx->r23, ctx->r30);
    // 0x800299D8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800299DC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800299E0: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x800299E4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800299E8: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x800299EC: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x800299F0: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800299F4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800299F8: b           L_80029AB8
    // 0x800299FC: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
        goto L_80029AB8;
    // 0x800299FC: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
L_80029A00:
    // 0x80029A00: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80029A04: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80029A08: sw          $t1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r9;
    // 0x80029A0C: jal         0x8007B4E8
    // 0x80029A10: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    material_set(rdram, ctx);
        goto after_2;
    // 0x80029A10: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    after_2:
    // 0x80029A14: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x80029A18: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80029A1C: bne         $s5, $zero, L_80029A28
    if (ctx->r21 != 0) {
        // 0x80029A20: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_80029A28;
    }
    // 0x80029A20: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80029A24: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80029A28:
    // 0x80029A28: addu        $v1, $s6, $fp
    ctx->r3 = ADD32(ctx->r22, ctx->r30);
    // 0x80029A2C: addiu       $t8, $s3, -0x1
    ctx->r24 = ADD32(ctx->r19, -0X1);
    // 0x80029A30: sll         $t3, $t8, 3
    ctx->r11 = S32(ctx->r24 << 3);
    // 0x80029A34: andi        $t9, $v1, 0x6
    ctx->r25 = ctx->r3 & 0X6;
    // 0x80029A38: or          $t5, $t3, $t9
    ctx->r13 = ctx->r11 | ctx->r25;
    // 0x80029A3C: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80029A40: sll         $t8, $s3, 3
    ctx->r24 = S32(ctx->r19 << 3);
    // 0x80029A44: addu        $t3, $t8, $s3
    ctx->r11 = ADD32(ctx->r24, ctx->r19);
    // 0x80029A48: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80029A4C: sll         $t4, $t6, 16
    ctx->r12 = S32(ctx->r14 << 16);
    // 0x80029A50: sll         $t9, $t3, 1
    ctx->r25 = S32(ctx->r11 << 1);
    // 0x80029A54: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80029A58: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80029A5C: addiu       $t5, $t9, 0x8
    ctx->r13 = ADD32(ctx->r25, 0X8);
    // 0x80029A60: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80029A64: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x80029A68: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x80029A6C: or          $t4, $t7, $t6
    ctx->r12 = ctx->r15 | ctx->r14;
    // 0x80029A70: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80029A74: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x80029A78: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80029A7C: addiu       $t3, $s4, -0x1
    ctx->r11 = ADD32(ctx->r20, -0X1);
    // 0x80029A80: sll         $t9, $t3, 4
    ctx->r25 = S32(ctx->r11 << 4);
    // 0x80029A84: or          $t5, $t9, $s1
    ctx->r13 = ctx->r25 | ctx->r17;
    // 0x80029A88: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80029A8C: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80029A90: andi        $t7, $t5, 0xFF
    ctx->r15 = ctx->r13 & 0XFF;
    // 0x80029A94: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80029A98: sll         $t8, $s4, 4
    ctx->r24 = S32(ctx->r20 << 4);
    // 0x80029A9C: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80029AA0: or          $t4, $t6, $at
    ctx->r12 = ctx->r14 | ctx->r1;
    // 0x80029AA4: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x80029AA8: or          $t9, $t4, $t3
    ctx->r25 = ctx->r12 | ctx->r11;
    // 0x80029AAC: addu        $t5, $s7, $fp
    ctx->r13 = ADD32(ctx->r23, ctx->r30);
    // 0x80029AB0: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x80029AB4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_80029AB8:
    extern void dkr_surface_interpolation_end(uint8_t*, recomp_context*); dkr_surface_interpolation_end(rdram, ctx);
    // 0x80029AB8: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
L_80029ABC:
    // 0x80029ABC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80029AC0: bne         $t1, $t7, L_8002972C
    if (ctx->r9 != ctx->r15) {
        // 0x80029AC4: addiu       $t2, $t2, 0xC
        ctx->r10 = ADD32(ctx->r10, 0XC);
            goto L_8002972C;
    }
    // 0x80029AC4: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
L_80029AC8:
    extern void dkr_level_segment_interpolation_end(uint8_t*, recomp_context*); dkr_level_segment_interpolation_end(rdram, ctx);
    // 0x80029AC8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80029ACC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80029AD0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80029AD4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80029AD8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80029ADC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80029AE0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80029AE4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80029AE8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80029AEC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80029AF0: jr          $ra
    // 0x80029AF4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80029AF4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void obj_loop_cameracontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039184: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80039188: jr          $ra
    // 0x8003918C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003918C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void mempool_slot_find(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070D3C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80070D40: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80070D44: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80070D48: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80070D4C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80070D50: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80070D54: jal         0x8006F510
    // 0x80070D58: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80070D58: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x80070D5C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80070D60: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80070D64: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80070D68: addiu       $t8, $t8, 0x3580
    ctx->r24 = ADD32(ctx->r24, 0X3580);
    // 0x80070D6C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80070D70: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80070D74: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80070D78: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80070D7C: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x80070D80: bne         $t2, $t3, L_80070D9C
    if (ctx->r10 != ctx->r11) {
        // 0x80070D84: andi        $t4, $s1, 0xF
        ctx->r12 = ctx->r17 & 0XF;
            goto L_80070D9C;
    }
    // 0x80070D84: andi        $t4, $s1, 0xF
    ctx->r12 = ctx->r17 & 0XF;
    // 0x80070D88: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80070D8C: jal         0x8006F53C
    // 0x80070D90: nop

    interrupts_enable(rdram, ctx);
        goto after_1;
    // 0x80070D90: nop

    after_1:
    // 0x80070D94: b           L_80070E7C
    // 0x80070D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80070E7C;
    // 0x80070D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80070D9C:
    // 0x80070D9C: beq         $t4, $zero, L_80070DB0
    if (ctx->r12 == 0) {
        // 0x80070DA0: addiu       $s0, $zero, -0x1
        ctx->r16 = ADD32(0, -0X1);
            goto L_80070DB0;
    }
    // 0x80070DA0: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80070DA4: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80070DA8: and         $t5, $s1, $at
    ctx->r13 = ctx->r17 & ctx->r1;
    // 0x80070DAC: addiu       $s1, $t5, 0x10
    ctx->r17 = ADD32(ctx->r13, 0X10);
L_80070DB0:
    // 0x80070DB0: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x80070DB4: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80070DB8: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80070DBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80070DC0: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80070DC4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80070DC8:
    // 0x80070DC8: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070DCC: mflo        $t6
    ctx->r14 = lo;
    // 0x80070DD0: addu        $v0, $t6, $t1
    ctx->r2 = ADD32(ctx->r14, ctx->r9);
    // 0x80070DD4: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x80070DD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80070DDC: bne         $t7, $zero, L_80070E08
    if (ctx->r15 != 0) {
        // 0x80070DE0: nop
    
            goto L_80070E08;
    }
    // 0x80070DE0: nop

    // 0x80070DE4: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80070DE8: nop

    // 0x80070DEC: slt         $at, $v1, $s1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80070DF0: bne         $at, $zero, L_80070E08
    if (ctx->r1 != 0) {
        // 0x80070DF4: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80070E08;
    }
    // 0x80070DF4: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80070DF8: beq         $at, $zero, L_80070E08
    if (ctx->r1 == 0) {
        // 0x80070DFC: nop
    
            goto L_80070E08;
    }
    // 0x80070DFC: nop

    // 0x80070E00: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80070E04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
L_80070E08:
    // 0x80070E08: lh          $a0, 0xC($a1)
    ctx->r4 = MEM_H(ctx->r5, 0XC);
    // 0x80070E0C: nop

    // 0x80070E10: bne         $a0, $a3, L_80070DC8
    if (ctx->r4 != ctx->r7) {
        // 0x80070E14: nop
    
            goto L_80070DC8;
    }
    // 0x80070E14: nop

    // 0x80070E18: beq         $s0, $a3, L_80070E6C
    if (ctx->r16 == ctx->r7) {
        // 0x80070E1C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80070E6C;
    }
    // 0x80070E1C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80070E20: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80070E24: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80070E28: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80070E2C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80070E30: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80070E34: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80070E38: jal         0x8007178C
    // 0x80070E3C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    mempool_slot_assign(rdram, ctx);
        goto after_2;
    // 0x80070E3C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_2:
    // 0x80070E40: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80070E44: jal         0x8006F53C
    // 0x80070E48: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x80070E48: nop

    after_3:
    // 0x80070E4C: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80070E50: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070E54: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80070E58: mflo        $t9
    ctx->r25 = lo;
    // 0x80070E5C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80070E60: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80070E64: b           L_80070E80
    // 0x80070E68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80070E80;
    // 0x80070E68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80070E6C:
    // 0x80070E6C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80070E70: jal         0x8006F53C
    // 0x80070E74: nop

    interrupts_enable(rdram, ctx);
        goto after_4;
    // 0x80070E74: nop

    after_4:
    // 0x80070E78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80070E7C:
    // 0x80070E7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80070E80:
    // 0x80070E80: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80070E84: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80070E88: jr          $ra
    // 0x80070E8C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80070E8C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void init_save_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081218: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008121C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081220: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80081224: jal         0x8006B224
    // 0x80081228: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    level_count(rdram, ctx);
        goto after_0;
    // 0x80081228: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x8008122C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80081230: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80081234: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80081238: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8008123C: addu        $v1, $t6, $t8
    ctx->r3 = ADD32(ctx->r14, ctx->r24);
    // 0x80081240: addiu       $v1, $v1, 0x11B
    ctx->r3 = ADD32(ctx->r3, 0X11B);
    // 0x80081244: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80081248: and         $t9, $v1, $at
    ctx->r25 = ctx->r3 & ctx->r1;
    // 0x8008124C: sll         $a0, $t9, 2
    ctx->r4 = S32(ctx->r25 << 2);
    // 0x80081250: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80081254: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80081258: jal         0x80070C9C
    // 0x8008125C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x8008125C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x80081260: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80081264: addiu       $a0, $a0, 0x6530
    ctx->r4 = ADD32(ctx->r4, 0X6530);
    // 0x80081268: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8008126C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081270: sw          $v0, 0x6530($at)
    MEM_W(0X6530, ctx->r1) = ctx->r2;
    // 0x80081274: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80081278: lw          $t1, 0x6530($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6530);
    // 0x8008127C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80081280: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80081284: addiu       $t2, $t1, 0x118
    ctx->r10 = ADD32(ctx->r9, 0X118);
    // 0x80081288: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008128C: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x80081290: lw          $t3, 0x6530($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6530);
    // 0x80081294: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80081298: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8008129C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800812A0: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800812A4: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x800812A8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800812AC: addu        $v1, $a3, $a3
    ctx->r3 = ADD32(ctx->r7, ctx->r7);
    // 0x800812B0: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x800812B4: sw          $t7, 0x6534($at)
    MEM_W(0X6534, ctx->r1) = ctx->r15;
    // 0x800812B8: lw          $t8, 0x6534($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6534);
    // 0x800812BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800812C0: addiu       $t9, $t8, 0x118
    ctx->r25 = ADD32(ctx->r24, 0X118);
    // 0x800812C4: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x800812C8: lw          $t0, 0x6534($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6534);
    // 0x800812CC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800812D0: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x800812D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800812D8: addu        $t1, $t2, $a2
    ctx->r9 = ADD32(ctx->r10, ctx->r6);
    // 0x800812DC: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x800812E0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800812E4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800812E8: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x800812EC: sw          $t5, 0x6538($at)
    MEM_W(0X6538, ctx->r1) = ctx->r13;
    // 0x800812F0: lw          $t3, 0x6538($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6538);
    // 0x800812F4: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800812F8: addiu       $t6, $t3, 0x118
    ctx->r14 = ADD32(ctx->r11, 0X118);
    // 0x800812FC: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x80081300: lw          $t7, 0x6538($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6538);
    // 0x80081304: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80081308: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x8008130C: nop

    // 0x80081310: addu        $t8, $t9, $a2
    ctx->r24 = ADD32(ctx->r25, ctx->r6);
    // 0x80081314: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x80081318: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8008131C: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    // 0x80081320: addu        $t1, $t2, $v1
    ctx->r9 = ADD32(ctx->r10, ctx->r3);
    // 0x80081324: sw          $t1, 0x653C($at)
    MEM_W(0X653C, ctx->r1) = ctx->r9;
    // 0x80081328: lw          $t0, 0x653C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X653C);
    // 0x8008132C: nop

    // 0x80081330: addiu       $t4, $t0, 0x118
    ctx->r12 = ADD32(ctx->r8, 0X118);
    // 0x80081334: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x80081338: lw          $t5, 0x653C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X653C);
    // 0x8008133C: nop

    // 0x80081340: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80081344: nop

    // 0x80081348: addu        $t3, $t6, $a2
    ctx->r11 = ADD32(ctx->r14, ctx->r6);
    // 0x8008134C: jal         0x8001E29C
    // 0x80081350: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    get_misc_asset(rdram, ctx);
        goto after_2;
    // 0x80081350: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    after_2:
    // 0x80081354: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80081358: addiu       $v1, $v1, 0x6C30
    ctx->r3 = ADD32(ctx->r3, 0X6C30);
    // 0x8008135C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80081360: lhu         $t8, 0x0($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X0);
    // 0x80081364: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081368: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    // 0x8008136C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80081370: jal         0x80070C9C
    // 0x80081374: sw          $t8, 0x6C38($at)
    MEM_W(0X6C38, ctx->r1) = ctx->r24;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x80081374: sw          $t8, 0x6C38($at)
    MEM_W(0X6C38, ctx->r1) = ctx->r24;
    after_3:
    // 0x80081378: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008137C: sw          $v0, -0xB60($at)
    MEM_W(-0XB60, ctx->r1) = ctx->r2;
    // 0x80081380: jal         0x8007F900
    // 0x80081384: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    load_menu_text(rdram, ctx);
        goto after_4;
    // 0x80081384: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80081388: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008138C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80081390: addiu       $v1, $v1, 0x6750
    ctx->r3 = ADD32(ctx->r3, 0X6750);
    // 0x80081394: addiu       $v0, $v0, 0x6550
    ctx->r2 = ADD32(ctx->r2, 0X6550);
L_80081398:
    // 0x80081398: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8008139C: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x800813A0: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x800813A4: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x800813A8: bne         $v0, $v1, L_80081398
    if (ctx->r2 != ctx->r3) {
        // 0x800813AC: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_80081398;
    }
    // 0x800813AC: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x800813B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800813B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800813B8: jr          $ra
    // 0x800813BC: nop

    return;
    // 0x800813BC: nop

;}
RECOMP_FUNC void input_get_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072254: beq         $a0, $zero, L_80072268
    if (ctx->r4 == 0) {
        // 0x80072258: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80072268;
    }
    // 0x80072258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007225C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80072260: bne         $a0, $at, L_80072280
    if (ctx->r4 != ctx->r1) {
        // 0x80072264: nop
    
            goto L_80072280;
    }
    // 0x80072264: nop

L_80072268:
    // 0x80072268: jal         0x8000E158
    // 0x8007226C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_race_started_by_player_two(rdram, ctx);
        goto after_0;
    // 0x8007226C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80072270: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80072274: beq         $v0, $zero, L_80072280
    if (ctx->r2 == 0) {
        // 0x80072278: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80072280;
    }
    // 0x80072278: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007227C: subu        $a0, $t6, $a0
    ctx->r4 = SUB32(ctx->r14, ctx->r4);
L_80072280:
    // 0x80072280: jal         0x8006A4F8
    // 0x80072284: nop

    input_player_id(rdram, ctx);
        goto after_1;
    // 0x80072284: nop

    after_1:
    // 0x80072288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007228C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072290: jr          $ra
    // 0x80072294: nop

    return;
    // 0x80072294: nop

;}
RECOMP_FUNC void func_8001E4C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E4C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8001E4C8: addiu       $t0, $t0, -0x51A4
    ctx->r8 = ADD32(ctx->r8, -0X51A4);
    // 0x8001E4CC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001E4D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E4D4: blez        $v1, L_8001E524
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E4D8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001E524;
    }
    // 0x8001E4D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001E4DC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001E4E0: addiu       $t1, $t1, -0x51A8
    ctx->r9 = ADD32(ctx->r9, -0X51A8);
    // 0x8001E4E4: addiu       $a2, $zero, -0x2001
    ctx->r6 = ADD32(0, -0X2001);
L_8001E4E8:
    // 0x8001E4E8: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8001E4EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E4F0: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8001E4F4: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x8001E4F8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001E4FC: lh          $t8, 0x6($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X6);
    // 0x8001E500: nop

    // 0x8001E504: and         $t9, $t8, $a2
    ctx->r25 = ctx->r24 & ctx->r6;
    // 0x8001E508: sh          $t9, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r25;
    // 0x8001E50C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001E510: nop

    // 0x8001E514: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E518: bne         $at, $zero, L_8001E4E8
    if (ctx->r1 != 0) {
        // 0x8001E51C: nop
    
            goto L_8001E4E8;
    }
    // 0x8001E51C: nop

    // 0x8001E520: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001E524:
    // 0x8001E524: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001E528: blez        $v1, L_8001E5DC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E52C: addiu       $t1, $t1, -0x51A8
        ctx->r9 = ADD32(ctx->r9, -0X51A8);
            goto L_8001E5DC;
    }
    // 0x8001E52C: addiu       $t1, $t1, -0x51A8
    ctx->r9 = ADD32(ctx->r9, -0X51A8);
    // 0x8001E530: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001E534: addiu       $t3, $t3, -0x5186
    ctx->r11 = ADD32(ctx->r11, -0X5186);
    // 0x8001E538: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001E53C: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x8001E540: addiu       $t2, $zero, 0x31
    ctx->r10 = ADD32(0, 0X31);
L_8001E544:
    // 0x8001E544: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8001E548: nop

    // 0x8001E54C: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x8001E550: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8001E554: nop

    // 0x8001E558: beq         $a1, $zero, L_8001E5C4
    if (ctx->r5 == 0) {
        // 0x8001E55C: nop
    
            goto L_8001E5C4;
    }
    // 0x8001E55C: nop

    // 0x8001E560: lh          $v1, 0x6($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X6);
    // 0x8001E564: nop

    // 0x8001E568: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
    // 0x8001E56C: bne         $t7, $zero, L_8001E5C4
    if (ctx->r15 != 0) {
        // 0x8001E570: nop
    
            goto L_8001E5C4;
    }
    // 0x8001E570: nop

    // 0x8001E574: lh          $t8, 0x48($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X48);
    // 0x8001E578: nop

    // 0x8001E57C: bne         $t2, $t8, L_8001E5C4
    if (ctx->r10 != ctx->r24) {
        // 0x8001E580: nop
    
            goto L_8001E5C4;
    }
    // 0x8001E580: nop

    // 0x8001E584: lw          $a2, 0x3C($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X3C);
    // 0x8001E588: lh          $t9, 0x0($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X0);
    // 0x8001E58C: lb          $a3, 0x21($a2)
    ctx->r7 = MEM_B(ctx->r6, 0X21);
    // 0x8001E590: nop

    // 0x8001E594: beq         $t9, $a3, L_8001E5C4
    if (ctx->r25 == ctx->r7) {
        // 0x8001E598: nop
    
            goto L_8001E5C4;
    }
    // 0x8001E598: nop

    // 0x8001E59C: beq         $t4, $a3, L_8001E5C4
    if (ctx->r12 == ctx->r7) {
        // 0x8001E5A0: nop
    
            goto L_8001E5C4;
    }
    // 0x8001E5A0: nop

    // 0x8001E5A4: lw          $a2, 0x64($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X64);
    // 0x8001E5A8: ori         $t5, $v1, 0x2000
    ctx->r13 = ctx->r3 | 0X2000;
    // 0x8001E5AC: beq         $a2, $zero, L_8001E5C4
    if (ctx->r6 == 0) {
        // 0x8001E5B0: sh          $t5, 0x6($a1)
        MEM_H(0X6, ctx->r5) = ctx->r13;
            goto L_8001E5C4;
    }
    // 0x8001E5B0: sh          $t5, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r13;
    // 0x8001E5B4: lh          $t6, 0x6($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X6);
    // 0x8001E5B8: nop

    // 0x8001E5BC: ori         $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 | 0X2000;
    // 0x8001E5C0: sh          $t7, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r15;
L_8001E5C4:
    // 0x8001E5C4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001E5C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E5CC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E5D0: bne         $at, $zero, L_8001E544
    if (ctx->r1 != 0) {
        // 0x8001E5D4: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8001E544;
    }
    // 0x8001E5D4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001E5D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001E5DC:
    // 0x8001E5DC: addiu       $a2, $v1, -0x1
    ctx->r6 = ADD32(ctx->r3, -0X1);
    // 0x8001E5E0: bltz        $a2, L_8001E6D8
    if (SIGNED(ctx->r6) < 0) {
        // 0x8001E5E4: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_8001E6D8;
    }
    // 0x8001E5E4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8001E5E8: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
L_8001E5EC:
    // 0x8001E5EC: bne         $at, $zero, L_8001E640
    if (ctx->r1 != 0) {
        // 0x8001E5F0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001E640;
    }
    // 0x8001E5F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001E5F4: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8001E5F8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8001E5FC: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
L_8001E600:
    // 0x8001E600: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8001E604: nop

    // 0x8001E608: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x8001E60C: nop

    // 0x8001E610: andi        $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 & 0X2000;
    // 0x8001E614: beq         $t7, $zero, L_8001E628
    if (ctx->r15 == 0) {
        // 0x8001E618: nop
    
            goto L_8001E628;
    }
    // 0x8001E618: nop

    // 0x8001E61C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E620: b           L_8001E62C
    // 0x8001E624: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
        goto L_8001E62C;
    // 0x8001E624: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_8001E628:
    // 0x8001E628: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8001E62C:
    // 0x8001E62C: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001E630: bne         $at, $zero, L_8001E640
    if (ctx->r1 != 0) {
        // 0x8001E634: nop
    
            goto L_8001E640;
    }
    // 0x8001E634: nop

    // 0x8001E638: beq         $v1, $zero, L_8001E600
    if (ctx->r3 == 0) {
        // 0x8001E63C: nop
    
            goto L_8001E600;
    }
    // 0x8001E63C: nop

L_8001E640:
    // 0x8001E640: bltz        $a2, L_8001E690
    if (SIGNED(ctx->r6) < 0) {
        // 0x8001E644: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001E690;
    }
    // 0x8001E644: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001E648: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8001E64C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8001E650: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
L_8001E654:
    // 0x8001E654: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8001E658: nop

    // 0x8001E65C: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x8001E660: nop

    // 0x8001E664: andi        $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 & 0X2000;
    // 0x8001E668: beq         $t7, $zero, L_8001E678
    if (ctx->r15 == 0) {
        // 0x8001E66C: nop
    
            goto L_8001E678;
    }
    // 0x8001E66C: nop

    // 0x8001E670: b           L_8001E680
    // 0x8001E674: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_8001E680;
    // 0x8001E674: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8001E678:
    // 0x8001E678: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001E67C: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
L_8001E680:
    // 0x8001E680: bltz        $a2, L_8001E694
    if (SIGNED(ctx->r6) < 0) {
        // 0x8001E684: slt         $at, $v0, $a2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001E694;
    }
    // 0x8001E684: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001E688: beq         $v1, $zero, L_8001E654
    if (ctx->r3 == 0) {
        // 0x8001E68C: nop
    
            goto L_8001E654;
    }
    // 0x8001E68C: nop

L_8001E690:
    // 0x8001E690: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
L_8001E694:
    // 0x8001E694: beq         $at, $zero, L_8001E6CC
    if (ctx->r1 == 0) {
        // 0x8001E698: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_8001E6CC;
    }
    // 0x8001E698: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8001E69C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8001E6A0: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8001E6A4: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x8001E6A8: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x8001E6AC: addu        $a0, $v1, $t8
    ctx->r4 = ADD32(ctx->r3, ctx->r24);
    // 0x8001E6B0: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8001E6B4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8001E6B8: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8001E6BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E6C0: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x8001E6C4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001E6C8: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
L_8001E6CC:
    // 0x8001E6CC: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001E6D0: beq         $at, $zero, L_8001E5EC
    if (ctx->r1 == 0) {
        // 0x8001E6D4: slt         $at, $a3, $v0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001E5EC;
    }
    // 0x8001E6D4: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
L_8001E6D8:
    // 0x8001E6D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E6DC: sw          $v0, -0x51A0($at)
    MEM_W(-0X51A0, ctx->r1) = ctx->r2;
    // 0x8001E6E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E6E4: jr          $ra
    // 0x8001E6E8: sh          $zero, -0x5184($at)
    MEM_H(-0X5184, ctx->r1) = 0;
    return;
    // 0x8001E6E8: sh          $zero, -0x5184($at)
    MEM_H(-0X5184, ctx->r1) = 0;
;}
RECOMP_FUNC void obj_init_dino_whale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800391C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800391CC: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x800391D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800391D4: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x800391D8: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x800391DC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800391E0: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x800391E4: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x800391E8: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x800391EC: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x800391F0: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x800391F4: jr          $ra
    // 0x800391F8: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    return;
    // 0x800391F8: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
;}
RECOMP_FUNC void set_player_selected_vehicle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C264: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009C268: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8009C26C: jr          $ra
    // 0x8009C270: sb          $a1, 0x69C0($at)
    MEM_B(0X69C0, ctx->r1) = ctx->r5;
    return;
    // 0x8009C270: sb          $a1, 0x69C0($at)
    MEM_B(0X69C0, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void sprintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4A14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B4A18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B4A1C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800B4A20: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800B4A24: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800B4A28: jal         0x800B4A40
    // 0x800B4A2C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    vsprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800B4A2C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800B4A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B4A34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B4A38: jr          $ra
    // 0x800B4A3C: nop

    return;
    // 0x800B4A3C: nop

;}
RECOMP_FUNC void pakmenu_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088938: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8008893C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80088940: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80088944: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x80088948: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x8008894C: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80088950: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80088954: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80088958: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8008895C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80088960: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80088964: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80088968: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008896C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088970: jal         0x800C43CC
    // 0x80088974: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_0;
    // 0x80088974: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80088978: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8008897C: lw          $s6, 0x63BC($s6)
    ctx->r22 = MEM_W(ctx->r22, 0X63BC);
    // 0x80088980: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80088984: sll         $t6, $s6, 3
    ctx->r14 = S32(ctx->r22 << 3);
    // 0x80088988: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x8008898C: bne         $at, $zero, L_8008899C
    if (ctx->r1 != 0) {
        // 0x80088990: or          $s6, $t6, $zero
        ctx->r22 = ctx->r14 | 0;
            goto L_8008899C;
    }
    // 0x80088990: or          $s6, $t6, $zero
    ctx->r22 = ctx->r14 | 0;
    // 0x80088994: addiu       $t7, $zero, 0x1FF
    ctx->r15 = ADD32(0, 0X1FF);
    // 0x80088998: subu        $s6, $t7, $t6
    ctx->r22 = SUB32(ctx->r15, ctx->r14);
L_8008899C:
    // 0x8008899C: lw          $t8, 0x6BC8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6BC8);
    // 0x800889A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800889A4: beq         $t8, $zero, L_800889C4
    if (ctx->r24 == 0) {
        // 0x800889A8: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800889C4;
    }
    // 0x800889A8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800889AC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800889B0: addiu       $a1, $a1, -0x34C
    ctx->r5 = ADD32(ctx->r5, -0X34C);
    // 0x800889B4: jal         0x800821EC
    // 0x800889B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    draw_menu_elements(rdram, ctx);
        goto after_1;
    // 0x800889B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x800889BC: b           L_80089084
    // 0x800889C0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80089084;
    // 0x800889C0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800889C4:
    // 0x800889C4: lw          $t9, -0x26C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X26C);
    // 0x800889C8: nop

    // 0x800889CC: beq         $t9, $zero, L_80089084
    if (ctx->r25 == 0) {
        // 0x800889D0: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80089084;
    }
    // 0x800889D0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800889D4: jal         0x800C42EC
    // 0x800889D8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_2;
    // 0x800889D8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x800889DC: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x800889E0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800889E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800889E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800889EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800889F0: jal         0x800C4384
    // 0x800889F4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_3;
    // 0x800889F4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x800889F8: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800889FC: addiu       $s7, $s7, -0xB60
    ctx->r23 = ADD32(ctx->r23, -0XB60);
    // 0x80088A00: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x80088A04: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088A08: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80088A0C: lw          $a3, 0x8C($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X8C);
    // 0x80088A10: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80088A14: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80088A18: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x80088A1C: jal         0x800C4440
    // 0x80088A20: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    draw_text(rdram, ctx);
        goto after_4;
    // 0x80088A20: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    after_4:
    // 0x80088A24: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80088A28: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80088A2C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80088A30: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80088A34: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80088A38: jal         0x800C4384
    // 0x80088A3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_5;
    // 0x80088A3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80088A40: lw          $t4, 0x0($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X0);
    // 0x80088A44: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088A48: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80088A4C: lw          $a3, 0x8C($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X8C);
    // 0x80088A50: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80088A54: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80088A58: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80088A5C: jal         0x800C4440
    // 0x80088A60: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    draw_text(rdram, ctx);
        goto after_6;
    // 0x80088A60: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_6:
    // 0x80088A64: addiu       $s5, $zero, 0x30
    ctx->r21 = ADD32(0, 0X30);
    // 0x80088A68: jal         0x800C5494
    // 0x80088A6C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_7;
    // 0x80088A6C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_7:
    // 0x80088A70: addiu       $t6, $s5, 0x1E
    ctx->r14 = ADD32(ctx->r21, 0X1E);
    // 0x80088A74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80088A78: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088A7C: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x80088A80: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80088A84: jal         0x800C4EDC
    // 0x80088A88: addiu       $a3, $zero, 0x106
    ctx->r7 = ADD32(0, 0X106);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_8;
    // 0x80088A88: addiu       $a3, $zero, 0x106
    ctx->r7 = ADD32(0, 0X106);
    after_8:
    // 0x80088A8C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80088A90: lw          $t7, -0xBA0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XBA0);
    // 0x80088A94: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80088A98: bne         $t7, $at, L_80088AC4
    if (ctx->r15 != ctx->r1) {
        // 0x80088A9C: sra         $t8, $s6, 1
        ctx->r24 = S32(SIGNED(ctx->r22) >> 1);
            goto L_80088AC4;
    }
    // 0x80088A9C: sra         $t8, $s6, 1
    ctx->r24 = S32(SIGNED(ctx->r22) >> 1);
    // 0x80088AA0: addiu       $t9, $t8, 0x80
    ctx->r25 = ADD32(ctx->r24, 0X80);
    // 0x80088AA4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80088AA8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088AAC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80088AB0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80088AB4: jal         0x800C4FBC
    // 0x80088AB8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_9;
    // 0x80088AB8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_9:
    // 0x80088ABC: b           L_80088AE4
    // 0x80088AC0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
        goto L_80088AE4;
    // 0x80088AC0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_80088AC4:
    // 0x80088AC4: addiu       $t0, $zero, 0xE0
    ctx->r8 = ADD32(0, 0XE0);
    // 0x80088AC8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80088ACC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088AD0: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x80088AD4: addiu       $a2, $zero, 0xC0
    ctx->r6 = ADD32(0, 0XC0);
    // 0x80088AD8: jal         0x800C4FBC
    // 0x80088ADC: addiu       $a3, $zero, 0x5C
    ctx->r7 = ADD32(0, 0X5C);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_10;
    // 0x80088ADC: addiu       $a3, $zero, 0x5C
    ctx->r7 = ADD32(0, 0X5C);
    after_10:
    // 0x80088AE0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_80088AE4:
    // 0x80088AE4: jal         0x800C4F7C
    // 0x80088AE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_11;
    // 0x80088AE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80088AEC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80088AF0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80088AF4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088AF8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80088AFC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80088B00: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80088B04: jal         0x800C5000
    // 0x80088B08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_12;
    // 0x80088B08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_12:
    // 0x80088B0C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088B14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088B18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80088B1C: jal         0x800C5050
    // 0x80088B20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_13;
    // 0x80088B20: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_13:
    // 0x80088B24: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80088B28: lw          $t3, 0x6A68($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6A68);
    // 0x80088B2C: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
    // 0x80088B30: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80088B34: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80088B38: lw          $a3, 0x158($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X158);
    // 0x80088B3C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80088B40: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80088B44: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80088B48: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80088B4C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088B50: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80088B54: jal         0x800C5168
    // 0x80088B58: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    render_dialogue_text(rdram, ctx);
        goto after_14;
    // 0x80088B58: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_14:
    // 0x80088B5C: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x80088B60: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80088B64: lw          $t9, 0x6BB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6BB0);
    // 0x80088B68: lw          $a3, 0x1C8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X1C8);
    // 0x80088B6C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80088B70: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80088B74: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088B78: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80088B7C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80088B80: jal         0x800C5168
    // 0x80088B84: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    render_dialogue_text(rdram, ctx);
        goto after_15;
    // 0x80088B84: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_15:
    // 0x80088B88: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088B8C: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80088B90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088B94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088B98: jal         0x800C5B58
    // 0x80088B9C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    render_dialogue_box(rdram, ctx);
        goto after_16;
    // 0x80088B9C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_16:
    // 0x80088BA0: addiu       $s5, $s5, 0x22
    ctx->r21 = ADD32(ctx->r21, 0X22);
    // 0x80088BA4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088BA8: jal         0x800C4F7C
    // 0x80088BAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    set_dialogue_font(rdram, ctx);
        goto after_17;
    // 0x80088BAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80088BB0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088BB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088BB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088BBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80088BC0: jal         0x800C5050
    // 0x80088BC4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_18;
    // 0x80088BC4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_18:
    // 0x80088BC8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80088BCC: lw          $v0, 0x6BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6BB4);
    // 0x80088BD0: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80088BD4: bltz        $v0, L_80088DB4
    if (SIGNED(ctx->r2) < 0) {
        // 0x80088BD8: nop
    
            goto L_80088DB4;
    }
    // 0x80088BD8: nop

L_80088BDC:
    // 0x80088BDC: jal         0x800C5494
    // 0x80088BE0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_19;
    // 0x80088BE0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_19:
    // 0x80088BE4: addiu       $t1, $s5, 0xE
    ctx->r9 = ADD32(ctx->r21, 0XE);
    // 0x80088BE8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80088BEC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088BF0: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80088BF4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80088BF8: jal         0x800C4EDC
    // 0x80088BFC: addiu       $a3, $zero, 0x124
    ctx->r7 = ADD32(0, 0X124);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_20;
    // 0x80088BFC: addiu       $a3, $zero, 0x124
    ctx->r7 = ADD32(0, 0X124);
    after_20:
    // 0x80088C00: bgez        $s1, L_80088C6C
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80088C04: lui         $t6, 0x800F
        ctx->r14 = S32(0X800F << 16);
            goto L_80088C6C;
    }
    // 0x80088C04: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x80088C08: addiu       $t3, $zero, 0xE0
    ctx->r11 = ADD32(0, 0XE0);
    // 0x80088C0C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80088C10: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088C14: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x80088C18: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80088C1C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x80088C20: jal         0x800C4FBC
    // 0x80088C24: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_21;
    // 0x80088C24: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    after_21:
    // 0x80088C28: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80088C2C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80088C30: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80088C34: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80088C38: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088C3C: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x80088C40: addiu       $a2, $zero, 0xE0
    ctx->r6 = ADD32(0, 0XE0);
    // 0x80088C44: jal         0x800C5000
    // 0x80088C48: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    set_current_text_colour(rdram, ctx);
        goto after_22;
    // 0x80088C48: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_22:
    // 0x80088C4C: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80088C50: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80088C54: lw          $t5, 0x63D8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X63D8);
    // 0x80088C58: lw          $s2, 0x1CC($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X1CC);
    // 0x80088C5C: lw          $s0, 0x1D0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X1D0);
    // 0x80088C60: lw          $s4, 0x1D4($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X1D4);
    // 0x80088C64: b           L_80088D20
    // 0x80088C68: addu        $v1, $s1, $t5
    ctx->r3 = ADD32(ctx->r17, ctx->r13);
        goto L_80088D20;
    // 0x80088C68: addu        $v1, $s1, $t5
    ctx->r3 = ADD32(ctx->r17, ctx->r13);
L_80088C6C:
    // 0x80088C6C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80088C70: lw          $t8, 0x63D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X63D8);
    // 0x80088C74: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80088C78: lw          $t7, -0xBA0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XBA0);
    // 0x80088C7C: addiu       $s4, $t6, -0x7DF4
    ctx->r20 = ADD32(ctx->r14, -0X7DF4);
    // 0x80088C80: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x80088C84: bne         $t7, $t9, L_80088CB4
    if (ctx->r15 != ctx->r25) {
        // 0x80088C88: or          $s2, $s4, $zero
        ctx->r18 = ctx->r20 | 0;
            goto L_80088CB4;
    }
    // 0x80088C88: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    // 0x80088C8C: sra         $t0, $s6, 1
    ctx->r8 = S32(SIGNED(ctx->r22) >> 1);
    // 0x80088C90: addiu       $t1, $t0, 0x80
    ctx->r9 = ADD32(ctx->r8, 0X80);
    // 0x80088C94: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80088C98: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088C9C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80088CA0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80088CA4: jal         0x800C4FBC
    // 0x80088CA8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_23;
    // 0x80088CA8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_23:
    // 0x80088CAC: b           L_80088CD4
    // 0x80088CB0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
        goto L_80088CD4;
    // 0x80088CB0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
L_80088CB4:
    // 0x80088CB4: addiu       $t3, $zero, 0xE0
    ctx->r11 = ADD32(0, 0XE0);
    // 0x80088CB8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80088CBC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088CC0: addiu       $a1, $zero, 0xE0
    ctx->r5 = ADD32(0, 0XE0);
    // 0x80088CC4: addiu       $a2, $zero, 0xE0
    ctx->r6 = ADD32(0, 0XE0);
    // 0x80088CC8: jal         0x800C4FBC
    // 0x80088CCC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_24;
    // 0x80088CCC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_24:
    // 0x80088CD0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
L_80088CD4:
    // 0x80088CD4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80088CD8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80088CDC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80088CE0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088CE4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80088CE8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80088CEC: jal         0x800C5000
    // 0x80088CF0: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    set_current_text_colour(rdram, ctx);
        goto after_25;
    // 0x80088CF0: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
    after_25:
    // 0x80088CF4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80088CF8: lw          $t5, 0x63D8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X63D8);
    // 0x80088CFC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80088D00: addu        $v1, $t5, $s1
    ctx->r3 = ADD32(ctx->r13, ctx->r17);
    // 0x80088D04: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80088D08: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80088D0C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80088D10: addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x80088D14: lw          $s0, 0x6AA0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6AA0);
    // 0x80088D18: lw          $s3, 0x6B70($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X6B70);
    // 0x80088D1C: nop

L_80088D20:
    // 0x80088D20: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80088D24: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80088D28: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80088D2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80088D30: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088D34: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x80088D38: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80088D3C: jal         0x800C5168
    // 0x80088D40: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_26;
    // 0x80088D40: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_26:
    // 0x80088D44: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80088D48: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80088D4C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088D50: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x80088D54: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80088D58: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80088D5C: jal         0x800C5168
    // 0x80088D60: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    render_dialogue_text(rdram, ctx);
        goto after_27;
    // 0x80088D60: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_27:
    // 0x80088D64: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80088D68: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80088D6C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088D70: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // 0x80088D74: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80088D78: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80088D7C: jal         0x800C5168
    // 0x80088D80: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    render_dialogue_text(rdram, ctx);
        goto after_28;
    // 0x80088D80: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    after_28:
    // 0x80088D84: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088D88: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80088D8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088D90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088D94: jal         0x800C5B58
    // 0x80088D98: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    render_dialogue_box(rdram, ctx);
        goto after_29;
    // 0x80088D98: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_29:
    // 0x80088D9C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80088DA0: lw          $v0, 0x6BB4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6BB4);
    // 0x80088DA4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80088DA8: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80088DAC: bne         $at, $zero, L_80088BDC
    if (ctx->r1 != 0) {
        // 0x80088DB0: addiu       $s5, $s5, 0x10
        ctx->r21 = ADD32(ctx->r21, 0X10);
            goto L_80088BDC;
    }
    // 0x80088DB0: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
L_80088DB4:
    // 0x80088DB4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80088DB8: lw          $t0, 0x63D8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X63D8);
    // 0x80088DBC: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
    // 0x80088DC0: subu        $t1, $s0, $v0
    ctx->r9 = SUB32(ctx->r16, ctx->r2);
    // 0x80088DC4: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80088DC8: beq         $at, $zero, L_80088E2C
    if (ctx->r1 == 0) {
        // 0x80088DCC: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_80088E2C;
    }
    // 0x80088DCC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80088DD0: lw          $t3, 0x63BC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X63BC);
    // 0x80088DD4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088DD8: andi        $t2, $t3, 0x8
    ctx->r10 = ctx->r11 & 0X8;
    // 0x80088DDC: beq         $t2, $zero, L_80088EA4
    if (ctx->r10 == 0) {
        // 0x80088DE0: addiu       $a0, $a0, 0x63A0
        ctx->r4 = ADD32(ctx->r4, 0X63A0);
            goto L_80088EA4;
    }
    // 0x80088DE0: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80088DE4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80088DE8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80088DEC: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80088DF0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80088DF4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80088DF8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80088DFC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80088E00: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80088E04: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80088E08: addiu       $a1, $a1, 0x43C
    ctx->r5 = ADD32(ctx->r5, 0X43C);
    // 0x80088E0C: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x80088E10: jal         0x80078AB8
    // 0x80088E14: addiu       $a3, $s5, 0x8
    ctx->r7 = ADD32(ctx->r21, 0X8);
    texrect_draw(rdram, ctx);
        goto after_30;
    // 0x80088E14: addiu       $a3, $s5, 0x8
    ctx->r7 = ADD32(ctx->r21, 0X8);
    after_30:
    // 0x80088E18: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088E1C: jal         0x8007B3D0
    // 0x80088E20: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    rendermode_reset(rdram, ctx);
        goto after_31;
    // 0x80088E20: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    after_31:
    // 0x80088E24: b           L_80088EA4
    // 0x80088E28: nop

        goto L_80088EA4;
    // 0x80088E28: nop

L_80088E2C:
    // 0x80088E2C: jal         0x800C42EC
    // 0x80088E30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_32;
    // 0x80088E30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_32:
    // 0x80088E34: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80088E38: lw          $t7, -0xBA0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XBA0);
    // 0x80088E3C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80088E40: bne         $s0, $t7, L_80088E6C
    if (ctx->r16 != ctx->r15) {
        // 0x80088E44: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80088E6C;
    }
    // 0x80088E44: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80088E48: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80088E4C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80088E50: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80088E54: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80088E58: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80088E5C: jal         0x800C4384
    // 0x80088E60: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    set_text_colour(rdram, ctx);
        goto after_33;
    // 0x80088E60: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_33:
    // 0x80088E64: b           L_80088E84
    // 0x80088E68: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
        goto L_80088E84;
    // 0x80088E68: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
L_80088E6C:
    // 0x80088E6C: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80088E70: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80088E74: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80088E78: jal         0x800C4384
    // 0x80088E7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_34;
    // 0x80088E7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_34:
    // 0x80088E80: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
L_80088E84:
    // 0x80088E84: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088E88: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80088E8C: lw          $a3, 0xCC($t1)
    ctx->r7 = MEM_W(ctx->r9, 0XCC);
    // 0x80088E90: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80088E94: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80088E98: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80088E9C: jal         0x800C4440
    // 0x80088EA0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    draw_text(rdram, ctx);
        goto after_35;
    // 0x80088EA0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_35:
L_80088EA4:
    // 0x80088EA4: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80088EA8: addiu       $s3, $s3, 0x63E0
    ctx->r19 = ADD32(ctx->r19, 0X63E0);
    // 0x80088EAC: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80088EB0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80088EB4: beq         $t2, $zero, L_8008902C
    if (ctx->r10 == 0) {
        // 0x80088EB8: nop
    
            goto L_8008902C;
    }
    // 0x80088EB8: nop

    // 0x80088EBC: lw          $t4, 0x6C10($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6C10);
    // 0x80088EC0: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x80088EC4: bne         $t4, $zero, L_8008902C
    if (ctx->r12 != 0) {
        // 0x80088EC8: nop
    
            goto L_8008902C;
    }
    // 0x80088EC8: nop

    // 0x80088ECC: lw          $t5, 0x300($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X300);
    // 0x80088ED0: addiu       $s5, $zero, 0x78
    ctx->r21 = ADD32(0, 0X78);
    // 0x80088ED4: bne         $t5, $zero, L_80088EE4
    if (ctx->r13 != 0) {
        // 0x80088ED8: nop
    
            goto L_80088EE4;
    }
    // 0x80088ED8: nop

    // 0x80088EDC: b           L_80088EE4
    // 0x80088EE0: addiu       $s5, $zero, 0x86
    ctx->r21 = ADD32(0, 0X86);
        goto L_80088EE4;
    // 0x80088EE0: addiu       $s5, $zero, 0x86
    ctx->r21 = ADD32(0, 0X86);
L_80088EE4:
    // 0x80088EE4: jal         0x800C5494
    // 0x80088EE8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_36;
    // 0x80088EE8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_36:
    // 0x80088EEC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088EF0: jal         0x800C4F7C
    // 0x80088EF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_37;
    // 0x80088EF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_37:
    // 0x80088EF8: addiu       $t6, $s5, 0x1C
    ctx->r14 = ADD32(ctx->r21, 0X1C);
    // 0x80088EFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80088F00: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088F04: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x80088F08: addiu       $a2, $s5, -0x1C
    ctx->r6 = ADD32(ctx->r21, -0X1C);
    // 0x80088F0C: jal         0x800C4EDC
    // 0x80088F10: addiu       $a3, $zero, 0xF4
    ctx->r7 = ADD32(0, 0XF4);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_38;
    // 0x80088F10: addiu       $a3, $zero, 0xF4
    ctx->r7 = ADD32(0, 0XF4);
    after_38:
    // 0x80088F14: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x80088F18: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80088F1C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088F20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088F24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088F28: jal         0x800C4FBC
    // 0x80088F2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_39;
    // 0x80088F2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_39:
    // 0x80088F30: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x80088F34: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80088F38: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80088F3C: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_80088F40:
    // 0x80088F40: bne         $s1, $zero, L_80088F70
    if (ctx->r17 != 0) {
        // 0x80088F44: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_80088F70;
    }
    // 0x80088F44: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088F48: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x80088F4C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80088F50: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80088F54: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80088F58: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80088F5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088F60: jal         0x800C5000
    // 0x80088F64: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_current_text_colour(rdram, ctx);
        goto after_40;
    // 0x80088F64: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_40:
    // 0x80088F68: b           L_80088FC4
    // 0x80088F6C: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
        goto L_80088FC4;
    // 0x80088F6C: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
L_80088F70:
    // 0x80088F70: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80088F74: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088F78: bne         $s1, $t0, L_80088FA8
    if (ctx->r17 != ctx->r8) {
        // 0x80088F7C: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80088FA8;
    }
    // 0x80088F7C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80088F80: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80088F84: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80088F88: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088F8C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80088F90: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80088F94: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80088F98: jal         0x800C5000
    // 0x80088F9C: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    set_current_text_colour(rdram, ctx);
        goto after_41;
    // 0x80088F9C: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    after_41:
    // 0x80088FA0: b           L_80088FC4
    // 0x80088FA4: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
        goto L_80088FC4;
    // 0x80088FA4: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
L_80088FA8:
    // 0x80088FA8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80088FAC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80088FB0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80088FB4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80088FB8: jal         0x800C5000
    // 0x80088FBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_42;
    // 0x80088FBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_42:
    // 0x80088FC0: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
L_80088FC4:
    // 0x80088FC4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80088FC8: lw          $t5, -0xBA0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0XBA0);
    // 0x80088FCC: addu        $t4, $t2, $s0
    ctx->r12 = ADD32(ctx->r10, ctx->r16);
    // 0x80088FD0: lw          $a3, 0x1BC($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X1BC);
    // 0x80088FD4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80088FD8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80088FDC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80088FE0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80088FE4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80088FE8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80088FEC: jal         0x800C5168
    // 0x80088FF0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_43;
    // 0x80088FF0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_43:
    // 0x80088FF4: beq         $s1, $zero, L_80089004
    if (ctx->r17 == 0) {
        // 0x80088FF8: nop
    
            goto L_80089004;
    }
    // 0x80088FF8: nop

    // 0x80088FFC: b           L_80089008
    // 0x80089000: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
        goto L_80089008;
    // 0x80089000: addiu       $s5, $s5, 0x10
    ctx->r21 = ADD32(ctx->r21, 0X10);
L_80089004:
    // 0x80089004: addiu       $s5, $s5, 0x14
    ctx->r21 = ADD32(ctx->r21, 0X14);
L_80089008:
    // 0x80089008: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008900C: bne         $s1, $s2, L_80088F40
    if (ctx->r17 != ctx->r18) {
        // 0x80089010: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80088F40;
    }
    // 0x80089010: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80089014: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089018: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x8008901C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089020: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80089024: jal         0x800C5B58
    // 0x80089028: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    render_dialogue_box(rdram, ctx);
        goto after_44;
    // 0x80089028: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_44:
L_8008902C:
    // 0x8008902C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80089030: lw          $t7, 0x6C10($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6C10);
    // 0x80089034: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80089038: beq         $t7, $zero, L_80089080
    if (ctx->r15 == 0) {
        // 0x8008903C: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80089080;
    }
    // 0x8008903C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80089040: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80089044: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80089048: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008904C: jal         0x800C4384
    // 0x80089050: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_45;
    // 0x80089050: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_45:
    // 0x80089054: jal         0x800C42EC
    // 0x80089058: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_46;
    // 0x80089058: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_46:
    // 0x8008905C: lw          $t0, 0x0($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X0);
    // 0x80089060: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80089064: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80089068: lw          $a3, 0x1F0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X1F0);
    // 0x8008906C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80089070: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x80089074: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80089078: jal         0x800C4440
    // 0x8008907C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    draw_text(rdram, ctx);
        goto after_47;
    // 0x8008907C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_47:
L_80089080:
    // 0x80089080: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80089084:
    // 0x80089084: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80089088: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8008908C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80089090: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80089094: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80089098: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8008909C: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x800890A0: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x800890A4: jr          $ra
    // 0x800890A8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800890A8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void sndp_get_global_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000317C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80003180: lw          $v0, -0x3940($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3940);
    // 0x80003184: jr          $ra
    // 0x80003188: nop

    return;
    // 0x80003188: nop

;}
RECOMP_FUNC void music_jingle_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001BC0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80001BC4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80001BC8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001BCC: addiu       $v0, $v0, 0x5D05
    ctx->r2 = ADD32(ctx->r2, 0X5D05);
    // 0x80001BD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001BD4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80001BD8: sb          $t6, -0x39BC($at)
    MEM_B(-0X39BC, ctx->r1) = ctx->r14;
    // 0x80001BDC: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
    // 0x80001BE0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80001BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001BE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001BEC: lw          $a1, -0x39CC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X39CC);
    // 0x80001BF0: jal         0x800022BC
    // 0x80001BF4: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    music_sequence_start(rdram, ctx);
        goto after_0;
    // 0x80001BF4: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    after_0:
    // 0x80001BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001C00: jr          $ra
    // 0x80001C04: nop

    return;
    // 0x80001C04: nop

;}
RECOMP_FUNC void _Ldtob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6F10: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x800D6F14: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800D6F18: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800D6F1C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x800D6F20: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800D6F24: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800D6F28: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800D6F2C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800D6F30: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800D6F34: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x800D6F38: sw          $a1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r5;
    // 0x800D6F3C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x800D6F40: addiu       $s5, $sp, 0xB0
    ctx->r21 = ADD32(ctx->r29, 0XB0);
    // 0x800D6F44: ldc1        $f20, 0x0($a0)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r4, 0X0);
    // 0x800D6F48: bgez        $v0, L_800D6F58
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D6F4C: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_800D6F58;
    }
    // 0x800D6F4C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800D6F50: b           L_800D6F84
    // 0x800D6F54: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
        goto L_800D6F84;
    // 0x800D6F54: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
L_800D6F58:
    // 0x800D6F58: bne         $v0, $zero, L_800D6F84
    if (ctx->r2 != 0) {
        // 0x800D6F5C: lbu         $t8, 0xD7($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0XD7);
            goto L_800D6F84;
    }
    // 0x800D6F5C: lbu         $t8, 0xD7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD7);
    // 0x800D6F60: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x800D6F64: beq         $t8, $at, L_800D6F78
    if (ctx->r24 == ctx->r1) {
        // 0x800D6F68: sw          $t8, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r24;
            goto L_800D6F78;
    }
    // 0x800D6F68: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x800D6F6C: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800D6F70: bnel        $t8, $at, L_800D6F88
    if (ctx->r24 != ctx->r1) {
        // 0x800D6F74: lw          $t6, 0xD0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XD0);
            goto L_800D6F88;
    }
    goto skip_0;
    // 0x800D6F74: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    skip_0:
L_800D6F78:
    // 0x800D6F78: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x800D6F7C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D6F80: sw          $t9, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r25;
L_800D6F84:
    // 0x800D6F84: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
L_800D6F88:
    // 0x800D6F88: addiu       $at, $zero, 0x7FF
    ctx->r1 = ADD32(0, 0X7FF);
    // 0x800D6F8C: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x800D6F90: andi        $v1, $a0, 0x7FF0
    ctx->r3 = ctx->r4 & 0X7FF0;
    // 0x800D6F94: sra         $t8, $v1, 4
    ctx->r24 = S32(SIGNED(ctx->r3) >> 4);
    // 0x800D6F98: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D6F9C: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800D6FA0: bne         $v1, $at, L_800D7004
    if (ctx->r3 != ctx->r1) {
        // 0x800D6FA4: nop
    
            goto L_800D7004;
    }
    // 0x800D6FA4: nop

    // 0x800D6FA8: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
    // 0x800D6FAC: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x800D6FB0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800D6FB4: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800D6FB8: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x800D6FBC: bnel        $t9, $zero, L_800D6FE8
    if (ctx->r25 != 0) {
        // 0x800D6FC0: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800D6FE8;
    }
    goto skip_1;
    // 0x800D6FC0: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_1:
    // 0x800D6FC4: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x800D6FC8: bnel        $t7, $zero, L_800D6FE8
    if (ctx->r15 != 0) {
        // 0x800D6FCC: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800D6FE8;
    }
    goto skip_2;
    // 0x800D6FCC: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_2:
    // 0x800D6FD0: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x800D6FD4: bnel        $t8, $zero, L_800D6FE8
    if (ctx->r24 != 0) {
        // 0x800D6FD8: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800D6FE8;
    }
    goto skip_3;
    // 0x800D6FD8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_3:
    // 0x800D6FDC: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x800D6FE0: beq         $t9, $zero, L_800D6FF0
    if (ctx->r25 == 0) {
        // 0x800D6FE4: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800D6FF0;
    }
    // 0x800D6FE4: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
L_800D6FE8:
    // 0x800D6FE8: b           L_800D703C
    // 0x800D6FEC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800D703C;
    // 0x800D6FEC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800D6FF0:
    // 0x800D6FF0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800D6FF4: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x800D6FF8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800D6FFC: b           L_800D703C
    // 0x800D7000: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_800D703C;
    // 0x800D7000: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800D7004:
    // 0x800D7004: blez        $v1, L_800D7028
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800D7008: andi        $t8, $a0, 0x800F
        ctx->r24 = ctx->r4 & 0X800F;
            goto L_800D7028;
    }
    // 0x800D7008: andi        $t8, $a0, 0x800F
    ctx->r24 = ctx->r4 & 0X800F;
    // 0x800D700C: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800D7010: ori         $t6, $t8, 0x3FF0
    ctx->r14 = ctx->r24 | 0X3FF0;
    // 0x800D7014: addiu       $t7, $v1, -0x3FE
    ctx->r15 = ADD32(ctx->r3, -0X3FE);
    // 0x800D7018: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
    // 0x800D701C: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x800D7020: b           L_800D703C
    // 0x800D7024: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800D703C;
    // 0x800D7024: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800D7028:
    // 0x800D7028: bgez        $v1, L_800D7038
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D702C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D7038;
    }
    // 0x800D702C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D7030: b           L_800D703C
    // 0x800D7034: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800D703C;
    // 0x800D7034: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800D7038:
    // 0x800D7038: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_800D703C:
    // 0x800D703C: blez        $v0, L_800D7088
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D7040: sll         $t8, $v0, 16
        ctx->r24 = S32(ctx->r2 << 16);
            goto L_800D7088;
    }
    // 0x800D7040: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x800D7044: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x800D7048: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D704C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D7050: bne         $t6, $at, L_800D7064
    if (ctx->r14 != ctx->r1) {
        // 0x800D7054: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_800D7064;
    }
    // 0x800D7054: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800D7058: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800D705C: b           L_800D706C
    // 0x800D7060: addiu       $a1, $a1, -0x6758
    ctx->r5 = ADD32(ctx->r5, -0X6758);
        goto L_800D706C;
    // 0x800D7060: addiu       $a1, $a1, -0x6758
    ctx->r5 = ADD32(ctx->r5, -0X6758);
L_800D7064:
    // 0x800D7064: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800D7068: addiu       $a1, $a1, -0x6754
    ctx->r5 = ADD32(ctx->r5, -0X6754);
L_800D706C:
    // 0x800D706C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800D7070: sw          $t7, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r15;
    // 0x800D7074: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x800D7078: jal         0x800CE170
    // 0x800D707C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x800D707C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x800D7080: b           L_800D7438
    // 0x800D7084: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800D7438;
    // 0x800D7084: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800D7088:
    // 0x800D7088: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D708C: bne         $t6, $zero, L_800D709C
    if (ctx->r14 != 0) {
        // 0x800D7090: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800D709C;
    }
    // 0x800D7090: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800D7094: b           L_800D7420
    // 0x800D7098: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
        goto L_800D7420;
    // 0x800D7098: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_800D709C:
    // 0x800D709C: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x800D70A0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D70A4: lbu         $t7, 0xD7($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD7);
    // 0x800D70A8: lh          $t9, 0x9A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X9A);
    // 0x800D70AC: c.lt.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d < ctx->f2.d;
    // 0x800D70B0: addiu       $at, $zero, 0x7597
    ctx->r1 = ADD32(0, 0X7597);
    // 0x800D70B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D70B8: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x800D70BC: bc1f        L_800D70C8
    if (!c1cs) {
        // 0x800D70C0: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_800D70C8;
    }
    // 0x800D70C0: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800D70C4: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
L_800D70C8:
    // 0x800D70C8: multu       $t9, $at
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D70CC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800D70D0: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x800D70D4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800D70D8: mflo        $t8
    ctx->r24 = lo;
    // 0x800D70DC: nop

    // 0x800D70E0: nop

    // 0x800D70E4: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x800D70E8: mflo        $t6
    ctx->r14 = lo;
    // 0x800D70EC: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x800D70F0: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800D70F4: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800D70F8: bgez        $t8, L_800D7160
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D70FC: sh          $t7, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r15;
            goto L_800D7160;
    }
    // 0x800D70FC: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x800D7100: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800D7104: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800D7108: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800D710C: subu        $a0, $t6, $t8
    ctx->r4 = SUB32(ctx->r14, ctx->r24);
    // 0x800D7110: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D7114: and         $v0, $a0, $at
    ctx->r2 = ctx->r4 & ctx->r1;
    // 0x800D7118: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x800D711C: blez        $v0, L_800D71D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D7120: sh          $t9, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r25;
            goto L_800D71D0;
    }
    // 0x800D7120: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x800D7124: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D7128: addiu       $a0, $a0, -0x67A0
    ctx->r4 = ADD32(ctx->r4, -0X67A0);
L_800D712C:
    // 0x800D712C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800D7130: beq         $t6, $zero, L_800D714C
    if (ctx->r14 == 0) {
        // 0x800D7134: sra         $t9, $v0, 1
        ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800D714C;
    }
    // 0x800D7134: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800D7138: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x800D713C: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x800D7140: ldc1        $f4, 0x0($t7)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r15, 0X0);
    // 0x800D7144: mul.d       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f20.d = MUL_D(ctx->f20.d, ctx->f4.d);
    // 0x800D7148: nop

L_800D714C:
    // 0x800D714C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800D7150: bgtz        $t9, L_800D712C
    if (SIGNED(ctx->r25) > 0) {
        // 0x800D7154: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800D712C;
    }
    // 0x800D7154: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800D7158: b           L_800D71D4
    // 0x800D715C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
        goto L_800D71D4;
    // 0x800D715C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_800D7160:
    // 0x800D7160: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x800D7164: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800D7168: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D716C: blez        $t6, L_800D71D0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800D7170: andi        $t8, $t6, 0xFFFC
        ctx->r24 = ctx->r14 & 0XFFFC;
            goto L_800D71D0;
    }
    // 0x800D7170: andi        $t8, $t6, 0xFFFC
    ctx->r24 = ctx->r14 & 0XFFFC;
    // 0x800D7174: sll         $v0, $t8, 16
    ctx->r2 = S32(ctx->r24 << 16);
    // 0x800D7178: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800D717C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800D7180: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D7184: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800D7188: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800D718C: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x800D7190: blez        $t6, L_800D71CC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800D7194: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800D71CC;
    }
    // 0x800D7194: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800D7198: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800D719C: addiu       $a0, $a0, -0x67A0
    ctx->r4 = ADD32(ctx->r4, -0X67A0);
L_800D71A0:
    // 0x800D71A0: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800D71A4: beq         $t7, $zero, L_800D71C0
    if (ctx->r15 == 0) {
        // 0x800D71A8: sra         $t6, $v0, 1
        ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800D71C0;
    }
    // 0x800D71A8: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800D71AC: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x800D71B0: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800D71B4: ldc1        $f6, 0x0($t9)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r25, 0X0);
    // 0x800D71B8: mul.d       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800D71BC: nop

L_800D71C0:
    // 0x800D71C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800D71C4: bgtz        $t6, L_800D71A0
    if (SIGNED(ctx->r14) > 0) {
        // 0x800D71C8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800D71A0;
    }
    // 0x800D71C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800D71CC:
    // 0x800D71CC: div.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = DIV_D(ctx->f20.d, ctx->f0.d);
L_800D71D0:
    // 0x800D71D0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_800D71D4:
    // 0x800D71D4: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x800D71D8: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800D71DC: bne         $t7, $at, L_800D71F0
    if (ctx->r15 != ctx->r1) {
        // 0x800D71E0: addiu       $t6, $zero, 0x30
        ctx->r14 = ADD32(0, 0X30);
            goto L_800D71F0;
    }
    // 0x800D71E0: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800D71E4: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x800D71E8: b           L_800D71F0
    // 0x800D71EC: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
        goto L_800D71F0;
    // 0x800D71EC: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
L_800D71F0:
    // 0x800D71F0: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x800D71F4: addu        $s4, $a1, $t9
    ctx->r20 = ADD32(ctx->r5, ctx->r25);
    // 0x800D71F8: slti        $at, $s4, 0x14
    ctx->r1 = SIGNED(ctx->r20) < 0X14 ? 1 : 0;
    // 0x800D71FC: bne         $at, $zero, L_800D7208
    if (ctx->r1 != 0) {
        // 0x800D7200: nop
    
            goto L_800D7208;
    }
    // 0x800D7200: nop

    // 0x800D7204: addiu       $s4, $zero, 0x13
    ctx->r20 = ADD32(0, 0X13);
L_800D7208:
    // 0x800D7208: blez        $s4, L_800D72D8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800D720C: sb          $t6, 0xB0($sp)
        MEM_B(0XB0, ctx->r29) = ctx->r14;
            goto L_800D72D8;
    }
    // 0x800D720C: sb          $t6, 0xB0($sp)
    MEM_B(0XB0, ctx->r29) = ctx->r14;
    // 0x800D7210: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x800D7214: addiu       $s3, $zero, 0x30
    ctx->r19 = ADD32(0, 0X30);
    // 0x800D7218: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
    // 0x800D721C: bc1fl       L_800D72DC
    if (!c1cs) {
        // 0x800D7220: lh          $t8, 0x9A($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X9A);
            goto L_800D72DC;
    }
    goto skip_4;
    // 0x800D7220: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
    skip_4:
    // 0x800D7224: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
L_800D7228:
    // 0x800D7228: addiu       $s4, $s4, -0x8
    ctx->r20 = ADD32(ctx->r20, -0X8);
    // 0x800D722C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800D7230: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x800D7234: blez        $s4, L_800D7258
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800D7238: nop
    
            goto L_800D7258;
    }
    // 0x800D7238: nop

    // 0x800D723C: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x800D7240: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D7244: ldc1        $f8, -0x6748($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6748);
    // 0x800D7248: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x800D724C: sub.d       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f20.d - ctx->f4.d;
    // 0x800D7250: mul.d       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f20.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800D7254: nop

L_800D7258:
    // 0x800D7258: blez        $s1, L_800D72A0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800D725C: addiu       $s0, $zero, 0x8
        ctx->r16 = ADD32(0, 0X8);
            goto L_800D72A0;
    }
    // 0x800D725C: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x800D7260: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x800D7264: bltz        $s0, L_800D72A0
    if (SIGNED(ctx->r16) < 0) {
        // 0x800D7268: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D72A0;
    }
    // 0x800D7268: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800D726C:
    // 0x800D726C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D7270: jal         0x800D7570
    // 0x800D7274: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    ldiv_recomp(rdram, ctx);
        goto after_1;
    // 0x800D7274: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
    // 0x800D7278: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x800D727C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800D7280: addiu       $t9, $t8, 0x30
    ctx->r25 = ADD32(ctx->r24, 0X30);
    // 0x800D7284: sb          $t9, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r25;
    // 0x800D7288: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x800D728C: blezl       $s1, L_800D72A4
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800D7290: mtc1        $zero, $f3
        ctx->f_odd[(3 - 1) * 2] = 0;
            goto L_800D72A4;
    }
    goto skip_5;
    // 0x800D7290: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    skip_5:
    // 0x800D7294: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800D7298: bgezl       $s0, L_800D726C
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800D729C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800D726C;
    }
    goto skip_6;
    // 0x800D729C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_6:
L_800D72A0:
    // 0x800D72A0: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
L_800D72A4:
    // 0x800D72A4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D72A8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800D72AC: bltz        $s0, L_800D72C0
    if (SIGNED(ctx->r16) < 0) {
        // 0x800D72B0: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800D72C0;
    }
L_800D72B0:
    // 0x800D72B0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800D72B4: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800D72B8: bgez        $s0, L_800D72B0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800D72BC: sb          $s3, 0x0($s5)
        MEM_B(0X0, ctx->r21) = ctx->r19;
            goto L_800D72B0;
    }
    // 0x800D72BC: sb          $s3, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r19;
L_800D72C0:
    // 0x800D72C0: blez        $s4, L_800D72D8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800D72C4: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_800D72D8;
    }
    // 0x800D72C4: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x800D72C8: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x800D72CC: nop

    // 0x800D72D0: bc1tl       L_800D7228
    if (c1cs) {
        // 0x800D72D4: trunc.w.d   $f8, $f20
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
            goto L_800D7228;
    }
    goto skip_7;
    // 0x800D72D4: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
    skip_7:
L_800D72D8:
    // 0x800D72D8: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
L_800D72DC:
    // 0x800D72DC: lbu         $t6, 0xB1($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XB1);
    // 0x800D72E0: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x800D72E4: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800D72E8: subu        $s4, $s5, $t7
    ctx->r20 = SUB32(ctx->r21, ctx->r15);
    // 0x800D72EC: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x800D72F0: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800D72F4: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x800D72F8: bne         $v0, $t6, L_800D7320
    if (ctx->r2 != ctx->r14) {
        // 0x800D72FC: addiu       $s5, $sp, 0xB1
        ctx->r21 = ADD32(ctx->r29, 0XB1);
            goto L_800D7320;
    }
    // 0x800D72FC: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x800D7300: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
L_800D7304:
    // 0x800D7304: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800D7308: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x800D730C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800D7310: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x800D7314: lbu         $t9, 0x0($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X0);
    // 0x800D7318: beql        $v0, $t9, L_800D7304
    if (ctx->r2 == ctx->r25) {
        // 0x800D731C: lh          $t7, 0x9A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X9A);
            goto L_800D7304;
    }
    goto skip_8;
    // 0x800D731C: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
    skip_8:
L_800D7320:
    // 0x800D7320: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800D7324: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x800D7328: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800D732C: bne         $t6, $at, L_800D7340
    if (ctx->r14 != ctx->r1) {
        // 0x800D7330: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_800D7340;
    }
    // 0x800D7330: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800D7334: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x800D7338: b           L_800D7360
    // 0x800D733C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_800D7360;
    // 0x800D733C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800D7340:
    // 0x800D7340: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x800D7344: beq         $t7, $at, L_800D7354
    if (ctx->r15 == ctx->r1) {
        // 0x800D7348: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_800D7354;
    }
    // 0x800D7348: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x800D734C: bne         $t7, $at, L_800D735C
    if (ctx->r15 != ctx->r1) {
        // 0x800D7350: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D735C;
    }
    // 0x800D7350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D7354:
    // 0x800D7354: b           L_800D735C
    // 0x800D7358: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D735C;
    // 0x800D7358: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D735C:
    // 0x800D735C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800D7360:
    // 0x800D7360: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x800D7364: addu        $s3, $a1, $t9
    ctx->r19 = ADD32(ctx->r5, ctx->r25);
    // 0x800D7368: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800D736C: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D7370: slt         $at, $s4, $s3
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800D7374: beq         $at, $zero, L_800D7388
    if (ctx->r1 == 0) {
        // 0x800D7378: nop
    
            goto L_800D7388;
    }
    // 0x800D7378: nop

    // 0x800D737C: sll         $s3, $s4, 16
    ctx->r19 = S32(ctx->r20 << 16);
    // 0x800D7380: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800D7384: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
L_800D7388:
    // 0x800D7388: blez        $s3, L_800D7420
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800D738C: slt         $at, $s3, $s4
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_800D7420;
    }
    // 0x800D738C: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800D7390: beq         $at, $zero, L_800D73B0
    if (ctx->r1 == 0) {
        // 0x800D7394: addu        $v0, $s3, $s5
        ctx->r2 = ADD32(ctx->r19, ctx->r21);
            goto L_800D73B0;
    }
    // 0x800D7394: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
    // 0x800D7398: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800D739C: slti        $at, $t9, 0x35
    ctx->r1 = SIGNED(ctx->r25) < 0X35 ? 1 : 0;
    // 0x800D73A0: bnel        $at, $zero, L_800D73B4
    if (ctx->r1 != 0) {
        // 0x800D73A4: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_800D73B4;
    }
    goto skip_9;
    // 0x800D73A4: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    skip_9:
    // 0x800D73A8: b           L_800D73B8
    // 0x800D73AC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
        goto L_800D73B8;
    // 0x800D73AC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
L_800D73B0:
    // 0x800D73B0: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
L_800D73B4:
    // 0x800D73B4: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
L_800D73B8:
    // 0x800D73B8: lbu         $t6, -0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X1);
    // 0x800D73BC: addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // 0x800D73C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800D73C4: bne         $a1, $t6, L_800D73EC
    if (ctx->r5 != ctx->r14) {
        // 0x800D73C8: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_800D73EC;
    }
    // 0x800D73C8: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x800D73CC: addu        $v0, $v1, $s5
    ctx->r2 = ADD32(ctx->r3, ctx->r21);
L_800D73D0:
    // 0x800D73D0: lbu         $t9, -0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X1);
    // 0x800D73D4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800D73D8: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x800D73DC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800D73E0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800D73E4: beq         $a0, $t9, L_800D73D0
    if (ctx->r4 == ctx->r25) {
        // 0x800D73E8: sra         $s3, $t7, 16
        ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
            goto L_800D73D0;
    }
    // 0x800D73E8: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
L_800D73EC:
    // 0x800D73EC: bne         $a0, $at, L_800D7400
    if (ctx->r4 != ctx->r1) {
        // 0x800D73F0: addu        $v0, $s5, $v1
        ctx->r2 = ADD32(ctx->r21, ctx->r3);
            goto L_800D7400;
    }
    // 0x800D73F0: addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // 0x800D73F4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800D73F8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D73FC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_800D7400:
    // 0x800D7400: bgez        $v1, L_800D7420
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800D7404: lh          $t6, 0x9A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X9A);
            goto L_800D7420;
    }
    // 0x800D7404: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x800D7408: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800D740C: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800D7410: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D7414: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x800D7418: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D741C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_800D7420:
    // 0x800D7420: lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD0);
    // 0x800D7424: lbu         $s4, 0xD7($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0XD7);
    // 0x800D7428: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x800D742C: jal         0x800D69A0
    // 0x800D7430: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    static_3_800D69A0(rdram, ctx);
        goto after_2;
    // 0x800D7430: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    after_2:
    // 0x800D7434: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800D7438:
    // 0x800D7438: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800D743C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800D7440: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800D7444: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800D7448: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800D744C: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800D7450: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800D7454: jr          $ra
    // 0x800D7458: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x800D7458: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void music_animation_fraction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800015F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800015FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001600: jal         0x800C78D0
    // 0x80001604: nop

    osGetCount_recomp(rdram, ctx);
        goto after_0;
    // 0x80001604: nop

    after_0:
    // 0x80001608: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000160C: lw          $a0, -0x39B4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39B4);
    // 0x80001610: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80001614: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80001618: beq         $at, $zero, L_80001668
    if (ctx->r1 == 0) {
        // 0x8000161C: lui         $t1, 0x8011
        ctx->r9 = S32(0X8011 << 16);
            goto L_80001668;
    }
    // 0x8000161C: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80001620: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x80001624: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80001628: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000162C: addiu       $v1, $v1, 0x5D34
    ctx->r3 = ADD32(ctx->r3, 0X5D34);
    // 0x80001630: bgez        $t6, L_80001648
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80001634: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80001648;
    }
    // 0x80001634: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80001638: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000163C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80001640: nop

    // 0x80001644: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80001648:
    // 0x80001648: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000164C: lwc1        $f10, 0x49E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X49E0);
    // 0x80001650: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80001654: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80001658: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000165C: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80001660: b           L_800016B0
    // 0x80001664: swc1        $f4, 0x5D34($at)
    MEM_W(0X5D34, ctx->r1) = ctx->f4.u32l;
        goto L_800016B0;
    // 0x80001664: swc1        $f4, 0x5D34($at)
    MEM_W(0X5D34, ctx->r1) = ctx->f4.u32l;
L_80001668:
    // 0x80001668: subu        $t7, $v0, $a0
    ctx->r15 = SUB32(ctx->r2, ctx->r4);
    // 0x8000166C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80001670: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80001674: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80001678: addiu       $v1, $v1, 0x5D34
    ctx->r3 = ADD32(ctx->r3, 0X5D34);
    // 0x8000167C: bgez        $t8, L_80001694
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80001680: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80001694;
    }
    // 0x80001680: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80001684: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80001688: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000168C: nop

    // 0x80001690: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80001694:
    // 0x80001694: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001698: lwc1        $f18, 0x49E4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X49E4);
    // 0x8000169C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800016A0: div.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800016A4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800016A8: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800016AC: swc1        $f8, 0x5D34($at)
    MEM_W(0X5D34, ctx->r1) = ctx->f8.u32l;
L_800016B0:
    // 0x800016B0: lbu         $t9, 0x5D40($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X5D40);
    // 0x800016B4: addiu       $t0, $zero, 0xB6
    ctx->r8 = ADD32(0, 0XB6);
    // 0x800016B8: bne         $t9, $zero, L_800016C4
    if (ctx->r25 != 0) {
        // 0x800016BC: lui         $at, 0x8011
        ctx->r1 = S32(0X8011 << 16);
            goto L_800016C4;
    }
    // 0x800016BC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800016C0: sh          $t0, 0x5D30($at)
    MEM_H(0X5D30, ctx->r1) = ctx->r8;
L_800016C4:
    // 0x800016C4: lh          $t1, 0x5D30($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X5D30);
    // 0x800016C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800016CC: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800016D0: lwc1        $f10, 0x49E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X49E8);
    // 0x800016D4: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800016D8: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800016DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800016E0: div.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800016E4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800016E8: nop

    // 0x800016EC: bc1f        L_80001718
    if (!c1cs) {
        // 0x800016F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001718;
    }
    // 0x800016F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800016F4:
    // 0x800016F4: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800016F8: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x800016FC: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80001700: nop

    // 0x80001704: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80001708: nop

    // 0x8000170C: bc1t        L_800016F4
    if (c1cs) {
        // 0x80001710: nop
    
            goto L_800016F4;
    }
    // 0x80001710: nop

    // 0x80001714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001718:
    // 0x80001718: sw          $v0, -0x39B4($at)
    MEM_W(-0X39B4, ctx->r1) = ctx->r2;
    // 0x8000171C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001720: jr          $ra
    // 0x80001724: div.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
    return;
    // 0x80001724: div.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
;}
RECOMP_FUNC void music_can_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800018D0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800018D4: lbu         $v0, -0x39C0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X39C0);
    // 0x800018D8: jr          $ra
    // 0x800018DC: nop

    return;
    // 0x800018DC: nop

;}
RECOMP_FUNC void obj_loop_unknown94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042160: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80042164: jr          $ra
    // 0x80042168: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80042168: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void level_properties_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C2F0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006C2F4: lh          $v0, -0x2CD8($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2CD8);
    // 0x8006C2F8: jr          $ra
    // 0x8006C2FC: nop

    return;
    // 0x8006C2FC: nop

;}
RECOMP_FUNC void fb_init_vi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A550: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8007A554: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x8007A558: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A55C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A560: bne         $v0, $zero, L_8007A574
    if (ctx->r2 != 0) {
        // 0x8007A564: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007A574;
    }
    // 0x8007A564: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007A568: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
    // 0x8007A56C: b           L_8007A584
    // 0x8007A570: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_8007A584;
    // 0x8007A570: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8007A574:
    // 0x8007A574: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8007A578: bne         $a1, $v0, L_8007A584
    if (ctx->r5 != ctx->r2) {
        // 0x8007A57C: nop
    
            goto L_8007A584;
    }
    // 0x8007A57C: nop

    // 0x8007A580: addiu       $v1, $zero, 0x1C
    ctx->r3 = ADD32(0, 0X1C);
L_8007A584:
    // 0x8007A584: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007A588: lw          $t6, 0x62CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X62CC);
    // 0x8007A58C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A590: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x8007A594: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007A598: addu        $at, $at, $t7
    gpr jr_addend_8007A5A4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007A59C: lw          $t7, 0x7B0C($at)
    ctx->r15 = ADD32(ctx->r1, 0X7B0C);
    // 0x8007A5A0: nop

    // 0x8007A5A4: jr          $t7
    // 0x8007A5A8: nop

    switch (jr_addend_8007A5A4 >> 2) {
        case 0: goto L_8007A5AC; break;
        case 1: goto L_8007A5D0; break;
        case 2: goto L_8007A658; break;
        case 3: goto L_8007A6C0; break;
        case 4: goto L_8007A728; break;
        case 5: goto L_8007A750; break;
        case 6: goto L_8007A778; break;
        case 7: goto L_8007A7A0; break;
        default: switch_error(__func__, 0x8007A5A4, 0x800E7B0C);
    }
    // 0x8007A5A8: nop

L_8007A5AC:
    // 0x8007A5AC: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8007A5B0: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x8007A5B4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007A5B8: addiu       $t9, $t9, 0x3900
    ctx->r25 = ADD32(ctx->r25, 0X3900);
    // 0x8007A5BC: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8007A5C0: jal         0x800D1CA0
    // 0x8007A5C4: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    osViSetMode_recomp(rdram, ctx);
        goto after_0;
    // 0x8007A5C4: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8007A5C8: b           L_8007A7C0
    // 0x8007A5CC: nop

        goto L_8007A7C0;
    // 0x8007A5CC: nop

L_8007A5D0:
    // 0x8007A5D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007A5D4: bne         $v0, $zero, L_8007A5E8
    if (ctx->r2 != 0) {
        // 0x8007A5D8: addiu       $a0, $a0, 0x4620
        ctx->r4 = ADD32(ctx->r4, 0X4620);
            goto L_8007A5E8;
    }
    // 0x8007A5D8: addiu       $a0, $a0, 0x4620
    ctx->r4 = ADD32(ctx->r4, 0X4620);
    // 0x8007A5DC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007A5E0: b           L_8007A5F8
    // 0x8007A5E4: addiu       $a0, $a0, 0x4670
    ctx->r4 = ADD32(ctx->r4, 0X4670);
        goto L_8007A5F8;
    // 0x8007A5E4: addiu       $a0, $a0, 0x4670
    ctx->r4 = ADD32(ctx->r4, 0X4670);
L_8007A5E8:
    // 0x8007A5E8: bne         $a1, $v0, L_8007A5F8
    if (ctx->r5 != ctx->r2) {
        // 0x8007A5EC: nop
    
            goto L_8007A5F8;
    }
    // 0x8007A5EC: nop

    // 0x8007A5F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007A5F4: addiu       $a0, $a0, 0x46C0
    ctx->r4 = ADD32(ctx->r4, 0X46C0);
L_8007A5F8:
    // 0x8007A5F8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007A5FC: addiu       $a1, $a1, 0x6260
    ctx->r5 = ADD32(ctx->r5, 0X6260);
    // 0x8007A600: jal         0x8007ABFC
    // 0x8007A604: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    fb_memcpy(rdram, ctx);
        goto after_1;
    // 0x8007A604: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_1:
    // 0x8007A608: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8007A60C: lw          $t0, 0x300($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X300);
    // 0x8007A610: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007A614: bne         $t0, $zero, L_8007A648
    if (ctx->r8 != 0) {
        // 0x8007A618: addiu       $a1, $a1, 0x6260
        ctx->r5 = ADD32(ctx->r5, 0X6260);
            goto L_8007A648;
    }
    // 0x8007A618: addiu       $a1, $a1, 0x6260
    ctx->r5 = ADD32(ctx->r5, 0X6260);
    // 0x8007A61C: lw          $t1, 0x30($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X30);
    // 0x8007A620: lw          $t3, 0x44($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X44);
    // 0x8007A624: lui         $v0, 0x18
    ctx->r2 = S32(0X18 << 16);
    // 0x8007A628: subu        $t2, $t1, $v0
    ctx->r10 = SUB32(ctx->r9, ctx->r2);
    // 0x8007A62C: subu        $t4, $t3, $v0
    ctx->r12 = SUB32(ctx->r11, ctx->r2);
    // 0x8007A630: sw          $t2, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r10;
    // 0x8007A634: sw          $t4, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r12;
    // 0x8007A638: addiu       $t6, $t2, 0x18
    ctx->r14 = ADD32(ctx->r10, 0X18);
    // 0x8007A63C: addiu       $t8, $t4, 0x18
    ctx->r24 = ADD32(ctx->r12, 0X18);
    // 0x8007A640: sw          $t6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r14;
    // 0x8007A644: sw          $t8, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r24;
L_8007A648:
    // 0x8007A648: jal         0x800D1CA0
    // 0x8007A64C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osViSetMode_recomp(rdram, ctx);
        goto after_2;
    // 0x8007A64C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8007A650: b           L_8007A7C0
    // 0x8007A654: nop

        goto L_8007A7C0;
    // 0x8007A654: nop

L_8007A658:
    // 0x8007A658: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007A65C: bne         $v0, $zero, L_8007A670
    if (ctx->r2 != 0) {
        // 0x8007A660: addiu       $a0, $a0, 0x4620
        ctx->r4 = ADD32(ctx->r4, 0X4620);
            goto L_8007A670;
    }
    // 0x8007A660: addiu       $a0, $a0, 0x4620
    ctx->r4 = ADD32(ctx->r4, 0X4620);
    // 0x8007A664: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007A668: b           L_8007A680
    // 0x8007A66C: addiu       $a0, $a0, 0x4670
    ctx->r4 = ADD32(ctx->r4, 0X4670);
        goto L_8007A680;
    // 0x8007A66C: addiu       $a0, $a0, 0x4670
    ctx->r4 = ADD32(ctx->r4, 0X4670);
L_8007A670:
    // 0x8007A670: bne         $a1, $v0, L_8007A680
    if (ctx->r5 != ctx->r2) {
        // 0x8007A674: nop
    
            goto L_8007A680;
    }
    // 0x8007A674: nop

    // 0x8007A678: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007A67C: addiu       $a0, $a0, 0x46C0
    ctx->r4 = ADD32(ctx->r4, 0X46C0);
L_8007A680:
    // 0x8007A680: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007A684: addiu       $a1, $a1, 0x6260
    ctx->r5 = ADD32(ctx->r5, 0X6260);
    // 0x8007A688: jal         0x8007ABFC
    // 0x8007A68C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    fb_memcpy(rdram, ctx);
        goto after_3;
    // 0x8007A68C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_3:
    // 0x8007A690: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007A694: addiu       $a0, $a1, 0x6260
    ctx->r4 = ADD32(ctx->r5, 0X6260);
    // 0x8007A698: addiu       $v0, $zero, 0x500
    ctx->r2 = ADD32(0, 0X500);
    // 0x8007A69C: addiu       $t9, $zero, 0x280
    ctx->r25 = ADD32(0, 0X280);
    // 0x8007A6A0: addiu       $t0, $zero, 0x400
    ctx->r8 = ADD32(0, 0X400);
    // 0x8007A6A4: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8007A6A8: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    // 0x8007A6AC: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
    // 0x8007A6B0: jal         0x800D1CA0
    // 0x8007A6B4: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    osViSetMode_recomp(rdram, ctx);
        goto after_4;
    // 0x8007A6B4: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    after_4:
    // 0x8007A6B8: b           L_8007A7C0
    // 0x8007A6BC: nop

        goto L_8007A7C0;
    // 0x8007A6BC: nop

L_8007A6C0:
    // 0x8007A6C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007A6C4: bne         $v0, $zero, L_8007A6D8
    if (ctx->r2 != 0) {
        // 0x8007A6C8: addiu       $a0, $a0, 0x4710
        ctx->r4 = ADD32(ctx->r4, 0X4710);
            goto L_8007A6D8;
    }
    // 0x8007A6C8: addiu       $a0, $a0, 0x4710
    ctx->r4 = ADD32(ctx->r4, 0X4710);
    // 0x8007A6CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007A6D0: b           L_8007A6E8
    // 0x8007A6D4: addiu       $a0, $a0, 0x4760
    ctx->r4 = ADD32(ctx->r4, 0X4760);
        goto L_8007A6E8;
    // 0x8007A6D4: addiu       $a0, $a0, 0x4760
    ctx->r4 = ADD32(ctx->r4, 0X4760);
L_8007A6D8:
    // 0x8007A6D8: bne         $a1, $v0, L_8007A6E8
    if (ctx->r5 != ctx->r2) {
        // 0x8007A6DC: nop
    
            goto L_8007A6E8;
    }
    // 0x8007A6DC: nop

    // 0x8007A6E0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007A6E4: addiu       $a0, $a0, 0x47B0
    ctx->r4 = ADD32(ctx->r4, 0X47B0);
L_8007A6E8:
    // 0x8007A6E8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007A6EC: addiu       $a1, $a1, 0x6260
    ctx->r5 = ADD32(ctx->r5, 0X6260);
    // 0x8007A6F0: jal         0x8007ABFC
    // 0x8007A6F4: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    fb_memcpy(rdram, ctx);
        goto after_5;
    // 0x8007A6F4: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_5:
    // 0x8007A6F8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007A6FC: addiu       $a0, $a1, 0x6260
    ctx->r4 = ADD32(ctx->r5, 0X6260);
    // 0x8007A700: addiu       $v0, $zero, 0x500
    ctx->r2 = ADD32(0, 0X500);
    // 0x8007A704: addiu       $t1, $zero, 0x280
    ctx->r9 = ADD32(0, 0X280);
    // 0x8007A708: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x8007A70C: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x8007A710: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8007A714: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
    // 0x8007A718: jal         0x800D1CA0
    // 0x8007A71C: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    osViSetMode_recomp(rdram, ctx);
        goto after_6;
    // 0x8007A71C: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    after_6:
    // 0x8007A720: b           L_8007A7C0
    // 0x8007A724: nop

        goto L_8007A7C0;
    // 0x8007A724: nop

L_8007A728:
    // 0x8007A728: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8007A72C: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x8007A730: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x8007A734: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007A738: addiu       $t5, $t5, 0x3900
    ctx->r13 = ADD32(ctx->r13, 0X3900);
    // 0x8007A73C: addiu       $t4, $t3, 0x280
    ctx->r12 = ADD32(ctx->r11, 0X280);
    // 0x8007A740: jal         0x800D1CA0
    // 0x8007A744: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    osViSetMode_recomp(rdram, ctx);
        goto after_7;
    // 0x8007A744: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_7:
    // 0x8007A748: b           L_8007A7C0
    // 0x8007A74C: nop

        goto L_8007A7C0;
    // 0x8007A74C: nop

L_8007A750:
    // 0x8007A750: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8007A754: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8007A758: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8007A75C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007A760: addiu       $t8, $t8, 0x3900
    ctx->r24 = ADD32(ctx->r24, 0X3900);
    // 0x8007A764: addiu       $t7, $t6, 0x320
    ctx->r15 = ADD32(ctx->r14, 0X320);
    // 0x8007A768: jal         0x800D1CA0
    // 0x8007A76C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    osViSetMode_recomp(rdram, ctx);
        goto after_8;
    // 0x8007A76C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_8:
    // 0x8007A770: b           L_8007A7C0
    // 0x8007A774: nop

        goto L_8007A7C0;
    // 0x8007A774: nop

L_8007A778:
    // 0x8007A778: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8007A77C: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x8007A780: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x8007A784: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007A788: addiu       $t1, $t1, 0x3900
    ctx->r9 = ADD32(ctx->r9, 0X3900);
    // 0x8007A78C: addiu       $t0, $t9, 0x2D0
    ctx->r8 = ADD32(ctx->r25, 0X2D0);
    // 0x8007A790: jal         0x800D1CA0
    // 0x8007A794: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    osViSetMode_recomp(rdram, ctx);
        goto after_9;
    // 0x8007A794: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_9:
    // 0x8007A798: b           L_8007A7C0
    // 0x8007A79C: nop

        goto L_8007A7C0;
    // 0x8007A79C: nop

L_8007A7A0:
    // 0x8007A7A0: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8007A7A4: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x8007A7A8: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x8007A7AC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8007A7B0: addiu       $t4, $t4, 0x3900
    ctx->r12 = ADD32(ctx->r12, 0X3900);
    // 0x8007A7B4: addiu       $t3, $t2, 0x370
    ctx->r11 = ADD32(ctx->r10, 0X370);
    // 0x8007A7B8: jal         0x800D1CA0
    // 0x8007A7BC: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    osViSetMode_recomp(rdram, ctx);
        goto after_10;
    // 0x8007A7BC: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_10:
L_8007A7C0:
    // 0x8007A7C0: jal         0x800D2260
    // 0x8007A7C4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_11;
    // 0x8007A7C4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_11:
    // 0x8007A7C8: jal         0x800D2260
    // 0x8007A7CC: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_12;
    // 0x8007A7CC: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_12:
    // 0x8007A7D0: jal         0x800D2260
    // 0x8007A7D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_13;
    // 0x8007A7D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_13:
    // 0x8007A7D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A7DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007A7E0: jr          $ra
    // 0x8007A7E4: nop

    return;
    // 0x8007A7E4: nop

;}
RECOMP_FUNC void sound_volume_set_relative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001FB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001FBC: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001FC0: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80001FC4: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80001FC8: lw          $t8, 0x5D18($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5D18);
    // 0x80001FCC: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80001FD0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80001FD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001FD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001FDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001FE0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80001FE4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80001FE8: lbu         $t1, 0x2($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X2);
    // 0x80001FEC: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x80001FF0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80001FF4: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80001FF8: bgez        $t1, L_80002010
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80001FFC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80002010;
    }
    // 0x80001FFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80002000: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80002004: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80002008: nop

    // 0x8000200C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80002010:
    // 0x80002010: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x80002014: bgez        $a2, L_8000202C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80002018: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8000202C;
    }
    // 0x80002018: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000201C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80002020: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80002024: nop

    // 0x80002028: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8000202C:
    // 0x8000202C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80002030: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80002034: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80002038: div.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000203C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80002040: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80002044: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80002048: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8000204C: nop

    // 0x80002050: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80002054: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80002058: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000205C: nop

    // 0x80002060: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80002064: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80002068: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8000206C: beq         $t4, $zero, L_8000207C
    if (ctx->r12 == 0) {
        // 0x80002070: sll         $t3, $a3, 8
        ctx->r11 = S32(ctx->r7 << 8);
            goto L_8000207C;
    }
    // 0x80002070: sll         $t3, $a3, 8
    ctx->r11 = S32(ctx->r7 << 8);
    // 0x80002074: jal         0x800049F8
    // 0x80002078: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    sndp_set_param(rdram, ctx);
        goto after_0;
    // 0x80002078: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_0:
L_8000207C:
    // 0x8000207C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002084: jr          $ra
    // 0x80002088: nop

    return;
    // 0x80002088: nop

;}
RECOMP_FUNC void obj_loop_parkwarden(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039330: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80039334: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80039338: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003933C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80039340: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80039344: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x80039348: sb          $zero, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = 0;
    // 0x8003934C: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80039350: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80039354: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80039358: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8003935C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80039360: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80039364: bne         $t7, $zero, L_80039384
    if (ctx->r15 != 0) {
        // 0x80039368: swc1        $f4, 0x98($sp)
        MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
            goto L_80039384;
    }
    // 0x80039368: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x8003936C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80039370: lwc1        $f11, 0x6060($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6060);
    // 0x80039374: lwc1        $f10, 0x6064($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6064);
    // 0x80039378: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8003937C: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80039380: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
L_80039384:
    // 0x80039384: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x80039388: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x8003938C: jal         0x8006BDB0
    // 0x80039390: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    level_header(rdram, ctx);
        goto after_0;
    // 0x80039390: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80039394: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80039398: lh          $t8, 0x18($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X18);
    // 0x8003939C: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x800393A0: bne         $t8, $zero, L_800393D8
    if (ctx->r24 != 0) {
        // 0x800393A4: nop
    
            goto L_800393D8;
    }
    // 0x800393A4: nop

    // 0x800393A8: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800393AC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800393B0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800393B4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800393B8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800393BC: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x800393C0: nop

    // 0x800393C4: bc1f        L_800393D8
    if (!c1cs) {
        // 0x800393C8: nop
    
            goto L_800393D8;
    }
    // 0x800393C8: nop

    // 0x800393CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800393D0: nop

    // 0x800393D4: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
L_800393D8:
    // 0x800393D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800393DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800393E0: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    // 0x800393E4: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x800393E8: jal         0x8001BAC8
    // 0x800393EC: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    get_racer_object(rdram, ctx);
        goto after_1;
    // 0x800393EC: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x800393F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800393F4: beq         $v0, $zero, L_8003945C
    if (ctx->r2 == 0) {
        // 0x800393F8: sw          $v0, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->r2;
            goto L_8003945C;
    }
    // 0x800393F8: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x800393FC: lw          $v0, 0x64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X64);
    // 0x80039400: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80039404: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80039408: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8003940C: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80039410: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80039414: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80039418: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003941C: lwc1        $f6, 0x14($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80039420: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80039424: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80039428: sub.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8003942C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80039430: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x80039434: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80039438: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    // 0x8003943C: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80039440: sub.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80039444: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80039448: swc1        $f2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f2.u32l;
    // 0x8003944C: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80039450: jal         0x800C9AD0
    // 0x80039454: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80039454: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    after_2:
    // 0x80039458: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
L_8003945C:
    // 0x8003945C: jal         0x8006A554
    // 0x80039460: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_3;
    // 0x80039460: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80039464: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
    // 0x80039468: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003946C: bne         $t9, $zero, L_80039560
    if (ctx->r25 != 0) {
        // 0x80039470: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80039560;
    }
    // 0x80039470: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80039474: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80039478: lwc1        $f17, 0x6068($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6068);
    // 0x8003947C: lwc1        $f16, 0x606C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X606C);
    // 0x80039480: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80039484: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x80039488: nop

    // 0x8003948C: bc1f        L_80039560
    if (!c1cs) {
        // 0x80039490: nop
    
            goto L_80039560;
    }
    // 0x80039490: nop

    // 0x80039494: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x80039498: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x8003949C: lh          $t0, 0x14($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X14);
    // 0x800394A0: andi        $t4, $v0, 0x2000
    ctx->r12 = ctx->r2 & 0X2000;
    // 0x800394A4: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x800394A8: beq         $t1, $zero, L_800394C0
    if (ctx->r9 == 0) {
        // 0x800394AC: nop
    
            goto L_800394C0;
    }
    // 0x800394AC: nop

    // 0x800394B0: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800394B4: nop

    // 0x800394B8: beq         $t2, $t3, L_800394C8
    if (ctx->r10 == ctx->r11) {
        // 0x800394BC: andi        $t5, $v0, 0x2000
        ctx->r13 = ctx->r2 & 0X2000;
            goto L_800394C8;
    }
    // 0x800394BC: andi        $t5, $v0, 0x2000
    ctx->r13 = ctx->r2 & 0X2000;
L_800394C0:
    // 0x800394C0: beq         $t4, $zero, L_80039560
    if (ctx->r12 == 0) {
        // 0x800394C4: andi        $t5, $v0, 0x2000
        ctx->r13 = ctx->r2 & 0X2000;
            goto L_80039560;
    }
    // 0x800394C4: andi        $t5, $v0, 0x2000
    ctx->r13 = ctx->r2 & 0X2000;
L_800394C8:
    // 0x800394C8: beq         $t5, $zero, L_800394EC
    if (ctx->r13 == 0) {
        // 0x800394CC: lw          $t6, 0x90($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X90);
            goto L_800394EC;
    }
    // 0x800394CC: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x800394D0: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x800394D4: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800394D8: jal         0x80056930
    // 0x800394DC: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    play_char_horn_sound(rdram, ctx);
        goto after_4;
    // 0x800394DC: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_4:
    // 0x800394E0: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x800394E4: nop

    // 0x800394E8: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
L_800394EC:
    // 0x800394EC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800394F0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800394F4: lwc1        $f4, 0xC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC);
    // 0x800394F8: lwc1        $f10, 0x14($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X14);
    // 0x800394FC: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    // 0x80039500: sub.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80039504: jal         0x80070750
    // 0x80039508: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    arctan2_f(rdram, ctx);
        goto after_5;
    // 0x80039508: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    after_5:
    // 0x8003950C: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x80039510: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80039514: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80039518: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x8003951C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80039520: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x80039524: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80039528: bne         $at, $zero, L_8003953C
    if (ctx->r1 != 0) {
        // 0x8003952C: slti        $at, $v1, -0x8000
        ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
            goto L_8003953C;
    }
    // 0x8003952C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80039530: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x80039534: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x80039538: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
L_8003953C:
    // 0x8003953C: beq         $at, $zero, L_8003954C
    if (ctx->r1 == 0) {
        // 0x80039540: slti        $at, $v1, -0x1FFF
        ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
            goto L_8003954C;
    }
    // 0x80039540: slti        $at, $v1, -0x1FFF
    ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
    // 0x80039544: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x80039548: slti        $at, $v1, -0x1FFF
    ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
L_8003954C:
    // 0x8003954C: bne         $at, $zero, L_80039560
    if (ctx->r1 != 0) {
        // 0x80039550: slti        $at, $v1, 0x2000
        ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
            goto L_80039560;
    }
    // 0x80039550: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x80039554: beq         $at, $zero, L_80039560
    if (ctx->r1 == 0) {
        // 0x80039558: nop
    
            goto L_80039560;
    }
    // 0x80039558: nop

    // 0x8003955C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80039560:
    // 0x80039560: lw          $t1, 0x4C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4C);
    // 0x80039564: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80039568: sh          $t0, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r8;
    // 0x8003956C: jal         0x80052188
    // 0x80039570: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    should_taj_teleport(rdram, ctx);
        goto after_6;
    // 0x80039570: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_6:
    // 0x80039574: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80039578: bne         $v0, $zero, L_80039588
    if (ctx->r2 != 0) {
        // 0x8003957C: nop
    
            goto L_80039588;
    }
    // 0x8003957C: nop

    // 0x80039580: beq         $a2, $zero, L_800396A0
    if (ctx->r6 == 0) {
        // 0x80039584: nop
    
            goto L_800396A0;
    }
    // 0x80039584: nop

L_80039588:
    // 0x80039588: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x8003958C: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80039590: beq         $v0, $zero, L_800395A0
    if (ctx->r2 == 0) {
        // 0x80039594: nop
    
            goto L_800395A0;
    }
    // 0x80039594: nop

    // 0x80039598: bne         $v0, $at, L_800396A0
    if (ctx->r2 != ctx->r1) {
        // 0x8003959C: nop
    
            goto L_800396A0;
    }
    // 0x8003959C: nop

L_800395A0:
    // 0x800395A0: jal         0x800012E8
    // 0x800395A4: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    music_channel_reset_all(rdram, ctx);
        goto after_7;
    // 0x800395A4: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_7:
    // 0x800395A8: jal         0x80000BE0
    // 0x800395AC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_8;
    // 0x800395AC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_8:
    // 0x800395B0: jal         0x80000B34
    // 0x800395B4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    music_play(rdram, ctx);
        goto after_9;
    // 0x800395B4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_9:
    // 0x800395B8: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x800395BC: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x800395C0: beq         $t2, $zero, L_800395DC
    if (ctx->r10 == 0) {
        // 0x800395C4: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_800395DC;
    }
    // 0x800395C4: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800395C8: jal         0x80006AC8
    // 0x800395CC: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    racer_sound_free(rdram, ctx);
        goto after_10;
    // 0x800395CC: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_10:
    // 0x800395D0: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x800395D4: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x800395D8: sw          $zero, 0x118($t3)
    MEM_W(0X118, ctx->r11) = 0;
L_800395DC:
    // 0x800395DC: jal         0x80008140
    // 0x800395E0: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    audspat_jingle_off(rdram, ctx);
        goto after_11;
    // 0x800395E0: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_11:
    // 0x800395E4: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
    // 0x800395E8: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800395EC: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800395F0: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800395F4: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800395F8: sub.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800395FC: jal         0x80070750
    // 0x80039600: sub.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f18.fl;
    arctan2_f(rdram, ctx);
        goto after_12;
    // 0x80039600: sub.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f18.fl;
    after_12:
    // 0x80039604: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x80039608: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8003960C: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80039610: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80039614: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x80039618: subu        $v1, $v0, $t6
    ctx->r3 = SUB32(ctx->r2, ctx->r14);
    // 0x8003961C: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80039620: bne         $at, $zero, L_80039628
    if (ctx->r1 != 0) {
        // 0x80039624: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80039628;
    }
    // 0x80039624: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80039628:
    // 0x80039628: beq         $a2, $zero, L_8003963C
    if (ctx->r6 == 0) {
        // 0x8003962C: addiu       $a1, $s1, 0x20
        ctx->r5 = ADD32(ctx->r17, 0X20);
            goto L_8003963C;
    }
    // 0x8003962C: addiu       $a1, $s1, 0x20
    ctx->r5 = ADD32(ctx->r17, 0X20);
    // 0x80039630: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80039634: b           L_8003964C
    // 0x80039638: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
        goto L_8003964C;
    // 0x80039638: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
L_8003963C:
    // 0x8003963C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80039640: sw          $t8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r24;
    // 0x80039644: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80039648: sb          $t9, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r25;
L_8003964C:
    // 0x8003964C: addiu       $t0, $s1, 0x12
    ctx->r8 = ADD32(ctx->r17, 0X12);
    // 0x80039650: addiu       $t1, $s1, 0x13
    ctx->r9 = ADD32(ctx->r17, 0X13);
    // 0x80039654: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80039658: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8003965C: addiu       $a2, $s1, 0x22
    ctx->r6 = ADD32(ctx->r17, 0X22);
    // 0x80039660: jal         0x80030750
    // 0x80039664: addiu       $a3, $s1, 0x11
    ctx->r7 = ADD32(ctx->r17, 0X11);
    get_fog_settings(rdram, ctx);
        goto after_13;
    // 0x80039664: addiu       $a3, $s1, 0x11
    ctx->r7 = ADD32(ctx->r17, 0X11);
    after_13:
    // 0x80039668: addiu       $t2, $zero, 0x3C0
    ctx->r10 = ADD32(0, 0X3C0);
    // 0x8003966C: addiu       $t3, $zero, 0x44C
    ctx->r11 = ADD32(0, 0X44C);
    // 0x80039670: addiu       $t4, $zero, 0xF0
    ctx->r12 = ADD32(0, 0XF0);
    // 0x80039674: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80039678: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8003967C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80039680: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80039684: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80039688: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003968C: jal         0x80030DE0
    // 0x80039690: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    slowly_change_fog(rdram, ctx);
        goto after_14;
    // 0x80039690: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    after_14:
    // 0x80039694: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80039698: nop

    // 0x8003969C: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
L_800396A0:
    // 0x800396A0: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x800396A4: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800396A8: beq         $v0, $zero, L_800396E4
    if (ctx->r2 == 0) {
        // 0x800396AC: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_800396E4;
    }
    // 0x800396AC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800396B0: beq         $v0, $at, L_800396E0
    if (ctx->r2 == ctx->r1) {
        // 0x800396B4: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_800396E0;
    }
    // 0x800396B4: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800396B8: beq         $v0, $at, L_800396E0
    if (ctx->r2 == ctx->r1) {
        // 0x800396BC: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_800396E0;
    }
    // 0x800396BC: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x800396C0: beq         $v0, $at, L_800396E4
    if (ctx->r2 == ctx->r1) {
        // 0x800396C4: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_800396E4;
    }
    // 0x800396C4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800396C8: jal         0x8005A3B0
    // 0x800396CC: nop

    disable_racer_input(rdram, ctx);
        goto after_15;
    // 0x800396CC: nop

    after_15:
    // 0x800396D0: jal         0x800AB194
    // 0x800396D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    minimap_fade(rdram, ctx);
        goto after_16;
    // 0x800396D4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
    // 0x800396D8: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x800396DC: nop

L_800396E0:
    // 0x800396E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_800396E4:
    // 0x800396E4: beq         $v0, $a3, L_80039704
    if (ctx->r2 == ctx->r7) {
        // 0x800396E8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80039704;
    }
    // 0x800396E8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800396EC: beq         $v0, $at, L_80039704
    if (ctx->r2 == ctx->r1) {
        // 0x800396F0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80039704;
    }
    // 0x800396F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800396F4: beq         $v0, $at, L_80039704
    if (ctx->r2 == ctx->r1) {
        // 0x800396F8: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80039704;
    }
    // 0x800396F8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800396FC: bne         $v0, $at, L_80039718
    if (ctx->r2 != ctx->r1) {
        // 0x80039700: nop
    
            goto L_80039718;
    }
    // 0x80039700: nop

L_80039704:
    // 0x80039704: jal         0x8009CFEC
    // 0x80039708: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    npc_dialogue_loop(rdram, ctx);
        goto after_17;
    // 0x80039708: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x8003970C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80039710: b           L_80039728
    // 0x80039714: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
        goto L_80039728;
    // 0x80039714: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
L_80039718:
    // 0x80039718: jal         0x8009CF68
    // 0x8003971C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    dialogue_npc_finish(rdram, ctx);
        goto after_18;
    // 0x8003971C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_18:
    // 0x80039720: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80039724: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
L_80039728:
    // 0x80039728: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x8003972C: nop

    // 0x80039730: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80039734: sltiu       $at, $t5, 0x15
    ctx->r1 = ctx->r13 < 0X15 ? 1 : 0;
    // 0x80039738: beq         $at, $zero, L_80039768
    if (ctx->r1 == 0) {
        // 0x8003973C: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80039768;
    }
    // 0x8003973C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80039740: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80039744: addu        $at, $at, $t5
    gpr jr_addend_80039750 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80039748: lw          $t5, 0x6070($at)
    ctx->r13 = ADD32(ctx->r1, 0X6070);
    // 0x8003974C: nop

    // 0x80039750: jr          $t5
    // 0x80039754: nop

    switch (jr_addend_80039750 >> 2) {
        case 0: goto L_80039758; break;
        case 1: goto L_80039758; break;
        case 2: goto L_80039758; break;
        case 3: goto L_80039758; break;
        case 4: goto L_80039768; break;
        case 5: goto L_80039768; break;
        case 6: goto L_80039758; break;
        case 7: goto L_80039768; break;
        case 8: goto L_80039768; break;
        case 9: goto L_80039758; break;
        case 10: goto L_80039758; break;
        case 11: goto L_80039768; break;
        case 12: goto L_80039768; break;
        case 13: goto L_80039768; break;
        case 14: goto L_80039758; break;
        case 15: goto L_80039768; break;
        case 16: goto L_80039768; break;
        case 17: goto L_80039768; break;
        case 18: goto L_80039768; break;
        case 19: goto L_80039758; break;
        case 20: goto L_80039758; break;
        default: switch_error(__func__, 0x80039750, 0x800E6070);
    }
    // 0x80039754: nop

L_80039758:
    // 0x80039758: jal         0x8006F388
    // 0x8003975C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_pause_lockout_timer(rdram, ctx);
        goto after_19;
    // 0x8003975C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x80039760: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x80039764: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_80039768:
    // 0x80039768: beq         $v0, $zero, L_80039794
    if (ctx->r2 == 0) {
        // 0x8003976C: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80039794;
    }
    // 0x8003976C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80039770: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x80039774: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80039778: beq         $t6, $zero, L_80039794
    if (ctx->r14 == 0) {
        // 0x8003977C: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80039794;
    }
    // 0x8003977C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80039780: beq         $at, $zero, L_80039794
    if (ctx->r1 == 0) {
        // 0x80039784: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80039794;
    }
    // 0x80039784: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80039788: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8003978C: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    // 0x80039790: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_80039794:
    // 0x80039794: sltiu       $at, $t7, 0x1E
    ctx->r1 = ctx->r15 < 0X1E ? 1 : 0;
    // 0x80039798: beq         $at, $zero, L_8003A5AC
    if (ctx->r1 == 0) {
        // 0x8003979C: addiu       $v1, $zero, 0x4
        ctx->r3 = ADD32(0, 0X4);
            goto L_8003A5AC;
    }
    // 0x8003979C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800397A0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800397A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800397A8: addu        $at, $at, $t7
    gpr jr_addend_800397B4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800397AC: lw          $t7, 0x60C4($at)
    ctx->r15 = ADD32(ctx->r1, 0X60C4);
    // 0x800397B0: nop

    // 0x800397B4: jr          $t7
    // 0x800397B8: nop

    switch (jr_addend_800397B4 >> 2) {
        case 0: goto L_800397BC; break;
        case 1: goto L_80039978; break;
        case 2: goto L_80039AE0; break;
        case 3: goto L_80039BB8; break;
        case 4: goto L_80039DC4; break;
        case 5: goto L_80039ED8; break;
        case 6: goto L_80039FDC; break;
        case 7: goto L_80039FDC; break;
        case 8: goto L_8003A5AC; break;
        case 9: goto L_8003A0CC; break;
        case 10: goto L_8003A1E8; break;
        case 11: goto L_8003A5AC; break;
        case 12: goto L_8003A5AC; break;
        case 13: goto L_8003A5AC; break;
        case 14: goto L_8003A268; break;
        case 15: goto L_8003A5AC; break;
        case 16: goto L_8003A5AC; break;
        case 17: goto L_8003A5AC; break;
        case 18: goto L_8003A5AC; break;
        case 19: goto L_8003A3FC; break;
        case 20: goto L_8003A4F4; break;
        case 21: goto L_8003A5AC; break;
        case 22: goto L_8003A5AC; break;
        case 23: goto L_8003A5AC; break;
        case 24: goto L_8003A5AC; break;
        case 25: goto L_8003A5AC; break;
        case 26: goto L_8003A5AC; break;
        case 27: goto L_8003A5AC; break;
        case 28: goto L_8003A5AC; break;
        case 29: goto L_8003A574; break;
        default: switch_error(__func__, 0x800397B4, 0x800E60C4);
    }
    // 0x800397B8: nop

L_800397BC:
    // 0x800397BC: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800397C0: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x800397C4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800397C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800397CC: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x800397D0: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x800397D4: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x800397D8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800397DC: bc1f        L_80039800
    if (!c1cs) {
        // 0x800397E0: sb          $t8, 0xD($s1)
        MEM_B(0XD, ctx->r17) = ctx->r24;
            goto L_80039800;
    }
    // 0x800397E0: sb          $t8, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r24;
    // 0x800397E4: swc1        $f1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x800397E8: jal         0x8005A3C0
    // 0x800397EC: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_20;
    // 0x800397EC: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x800397F0: lwc1        $f1, 0x40($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x800397F4: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800397F8: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800397FC: nop

L_80039800:
    // 0x80039800: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80039804: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80039808: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003980C: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80039810: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x80039814: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80039818: bc1f        L_80039934
    if (!c1cs) {
        // 0x8003981C: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_80039934;
    }
    // 0x8003981C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80039820: nop

    // 0x80039824: div.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80039828: jal         0x80070750
    // 0x8003982C: div.s       $f14, $f4, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    arctan2_f(rdram, ctx);
        goto after_21;
    // 0x8003982C: div.s       $f14, $f4, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    after_21:
    // 0x80039830: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x80039834: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80039838: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x8003983C: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x80039840: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80039844: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80039848: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8003984C: bne         $at, $zero, L_8003985C
    if (ctx->r1 != 0) {
        // 0x80039850: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8003985C;
    }
    // 0x80039850: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80039854: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80039858: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8003985C:
    // 0x8003985C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80039860: beq         $at, $zero, L_8003986C
    if (ctx->r1 == 0) {
        // 0x80039864: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8003986C;
    }
    // 0x80039864: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80039868: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8003986C:
    // 0x8003986C: blez        $v1, L_80039880
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80039870: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_80039880;
    }
    // 0x80039870: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80039874: beq         $at, $zero, L_80039884
    if (ctx->r1 == 0) {
        // 0x80039878: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_80039884;
    }
    // 0x80039878: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8003987C: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_80039880:
    // 0x80039880: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
L_80039884:
    // 0x80039884: sra         $t0, $v1, 4
    ctx->r8 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80039888: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003988C: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x80039890: slti        $at, $v1, 0x801
    ctx->r1 = SIGNED(ctx->r3) < 0X801 ? 1 : 0;
    // 0x80039894: beq         $at, $zero, L_800398A4
    if (ctx->r1 == 0) {
        // 0x80039898: sh          $t1, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r9;
            goto L_800398A4;
    }
    // 0x80039898: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x8003989C: slti        $at, $v1, -0x800
    ctx->r1 = SIGNED(ctx->r3) < -0X800 ? 1 : 0;
    // 0x800398A0: beq         $at, $zero, L_800398B0
    if (ctx->r1 == 0) {
        // 0x800398A4: lui         $at, 0xBF00
        ctx->r1 = S32(0XBF00 << 16);
            goto L_800398B0;
    }
L_800398A4:
    // 0x800398A4: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x800398A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800398AC: nop

L_800398B0:
    // 0x800398B0: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800398B4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800398B8: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800398BC: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x800398C0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800398C4: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x800398C8: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800398CC: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x800398D0: add.d       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f18.d + ctx->f8.d;
    // 0x800398D4: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x800398D8: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    // 0x800398DC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800398E0: jal         0x800707C4
    // 0x800398E4: nop

    sins_f(rdram, ctx);
        goto after_22;
    // 0x800398E4: nop

    after_22:
    // 0x800398E8: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800398EC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800398F0: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800398F4: jal         0x800707F8
    // 0x800398F8: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    coss_f(rdram, ctx);
        goto after_23;
    // 0x800398F8: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    after_23:
    // 0x800398FC: lwc1        $f18, 0x14($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80039900: lwc1        $f2, 0xAC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039904: mul.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80039908: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003990C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039910: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x80039914: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80039918: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003991C: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80039920: nop

    // 0x80039924: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80039928: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8003992C: b           L_80039940
    // 0x80039930: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
        goto L_80039940;
    // 0x80039930: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
L_80039934:
    // 0x80039934: sw          $t2, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r10;
    // 0x80039938: lwc1        $f2, 0xAC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003993C: nop

L_80039940:
    // 0x80039940: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80039944: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80039948: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8003994C: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80039950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039954: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80039958: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003995C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80039960: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80039964: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80039968: jal         0x80011570
    // 0x8003996C: nop

    move_object(rdram, ctx);
        goto after_24;
    // 0x8003996C: nop

    after_24:
    // 0x80039970: b           L_8003AB04
    // 0x80039974: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB04;
    // 0x80039974: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039978:
    // 0x80039978: jal         0x8005A3C0
    // 0x8003997C: nop

    racer_set_dialogue_camera(rdram, ctx);
        goto after_25;
    // 0x8003997C: nop

    after_25:
    // 0x80039980: lwc1        $f14, 0xAC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039984: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x80039988: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003998C: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x80039990: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x80039994: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80039998: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x8003999C: add.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f4.d + ctx->f10.d;
    // 0x800399A0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800399A4: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x800399A8: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x800399AC: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x800399B0: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x800399B4: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x800399B8: andi        $t5, $a1, 0xFFFF
    ctx->r13 = ctx->r5 & 0XFFFF;
    // 0x800399BC: subu        $v1, $t4, $t5
    ctx->r3 = SUB32(ctx->r12, ctx->r13);
    // 0x800399C0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x800399C4: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800399C8: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800399CC: bne         $at, $zero, L_800399DC
    if (ctx->r1 != 0) {
        // 0x800399D0: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800399DC;
    }
    // 0x800399D0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800399D4: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800399D8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800399DC:
    // 0x800399DC: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800399E0: beq         $at, $zero, L_800399EC
    if (ctx->r1 == 0) {
        // 0x800399E4: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800399EC;
    }
    // 0x800399E4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800399E8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800399EC:
    // 0x800399EC: blez        $v1, L_80039A00
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800399F0: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_80039A00;
    }
    // 0x800399F0: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x800399F4: beq         $at, $zero, L_80039A04
    if (ctx->r1 == 0) {
        // 0x800399F8: sra         $t6, $v1, 3
        ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80039A04;
    }
    // 0x800399F8: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800399FC: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_80039A00:
    // 0x80039A00: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
L_80039A04:
    // 0x80039A04: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x80039A08: slti        $at, $v1, 0x400
    ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x80039A0C: beq         $at, $zero, L_80039A6C
    if (ctx->r1 == 0) {
        // 0x80039A10: sh          $t7, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r15;
            goto L_80039A6C;
    }
    // 0x80039A10: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x80039A14: slti        $at, $v1, -0x3FF
    ctx->r1 = SIGNED(ctx->r3) < -0X3FF ? 1 : 0;
    // 0x80039A18: bne         $at, $zero, L_80039A6C
    if (ctx->r1 != 0) {
        // 0x80039A1C: nop
    
            goto L_80039A6C;
    }
    // 0x80039A1C: nop

    // 0x80039A20: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80039A24: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80039A28: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80039A2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80039A30: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80039A34: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x80039A38: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80039A3C: bc1f        L_80039A6C
    if (!c1cs) {
        // 0x80039A40: nop
    
            goto L_80039A6C;
    }
    // 0x80039A40: nop

    // 0x80039A44: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80039A48: sw          $a3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r7;
    // 0x80039A4C: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x80039A50: lhu         $a0, -0x2B1E($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X2B1E);
    // 0x80039A54: jal         0x8003AC3C
    // 0x80039A58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_26;
    // 0x80039A58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80039A5C: addiu       $t8, $zero, 0x10F
    ctx->r24 = ADD32(0, 0X10F);
    // 0x80039A60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80039A64: lwc1        $f14, 0xAC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039A68: sh          $t8, -0x2B1E($at)
    MEM_H(-0X2B1E, ctx->r1) = ctx->r24;
L_80039A6C:
    // 0x80039A6C: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80039A70: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80039A74: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80039A78: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80039A7C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80039A80: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x80039A84: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80039A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039A8C: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x80039A90: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80039A94: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80039A98: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80039A9C: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80039AA0: nop

    // 0x80039AA4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80039AA8: mul.d       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x80039AAC: nop

    // 0x80039AB0: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80039AB4: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x80039AB8: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x80039ABC: mul.s       $f16, $f8, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80039AC0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80039AC4: mul.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80039AC8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80039ACC: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80039AD0: jal         0x80011570
    // 0x80039AD4: nop

    move_object(rdram, ctx);
        goto after_27;
    // 0x80039AD4: nop

    after_27:
    // 0x80039AD8: b           L_8003AB04
    // 0x80039ADC: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB04;
    // 0x80039ADC: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039AE0:
    // 0x80039AE0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80039AE4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80039AE8: sb          $t9, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r25;
    // 0x80039AEC: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    // 0x80039AF0: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039AF4: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039AF8: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80039AFC: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80039B00: add.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f6.d + ctx->f16.d;
    // 0x80039B04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80039B08: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x80039B0C: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x80039B10: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039B14: lwc1        $f18, 0x6144($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6144);
    // 0x80039B18: lwc1        $f19, 0x6140($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6140);
    // 0x80039B1C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80039B20: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80039B24: lui         $at, 0x429A
    ctx->r1 = S32(0X429A << 16);
    // 0x80039B28: bc1f        L_80039B4C
    if (!c1cs) {
        // 0x80039B2C: lw          $t0, 0x90($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X90);
            goto L_80039B4C;
    }
    // 0x80039B2C: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x80039B30: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80039B34: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80039B38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039B3C: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x80039B40: swc1        $f4, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f4.u32l;
    // 0x80039B44: sw          $v1, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r3;
    // 0x80039B48: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
L_80039B4C:
    // 0x80039B4C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x80039B50: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80039B54: andi        $t2, $a1, 0xFFFF
    ctx->r10 = ctx->r5 & 0XFFFF;
    // 0x80039B58: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80039B5C: subu        $v1, $t1, $t2
    ctx->r3 = SUB32(ctx->r9, ctx->r10);
    // 0x80039B60: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80039B64: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80039B68: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80039B6C: bne         $at, $zero, L_80039B7C
    if (ctx->r1 != 0) {
        // 0x80039B70: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80039B7C;
    }
    // 0x80039B70: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80039B74: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80039B78: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80039B7C:
    // 0x80039B7C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80039B80: beq         $at, $zero, L_80039B8C
    if (ctx->r1 == 0) {
        // 0x80039B84: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80039B8C;
    }
    // 0x80039B84: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80039B88: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80039B8C:
    // 0x80039B8C: blez        $v1, L_80039BA0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80039B90: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_80039BA0;
    }
    // 0x80039B90: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80039B94: beq         $at, $zero, L_80039BA4
    if (ctx->r1 == 0) {
        // 0x80039B98: sra         $t3, $v1, 4
        ctx->r11 = S32(SIGNED(ctx->r3) >> 4);
            goto L_80039BA4;
    }
    // 0x80039B98: sra         $t3, $v1, 4
    ctx->r11 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80039B9C: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_80039BA0:
    // 0x80039BA0: sra         $t3, $v1, 4
    ctx->r11 = S32(SIGNED(ctx->r3) >> 4);
L_80039BA4:
    // 0x80039BA4: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x80039BA8: jal         0x8005A3C0
    // 0x80039BAC: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_28;
    // 0x80039BAC: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    after_28:
    // 0x80039BB0: b           L_8003AB04
    // 0x80039BB4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB04;
    // 0x80039BB4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039BB8:
    // 0x80039BB8: sb          $v1, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r3;
    // 0x80039BBC: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039BC0: lwc1        $f18, 0xAC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039BC4: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80039BC8: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80039BCC: add.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f8.d + ctx->f6.d;
    // 0x80039BD0: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x80039BD4: jal         0x8005A3C0
    // 0x80039BD8: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_29;
    // 0x80039BD8: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    after_29:
    // 0x80039BDC: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80039BE0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80039BE4: beq         $a2, $a3, L_80039BF0
    if (ctx->r6 == ctx->r7) {
        // 0x80039BE8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80039BF0;
    }
    // 0x80039BE8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80039BEC: bne         $a2, $at, L_80039CA8
    if (ctx->r6 != ctx->r1) {
        // 0x80039BF0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80039CA8;
    }
L_80039BF0:
    // 0x80039BF0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80039BF4: bne         $a2, $at, L_80039C08
    if (ctx->r6 != ctx->r1) {
        // 0x80039BF8: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80039C08;
    }
    // 0x80039BF8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80039BFC: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80039C00: b           L_80039C10
    // 0x80039C04: sw          $t5, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r13;
        goto L_80039C10;
    // 0x80039C04: sw          $t5, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r13;
L_80039C08:
    // 0x80039C08: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80039C0C: sw          $t6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r14;
L_80039C10:
    // 0x80039C10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80039C14: lwc1        $f10, 0x6148($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6148);
    // 0x80039C18: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    // 0x80039C1C: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x80039C20: sb          $t7, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r15;
    // 0x80039C24: sh          $zero, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = 0;
    // 0x80039C28: jal         0x8003AC3C
    // 0x80039C2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_30;
    // 0x80039C2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80039C30: lh          $t8, 0x20($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X20);
    // 0x80039C34: lbu         $a1, 0x11($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X11);
    // 0x80039C38: lbu         $a2, 0x12($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X12);
    // 0x80039C3C: lbu         $a3, 0x13($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X13);
    // 0x80039C40: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80039C44: lh          $t9, 0x22($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X22);
    // 0x80039C48: addiu       $t0, $zero, 0xB4
    ctx->r8 = ADD32(0, 0XB4);
    // 0x80039C4C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80039C50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80039C54: jal         0x80030DE0
    // 0x80039C58: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    slowly_change_fog(rdram, ctx);
        goto after_31;
    // 0x80039C58: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_31:
    // 0x80039C5C: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80039C60: nop

    // 0x80039C64: lbu         $a0, 0xB3($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0XB3);
    // 0x80039C68: jal         0x80000BE0
    // 0x80039C6C: nop

    music_voicelimit_set(rdram, ctx);
        goto after_32;
    // 0x80039C6C: nop

    after_32:
    // 0x80039C70: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80039C74: nop

    // 0x80039C78: lbu         $a0, 0x52($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X52);
    // 0x80039C7C: jal         0x80000B34
    // 0x80039C80: nop

    music_play(rdram, ctx);
        goto after_33;
    // 0x80039C80: nop

    after_33:
    // 0x80039C84: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80039C88: nop

    // 0x80039C8C: lhu         $a0, 0x54($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X54);
    // 0x80039C90: jal         0x80001074
    // 0x80039C94: nop

    music_dynamic_set(rdram, ctx);
        goto after_34;
    // 0x80039C94: nop

    after_34:
    // 0x80039C98: jal         0x80008168
    // 0x80039C9C: nop

    audspat_jingle_on(rdram, ctx);
        goto after_35;
    // 0x80039C9C: nop

    after_35:
    // 0x80039CA0: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80039CA4: nop

L_80039CA8:
    // 0x80039CA8: andi        $t4, $a2, 0x80
    ctx->r12 = ctx->r6 & 0X80;
    // 0x80039CAC: beq         $t4, $zero, L_80039D20
    if (ctx->r12 == 0) {
        // 0x80039CB0: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80039D20;
    }
    // 0x80039CB0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80039CB4: addiu       $v1, $v1, -0x2B20
    ctx->r3 = ADD32(ctx->r3, -0X2B20);
    // 0x80039CB8: andi        $t5, $a2, 0x7F
    ctx->r13 = ctx->r6 & 0X7F;
    // 0x80039CBC: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80039CC0: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x80039CC4: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x80039CC8: lb          $t7, 0x1D6($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X1D6);
    // 0x80039CCC: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80039CD0: beq         $t7, $t8, L_80039D10
    if (ctx->r15 == ctx->r24) {
        // 0x80039CD4: addiu       $a0, $zero, 0x62
        ctx->r4 = ADD32(0, 0X62);
            goto L_80039D10;
    }
    // 0x80039CD4: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    // 0x80039CD8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80039CDC: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
    // 0x80039CE0: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x80039CE4: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80039CE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80039CEC: lb          $a0, 0x1D6($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X1D6);
    // 0x80039CF0: nop

    // 0x80039CF4: addiu       $a0, $a0, 0x235
    ctx->r4 = ADD32(ctx->r4, 0X235);
    // 0x80039CF8: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x80039CFC: jal         0x8003AC3C
    // 0x80039D00: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    play_taj_voice_clip(rdram, ctx);
        goto after_36;
    // 0x80039D00: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_36:
    // 0x80039D04: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80039D08: b           L_80039D20
    // 0x80039D0C: nop

        goto L_80039D20;
    // 0x80039D0C: nop

L_80039D10:
    // 0x80039D10: jal         0x8009D33C
    // 0x80039D14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    set_menu_id_if_option_equal(rdram, ctx);
        goto after_37;
    // 0x80039D14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_37:
    // 0x80039D18: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80039D1C: nop

L_80039D20:
    // 0x80039D20: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80039D24: andi        $t2, $a2, 0x40
    ctx->r10 = ctx->r6 & 0X40;
    // 0x80039D28: beq         $t2, $zero, L_80039DBC
    if (ctx->r10 == 0) {
        // 0x80039D2C: addiu       $v1, $v1, -0x2B20
        ctx->r3 = ADD32(ctx->r3, -0X2B20);
            goto L_80039DBC;
    }
    // 0x80039D2C: addiu       $v1, $v1, -0x2B20
    ctx->r3 = ADD32(ctx->r3, -0X2B20);
    // 0x80039D30: andi        $t3, $a2, 0xF
    ctx->r11 = ctx->r6 & 0XF;
    // 0x80039D34: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80039D38: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x80039D3C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80039D40: lb          $t5, 0x1D6($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X1D6);
    // 0x80039D44: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x80039D48: beq         $t5, $v0, L_80039D90
    if (ctx->r13 == ctx->r2) {
        // 0x80039D4C: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80039D90;
    }
    // 0x80039D4C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80039D50: ori         $t6, $v0, 0x80
    ctx->r14 = ctx->r2 | 0X80;
    // 0x80039D54: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80039D58: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x80039D5C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80039D60: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
    // 0x80039D64: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x80039D68: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80039D6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80039D70: lb          $a0, 0x1D6($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X1D6);
    // 0x80039D74: nop

    // 0x80039D78: addiu       $a0, $a0, 0x235
    ctx->r4 = ADD32(ctx->r4, 0X235);
    // 0x80039D7C: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x80039D80: jal         0x8003AC3C
    // 0x80039D84: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    play_taj_voice_clip(rdram, ctx);
        goto after_38;
    // 0x80039D84: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_38:
    // 0x80039D88: b           L_8003AB04
    // 0x80039D8C: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB04;
    // 0x80039D8C: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039D90:
    // 0x80039D90: sw          $t0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r8;
    // 0x80039D94: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80039D98: sb          $t1, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r9;
    // 0x80039D9C: jal         0x800C01D8
    // 0x80039DA0: addiu       $a0, $a0, -0x3688
    ctx->r4 = ADD32(ctx->r4, -0X3688);
    transition_begin(rdram, ctx);
        goto after_39;
    // 0x80039DA0: addiu       $a0, $a0, -0x3688
    ctx->r4 = ADD32(ctx->r4, -0X3688);
    after_39:
    // 0x80039DA4: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x80039DA8: jal         0x8003AC3C
    // 0x80039DAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_40;
    // 0x80039DAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_40:
    // 0x80039DB0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80039DB4: nop

    // 0x80039DB8: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
L_80039DBC:
    // 0x80039DBC: b           L_8003AB04
    // 0x80039DC0: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB04;
    // 0x80039DC0: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039DC4:
    // 0x80039DC4: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x80039DC8: jal         0x8005A3C0
    // 0x80039DCC: sb          $t2, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r10;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_41;
    // 0x80039DCC: sb          $t2, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r10;
    after_41:
    // 0x80039DD0: lwc1        $f16, 0xAC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039DD4: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039DD8: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80039DDC: add.d       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f0.d + ctx->f0.d;
    // 0x80039DE0: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x80039DE4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80039DE8: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x80039DEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80039DF0: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80039DF4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80039DF8: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x80039DFC: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039E00: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80039E04: cvt.d.s     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.d = CVT_D_S(ctx->f16.fl);
    // 0x80039E08: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80039E0C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80039E10: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80039E14: bc1f        L_80039E30
    if (!c1cs) {
        // 0x80039E18: lui         $at, 0x404E
        ctx->r1 = S32(0X404E << 16);
            goto L_80039E30;
    }
    // 0x80039E18: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x80039E1C: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x80039E20: sw          $t3, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r11;
    // 0x80039E24: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039E28: nop

    // 0x80039E2C: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
L_80039E30:
    // 0x80039E30: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x80039E34: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80039E38: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80039E3C: bc1f        L_80039E54
    if (!c1cs) {
        // 0x80039E40: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_80039E54;
    }
    // 0x80039E40: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80039E44: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x80039E48: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039E4C: nop

    // 0x80039E50: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
L_80039E54:
    // 0x80039E54: c.lt.d      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.d < ctx->f2.d;
    // 0x80039E58: nop

    // 0x80039E5C: bc1f        L_80039ED0
    if (!c1cs) {
        // 0x80039E60: nop
    
            goto L_80039ED0;
    }
    // 0x80039E60: nop

    // 0x80039E64: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80039E68: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x80039E6C: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x80039E70: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    // 0x80039E74: lbu         $v0, 0x1F7($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1F7);
    // 0x80039E78: sll         $t4, $v1, 4
    ctx->r12 = S32(ctx->r3 << 4);
    // 0x80039E7C: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80039E80: beq         $at, $zero, L_80039E94
    if (ctx->r1 == 0) {
        // 0x80039E84: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80039E94;
    }
    // 0x80039E84: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80039E88: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x80039E8C: b           L_8003AB00
    // 0x80039E90: sb          $t5, 0x1F7($a2)
    MEM_B(0X1F7, ctx->r6) = ctx->r13;
        goto L_8003AB00;
    // 0x80039E90: sb          $t5, 0x1F7($a2)
    MEM_B(0X1F7, ctx->r6) = ctx->r13;
L_80039E94:
    // 0x80039E94: addiu       $v1, $v1, -0x2B20
    ctx->r3 = ADD32(ctx->r3, -0X2B20);
    // 0x80039E98: sb          $zero, 0x1F7($a2)
    MEM_B(0X1F7, ctx->r6) = 0;
    // 0x80039E9C: lb          $a1, 0x0($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X0);
    // 0x80039EA0: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x80039EA4: andi        $t6, $a1, 0xF
    ctx->r14 = ctx->r5 & 0XF;
    // 0x80039EA8: jal         0x8000E1EC
    // 0x80039EAC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    despawn_player_racer(rdram, ctx);
        goto after_42;
    // 0x80039EAC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_42:
    // 0x80039EB0: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80039EB4: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
    // 0x80039EB8: addiu       $a0, $zero, 0x113
    ctx->r4 = ADD32(0, 0X113);
    // 0x80039EBC: jal         0x80001D04
    // 0x80039EC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_43;
    // 0x80039EC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_43:
    // 0x80039EC4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80039EC8: jal         0x800C01D8
    // 0x80039ECC: addiu       $a0, $a0, -0x3690
    ctx->r4 = ADD32(ctx->r4, -0X3690);
    transition_begin(rdram, ctx);
        goto after_44;
    // 0x80039ECC: addiu       $a0, $a0, -0x3690
    ctx->r4 = ADD32(ctx->r4, -0X3690);
    after_44:
L_80039ED0:
    // 0x80039ED0: b           L_8003AB04
    // 0x80039ED4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB04;
    // 0x80039ED4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039ED8:
    // 0x80039ED8: jal         0x8005A3C0
    // 0x80039EDC: nop

    racer_set_dialogue_camera(rdram, ctx);
        goto after_45;
    // 0x80039EDC: nop

    after_45:
    // 0x80039EE0: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x80039EE4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80039EE8: beq         $t8, $zero, L_80039FD4
    if (ctx->r24 == 0) {
        // 0x80039EEC: nop
    
            goto L_80039FD4;
    }
    // 0x80039EEC: nop

    // 0x80039EF0: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039EF4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80039EF8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80039EFC: c.eq.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl == ctx->f12.fl;
    // 0x80039F00: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80039F04: bc1t        L_80039F28
    if (c1cs) {
        // 0x80039F08: lw          $a2, 0xB4($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XB4);
            goto L_80039F28;
    }
    // 0x80039F08: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x80039F0C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80039F10: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80039F14: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x80039F18: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x80039F1C: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80039F20: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x80039F24: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
L_80039F28:
    // 0x80039F28: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x80039F2C: slti        $at, $a2, 0x5
    ctx->r1 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x80039F30: bne         $at, $zero, L_80039F3C
    if (ctx->r1 != 0) {
        // 0x80039F34: nop
    
            goto L_80039F3C;
    }
    // 0x80039F34: nop

    // 0x80039F38: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_80039F3C:
    // 0x80039F3C: lbu         $v0, 0x1F7($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1F7);
    // 0x80039F40: sll         $t0, $a2, 5
    ctx->r8 = S32(ctx->r6 << 5);
    // 0x80039F44: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x80039F48: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80039F4C: beq         $at, $zero, L_80039F5C
    if (ctx->r1 == 0) {
        // 0x80039F50: addu        $t3, $v0, $t0
        ctx->r11 = ADD32(ctx->r2, ctx->r8);
            goto L_80039F5C;
    }
    // 0x80039F50: addu        $t3, $v0, $t0
    ctx->r11 = ADD32(ctx->r2, ctx->r8);
    // 0x80039F54: b           L_8003AB00
    // 0x80039F58: sb          $t3, 0x1F7($v1)
    MEM_B(0X1F7, ctx->r3) = ctx->r11;
        goto L_8003AB00;
    // 0x80039F58: sb          $t3, 0x1F7($v1)
    MEM_B(0X1F7, ctx->r3) = ctx->r11;
L_80039F5C:
    // 0x80039F5C: sb          $t4, 0x1F7($v1)
    MEM_B(0X1F7, ctx->r3) = ctx->r12;
    // 0x80039F60: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039F64: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80039F68: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80039F6C: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80039F70: c.eq.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d == ctx->f4.d;
    // 0x80039F74: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80039F78: bc1f        L_80039FD4
    if (!c1cs) {
        // 0x80039F7C: addiu       $v1, $v1, -0x2B20
        ctx->r3 = ADD32(ctx->r3, -0X2B20);
            goto L_80039FD4;
    }
    // 0x80039F7C: addiu       $v1, $v1, -0x2B20
    ctx->r3 = ADD32(ctx->r3, -0X2B20);
    // 0x80039F80: lb          $t5, 0x0($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X0);
    // 0x80039F84: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80039F88: andi        $t6, $t5, 0x80
    ctx->r14 = ctx->r13 & 0X80;
    // 0x80039F8C: beq         $t6, $zero, L_80039FC8
    if (ctx->r14 == 0) {
        // 0x80039F90: addiu       $a0, $zero, 0x62
        ctx->r4 = ADD32(0, 0X62);
            goto L_80039FC8;
    }
    // 0x80039F90: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    // 0x80039F94: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80039F98: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80039F9C: sb          $t7, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r15;
    // 0x80039FA0: jal         0x800C01D8
    // 0x80039FA4: addiu       $a0, $a0, -0x3688
    ctx->r4 = ADD32(ctx->r4, -0X3688);
    transition_begin(rdram, ctx);
        goto after_46;
    // 0x80039FA4: addiu       $a0, $a0, -0x3688
    ctx->r4 = ADD32(ctx->r4, -0X3688);
    after_46:
    // 0x80039FA8: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80039FAC: sw          $t8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r24;
    // 0x80039FB0: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x80039FB4: jal         0x80001D04
    // 0x80039FB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_47;
    // 0x80039FB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_47:
    // 0x80039FBC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80039FC0: b           L_8003AB00
    // 0x80039FC4: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
        goto L_8003AB00;
    // 0x80039FC4: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
L_80039FC8:
    // 0x80039FC8: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
    // 0x80039FCC: jal         0x8009D33C
    // 0x80039FD0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    set_menu_id_if_option_equal(rdram, ctx);
        goto after_48;
    // 0x80039FD0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_48:
L_80039FD4:
    // 0x80039FD4: b           L_8003AB04
    // 0x80039FD8: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB04;
    // 0x80039FD8: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039FDC:
    // 0x80039FDC: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039FE0: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80039FE4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80039FE8: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80039FEC: c.eq.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d == ctx->f2.d;
    // 0x80039FF0: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039FF4: bc1t        L_8003A020
    if (c1cs) {
        // 0x80039FF8: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_8003A020;
    }
    // 0x80039FF8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80039FFC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003A000: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003A004: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8003A008: mul.d       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8003A00C: add.d       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f2.d + ctx->f16.d;
    // 0x8003A010: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8003A014: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x8003A018: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A01C: nop

L_8003A020:
    // 0x8003A020: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003A024: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003A028: c.eq.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl == ctx->f12.fl;
    // 0x8003A02C: nop

    // 0x8003A030: bc1f        L_8003AB00
    if (!c1cs) {
        // 0x8003A034: nop
    
            goto L_8003AB00;
    }
    // 0x8003A034: nop

    // 0x8003A038: sb          $t0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r8;
    // 0x8003A03C: lw          $t1, 0x78($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X78);
    // 0x8003A040: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8003A044: bne         $t1, $at, L_8003A098
    if (ctx->r9 != ctx->r1) {
        // 0x8003A048: addiu       $t2, $zero, 0x14
        ctx->r10 = ADD32(0, 0X14);
            goto L_8003A098;
    }
    // 0x8003A048: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x8003A04C: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8003A050: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8003A054: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003A058: lwc1        $f18, 0x38($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8003A05C: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8003A060: mul.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8003A064: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003A068: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A06C: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
    // 0x8003A070: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8003A074: sub.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8003A078: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003A07C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003A080: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003A084: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003A088: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8003A08C: jal         0x80022CFC
    // 0x8003A090: nop

    obj_taj_create_balloon(rdram, ctx);
        goto after_49;
    // 0x8003A090: nop

    after_49:
    // 0x8003A094: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
L_8003A098:
    // 0x8003A098: sw          $t2, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r10;
    // 0x8003A09C: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x8003A0A0: jal         0x80001D04
    // 0x8003A0A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_50;
    // 0x8003A0A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_50:
    // 0x8003A0A8: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8003A0AC: nop

    // 0x8003A0B0: lb          $a0, 0x3($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X3);
    // 0x8003A0B4: lb          $a1, 0x1D6($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X1D6);
    // 0x8003A0B8: jal         0x80004B40
    // 0x8003A0BC: nop

    racer_sound_init(rdram, ctx);
        goto after_51;
    // 0x8003A0BC: nop

    after_51:
    // 0x8003A0C0: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8003A0C4: b           L_8003AB00
    // 0x8003A0C8: sw          $v0, 0x118($t3)
    MEM_W(0X118, ctx->r11) = ctx->r2;
        goto L_8003AB00;
    // 0x8003A0C8: sw          $v0, 0x118($t3)
    MEM_W(0X118, ctx->r11) = ctx->r2;
L_8003A0CC:
    // 0x8003A0CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003A0D0: sb          $a3, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r7;
    // 0x8003A0D4: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8003A0D8: sb          $t4, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r12;
    // 0x8003A0DC: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    // 0x8003A0E0: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A0E4: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A0E8: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8003A0EC: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x8003A0F0: lui         $at, 0x429E
    ctx->r1 = S32(0X429E << 16);
    // 0x8003A0F4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8003A0F8: add.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f4.d + ctx->f6.d;
    // 0x8003A0FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003A100: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8003A104: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003A108: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x8003A10C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A110: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003A114: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8003A118: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x8003A11C: bc1f        L_8003A130
    if (!c1cs) {
        // 0x8003A120: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8003A130;
    }
    // 0x8003A120: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003A124: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8003A128: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A12C: nop

L_8003A130:
    // 0x8003A130: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A134: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x8003A138: sll         $t5, $a2, 3
    ctx->r13 = S32(ctx->r6 << 3);
    // 0x8003A13C: bc1f        L_8003A148
    if (!c1cs) {
        // 0x8003A140: or          $a2, $t5, $zero
        ctx->r6 = ctx->r13 | 0;
            goto L_8003A148;
    }
    // 0x8003A140: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8003A144: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8003A148:
    // 0x8003A148: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x8003A14C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003A150: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003A154: beq         $at, $zero, L_8003A164
    if (ctx->r1 == 0) {
        // 0x8003A158: subu        $t6, $v0, $a2
        ctx->r14 = SUB32(ctx->r2, ctx->r6);
            goto L_8003A164;
    }
    // 0x8003A158: subu        $t6, $v0, $a2
    ctx->r14 = SUB32(ctx->r2, ctx->r6);
    // 0x8003A15C: b           L_8003AB00
    // 0x8003A160: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
        goto L_8003AB00;
    // 0x8003A160: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
L_8003A164:
    // 0x8003A164: jal         0x80001D04
    // 0x8003A168: sb          $t7, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r15;
    sound_play(rdram, ctx);
        goto after_52;
    // 0x8003A168: sb          $t7, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r15;
    after_52:
    // 0x8003A16C: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8003A170: lw          $v1, 0x90($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X90);
    // 0x8003A174: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x8003A178: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8003A17C: sb          $zero, 0x39($s0)
    MEM_B(0X39, ctx->r16) = 0;
    // 0x8003A180: sw          $t8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r24;
    // 0x8003A184: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003A188: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8003A18C: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8003A190: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8003A194: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003A198: sub.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8003A19C: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8003A1A0: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8003A1A4: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8003A1A8: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003A1AC: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A1B0: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8003A1B4: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x8003A1B8: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003A1BC: jal         0x80029F18
    // 0x8003A1C0: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_53;
    // 0x8003A1C0: nop

    after_53:
    // 0x8003A1C4: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // 0x8003A1C8: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x8003A1CC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003A1D0: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8003A1D4: nop

    // 0x8003A1D8: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x8003A1DC: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x8003A1E0: b           L_8003AB04
    // 0x8003A1E4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB04;
    // 0x8003A1E4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A1E8:
    // 0x8003A1E8: sb          $a3, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r7;
    // 0x8003A1EC: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A1F0: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A1F4: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8003A1F8: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x8003A1FC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003A200: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8003A204: sub.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d - ctx->f10.d;
    // 0x8003A208: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8003A20C: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8003A210: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8003A214: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x8003A218: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A21C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003A220: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8003A224: nop

    // 0x8003A228: bc1f        L_8003A238
    if (!c1cs) {
        // 0x8003A22C: lw          $v1, 0xB4($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XB4);
            goto L_8003A238;
    }
    // 0x8003A22C: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A230: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8003A234: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
L_8003A238:
    // 0x8003A238: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x8003A23C: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8003A240: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x8003A244: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003A248: beq         $at, $zero, L_8003A258
    if (ctx->r1 == 0) {
        // 0x8003A24C: addu        $t5, $v0, $t2
        ctx->r13 = ADD32(ctx->r2, ctx->r10);
            goto L_8003A258;
    }
    // 0x8003A24C: addu        $t5, $v0, $t2
    ctx->r13 = ADD32(ctx->r2, ctx->r10);
    // 0x8003A250: b           L_8003AB00
    // 0x8003A254: sb          $t5, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r13;
        goto L_8003AB00;
    // 0x8003A254: sb          $t5, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r13;
L_8003A258:
    // 0x8003A258: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
    // 0x8003A25C: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
    // 0x8003A260: b           L_8003AB04
    // 0x8003A264: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB04;
    // 0x8003A264: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A268:
    // 0x8003A268: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003A26C: sb          $a3, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r7;
    // 0x8003A270: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8003A274: sb          $t8, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r24;
    // 0x8003A278: swc1        $f16, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f16.u32l;
    // 0x8003A27C: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A280: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A284: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8003A288: add.d       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f0.d + ctx->f0.d;
    // 0x8003A28C: lui         $at, 0x429E
    ctx->r1 = S32(0X429E << 16);
    // 0x8003A290: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8003A294: add.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d + ctx->f18.d;
    // 0x8003A298: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003A29C: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x8003A2A0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003A2A4: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x8003A2A8: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A2AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003A2B0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8003A2B4: nop

    // 0x8003A2B8: bc1f        L_8003A2D0
    if (!c1cs) {
        // 0x8003A2BC: lw          $a2, 0xB4($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XB4);
            goto L_8003A2D0;
    }
    // 0x8003A2BC: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A2C0: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8003A2C4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A2C8: nop

    // 0x8003A2CC: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
L_8003A2D0:
    // 0x8003A2D0: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x8003A2D4: sll         $t9, $a2, 3
    ctx->r25 = S32(ctx->r6 << 3);
    // 0x8003A2D8: bc1f        L_8003A2E4
    if (!c1cs) {
        // 0x8003A2DC: or          $a2, $t9, $zero
        ctx->r6 = ctx->r25 | 0;
            goto L_8003A2E4;
    }
    // 0x8003A2DC: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8003A2E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8003A2E4:
    // 0x8003A2E4: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x8003A2E8: nop

    // 0x8003A2EC: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003A2F0: beq         $at, $zero, L_8003A300
    if (ctx->r1 == 0) {
        // 0x8003A2F4: subu        $t0, $v0, $a2
        ctx->r8 = SUB32(ctx->r2, ctx->r6);
            goto L_8003A300;
    }
    // 0x8003A2F4: subu        $t0, $v0, $a2
    ctx->r8 = SUB32(ctx->r2, ctx->r6);
    // 0x8003A2F8: b           L_8003AB00
    // 0x8003A2FC: sb          $t0, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r8;
        goto L_8003AB00;
    // 0x8003A2FC: sb          $t0, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r8;
L_8003A300:
    // 0x8003A300: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8003A304: nop

    // 0x8003A308: lb          $a0, 0x3($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X3);
    // 0x8003A30C: lb          $a1, 0x1D6($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X1D6);
    // 0x8003A310: jal         0x80004B40
    // 0x8003A314: nop

    racer_sound_init(rdram, ctx);
        goto after_54;
    // 0x8003A314: nop

    after_54:
    // 0x8003A318: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8003A31C: addiu       $t4, $zero, 0xB4
    ctx->r12 = ADD32(0, 0XB4);
    // 0x8003A320: sw          $v0, 0x118($t1)
    MEM_W(0X118, ctx->r9) = ctx->r2;
    // 0x8003A324: lh          $t2, 0x20($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X20);
    // 0x8003A328: lbu         $a3, 0x13($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X13);
    // 0x8003A32C: lbu         $a2, 0x12($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X12);
    // 0x8003A330: lbu         $a1, 0x11($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X11);
    // 0x8003A334: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8003A338: lh          $t3, 0x22($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X22);
    // 0x8003A33C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8003A340: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003A344: jal         0x80030DE0
    // 0x8003A348: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    slowly_change_fog(rdram, ctx);
        goto after_55;
    // 0x8003A348: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_55:
    // 0x8003A34C: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8003A350: nop

    // 0x8003A354: lbu         $a0, 0xB3($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0XB3);
    // 0x8003A358: jal         0x80000BE0
    // 0x8003A35C: nop

    music_voicelimit_set(rdram, ctx);
        goto after_56;
    // 0x8003A35C: nop

    after_56:
    // 0x8003A360: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8003A364: nop

    // 0x8003A368: lbu         $a0, 0x52($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X52);
    // 0x8003A36C: jal         0x80000B34
    // 0x8003A370: nop

    music_play(rdram, ctx);
        goto after_57;
    // 0x8003A370: nop

    after_57:
    // 0x8003A374: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8003A378: nop

    // 0x8003A37C: lhu         $a0, 0x54($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X54);
    // 0x8003A380: jal         0x80001074
    // 0x8003A384: nop

    music_dynamic_set(rdram, ctx);
        goto after_58;
    // 0x8003A384: nop

    after_58:
    // 0x8003A388: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8003A38C: nop

    // 0x8003A390: lb          $a0, 0x1D6($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X1D6);
    // 0x8003A394: jal         0x800228EC
    // 0x8003A398: nop

    init_racer_for_challenge(rdram, ctx);
        goto after_59;
    // 0x8003A398: nop

    after_59:
    // 0x8003A39C: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A3A0: lwc1        $f14, 0x14($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003A3A4: jal         0x8002342C
    // 0x8003A3A8: nop

    find_furthest_telepoint(rdram, ctx);
        goto after_60;
    // 0x8003A3A8: nop

    after_60:
    // 0x8003A3AC: beq         $v0, $zero, L_8003A3F0
    if (ctx->r2 == 0) {
        // 0x8003A3B0: addiu       $t3, $zero, 0x1E
        ctx->r11 = ADD32(0, 0X1E);
            goto L_8003A3F0;
    }
    // 0x8003A3B0: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x8003A3B4: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003A3B8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003A3BC: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8003A3C0: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003A3C4: nop

    // 0x8003A3C8: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x8003A3CC: lh          $t9, 0x2E($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2E);
    // 0x8003A3D0: nop

    // 0x8003A3D4: sh          $t9, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r25;
    // 0x8003A3D8: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x8003A3DC: nop

    // 0x8003A3E0: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8003A3E4: nop

    // 0x8003A3E8: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x8003A3EC: sh          $t2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r10;
L_8003A3F0:
    // 0x8003A3F0: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    // 0x8003A3F4: b           L_8003AB04
    // 0x8003A3F8: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB04;
    // 0x8003A3F8: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A3FC:
    // 0x8003A3FC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003A400: sb          $a3, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r7;
    // 0x8003A404: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8003A408: sb          $t4, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r12;
    // 0x8003A40C: swc1        $f18, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f18.u32l;
    // 0x8003A410: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A414: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A418: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8003A41C: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x8003A420: lui         $at, 0x429E
    ctx->r1 = S32(0X429E << 16);
    // 0x8003A424: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8003A428: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8003A42C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003A430: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8003A434: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003A438: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x8003A43C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A440: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003A444: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8003A448: addiu       $t7, $zero, 0x15
    ctx->r15 = ADD32(0, 0X15);
    // 0x8003A44C: bc1f        L_8003A464
    if (!c1cs) {
        // 0x8003A450: lw          $a2, 0xB4($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XB4);
            goto L_8003A464;
    }
    // 0x8003A450: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A454: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8003A458: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A45C: nop

    // 0x8003A460: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
L_8003A464:
    // 0x8003A464: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x8003A468: sll         $t5, $a2, 3
    ctx->r13 = S32(ctx->r6 << 3);
    // 0x8003A46C: bc1f        L_8003A478
    if (!c1cs) {
        // 0x8003A470: or          $a2, $t5, $zero
        ctx->r6 = ctx->r13 | 0;
            goto L_8003A478;
    }
    // 0x8003A470: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8003A474: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8003A478:
    // 0x8003A478: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x8003A47C: nop

    // 0x8003A480: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003A484: beq         $at, $zero, L_8003A494
    if (ctx->r1 == 0) {
        // 0x8003A488: subu        $t6, $v0, $a2
        ctx->r14 = SUB32(ctx->r2, ctx->r6);
            goto L_8003A494;
    }
    // 0x8003A488: subu        $t6, $v0, $a2
    ctx->r14 = SUB32(ctx->r2, ctx->r6);
    // 0x8003A48C: b           L_8003AB00
    // 0x8003A490: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
        goto L_8003AB00;
    // 0x8003A490: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
L_8003A494:
    // 0x8003A494: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A498: lwc1        $f14, 0x14($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003A49C: sb          $zero, 0x39($s0)
    MEM_B(0X39, ctx->r16) = 0;
    // 0x8003A4A0: jal         0x8002342C
    // 0x8003A4A4: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
    find_furthest_telepoint(rdram, ctx);
        goto after_61;
    // 0x8003A4A4: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
    after_61:
    // 0x8003A4A8: beq         $v0, $zero, L_8003A4EC
    if (ctx->r2 == 0) {
        // 0x8003A4AC: nop
    
            goto L_8003A4EC;
    }
    // 0x8003A4AC: nop

    // 0x8003A4B0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003A4B4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003A4B8: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8003A4BC: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003A4C0: nop

    // 0x8003A4C4: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8003A4C8: lh          $t8, 0x2E($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2E);
    // 0x8003A4CC: nop

    // 0x8003A4D0: sh          $t8, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r24;
    // 0x8003A4D4: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x8003A4D8: nop

    // 0x8003A4DC: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8003A4E0: nop

    // 0x8003A4E4: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x8003A4E8: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
L_8003A4EC:
    // 0x8003A4EC: b           L_8003AB04
    // 0x8003A4F0: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB04;
    // 0x8003A4F0: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A4F4:
    // 0x8003A4F4: sb          $a3, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r7;
    // 0x8003A4F8: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A4FC: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A500: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8003A504: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x8003A508: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003A50C: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8003A510: sub.d       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f18.d - ctx->f6.d;
    // 0x8003A514: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8003A518: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8003A51C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8003A520: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x8003A524: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A528: nop

    // 0x8003A52C: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8003A530: nop

    // 0x8003A534: bc1f        L_8003A544
    if (!c1cs) {
        // 0x8003A538: lw          $v1, 0xB4($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XB4);
            goto L_8003A544;
    }
    // 0x8003A538: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A53C: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8003A540: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
L_8003A544:
    // 0x8003A544: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x8003A548: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8003A54C: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x8003A550: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003A554: beq         $at, $zero, L_8003A564
    if (ctx->r1 == 0) {
        // 0x8003A558: addu        $t5, $v0, $t2
        ctx->r13 = ADD32(ctx->r2, ctx->r10);
            goto L_8003A564;
    }
    // 0x8003A558: addu        $t5, $v0, $t2
    ctx->r13 = ADD32(ctx->r2, ctx->r10);
    // 0x8003A55C: b           L_8003AB00
    // 0x8003A560: sb          $t5, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r13;
        goto L_8003AB00;
    // 0x8003A560: sb          $t5, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r13;
L_8003A564:
    // 0x8003A564: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
    // 0x8003A568: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x8003A56C: b           L_8003AB04
    // 0x8003A570: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB04;
    // 0x8003A570: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A574:
    // 0x8003A574: lw          $t7, 0x4C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4C);
    // 0x8003A578: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8003A57C: sh          $zero, 0x14($t7)
    MEM_H(0X14, ctx->r15) = 0;
    // 0x8003A580: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8003A584: sb          $t8, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r24;
    // 0x8003A588: sb          $t9, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r25;
    // 0x8003A58C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A590: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A594: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8003A598: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8003A59C: add.d       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f18.d + ctx->f16.d;
    // 0x8003A5A0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8003A5A4: b           L_8003AB00
    // 0x8003A5A8: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
        goto L_8003AB00;
    // 0x8003A5A8: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
L_8003A5AC:
    // 0x8003A5AC: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x8003A5B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003A5B4: lbu         $t0, 0xD($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XD);
    // 0x8003A5B8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8003A5BC: bne         $t0, $at, L_8003A62C
    if (ctx->r8 != ctx->r1) {
        // 0x8003A5C0: swc1        $f4, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
            goto L_8003A62C;
    }
    // 0x8003A5C0: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    // 0x8003A5C4: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A5C8: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003A5CC: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003A5D0: jal         0x8001C524
    // 0x8003A5D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ainode_find_nearest(rdram, ctx);
        goto after_62;
    // 0x8003A5D4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_62:
    // 0x8003A5D8: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003A5DC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8003A5E0: beq         $a0, $at, L_8003A7E0
    if (ctx->r4 == ctx->r1) {
        // 0x8003A5E4: sb          $v0, 0xD($s1)
        MEM_B(0XD, ctx->r17) = ctx->r2;
            goto L_8003A7E0;
    }
    // 0x8003A5E4: sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // 0x8003A5E8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8003A5EC: jal         0x8001CC48
    // 0x8003A5F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_63;
    // 0x8003A5F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_63:
    // 0x8003A5F4: lbu         $a1, 0xD($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XD);
    // 0x8003A5F8: sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // 0x8003A5FC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003A600: jal         0x8001CC48
    // 0x8003A604: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_64;
    // 0x8003A604: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_64:
    // 0x8003A608: lbu         $a1, 0xE($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XE);
    // 0x8003A60C: sb          $v0, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r2;
    // 0x8003A610: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003A614: jal         0x8001CC48
    // 0x8003A618: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_65;
    // 0x8003A618: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_65:
    // 0x8003A61C: lbu         $t1, 0xD($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XD);
    // 0x8003A620: sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // 0x8003A624: b           L_8003A7E0
    // 0x8003A628: sb          $t1, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r9;
        goto L_8003A7E0;
    // 0x8003A628: sb          $t1, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r9;
L_8003A62C:
    // 0x8003A62C: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x8003A630: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003A634: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8003A638: nop

    // 0x8003A63C: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x8003A640: nop

    // 0x8003A644: bc1f        L_8003A688
    if (!c1cs) {
        // 0x8003A648: nop
    
            goto L_8003A688;
    }
    // 0x8003A648: nop

    // 0x8003A64C: lh          $t2, 0x1C($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X1C);
    // 0x8003A650: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x8003A654: bne         $t2, $zero, L_8003A688
    if (ctx->r10 != 0) {
        // 0x8003A658: nop
    
            goto L_8003A688;
    }
    // 0x8003A658: nop

    // 0x8003A65C: beq         $t3, $zero, L_8003A688
    if (ctx->r11 == 0) {
        // 0x8003A660: addiu       $t4, $zero, 0xF0
        ctx->r12 = ADD32(0, 0XF0);
            goto L_8003A688;
    }
    // 0x8003A660: addiu       $t4, $zero, 0xF0
    ctx->r12 = ADD32(0, 0XF0);
    // 0x8003A664: sh          $t4, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r12;
    // 0x8003A668: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8003A66C: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8003A670: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8003A674: div.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8003A678: jal         0x80070750
    // 0x8003A67C: div.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    arctan2_f(rdram, ctx);
        goto after_66;
    // 0x8003A67C: div.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    after_66:
    // 0x8003A680: addiu       $t5, $v0, 0x4000
    ctx->r13 = ADD32(ctx->r2, 0X4000);
    // 0x8003A684: sh          $t5, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r13;
L_8003A688:
    // 0x8003A688: lh          $v0, 0x1C($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X1C);
    // 0x8003A68C: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A690: blez        $v0, L_8003A6A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003A694: subu        $t7, $v0, $t6
        ctx->r15 = SUB32(ctx->r2, ctx->r14);
            goto L_8003A6A0;
    }
    // 0x8003A694: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8003A698: b           L_8003A6A4
    // 0x8003A69C: sh          $t7, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r15;
        goto L_8003A6A4;
    // 0x8003A69C: sh          $t7, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r15;
L_8003A6A0:
    // 0x8003A6A0: sh          $zero, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = 0;
L_8003A6A4:
    // 0x8003A6A4: lh          $t8, 0x1C($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X1C);
    // 0x8003A6A8: lw          $t1, 0xB4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A6AC: slti        $at, $t8, 0x78
    ctx->r1 = SIGNED(ctx->r24) < 0X78 ? 1 : 0;
    // 0x8003A6B0: beq         $at, $zero, L_8003A6E0
    if (ctx->r1 == 0) {
        // 0x8003A6B4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8003A6E0;
    }
    // 0x8003A6B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003A6B8: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x8003A6BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003A6C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003A6C4: jal         0x8001C6C4
    // 0x8003A6C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001C6C4(rdram, ctx);
        goto after_67;
    // 0x8003A6C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_67:
    // 0x8003A6CC: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A6D0: nop

    // 0x8003A6D4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8003A6D8: b           L_8003A7E0
    // 0x8003A6DC: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
        goto L_8003A7E0;
    // 0x8003A6DC: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
L_8003A6E0:
    // 0x8003A6E0: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8003A6E4: lh          $t9, 0x1E($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X1E);
    // 0x8003A6E8: andi        $t0, $a1, 0xFFFF
    ctx->r8 = ctx->r5 & 0XFFFF;
    // 0x8003A6EC: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8003A6F0: subu        $a2, $t9, $t0
    ctx->r6 = SUB32(ctx->r25, ctx->r8);
    // 0x8003A6F4: slt         $at, $a2, $at
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8003A6F8: bne         $at, $zero, L_8003A708
    if (ctx->r1 != 0) {
        // 0x8003A6FC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8003A708;
    }
    // 0x8003A6FC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8003A700: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8003A704: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
L_8003A708:
    // 0x8003A708: slti        $at, $a2, -0x8000
    ctx->r1 = SIGNED(ctx->r6) < -0X8000 ? 1 : 0;
    // 0x8003A70C: beq         $at, $zero, L_8003A718
    if (ctx->r1 == 0) {
        // 0x8003A710: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8003A718;
    }
    // 0x8003A710: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8003A714: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
L_8003A718:
    // 0x8003A718: multu       $a2, $t1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003A71C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003A720: mflo        $t2
    ctx->r10 = lo;
    // 0x8003A724: sra         $t3, $t2, 4
    ctx->r11 = S32(SIGNED(ctx->r10) >> 4);
    // 0x8003A728: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x8003A72C: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x8003A730: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8003A734: nop

    // 0x8003A738: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x8003A73C: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x8003A740: jal         0x800707C4
    // 0x8003A744: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    sins_f(rdram, ctx);
        goto after_68;
    // 0x8003A744: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_68:
    // 0x8003A748: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x8003A74C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8003A750: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003A754: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x8003A758: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8003A75C: jal         0x800707F8
    // 0x8003A760: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    coss_f(rdram, ctx);
        goto after_69;
    // 0x8003A760: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_69:
    // 0x8003A764: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003A768: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8003A76C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003A770: mul.s       $f16, $f12, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8003A774: lwc1        $f3, 0x6150($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, 0X6150);
    // 0x8003A778: lwc1        $f2, 0x6154($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6154);
    // 0x8003A77C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003A780: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8003A784: mul.d       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x8003A788: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8003A78C: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8003A790: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8003A794: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003A798: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8003A79C: mul.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x8003A7A0: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8003A7A4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8003A7A8: jal         0x80011570
    // 0x8003A7AC: nop

    move_object(rdram, ctx);
        goto after_70;
    // 0x8003A7AC: nop

    after_70:
    // 0x8003A7B0: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A7B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003A7B8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8003A7BC: lwc1        $f7, 0x6158($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6158);
    // 0x8003A7C0: cvt.d.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
    // 0x8003A7C4: lwc1        $f6, 0x615C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X615C);
    // 0x8003A7C8: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A7CC: mul.d       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8003A7D0: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8003A7D4: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x8003A7D8: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8003A7DC: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
L_8003A7E0:
    // 0x8003A7E0: jal         0x8001BA74
    // 0x8003A7E4: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    get_racer_objects(rdram, ctx);
        goto after_71;
    // 0x8003A7E4: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_71:
    // 0x8003A7E8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8003A7EC: nop

    // 0x8003A7F0: beq         $t0, $zero, L_8003A96C
    if (ctx->r8 == 0) {
        // 0x8003A7F4: nop
    
            goto L_8003A96C;
    }
    // 0x8003A7F4: nop

    // 0x8003A7F8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003A7FC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A800: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003A804: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003A808: sub.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8003A80C: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003A810: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003A814: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8003A818: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003A81C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003A820: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003A824: sub.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8003A828: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003A82C: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8003A830: jal         0x800C9AD0
    // 0x8003A834: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_72;
    // 0x8003A834: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_72:
    // 0x8003A838: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8003A83C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003A840: nop

    // 0x8003A844: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8003A848: nop

    // 0x8003A84C: bc1f        L_8003A954
    if (!c1cs) {
        // 0x8003A850: nop
    
            goto L_8003A954;
    }
    // 0x8003A850: nop

    // 0x8003A854: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8003A858: jal         0x80069D7C
    // 0x8003A85C: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    cam_get_cameras(rdram, ctx);
        goto after_73;
    // 0x8003A85C: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    after_73:
    // 0x8003A860: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A864: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003A868: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003A86C: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003A870: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8003A874: sub.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8003A878: jal         0x800090C0
    // 0x8003A87C: sub.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f16.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_74;
    // 0x8003A87C: sub.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f16.fl;
    after_74:
    // 0x8003A880: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8003A884: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003A888: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003A88C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8003A890: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8003A894: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003A898: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8003A89C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8003A8A0: div.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8003A8A4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8003A8A8: nop

    // 0x8003A8AC: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8003A8B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003A8B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003A8B8: nop

    // 0x8003A8BC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8003A8C0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x8003A8C4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8003A8C8: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x8003A8CC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8003A8D0: jal         0x80001268
    // 0x8003A8D4: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    music_channel_fade_set(rdram, ctx);
        goto after_75;
    // 0x8003A8D4: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    after_75:
    // 0x8003A8D8: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x8003A8DC: jal         0x80001268
    // 0x8003A8E0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    music_channel_fade_set(rdram, ctx);
        goto after_76;
    // 0x8003A8E0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_76:
    // 0x8003A8E4: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x8003A8E8: jal         0x80001268
    // 0x8003A8EC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    music_channel_fade_set(rdram, ctx);
        goto after_77;
    // 0x8003A8EC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_77:
    // 0x8003A8F0: lbu         $a1, 0x57($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X57);
    // 0x8003A8F4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8003A8F8: jal         0x800011A8
    // 0x8003A8FC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    music_channel_pan_set(rdram, ctx);
        goto after_78;
    // 0x8003A8FC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_78:
    // 0x8003A900: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x8003A904: jal         0x800011A8
    // 0x8003A908: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    music_channel_pan_set(rdram, ctx);
        goto after_79;
    // 0x8003A908: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_79:
    // 0x8003A90C: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x8003A910: jal         0x800011A8
    // 0x8003A914: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    music_channel_pan_set(rdram, ctx);
        goto after_80;
    // 0x8003A914: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_80:
    // 0x8003A918: jal         0x80001170
    // 0x8003A91C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    music_channel_on(rdram, ctx);
        goto after_81;
    // 0x8003A91C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_81:
    // 0x8003A920: jal         0x80001170
    // 0x8003A924: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    music_channel_on(rdram, ctx);
        goto after_82;
    // 0x8003A924: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_82:
    // 0x8003A928: jal         0x80001170
    // 0x8003A92C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    music_channel_on(rdram, ctx);
        goto after_83;
    // 0x8003A92C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_83:
    // 0x8003A930: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8003A934: addiu       $t3, $zero, 0x7F
    ctx->r11 = ADD32(0, 0X7F);
    // 0x8003A938: subu        $a1, $t3, $t2
    ctx->r5 = SUB32(ctx->r11, ctx->r10);
    // 0x8003A93C: andi        $t4, $a1, 0xFF
    ctx->r12 = ctx->r5 & 0XFF;
    // 0x8003A940: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x8003A944: jal         0x80001268
    // 0x8003A948: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    music_channel_fade_set(rdram, ctx);
        goto after_84;
    // 0x8003A948: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_84:
    // 0x8003A94C: b           L_8003A970
    // 0x8003A950: lb          $v1, 0x36($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X36);
        goto L_8003A970;
    // 0x8003A950: lb          $v1, 0x36($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X36);
L_8003A954:
    // 0x8003A954: jal         0x80001114
    // 0x8003A958: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    music_channel_off(rdram, ctx);
        goto after_85;
    // 0x8003A958: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_85:
    // 0x8003A95C: jal         0x80001114
    // 0x8003A960: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    music_channel_off(rdram, ctx);
        goto after_86;
    // 0x8003A960: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_86:
    // 0x8003A964: jal         0x80001114
    // 0x8003A968: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    music_channel_off(rdram, ctx);
        goto after_87;
    // 0x8003A968: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_87:
L_8003A96C:
    // 0x8003A96C: lb          $v1, 0x36($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X36);
L_8003A970:
    // 0x8003A970: lw          $v0, 0xB4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A974: beq         $v1, $zero, L_8003A98C
    if (ctx->r3 == 0) {
        // 0x8003A978: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8003A98C;
    }
    // 0x8003A978: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003A97C: beq         $v1, $at, L_8003AA64
    if (ctx->r3 == ctx->r1) {
        // 0x8003A980: nop
    
            goto L_8003AA64;
    }
    // 0x8003A980: nop

    // 0x8003A984: b           L_8003AAF0
    // 0x8003A988: nop

        goto L_8003AAF0;
    // 0x8003A988: nop

L_8003A98C:
    // 0x8003A98C: lhu         $v1, 0x34($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X34);
    // 0x8003A990: sll         $t5, $v0, 7
    ctx->r13 = S32(ctx->r2 << 7);
    // 0x8003A994: slt         $at, $t5, $v1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003A998: beq         $at, $zero, L_8003A9D0
    if (ctx->r1 == 0) {
        // 0x8003A99C: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8003A9D0;
    }
    // 0x8003A99C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8003A9A0: subu        $t6, $v1, $t5
    ctx->r14 = SUB32(ctx->r3, ctx->r13);
    // 0x8003A9A4: sh          $t6, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r14;
    // 0x8003A9A8: jal         0x80001170
    // 0x8003A9AC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    music_channel_on(rdram, ctx);
        goto after_88;
    // 0x8003A9AC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_88:
    // 0x8003A9B0: lhu         $a1, 0x34($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X34);
    // 0x8003A9B4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8003A9B8: sra         $t7, $a1, 8
    ctx->r15 = S32(SIGNED(ctx->r5) >> 8);
    // 0x8003A9BC: jal         0x80001268
    // 0x8003A9C0: andi        $a1, $t7, 0xFF
    ctx->r5 = ctx->r15 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_89;
    // 0x8003A9C0: andi        $a1, $t7, 0xFF
    ctx->r5 = ctx->r15 & 0XFF;
    after_89:
    // 0x8003A9C4: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
    // 0x8003A9C8: b           L_8003A9FC
    // 0x8003A9CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8003A9FC;
    // 0x8003A9CC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8003A9D0:
    // 0x8003A9D0: jal         0x80001114
    // 0x8003A9D4: sh          $zero, 0x34($s1)
    MEM_H(0X34, ctx->r17) = 0;
    music_channel_off(rdram, ctx);
        goto after_90;
    // 0x8003A9D4: sh          $zero, 0x34($s1)
    MEM_H(0X34, ctx->r17) = 0;
    after_90:
    // 0x8003A9D8: lw          $v1, 0x30($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X30);
    // 0x8003A9DC: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    // 0x8003A9E0: bne         $v1, $zero, L_8003A9FC
    if (ctx->r3 != 0) {
        // 0x8003A9E4: nop
    
            goto L_8003A9FC;
    }
    // 0x8003A9E4: nop

    // 0x8003A9E8: jal         0x8006F94C
    // 0x8003A9EC: addiu       $a1, $zero, 0x384
    ctx->r5 = ADD32(0, 0X384);
    rand_range(rdram, ctx);
        goto after_91;
    // 0x8003A9EC: addiu       $a1, $zero, 0x384
    ctx->r5 = ADD32(0, 0X384);
    after_91:
    // 0x8003A9F0: sw          $v0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r2;
    // 0x8003A9F4: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x8003A9F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8003A9FC:
    // 0x8003A9FC: beq         $v1, $zero, L_8003AA58
    if (ctx->r3 == 0) {
        // 0x8003AA00: nop
    
            goto L_8003AA58;
    }
    // 0x8003AA00: nop

    // 0x8003AA04: jal         0x8000105C
    // 0x8003AA08: nop

    music_channel_get_mask(rdram, ctx);
        goto after_92;
    // 0x8003AA08: nop

    after_92:
    // 0x8003AA0C: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x8003AA10: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x8003AA14: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8003AA18: bne         $t9, $at, L_8003AA58
    if (ctx->r25 != ctx->r1) {
        // 0x8003AA1C: nop
    
            goto L_8003AA58;
    }
    // 0x8003AA1C: nop

    // 0x8003AA20: lw          $t0, 0x2C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X2C);
    // 0x8003AA24: lw          $t1, 0xB4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB4);
    // 0x8003AA28: lw          $t2, 0x30($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X30);
    // 0x8003AA2C: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x8003AA30: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8003AA34: beq         $at, $zero, L_8003AAF0
    if (ctx->r1 == 0) {
        // 0x8003AA38: sw          $t3, 0x2C($s1)
        MEM_W(0X2C, ctx->r17) = ctx->r11;
            goto L_8003AAF0;
    }
    // 0x8003AA38: sw          $t3, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r11;
    // 0x8003AA3C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003AA40: sb          $t5, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r13;
    // 0x8003AA44: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    // 0x8003AA48: jal         0x8006F94C
    // 0x8003AA4C: addiu       $a1, $zero, 0x384
    ctx->r5 = ADD32(0, 0X384);
    rand_range(rdram, ctx);
        goto after_93;
    // 0x8003AA4C: addiu       $a1, $zero, 0x384
    ctx->r5 = ADD32(0, 0X384);
    after_93:
    // 0x8003AA50: b           L_8003AAF0
    // 0x8003AA54: sw          $v0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r2;
        goto L_8003AAF0;
    // 0x8003AA54: sw          $v0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r2;
L_8003AA58:
    // 0x8003AA58: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x8003AA5C: b           L_8003AAF0
    // 0x8003AA60: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
        goto L_8003AAF0;
    // 0x8003AA60: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
L_8003AA64:
    // 0x8003AA64: jal         0x8000105C
    // 0x8003AA68: nop

    music_channel_get_mask(rdram, ctx);
        goto after_94;
    // 0x8003AA68: nop

    after_94:
    // 0x8003AA6C: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x8003AA70: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x8003AA74: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8003AA78: bne         $t6, $at, L_8003AAE4
    if (ctx->r14 != ctx->r1) {
        // 0x8003AA7C: nop
    
            goto L_8003AAE4;
    }
    // 0x8003AA7C: nop

    // 0x8003AA80: lw          $v0, 0xB4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB4);
    // 0x8003AA84: lhu         $t7, 0x34($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X34);
    // 0x8003AA88: sll         $t8, $v0, 7
    ctx->r24 = S32(ctx->r2 << 7);
    // 0x8003AA8C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8003AA90: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8003AA94: slti        $at, $t0, 0x7F01
    ctx->r1 = SIGNED(ctx->r8) < 0X7F01 ? 1 : 0;
    // 0x8003AA98: bne         $at, $zero, L_8003AAA8
    if (ctx->r1 != 0) {
        // 0x8003AA9C: sh          $t9, 0x34($s1)
        MEM_H(0X34, ctx->r17) = ctx->r25;
            goto L_8003AAA8;
    }
    // 0x8003AA9C: sh          $t9, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r25;
    // 0x8003AAA0: addiu       $t1, $zero, 0x7F00
    ctx->r9 = ADD32(0, 0X7F00);
    // 0x8003AAA4: sh          $t1, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r9;
L_8003AAA8:
    // 0x8003AAA8: lw          $t3, 0x2C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X2C);
    // 0x8003AAAC: nop

    // 0x8003AAB0: subu        $t2, $t3, $v0
    ctx->r10 = SUB32(ctx->r11, ctx->r2);
    // 0x8003AAB4: bgez        $t2, L_8003AAC0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8003AAB8: sw          $t2, 0x2C($s1)
        MEM_W(0X2C, ctx->r17) = ctx->r10;
            goto L_8003AAC0;
    }
    // 0x8003AAB8: sw          $t2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r10;
    // 0x8003AABC: sb          $zero, 0x36($s1)
    MEM_B(0X36, ctx->r17) = 0;
L_8003AAC0:
    // 0x8003AAC0: jal         0x80001170
    // 0x8003AAC4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    music_channel_on(rdram, ctx);
        goto after_95;
    // 0x8003AAC4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_95:
    // 0x8003AAC8: lhu         $a1, 0x34($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X34);
    // 0x8003AACC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8003AAD0: sra         $t5, $a1, 8
    ctx->r13 = S32(SIGNED(ctx->r5) >> 8);
    // 0x8003AAD4: jal         0x80001268
    // 0x8003AAD8: andi        $a1, $t5, 0xFF
    ctx->r5 = ctx->r13 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_96;
    // 0x8003AAD8: andi        $a1, $t5, 0xFF
    ctx->r5 = ctx->r13 & 0XFF;
    after_96:
    // 0x8003AADC: b           L_8003AAF0
    // 0x8003AAE0: nop

        goto L_8003AAF0;
    // 0x8003AAE0: nop

L_8003AAE4:
    // 0x8003AAE4: sb          $zero, 0x36($s1)
    MEM_B(0X36, ctx->r17) = 0;
    // 0x8003AAE8: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x8003AAEC: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
L_8003AAF0:
    // 0x8003AAF0: jal         0x8000105C
    // 0x8003AAF4: nop

    music_channel_get_mask(rdram, ctx);
        goto after_97;
    // 0x8003AAF4: nop

    after_97:
    // 0x8003AAF8: andi        $t7, $v0, 0xBFFF
    ctx->r15 = ctx->r2 & 0XBFFF;
    // 0x8003AAFC: sh          $t7, 0x28($s1)
    MEM_H(0X28, ctx->r17) = ctx->r15;
L_8003AB00:
    // 0x8003AB00: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003AB04:
    // 0x8003AB04: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
    // 0x8003AB08: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003AB0C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003AB10: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
    // 0x8003AB14: jal         0x8002B0F4
    // 0x8003AB18: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    get_level_segment_waves(rdram, ctx);
        goto after_98;
    // 0x8003AB18: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    after_98:
    // 0x8003AB1C: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x8003AB20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003AB24: beq         $v0, $zero, L_8003AB98
    if (ctx->r2 == 0) {
        // 0x8003AB28: addiu       $a2, $v0, -0x1
        ctx->r6 = ADD32(ctx->r2, -0X1);
            goto L_8003AB98;
    }
    // 0x8003AB28: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    // 0x8003AB2C: bltz        $a2, L_8003AB98
    if (SIGNED(ctx->r6) < 0) {
        // 0x8003AB30: sll         $a0, $a2, 2
        ctx->r4 = S32(ctx->r6 << 2);
            goto L_8003AB98;
    }
    // 0x8003AB30: sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6 << 2);
    // 0x8003AB34: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8003AB38: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x8003AB3C: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
L_8003AB40:
    // 0x8003AB40: nop

    // 0x8003AB44: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8003AB48: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8003AB4C: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8003AB50: lb          $v1, 0x10($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X10);
    // 0x8003AB54: nop

    // 0x8003AB58: beq         $a2, $v1, L_8003AB90
    if (ctx->r6 == ctx->r3) {
        // 0x8003AB5C: nop
    
            goto L_8003AB90;
    }
    // 0x8003AB5C: nop

    // 0x8003AB60: beq         $a1, $v1, L_8003AB90
    if (ctx->r5 == ctx->r3) {
        // 0x8003AB64: nop
    
            goto L_8003AB90;
    }
    // 0x8003AB64: nop

    // 0x8003AB68: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8003AB6C: nop

    // 0x8003AB70: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8003AB74: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    // 0x8003AB78: nop

    // 0x8003AB7C: bc1f        L_8003AB90
    if (!c1cs) {
        // 0x8003AB80: nop
    
            goto L_8003AB90;
    }
    // 0x8003AB80: nop

    // 0x8003AB84: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003AB88: nop

    // 0x8003AB8C: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
L_8003AB90:
    // 0x8003AB90: bgez        $a0, L_8003AB40
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8003AB94: lw          $t8, 0x94($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X94);
            goto L_8003AB40;
    }
    // 0x8003AB94: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
L_8003AB98:
    // 0x8003AB98: lw          $t0, 0x78($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X78);
    // 0x8003AB9C: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8003ABA0: beq         $t0, $zero, L_8003ABB4
    if (ctx->r8 == 0) {
        // 0x8003ABA4: sh          $zero, 0x4($s0)
        MEM_H(0X4, ctx->r16) = 0;
            goto L_8003ABB4;
    }
    // 0x8003ABA4: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x8003ABA8: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003ABAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003ABB0: swc1        $f4, -0x2B30($at)
    MEM_W(-0X2B30, ctx->r1) = ctx->f4.u32l;
L_8003ABB4:
    // 0x8003ABB4: lb          $t1, 0x6B($sp)
    ctx->r9 = MEM_B(ctx->r29, 0X6B);
    // 0x8003ABB8: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8003ABBC: beq         $t1, $zero, L_8003ABE4
    if (ctx->r9 == 0) {
        // 0x8003ABC0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8003ABE4;
    }
    // 0x8003ABC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003ABC4: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003ABC8: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003ABCC: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003ABD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003ABD4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8003ABD8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8003ABDC: jal         0x8003FC44
    // 0x8003ABE0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_99;
    // 0x8003ABE0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_99:
L_8003ABE4:
    // 0x8003ABE4: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003ABE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003ABEC: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8003ABF0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8003ABF4: nop

    // 0x8003ABF8: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8003ABFC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003AC00: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003AC04: nop

    // 0x8003AC08: cvt.w.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_D(ctx->f10.d);
    // 0x8003AC0C: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8003AC10: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8003AC14: jal         0x80061C0C
    // 0x8003AC18: sh          $t2, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r10;
    func_80061C0C(rdram, ctx);
        goto after_100;
    // 0x8003AC18: sh          $t2, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r10;
    after_100:
    // 0x8003AC1C: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    // 0x8003AC20: jal         0x800AFC3C
    // 0x8003AC24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_101;
    // 0x8003AC24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_101:
    // 0x8003AC28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003AC2C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8003AC30: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8003AC34: jr          $ra
    // 0x8003AC38: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8003AC38: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_8002FD74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FD74: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x8002FD78: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x8002FD7C: swc1        $f14, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f14.u32l;
    // 0x8002FD80: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8002FD84: blez        $a0, L_8002FF60
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8002FD88: sw          $a3, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r7;
            goto L_8002FF60;
    }
    // 0x8002FD88: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8002FD8C: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x8002FD90: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8002FD94: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FD98: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FD9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002FDA0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8002FDA4: bne         $at, $zero, L_8002FF10
    if (ctx->r1 != 0) {
        // 0x8002FDA8: mov.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
            goto L_8002FF10;
    }
    // 0x8002FDA8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x8002FDAC: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x8002FDB0: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x8002FDB4: beq         $t6, $zero, L_8002FE2C
    if (ctx->r14 == 0) {
        // 0x8002FDB8: sll         $t8, $a0, 4
        ctx->r24 = S32(ctx->r4 << 4);
            goto L_8002FE2C;
    }
    // 0x8002FDB8: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x8002FDBC: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x8002FDC0: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002FDC4: nop

    // 0x8002FDC8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8002FDCC: nop

    // 0x8002FDD0: bc1f        L_8002FDE0
    if (!c1cs) {
        // 0x8002FDD4: nop
    
            goto L_8002FDE0;
    }
    // 0x8002FDD4: nop

    // 0x8002FDD8: b           L_8002FDF4
    // 0x8002FDDC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_8002FDF4;
    // 0x8002FDDC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_8002FDE0:
    // 0x8002FDE0: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8002FDE4: nop

    // 0x8002FDE8: bc1f        L_8002FDF4
    if (!c1cs) {
        // 0x8002FDEC: nop
    
            goto L_8002FDF4;
    }
    // 0x8002FDEC: nop

    // 0x8002FDF0: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8002FDF4:
    // 0x8002FDF4: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002FDF8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8002FDFC: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x8002FE00: nop

    // 0x8002FE04: bc1f        L_8002FE14
    if (!c1cs) {
        // 0x8002FE08: nop
    
            goto L_8002FE14;
    }
    // 0x8002FE08: nop

    // 0x8002FE0C: b           L_8002FE28
    // 0x8002FE10: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_8002FE28;
    // 0x8002FE10: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_8002FE14:
    // 0x8002FE14: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8002FE18: nop

    // 0x8002FE1C: bc1f        L_8002FE28
    if (!c1cs) {
        // 0x8002FE20: nop
    
            goto L_8002FE28;
    }
    // 0x8002FE20: nop

    // 0x8002FE24: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
L_8002FE28:
    // 0x8002FE28: beq         $v1, $a0, L_8002FF10
    if (ctx->r3 == ctx->r4) {
        // 0x8002FE2C: sll         $t7, $v1, 4
        ctx->r15 = S32(ctx->r3 << 4);
            goto L_8002FF10;
    }
L_8002FE2C:
    // 0x8002FE2C: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x8002FE30: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x8002FE34: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
L_8002FE38:
    // 0x8002FE38: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002FE3C: nop

    // 0x8002FE40: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8002FE44: nop

    // 0x8002FE48: bc1f        L_8002FE58
    if (!c1cs) {
        // 0x8002FE4C: nop
    
            goto L_8002FE58;
    }
    // 0x8002FE4C: nop

    // 0x8002FE50: b           L_8002FE6C
    // 0x8002FE54: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_8002FE6C;
    // 0x8002FE54: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_8002FE58:
    // 0x8002FE58: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8002FE5C: nop

    // 0x8002FE60: bc1f        L_8002FE6C
    if (!c1cs) {
        // 0x8002FE64: nop
    
            goto L_8002FE6C;
    }
    // 0x8002FE64: nop

    // 0x8002FE68: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8002FE6C:
    // 0x8002FE6C: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8002FE70: nop

    // 0x8002FE74: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x8002FE78: nop

    // 0x8002FE7C: bc1f        L_8002FE8C
    if (!c1cs) {
        // 0x8002FE80: nop
    
            goto L_8002FE8C;
    }
    // 0x8002FE80: nop

    // 0x8002FE84: b           L_8002FEA0
    // 0x8002FE88: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_8002FEA0;
    // 0x8002FE88: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_8002FE8C:
    // 0x8002FE8C: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8002FE90: nop

    // 0x8002FE94: bc1f        L_8002FEA0
    if (!c1cs) {
        // 0x8002FE98: nop
    
            goto L_8002FEA0;
    }
    // 0x8002FE98: nop

    // 0x8002FE9C: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
L_8002FEA0:
    // 0x8002FEA0: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8002FEA4: nop

    // 0x8002FEA8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8002FEAC: nop

    // 0x8002FEB0: bc1f        L_8002FEC0
    if (!c1cs) {
        // 0x8002FEB4: nop
    
            goto L_8002FEC0;
    }
    // 0x8002FEB4: nop

    // 0x8002FEB8: b           L_8002FED4
    // 0x8002FEBC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_8002FED4;
    // 0x8002FEBC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_8002FEC0:
    // 0x8002FEC0: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8002FEC4: nop

    // 0x8002FEC8: bc1f        L_8002FED4
    if (!c1cs) {
        // 0x8002FECC: nop
    
            goto L_8002FED4;
    }
    // 0x8002FECC: nop

    // 0x8002FED0: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8002FED4:
    // 0x8002FED4: lwc1        $f16, 0x18($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8002FED8: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x8002FEDC: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x8002FEE0: nop

    // 0x8002FEE4: bc1f        L_8002FEF4
    if (!c1cs) {
        // 0x8002FEE8: nop
    
            goto L_8002FEF4;
    }
    // 0x8002FEE8: nop

    // 0x8002FEEC: b           L_8002FF08
    // 0x8002FEF0: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_8002FF08;
    // 0x8002FEF0: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_8002FEF4:
    // 0x8002FEF4: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8002FEF8: nop

    // 0x8002FEFC: bc1f        L_8002FF08
    if (!c1cs) {
        // 0x8002FF00: nop
    
            goto L_8002FF08;
    }
    // 0x8002FF00: nop

    // 0x8002FF04: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
L_8002FF08:
    // 0x8002FF08: bne         $a1, $a2, L_8002FE38
    if (ctx->r5 != ctx->r6) {
        // 0x8002FF0C: nop
    
            goto L_8002FE38;
    }
    // 0x8002FF0C: nop

L_8002FF10:
    // 0x8002FF10: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8002FF14: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8002FF18: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8002FF1C: nop

    // 0x8002FF20: bc1f        L_8002FF64
    if (!c1cs) {
        // 0x8002FF24: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002FF64;
    }
    // 0x8002FF24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002FF28: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x8002FF2C: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8002FF30: bc1f        L_8002FF64
    if (!c1cs) {
        // 0x8002FF34: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002FF64;
    }
    // 0x8002FF34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002FF38: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8002FF3C: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8002FF40: bc1f        L_8002FF64
    if (!c1cs) {
        // 0x8002FF44: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002FF64;
    }
    // 0x8002FF44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002FF48: c.le.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl <= ctx->f10.fl;
    // 0x8002FF4C: nop

    // 0x8002FF50: bc1f        L_8002FF64
    if (!c1cs) {
        // 0x8002FF54: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002FF64;
    }
    // 0x8002FF54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002FF58: jr          $ra
    // 0x8002FF5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8002FF5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8002FF60:
    // 0x8002FF60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002FF64:
    // 0x8002FF64: jr          $ra
    // 0x8002FF68: nop

    return;
    // 0x8002FF68: nop

;}
