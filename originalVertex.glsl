#version 400
layout(location = 0) in vec3 vp;
layout(location = 1) in vec3 color;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
void main() {
  gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * vec4(vp, 1);

};