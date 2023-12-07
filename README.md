# IMS Project

SHO Simulation of skipark Ski Králiky

## Usage
```utf-8
./skicentrum-sim	[-h | --help] [-i iterations | --iterations iterations]
			[-s skiers | --skiers skiers] [-t time | --shift-time time]
			[-g gap | --skilift-gap gap] [-r strict_seats | --strict strict_seats]
			[-c skilift_cars | --skilift-cars skilift_cars]
```
```utf-8
-i | --iterations iterations     - Specifies the number of iterations the simulation will be run for.
                                   DEFAULT VALUE: 5
                                   MINIMUM VALUE: 1
-s | --skiers skiers             - Specifies the number of skiers skiing in the skipark
                                   DEFAULT VALUE: 500
                                   MINIMUM VALUE: 1
-t | --shift-time time           - Specifies the duration of the workshift (duration of the simulation) (in seconds).
                                   From this duration a 10 minute margin will be subtracted, to simulate turning off the skilift.
                                   DEFAULT VALUE: 25200 (7 hours)
                                   MINIMUM VALUE: 3600 (1 hour)
-g | --skilift-gap gap           - Specifies the gap between each skilift car (in seconds).
                                   DEFAULT VALUE: 7
                                   MINIMUM VALUE: 1
-r | --strict strict_seats       - Specifies the number of seats that will be occupied at all times, meaning simulation will not allow seating by less or more seats than specified.
                                   DEFAULT VALUE: OFF
                                   MINIMUM VALUE: 1
                                   MAXIMAL VALUE: 4
-c | --skilift-cars skilift_cars - Specifies the number of skilift cars on the skilift.
                                   DEFAULT VALUE: 48
                                   MINIMUM VALUE: 48
-h | --help                      - Prints help
```

## Building the executable

Executable can be build using ```GNU make``` from the root directory of the project using following commands:

```utf-8
make
```
or
```utf-8
make all
```

## Running the simulation

Simulation can be run with default values from the root directory of the project using following commands:

```utf-8
make run
```
or
```utf-8
./skicentrum-sim
```

Running with custom values can be done by utilizing parameters specified above.

## Authors
- Romana Ďuráčiová (xdurac01)
- Matúš Ďurica (xduric06)
