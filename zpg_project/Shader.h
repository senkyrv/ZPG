#pragma once
#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>

class Shader
{
private:
	GLuint shaderProgram;

public:
	const char* vertex_shader =
		"#version 330\n"
		"layout(location=0) in vec3 in_position;"
		"layout(location=1) in vec3 in_color;"
		"out vec3 color;"
		"uniform mat4 modelMatrix;"
		"void main () {"
		"     gl_Position = modelMatrix * vec4 (in_position, 1.0);"
		"     color = in_color;"
		"}";

	const char* fragment_shader =
		"#version 330\n"
		"out vec4 frag_colour;"
		"in vec3 color;"
		"void main () {"
		"     frag_colour = vec4 (color, 1.0);"
		"}";

	Shader();
	~Shader();
	GLuint getShaderProgram();
};

