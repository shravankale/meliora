
# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_COMPILER "/home/users/shravank/libs/llvm-14-meliora/bin/clang++")

add_executable(stack_test src/stack_test.cpp)
target_include_directories(stack_test PRIVATE include)