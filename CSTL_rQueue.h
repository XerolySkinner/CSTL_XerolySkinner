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
	名字:CSTL_rQueue
	时间:20221103-1947
	程序员:梁源康
	说明:实现队列
*/
#ifndef _XEROLYSKINNER_CSTL_RQUEUE_H
#define _XEROLYSKINNER_CSTL_RQUEUE_H
#include "CSTL_stdint.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	错误枚举
//	
enum {
	QUEUES_OK,
	QUEUES_NULL,
	QUEUES_EMPTY,
	QUEUES_REAL_ERROR,
	QUEUES_MALL_ERROR
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	结构体声明
//	
typedef struct {
	u32						size;		//	元素数
	u8*						dat;		//	顶部
	}_rQueue;
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	函数声明
//	
_rQueue	*	CREAT8_rQueue	(void);
u8			PUSH8_rQueue	(_rQueue* queues, u8 dat);
u8			POP8_rQueue		(_rQueue* queues);
u8			TOP8_rQueue		(_rQueue* queues, u8* dat);
u8			SIZE8_rQueue	(_rQueue* queues, u32* dat);
//----------------------------------------------------------------------------------------------------
u8			POPTOP8_rQueue	(_rQueue* queues);
u32			SIZEMEM8_rQueue	(_rQueue* queues);
//----------------------------------------------------------------------------------------------------
_rQueue*	CREAT32_rQueue	(void);
u8			PUSH32_rQueue	(_rQueue* queues, u32 dat);
u32			POPTOP32_rQueue	(_rQueue* queues);
void		(*POPTOPFUN_rQueue(_rQueue* queues))(void);
//////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
