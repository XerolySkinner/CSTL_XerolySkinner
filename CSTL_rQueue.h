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
