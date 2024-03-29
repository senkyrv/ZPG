#version 330
layout(location = 0) in vec3 vp;
layout(location = 1) in vec3 color;
layout(location = 2) in vec2 uv;
out vec2 uvc;
//out vec2 uv
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main() {
  gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * vec4(vp, 1);
  uvc = uv;
};
