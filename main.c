#include <stdio.h>

#include "cars.h"
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

    const PositionDirection_T position_direction = get_car_start_position_and_direction(&room_size);
    const Car_T car = create_car(MonsterTruck, 1u, &position_direction);
    printf("%d %d %s\n", room.room_size.x_size, room.room_size.y_size, dir_to_str(car.direction));

    printf(
        "#########################################################\n"
        "############  The simulation has finnished  #############\n"
        "#########################################################\n");
    return 0;
}
