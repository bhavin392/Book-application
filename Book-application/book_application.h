#ifndef BOOK_APPLICATION_H
#define BOOK_APPLICATION_H
#include <vector>
#include <QObject>
#include <QString>
#include <QDebug>


using namespace std;
class Book_Application : public QObject{
    Q_OBJECT

    public:
        explicit Book_Application(QObject *parent = nullptr) : QObject(parent) {}
        Q_INVOKABLE void readRecord(QString customer_name){
            for (const auto& record : records) {
                //Convert customer_name to lowercase
                customer_name = customer_name.toLower();
                if (record.customer_name == customer_name) {
                    qDebug() << "Customer Name: " << record.customer_name;
                    qDebug() << "Address: " << record.address;
                    qDebug() << "State: " << record.state;
                    qDebug() << "City: " << record.city;
                    qDebug() << "Zipcode: " << record.zipcode;
                    return;
                }
            }
            qDebug() << "Record not found for customer: " << customer_name;
        }

         Q_INVOKABLE void storeRecord(QString customer_name, QString address, QString state, QString city, QString zipcode){
            Person newPerson;
            //Convert customer_name to lowercase
            customer_name= customer_name.toLower();
            newPerson.customer_name = customer_name;
            newPerson.address = address;
            newPerson.state = state;
            newPerson.city = city;
            newPerson.zipcode = zipcode;
            records.push_back(newPerson);
        }

        Q_INVOKABLE void deleteRecord(QString customer_name){
            for (auto it = records.begin(); it != records.end(); ++it) {
                if (it->customer_name == customer_name) {
                    records.erase(it);
                    qDebug() << "Record deleted for customer: " << customer_name;
                    return;
                }
            }
            qDebug() << "Record not found for customer: " << customer_name;
        }

         Q_INVOKABLE void displayAllRecords(){
            for (const auto& record : records) {
                qDebug() << "Customer Name: " << record.customer_name;
                qDebug() << "Address: " << record.address;
                qDebug() << "State: " << record.state;
                qDebug() << "City: " << record.city ;
                qDebug() << "Zipcode: " << record.zipcode;
                qDebug() << "------------------------" ;
            }
        }
        struct Person{
            QString customer_name;
            QString address;
            QString state;
            QString city;
            QString zipcode;
        };
    private:
        vector<Person> records;


};

#endif // BOOK_APPLICATION_H
