#include <stdio.h>

#include "room.h"
#include "spatial.h"
#include "utils.h"

int main(void) {
    printf(
        "#########################################################\n"
        "####  WELCOME TO THE RADIO CONTROLLED CAR SIMULATOR  ####\n"
        "#########################################################\n\n");


    const RoomSize_T room_size = get_room_size();
    const Room_T room = create_room(&room_size);

    printf("%d %d\n", room.room_size.x_size, room.room_size.y_size);

    printf(
        "#########################################################\n"
        "############  The simulation has finnished  #############\n"
        "#########################################################\n");
    return 0;
}
