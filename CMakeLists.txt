cmake_minimum_required(VERSION 3.10)
project(Beaver)
set(CMAKE_C_STANDARD 99)

# Source files
file(GLOB_RECURSE Core_src CONFIGURE_DEPENDS "Core/*.c")
file(GLOB_RECURSE Include_src CONFIGURE_DEPENDS "Include/*.c")
file(GLOB_RECURSE Libs_src CONFIGURE_DEPENDS "Libs/*.c")
file(GLOB_RECURSE Modules_src CONFIGURE_DEPENDS "Modules/*.c")
set(SOURCE_FILES ${Core_src} ${Include_src} ${Libs_src} ${Modules_src})

# Create an executable
add_executable(Debug ${SOURCE_FILES})
add_executable(Beaver ${SOURCE_FILES})

# Output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set_target_properties(Debug Beaver
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build
)

# Add header files
include_directories(.)

# Compiler flags
add_compile_options(
	-Wall -Wextra -pedantic
	-I. -IInclude -IModules -ILibs -ICore
	-s -O2 -flto -static
	-fanalyzer -Wmaybe-uninitialized -Wmisleading-indentation
	-Wnull-dereference -Wrestrict)
# add_compile_options(-lm)

# Specific flags
target_compile_options(Debug PRIVATE -fsanitize=address -g -ggdb)
target_link_options(Debug PRIVATE -fsanitize=address -g -ggdb)

# Link -lm
target_link_libraries(Debug m)
target_link_libraries(Beaver m)

### MAIN: run ###
add_custom_target(run
	COMMAND Debug
	DEPENDS Debug
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

### MAIN: release ###
add_custom_target(release
	COMMAND Beaver
	COMMAND objcopy --strip-all ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Beaver
	DEPENDS Beaver
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

### STYLE: indent ###
add_custom_target(indent
	COMMAND indent ${SOURCE_FILES}
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

### MISC: archive ###
add_custom_target(archive
	COMMAND tar
		--exclude='./.git'
		--exclude='./CMakeFiles'
		--exclude='./CMakeCache.txt'
		--exclude='./cmake_install.cmake'
		--exclude='./doxygen_filter{,.cmo,.cmi}'
		--exclude='./build'
		--exclude='*~'
		-zcf build/beaver.tar.gz ./
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

### MISC: database ###
add_custom_target(database
	COMMAND compiledb make run --dry-run
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

### DOXYGEN: docs ###
add_custom_target(docs
	COMMAND doxygen
	DEPENDS dox-filter
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

### DOXYGEN: dox-filter ###
add_custom_target(dox-filter
	COMMAND ocamlc -I +str str.cma doxygen_filter.ml -o doxygen_filter
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
