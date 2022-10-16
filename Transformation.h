#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <stdlib.h>
#include <stdio.h>
#include "Shader.h"

class Transformation {
private:
	glm::mat4 transformationMatrix = glm::mat4(1.0f);;
public:
	
	Transformation();
	void passTransformationMatrix(Shader* shader);
	void translate(glm::vec3 delta);
	void scale(float scale);
	void rotate(float angel);
	~Transformation();
};