//
// Created by 延年易廋 on 2025/8/10.
//
#include "boss.h"
#include "work.h"
#include "manager.h"
#include "employee.h"
#include <iostream>
#include <string>
using namespace std;
void test_1(){
    worker*worker= nullptr;
    worker=new employee(1,"zhangsan",1);
    worker->showInfo();
    cout<<worker->getDepName()<<endl;
    delete worker;
    worker=new manager(1,"lisi",2);
    worker->showInfo();
    cout<<worker->getDepName()<<endl;
    delete worker;
    worker=new boss(1,"wangwu",3);
    worker->showInfo();
    cout<<worker->getDepName()<<endl;
    delete worker;
}