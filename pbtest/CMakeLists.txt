


add_executable(pbreader
		reader.cpp
		protos/Sample.pb.cc
		)

target_include_directories(pbreader  PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		)
target_link_libraries(pbreader  protobuflib)

########
add_executable(pbwriter
		writer.cpp
		protos/Sample.pb.cc
		)
target_link_libraries(pbwriter protobuflib)

target_include_directories(pbwriter  PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/../pb
		)
