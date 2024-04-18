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
        // If the content value is not valid, set appropriate error info
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
