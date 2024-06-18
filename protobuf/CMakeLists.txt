
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
find_package(Protobuf REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR TRUE)
add_executable(main main.cpp person.proto address.proto)
target_link_libraries(main protobuf::libprotobuf)
protobuf_generate(TARGET main)
