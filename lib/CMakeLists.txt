include_directories("../script")

set(CMAKE_BUILD_TYPE "RelWithDebInfo")
# begin boost
set(BOOST_ROOT "/home/users/shravank/packages/boost_175")
find_package(Boost COMPONENTS python36 REQUIRED)
#set(Python3_INCLUDE_DIRS "/usr/include/python3.6/")
#set(Python3_LIBRARIES "/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu/libpython3.6.so")

set(Python3_INCLUDE_DIRS "/usr/include/python3.10/")
set(Python3_LIBRARIES "/usr/lib/python3.10/config-3.10-x86_64-linux-gnu/libpython3.10.so")

message("TESTS")

message("PYTHON_LIBRARIES - ${Python3_LIBRARIES}")
message("BOOST_LIBRARIES_DIR - ${Boost_LIBRARY_DIRS}")
message("BOOST_LIBRARIES - ${Boost_LIBRARIES}")
message("PYTHON_INCLUDE_DIRS - ${Python3_INCLUDE_DIRS}")
message("Boost_INCLUDE_DIR - ${Boost_INCLUDE_DIR}")
#//end boost ]]

#Fixes the boost warnings regarding placeholders
add_definitions(-DBOOST_BIND_GLOBAL_PLACEHOLDERS)
#add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

# begin boost
set(LF1 "-Wl,-rpath,${Boost_LIBRARY_DIRS}")
set(LF2 "-Wl,-rpath,${Python3_LIBRARIES}")
#]]

add_library(Meliora MODULE Meliora_loopTests.cpp)
#add_llvm_loadable_module(Meliora MODULE Meliora.cpp)


set(Polly_SRC "~/libs/llvm-14-meliora/include/polly")
set(Polly_Lib_SRC "~/libs/llvm-14-meliora/lib/LLVMPolly.so")

#Boost Include
# // begin boost
target_include_directories(Meliora PRIVATE ${Python3_INCLUDE_DIRS} PRIVATE ${Boost_INCLUDE_DIR})
target_include_directories(Meliora PRIVATE ${Polly_SRC})
message("Polly: ${Polly}")
target_link_libraries(Meliora PRIVATE ${Boost_LIBRARIES} ${LF1})
target_link_libraries(Meliora PRIVATE ${Python3_LIBRARIES} ${LF2})
#target_link_libraries(Meliora PRIVATE ${Polly_Lib_SRC})
#]]

target_link_libraries(Meliora PRIVATE stdc++fs)
target_compile_features(Meliora PRIVATE cxx_range_for cxx_auto_type)

