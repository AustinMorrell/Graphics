#include "Drawing.h"

Drawing::Drawing()
{
	/*startupShade();*/
}

Drawing::~Drawing()
{
	glDeleteProgram(m_shader);
}

//void Drawing::create(unsigned int a_maxLines = 0xffff, unsigned int a_maxTris = 0xffff, unsigned int a_max2DLines = 0xff, unsigned int a_max2DTris = 0xff)
//{
//	//if (sm_singleton == nullptr)
//	//	sm_singleton = new Drawing(a_maxLines, a_maxTris, a_max2DLines, a_max2DTris);
//}

void Drawing::destroy()
{

}

void Drawing::clear()
{

}

void Drawing::draw(const glm::mat4& a_projectionView)
{

}

void Drawing::draw(const glm::mat4& a_projection, const glm::mat4& a_view)
{

}

void Drawing::generateGrid(unsigned int rows, unsigned int cols)
{
	Vertex* aoVertices = new Vertex[rows * cols];
	for (unsigned int r = 0; r < rows; ++r) {
		for (unsigned int c = 0; c < cols; ++c) {
			aoVertices[r * cols + c].position = vec4(
				(float)c, 0, (float)r, 1);
			// create some arbitrary colour based off something
			// that might not be related to tiling a texture
			vec3 colour = vec3(sinf((c / (float)(cols - 1)) *
				(r / (float)(rows - 1))));
			aoVertices[r * cols + c].colour = vec4(colour, 1);
		}
	}

	// defining index count based off quad count (2 triangles per quad)
	unsigned int* auiIndices = new unsigned int[(rows - 1) * (cols - 1) *
		6];
	unsigned int index = 0;
	for (unsigned int r = 0; r < (rows - 1); ++r) {
		for (unsigned int c = 0; c < (cols - 1); ++c) {
			// triangle 1
			auiIndices[index++] = r * cols + c;
			auiIndices[index++] = (r + 1) * cols + c;
			auiIndices[index++] = (r + 1) * cols + (c + 1);
			// triangle 2
			auiIndices[index++] = r * cols + c;
			auiIndices[index++] = (r + 1) * cols + (c + 1);
			auiIndices[index++] = r * cols + (c + 1);
		}
	}

	// we’ll do more here soon!
	// create and bind buffers to a vertex array object
	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, (rows * cols) * sizeof(Vertex),
		aoVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(void*)(sizeof(vec4)));
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &m_IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (rows - 1) * (cols - 1) * 6 *
		sizeof(unsigned int), auiIndices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// Generate our GL Buffers
	// Lets move these so that they are all generated together
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_IBO);
	//Add the following line to generate a VertexArrayObject
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);
	// ....Code Segment here to bind and fill VBO + IBO
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	delete[] aoVertices;
}

void Drawing::startupShade()
{
	const char* vsSource;
	std::string vs = ReadFromFile("vsInfo.txt");
	vsSource = vs.c_str();

	const char* fsSource;
	std::string fs = ReadFromFile("fsInfo.txt");
	fsSource = fs.c_str();

	int success = GL_FALSE;
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, (const char**)&vsSource, 0);
	glCompileShader(vertexShader);
	glShaderSource(fragmentShader, 1, (const char**)&fsSource, 0);
	glCompileShader(fragmentShader);

	m_shader = glCreateProgram();
	glAttachShader(m_shader, vertexShader);
	glAttachShader(m_shader, fragmentShader);
	glLinkProgram(m_shader);

	glGetProgramiv(m_shader, GL_LINK_STATUS, &success);
	if (success == GL_FALSE)
	{
		int infoLogLength = 0;
		glGetProgramiv(m_shader, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* infoLog = new char[infoLogLength];
		glGetProgramInfoLog(m_shader, infoLogLength, 0, infoLog);
		printf("Error: Failed to link shader program!\n");
		printf("%s\n", infoLog);
		delete[] infoLog;
	}
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);

}

std::string Drawing::ReadFromFile(std::string text)
{
	std::string data;
	std::string container;
	std::ifstream file(text);

	if (file.is_open())
	{
		while (std::getline(file, data))
		{
			container += data + "\n";
		}
		file.close();
	}
	return container;
}

void Drawing::generatePlane(mat4 b, int rows, int cols)
{
	glUseProgram(m_shader);
	unsigned int projectionViewUniform =
		glGetUniformLocation(m_shader, "projectionViewWorldMatrix");
	glUniformMatrix4fv(projectionViewUniform, 1, false,
		glm::value_ptr(b));
	glBindVertexArray(m_VAO);
	unsigned int indexCount = rows * cols * 6;
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);

}

void Drawing::generateCube()
{

}

void Drawing::generateSphere()
{

}