// Sexy4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
#include "exception.h"
#include "buy.h"
#include "membermanage.h"

void print();
void login(ItemManage S);
void mainmenu();
void submenu();
//void savefile( );						//	打印清单

int _tmain(int argc, _TCHAR* argv[])
{
	ItemManage s;
	MemberManage m;
	m.readfile(m);
	login(s);
	system("cls");
	mainmenu();
	s.readfile(s);
	print();
	s.output();
	submenu();
	Buy b;
	string chose;
	string num;
	while(chose != "Y" && chose != "y"){
		cout<<"请输入您要购买的商品编号：";
		cin>>num;
		if(s.search(num) == false) cout<<"您输入的商品不存在！"<<endl;
		else{
			int cou;
			cout<<"请输入您要购买的数量：";
			cin>>cou;
			while(1){
					if(cou > 0){
						if(cou > s.getCount(num)) cout<<"超出剩余数量！"<<endl;
						if(cou <= s.getCount(num) && b.search( num, cou ) == 0){
							b.AddGoods( num, s.getName(num),s.getPrice(num),s.getDiscount(num),cou,s.getPromotion(num),s.getVipdiscount(num));
							break;
						}
					else cout<<"您输入的数量有误，请重新输入：";
					cin >> cou;
				}
			}
		}
		cout<<"是否进行结算(Y结算)：";
		cin>>chose;
	}
	string select;
	string MNo;
	bool flag = false;
	system("cls");
	cout<<"请问是否为会员(Y/N):";
	cin>>select;
	while(1){
		if( select == "Y" || select == "y" ){
			flag = true; 
			cout<<"请输入会员编号：";
			cin>>MNo;
			while(1){
				if(m.search(MNo) == true) break;
				else{
					cout<<"您输入的编号有误请重新输入：";
					cin >> MNo;
					if(m.search(MNo) == true) break;
				}
			}
			b.Sum(m.getIsVip(MNo),s);
			break;
		}
		else if( select == "N" || select == "n" ) {
			flag == false;
			b.Sum(flag,s);
			break;
		}
		else cout<<"您输入的信息有误，请重新输入：";
		cin >> select;
	}
	system("cls");
	cout<<"***商店购物清单***"<<endl;
	if(flag == true){
		m.sumPoint(MNo,b.getValue());
		cout<<"会员编号："<<MNo<<"	会员积分："<<m.getPoint(MNo)<<"分"<<endl;
		cout<<"----------------------"<<endl;
	}
	b.outputGoods();
	cout<<"----------------------"<<"\n"<<"总计：";
	cout<<b.getValue()<<"(元)"<<endl;
	if(b.getDis()!=0 ) cout<<"节省："<<b.getDis()<<"(元)"<<endl;
	cout<<"**********************"<<endl;
	system("pause");
	s.savefile(s);
	return 0;
}
//	登陆
void login(ItemManage S){
	int code,incode;
	code = S.getCode();
	cout<<"————超市收银系统————"<<endl;
	cout<<"请输入密码：";
	cin>>incode;
	while (incode!=code){
		cout<<"密码错误！！！"<<endl;
		cout<<"请输入密码：";
		cin>>incode;
	}
}
//	打印商品的抬头
void print(){
	string title[7];
	title[0]="商品编号"; 
	title[1]="商品名"; 
	title[2]="单价"; 
	title[3]="数量"; 
	title[4]="折扣";
	title[5]="是否促销";
	title[6]="Vip折扣";
	for(int i=0;i<7;i++){
		cout.width(12);
		cout<<left<<title[i];
	}
	cout<<endl;
}
//	主菜单
void mainmenu(){
	cout<<"*******************************************************************************"<<endl;
	cout<<"\n";
	cout<<"********************************欢迎来到SEXY4商店******************************"<<endl;
	cout<<"--------------------------------本商店有如下商品-------------------------------"<<endl;
}
//	副菜单
void submenu(){
	cout<<"*******************************************************************************"<<endl;
	cout<<"*  *祝您购物愉快！                                                            *"<<endl;
	cout<<"*******************************************************************************"<<endl;
}
//	打印时间
void time(){
	time_t t;
	time ( &t );
	cout<<"打印时间: "<<ctime(&t);
	cout<<"----------------------"<<endl;
}