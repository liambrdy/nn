#!/bin/sh

set -xe

export PKG_CONFIG_PATH="$HOME/opt/raylib/lib/pkgconfig/"

CFLAGS="-O3 -Wall -Wextra `pkg-config --cflags raylib`"
LIBS="-lm `pkg-config --libs raylib`"

#clang $CFLAGS -o xor xor.c -lm
#clang $CFLAGS -o adder adder.c $LIBS
#clang $CFLAGS -o dump_nn dump_nn.c -lm
# clang $CFLAGS -o adder_gen adder_gen.c $LIBS
# clang $CFLAGS -o xor_gen xor_gen.c $LIBS
clang $CFLAGS -o gym gym.c $LIBS
