#pragma once
#include<functional>
#include<iostream>

namespace test
{
	class Test 
	{
	public:
		Test(){}

		virtual ~Test(){}

		virtual void OnUpdate(float deltaTime) = 0;

		virtual void OnRender() = 0;

		virtual void  OnImGuiRender() = 0;
	};


	class TestMenu:public Test
	{
	public:
		TestMenu(Test*& currentTestPointer);

		~TestMenu();

		 void  OnImGuiRender()override;
		 void OnUpdate(float deltaTime) override;
		  void OnRender() override;

		 template<typename T>
		 void ResgisterTest(const std::string& name)
		 {
			 m_Tests.push_back(std::make_pair(name, []()
											 {
												 return new T();
											 }
			 ));
		 }

	private:
		Test*& m_CurrentTest;
		std::vector<std::pair<std::string, std::function<Test*()>>> m_Tests;
	};
}