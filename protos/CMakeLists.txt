include(FindProtobuf)
# 查找 protobuf库文件
find_package(Protobuf REQUIRED)
if (PROTOBUF_FOUND)
    message("protobuf found")
else ()
    message(FATAL_ERROR "Cannot find Protobuf")
endif ()
# 将protobuf头文件添加到搜索路径
include_directories(${PROTOBUF_INCLUDE_DIR})
set(PROTOC_SRC_PATH ${CMAKE_CURRENT_LIST_DIR})

set_property(GLOBAL PROPERTY PROTO_SRCS_PATH "${PROTOC_SRC_PATH}")
file(GLOB PROTOBUF_SRC ${PROTOC_SRC_PATH}/*.proto)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

#protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTOBUF_SRC})
#protobuf_generate_cpp(${PROTO_SRCS} PROTO_HDRS EXPORT_MACRO DLL_EXPORT ${PROTOBUF_SRC})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS DESCRIPTORS PROTO_DESCS ${PROTOBUF_SRC})
set_property(GLOBAL PROPERTY PROTO_SRCS "${PROTO_SRCS}" )
set_property(GLOBAL PROPERTY PROTO_HDRS "${PROTO_HDRS}" )

message("===>PROTO SOURCE:"${Protobuf_LIBRARIES})

add_library(modelconfig SHARED ${PROTO_HDRS} ${PROTO_SRCS})
target_link_libraries(modelconfig ${Protobuf_LIBRARIES})
