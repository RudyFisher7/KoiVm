cmake_minimum_required(VERSION 3.13)
project(KoiVMDebug)

add_executable(${PROJECT_NAME}
    debug.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    KoiVM
)
