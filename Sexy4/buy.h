#include <string>
using namespace std;
#include "itemmanage.h"
class Buy{
	struct Goods{
		string  no;			//  ��Ʒ���
		string name;		//  ��Ʒ��
		float price;		//  ����
		float discount;		//  �ۿ�
		float vipdiscount;	//	��Ա�ۿ�
		bool promotion;		//	����
		int count;			//	��������
		float val;			//	С��
	};
	struct node{
		Goods*commodity;
		node *next;
	} *headb;
	float value;		//	�ܼ�
	float dis;			//	�ۼ�
public:
	Buy( );
	~Buy( );
    void AddGoods( string No, string Name, float Price, float Discount, int Count, bool Promotion, float Vipdiscount );
													//	������Ʒ
    void RemoveGoods( string No );					//	ɾ����Ʒ 
    void Sum( bool IsVip, ItemManage S );			//	�����Ʒ�ܼ�
	void outputGoods( );							//	����嵥
	int search( string No, int Cou );				//	������Ʒ
	float getValue( );								//	��ȡ�ܼ�
	float getDis( );								//	��ȡ�ۿ�
};