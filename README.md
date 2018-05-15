# Lem-in
Elementary algorithmic project - Graph Traversal. 
Program solves a random labyrinth and lead random number of ants through in the most optimized way distributing them on different paths.
It's a graph traversal problem: we use the breadth-first search algorithm implemented with adjacency lists (linked list) and a custom
algorithm to distribute the ants based on their total number and paths they can use.

This was a group project done by dwald (eryndi) and [hadleycode](https://github.com/hadleycode).

## Usage
```
./lem-in < [map_name]
```
or run a script from the MAPS_TEST folder
```
./run_test.sh
```

## Input data

The program receive the data describing the ant farm from the standard output in the following format:
```
number_of_ants
the_rooms
the_links
```

- The rooms, which are defined by: name coord_x coord_y.
- The links, which are defined by: name1-name2.
- All of it is broken by comments, which start with #.
- Lines that start with ## are commands modifying the properties of the line that comes right after.

### Example
```
21
##start
1 0 0
2 3 0
3 5 0
4 7 0
5 3 3
6 5 3
7 7 3
8 0 5
9 3 5
10 5 5
##end
11 7 5
12 3 7
13 5 7
1-2
1-9
2-5
2-3
2-6
3-4
3-6
4-7
5-9
6-7
6-10
7-11
8-9
9-10
9-12
10-11
11-13
12-13
```

## lem-in

![alt text](https://github.com/eryndi/Lem-in/blob/master/screenshot/Lem-in-out.png "Lem-in output")

