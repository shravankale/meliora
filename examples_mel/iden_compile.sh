#!/bin/bash

clang="/home/users/shravank/libs/llvm-14-meliora/bin/clang-14"
opt="/home/users/shravank/libs/llvm-14-meliora/bin/opt"

echo 'Enter kernel'
kernel=$1


/home/users/shravank/libs/llvm-14-meliora/bin/clang-14 -S -emit-llvm iden.c -fno-discard-value-names -Xclang -disable-O0-optnone -c -g -o iden.ll;
/home/users/shravank/libs/llvm-14-meliora/bin/opt -S -polly-canonicalize iden.ll -o iden.preopt.ll;

