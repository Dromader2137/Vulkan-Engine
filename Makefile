CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
FILES = src/inputInterface.cpp src/rendererInterface.cpp src/components.cpp src/renderer.cpp src/gameObject.cpp src/main.cpp

VulkanEngine: $(FILES)
	g++ $(CFLAGS) -o VulkanEngine $(FILES) $(LDFLAGS)
	./compile.sh

.PHONY: test clean

test: VulkanEngine
	./VulkanEngine

clean:
	rm -f VulkanEngine
