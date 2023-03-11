cmake_minimum_required(VERSION 3.25)

# This gives a name and version to the project.  It also creates
# two variables called wx_practice_VERSION_MAJOR and
# wx_practice_VERSION_MINOR.
project(wx_practice VERSION 1.0)

#configure_file(wx_practice_config.h.in wx_practice_config.h)

# Reserved variable that says the C++ code works only on C++17 or later.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# WIN32 added tells to link against WinMain instead of main.
add_executable(wx_hello WIN32 src/hello.cpp)

target_include_directories(wx_hello PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

#set(wxWidgets_ROOT_DIR "F:/ProgramFiles/wxWidgets")
set(wxWidgets_ROOT_DIR "../wxWidgets")
#set(wxWidgets_LIB_DIR  "${wxWidgets_ROOT_DIR}/lib/vc_x64_dll")
#set(wxWidgets_CONFIGURATION mswu)
#set(wxWidgets_EXCLUDE_COMMON_LIBRARIES TRUE)

find_package(wxWidgets REQUIRED core base OPTIONAL_COMPONENTS net)
include(${wxWidgets_USE_FILE})
target_link_libraries(wx_hello PRIVATE "${wxWidgets_LIBRARIES}")
#target_link_options(wx_hello PRIVATE /entry:WinMainCRTStartup)
#target_link_options(wx_hello PRIVATE /ENTRY:wWinMainCRTStartup)