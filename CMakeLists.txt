CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(ChessGame)

ADD_SUBDIRECTORY(tests/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

ADD_EXECUTABLE(test
    src/Position.cpp
    src/Game.cpp
    src/GameState.cpp
    src/GameAction.cpp
    src/Board.cpp
    src/Character.cpp
    src/Pawn.cpp
    src/King.cpp
    src/Knight.cpp
    src/Bishop.cpp
    src/Rook.cpp
    src/Queen.cpp
    src/Move.cpp
    src/QueenMove.cpp
    tests/test.cpp
    tests/GameTests.cpp
)

ADD_EXECUTABLE(chess
    src/Chess.cpp
    src/Position.cpp
    src/Game.cpp
    src/GameState.cpp
    src/GameAction.cpp
    src/Board.cpp
    src/Character.cpp
    src/Pawn.cpp
    src/King.cpp
    src/Knight.cpp
    src/Bishop.cpp
    src/Rook.cpp
    src/Queen.cpp
    src/Move.cpp
    src/QueenMove.cpp
)

TARGET_LINK_LIBRARIES(test gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
