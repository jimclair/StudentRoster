#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Roster.h"
#include "Degree.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"
#include "NetworkStudent.h"



void Roster::AddStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, std::string studentDegree)
{
    //Determine object intance type and object's memory and create a ptr to it
    //FIXME: Build a temporary array of 3 elements for daysInCourse integers
    int myDaysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    Student *studentObjPtr = nullptr;

    if (studentDegree == "SOFTWARE")
    {
        studentObjPtr = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, myDaysInCourse, degree::SOFTWARE);
    }
    else if (studentDegree == "SECURITY")
    {
        studentObjPtr = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, myDaysInCourse, degree::SECURITY);
    }
    else
    {
        studentObjPtr = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, myDaysInCourse, degree::NETWORKING);
    }

    //Update the roster
    classRosterArray.push_back(studentObjPtr);
    return;
}

void Roster::RemoveStudent(std::string studentID)
{ //removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
    Student *studentObjPtr = nullptr;
    bool match = false;
    int i = 0;
    for (i = 0; i < classRosterArray.size(); i++)
    {
        if (studentID == classRosterArray[i]->GetStudentID())
        {
            studentObjPtr = classRosterArray[i];
            delete studentObjPtr;
            classRosterArray.erase(classRosterArray.begin() + i);
            match = true;
            //Test if studentObjPtr still has the ptr value after the delete and erase options:
            std::cout << studentObjPtr << std::endl;
        }
    }
    if (match == false)
    {
        std::cout << "StudentID: " << studentID << " was not found.  No student records were deleted." << std::endl;
    }
    else
    {
        std::cout << "StudentID found and deleted." << std::endl;
    }
    return;
}

void Roster::PrintAll()
{ //prints a complete tab-separated list of student data using accessor functions
    int i = 0;
    for (i = 0; i < classRosterArray.size(); i++)
    {
        classRosterArray[i]->PrintData();
    }
}

void Roster::PrintDaysInCourse(std::string studentID)
{
    int i = 0;
    double avgDaysInClass = 0.0;
    bool IDFound = false;
    for (i = 0; i < classRosterArray.size(); i++)
    {
        if (classRosterArray[i]->GetStudentID() == studentID)
        {
            avgDaysInClass = (classRosterArray[i]->GetDaysInCourse()[0] + classRosterArray[i]->GetDaysInCourse()[1] + classRosterArray[i]->GetDaysInCourse()[2]) / 3.0;
            IDFound = true;
        }
    }
    if (!IDFound)
    {
        std::cout << "Student ID NOT found!" << std::endl;
    }
    else
    {
        std::cout << "Average Days in Class: " << avgDaysInClass << std::endl;
    }
}

void Roster::PrintInvalidEmails()
{ //verifies student email addresses and displays all invalid email addresses to the user
    std::string email;
    std::size_t found;
    bool invalid = false;
    int i = 0;
    std::cout << "Invalid emails: " << std::endl;
    for (i = 0; i < classRosterArray.size(); i++)
    {
        email = classRosterArray[i]->GetEmail();
        //FIXME: use a nested for loop rather than multiple if branches.
        found = email.find("@");
        if (found == std::string::npos)
        {
            invalid = true;
        }
        found = email.find(".");
        if (found == std::string::npos)
        {
            invalid = true;
        }
        found = email.find(" ");
        if (found == std::string::npos)
        {
            invalid = true;
        }
        if (invalid == true)
        {
            std::cout << email << std::endl;
        }
    }
}

void Roster::PrintByDegreeProgram(degree degreeProgram)
{ //prints out student information for a degree program specified by an enumerated type
    int i = 0;
    for (i = 0; i < classRosterArray.size(); i++)
    {
        if (classRosterArray[i]->GetDegreeProgram() == degreeProgram)
        {
            classRosterArray[i]->PrintData();
            std::cout << std::endl;
        }
    }
}

int Roster::GetNumStudents() {
    return classRosterArray.size();
}

std::vector<std::string> Roster::GetStudentIDs() {
    std::vector<std::string> studentIDs;
    int i = 0;
    for (i = 0; i < classRosterArray.size(); ++i) {
        studentIDs.push_back(classRosterArray[i]->GetStudentID());
    }
    return studentIDs;
}

Roster::~Roster()
{
    std::cout << "Destructor called";
    int i = 0;
    for (i = 0; i < classRosterArray.size(); i++)
    {
        delete classRosterArray[i];
    }
}

int main()
{
    //Print out to the screen, via your application, the course title, the programming language used, your student ID, and your name.
    std::string COURSE_TITLE = "Scripting and Programming - Applications – C867";
    std::string LANGUAGE = "C++";
    std::string MY_NAME = "James Clair";
    std::string MY_ID = "000847594";

    std::cout << "Course Title:" << COURSE_TITLE << std::endl;
    std::cout << "Language:" << LANGUAGE << std::endl;
    std::cout << "Name:" << MY_NAME << std::endl;
    std::cout << "Student ID:" << MY_ID << std::endl;

    std::vector<std::string> studentData{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                         "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                         "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                         "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                         "000847594,James,Clair,jclair2@wgu.edu,30,4,32,8,SOFTWARE"};

    Roster classRoster; //Create an instance of the Roster class called classRoster.
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string email;
    int age;
    int daysInCourse1;
    int daysInCourse2;
    int daysInCourse3;
    std::string studentDegree;
    std::vector<std::string> parsedValues;
    std::string tmpString;

    int i = 0;
    for (i = 0; i < studentData.size(); i++)
    { //Add each student to classRoster.

        std::istringstream inSS(studentData.at(i));
        while (inSS.good())
        {
            getline(inSS, tmpString, ',');
            parsedValues.push_back(tmpString);
        }

        studentID = parsedValues.at(0);
        firstName = parsedValues.at(1);
        lastName = parsedValues.at(2);
        email = parsedValues.at(3);
        age = stoi(parsedValues.at(4));
        daysInCourse1 = stoi(parsedValues.at(5));
        daysInCourse2 = stoi(parsedValues.at(6));
        daysInCourse3 = stoi(parsedValues.at(7));
        studentDegree = parsedValues.at(8);

        classRoster.AddStudent(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, studentDegree);

        parsedValues.clear();
    }

    classRoster.PrintAll();
    classRoster.PrintInvalidEmails();
    
    i = 0;
    for (i = 0; i < classRoster.GetNumStudents(); ++i) {
        classRoster.PrintDaysInCourse(classRoster.GetStudentIDs()[i]);
    }
    
    //classRoster.PrintDaysInCourse(/*current_object's student id*/)//FIXME: loop through classRosterArray and for each element: classRoster.printAverageDaysInCourse(/*current_object's student id*/)
    classRoster.PrintByDegreeProgram(degree::SOFTWARE);
    classRoster.RemoveStudent("A3");
    classRoster.RemoveStudent("A3");
}
