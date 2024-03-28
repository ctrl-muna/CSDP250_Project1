//class function file
#include <iostream>
#include <string>
#include "CourseList.h"

using namespace std;

CourseList::CourseList() {
	head = nullptr;
}

CourseList::~CourseList(){
	deleteAllNodes();
}

void CourseList::insertNode(string code, int cred, int points){
	//Step 1: Create a new node
	CourseNode* nodePtr;//transverse list
	CourseNode* prevNode; //transverse list one step behind
	CourseNode* newNode = new CourseNode;
	newNode->courseCode = code;
	newNode->credit = cred;
	newNode->grade = points;
	newNode->next = nullptr;

	//Step 2: Insert
	if (!head) { // Case 1: List is empty
		head = newNode;
	}
	else { //Case 2: List is not empty
		nodePtr = head;
		prevNode = nullptr;
		while (nodePtr && extractCourseNum(nodePtr->courseCode) < extractCourseNum(code)) {
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (!prevNode) { // if insert a new node before head
			newNode->next = head;
			head = newNode;
		}
		else {
			prevNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

void CourseList::deleteNode(string code) {
	CourseNode* prevNode = nullptr;
	CourseNode* nodePtr = head;

	if (!head) { //Case 1: if the list is empty
		cout << "There is nothing to delete"<<endl;
		return;
	}

	if (head->courseCode == code) { //Case 2: if the course is in the head node
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}else{//Case 3: if the course is not in the head node
		while (nodePtr && nodePtr->courseCode != code) {
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (!nodePtr) {// Node with the code not found
			cout << "Course not found in the list." << endl;
			return;
		}

		if (nodePtr != nullptr) {
			prevNode->next = nodePtr->next;
		}

		delete nodePtr;
	}
}

void CourseList::displayNode()const {
	CourseNode* nodePtr = head;

	while (nodePtr != nullptr) {
		cout << "Student ID: " << nodePtr->courseCode << "\t";
		cout << "Grade: " << nodePtr->grade << endl;
		nodePtr = nodePtr->next;
	}
}

void CourseList::deleteAllNodes() {
	CourseNode* nodePtr = head;
	while (nodePtr != nullptr) {
		CourseNode* temp = nodePtr;
		nodePtr = nodePtr->next;
		delete temp;
	}
	head = nullptr;//resets the list to nullptr
}

int CourseList::extractCourseNum(string code) {
	string numStr = "";
	for (char c : code) {
		if (isdigit(c)) {//check each character to see if it is a number
			numStr += c;
		}
	}
	if (!numStr.empty()) {
		return stoi(numStr);//returns int number
	}
	else {
		return -1;
	}
}
