#include "spatial.h"

#include <stdio.h>
#include <stdlib.h>


RoomSize_T create_room_size(const unsigned int x_size, const unsigned int y_size) {
    RoomSize_T new_room_size;
    new_room_size.x_size = x_size;
    new_room_size.y_size = y_size;

    return new_room_size;
}

Position_T create_position(const unsigned int position_x, const unsigned int position_y) {
    Position_T new_position;
    new_position.x_coordinate = position_x;
    new_position.y_coordinate = position_y;
    return new_position;
}

PositionDirection_T create_position_direction(const Position_T position, const Direction_E direction) {
    PositionDirection_T new_position_direction;
    new_position_direction.position = position;
    new_position_direction.direction = direction;

    return new_position_direction;
}

char *dir_to_str(Direction_E direction) {
    switch (direction) {
        case North:
            return "North";
        case East:
            return "East";
        case South:
            return "South";
        case West:
            return "West";
        default:
            printf("Invalid enum!");
            exit(1);
    }
}
