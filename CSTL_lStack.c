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
	名字:CSTL_lStack
	时间:20221102-1904
	程序员:梁源康
	说明:实现栈
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	头文件
#include "CSTL_lStack.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	8位数据链表为基本的函数声明
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
	
	//	多成员
	if (stacks->size) {
		stacksNode->dat = dat;
		stacksNode->up = stacks->top;
		stacks->top = stacksNode;
		stacks->size++;
		return STACKS_OK;}
	//	空成员
	stacksNode->up = NULL;
	stacksNode->dat = dat;
	stacks->top = stacksNode;
	stacks->size = 1;
	return STACKS_OK;}
//----------------------------------------------------------------------------------------------------
u8 POP8_lStack(_8lStack* stacks) {
	if (stacks == NULL)return STACKS_NULL;
	_8lStackNode* stacksNode = stacks->top;
	//	判断栈长大于1
	if (stacks->size > 1) {
		stacks->top = stacks->top->up;
		stacks->size--;
		free(stacksNode);
		return STACKS_OK;}
	//	判断栈长等于1
	else if (stacks->size == 1) {
		stacks->top = NULL;
		stacks->size = 0;
		free(stacksNode);
		return STACKS_OK;}
	//	空成员
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
//	8位数据链表为基本的程序封装
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
//	32位数据链表为基本的函数声明
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

	//	多成员
	if (stacks->size) {
		stacksNode->dat = dat;
		stacksNode->up = stacks->top;
		stacks->top = stacksNode;
		stacks->size++;
		return STACKS_OK;
	}
	//	空成员
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
	//	判断栈长大于1
	if (stacks->size > 1) {
		stacks->top = stacks->top->up;
		stacks->size--;
		free(stacksNode);
		return STACKS_OK;}
	//	判断栈长等于1
	else if (stacks->size == 1) {
		stacks->top = NULL;
		stacks->size = 0;
		free(stacksNode);
		return STACKS_OK;}
	//	空成员
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
//	32位数据链表为基本的程序封装
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
