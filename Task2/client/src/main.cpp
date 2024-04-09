#include "client.h"
int main(){
	Client client("127.0.0.1",98989);
	while (true)
	{
	client.begin();
	}
	return 0;
}
