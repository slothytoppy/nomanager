#define NOMAKE_IMPLEMENTATION
#include "nomake.h"

int main(){
char* flags[]={"-lglfw", "-lGL", "glad.c"}; 
compile_file("gcc", flags, "test_gl.c",  "test_gl",  ".c", 3); 
}
