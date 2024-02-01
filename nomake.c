#define NOM_IMPLEMENTATION
#include "nom/nom.h"

int build_nomanager(void){
Nom_cmd cmd={0};
nom_cmd_append(&cmd, "gcc");
nom_cmd_append(&cmd, "-lm");
nom_cmd_append(&cmd, "-lglfw");
nom_cmd_append(&cmd, "-lGL");
nom_cmd_append(&cmd, "-ggdb");
nom_cmd_append(&cmd, "-I/usr/local/include/");
nom_cmd_append(&cmd, "nomanager.c");
nom_cmd_append(&cmd, "-o");
nom_cmd_append(&cmd, "nomanager");
nom_cmd_append(&cmd, "-L/usr/local/lib");
nom_cmd_append(&cmd, "-lraylib");
if(nom_run_async(cmd)) return 1; 
return 0;
}

int build(char* file){
if(!file) return 1;
char* buff=calloc(1, PATH_MAX);
if(!IS_PATH_EXIST(file)){
nom_log(NOM_WARN, "file %s does not exist", file);
return 1;
}
if(file[strlen(file)-2]=='.' && file[strlen(file)-1]=='c'){
strncpy(buff, file, strlen(file)-2);
}
if(buff==NULL) return 1;
Nom_cmd cmd={0};
nom_cmd_append(&cmd, "gcc");
nom_cmd_append(&cmd, "-lm");
nom_cmd_append(&cmd, "-lglfw");
nom_cmd_append(&cmd, "-lGL");
nom_cmd_append(&cmd, "-ggdb");
nom_cmd_append(&cmd, "-I/usr/local/include/");
nom_cmd_append(&cmd, file);
nom_cmd_append(&cmd, "-o");
nom_cmd_append(&cmd, buff);
nom_cmd_append(&cmd, "-L/usr/local/lib");
nom_cmd_append(&cmd, "-lraylib");
if(nom_run_async(cmd)) return 0; 
return 1;
}

int build_rayout(void){
Nom_cmd cmd={0};
nom_cmd_append(&cmd, "gcc");
nom_cmd_append(&cmd, "-lm");
nom_cmd_append(&cmd, "-lglfw");
nom_cmd_append(&cmd, "-lGL");
nom_cmd_append(&cmd, "-ggdb");
nom_cmd_append(&cmd, "-I/usr/local/include/");
nom_cmd_append(&cmd, "rayout.c");
nom_cmd_append(&cmd, "-o");
nom_cmd_append(&cmd, "rayout");
nom_cmd_append(&cmd, "-L/usr/local/lib");
nom_cmd_append(&cmd, "-lraylib");
if(nom_run_async(cmd)) return 1; 
return 0;

}

int main(int argc, char* argv[]){
rebuild(__FILE__, "gcc");

if(IS_LIBRARY_MODIFIED("nom/nom.h", __FILE__, "gcc")){
UPDATE_PATH_TIME(__FILE__, "nom/nom.h");
// rebuild(__FILE__, "gcc");
printf("seaman\n");
}
// char* flags[]={"-lglfw", "-lGL", "-Wall", "-Wextra", "glad.c"}; 
// gcc -lm -lglfw -lGL -I/usr/local/include/ -L/usr/local/lib -lraylib nomanager.c -o nomanager

Nom_cmd cmd={0};
build("rayout.c");
build("nomanager.c");
// char* rflags[]={"-lm", "-lglfw", "-lGL", "-lraylib", "-I/usr/local/include/", "-L/usr/local/lib"};
// compile_file("gcc", rflags, "nomanager.c", "nomanager", ".c", 7);
// compile_file("gcc", flags, "test_gl.c", "test_gl", 5);
}
