#version 400
layout(location = 0)in vec3 position;
layout(location = 1)in vec3 normal;
out vec4 worldPos;
out vec4 worldNorm;
out vec3 objectColor;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;
void main(void)
{
gl_Position = projectionMatrix*viewMatrix*modelMatrix*vec4(position, 1.0);
worldPos = modelMatrix*vec4(position, 1.0);
worldNorm = vec4(normalize(transpose(inverse(mat3(modelMatrix))) * normal), 1);
objectColor =  vec3(0.4, 0.6, 0.7);
}