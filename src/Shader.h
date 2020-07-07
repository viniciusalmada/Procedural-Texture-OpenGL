#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <string>
#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
	unsigned int compileShader(std::string filePath, int shaderType);

public:
	unsigned int program;

	Shader(std::string vertexPath, std::string fragPath);

	void use();
};

Shader::Shader(std::string vertexPath, std::string fragPath) {
	unsigned int vertexShader = compileShader(vertexPath, GL_VERTEX_SHADER);
	unsigned int fragShader = compileShader(fragPath, GL_FRAGMENT_SHADER);

	glLinkProgram(program);
	int success = 0;

	char infoLog[512];
	glGetProgramiv(this->program, GL_LINK_STATUS, &success);

	if (!success){
		glGetProgramInfoLog(this->program,512, nullptr, infoLog);
		std::cout << "ERROR: PROGRAM LINKING\n" << infoLog << std::endl;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragShader);
}

void Shader::use() {
	glUseProgram(this->program);
}

unsigned int Shader::compileShader(std::string filePath, int shaderType) {
	std::ifstream shaderFile;
	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);


	std::string shaderString;
	try {
		shaderFile.open(filePath);
		std::stringstream shaderStream;

		shaderStream << shaderFile.rdbuf();

		shaderFile.close();

		shaderString = shaderStream.str();
	} catch (std::ifstream::failure& ex) {
		std::cout << "ERROR: Compiling shader file: \n" << ex.what() << std::endl;
	}

	const char* shaderCode = shaderString.c_str();

	int success = 0;

	char infoLog[512];

	unsigned int shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderCode, nullptr);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, 512, nullptr, infoLog);
		std::cout << "ERROR: SHADER COMPILE\n" << infoLog << std::endl;
	}

	this->program = glCreateProgram();
	glAttachShader(this->program, shader);

	return shader;
}

#endif //OPENGL_SHADER_H
