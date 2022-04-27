/*
任务：参加运动会有n个学校，学校编号为1……n。比赛分成m个男子项目，和w个女子项目。
项目编号为男子1……m，女子m+1……m+w。不同的项目取前五名或前三名积分；
取前五名的积分分别为：7、5、3、2、1，前三名的积分分别为：5、3、2；
哪些取前五名或前三名由学生自己设定。（n<=20 , m<=20）
功能要求：
（1）	可以输入各个项目的前三名或前五名的成绩；
（2）	能统计各学校总分；
（3）	可以按学校编号、学校总分、男女团体总分排序输出；
（4）	可以按学校编号查询学校某个项目的情况；可以按项目编号查询取得前三或前五名的学校。
*/

#include<iostream>
#include<algorithm>
#include<cstdlib>
int a[]={7,5,3,2,1};
int b[]={5,3,2};

enum Flag { three = 3, five = 5};
typedef struct ProjectNode* Project;
struct ProjectNode {
    Flag flag;
    int school[5];
    int n;
    int w;
    int m;
};



void Build(Project project) {
    int flag;
    int i,j;
    
    for( i=0;i<(project->m+project->w);i++) {
        std::cin >> flag;
        project[i].flag = ((flag == 3) ? Flag::three : Flag::five);
        for( j=0;j<project[i].flag;j++) {
            std::cin >> project[i].school[j];
        }
    }
}
//每个项目的名次
void Prescore(Project project) {

    int i;
    //std::cout << project->w+project->m;
    //std::cout << project[1].flag;
    for(i=0;i<project->m+project->w;i++) {
        std::cout << "project" << "{"<< i << "}";

        if(project[i].flag==Flag::three) {
            int j;
            for(j=0;j<3;j++) {
                std::cout << "学校" << j << "=" << b[j] << ' ';
            }
        }
        if(project[i].flag==Flag::five) {
            //std::cout << "yes";
            int j;
            for(j=0;j<5;j++) {
                std::cout << "学校" << j << "=" << a[j] << ' ';
            }
        }
        std::cout << std::endl;
    }
}

//每个学校的总分
void school_total(Project project) {
    int *score = (int *)malloc(sizeof(int)*(project->n+1));
    int *num = (int *)malloc(sizeof(int)*(project->n+1));
    for(int i=0;i<=project->n;i++) {
        score[i] = 0;
    }
    for(int i=0;i<=project->n;i++) {
        num[i] = i;
    }
    for(int i= 0;i<project->m+project->w;i++) {
        if(project[i].flag==Flag::three) {
            for(int j=0;j<3;j++)
                score[project[i].school[j]]+=b[j];
        }
        if(project[i].flag==Flag::five) {
            
            for(int j=0;j<5;j++) {
                score[project[i].school[j]]+=a[j];
            }
        }
    }
    //学校总分输出
    std::cout << "学校编号输出 " << std::endl;
    for(int i=1;i<=project->n;i++) {
        std::cout << "学校" << i << "=" <<score[i] << " " <<std::endl;
    }
    //学校分排序
    std::cout << "分序输出" <<std::endl;
    for(int i=1;i<=project->n;i++) {
        for(int j=1;j<=project->n;j++) {
            if(score[j]<score[i]) {
                std::swap(score[i],score[j]);
                std::swap(num[i],num[j]);
            }
        }
    }
    for(int i=1;i<=project->n;i++) {
        std::cout << "学校" << num[i] << "=" << score[i] << " " <<std::endl;
    }
}


int main()
{
    Project project = nullptr ;
    int n,m,w;
    std::cin >> n >> m >> w;
    project = (Project)malloc(sizeof(struct ProjectNode)*(m+w));
    project->n = n;
    project->m = m;
    project->w = w;
    Build(project);
    
    Prescore(project);
    std::cout << "学校总分 ： " << std::endl;
    school_total(project);
}
/*
5 1 2
3 1 2 3
5 2 3 4 5 1
3 5 3 1
*/