#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include <string>

#include "Student.h"
#include "Degree.h"

class SecurityStudent : public Student {
    public:
        SecurityStudent(std::string resstudentID, std::string resfirstName, std::string reslastName, std::string resemail, int resage, int *resdaysInCourse, degree mydegree);
        degree GetDegreeProgram();
        void PrintData();
    private:
        degree mydegree;
};

#endif