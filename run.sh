#! /usr/bin/env bash

mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make && src/test_mtbound
