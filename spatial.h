#ifndef SPATIAL_H
#define SPATIAL_H

/* Direction enumeration representing North, East, South, and West.  */
typedef enum Direction { North, East, South, West } Direction_E;

/* RoomSize data structure representing a 2D room size.  */
typedef struct RoomSize {
    unsigned int x_size;
    unsigned int y_size;
} RoomSize_T;

/* Creates a new room size instance.
   Returns the room size instance.  */
RoomSize_T create_room_size(unsigned int x_size, unsigned int y_size);

/* Locatoin data structure that will represents positions in 2D space.  */
typedef struct Position {
    unsigned int x_coordinate;
    unsigned int y_coordinate;
} Position_T;

/* Creates a new position instance.
   Returns the position instance.  */
Position_T create_position(unsigned int position_x, unsigned int position_y);

/* Locatoin data structure that will represents positions in 2D space.  */
typedef struct PositionDirection {
    Position_T position;
    Direction_E direction;
} PositionDirection_T;

/* Creates a new instance of the position and the direction of the car.
   Returns the position direction instance.  */
PositionDirection_T create_position_direction(Position_T position, Direction_E direction);

/* Converts direction enum to a string representations.  */
char *dir_to_str(Direction_E direction);

#endif //SPATIAL_H
