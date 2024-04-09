#include "echo_server.h"
int main() {
    EchoServer server(98989);
    while(true){
    server.acceptClientConnection();
    }
    return 0;
}
