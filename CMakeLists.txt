CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(tests/googletest)

ADD_EXECUTABLE(pawntest
    src/Character.cpp
    src/Pawn.cpp
    tests/test.cpp
)

TARGET_LINK_LIBRARIES(pawntest gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(pawntest PRIVATE gtest_disable_pthreads=ON)