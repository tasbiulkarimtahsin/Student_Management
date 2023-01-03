#include <bits/stdc++.h>
using namespace std;
class Student {
   private:
    string name1, no, name2, name3, address, mobile;
    string roll, result1, result2, result3, result4, result5, result6;

   public:
    void student_login();
    void information();
    void result_view();
    void studentAuth();
};

void Student::student_login() {
    int choice2;
    char x2;
menustart:
    // system("cls");
    fstream file;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------STUDENT LOGIN------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------";
    cout << "\n\t\t\t\t 1.INFORMATION" << endl;
    cout << "\t\t\t\t 2.RESULT VIEW" << endl;
    cout << "\t\t\t\t 3.EXIT" << endl;
    cin >> choice2;
    switch (choice2) {
        case 1:
            studentAuth();
            break;
        case 2:
            result_view();
        case 3:
            exit(0);
        default:
            cout << "\t\t\t\t Please try again later" << endl;
            break;
    }
}
void Student::result_view() {
manustart:
    fstream file;
    int total = 1;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------RESULT DISPLAY------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------"
         << endl;

    cout << "\t\t Enter Roll: " << endl;
    string roll_in;
    cin >> roll_in;

    file.open("res.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\t NO DATA IS PRESENT....";
        file.close();
    } else {
        file >> roll >> result1 >> result2 >> result3 >> result4 >> result5 >> result6;
        while (!file.eof()) {
            if (roll == roll_in) {
                cout << "\t\t\t STUDENT SERIAL NO: " << total++ << endl;
                cout << "\t\t\t StudentT Roll: " << roll << endl;
                if (roll_in[0] == 'c') {
                    cout << "\t\t\t Computer Scienence & Engennering: " << result1 << endl;
                    cout << "\t\t\t Compitive Programing 1: " << result2 << endl;
                    cout << "\t\t\t Software Devlopment: " << result3 << endl;
                    cout << "\t\t\t Engennering Drawing: " << result4 << endl;
                    cout << "\t\t\t Data Sturcture: " << result5 << endl;
                    cout << "\t\t\t Theory of computing: " << result6 << endl
                         << endl;
                } else if (roll_in[0] == 'e') {
                    cout << "\t\t\t Computer Scienence & Engennering: " << result1 << endl;
                    cout << "\t\t\t Electrical Circuits I: " << result2 << endl;
                    cout << "\t\t\t Electrical Circuits I Sessional: " << result3 << endl;
                    cout << "\t\t\t Mathematics I: " << result4 << endl;
                    cout << "\t\t\t Physics I: " << result5 << endl;
                    cout << "\t\t\t Advanced English: " << result6 << endl
                         << endl;
                } else {
                    cout << "\t\t\t URED: " << result1 << endl;
                    cout << "\t\t\t Advanced English: " << result2 << endl;
                    cout << "\t\t\t Basic Accounting: " << result3 << endl;
                    cout << "\t\t\t Fundamentals of Management: " << result4 << endl;
                    cout << "\t\t\t Introduction to Business: " << result5 << endl;
                    cout << "\t\t\t Foundation of Mathematics: " << result6 << endl
                         << endl;
                }
            }
            file >> roll >> result1 >> result2 >> result3 >> result4 >> result5 >> result6;
        }
        if (total == 0) {
            cout << "\n\t\t\t NO DATA IS PRESENT....";
        }
    }
    file.close();
}

void Student::studentAuth() {
manustart:
    fstream file;
    string roll_no;
    int cnt = 3;
    bool check = false, flag = false;

    while (1) {
        if (!check) {
            file.open("studentRecord.txt", ios::in);
            cout << "\n\t\t\t You Have " << cnt << endl;
            cout << "\n\t\t\t PLEASE ENTER YOUR ROLL NO: ";
            cin >> roll_no;
            file >> name1 >> no >> name2 >> name3 >> address >> mobile;

            while (!file.eof()) {
                if (roll_no == no) {
                    check = true;
                    break;
                }
                file >> name1 >> no >> name2 >> name3 >> address >> mobile;
            }
            file.close();
        }
        if (check) {
            if (flag) {
                char ch;
                cout << "\n\t\t\t You want to search agin:y/n" << endl;
                cin >> ch;
                if (ch == 'n' || ch == 'N')
                    break;
                else
                    information();
            } else {
                information();
            }
            flag = true;
        } else {
            cout << "\n\t\t\t ID Not Pound";
            cnt--;
            if (cnt == 0)
                break;
        }
    }
}

void Student::information() {
manustart:
    fstream file;
    int search = 1;
    file.open("studentRecord.txt", ios::in);
    if (!file) {
        cout << "\n------------------------------------------------------------------------------------------";
        cout << "\n-------------------------------------INFORMATION------------------------------------------" << endl;
        cout << "-------------------------------------------------------------------------------------------" << endl;
        cout << "\n\t\t\t DATA IS'NT AVAILABLE NOW..........";
    } else {
        string roll_no;
        cout << "\n------------------------------------------------------------------------------------------";
        cout << "\n-------------------------------------INFORMATION---------------------------------------" << endl;
        cout << "-------------------------------------------------------------------------------------------" << endl;
        cout << "\n\t\t\t PLEASE ENTER ROLL NO: ";
        cin >> roll_no;
        while (!file.eof()) {
            file >> name1 >> no >> name2 >> name3 >> address >> mobile;
            if (roll_no == no) {
                cout << "\t\t\t STUDENT NAME: " << name1 << endl;
                cout << "\t\t\t STUDENT ROLL NO: " << no << endl;
                cout << "\t\t\t STUDENT FATHERS NAME: " << name2 << endl;
                cout << "\t\t\t STUDENT MOTHERS NAME: " << name3 << endl;
                cout << "\t\t\t STUDENT EMAIL ADDRESS: " << address << endl;
                cout << "\t\t\t STUDENT MOBILE NO: " << mobile << endl;
                search++;
                return;
            }
        }
        cout << "\t\t\t Not Found" << endl;
    }
}
