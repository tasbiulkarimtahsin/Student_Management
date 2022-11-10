#include <bits/stdc++.h>

#include "./admin.h"
#include "./student.h"
using namespace std;

void menu() {
    int choice1;
    char x;
menustart:
    cout << "\t\t\t\t**********" << endl;
    cout << "\t\t\t\t**********" << endl;
    cout << "\t\t\t\t|| Student Management System ||" << endl;
    cout << "\t\t\t\t**********" << endl;
    cout << "\t\t\t\t**********" << endl;

    cout << "\t\t\t\t 1. ADMIN LOGIN" << endl;
    cout << "\t\t\t\t 2. STUDENT LOGIN" << endl;
    cout << "\t\t\t\t 3. EXIT" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t CHOOSE OPTION[1,2,3]" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\t ENTER YOUR OPTION: " << endl;
    cin >> choice1;
    Admin admin;
    Student student;
    switch (choice1) {
        case 1:
            admin.admin_login();
            break;
        case 2:
            student.student_login();
            break;
        case 3:
            exit(0);

        default:
            cout << "\n\t\t\t\t Please try again later" << endl;
            break;
    }
}