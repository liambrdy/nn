#!/bin/sh

set -xe

# clang -O3 -Wall -Wextra -o nn nn.c -lm
# clang -O3 -Wall -Wextra -o adder adder.c -lm
clang -Wall -Wextra -o dump_nn dump_nn.c -lm