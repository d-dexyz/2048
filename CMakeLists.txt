cmake_minimum_required(VERSION 3.16)
project(SFML_GAME2)


set(CMAKE_CXX_STANDARD 17)
include_directories("E:/install/msys64/ucrt64/include")

set(src
    sc/main.cpp
    sc/GameManager.cpp
    sc/GamePainter.cpp
    sc/Board.cpp
    sc/Tile.cpp
    sc/BasePainter.cpp
)
add_executable(${PROJECT_NAME} WIN32 ${src})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(SFML_GAME2
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)
