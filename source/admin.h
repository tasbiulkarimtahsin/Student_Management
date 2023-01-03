#include <bits/stdc++.h>
using namespace std;
class Admin {
   private:
    string name1, no, name2, name3, address, mobile;
    string roll, result1, result2, result3, result4, result5, result6;

   public:
    void adminAuth();
    void admin_login();
    void admin_workspace();
    void faculty_workspace();
    void add_student();
    void remove_student();
    void student_record();
    void modify_student();
    void cse();
    void eee();
    void bba();
    void add_result_cse();
    void add_result_eee();
    void add_result_bba();
    void display_result_cse();
    void display_result_eee();
    void display_result_bba();
};

void Admin::adminAuth() {
manustart:
    string pass;
    while (1) {
        cout << "\t\t\t\t Enter your password: ";
        cin >> pass;
        if (pass == "admin") {
            admin_login();
        } else {
            cout << "\n\t\t\t Try Again :(   : y/n" << endl;
            char ch;
            cin >> ch;
            if (ch == 'n' || ch == 'N')
                break;
        }
    }
}
void Admin::admin_login() {
manustart:
    int choice;
    char x;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------ADMIN LOGIN------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "\n\t\t\t\t 1.ADMIN WORKSPACE" << endl;
    cout << "\t\t\t\t 2.FACULTY VIEW" << endl;
    cout << "\t\t\t\t 3.EXIT" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t CHOOSE OPTION BETWEEN[1,2,3]" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t ENTER YOUR OPTION: " << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            admin_workspace();
            break;

        case 2:
            faculty_workspace();
            break;

        case 3:
            exit(0);

        default:
            cout << "\n\t\t\t\t Please try again later" << endl;
            break;
    }
}

void Admin::admin_workspace() {
    int choice2;
    char x1;
menustart:
    // system("cls");
    fstream file;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------ADMIN WORKSPACE------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "\n\t\t\t\t 1.ADD NEW STUDENT" << endl;
    cout << "\t\t\t\t 2.STUDENT DISPLAY" << endl;
    cout << "\t\t\t\t 3.MODIFY STUDENT" << endl;
    cout << "\t\t\t\t 4.REMOVE STUDENT" << endl;
    cout << "\t\t\t\t 5.EXIT" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t CHOOSE OPTION[1,2,3,4,5]" << endl;
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
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------ADD NEW STUDENT------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
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
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------STUDENT RECORD------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------"
         << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\t NO DATA IS PRESENT....";
        file.close();
    } else {
        file >> name1 >> no >> name2 >> name3 >> address >> mobile;
        while (!file.eof()) {
            cout << "\t\t\t STUDENT SERIAL NO: " << total++ << endl;
            cout << "\t\t\t STUDENT NAME: " << name1 << endl;
            cout << "\t\t\t STUDENT ID NO: " << no << endl;
            cout << "\t\t\t STUDENT FATHERS NAME: " << name2 << endl;
            cout << "\t\t\t STUDENT MOTHERS NAME: " << name3 << endl;
            cout << "\t\t\t STUDENT EMAIL ADDRESS: " << address << endl;
            cout << "\t\t\t STUDENT MOBILE NO: " << mobile << endl
                 << endl;
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
    cout << "\n-------------------------------------MODIFY STUDENT------------------------------------------" << endl;
    cout << "\n-------------------------------------------------------------------------------------------";
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
                file1 << " " << name1 << " " << no << " " << name2 << " " << name3 << " " << address << " " << mobile << "\n";
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
                file1 << " " << name1 << " " << no << " " << name2 << " " << name3 << " " << address << " " << mobile << "\n";
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
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------REMOVE STUDENT------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\t NO Data Is Present.........";
    } else {
        cout << "\n\t\t\t Enter Roll No. Of Student you want to remove: ";
        cin >> roll_no1;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name1 >> no >> name2 >> name3 >> address >> mobile;
        while (!file.eof()) {
            if (roll_no1 != no) {
                file1 << " " << name1 << " " << no << " " << name2 << " " << name3 << " " << address << " " << mobile << "\n";
            } else {
                found++;
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
void Admin::faculty_workspace() {
manustart:
    int choice3;
    char x;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------FACULTY  WORKSPACE------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "\n\t\t\t\t 1.Dept of CSE" << endl;
    cout << "\t\t\t\t 2.Dept of EEE" << endl;
    cout << "\t\t\t\t 3.Dept of BBA" << endl;
    cout << "\t\t\t\t 4.exit" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t CHOOSE OPTION BETWEEN[1,2,3,4]" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t ENTER YOUR OPTION: " << endl;
    cin >> choice3;

    switch (choice3) {
        case 1:
            cse();
            break;

        case 2:
            eee();
            break;

        case 3:
            bba();
            break;
        case 4:
            exit(0);

        default:
            cout << "\n\t\t\t\t Please try again later" << endl;
            break;
    }
}
void Admin::cse() {
manustart:
    int choice4;
    char x2;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------|Dept of CSE|------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "\n\t\t\t\t 1.add result" << endl;
    cout << "\t\t\t\t 2.display result" << endl;
    cout << "\t\t\t\t 3.exit" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t CHOOSE OPTION BETWEEN[1,2,3]" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t ENTER YOUR OPTION: " << endl;
    cin >> choice4;
    switch (choice4) {
        case 1:

            do {
                add_result_cse();
                cout << "\n\t\t\tadd another student result cse(Y<N add_result_cse(Y,N): ";
                cin >> x2;
            } while (x2 == 'y' || x2 == 'Y');

            break;

        case 2:
            display_result_cse();
            break;
        case 3:
            exit(0);

        default:
            cout << "\n\t\t\t\t Please try again later" << endl;
            break;
    }
}
void Admin::add_result_cse() {
menustart:
    fstream file_cse;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------RESULT PANALE CSE------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t Enter Roll: " << endl;
    cin.ignore();
    getline(cin, roll);
    cout << "\t\t Computer Scienence & Engennering: " << endl;
    getline(cin, result1);
    cout << "\t\t Compitive Programing 1: " << endl;
    getline(cin, result2);
    cout << "\t\t Software Devlopment: " << endl;
    getline(cin, result3);
    cout << "\t\t Engennering Drawing " << endl;
    getline(cin, result4);
    cout << "\t\t Data Sturcture " << endl;
    getline(cin, result5);
    cout << "\t\t Theory of computing: " << endl;
    getline(cin, result6);
    file_cse.open("res.txt", ios::app | ios::out);
    file_cse << " " << roll << " " << result1 << " " << result2 << " " << result3 << " " << result4 << " "
             << result5 << " " << result6 << "\n";
    file_cse.close();
}

void Admin::display_result_cse() {
manustart:
    fstream file_cse;
    int total = 1;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------RESULT DISPLAY CSE------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------"
         << endl;

    cout << "\t\t Enter Roll: " << endl;
    string roll_in;
    cin >> roll_in;

    file_cse.open("res.txt", ios::in);
    if (!file_cse) {
        cout << "\n\t\t\t NO DATA IS PRESENT....";
        file_cse.close();
    } else {
        file_cse >> roll >> result1 >> result2 >> result3 >> result4 >> result5 >> result6;
        while (!file_cse.eof()) {
            if (roll == roll_in) {
                cout << "\t\t\t STUDENT SERIAL NO: " << total++ << endl;
                cout << "\t\t\t StudentT Roll: " << roll << endl;
                cout << "\t\t\t Computer Scienence & Engennering: " << result1 << endl;
                cout << "\t\t\t Compitive Programing 1: " << result2 << endl;
                cout << "\t\t\t Software Devlopment: " << result3 << endl;
                cout << "\t\t\t Engennering Drawing: " << result4 << endl;
                cout << "\t\t\t Data Sturcture: " << result5 << endl;
                cout << "\t\t\t Theory of computing: " << result6 << endl
                     << endl;
                exit;
            }
            file_cse >> roll >> result1 >> result2 >> result3 >> result4 >> result5 >> result6;
        }
        if (total == 0) {
            cout << "\n\t\t\t NO DATA IS PRESENT....";
        }
    }
    file_cse.close();
}

void Admin::eee() {
manustart:
    int choice5;
    char x3;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------|Dept of EEE|------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "\n\t\t\t\t 1.add result" << endl;
    cout << "\t\t\t\t 2.display result" << endl;
    cout << "\t\t\t\t 3.exit" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t CHOOSE OPTION BETWEEN[1,2,3]" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t ENTER YOUR OPTION: " << endl;
    cin >> choice5;

    switch (choice5) {
        case 1:
            do {
                add_result_eee();
                cout << "\n\t\t\tadd another student result eee(Y<N add_result_eee(Y,N): ";
                cin >> x3;
            } while (x3 == 'y' || x3 == 'Y');
            break;

        case 2:
            display_result_eee();
            break;
        case 3:
            exit(0);

        default:
            cout << "\n\t\t\t\t Please try again later" << endl;
            break;
    }
}
void Admin::add_result_eee() {
menustart:
    fstream file_eee;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------RESULT PANALE EEE------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t Enter Roll: " << endl;
    cin.ignore();
    getline(cin, roll);
    cout << "\t\t Computer Scienence & Engennering: " << endl;
    getline(cin, result1);
    cout << "\t\t Electrical Circuits I " << endl;
    getline(cin, result2);
    cout << "\t\t Electrical Circuits I Sessional: " << endl;
    getline(cin, result3);
    cout << "\t\t Mathematics I " << endl;
    getline(cin, result4);
    cout << "\t\t Physics I " << endl;
    getline(cin, result5);
    cout << "\t\t Advanced English: " << endl;
    getline(cin, result6);
    file_eee.open("res.txt", ios::app | ios::out);
    file_eee << " " << roll << " " << result1 << " " << result2 << " " << result3 << " " << result4 << " "
             << result5 << " " << result6 << "\n";
    file_eee.close();
}
void Admin::display_result_eee() {
manustart:
    fstream file_eee;
    int total = 1;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------RESULT DISPLAY EEE------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------"
         << endl;

    cout << "\t\t Enter Roll: " << endl;
    string roll_in;
    cin >> roll_in;

    file_eee.open("res.txt", ios::in);
    if (!file_eee) {
        cout << "\n\t\t\t NO DATA IS PRESENT....";
        file_eee.close();
    } else {
        file_eee >> roll_in >> result1 >> result2 >> result3 >> result4 >> result5 >> result6;
        while (!file_eee.eof()) {
            if (roll == roll_in) {
                cout << "\t\t\t STUDENT SERIAL NO: " << total++ << endl;
                cout << "\t\t\t StudentT Roll: " << roll << endl;
                cout << "\t\t\t Computer Scienence & Engennering: " << result1 << endl;
                cout << "\t\t\t Electrical Circuits I: " << result2 << endl;
                cout << "\t\t\t Electrical Circuits I Sessional: " << result3 << endl;
                cout << "\t\t\t Mathematics I: " << result4 << endl;
                cout << "\t\t\t Physics I: " << result5 << endl;
                cout << "\t\t\t Advanced English: " << result6 << endl
                     << endl;
            }
            file_eee >> roll_in >> result1 >> result2 >> result3 >> result4 >> result5 >> result6;
        }
        if (total == 0) {
            cout << "\n\t\t\t NO DATA IS PRESENT....";
        }
    }
    file_eee.close();
}
void Admin::bba() {
manustart:
    int choice6;
    char x4;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------|Dept of BBA|------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "\n\t\t\t\t 1.add result" << endl;
    cout << "\t\t\t\t 2.display result" << endl;
    cout << "\t\t\t\t 3.exit" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t CHOOSE OPTION BETWEEN[1,2,3]" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t ENTER YOUR OPTION: " << endl;
    cin >> choice6;

    switch (choice6) {
        case 1:
            do {
                add_result_bba();
                cout << "\n\t\t\tadd another student result bba(Y<N add_result_bba(Y,N): ";
                cin >> x4;
            } while (x4 == 'y' || x4 == 'Y');

            break;

        case 2:
            display_result_bba();
            break;
        case 3:
            exit(0);

        default:
            cout << "\n\t\t\t\t Please try again later" << endl;
            break;
    }
}
void Admin::add_result_bba() {
menustart:
    fstream file_bba;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------RESULT PANALE BBA------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;

    cout << "\t\t Enter Roll: " << endl;
    cin.ignore();
    getline(cin, roll);
    cout << "\t\t Computer Scienence & Engennering: " << endl;
    getline(cin, result1);
    cout << "\t\t Advanced English: " << endl;
    getline(cin, result2);
    cout << "\t\t Basic Accounting: " << endl;
    getline(cin, result3);
    cout << "\t\t Fundamentals of Management " << endl;
    getline(cin, result4);
    cout << "\t\t Introduction to Business " << endl;
    getline(cin, result5);
    cout << "\t\t Foundation of Mathematics " << endl;
    getline(cin, result6);
    file_bba.open("res.txt", ios::app | ios::out);
    file_bba << " " << roll << " " << result1 << " " << result2 << " " << result3 << " " << result4 << " "
             << result5 << " " << result6 << "\n";
    file_bba.close();
}
void Admin::display_result_bba() {
manustart:
    fstream file_bba;
    int total = 1;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------RESULT DISPLAY BBA------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------"
         << endl;

    cout << "\t\t Enter Roll: " << endl;
    string roll_in;
    cin >> roll_in;

    file_bba.open("res.txt", ios::in);
    if (!file_bba) {
        cout << "\n\t\t\t NO DATA IS PRESENT....";
        file_bba.close();
    } else {
        file_bba >> roll >> result1 >> result2 >> result3 >> result4 >> result5 >> result6;
        while (!file_bba.eof()) {
            if (roll == roll_in) {
                cout << "\t\t\t STUDENT SERIAL NO: " << total++ << endl;
                cout << "\t\t\t StudentT Roll: " << roll << endl;
                cout << "\t\t\t URED: " << result1 << endl;
                cout << "\t\t\t Advanced English: " << result2 << endl;
                cout << "\t\t\t Basic Accounting: " << result3 << endl;
                cout << "\t\t\t Fundamentals of Management: " << result4 << endl;
                cout << "\t\t\t Introduction to Business: " << result5 << endl;
                cout << "\t\t\t Foundation of Mathematics: " << result6 << endl
                     << endl;
            }
            file_bba >> roll >> result1 >> result2 >> result3 >> result4 >> result5 >> result6;
        }
        if (total == 0) {
            cout << "\n\t\t\t NO DATA IS PRESENT....";
        }
    }
    file_bba.close();
}
