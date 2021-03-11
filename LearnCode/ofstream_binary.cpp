//
//  main.cpp
//  二进制文件-写文件
//
//  Created by song on 2020/12/18.
//

#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
    char m_Name[20];
    int m_Age;
};
void test01()
{
    //1.包含头文件:    #include <fstream>
    
    //2.创建流对象:    ofstream ofs ,创建流对象的同时可以打开文件
    ofstream ofs("Person.txt", ios::out | ios::binary);
    //3.打开文件:     ofs.open("文件路径",打开方式);
    //ofs.open("test.txt",ios::out | ios::binary);
    //4.写数据:      ofs<<"写入的数据";
    Person p = {"张三",18};
    ofs.write((const char *)&p, sizeof(Person));
    //5.关闭文件:     ofs.close();
    ofs.close();
}
int main()
{
    test01();
    return 0;
}

