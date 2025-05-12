#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<limits>
#include<fstream>
#include <iomanip>
#include <ctype.h>
#include <conio.h>
using namespace std;
struct 	Schedule {
	string dayOfWeek;
	string place;
	string startTime;
	string endTime;
};
struct Course {
	int courseID;
	string title;
	string instructor;
	Schedule coursesSchedule;
	int numStudents;
};
struct Student
{
	int studentID;
	string name;
	int age;
	string major;
	int enrolledCoursesnum;
	vector<Course>enrolledCourses;
	string username;
	string password;
};
struct Instructor {
	int instructorID;
	string name;
	string department;
	int age;
	string username;
	string password;
};
struct Grade
{
	int gradeID;
	int courseID;
	int studentID;
	int score;
};
int instructorcounter = 0;
int coursesCounter = 0;
int StudentsCounter = 0;
int gradesCounter = 0;
int constinstructorid;
int conststudentid;
//===============================
//Menus
void MainMenu();
void AdminMenu();
void StudentMenu();
//===============================
//Login functions
void LoginAsAdmin();
void LoginAsStudent();
void logout();
//===============================
//MainFunctions
void AddCourse();
void RemoveCourse();
void AddStudent();
void RemoveStudent();
void addGrade();
void ViewCourses();
void ViewGrades();
void enrollCourses();
void studentViewCourses();
//===============================
//validity functions
bool isValidage(int age);
bool isValidinteger(int integer);
bool isValidstring(string str);
bool isValidtime(string time);
bool isValidendTime(string time1, string time2);
bool isValidchoice(char choice);
bool isValidscore(int);
//================================
//getFunctions
int  getAge();
int  getID(string type);
int  getNum(string numberinfo = "number");
int  getStudentsnum();
int  getCourseIndex(int CourseID);
int  getStudentIndex(int);
int  getScore();
char getChoice();
char getStudentremoveConfirmation(int StudentIndex);
char getCourseremoveConfirmation(int courseIndex);
char getConfirmation(string);
string getdetails(string type, string infoName);
string getStarttime();
string getEndtime(string startTime);
//=================================
//Another functions
bool toContinue(char choice);
void outputStudentdetails(int studentID, int age, string name, string major, string username, string password);
void outputCourseDetails(int courseID, string title, string instructor, string day, string place, string startTime, string endTime, int students);
void outputGradeDetails(int, int, int);
int handlingStudentIdNotfound(int, int);
int handlingCourseIdNotfound(int, int);
void fillCourses(int courseID, string title, string instructor, string day, string place, string startTime, string endTime, int students);
void fillStudents(int studentID, string name, int age, string major, string username, string password);
void fillgrades(int gradeID, int studentID, int courseID, int score);
void deleteCourse(int courseIndex);
void deleteStudent(int StudentIndex);
char calcgrade(int);
//==================================
//Files functions
void LoadCoursesFiles();
void LoadStudentsFiles();
void LoadInstructorsFiles();
void LoadGradesFiles();
void LoadEnrolledCoursesFiles();
void exitProgram();
void saveCoursesToFile(const string& filename,vector<Course>);
void saveStudentsToFile(const string& filename, vector<Student>);
void saveInstructorToFile(const string& filename, vector<Instructor>);
void saveGradesToFile(const string& filename, vector<Grade>);
void saveEnrolledCoursesToFile(const string& filename, vector<Student>);
//===================================================================================================================================
	vector<Course>courses;
	vector<Student>students;
	vector<Instructor>instructores;
	vector<Grade>grades;
int main()
{
	LoadCoursesFiles();
	LoadStudentsFiles();
	LoadGradesFiles();
	LoadInstructorsFiles();
	LoadEnrolledCoursesFiles();
	MainMenu();
	return 0;
}
//===================================================================================================================================
//Menus
void MainMenu()
{

	char choice, choice2;
	cout << "                     ** welcome to universty learning system ** \n";
	cout << "                       --------------------------------------\n\n";
	cout << "Choose option for login: \n";
	cout << "------------------------\n";
	cout << " 1 : login as admin\n";
	cout << " 2 : login as student\n";
	cout << " 3 : Exit\n";
	cout << "\nChoice:";
	choice = getNum("choice");
	cin.ignore();
	switch (choice)
	{
	case(1):LoginAsAdmin();
		break;
	case(2):LoginAsStudent();
		break;
	case(3):exitProgram();
	default:cout << "Invalid choice";
		choice2 = getConfirmation("continue");
		if (toContinue(choice2))
			MainMenu();
		else
		{
			exitProgram();
		}
	}
}
void AdminMenu()
{
	system("Cls");
	int choice;
	char choice2;
	cout << "\n================ Welcome ==================\n\n";
	cout << "\n1:Add Course:\n";
	cout << "2:Remove Course:\n";
	cout << "3:Add Student:\n";
	cout << "4:Remove Student:\n";
	cout << "5:Add Grades:\n";
	cout << "6:Log out:\n";
	cout << "\nEnter your choice\n";
	cout << "\nChoice:";
	choice = getNum();
	switch (choice)
	{
	case(1):AddCourse();
		break;
	case(2):RemoveCourse();
		break;
	case(3):AddStudent();
		break;
	case(4):RemoveStudent();
		break;
	case(5):addGrade();
		break;
	case(6):logout();
		break;
	default:cout << "Invalid choice";
		choice2 = getConfirmation("continue");
		if (toContinue(choice2))
			AdminMenu();
		else
		{
			exitProgram();
		}
	}

}
void StudentMenu()
{
	system("Cls");
	int choice;
	char choice2;
	cout << "\n================ Welcome ==================\n\n";
	cout << "\n1:View Course:\n";
	cout << "2:Enroll in Course:\n";
	cout << "3:View student enrolled courses:\n";
	cout << "4:View Grades:\n";
	cout << "5:Log out:\n";
	cout << "\nEnter your choice\n";
	cout << "\nChoice:";
	cin >> choice;
	switch (choice)
	{
	case(1):ViewCourses();
		break;
	case(2):enrollCourses();
		break;
	case(3):studentViewCourses();
		break;
	case(4):ViewGrades();
		break;
	case(5):logout();
		break;
	default:cout << "Invalid choice";
		choice2 = getConfirmation("continue");
		if (toContinue(choice2))
			StudentMenu();
		else
		{
			exitProgram();
		}
	}
}

//===============================
//Login functions
void LoginAsAdmin()
{
	system("Cls");
	string username, password;
	cout << "\nEnter your username: ";
	getline(cin, username);
	cout << "Enter your password: ";
	getline(cin, password);
	for (int i = 0; i < instructorcounter; i++)
	{
		if (username == instructores[i].username && password == instructores[i].password)
		{
			constinstructorid = instructores[i].instructorID;
			AdminMenu();
		}
	}
	LoginAsAdmin();
}
void LoginAsStudent()
{
	system("Cls");
	string username, password;
	cout << "\nEnter your username: ";
	getline(cin, username);
	cout << "Enter your password: ";
	getline(cin, password);
	for (int i = 0; i < StudentsCounter; i++)
	{
		if (username == students[i].username && password == students[i].password)
		{
			conststudentid = students[i].studentID;
			StudentMenu();
		}
	}
	LoginAsStudent();
}
void logout()
{
	system("Cls");
	cout << "\n\nlogged out successfully\n";
	MainMenu();
}
//===============================
//MainFunctions
void AddCourse()
{
	system("Cls");
	cout << "\n";
	char choice, choice2;
	int courseID, students;
	string title, instructor, day, place, startTime, endTime;
	cout << "\n";
	courseID = getID("Course");
	cin.ignore();
	title = getdetails("Course", "title");
	instructor = getdetails("Course", "instructor");
	day = getdetails("Course", "day");
	place = getdetails("Course", "place");
	startTime = getStarttime();
	endTime = getEndtime(startTime);
	students = getStudentsnum();
	outputCourseDetails(courseID, title, instructor, day, place, startTime, endTime, students);
	//check if the user want to confirm to add the course
	choice = getConfirmation("confirm to add this Course");
	if (toContinue(choice))
	{
		fillCourses(courseID, title, instructor, day, place, startTime, endTime, students);
		cout << "\nCourse added succesfully\n";
	}
	else cout << "\nCourse not added\n ";
	//check if user want to add another course
	choice2 = getConfirmation("add another Course");
	if (toContinue(choice2))
	{
		AddCourse();
	}
	else AdminMenu();
}
void RemoveCourse()
{
	system("Cls");
	cout << '\n';
	int CourseID, courseIndex;
	char choice, choice2;
	CourseID = getID("Course");
	courseIndex = getCourseIndex(CourseID);
	courseIndex = handlingCourseIdNotfound(courseIndex, CourseID);
	choice = getCourseremoveConfirmation(courseIndex);
	if (toContinue(choice))
	{
		deleteCourse(courseIndex);
		cout << "Course deleted successfully\n";
	}
	else cout << "Course not deleted\n";
	choice2 = getConfirmation("remove another Course");
	if (toContinue(choice2))
	{
		RemoveCourse();
	}
	else AdminMenu();
}
void AddStudent()
{
	system("Cls");
	cout << '\n';
	char choice, choice2;
	int studentID, age;
	string name, major, username, password;
	cout << '\n';
	studentID = getID("Student");
	age = getAge();
	cin.ignore();
	name = getdetails("Student", "name");
	major = getdetails("Student", "major");
	username = getdetails("Student", "username");
	password = getdetails("Student", "password");
	outputStudentdetails(studentID, age, name, major, username, password);
	choice = getConfirmation("confirm to add this Student");
	if (toContinue(choice))
	{
		fillStudents(studentID, name, age, major, username, password);
		cout << "\nStudent added succesfully\n";
	}
	else cout << "\nStudent not added\n ";
	//check if user want to add another student
	choice2 = getConfirmation("add another Student");
	if (toContinue(choice2))
	{
		AddStudent();
	}
	else AdminMenu();

}
void RemoveStudent()
{
	system("Cls");
	cout << '\n';
	int StudentID, StudentIndex;
	char choice, choice2;
	StudentID = getID("Student");
	StudentIndex = getStudentIndex(StudentID);
	StudentIndex = handlingStudentIdNotfound(StudentIndex, StudentID);
	choice = getStudentremoveConfirmation(StudentIndex);
	if (toContinue(choice))
	{
		deleteStudent(StudentIndex);
		cout << "Student deleted successfully\n";
	}
	else cout << "Student not deleted\n";
	choice2 = getConfirmation("remove another Student");
	if (toContinue(choice2))
	{
		RemoveStudent();
	}
	else AdminMenu();

}
void addGrade()
{
	system("Cls");
	int courseID, studentID, gradeID, courseIndex, studentIndex, gradeIndex, score;
	char choice, choice2;
	cout << "\n";
	studentID = getID("Student");
	studentIndex = getStudentIndex(studentID);
	studentIndex = handlingStudentIdNotfound(studentIndex, studentID);
	courseID = getID("Course");
	courseIndex = getCourseIndex(courseID);
	courseIndex = handlingCourseIdNotfound(courseIndex, studentIndex);
	gradeID = getID("Grade");
	score = getScore();

	outputGradeDetails(studentIndex, courseIndex, score);
	choice = getConfirmation("confirm to add this grade");
	if (toContinue(choice))
	{
		fillgrades(gradeID, studentID, courseID, score);
		cout << "\nGrade added succesfully\n";
	}
	else cout << "\nGrade not added\n ";
	//check if user want to add another grade
	choice2 = getConfirmation("add another Grade");
	if (toContinue(choice2))
	{
		addGrade();
	}
	else AdminMenu();
}

void ViewCourses()
{
	system("Cls");
	cout << "Avaliable Courses :\n----------------------------------\n\n";
	cout << left
		<< setw(10) << "ID"
		<< setw(20) << "Title" 
		<< setw(20) << "Instructor"
		<< setw(15) << "Place"
		<< setw(15) << "Day" 
		<< setw(10) << "Starts"
		<< setw(10) << "Ends"
		<< setw(10) << "Students" <<
		"\n-------------------------------------------------------------------------------------------------------------\n";
	
	for (int i = 0; i < courses.size(); i++)
	{
		cout << left
			<< setw(10) << courses[i].courseID
			<< setw(20) << courses[i].title
			<< setw(20) << courses[i].instructor
			<< setw(15) << courses[i].coursesSchedule.place
			<< setw(15) << courses[i].coursesSchedule.dayOfWeek
			<< setw(10) << courses[i].coursesSchedule.startTime
			<< setw(10) << courses[i].coursesSchedule.endTime
			<< setw(10) << courses[i].numStudents << endl;
	}
	cout << "\nPress any key to continue : ";
	_getch();
	StudentMenu();
}
void enrollCourses()
{
	system("Cls");
	int select;
	int studentIndex;
	studentIndex = getStudentIndex(conststudentid);
	if (courses.size() == 0)
		cout << " there is no course to enroll \n";
	else {
			cout<< left
				<<setw(10)<<"index"
				<< setw(10) << "ID"
				<< setw(20) << "Title"
				<< "Instructor\n"
				<< "------------------------------------------------------\n";
			
		for (int i = 0; i < courses.size(); i++)
		{
			cout << left
				<<"["<<i+1<<setw(8)<<"]"
				<< setw(10) << courses[i].courseID
				<< setw(20) << courses[i].title
				<<courses[i].instructor << endl;
		}
		
		cout << "\nEnter the number of the course to enroll:  ";
		int select = getNum();
		select -= 1;
		if (select >= 0 && select <courses.size()) {
			if (students[studentIndex].enrolledCoursesnum < 6)
			{
				Course temp = courses[select];
				students[studentIndex].enrolledCourses.push_back(temp);
				students[studentIndex].enrolledCoursesnum++;
				cout << "\nThe course with ID: " << courses[select].courseID << " and Title: " << courses[select].title << " Has sucessfully Enrolled" << endl;
			}
			else {
				cout << "\nMax courses for the student has been reached" << endl;
			}
		}
		else {
			cout << "\nInvalid course selection.\n";

		}
	}
	cout << "\nPress any key to continue : ";
	_getch();
	StudentMenu();
}
void studentViewCourses()
{
	int studentIndex;
	studentIndex = getStudentIndex(conststudentid);
	system("Cls");
	cout << left
		<< setw(10) << "ID"
		<< setw(20) << "Title"
		<< "Instructor\n"
		<< "-----------------------------------------\n";
	for (int i = 0; i < students[studentIndex].enrolledCourses.size(); i++)
	{
		cout << left
			<< setw(10) << students[studentIndex].enrolledCourses[i].courseID
			<< setw(20) << students[studentIndex].enrolledCourses[i].title
			<< students[studentIndex].enrolledCourses[i].instructor << endl;
	}

	cout << "\nPress any key to continue : ";
	_getch();
	StudentMenu();
}
void ViewGrades() {
	system("Cls");
	int studentID = conststudentid;
	int studentIndex;
	studentIndex = getStudentIndex(conststudentid);
	cout << left<<setw(20)<<"Course Title"<<setw(10)<<"Score"<<"Grade\n";
	cout << "---------------------------------------\n";
	bool foundGrades = false;
	double totalScore = 0;
	int gradeCount = 0;
	for (int i = 0; i <grades.size(); i++)
	{
		if (grades[i].studentID == studentID)
		{
			for (int j = 0; j <courses.size(); j++)
			{
				if (courses[j].courseID == grades[i].courseID)
				{
					cout <<left<<setw(21)<< courses[j].title <<setw(10)<< grades[i].score<<calcgrade(grades[i].score) << "\n";
					totalScore += grades[i].score;
					foundGrades = true;
					gradeCount++;
				}
			}
		}
	}

	if (!foundGrades) {
		cout << "No grades available for this student.\n";
	}
	else {
		double averageScore = totalScore / gradeCount;
		cout << "\nOverall Grade: " << calcgrade(averageScore) << "\n";
	}

	cout << "\nPress any key to Continue";
	_getch();
	StudentMenu();
}
char calcgrade(int score)
{
	char grade;
	if (100 >= score && score >= 90)
	{
		grade = 'A';
	}
	else if (90 >= score && score >= 80)
	{
		grade = 'B';
	}
	else if (80 >= score && score >= 70)
	{
		grade = 'C';
	}
	else if (70 >= score && score >= 60)
	{
		grade = 'D';
	}
	else if (60 > score && score >= 0)
		grade = 'F';
	else
		cout << "out of range" << endl;
	return grade;
}
//===============================
//validity functions(functions to Check if the input valid or not)
bool isValidinteger(int integer)
{
	if (integer > 0 && cin.peek() == '\n')
		return true;
	else
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}
}
bool isValidstring(string str)
{
	if (str.empty())
		return false;
	return true;
}
bool isValidtime(string time)
{
	if (time.size() != 5)
		return false;
	if (time[2] != ':')
		return false;
	int hours = stoi(time.substr(0, 2));
	int minutes = stoi(time.substr(3, 2));
	if (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59)
		return true;
	return false;
}
bool isValidage(int age)
{
	if (age <= 100 && age >= 16)
		return true;
	return false;
}
bool isValidendTime(string firstTime, string endTime)
{
	if (stoi(firstTime.substr(0, 2)) < stoi(endTime.substr(0, 2)))
	{
		return true;
	}
	if (stoi(firstTime.substr(0, 2)) == stoi(endTime.substr(0, 2)))
	{
		if (stoi(firstTime.substr(3, 2)) < stoi(endTime.substr(3, 2)))
			return true;
	}
	return false;
}
bool isValidchoice(char choice)
{
	if ((choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') && cin.peek() == '\n')
		return true;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return false;
}
bool isValidscore(int score)
{
	if (score <= 100 && score >= 0)
		return true;
	return false;
}
//================================
//getFunctions(functions to get data for a specific type)
int getID(string type)
{
	int ID;
	cout << "Enter " << type << " ID: ";
	cin >> ID;
	while (!isValidinteger(ID))
	{
		cout << "Wrong input ,Enter a valid " << type << " ID: ";
		cin >> ID;
	}
	return ID;
}
int getCourseIndex(int CourseID)
{
	for (int i = 0; i < courses.size(); i++)
	{
		if (courses[i].courseID == CourseID)
		{
			return i;
		}
	}
	return -1;
}
int getStudentIndex(int studentID)
{
	for (int i = 0; i <students.size(); i++)
	{
		if (students[i].studentID == studentID)
		{
			return i;
		}
	}
	return -1;
}int getGradeIndex(int gradeID)
{
	for (int i = 0; i <grades.size(); i++)
	{
		if (grades[i].gradeID == gradeID)
		{
			return i;
		}
	}
	return -1;
}
int getStudentsnum()
{
	int students;
	cout << "Enter maximum Enrolled students for this course: ";
	cin >> students;
	while (!isValidinteger(students))
	{
		cout << "Wrong input ,Enter a valid number:";
		cin >> students;
		if (isValidinteger(students))
			break;
	}
	return students;
}
int getNum(string numberinfo)
{
	int number;
	cin >> number;
	while (!isValidinteger(number))
	{
		cout << "Wrong input ,Enter a valid " << numberinfo << ":";
		cin >> number;
	}
	return number;
}
int getAge()
{
	cout << "Enter age: ";
	int age;
	age = getNum("age");
	while (!isValidage(age))
	{
		cout << "wrong input (age should be between 16:100 ), enter valid age: ";
		age = getNum("age");
	}
	return age;
}
int getScore()
{
	int score;
	cout << "Enter score: ";
	score = getNum("score");
	while (!isValidscore(score))
	{
		cout << "wrong input(score should be between (0:100),enter valid score: ";
		score = getNum("Score");
	}
	return score;
}
string getdetails(string type, string infoName)
{
	string info;
	cout << "Enter the " << infoName << " of the " << type << " : ";
	getline(cin, info);
	while (!isValidstring(info))
	{
		cout << type << " " << infoName << " can not be empty, Enter valid " << infoName << " : ";
		getline(cin, info);
	}
	return info;
}
string getStarttime()
{
	string startTime;
	cout << "Enter the startTime for the course in 24 hours format (eg 13:50): ";
	getline(cin, startTime);
	if (!isValidtime(startTime))
	{
		while (true)
		{
			cout << "Wrong input ,Enter a valid time:";
			getline(cin, startTime);
			if (isValidtime(startTime))
				break;
		}
	}
	return startTime;
}
string getEndtime(string startTime)
{
	string endTime;
	cout << "Enter the endTime for the course in 24 hours format (eg 13:50): ";
	getline(cin, endTime);
	while (!isValidtime(endTime))
	{
		cout << "Wrong input ,Enter a valid time: ";
		getline(cin, endTime);
	}
	while (!isValidendTime(startTime, endTime))
	{
		cout << "Wrong input (end time cannot precede start time) ,Enter a valid time: ";
		getline(cin, endTime);
	}
	return endTime;
}
char getChoice()
{
	char choice;
	cin >> choice;
	while (!isValidchoice(choice))
	{
		cout << "Enter valid choice (y for yes|| n for no) :";
		cin >> choice;
	}
	return choice;
}
char getConfirmation(string message)
{
	char confirmation;
	cout << "\nDo you want to " << message << " (y for yes || n for no) : ";
	confirmation = getChoice();
	return confirmation;
}
char getCourseremoveConfirmation(int courseIndex)
{
	char choice;
	cout << "are you sure you want to remove course: " << courses[courseIndex].title << " ?\n";
	cout << "y for apply | n to cancel:";
	choice = getChoice();
	return choice;
}
char getStudentremoveConfirmation(int StudentIndex)
{
	char choice;
	cout << "are you sure you want to remove Student: " << students[StudentIndex].name << " ?\n";
	cout << "y for apply | n to cancel:";
	choice = getChoice();
	return choice;
}
//=================================
//Another functions
bool toContinue(char choice)
{
	if (choice == 'y' || choice == 'Y')
		return true;
	return false;
}
void outputCourseDetails(int courseID, string title, string instructor, string day, string place, string startTime, string endTime, int students)
{
	cout << "\nCourse details:\n";
	cout << "ID: " << courseID << endl;
	cout << "Title: " << title << endl;
	cout << "Instructor: " << instructor << endl;
	cout << "Day: " << day << endl;
	cout << "Place: " << place << endl;
	cout << "Start Time: " << startTime << endl;
	cout << "End Time: " << endTime << endl;
	cout << "Maximum Enrolled Students: " << students << endl;

}
void outputStudentdetails(int studentID, int age, string name, string major, string username, string password)
{
	cout << "\nStudent details:\n";
	cout << "ID: " << studentID << endl;
	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "major: " << major << endl;
	cout << "Username: " << username << endl;
	cout << "Password: " << password << endl;
}
void outputGradeDetails(int studentindex, int courseindex, int score)
{
	cout << "\nGrade details:\n";
	cout << "student name:" << students[studentindex].name << endl;
	cout << "Course title:" << courses[courseindex].title << endl;
	cout << "Score:" << score << endl;
}
void fillCourses(int courseID, string title, string instructor, string day, string place, string startTime, string endTime, int students)
{
	Course temp;
	temp.courseID = courseID;
	temp.title = title;
	temp.instructor = instructor;
	temp.coursesSchedule.dayOfWeek = day;
	temp.coursesSchedule.place = place;
	temp.coursesSchedule.startTime = startTime;
	temp.coursesSchedule.endTime = endTime;
	temp.numStudents = students;
	courses.push_back(temp);
	coursesCounter++;
}
void fillStudents(int studentID, string name, int age, string major, string username, string password)
{
	Student temp;
	temp.studentID = studentID;
	temp.name = name;
	temp.age = age;
	temp.major = major;
	temp.username = username;
	temp.password = password;
	students.push_back(temp);
	StudentsCounter++;
}
void fillInstructors(int InstructortID, string name, int age, string Department, string username, string password)
{
	Instructor temp;
	temp.instructorID = InstructortID;
	temp.name = name;
	temp.age = age;
	temp.department = Department;
	temp.username = username;
	temp.password = password;
	instructores.push_back(temp);
	instructorcounter++;
}
void fillgrades(int gradeID, int studentID, int courseID, int score)
{
	Grade temp;
	temp.gradeID = gradeID;
	temp.studentID = studentID;
	temp.courseID = courseID;
	temp.score = score;
	grades.push_back(temp);
	gradesCounter++;

}
int handlingStudentIdNotfound(int studentIndex, int studentID)
{
	char choice;
	while (studentIndex == -1)
	{
		cout << "Student not found";
		choice = getConfirmation("Enter another Student ID");
		if (toContinue(choice))
		{
			studentID = getID("Student");
			studentIndex = getStudentIndex(studentID);
		}
		else AdminMenu();
	}
	return studentIndex;
}
int handlingCourseIdNotfound(int courseIndex, int courseID)
{
	char choice;
	while (courseIndex == -1)
	{
		cout << "Course not found";
		choice = getConfirmation("Enter another Course ID");
		if (toContinue(choice))
		{
			courseID = getID("Course");
			courseIndex = getCourseIndex(courseID);
		}
		else AdminMenu();
	}
	return courseIndex;
}
void deleteCourse(int courseIndex)
{

	courses.erase(courses.begin() + courseIndex);
	coursesCounter--;
}
void deleteStudent(int StudentIndex)
{

	students.erase(students.begin() + StudentIndex);
	StudentsCounter--;
}

//==================================
//files functions:
void LoadCoursesFiles()
{
	ifstream coursesFile("courses.txt");
	if (!coursesFile) {
		cerr << "Error opening file for reading." << endl;
		return;
	}
	while (coursesFile) {
		int courseID;
		string title, instructor, dayOfWeek, place, startTime, endTime;
		int numStudents;

		if (!(coursesFile >> courseID >> title >> instructor >> dayOfWeek >> place >> startTime >> endTime >> numStudents)) {
			break;
		}
		fillCourses(courseID, title, instructor, dayOfWeek, place, startTime, endTime, numStudents);
	}
	coursesFile.close();
}
void LoadStudentsFiles()
{
	ifstream StudentFile("Students.txt");
	if (!StudentFile) {
		cerr << "Error opening file for reading." << endl;
		return;
	}
	while (StudentFile) {
		int StudentID, age;
		string name, major, username, password;
		if (!(StudentFile >> StudentID >> name >> age >> major >> username >> password))
		{
			break;
		}
		fillStudents(StudentID, name, age, major, username, password);
	}
	StudentFile.close();
}
void LoadInstructorsFiles()
{
	ifstream instructorFile("instructors.txt");
	if (!instructorFile) {
		cerr << "Error opening file for reading." << endl;
		return;
	}
	while (instructorFile) {
		int InstructorID, age;
		string name, Department, username, password;
		if (!(instructorFile >> InstructorID >> name >> age >> Department >> username >> password))
		{
			break;
		}
		fillInstructors(InstructorID, name, age, Department, username, password);
	}
	instructorFile.close();
}
void LoadGradesFiles()
{
	ifstream gradeFile("grades.txt");
	if (!gradeFile) {
		cerr << "Error opening file for reading." << endl;
		return;
	}
	while (gradeFile) {
		int gradeID, studentID, courseID, score;
		if (!(gradeFile >> gradeID >> studentID >> courseID >> score))
		{
			break;
		}
		fillgrades(gradeID, studentID, courseID, score);
	}
	gradeFile.close();
}
void LoadEnrolledCoursesFiles() {
	ifstream enrolledFile("enrolledCourses.txt");
	if (!enrolledFile) {
		cerr << "Error opening enrolled courses file for reading." << endl;
		return;
	}
	int studentID, courseID;
	while (enrolledFile >> studentID >> courseID) {
		int studentIndex = getStudentIndex(studentID);
		int courseIndex = getCourseIndex(courseID);
		if (studentIndex != -1 && courseIndex != -1) {
			students[studentIndex].enrolledCourses.push_back(courses[courseIndex]);
			students[studentIndex].enrolledCoursesnum++;
		}
	}
	enrolledFile.close();
}
void saveCoursesToFile(const string& filename, vector<Course>courses) {
	ofstream out_file(filename);
	if (!out_file) {
		cerr << "Error opening file for writing." << endl;
		return;
	}

	for (int i = 0; i <courses.size(); ++i) {
		out_file << courses[i].courseID << " " << courses[i].title << " " << courses[i].instructor << " "
			<< courses[i].coursesSchedule.dayOfWeek << " " << courses[i].coursesSchedule.place << " "
			<< courses[i].coursesSchedule.startTime << " " << courses[i].coursesSchedule.endTime << " "
			<< courses[i].numStudents << endl;
	}

	out_file.close();
	cout << "Data saved to " << filename << " successfully." << endl;
}
void saveStudentsToFile(const string& filename,vector<Student>students) {
	ofstream out_file(filename);
	if (!out_file) {
		cerr << "Error opening file for writing." << endl;
		return;
	}

	for (int i = 0; i <students.size(); ++i) {
		out_file << students[i].studentID << " " << students[i].name << " " << students[i].age << " " << students[i].major << " " << students[i].username << " " << students[i].password << endl;
	}

	out_file.close();
	cout << "Data saved to " << filename << " successfully." << endl;
}
void saveInstructorToFile(const string& filename,vector<Instructor>instructores) {
	ofstream out_file(filename);
	if (!out_file) {
		cerr << "Error opening file for writing." << endl;
		return;
	}

	for (int i = 0; i < instructores.size(); ++i) {
		out_file << instructores[i].instructorID << " " << instructores[i].name << " " << instructores[i].age << " " << instructores[i].department << " " << instructores[i].username << " " << instructores[i].password << endl;
	}

	out_file.close();
	cout << "Data saved to " << filename << " successfully." << endl;
}
void saveGradesToFile(const string& filename, vector<Grade >grades) {
	ofstream out_file(filename);
	if (!out_file) {
		cerr << "Error opening file for writing." << endl;
		return;
	}

	for (int i = 0; i <grades.size(); ++i) {
		out_file << grades[i].gradeID << " " << grades[i].studentID << " " << grades[i].courseID << " " << grades[i].score << endl;
	}

	out_file.close();
	cout << "Data saved to " << filename << " successfully." << endl;
}
void saveEnrolledCoursesToFile(const string& filename, vector<Student> students) {
	ofstream out_file(filename);
	if (!out_file) {
		cerr << "Error opening file for writing." << endl;
		return;
	}
	for (int i = 0; i < students.size(); i++) {
		for (int j = 0; j < students[i].enrolledCourses.size(); j++) {
			out_file << students[i].studentID << " " << students[i].enrolledCourses[j].courseID << endl;
		}
	}
	out_file.close();
	cout << "Data saved to " << filename << " successfully." << endl;
}
//==================================
void exitProgram()
{
	saveCoursesToFile("courses.txt", courses);
	saveStudentsToFile("students.txt", students);
	saveGradesToFile("grades.txt", grades);
	saveInstructorToFile("instructors.txt", instructores);
	saveEnrolledCoursesToFile("enrolledCourses.txt", students);
	cout << "\nThanks for using our system :)\n";
	exit(0);
}
