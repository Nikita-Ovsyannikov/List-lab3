set(target ${LIST_CUSTOM_PROJECT})
project(${target})

file(GLOB LIST_HEADERS "*.h*")

add_custom_target(${target} SOURCES ${LIST_HEADERS})