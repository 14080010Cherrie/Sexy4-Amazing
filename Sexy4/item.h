#include <string>
using namespace std;
class Item{
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