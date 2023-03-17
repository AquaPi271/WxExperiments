cmake_minimum_required(VERSION 3.25)

# This gives a name and version to the project.  It also creates
# two variables called wx_practice_VERSION_MAJOR and
# wx_practice_VERSION_MINOR.
project(wx_hello VERSION 1.0)

# Reserved variable that says the C++ code works only on C++17 or later.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# WIN32 added tells to link against WinMain instead of main.
add_executable(wx_hello WIN32 src/hello.cpp)

target_link_libraries(wx_hello wx::core wx::base wx::net)
