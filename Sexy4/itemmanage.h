#include "item.h"
class ItemManage{
    struct node{
		Item *commodity;
		node *next;
	} *head;									//  �����ͷָ��
	int code;
public:
	ItemManage( );
	~ItemManage( );								//  ��ȫ����Item����
    void Add( string No, string Name, float Price, int Count, float Discount, bool Promotion, float Vipdiscount );
												//	������Ʒ
    void Remove( string No );					//	ɾ����Ʒ 
    string getName( string No );				//	�����Ʒ��
    float &getPrice( string No );				//  ��õ���
    int &getCount( string No );					//  �������
    float &getDiscount( string No );			//  ����ۿ�
	bool &getPromotion( string No );			//	��ô���
	float &getVipdiscount( string No );			//	��û�Ա�ۿ�
	void output( );								//	������
	bool search( string No );					//	������Ʒ
	int &getCode();								//	����
};