#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>

static void errorGLFW(int error, const char* description) {
	std::cout << "Error : " << description << std::endl;
}

void startWindow(std::string& title)
{
	glfwSetErrorCallback(errorGLFW);
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW." << std::endl;
		return;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, title.c_str(), nullptr, nullptr);
	if (!window) {
		std::cout << "Failed to create window and opengl context" << std::endl;
		return;
	}

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window)) 
	{
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
}

/*int main() {
	std::string title = "My sample GLFW Window";
	startWindow(title);
}*/