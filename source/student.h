#include <bits/stdc++.h>
using namespace std;
class Student {
   private:
    string name1, no, name2, name3, address, mobile;

   public:
    void student_login();
    void information();
    void studentAuth();
};

void Student::student_login() {
    int choice2;
    char x2;
menustart:
    // system("cls");
    fstream file;
    cout << "\n------------------------------------------------------------------------------------------";
    cout << "\n-------------------------------------STUDENT LOGIN------------------------------------------"<< endl;
    cout << "-------------------------------------------------------------------------------------------";
    cout << "\n\t\t\t\t 1.INFORMATION" << endl;
    cout << "\t\t\t\t 2.EXIT" << endl;
    cin >> choice2;
    switch (choice2) {
        case 1:
            studentAuth();
            break;
        case 2:
            exit(0);
        default:
            cout << "\t\t\t\t Please try again later" << endl;
            break;
    }
}

void Student::studentAuth() {
manustart:
    fstream file;
    string roll_no;
    int cnt = 3;
    bool check = false,flag = false;
    
    while (1) {
        if (!check){
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
            if(flag){
                char ch;
                cout << "\n\t\t\t You want to search agin:y/n"<<endl;
                cin>>ch;
                if(ch=='n' || ch =='N')break;
                else information();
            }else{
                information();
            }
            flag = true;
        } else {
            cout << "\n\t\t\t ID Not Pound";
            cnt--;
            if(cnt==0)break;
        }
    }
}

void Student::information() {
manustart:
    fstream file;
    int search = 1;
    file.open("studentRecord.txt", ios::in);
    if (!file) {
        cout << "\n--------------------------------------------------------------"
                "----------------------------";
        cout << "\n-------------------------------------INFORMATION--------------"
                "----------------------------"
             << endl;
        cout << "----------------------------------------------------------------"
                "---------------------------"
             << endl;
        cout << "\n\t\t\t DATA IS'NT AVAILABLE NOW..........";
    } else {
        string roll_no;
        cout << "\n--------------------------------------------------------------"
                "----------------------------";
        cout << "\n-------------------------------------INFORMATION--------------"
                "----------------------------"
             << endl;
        cout << "----------------------------------------------------------------"
                "---------------------------"
             << endl;
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
        cout  << "\t\t\t Not Found"<<endl;
    }
}
