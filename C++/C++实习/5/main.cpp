// 	对文本文件按行进行编辑：先从输入文件中读取数据，
//  然后根据行编辑命令处理，将结果写到输出文件中。
// 	行编辑命令包括：
// 序号	行编辑命令格式	功能
// １	*L  m，n	显示从第m至n行的文本
// ２	*I  m ......   插入文本（……）在第m行后
// ３	*D  m，n	删除从第m至n行的文本
// ４	*R  m，n  .....  用文本（……）替换第m至n行的文本
// ５	*X	保存并退出编辑程序
// ６	*Q	放弃并退出程序

#include"TextEditer.cpp"
int main(){
    TextEditer textediter;
    textediter.in();
    std::cout << textediter << std::endl;


    textediter.mainProcess();
}