#version 450

#define MAX_OBJ 1024

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormal;
layout(location = 2) in vec2 inUV;

layout(location = 4) out vec3 fragNormal;

layout(binding = 0) uniform UniformBufferObject
{
  mat4 proj;
  mat4 view;
  mat4 model[MAX_OBJ];
  int from[MAX_OBJ];
} ubo;

void main() {
  gl_Position = vec4(ubo.proj * ubo.view * ubo.model[0] * vec4(inPosition, 1.0));
  fragNormal = vec3(ubo.model[0] * vec4(inNormal, 1.0));
}
