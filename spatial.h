#ifndef SPATIAL_H
#define SPATIAL_H


/* RoomSize data structure representing a 2D room size.  */
typedef struct RoomSize {
    unsigned int x_size;
    unsigned int y_size;
} RoomSize_T;

/* Creates a new room size instance.
   Returns the room size instance.  */
RoomSize_T create_room_size(unsigned int x_size, unsigned int y_size);

#endif //SPATIAL_H
