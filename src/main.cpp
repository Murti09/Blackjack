#include "card.h"
#include "game.h"
#include "raylib.h"

int main()
{
    InitWindow(1024, 769, "Blackjack");
    SetTargetFPS(60);

    // Spritesheet laden
    Texture2D spritesheet = LoadTexture("cards.png");
    SetTextureFilter(spritesheet, TEXTURE_FILTER_POINT);

    // Test: Herz Ass (Zeile 0, Spalte 0)
    Rectangle src = {0, 0, 48, 64};
    Rectangle dst = {100, 100, 10 * 48, 10 * 64};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground({34, 100, 34, 255});
        DrawTexturePro(spritesheet, src, dst, {0, 0}, 0, WHITE);
        EndDrawing();
    }

    UnloadTexture(spritesheet);
    CloseWindow();
}