
# Build output setup
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/src/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/src/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/src/bin)

#get all of the source files
set(SRCS *.hpp *.cpp)

add_library(${LIBNAME} SHARED ${SRCS})

# set(BINARY ${CMAKE_PROJECT_NAME})
# file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.hpp *.cpp)
# set(SOURCES ${SOURCES})
# add_executable(${BINARY}_run ${SOURCES}) #The name of the compiled program will be ExampleProject_run,
# add_library(${BINARY}_lib STATIC ${SOURCES})#to include the code in the unit tests.