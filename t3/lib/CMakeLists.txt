#message(${PROJECT_BINARY_DIR})
SET (LIBHELLO_SRC hello.cpp)

# 共享库文件生成位置
SET(LIBRARY_OUTPUT_PATH /home/ruiy/CMakeDemo/t3/cmake-build-debug/lib)

# 创建libhello.so的动态库
add_library(hello SHARED ${LIBHELLO_SRC})
# 创建libhello_static.a的动态库静态库
add_library(hello_static STATIC ${LIBHELLO_SRC})

# 保持静态库和动态库名字一样,都为libhello.x
SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME "hello")
GET_TARGET_PROPERTY(OUTPUT_VALUE hello_static OUTPUT_NAME)
MESSAGE(STATUS "This is the hello_static OUTPUT_NAME: " ${OUTPUT_VALUE})

# 防止构建静态库或者动态库时清理掉对方，因为cmake在构建一个新的target时，会尝试清理掉其他使用这个名字的库
SET_TARGET_PROPERTIES(hello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(hello PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# version指的是动态库版本，soversion指代API版本
# 会生成libhello.so,libhello.so.1,libhello.so.1.4
SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.4 SOVERSION 1)

# 需要将libhello.a,libhello.so.x以及hello.h安装到系统目录，才能让其他人开发使用
# 在cmake-build-debug中通过运行cmake -DCMAKE_INSTALL_PREFIX=/tmp324/t3/usr/local ..将CMAKE_INSTALL_PREFIX改为如上的目录(..表示cmake-build-debug的上一层目录)
# 可以通过在项目主路径下的CMakeLists.txt的MESSAGE(STATUS "432" ${CMAKE_INSTALL_PREFIX})查看路径
# 也可以通过直接在install之前SET(CMAKE_INSTALL_PREFIX /usr)这句话设置

# 安装步骤:1.在cmake-build-debug下make 2.继续make install 3.然后就能在<prefix>/lib目录和<prefix>/include/hello目录下看到文件了

# hello的两个库安装到了<prefix>/lib目录下
INSTALL(TARGETS hello hello_static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
# hello.h安装到了<prefix>/include/hello目录下
INSTALL(FILES hello.h DESTINATION include/hello)


MESSAGE(STATUS “fewfwdewe” ${DESTINATION})
