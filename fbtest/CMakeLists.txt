add_executable(fbreader
		reader.cpp
		)

target_include_directories(fbreader  PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/../fb/include
		)
target_link_libraries(fbreader  protobuflib)

########
add_executable(fbwriter
		writer.cpp
		)
target_link_libraries(fbwriter protobuflib)

target_include_directories(fbwriter  PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/../fb/include
		)