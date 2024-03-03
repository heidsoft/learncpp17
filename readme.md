CLion和CMake允许你以灵活的方式组织你的源代码和项目。以下是一个基本的多程序项目的目录结构示例：

/my_project
CMakeLists.txt
/program1
CMakeLists.txt
main1.cpp
/program2
CMakeLists.txt
main2.cpp
在这个结构中，每个程序都有自己的子目录和一个CMakeLists.txt文件，这个文件定义了如何构建该程序。主CMakeLists.txt文件位于项目的根目录，用于定义全局的项目设置，并包含所有子项目。

以下是主CMakeLists.txt的一个基本示例：

cmake_minimum_required(VERSION 3.10)
project(my_project)

add_subdirectory(program1)
add_subdirectory(program2)
这个文件定义了项目名，并通过add_subdirectory命令包含了两个子项目。

以下是一个子CMakeLists.txt的基本示例：

add_executable(program1 main1.cpp)
这个文件定义了一个可执行目标，这个目标由main1.cpp文件构建。

通过这种方式，你可以为你的项目添加任意多的程序，每个程序都有自己的目录和CMakeLists.txt文件。当你在CLion中打开你的项目时，所有的程序都会被正确地识别和构建。