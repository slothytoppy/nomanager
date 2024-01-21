#include <stdio.h> // standard headers
#include <unistd.h>
#include <string.h>

#include <glad/glad.h>

#include "core.h" // my headers
#include "utils.h"

int main(){
		char* args="./nomake";
		run(args);
		/*
		struct sigaction sa;
		sa.sa_handler=sighand;
		sigemptyset(&sa.sa_mask);
		sa.sa_flags=0;
		sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGTSTP);
    // Block the signals in the mask
    sigprocmask(SIG_BLOCK, &mask, NULL);
		*/
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
		// core_fullscreen(window);
		// core.key.override_exitkey=GLFW_TRUE;
		// set_exitkey(GLFW_KEY_Q);
		if(iskeypressed(window, GLFW_KEY_Q)){
				core_window_should_close();
				}
		processExit(window);
				// signal(SIGTERM, sighand);
				// processKey(window, GLFW_KEY_Q, )
				Color color={
				.r=0.1,
				.g=0.1,
				.b=0.1,
				.a=0.1
				};
				clearscreen(window, WHITE);
				// glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // glClear(GL_COLOR_BUFFER_BIT);
				// glfwSwapBuffers(window);
        // glfwPollEvents();
		}
		core_window_terminate();
		return 0;
}


