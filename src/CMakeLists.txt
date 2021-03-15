include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB ENGINE_SRC ${CMAKE_SOURCE_DIR}/src/*.c)
add_library(common SHARED ${ENGINE_SRC})