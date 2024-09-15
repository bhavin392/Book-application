#include <iostream>
#include "book_application.h"
using namespace std;

enum MenuOptions {
    READ = 1,
    STORE,
    DELETE,
    DISPLAY_ALL,
    EXIT
};

int main(){
    Book_Application app;
    int choice;
    while(choice != EXIT){
        cout << "What application would you like to use? (1: Read, 2: Store, 3: Delete, 4: Display All, 5: Exit): ";
        cin >> choice;
        switch(choice){
            case READ: {
                string customer_name;
                cout << "Enter customer name to read record: ";
                cin >> customer_name;
                app.readRecord(customer_name);
                break;
            }
            case STORE: {
                string customer_name, address, state, city, zipcode;
        
                cout << "Enter customer name: ";
                cin >> customer_name;
                cout << "Enter address: ";
                cin >> address;
                cout << "Enter state: ";
                cin >> state;
                cout << "Enter city: ";
                cin >> city;
                cout << "Enter zipcode: ";
                cin >> zipcode;
                app.storeRecord(customer_name, address, state, city, zipcode);
                break;
            }
            case DELETE: {
                string customer_name;
                cout << "Enter customer name to delete record: ";
                cin >> customer_name;
                app.deleteRecord(customer_name);
                break;
            }
            case DISPLAY_ALL: {
                app.displayAllRecords();
                break;
            }
            case EXIT: {
                cout << "Exiting application." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
    return 0;
}

