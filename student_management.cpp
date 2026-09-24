#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student
{
    int rollNo;
    string name;
    float marks;
};

void addStudent()
{
    Student s;

    cout << "\nEnter Roll Number: ";
    cin >> s.rollNo;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Marks: ";
    cin >> s.marks;

    ofstream file("students.txt", ios::app);

    file << s.rollNo << " "
         << s.name << " "
         << s.marks << endl;

    file.close();

    cout << "\nStudent added successfully!\n";
}

void displayStudents()
{
    Student s;

    ifstream file("students.txt");

    cout << "\n===== Student Records =====\n";

    while (file >> s.rollNo >> s.name >> s.marks)
    {
        cout << "Roll Number: " << s.rollNo << endl;
        cout << "Name: " << s.name << endl;
        cout << "Marks: " << s.marks << endl;
        cout << "--------------------------\n";
    }

    file.close();
}

void updateStudent()
{
    int roll;
    cout << "\nEnter Roll Number to update: ";
    cin >> roll;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    Student s;
    bool found = false;

    while (file >> s.rollNo >> s.name >> s.marks)
    {
        if (s.rollNo == roll)
        {
            cout << "Enter new name: ";
            cin >> s.name;

            cout << "Enter new marks: ";
            cin >> s.marks;

            found = true;
        }

        temp << s.rollNo << " "
             << s.name << " "
             << s.marks << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nStudent updated successfully!\n";
    else
        cout << "\nStudent not found!\n";
}

void deleteStudent()
{
    int roll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    Student s;
    bool found = false;

    while (file >> s.rollNo >> s.name >> s.marks)
    {
        if (s.rollNo == roll)
        {
            found = true;
            continue;
        }

        temp << s.rollNo << " "
             << s.name << " "
             << s.marks << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nStudent deleted successfully!\n";
    else
        cout << "\nStudent not found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n==============================\n";
        cout << "   STUDENT MANAGEMENT SYSTEM\n";
        cout << "==============================\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "==============================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                updateStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}