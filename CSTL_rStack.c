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
//	
_rStack* CREAT8_rStack(void){
	_rStack* stacks = malloc(sizeof(_rStack));
	if (stacks == NULL)return NULL;
	stacks->size = 0;
	stacks->dat = NULL;
	return stacks;}
//----------------------------------------------------------------------------------------------------
u8	PUSH8_rStack(_rStack* stacks, u8 dat) {
	if (stacks == NULL)return STACKS_NULL;
	u8* temp_stacks = stacks->dat;
	stacks->dat = realloc(stacks->dat, ++stacks->size);
	if (stacks->dat == NULL) {
		stacks->dat = temp_stacks;
		return STACKS_REAL_ERROR;}
	(stacks->dat)[stacks->size - 1] = dat;
	return STACKS_OK;}
//----------------------------------------------------------------------------------------------------
u8	POP8_rStack(_rStack* stacks) {
	if (stacks == NULL)return STACKS_NULL;
	u8* temp_stacks = stacks->dat;
	if (stacks->size > 1) {
		stacks->dat = realloc(stacks->dat, --stacks->size);
		if (stacks->dat == NULL) {
			stacks->dat = temp_stacks;
			return STACKS_REAL_ERROR;}
		return STACKS_OK;}
	else if (stacks->size == 1) {
		stacks->size = 0;
		free(stacks->dat);
		stacks->dat = NULL;
		return STACKS_OK;}
	else
		return STACKS_EMPTY;}
//----------------------------------------------------------------------------------------------------
u8	TOP8_rStack(_rStack* stacks,u8 *dat){
	if (stacks == NULL)return STACKS_NULL;
	if (stacks->size) {
		*dat = (stacks->dat)[stacks->size - 1];
		return STACKS_OK;}
	return STACKS_EMPTY;}
//----------------------------------------------------------------------------------------------------
u8	SIZE8_rStack(_rStack* stacks,u32 *dat) {
	if (stacks == NULL)return STACKS_NULL;
	*dat = stacks->size;
	return STACKS_OK;}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	���򶥲��װ
//	
u8 POPTOP8_rStack(_rStack* stacks) {
	u8 dat=0;
	TOP8_rStack(stacks, &dat);
	POP8_rStack(stacks);
	return dat;}
//----------------------------------------------------------------------------------------------------
u32	SIZEMEM8_rStack(_rStack* stacks) {
	return stacks->size;}
//----------------------------------------------------------------------------------------------------
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
	u8 dat[4] = {0,0,0,0};
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
void(*POPTOPFUN_rStack(_rStack* stacks))(void)  {
	return POPTOP32_rStack(stacks);}
//////////////////////////////////////////////////////////////////////////////////////////////////////
