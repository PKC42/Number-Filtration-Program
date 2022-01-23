# Number-Filtration-Program

Purpose: The purpose of this program is to create a number filter that takes several numbers inputed from 
stdin, removes duplicates and prints a list of all the numberes entered (duplicates not included) in ascending order. 
An important detail is that the rane is from 0 up to 2 billion. This means that there may be up to 2 billion unique 
integers entered. This is an issue with datastructures such as trees because storing all 2 billion integers will 
require at least 8 billion bytes or 8 gigabytes. This uses too much memory. The program below stores the state of each
integer entered as a bit. If there can be up to 2 billion unique numbers, there needs to be 2 billion bits. This can 
be achived using arrays and bitflags like in the previous assignments. In this assignment, an array will hold integers
which will contain 32 bits (sizeof(int)). The array will be used in a way that all the bits are a single bit stream. 
These bits will store whether or not a specific output has been entered (which will be entered using the << operator). 
If using an integer array -> 2,000,000,000 bits / 32 bits = 62,500,000. The array must at the maximum, be able to store
62,500,000 integers. This number multiplied by 4 bytes is 250,000,000 or 250 mega bytes. This method uses far less memory than 
using other data structures that will simply store the integer entered. 
Note: This program needs to keep iterating until the highest entered flag_position. This as a result, large numbers take a much 
longer time to get. 
