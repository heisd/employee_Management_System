//
// Created by 延年易廋 on 2025/8/9.
//

#pragma once
#include <iostream>
#include "work.h"

using namespace std;
class workerManger{
public:
    workerManger();
    void show_menu();
    void exitSystem();
    //添加职工的函数
    void addWorker();
    ~workerManger();
    //记录职工人数
    int m_count;
    //指向职工数组的指针
    worker**pww;
    //保存文件
    void save();

    //判断文件是否为空
    bool m_FileIsEmpty;
    //统计文件中人数
    int get_num();
    //初始化员工
    void init_Emp();
    //显示职工
    void show_emp();
    //删除职工
    void Del_Emp();
    //判断职工是否存在的函数
    int IsExit(int id);
    //修改职工
    void Mod_Emp();
    //查找员工
    void Find_Emp();
    //按序号排序员工
    void sort_Emp();
    //清空文件
    void clean_file();

};

