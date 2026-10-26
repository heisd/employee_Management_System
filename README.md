# employee_Management_System

C++ 控制台职工管理练习，包含普通员工、经理与老板三类角色，以及添加、显示、删除、修改、查找、排序和清空职工记录的菜单。

## 内容导航

- [main.cpp](./main.cpp)：菜单入口
- [workerManager.cpp](./workerManager.cpp)：职工管理与文件读写
- [employee.cpp](./employee.cpp)：员工类
- [manager.cpp](./manager.cpp)：经理类
- [boss.cpp](./boss.cpp)：老板类
- [empFile.txt](./empFile.txt)：职工数据
- [CMakeLists.txt](./CMakeLists.txt)：构建配置

## 构建

需要 CMake 3.31 或以上及支持 C++20 的编译器。在仓库根目录执行：

```bash
cmake -S . -B build
cmake --build build
```

构建目标为 `EmployeeManagementSystem`；多配置生成器通常将程序放在 `build/Debug/` 下。代码含 Windows 的 `cls` 等控制台命令，其他平台需要适配。运行前请检查文件读写路径，并备份 `empFile.txt`。
