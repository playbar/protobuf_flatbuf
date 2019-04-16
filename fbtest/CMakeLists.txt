


add_executable(fbreader
		reader.cpp
		protos/Sample.pb.cc
		)

target_include_directories(fbreader  PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		)
target_link_libraries(fbreader  protobuflib)

########
add_executable(fbwriter
		writer.cpp
		protos/Sample.pb.cc
		)
target_link_libraries(fbwriter protobuflib)

target_include_directories(fbwriter  PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/../pb
		)