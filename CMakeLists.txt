cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

# This gives a name and version to the project.  It also creates
# two variables called wx_practice_VERSION_MAJOR and
# wx_practice_VERSION_MINOR.
project(wxExperiments VERSION 1.0)

# Reserved variable that says the C++ code works only on C++17 or later.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_VERBOSE_MAKEFILE False)  # Set to true to see details of the build

# Do not want shared.... for now.

set(wxBUILD_SHARED OFF)

# Build the third party dependencies and receive all of the targets.

add_subdirectory(third_party/wxWidgets)

# Build individual wxWidget applications.

add_subdirectory(wxHello)
