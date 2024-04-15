#include "client.h"
int main(){
	client client("127.0.0.1",98989);
	while (true)
	{
	client.initiateConnection();
	}
	return 0;
}

