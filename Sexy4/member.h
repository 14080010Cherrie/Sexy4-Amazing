#include <string>
using namespace std;
class Member{
	string  no;			//  ��Ա���
	string name;		//  ��Ա��
	//long phoneno;		//  �ֻ���
	bool isVip;			//	���
	int point;			//	����
public:
	Member( string No, string Name, /*long Phoneno, */bool IsVip, int point );
								//	���캯�����ڴ������󡢳�ʼ������
	string getNo( );			//  ��û�Ա���
    string &getName( );			//  ��û�Ա��
    //long &getPhoneno( );		//  ����ֻ���
	bool &getIsVip( );			//	������
	int &getPoint( );			//	��û���
};