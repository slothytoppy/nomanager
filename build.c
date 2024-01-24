#define NOMAKE_IMPLEMENTATION
#include "nomake/nomake.h"

int main(int argc, char* argv[]){
GO_REBUILD(argc, argv, "gcc");
// char* flags[]={"-lglfw", "-lGL", "-Wall", "-Wextra", "glad.c"}; 

char* rflags[]={"-lm", "-lglfw", "-lGL", "-lraylib", "-I/usr/local/include/", "-L/usr/local/lib"};
compile_file("gcc", rflags, "nomanager.c", "nomanager", ".c", 6);
// compile_file("gcc", flags, "test_gl.c", "test_gl", 5);
}
