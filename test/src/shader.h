#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <iostream>
#include <sstream>
#include <fstream>

class Shader{
public:
	Shader(){}
	Shader(const char* VertexPath, const char* FragmentPath) : VertexPath(VertexPath), FragmentPath(FragmentPath), ShaderProgram(0)
	{
		compileShader();
	}
	void compileShader();
	void checkCompileErrors(unsigned int shader, std::string type);
	GLuint getShaderProgram(){return ShaderProgram;}
	void useProgram();
private:
	const char* VertexPath;
	const char* FragmentPath;
	GLuint ShaderProgram;
};

#endif //SHADER_H