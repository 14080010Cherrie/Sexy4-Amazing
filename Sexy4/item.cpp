#include "stdafx.h"
#include <string>
using namespace std;
#include "Item.h"

//	��ʼ��
Item::Item( string No, string Name, float Price, int Count, float Discount, bool Promotion )
{
	no = No;
	name = Name;
	price = Price;
	count = Count;
	discount = Discount;
	promotion = Promotion;
}
//  �����Ʒ���
string Item::getNo( ){
	return no;
}
//  �����Ʒ��
string Item::getName( ){
	return name;
}
//  ��õ���
float &Item::getPrice( ){
	return price;
}
//  �������
int &Item::getCount( ){
	return count;
}
//  ����ۿ�
float &Item::getDiscount( ){
	return discount;
}
//	��ô���
bool &Item::getPromotion( ){
	return promotion;
}