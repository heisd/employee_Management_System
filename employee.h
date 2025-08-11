//
// Created by 延年易廋 on 2025/8/10.
//

#pragma once
#include <iostream>
#include <string>
#include "work.h"
using namespace std;
class employee :public worker{
public:
    employee(int id,string name,int dId);
    virtual void showInfo();
    virtual string getDepName();
private:
    int m_id;
    string m_name;
    int m_dId;
};



