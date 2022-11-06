/*----------------------------------------------------------------------------------------------------
 #
 #	Copyright (c) 2022 Yuankang Liang(XerolySkinner)
 #
 #	本软件按原样提供,无任何明示或暗示
 #	在任何情况下,作者都不承担任何损害赔偿责任
 #
 #	使用的许可声明:
 #	1.	不得歪曲本软件的来源,你不能声称你编写了原始软件.
 #	2.	免费授予以任何目的,前提是版权声明出现在所有副本中.
 #		并且版权声明和许可声明同时出现.
 #	3.	你有使用,复制,修改,分发,和销售本软件的许可.
 #	4.	如果你在产品中使用,产品文档中的声明是赞赏的但不是必须的.
 #	5.	本通知不得从任何来源删除或更改.
 #
 #	Yuankang Liang(XerolySkinner)
 #		E-mail:zabbcccbbaz@163.com
 #		QQ:2715099320
 #		Mobile Phone:13005636215
 #
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
	STACKS_MALL_ERROR
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	结构体声明
//	
typedef struct {
	u32						room;		//	分配空间
	u32						size;		//	已有成员
	u8*						dat;		//	数据头
	}_rStack;
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	函数声明
//	
_rStack* CREAT8_rStack(void);							//	创建一个栈
u8			DEL8_rStack(_rStack* queues);				//	删除一个栈
u8			PUSH8_rStack(_rStack* queues, u8 dat);		//	向一个栈压入数据
u8			POP8_rStack(_rStack* queues);				//	弹出一个栈的数据
u8			CLS8_rStack(_rStack* queues);				//	清除一个栈的冗余空间
u8			TOP8_rStack(_rStack* queues, u8* dat);		//	出示栈的一个数据
u8			SIZE8_rStack(_rStack* queues, u32* dat);	//	出示栈的成员数
u8			ROOM8_rStack(_rStack* queues, u32* dat);	//	出示栈的占用空间
//----------------------------------------------------------------------------------------------------
u8			POPTOP8_rStack(_rStack* queues);			//	弹出并出示栈的顶端
u32			SIZEMEM8_rStack(_rStack* queues);			//	出示栈的占用空间
//----------------------------------------------------------------------------------------------------
_rStack*	CREAT32_rStack(void);						//	创造一个32位的栈
u8			PUSH32_rStack(_rStack* queues, u32 dat);	//	压入一个32位元素
u32			POPTOP32_rStack(_rStack* queues);			//	弹出并出示一个32位的元素
void		(*POPTOPFUN_rStack(_rStack* queues))(void);	//	弹出一个void(void)函数
//////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
