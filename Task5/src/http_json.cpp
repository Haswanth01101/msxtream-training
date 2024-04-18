// 
// HttpJson::~HttpJson() {
//     // No need to delete jsonData and configData, unique_ptr handles memory deallocation automatically
// }
// void HttpJson::onInvalidJsonRequest(HTTPServerRequest* request, HTTPConnection* connection, const string& rawRequest) {
//     cerr << "Request Received: " << rawRequest << endl;
//     string infoid = configObj["Response_onInvalidJson"]["infoid"];
//     string infomsg = configObj["Response_onInvalidJson"]["infomsg"];

//     MSFRequest* msfreq = new MSFRequest(rawRequest);
//     MSFResponse* error = new MSFResponse(msfreq);
//     string errmsg = "Invalid JSON request: " + rawRequest;
//     error->addToData("error", errmsg);
//     error->setInfoID(infoid);
//     error->setInfoMsg(infomsg);
//     error->setSvcName(configObj["Response_onInvalidJson"]["svcName"]);
//     error->setSvcGroup(configObj["Response_onInvalidJson"]["svcGroup"]);

//     sendResponse(error, connection);
//     connection->release();
// }

// void HttpJson::onPostProcessRequest(MSFRequest* msfRequest, MSFResponse* msfResponse, HTTPConnection* connection) {
//     cout << "Request received" << endl;
//     string requestStr = msfRequest->toString();
//     JsonParser parser(requestStr);
//     JsonObject requestObject = parser.getJsonObject();

//     if (requestObject.hasKey(configObj["Response_onPostProcessRequest"]["key"])) {
//         string contentValue = requestObject[configObj["Response_onPostProcessRequest"]["key"]];

//         if (contentValue == configObj["Response_onPostProcessRequest"]["value1"] ||
//             contentValue == configObj["Response_onPostProcessRequest"]["value2"] ||
//             contentValue == configObj["Response_onPostProcessRequest"]["value3"]) {
//             JsonObject responseData = jsonData->getObject();

//             if (contentValue == configObj["Response_onPostProcessRequest"]["value1"]) {
//                 msfResponse->addToData("all", responseData);
//             } else if (contentValue == configObj["Response_onPostProcessRequest"]["value2"]) {
//                 msfResponse->addToData("app", responseData["app"]);
//             } else if (contentValue == configObj["Response_onPostProcessRequest"]["value3"]) {
//                 msfResponse->addToData("info", responseData["info"]);
//             }
//         } else {
//             cerr << "Invalid content value!!" << endl;
//             string infoid = configObj["Response_onPostProcessRequest"]["infoid"];
//             string infomsg = configObj["Response_onPostProcessRequest"]["infomsg"];

//             msfResponse->setInfoID(infoid);
//             msfResponse->setInfoMsg(infomsg);
//         }
//     }

//     msfResponse->setSvcName(configObj["Response_onPostProcessRequest"]["svcName"]);
//     msfResponse->setSvcGroup(configObj["Response_onPostProcessRequest"]["svcGroup"]);

//     cout << msfResponse->toString() << endl;
//     sendResponse(msfResponse, connection);
//     connection->release();
// }
#include "http_json.h"
HttpJson::HttpJson(const string& jsonPath, const string& configPath) : SBU2WebService(), jsonPath(jsonPath), configPath(configPath) {
    jsonData = make_unique<JsonApp>(jsonPath);
    configData = make_unique<JsonApp>(configPath);
    configObj = configData->getObject();
}
HttpJson::~HttpJson() {
    // No need to delete jsonData and configData, unique_ptr handles memory deallocation automatically
}
void HttpJson::onPostProcessRequest(MSFRequest* msfRequest, MSFResponse* msfResponse, HTTPConnection* connection) {
    cout << "Request received" << endl;
    string requestStr = msfRequest->toString();
    JsonParser parser(requestStr);
    JsonObject requestObject = parser.getJsonObject();

    // Extract the content value from the request object
    string contentValue = requestObject[configObj["Response_onPostProcessRequest"]["key"]];

    // Check if the content value is one of the predefined values
    if (contentValue == configObj["Response_onPostProcessRequest"]["value1"] ||
        contentValue == configObj["Response_onPostProcessRequest"]["value2"] ||
        contentValue == configObj["Response_onPostProcessRequest"]["value3"]) {
        
        // Get the corresponding data from the JSON data object
        JsonObject responseData = jsonData->getObject();
        string responseKey;

        // Determine the appropriate response key based on the content value
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

        // Add the selected data to the response
    } else {
        // If the content value is not valid, set appropriate error info
        cerr << "Invalid content value: " << contentValue << endl;
        string infoid = configObj["Response_onPostProcessRequest"]["infoid"];
        string infomsg = configObj["Response_onPostProcessRequest"]["infomsg"];

        msfResponse->setInfoID(infoid);
        msfResponse->setInfoMsg(infomsg);
    }

    // Set service name and group for the response
    msfResponse->setSvcName(configObj["Response_onPostProcessRequest"]["svcName"]);
    msfResponse->setSvcGroup(configObj["Response_onPostProcessRequest"]["svcGroup"]);

    // Print the response information
    cout << msfResponse->toString() << endl;

    // Send the response and release the connection
    sendResponse(msfResponse, connection);
    connection->release();
}
