# Cedar West Process Simulation - (skynet)

## Description

This project is a simulation of the processes at Cargill's Cedar Rapids West soybean processing plant. The simulation is built to serve initially as a tool for training and assessing competency of new operators and later in the development of the AI powered aspects of Skynet as well as serving as an AI powered simulation that can be used in pre production research to determine start up settings and pre-train the AI on new or experimental products.

## Compilation

### Prerequisites

- **Linux**: `sudo apt-get install g++`
- **Windows**: [MinGW](https://sourceforge.net/projects/mingw-w64/)
- **MacOS**: `brew install gcc`

To compile the project with `g++`, clone the repository and run the following command in the root directory of the project:

```bash
g++ -o main.cpp
```

## Running the Simulation

To run the simulation, run the following command in the root directory of the project:

```bash
./main.out # For Linux
./main.exe # For Windows
./main # For MacOS
```
