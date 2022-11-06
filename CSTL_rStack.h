/*----------------------------------------------------------------------------------------------------
#	THIS FILE IS A PART OF XerolySkinner's PROJECT
#
#	THIS PROGRAM IS FREE SOFTWARE
#
#	E-mail:ZABBCCCBBAZ@163.com
#	QQ:2715099320
#
#	Copyright (c) 2022 XerolySkinner
#	All rights reserved.
*/

/*----------------------------------------------------------------------------------------------------
	名字:CSTL_rStack
	时间:20221102-1904
	程序员:梁源康
	说明:实现栈
*/
#ifndef _XEROLYSKINNER_CSTL_RSTACK_H
#define _XEROLYSKINNER_CSTL_RSTACK_H
#include "CSTL_stdint.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	错误枚举
//	
enum {
	STACKS_OK,
	STACKS_NULL,
	STACKS_EMPTY,
	STACKS_REAL_ERROR,
	STACKS_MALL_ERROR};
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	结构体定义
//	
typedef struct {
	u32						size;		//	元素数
	u8*						dat;		//	顶部
	}_rStack;
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	程序声明
//	
_rStack*	CREAT8_rStack	(void);
u8			PUSH8_rStack	(_rStack* stacks, u8 dat);
u8			POP8_rStack		(_rStack* stacks);
u8			TOP8_rStack		(_rStack* stacks, u8* dat);
u8			SIZE8_rStack	(_rStack* stacks, u32* dat);
//----------------------------------------------------------------------------------------------------
u8			POPTOP8_rStack	(_rStack* stacks);
u32			SIZEMEM8_rStack	(_rStack* stacks);
//----------------------------------------------------------------------------------------------------
_rStack*	CREAT32_rStack	(void);
u8			PUSH32_rStack	(_rStack* stacks, u32 dat);
u32			POPTOP32_rStack	(_rStack* stacks);
void		(*POPTOPFUN_rStack(_rStack* stacks))(void);
//////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
