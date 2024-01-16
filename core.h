#pragma once

#include <GLFW/glfw3.h>
#include <stdbool.h>
#include <stdio.h>
// TODO implement functionality for core_window_init and core_window_should_close for a render loop
void framebuffer_size_callback(GLFWwindow* window, int width, int height);		
// typedef void (*processkeycallback)(GLFWwindow*, int); 

typedef struct{int x, y;} Position;
typedef struct {
Position position;
int exitkey;
int hardcoded_escape;
bool window_ready;
bool should_close;
int recently_pressed_key;
} coredata;

coredata core={0};

GLFWwindow* core_window_init(Position position, const char* title){
int SCR_WIDTH=0;
int SCR_HEIGHT=0;
if(position.x==0 || position.y==0){ 
GLFWmonitor* monitor=glfwGetPrimaryMonitor();
const GLFWvidmode* mode = glfwGetVideoMode(monitor);
glfwWindowHint(GLFW_RED_BITS, mode->redBits);
glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
SCR_WIDTH=mode->width;
SCR_HEIGHT=mode->height;
GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "My Title", monitor, NULL);
glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
}
else{
int SCR_WIDTH=core.position.x=position.x;
int SCR_HEIGHT=core.position.y=position.y;
}
core.exitkey=GLFW_KEY_ESCAPE;
glfwInit();
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, title, NULL, NULL);
if(window == NULL){
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return NULL;
}
glfwMakeContextCurrent(window);
glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
	printf("Failed to initialize GLAD\n");  
  return NULL;
	}
return window;
}

int core_window_should_close(void){
if(core.window_ready) return core.should_close=GLFW_TRUE;
else return GLFW_FALSE;
}

void set_exitkey(int exitkey){
#ifdef OVERRIDE_DIFFERENT_ESCAPE
exitkey=GLFW_KEY_ESCAPE;
#endif
core.exitkey=exitkey;
}

void core_window_ready(void){
core.window_ready=GLFW_TRUE;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){		
		/*
    make sure the viewport matches the new window dimensions; note that width and 
    height will be significantly larger than specified on retina displays.
    */
		(void) window;
		glViewport(0, 0, width, height);
}

bool processKey(GLFWwindow* window, int key){
if(glfwGetKey(window, key)==GLFW_PRESS) return GLFW_TRUE;
else return GLFW_FALSE; 
}

void processExit(GLFWwindow *window){
    if (glfwGetKey(window, core.exitkey) == GLFW_PRESS)
		core_window_ready();
}

void core_window_terminate(){
glfwTerminate();
}

