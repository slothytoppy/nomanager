#define NOM_IMPLEMENTATION
#include "../nom/nom.h"

int main(int argc, char* argv[]){
rebuild(__FILE__, "gcc");
Nom_cmd cmd={0};

nom_cmd_append(&cmd, "gcc");
nom_cmd_append(&cmd, "-lglfw");
nom_cmd_append(&cmd, "-lGL");
nom_cmd_append(&cmd, "glad.c");
nom_cmd_append(&cmd, "test_gl.c");
nom_cmd_append(&cmd, "-o");
nom_cmd_append(&cmd, "test_gl");
if(!nom_run_async(cmd)){
nom_log(NOM_WARN, "could not compile cmd");
return 1;
}
return 0;
}
