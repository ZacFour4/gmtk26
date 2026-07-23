#include "game_manager.hpp"

ResourceManager<Texture2D, TextureIndex> texture_manager;
ResourceManager<Shader, ShaderIndex> shader_manager;

void game_manager_initialise()
{
    texture_manager = ResourceManager<Texture2D, TextureIndex>(load_texture, unload_texture);
    texture_manager.load_resource(TextureIndex::test_texture, "test.png");
    
    shader_manager = ResourceManager<Shader, ShaderIndex>(load_shader_pair, unload_shader_pair);
    shader_manager.load_resource(ShaderIndex::passthrough, "shaders/passthrough");
}