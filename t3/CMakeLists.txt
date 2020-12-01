cmake_minimum_required(VERSION 3.1)

## 设置项目名称
#PROJECT(HELLOLIB)
## 指定编译输出位置,也就是本工程中动态库、静态库生成的位置:cmake-build-debug/lib
## 想要修改库文件生成位置就修改它 or 在lib/CMakeLists.txt中添加SET(LIBRARY_OUTPUT_PATH <路径>)指定1个新的位置
#ADD_SUBDIRECTORY(lib)
#
#MESSAGE(STATUS "432cvsdvsdv4csd3fwe2" ${CMAKE_INSTALL_PREFIX})

PROJECT(NEWHELLO)

# 调用xxx子目录的CMakeLists.txt执行
# 库文件生成和安装
ADD_SUBDIRECTORY(lib)

# ADD_SUBDIRECTORY会在build中创建相应目录，然后将相应cmakelists(一般里面都会有一个cmakelists)运行生成相应文件(动态库，静态库，可执行文件)
# 可执行文件main在此，cmake-build-debug/src
ADD_SUBDIRECTORY(src)


MESSAGE(STATUS “fewfwdewe1” ${DESTINATION})