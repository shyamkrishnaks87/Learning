#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>

static void glfwError(int error, const char* description)
{
	std::cout << "Error : " << description << std::endl;
}

void main() 
{
	glfwSetErrorCallback(glfwError);
	GLFWwindow* window = nullptr;
	if (!glfwInit())
	{
		std::cout << "Error occurred while initializing GLFW" << std::endl;
		return;
	}
	window = glfwCreateWindow(640, 480, "Triangle", nullptr, nullptr);

	if (!window)
	{
		std::cout << "Error occurrec while creating window and initializing opengl context" << std::endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5, -0.5);
		glVertex2f(0.0, 0.5);
		glVertex2f(0.5, -0.5);
		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}