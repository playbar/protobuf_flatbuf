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

########
add_executable(TestFlatWrite
		TestFlatWrite.cpp
		)
target_link_libraries(TestFlatWrite flatbuffers)

target_include_directories(TestFlatWrite  PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/../fb/include
		)

########
add_executable(TestFlatRead
		TestFlatRead.cpp
		)
target_link_libraries(TestFlatRead flatbuffers)

target_include_directories(TestFlatRead  PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/../fb/include
		)

########
add_executable(FlatBufferDemo
		FlatBufferDemo.cpp
		)
target_link_libraries(FlatBufferDemo flatbuffers)

target_include_directories(FlatBufferDemo  PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/../fb/include
		)

