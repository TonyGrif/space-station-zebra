.PHONY: all clean

all:
	${MAKE} build
	@cmake -S . -B build
	@cmake --build build

build:
	@echo "Creating build directory"
	@[ -d build ] || mkdir build

release:
	${MAKE} build
	@cmake -S . -B build -DBUILD_TESTING=OFF
	@cmake --build build

clean:
	@echo "Removing build directory"
	@rm -rf build/
	@rm -rf CMakeCache.txt CMakeFiles/
