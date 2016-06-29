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
void Buy::AddGoods( string No, string Name, float Price, float Discount,int Count, bool Promotion, float Vipdiscount ){
	node *p = new node;						//  ��������ڵ�
	p->commodity = new Goods;
	p->commodity->no = No;
	p->commodity->name = Name;
	p->commodity->price = Price;
	p->commodity->discount = Discount;
	p->commodity->count = Count;
	p->commodity->promotion = Promotion;
	p->commodity->vipdiscount = Vipdiscount;
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
//	�����Ʒ�ܼۺ��ۿ�
void Buy::Sum(){
	node *p;					// ��ǰ����ڵ��ַ
	float v;
	float d;
	for( p=headb; p!=NULL; p=p->next ) 
	{
		v = p->commodity->count*p->commodity->price;
		if(p->commodity->discount!=1){
			d = v*p->commodity->discount;
			if(p->commodity->vipdiscount == 1){
				p->commodity->val = d;
				dis = dis + (v-d);
				value = value + d;
			}
			else{
				p->commodity->val = d*p->commodity->vipdiscount;
				dis = dis + (v-(d/p->commodity->vipdiscount));
				value = value + p->commodity->val;
			}
		}
		else{
			if(p->commodity->promotion == true && p->commodity->count >= 2 ){
				dis = dis + p->commodity->price;
				p->commodity->val = p->commodity->count*p->commodity->price;
				value = value + p->commodity->val;
				p->commodity->count++;
			}
			if(p->commodity->promotion == false && p->commodity->vipdiscount == 1){
				p->commodity->val = p->commodity->count*p->commodity->price;
				value = value + p->commodity->val;
			}
			if(p->commodity->promotion == false && p->commodity->vipdiscount != 1){
				p->commodity->val = p->commodity->count*p->commodity->price*p->commodity->vipdiscount;
				dis = dis + ((p->commodity->val/p->commodity->vipdiscount) - p->commodity->val);
				value = value + p->commodity->val;
			}
		}
	}
}
//	����嵥
void Buy::outputGoods( ){
	node *p;
	int flag=0;
	for( p=headb; p!=NULL; p=p->next ) 
	{
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<"���ƣ�"<<p->commodity->name<<",������"<<p->commodity->count<<",���ۣ�"<<p->commodity->price<<"(Ԫ)��С�ƣ�"<<p->commodity->val<<"(Ԫ)"<<endl;
		if(p->commodity->promotion == true && p->commodity->count>=2 ) flag=1;
	}
	if(flag == 1){
		cout<< "----------------------"<<endl;
		cout<< "����������Ʒ��"<< endl;
		for( p=headb; p!=NULL; p=p->next ) {
			if( p->commodity->promotion == true ) cout<<"���ƣ�"<<p->commodity->name<<",������1"<<endl;
		}
	}
}
//	������Ʒ
int Buy::search( string No, int Cou ){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=headb; p!=NULL; p=p->next ) {
			if( p->commodity->no == No ){
				p->commodity->count = p->commodity->count + Cou;
				return 1;
			}
	}
	if(p==NULL)	return 0;
}
//	��ȡ�ܼ�
float Buy::getValue( ){
	return value;
}
//	��ȡ�ۿ�
float Buy::getDis( ){
	return dis;
}