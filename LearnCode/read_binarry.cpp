//
//  main.cpp
//  二进制文件-读文件
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
    
    //2.创建输出流对象:ifstream
    ifstream ifs;

    //3.打开文件 判断文件是否打开成功:     ifs.open("文件路径",打开方式);

    ifs.open("Person.txt",ios::in | ios::binary);
    if (!ifs.is_open()){
        cout<<"打开文件失败"<<endl;
        return;
    }

    //4.读数据:      ofs.read()
    
    Person p;
    ifs.read((char *)&p, sizeof(Person));
    cout<<"Name:"<<p.m_Name<<"\tAge:"<<p.m_Age<<endl;
    //5.关闭文件:     ofs.close();
    ifs.close();
}
int main()
{
    test01();
    return 0;
}

