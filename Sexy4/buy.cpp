#include "stdafx.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
#include "buy.h"
#include "exception.h"

Buy::Buy(){
	headb = NULL;
	value = 0;
	dis = 0;
}

Buy::~Buy(){
	;
}

//	������Ʒ
void Buy::AddGoods( string No, string Name, float Price, float Discount,int Count ){
	node *p = new node;						//  ��������ڵ�
	p->commodity = new Goods;
	p->commodity->no = No;
	p->commodity->name = Name;
	p->commodity->price = Price;
	p->commodity->discount = Discount;
	p->commodity->count = Count;
	p->commodity->val = 0;
	p->next = headb;
	headb = p;								//	���뵽����ͷ��	
	/*cout<<"������ɣ�\n";*/
}
//  ɾ����Ʒ
void Buy::RemoveGoods( string No ){
	node *p, **q = &headb;					//  ��ǰ����ڵ��ַ
	for( p=headb; p!=NULL; p=p->next ) 
	{
		if( p->commodity->no == No)
			break;							//	�ҵ�
 		if( p->next == NULL ) throw Exception("δ�ҵ�����Ʒ��");
		q = &p->next;	
	}
	*q = p->next;							//	ɾ������ڵ�
	delete p;								//	�ͷ�����ڵ�
	cout<<"ɾ���ɹ���"<<endl;
}
//	�����Ʒ��
void Buy::Sum(){
	node *p;					// ��ǰ����ڵ��ַ
	for( p=headb; p!=NULL; p=p->next ) 
	{
		if(p->commodity->discount!=1){
			p->commodity->val = p->commodity->count*p->commodity->price*p->commodity->discount;
			dis = dis + ((p->commodity->val/p->commodity->discount)- p->commodity->val);
			value = value + p->commodity->val;
		}
		else{
			p->commodity->val = p->commodity->count*p->commodity->price;
			value = value + p->commodity->val;
		}
	}
}
//	����嵥
void Buy::outputGoods( ){
	node *p;
	for( p=headb; p!=NULL; p=p->next ) 
	{
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<"���ƣ�"<<p->commodity->name<<",������"<<p->commodity->count<<",���ۣ�"<<p->commodity->price<<"(Ԫ)��С�ƣ�"<<p->commodity->val<<"(Ԫ)"<<endl;
	}
}
//	������Ʒ
int Buy::search( string No, int Cou ){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=headb; p!=NULL; p=p->next ) {
			if( p->commodity->no == No ){
				if( Cou > p->commodity->count ) return 01;
				else{
					p->commodity->count = p->commodity->count + Cou;
					return 11;
				}
		}
	}
	if(p==NULL)	return 12;
}
//	��ȡ�ܼ�
float Buy::getValue( ){
	return value;
}
//	��ȡ�ۿ�
float Buy::getDis( ){
	return dis;
}