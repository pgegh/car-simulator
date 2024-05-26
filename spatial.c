#include "spatial.h"


RoomSize_T create_room_size(const unsigned int x_size, const unsigned int y_size) {
    RoomSize_T new_room_size;
    new_room_size.x_size = x_size;
    new_room_size.y_size = y_size;

    return new_room_size;
}
