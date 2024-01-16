#include <stdio.h>
#include <raylib.h>

int main(){
InitWindow(800, 450, "raylib [core] example - basic window");
SetWindowTitle("NoManager");                     // Set title for window (only PLATFORM_DESKTOP and PLATFORM_WEB)
SetWindowState(FLAG_WINDOW_RESIZABLE);
while(!WindowShouldClose()){
BeginDrawing();
ClearBackground(RAYWHITE);
int x=GetScreenWidth();                                   /* Get current screen width */
int y=GetScreenHeight();                                  /* Get current screen height */
int j=MeasureText("Congrats! You created your first window!", 20);                                      /* Measure string width for default font */
if(IsKeyPressed(KEY_Q)){
	DrawText("You pressed KEY_Q Exiting...", x/2, y/2, 20, LIGHTGRAY);
	EndDrawing();
	WindowShouldClose();
}
if(IsWindowResized()){
printf("%d|%d|%d\n", x, y/2, j);
}
DrawText("Congrats! You created your first window!", x/2, y/4, 20, LIGHTGRAY);
EndDrawing();
}
CloseWindow();
return 0;
}

