#ifndef JSON_FILE_H
#define JSON_FILE_H
#include "jsonparser/JsonParser.h"
#include <iostream>
#include <fstream>
using namespace std;
using namespace UBACJSON;
class JsonApp {
private:
    JsonObject object;
    string path;
    void loadJson();
    void printInfo();
    void printInfoById(JsonObject& obj);
    void printApps(); 
public:
    JsonApp(const string& path);
    ~JsonApp();
    void searchById(); 
    void displayApplications();
};
#endif
