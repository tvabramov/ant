# ant
**ant** is a CLI utility to count ant's waypoints.

## How to build it
Just clone the code and:
```sh
$ cd ant && make
```
Note: you need a c++17 compatible compiler and "make" utility.
If you want to run tests, just:
```sh
$ make test
```
But you will also need a python2 installed.

## Usage
```sh
$ ./ant <init_x> <init_y> <deepness>
```
where `init_x` and `init_y` are initial coordinates of the ant, and `deepness` is the max sum of coordinates' digits.
