set -e

cd /cygdrive/c/Users/jgonc/CLionProjects/AED/cmake-build-debug
/cygdrive/c/Users/jgonc/AppData/Local/JetBrains/CLion2024.3/cygwin_cmake/bin/cmake.exe --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
