#pragma once

/*!
\file
\brief Заголовочный файл с описанием класса менеджера ресурсов
\author Краюшкин А.Ю.
\version 1.0
\date Январь 2024 года
*/

#include <string>
#include <memory>
#include <map>


namespace Renderer
{
	class ShaderProgram;
}

/*!
\class ResourceManager
\brief Класс менеджера ресурсов
*/
class ResourceManager {
public:

/*!
\fn ResourceManager(const std::string& executablePath);
\brief Конструктор. 
\param[in] executablePath - путь к ресурсам
*/
	ResourceManager(const std::string& executablePath);
/*!
\fn ~ShaderProgram();
\brief Деструктор. Удаляет менеджер ресурсов.
*/
	~ResourceManager() = default;

	ResourceManager(const ResourceManager&) = delete;
	ResourceManager(ResourceManager&&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&&) = delete;

/*!
\fn std::shared_ptr<Renderer::ShaderProgram> loadShaders(const std::string& sharedName, const std::string& vertexPath, const std::string& fragmentPath);
\brief функция загрузки шейдерной программы
\param[in] sharedName - имя шейдерной программы
\param[in] vertexPath - путь к вертексному шейдеру
\param[in] fragmentPath - путь к фрагментному шейдеру
\return указатель на шейдерную программу
*/
	std::shared_ptr<Renderer::ShaderProgram> loadShaders(const std::string& sharedName, const std::string& vertexPath, const std::string& fragmentPath);
/*!
\fn std::shared_ptr<Renderer::ShaderProgram> getShaderProgram(const std::string& sharedName);
\brief функция получения шейдера по его названию
\param[in] sharedName - имя шейдерной программы
\return указатель на шейдерную программу
*/
	std::shared_ptr<Renderer::ShaderProgram> getShaderProgram(const std::string& sharedName);


private:
	/* возвращает путь к файлу в формате string */
	std::string getFileString(const std::string& relativeFilePath);
	
	typedef std::map<const std::string, std::shared_ptr<Renderer::ShaderProgram>> ShaderProgramMaps;
	/* структура хранения шейдерных программ */
	ShaderProgramMaps m_shaderPrograms;
	/* путь к ресурсам */
	std::string m_path;
};	