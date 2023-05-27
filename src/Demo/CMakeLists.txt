cmake_minimum_required(VERSION 3.14)

include_directories(
    ${CMAKE_ROOT_DIR}/src/Demo/src
    ${CMAKE_ROOT_DIR}/inc
)

add_executable(${DEMO_EXEC_NAME} 
    Main.cpp
    Sort.cpp
)

target_link_libraries(${DEMO_EXEC_NAME} PRIVATE ${RACCOON_POT_LIBRARY})