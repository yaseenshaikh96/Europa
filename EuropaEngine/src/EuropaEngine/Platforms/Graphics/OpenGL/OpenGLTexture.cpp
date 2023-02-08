#include "EuropaEnginePCH.h"
#include "OpenGLTexture.h"

#include <glad/glad.h>


#include <stb_image.h>
#include <glad/glad.h>

namespace EuropaEngine
{
	OpenGLTexture2D::OpenGLTexture2D(uint32_t width, uint32_t height)
		:
		m_Width(width),
		m_Height(height)
	{	
		
		
		glGenTextures(1, &m_RendererID);
		glBindTexture(GL_TEXTURE_2D, m_RendererID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}

	OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
		:
		m_Path(path), m_Width(0), m_Height(0), m_RendererID(0)
	{
		

		int channel, width, height;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data;
		{
			data = stbi_load(m_Path.c_str(), &width, &height, &channel, 0);
		}
		EUROPA_ASSERT(data, "Failed to load Texture2D!");
		m_Width = width;
		m_Height = height;

		GLenum internalFormat = 0, dataFormat = 0;
		if (channel == 4)
		{
			internalFormat = GL_RGBA;
			dataFormat = GL_RGBA;
		}
		else if (channel == 3)
		{
			internalFormat = GL_RGB;
			dataFormat = GL_RGB;
		}
		else
		{
			EUROPA_ASSERT(false, "Only RGB and RGBA format supported!");
		}

		m_InternalFormat = internalFormat;
		m_DataFormat = dataFormat;

		glGenTextures(1, &m_RendererID);
		glBindTexture(GL_TEXTURE_2D, m_RendererID);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexImage2D(GL_TEXTURE_2D, 0, m_InternalFormat, m_Width, m_Height, 0, m_DataFormat, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		//glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, m_Width, m_Height, 0, dataFormat, GL_UNSIGNED_BYTE, data);
		//glGenerateMipmap(GL_TEXTURE_2D);

	
		stbi_image_free(data);
	}
	OpenGLTexture2D::~OpenGLTexture2D()
	{
		

		glDeleteTextures(1, &m_RendererID);
	}

	void OpenGLTexture2D::SetData(void* data, uint32_t size)
	{
		

		uint32_t bytesPerPixel = m_DataFormat == GL_RGBA ? 4 : 3;
		EUROPA_ASSERT(size == m_Width * m_Height * bytesPerPixel, "data must be entire texture!");

		glBindTexture(GL_TEXTURE_2D, m_RendererID);
		glTexImage2D(GL_TEXTURE_2D, 0, m_InternalFormat, m_Width, m_Height, 0, m_DataFormat, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	void OpenGLTexture2D::Bind(uint32_t slot) const
	{
		
		
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_RendererID);

		//glActiveTexture(slot);
		//glBindTexture(GL_TEXTURE_2D, m_RendererID);
	}
}