#!/bin/bash
rm -rf tests
mkdir tests
cd tests
cmake ..
make test0
./test0
