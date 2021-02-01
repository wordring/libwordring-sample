# sample/html/clawl
#
# このプロジェクトは clawl サンプルを作成します。

cmake_minimum_required (VERSION 3.12)

project("html-clawl-sample")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories ("${CMAKE_SOURCE_DIR}/libwordring/include")
add_definitions(-DCURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME}	"crawl.cpp")
target_link_libraries(${PROJECT_NAME} "wordring")
