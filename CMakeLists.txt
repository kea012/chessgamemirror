CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(tests/googletest)

ADD_EXECUTABLE(test
    src/Character.cpp
    src/Pawn.cpp
    src/Queen.cpp
    src/Bishop.cpp
    tests/test.cpp
)

TARGET_LINK_LIBRARIES(test gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)