cmake_minimum_required(VERSION 3.4)

project(protobuf_flatbuf LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -ftemplate-depth=1024 -fPIC -fvisibility=hidden -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wno-variadic-macros -Wno-unknown-pragmas -Wno-unused-parameter")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -fvisibility=hidden -Wall -Wextra -Wshadow -Wno-variadic-macros -Wno-unknown-pragmas")

ADD_DEFINITIONS(-DRAPIDJSON_HAS_STDSTRING)
ADD_DEFINITIONS(-DLIBICONV_PLUG)
#ADD_DEFINITIONS(-DGOOGLE_PROTOBUF_NO_RTTI)

add_subdirectory(fb)
add_subdirectory(pbtest)
#add_subdirectory(pb)
add_subdirectory(pbnew)
add_subdirectory(fbtest)

