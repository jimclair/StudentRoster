#ifndef STUDENT_H
#define STUDENT_H

#include "string"
#include "Degree.h"

class Student
{
  public:
    //Accessors
    std::string GetStudentID();
    std::string GetFirstName();
    std::string GetLastName();
    std::string GetEmail();
    int GetAge();
    int *GetDaysInCourse();
    


    //Mutators
    void SetStudentID(std::string studentID);
    void SetFirstName(std::string firstName);
    void SetLastName(std::string lastName);
    void SetEmail(std::string emailAddress);
    void SetAge(int age);
    void SetDaysInCourse(int *daysInCourse);

    //Default Constructor
    Student ();
    //Constructor w/ expected base class Parameters
    Student (std::string resstudentID, std::string resfirstName, std::string reslastName, std::string resemail, int resage, int *ptrdaysInCourse);
    //Deconstructor
    virtual ~Student () = 0;
    
    //Polymorphs
    virtual void PrintData() = 0;
    virtual degree GetDegreeProgram() = 0;

  private:
    //Data Members
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string email;
    int age;
    int daysInCourse[3];
};

#endif