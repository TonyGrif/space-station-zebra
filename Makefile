.PHONY: all clean

all:
	@echo "Creating build directory"
	@[ -d build ] || mkdir build

clean:
	@echo "Removing build directory"
	@rm -rf build/
