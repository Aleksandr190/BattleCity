#pragma once

/*!
\file
\brief Заголовочный файл с описанием классов и функций для отрисовки
\author Краюшкин А.Ю.
\version 1.0
\date Январь 2024 года
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

namespace Renderer {
	
/*!
\class ShaderProgram
\brief Класс создания шейдерных программ
*/
	class ShaderProgram {
	public:
/*!
\fn ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
\brief Конструктор. Создает шейдерную программу.
\param[in] vertexShader - ссылка на текст программы вертексного шейдера
\param[in] fragmentShader - ссылка на текст программы фрагментного(пиксельного) шейдера
*/
	    ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);


		/* запрет конструктора без параметров */
		ShaderProgram() = delete;
		/*запрет копирования*/
		ShaderProgram(const ShaderProgram&) = delete;
		ShaderProgram& operator=(const ShaderProgram&) = delete;

/*!
\fn ShaderProgram(ShaderProgram&& shaderProgram);
\brief Конструктор перемещения. Создает шейдерную программу, перемещая другой объект шейдерной программы.
\param[in] shaderProgram - rvalue-ссылка на перещаемый объект шейдерной программы.
*/
		ShaderProgram(ShaderProgram&& shaderProgram) noexcept;
/*!
\fn ShaderProgram& operator=(ShaderProgram&& shaderProgram);
\brief Перегрузка оператора присваивания с перемещением .Присваевает другой объект текущему объекту перемещая его.
\param[in] shaderProgram - rvalue - ссылка на перещаемый объект шейдерной программы.
*/
		ShaderProgram& operator=(ShaderProgram&& shaderProgram) noexcept;
		
		
/*!
\fn ~ShaderProgram();
\brief Деструктор. Удаляет шейдерную программу.
*/		
		~ShaderProgram();
/*!		
\fn bool isCompiled();
\brief функция информирует о том что компиляция шейдеров и сборка шейдерной программы прошла успешно
\return true - компиляция и сборка прошла успешно, false - шейдеры не скомпилировались или шейдерная программа не собралась
*/		
		bool isCompiled() const {return m_isCompiled;}

		void use() const;

		
	
	protected:
/*!		
\fn bool createShader(const std::string& source, const GLenum shaderType, GLuint& shaderID);
\brief функция создания шейдера
\param[in] source - ссылка на текст программы  шейдера
\param[in] shaderType - тип шейдер
\param[out] shaderID - идентификатор шейдера
\return true - компиляция прошла успешно, false - шейдер не скомпилировался
*/	
	    bool createShader(const std::string& source/*ссылка на массив строк*/, const GLenum shaderType/*тип шейдера*/, GLuint& shaderID/*идентификатор шейдера*/);
	    
	private:	
		bool m_isCompiled = false;
		GLuint m_ID;
	};
}