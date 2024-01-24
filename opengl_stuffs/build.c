#define NOMAKE_IMPLEMENTATION
#include "../nomake/nomake.h"

int main(int argc, char* argv[]){
GO_REBUILD(argc, argv, "gcc");
Nom_cmd cmd={0};
// nom_cmd_append_many(&cmd, 7, "gcc", "-lgflw", "-lGL", "glad.c", "test_gl.c", "-o", "test_gl"); // dont use for command
nom_cmd_append(&cmd, "gcc");
nom_cmd_append(&cmd, "-lglfw");
nom_cmd_append(&cmd, "-lGL");
nom_cmd_append(&cmd, "glad.c");
nom_cmd_append(&cmd, "test_gl.c");
nom_cmd_append(&cmd, "-o");
nom_cmd_append(&cmd, "test_gl");
nom_cmd_append_null(&cmd);
if(!nom_cmd_compile(&cmd)){
NOM_LOG(NOM_WARN, "could not compile cmd");
return 1;
}
}
