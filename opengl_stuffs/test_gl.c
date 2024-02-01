#include <stdio.h> // standard headers
#include <unistd.h>
#include <string.h>

// glad and glfw not setup yet
#include <glad/glad.h>

#include "core.h" // my headers

int main(){
Position pos={ 
	.x=800,
	.y=800
};
	 /*
	 int daemonize=daemon(0, 1);
	 if(daemonize==-1) return -1;
	 */
GLFWwindow* window=core_window_init(pos, "welcome to core");
printf("SECOND PID:%d\n", getpid());
if(window==NULL){
  fprintf(stderr, "error init window\n");
  glfwTerminate();
}
while(!core_window_should_close()){
	setwindowtitle(window, "core.h");
	core_fullscreen(window);
	// core.key.override_exitkey=GLFW_TRUE;
	// set_exitkey(GLFW_KEY_Q);
	if(iskeypressed(window, GLFW_KEY_Q)){
		core_window_should_close();
    core_window_terminate();
		return 0;
  }
processExit(window);
Color color={
		.r=0.1,
		.g=0.1,
		.b=0.1,
		.a=0.1
};
clearscreen(window, WHITE);
}
core_window_terminate();
return 0;
}


