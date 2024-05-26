#ifndef UTILS_H
#define UTILS_H

#include "spatial.h"


/* Get the room size form the user input.
   Returns a room size instance.

   This function will handle all kinds of faulty inputs, except
   unrealisticly large integer numbers that could cause arithmetic
   overflow. For such numbers the behaviour is undifined.  */
RoomSize_T get_room_size();

#endif //UTILS_H
