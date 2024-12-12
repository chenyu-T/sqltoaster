cmake_minimum_required(VERSION 3.28)

project(sqltoaster)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#源文件列表
set(SQLTOASTER_SOURCES
    src/node.cc
    src/printer.cc
    src/statement.cc
)
#头文件列表
set(SQLTOASTER_HEADERS
    include/fill.h
    include/measure.h
    include/node.h
    include/printer.h
    include/get_tbname.h
)

#本项目头文件路径
include_directories(include)

#设置依赖库头文件路径，让编译器找到依赖库头文件
include_directories(pkg/sqltoast/include)

#设置链接依赖库路径，让链接器找到依赖库
link_directories(pkg/sqltoast/lib)

#创建静态库
add_library(sqltoaster STATIC ${SQLTOASTER_SOURCES} ${SQLTOASTER_HEADERS})

#添加可执行文件
add_executable(sqltest ${SQLTOASTER_SOURCES} ${SQLTOASTER_HEADERS} src/main.cpp)

#链接依赖库到静态库中
target_link_libraries(sqltoaster PUBLIC libsqltoast.a)

#链接依赖库到可执行文件中
target_link_libraries(sqltest PUBLIC libsqltoast.a)


