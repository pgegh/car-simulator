#ifndef UTILS_H
#define UTILS_H

#include "spatial.h"


/* Get the room size form the user input.
   Returns a room size instance.

   This function will handle all kinds of faulty inputs, except
   unrealisticly large integer numbers that could cause arithmetic
   overflow. For such numbers the behaviour is undifined.  */
RoomSize_T get_room_size();

/* Get the car start location and direction input form the user.
   Check the given input is valid and within the room size.
   Return a PositionDirection strusture.

   This function will handle all kinds of faulty inputs, except
   unrealisticly large integer numbers that could cause arithmetic
   overflow. For such numbers the behaviour is undifined.  */
PositionDirection_T get_car_start_position_and_direction(const RoomSize_T *room_size);

#endif //UTILS_H
