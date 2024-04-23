#include "http_json.h"
#include <iostream>
using namespace std;
int main(int argc,char *argv[]) {
	if (argc < 2) {
	 	cerr << "Usage: " << argv[0] << " <json_path> <config_path>" << endl;
		return 1;
	}
	string jsonpath=argv[1];
	string configpath = argv[2];
	HttpJson* server = new HttpJson(jsonpath, configpath);
    JsonApp config(configpath);
    JsonObject obj = config.getObject();
    map<string, SBU2WebService*>* jWebService = new map<string, SBU2WebService*>;
    string end_url = obj["httpServer"]["endUrl"]; 
    int load = 1; 
    int port = 12345; 
    cout << "End URL: " << end_url << ", Load: " << load << ", Port: " << port << endl;
    (*jWebService)[end_url] = server;
    SBU2LoadBalancer* loadBalancer = new SBU2LoadBalancer(load, jWebService);
    SBU2HTTPServer* httpServer = new SBU2HTTPServer(port, loadBalancer);
    httpServer->run();
    while (1);
    return 0;
}

    
