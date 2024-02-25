#pragma once

/*!
\file
\brief ������������ ���� � ��������� ������ ��������� ��������
\author �������� �.�.
\version 1.0
\date ������ 2024 ����
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
\brief ����� ��������� ��������
*/
class ResourceManager {
public:

/*!
\fn ResourceManager(const std::string& executablePath);
\brief �����������. 
\param[in] executablePath - ���� � ��������
*/
	ResourceManager(const std::string& executablePath);
/*!
\fn ~ShaderProgram();
\brief ����������. ������� �������� ��������.
*/
	~ResourceManager() = default;

	ResourceManager(const ResourceManager&) = delete;
	ResourceManager(ResourceManager&&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&&) = delete;

/*!
\fn std::shared_ptr<Renderer::ShaderProgram> loadShaders(const std::string& sharedName, const std::string& vertexPath, const std::string& fragmentPath);
\brief ������� �������� ��������� ���������
\param[in] sharedName - ��� ��������� ���������
\param[in] vertexPath - ���� � ����������� �������
\param[in] fragmentPath - ���� � ������������ �������
\return ��������� �� ��������� ���������
*/
	std::shared_ptr<Renderer::ShaderProgram> loadShaders(const std::string& sharedName, const std::string& vertexPath, const std::string& fragmentPath);
/*!
\fn std::shared_ptr<Renderer::ShaderProgram> getShaderProgram(const std::string& sharedName);
\brief ������� ��������� ������� �� ��� ��������
\param[in] sharedName - ��� ��������� ���������
\return ��������� �� ��������� ���������
*/
	std::shared_ptr<Renderer::ShaderProgram> getShaderProgram(const std::string& sharedName);


private:
	/* ���������� ���� � ����� � ������� string */
	std::string getFileString(const std::string& relativeFilePath);
	
	typedef std::map<const std::string, std::shared_ptr<Renderer::ShaderProgram>> ShaderProgramMaps;
	/* ��������� �������� ��������� �������� */
	ShaderProgramMaps m_shaderPrograms;
	/* ���� � �������� */
	std::string m_path;
};	