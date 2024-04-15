#include "jsonfile.h"
int main() {
    string jsonFilePath;
    cout << "Enter the path to the JSON file: ";
    cin >> jsonFilePath;
    JsonApp app(jsonFilePath);
    app.searchById();
    app.displayApplications();
    return 0;
}
