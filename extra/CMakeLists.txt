 
add_library(
    extra SHARED
	include/ansi_colors.hpp
	include/ansi_input.hpp
	include/crc16_support.hpp
	include/crc32_support.hpp
	include/crc64_support.hpp
	include/Directory.hpp
	include/octal_support.hpp
	include/string_support.hpp
	src/ansi_colors.cpp
	src/crc16.cpp
	src/crc32.cpp
	src/crc64.cpp
	src/Directory.cpp
	src/string_support.cpp
)

 target_include_directories(extra PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

 target_compile_definitions(extra INTERFACE EXTRA_VERSION=1)
