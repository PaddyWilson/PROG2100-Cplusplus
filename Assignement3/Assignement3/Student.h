#include <string>

using namespace std;

class Student
{
private:
	string name;
	int numCourses;
	string *courseList;// = string[];

public:
	Student();//default
	Student(const Student& studentIn);//copy
	~Student();//destructor

	void getValuesForEverything(string name, string *courseList, int numCourses);
	void reset();
	void resetCourses();
	void displayStudent();

	friend ostream& operator<<(ostream& output, Student& studentIn);
	Student operator=(Student& studentIn);

	//getter setter
	string getName();
	void setName(string name);

	int getNumCourses();
	void setNumCourses(int numCourses);

	string getCourseList();
	void setCourseList(string *courseList);
};