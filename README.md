# Lem-in
Elementary algorithmic project - Graph Traversal. 
Program solves a random labyrinth and lead random number of ants through in the most optimized way distributing them on different paths.
It's a graph traversal problem: we use the breadth-first search algorithm implemented with adjacency lists (linked list) and a custom
algorithm to distribute the ants based on their total number and paths they can use.

This was a group project done by dwald (eryndi) and [hadleycode](https://github.com/hadleycode).

## Usage
```
./lem-in [-details] < [map_name]
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
42
##start
1 23 3
2 16 7
#comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
```

## lem-in
