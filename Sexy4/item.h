#include <string>
using namespace std;
class Item{
<<<<<<< HEAD
	string  no;			//  ��Ʒ���
	string name;		//  ��Ʒ��
	float price;		//  ����
	int count;			//  ����
	float discount;		//  �ۿ�
	bool promotion;		//	����
	float vipdiscount;	//	��Ա�ۿ�
public:
	Item( string No, string Name, float Price, int Count, float Discount, bool Promotion, float Vipdiscount );
								//	���캯�����ڴ������󡢳�ʼ������
	string getNo( );			//  �����Ʒ���
    string getName( );			//  �����Ʒ��
    float &getPrice( );			//  ��õ���
    int &getCount( );			//  �������
    float &getDiscount( );		//  ����ۿ�
	bool &getPromotion( );		//	��ô���
	float &getVipdiscount( );	//	��û�Ա�ۿ�
};
=======
	string  no;			//  商品编号
	string name;		//  商品名
	float price;		//  单价
	int count;			//  总数
	float discount;		//  折扣
	bool promotion;		//	促销
	float vipdiscount;	//	会员折扣
public:
	Item( string No, string Name, float Price, int Count, float Discount, bool Promotion, float Vipdiscount );
								//	构造函数用于创建对象、初始化属性
	string getNo( );			//  获得商品编号
    string getName( );			//  获得商品名
    float &getPrice( );			//  获得单价
    int &getCount( );			//  获得总数
    float &getDiscount( );		//  获得折扣
	bool &getPromotion( );		//	获得促销
	float &getVipdiscount( );	//	获得会员折扣
};
>>>>>>> refs/remotes/origin/master
