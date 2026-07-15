cmake_minimum_required(VERSION 3.16)
project(oct408 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES src/*.cpp)

list(FILTER SOURCES EXCLUDE REGEX ".*/oxygen/.*")
list(FILTER SOURCES EXCLUDE REGEX ".*/jiuzhi/.*")
list(FILTER SOURCES EXCLUDE REGEX ".*/wandao/.*")

foreach(src ${SOURCES})
    get_filename_component(name ${src} NAME_WE)
    get_filename_component(dir ${src} DIRECTORY)
    file(RELATIVE_PATH rel_dir ${CMAKE_SOURCE_DIR} ${dir})
    string(REPLACE "/" "-" target_name ${rel_dir}/${name})
    add_executable(${target_name} ${src})
endforeach()
