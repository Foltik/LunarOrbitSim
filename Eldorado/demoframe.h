#pragma once
#include <k5/k5.h>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SOIL.h>


class CDemoFrame : public CFrame{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void ProcessInput(bool* keyboard, double mxpos, double mypos);
	void Loop();
	void Render();

	static CDemoFrame* Instance() {
		return &pInstance;
	}

protected:
	CDemoFrame() {}

private:
	static CDemoFrame pInstance;

	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 proj;

	float cameraSpeed = 0.03f;
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	float pitch = 0.0f;
	float yaw = -90.0f;
	double lastX = 400, lastY = 300;
	double sensitivity = 0.020;

	GLuint tex;
	GLuint tex2;

	Shader* shader;

	GLuint ebo;
	GLuint vao;
	GLuint vbo;
};