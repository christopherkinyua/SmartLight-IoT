# Define the base source and include directories relative to the component directory
set(INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/Inc")
set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/Src")

# Recursively include all .c files in Src and its subdirectories
file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.c")

# Gather all directories in Inc, excluding files
file(GLOB INCLUDE_DIR_PATHS RELATIVE ${CMAKE_CURRENT_LIST_DIR} "${INCLUDE_DIRS}/*")
list(FILTER INCLUDE_DIR_PATHS INCLUDE REGEX ".*[^\\.h]$")
set(FINAL_INCLUDE_DIRS ${INCLUDE_DIRS} ${INCLUDE_DIR_PATHS})

# Register the component with ESP-IDF
idf_component_register(SRCS ${SRC_FILES}
                       INCLUDE_DIRS ${FINAL_INCLUDE_DIRS}
                       REQUIRES driver esp_timer freertos)