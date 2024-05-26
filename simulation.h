#ifndef SIMULATION_H
#define SIMULATION_H

#include "cars.h"
#include "room.h"

/* Simulation data structure which represents a simulation run.  */
typedef struct Simulation {
    Car_T car;
    Room_T room;
    const char *commands_string;
    unsigned int command_index;
} Simulation_T;

/* Malloc a simulation instance that contains all simulation state information.
   Returns a pointer to the simulation instance.  */
Simulation_T *create_simulation(const Room_T *room, const Car_T *car, const char *commands_string);

/* Prints a human readable representation of all data in the simulation instance.  */
void print_simulation_state_info(const Simulation_T *simulation);

#endif //SIMULATION_H
