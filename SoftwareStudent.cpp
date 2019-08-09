#include <iostream>
#include <string>
#include <iomanip>
#include <ios>

#include "SoftwareStudent.h"





SoftwareStudent::SoftwareStudent(std::string resstudentID, std::string resfirstName, std::string reslastName, std::string resemail, int resage, int  *resdaysInCourse, degree mydegree):Student(resstudentID, resfirstName, reslastName, resemail, resage, resdaysInCourse), mydegree(mydegree) {
    return;
}

degree SoftwareStudent::GetDegreeProgram() {
    return mydegree;
}

void SoftwareStudent::PrintData() {
    
    std::cout << this->GetStudentID();
    std::cout << std::setw(4) << std::right << "First Name: " << this->GetFirstName();
    std::cout << std::setw(4) << std::right << "Last Name: " << this->GetLastName();
    std::cout << std::setw(4) << std::right << "Age: " << this->GetAge();
    std::cout << std::setw(4) << std::right << "daysInCourse: {" << this->GetDaysInCourse()[0] << "," << this->GetDaysInCourse()[1] << "," << this->GetDaysInCourse()[2] << "}";
    std::cout << std::setw(4) << std::right << "DegreeProgram: " << this->GetDegreeProgram() << std::endl;
    return;
}