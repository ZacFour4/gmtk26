#include "content_manager.hpp"
#include <raylib.h>

enum class TextureIndex {
    test_texture,
    city_1,
    city_2
};

enum class ShaderIndex {
    passthrough
};

extern ResourceManager<Texture2D, TextureIndex> texture_manager;
extern ResourceManager<Shader, ShaderIndex> shader_manager;

void game_manager_initialise();