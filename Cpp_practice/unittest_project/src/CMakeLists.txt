cmake_minimum_required(VERSION 3.16)

#get all of the source files
file(GLOB SRCS LIST_DIRECTORIES true *.hpp *.cpp) 
cmake_print_variables(${SRCS})
set(MAIN main) # separated so libs do not have main()
list(REMOVE_ITEM SRCS main.cpp)

# Name new libs to be included in the test
set(LIB_PRIME prime)
set(LIBS "${LIB_PRIME}" PARENT_SCOPE) # add new libs in the list
add_library(${LIB_PRIME} STATIC ${SRCS}) # creates *.a (STATIC) or *.so (SHARED)

# compile code only
add_executable(${MAIN} main.cpp ${SRCS})
target_link_libraries(${MAIN} PRIVATE ${LIBS})

# Define X to be a list of all cpp and hpp files
# file(GLOB_RECURSE X LIST_DIRECTORIES true *.hpp *.cpp) # error: multiple defn of main due to GLOB_RECURSE