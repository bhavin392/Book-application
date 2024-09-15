#include <iostream>
#include <vector>
#include <string>   
using namespace std;
class Book_Application{
    public:
        void readRecord(string customer_name){
            for (const auto& record : records) {
                //Convert customer_name to lowercase
                for (auto & c : customer_name) c = tolower(c);
                if (record.customer_name == customer_name) {
                    cout << "Customer Name: " << record.customer_name << endl;
                    cout << "Address: " << record.address << endl;
                    cout << "State: " << record.state << endl;
                    cout << "City: " << record.city << endl;
                    cout << "Zipcode: " << record.zipcode << endl;
                    return;
                }
            }
            cout << "Record not found for customer: " << customer_name << endl;
        }
        void storeRecord(string customer_name, string address, string state, string city, string zipcode){
            Person newPerson;
            //Convert customer_name to lowercase
            for (auto & c : customer_name) c = tolower(c);
            newPerson.customer_name = customer_name;
            newPerson.address = address;
            newPerson.state = state;
            newPerson.city = city;
            newPerson.zipcode = zipcode;
            records.push_back(newPerson);
        }

        void deleteRecord(string customer_name){
            for (auto it = records.begin(); it != records.end(); ++it) {
                if (it->customer_name == customer_name) {
                    records.erase(it);
                    cout << "Record deleted for customer: " << customer_name << endl;
                    return;
                }
            }
            cout << "Record not found for customer: " << customer_name << endl;
        }

        void displayAllRecords(){
            for (const auto& record : records) {
                cout << "Customer Name: " << record.customer_name << endl;
                cout << "Address: " << record.address << endl;
                cout << "State: " << record.state << endl;
                cout << "City: " << record.city << endl;
                cout << "Zipcode: " << record.zipcode << endl;
                cout << "------------------------" << endl;
            }
        }
        struct Person{
            string customer_name;
            string address;
            string state;
            string city;
            string zipcode; 
        };
    private:
        vector<Person> records;


};