#include <cstddef>
#include <functional>
#include <iostream>
#include <raylib.h>
#include <string>
#include <vector>
#include <math.h>
#include <memory>

Shader* load_shader_pair(const std::string&);
Texture2D* load_texture(const std::string&);

void unload_shader_pair(Shader*);
void unload_texture(Texture2D*);

template<typename ResourceType, typename IndexType>
class ResourceManager
{
private:
    std::vector<ResourceType*> resource_map;
    std::function<ResourceType*(const std::string&)> load_function;
    std::function<void(ResourceType*)> unload_function;

public:
    ResourceManager() = default;
    ResourceManager(
        std::function<ResourceType*(const std::string&)> load_callback,
        std::function<void(ResourceType*)> unload_callback
    )
    {
        load_function = load_callback;
        unload_function = unload_callback;
    }

    ResourceType* get_resource(int index)
    {
        if (index < 0 || index >= static_cast<int>(resource_map.size()))
        {
            return nullptr;
        }

        return resource_map[index];
    }

    ResourceType* get_resource(IndexType index)
    { 
        return get_resource(static_cast<int>(index));
    }

    void load_resource(int index, const std::string& file_path)
    { 
        std::size_t new_potential_size = static_cast<std::size_t>(index);

        if (resource_map.size() <= new_potential_size)
        {
            resource_map.resize(new_potential_size + 1);
        }
        resource_map[index] = load_function(file_path);
    } 

    void load_resource(IndexType index, const std::string& file_path)
    { 
        load_resource(static_cast<int>(index), file_path);
    }

    void unload_resource(int index)
    {
        unload_function(get_resource(index));
        resource_map[index] = nullptr;
    }

    void unload_resource(IndexType index)
    {
        unload_resource(static_cast<int>(index));
    }

};
