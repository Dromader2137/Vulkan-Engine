CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

VulkanEngine: src/main.cpp src/renderer.cpp
	g++ $(CFLAGS) -o VulkanEngine src/main.cpp src/renderer.cpp $(LDFLAGS)

.PHONY: test clean

test: VulkanEngine
	./VulkanEngine

clean:
	rm -f VulkanEngine
