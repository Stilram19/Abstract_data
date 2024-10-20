# define the build directory
BUILD_DIR=build

all: build build_project

# create the build directory and run CMake
build:
	@mkdir -p $(BUILD_DIR)
	cmake -S . -B $(BUILD_DIR)

# build the project
build_project:
	cmake --build $(BUILD_DIR)

# run_tests: build_project
# 	ctest --test-dir $(BUILD_DIR)

unit_vector:
	(cd $(BUILD_DIR) && ctest --verbose test_vector_unit)

# clean the build directory
clean:
	rm -rf $(BUILD_DIR)

re: clean all

.PHONY: all build build_project run_tests clean
