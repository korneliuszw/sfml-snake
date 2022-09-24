cmake_minimum_required(VERSION 3.0)
project(sfml_snake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
find_package(SFML COMPONENTS graphics audio window REQUIRED)
include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
file (GLOB all_SRCS ${PROJECT_SOURCE_DIR}/include/*.hpp ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(sfml_snake src/main.cpp src/Game.cpp include/Game.hpp src/AssetManager.cpp include/AssetManager.hpp src/Snake.cpp include/Snake.hpp include/Entity.hpp src/SnakePart.cpp include/SnakePart.hpp src/AppleManager.cpp include/AppleManager.hpp src/BaseText.cpp include/BaseText.hpp src/ScoreText.cpp include/ScoreText.hpp src/GameOverText.cpp include/GameOverText.hpp src/Highscores.cpp src/Highscores.hpp)
target_link_libraries(sfml_snake sfml-graphics sfml-window sfml-audio)


