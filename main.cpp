#include <iostream>
#include "workerManager.h"
#include "test.h"
using namespace std;

int main(){
    workerManger wm;
    int choice=0;
    test_1();
    do{
        wm.show_menu();
        cin>>choice;
        switch (choice) {
            case 0:
                wm.exitSystem();
                cout<<"成功退出"<<endl;
                break;
            case 1:
                cout<<"添加职工"<<endl;
                wm.addWorker();
                break;
            case 2:
                cout<<"显示职工"<<endl;
                wm.show_emp();
                break;
            case 3:
                cout<<"删除职工"<<endl;
                wm.Del_Emp();
                break;
            case 4:
                cout<<"修改职工"<<endl;
                wm.Mod_Emp();
                break;
            case 5:
                cout<<"查找职工"<<endl;
                wm.Find_Emp();
                break;
            case 6:
                cout<<"排序"<<endl;
                wm.sort_Emp();
                break;
            case 7:
                cout<<"清空"<<endl;
                wm.clean_file();
                break;
            default:
                system("cls");
                break;


        }
    }while(choice);




    return 0;
}