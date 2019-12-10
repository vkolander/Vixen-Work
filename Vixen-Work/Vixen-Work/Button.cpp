#include <GLFW/glfw3.h>
#include "LinMath.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

//Tutorial used https://www.youtube.com/watch?v=kwxCP_LLZJ4 this is where the majority of the code was taken from
//Second tutorial used https://www.youtube.com/watch?time_continue=59&v=ge78EbTLgAs&feature=emb_logo

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

int main(void) {
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	int height_window, width_window;

	height_window = 640;
	width_window = 640;
	/*
	int& width_later = width_window;
	int& height_later = height_window;
	*/
	//Specify the minimum GLFW version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);//here we are defining that we are using 2.0 which we are using as it is the one in the tutorial
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);//updating these would create issues as the functions are very different for OpenGL if we switch versions

	/*
	We created a window with variable height and width so that we can test out different sizes.
	We will later use this to make the height and width of the button
	*/
	GLFWwindow* window = glfwCreateWindow(width_window, height_window, "Test", NULL, NULL);
	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
	//This will allow us to have the event when a key is pressed. This calls the function we made a prototype for earlier and will define later

	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	const float  Deg2Rad = 3.14159 / 180; //this will help us draw circles in the future
	float radius;
	if (height_window != width_window) {
		radius = 0.5;
	}
	else {
		radius = 1;
	}
	//These next values will allow us to create color (values form 0-1)
	float r = 0.0;
	float g = 0.0;
	float b = 1.0;

	while (!glfwWindowShouldClose(window)) {//While window is open do...
		float ratio;
		int width, height;// this width and height should correlate to the window vales we made earlier
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float)height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);//This cleans it, starting the frame from scratch

		//Now we can start drawing
		glColor3f(r, g, b);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++) {
			float DeginRad = i * Deg2Rad;
			glVertex2f(cos(DeginRad) * radius, sin(DeginRad * radius));
		}
			
		glEnd();
		//now we want to specify that we are drawing something with four sides

		//bufers swapped
		glfwSwapBuffers(window);
		glfwPollEvents();	
		}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);

}

//this net function is what allows us to do certain actions bsed on key presses

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	const float  Deg2Rad = 3.14159 / 180; //this will help us draw circles in this function
	float radius = 1;
	/*int height_window_2 = *height_later
	//int width_window_2 = 640;
	if (height_window_2 != width_window_2) {
		radius = 0.5;
	}
	else {
		radius = 1;
	}
	*/
	if (key == GLFW_KEY_K && action == GLFW_PRESS) {
		std::cout << "K key is pressed" << std::endl;
	}
	//Here is a switch case that will change the output depening on if the spacebar is being held down or being released
	if (key == GLFW_KEY_SPACE) {
		switch (action) {
		case GLFW_REPEAT:
			std::cout << "The space key is being held down" << std::endl;
			break;
		case GLFW_RELEASE:
			std::cout << "The space key is released" << std::endl;
			break;
		}
	}
	//This will draw a green circle every time the P button is pressed
	if (key == GLFW_KEY_P && action == GLFW_PRESS) {
		glClear(GL_COLOR_BUFFER_BIT);
		int red = 0.0;
		int green = 1.0;
		int blue = 0.0;
		glColor3f(red, green, blue);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++) {
			float DeginRad = i * Deg2Rad;
			glVertex2f(cos(DeginRad) * radius, sin(DeginRad * radius));
		}

		glEnd();
		glfwSwapBuffers(window);
	}
	if (key == GLFW_KEY_L && action == GLFW_REPEAT) {
		glClear(GL_COLOR_BUFFER_BIT);
		int red = 1.0;
		int green = 0.0;
		int blue = 0.0;
		glColor3f(red, green, blue);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++) {
			float DeginRad = i * Deg2Rad;
			glVertex2f(cos(DeginRad) * radius, sin(DeginRad * radius));
		}

		glEnd();
		glfwSwapBuffers(window);
	}
}
/*	All of this code is what craetes the window and closes it correctly


	if (!glfwInit()){
		exit(EXIT_FAILURE);
	}
	int height_window, width_window;
	char title[10];
	cout << "Enter a height, width, and title";
	cin >> height >> width >> title;
	//Create window
		//Specify the minimum GLFW version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	GLFWwindow* window = glfwCreateWindow(height_window, width_window, title, NULL, NULL);

	if (!window){
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	while (!glfwWindowShoulClose(window)) {//While window is open do...
**********************************************************************************************************************
				This is where we enter the code of things we actually want to do in the window
**********************************************************************************************************************
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
	*/

/*
Future goals:
Make a more dynamic system that changes the button size depending on the size of the window
Allow the button to be shown for much longer in order to not have a user's eyes bleed everytime they press a particular button
Creating a full UI with multiple buttons and mice to be used with the AI
*/