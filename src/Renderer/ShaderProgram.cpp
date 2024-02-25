#include "ShaderProgram.h"
#include <iostream>

namespace Renderer {
	
ShaderProgram::ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader)
{
	/* создаем вертексный шейдер */
	GLuint vertexShaderID;
	
	if(!createShader(vertexShader,GL_VERTEX_SHADER,vertexShaderID))
	{
		std::cerr << "VERTEX::SHADER::Compile-time error\n"<<std::endl;
		return;
	}
	
	/* создаем фрагментный шейдер */
	GLuint fragmentShaderID;
	
	if(!createShader(fragmentShader,GL_FRAGMENT_SHADER, fragmentShaderID))
	{
		std::cerr << "FRAGMENT::SHADER::Compile-time error\n"<<std::endl;
		glDeleteShader(fragmentShaderID);
		return;
	}
	
	/* создаем шейдерную программу */
	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertexShaderID);
	glAttachShader(m_ID, fragmentShaderID);
	glLinkProgram(m_ID);
	
	/* проверка сборки шейдерной программы */	
	GLint success;
	glGetProgramiv(m_ID, GL_LINK_STATUS,&success);

	if(!success)
	{
		GLchar infoLog[1024];
		glGetShaderInfoLog(m_ID, 1024, nullptr, infoLog);
		std::cerr << "ERROR::SHADER::Link-time error:\n" << infoLog << std::endl;
	}
	else
	{
		m_isCompiled = true;
	}
	
    /* удаление шейдеров */	
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}


ShaderProgram::ShaderProgram(ShaderProgram&& shaderProgram) noexcept
{
	m_ID = shaderProgram.m_ID;
	m_isCompiled = shaderProgram.m_isCompiled;

	shaderProgram.m_ID = 0;
	shaderProgram.m_isCompiled = false;
}

ShaderProgram& ShaderProgram::operator=(ShaderProgram&& shaderProgram) noexcept
{
	glDeleteProgram(m_ID);
	m_ID = shaderProgram.m_ID;
	m_isCompiled = shaderProgram.m_isCompiled;

	shaderProgram.m_ID = 0;
	shaderProgram.m_isCompiled = false;

	return *this;
}



ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(m_ID);
}

void ShaderProgram::use() const
{
	glUseProgram(m_ID);
}




bool ShaderProgram::createShader(const std::string& source, const GLenum shaderType, GLuint& shaderID)
{
	/* создаем фрагментный шейдер */
	shaderID = glCreateShader(shaderType/* тип шейдера */);
	const char* code = source.c_str();
	/* передаем шейдеру исходный код */
	glShaderSource(shaderID, 1, &code, nullptr);
	/* компилируем шейдер */
	glCompileShader(shaderID);
	
	/* проверка компиляции */	
	GLint success;
	
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

    if (!success)
    {
		GLchar infoLog [1024];
        glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::Compile-time error\n" << infoLog << std::endl;
		return false;
    }
	
	return true;
}	




}