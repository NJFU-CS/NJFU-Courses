/*第1题：设计一个学生学籍管理系统
	学生信息包括：姓名、学号、性别和英语、数学、程序设计、体育成绩。
	从键盘输入数据，建立数据文件student.dat。
	实现对学生或学号查询，显示信息。
	对所有学生，按照班级计算平均成绩。
	分别按照英语、数学、程序设计和体育成绩排序生成结果文件。 
*/
#pragma once

#include "StudentManageSystem.h"
#include "Student.cpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
StudentManagerSystem::StudentManagerSystem()
{
	std::ifstream fs("src/data.dat");
	if (fs)
	{
		std::string name;
		int num;
		int gender;
		int a, b, c, d;
		while (fs >> name >> num >> gender >> a >> b >> c >> d)
		{
			Student s(name, num, gender ? Student::Gender::WOMAN : Student::Gender::MAN, Score(a, b, c, d));
			v.push_back(s);
		}
	}
	else
	{
		std::cerr << "open file error" << std::endl;
	}
	fs.close();
	fs.clear();
}
void StudentManagerSystem::print()
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}

void StudentManagerSystem::find(const Student &s)
{
	vector<Student>::iterator it = std::find(v.begin(), v.end(), s);
	if (it != v.end())
		cout << *it << endl;
	else
	{
		cout << "not found" << endl;
	}
}

void StudentManagerSystem::Average()
{
	Score sum(0, 0, 0, 0);
	std::for_each(v.begin(), v.end(), [&sum](Student s)
				  { sum += s.getScore(); });
	sum.English /= v.size();
	sum.Math /= v.size();
	sum.PE /= v.size();
	sum.program_design /= v.size();
	cout << sum << endl;
}

void StudentManagerSystem::sort()
{
	string s = "result/";
	vector<Student> vec(v);
	ofstream os1(s + "English.dat", ios::out);
	std::sort(vec.begin(), vec.end(), [](Student a, Student b)
			  { return a.getScore().English - b.getScore().English; });
	for_each(vec.begin(), vec.end(), [&os1](Student s)
			 { os1 << s; });
	os1.clear();
	os1.close();

	vec = v;
	ofstream os2(s + "Math.dat", ios::out);
	std::sort(vec.begin(), vec.end(), [](Student a, Student b)
			  { return a.getScore().Math - b.getScore().Math; });
	for_each(vec.begin(), vec.end(), [&os2](Student s)
			 { os2 << s; });

	os2.close();
	os2.clear();

	vec = v;
	ofstream os3(s + "program_design.dat", ios::out);
	std::sort(vec.begin(), vec.end(), [](Student a, Student b)
			  { return a.getScore().program_design - b.getScore().program_design; });
	for_each(vec.begin(), vec.end(), [&os3](Student s)
			 { os3 << s; });

	os3.close();
	os3.clear();

	vec = v;
	ofstream os4(s + "PE.dat", ios::out);
	std::sort(vec.begin(), vec.end(), [](Student a, Student b)
			  { return a.getScore().PE - b.getScore().PE; });
	for_each(vec.begin(), vec.end(), [&os4](Student s)
			 { os4 << s; });
	os4.close();
	os4.clear();
}

void StudentManagerSystem::mainProcess()
{

	std::cout << "[1] print list" << std::endl;
	std::cout << "[2] find student" << std::endl;
	std::cout << "[3] average" << std::endl;
	std::cout << "[4] sort" << std::endl;
	int cmd;
	while (cin >> cmd)
	{
		if (cmd == 1)
		{
			print();
		}
		else if (cmd == 2)
		{
			string s;
			cin >> s;
			if (s == "name")
			{
				string name;
				cin >> name;
				find(name);
			}
			else
			{
				int num;
				cin >> num;
				find(num);
			}
		}
		else if (cmd == 3)
		{
			Average();
		}
		else if (cmd == 4)
		{
			sort();
		}
		else
		{
			std::cerr << "no such cmd" << std::endl;
		}
	}
}