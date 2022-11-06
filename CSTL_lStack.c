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
	����:CSTL_lStack
	ʱ��:20221102-1904
	����Ա:��Դ��
	˵��:ʵ��ջ
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	ͷ�ļ�
#include "CSTL_lStack.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	8λ��������Ϊ�����ĺ�������
//	
#ifdef _USE_CSTL_STACK_LIST8
//----------------------------------------------------------------------------------------------------
_8lStack* CREAT8_lStack(void) {
	_8lStack* stacks = malloc(sizeof(_8lStack));
	if (stacks == NULL)return NULL;
	stacks->size = 0;
	stacks->top = 0;
	return stacks;}
//----------------------------------------------------------------------------------------------------
u8 PUSH8_lStack(_8lStack* stacks,u8 dat) {
	if (stacks == NULL)return STACKS_NULL;
	_8lStackNode* stacksNode = malloc(sizeof(_8lStackNode));
	if (stacksNode == NULL)return STACKS_MALL_ERROR;
	
	//	���Ա
	if (stacks->size) {
		stacksNode->dat = dat;
		stacksNode->up = stacks->top;
		stacks->top = stacksNode;
		stacks->size++;
		return STACKS_OK;}
	//	�ճ�Ա
	stacksNode->up = NULL;
	stacksNode->dat = dat;
	stacks->top = stacksNode;
	stacks->size = 1;
	return STACKS_OK;}
//----------------------------------------------------------------------------------------------------
u8 POP8_lStack(_8lStack* stacks) {
	if (stacks == NULL)return STACKS_NULL;
	_8lStackNode* stacksNode = stacks->top;
	//	�ж�ջ������1
	if (stacks->size > 1) {
		stacks->top = stacks->top->up;
		stacks->size--;
		free(stacksNode);
		return STACKS_OK;}
	//	�ж�ջ������1
	else if (stacks->size == 1) {
		stacks->top = NULL;
		stacks->size = 0;
		free(stacksNode);
		return STACKS_OK;}
	//	�ճ�Ա
	return STACKS_EMPTY;}
//----------------------------------------------------------------------------------------------------
u8 TOP8_lStack(_8lStack* stacks, u8* dat) {
	if (stacks == NULL)return STACKS_NULL;
	if (stacks->size) {
		*dat = stacks->top->dat;}
	return STACKS_OK;}
//----------------------------------------------------------------------------------------------------
u32 SIZE8_lStack(_8lStack* stacks, u32* dat) {
	if (stacks == NULL)return STACKS_NULL;
	return stacks->size;}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	8λ��������Ϊ�����ĳ����װ
//	
u8 POPTOP8_lStack(_8lStack* stacks) {
	u8 dat = 0;
	TOP8_lStack(stacks, &dat);
	POP8_lStack(stacks);
	return dat;}
u32	SIZEMEM8_lStack(_8lStack* stacks) {
	return stacks->size;}
//----------------------------------------------------------------------------------------------------
#endif // _USE_CSTL_STACK_LIST8

//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	32λ��������Ϊ�����ĺ�������
//	
#ifdef _USE_CSTL_STACK_LIST32
//----------------------------------------------------------------------------------------------------
_32lStack* CREAT32_lStack(void) {
	_32lStack* stacks = malloc(sizeof(_32lStack));
	if (stacks == NULL)return NULL;
	stacks->size = 0;
	stacks->top = 0;
	return stacks;
}
//----------------------------------------------------------------------------------------------------
u8 PUSH32_lStack(_32lStack* stacks, u32 dat) {
	if (stacks == NULL)return STACKS_NULL;
	_32lStackNode* stacksNode = malloc(sizeof(_32lStackNode));
	if (stacksNode == NULL)return STACKS_MALL_ERROR;

	//	���Ա
	if (stacks->size) {
		stacksNode->dat = dat;
		stacksNode->up = stacks->top;
		stacks->top = stacksNode;
		stacks->size++;
		return STACKS_OK;
	}
	//	�ճ�Ա
	stacksNode->up = NULL;
	stacksNode->dat = dat;
	stacks->top = stacksNode;
	stacks->size = 1;
	return STACKS_OK;
}
//----------------------------------------------------------------------------------------------------
u8 POP32_lStack(_32lStack* stacks) {
	if (stacks == NULL)return STACKS_NULL;
	_32lStackNode* stacksNode = stacks->top;
	//	�ж�ջ������1
	if (stacks->size > 1) {
		stacks->top = stacks->top->up;
		stacks->size--;
		free(stacksNode);
		return STACKS_OK;}
	//	�ж�ջ������1
	else if (stacks->size == 1) {
		stacks->top = NULL;
		stacks->size = 0;
		free(stacksNode);
		return STACKS_OK;}
	//	�ճ�Ա
	return STACKS_EMPTY;
}
//----------------------------------------------------------------------------------------------------
u32 TOP32_lStack(_32lStack* stacks, u32* dat) {
	if (stacks == NULL)return STACKS_NULL;
	if (stacks->size) {
		*dat = stacks->top->dat;
	}
	return STACKS_OK;
}
//----------------------------------------------------------------------------------------------------
u32 SIZE32_lStack(_32lStack* stacks, u32* dat) {
	if (stacks == NULL)return STACKS_NULL;
	return stacks->size;}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	32λ��������Ϊ�����ĳ����װ
//	
u32 POPTOP32_lStack(_32lStack* stacks) {
	u32 dat = 0;
	TOP32_lStack(stacks, &dat);
	POP32_lStack(stacks);
	return dat;}
u32	SIZEMEM32_lStack(_32lStack* stacks) {
	return stacks->size;}
//----------------------------------------------------------------------------------------------------
void(*POPTOPFUN_lStack(_8lStack* stacks))(void) {
	return POPTOP32_lStack(stacks);}
//----------------------------------------------------------------------------------------------------
#endif // _USE_CSTL_STACK_LIST32
//////////////////////////////////////////////////////////////////////////////////////////////////////
