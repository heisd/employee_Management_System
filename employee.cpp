//
// Created by 延年易廋 on 2025/8/10.
//

#include "employee.h"
//初始化函数
employee::employee(int id, string name, int dId) {
    m_id=id;
    m_name=std::move(name);
    m_dId=dId;
}
void employee::showInfo() {
    cout<<"职工编号"<<this->m_id;
    cout<<"\t职工姓名"<<this->m_name;
    cout<<"\t岗位"<<this->m_dId;
    cout<<"\t岗位职责，完成经理安排的任务"<<endl;
}
string employee::getDepName() {
    return "员工";
}