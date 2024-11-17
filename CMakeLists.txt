CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(tests/googletest)

ADD_EXECUTABLE(charactertest
    src/Character.cpp
    src/Board.cpp
    tests/test.cpp
)

TARGET_LINK_LIBRARIES(charactertest gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(charactertest PRIVATE gtest_disable_pthreads=ON)