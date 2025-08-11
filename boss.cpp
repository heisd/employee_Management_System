//
// Created by 延年易廋 on 2025/8/10.
//

#include "boss.h"
boss::boss(int id, std::string name, int dId) {
    m_id=id;
    m_name=std::move(name);
    m_dId=dId;
}

void boss::showInfo() {
    cout<<"职工编号"<<this->m_id;
    cout<<"\t职工姓名"<<this->m_name;
    cout<<"\t岗位";
    cout<<"\t岗位职责，公司的所有职务"<<endl;
}

string boss::getDepName() {
    return "老板";
}
