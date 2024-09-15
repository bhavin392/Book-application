import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Book Application")

    Column {
        spacing: 10
        anchors.centerIn: parent

        Button {
            text: "Read Record"
            onClicked: {
                var customerName = prompt("Enter customer name to read record:");
                if (customerName) {
                    bookApp.readRecord(customerName);
                }
            }
        }

        Button {
            text: "Store Record"
            onClicked: {
                var customerName = prompt("Enter customer name:");
                var address = prompt("Enter address:");
                var state = prompt("Enter state:");
                var city = prompt("Enter city:");
                var zipcode = prompt("Enter zipcode:");
                if (customerName && address && state && city && zipcode) {
                    bookApp.storeRecord(customerName, address, state, city, zipcode);
                }
            }
        }

        Button {
            text: "Delete Record"
            onClicked: {
                var customerName = prompt("Enter customer name to delete record:");
                if (customerName) {
                    bookApp.deleteRecord(customerName);
                }
            }
        }

        Button {
            text: "Display All Records"
            onClicked: {
                bookApp.displayAllRecords();
            }
        }

        Button {
            text: "Exit"
            onClicked: Qt.quit
        }
    }
}
