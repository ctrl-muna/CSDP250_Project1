#ifndef CourseList_h
#define CourseList_h

#include <stdio.h>
#include <string>

using namespace std;

class CourseList{
private:
	struct CourseNode {
		string courseCode;
		int credit;
		int grade;
		CourseNode* next;
	};
	CourseNode* head;

public:
	CourseList();
	~CourseList();

	void insertNode(string,int,int);
	void deleteNode(string);
	void displayNode()const;
	void deleteAllNodes();
	int extractCourseNum(string);
};

#endif
