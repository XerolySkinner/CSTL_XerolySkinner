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
	����:CSTL_rStack
	ʱ��:20221102-1904
	����Ա:��Դ��
	˵��:ʵ��ջ
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	ͷ�ļ�
#include "CSTL_rStack.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	�������
_rStack* CREAT8_rStack(void) {
	//	��ֹ����ʧ��
	_rStack* stacks = malloc(sizeof(_rStack));
	if (stacks == NULL)return NULL;
	//	��ջ��ֵ
	stacks->room = 0;
	stacks->size = 0;
	stacks->dat = NULL;
	//	��������Ŀռ�ͷ
	return stacks;}
//----------------------------------------------------------------------------------------------------
u8 DEL8_rStack(_rStack* stacks) {
	//	��ֹ�������ͷ
	if (stacks == NULL)return STACKS_NULL;
	//	�ݻ�ջ����
	if (stacks->size)
		free(stacks->dat);
	//	�ݻ�ջ
	free(stacks);
	//	��������Ŀռ�ͷ
	return STACKS_OK;}
//----------------------------------------------------------------------------------------------------
u8 PUSH8_rStack(_rStack* stacks, u8 dat) {
	//	��ֹ�������ͷ
	if (stacks == NULL)return STACKS_NULL;
	//	�������ǰ������ͷ
	u8* temp_stacks = stacks->dat;
	//	������ռ�С�����пռ�
	if (stacks->size >= stacks->room) {
		//	�����³���
		stacks->dat = realloc(stacks->dat, ++stacks->size);
		//	����ʧ��,�ƺ��ҷ��ش���
		if (stacks->dat == NULL) {
			--stacks->size;					//	�ָ�ԭ����
			stacks->dat = temp_stacks;		//	�ָ�����
			return STACKS_REAL_ERROR;}		//	���ش���
		stacks->room = stacks->size;
		//	����ɹ�,ѹ������
		(stacks->dat)[stacks->size - 1] = dat;
		//	������ȷָ��
		return STACKS_OK;}
	//	�ռ�ʣ��,ѹ������
	(stacks->dat)[(++stacks->size) - 1] = dat;
	//	������ȷָ��
	return STACKS_OK;}
//----------------------------------------------------------------------------------------------------
u8 POP8_rStack(_rStack* stacks) {
	//	��ֹ�������ͷ
	if (stacks == NULL)return STACKS_NULL;
	//	������ջ�д���1,���̳�Ա�ռ�
	if (stacks->size > 1) {
		--stacks->size;						//	���·����Ա�ռ�
		return STACKS_OK;}
	//	������ջ�е���1,��ָ��ͷ
	else if (stacks->size == 1) {
		stacks->size = 0;					//	���·����Ա�ռ�
		return STACKS_OK;}
	//	������ջΪ��,���ؿ�ջ�����
	else
		return STACKS_EMPTY;}
//----------------------------------------------------------------------------------------------------
u8 CLS8_rStack(_rStack* stacks) {
	//	��ֹ�������ͷ
	if (stacks == NULL)return STACKS_NULL;
	//	�������ǰ������ͷ
	u8* temp_stacks = stacks->dat;
	//	����г�Ա,���·���ռ�
	if (stacks->size) {
		//	���·���ռ�
		stacks->dat = realloc(stacks->dat, stacks->size);
		//	����ʧ��,�ƺ󲢷��ش���
		if (stacks->dat == NULL) {
			--stacks->size;						//	�ָ�ԭ����
			stacks->dat = temp_stacks;			//	�ָ�����
			return STACKS_REAL_ERROR;}			//	���ش���
	}
	//	�޳�Աջ���·����Ա
	else {
		free(stacks->dat);						//	�ͷ�ȫ���ռ�
		stacks->size = 0;}						//	��ָ���ײ�
//	�����ݷ��ؿ�ջ
	stacks->room = stacks->size;				//	�µĿռ��С
	return STACKS_OK;}
//----------------------------------------------------------------------------------------------------
u8 TOP8_rStack(_rStack* stacks, u8* dat) {
	//	��ֹ�������ͷ
	if (stacks == NULL)return STACKS_NULL;
	//	��������,���ض�������
	if (stacks->size) {
		*dat = (stacks->dat)[stacks->size-1];
		return STACKS_OK;}
	//	�����ݷ��ؿ�ջ
	return STACKS_EMPTY;}
//----------------------------------------------------------------------------------------------------
u8 SIZE8_rStack(_rStack* stacks, u32* dat) {
	//	��ֹ�������ͷ
	if (stacks == NULL)return STACKS_NULL;
	//	������������
	*dat = stacks->size;
	return STACKS_OK;}
//----------------------------------------------------------------------------------------------------
u8 ROOM8_rStack(_rStack* stacks, u32* dat) {
	//	��ֹ�������ͷ
	if (stacks == NULL)return STACKS_NULL;
	//	������������
	*dat = stacks->room;
	return STACKS_OK;}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	���򶥲��װ
//	
u8 POPTOP8_rStack(_rStack* stacks) {
	u8 dat = 0;
	TOP8_rStack(stacks, &dat);
	POP8_rStack(stacks);
	return dat;}
//----------------------------------------------------------------------------------------------------
u32	SIZEMEM8_rStack(_rStack* stacks) {
	return stacks->size;}
//----------------------------------------------------------------------------------------------------
//	32λ�İ�
_rStack* CREAT32_rStack(void) {
	_rStack* stacks = CREAT8_rStack();
	return stacks;}
//----------------------------------------------------------------------------------------------------
u8	PUSH32_rStack(_rStack* stacks, u32 dat) {
	PUSH8_rStack(stacks, ((u8*)(&dat))[3]);
	PUSH8_rStack(stacks, ((u8*)(&dat))[2]);
	PUSH8_rStack(stacks, ((u8*)(&dat))[1]);
	PUSH8_rStack(stacks, ((u8*)(&dat))[0]);
	return STACKS_OK;}
//----------------------------------------------------------------------------------------------------
u32 POPTOP32_rStack(_rStack* stacks) {
	u8 dat[4] = { 0,0,0,0 };
	TOP8_rStack(stacks, dat + 0);
	POP8_rStack(stacks);
	TOP8_rStack(stacks, dat + 1);
	POP8_rStack(stacks);
	TOP8_rStack(stacks, dat + 2);
	POP8_rStack(stacks);
	TOP8_rStack(stacks, dat + 3);
	POP8_rStack(stacks);
	return *((u32*)(dat));}
//----------------------------------------------------------------------------------------------------
void(*POPTOPFUN_rStack(_rStack* stacks))(void) {
	return POPTOP32_rStack(stacks);}
//////////////////////////////////////////////////////////////////////////////////////////////////////
