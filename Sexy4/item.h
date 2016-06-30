#include <string>
using namespace std;
class Item{
<<<<<<< HEAD
	string  no;			//  ÉÌÆ·±àºÅ
	string name;		//  ÉÌÆ·Ãû
	float price;		//  µ¥¼Û
	int count;			//  ×ÜÊý
	float discount;		//  ÕÛ¿Û
	bool promotion;		//	´ÙÏú
	float vipdiscount;	//	»áÔ±ÕÛ¿Û
public:
	Item( string No, string Name, float Price, int Count, float Discount, bool Promotion, float Vipdiscount );
								//	¹¹Ôìº¯ÊýÓÃÓÚ´´½¨¶ÔÏó¡¢³õÊ¼»¯ÊôÐÔ
	string getNo( );			//  »ñµÃÉÌÆ·±àºÅ
    string getName( );			//  »ñµÃÉÌÆ·Ãû
    float &getPrice( );			//  »ñµÃµ¥¼Û
    int &getCount( );			//  »ñµÃ×ÜÊý
    float &getDiscount( );		//  »ñµÃÕÛ¿Û
	bool &getPromotion( );		//	»ñµÃ´ÙÏú
	float &getVipdiscount( );	//	»ñµÃ»áÔ±ÕÛ¿Û
};
=======
	string  no;			//  å•†å“ç¼–å·
	string name;		//  å•†å“å
	float price;		//  å•ä»·
	int count;			//  æ€»æ•°
	float discount;		//  æŠ˜æ‰£
	bool promotion;		//	ä¿ƒé”€
	float vipdiscount;	//	ä¼šå‘˜æŠ˜æ‰£
public:
	Item( string No, string Name, float Price, int Count, float Discount, bool Promotion, float Vipdiscount );
								//	æž„é€ å‡½æ•°ç”¨äºŽåˆ›å»ºå¯¹è±¡ã€åˆå§‹åŒ–å±žæ€§
	string getNo( );			//  èŽ·å¾—å•†å“ç¼–å·
    string getName( );			//  èŽ·å¾—å•†å“å
    float &getPrice( );			//  èŽ·å¾—å•ä»·
    int &getCount( );			//  èŽ·å¾—æ€»æ•°
    float &getDiscount( );		//  èŽ·å¾—æŠ˜æ‰£
	bool &getPromotion( );		//	èŽ·å¾—ä¿ƒé”€
	float &getVipdiscount( );	//	èŽ·å¾—ä¼šå‘˜æŠ˜æ‰£
};
>>>>>>> refs/remotes/origin/master
