// Public.cpp: implementation of the CPublic class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFCTestOne.h"
#include "Public.h"

//ultra_light card beagin
//#include <vcl.h>
#include <stdio.h>
//#include <mem.h>
#include <string.h>
#include <time.h>
//ultra_light card end

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//HANDLE CPublic::comhald=0x0000078c;
HANDLE CPublic::comhald=0x00000000;
int CPublic::s_address=0;
int  CPublic::language_flag=0;// 1:Simplified chinese,  0:english 
unsigned char temp[120];
unsigned char * CPublic::buff=temp;//save return data 
char temp1[50];
char * CPublic::temp50=temp1;
char temp2[370];
char * CPublic::temp300=temp2;

char temp3[256];

char  CPublic::flag_from_buze=0; //标记 调用 打开/关闭事件来自于窗口(0)/设置波特率(1)
int   CPublic::cur_buze=0;
unsigned char ustr[36];//30
char str1[50];
char * str=str1;
char tille[5];
char * CPublic::xtsz_tille=&tille[0];
CPropertySheet * CPublic::pSheet=NULL;
CTabCtrl* CPublic::pTab=NULL; 
COLORREF CPublic::m_bkEdit_Color=RGB(255,255,255);//你想设置的颜色
CStatusBarCtrl *  CPublic::m_StatusBar= new CStatusBarCtrl; 

//////////////////////////////////////////////////////////////////////

//计算时间日期函数 且为全局函数


CString CPublic::time_use(void)
{	
	CString str;
	CTime t= CTime::GetCurrentTime();
	//long Year=t.GetYear();
	//CTime tt=CTime::CTime(Year,1,1,0,0,0,-1); 
	//CTimeSpan tt1=t-tt;
	str.Format(" %d-%d-%d  %02d:%02d:%02d (%d)", t.GetYear(), t.GetMonth(), t.GetDay(), t.GetHour(), t.GetMinute(), t.GetSecond(), t.GetDayOfWeek() - 1);
	return str;
}

//动态库api函数返回出错值转换

char * CPublic::api_error(int api_return)
{
	str="";

	if(CPublic::language_flag==0)
	{
		switch(api_return)
		{
		case 0x00:
			str= "successfully";
			break;
		case 0x01:	//命令错误 inBuffer[3]
			if(!(CPublic::buff[0]==0x80)) 
			{
				str="command failed\r\n";
			}
			break;
		case 0x02:
			str= "unmatched length of receiving data";
			break;
		case 0x03:
			str= "failure sending of COM";
			break;
		case 0x04:
			str= "nothing receiving from COM";
			break;
		case 0x05://
			str= "unmatched address of equipment";
			break;
		case 0x07://
			str= "failure checksum";
			break;
		case 0x08:
			str = "device not open";
			break;
		case 0x09:
			str = "transfer error";
			break;
		case 0x0A:
			str= "failure input parameters";
			break;
			//	default:
			//	str= "not define error ";
			//	break;
		}	
	}
	else
	{
		switch(api_return)
		{
		case 0x00:
			str= "命令执行成功";
			break;
		case 0x01:	
			if(!(CPublic::buff[0]==0x80)) 
			{
				str="命令操作失败";
			}
			break;
		case 0x02:
			str= "接收数据长度不匹配";
			break;
		case 0x03:
			str= "串口发送失败";
			break;
		case 0x04:
			str= "串口未接到任何数据";
			break;
		case 0x05:
			str= "表示设备地址不匹配";
			break;
		case 0x07:
			str= "校验和不正确";
			break;
		case 0x08:
			str = "设备没有打开";
			break;
		case 0x09:
			str = "传输错误";
			break;
		case 0x0A:
			str= "输入参数有误，请参见具体的函数说明";
			break;
			//	default:
			//	str= "未定义的操作错误";
			//	break;
		}
	}

	str+=0x00;

	return str;
}

char * CPublic::return_code_error(unsigned char * buff)//读写器状态返回码转换
{
	str="";

	if(CPublic::language_flag==0)
	{
		switch(*buff)
		{ 
			case 0x00:	
				str="successfully";
				break;
			case 0x01:	
				str="error ";
				break;
			case 0x80:	
				str="setting successfully";
				break;
			case 0x81:	
				str="Fail operating";
				break;
			case 0x82:	
				str="error,overtime";
				break;
			case 0x83:	
				str="error,no card";
				break;
			case 0x84:	
				str="error,data of card";
				break;
			case 0x85:	
				str="error,Incorrect input parameter or command format";
				break;
			case 0x87:	
				str="unknown failure";
				break;
			case 0x89:	
				str="error,Incorrect input parameter or command format";
				break;
			case 0x8A:	
				str="Initial block error";
				break;
			case 0x8B:	
				str="wrong card Serial Number in the anti-collision";
				break;
			case 0x8C:	
				str="password Authentication failed";
				break;
			case 0x8f:	
				str="error,Input command code not exist";
				break;
			case 0x90:	
				str="The card were unmatched for the command";
				break;
			case 0x91:	
				str="error in order format";
				break;
			case 0x92:	
				str="unmatched FLAG parameter and OPTION parameter ";
				break;
			case 0x93:	
				str="inexistent block";
				break;
			case 0x94:	
				str="locked,unchangeable operation";
				break;
			case 0x95:	
				str="locking operation unsuccessfully";
				break;
			case 0x96:	
				str="write operation unsuccessfully";
		//	  break;
		//default:
		//	str= "not define error";
		//	break;
		}
	}
	else
	{
		switch(*buff)
		{ 
		//case 0x00:	
		//	  str="表示命令执行成功";
		//	  break;
			case 0x01:	
				str="表示命令操作失败（具体说明参见函数）";
				break;
			case 0x80:	
				str="表示参数设置成功";
				break;
			case 0x81:	
				str="表示参数设置失败";
				break;
			case 0x82:	
				str="表示通讯超时";
				break;
			case 0x83:	
				str="表示卡不存在";
				break;
			case 0x84:	
				str="表示接收卡数据出错";
				break;
			case 0x85:	
				str="表示输入参数或者输入命令格式错误";
				break;
			case 0x87:	
				str="表示未知的错误";
				break;
			case 0x89:	
				str="表示输入参数或者输入命令格式错误";
				break;
			case 0x8A:	
				str="在块初始化中出现错误";
				break;
			case 0x8B:	
				str="防冲突过程中得到错误的序列号";
				break;
			case 0x8C:	
				str="密码认证没有通过";
				break;
			case 0x8f:	
				str="表示输入的指令代码不存在";
				break;
			case 0x90:	
				str="表示卡不支持这个命令";
				break;
			case 0x91:	
				str="表示命令格式有错误";
				break;
			case 0x92:	
				str="表示在命令的FLAG参数中，不支持OPTION 模式";
				break;
			case 0x93:	
				str="表示要操作的BLOCK不存在";
				break;
			case 0x94:	
				str="表示要操作的对象已经别锁定，不能进行修改";
				break;
			case 0x95:	
				str="表示锁定操作不成功";
				break;
			case 0x96:	
				str="表示写操作不成功";
				break;
		//default:
		//	str= "未定义的操作错误";
		//	break;
		}
	}
	
	str+=0x00;
	return str;
}

char * CPublic::strtohexstr(char * strr)//去掉字符中非16进制的字符
{
	char * strtemp=strr;//
	char * r_str= temp3;
	//strtemp=strr;
	//str=" ";
	int i,j;
	
	for(i=0,j=0;(!(*strtemp=='\0'))&&(i<(int)strlen(strr));)
	{
		if(((*(strtemp+i)>='a'&& *(strtemp+i)<='f'))
			|| ((*(strtemp+i)>='A'&& *(strtemp+i)<='F'))  
			|| isdigit(*(strtemp+i)) || *(strtemp+i)==0)
		{
			*(r_str+j)=*(strtemp+i);
			j++;
		}
		
		i++;
	}
	*(r_str+j)='\0';
	
	return r_str;//有问题，返回栈中的指针，如果这个指针指向的数据区，被别的数据填充，就会有错误
}
//寻卡时，转换16进制数据为字符型
void CPublic::uctoc(unsigned char *str,int n)
{
	int i;
	//CPublic::temp50[3]='\0';
	for(i=0; i<n; i++)
	{
		_itoa(*(str+i),CPublic::temp50,16);
		
		if(strlen(CPublic::temp50)==1)//十六进制数为0x03这类数时
		{
			CPublic::temp50[1]=CPublic::temp50[0];
			CPublic::temp50[0]=0x30;//再前面加上'0';
		}
	
		if(CPublic::temp50[0]>='a'&&CPublic::temp50[0]<='f')//转换成大写
		{	
			CPublic::temp50[0]-=32;
		}
		if(CPublic::temp50[1]>='a'&&CPublic::temp50[1]<='f')//temp50[0]
		{
			CPublic::temp50[1]-=32;
		}

		*(CPublic::temp300+i*2+0) = CPublic::temp50[0];
		*(CPublic::temp300+i*2+1) = CPublic::temp50[1];
	}
	*(CPublic::temp300+i*2)='\0';
}
//把字符串中的诸如FF的字符转换成数字FF，返回了全局的变量
unsigned char * CPublic::ctouc(char * str)
{
    char temp[3];
	
	int i;

	for(i=0;i<(int)strlen(str);i++)
	{
		temp[0]=*(str+2*i);
		temp[1]=*(str+2*i+1);//temp1 要以伪0结尾
		temp[2] = '\0';
		ustr[i]=(unsigned char)strtol(temp,NULL,16);//很有问题
	}
	
	ustr[i]='\0';
	return ustr;
}

CPublic::CPublic()
{
	
}

CPublic::~CPublic()
{
	
}

void CPublic::inti()
{
	int i;

	for(i=0;i<=370;i++)
	{
		*(CPublic::temp300+i)=' ';
	}

	for(i=0;i<=50;i++)
	{
		*(CPublic::temp50+i)=' ';
	}
}

void CPublic::init_StatusBar(void)
{
	
}
