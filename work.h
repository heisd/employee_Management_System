//
// Created by 延年易廋 on 2025/8/10.
//

#pragma once
#include <iostream>
#include <string>
using namespace std;
class worker{
public:
    virtual void showInfo()=0;
    virtual string getDepName()=0;
    virtual ~worker()=default;
    int m_id;
    string m_name;
    int m_DeptId;
};
