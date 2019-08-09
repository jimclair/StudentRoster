#include <iostream>
#include <string>
#include <iomanip>
#include <ios>

#include "Student.h"
#include "Degree.h"

std::string Student::GetStudentID()
{
    return this->studentID;
}

std::string Student::GetFirstName()
{
    return this->firstName;
}

std::string Student::GetLastName()
{
    return this->lastName;
}

std::string Student::GetEmail()
{
    return this->email;
}

int Student::GetAge()
{
    return this->age;
}

//FIXME: Change to Array pointer, fix references to GetDaysInCourse accessors
int *Student::GetDaysInCourse()
{
    return this->daysInCourse;
}


void Student::SetStudentID(std::string studentID)
{
    this->studentID = studentID;
    return;
}

void Student::SetFirstName(std::string firstName)
{
    this->firstName = firstName;
    return;
}

void Student::SetLastName(std::string lastName)
{
    this->lastName = lastName;
    return;
}

void Student::SetEmail(std::string emailAddress)
{
    this->email = emailAddress;
    return;
}

void Student::SetAge(int age)
{
    this->age = age;
    return;
}

void Student::SetDaysInCourse(int *ptrdaysInCourse)
{
    daysInCourse[0] = ptrdaysInCourse[0];
    daysInCourse[1] = ptrdaysInCourse[1];
    daysInCourse[2] = ptrdaysInCourse[2];
    return;
}

void Student::PrintData()
{
    std::cout << "Student program unknown" << std::endl;
    return;
}

//Default Constructor with default parameter values
Student::Student()
{
    studentID = "None";
    firstName = "None";
    lastName = "None";
    email = "None";
    age = 0;
    daysInCourse[0] = 0;
    daysInCourse[1] = 0;
    daysInCourse[2] = 0;
    return;
}

Student::Student(std::string resstudentID, std::string resfirstName, std::string reslastName, std::string resemail, int resage, int *ptrdaysInCourse)
{ //Do I need a parameterized constructor in the base class?
    studentID = resstudentID;
    firstName = resfirstName;
    lastName = reslastName;
    email = resemail;
    age = resage;
    daysInCourse[0] = ptrdaysInCourse[0];
    daysInCourse[1] = ptrdaysInCourse[1];
    daysInCourse[2] = ptrdaysInCourse[2];
    return;
}