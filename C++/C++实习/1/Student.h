#pragma once

#include "Score.cpp"
class Student
{
public:
	enum Gender
	{
		MAN,
		WOMAN
	};

    Student();
    Student(int num);
    Student(std::string s);
    Student(std::string s, int num, Gender gender, Score score);

    friend std::ostream &operator<<(std::ostream &os, Student &s);
    bool operator==(const Student &obj);
	Score getScore();

private:
	std::string name;
	int num;
	Gender gender;
	Score score;
};