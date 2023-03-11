cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

# This gives a name and version to the project.  It also creates
# two variables called wx_practice_VERSION_MAJOR and
# wx_practice_VERSION_MINOR.
project(wxExperiments VERSION 1.0)

# Reserved variable that says the C++ code works only on C++17 or later.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ExternalProject base
# Place the external project source and build here:
set_property(DIRECTORY PROPERTY EP_BASE ${CMAKE_BINARY_DIR}/subprojects)

# Install the external projects here:
set(STAGED_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/stage)

add_subdirectory(third_party)

include(ExternalProject)
ExternalProject_Add(${PROJECT_NAME}_core
  DEPENDS
    wxWidgets_external
  SOURCE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/src
  CMAKE_ARGS
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
    -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
    -DCMAKE_CXX_EXTENSIONS=${CMAKE_CXX_EXTENSIONS}
    -DCMAKE_CXX_STANDARD_REQUIRED=${CMAKE_CXX_STANDARD_REQUIRED}
    -DwxWidgets_ROOT_DIR=${wxWidgets_ROOT_DIR}
    -DENV_WX_CONFIG=${ENV_WX_CONFIG}
  CMAKE_CACHE_ARGS
    -DCMAKE_CXX_FLAGS:STRING=${CMAKE_CXX_FLAGS}
    -DCMAKE_PREFIX_PATH:PATH=${CMAKE_PREFIX_PATH}
  BUILD_ALWAYS
    1
  INSTALL_COMMAND
    ""
  )

#add_subdirectory(wxHello)

# WIN32 added tells to link against WinMain instead of main.
# add_executable(wx_hello WIN32 src/hello.cpp)

# target_include_directories(wx_hello PUBLIC
#                            "${PROJECT_BINARY_DIR}"
#                            )

# #set(wxWidgets_ROOT_DIR "F:/ProgramFiles/wxWidgets")
# set(wxWidgets_ROOT_DIR "../wxWidgets")
# #set(wxWidgets_LIB_DIR  "${wxWidgets_ROOT_DIR}/lib/vc_x64_dll")
# #set(wxWidgets_CONFIGURATION mswu)
# #set(wxWidgets_EXCLUDE_COMMON_LIBRARIES TRUE)

# find_package(wxWidgets REQUIRED core base OPTIONAL_COMPONENTS net)
# include(${wxWidgets_USE_FILE})
# target_link_libraries(wx_hello PRIVATE "${wxWidgets_LIBRARIES}")
# #target_link_options(wx_hello PRIVATE /entry:WinMainCRTStartup)
# #target_link_options(wx_hello PRIVATE /ENTRY:wWinMainCRTStartup)