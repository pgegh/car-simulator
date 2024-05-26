#include "cars.h"


Car_T create_car(const CarType_E type, const unsigned int speed,
                 const PositionDirection_T *const position_direction) {
    Car_T new_car;
    new_car.type = type;
    new_car.speed = speed;
    new_car.direction = position_direction->direction;
    new_car.position = position_direction->position;

    return new_car;
}
