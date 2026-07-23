#include "raylib.h"
#include "game_manager.hpp"

#define SCREEN_WIDTH (800)
#define SCREEN_HEIGHT (450)

#define WINDOW_TITLE "Window title"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);

    game_manager_initialise();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        Texture2D* texture = texture_manager.get_resource(TextureIndex::test_texture);

        if (!texture)
        {
            TraceLog(LOG_ERROR, "Texture was not loaded!");
            return 1;
        }

        ClearBackground(RAYWHITE);

        const int texture_x = SCREEN_WIDTH / 2 - (*texture_manager.get_resource(TextureIndex::test_texture)).width / 2;
        const int texture_y = SCREEN_HEIGHT / 2 - (*texture_manager.get_resource(TextureIndex::test_texture)).height / 2;
        DrawTexture(*texture_manager.get_resource(TextureIndex::test_texture), texture_x, texture_y, WHITE);

        const char* text = "OMG! IT WORKS!";
        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
        DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, texture_y + (*texture_manager.get_resource(TextureIndex::test_texture)).height + text_size.y + 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
