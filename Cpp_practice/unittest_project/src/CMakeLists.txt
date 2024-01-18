cmake_minimum_required(VERSION 3.16)

#get all of the source files
file(GLOB SRCS *.hpp *.cpp) 
set(LIB_PRIME prime)

add_library(${LIB_PRIME} STATIC ${SRCS}) # creates *.a (STATIC) or *.so (SHARED) to be used by Googletest
add_executable(prime_src ${SRCS})
# Define SOURCES to be a list of all cpp and hpp files
# file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.hpp *.cpp) # error: multiple defn of main