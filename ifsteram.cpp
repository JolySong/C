//
//  main.cpp
//  文本文件-读文件
//
//  Created by song on 2020/12/18.
//

#include <iostream>
#include <fstream>
using namespace std;

void test01()
{
    //1.包含头文件:    #include <fstream>
    
    //2.创建流对象:    ifstream ifs;
    ifstream ifs;
    //3.打开文件并判断是否打开成功:     ifs.open("文件路径",打开方式);
    ifs.open("test.txt",ios::in);
    
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    //4.读数据:      4种方式读文件;
    //第一种
    char buf[1024] = {0};
    while( ifs >> buf ){
        cout<<buf<<endl;
    }
    //5.关闭文件:     ofs.close();
    ifs.close();
}
int main()
{
    test01();
    return 0;
}
