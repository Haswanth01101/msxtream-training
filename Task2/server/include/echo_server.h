#ifndef ECHO_SERVER_H
#define ECHO_SERVER_H
#include <ubacipc/TCPServer.h>
using namespace std;
class EchoServer : public UBACIPC::TCPServer {
public:
    EchoServer(int port);
    virtual ~EchoServer();
    virtual void createNewClient(int fd) override;
};
#endif
