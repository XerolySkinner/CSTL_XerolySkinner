/*----------------------------------------------------------------------------------------------------
 #
 #	Copyright (c) 2022 Yuankang Liang(XerolySkinner)
 #
 #	�������ԭ���ṩ,���κ���ʾ��ʾ
 #	���κ������,���߶����е��κ����⳥����
 #
 #	ʹ�õ��������:
 #	1.	�����������������Դ,�㲻���������д��ԭʼ���.
 #	2.	����������κ�Ŀ��,ǰ���ǰ�Ȩ�������������и�����.
 #		���Ұ�Ȩ�������������ͬʱ����.
 #	3.	����ʹ��,����,�޸�,�ַ�,�����۱���������.
 #	4.	������ڲ�Ʒ��ʹ��,��Ʒ�ĵ��е����������͵ĵ����Ǳ����.
 #	5.	��֪ͨ���ô��κ���Դɾ�������.
 #
 #	Yuankang Liang(XerolySkinner)
 #		E-mail:zabbcccbbaz@163.com
 #		QQ:2715099320
 #		Mobile Phone:13005636215
 #
 #	All rights reserved.
 */

/*----------------------------------------------------------------------------------------------------
	����:CSTL_rQueue
	ʱ��:20221103-1947
	����Ա:��Դ��
	˵��:ʵ�ֶ���
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	ͷ�ļ�
#include "CSTL_rQueue.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	�������
_rQueue* CREAT8_rQueue(void) {
	//	��ֹ����ʧ��
	_rQueue* queues = malloc(sizeof(_rQueue));
	if (queues == NULL)return NULL;
	//	�¶��и�ֵ
	queues->room = 0;
	queues->size = 0;
	queues->dat = NULL;
	//	��������Ŀռ�ͷ
	return queues;}
//----------------------------------------------------------------------------------------------------
u8 DEL8_rQueue(_rQueue* queues) {
	//	��ֹ�������ͷ
	if (queues == NULL)return QUEUES_NULL;
	//	�ݻٶ�������
	if (queues->size)
		free(queues->dat);
	//	�ݻٶ���
	free(queues);
	//	��������Ŀռ�ͷ
	return QUEUES_OK;}
//----------------------------------------------------------------------------------------------------
u8 PUSH8_rQueue(_rQueue* queues, u8 dat) {
	//	��ֹ�������ͷ
	if (queues == NULL)return QUEUES_NULL;
	//	�������ǰ������ͷ
	u8* temp_queues = queues->dat;
	//	������ռ�С�����пռ�
	if (queues->size >= queues->room) {
		//	�����³���
		queues->dat = realloc(queues->dat, ++queues->size);
		//	����ʧ��,�ƺ��ҷ��ش���
		if (queues->dat == NULL) {
			--queues->size;					//	�ָ�ԭ����
			queues->dat = temp_queues;		//	�ָ�����
			return QUEUES_REAL_ERROR;}		//	���ش���
		queues->room = queues->size;
		//	����ɹ�,ѹ������
		(queues->dat)[queues->size - 1] = dat;
		//	������ȷָ��
		return QUEUES_OK;}
	//	�ռ�ʣ��,ѹ������
	(queues->dat)[(++queues->size) - 1] = dat;
	//	������ȷָ��
	return QUEUES_OK;}
//----------------------------------------------------------------------------------------------------
u8 POP8_rQueue(_rQueue* queues) {
	//	��ֹ�������ͷ
	if (queues == NULL)return QUEUES_NULL;
	//	�����ݶ����д���1,���̳�Ա�ռ�
	if (queues->size > 1) {
		//	�����ƶ���һλ
		memcpy(queues->dat,queues->dat+1,queues->size-1);
		--queues->size;						//	���·����Ա�ռ�
		return QUEUES_OK;}
	//	�����ݶ����е���1,��ָ��ͷ
	else if (queues->size == 1) {
		queues->size = 0;					//	���·����Ա�ռ�
		return QUEUES_OK;}
	//	�����ݶ���Ϊ��,���ؿն��д����
	else
		return QUEUES_EMPTY;}
//----------------------------------------------------------------------------------------------------
u8 CLS8_rQueue(_rQueue* queues) {
	//	��ֹ�������ͷ
	if (queues == NULL)return QUEUES_NULL;
	//	�������ǰ������ͷ
	u8* temp_queues = queues->dat;
	//	����г�Ա,���·���ռ�
	if (queues->size) {
		//	���·���ռ�
		queues->dat = realloc(queues->dat, queues->size);
		//	����ʧ��,�ƺ󲢷��ش���
		if (queues->dat == NULL) {
			--queues->size;						//	�ָ�ԭ����
			queues->dat = temp_queues;			//	�ָ�����
			return QUEUES_REAL_ERROR;}			//	���ش���
		}
	//	�޳�Ա�������·����Ա
	else {
		free(queues->dat);						//	�ͷ�ȫ���ռ�
		queues->size = 0;}						//	��ָ���ײ�
	//	�����ݷ��ؿն���
	queues->room = queues->size;				//	�µĿռ��С
	return QUEUES_OK;}
//----------------------------------------------------------------------------------------------------
u8 TOP8_rQueue(_rQueue* queues, u8* dat) {
	//	��ֹ�������ͷ
	if (queues == NULL)return QUEUES_NULL;
	//	��������,���ض�������
	if (queues->size) {
		*dat = (queues->dat)[0];
		return QUEUES_OK;}
	//	�����ݷ��ؿն���
	return QUEUES_EMPTY;}
//----------------------------------------------------------------------------------------------------
u8 SIZE8_rQueue(_rQueue* queues, u32* dat) {
	//	��ֹ�������ͷ
	if (queues == NULL)return QUEUES_NULL;
	//	������������
	*dat = queues->size;
	return QUEUES_OK;}
//----------------------------------------------------------------------------------------------------
u8 ROOM8_rQueue(_rQueue* queues, u32* dat) {
	//	��ֹ�������ͷ
	if (queues == NULL)return QUEUES_NULL;
	//	������������
	*dat = queues->room;
	return QUEUES_OK;}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	���򶥲��װ
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
//	32λ�İ�
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
