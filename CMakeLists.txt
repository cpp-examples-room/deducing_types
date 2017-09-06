cmake_minimum_required(VERSION 3.5.2)

include("gate/cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.18.52.tar.gz"
    SHA1 "b16c19e28aefbb83b02aa90bacf8350fc45ef7d0"
)

project(deducing_types)
include("config.cmake")
include("hunter.cmake")

add_executable(
    ${CMAKE_PROJECT_NAME}
    main.cpp
)

target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    ${BOOST}
)
