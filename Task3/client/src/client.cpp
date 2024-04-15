#include "client.h"
client::client(string ip, int port) : TCPClient(ip, port) {}
void client::initiateConnection(){
    string msg;
    while (true) {
        cout << "Enter a message or (type 'BYE' to BYE): ";
        getline(cin, msg);
        if (msg == "exit") {
            break;
        }
        int bytesSent = sendData(msg);
        if (bytesSent > 0) {
            cout << "Message sent to Server Successfully" <<endl;
            char buffer[1024];
            int bytesRead = recv(this->getDescriptor(), buffer, sizeof(buffer), 0);
            
            if (bytesRead > 0) {
                cout << "Received Message from server Successfully: " << buffer<<endl;
            } else {
                cerr << "Error receiving response from server !!" <<endl;
            }
        } else {
            cerr << "Error sending message !!" <<endl;
        }
    }
}

client::~client() {}