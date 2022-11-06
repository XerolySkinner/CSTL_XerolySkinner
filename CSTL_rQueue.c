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

//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	头文件
#include "CSTL_rQueue.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	程序基底
_rQueue* CREAT8_rQueue(void) {
	_rQueue* queues = malloc(sizeof(_rQueue));
	if (queues == NULL)return NULL;
	queues->size = 0;
	queues->dat = NULL;
	return queues;}
//----------------------------------------------------------------------------------------------------
u8 PUSH8_rQueue(_rQueue* queues, u8 dat) {
	if (queues == NULL)return QUEUES_NULL;
	u8* temp_queues = queues->dat;
	queues->dat = realloc(queues->dat, ++queues->size);
	if (queues->dat == NULL) {
		queues->dat = temp_queues;
		return QUEUES_REAL_ERROR;}
	(queues->dat)[queues->size - 1] = dat;
	return QUEUES_OK;}
//----------------------------------------------------------------------------------------------------
u8 POP8_rQueue(_rQueue* queues) {
	if (queues == NULL)return QUEUES_NULL;
	u8* temp_queues = queues->dat;
	if (queues->size > 1) {
		memcpy(queues->dat,queues->dat+1,queues->size-1);
		queues->dat = realloc(queues->dat, --queues->size);
		if (queues->dat == NULL) {
			queues->dat = temp_queues;
			return QUEUES_REAL_ERROR;}
		return QUEUES_OK;}
	else if (queues->size == 1) {
		queues->size = 0;
		free(queues->dat);
		queues->dat = NULL;
		return QUEUES_OK;}
	else
		return QUEUES_EMPTY;}
//----------------------------------------------------------------------------------------------------
u8 TOP8_rQueue(_rQueue* queues, u8* dat) {
	if (queues == NULL)return QUEUES_NULL;
	if (queues->size) {
		*dat = (queues->dat)[0];
		return QUEUES_OK;}
	return QUEUES_EMPTY;}
//----------------------------------------------------------------------------------------------------
u8 SIZE8_rQueue(_rQueue* queues, u32* dat) {
	if (queues == NULL)return QUEUES_NULL;
	*dat = queues->size;
	return QUEUES_OK;}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	程序顶层封装
//	
u8 POPTOP8_rQueue(_rQueue* queues) {
	u8 dat = 0;
	TOP8_rQueue(queues, &dat);
	POP8_rQueue(queues);
	return dat;}
//----------------------------------------------------------------------------------------------------
u32	SIZEMEM8_rQueue(_rQueue* queues) {
	return queues->size;}
//----------------------------------------------------------------------------------------------------
//	32位改版
_rQueue* CREAT32_rQueue(void) {
	_rQueue* queues = CREAT8_rQueue();
	return queues;}
//----------------------------------------------------------------------------------------------------
u8	PUSH32_rQueue(_rQueue* queues, u32 dat) {
	PUSH8_rQueue(queues, ((u8*)(&dat))[3]);
	PUSH8_rQueue(queues, ((u8*)(&dat))[2]);
	PUSH8_rQueue(queues, ((u8*)(&dat))[1]);
	PUSH8_rQueue(queues, ((u8*)(&dat))[0]);
	return QUEUES_OK;}
//----------------------------------------------------------------------------------------------------
u32 POPTOP32_rQueue(_rQueue* queues) {
	u8 dat[4] = { 0,0,0,0 };
	TOP8_rQueue(queues, dat + 3);
	POP8_rQueue(queues);
	TOP8_rQueue(queues, dat + 2);
	POP8_rQueue(queues);
	TOP8_rQueue(queues, dat + 1);
	POP8_rQueue(queues);
	TOP8_rQueue(queues, dat + 0);
	POP8_rQueue(queues);
	return *((u32*)(dat));}
//----------------------------------------------------------------------------------------------------
void(*POPTOPFUN_rQueue(_rQueue* queues))(void) {
	return POPTOP32_rQueue(queues);}
//////////////////////////////////////////////////////////////////////////////////////////////////////
