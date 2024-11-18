CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(tests/googletest)

ADD_EXECUTABLE(test
    src/Character.cpp
    src/Pawn.cpp
    src/King.cpp
    src/Knight.cpp
    src/Bishop.cpp
    src/Rook.cpp
    src/Queen.cpp
    tests/test.cpp
)

TARGET_LINK_LIBRARIES(test gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)