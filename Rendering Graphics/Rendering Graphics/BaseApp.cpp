#include "BaseApp.h"
BaseApp::Run()
{
	double prevTime = glfwGetTime();
	double currTime = 0;

	while (currTime = glfwGetTime(),
		update((float)(currTime - prevTime))) {

		glfwPollEvents();
		draw();
		glfwSwapBuffers(m_window);

		prevTime = currTime;
	}
}