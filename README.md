# C++ 职工管理系统

基于控制台菜单的 C++ 学习项目，使用继承与多态表示普通员工、经理和老板，通过文件保存职工信息。适合结合源码学习抽象类、动态对象管理、查找排序以及文本持久化。

## 功能与菜单

| 选项 | 功能 | 对应实现 |
| --- | --- | --- |
| 0 | 退出系统 | `exitSystem()` |
| 1 | 添加职工 | `addWorker()` |
| 2 | 显示职工 | `show_emp()` |
| 3 | 删除职工 | `Del_Emp()` |
| 4 | 修改职工 | `Mod_Emp()` |
| 5 | 查找职工 | `Find_Emp()` |
| 6 | 排序 | `sort_Emp()` |
| 7 | 清空记录 | `clean_file()` |

这些功能从 [main.cpp](./main.cpp) 的菜单分支调用，核心管理逻辑集中在 [workerManager.cpp](./workerManager.cpp)。

## 代码结构与设计

| 文件 | 职责 |
| --- | --- |
| [work.h](./work.h) | `worker` 抽象基类，定义 `showInfo()`、`getDepName()` 与虚析构函数 |
| [employee.cpp](./employee.cpp) | 普通员工的具体实现 |
| [manager.cpp](./manager.cpp) | 经理的具体实现 |
| [boss.cpp](./boss.cpp) | 老板的具体实现 |
| [workerManager.h](./workerManager.h) | 管理类声明，维护人数与职工指针数组 |
| [workerManager.cpp](./workerManager.cpp) | 初始化、菜单操作、保存和恢复数据 |
| [test.cpp](./test.cpp) | 多态演示，依次创建三类职工并展示信息 |
| [empFile.txt](./empFile.txt) | 默认职工数据文件 |
| [CMakeLists.txt](./CMakeLists.txt) | 编译目标及 C++ 标准 |

启动时先构造管理对象并读取数据；随后执行 `test_1()` 展示三种角色，再进入菜单。因此第一次看到的角色信息可能来自演示代码，不一定是数据文件中的实际职工。

## 环境与构建

仓库构建配置要求 **CMake 3.31+**，使用 **C++20**。需要安装相应编译器，例如配置完成的 MSVC 或 MinGW。代码使用 `system("cls")` 等 Windows 控制台调用，跨平台运行前需要适配。

```bash
git clone --branch main https://github.com/heisd/employee_Management_System.git
cd employee_Management_System
cmake -S . -B build
cmake --build build --config Debug
```

CMake 目标名为 `EmployeeManagementSystem`。程序位置取决于生成器：

| 生成器类型 | 常见输出位置 |
| --- | --- |
| 单配置 | `build/EmployeeManagementSystem.exe` |
| Visual Studio 等多配置 | `build/Debug/EmployeeManagementSystem.exe` |

在 PowerShell 中使用 Visual Studio 生成器时，可从仓库根目录运行：

```powershell
.\build\Debug\EmployeeManagementSystem.exe
```

## 数据文件与工作目录

源码将文件名定义为 `empFile.txt`，它是相对于**进程当前工作目录**解析的。为了读取仓库自带数据，建议在仓库根目录启动程序；在 IDE 内运行时，也应将工作目录设置到这里。

操作流程可按“添加 → 显示 → 查找 → 修改 → 排序 → 退出并重启”验证。删除与清空操作会改变本地数据，试验前先复制 `empFile.txt`。

## 常见问题

| 现象 | 检查方式 |
| --- | --- |
| 提示文件不存在或人数为零 | 检查当前工作目录及 `empFile.txt` 是否存在、有内容 |
| 构建时提示 CMake 版本不足 | 核对 `cmake --version`，仓库最低要求为 3.31 |
| 中文显示异常 | 统一源文件与终端编码，检查编译器字符集配置 |
| 非 Windows 环境出现 cls 或 pause 相关错误 | 调整控制台命令；业务代码与终端行为需要分别检查 |
| 首次启动先输出三种职工 | 这是 `main.cpp` 显式调用的 `test_1()` 演示 |

本仓库是面向学习的文件式管理程序，没有数据库、网络接口或多用户并发管理。
