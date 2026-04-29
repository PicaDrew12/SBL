cmake_minimum_required(VERSION 3.16)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS "include/*.h")

add_executable(SBL SBL.cpp ${SRC_FILES} ${HEADER_FILES})

target_include_directories(SBL PRIVATE "include")

set_property(TARGET SBL PROPERTY CXX_STANDARD 20)
