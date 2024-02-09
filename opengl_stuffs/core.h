#ifndef CORE_H
#define CORE_H

#include <GLFW/glfw3.h>
#include <stdbool.h>
#include <stdio.h>

#include "./color.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);		
// typedef void (*processkeycallback)(GLFWwindow*, int); 
void processExit(GLFWwindow *window);
void core_window_terminate();
GLFWmonitor* core_fullscreen_size(void);
void core_fullscreen(GLFWwindow* window);
// void plug_load();

typedef struct{int x, y;} Position;
typedef struct coredata{
	Position position;
	struct key{ 
		int exitkey;
		int hardcoded_escape;
		bool override_exitkey;
		int recently_pressed_key;
	} key;
	struct{
		GLFWwindow* whandle;
	Color color;
		bool window_ready;
		bool should_close;
		Position max; 
		Position size;
	} window;
} coredata;

coredata core={0};

GLFWwindow* core_window_init(Position position, const char* title){
	glfwInit();
	core.key.exitkey=GLFW_KEY_ESCAPE;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	int SCR_WIDTH=0;
	int SCR_HEIGHT=0;
		SCR_WIDTH=core.position.x=position.x;
		SCR_HEIGHT=core.position.y=position.y;
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, title, NULL, NULL);
		if(window == NULL){
		goto window_defer;
		}
	core.window.whandle=window;
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	goto init_glad;
window_defer:
	printf("Failed to create GLFW window\n");
	glfwTerminate();
	return NULL;
processExit(window);
init_glad:
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		printf("Failed to initialize GLAD\n");  
		return NULL;
	}
return window;
}

void setwindowtitle(GLFWwindow* window, const char* title){
glfwSetWindowTitle(window, title);
}

void setwindowicon(GLFWwindow* window, int count, GLFWimage image[]){
glfwSetWindowIcon(window, 2, image);
}

int core_window_should_close(void){
	if(core.window.window_ready) return core.window.should_close=GLFW_TRUE;
	else return GLFW_FALSE;
}

void set_exitkey(int exitkey){
	if(core.key.override_exitkey==GLFW_TRUE){
		exitkey=GLFW_KEY_ESCAPE;
		return;
	}
	core.key.exitkey=exitkey;
	return;
}

void core_window_ready(void){
	core.window.window_ready=GLFW_TRUE;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){		
	/*
		 make sure the viewport matches the new window dimensions; note that width and 
		 height will be significantly larger than specified on retina displays.
		 */
	glViewport(0, 0, width, height);
}

bool processKey(GLFWwindow* window, int key){
	if(glfwGetKey(window, key)==GLFW_PRESS) return GLFW_TRUE;
	else return GLFW_FALSE; 
}

void processExit(GLFWwindow *window){
	if (glfwGetKey(window, core.key.exitkey) == GLFW_PRESS)
		core_window_ready();
}

void core_window_terminate(){
	glfwTerminate();
}

GLFWmonitor* core_fullscreen_size(void){
	GLFWmonitor* monitor=glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	core.window.max.x=mode->width;
	core.window.max.y=mode->height;
	return monitor;
}

void core_fullscreen(GLFWwindow* window){
	GLFWmonitor* monitor=core_fullscreen_size();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
	glfwSetWindowSize(window, mode->width, mode->height);
  // glfwSetWindowMonitor(window, monitor, 0, 0, mode->width-28, mode->height-28, mode->refreshRate); // use this for going "fullscreen" doesnt show top window bar
return;
}

bool iskeypressed(GLFWwindow* window, int key){
	if(glfwGetKey(window, key)==GLFW_PRESS) return GLFW_TRUE;
	else return GLFW_FALSE;
}

void clearscreen(GLFWwindow* window, Color color){
				glClearColor(color.r, color.g, color.b, color.a);
        glClear(GL_COLOR_BUFFER_BIT);
				glfwSwapBuffers(window);
        glfwPollEvents();
}

#endif
