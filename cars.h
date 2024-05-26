#ifndef CARS_H
#define CARS_H

#include "spatial.h"

/* Car type enumeration representing defferent car types.  */
typedef enum CarType { MonsterTruck } CarType_E;

/* Data structure for representing a car.  */
typedef struct Car {
    CarType_E type;
    unsigned int speed;
    Direction_E direction;
    Position_T position;
} Car_T;

/* Create a new car instance.
   Return the car instance.  */
Car_T create_car(CarType_E type, unsigned int speed, const PositionDirection_T *position_direction);


#endif //CARS_H
