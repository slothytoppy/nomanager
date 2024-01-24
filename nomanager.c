#include <stdio.h>
#include <raylib.h>
#define NOMAKE_IMPLEMENTATION 
#include "./nomake/nomake.h"
int main(){
run("nomake");
SetTraceLogLevel(LOG_WARNING); 
InitWindow(800, 450, "raylib [core] example - basic window");
SetWindowTitle("NoManager");                     // Set title for window (only PLATFORM_DESKTOP and PLATFORM_WEB)
SetWindowState(FLAG_WINDOW_RESIZABLE);
Image image=LoadImage("/home/slothy/Downloads/0175-034.png");
ImageFormat(&image, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8); 
SetWindowIcon(image);
while(!WindowShouldClose()){
BeginDrawing();
ClearBackground(RAYWHITE);
int screenCenterX = GetScreenWidth() / 2;
int screenCenterY = GetScreenHeight() / 2;
const char *text="Congrats! You created your first window!";
int fontSize = 20;
int textWidth = MeasureText(text, fontSize);
int textStartX = screenCenterX - textWidth / 2;
int textStartY = screenCenterY - fontSize / 2;
if(IsKeyPressed(KEY_Q)){
	DrawText("You pressed KEY_Q Exiting...", textStartX, textStartY, 20, LIGHTGRAY);
	EndDrawing();
	WindowShouldClose();
}
if(IsWindowResized()){
printf("%d|%d\n", textStartX, textStartY);
}
DrawText(text, textStartX, textStartY, 20, LIGHTGRAY);
EndDrawing();
}
CloseWindow();
UnloadImage(image);
return 0;
}

