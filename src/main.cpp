#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Shader.h"

int main() {
	glfwInit();
	glfwWindowHint(GLFW_RESIZABLE, false);

	auto window = Window();

	glfwMakeContextCurrent(window.window);

	glewExperimental = true;
	glewInit();

	glViewport(0, 0, window.width, window.height);

	glEnable(GL_DEPTH_TEST);

	auto vertexShader = Shader("shaders/vertex.glsl", "shaders/fragment.glsl");

	window.showWindow(vertexShader);

	return 0;
}
