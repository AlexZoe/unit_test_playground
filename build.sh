#!/bin/bash

mkdir -p build && \
cd build && \
cmake .. && \
make || exit 1;
