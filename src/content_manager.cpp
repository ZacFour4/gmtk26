#include "content_manager.hpp"
#include <raylib.h>

Shader* load_shader_pair(const std::string& file_path)
{
    
    return new Shader(LoadShader((ASSETS_PATH + file_path + ".vs").c_str(), (ASSETS_PATH +file_path + ".fs").c_str()));
}

Texture2D* load_texture(const std::string& file_path)
{
    return new Texture(LoadTexture((ASSETS_PATH + file_path).c_str()));
}

void unload_shader_pair(Shader* shader)
{
    if (shader)
    {
        UnloadShader(*shader);
        delete shader;
    }
}

void unload_texture(Texture2D* texture)
{
    if (texture)
    {
        UnloadTexture(*texture);
        delete texture;
    }
}
