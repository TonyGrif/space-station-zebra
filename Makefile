.PHONY: all test build clean

all:
	${MAKE} build
	@cmake -S . -B build -DBUILD_TESTING=OFF
	@cmake --build build

test:
	${MAKE} build
	@cmake -S . -B build -DBUILD_TESTING=ON
	@cmake --build build
	@cd build && ctest --output-on-failure

build:
	@echo "Creating build directory"
	@[ -d build ] || mkdir build

clean:
	@echo "Removing build directory"
	@rm -rf build/
	@rm -rf CMakeCache.txt CMakeFiles/
