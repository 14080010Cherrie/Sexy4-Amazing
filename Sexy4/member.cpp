#include "stdafx.h"
#include <string>
using namespace std;
#include "member.h"

//	��ʼ��
Member::Member( string No, string Name, /*long Phoneno, */bool IsVip, int Point )
{
	no = No;
	name = Name;
	//phoneno = Phoneno;
	isVip = IsVip;
	point = Point;
}
//  ��û�Ա���
string Member::getNo( ){
	return no;
}
//  ��û�Ա��
string &Member::getName( ){
	return name;
}
////  ����ֻ���
//long &Member::getPhoneno( ){
//	return phoneno;
//}
//	������
bool &Member::getIsVip( ){
	return isVip;
}
//	��û���
int &Member::getPoint( ){
	return point;
}