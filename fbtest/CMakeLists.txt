add_executable(fbreader
		fbreader.cpp
		)

target_include_directories(fbreader  PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/../fb/include
		)
target_link_libraries(fbreader  flatbuffers)

########
add_executable(fbwriter
		fbwriter.cpp
		)
target_link_libraries(fbwriter flatbuffers)

target_include_directories(fbwriter  PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/../fb/include
		)