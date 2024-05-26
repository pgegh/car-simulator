#include "simulation.h"

#include <stdio.h>
#include <stdlib.h>


Simulation_T *create_simulation(const Room_T *room, const Car_T *car, const char *commands_string) {
    Simulation_T *new_simulation = (Simulation_T *) malloc(sizeof(Simulation_T));
    new_simulation->room = *room;
    new_simulation->car = *car;
    new_simulation->commands_string = commands_string;

    return new_simulation;
}

void print_simulation_state_info(const Simulation_T *simulation) {
    printf("room size %dx%d,\n"
           "car type %d,  {0: Monster Truck}\n"
           "car location (%d, %d),\n"
           "car direction %s,\n"
           "car speed %d,\n"
           "command string: %s.\n\n",
           simulation->room.room_size.x_size,
           simulation->room.room_size.y_size,
           simulation->car.type,
           simulation->car.position.x_coordinate,
           simulation->car.position.y_coordinate,
           dir_to_str(simulation->car.direction),
           simulation->car.speed,
           simulation->commands_string);
}
