class Exception
{
 	string  msg;		//	������Ϣ
public:
 	Exception( string m ) 
	{
 		msg = m;		
	}
 	string  Msg( )	
	{
 		return  msg; 	
	}
};