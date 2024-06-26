# car-simulator

A simulation for a controlled car moving in a 2D room. A code assignment for a job interview.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Author](#author)
- [Developer Notes](#developer_notes)

## Installation

Instructions for Linux operating system.

1. Clone the repository:
    ```shell
    git clone https://github.com/pgegh/car-simulator.git
    ```
2. Navigate to the cloned directory:
    ```shell
    cd car-simulator
    ```
3. Compile the project (requires cmake):
    ```shell
    cmake -B build && cd build && make
    ```

## Usage

1. Navigate to the build directory
    ```shell
    cd  [projects_parent_directory]/car-simulator/build/
    ```
2. Execute the binary file
    ```shell
    ./car-simulator
    ```

## Author

The author of this code is Hovig Manjikian. The code was written with no AI aid.

## Developer Notes

### Assumptions

- The description document does not explicitly specify the format of the user input for the room size. We assume the
  format of the input is "x-axis y-axis" where x-axis represents the width and y-axis represents the length.
- There is no indication in the provided illustration on how the room is aligned with the cardinal directions: N, E, S,
  and W. We assume that the length (y-axis) is in parallel aligned with the N-S axis.
- There is no explicit specification for the integers in the input of the car start position. We assume the format is "
  x-axis y-axis direction".
- There is no upper limit specified for the dimensions and quantities. We assume that room sizes larger than 1'000'
  000'000 meter are unrealistic. And commands of string length longer than 1'000'000 are also unrealistic.
- There is no specification of the minimum number of commands in a commands string. I assume the 0 commands, i.e. an
  empty commands string is a valid command sequence. However, it is not supported by the current implementation.
  Currently, a minimum of 1 command is needed.

### Design Choices

In this project we prioritize readability and scalability over performance.

- I have divided the code into small and manageable modules.
- Some data structures might seem redundant. But they were created to make future implementations easier. One such
  example is the data structure of the car type `enum CarType`, although we only have one type of car this data
  structure will make it easy to add new types of car in the future.
- Data input and output functionalities were isolated into specialized functions. This will make future implementations
  of other input output methods easier.

### Weaknesses

- The input functions are not as robust as I would wish. I have implemented some measures to handle faulty input, but it
  is far from complete. One obvious weakness is when we input unrealistically large numbers. Another weakness in the
  input fault handling is that the implementation will not complain on illegal input that is concatenated at the end of
  a legal input.
- A systematic thorough testing has not been done. The tests are only done on system-level. A lower level unit-tests are
  missing.
- Apart from the test cases all the project files are in the main directory. It will be much better if the project files
  were reorganized so that the source files are moved into a dedicated `src/` directory.

### Todo

- Implement support for command sequences with zero commands in them.
- Implement systematic and thorougher tests that include also unit-tests.
- Reorganize the files of the project into dedicated directories.
