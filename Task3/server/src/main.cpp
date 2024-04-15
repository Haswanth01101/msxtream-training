
#include "server.h"
int main() {
    Server server(98989);
    while(true){
    server.acceptClientConnection();
    }
    return 0;
}
