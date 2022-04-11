cmake_minimum_required(VERSION 3.21)
project(nmea2000)

set(CMAKE_CXX_STANDARD 23)

include_directories(./NMEA2000/src)
add_subdirectory(./NMEA2000)

add_executable(nmea
        main.cpp
        )

target_link_libraries(nmea
        PRIVATE
        nmea2000
        )