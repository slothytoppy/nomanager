#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

#define OVERRIDE_DIFFERENT_ESCAPE
#include "core.h"

int main(){	
		Position pos={ 
			.x=0,
			.y=0
		};
		GLFWwindow* window=core_window_init(pos, "welcome to core");
		while(!core_window_should_close()){
		set_exitkey(GLFW_KEY_Q);
        processExit(window);
				// processKey(window, GLFW_KEY_Q, )
				glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
				glfwSwapBuffers(window);
        glfwPollEvents();
		}
		core_window_terminate();
    return 0;
}

