.PHONY: all clean

all:
	@echo "Creating build directory"
	@[ -d build ] || mkdir build
	@cmake -S . -B build
	@cmake --build build

clean:
	@echo "Removing build directory"
	@rm -rf build/
