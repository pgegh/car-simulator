#ifndef ROOM_H
#define ROOM_H

#include "spatial.h"

/* Room data structure represtneing a room.  */
typedef struct Room {
    RoomSize_T room_size;
} Room_T;

/* Creates a new room instance.
   Returns the room instance.  */
Room_T create_room(const RoomSize_T *room_size);

#endif //ROOM_H
