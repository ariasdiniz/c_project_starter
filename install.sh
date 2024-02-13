#!/bin/bash

# Executing cmake and make
echo "Building software..."
cmake .

if [ $? != 0 ]; then
    echo "cmake failed. Exiting..."
    exit 1
fi

make

if [ $? != 0 ]; then
    echo "Build failed. Exiting..."
    exit 1
fi

echo "Build successful. Installing..."

# Copying the binary to /usr/local/bin
if [ ! -d ~/.local/bin ]; then
    mkdir -p ~/.local/bin
    if [ $? != 0 ]; then
        echo "Failed to create /usr/local/bin. Exiting..."
        make clean
        exit 1
    fi
fi

cp -f cgen ~/.local/bin

if [ $? != 0 ]; then
    echo "Failed to copy cgen to ~/.local/bin. Exiting..."
    make clean
    exit 1
fi

make clean

echo "Installation successful."