//
// Created by 延年易廋 on 2025/8/10.
//

#include "manager.h"
manager::manager(int id, std::string name, int dId) {
    m_id=id;
    m_name=std::move(name);
    m_dId=dId;
}

void manager::showInfo() {
    cout<<"职工编号"<<this->m_id;
    cout<<"\t职工姓名"<<this->m_name;
    cout<<"\t岗位";
    cout<<"\t岗位职责，完成老板安排的任务"<<endl;
}

string manager::getDepName() {
    return "经理";
}
