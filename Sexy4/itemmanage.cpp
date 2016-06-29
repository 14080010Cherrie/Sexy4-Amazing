#include "stdafx.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
#include "exception.h"
#include "itemmanage.h"

ItemManage::ItemManage(){
	head = NULL;
	code = 123456;
}

ItemManage::~ItemManage(){
	;
}

//	������Ʒ
void ItemManage::Add( string No, string Name, float Price, int Count, float Discount ){
	node *p = new node;						//  ��������ڵ�
	p->commodity = new Item( No, Name, Price, Count, Discount);
	p->next = head;
	head = p;								//	���뵽����ͷ��	
	/*cout<<"������ɣ�\n";*/
}
//  ɾ����Ʒ
void ItemManage::Remove( string No )	{
	node *p, **q = &head;					//  ��ǰ����ڵ��ַ
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No)
			break;							//	�ҵ�
 		if( p->next == NULL ) throw Exception("δ�ҵ�����Ʒ��");
		q = &p->next;	
	}
	*q = p->next;							//	ɾ������ڵ�
	delete p->commodity;					//	�ͷ�Item����
	delete p;								//	�ͷ�����ڵ�
	cout<<"ɾ���ɹ���"<<endl;
}
//	�����Ʒ��
string ItemManage::getName( string No ){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No )
			break;							//	�ҵ�
	}
	if(p==NULL) throw Exception("δ�ҵ�����Ʒ��");
	string name;
	name = p->commodity->getName();
	return name;
}
//	�����Ʒ����
float ItemManage::getPrice( string No){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No )
			break;							//	�ҵ�
	}
	if(p==NULL) throw Exception("δ�ҵ�����Ʒ��");
	return p->commodity->getPrice();
}
//	�����Ʒ����
int ItemManage::getCount( string No ){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity ->getNo( )== No )
			break;							//	�ҵ�
	}
	if(p==NULL) throw Exception("�޸�����Ϣ��");
	return p->commodity->getCount();
}
//	�����Ʒ�ۿ�
float ItemManage::getDiscount( string No ){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No )
			break;							//	�ҵ�
	}
	if(p==NULL) throw Exception("δ�ҵ�����Ʒ��");
	return p->commodity->getDiscount();
	
}
//	��ȡ����
int ItemManage::getCode(){
	return code;
}
//	������
void ItemManage::output( ){
	node *p;
	for( p=head; p!=NULL; p=p->next ) 
	{
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<setw(20)<<p->commodity->getNo()<<setw(20)<<p->commodity->getName()<<setw(20)<<p->commodity->getPrice()<<setw(20)<<p->commodity->getCount()<<endl;
	}
}
//	������Ʒ
bool ItemManage::search( string No ){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=head; p!=NULL; p=p->next ) 
	{
		if( p->commodity->getNo( )== No )
		return true;						//	�ҵ�
	}
	if(p==NULL)	return false;
}
////	���������Ʒ����Ϣ��ʹ���������֮�����Ⱦ�
//ostream& operator<<(ostream&out,Item&g){
//	out<<setw(20)<<g.getNo()<<setw(20)<<g.getName()<<setw(20)<<g.getPrice()<<setw(20)<<g.getCount()<<endl;
//	return out;
//}