#version 450
#extension GL_EXT_scalar_block_layout : enable
#define MAX_OBJ 512

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormal;
layout(location = 2) in vec2 inUV;
layout(location = 3) in int inObj;
layout(location = 4) in int inMat;

layout(location = 5) out vec3 fragNormal;
layout(location = 6) out flat int mat;

layout(std430, binding = 0) uniform UniformBufferObject
{
  mat4 proj;
  mat4 view;
  mat4 model[MAX_OBJ];
} ubo;

void main() {
  gl_Position = vec4(ubo.proj * ubo.view * ubo.model[inObj] * vec4(inPosition, 1.0));
  fragNormal = vec3(ubo.model[inObj] * vec4(inNormal, 1.0));
  mat = inMat;
}
