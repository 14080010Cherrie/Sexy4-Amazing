#include "member.h"
class MemberManage{
    struct node{
		Member *user;
		node *next;
	} *headm;									//  �����ͷָ��
	int code;
public:
	MemberManage( );
	~MemberManage( );							//  ��ȫ����Member����
    void Add( string No, string Name, /*long Phoneno, */bool IsVip,int point );
												//	������Ա
    void Remove( string No );					//	ɾ����Ա 
    string &getName( string No );				//	��û�Ա��
    //long &getPhoneno( string No );				//  ����ֻ���
	bool &getIsVip( string No );				//	������
	int &getPoint( string No );					//	��û���
	void sumPoint( string No, float Value );	//	�������
	void output( );								//	�����Ա�б�
	bool search( string No );					//	���һ�Ա
	int &getCode();								//	����
};