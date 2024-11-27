set(target ${LIST_TESTS})

file(GLOB LIST_HEADERS "*.h*")
file(GLOB LIST_SOURCES "*.cpp")

add_executable(${target} ${LIST_SOURCES} ${LIST_HEADERS})
target_link_libraries(${target} gtest)
target_include_directories(${target} PUBLIC ${CMAKE_SOURCE_DIR}/gtest ${LIST_INCLUDE})
add_test(${target} ${target})