#include "pch.h"
#include "Transer.h"
#include <vcruntime_string.h>

unsigned char type;
unsigned char len;
unsigned char ch;
//函数功能:
//	得到CRC16值
//函数输入:
//	u8  *buf
//		要计算的数据
//	u16 len
//   数据长度
//函数输出:
//  CRC16值
//注:
//	没有检测指针是否为空的情况.
//因为用户在调用这个函数之前就判断了
unsigned short ChecksumCRC16(unsigned char* buf, unsigned short len)
{
	unsigned short counter = 0;
	unsigned short crc = 0;
	for (counter = 0; counter < len; counter++)
	{
		crc = (crc << 8) ^ CRC16Tab[((crc >> 8) ^ *(char*)buf++) & 0x00FF];
	}
	return crc;
}

//组包
void PcakMessage(unsigned char buff[],
	unsigned char result[])
{
	unsigned short CRC;

	memset(result, 0, sizeof(result));

	result[0] = 0xAA;
	result[1] = type;
	result[2] = len;
	result[3] = ch;
	result[4] = buff[0];
	CRC = ChecksumCRC16(&result[1], 4);
	result[5] = CRC >> 8;
	result[6] = CRC << 8 >> 8;
	result[7] = 0xBB;
}
//解包  0成功  1失败
int UnPcakMessage(unsigned char buff[], unsigned char result[])
{
	unsigned short CRC;
	unsigned char flag = 0;
	if (buff[0] != 0xAA)	return 1;

	type = buff[1];
	len = buff[2];
	ch = buff[3];

	if (buff[1] == 0x04)//设置和查询的返回指令
	{
		result[0] = buff[4];
		CRC = ChecksumCRC16(&buff[1], 4);
		if ((buff[5] != (CRC >> 8)) || (buff[6] != (CRC << 8 >> 8)))
			return 1;
	}
	if (buff[1] == 0x01)//读卡返回指令
	{
		
		CRC = ChecksumCRC16(&buff[1], 7);
		if ((buff[8] != (CRC >> 8)) || (buff[9] != (CRC << 8 >> 8)))
			return 1;
		memcpy(result,&buff[4],4);
	}
	
	return 0;
}