#ifndef ROSTER_H
#define ROSTER_H

#include <vector>
#include <string>

#include "Degree.h"
#include "Student.h"

class Roster {
    public:
        int GetNumStudents();
        std::vector<std::string> GetStudentIDs();
        void AddStudent(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, std::string studentDegree);
        void RemoveStudent(std::string studentID);
        void PrintAll();
        void PrintDaysInCourse(std::string studentID);
        void PrintInvalidEmails();
        void PrintByDegreeProgram(degree degreeProgram);
        ~Roster();
    private:
        std::vector<Student*> classRosterArray;
};
#endif