#include <iostream>
#include <jsonapp/jsonfile.h>
int main() {
    string jsonFilePath;
    cout << "Enter the path to the JSON file: ";
    cin >> jsonFilePath;
    JsonApp app(jsonFilePath);
    bool continueExecution = true;
    while (continueExecution) {
        cout << "Choose an option:"<<endl;
        cout << "1. Search by ID" << endl;
        cout << "2. Display applications" <<endl;
        cout << "3. Exit" <<endl;
        int option;
        cin >> option;
        switch (option) {
            case 1:
                app.searchById();
                break;
            case 2:
                app.displayApplications();
                break;
            case 3:
                continueExecution = false;
                cout << "Exiting..." << std::endl;
                break;
            default:
                cout << "Invalid option. Please choose again." <<endl;
                break;
        }
    }
    return 0;
}
