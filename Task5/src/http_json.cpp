#include "http_json.h"
HttpJson::HttpJson(const string& jsonPath, const string& configPath) : SBU2WebService(), jsonPath(jsonPath), configPath(configPath) {
    jsonData = make_unique<JsonApp>(jsonPath);
    configData = make_unique<JsonApp>(configPath);
    configObj = configData->getObject();
}
HttpJson::~HttpJson() {
}
void HttpJson::onPostProcessRequest(MSFRequest* msfRequest, MSFResponse* msfResponse, HTTPConnection* connection) {
    cout << "Request received" << endl;
    string requestStr = msfRequest->toString();
    JsonParser parser(requestStr);
    JsonObject requestObject = parser.getJsonObject();
    string contentValue = requestObject[configObj["Response_onPostProcessRequest"]["key"]];
    if (contentValue == configObj["Response_onPostProcessRequest"]["value1"] ||
        contentValue == configObj["Response_onPostProcessRequest"]["value2"] ||
        contentValue == configObj["Response_onPostProcessRequest"]["value3"]) {
        JsonObject responseData = jsonData->getObject();
        string responseKey;
        if (contentValue == configObj["Response_onPostProcessRequest"]["value1"]) {
            responseKey = "all";
            msfResponse->addToData(responseKey, responseData);

        } else if (contentValue == configObj["Response_onPostProcessRequest"]["value2"]) {
            responseKey = "app";
        msfResponse->addToData(responseKey, responseData[responseKey]);

        } else if (contentValue == configObj["Response_onPostProcessRequest"]["value3"]) {
            responseKey = "info";
        msfResponse->addToData(responseKey, responseData[responseKey]);
            }
    } else {
        cerr << "Invalid content value: " << contentValue << endl;
        string infoid = configObj["Response_onPostProcessRequest"]["infoid"];
        string infomsg = configObj["Response_onPostProcessRequest"]["infomsg"];

        msfResponse->setInfoID(infoid);
        msfResponse->setInfoMsg(infomsg);
    }
    msfResponse->setSvcName(configObj["Response_onPostProcessRequest"]["svcName"]);
    msfResponse->setSvcGroup(configObj["Response_onPostProcessRequest"]["svcGroup"]);
    cout << msfResponse->toString() << endl;
    sendResponse(msfResponse, connection);
    connection->release();
}
void HttpJson::onInvalidJSONRequest(HTTPServerRequest* request, HTTPConnection* connection, const string& rawRequest)
{
	cerr << "Request Received: " << rawRequest << endl;
	string infoid,infomsg;
	infoid = configObj["Response_onInvaidJson"]["infoid"];
	infomsg = configObj["Response_onInvalidJson"]["infomsg"];
	MSFRequest* msfreq = new MSFRequest(rawRequest);
	MSFResponse* err = new MSFResponse(msfreq);
	string errmsg = "Invalid JSON request: " + rawRequest;
	err->addToData("error", errmsg);
	err->setInfoID(infoid);
	err->setInfoMsg(infomsg);
        err->setSvcName(configObj["Response_onInvalidJson"]["svcName"]);
	err->setSvcGroup(configObj["Response_onInvalidJson"]["svcGroup"]);
	err->setSvcVersion(configObj["Response_onInvalidJson"]["svcVersion"]);
	sendResponse(err, connection);
	connection->release();
	}
