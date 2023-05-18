#!/bin/bash

clang="/home/users/shravank/libs/llvm-14-meliora/bin/clang-14"
opt="/home/users/shravank/libs/llvm-14-meliora/bin/opt"


kernel=$1
file=${kernel%.*}
extension=${kernel##*.}

echo "File: $file"
echo "Extension: $extension"

$clang -S -emit-llvm $kernel -fno-discard-value-names -Xclang -disable-O0-optnone -c -g -o $file.ll
$opt -S -polly-canonicalize $file.ll -o $file.preopt.ll
$opt -polly-use-llvm-names -basic-aa -polly-scops -analyze $file.preopt.ll -polly-process-unprofitable

