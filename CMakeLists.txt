cmake_minimum_required(VERSION 3.16)

project(E2EMsg VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

add_executable(E2EMsg
	src/main.c
	src/router/router.c

)

target_include_directories(E2EMsg PRIVATE
	${CMAKE_SOURCE_DIR}/deps/httpserver
	${CMAKE_SOURCE_DIR}/deps/httpserver/src
)

target_compile_definitions(E2EMsg PRIVATE
	EPOLL
	_GNU_SOURCE
	_POSIX_C_SOURCE=200809L
)
