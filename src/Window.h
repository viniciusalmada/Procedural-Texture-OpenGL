#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H

#include <GLFW/glfw3.h>
#include "Shader.h"

namespace vinicius {

	class Window {
	public:
		int width;
		int height;
		GLFWwindow* window;

		Window();

		Window(int w, int h);

		void showWindow(Shader shader);
	};

}
using namespace vinicius;

Window::Window() : width(800), height(600),
				   window(glfwCreateWindow(width, height, "Textura Procedural", nullptr, nullptr)) {

}

Window::Window(int w, int h) : width(w), height(h),
							   window(glfwCreateWindow(w, h, "Textura Procedural", nullptr, nullptr)
							   ) {

}

void Window::showWindow(Shader shader) {
	while (!glfwWindowShouldClose(this->window)) {
		glfwPollEvents();

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.use();

		glfwSwapBuffers(this->window);
	}

	glfwTerminate();
}

#endif