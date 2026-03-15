cmake_minimum_required(VERSION 3.22)
project(pacman)

file(GLOB_RECURSE SOURCES source/*.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.2
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES}
        source/game/maze/RoomSide/Wall.cpp
        source/game/entities/Pacman.h
        source/game/entities/IStaticEntity.h
        source/game/entities/IDynamicEntity.h
        source/game/GameContext.h
        source/game/entities/Pacman.cpp
        source/game/entities/Food.h
        source/game/entities/Enemy.h
        source/game/entities/Enemy.cpp
        source/game/entities/Food.cpp
        source/game/GameContext.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)


