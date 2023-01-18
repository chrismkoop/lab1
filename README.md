# Lab 1

This is a stub for CST276 Lab1. You will be building on top of this.

## Setup

Be sure to have CMake, a C++ compiler, and a text editor installed.

### Windows

Install the latest version of Visual Studio. This ensures you have the proper compiler and libs set up.

### Linux (or WSL2)

In this repo, run `bash setup.sh` to install all of the pre-reqs.

### macOS

Run `xcode-select --install` to be sure you have the latest command line tools.
Then, install Homebrew at https://brew.sh

After install Homebrew, run `brew install cmake sfml` in your terminal.

## Running

In this directory:

```bash
cmake -B build -S .
cmake --build build
./build/Lab1
```

If using Visual Studio, you should only need to run the first command. Then you can use Visual Studio as normal. That is, Visual Studio has CMake integration, and it should run the other commands for you. There may be a way to have it run all of the commands. I have not yet tested this.

