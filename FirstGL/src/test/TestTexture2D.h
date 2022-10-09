#pragma once


#include"Test.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Texture.h"
#include <memory>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.h"


namespace test
{
	class TestTexture2D :public Test
	{
	public:
		TestTexture2D();
		~TestTexture2D();

		void OnUpdate(float deltaTime)override;
		void OnRender() override;
		void  OnImGuiRender() override;

	private:
		std::unique_ptr<VertexArray>m_Vao;
		std::unique_ptr <IndexBuffer> m_IndexBuffer;
		std::unique_ptr <Shader> m_Shader;
		std::unique_ptr <Texture> m_Texture;
		std::unique_ptr <VertexBuffer> m_Vb;
		glm::vec3 m_Translation;
		glm::vec3 m_Translation2;

		glm::mat4 m_Proj;
		glm::mat4 m_View;
		glm::mat4 m_Proj2;
		glm::mat4 m_View2;
	};



}