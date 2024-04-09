#include "echo_server.h"
void EchoServer::createNewClient(int fd) {
    cout << "Connected the New Client: " <<fd<<endl;
    char buffer[1024];
    int bytesRead;
    while (true) {
        bytesRead = recv(fd, buffer, sizeof(buffer), 0);
        if (bytesRead > 0) {
            cout << "Received from client SuccessFully: " << buffer<<endl;
            int bytesSent = send(fd, buffer, bytesRead, 0);
            if (bytesSent != bytesRead) {
                cerr << " It contain error while sending data to client!!" <<endl;
                break;
            }
        } else if (bytesRead == 0) {
            cout << "Client is Terminated: "<<fd<<endl;
            close(fd);
            break;
        } else {
            cerr << "Error receiving data from client!!"<<endl;
            break;
        }
    }
}
EchoServer::EchoServer(int port) : TCPServer(port) {}
EchoServer::~EchoServer() {}
