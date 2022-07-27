# Rat in a maze 

You receive an N*N maze with a rat placed in maze [0] [0]. 

Find and print all the paths that rat can follow to reach its destination, ie the maze [N-1] [N-1]. 

The rat can move in any direction (left, right, up and down). 

The value of each cell in the maze can be 0 or 1. 
0 - Blocked   1-Open


* Check for the current cell, if it is the destination cell, then the puzzle is solved.
* If not, then we will try to move downward and see if we can move in the downward cell or not (to move in a cell it must be vacant and not already present in the path).
* If we can move there, then we will continue with the path taken to the next downward cell.
* If not, we will try to move to the rightward cell. And if it is blocked or taken, we will move upward.
* Similarly, if we can't move up as well, we will simply move to the left cell.
* If none of the four moves (down, right, up, or left) are possible, we will simply move back and change our current path (backtracking).
* Thus, the summary is that we try to move to the other cell (down, right, up, and left) from the current cell and if no movement is possible, then just come back and change the direction of the path to another cell.
