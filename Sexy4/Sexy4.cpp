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
#include "membermanage.h"

void print();
void login(ItemManage S);
void mainmenu();
void submenu();

int _tmain(int argc, _TCHAR* argv[])
{
	ItemManage s;
	MemberManage m;
	m.Add("USER003","User 003",true,600);
	m.Add("USER002","User 002",false,200);
	m.Add("USER001","User 001",true,0);
	/*login(s);*/
	system("cls");
	mainmenu();
	s.Add("ITEM000002","���",2.00,100,1,false,0.8);
	s.Add("ITEM000001","ѩ��",3.00,2000,0.8,false,0.5);
	s.Add("ITEM000000","�ɿڿ���",3.00,5000,1,true,1);
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
	string select;
	string MNo;
	bool flag = false;
	system("cls");
	cout<<"�����Ƿ�Ϊ��Ա(Y/N):";
	cin>>select;
	while(1){
		if( select == "Y" || select == "y" ){
			flag = true; 
			cout<<"�������Ա��ţ�";
			cin>>MNo;
			while(1){
				if(m.search(MNo) == true) break;
				else{
					cout<<"������ı���������������룺";
					cin >> MNo;
					if(m.search(MNo) == true) break;
				}
			}
			b.Sum(m.getIsVip(MNo));
			break;
		}
		else if( select == "N" || select == "n" ) {
			flag == false;
			b.Sum(flag);
			break;
		}
		else cout<<"���������Ϣ�������������룺";
		cin >> select;
	}
	system("cls");
	cout<<"***�̵깺���嵥***"<<endl;
	if(flag == true){
		m.sumPoint(MNo,b.getValue());
		cout<<"��Ա��ţ�"<<MNo<<"	��Ա���֣�"<<m.getPoint(MNo)<<"��"<<endl;
		cout<<"----------------------"<<endl;
	}
	b.outputGoods();
	cout<<"----------------------"<<"\n"<<"�ܼƣ�";
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
//	��ӡʱ��
void time(){
	time_t t;
	time ( &t );
	cout<<"��ӡʱ��: "<<ctime(&t);
	cout<<"----------------------"<<endl;
}