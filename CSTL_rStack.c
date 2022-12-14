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

//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	头文件
#include "CSTL_rStack.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	程序基底
_rStack* CREAT8_rStack(void) {
	//	防止分配失败
	_rStack* stacks = malloc(sizeof(_rStack));
	if (stacks == NULL)return NULL;
	//	新栈赋值
	stacks->room = 0;
	stacks->size = 0;
	stacks->dat = NULL;
	//	传出分配的空间头
	return stacks;}
//----------------------------------------------------------------------------------------------------
u8 DEL8_rStack(_rStack* stacks) {
	//	防止传入错误头
	if (stacks == NULL)return STACKS_NULL;
	//	摧毁栈数据
	if (stacks->size)
		free(stacks->dat);
	//	摧毁栈
	free(stacks);
	//	传出分配的空间头
	return STACKS_OK;}
//----------------------------------------------------------------------------------------------------
u8 PUSH8_rStack(_rStack* stacks, u8 dat) {
	//	防止传入错误头
	if (stacks == NULL)return STACKS_NULL;
	//	保存分配前的数据头
	u8* temp_stacks = stacks->dat;
	//	若所需空间小于现有空间
	if (stacks->size >= stacks->room) {
		//	分配新长度
		stacks->dat = realloc(stacks->dat, ++stacks->size);
		//	分配失败,善后并且返回错误
		if (stacks->dat == NULL) {
			--stacks->size;					//	恢复原长度
			stacks->dat = temp_stacks;		//	恢复数据
			return STACKS_REAL_ERROR;}		//	返回错误
		stacks->room = stacks->size;
		//	分配成功,压入数据
		(stacks->dat)[stacks->size - 1] = dat;
		//	返回正确指数
		return STACKS_OK;}
	//	空间剩余,压入数据
	(stacks->dat)[(++stacks->size) - 1] = dat;
	//	返回正确指数
	return STACKS_OK;}
//----------------------------------------------------------------------------------------------------
u8 POP8_rStack(_rStack* stacks) {
	//	防止传入错误头
	if (stacks == NULL)return STACKS_NULL;
	//	若数据栈中大于1,缩短成员空间
	if (stacks->size > 1) {
		--stacks->size;						//	重新分配成员空间
		return STACKS_OK;}
	//	若数据栈中等于1,重指定头
	else if (stacks->size == 1) {
		stacks->size = 0;					//	重新分配成员空间
		return STACKS_OK;}
	//	若数据栈为空,返回空栈错误号
	else
		return STACKS_EMPTY;}
//----------------------------------------------------------------------------------------------------
u8 CLS8_rStack(_rStack* stacks) {
	//	防止传入错误头
	if (stacks == NULL)return STACKS_NULL;
	//	保存分配前的数据头
	u8* temp_stacks = stacks->dat;
	//	如果有成员,重新分配空间
	if (stacks->size) {
		//	重新分配空间
		stacks->dat = realloc(stacks->dat, stacks->size);
		//	分配失败,善后并返回错误
		if (stacks->dat == NULL) {
			--stacks->size;						//	恢复原长度
			stacks->dat = temp_stacks;			//	恢复数据
			return STACKS_REAL_ERROR;}			//	返回错误
	}
	//	无成员栈重新分配成员
	else {
		free(stacks->dat);						//	释放全部空间
		stacks->size = 0;}						//	重指定首部
//	无数据返回空栈
	stacks->room = stacks->size;				//	新的空间大小
	return STACKS_OK;}
//----------------------------------------------------------------------------------------------------
u8 TOP8_rStack(_rStack* stacks, u8* dat) {
	//	防止传入错误头
	if (stacks == NULL)return STACKS_NULL;
	//	若有数据,传回顶部数据
	if (stacks->size) {
		*dat = (stacks->dat)[stacks->size-1];
		return STACKS_OK;}
	//	无数据返回空栈
	return STACKS_EMPTY;}
//----------------------------------------------------------------------------------------------------
u8 SIZE8_rStack(_rStack* stacks, u32* dat) {
	//	防止传入错误头
	if (stacks == NULL)return STACKS_NULL;
	//	传出长度数据
	*dat = stacks->size;
	return STACKS_OK;}
//----------------------------------------------------------------------------------------------------
u8 ROOM8_rStack(_rStack* stacks, u32* dat) {
	//	防止传入错误头
	if (stacks == NULL)return STACKS_NULL;
	//	传出长度数据
	*dat = stacks->room;
	return STACKS_OK;}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------------
//	程序顶层封装
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
//	32位改版
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
