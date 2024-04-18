#ifndef HTTP_JSON_H
#define HTTP_JSON_H

#include <iostream>
#include <string>
#include <memory>
#include <sbu2webapp/SBU2WebService.h>
#include <jsonapp/jsonfile.h>
#include <jsonparser/JsonParser.h>
#include<sbu2webapp/SBU2HTTPServer.h>
using namespace std;
using namespace SBU2;
using namespace UBACIPC;
class HttpJson : public SBU2WebService {
public:
    HttpJson(const string& jsonPath, const string& configPath);
    ~HttpJson();
    void onInvalidJsonRequest(HTTPServerRequest* request, HTTPConnection* connection, const string& rawRequest);
    void onPostProcessRequest(MSFRequest* msfRequest, MSFResponse* msfResponse, HTTPConnection* connection);
private:
    unique_ptr<JsonApp> jsonData;
    unique_ptr<JsonApp> configData;
    string jsonPath;
    string configPath;
    JsonObject request;
    JsonObject response;
    JsonObject configObj;
};
#endif
