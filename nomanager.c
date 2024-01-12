#include <stdio.h>
#include <raylib.h>

int main(){
InitWindow(800, 450, "raylib [core] example - basic window");
SetWindowState(FLAG_WINDOW_RESIZABLE);
while(!WindowShouldClose()){
BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
}
CloseWindow();
return 0;
}

