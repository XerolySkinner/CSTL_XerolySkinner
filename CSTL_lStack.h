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
	名字:CSTL_lStack
	时间:20221102-1904
	程序员:梁源康
	说明:实现栈
*/
#ifndef _XEROLYSKINNER_CSTL_LSTACK_H
#define _XEROLYSKINNER_CSTL_LSTACK_H
#include "CSTL_stdint.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	编译开关
//	
#define		_USE_CSTL_STACK_LIST8			//	使用LIST8的栈堆
#define		_USE_CSTL_STACK_LIST32			//	使用LIST32的栈堆
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
//	8位数据链表为基本的函数声明
//	
#ifdef _USE_CSTL_STACK_LIST8
typedef struct {
		struct _8lStackNode*	up;			//	上元素
		u8						dat;		//	数据
	}_8lStackNode;
typedef struct {
		u32						size;		//	元素数
		_8lStackNode*			top;		//	顶部
	}_8lStack;
//----------------------------------------------------------------------------------------------------
_8lStack*	CREAT8_lStack	(void);
u8			PUSH8_lStack	(_8lStack* stacks, u8 dat);
u8			POP8_lStack		(_8lStack* stacks);
u8			TOP8_lStack		(_8lStack* stacks, u8* dat);
u32			SIZE8_lStack	(_8lStack* stacks, u32* dat);
//----------------------------------------------------------------------------------------------------
u8			POPTOP8_lStack	(_8lStack* stacks);
u32			SIZEMEM8_lStack	(_8lStack* stacks);
//----------------------------------------------------------------------------------------------------
#endif // _USE_CSTL_STACK_LIST8
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	32位数据链表为基本的函数声明
//	
#ifdef _USE_CSTL_STACK_LIST32
//----------------------------------------------------------------------------------------------------
typedef struct {
	struct _32lStackNode*		up;			//	上元素
	u32							dat;		//	数据
	}_32lStackNode;
typedef struct {
	u32							size;		//	元素数
	_32lStackNode*				top;		//	顶部
	}_32lStack;
//----------------------------------------------------------------------------------------------------
_32lStack*	CREAT32_lStack(void);
u8			PUSH32_lStack	(_32lStack* stacks, u32 dat);
u8			POP32_lStack	(_32lStack* stacks);
u32			TOP32_lStack	(_32lStack* stacks, u32* dat);
u32			SIZE32_lStack	(_32lStack* stacks, u32* dat);
//----------------------------------------------------------------------------------------------------
u32			POPTOP32_lStack	(_32lStack* stacks);
u32			SIZEMEM32_lStack(_32lStack* stacks);
void(*POPTOPFUN_lStack(_8lStack* stacks))(void);
//----------------------------------------------------------------------------------------------------
#endif // _USE_CSTL_STACK_LIST32
//////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
