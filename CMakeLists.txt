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
        source/user_interface/core/IDrawable.h
        source/user_interface/core/ISelectCommand.h
        source/user_interface/elements/Button.h
        source/utils/graphics/MyFont.h
        source/user_interface/elements/Menu.h
        source/user_interface/commands/ExitCommand.hpp
        source/user_interface/commands/GameCommand.h
        source/user_interface/ChangeStateCommand.h
        source/utils/config/GameConfig.hpp
        source/user_interface/elements/Menu.cpp
        source/user_interface/elements/Button.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics)


