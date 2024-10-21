# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly

# Minimum required version for CMake
cmake_minimum_required(VERSION 3.5)

# Set the component directory to include the renamed core folder
set(EXTRA_COMPONENT_DIRS "${CMAKE_SOURCE_DIR}/core")

# Include the project definition
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Define the project name
project(firmware)

