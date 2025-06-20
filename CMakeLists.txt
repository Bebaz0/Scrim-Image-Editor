cmake_minimum_required(VERSION 3.15)
project(project)

# Define your common flags here
set(COMMON_FLAGS "-g -Wall -pedantic -Wuninitialized -Werror")
set(COMMON_CXX_FLAGS "-std=c++17")

# Add sanitization flags if not on Windows
if(NOT WIN32)
    set(COMMON_FLAGS "${COMMON_FLAGS} -fsanitize=address -fsanitize=undefined")
endif ()

# Apply the flags globally
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS} ${COMMON_CXX_FLAGS} ${EXTRA}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_FLAGS} ${EXTRA}")

# Adds all .cpp files inside the 'src' folder, recursively
file(GLOB_RECURSE SOURCES_BASE CONFIGURE_DEPENDS "src/*.cpp")

# Create runscrim executable
add_executable(runscrim
        ${SOURCES_BASE}
        main/RunScrim.cpp
        include/Command/Invert.hpp
        src/Command/Invert.cpp
        include/Command/to_gray_scale.hpp
        src/Command/to_gray_scale.cpp
        include/Command/Fill.hpp
        src/Command/Fill.cpp
        include/Command/Add.hpp
        src/Command/Add.cpp
        include/Command/Move.hpp
        src/Command/Move.cpp
        include/Command/Slide.hpp
        src/Command/Slide.cpp
        include/Command/Crop.hpp
        src/Command/Crop.cpp
        include/Command/Chain.hpp
        src/Command/Chain.cpp
        include/Command/Mirror.hpp
        src/Command/Mirror.cpp
)

# Create tester executable
add_executable(tester
        ${SOURCES_BASE}
        main/Tester.cpp
        include/Command/to_gray_scale.hpp
        src/Command/to_gray_scale.cpp
        include/Command/Move.hpp
        src/Command/Move.cpp
        include/Command/Slide.hpp
        src/Command/Slide.cpp
        include/Command/Crop.hpp
        src/Command/Crop.cpp
        include/Command/Chain.hpp
        src/Command/Chain.cpp
)

target_include_directories(runscrim PRIVATE
        include
)
target_include_directories(tester PRIVATE
        include
)

# Add common linker flags
target_link_libraries(runscrim m)
target_link_libraries(tester m)

# List of files or directories to include in the zip
set(FILES_TO_ZIP ${CMAKE_SOURCE_DIR}/include ${SOURCES_BASE})

# Output zip file path
set(ZIP_FILE ${CMAKE_BINARY_DIR}/delivery.zip)

# Create the zip file using a custom command
add_custom_command(
    OUTPUT ${ZIP_FILE}
    COMMAND ${CMAKE_COMMAND} -E tar "cf" ${ZIP_FILE} --format=zip ${FILES_TO_ZIP}
    DEPENDS ${FILES_TO_ZIP}
    COMMENT "Creating zip archive: ${ZIP_FILE}"
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    VERBATIM
)

# Create a custom target that depends on the zip file
add_custom_target(delivery  # ALL # add ALL to update delivery.zip with every compilation
    DEPENDS ${ZIP_FILE}
)

# If you want to choose the compiler, when calling cmake use the following flags (clang in this case):
# cmake <path to CMakeLists.txt, usually ..> -D CMAKE_C_COMPILER=clang -D CMAKE_CXX_COMPILER=clang++ 

