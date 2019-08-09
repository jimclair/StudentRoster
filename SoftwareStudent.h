#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include <string>

#include "Student.h"
#include "Degree.h"

class SoftwareStudent : public Student {
    public:
        SoftwareStudent(std::string resstudentID, std::string resfirstName, std::string reslastName, std::string resemail, int resage, int  *resdaysInCourse, degree mydegree);
        degree GetDegreeProgram();
        void PrintData();
    private:
        degree mydegree;
};

#endif