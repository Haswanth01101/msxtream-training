#include "client.h"
Client::Client(std::string ip, int port) : TCPClient(ip, port) {}
void Client::begin() {
    string msg;
    while (true) {
        cout << "Enter a message or (type 'Bye' to Bye): ";
        getline(cin, msg);
        if (msg == "Bye") {
            break;
        }
        int bytesSent = sendData(msg);
        if (bytesSent > 0) {
            cout << "Message sent to Server :" <<endl;
            char buffer[1024];
            int bytesRead = recv(this->getDescriptor(), buffer, sizeof(buffer), 0);
            if (bytesRead > 0) {
                cout << "Received from server: " << buffer<<endl;
            } else {
                cerr << "Error receiving response from server"<<endl;
            }
        } else {
            cerr << "Error sending message!!" << std::endl;
        }
    }
}

Client::~Client() {}
