cmake_minimum_required(VERSION 3.15)

project(test)

add_subdirectory(src)

add_compile_options(-g)

add_executable(${PROJECT_NAME} ex2.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)
# target_link_libraries(${PROJECT_NAME} PUBLIC Backward)
