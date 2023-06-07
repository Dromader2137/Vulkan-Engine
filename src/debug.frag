#version 450

layout(location = 4) in vec3 fragNormal;

layout(location = 0) out vec4 outColor;

void main() {
  vec3 normal = normalize(fragNormal);
  
  float lighting = dot(vec3(1.0, 0.0, 0.0), normal);

  vec3 color = vec3(lighting, lighting, lighting);

  outColor = vec4(color, 1.0);
}

