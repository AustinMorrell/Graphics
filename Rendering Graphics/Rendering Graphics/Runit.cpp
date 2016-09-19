//#include "Runit.h"
//
//App::App()
//{
//
//}
//
//int App::Start()
//{
//	if (glfwInit() == false)
//	{
//		return -1;
//	}
//
//	window = glfwCreateWindow(1280, 720, "OpenGLTour2", nullptr, nullptr);
//
//	if (window == nullptr)
//	{
//		glfwTerminate();
//		return -2;
//	}
//
//	glfwMakeContextCurrent(window);
//
//	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
//	{
//		glfwDestroyWindow(window);
//		glfwTerminate();
//		return -3;
//	}
//
//	Cam.setLookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
//
//	Cam.setPerspective(glm::pi<float>() * 0.25f, 16 / 9.f, 0.1f, 1000.f);
//
//	Cam.setSpeed(10);
//
//	auto major = ogl_GetMajorVersion();
//	auto minor = ogl_GetMinorVersion();
//	printf("GL: %i.%i\n", major, minor);
//
//	Drawer.startupShade();
//
//	// After checking, the rest of the code goes here.
//
//	glClearColor(0.25f, 0.25f, 0.25f, 1);
//	glEnable(GL_DEPTH_TEST); // enables the depth buffer
//
//	return 1;
//}
//
//void App::Draw()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	vec4 white(1);
//	vec4 black(0, 0, 0, 1);
//
//	Drawer.generatePlane(p_ViewMatrix, 10, 10);
//
//	glfwSwapBuffers(window);
//	glfwPollEvents();
//}
//
//bool App::Update()
//{
//	while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
//	{
//		pastTime = newTime;
//		newTime = glfwGetTime();
//		DeltaTime = newTime - pastTime;
//		Cam.update(DeltaTime);
//		return true;
//	}
//	return false;
//}
//
//void App::Stop()
//{
//	glfwDestroyWindow(window);
//	glfwTerminate();
//}