#include "raylib.h"

#define SCALE 40.0f
Vector2 origin = {480, 360};

Vector2 ToScreen(Vector2 v) {
    return (Vector2){origin.x + v.x * SCALE, origin.y - v.y * SCALE};
}

int main() {
    InitWindow(960, 720, "My Screen");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 xAxisStart = ToScreen((Vector2){-12, 0});
        Vector2 xAxisEnd = ToScreen((Vector2){12, 0});
        DrawLineEx(xAxisStart, xAxisEnd, 4.0, BLACK);

        Vector2 yAxisStart = ToScreen((Vector2){0, -9});
        Vector2 yAxisEnd = ToScreen((Vector2){0, 9});
        DrawLineEx(yAxisStart, yAxisEnd, 4.0, BLACK);

        for (int k = -12; k <= 12; k++) {
            Vector2 start = ToScreen((Vector2){k, -9});
            Vector2 end = ToScreen((Vector2){k, 9});
            DrawLineEx(start, end, 1.0, BLACK);
        }
        for (int k = -9; k <= 9; k++) {
            Vector2 start = ToScreen((Vector2){-12, k});
            Vector2 end = ToScreen((Vector2){12, k});
            DrawLineEx(start, end, 1.0, BLACK);
        }

        Vector2 vector = ToScreen((Vector2){4, 5});
        DrawLineEx(origin, vector, 3.0, RED);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
