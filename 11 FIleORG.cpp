#include <iostream>
#include <fstream>
using namespace std;

class Record {
    int rollno;
    string name;
    int division;
    string address;

public:
    Record();
    int getRollno();
    void getData();
    void putData();
};

Record::Record() {
    rollno = 0;
    name = ' ';
    address = ' ';
    division = 0;
}

int Record::getRollno() {
    return (rollno);
}

void Record::getData() {
    cout << "\nEnter Details: ";
    cout << "\nRoll no: ";
    cin >> rollno;
    cout << "Name: ";
    cin >> name;
    cout << "Division Code: ";
    cin >> division;
    cout << "Address: ";
    cin >> address;
}

void Record::putData() {
    cout << "\nRoll No.: ";
    cout << rollno;
    cout << "\t\tName: ";
    cout << name;
    cout << "\nDivision Code: ";
    cout << division;
    cout << "\tAddress: ";
    cout << address;
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
    fout.open("StudentDB", ios::ate | ios::app);
    fout.write((char *)&r, sizeof(r));
    fout.close();
}

void File::display() {
    Record r;
    fin.open("StudentDB");
    fin.seekg(0, ios::beg);
    while (fin.read((char *)&r, sizeof(r)))
        r.putData();

    fin.close();
}

void File::search(int rollno) {
    Record r;
    int flag = 0;
    fin.open("StudentDB");
    fin.seekg(0, ios::beg);
    while (fin.read((char *)&r, sizeof(r))) {
        if (r.getRollno() == rollno) {
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

int File::Delete(int rollno) {
    Record r;
    int flag = 0;
    fin.open("StudentDB");
    fout.open("Temp", ios::ate | ios::app);
    fin.seekg(0, ios::beg);
    while (fin.read((char *)&r, sizeof(r))) {
        if (r.getRollno() == rollno) {
            flag = 1;
        }
        else {
            fout.write((char *)&r, sizeof(r));
        }
    }
    fin.close();
    fout.close();
    remove("StudentDB");
    rename("Temp", "StudentDB");
    return (flag);
}

int File::edit(int rollno) {
    Record r;
    int flag = 0;
    fs.open("StudentDB");
    fs.seekg(0, ios::beg);
    while (fs.read((char *)&r, sizeof(r))) {
        if (r.getRollno() == rollno) {
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
                cout << "\nEnter Roll No of Student Whose Record is to be Deleted: ";
                cin >> n;
                i = f.Delete(n);
                if (i == 1)
                    cout << "\nRecord Deleted Successfully";
                else
                    cout << "\nRecord not Found";
                break;
            case 5:
                cout << "\nEnter Roll No of Student Whose Record is to be Edit: ";
                cin >> n;
                i = f.edit(n);
                if (i == 1)
                    cout << "\nRecord Modified Successfully";
                else
                    cout << "\nRecord not Found";
                break;
            case 6:
                cout << "\nEnter Roll No of Student Whose Record is to be Searched: ";
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







// ALGORITHM:
// Algorithm: Student Information System
// 1. Define Student Structure
//  Create a structure named Student with members rollNo, name, division, and address.
// 2. Function to Add a Student
//  Open the file &quot;students.dat&quot; in append mode.
//  Read student details (roll number, name, division, address) from the user.
//  Write the student structure to the file.
//  Close the file.
//  Print a success message.
// 3. Function to Delete a Student
//  Open the file &quot;students.dat&quot; for reading and create a temporary file &quot;temp.dat&quot; for writing.
//  Read the roll number to delete from the user.
//  Traverse through the file and copy records to &quot;temp.dat&quot; excluding the one to be deleted.
//  Close both files.
//  Delete the original file and rename &quot;temp.dat&quot; to &quot;students.dat&quot;.
//  Print a success message if the student is found, else print a message indicating the student was
// not found.
// 4. Function to Display Student Information
//  Open the file &quot;students.dat&quot; for reading.
//  Read the roll number to display from the user.
//  Traverse through the file and print details if the roll number matches.
//  Close the file.
//  Print a message indicating whether the student was found or not.
// 5. Main Function
//  Initialize a variable choice to 0.
//  Start a do-while loop until the user chooses to exit.
//  Display a menu with options to add, delete, display, or exit.
//  Read the user&#39;s choice.
//  Execute the corresponding function based on the choice.
//  Repeat until the user chooses to exit.
// 6. Detailed Steps:
// 1. Start the program by initializing the choice variable to 0.
// 2. Enter a do-while loop to display the menu until the user chooses to exit.
// 3. Display the menu options:
// 1. Add Student
// 2. Delete Student
// 3. Display Student Information
// 4. Exit
// 4. Read the user&#39;s choice.
// 5. Execute the corresponding function based on the choice:
// a. Case 1: Add a student using the addStudent function.
//      Case 2: Delete a student using the deleteStudent function.
//  Case 3: Display student information using the displayStudent function.
//  Case 4: Print an exit message and end the loop.
//  Default: Print an invalid choice message.
// 6. Repeat the loop until the user chooses to exit.
// 7. End of the algorithm.
