#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void _flush();

bool _is_faulty_commands_string(const char *string);


RoomSize_T get_room_size() {
    printf("Provide the room size in meters as two integers separated with a "
        "space in the format \"WIDTH LENGTH\" and then press enter.\n");
    int room_x_size;
    int room_y_size;

    while (
        scanf("%d %d", &room_x_size, &room_y_size) != 2 ||
        room_x_size <= 0 || room_y_size <= 0
    ) {
        // Empties the input buffer before requesting a new input
        _flush();

        printf("The room size should be two positive integeres seperated "
            "by a single space. Try again:\n");
    }

    return create_room_size((unsigned int) room_x_size, (unsigned int) room_y_size);
}


PositionDirection_T get_car_start_position_and_direction(const RoomSize_T *const room_size) {
    // Empties the input buffer before requesting a new input
    // scanf("%*[^\n]");
    _flush();

    printf("Provide the start position and heading with format \"X Y D\" "
        "where X is the position on the rooms width axis and Y on the rooms length "
        "axis. D is the cardinal direction (the heading) given as 'N', 'E', 'S', or"
        " 'W' character.\n");
    int position_x;
    int position_y;
    char direction_char;

    while (
        scanf("%d %d %c", &position_x, &position_y, &direction_char) != 3 ||
        position_x < 0 || position_x >= room_size->x_size ||
        position_y < 0 || position_y >= room_size->y_size ||
        (direction_char != 'N' &&
         direction_char != 'E' &&
         direction_char != 'S' &&
         direction_char != 'W')
    ) {
        // Empty the input buffer before requesting a new input
        _flush();

        printf("The input should have the format \"X Y D\" where X is the "
            "position on the rooms width axis and Y on the rooms length axis. D is"
            " the cardinal direction (the heading) givern as 'N', 'E', 'S', or 'W'"
            " character.\n");
    }

    const Position_T position = create_position((unsigned int) position_x, (unsigned int) position_y);

    Direction_E direction;
    switch (direction_char) {
        case 'N':
            direction = North;
            break;
        case 'E':
            direction = East;
            break;
        case 'S':
            direction = South;
            break;
        case 'W':
            direction = West;
            break;
        default:
            printf("Something went wrong with the heading input.");
            exit(1);
    }
    return create_position_direction(position, direction);
}


void get_commands_string(char *commands_string) {
    // Empties the input buffer before requesting a new input
    _flush();

    printf("Provide the command string. Characters {'F', 'B', 'L', 'R'} are "
        "only accepted. The string should not contain any spaces.\n");

    while (
        scanf("%s", commands_string) != 1 ||
        _is_faulty_commands_string(commands_string)
    ) {
        // Empty the input buffer before requesting a new input
        _flush();

        printf("Invalid input! The string either contains illegal characters. Try again.\n");
    }
}


void _flush() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


bool _is_faulty_commands_string(const char *string) {
    const int len = strlen(string);

    for (int i = 0; i < len; i++)
        if (string[i] != 'F' && string[i] != 'B' && string[i] != 'L' && string[i] != 'R')
            return true;

    return false;
}
