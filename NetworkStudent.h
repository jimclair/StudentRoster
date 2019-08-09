#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include <string>

#include "Student.h"
#include "Degree.h"

class NetworkStudent : public Student {
    public:
        NetworkStudent(std::string resstudentID, std::string resfirstName, std::string reslastName, std::string resemail, int resage, int *resdaysInCourse, degree mydegree);
        degree GetDegreeProgram();
        void PrintData();
    private:
        degree mydegree;
};

#endif