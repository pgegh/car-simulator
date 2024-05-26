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


/* Simulation result data structure which represents the results of a simulation run.  */
typedef struct SimulationResults {
    bool success;
    Position_T car_final_position;
    Direction_E car_final_direction;
    unsigned int last_successful_command_position;
} SimulationResults_T;


/* Runs the simulation and returns the resulsts of the run.  */
SimulationResults_T run_simulation(Simulation_T *simulation);


/* Prints a human readable simulation results.  */
void print_simulation_results(const SimulationResults_T *simulation_results);


#endif //SIMULATION_H
