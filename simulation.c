#include "simulation.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool _execute_command_forward(Car_T *car, const Room_T *room);

bool _execute_command_backward(Car_T *car, const Room_T *room);

bool _execute_command_turn_left(Car_T *car, Room_T *room);

bool _execute_command_turn_right(Car_T *car, Room_T *room);

bool _move_car(Direction_E direction, Car_T *car, const Room_T *room);

SimulationResults_T _create_simulation_results(bool success, Position_T position,
                                               Direction_E direction, unsigned int command_index);


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


SimulationResults_T run_simulation(Simulation_T *simulation) {
    SimulationResults_T results;
    results.success = true;
    results.last_successful_command_position = 0;
    results.car_final_direction = simulation->car.direction;
    results.car_final_position = simulation->car.position;

    const unsigned int number_of_commands = strlen(simulation->commands_string);
    bool command_success;

    for (unsigned int i = 0; i < number_of_commands; i++) {
        switch (simulation->commands_string[i]) {
            case 'F':
                printf("Executing command F\n");
                command_success = _execute_command_forward(&(simulation->car), &(simulation->room));
                break;
            case 'B':
                printf("Executing command B\n");
                command_success = _execute_command_backward(&(simulation->car), &(simulation->room));
                break;
            case 'L':
                printf("Executing command L\n");
                command_success = _execute_command_turn_left(&(simulation->car), &(simulation->room));
                break;
            case 'R':
                printf("Executing command R\n");
                command_success = _execute_command_turn_right(&(simulation->car), &(simulation->room));
                break;
            default:
                printf("Something went wrong with the command string.");
                exit(1);
        }
        if (!command_success) {
            results.success = false;
            results.car_final_direction = simulation->car.direction;
            results.car_final_position = simulation->car.position;
            results.last_successful_command_position = i;

            return results;
        }
    }

    results.car_final_direction = simulation->car.direction;
    results.car_final_position = simulation->car.position;
    results.last_successful_command_position = number_of_commands;

    return results;
}


void print_simulation_results(const SimulationResults_T *simulation_results) {
    if (simulation_results->success) {
        printf("\nThe simulation has ran successfully. The car did not crash into"
               " any wall during the simulation. The final position of the car is "
               "(%d, %d) and the car is heading %s.\n\n",
               simulation_results->car_final_position.x_coordinate,
               simulation_results->car_final_position.y_coordinate,
               dir_to_str(simulation_results->car_final_direction));
    } else {
        printf("\nThe simulation has ran successfully. However, the car has"
               " crashed into the wall. The crash happened when command number "
               "%d was executed. The cars last position before the crash was "
               "(%d, %d) and it was heading towards the %s.\n\n",
               simulation_results->last_successful_command_position + 1,
               simulation_results->car_final_position.x_coordinate,
               simulation_results->car_final_position.y_coordinate,
               dir_to_str(simulation_results->car_final_direction));
    }
}


SimulationResults_T _create_simulation_results(const bool success,
                                               const Position_T position,
                                               const Direction_E direction,
                                               const unsigned int command_index) {
    SimulationResults_T new_simulation_results;
    new_simulation_results.success = success;
    new_simulation_results.car_final_position = position;
    new_simulation_results.car_final_direction = direction;
    new_simulation_results.last_successful_command_position = command_index;

    return new_simulation_results;
}


bool _execute_command_forward(Car_T *car, const Room_T *room) {
    switch (car->direction) {
        case North:
            return _move_car(North, car, room);
        case East:
            return _move_car(East, car, room);
        case South:
            return _move_car(South, car, room);
        case West:
            return _move_car(West, car, room);
        default:
            printf("Something went wrong with the command execution.");
            exit(1);
    }
}


bool _execute_command_backward(Car_T *car, const Room_T *room) {
    switch (car->direction) {
        case North:
            return _move_car(South, car, room);
        case East:
            return _move_car(West, car, room);
        case South:
            return _move_car(North, car, room);
        case West:
            return _move_car(East, car, room);
        default:
            printf("Something went wrong with the command execution.");
            exit(1);
    }
}


bool _execute_command_turn_left(Car_T *car, Room_T *room) {
    switch (car->direction) {
        case North:
            car->direction = West;
            break;
        case East:
            car->direction = North;
            break;
        case South:
            car->direction = East;
            break;
        case West:
            car->direction = South;
            break;
        default:
            printf("Something went wrong with the command execution.");
            exit(1);
    }
    return true;
}


bool _execute_command_turn_right(Car_T *car, Room_T *room) {
    switch (car->direction) {
        case North:
            car->direction = East;
            break;
        case East:
            car->direction = South;
            break;
        case South:
            car->direction = West;
            break;
        case West:
            car->direction = North;
            break;
        default:
            printf("Something went wrong with the command execution.");
            exit(1);
    }
    return true;
}


bool _move_car(Direction_E direction, Car_T *car, const Room_T *room) {
    int temp_new_position;

    switch (direction) {
        case North:
            temp_new_position = car->position.y_coordinate + car->speed;
            if (temp_new_position >= room->room_size.y_size)
                return false;
            car->position.y_coordinate = temp_new_position;
            break;
        case East:
            temp_new_position = car->position.x_coordinate + car->speed;
            if (temp_new_position >= room->room_size.x_size)
                return false;
            car->position.x_coordinate = temp_new_position;
            break;
        case South:
            temp_new_position = car->position.y_coordinate - car->speed;
            if (temp_new_position < 0)
                return false;
            car->position.y_coordinate = temp_new_position;
            break;
        case West:
            temp_new_position = car->position.x_coordinate - car->speed;
            if (temp_new_position < 0)
                return false;
            car->position.x_coordinate = temp_new_position;
            break;
        default:
            printf("Something went wrong with the command execution.");
            exit(1);
    }

    return true;
}
