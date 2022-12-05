#version 400
layout(location = 0) in vec3 vp;

out vec3 uv;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main() {
  gl_Position = (projectionMatrix * mat4(mat3(viewMatrix)) * vec4(vp, 1));
  uv = vp;

};