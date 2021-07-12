cmake_minimum_required(VERSION 3.5)
project(ChessMind LANGUAGES CXX)

set(CMAKE_BUILD_TYPE Debug)

# Add local project module path so CMake includes custom CMake modules.
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

add_subdirectory(extra)
add_subdirectory(docopt)

add_library(helloworld_lib SHARED
    include/Imploder/ExploderInterface.hpp
    include/Imploder/ImploderInterface.hpp
    include/Imploder/ZipEntryInterface.hpp
    include/Imploder/Linux/ZipEntry.hpp
    include/Imploder/Linux/Exploder.hpp
    include/Imploder/Linux/FreeFormJS.hpp
    include/Imploder/Linux/Imploder.hpp
    include/NgMonitor/NgMonitor.hpp
    include/HelloWorld.hpp
	src/Imploder/Linux/Exploder.cpp
	src/Imploder/Linux/FreeFormJS.cpp
	src/Imploder/Linux/Imploder.cpp
	src/Imploder/Linux/ZipEntry.cpp
	src/NgMonitor/NgMonitor.cpp
	src/HelloWorld.cpp
)
add_library(helloworld::library ALIAS helloworld_lib)

target_include_directories(helloworld_lib
	PUBLIC
        ${PROJECT_SOURCE_DIR}/include
		src
)
target_compile_options(helloworld_lib
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			 -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)

#
# Create executable that uses the ChessMind lib to say Hello.
#
add_executable(helloworld
	src/main.cpp
)
target_link_libraries(helloworld
	PRIVATE
	    helloworld::library 
		docopt
		extra
)
target_compile_options(helloworld
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)

#
# Create executable that uses the ChessMind lib to say Hello.
#
add_executable(implode
	src/implode.cpp
)
target_link_libraries(implode
	PRIVATE
	    helloworld::library 
		docopt
		extra
)
target_compile_options(implode
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)

#
# Create executable that uses the ChessMind lib to say Hello.
#
add_executable(explode
	src/explode.cpp
)
target_link_libraries(explode
	PRIVATE
	    helloworld::library 
		docopt
		extra
)
target_compile_options(explode
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)

#
# Create executable that uses the ChessMind lib to say Hello.
#
add_executable(freeformjs
	src/FreeFormJS.cpp
)
target_link_libraries(freeformjs
	PRIVATE
	    helloworld::library 
		docopt
		extra
)
target_compile_options(freeformjs
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)

#
# Create a target for executing the Catch2 unit tests.
#
add_executable(run-unittests
	test/main.cpp
	test/test_FakeIt.cpp
	test/test_Directory.cpp
	test/test_Exploder.cpp
	test/test_FreeFormJS.cpp
	test/test_Imploder.cpp
	test/test_NgMonitor.cpp
	test/test_HelloWorld.cpp
)
target_include_directories(run-unittests
	PUBLIC
		test/
)
target_link_libraries(run-unittests
   helloworld::library 
   extra
)
# -Werror
target_compile_options(run-unittests
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			  -Wall -Wextra>
		$<$<CXX_COMPILER_ID:MSVC>:
			/W4>
)

############################################################
# Install
############################################################

# Binaries
install (TARGETS helloworld
    DESTINATION bin)

# Library
# Note: may not work on windows
install (TARGETS helloworld_lib
    LIBRARY DESTINATION lib)

# Header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ 
    DESTINATION include)

# Config
install (FILES cmake-examples.conf
    DESTINATION etc)

