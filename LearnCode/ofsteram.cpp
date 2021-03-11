#include <iostream>
#include <fstream>
using namespace std;

void test01()
{
    //1.包含头文件:    #include <fstream>
    
    //2.创建流对象:    ofstream ofs;
    ofstream ofs;
    //3.打开文件:     ofs.open("文件路径",打开方式);
    ofs.open("test.txt",ios::out);
    //4.写数据:      ofs<<"写入的数据";
    ofs<<"姓名：张三"<<endl;
    ofs<<"性别：男"<<endl;
    ofs<<"年龄：18"<<endl;
    //5.关闭文件:     ofs.close();
    ofs.close();
}
int main()
{
    test01();
    return 0;
}

