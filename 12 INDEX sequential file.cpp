#include <iostream>
#include <fstream>
using namespace std;

class Record {
    int id;
    string name;
    int salary;
    string designation;

public:
    Record();
    int getIdno();
    void getData();
    void putData();
};

Record::Record() {
    id = 0;
    name = ' ';
    designation = ' ';
    salary = 0;
}

int Record::getIdno() {
    return (id);
}

void Record::getData() {
    cout << "\nEnter Details: ";
    cout << "\nId no: ";
    cin >> id;
    cout << "Name: ";
    cin >> name;
    cout << "Salary: ";
    cin >> salary;
    cout << "Designation: ";
    cin >> designation;
}

void Record::putData() {
    cout << "\nId No.: ";
    cout << id;
    cout << "\t\tName: ";
    cout << name;
    cout << "\nSalary: ";
    cout << salary;
    cout << "\tDesignation: ";
    cout << designation;
}

class File {
    ifstream fin;
    ofstream fout;
    fstream fs;

public:
    void insert();
    void display();
    void search(int);
    int Delete(int);
    int edit(int);
};

void File::insert() {
    Record r;
    r.getData();
    fout.open("EmployeeDB", ios::ate | ios::app);
    fout.write((char *)&r, sizeof(r));
    fout.close();
}

void File::display() {
    Record r;
    fin.open("EmployeeDB");
    fin.seekg(0, ios::beg);
    while (fin.read((char *)&r, sizeof(r)))
        r.putData();

    fin.close();
}

void File::search(int id) {
    Record r;
    int flag = 0;
    fin.open("EmployeeDB");
    fin.seekg(0, ios::beg);
    while (fin.read((char *)&r, sizeof(r))) {
        if (r.getIdno() == id) {
            flag = 1;
            break;
        }
    }

    fin.close();
    if (flag == 1) {
        cout << "\nRecord Found:";
        r.putData();
    }
    else
        cout << "\nRecord not Found ";
}

int File::Delete(int id) {
    Record r;
    int flag = 0;
    fin.open("EmployeeDB");
    fout.open("Temp", ios::ate | ios::app);
    fin.seekg(0, ios::beg);
    while (fin.read((char *)&r, sizeof(r))) {
        if (r.getIdno() == id) {
            flag = 1;
        }
        else {
            fout.write((char *)&r, sizeof(r));
        }
    }
    fin.close();
    fout.close();
    remove("EmployeeDB");
    rename("Temp", "EmployeeDB");
    return (flag);
}

int File::edit(int id) {
    Record r;
    int flag = 0;
    fs.open("EmployeeDB");
    fs.seekg(0, ios::beg);
    while (fs.read((char *)&r, sizeof(r))) {
        if (r.getIdno() == id) {
            flag = 1;
            cout << "\nEnter New Details: ";
            r.getData();
            fs.seekp((int)fs.tellg() - sizeof(r), ios::beg);
            fs.write((char *)&r, sizeof(r));
        }
    }
    fs.close();
    return (flag);
}

int main() {
    File f;
    int ch, n, i, flag = 0;
    do {
        cout << "\n\n\t-----M E N U-----";
        cout << "\n\n1. Build A Master Table";
        cout << "\n2. List A Table";
        cout << "\n3. Insert a New Entry";
        cout << "\n4. Delete Old Entry";
        cout << "\n5. Edit an Entry";
        cout << "\n6. Search for a Record";
        cout << "\n7. Quit";
        cout << "\nEnter your Choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                if (flag == 0) {
                    cout << "\nEnter No of Records to insert : ";
                    cin >> n;
                    for (i = 0; i < n; i++) {
                        f.insert();
                    }
                    flag = 1;
                }
                else {
                    cout << "\nSorry.. Table is Already build... \n If want to add record please select Insert a New Entry in option.....";
                }
                break;
            case 2:
                f.display();
                break;
            case 3:
                f.insert();
                break;
            case 4:
                cout << "\nEnter Id No of Employee Whose Record is to be Deleted: ";
                cin >> n;
                i = f.Delete(n);
                if (i == 1)
                    cout << "\nRecord Deleted Successfully";
                else
                    cout << "\nRecord not Found";
                break;
            case 5:
                cout << "\nEnter Id No of Employee Whose Record is to be Edit: ";
                cin >> n;
                i = f.edit(n);
                if (i == 1)
                    cout << "\nRecord Modified Successfully";
                else
                    cout << "\nRecord not Found";
                break;
            case 6:
                cout << "\nEnter Id No of Employee Whose Record is to be Searched: ";
                cin >> n;
                f.search(n);
                break;
            case 7:
                break;
            default:
                cout << "\nEnter Valid Choice.....";
        }
    } while (ch != 7);
    return (0);
}













// ALGORITHM :
// 1. Include necessary header files:
//  iostream: for input/output operations
//  fstream: for file operations
//  cstring: for string-related operations
// 2. Define Employee structure:
//  Define a structure named Employee with fields such as employeeID, name, designation, and
// salary.
// 3. Function Prototypes:
//  Declare function prototypes for addEmployee, deleteEmployee, and displayEmployee.
// 4. Main Function:
//  Open a file stream (fstream) with the name &quot;employee_data.dat&quot; for input, output, binary, and
// append operations.
//  Display a menu with options to add, delete, display employees, and exit.
// 5. Add Employee Function (addEmployee):
//  Create an Employee structure variable (emp).
//  Prompt the user to enter employee details (ID, name, designation, salary).
//  Check if the employee with the entered ID already exists in the file.
//  If yes, display a message and return.
//  If no, write the employee details to the file.
//  Display a success message.
// 6. Delete Employee Function (deleteEmployee):
//  Prompt the user to enter the employee ID to delete.
//  Create an Employee structure variable (emp).
//  Create a temporary file stream (fstream) named &quot;temp.dat&quot; for output and binary operations.
//  Read each employee record from the main file.
//  If the ID matches the one to be deleted, skip that record.
//  Otherwise, write the record to the temporary file.
//  Close both file streams.
//  Remove the original file and rename the temporary file to the original file name.
//  Display a success message.

// 7. Display Employee Function (displayEmployee):
//  Prompt the user to enter the employee ID to display.
//  Create an Employee structure variable (emp).
//  Read each employee record from the main file.
//  If the ID matches the one to be displayed, print the details and return.
//  If the ID is not found, display a message indicating that the employee was not found.
// 8. Repeat:
//  Continue displaying the menu and processing user input until the user chooses to exit.
// 9. Close File Stream:
//  Close the file stream before exiting the program.
