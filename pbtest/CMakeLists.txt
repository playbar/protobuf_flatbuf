######
add_executable(pbreader
		reader.cpp
		protos/Sample.pb.cc
		)

target_include_directories(pbreader  PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		)
target_link_libraries(pbreader  protobuf)

########
add_executable(pbwriter
		writer.cpp
		protos/Sample.pb.cc
		)
target_link_libraries(pbwriter protobuf)

target_include_directories(pbwriter  PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/../pb
		)

##########
set(data_write_SRCS
		data_write.cc
		protos/data.pb.cc)
add_executable(data_write ${data_write_SRCS})
target_include_directories(data_write  PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/../pb
		${CMAKE_CURRENT_SOURCE_DIR}/protos
		${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(data_write protobuf)

#######
set(data_read_SRCS
		data_read.cc
		protos/data.pb.cc)
add_executable(data_read ${data_read_SRCS})
target_include_directories(data_read  PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/../pb
		${CMAKE_CURRENT_SOURCE_DIR}/protos
		${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(data_read protobuf)