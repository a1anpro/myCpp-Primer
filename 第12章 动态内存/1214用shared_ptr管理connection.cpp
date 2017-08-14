#include <iostream>
#include <memory>
using namespace std;

struct destination{
public:
	destination()=default;
	destination(string ip, int host):_ip(ip),_host(host){}

	string _ip;
	int _host;
	
};
struct connection{
public:
	connection()=default;
	connection(string ip, int host):_ip(ip),_host(host){}

	string _ip;
	int _host;
};

connection connect(destination* pDest){
	shared_ptr<connection> pConn(new connection(pDest->_ip, pDest->_host));//指向connection的智能指针
	cout << "creating connection(" << pConn.use_count() << ")" <<endl;
	return *pConn; 
}

void disconnect(connection pConn){
	cout << "connection close(" << pConn._ip<<","<<pConn._host << ")" <<endl;
}
void end_connection(connection *pConn){
	disconnect(*pConn);
}

void f(destination &dest)
{
	connection conn = connect(&dest);
	shared_ptr<connection> p(&conn, end_connection);//end_..代替delete 
	cout << "connecting now ("<<p.use_count()<<")"<<endl;
}

int main(){
	destination dest("218.199.228.248",10);
	f(dest);
	
	return 0;
}
