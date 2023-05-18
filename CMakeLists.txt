cmake_minimum_required(VERSION 3.1)
project(Meliora)
set(CMAKE_BUILD_TYPE "RelWithDebInfo")

#Windows ONLY
#set(LLVM_EXPORTED_SYMBOL_FILE ON)

#LLVM-14
#set(LLVM_DIR "/home/users/shravank/packages/llvm/build/lib/cmake/llvm/")
#set(LLVM_DIR "/home/users/shravank/libs/llvm14/lib/cmake/llvm/") LLVM14-no-rttti
set(LLVM_DIR "/home/users/shravank/libs/llvm-14-meliora/lib/cmake/llvm/")

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

#Add cmake folder from LLVM to search path
#list(APPEND CMAKE_MODULE_PATH ${LLVM_DIR})
#include(ChooseMSVCCRT)
#include(AddLLVM)

#Definitions and LLVM Paths
include_directories("${LLVM_INCLUDE_DIR}")
add_definitions("${LLVM_DEFINITIONS}")
link_directories("${LLVM_LIBRARY_DIR}")

message(STATUS "LLVM_INCLUDE_DIR:  ${LLVM_INCLUDE_DIR}")

#Meliora related include/source folders
include_directories(BEFORE include)
#include_directories(BEFORE "~/libs/llvm-14-meliora/include/polly/isl/")
add_subdirectory(lib)