#include "http_json.h"
#include <iostream>
using namespace std;
int main() {
    string jsonpath;
    cout << "Enter Source JSON File path: ";
    cin >> jsonpath;
    string configpath = "./config/configuration.json";
    HttpJson* server = new HttpJson(jsonpath, configpath);
    JsonApp config(configpath);
    JsonObject obj = config.getObject();
    map<string, SBU2WebService*>* jWebService = new map<string, SBU2WebService*>;
    string end_url = "/content"; 
    int load = 1; 
    int port = 8080; 
    cout << "End URL: " << end_url << ", Load: " << load << ", Port: " << port << endl;
    (*jWebService)[end_url] = server;
    SBU2LoadBalancer* loadBalancer = new SBU2LoadBalancer(load, jWebService);
    SBU2HTTPServer* httpServer = new SBU2HTTPServer(port, loadBalancer);
    httpServer->run();
    while (1);
     delete server;
    delete loadBalancer;
    delete httpServer;
    return 0;
}

    
