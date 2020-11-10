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

char  CPublic::flag_from_buze=0; //��� ���� ��/�ر��¼������ڴ���(0)/���ò�����(1)
int   CPublic::cur_buze=0;
unsigned char ustr[36];//30
char str1[50];
char * str=str1;
char tille[5];
char * CPublic::xtsz_tille=&tille[0];
CPropertySheet * CPublic::pSheet=NULL;
CTabCtrl* CPublic::pTab=NULL; 
COLORREF CPublic::m_bkEdit_Color=RGB(255,255,255);//�������õ���ɫ
CStatusBarCtrl *  CPublic::m_StatusBar= new CStatusBarCtrl; 

//////////////////////////////////////////////////////////////////////

//����ʱ�����ں��� ��Ϊȫ�ֺ���


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

//��̬��api�������س���ֵת��

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
		case 0x01:	//������� inBuffer[3]
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
			str= "����ִ�гɹ�";
			break;
		case 0x01:	
			if(!(CPublic::buff[0]==0x80)) 
			{
				str="�������ʧ��";
			}
			break;
		case 0x02:
			str= "�������ݳ��Ȳ�ƥ��";
			break;
		case 0x03:
			str= "���ڷ���ʧ��";
			break;
		case 0x04:
			str= "����δ�ӵ��κ�����";
			break;
		case 0x05:
			str= "��ʾ�豸��ַ��ƥ��";
			break;
		case 0x07:
			str= "У��Ͳ���ȷ";
			break;
		case 0x08:
			str = "�豸û�д�";
			break;
		case 0x09:
			str = "�������";
			break;
		case 0x0A:
			str= "�������������μ�����ĺ���˵��";
			break;
			//	default:
			//	str= "δ����Ĳ�������";
			//	break;
		}
	}

	str+=0x00;

	return str;
}

char * CPublic::return_code_error(unsigned char * buff)//��д��״̬������ת��
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
		//	  str="��ʾ����ִ�гɹ�";
		//	  break;
			case 0x01:	
				str="��ʾ�������ʧ�ܣ�����˵���μ�������";
				break;
			case 0x80:	
				str="��ʾ�������óɹ�";
				break;
			case 0x81:	
				str="��ʾ��������ʧ��";
				break;
			case 0x82:	
				str="��ʾͨѶ��ʱ";
				break;
			case 0x83:	
				str="��ʾ��������";
				break;
			case 0x84:	
				str="��ʾ���տ����ݳ���";
				break;
			case 0x85:	
				str="��ʾ��������������������ʽ����";
				break;
			case 0x87:	
				str="��ʾδ֪�Ĵ���";
				break;
			case 0x89:	
				str="��ʾ��������������������ʽ����";
				break;
			case 0x8A:	
				str="�ڿ��ʼ���г��ִ���";
				break;
			case 0x8B:	
				str="����ͻ�����еõ���������к�";
				break;
			case 0x8C:	
				str="������֤û��ͨ��";
				break;
			case 0x8f:	
				str="��ʾ�����ָ����벻����";
				break;
			case 0x90:	
				str="��ʾ����֧���������";
				break;
			case 0x91:	
				str="��ʾ�����ʽ�д���";
				break;
			case 0x92:	
				str="��ʾ�������FLAG�����У���֧��OPTION ģʽ";
				break;
			case 0x93:	
				str="��ʾҪ������BLOCK������";
				break;
			case 0x94:	
				str="��ʾҪ�����Ķ����Ѿ������������ܽ����޸�";
				break;
			case 0x95:	
				str="��ʾ�����������ɹ�";
				break;
			case 0x96:	
				str="��ʾд�������ɹ�";
				break;
		//default:
		//	str= "δ����Ĳ�������";
		//	break;
		}
	}
	
	str+=0x00;
	return str;
}

char * CPublic::strtohexstr(char * strr)//ȥ���ַ��з�16���Ƶ��ַ�
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
	
	return r_str;//�����⣬����ջ�е�ָ�룬������ָ��ָ����������������������䣬�ͻ��д���
}
//Ѱ��ʱ��ת��16��������Ϊ�ַ���
void CPublic::uctoc(unsigned char *str,int n)
{
	int i;
	//CPublic::temp50[3]='\0';
	for(i=0; i<n; i++)
	{
		_itoa(*(str+i),CPublic::temp50,16);
		
		if(strlen(CPublic::temp50)==1)//ʮ��������Ϊ0x03������ʱ
		{
			CPublic::temp50[1]=CPublic::temp50[0];
			CPublic::temp50[0]=0x30;//��ǰ�����'0';
		}
	
		if(CPublic::temp50[0]>='a'&&CPublic::temp50[0]<='f')//ת���ɴ�д
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
//���ַ����е�����FF���ַ�ת��������FF��������ȫ�ֵı���
unsigned char * CPublic::ctouc(char * str)
{
    char temp[3];
	
	int i;

	for(i=0;i<(int)strlen(str);i++)
	{
		temp[0]=*(str+2*i);
		temp[1]=*(str+2*i+1);//temp1 Ҫ��α0��β
		temp[2] = '\0';
		ustr[i]=(unsigned char)strtol(temp,NULL,16);//��������
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
