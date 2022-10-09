#pragma once


#include <string>


class Texture
{
private :
	unsigned int m_RendererID;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
	std::string m_FilePath;
public :
	Texture(const std::string& path);
	~Texture();
	void Bind(unsigned int slot=0)const; // slot - texture unit
	void UnBind()const;


	inline int GetWidth()const
	{
		return m_Width;
	}
	inline int GetHeight()const
	{
		return m_Height;
	}
};


