#include "room.h"

Room_T create_room(const RoomSize_T *const room_size) {
    Room_T new_room;
    new_room.room_size = *room_size;

    return new_room;
}
