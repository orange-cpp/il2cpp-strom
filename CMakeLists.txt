cmake_minimum_required(VERSION 3.29)


project(il2cpp_storm)

set(CMAKE_CXX_STANDARD 26)

add_library(il2cpp_storm STATIC
        include/il2cpp_storm/unity/Camera.hpp
        source/Camera.cpp
        include/il2cpp_storm/api/GameAssembly.h
        source/GameAssembly.cpp
        test/TestDll.cpp)

add_subdirectory(source)
add_subdirectory(test)
add_subdirectory(minhook-master)

target_include_directories(il2cpp_storm PUBLIC include)
target_link_libraries(il2cpp_storm PUBLIC minhook)