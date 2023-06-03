#!/bin/sh

set -xe

clang -Wall -Wextra -o nn nn.c -lm
clang -Wall -Wextra -o adder adder.c -lm