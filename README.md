# Doodle Jump
A recreation of the classic game Doodle Jump\
Dm for features

## Installation
This project can either be downloaded as a standalone binary from the releases page or built from source\
Note that this is an unsigned binary and will likely be flagged by Windows SmartScreen

### Building from source
To build this project from source, the only prerequisite you need is CMake and a C compiler such as GCC or Clang.\
\
The first step is to clone the repository:
```ps
git clone --recurse-submodules https://github.com/kdauntln/doodle-jump.git
```
Then create a ```build\``` directory for CMake
```ps
mkdir build
cd build
```
Then run CMake to build the executable and run it
```ps
cmake ..
cmake --build .
./debug/doodle-jump.exe
```
