// Sexy4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
#include "exception.h"
#include "itemmanage.h"
#include "buy.h"

void print();
void login(ItemManage S);
void mainmenu();
void submenu();
void listpre();
void listsuf();

int _tmain(int argc, _TCHAR* argv[])
{
	ItemManage s;
	login(s);
	system("cls");
	mainmenu();
	s.Add("ITEM000000","�ɿڿ���",3.00,5000,1);
	s.Add("ITEM000001","ѩ��",3.00,2000,0.8);
	s.Add("ITEM000002","���",2.00,100,1);
	print();
	s.output();
	submenu();
	Buy b;
	char chose='\0';
	string num;
	while(chose != 'N'&& chose != 'n'){
		cout<<"��������Ҫ�������Ʒ��ţ�";
		cin>>num;
		if(s.search(num) == false) cout<<"���������Ʒ�����ڣ�"<<endl;
		else{
			int cou;
			cout<<"��������Ҫ�����������";
			cin>>cou;
			if(b.search( num, cou) == 11) b.AddGoods( num, s.getName(num),s.getPrice(num),s.getDiscount(num),cou);
			else if(b.search( num, cou) == 12) cout<<"��������ʣ��������"<<endl;
		}
		cout<<"�Ƿ��������(Y������N����)��";
		cin>>chose;
	}
	b.Sum();
	system("cls");
	listpre();
	b.outputGoods();
	listsuf();
	cout<<b.getValue()<<"(Ԫ)"<<endl;
	if(b.getDis()!=0) cout<<"��ʡ��"<<b.getDis()<<"(Ԫ)"<<endl;
	cout<<"**********************"<<endl;
	return 0;
}
//	��½
void login(ItemManage S){
	int code,incode;
	code = S.getCode();
	cout<<"����������������ϵͳ��������"<<endl;
	cout<<"���������룺";
	cin>>incode;
	while (incode!=code){
		cout<<"������󣡣���"<<endl;
		cout<<"���������룺";
		cin>>incode;
	}
}
//	��ӡ��Ʒ��̧ͷ
void print(){
	string title[4];
	title[0]="��Ʒ���"; 
	title[1]="��Ʒ��"; 
	title[2]="����"; 
	title[3]="����"; 
	for(int i=0;i<4;i++){
		cout.width(20);
		cout<<left<<title[i];
	}
	cout<<endl;
}
//	���˵�
void mainmenu(){
	cout<<"*******************************************************************************"<<endl;
	cout<<"\n";
	cout<<"********************************��ӭ����SEXY4�̵�******************************"<<endl;
	cout<<"--------------------------------���̵���������Ʒ-------------------------------"<<endl;
}
//	���˵�
void submenu(){
	cout<<"*******************************************************************************"<<endl;
	cout<<"*                                                                             *"<<endl;
	//cout<<"*  *����������Ҫ�����Ʒ��ţ�����-1�˳�ϵͳ                                  *"<<endl;
	cout<<"*  *ף��������죡                                                            *"<<endl;
	cout<<"*                                                                             *"<<endl;
	cout<<"*******************************************************************************"<<endl;
}
//	�����嵥
void listpre(){
	cout<<"***�̵깺���嵥***"<<endl;
}
void listsuf(){
	cout<<"----------------------"<<"\n"<<"�ܼƣ�";
}