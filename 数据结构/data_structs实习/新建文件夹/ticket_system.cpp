/*
6．	订票系统
功能要求：
（1）录入：可以录入航班情况，数据可以存储在一个数据文件中，数据结构自定；
（2）查询：可以查询某个航线的情况（如，输入航班号，查询起降时间，起飞抵达城市，航班票价，票价折扣，确定航班是否满仓）；可以输入起飞抵达城市，查询飞机航班情况；
（3）订票：（订票情况可以存在一个数据文件中，结构自己设定）可以订票，如果该航班已经无票，可以提供相关可选择航班；
（4）退票： 可退票，退票后修改相关数据文件；客户资料有姓名，证件号，订票数量及航班情况，订单要有编号。
（5）修改航班信息：当航班信息改变可以修改航班数据文件
请根据以上功能要求，设计航班信息，订票信息的存储结构，设计程序完成功能；

*/

#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

struct Time {
    int hour;
    int minute;
    Time() : hour(0),minute(0) { }
    Time(int _hour,int _minute) : minute(_minute),hour(_hour) { }
};

struct Flight {
    int num;
    Time lift_off_time;
    Time land_time;
    char place[10];
    char targe[10];
    int price;
    int off;
    bool isfull;
};


int main()
{
    Flight f;

    FILE* fp = fopen("./data.txt","r");
    if(fp) {
        //输入航班号，查询起降时间，起飞抵达城市，航班票价，票价折扣，确定航班是否满仓
        fscanf(fp,"%d %d %d %d %d %s %s %d %d %d",&f.num,&f.lift_off_time.hour,&f.lift_off_time.minute,&f.land_time.hour,&f.land_time.minute,
            f.place,f.targe,&f.price,&f.off,&f.isfull);
    }
    cout << f.num <<endl;
    cout << f.lift_off_time.hour << ":" << f.lift_off_time.minute <<endl;
    cout << f.land_time.hour << ":" << f.land_time.minute <<endl;
    cout << f.off <<endl;
    cout << f.place <<endl;
    cout << f.targe <<endl;
    cout << f.price <<endl;
    cout << f.isfull <<endl;
    fclose(fp);
}