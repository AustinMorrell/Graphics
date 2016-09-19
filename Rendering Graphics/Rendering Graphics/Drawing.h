#pragma once
#include "FlyCamera.h"
#include "Runit.h"

class Drawing : BaseApplication
{
private:
	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_IBO;
	unsigned int m_shader;
public:
	Drawing();
	~Drawing();
	/*void create(unsigned int a_maxLines = 0xffff, unsigned int a_maxTris = 0xffff,
		unsigned int a_max2DLines = 0xff, unsigned int a_max2DTris = 0xff);*/
	void destroy();

	void clear();

	void draw(const glm::mat4& a_projectionView);
	void draw(const glm::mat4& a_projection, const glm::mat4& a_view);

	void generateGrid(unsigned int rows, unsigned int cols);
	void startupShade();
	std::string ReadFromFile(std::string text);
	void generatePlane(mat4 b, int rows, int cols);
	void generateCube();
	void generateSphere();
};