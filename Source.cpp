#include "Aplication.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>  


int main(void)
{
	Aplication* app = Aplication::getApp();
	app->Run();
}
