//main function file
#include <iostream>
#include <string>
#include "CourseList.h"

using namespace std;

int main()
{
	CourseList List;
    string code;
    int hours, grade;
    for (int i = 0; i < 10; i++) {
        cout << "Enter course code: ";
        getline(cin,code);
        cout << "Enter credit hours: ";
        cin >> hours;
        cout << "Enter grade: ";
        cin >> grade;
        cin.ignore();
        List.insertNode(code, hours, grade);
    }

    // Display the list before the deletion process starts
    cout << "List before deletion:" << endl;
    List.displayNode();

    // Delete two courses and display the list after each deletion
    //Deletion 1
    cout << "Enter course code to delete: ";
    getline(cin,code);
    List.deleteNode(code);
    cout << "List after first deletion: " << endl;
    List.displayNode();


    //Deletion 2
    cout << "Enter course code to delete: ";
    getline(cin,code);
    List.deleteNode(code);
    cout << "List after second deletion:" << endl;
    List.displayNode();

	return 0;
}