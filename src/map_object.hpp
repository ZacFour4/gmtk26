#include <raylib.h>

class MapObject
{
private:
    Vector2 position;
    bool selectable;
public: 
    bool is_selected();
    MapObject() = default;
    MapObject(const Vector2&, bool);
};