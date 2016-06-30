#include "stdafx.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
#include "exception.h"
#include "membermanage.h"

MemberManage::MemberManage( ){
	headm = NULL;
	code = 123456789;
}
MemberManage::~MemberManage( ){
	;
}
//	������Ʒ
void MemberManage::Add( string No, string Name, /*long Phoneno, */bool IsVip, int Point ){
	//if(Phoneno ==0 ){
	//	cout<<"�ֻ��Ų���Ϊ�գ����ʧ�ܣ�"<<endl;
	//	return;
	//}
	node *p = new node;						//  ��������ڵ�
	p->user = new Member( No, Name, /*Phoneno, */IsVip, Point );
	p->next = headm;
	headm = p;								//	���뵽����ͷ��	
	//cout<<"������ɣ�\n";
}
//  ɾ����Ʒ
void MemberManage::Remove( string No )	{
	node *p, **q = &headm;					//  ��ǰ����ڵ��ַ
	for( p=headm; p!=NULL; p=p->next ) 
	{
		if( p->user->getNo( )== No)
			break;							//	�ҵ�
 		if( p->next == NULL ) throw Exception("δ�ҵ��û�Ա��");
		q = &p->next;	
	}
	*q = p->next;							//	ɾ������ڵ�
	delete p->user;							//	�ͷ�Item����
	delete p;								//	�ͷ�����ڵ�
	cout<<"ɾ���ɹ���"<<endl;
}
//	�����Ʒ��
string &MemberManage::getName( string No ){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=headm; p!=NULL; p=p->next ) 
	{
		if( p->user->getNo( )== No )
			break;							//	�ҵ�
	}
	if(p==NULL) throw Exception("δ�ҵ��û�Ա��");
	string name;
	name = p->user->getName();
	return name;
}
////  ����ֻ���
//long &MemberManage::getPhoneno( string No ){
//	node *p;								// ��ǰ����ڵ��ַ
//	for( p=headm; p!=NULL; p=p->next ) 
//	{
//		if( p->user->getNo( )== No )
//			break;							//	�ҵ�
//	}
//	if(p==NULL) throw Exception("δ�ҵ��û�Ա��");
//	return p->user->getPhoneno();
//}
//	������
bool &MemberManage::getIsVip( string No ){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=headm; p!=NULL; p=p->next ) 
	{
		if( p->user->getNo( )== No )
			break;							//	�ҵ�
	}
	if(p==NULL) throw Exception("δ�ҵ��û�Ա��");
	return p->user->getIsVip();
}
//	��û���
int &MemberManage::getPoint( string No ){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=headm; p!=NULL; p=p->next ) 
	{
		if( p->user->getNo( )== No )
			break;							//	�ҵ�
	}
	if(p==NULL) throw Exception("δ�ҵ��û�Ա��");
	return p->user->getPoint();	
}
//	�������
void MemberManage::sumPoint( string No, float Value ){
	node *p;
	int poi;								//	��ǰ����
	int a;									//	����
	int v;									//	�ɻ��ֵ���
	v = (int)(Value/5);
	for( p=headm; p!=NULL; p=p->next ) 
	{
		if( p->user->getNo( )== No )
			break;							//	�ҵ�
	}
	if(p==NULL) throw Exception("δ�ҵ��û�Ա��");
	else{
		poi = getPoint( No );
		if( poi <0 ) cout<<"�û�Ա���������뵽�ͻ�����̨���в�ѯ��";
		if( poi >=0 && poi <=200){
			a = poi + v;
			if( a > 200){
				cout<<"adfd";
				v = a - 201;
				a = 201 + (v*3);
				if(a > 500){
					v = (a - 501)/3;
					p->user->getPoint() = 501 + ( v*5 );
				}
				else p->user->getPoint() = a;
			}
			else p->user->getPoint() = a;
		}
		if( poi >200 && poi <=500 ){
			a = poi + ( v*3 );
			if( a >501 ){
				v = (a - 501)/3;
				p->user->getPoint() = 501 + ( v*5 );
			}
			else p->user->getPoint() = a;
		}
		if( poi >500 ) p->user->getPoint() = poi + ( v*5 );
	}
}
//	�����Ա�б�
void MemberManage::output( ){
	node *p;
	for( p=headm; p!=NULL; p=p->next ) 
	{
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<setw(12)<<p->user->getNo()<<setw(12)<<p->user->getName();
		cout<<setiosflags(ios::fixed)<<setprecision(2)/*<<setw(12)<<p->user->getPhoneno()*/<<setw(12)<<p->user->getIsVip();
	}
}
//	���һ�Ա
bool MemberManage::search( string No ){
	node *p;								// ��ǰ����ڵ��ַ
	for( p=headm; p!=NULL; p=p->next ) 
	{
		if( p->user->getNo( )== No )
		return true;						//	�ҵ�
	}
	if(p==NULL)	return false;
}
//	����
int &MemberManage::getCode(){
	return code;
}