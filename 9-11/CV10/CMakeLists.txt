cmake_minimum_required(VERSION 3.16)

project(OpenMP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP REQUIRED)

add_executable(OpenMP main.cpp)

if(OpenMP_CXX_FOUND)
    target_link_libraries(OpenMP PUBLIC OpenMP::OpenMP_CXX)
endif()

include(GNUInstallDirs)
install(TARGETS OpenMP
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
