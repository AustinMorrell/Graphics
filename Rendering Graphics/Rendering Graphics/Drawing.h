#pragma once
#include "FlyCamera.h"

class Drawing
{
private:
	// our vertex and index buffers
	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_IBO;
	unsigned int m_programID;
public:
	void generateGrid(unsigned int rows, unsigned int cols);
	void startupShade();
};