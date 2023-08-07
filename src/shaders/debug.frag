#version 450
#extension GL_EXT_scalar_block_layout : enable
#define MAX_OBJ 512

layout(location = 5) in vec3 fragNormal;
layout(location = 6) in flat int mat;

layout(location = 0) out vec4 outColor;

layout(std430, binding = 0) uniform UniformBufferObject
{
  mat4 proj;
  mat4 view;
  mat4 model[MAX_OBJ];
} ubo;

void main() {
  vec3 result = vec3(1.0, 0.0, 1.0);
  
  if(mat == 1)
  {
    result = vec3(1.0, 1.0, 1.0);
  }
  else if(mat == 2)
  {
    vec3 lightDir = vec3(-1.0, 0.0, -1.0);

    float lighting = dot(-normalize(lightDir), fragNormal);

    result = vec3(1.0, 1.0, 1.0) * max(lighting, 0);
  }
  else if(mat == 3)
  {
    result = vec3(0.0, 0.0, 1.0);
  }

  outColor = vec4(result, 1.0);
}

