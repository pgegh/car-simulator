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

- The description document does not explicitly specify the format of the user input for the room size. We assume the format of the input is "x-axis y-axis" where x-axis represents the width and y-axis represents the length.
- There is no indication in the provided illustration on how the room is aligned with the cardinal directions: N, E, S, and W. We assume that the length (y-axis) is in parallel aligned with the N-S axis.
- There is no explicit specification for the integers in the input of the car start position. We assume the format is "x-axis y-axis direction".
- There is no upper limit specified for the dimensions and quantities. We assume that room sizes larger than 1'000'000'000 meter are unrealistic. And commands of string length longer than 1'000'000 are also unrealistic.

### Design Choices

In this project we prioritize readability and scalability over performance.

### Weaknesses