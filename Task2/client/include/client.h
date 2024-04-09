#ifndef CLIENT_H
#define CLIENT_H
#include<ubacipc/TCPClient.h>
#include<iostream>
using namespace std;
class Client : public UBACIPC::TCPClient
{
	public:
		Client(string ip, int port);
		~Client();
		void begin();
};
#endif
