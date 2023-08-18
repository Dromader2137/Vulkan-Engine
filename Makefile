CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
<<<<<<< HEAD
FILES = src/rendererInterface.cpp src/components.cpp src/renderer.cpp src/gameObject.cpp src/inputInterface.cpp src/main.cpp
=======
FILES = src/inputInterface.cpp src/rendererInterface.cpp src/components.cpp src/renderer.cpp src/gameObject.cpp src/main.cpp
>>>>>>> dev

VulkanEngine: $(FILES)
	g++ $(CFLAGS) -o VulkanEngine $(FILES) $(LDFLAGS)
	./compile.sh

.PHONY: test clean

test: VulkanEngine
	./VulkanEngine

clean:
	rm -f VulkanEngine
