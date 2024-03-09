#include <iostream>
#include <list>
#include <iomanip>
#include <limits> 
using namespace std;

class sheet {
public:
    list<list<int>> rows;

    void addRow(const list<int>& rowData) {
        rows.push_back(rowData);
    }

    void deleteRow(int rowIndex) {
        auto it = rows.begin();
        advance(it, rowIndex);
        rows.erase(it);
    }

    void display() {
        cout << "Spreadsheet:" << endl;
        for (const auto& row : rows) {
            for (int cell : row) {
                cout << setw(4) << cell << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    sheet spreadsheet;

    int choice;
    do {
        cout << "Enter 1 to add a new row" << endl;
        cout << "Enter 2 to delete a row" << endl;
        cout << "Enter 3 to display the spreadsheet" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter data for the new row (press space between data, press Enter to finish row): ";
            list<int> newRow;
            char ch;
            int cellData;
            while (cin >> cellData) {
                newRow.push_back(cellData);
                ch = cin.peek();
                if (ch == '\n') {
                    cin.get(); 
                    break; 
                }
                else if (ch == ' ') {
                    cin.get(); 
                }
            }
            spreadsheet.addRow(newRow);
            
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        case 2: {
            int rowIndex;
            cout << "Enter the index of the row to delete: ";
            cin >> rowIndex;
            spreadsheet.deleteRow(rowIndex);
            break;
        }
        case 3: {
            spreadsheet.display();
            break;
        }
        case 0:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
