set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SRC_FILES *.cpp *.h)

add_executable(BaseProject ${SRC_FILES} ${IMGUI_SOURCES})

# ImGui
target_include_directories(BaseProject PRIVATE
  ${CMAKE_SOURCE_DIR}/external/imgui
  ${CMAKE_SOURCE_DIR}/external/imgui/backends
  ${SDL2_INCLUDE_DIRS})
target_link_libraries(BaseProject imgui)

# Crow
find_package(Crow CONFIG REQUIRED)
target_link_libraries(BaseProject Crow::Crow)

#GTest
#find_package(GTest REQUIRED)
#target_link_libraries(BaseProject GTest::gtest_main)

#Thread
find_package(Threads REQUIRED)
target_link_libraries(BaseProject Threads::Threads)

# SQLite
find_package(SQLite3 REQUIRED)
target_link_libraries(BaseProject SQLite::SQLite3)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(BaseProject OpenGL::GL)

# SDL (para ImGui + Loop)
find_package(SDL2 REQUIRED)
target_include_directories(BaseProject PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(BaseProject SDL2::SDL2)
