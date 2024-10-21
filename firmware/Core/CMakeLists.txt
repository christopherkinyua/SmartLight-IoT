# Define the source and include directories
set(INCLUDE_DIRS Inc)
set(SRC_DIR Src)

# Automatically include all .c files in src
file(GLOB SRC_FILES "${SRC_DIR}/*.c")

# Register the component with ESP-IDF
idf_component_register(SRCS ${SRC_FILES}
                       INCLUDE_DIRS ${INCLUDE_DIRS}
                       REQUIRES driver)
