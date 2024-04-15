#ifndef CLIENT_H
#define CLIENT_H
#include <ubacipc/TCPClient.h>
#include <iostream>
using namespace std;
class client : public UBACIPC::TCPClient
{
	public:
		client(string ip, int port);
		~client();
		void initiateConnection();
};
#endif
