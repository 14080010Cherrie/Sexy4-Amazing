// Sexy4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <ctime>
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
	s.Add("ITEM000000","�ɿڿ���",3.00,5000,1,true,1);
	s.Add("ITEM000001","ѩ��",3.00,2000,0.8,false,0.5);
	s.Add("ITEM000002","���",2.00,100,1,false,0.8);
	print();
	s.output();
	submenu();
	Buy b;
	string chose;
	string num;
	while(chose != "Y" && chose != "y"){
		cout<<"��������Ҫ�������Ʒ��ţ�";
		cin>>num;
		if(s.search(num) == false) cout<<"���������Ʒ�����ڣ�"<<endl;
		else{
			int cou;
			cout<<"��������Ҫ�����������";
			cin>>cou;
			if(cou > s.getCount(num)) cout<<"����ʣ��������"<<endl;
			if(cou <= s.getCount(num) && b.search( num, cou ) == 1) s.getCount(num) = s.getCount(num) - cou;
			if(cou <= s.getCount(num) && b.search( num, cou ) == 0){
				b.AddGoods( num, s.getName(num),s.getPrice(num),s.getDiscount(num),cou,s.getPromotion(num),s.getVipdiscount(num));
				s.getCount(num) = s.getCount(num) - cou;
			}
		}
		cout<<"�Ƿ���н���(Y����)��";
		cin>>chose;
	}
	b.Sum();
	system("cls");
	listpre();
	b.outputGoods();
	listsuf();
	cout<<b.getValue()<<"(Ԫ)"<<endl;
	if(b.getDis()!=0 ) cout<<"��ʡ��"<<b.getDis()<<"(Ԫ)"<<endl;
	cout<<"**********************"<<endl;
	system("pause");
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
	string title[7];
	title[0]="��Ʒ���"; 
	title[1]="��Ʒ��"; 
	title[2]="����"; 
	title[3]="����"; 
	title[4]="�ۿ�";
	title[5]="�Ƿ����";
	title[6]="Vip�ۿ�";
	for(int i=0;i<7;i++){
		cout.width(12);
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
	cout<<"*  *ף��������죡                                                            *"<<endl;
	cout<<"*******************************************************************************"<<endl;
}
//	�����嵥
void listpre(){
	cout<<"***�̵깺���嵥***"<<endl;
	time_t t;
	time ( &t );
	cout<<"��ӡʱ��: "<<ctime(&t);
	cout<<"----------------------"<<endl;
}
void listsuf(){
	cout<<"----------------------"<<"\n"<<"�ܼƣ�";
}