.PHONY: all test build clean format tidy lint

SOURCES := $(wildcard main.cpp src/*.cpp)
HEADERS := $(wildcard include/station/*.h)
TEST_SOURCES := $(wildcard tests/*.cpp)

all:
	${MAKE} build
	@cmake -S . -B build -DBUILD_TESTING=OFF
	@cmake --build build

test:
	${MAKE} build
	@cmake -S . -B build -DBUILD_TESTING=ON -DENABLE_COVERAGE=ON
	@cmake --build build
	@cd build && ctest --output-on-failure
	@gcovr --root . --filter 'src/' --filter 'include/' --exclude-unreachable-branches --print-summary build

build:
	@echo "Creating build directory"
	@[ -d build ] || mkdir build

clean:
	@echo "Removing build directory"
	@rm -rf build/
	@rm -rf CMakeCache.txt CMakeFiles/

format:
	@clang-format -i $(SOURCES) $(HEADERS) $(TEST_SOURCES)

tidy:
	${MAKE} build
	@cmake -S . -B build -DBUILD_TESTING=OFF -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	@clang-tidy -p build $(SOURCES)

lint: format tidy
