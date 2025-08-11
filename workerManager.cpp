//
// Created by 延年易廋 on 2025/8/9.
//
//这个是一个用户交互的界面
#include "workerManager.h"
#include "work.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
//设置文件路径
#define FILENAME "empFile.txt"
workerManger::workerManger() {
    //1.文件不存在
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){
            cout<<"文件不存在"<<endl;
            this->m_count=0;
            this->pww= nullptr;
            this->m_FileIsEmpty= true;
            ifs.close();
            return ;
        }
    //2.文件存在但是被清空
    char ch;
    //读取一个字符
    ifs>>ch;
    //第一个读到的是结尾标志
    if(ifs.eof()){
        cout<<"文件为空"<<endl;
        this->m_count=0;
        this->pww= nullptr;
        this->m_FileIsEmpty= true;
        ifs.close();
    }
    //3.文件存在，并且保存职工的所有数据
    int num=this->get_num();
    cout<<"职工人数为"<<num<<endl;
    //更新原来的数据为新的大小
    this->m_count=num;
    //开辟空间
    this->pww=new worker * [this->m_count];
    //将文件中的数据存到数组中
    this->init_Emp();
    //测试代码
    for (int i = 0; i < this->m_count; ++i) {
        cout<<"职工编号"<<this->pww[i]->m_id<<endl;
        cout<<"职工姓名"<<this->pww[i]->m_name<<endl;
        cout<<"部门编号"<<this->pww[i]->m_DeptId<<endl;

    }
}

//手动释放堆区数据
workerManger::~workerManger() {
    if(this->pww!= nullptr){
        delete[]this->pww;
        this->pww= nullptr;
    }
}

void workerManger::show_menu() {
    cout<<"欢迎使用职工管理系统"<<endl;
    cout<<"0退出职工管理系统"<<endl;
    cout<<"1增加职工信息"<<endl;
    cout<<"2显示职工信息"<<endl;
    cout<<"3删除职工信息"<<endl;
    cout<<"4修改职工信息"<<endl;
    cout<<"5查找职工信息"<<endl;
    cout<<"6按照编号排序"<<endl;
    cout<<"7清空所有文档"<<endl;
}
void workerManger::exitSystem() {
    cout<<"欢迎下次使用"<<endl;
    system("pause");
    exit(0);
}
//添加功能的实现
void workerManger::addWorker() {
   cout<<"输入你要添加的员工的数量"<<endl;
   //记录用户输入的数量
   int addNum=0;
   cin>>addNum;
   //执行具体的添加
    if(addNum>0){
        //计算你新添加的空间大小
        //新空间的大小等于原来记录+新增人数
        int newSize=this->m_count+addNum;
        //开辟新空间--大小是新空间的大小
        worker **newSpace =new worker *[newSize];
        //将原来的数据拷贝到新空间中
        if(this->pww!= nullptr){
            for (int i = 0; i < this->m_count; ++i) {
                newSpace[i]=this->pww[i];
            }
        }
        //开始添加新数据
            for (int i = 0; i < addNum; ++i) {
                int id;
                string name;
                int dSelect;
                cout<<"请输入第"<<i+1<<"个职工的编号"<<endl;
                cin>>id;
                cout<<"请输入第"<<i+1<<"个职工的姓名"<<endl;
                cin>>name;
                cout<<"请输入第"<<i+1<<"个职工的选择的部门"<<endl;
                cout<<"1.普通员工"<<endl;
                cout<<"2.经理"<<endl;
                cout<<"3.老板"<<endl;
                cin>>dSelect;
                worker *worker= nullptr;
                switch (dSelect) {
                    case 1:
                        worker=new employee(id,name,1);
                        break;
                    case 2:
                        worker=new manager(id,name,2);
                        break;
                    case 3:
                        worker=new boss(id,name,3);
                        break;
                    default:
                        cout<<"error";
                        break;
                }
                newSpace[this->m_count+i]=worker;
            }
            //释放原有的空间
            delete[]this->pww;
            //更改新空间的指向
            this->pww=newSpace;
            //更新新空间的人数
            this->m_count=newSize;
            //更新职工不为空的情况
            this->m_FileIsEmpty= false;
            //提示添加成功
            cout<<"成功添加了"<<addNum<<"名职工"<<endl;
            //成功添加后保存到文件中
            this->save();

        }
    //用户输入错误的情况
    else{
        cout<<"请你检查一下你的输入，你的输入是不合法的"<<endl;
    }
    //按任意键清屏后返回上一级目录
    system("pause");
    system("cls");
}
void workerManger::save(){
    ofstream ofs;
    ofs.open(FILENAME,ios::out|ios::trunc);
    //通过循环把所有数据写入
    for (int i = 0; i < this->m_count; ++i) {
        ofs<<this->pww[i]->m_id<<" "<< this->pww[i]->m_name<<" "<<this->pww[i]->m_DeptId<<endl;
    }
    ofs.close();
}

int workerManger::get_num() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int dId;
    int num=0;
    //读完一行的标志
    while(ifs>>id&&ifs>>name&&ifs>>dId){
        num++;
    }
    ifs.close();
    return num;

}

void workerManger::init_Emp() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int dId;
    int index=0;
    while (ifs>>id&&ifs>>name&&ifs>>dId){
        worker*worker= nullptr;
        if(dId==1){
            worker=new employee(id,name,dId);
        }
        else if(dId==2){
            worker=new manager(id,name,dId);
        }
        else{
            worker=new boss(id,name,dId);
        }
        this->pww[index]=worker;
        index++;
    }
    ifs.close();

}

void workerManger::show_emp() {
    //检查是否为空
    if(this->m_FileIsEmpty)
    {
        cout<<"文件为空不打印"<<endl;
    }
    //打印
    for (int i = 0; i < this->m_count; ++i) {
        //利用多态调用程序接口
        this->pww[i]->showInfo();
    }
    system("pause");
    system("cls");
}
//判断职工是否存在
int workerManger::IsExit(int id) {
   int index=-1;
    for (int i = 0; i < this->m_count; ++i) {
        if(this->pww[i]->m_id==id){
            index=i;
            break;
        }
    }
    return index;
}
//删除功能实现
//在删除时应该先释放当前对象的内存再前移动数据
//本质就是数据的前移
void workerManger::Del_Emp() {
    if (this->m_FileIsEmpty){
        cout<<"文件不存在"<<endl;
    }
    else {
        cout<<"请输入你要删除的编号"<<endl;
        int id=0;
        cin>>id;
        int index= IsExit(id);
        if (index!=-1) {
            delete this->pww[index];
            for (int i = index; i < this->m_count-1; ++i) {
                this->pww[i] = this->pww[i + 1];
            }
            this->m_count--;
            this->save();
            cout << "删除成功" << endl;
        }
        else {
            cout << "这个编号不存在" << endl;
        }
    }
}
void workerManger::Mod_Emp() {
    //判断文件是否为空
    if(this->m_FileIsEmpty){
        cout<<"文件为空或者不存在"<<endl;
    }
    else{
        cout<<"请输入你要修改的职工的编号"<<endl;
        int id=0;
        cin>>id;
        int index=this->IsExit(id);
        if(index!=-1){
            {
                //释放原有空间
                delete this->pww[index];
                int NewId = 0;
                string NewName = " ";
                int NewDSelect = 0;
                cout << "查到:" << id << "号职工，请输入新工号" << endl;
                cin >> NewId;
                cout << "请输入新姓名" << endl;
                cin >> NewName;
                cout << "请输出新职位" << endl;
                cout << "1.普通员工" << endl;
                cout << "2.经理" << endl;
                cout << "3.老板" << endl;
                cin >> NewDSelect;
                //把输入的数据保存
                worker *worker = nullptr;
                switch (NewDSelect) {
                    case 1:
                        worker = new employee(NewId, NewName, NewDSelect);
                        break;
                    case 2:
                        worker = new manager(NewId, NewName, NewDSelect);
                        break;
                    case 3:
                        worker = new boss(NewId, NewName, NewDSelect);
                        break;
                    default:
                        break;
                }
                //更新数据到数组中
                this->pww[index] = worker;
                cout << "修改成功" << this->pww[index]->m_DeptId << endl;
                //修改成功后保存到文件中
                this->save();
            }
        }
        else{
            cout<<"没有这个人"<<endl;
        }
    }
    system("pause");
    system("cls");
}
//查找职工
void workerManger::Find_Emp() {
    if(this->m_FileIsEmpty){
        cout<<"这文件为空文件"<<endl;
    }
    else
    {
        cout<<"请输入要查找的方式"<<endl;
        cout<<"1.按照编号查找"<<endl;
        cout<<"2.按照姓名查找"<<endl;
        //1.按照职工编号来查找
        //2.按照职工姓名--存在重名
        int select=0;
        cin>>select;
        if(select==1) {
            int find_id = 0;
            cout << "请输入你要查找的编号" << endl;
            cin >> find_id;
            int ret = IsExit(find_id);
            if (ret != -1) {
                this->pww[ret]->showInfo();
            } else {
                cout << "这个编号没有" << endl;
            }
        }
        else if(select==2){
            cout<<"请输入你要查找的员工的姓名"<<endl;
            string find_name;
            cin>>find_name;
            bool flag= false;
            for (int i = 0; i < this->m_count; ++i) {
                if(find_name==this->pww[i]->m_name){
                    flag= true;
                    cout<<"查找成功"<<endl;
                    this->pww[i]->showInfo();
                }

            }
            if(!flag){
                cout<<"查无此人"<<endl;
            }
        }
    }
    system("pause");
    system("cls");
}

void workerManger::sort_Emp() {
    if(this->m_FileIsEmpty){
        cout<<"文件不存在"<<endl;
        system("pause");
        system("cls");
    }
    //选择排序的方法
    else{
        cout<<"请选择排序方式"<<endl;
        cout<<"1.按照职工号升序排列"<<endl;
        cout<<"2.按照职工号降序排列"<<endl;
        int select=0;
        cin>>select;
        for (int i = 0; i < this->m_count; ++i) {
                int Min_Or_Max=i;
                for (int j = i+1; j <this->m_count ; ++j) {
                    //升序
                    if(select==1){
                        //如果这Min_Or_Max大于j
                        //Min_Or_Max就会和j交换位置
                        //把小的数据排在前面
                        if (this->pww[Min_Or_Max]->m_id>this->pww[j]->m_id){
                            Min_Or_Max=j;
                        }
                    }
                    //降序
                    else if(select==2){
                        //如果这Min_Or_Max小于j
                        //Min_Or_Max就会和j交换位置
                        //把大的数据排在前面
                        if(this->pww[Min_Or_Max]->m_id<this->pww[j]->m_id){
                            Min_Or_Max=j;
                        }
                    }
                    else{
                        cout<<"你输入的选择有误"<<endl;
                    }
            }
            if(i!=Min_Or_Max){
                worker*temp=this->pww[i];
                this->pww[i]=this->pww[Min_Or_Max];
                this->pww[Min_Or_Max]=temp;
            }
        }
        cout<<"排序成功"<<endl;
        this->save();
        this->show_emp();
    }
}

void workerManger::clean_file() {
    cout<<"确认清空"<<endl;
    cout<<"1.确认清空"<<endl;
    cout<<"2.返回"<<endl;
    int select=0;
    cin>>select;
    if(select==1){
        //如果存在删除文件并且新建
        ofstream ofs(FILENAME,ios::trunc);
        ofs.close();
        //清除堆区空间
        if(this->pww!= nullptr){
            for (int i = 0; i < this->m_count; ++i) {
                if(this->pww[i]!= nullptr){
                    delete this->pww[i];
                }
            }
            this->m_count=0;
            delete[]this->pww;
            this->pww= nullptr;
            this->m_FileIsEmpty=true;
        }
        cout<<"清空成功"<<endl;
    }else if(select==2){
        cout<<"取消清空操作"<<endl;
        return ;
    }




}


