file(GLOB_RECURSE SRC_FILES *.cpp *.h)

# ImGui
find_package(imgui REQUIRED)

add_executable(BaseProject ${SRC_FILES} ${IMGUI_SOURCES})

#add_subdirectory(external/imgui EXCLUDE_FROM_ALL)
#target_include_directories(BaseProject PRIVATE ${CMAKE_SOURCE_DIR}/external/imgui)
target_link_libraries(BaseProject imgui)


#unsucessifull test
#https://github.com/ocornut/imgui/archive/refs/tags/v1.90.8.tar.gz
#FetchContent_Declare(imgui_external
#	URL https://github.com/ocornut/imgui/archive/refs/tags/v1.91.9b.zip
#	EXCLUDE_FROM_ALL
#)
#FetchContent_MakeAvailable(imgui_external)

#add_library(imgui
#	${imgui_external_SOURCE_DIR}/imgui.cpp
#	${imgui_external_SOURCE_DIR}/imgui_draw.cpp
#	${imgui_external_SOURCE_DIR}/imgui_tables.cpp
#	${imgui_external_SOURCE_DIR}/imgui_widgets.cpp
#	${imgui_external_SOURCE_DIR}/backends/imgui_impl_allegro5.cpp
#)
#target_include_directories(imgui PUBLIC ${imgui_external_SOURCE_DIR})


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

# SDL (para ImGui + Loop)
find_package(SDL2 REQUIRED)
target_include_directories(BaseProject PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(BaseProject ${SDL2_LIBRARIES})

