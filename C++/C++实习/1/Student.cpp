#pragma once
#include "Student.h"
#include "Score.cpp"
#include <iostream>
#include <string>
Student::Student() {}
Student::Student(int num) : num(num) {}
Student::Student(std::string s) : name(s) {}
Student::Student(std::string s, int num, Gender gender, Score score)
{
	name = s;
	this->num = num;
	this->gender = gender;
	this->score.English = score.English;
	this->score.Math = score.Math;
	this->score.PE = score.PE;
	this->score.program_design = score.program_design;
}

std::ostream &operator<<(std::ostream &os, Student &s)
{
	os << " name: " << s.name
	   << " num: " << s.num
	   << " gender: " << (s.gender == Student::Gender::MAN ? "Man" : "Woman")
	   << std::endl
	   << " Score: "
	   << s.score
	   << std::endl
	   << std::endl;
	return os;
}
bool Student::operator==(const Student &obj)
{
	return num == obj.num || name == obj.name;
}
Score Student::getScore(){
	    return score;
}