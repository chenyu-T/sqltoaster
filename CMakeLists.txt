cmake_minimum_required(VERSION 3.28)

project(sqltoaster)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SQLTOASTER_SOURCES
    main.cc
    node.cc
    printer.cc
    node/statement.cc
)

#头文件路径
include_directories(E:/CAE/sqltoaster/include)
#链接库路径
link_directories(E:/CAE/sqltoaster/lib)
#添加可执行文件
add_executable(sqltoaster ${SQLTOASTER_SOURCES})
#链接sql-parse库
target_link_libraries(sqltoaster libsqltoast.a)
