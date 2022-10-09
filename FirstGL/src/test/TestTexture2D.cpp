#include"TestTexture2D.h"
#include "GLCall.h"
#include "GL/glew.h"
#include "imgui/imgui.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Renderer.h"

namespace test
{
	TestTexture2D::TestTexture2D():
		m_Translation(0,0,0), m_Translation2(0,0,0),m_Proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),m_Proj2(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),
		m_View2(glm::translate(glm::mat4(1.0f), glm::vec3(-100, -100, 0))),m_View(glm::translate(glm::mat4(1.0f), glm::vec3(-100, -100, 0)))
	{
		float vertexAttrib[] = {
		100.0f,100.0f, 0.0f,0.0f,
		200.0f,100.0f, 1.0f,0.0f,
		200.0f,200.0f, 1.0f,1.0f,
		100.0f,200.0f, 0.0f,1.0f,

		/*-1.f,-1.f, 0.0f,0.0f,
		1.f,-1.f, 1.0f,0.0f,
		1.f,1.f, 1.0f,1.0f,
		-1.f,1.f, 0.0f,1.0f,*/


		/*-170,-380, 0.0f,0.0f,
		-370,-380, 1.0f,0.0f,
		-370,-580, 1.0f,1.0f,
		-170,-580, 0.0f,1.0f,*/
		};

		unsigned int indeces[] = {
			0,1,2,
			2,3,0
		};

		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		 m_Vb=std::make_unique<VertexBuffer>(vertexAttrib, sizeof(float) * 4 * 4);

		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		
		IndexBuffer ib(indeces, 6);

		m_Shader=std::make_unique<Shader>("res/shaders/Basic.shader");
		m_Vao=std::make_unique<VertexArray>();
		m_IndexBuffer = std::make_unique<IndexBuffer>(indeces, 6);

		m_Vao->AddBuffer(*m_Vb, layout);
		m_Texture=std::make_unique<Texture>("res/textures/wallpaperflare.com_wallpaper.png");

	}

	TestTexture2D::~TestTexture2D()
	{
	}


	void TestTexture2D::OnUpdate(float deltaTime)
	{
	}


	void TestTexture2D::OnRender()
	{
		GLCall(glClearColor(0.f,0.f,0.f,1));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		Renderer renderer;

		m_Texture->Bind();

		glm::mat4 model = glm::translate(glm::mat4(1.0f), m_Translation);
		glm::mat4 mvp = m_Proj * m_View * model;
		m_Shader->Bind();
		m_Shader->SetUniformMat4f("u_MVP", mvp);
		renderer.Draw(*m_Vao, *m_IndexBuffer, *m_Shader);


		glm::mat4 model2 = glm::translate(glm::mat4(1.0f), m_Translation2);
		glm::mat4 mvp2 = m_Proj2 * m_View2 * model2;
		m_Shader->Bind();
		m_Shader->SetUniformMat4f("u_MVP", mvp2);
		renderer.Draw(*m_Vao, *m_IndexBuffer, *m_Shader);
	}
	void TestTexture2D::OnImGuiRender()
	{
		ImGui::Begin("Hello, world!");                          

		ImGui::SliderFloat3("Translation", &m_Translation.x, 0.0f, 960.f);            
		ImGui::SliderFloat3("Translation2", &m_Translation2.x, 0.0f, 960.f);          

		ImGui::End();
	}
}