Project description: A C++ program to record the courses a student has taken by far in his
bachelor program, offering basic functionality to manage the list of courses..


Input Data: For each course, a course code, grade, and credit hours are required. To delete a node, a course code input is needed


Output result: Displays the courses and their information before and after each deletion
  
  
  
  



Procedures you run the program: The class CourseList manages a linked list of courses, where each course is represented by a CourseNode.
The CourseNode struct contains information about a course, including the course code, credit hours, grade, and a pointer to the next node (next).
The constructor CourseList() initializes the head pointer to nullptr, indicating an empty list.
The destructor ~CourseList() is responsible for deleting all nodes in the list when the object is destroyed.


The insertNode() function adds a new course node to the linked list based on the course code.
The deleteNode() function removes a course node from the list based on the specified course code.


The displayNode() function traverses the list and displays the information (course code and grade) of each course node.


The deleteAllNodes() function deletes all nodes in the list by traversing the list and freeing the memory allocated for each node.


Main Function: The user inputs details of 10 courses, including course code, credit hours, and grade, and these courses are inserted into the linked list.
After inserting the courses, the list is displayed.
The user then deletes 2 courses from the list based on the course code, and the list is displayed after each deletion.