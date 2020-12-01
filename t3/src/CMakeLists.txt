#[[大坑:因为我生成的动态库不是系统默认的目录，所以我需要告诉cmake我库和头文件的位置
也就自然而然地写下这两句:
INCLUDE_DIRECTORIES(/tmp324/t3/usr/local/include/hello)
LINK_DIRECTORIES(/tmp324/t3/usr/local/lib)
一个寻找头文件
一个寻找库文件
源代码:

ADD_EXECUTABLE(mainew main.cpp)

INCLUDE_DIRECTORIES(/tmp324/t3/usr/local/include/hello)

LINK_DIRECTORIES(/tmp324/t3/usr/local/lib)

TARGET_LINK_LIBRARIES(mainew libhello.so)

然后死活报错:error while loading shared libraries: libXXX.so.X: cannot open shared object file: No such file

只要把ADD_EXECUTABLE(mainew main.cpp)这个生成可执行文件按照下面顺序就可
]]

## 调用安装lib/CMakeLists中通过install生成的路径
# 添加一个头文件搜索路径可以找到hello.h
#INCLUDE_DIRECTORIES(/tmp324/t3/usr/local/include/hello)
#
# 告诉链接库的地址
#LINK_DIRECTORIES(/tmp324/t3/usr/local/lib)

## 调用自己项目中本地的库文件
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)

# 生成可执行文件
ADD_EXECUTABLE(mainew main.cpp)

## #给目标添加依赖库，类似与gcc -l lib_name，此指令有两个用处，一个是给可执行文件添加库依赖，二是给库添加库依赖。
# 解决undefiled reference to 'HelloFunc()',因为我需要link到动态库libhello上去
# 此处Link的是可执行文件，也可以为自己编写的动态库添加动态库链接
TARGET_LINK_LIBRARIES(mainew libhello.so)


MESSAGE(STATUS “fewfwdewe2” ${DESTINATION})