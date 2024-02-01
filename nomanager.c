#include <stdio.h>
#include <raylib.h>
#define NOM_IMPLEMENTATION
#include "./nom/nom.h"

void CenterText(char* str1){
int screenCenterX = GetScreenWidth() / 2;
int screenCenterY = GetScreenHeight() / 2;
int fontSize = 20;
int textWidth = MeasureText(str1, 20);
int textStartX = screenCenterX - textWidth / 2;
int textStartY = screenCenterY - fontSize / 2;
DrawText(str1, textStartX, textStartY, 20, LIGHTGRAY);
}

void togglefullscreen(void){
if(IsWindowMaximized()){
  RestoreWindow();
  return;
}
if(!IsWindowMaximized()){
  MaximizeWindow();
  return;
}
}

int main(){
if(IS_PATH_MODIFIED("nom/nom.h", __FILE__) || IS_PATH_MODIFIED("nomake.c", __FILE__)){
run("nomake");
}
SetConfigFlags(FLAG_WINDOW_RESIZABLE);
InitWindow(800, 450, "NoManager");
// SetWindowState(FLAG_WINDOW_RESIZABLE);
while(!WindowShouldClose()){

if(IsKeyPressed(KEY_F) && IsWindowState(FLAG_WINDOW_RESIZABLE)){
togglefullscreen();
}
BeginDrawing();
ClearBackground(RAYWHITE);

char *text="Congrats! You created your first window!";
if(IsKeyPressed(KEY_Q)){
	printf("hello\n");
  CenterText("You pressed KEY_Q Exiting...");
	EndDrawing();
  CloseWindow();
  return 0;
}
CenterText(text);
EndDrawing();
}
CloseWindow();
return 0;
}

