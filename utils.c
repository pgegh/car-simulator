#include "utils.h"

#include <stdio.h>


void _flush();

RoomSize_T get_room_size() {
    printf("Provide the room size as two integers separated with a space in the"
        " format \"WIDTH LENGTH\" and then press enter.\n");
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

void _flush() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
