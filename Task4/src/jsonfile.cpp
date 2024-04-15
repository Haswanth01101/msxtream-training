#include "jsonfile.h"
JsonApp::JsonApp(const string& path) : path(path) {
    loadJson();
}
JsonApp::~JsonApp() {}
void JsonApp::loadJson() {
    ifstream file(path);
    if (!file.is_open()) {
        cerr << "Error: Unable to open JSON file." << endl;
        return;
    }
    ostringstream ss;
    ss << file.rdbuf();
    JsonParser parser(ss.str());
    object = parser.getJsonObject();
    file.close();
}
void JsonApp::searchById() {
    printInfo(); 
    string key;
    cout << "Enter the key or 'all' to print all IDs: ";
    cin >> key;
    if (key == "all" || key == "All" || key == "ALL") {
        printInfo(); 
    } else {
        bool keyFound = false;
        for (size_t i = 0; i < object["info"].size(); ++i) {
            JsonObject infoObj = object["info"][i];
            if (key == infoObj["key"].toString()) {
                printInfoById(infoObj);
                keyFound = true;
                break;
            }
        }
        if (!keyFound) {
            cerr << "Key '" << key << "' not found in the JSON file." << endl;
        }
    }
}
void JsonApp::displayApplications() {
    printApps();
}
void JsonApp::printInfo() {
    JsonObject info = object.getJsonObject("info");
    if (info.size() == 0) {
        cerr << "No info found in the JSON file." << endl;
        return;
    }
    cout << "Available info:" << endl;
    for (size_t i = 0; i < info.size(); ++i) {
        printInfoById(info[i]);
    }
}
void JsonApp::printInfoById(JsonObject& infoObj) {
    cout << "Key: " << infoObj["key"].toString() << endl;
    cout << "Action: " << infoObj["value"]["action"].toString() << endl;
    cout << "Message: " << infoObj["value"]["msg"].toString() << endl;
}
void JsonApp::printApps() {
    JsonObject app = object.getJsonObject("app");
    if (app.size() == 0) {
        cerr << "No apps found in the JSON file." << endl;
        return;
    }
    cout << "Available apps:" << endl;
    for (size_t i = 0; i < app.size(); ++i) {
        cout << "Key: " << app[i]["key"].toString() << endl;
        cout << "Value: " << app[i]["value"].toString() << endl;
    }
}
