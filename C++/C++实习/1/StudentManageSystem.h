#pragma once

#include "Student.cpp"
#include <vector>
class StudentManagerSystem
{
private:
    std::vector<Student> v;

public:
    StudentManagerSystem();
    void print();
    void find(const Student &s);
    void Average();
    void sort();
    void mainProcess();
};