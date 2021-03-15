cmake_minimum_required(VERSION 3.5)

project(convert LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
#设置自动编译
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 日志模块
if (NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif ()
# 设置Qt包查找路径
find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

set(TS_FILES convert_zh_CN.ts)
set(TENGINE_COMMON_LIB_DIRS "${CMAKE_SOURCE_DIR}/libs")
link_directories(${TENGINE_COMMON_LIB_DIRS})

add_subdirectory(tools)
add_subdirectory(src)
add_subdirectory(protos)

add_executable(${PROJECT_NAME}
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${TS_FILES})


# 包含tengine动态库路径
link_directories(${TENGINE_COMMON_LIB_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets tengine-lite common spdlog::spdlog modelconfig)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
