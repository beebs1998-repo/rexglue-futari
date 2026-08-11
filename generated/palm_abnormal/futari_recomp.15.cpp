#include "futari_init.h"

DEFINE_REX_FUNC(sub_882647D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x882647D8;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x882647F8;
	sub_880A6EC0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bgt cr6,0x882649c0
	if (ctx.cr6.gt) goto loc_882649C0;
	// beq cr6,0x8826494c
	if (ctx.cr6.eq) goto loc_8826494C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x882648d8
	if (ctx.cr6.eq) goto loc_882648D8;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x882648a0
	if (ctx.cr6.eq) goto loc_882648A0;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x88264b20
	if (!ctx.cr6.eq) goto loc_88264B20;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x882648f8
	if (!ctx.cr6.eq) goto loc_882648F8;
	// lis r11,-30680
	ctx.r11.s64 = -2010644480;
	// lwz r9,8(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 8);
	// lis r8,120
	ctx.r8.s64 = 7864320;
	// addi r10,r11,29624
	ctx.r10.s64 = ctx.r11.s64 + 29624;
	// cmpw cr6,r9,r8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, ctx.xer);
	// addi r11,r10,8
	ctx.r11.s64 = ctx.r10.s64 + 8;
	// bgt cr6,0x88264850
	if (ctx.cr6.gt) goto loc_88264850;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_88264850:
	// li r10,4
	ctx.r10.s64 = 4;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,16(r28)
	REX_STORE_U32(ctx.r28.u32 + 16, ctx.r10.u32);
	// lis r8,-30684
	ctx.r8.s64 = -2010906624;
	// lwz r6,4(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r4,r8,29464
	ctx.r4.s64 = ctx.r8.s64 + 29464;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// stw r6,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// bl 0x880a6320
	ctx.lr = 0x88264884;
	sub_880A6320(ctx, base);
	// li r5,192
	ctx.r5.s64 = 192;
	// li r4,7
	ctx.r4.s64 = 7;
	// stw r5,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_882648A0:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x882648f8
	if (!ctx.cr6.eq) goto loc_882648F8;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,10888
	ctx.r4.s64 = ctx.r11.s64 + 10888;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880a6b28
	ctx.lr = 0x882648C0;
	sub_880A6B28(ctx, base);
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r3,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_882648D8:
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// lwz r10,5724(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 5724);
	// addi r9,r11,28168
	ctx.r9.s64 = ctx.r11.s64 + 28168;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88264b20
	if (!ctx.cr6.eq) goto loc_88264B20;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88264918
	if (ctx.cr6.eq) goto loc_88264918;
loc_882648F8:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88264b20
	if (ctx.cr0.gt) goto loc_88264B20;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88264918:
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,10560
	ctx.r4.s64 = ctx.r11.s64 + 10560;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880a6b28
	ctx.lr = 0x8826492C;
	sub_880A6B28(ctx, base);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r3,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_8826494C:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88264990
	if (ctx.cr6.eq) goto loc_88264990;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88264b20
	if (ctx.cr0.gt) goto loc_88264B20;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880a6918
	ctx.lr = 0x88264970;
	sub_880A6918(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,28(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x880a6918
	ctx.lr = 0x8826497C;
	sub_880A6918(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88264990:
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// lwz r10,5724(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 5724);
	// addi r9,r11,28168
	ctx.r9.s64 = ctx.r11.s64 + 28168;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88264b20
	if (!ctx.cr6.eq) goto loc_88264B20;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,8
	ctx.r10.s64 = 8;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_882649C0:
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// beq cr6,0x88264a90
	if (ctx.cr6.eq) goto loc_88264A90;
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// beq cr6,0x88264a14
	if (ctx.cr6.eq) goto loc_88264A14;
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// bne cr6,0x88264b20
	if (!ctx.cr6.eq) goto loc_88264B20;
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// lwz r10,5724(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 5724);
	// addi r9,r11,28168
	ctx.r9.s64 = ctx.r11.s64 + 28168;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88264b20
	if (!ctx.cr6.eq) goto loc_88264B20;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88264b20
	if (ctx.cr0.gt) goto loc_88264B20;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880a64a8
	ctx.lr = 0x88264A08;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88264A14:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88264a4c
	if (ctx.cr6.eq) goto loc_88264A4C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88264b20
	if (ctx.cr0.gt) goto loc_88264B20;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r4,24(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bl 0x880a6918
	ctx.lr = 0x88264A40;
	sub_880A6918(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88264A4C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880a6970
	ctx.lr = 0x88264A58;
	sub_880A6970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88264b20
	if (!ctx.cr6.eq) goto loc_88264B20;
	// lis r11,-30698
	ctx.r11.s64 = -2011824128;
	// lwz r3,24(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,16616
	ctx.r4.s64 = ctx.r11.s64 + 16616;
	// bl 0x880a6800
	ctx.lr = 0x88264A74;
	sub_880A6800(ctx, base);
	// li r10,40
	ctx.r10.s64 = 40;
	// li r9,112
	ctx.r9.s64 = 112;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88264A90:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x882648f8
	if (!ctx.cr6.eq) goto loc_882648F8;
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,10328
	ctx.r4.s64 = ctx.r11.s64 + 10328;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880a6b28
	ctx.lr = 0x88264AB0;
	sub_880A6B28(ctx, base);
	// stw r3,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// li r30,0
	ctx.r30.s64 = 0;
loc_88264AB8:
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// lis r11,-30685
	ctx.r11.s64 = -2010972160;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,10096
	ctx.r4.s64 = ctx.r11.s64 + 10096;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880a6b28
	ctx.lr = 0x88264AD0;
	sub_880A6B28(ctx, base);
	// addi r30,r30,32
	ctx.r30.s64 = ctx.r30.s64 + 32;
	// cmpwi cr6,r30,256
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 256, ctx.xer);
	// blt cr6,0x88264ab8
	if (ctx.cr6.lt) goto loc_88264AB8;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// stw r11,16(r28)
	REX_STORE_U32(ctx.r28.u32 + 16, ctx.r11.u32);
	// lis r8,280
	ctx.r8.s64 = 18350080;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30684
	ctx.r7.s64 = -2010906624;
	// stw r8,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,29464
	ctx.r4.s64 = ctx.r7.s64 + 29464;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x880a6320
	ctx.lr = 0x88264B10;
	sub_880A6320(ctx, base);
	// li r6,272
	ctx.r6.s64 = 272;
	// li r5,9
	ctx.r5.s64 = 9;
	// stw r6,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
	// stw r5,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
loc_88264B20:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88264B30) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x88264B38;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88264B58;
	sub_880A6EC0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bgt cr6,0x88264c64
	if (ctx.cr6.gt) goto loc_88264C64;
	// beq cr6,0x88264c10
	if (ctx.cr6.eq) goto loc_88264C10;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88264ba4
	if (ctx.cr6.eq) goto loc_88264BA4;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x88264c9c
	if (!ctx.cr6.eq) goto loc_88264C9C;
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// lwz r10,5724(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,28168
	ctx.r9.s64 = ctx.r11.s64 + 28168;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88264c9c
	if (!ctx.cr6.eq) goto loc_88264C9C;
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88264BA4:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88264c9c
	if (ctx.cr0.gt) goto loc_88264C9C;
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,2
	ctx.r10.s64 = 2;
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// stw r11,16(r28)
	REX_STORE_U32(ctx.r28.u32 + 16, ctx.r11.u32);
	// lis r8,240
	ctx.r8.s64 = 15728640;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30684
	ctx.r7.s64 = -2010906624;
	// stw r8,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,29464
	ctx.r4.s64 = ctx.r7.s64 + 29464;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6320
	ctx.lr = 0x88264BE8;
	sub_880A6320(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r6,3
	ctx.r6.s64 = 3;
	// li r5,16
	ctx.r5.s64 = 16;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// stw r5,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88264C10:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88264c9c
	if (ctx.cr0.gt) goto loc_88264C9C;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r10,-30685
	ctx.r10.s64 = -2010972160;
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// addi r4,r10,12664
	ctx.r4.s64 = ctx.r10.s64 + 12664;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6b28
	ctx.lr = 0x88264C44;
	sub_880A6B28(ctx, base);
	// li r9,100
	ctx.r9.s64 = 100;
	// li r8,256
	ctx.r8.s64 = 256;
	// stw r3,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r3.u32);
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88264C64:
	// cmpwi cr6,r11,100
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 100, ctx.xer);
	// bne cr6,0x88264c9c
	if (!ctx.cr6.eq) goto loc_88264C9C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,24(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x880a6970
	ctx.lr = 0x88264C78;
	sub_880A6970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88264c9c
	if (!ctx.cr6.eq) goto loc_88264C9C;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88264c9c
	if (ctx.cr0.gt) goto loc_88264C9C;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a64a8
	ctx.lr = 0x88264C9C;
	sub_880A64A8(ctx, base);
loc_88264C9C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88264CA8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8808114c
	ctx.lr = 0x88264CB0;
	__savegprlr_25(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r27,2304(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88264CD0;
	sub_880A6EC0(ctx, base);
	// lwz r11,80(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r25,4
	ctx.r25.s64 = 4;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r26,1
	ctx.r26.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x88264d70
	if (ctx.cr6.lt) goto loc_88264D70;
	// bne cr6,0x88264d9c
	if (!ctx.cr6.eq) goto loc_88264D9C;
	// lwz r11,84(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,84(r3)
	REX_STORE_U32(ctx.r3.u32 + 84, ctx.r11.u32);
	// bgt 0x88264d9c
	if (ctx.cr0.gt) goto loc_88264D9C;
	// stw r25,16(r27)
	REX_STORE_U32(ctx.r27.u32 + 16, ctx.r25.u32);
	// li r11,3
	ctx.r11.s64 = 3;
	// li r3,24
	ctx.r3.s64 = 24;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x8812f858
	ctx.lr = 0x88264D14;
	sub_8812F858(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lwz r10,72(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// li r3,32
	ctx.r3.s64 = 32;
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// subfic r7,r8,60
	ctx.xer.ca = ctx.r8.u32 <= 60;
	ctx.r7.u64 = static_cast<uint64_t>(60) - ctx.r8.u64;
	// rlwinm r6,r7,17,0,14
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 17) & 0xFFFE0000;
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x8812f858
	ctx.lr = 0x88264D38;
	sub_8812F858(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// lis r4,-30684
	ctx.r4.s64 = -2010906624;
	// addi r3,r11,294
	ctx.r3.s64 = ctx.r11.s64 + 294;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r3,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 16) & 0xFFFF0000;
	// addi r4,r4,29464
	ctx.r4.s64 = ctx.r4.s64 + 29464;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6320
	ctx.lr = 0x88264D5C;
	sub_880A6320(ctx, base);
	// lwz r10,72(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// stw r29,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r29.u32);
	// neg r9,r10
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// stw r9,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// b 0x88264d9c
	goto loc_88264D9C;
loc_88264D70:
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// lwz r10,5724(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 5724);
	// addi r9,r11,28168
	ctx.r9.s64 = ctx.r11.s64 + 28168;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x88264d9c
	if (!ctx.cr6.eq) goto loc_88264D9C;
	// stw r26,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r26.u32);
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x8812f858
	ctx.lr = 0x88264D90;
	sub_8812F858(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
loc_88264D9C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bgt cr6,0x88265058
	if (ctx.cr6.gt) goto loc_88265058;
	// lis r12,-30682
	ctx.r12.s64 = -2010775552;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,19904
	ctx.r12.s64 = ctx.r12.s64 + 19904;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_88264DF0;
	case 1:
		goto loc_88264E4C;
	case 2:
		goto loc_88265058;
	case 3:
		goto loc_88265058;
	case 4:
		goto loc_88265058;
	case 5:
		goto loc_88264F74;
	case 6:
		goto loc_88265058;
	case 7:
		goto loc_88265058;
	case 8:
		goto loc_88265058;
	case 9:
		goto loc_88265058;
	case 10:
		goto loc_88265058;
	case 11:
		goto loc_8826502C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_88264DF0:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88265058
	if (ctx.cr0.gt) goto loc_88265058;
	// stw r29,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// lis r11,-30698
	ctx.r11.s64 = -2011824128;
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r29,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// addi r4,r11,16728
	ctx.r4.s64 = ctx.r11.s64 + 16728;
	// lwz r3,24(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// bl 0x880a6800
	ctx.lr = 0x88264E20;
	sub_880A6800(ctx, base);
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// stw r29,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// stw r26,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r29,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r29.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8808119c
	__restgprlr_25(ctx, base);
	return;
loc_88264E4C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x880a6648
	ctx.lr = 0x88264E58;
	sub_880A6648(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88265058
	if (!ctx.cr6.eq) goto loc_88265058;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x880a6970
	ctx.lr = 0x88264E6C;
	sub_880A6970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88265058
	if (!ctx.cr6.eq) goto loc_88265058;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88264e9c
	if (ctx.cr6.eq) goto loc_88264E9C;
loc_88264E80:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88265058
	if (ctx.cr0.gt) goto loc_88265058;
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8808119c
	__restgprlr_25(ctx, base);
	return;
loc_88264E9C:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// bge 0x88265058
	if (!ctx.cr0.lt) goto loc_88265058;
	// lwz r9,36(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// lis r10,-30685
	ctx.r10.s64 = -2010972160;
	// lwz r8,32(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// clrlwi r6,r9,31
	ctx.r6.u64 = ctx.r9.u32 & 0x1;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// clrlwi r9,r8,31
	ctx.r9.u64 = ctx.r8.u32 & 0x1;
	// lwz r7,48(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// addi r4,r10,12456
	ctx.r4.s64 = ctx.r10.s64 + 12456;
	// lwz r10,52(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r8,56(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r7,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// stw r10,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r8,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// bl 0x880a6b28
	ctx.lr = 0x88264EF8;
	sub_880A6B28(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r8,36(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,32(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// addi r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 1;
	// lwz r6,40(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// addic. r11,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r11.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// stw r7,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r7.u32);
	// stw r4,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r4.u32);
	// stw r5,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r5.u32);
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bgt 0x88265058
	if (ctx.cr0.gt) goto loc_88265058;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// addi r10,r10,-12
	ctx.r10.s64 = ctx.r10.s64 + -12;
	// lwz r9,44(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// li r8,5
	ctx.r8.s64 = 5;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r10,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// stw r25,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r25.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r7,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r7.u32);
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// stw r9,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r9.u32);
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8808119c
	__restgprlr_25(ctx, base);
	return;
loc_88264F74:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x880a6970
	ctx.lr = 0x88264F80;
	sub_880A6970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88265058
	if (!ctx.cr6.eq) goto loc_88265058;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88264e80
	if (!ctx.cr6.eq) goto loc_88264E80;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// lis r10,-30685
	ctx.r10.s64 = -2010972160;
	// lwz r9,68(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,12112
	ctx.r4.s64 = ctx.r10.s64 + 12112;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x880a6b28
	ctx.lr = 0x88264FB8;
	sub_880A6B28(ctx, base);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stw r3,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r3.u32);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// blt cr6,0x88264fd8
	if (ctx.cr6.lt) goto loc_88264FD8;
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
loc_88264FD8:
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r26,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r26.u32);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r26,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r26.u32);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r11,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// bgt 0x88265058
	if (ctx.cr0.gt) goto loc_88265058;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r11,11
	ctx.r11.s64 = 11;
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// lis r9,-30698
	ctx.r9.s64 = -2011824128;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,16616
	ctx.r4.s64 = ctx.r9.s64 + 16616;
	// lwz r3,24(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// bl 0x880a6800
	ctx.lr = 0x8826501C;
	sub_880A6800(ctx, base);
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8808119c
	__restgprlr_25(ctx, base);
	return;
loc_8826502C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x880a6648
	ctx.lr = 0x88265038;
	sub_880A6648(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88265058
	if (!ctx.cr6.eq) goto loc_88265058;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88264e80
	if (!ctx.cr6.eq) goto loc_88264E80;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a64a8
	ctx.lr = 0x88265058;
	sub_880A64A8(ctx, base);
loc_88265058:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x8808119c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88265068) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8808115c
	ctx.lr = 0x88265070;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88265090;
	sub_880A6EC0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r9,17704
	ctx.r5.s64 = ctx.r9.s64 + 17704;
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,32(r10)
	REX_STORE_U32(ctx.r10.u32 + 32, ctx.r11.u32);
	// stw r11,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r8,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r8.u32);
	// bl 0x880a6530
	ctx.lr = 0x882650C4;
	sub_880A6530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_882650D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081154
	ctx.lr = 0x882650D8;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,56
	ctx.r5.s64 = 56;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x882650FC;
	sub_880A6EC0(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,30
	ctx.r10.s64 = 30;
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lis r7,120
	ctx.r7.s64 = 7864320;
	// stw r11,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r11.u32);
	// lis r6,280
	ctx.r6.s64 = 18350080;
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// stw r11,32(r27)
	REX_STORE_U32(ctx.r27.u32 + 32, ctx.r11.u32);
	// lis r4,-30684
	ctx.r4.s64 = -2010906624;
	// stw r11,52(r27)
	REX_STORE_U32(ctx.r27.u32 + 52, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// addi r4,r4,29464
	ctx.r4.s64 = ctx.r4.s64 + 29464;
	// stw r6,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// stw r9,16(r28)
	REX_STORE_U32(ctx.r28.u32 + 16, ctx.r9.u32);
	// bl 0x880a6320
	ctx.lr = 0x88265154;
	sub_880A6320(ctx, base);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lis r3,-30682
	ctx.r3.s64 = -2010775552;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r3,18384
	ctx.r5.s64 = ctx.r3.s64 + 18384;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,36(r27)
	REX_STORE_U32(ctx.r27.u32 + 36, ctx.r11.u32);
	// bl 0x880a6530
	ctx.lr = 0x88265170;
	sub_880A6530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88265180) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8808115c
	ctx.lr = 0x88265188;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x882651A8;
	sub_880A6EC0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r9,-30682
	ctx.r9.s64 = -2010775552;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r9,19248
	ctx.r5.s64 = ctx.r9.s64 + 19248;
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stw r8,36(r10)
	REX_STORE_U32(ctx.r10.u32 + 36, ctx.r8.u32);
	// bl 0x880a6530
	ctx.lr = 0x882651D4;
	sub_880A6530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_882651E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8808115c
	ctx.lr = 0x882651E8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,88
	ctx.r5.s64 = 88;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88265208;
	sub_880A6EC0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lis r6,-30669
	ctx.r6.s64 = -2009923584;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lis r5,16838
	ctx.r5.s64 = 1103495168;
	// stw r11,80(r3)
	REX_STORE_U32(ctx.r3.u32 + 80, ctx.r11.u32);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// ori r4,r5,20077
	ctx.r4.u64 = ctx.r5.u64 | 20077;
	// li r8,4
	ctx.r8.s64 = 4;
	// lwz r10,4328(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 4328);
	// li r9,3
	ctx.r9.s64 = 3;
	// li r3,20
	ctx.r3.s64 = 20;
	// mullw r10,r10,r4
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// stw r11,36(r7)
	REX_STORE_U32(ctx.r7.u32 + 36, ctx.r11.u32);
	// stw r11,48(r7)
	REX_STORE_U32(ctx.r7.u32 + 48, ctx.r11.u32);
	// stw r11,68(r7)
	REX_STORE_U32(ctx.r7.u32 + 68, ctx.r11.u32);
	// stw r3,28(r7)
	REX_STORE_U32(ctx.r7.u32 + 28, ctx.r3.u32);
	// stw r8,40(r7)
	REX_STORE_U32(ctx.r7.u32 + 40, ctx.r8.u32);
	// stw r8,44(r7)
	REX_STORE_U32(ctx.r7.u32 + 44, ctx.r8.u32);
	// stw r9,52(r7)
	REX_STORE_U32(ctx.r7.u32 + 52, ctx.r9.u32);
	// stw r9,60(r7)
	REX_STORE_U32(ctx.r7.u32 + 60, ctx.r9.u32);
	// addi r10,r10,12345
	ctx.r10.s64 = ctx.r10.s64 + 12345;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r10,4328(r6)
	REX_STORE_U32(ctx.r6.u32 + 4328, ctx.r10.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// lhz r10,4328(r6)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r6.u32 + 4328);
	// clrlwi r11,r10,31
	ctx.r11.u64 = ctx.r10.u32 & 0x1;
	// stw r5,56(r7)
	REX_STORE_U32(ctx.r7.u32 + 56, ctx.r5.u32);
	// lis r3,-30682
	ctx.r3.s64 = -2010775552;
	// stw r4,64(r7)
	REX_STORE_U32(ctx.r7.u32 + 64, ctx.r4.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r11,32(r7)
	REX_STORE_U32(ctx.r7.u32 + 32, ctx.r11.u32);
	// addi r5,r3,19624
	ctx.r5.s64 = ctx.r3.s64 + 19624;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,72(r7)
	REX_STORE_U32(ctx.r7.u32 + 72, ctx.r10.u32);
	// bl 0x880a6530
	ctx.lr = 0x882652A0;
	sub_880A6530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_882652B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8808115c
	ctx.lr = 0x882652B8;
	__savegprlr_29(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x882652D4;
	sub_880A6EC0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bgt cr6,0x88265414
	if (ctx.cr6.gt) goto loc_88265414;
	// beq cr6,0x882653b8
	if (ctx.cr6.eq) goto loc_882653B8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88265354
	if (ctx.cr6.eq) goto loc_88265354;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x882654d0
	if (!ctx.cr6.eq) goto loc_882654D0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x880a6388
	ctx.lr = 0x88265304;
	sub_880A6388(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x882654d0
	if (!ctx.cr6.eq) goto loc_882654D0;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882654d0
	if (ctx.cr0.gt) goto loc_882654D0;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30682
	ctx.r10.s64 = -2010775552;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,20864
	ctx.r4.s64 = ctx.r10.s64 + 20864;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880a6588
	ctx.lr = 0x88265338;
	sub_880A6588(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x880a63d8
	ctx.lr = 0x8826534C;
	sub_880A63D8(ctx, base);
	// li r8,30
	ctx.r8.s64 = 30;
	// b 0x882654c4
	goto loc_882654C4;
loc_88265354:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882654d0
	if (ctx.cr0.gt) goto loc_882654D0;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30682
	ctx.r10.s64 = -2010775552;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// neg r9,r11
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// addi r4,r10,20960
	ctx.r4.s64 = ctx.r10.s64 + 20960;
	// stw r9,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880a6588
	ctx.lr = 0x88265388;
	sub_880A6588(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r8,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// bl 0x880a63d8
	ctx.lr = 0x8826539C;
	sub_880A63D8(ctx, base);
	// li r7,20
	ctx.r7.s64 = 20;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r7,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r7.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r6.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_882653B8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x880a6388
	ctx.lr = 0x882653C4;
	sub_880A6388(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x882654d0
	if (!ctx.cr6.eq) goto loc_882654D0;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882654d0
	if (ctx.cr0.gt) goto loc_882654D0;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30682
	ctx.r10.s64 = -2010775552;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,20688
	ctx.r4.s64 = ctx.r10.s64 + 20688;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880a6588
	ctx.lr = 0x882653F8;
	sub_880A6588(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x880a63d8
	ctx.lr = 0x8826540C;
	sub_880A63D8(ctx, base);
	// li r8,25
	ctx.r8.s64 = 25;
	// b 0x882654c4
	goto loc_882654C4;
loc_88265414:
	// cmpwi cr6,r11,25
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 25, ctx.xer);
	// beq cr6,0x8826546c
	if (ctx.cr6.eq) goto loc_8826546C;
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// bne cr6,0x882654d0
	if (!ctx.cr6.eq) goto loc_882654D0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x880a6388
	ctx.lr = 0x88265430;
	sub_880A6388(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x882654d0
	if (!ctx.cr6.eq) goto loc_882654D0;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882654d0
	if (ctx.cr0.gt) goto loc_882654D0;
	// lwz r11,15768(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 15768);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,15768(r29)
	REX_STORE_U32(ctx.r29.u32 + 15768, ctx.r11.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_8826546C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// bl 0x880a6388
	ctx.lr = 0x88265478;
	sub_880A6388(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x882654d0
	if (!ctx.cr6.eq) goto loc_882654D0;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882654d0
	if (ctx.cr0.gt) goto loc_882654D0;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-30682
	ctx.r10.s64 = -2010775552;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,20584
	ctx.r4.s64 = ctx.r10.s64 + 20584;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880a6588
	ctx.lr = 0x882654AC;
	sub_880A6588(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// bl 0x880a63d8
	ctx.lr = 0x882654C0;
	sub_880A63D8(ctx, base);
	// li r8,10
	ctx.r8.s64 = 10;
loc_882654C4:
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// stw r7,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
loc_882654D0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_882654E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8808115c
	ctx.lr = 0x882654E8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88265508;
	sub_880A6EC0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lis r9,120
	ctx.r9.s64 = 7864320;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// stw r10,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// lwz r8,8(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x88265534
	if (!ctx.cr6.lt) goto loc_88265534;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
loc_88265534:
	// stw r11,15768(r29)
	REX_STORE_U32(ctx.r29.u32 + 15768, ctx.r11.u32);
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r11,21168
	ctx.r5.s64 = ctx.r11.s64 + 21168;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6530
	ctx.lr = 0x8826554C;
	sub_880A6530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88265558) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x88265560;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88265580;
	sub_880A6EC0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88265668
	if (ctx.cr6.eq) goto loc_88265668;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x882655f8
	if (ctx.cr6.eq) goto loc_882655F8;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x882656d4
	if (!ctx.cr6.eq) goto loc_882656D4;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x882655cc
	if (ctx.cr6.eq) goto loc_882655CC;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x882656d4
	if (ctx.cr0.gt) goto loc_882656D4;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_882655CC:
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,24800
	ctx.r4.s64 = ctx.r11.s64 + 24800;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6588
	ctx.lr = 0x882655E0;
	sub_880A6588(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a64a8
	ctx.lr = 0x882655EC;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_882655F8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,32(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x880a6970
	ctx.lr = 0x88265604;
	sub_880A6970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x882656d4
	if (!ctx.cr6.eq) goto loc_882656D4;
	// lis r11,-30707
	ctx.r11.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,13200
	ctx.r4.s64 = ctx.r11.s64 + 13200;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x88265620;
	sub_880A6800(ctx, base);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,96
	ctx.r8.s64 = 96;
	// addi r7,r10,-11936
	ctx.r7.s64 = ctx.r10.s64 + -11936;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// lwz r3,5728(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 5728);
	// lis r4,360
	ctx.r4.s64 = 23592960;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// cmpw cr6,r3,r7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, ctx.xer);
	// stw r4,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x882656d4
	if (ctx.cr6.eq) goto loc_882656D4;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// b 0x882656c8
	goto loc_882656C8;
loc_88265668:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882656d4
	if (ctx.cr0.gt) goto loc_882656D4;
	// lwz r11,9100(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 9100);
	// lis r10,-30687
	ctx.r10.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,17840
	ctx.r4.s64 = ctx.r10.s64 + 17840;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880a6b28
	ctx.lr = 0x88265694;
	sub_880A6B28(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,96
	ctx.r8.s64 = 96;
	// stw r3,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lis r6,120
	ctx.r6.s64 = 7864320;
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,300
	ctx.r5.s64 = 19660800;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lis r4,-30696
	ctx.r4.s64 = -2011693056;
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r4,r4,-11936
	ctx.r4.s64 = ctx.r4.s64 + -11936;
loc_882656C8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6320
	ctx.lr = 0x882656D4;
	sub_880A6320(ctx, base);
loc_882656D4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_882656E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x882656E8;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88265708;
	sub_880A6EC0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x882657e8
	if (ctx.cr6.eq) goto loc_882657E8;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x88265780
	if (ctx.cr6.eq) goto loc_88265780;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x88265870
	if (!ctx.cr6.eq) goto loc_88265870;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88265754
	if (ctx.cr6.eq) goto loc_88265754;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x88265870
	if (ctx.cr0.gt) goto loc_88265870;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88265754:
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,24800
	ctx.r4.s64 = ctx.r11.s64 + 24800;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6588
	ctx.lr = 0x88265768;
	sub_880A6588(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a64a8
	ctx.lr = 0x88265774;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88265780:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,32(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x880a6970
	ctx.lr = 0x8826578C;
	sub_880A6970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88265870
	if (!ctx.cr6.eq) goto loc_88265870;
	// lis r11,-30707
	ctx.r11.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,13200
	ctx.r4.s64 = ctx.r11.s64 + 13200;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x882657A8;
	sub_880A6800(ctx, base);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,64
	ctx.r8.s64 = 64;
	// addi r7,r10,-11936
	ctx.r7.s64 = ctx.r10.s64 + -11936;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// lwz r3,5728(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 5728);
	// lis r4,360
	ctx.r4.s64 = 23592960;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// cmpw cr6,r3,r7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, ctx.xer);
	// stw r4,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x88265870
	if (ctx.cr6.eq) goto loc_88265870;
	// b 0x8826585c
	goto loc_8826585C;
loc_882657E8:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88265870
	if (ctx.cr0.gt) goto loc_88265870;
	// lwz r11,9100(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 9100);
	// lis r10,-30687
	ctx.r10.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,18176
	ctx.r4.s64 = ctx.r10.s64 + 18176;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880a6b28
	ctx.lr = 0x88265814;
	sub_880A6B28(ctx, base);
	// lis r9,-30595
	ctx.r9.s64 = -2005073920;
	// li r8,10
	ctx.r8.s64 = 10;
	// stw r3,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// li r7,96
	ctx.r7.s64 = 96;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// stw r7,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r7.u32);
	// lwz r11,-11828(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -11828);
	// lis r4,280
	ctx.r4.s64 = 18350080;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// stw r4,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// lbz r3,144(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 144);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8826585c
	if (!ctx.cr6.eq) goto loc_8826585C;
	// lis r11,320
	ctx.r11.s64 = 20971520;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
loc_8826585C:
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6320
	ctx.lr = 0x88265870;
	sub_880A6320(ctx, base);
loc_88265870:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88265880) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x88265888;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x880a6ec0
	ctx.lr = 0x882658A8;
	sub_880A6EC0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r9,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// li r6,80
	ctx.r6.s64 = 80;
	// stw r11,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// li r28,32
	ctx.r28.s64 = 32;
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lis r5,-30682
	ctx.r5.s64 = -2010775552;
	// stw r10,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r7,28(r8)
	REX_STORE_U32(ctx.r8.u32 + 28, ctx.r7.u32);
	// addi r5,r5,21848
	ctx.r5.s64 = ctx.r5.s64 + 21848;
	// stw r6,40(r8)
	REX_STORE_U32(ctx.r8.u32 + 40, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,44(r8)
	REX_STORE_U32(ctx.r8.u32 + 44, ctx.r28.u32);
	// lwz r11,868(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 868);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,868(r29)
	REX_STORE_U32(ctx.r29.u32 + 868, ctx.r11.u32);
	// bl 0x880a6530
	ctx.lr = 0x88265908;
	sub_880A6530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88265918) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x88265920;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x880a6ec0
	ctx.lr = 0x88265940;
	sub_880A6EC0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r9,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// li r6,80
	ctx.r6.s64 = 80;
	// stw r11,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// li r28,32
	ctx.r28.s64 = 32;
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// lis r5,-30682
	ctx.r5.s64 = -2010775552;
	// stw r10,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r7,28(r8)
	REX_STORE_U32(ctx.r8.u32 + 28, ctx.r7.u32);
	// addi r5,r5,22240
	ctx.r5.s64 = ctx.r5.s64 + 22240;
	// stw r6,40(r8)
	REX_STORE_U32(ctx.r8.u32 + 40, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,44(r8)
	REX_STORE_U32(ctx.r8.u32 + 44, ctx.r28.u32);
	// lwz r11,864(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 864);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,864(r29)
	REX_STORE_U32(ctx.r29.u32 + 864, ctx.r11.u32);
	// bl 0x880a6530
	ctx.lr = 0x882659A0;
	sub_880A6530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_882659B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081154
	ctx.lr = 0x882659B8;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r30,2304(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x882659DC;
	sub_880A6EC0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88265bbc
	if (ctx.cr6.eq) goto loc_88265BBC;
	// cmpwi cr6,r10,10
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 10, ctx.xer);
	// beq cr6,0x88265ab4
	if (ctx.cr6.eq) goto loc_88265AB4;
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// bne cr6,0x88265c30
	if (!ctx.cr6.eq) goto loc_88265C30;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88265bc8
	if (!ctx.cr6.eq) goto loc_88265BC8;
	// lwz r11,2304(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 2304);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r9,-30707
	ctx.r9.s64 = -2012413952;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,12248
	ctx.r4.s64 = ctx.r9.s64 + 12248;
	// stw r10,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x880a6800
	ctx.lr = 0x88265A30;
	sub_880A6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8812f858
	ctx.lr = 0x88265A38;
	sub_8812F858(ctx, base);
	// extsh r8,r3
	ctx.r8.s64 = ctx.r3.s16;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x88265a80
	if (ctx.cr6.eq) goto loc_88265A80;
	// lwz r11,868(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 868);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x88265a8c
	if (ctx.cr6.lt) goto loc_88265A8C;
loc_88265A58:
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// addi r4,r11,22808
	ctx.r4.s64 = ctx.r11.s64 + 22808;
	// bl 0x880a6588
	ctx.lr = 0x88265A64;
	sub_880A6588(ctx, base);
	// stw r29,868(r30)
	REX_STORE_U32(ctx.r30.u32 + 868, ctx.r29.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a64a8
	ctx.lr = 0x88265A74;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a4
	__restgprlr_27(ctx, base);
	return;
loc_88265A80:
	// lwz r11,864(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 864);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// blt cr6,0x88265a58
	if (ctx.cr6.lt) goto loc_88265A58;
loc_88265A8C:
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// addi r4,r11,22656
	ctx.r4.s64 = ctx.r11.s64 + 22656;
	// bl 0x880a6588
	ctx.lr = 0x88265A98;
	sub_880A6588(ctx, base);
	// stw r29,864(r30)
	REX_STORE_U32(ctx.r30.u32 + 864, ctx.r29.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a64a8
	ctx.lr = 0x88265AA8;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a4
	__restgprlr_27(ctx, base);
	return;
loc_88265AB4:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88265b48
	if (ctx.cr6.eq) goto loc_88265B48;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bgt 0x88265c30
	if (ctx.cr0.gt) goto loc_88265C30;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r29,4
	ctx.r29.s64 = 4;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lis r9,-30687
	ctx.r9.s64 = -2011103232;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,13536
	ctx.r4.s64 = ctx.r9.s64 + 13536;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6b28
	ctx.lr = 0x88265AF0;
	sub_880A6B28(ctx, base);
	// lwz r6,9100(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 9100);
	// lis r8,220
	ctx.r8.s64 = 14417920;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// lis r7,360
	ctx.r7.s64 = 23592960;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// stw r7,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// beq cr6,0x88265b18
	if (ctx.cr6.eq) goto loc_88265B18;
	// lis r11,20
	ctx.r11.s64 = 1310720;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_88265B18:
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6320
	ctx.lr = 0x88265B2C;
	sub_880A6320(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// stw r10,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a4
	__restgprlr_27(ctx, base);
	return;
loc_88265B48:
	// lwz r10,24(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88265c30
	if (!ctx.cr6.eq) goto loc_88265C30;
	// li r10,20
	ctx.r10.s64 = 20;
	// li r9,128
	ctx.r9.s64 = 128;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// bl 0x8812f858
	ctx.lr = 0x88265B6C;
	sub_8812F858(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lis r6,-30707
	ctx.r6.s64 = -2012413952;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,7528
	ctx.r4.s64 = ctx.r6.s64 + 7528;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6800
	ctx.lr = 0x88265B94;
	sub_880A6800(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,-30687
	ctx.r4.s64 = -2011103232;
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,17360
	ctx.r4.s64 = ctx.r4.s64 + 17360;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6b28
	ctx.lr = 0x88265BB0;
	sub_880A6B28(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a4
	__restgprlr_27(ctx, base);
	return;
loc_88265BBC:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88265be8
	if (ctx.cr6.eq) goto loc_88265BE8;
loc_88265BC8:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bgt 0x88265c30
	if (ctx.cr0.gt) goto loc_88265C30;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a4
	__restgprlr_27(ctx, base);
	return;
loc_88265BE8:
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// lis r8,-30707
	ctx.r8.s64 = -2012413952;
	// lwz r7,2304(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + 2304);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,36(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r4,r8,12248
	ctx.r4.s64 = ctx.r8.s64 + 12248;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// stw r29,88(r7)
	REX_STORE_U32(ctx.r7.u32 + 88, ctx.r29.u32);
	// bl 0x880a6800
	ctx.lr = 0x88265C1C;
	sub_880A6800(ctx, base);
	// lis r6,-30707
	ctx.r6.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,36(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// addi r4,r6,14712
	ctx.r4.s64 = ctx.r6.s64 + 14712;
	// bl 0x880a6800
	ctx.lr = 0x88265C30;
	sub_880A6800(ctx, base);
loc_88265C30:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88265C40) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,20
	ctx.r5.s64 = 20;
	// bl 0x880a6ec0
	ctx.lr = 0x88265C6C;
	sub_880A6EC0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lis r8,-30682
	ctx.r8.s64 = -2010775552;
	// stw r9,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r8,22960
	ctx.r5.s64 = ctx.r8.s64 + 22960;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6530
	ctx.lr = 0x88265C98;
	sub_880A6530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_88265CB8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x88265CC0;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88265CE0;
	sub_880A6EC0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// bgt cr6,0x88266004
	if (ctx.cr6.gt) goto loc_88266004;
	// beq cr6,0x88265f0c
	if (ctx.cr6.eq) goto loc_88265F0C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88265ec8
	if (ctx.cr6.eq) goto loc_88265EC8;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x88265de4
	if (ctx.cr6.eq) goto loc_88265DE4;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x882660d4
	if (!ctx.cr6.eq) goto loc_882660D4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x880a6970
	ctx.lr = 0x88265D18;
	sub_880A6970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x882660d4
	if (!ctx.cr6.eq) goto loc_882660D4;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,96
	ctx.r9.s64 = 96;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bgt 0x88265d60
	if (ctx.cr0.gt) goto loc_88265D60;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r11,30
	ctx.r11.s64 = 30;
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88265D60:
	// lis r11,-30707
	ctx.r11.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,13096
	ctx.r4.s64 = ctx.r11.s64 + 13096;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x88265D74;
	sub_880A6800(ctx, base);
	// lis r10,-30707
	ctx.r10.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,12992
	ctx.r4.s64 = ctx.r10.s64 + 12992;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x88265D88;
	sub_880A6800(ctx, base);
	// lis r9,-30595
	ctx.r9.s64 = -2005073920;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// lwz r11,-11828(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -11828);
	// stw r6,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// stw r5,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// lbz r4,144(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 144);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x88265dc4
	if (!ctx.cr6.eq) goto loc_88265DC4;
	// li r11,24
	ctx.r11.s64 = 24;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
loc_88265DC4:
	// lis r11,-30687
	ctx.r11.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,17576
	ctx.r4.s64 = ctx.r11.s64 + 17576;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6b28
	ctx.lr = 0x88265DD8;
	sub_880A6B28(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88265DE4:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88265e3c
	if (ctx.cr6.eq) goto loc_88265E3C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882660d4
	if (ctx.cr0.gt) goto loc_882660D4;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// bl 0x8812f858
	ctx.lr = 0x88265E0C;
	sub_8812F858(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lis r10,-30707
	ctx.r10.s64 = -2012413952;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r4,r10,7528
	ctx.r4.s64 = ctx.r10.s64 + 7528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x88265E30;
	sub_880A6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88265E3C:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bge 0x882660d4
	if (!ctx.cr0.lt) goto loc_882660D4;
	// lis r11,-30595
	ctx.r11.s64 = -2005073920;
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r8,24(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// li r10,8
	ctx.r10.s64 = 8;
	// lwz r7,28(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// li r6,6
	ctx.r6.s64 = 6;
	// stw r10,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// stw r6,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// lwz r11,-11828(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -11828);
	// stw r9,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// lbz r5,144(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 144);
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x88265e94
	if (!ctx.cr6.eq) goto loc_88265E94;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r10,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
loc_88265E94:
	// lis r11,-30687
	ctx.r11.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,15392
	ctx.r4.s64 = ctx.r11.s64 + 15392;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6b28
	ctx.lr = 0x88265EA8;
	sub_880A6B28(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,20
	ctx.r9.s64 = 20;
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88265EC8:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882660d4
	if (ctx.cr0.gt) goto loc_882660D4;
	// lis r11,-30687
	ctx.r11.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,15160
	ctx.r4.s64 = ctx.r11.s64 + 15160;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6b28
	ctx.lr = 0x88265EEC;
	sub_880A6B28(ctx, base);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,24
	ctx.r9.s64 = 24;
	// stw r3,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88265F0C:
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bge 0x882660d4
	if (!ctx.cr0.lt) goto loc_882660D4;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lis r10,-30707
	ctx.r10.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,13096
	ctx.r4.s64 = ctx.r10.s64 + 13096;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bl 0x880a6800
	ctx.lr = 0x88265F38;
	sub_880A6800(ctx, base);
	// lis r9,-30707
	ctx.r9.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,12992
	ctx.r4.s64 = ctx.r9.s64 + 12992;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x88265F4C;
	sub_880A6800(ctx, base);
	// lis r8,-30595
	ctx.r8.s64 = -2005073920;
	// li r10,6
	ctx.r10.s64 = 6;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// lwz r11,-11828(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + -11828);
	// stw r7,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// stw r10,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// lbz r6,144(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 144);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x88265f8c
	if (!ctx.cr6.eq) goto loc_88265F8C;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,22
	ctx.r10.s64 = 22;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
loc_88265F8C:
	// lis r11,-30687
	ctx.r11.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,17576
	ctx.r4.s64 = ctx.r11.s64 + 17576;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6b28
	ctx.lr = 0x88265FA0;
	sub_880A6B28(ctx, base);
	// lis r10,40
	ctx.r10.s64 = 2621440;
	// lis r9,340
	ctx.r9.s64 = 22282240;
	// stw r3,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// lwz r8,9100(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 9100);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// beq cr6,0x88265fcc
	if (ctx.cr6.eq) goto loc_88265FCC;
	// lis r11,200
	ctx.r11.s64 = 13107200;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_88265FCC:
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6320
	ctx.lr = 0x88265FE0;
	sub_880A6320(ctx, base);
	// li r10,40
	ctx.r10.s64 = 40;
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lwz r4,32(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x880a6918
	ctx.lr = 0x88265FF8;
	sub_880A6918(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88266004:
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// beq cr6,0x882660b0
	if (ctx.cr6.eq) goto loc_882660B0;
	// cmpwi cr6,r11,50
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 50, ctx.xer);
	// bne cr6,0x882660d4
	if (!ctx.cr6.eq) goto loc_882660D4;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88266040
	if (ctx.cr6.eq) goto loc_88266040;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882660d4
	if (ctx.cr0.gt) goto loc_882660D4;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88266040:
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,23616
	ctx.r4.s64 = ctx.r11.s64 + 23616;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6588
	ctx.lr = 0x88266054;
	sub_880A6588(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,9104(r28)
	REX_STORE_U32(ctx.r28.u32 + 9104, ctx.r10.u32);
	// bl 0x8812f858
	ctx.lr = 0x88266064;
	sub_8812F858(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30707
	ctx.r7.s64 = -2012413952;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,7528
	ctx.r4.s64 = ctx.r7.s64 + 7528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x8826608C;
	sub_880A6800(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,40(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// bl 0x880a6a48
	ctx.lr = 0x88266098;
	sub_880A6A48(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a64a8
	ctx.lr = 0x882660A4;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_882660B0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,36(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// bl 0x880a6970
	ctx.lr = 0x882660BC;
	sub_880A6970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x882660d4
	if (!ctx.cr6.eq) goto loc_882660D4;
	// li r11,50
	ctx.r11.s64 = 50;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
loc_882660D4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_882660E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081154
	ctx.lr = 0x882660E8;
	__savegprlr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r27,2304(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// li r5,52
	ctx.r5.s64 = 52;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88266108;
	sub_880A6EC0(ctx, base);
	// lwz r11,9100(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 9100);
	// lis r10,-30595
	ctx.r10.s64 = -2005073920;
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// li r29,0
	ctx.r29.s64 = 0;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r7,9100(r27)
	REX_STORE_U32(ctx.r27.u32 + 9100, ctx.r7.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r11,-11828(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -11828);
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r29,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r29.u32);
	// li r6,32
	ctx.r6.s64 = 32;
	// stw r29,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,4
	ctx.r4.s64 = 4;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r6,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// stw r5,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r5.u32);
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// stw r4,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r4.u32);
	// stw r3,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// stw r29,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r29.u32);
	// lbz r11,144(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 144);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8826617c
	if (!ctx.cr6.eq) goto loc_8826617C;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r10,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
loc_8826617C:
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// lwz r10,5728(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 5728);
	// lis r8,120
	ctx.r8.s64 = 7864320;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r7,r11,-11936
	ctx.r7.s64 = ctx.r11.s64 + -11936;
	// lis r6,360
	ctx.r6.s64 = 23592960;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// stw r6,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// beq cr6,0x882661b8
	if (ctx.cr6.eq) goto loc_882661B8;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6320
	ctx.lr = 0x882661B8;
	sub_880A6320(ctx, base);
loc_882661B8:
	// lis r10,-30669
	ctx.r10.s64 = -2009923584;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// lis r8,-30707
	ctx.r8.s64 = -2012413952;
	// ori r7,r9,20077
	ctx.r7.u64 = ctx.r9.u64 | 20077;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,4328(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4328);
	// addi r4,r8,7528
	ctx.r4.s64 = ctx.r8.s64 + 7528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mullw r11,r11,r7
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4328(r10)
	REX_STORE_U32(ctx.r10.u32 + 4328, ctx.r11.u32);
	// lhz r11,4328(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 4328);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x880a6800
	ctx.lr = 0x882661FC;
	sub_880A6800(ctx, base);
	// lis r4,-30687
	ctx.r4.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,11208
	ctx.r4.s64 = ctx.r4.s64 + 11208;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6b28
	ctx.lr = 0x88266210;
	sub_880A6B28(ctx, base);
	// stw r3,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r3.u32);
	// lis r3,-30682
	ctx.r3.s64 = -2010775552;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r5,r3,23736
	ctx.r5.s64 = ctx.r3.s64 + 23736;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6530
	ctx.lr = 0x88266228;
	sub_880A6530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a4
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88266238) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081150
	ctx.lr = 0x88266240;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88266264;
	sub_880A6EC0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88266450
	if (ctx.cr6.eq) goto loc_88266450;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x882662f8
	if (ctx.cr6.eq) goto loc_882662F8;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x882664c4
	if (!ctx.cr6.eq) goto loc_882664C4;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8826645c
	if (!ctx.cr6.eq) goto loc_8826645C;
	// lwz r11,2304(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 2304);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r9,-30707
	ctx.r9.s64 = -2012413952;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,12248
	ctx.r4.s64 = ctx.r9.s64 + 12248;
	// stw r10,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x880a6800
	ctx.lr = 0x882662B8;
	sub_880A6800(ctx, base);
	// lwz r11,9100(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 9100);
	// stw r30,9104(r29)
	REX_STORE_U32(ctx.r29.u32 + 9104, ctx.r30.u32);
	// lis r8,-30682
	ctx.r8.s64 = -2010775552;
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// addi r4,r8,22656
	ctx.r4.s64 = ctx.r8.s64 + 22656;
	// stw r6,9100(r29)
	REX_STORE_U32(ctx.r29.u32 + 9100, ctx.r6.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a6588
	ctx.lr = 0x882662E0;
	sub_880A6588(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a64a8
	ctx.lr = 0x882662EC;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880811a0
	__restgprlr_26(ctx, base);
	return;
loc_882662F8:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x882663bc
	if (ctx.cr6.eq) goto loc_882663BC;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882664c4
	if (ctx.cr0.gt) goto loc_882664C4;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-30687
	ctx.r9.s64 = -2011103232;
	// cntlzw r8,r11
	ctx.r8.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// addi r4,r9,13536
	ctx.r4.s64 = ctx.r9.s64 + 13536;
	// xori r11,r7,1
	ctx.r11.u64 = ctx.r7.u64 ^ 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r6,r11,2
	ctx.r6.s64 = ctx.r11.s64 + 2;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x880a6b28
	ctx.lr = 0x88266344;
	sub_880A6B28(ctx, base);
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r5,4
	ctx.r5.s64 = 4;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// beq cr6,0x88266368
	if (ctx.cr6.eq) goto loc_88266368;
	// lis r10,400
	ctx.r10.s64 = 26214400;
	// lis r11,120
	ctx.r11.s64 = 7864320;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// b 0x88266388
	goto loc_88266388;
loc_88266368:
	// lwz r11,9100(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 9100);
	// lis r10,220
	ctx.r10.s64 = 14417920;
	// lis r9,360
	ctx.r9.s64 = 23592960;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// beq cr6,0x8826638c
	if (ctx.cr6.eq) goto loc_8826638C;
	// lis r11,20
	ctx.r11.s64 = 1310720;
loc_88266388:
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_8826638C:
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a6320
	ctx.lr = 0x882663A0;
	sub_880A6320(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// stw r10,24(r29)
	REX_STORE_U32(ctx.r29.u32 + 24, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880811a0
	__restgprlr_26(ctx, base);
	return;
loc_882663BC:
	// lwz r11,24(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x882664c4
	if (!ctx.cr6.eq) goto loc_882664C4;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x88266404
	if (ctx.cr6.eq) goto loc_88266404;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lis r10,-30687
	ctx.r10.s64 = -2011103232;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,17360
	ctx.r4.s64 = ctx.r10.s64 + 17360;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a6b28
	ctx.lr = 0x882663F0;
	sub_880A6B28(ctx, base);
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,128
	ctx.r8.s64 = 128;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// b 0x88266414
	goto loc_88266414;
loc_88266404:
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
loc_88266414:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8812f858
	ctx.lr = 0x8826641C;
	sub_8812F858(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lis r8,-30707
	ctx.r8.s64 = -2012413952;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,7528
	ctx.r4.s64 = ctx.r8.s64 + 7528;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a6800
	ctx.lr = 0x88266444;
	sub_880A6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880811a0
	__restgprlr_26(ctx, base);
	return;
loc_88266450:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8826647c
	if (ctx.cr6.eq) goto loc_8826647C;
loc_8826645C:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882664c4
	if (ctx.cr0.gt) goto loc_882664C4;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880811a0
	__restgprlr_26(ctx, base);
	return;
loc_8826647C:
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// lis r9,-30707
	ctx.r9.s64 = -2012413952;
	// lwz r8,2304(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 2304);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,36(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 36);
	// addi r4,r9,12248
	ctx.r4.s64 = ctx.r9.s64 + 12248;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// stw r30,88(r8)
	REX_STORE_U32(ctx.r8.u32 + 88, ctx.r30.u32);
	// bl 0x880a6800
	ctx.lr = 0x882664B0;
	sub_880A6800(ctx, base);
	// lis r7,-30707
	ctx.r7.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,36(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// addi r4,r7,14712
	ctx.r4.s64 = ctx.r7.s64 + 14712;
	// bl 0x880a6800
	ctx.lr = 0x882664C4;
	sub_880A6800(ctx, base);
loc_882664C4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880811a0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_882664D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x882664D8;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x882664F8;
	sub_880A6EC0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x882665e0
	if (ctx.cr6.eq) goto loc_882665E0;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x88266570
	if (ctx.cr6.eq) goto loc_88266570;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x8826664c
	if (!ctx.cr6.eq) goto loc_8826664C;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88266544
	if (ctx.cr6.eq) goto loc_88266544;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x8826664c
	if (ctx.cr0.gt) goto loc_8826664C;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88266544:
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,27984
	ctx.r4.s64 = ctx.r11.s64 + 27984;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6588
	ctx.lr = 0x88266558;
	sub_880A6588(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a64a8
	ctx.lr = 0x88266564;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88266570:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,32(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x880a6970
	ctx.lr = 0x8826657C;
	sub_880A6970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8826664c
	if (!ctx.cr6.eq) goto loc_8826664C;
	// lis r11,-30707
	ctx.r11.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,13200
	ctx.r4.s64 = ctx.r11.s64 + 13200;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x88266598;
	sub_880A6800(ctx, base);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,192
	ctx.r8.s64 = 192;
	// addi r7,r10,-11936
	ctx.r7.s64 = ctx.r10.s64 + -11936;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// lwz r3,5728(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 5728);
	// lis r4,360
	ctx.r4.s64 = 23592960;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// cmpw cr6,r3,r7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, ctx.xer);
	// stw r4,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x8826664c
	if (ctx.cr6.eq) goto loc_8826664C;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// b 0x88266640
	goto loc_88266640;
loc_882665E0:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8826664c
	if (ctx.cr0.gt) goto loc_8826664C;
	// lwz r11,9100(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 9100);
	// lis r10,-30684
	ctx.r10.s64 = -2010906624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-5704
	ctx.r4.s64 = ctx.r10.s64 + -5704;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880a6b28
	ctx.lr = 0x8826660C;
	sub_880A6B28(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,96
	ctx.r8.s64 = 96;
	// stw r3,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lis r6,120
	ctx.r6.s64 = 7864320;
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,300
	ctx.r5.s64 = 19660800;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lis r4,-30696
	ctx.r4.s64 = -2011693056;
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r4,r4,-11936
	ctx.r4.s64 = ctx.r4.s64 + -11936;
loc_88266640:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6320
	ctx.lr = 0x8826664C;
	sub_880A6320(ctx, base);
loc_8826664C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88266658) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8808115c
	ctx.lr = 0x88266660;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x880a6ec0
	ctx.lr = 0x8826667C;
	sub_880A6EC0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r9,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// li r6,80
	ctx.r6.s64 = 80;
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// li r29,32
	ctx.r29.s64 = 32;
	// stw r11,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lis r5,-30682
	ctx.r5.s64 = -2010775552;
	// stw r10,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r7,28(r8)
	REX_STORE_U32(ctx.r8.u32 + 28, ctx.r7.u32);
	// addi r5,r5,25808
	ctx.r5.s64 = ctx.r5.s64 + 25808;
	// stw r6,40(r8)
	REX_STORE_U32(ctx.r8.u32 + 40, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,44(r8)
	REX_STORE_U32(ctx.r8.u32 + 44, ctx.r29.u32);
	// bl 0x880a6530
	ctx.lr = 0x882666D0;
	sub_880A6530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_882666E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x882666E8;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x8826670C;
	sub_880A6EC0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88266898
	if (ctx.cr6.eq) goto loc_88266898;
	// cmpwi cr6,r10,10
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 10, ctx.xer);
	// beq cr6,0x8826678c
	if (ctx.cr6.eq) goto loc_8826678C;
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// bne cr6,0x8826690c
	if (!ctx.cr6.eq) goto loc_8826690C;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x882668a4
	if (!ctx.cr6.eq) goto loc_882668A4;
	// lwz r11,2304(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 2304);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r8,-30707
	ctx.r8.s64 = -2012413952;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,12248
	ctx.r4.s64 = ctx.r8.s64 + 12248;
	// stw r10,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x880a6800
	ctx.lr = 0x88266760;
	sub_880A6800(ctx, base);
	// lis r7,-30682
	ctx.r7.s64 = -2010775552;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,26200
	ctx.r4.s64 = ctx.r7.s64 + 26200;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6588
	ctx.lr = 0x88266774;
	sub_880A6588(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a64a8
	ctx.lr = 0x88266780;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_8826678C:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88266824
	if (ctx.cr6.eq) goto loc_88266824;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bgt 0x8826690c
	if (ctx.cr0.gt) goto loc_8826690C;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lis r8,-30684
	ctx.r8.s64 = -2010906624;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-9032
	ctx.r4.s64 = ctx.r8.s64 + -9032;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6b28
	ctx.lr = 0x882667C8;
	sub_880A6B28(ctx, base);
	// lwz r4,9100(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 9100);
	// li r7,4
	ctx.r7.s64 = 4;
	// lis r6,220
	ctx.r6.s64 = 14417920;
	// lis r5,360
	ctx.r5.s64 = 23592960;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r5,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// beq cr6,0x882667f4
	if (ctx.cr6.eq) goto loc_882667F4;
	// lis r11,20
	ctx.r11.s64 = 1310720;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_882667F4:
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6320
	ctx.lr = 0x88266808;
	sub_880A6320(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// stw r10,24(r28)
	REX_STORE_U32(ctx.r28.u32 + 24, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,20(r28)
	REX_STORE_U32(ctx.r28.u32 + 20, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88266824:
	// lwz r10,24(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8826690c
	if (!ctx.cr6.eq) goto loc_8826690C;
	// li r10,20
	ctx.r10.s64 = 20;
	// li r9,128
	ctx.r9.s64 = 128;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// bl 0x8812f858
	ctx.lr = 0x88266848;
	sub_8812F858(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lis r6,-30707
	ctx.r6.s64 = -2012413952;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,7528
	ctx.r4.s64 = ctx.r6.s64 + 7528;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6800
	ctx.lr = 0x88266870;
	sub_880A6800(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r4,-30684
	ctx.r4.s64 = -2010906624;
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-6168
	ctx.r4.s64 = ctx.r4.s64 + -6168;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6b28
	ctx.lr = 0x8826688C;
	sub_880A6B28(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88266898:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x882668c4
	if (ctx.cr6.eq) goto loc_882668C4;
loc_882668A4:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bgt 0x8826690c
	if (ctx.cr0.gt) goto loc_8826690C;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_882668C4:
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// lis r8,-30707
	ctx.r8.s64 = -2012413952;
	// lwz r7,2304(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 2304);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,36(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r4,r8,12248
	ctx.r4.s64 = ctx.r8.s64 + 12248;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r10,88(r7)
	REX_STORE_U32(ctx.r7.u32 + 88, ctx.r10.u32);
	// bl 0x880a6800
	ctx.lr = 0x882668F8;
	sub_880A6800(ctx, base);
	// lis r6,-30707
	ctx.r6.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,36(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 36);
	// addi r4,r6,14712
	ctx.r4.s64 = ctx.r6.s64 + 14712;
	// bl 0x880a6800
	ctx.lr = 0x8826690C;
	sub_880A6800(ctx, base);
loc_8826690C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88266918) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,12
	ctx.r5.s64 = 12;
	// bl 0x880a6ec0
	ctx.lr = 0x88266944;
	sub_880A6EC0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lis r8,-30682
	ctx.r8.s64 = -2010775552;
	// stw r9,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r8,26336
	ctx.r5.s64 = ctx.r8.s64 + 26336;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6530
	ctx.lr = 0x88266970;
	sub_880A6530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_88266990) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x88266998;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x882669B8;
	sub_880A6EC0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// bgt cr6,0x88266c7c
	if (ctx.cr6.gt) goto loc_88266C7C;
	// beq cr6,0x88266ba8
	if (ctx.cr6.eq) goto loc_88266BA8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88266b64
	if (ctx.cr6.eq) goto loc_88266B64;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x88266aa0
	if (ctx.cr6.eq) goto loc_88266AA0;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x88266d40
	if (!ctx.cr6.eq) goto loc_88266D40;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x880a6970
	ctx.lr = 0x882669F0;
	sub_880A6970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88266d40
	if (!ctx.cr6.eq) goto loc_88266D40;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,96
	ctx.r9.s64 = 96;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bgt 0x88266a38
	if (ctx.cr0.gt) goto loc_88266A38;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r11,30
	ctx.r11.s64 = 30;
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88266A38:
	// lis r11,-30707
	ctx.r11.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,13096
	ctx.r4.s64 = ctx.r11.s64 + 13096;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x88266A4C;
	sub_880A6800(ctx, base);
	// lis r10,-30707
	ctx.r10.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,12992
	ctx.r4.s64 = ctx.r10.s64 + 12992;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x88266A60;
	sub_880A6800(ctx, base);
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,2
	ctx.r8.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// li r6,8
	ctx.r6.s64 = 8;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// stw r7,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// lis r4,-30684
	ctx.r4.s64 = -2010906624;
	// stw r6,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-5952
	ctx.r4.s64 = ctx.r4.s64 + -5952;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6b28
	ctx.lr = 0x88266A94;
	sub_880A6B28(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88266AA0:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88266af8
	if (ctx.cr6.eq) goto loc_88266AF8;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88266d40
	if (ctx.cr0.gt) goto loc_88266D40;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// bl 0x8812f858
	ctx.lr = 0x88266AC8;
	sub_8812F858(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lis r10,-30707
	ctx.r10.s64 = -2012413952;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r4,r10,7528
	ctx.r4.s64 = ctx.r10.s64 + 7528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x88266AEC;
	sub_880A6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88266AF8:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bge 0x88266d40
	if (!ctx.cr0.lt) goto loc_88266D40;
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// li r10,4
	ctx.r10.s64 = 4;
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// li r8,12
	ctx.r8.s64 = 12;
	// lwz r7,20(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lis r6,-30684
	ctx.r6.s64 = -2010906624;
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r8,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r8.u32);
	// addi r4,r6,-7120
	ctx.r4.s64 = ctx.r6.s64 + -7120;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r7,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r7.u32);
	// bl 0x880a6b28
	ctx.lr = 0x88266B44;
	sub_880A6B28(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,20
	ctx.r4.s64 = 20;
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// stw r5,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88266B64:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88266d40
	if (ctx.cr0.gt) goto loc_88266D40;
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-7288
	ctx.r4.s64 = ctx.r11.s64 + -7288;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6b28
	ctx.lr = 0x88266B88;
	sub_880A6B28(ctx, base);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,24
	ctx.r9.s64 = 24;
	// stw r3,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88266BA8:
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bge 0x88266d40
	if (!ctx.cr0.lt) goto loc_88266D40;
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lis r10,-30707
	ctx.r10.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,13096
	ctx.r4.s64 = ctx.r10.s64 + 13096;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bl 0x880a6800
	ctx.lr = 0x88266BD4;
	sub_880A6800(ctx, base);
	// lis r9,-30707
	ctx.r9.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,12992
	ctx.r4.s64 = ctx.r9.s64 + 12992;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x88266BE8;
	sub_880A6800(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// li r8,4
	ctx.r8.s64 = 4;
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r8,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// lis r7,-30684
	ctx.r7.s64 = -2010906624;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// addi r4,r7,-5952
	ctx.r4.s64 = ctx.r7.s64 + -5952;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6b28
	ctx.lr = 0x88266C18;
	sub_880A6B28(ctx, base);
	// lis r6,40
	ctx.r6.s64 = 2621440;
	// lis r5,340
	ctx.r5.s64 = 22282240;
	// stw r3,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// lwz r4,9100(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 9100);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// beq cr6,0x88266c44
	if (ctx.cr6.eq) goto loc_88266C44;
	// lis r11,200
	ctx.r11.s64 = 13107200;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_88266C44:
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6320
	ctx.lr = 0x88266C58;
	sub_880A6320(ctx, base);
	// li r10,40
	ctx.r10.s64 = 40;
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lwz r4,32(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x880a6918
	ctx.lr = 0x88266C70;
	sub_880A6918(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88266C7C:
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// beq cr6,0x88266d1c
	if (ctx.cr6.eq) goto loc_88266D1C;
	// cmpwi cr6,r11,50
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 50, ctx.xer);
	// bne cr6,0x88266d40
	if (!ctx.cr6.eq) goto loc_88266D40;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88266cb8
	if (ctx.cr6.eq) goto loc_88266CB8;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88266d40
	if (ctx.cr0.gt) goto loc_88266D40;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88266CB8:
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,26904
	ctx.r4.s64 = ctx.r11.s64 + 26904;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6588
	ctx.lr = 0x88266CCC;
	sub_880A6588(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,9104(r28)
	REX_STORE_U32(ctx.r28.u32 + 9104, ctx.r10.u32);
	// bl 0x8812f858
	ctx.lr = 0x88266CDC;
	sub_8812F858(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30707
	ctx.r7.s64 = -2012413952;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,7528
	ctx.r4.s64 = ctx.r7.s64 + 7528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x88266D04;
	sub_880A6800(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a64a8
	ctx.lr = 0x88266D10;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88266D1C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,36(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// bl 0x880a6970
	ctx.lr = 0x88266D28;
	sub_880A6970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88266d40
	if (!ctx.cr6.eq) goto loc_88266D40;
	// li r11,50
	ctx.r11.s64 = 50;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
loc_88266D40:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88266D50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x88266D58;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88266D78;
	sub_880A6EC0(ctx, base);
	// lwz r10,9100(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 9100);
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r9,9100(r28)
	REX_STORE_U32(ctx.r28.u32 + 9100, ctx.r9.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// li r7,64
	ctx.r7.s64 = 64;
	// stw r30,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// addi r6,r10,-11936
	ctx.r6.s64 = ctx.r10.s64 + -11936;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// stw r8,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// lis r4,360
	ctx.r4.s64 = 23592960;
	// stw r7,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r7.u32);
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stw r9,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r9.u32);
	// stw r9,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r9.u32);
	// stw r30,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r30.u32);
	// lwz r3,5728(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 5728);
	// cmpw cr6,r3,r6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r6.s32, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// stw r4,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x88266dfc
	if (ctx.cr6.eq) goto loc_88266DFC;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6320
	ctx.lr = 0x88266DFC;
	sub_880A6320(ctx, base);
loc_88266DFC:
	// lis r10,-30669
	ctx.r10.s64 = -2009923584;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// lis r8,-30707
	ctx.r8.s64 = -2012413952;
	// ori r7,r9,20077
	ctx.r7.u64 = ctx.r9.u64 | 20077;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,4328(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4328);
	// addi r4,r8,7528
	ctx.r4.s64 = ctx.r8.s64 + 7528;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mullw r11,r11,r7
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4328(r10)
	REX_STORE_U32(ctx.r10.u32 + 4328, ctx.r11.u32);
	// lhz r11,4328(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 4328);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x880a6800
	ctx.lr = 0x88266E40;
	sub_880A6800(ctx, base);
	// lis r5,-30682
	ctx.r5.s64 = -2010775552;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r5,27024
	ctx.r5.s64 = ctx.r5.s64 + 27024;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6530
	ctx.lr = 0x88266E54;
	sub_880A6530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88266E60) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081150
	ctx.lr = 0x88266E68;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88266E8C;
	sub_880A6EC0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88267078
	if (ctx.cr6.eq) goto loc_88267078;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x88266f20
	if (ctx.cr6.eq) goto loc_88266F20;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x882670ec
	if (!ctx.cr6.eq) goto loc_882670EC;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88267084
	if (!ctx.cr6.eq) goto loc_88267084;
	// lwz r11,2304(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 2304);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r9,-30707
	ctx.r9.s64 = -2012413952;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,12248
	ctx.r4.s64 = ctx.r9.s64 + 12248;
	// stw r10,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x880a6800
	ctx.lr = 0x88266EE0;
	sub_880A6800(ctx, base);
	// lwz r11,9100(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 9100);
	// stw r30,9104(r29)
	REX_STORE_U32(ctx.r29.u32 + 9104, ctx.r30.u32);
	// lis r8,-30682
	ctx.r8.s64 = -2010775552;
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// addi r4,r8,26200
	ctx.r4.s64 = ctx.r8.s64 + 26200;
	// stw r6,9100(r29)
	REX_STORE_U32(ctx.r29.u32 + 9100, ctx.r6.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a6588
	ctx.lr = 0x88266F08;
	sub_880A6588(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a64a8
	ctx.lr = 0x88266F14;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880811a0
	__restgprlr_26(ctx, base);
	return;
loc_88266F20:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88266fe4
	if (ctx.cr6.eq) goto loc_88266FE4;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882670ec
	if (ctx.cr0.gt) goto loc_882670EC;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-30684
	ctx.r9.s64 = -2010906624;
	// cntlzw r8,r11
	ctx.r8.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// addi r4,r9,-9032
	ctx.r4.s64 = ctx.r9.s64 + -9032;
	// xori r11,r7,1
	ctx.r11.u64 = ctx.r7.u64 ^ 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r6,r11,2
	ctx.r6.s64 = ctx.r11.s64 + 2;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x880a6b28
	ctx.lr = 0x88266F6C;
	sub_880A6B28(ctx, base);
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r5,4
	ctx.r5.s64 = 4;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// beq cr6,0x88266f90
	if (ctx.cr6.eq) goto loc_88266F90;
	// lis r10,400
	ctx.r10.s64 = 26214400;
	// lis r11,120
	ctx.r11.s64 = 7864320;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// b 0x88266fb0
	goto loc_88266FB0;
loc_88266F90:
	// lwz r11,9100(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 9100);
	// lis r10,220
	ctx.r10.s64 = 14417920;
	// lis r9,360
	ctx.r9.s64 = 23592960;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// beq cr6,0x88266fb4
	if (ctx.cr6.eq) goto loc_88266FB4;
	// lis r11,20
	ctx.r11.s64 = 1310720;
loc_88266FB0:
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_88266FB4:
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a6320
	ctx.lr = 0x88266FC8;
	sub_880A6320(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// stw r10,24(r29)
	REX_STORE_U32(ctx.r29.u32 + 24, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880811a0
	__restgprlr_26(ctx, base);
	return;
loc_88266FE4:
	// lwz r11,24(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x882670ec
	if (!ctx.cr6.eq) goto loc_882670EC;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8826702c
	if (ctx.cr6.eq) goto loc_8826702C;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lis r10,-30684
	ctx.r10.s64 = -2010906624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-6168
	ctx.r4.s64 = ctx.r10.s64 + -6168;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a6b28
	ctx.lr = 0x88267018;
	sub_880A6B28(ctx, base);
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,128
	ctx.r8.s64 = 128;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// b 0x8826703c
	goto loc_8826703C;
loc_8826702C:
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
loc_8826703C:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8812f858
	ctx.lr = 0x88267044;
	sub_8812F858(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lis r8,-30707
	ctx.r8.s64 = -2012413952;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,7528
	ctx.r4.s64 = ctx.r8.s64 + 7528;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a6800
	ctx.lr = 0x8826706C;
	sub_880A6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880811a0
	__restgprlr_26(ctx, base);
	return;
loc_88267078:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x882670a4
	if (ctx.cr6.eq) goto loc_882670A4;
loc_88267084:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882670ec
	if (ctx.cr0.gt) goto loc_882670EC;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880811a0
	__restgprlr_26(ctx, base);
	return;
loc_882670A4:
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// lis r9,-30707
	ctx.r9.s64 = -2012413952;
	// lwz r8,2304(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 2304);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,36(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 36);
	// addi r4,r9,12248
	ctx.r4.s64 = ctx.r9.s64 + 12248;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// stw r30,88(r8)
	REX_STORE_U32(ctx.r8.u32 + 88, ctx.r30.u32);
	// bl 0x880a6800
	ctx.lr = 0x882670D8;
	sub_880A6800(ctx, base);
	// lis r7,-30707
	ctx.r7.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,36(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// addi r4,r7,14712
	ctx.r4.s64 = ctx.r7.s64 + 14712;
	// bl 0x880a6800
	ctx.lr = 0x882670EC;
	sub_880A6800(ctx, base);
loc_882670EC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880811a0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_882670F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x88267100;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88267120;
	sub_880A6EC0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88267208
	if (ctx.cr6.eq) goto loc_88267208;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x88267198
	if (ctx.cr6.eq) goto loc_88267198;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x88267274
	if (!ctx.cr6.eq) goto loc_88267274;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8826716c
	if (ctx.cr6.eq) goto loc_8826716C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x88267274
	if (ctx.cr0.gt) goto loc_88267274;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_8826716C:
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,27984
	ctx.r4.s64 = ctx.r11.s64 + 27984;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6588
	ctx.lr = 0x88267180;
	sub_880A6588(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a64a8
	ctx.lr = 0x8826718C;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88267198:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,32(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x880a6970
	ctx.lr = 0x882671A4;
	sub_880A6970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88267274
	if (!ctx.cr6.eq) goto loc_88267274;
	// lis r11,-30707
	ctx.r11.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,13200
	ctx.r4.s64 = ctx.r11.s64 + 13200;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x882671C0;
	sub_880A6800(ctx, base);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,128
	ctx.r8.s64 = 128;
	// addi r7,r10,-11936
	ctx.r7.s64 = ctx.r10.s64 + -11936;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// lwz r3,5728(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 5728);
	// lis r4,360
	ctx.r4.s64 = 23592960;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// cmpw cr6,r3,r7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, ctx.xer);
	// stw r4,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x88267274
	if (ctx.cr6.eq) goto loc_88267274;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// b 0x88267268
	goto loc_88267268;
loc_88267208:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88267274
	if (ctx.cr0.gt) goto loc_88267274;
	// lwz r11,9100(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 9100);
	// lis r10,-30684
	ctx.r10.s64 = -2010906624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-4904
	ctx.r4.s64 = ctx.r10.s64 + -4904;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880a6b28
	ctx.lr = 0x88267234;
	sub_880A6B28(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,96
	ctx.r8.s64 = 96;
	// stw r3,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lis r6,120
	ctx.r6.s64 = 7864320;
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,280
	ctx.r5.s64 = 18350080;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lis r4,-30696
	ctx.r4.s64 = -2011693056;
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r4,r4,-11936
	ctx.r4.s64 = ctx.r4.s64 + -11936;
loc_88267268:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6320
	ctx.lr = 0x88267274;
	sub_880A6320(ctx, base);
loc_88267274:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88267280) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x88267288;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x882672A8;
	sub_880A6EC0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88267390
	if (ctx.cr6.eq) goto loc_88267390;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x88267320
	if (ctx.cr6.eq) goto loc_88267320;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x882673fc
	if (!ctx.cr6.eq) goto loc_882673FC;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x882672f4
	if (ctx.cr6.eq) goto loc_882672F4;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x882673fc
	if (ctx.cr0.gt) goto loc_882673FC;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_882672F4:
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,31464
	ctx.r4.s64 = ctx.r11.s64 + 31464;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6588
	ctx.lr = 0x88267308;
	sub_880A6588(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a64a8
	ctx.lr = 0x88267314;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88267320:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,32(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x880a6970
	ctx.lr = 0x8826732C;
	sub_880A6970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x882673fc
	if (!ctx.cr6.eq) goto loc_882673FC;
	// lis r11,-30707
	ctx.r11.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,13200
	ctx.r4.s64 = ctx.r11.s64 + 13200;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x88267348;
	sub_880A6800(ctx, base);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,128
	ctx.r8.s64 = 128;
	// addi r7,r10,-11936
	ctx.r7.s64 = ctx.r10.s64 + -11936;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// lwz r3,5728(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 5728);
	// lis r4,360
	ctx.r4.s64 = 23592960;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// cmpw cr6,r3,r7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, ctx.xer);
	// stw r4,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x882673fc
	if (ctx.cr6.eq) goto loc_882673FC;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// b 0x882673f0
	goto loc_882673F0;
loc_88267390:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x882673fc
	if (ctx.cr0.gt) goto loc_882673FC;
	// lwz r11,9100(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 9100);
	// lis r10,-30684
	ctx.r10.s64 = -2010906624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-992
	ctx.r4.s64 = ctx.r10.s64 + -992;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880a6b28
	ctx.lr = 0x882673BC;
	sub_880A6B28(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,96
	ctx.r8.s64 = 96;
	// stw r3,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lis r6,120
	ctx.r6.s64 = 7864320;
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,280
	ctx.r5.s64 = 18350080;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lis r4,-30696
	ctx.r4.s64 = -2011693056;
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r4,r4,-11936
	ctx.r4.s64 = ctx.r4.s64 + -11936;
loc_882673F0:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6320
	ctx.lr = 0x882673FC;
	sub_880A6320(ctx, base);
loc_882673FC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88267408) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8808115c
	ctx.lr = 0x88267410;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x880a6ec0
	ctx.lr = 0x8826742C;
	sub_880A6EC0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r9,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// li r6,80
	ctx.r6.s64 = 80;
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// li r29,32
	ctx.r29.s64 = 32;
	// stw r11,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lis r5,-30682
	ctx.r5.s64 = -2010775552;
	// stw r10,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r7,28(r8)
	REX_STORE_U32(ctx.r8.u32 + 28, ctx.r7.u32);
	// addi r5,r5,29312
	ctx.r5.s64 = ctx.r5.s64 + 29312;
	// stw r6,40(r8)
	REX_STORE_U32(ctx.r8.u32 + 40, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,44(r8)
	REX_STORE_U32(ctx.r8.u32 + 44, ctx.r29.u32);
	// bl 0x880a6530
	ctx.lr = 0x88267480;
	sub_880A6530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88267490) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x88267498;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x882674BC;
	sub_880A6EC0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8826762c
	if (ctx.cr6.eq) goto loc_8826762C;
	// cmpwi cr6,r10,10
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 10, ctx.xer);
	// beq cr6,0x8826753c
	if (ctx.cr6.eq) goto loc_8826753C;
	// cmpwi cr6,r10,20
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 20, ctx.xer);
	// bne cr6,0x882676a0
	if (!ctx.cr6.eq) goto loc_882676A0;
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x88267638
	if (!ctx.cr6.eq) goto loc_88267638;
	// lwz r11,2304(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 2304);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r8,-30707
	ctx.r8.s64 = -2012413952;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,12248
	ctx.r4.s64 = ctx.r8.s64 + 12248;
	// stw r10,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x880a6800
	ctx.lr = 0x88267510;
	sub_880A6800(ctx, base);
	// lis r7,-30682
	ctx.r7.s64 = -2010775552;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,29704
	ctx.r4.s64 = ctx.r7.s64 + 29704;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6588
	ctx.lr = 0x88267524;
	sub_880A6588(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a64a8
	ctx.lr = 0x88267530;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_8826753C:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x882675d4
	if (ctx.cr6.eq) goto loc_882675D4;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bgt 0x882676a0
	if (ctx.cr0.gt) goto loc_882676A0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lis r8,-30684
	ctx.r8.s64 = -2010906624;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-3424
	ctx.r4.s64 = ctx.r8.s64 + -3424;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6b28
	ctx.lr = 0x88267578;
	sub_880A6B28(ctx, base);
	// lwz r4,9100(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 9100);
	// li r7,4
	ctx.r7.s64 = 4;
	// lis r6,220
	ctx.r6.s64 = 14417920;
	// lis r5,360
	ctx.r5.s64 = 23592960;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r5,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// beq cr6,0x882675a4
	if (ctx.cr6.eq) goto loc_882675A4;
	// lis r11,20
	ctx.r11.s64 = 1310720;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_882675A4:
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6320
	ctx.lr = 0x882675B8;
	sub_880A6320(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// stw r10,24(r28)
	REX_STORE_U32(ctx.r28.u32 + 24, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,20(r28)
	REX_STORE_U32(ctx.r28.u32 + 20, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_882675D4:
	// lwz r10,24(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 24);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x882676a0
	if (!ctx.cr6.eq) goto loc_882676A0;
	// li r10,20
	ctx.r10.s64 = 20;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// bl 0x8812f858
	ctx.lr = 0x882675F8;
	sub_8812F858(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// lis r6,-30707
	ctx.r6.s64 = -2012413952;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,7528
	ctx.r4.s64 = ctx.r6.s64 + 7528;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6800
	ctx.lr = 0x88267620;
	sub_880A6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_8826762C:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x88267658
	if (ctx.cr6.eq) goto loc_88267658;
loc_88267638:
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bgt 0x882676a0
	if (ctx.cr0.gt) goto loc_882676A0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88267658:
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// lis r8,-30707
	ctx.r8.s64 = -2012413952;
	// lwz r7,2304(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 2304);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,36(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// addi r4,r8,12248
	ctx.r4.s64 = ctx.r8.s64 + 12248;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r10,88(r7)
	REX_STORE_U32(ctx.r7.u32 + 88, ctx.r10.u32);
	// bl 0x880a6800
	ctx.lr = 0x8826768C;
	sub_880A6800(ctx, base);
	// lis r6,-30707
	ctx.r6.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,36(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 36);
	// addi r4,r6,14712
	ctx.r4.s64 = ctx.r6.s64 + 14712;
	// bl 0x880a6800
	ctx.lr = 0x882676A0;
	sub_880A6800(ctx, base);
loc_882676A0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_882676B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,12
	ctx.r5.s64 = 12;
	// bl 0x880a6ec0
	ctx.lr = 0x882676DC;
	sub_880A6EC0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lis r8,-30682
	ctx.r8.s64 = -2010775552;
	// stw r9,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r5,r8,29840
	ctx.r5.s64 = ctx.r8.s64 + 29840;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6530
	ctx.lr = 0x88267708;
	sub_880A6530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_88267728) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x88267730;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88267750;
	sub_880A6EC0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 30, ctx.xer);
	// bgt cr6,0x88267a14
	if (ctx.cr6.gt) goto loc_88267A14;
	// beq cr6,0x88267940
	if (ctx.cr6.eq) goto loc_88267940;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x882678fc
	if (ctx.cr6.eq) goto loc_882678FC;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x88267838
	if (ctx.cr6.eq) goto loc_88267838;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x88267ad8
	if (!ctx.cr6.eq) goto loc_88267AD8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x880a6970
	ctx.lr = 0x88267788;
	sub_880A6970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88267ad8
	if (!ctx.cr6.eq) goto loc_88267AD8;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,96
	ctx.r9.s64 = 96;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bgt 0x882677d0
	if (ctx.cr0.gt) goto loc_882677D0;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r11,30
	ctx.r11.s64 = 30;
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r29.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_882677D0:
	// lis r11,-30707
	ctx.r11.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,13096
	ctx.r4.s64 = ctx.r11.s64 + 13096;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x882677E4;
	sub_880A6800(ctx, base);
	// lis r10,-30707
	ctx.r10.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,12992
	ctx.r4.s64 = ctx.r10.s64 + 12992;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x882677F8;
	sub_880A6800(ctx, base);
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,2
	ctx.r8.s64 = 2;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// li r6,8
	ctx.r6.s64 = 8;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// stw r7,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// lis r4,-30684
	ctx.r4.s64 = -2010906624;
	// stw r6,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-1296
	ctx.r4.s64 = ctx.r4.s64 + -1296;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6b28
	ctx.lr = 0x8826782C;
	sub_880A6B28(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88267838:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88267890
	if (ctx.cr6.eq) goto loc_88267890;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88267ad8
	if (ctx.cr0.gt) goto loc_88267AD8;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// bl 0x8812f858
	ctx.lr = 0x88267860;
	sub_8812F858(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// lis r10,-30707
	ctx.r10.s64 = -2012413952;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r4,r10,7528
	ctx.r4.s64 = ctx.r10.s64 + 7528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x88267884;
	sub_880A6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88267890:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// bge 0x88267ad8
	if (!ctx.cr0.lt) goto loc_88267AD8;
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// li r10,4
	ctx.r10.s64 = 4;
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// li r8,12
	ctx.r8.s64 = 12;
	// lwz r7,20(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lis r6,-30684
	ctx.r6.s64 = -2010906624;
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r8,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r8.u32);
	// addi r4,r6,-2000
	ctx.r4.s64 = ctx.r6.s64 + -2000;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r7,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r7.u32);
	// bl 0x880a6b28
	ctx.lr = 0x882678DC;
	sub_880A6B28(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,20
	ctx.r4.s64 = 20;
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// stw r5,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r4,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_882678FC:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88267ad8
	if (ctx.cr0.gt) goto loc_88267AD8;
	// lis r11,-30684
	ctx.r11.s64 = -2010906624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-2208
	ctx.r4.s64 = ctx.r11.s64 + -2208;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6b28
	ctx.lr = 0x88267920;
	sub_880A6B28(ctx, base);
	// li r10,10
	ctx.r10.s64 = 10;
	// li r9,24
	ctx.r9.s64 = 24;
	// stw r3,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88267940:
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bge 0x88267ad8
	if (!ctx.cr0.lt) goto loc_88267AD8;
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lis r10,-30707
	ctx.r10.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,13096
	ctx.r4.s64 = ctx.r10.s64 + 13096;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bl 0x880a6800
	ctx.lr = 0x8826796C;
	sub_880A6800(ctx, base);
	// lis r9,-30707
	ctx.r9.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,12992
	ctx.r4.s64 = ctx.r9.s64 + 12992;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x88267980;
	sub_880A6800(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// li r8,4
	ctx.r8.s64 = 4;
	// li r29,0
	ctx.r29.s64 = 0;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r8,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// lis r7,-30684
	ctx.r7.s64 = -2010906624;
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// addi r4,r7,-1296
	ctx.r4.s64 = ctx.r7.s64 + -1296;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6b28
	ctx.lr = 0x882679B0;
	sub_880A6B28(ctx, base);
	// lis r6,40
	ctx.r6.s64 = 2621440;
	// lis r5,340
	ctx.r5.s64 = 22282240;
	// stw r3,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r3.u32);
	// lwz r4,9100(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 9100);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// beq cr6,0x882679dc
	if (ctx.cr6.eq) goto loc_882679DC;
	// lis r11,200
	ctx.r11.s64 = 13107200;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_882679DC:
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6320
	ctx.lr = 0x882679F0;
	sub_880A6320(ctx, base);
	// li r10,40
	ctx.r10.s64 = 40;
	// stw r29,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r29.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lwz r4,32(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x880a6918
	ctx.lr = 0x88267A08;
	sub_880A6918(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88267A14:
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// beq cr6,0x88267ab4
	if (ctx.cr6.eq) goto loc_88267AB4;
	// cmpwi cr6,r11,50
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 50, ctx.xer);
	// bne cr6,0x88267ad8
	if (!ctx.cr6.eq) goto loc_88267AD8;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88267a50
	if (ctx.cr6.eq) goto loc_88267A50;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88267ad8
	if (ctx.cr0.gt) goto loc_88267AD8;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88267A50:
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,30384
	ctx.r4.s64 = ctx.r11.s64 + 30384;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6588
	ctx.lr = 0x88267A64;
	sub_880A6588(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,9104(r28)
	REX_STORE_U32(ctx.r28.u32 + 9104, ctx.r10.u32);
	// bl 0x8812f858
	ctx.lr = 0x88267A74;
	sub_8812F858(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r7,-30707
	ctx.r7.s64 = -2012413952;
	// stw r8,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,7528
	ctx.r4.s64 = ctx.r7.s64 + 7528;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x88267A9C;
	sub_880A6800(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a64a8
	ctx.lr = 0x88267AA8;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88267AB4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,36(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// bl 0x880a6970
	ctx.lr = 0x88267AC0;
	sub_880A6970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88267ad8
	if (!ctx.cr6.eq) goto loc_88267AD8;
	// li r11,50
	ctx.r11.s64 = 50;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
loc_88267AD8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88267AE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x88267AF0;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88267B10;
	sub_880A6EC0(ctx, base);
	// lwz r10,9100(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 9100);
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r9,9100(r28)
	REX_STORE_U32(ctx.r28.u32 + 9100, ctx.r9.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// li r7,64
	ctx.r7.s64 = 64;
	// stw r30,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r30.u32);
	// addi r6,r10,-11936
	ctx.r6.s64 = ctx.r10.s64 + -11936;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// stw r8,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// lis r4,360
	ctx.r4.s64 = 23592960;
	// stw r7,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r7.u32);
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stw r9,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r9.u32);
	// stw r9,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r9.u32);
	// stw r30,44(r3)
	REX_STORE_U32(ctx.r3.u32 + 44, ctx.r30.u32);
	// lwz r3,5728(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 5728);
	// cmpw cr6,r3,r6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r6.s32, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// stw r4,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x88267b94
	if (ctx.cr6.eq) goto loc_88267B94;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6320
	ctx.lr = 0x88267B94;
	sub_880A6320(ctx, base);
loc_88267B94:
	// lis r10,-30669
	ctx.r10.s64 = -2009923584;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// lis r9,16838
	ctx.r9.s64 = 1103495168;
	// lis r8,-30707
	ctx.r8.s64 = -2012413952;
	// ori r7,r9,20077
	ctx.r7.u64 = ctx.r9.u64 | 20077;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,4328(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4328);
	// addi r4,r8,7528
	ctx.r4.s64 = ctx.r8.s64 + 7528;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mullw r11,r11,r7
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// addi r11,r11,12345
	ctx.r11.s64 = ctx.r11.s64 + 12345;
	// stw r11,4328(r10)
	REX_STORE_U32(ctx.r10.u32 + 4328, ctx.r11.u32);
	// lhz r11,4328(r10)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + 4328);
	// clrlwi r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	// addi r6,r11,1
	ctx.r6.s64 = ctx.r11.s64 + 1;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x880a6800
	ctx.lr = 0x88267BD8;
	sub_880A6800(ctx, base);
	// lis r5,-30682
	ctx.r5.s64 = -2010775552;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r5,r5,30504
	ctx.r5.s64 = ctx.r5.s64 + 30504;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x880a6530
	ctx.lr = 0x88267BEC;
	sub_880A6530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88267BF8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081158
	ctx.lr = 0x88267C00;
	__savegprlr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// lwz r28,2304(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88267C20;
	sub_880A6EC0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88267d08
	if (ctx.cr6.eq) goto loc_88267D08;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x88267c98
	if (ctx.cr6.eq) goto loc_88267C98;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x88267d74
	if (!ctx.cr6.eq) goto loc_88267D74;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88267c6c
	if (ctx.cr6.eq) goto loc_88267C6C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// bgt 0x88267d74
	if (ctx.cr0.gt) goto loc_88267D74;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88267C6C:
	// lis r11,-30682
	ctx.r11.s64 = -2010775552;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,31464
	ctx.r4.s64 = ctx.r11.s64 + 31464;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6588
	ctx.lr = 0x88267C80;
	sub_880A6588(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a64a8
	ctx.lr = 0x88267C8C;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
loc_88267C98:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,32(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x880a6970
	ctx.lr = 0x88267CA4;
	sub_880A6970(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x88267d74
	if (!ctx.cr6.eq) goto loc_88267D74;
	// lis r11,-30707
	ctx.r11.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,13200
	ctx.r4.s64 = ctx.r11.s64 + 13200;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6800
	ctx.lr = 0x88267CC0;
	sub_880A6800(ctx, base);
	// lis r10,-30696
	ctx.r10.s64 = -2011693056;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r8,192
	ctx.r8.s64 = 192;
	// addi r7,r10,-11936
	ctx.r7.s64 = ctx.r10.s64 + -11936;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,120
	ctx.r5.s64 = 7864320;
	// lwz r3,5728(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 5728);
	// lis r4,360
	ctx.r4.s64 = 23592960;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// cmpw cr6,r3,r7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r7.s32, ctx.xer);
	// stw r4,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// beq cr6,0x88267d74
	if (ctx.cr6.eq) goto loc_88267D74;
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// b 0x88267d68
	goto loc_88267D68;
loc_88267D08:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x88267d74
	if (ctx.cr0.gt) goto loc_88267D74;
	// lwz r11,9100(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 9100);
	// lis r10,-30684
	ctx.r10.s64 = -2010906624;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,216
	ctx.r4.s64 = ctx.r10.s64 + 216;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x880a6b28
	ctx.lr = 0x88267D34;
	sub_880A6B28(ctx, base);
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,96
	ctx.r8.s64 = 96;
	// stw r3,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lis r6,120
	ctx.r6.s64 = 7864320;
	// stw r8,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r8.u32);
	// lis r5,300
	ctx.r5.s64 = 19660800;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lis r4,-30696
	ctx.r4.s64 = -2011693056;
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r4,r4,-11936
	ctx.r4.s64 = ctx.r4.s64 + -11936;
loc_88267D68:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x880a6320
	ctx.lr = 0x88267D74;
	sub_880A6320(ctx, base);
loc_88267D74:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x880811a8
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88267D80) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8808115c
	ctx.lr = 0x88267D88;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r5,48
	ctx.r5.s64 = 48;
	// bl 0x880a6ec0
	ctx.lr = 0x88267DA4;
	sub_880A6EC0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r11,64
	ctx.r11.s64 = 64;
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r9,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// li r6,80
	ctx.r6.s64 = 80;
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// li r29,32
	ctx.r29.s64 = 32;
	// stw r11,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lis r5,-30682
	ctx.r5.s64 = -2010775552;
	// stw r10,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r7,28(r8)
	REX_STORE_U32(ctx.r8.u32 + 28, ctx.r7.u32);
	// addi r5,r5,31736
	ctx.r5.s64 = ctx.r5.s64 + 31736;
	// stw r6,40(r8)
	REX_STORE_U32(ctx.r8.u32 + 40, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r29,44(r8)
	REX_STORE_U32(ctx.r8.u32 + 44, ctx.r29.u32);
	// bl 0x880a6530
	ctx.lr = 0x88267DF8;
	sub_880A6530(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88267E08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x88081150
	ctx.lr = 0x88267E10;
	__savegprlr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lwz r29,2304(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 2304);
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a6ec0
	ctx.lr = 0x88267E34;
	sub_880A6EC0(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88268008
	if (ctx.cr6.eq) goto loc_88268008;
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// beq cr6,0x88267ec8
	if (ctx.cr6.eq) goto loc_88267EC8;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bne cr6,0x8826807c
	if (!ctx.cr6.eq) goto loc_8826807C;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x88268014
	if (!ctx.cr6.eq) goto loc_88268014;
	// lwz r11,2304(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 2304);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r9,-30707
	ctx.r9.s64 = -2012413952;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,12248
	ctx.r4.s64 = ctx.r9.s64 + 12248;
	// stw r10,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r10.u32);
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x880a6800
	ctx.lr = 0x88267E88;
	sub_880A6800(ctx, base);
	// lwz r11,9100(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 9100);
	// stw r30,9104(r29)
	REX_STORE_U32(ctx.r29.u32 + 9104, ctx.r30.u32);
	// lis r8,-30682
	ctx.r8.s64 = -2010775552;
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// addi r4,r8,32128
	ctx.r4.s64 = ctx.r8.s64 + 32128;
	// stw r6,9100(r29)
	REX_STORE_U32(ctx.r29.u32 + 9100, ctx.r6.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a6588
	ctx.lr = 0x88267EB0;
	sub_880A6588(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a64a8
	ctx.lr = 0x88267EBC;
	sub_880A64A8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880811a0
	__restgprlr_26(ctx, base);
	return;
loc_88267EC8:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88267f8c
	if (ctx.cr6.eq) goto loc_88267F8C;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8826807c
	if (ctx.cr0.gt) goto loc_8826807C;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-30684
	ctx.r9.s64 = -2010906624;
	// cntlzw r8,r11
	ctx.r8.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// addi r4,r9,-3424
	ctx.r4.s64 = ctx.r9.s64 + -3424;
	// xori r11,r7,1
	ctx.r11.u64 = ctx.r7.u64 ^ 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r6,r11,2
	ctx.r6.s64 = ctx.r11.s64 + 2;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x880a6b28
	ctx.lr = 0x88267F14;
	sub_880A6B28(ctx, base);
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r5,4
	ctx.r5.s64 = 4;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// beq cr6,0x88267f38
	if (ctx.cr6.eq) goto loc_88267F38;
	// lis r10,400
	ctx.r10.s64 = 26214400;
	// lis r11,120
	ctx.r11.s64 = 7864320;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// b 0x88267f58
	goto loc_88267F58;
loc_88267F38:
	// lwz r11,9100(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 9100);
	// lis r10,220
	ctx.r10.s64 = 14417920;
	// lis r9,360
	ctx.r9.s64 = 23592960;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r9,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// beq cr6,0x88267f5c
	if (ctx.cr6.eq) goto loc_88267F5C;
	// lis r11,20
	ctx.r11.s64 = 1310720;
loc_88267F58:
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
loc_88267F5C:
	// lis r11,-30696
	ctx.r11.s64 = -2011693056;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-11936
	ctx.r4.s64 = ctx.r11.s64 + -11936;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a6320
	ctx.lr = 0x88267F70;
	sub_880A6320(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,5
	ctx.r9.s64 = 327680;
	// stw r10,24(r29)
	REX_STORE_U32(ctx.r29.u32 + 24, ctx.r10.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r9,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r9.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880811a0
	__restgprlr_26(ctx, base);
	return;
loc_88267F8C:
	// lwz r11,24(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8826807c
	if (!ctx.cr6.eq) goto loc_8826807C;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88267fb8
	if (ctx.cr6.eq) goto loc_88267FB8;
	// li r11,20
	ctx.r11.s64 = 20;
	// li r10,128
	ctx.r10.s64 = 128;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// b 0x88267fcc
	goto loc_88267FCC;
loc_88267FB8:
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
loc_88267FCC:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8812f858
	ctx.lr = 0x88267FD4;
	sub_8812F858(ctx, base);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lis r8,-30707
	ctx.r8.s64 = -2012413952;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,7528
	ctx.r4.s64 = ctx.r8.s64 + 7528;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x880a6800
	ctx.lr = 0x88267FFC;
	sub_880A6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880811a0
	__restgprlr_26(ctx, base);
	return;
loc_88268008:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x88268034
	if (ctx.cr6.eq) goto loc_88268034;
loc_88268014:
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bgt 0x8826807c
	if (ctx.cr0.gt) goto loc_8826807C;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880811a0
	__restgprlr_26(ctx, base);
	return;
loc_88268034:
	// li r11,10
	ctx.r11.s64 = 10;
	// li r10,64
	ctx.r10.s64 = 64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// lis r9,-30707
	ctx.r9.s64 = -2012413952;
	// lwz r8,2304(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 2304);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,36(r8)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r8.u32 + 36);
	// addi r4,r9,12248
	ctx.r4.s64 = ctx.r9.s64 + 12248;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// stw r30,88(r8)
	REX_STORE_U32(ctx.r8.u32 + 88, ctx.r30.u32);
	// bl 0x880a6800
	ctx.lr = 0x88268068;
	sub_880A6800(ctx, base);
	// lis r7,-30707
	ctx.r7.s64 = -2012413952;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,36(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// addi r4,r7,14712
	ctx.r4.s64 = ctx.r7.s64 + 14712;
	// bl 0x880a6800
	ctx.lr = 0x8826807C;
	sub_880A6800(ctx, base);
loc_8826807C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x880811a0
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_88268088) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8808115c
	ctx.lr = 0x88268090;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,19
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 19, ctx.xer);
	// bgt cr6,0x882684b0
	if (ctx.cr6.gt) goto loc_882684B0;
	// lis r12,-30681
	ctx.r12.s64 = -2010710016;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,-32572
	ctx.r12.s64 = ctx.r12.s64 + -32572;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_88268114;
	case 1:
		goto loc_882681AC;
	case 2:
		goto loc_8826826C;
	case 3:
		goto loc_882684B0;
	case 4:
		goto loc_88268284;
	case 5:
		goto loc_88268298;
	case 6:
		goto loc_882682B4;
	case 7:
		goto loc_882682D0;
	case 8:
		goto loc_882682F4;
	case 9:
		goto loc_88268350;
	case 10:
		goto loc_88268370;
	case 11:
		goto loc_8826838C;
	case 12:
		goto loc_882683C0;
	case 13:
		goto loc_882683D8;
	case 14:
		goto loc_88268400;
	case 15:
		goto loc_88268414;
	case 16:
		goto loc_88268428;
	case 17:
		goto loc_88268440;
	case 18:
		goto loc_88268450;
	case 19:
		goto loc_88268498;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_88268114:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x882684b4
	if (ctx.cr6.eq) goto loc_882684B4;
	// lis r11,-30595
	ctx.r11.s64 = -2005073920;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-30626
	ctx.r10.s64 = -2007105536;
	// lwz r8,4(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,-10708
	ctx.r11.s64 = ctx.r11.s64 + -10708;
	// lwz r7,8(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r6,12(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// addi r4,r10,23624
	ctx.r4.s64 = ctx.r10.s64 + 23624;
	// lwz r5,16(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// li r31,3
	ctx.r31.s64 = 3;
	// lwz r29,20(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// stw r9,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r9.u32);
	// subf r4,r4,r29
	ctx.r4.u64 = ctx.r29.u64 - ctx.r4.u64;
	// stw r8,68(r11)
	REX_STORE_U32(ctx.r11.u32 + 68, ctx.r8.u32);
	// stw r7,104(r11)
	REX_STORE_U32(ctx.r11.u32 + 104, ctx.r7.u32);
	// stw r6,-128(r11)
	REX_STORE_U32(ctx.r11.u32 + -128, ctx.r6.u32);
	// stw r5,-108(r11)
	REX_STORE_U32(ctx.r11.u32 + -108, ctx.r5.u32);
loc_88268164:
	// li r7,8
	ctx.r7.s64 = 8;
	// add r9,r4,r10
	ctx.r9.u64 = ctx.r4.u64 + ctx.r10.u64;
	// addi r8,r10,-4
	ctx.r8.s64 = ctx.r10.s64 + -4;
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_88268178:
	// lwzu r7,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r7.u64 = REX_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// bdnz 0x88268178
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_88268178;
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// bne 0x88268164
	if (!ctx.cr0.eq) goto loc_88268164;
	// lwz r10,24(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r9,28(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,-36(r11)
	REX_STORE_U32(ctx.r11.u32 + -36, ctx.r10.u32);
	// stw r9,-32(r11)
	REX_STORE_U32(ctx.r11.u32 + -32, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_882681AC:
	// bl 0x880a23e8
	ctx.lr = 0x882681B0;
	sub_880A23E8(ctx, base);
	// lis r10,-30713
	ctx.r10.s64 = -2012807168;
	// lis r9,-30595
	ctx.r9.s64 = -2005073920;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// addi r10,r10,7700
	ctx.r10.s64 = ctx.r10.s64 + 7700;
	// addi r31,r9,-10708
	ctx.r31.s64 = ctx.r9.s64 + -10708;
loc_882681C4:
	// lbzx r9,r11,r10
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// addi r8,r31,-988
	ctx.r8.s64 = ctx.r31.s64 + -988;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stbx r9,r11,r8
	REX_STORE_U8(ctx.r11.u32 + ctx.r8.u32, ctx.r9.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bne cr6,0x882681c4
	if (!ctx.cr6.eq) goto loc_882681C4;
	// addi r3,r31,-476
	ctx.r3.s64 = ctx.r31.s64 + -476;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x88083bd0
	ctx.lr = 0x882681EC;
	sub_88083BD0(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// lis r10,-30719
	ctx.r10.s64 = -2013200384;
	// stw r30,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r30.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r30,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r30.u32);
	// addi r10,r10,-31808
	ctx.r10.s64 = ctx.r10.s64 + -31808;
	// stw r30,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r30.u32);
	// lis r9,-30700
	ctx.r9.s64 = -2011955200;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stw r10,116(r31)
	REX_STORE_U32(ctx.r31.u32 + 116, ctx.r10.u32);
	// addi r11,r9,23520
	ctx.r11.s64 = ctx.r9.s64 + 23520;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// std r30,0(r7)
	REX_STORE_U64(ctx.r7.u32 + 0, ctx.r30.u64);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,-44(r31)
	REX_STORE_U32(ctx.r31.u32 + -44, ctx.r11.u32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// addi r8,r31,-3708
	ctx.r8.s64 = ctx.r31.s64 + -3708;
	// stw r10,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r10.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r9,60
	ctx.r9.s64 = 60;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// addi r10,r8,-1
	ctx.r10.s64 = ctx.r8.s64 + -1;
	// stw r9,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r9.u32);
	// addi r11,r7,-1
	ctx.r11.s64 = ctx.r7.s64 + -1;
loc_8826824C:
	// lbzu r9,1(r11)
	ea = 1 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U8(ea);
	ctx.r11.u32 = ea;
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x8826824c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8826824C;
	// bl 0x8809d0a8
	ctx.lr = 0x8826825C;
	sub_8809D0A8(ctx, base);
	// bl 0x8809fe10
	ctx.lr = 0x88268260;
	sub_8809FE10(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_8826826C:
	// bl 0x8809fad0
	ctx.lr = 0x88268270;
	sub_8809FAD0(ctx, base);
	// bl 0x8809ff70
	ctx.lr = 0x88268274;
	sub_8809FF70(ctx, base);
	// bl 0x8809d938
	ctx.lr = 0x88268278;
	sub_8809D938(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_88268284:
	// bl 0x8809fa80
	ctx.lr = 0x88268288;
	sub_8809FA80(ctx, base);
	// bl 0x8809e480
	ctx.lr = 0x8826828C;
	sub_8809E480(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_88268298:
	// lis r11,-30595
	ctx.r11.s64 = -2005073920;
	// addi r11,r11,-10708
	ctx.r11.s64 = ctx.r11.s64 + -10708;
	// addi r10,r11,72
	ctx.r10.s64 = ctx.r11.s64 + 72;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_882682B4:
	// lis r11,-30595
	ctx.r11.s64 = -2005073920;
	// addi r11,r11,-10708
	ctx.r11.s64 = ctx.r11.s64 + -10708;
	// addi r10,r11,80
	ctx.r10.s64 = ctx.r11.s64 + 80;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_882682D0:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x882684b4
	if (ctx.cr6.eq) goto loc_882684B4;
	// lis r11,-30595
	ctx.r11.s64 = -2005073920;
	// addi r11,r11,-10708
	ctx.r11.s64 = ctx.r11.s64 + -10708;
	// addi r10,r11,-72
	ctx.r10.s64 = ctx.r11.s64 + -72;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_882682F4:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x882684b4
	if (ctx.cr6.eq) goto loc_882684B4;
	// lis r9,-30595
	ctx.r9.s64 = -2005073920;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addi r31,r9,-10708
	ctx.r31.s64 = ctx.r9.s64 + -10708;
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,12(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r7,16(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r6,20(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r5,24(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r4,28(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// stw r9,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r9.u32);
	// stw r8,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r8.u32);
	// stw r7,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r7.u32);
	// stw r6,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r6.u32);
	// stw r5,-180(r31)
	REX_STORE_U32(ctx.r31.u32 + -180, ctx.r5.u32);
	// stw r4,-176(r31)
	REX_STORE_U32(ctx.r31.u32 + -176, ctx.r4.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_88268350:
	// lis r11,-30595
	ctx.r11.s64 = -2005073920;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r9,r11,-10708
	ctx.r9.s64 = ctx.r11.s64 + -10708;
	// stw r10,-88(r9)
	REX_STORE_U32(ctx.r9.u32 + -88, ctx.r10.u32);
	// stw r30,-84(r9)
	REX_STORE_U32(ctx.r9.u32 + -84, ctx.r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_88268370:
	// lis r11,-30681
	ctx.r11.s64 = -2010710016;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r9,r11,11608
	ctx.r9.s64 = ctx.r11.s64 + 11608;
	// stw r10,128(r9)
	REX_STORE_U32(ctx.r9.u32 + 128, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_8826838C:
	// lis r11,-30595
	ctx.r11.s64 = -2005073920;
	// lis r8,-30681
	ctx.r8.s64 = -2010710016;
	// addi r7,r11,-10708
	ctx.r7.s64 = ctx.r11.s64 + -10708;
	// lis r9,0
	ctx.r9.s64 = 0;
	// li r11,3
	ctx.r11.s64 = 3;
	// li r10,-1
	ctx.r10.s64 = -1;
	// ori r9,r9,32768
	ctx.r9.u64 = ctx.r9.u64 | 32768;
	// stw r10,11608(r8)
	REX_STORE_U32(ctx.r8.u32 + 11608, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,-8(r7)
	REX_STORE_U32(ctx.r7.u32 + -8, ctx.r11.u32);
	// stw r9,16(r7)
	REX_STORE_U32(ctx.r7.u32 + 16, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_882683C0:
	// lis r10,-30595
	ctx.r10.s64 = -2005073920;
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,-10708(r10)
	REX_STORE_U32(ctx.r10.u32 + -10708, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_882683D8:
	// lis r11,-30595
	ctx.r11.s64 = -2005073920;
	// addi r11,r11,-10708
	ctx.r11.s64 = ctx.r11.s64 + -10708;
	// lbz r10,-69(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -69);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x882684b4
	if (!ctx.cr6.eq) goto loc_882684B4;
	// li r10,2
	ctx.r10.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_88268400:
	// lwz r4,16(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// bl 0x8809f200
	ctx.lr = 0x88268408;
	sub_8809F200(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_88268414:
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x8809f168
	ctx.lr = 0x8826841C;
	sub_8809F168(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_88268428:
	// lwz r4,4(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x8809f0b0
	ctx.lr = 0x88268434;
	sub_8809F0B0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_88268440:
	// bl 0x8809efc0
	ctx.lr = 0x88268444;
	sub_8809EFC0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_88268450:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x8826846c
	if (ctx.cr6.lt) goto loc_8826846C;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// blt cr6,0x88268480
	if (ctx.cr6.lt) goto loc_88268480;
	// cmplwi cr6,r11,15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 15, ctx.xer);
	// bge cr6,0x88268480
	if (!ctx.cr6.lt) goto loc_88268480;
loc_8826846C:
	// lis r10,-30681
	ctx.r10.s64 = -2010710016;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,11608(r10)
	REX_STORE_U32(ctx.r10.u32 + 11608, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_88268480:
	// lis r10,-30681
	ctx.r10.s64 = -2010710016;
	// li r11,-1
	ctx.r11.s64 = -1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,11608(r10)
	REX_STORE_U32(ctx.r10.u32 + 11608, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_88268498:
	// lwz r4,4(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x8809eee0
	ctx.lr = 0x882684A4;
	sub_8809EEE0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
loc_882684B0:
	// li r30,-1
	ctx.r30.s64 = -1;
loc_882684B4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x880811ac
	__restgprlr_29(ctx, base);
	return;
}

