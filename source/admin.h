#include <bits/stdc++.h>
using namespace std;
class Admin {
   private:
    string name1, no, name2, name3, address, mobile;

   public:
    void admin_login();
    void add_student();
    void remove_student();
    void student_record();
    void modify_student();
};

void Admin::admin_login() {
    int choice2;
    char x1;
menustart:
    // system("cls");
    fstream file;
    cout << "\n------------------------------------------------------------------"
            "------------------------";
    cout << "\n-------------------------------------ADMIN "
            "LOGIN------------------------------------------"
         << endl;
    cout << "--------------------------------------------------------------------"
            "-----------------------"
         << endl;
    cout << "\n\t\t\t\t 1.ADD NEW STUDENT" << endl;
    cout << "\t\t\t\t 2.STUDENT DISPLAY" << endl;
    cout << "\t\t\t\t 3.MODIFY STUDENT" << endl;
    cout << "\t\t\t\t 4.REMOVE STUDENT" << endl;
    cout << "\t\t\t\t 5.EXIT" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t CHOOSE OPTION[1,2,3]" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t ENTER YOUR OPTION: " << endl;
    cin >> choice2;

    switch (choice2) {
        case 1:

            do {
                add_student();
                cout << "\n\t\t\tadd another student record(Y<N add_student(Y,N): ";
                cin >> x1;
            } while (x1 == 'y' || x1 == 'Y');

            break;

        case 2:
            student_record();
            break;
        case 3:
            modify_student();
            break;
        case 4:
            remove_student();
            break;

        case 5:
            exit(0);

        default:
            cout << "\n\t\t\t\t Please try again later" << endl;
            break;
    }
}
void Admin::add_student() {
menustart:
    fstream file;
    cout << "\n------------------------------------------------------------------"
            "------------------------";
    cout << "\n-------------------------------------ADD NEW "
            "STUDENT------------------------------------------"
         << endl;
    cout << "--------------------------------------------------------------------"
            "-----------------------"
         << endl;
    cout << "\t\t ENTER NAME: " << endl;
    cin.ignore();
    getline(cin, name1);
    cout << "\t\t ROLL NO: " << endl;
    getline(cin, no);
    cout << "\t\t FATHERS NAME: " << endl;
    getline(cin, name2);
    cout << "\t\t MOTHERS NAME: " << endl;
    getline(cin, name3);
    cout << "\t\t EMAIL ADDRESS: " << endl;
    getline(cin, address);
    cout << "\t\t MOBILE NO: " << endl;
    getline(cin, mobile);
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name1 << " " << no << " " << name2 << " " << name3 << " "
         << address << " " << mobile << "\n";
    file.close();
}
void Admin::student_record() {
manustart:
    fstream file;
    int total = 1;
    cout << "\n------------------------------------------------------------------"
            "------------------------";
    cout << "\n-------------------------------------STUDENT "
            "RECORD------------------------------------------"
         << endl;
    cout << "--------------------------------------------------------------------"
            "-----------------------"
         << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\t NO DATA IS PRESENT....";
        file.close();
    } else {
        file >> name1 >> no >> name2 >> name3 >> address >> mobile;
        while (!file.eof()) {
            cout << "\t\t\t STUDENT NO: " << total++ << endl;
            cout << "\t\t\t STUDENT NAME: " << name1 << endl;
            cout << "\t\t\t STUDENT FATHERS NAME: " << name2 << endl;
            cout << "\t\t\t STUDENT MOTHERS NAME: " << name3 << endl;
            cout << "\t\t\t STUDENT EMAIL ADDRESS: " << address << endl;
            cout << "\t\t\t STUDENT MOBILE NO: " << mobile << endl;
            file >> name1 >> no >> name2 >> name3 >> address >> mobile;
        }
        if (total == 0) {
            cout << "\n\t\t\t NO DATA IS PRESENT....";
        }
    }
    file.close();
}

void Admin::modify_student() {
menustart:
    // system("cls");
    fstream file, file1;
    int found = 0;
    string roll_no;
    cout << "\n------------------------------------------------------------------"
            "------------------------";
    cout << "\n-------------------------------------MODIFY "
            "STUDENT------------------------------------------"
         << endl;
    cout << "\n------------------------------------------------------------------"
            "-------------------------";
    file.open("studentRecord.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\t NO DATA IS PRESENT....";
        file.close();
    } else {
        cout << "\n Enter ROll NO Of Student  You Want to Modify: ";
        cin >> roll_no;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name1 >> no >> name2 >> name3 >> address >> mobile;
        while (!file.eof()) {
            if (roll_no != no) {
                file1 << " " << name1 << " " << no << " " << name2 << " " << name3
                      << " " << address << " " << mobile << "\n";
            } else {
                cout << "\t\t ENTER NAME: " << endl;
                cin.ignore();
                getline(cin, name1);
                cout << "\t\t ROLL NO: " << endl;
                getline(cin, no);
                cout << "\t\t FATHERS NAME: " << endl;
                getline(cin, name2);
                cout << "\t\t MOTHERS NAME: " << endl;
                getline(cin, name3);
                cout << "\t\t EMAIL ADDRESS: " << endl;
                getline(cin, address);
                cout << "\t\t MOBILE NO: " << endl;
                getline(cin, mobile);
                file1 << " " << name1 << " " << no << " " << name2 << " " << name3
                      << " " << address << " " << mobile << "\n";
                found++;
            }
            file >> name1 >> no >> name2 >> name3 >> address >> mobile;
        }
        if (found == 0) {
            cout << "\n\t\t\t Student Roll No Not Found..........";
        }
    }
    file1.close();
    file.close();
    remove("studentRecord.txt");
    rename("Record.txt", "studentRecord.txt");
}
void Admin::remove_student() {
manustart:
    fstream file, file1;
    string roll_no1;
    int found = 0;
    cout << "\n------------------------------------------------------------------"
            "------------------------";
    cout << "\n-------------------------------------REMOVE "
            "STUDENT------------------------------------------"
         << endl;
    cout << "--------------------------------------------------------------------"
            "-----------------------"
         << endl;
    file.open("studentRecord.txt", ios::app | ios::out);
    if (!file) {
        cout << "\n\t\t\t NO Data Is Present.........";
    } else {
        cout << "\n\t\t\t Enter Roll No. Of Student you want to remove";
        cin >> roll_no1;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name1 >> no >> name2 >> name3 >> address >> mobile;
        while (!file.eof()) {
            if (roll_no1 != no) {
                file1 << " " << name1 << " " << no << " " << name2 << " " << name3
                      << " " << address << " " << mobile << "\n";
            }
            file >> name1 >> no >> name2 >> name3 >> address >> mobile;
        }
        if (found == 0) {
            cout << "\n\t\t\t Student Roll No Not Found..........";
        }

        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("Record.txt", "studentRecord.txt");
    }
}