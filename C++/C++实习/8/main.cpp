// 第8题：设计一个随机读写文件程序
// 考虑将数据文件当作一个数组，对文件的分量进行下标访问。
// 可以实现一个类，重载［］能够从数据文件随机读写。
#include<iostream>
#include<fstream>
#include<vector>

class Student{
private:
    std::string name;
    int ID;
public:
    Student() = default;
    Student(std::string s,int id){
        name = s;
        ID = id;
    }
    void setName(std::string name){
        this->name = name;
    }
    std::string getName(){
        return name;
    }
    void setID(int ID){
        this->ID = ID;
    }
    int getID(){
        return ID;
    }
    friend std::ostream &operator<<(std::ostream &os,const Student &student){
        os << student.name << " : " << student.ID;
        return os;
    }
};

class RandomAccess{
private:
    std::fstream *fs;
    std::vector<Student> data;

public:
    RandomAccess();
    ~RandomAccess();
    void in();
    Student operator[](int index){
        Student student;
        fs->seekg(index*40,std::ios::beg);
        // std::cout << fs->tellg() << std::endl;
        fs->read((char *)&student, sizeof(Student));
        return student;
    }
};

RandomAccess::RandomAccess(){
    fs = new std::fstream("src/data.dat", std::ios::in | std::ios::out | std::ios::binary);
    data.push_back(Student("gk", 100));
    data.push_back(Student("by", 1000));
    data.push_back(Student("jyf", 10));
    data.push_back(Student("hi~hi", 10000));
}

RandomAccess::~RandomAccess(){
    fs->clear();
    fs->close();
    delete fs;
}

void RandomAccess::in(){
    for (int i = 0; i < data.size();i++)
    {
        fs->write((char *)&data[i], sizeof(Student));
    }
}

int main(){
    RandomAccess RA;
    RA.in();
    std::cout << RA[0];
}