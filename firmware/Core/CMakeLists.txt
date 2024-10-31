# Define the source and include directories
set(INCLUDE_DIRS Inc Inc/unit_tests)
set(SRC_DIR Src)

# Automatically include all .c files in Core/Src and Core/Src/unit_tests
file(GLOB SRC_FILES "${SRC_DIR}/*.c" "${SRC_DIR}/unit_tests/*.c")

# Register the component with ESP-IDF
idf_component_register(SRCS ${SRC_FILES}
                       INCLUDE_DIRS ${INCLUDE_DIRS}
                       REQUIRES driver esp_timer)