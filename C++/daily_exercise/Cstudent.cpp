/*设计一个CStudent类，其中包含学生信息包括：姓名、学号、英语、数学、程序设计成绩和平均成绩。
其类的结构如下：*/
#include <iostream>
#include<iomanip>
using namespace std;
class CStudent{
private:
	char stuno[20];    //学号
	char  name[20];    //姓名，用英语不考虑汉字
	int english;       //英语成绩（小于等于100，大于等于0，不在此范围按0分处理）
	int math;          //数学成绩（小于等于100，大于等于0，不在此范围按0分处理）
	int programe;      //程序设计成绩（小于等于100，大于等于0，不在此范围按0分处理）
	double avg;        //平均成绩，小数点后只取一位，其余部分四舍五入处理
public:
	CStudent();
	//计算平均成绩
	void getavg();
	//显示整个记录数据
	void print();
};
void CStudent::print()
{
    cout << fixed  << setprecision(1);
	cout << "学号："<<stuno << "  姓名："<<name<<"  英语成绩："<<english<<"  数学成绩："<<math<<"  程序设计成绩"<<programe<<"  平均成绩"<<avg<<endl;
}

CStudent::CStudent() : avg(0) {
    cin >> stuno >> name >> english >> math >> programe ;
    if(math<0)  math = 0;
    if(english<0)  english = 0;
    if(programe<0) programe=0;
}

void CStudent::getavg() {
    avg = (english+math+programe)/3.0;
}
//如下main函数执行后
int main()
{
	CStudent s[3];

	for(int i = 0; i < 3; i++)
	{
		s[i].getavg();
		s[i].print();
	}
	return 0;
}
/*
键盘输入如下内容：
1101001 zhangsan 85 69 89
1101002 lisi 75 89 77
1101003 wangwu 100 100 -89
执行的结果为
学号：1101001  姓名：zhangsan  英语成绩：85  数学成绩：69  程序设计成绩89  平均成绩81
学号：1101002  姓名：lisi  英语成绩：75  数学成绩：89  程序设计成绩77  平均成绩80.3
学号：1101003  姓名：wangwu  英语成绩：100  数学成绩：100  程序设计成绩0  平均成绩66.7
*/