#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
using namespace std;


// ************************************************************************
// helper functions (do not change these functions)
// ************************************************************************

// print the maze map
void print_maze(char maze[], int width, int height) {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            cout << maze[i*width+j] << " ";
        }
        cout << endl;
    }
}

// print the planned path
void print_path(char maze[], bool path[], int width, int height) {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (path[i*width+j]) {
                cout << "x" << " ";
            } else {
                cout << maze[i*width+j] << " ";
            }
        }
        cout << endl;
    }
}

// ************************************************************************
// core functions (you need to complete these functions)
// ************************************************************************

// helper function: test (x,y) is a valid position (within the maze map) or not
// return true if (x, y) is a valid cell
bool is_valid(int x, int y, int width, int height) {
    //convert x and y into the 1D big ass array maze[] first
    // check if x is in the range of the columns, width
    if (x<0||x>width || y<0 || y> height-1){
        return false;
    }
    else{
        return true;
    }
}

// helper function: test (x,y) is the Exit or not 
// return true if (x, y) is the Exit
bool is_exit(int x, int y, int end_x, int end_y) {
    // check if the values of x and y are at the end
    if (x==end_x && y==end_y){
        return true;
    }
    else{
        return false;
    }
}

// helper function: test (x,y) is a wall or not
// return true if (x, y) is a dead cell (wall)
bool is_wall(char maze[], int x, int y, int width, int height) {
    if (maze[y*width + x]=='#'){
        return true; // RETURN TRUE IF IT IS A DEAD WALL
    }
    else{
        return false;
    }
}

// helper function: test (x,y) is a dangerous position or not
// return true if (x, y) is a dangerous cell
bool is_dangerous(char maze[], int x, int y, int width, int height) {
        // verify all cases for tom
    int tom_x, tom_y;
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (maze[i*width+j]== 'T') { //if the position number contains element 'T' in the array, then it is tom's position 
                tom_x=j;
                tom_y=i;
                break;
            }
        }
    }
    // no need to check for valid move as we are sure that x and y are already validated
    if(tom_x==x && tom_y+1==y||tom_x==x && tom_y-1==y || tom_x+1 ==x && tom_y==y || tom_x-1==x && tom_y==y || \
    tom_x-1==x && tom_y-1==y||tom_x+1==x && tom_y-1==y || tom_x-1 ==x && tom_y+1==y || tom_x+1==x && tom_y+1==y)
    {// check if the position of x is next to tom or not (up down left right + all 4 diagonals)
        return true;
    }
    else{
        return false;
    }
}

/**
    task 1: find a safe path to the Exit 
    description: Given a maze map, the entry (x, y) and the exit (exit_x, exit_y), 
    find a safe path from the entry to the exit, and save the planned path.

    @param maze the maze map: '.' (empty cell), 'x' (dead cell), 'T' (Tom), 'o' (cheese).
    @param path a variable to save the planned path: true (included), false (not included)
    @param x x axis of the entry.
    @param y y axis of the entry.
    @param exit_x x axis of the exit.
    @param exit_y y axis of the exit.
    @param width width of the maze map.
    @param height height of the maze map.
    @return whether find a safe path from (x,y) to (exit_x, exit_y) or not
**/
bool find_safe_path(char maze[], bool path[], int x, int y, int exit_x, int exit_y, int width, int height) {
    // fill your code here.
    int count =0;
    // base case, if find the exit
    if (is_exit(x,y,exit_x,exit_y)){
        path[y*width+x]= true;
        return true;
    }
    // recursive part
    if (x==0 & y==0){
        path[y*width+x]= true;
    }
    if (is_exit(x,y,exit_x,exit_y)== false){
        // check if it is valid, is a wall, or is dangerous area
        // prioritise moving to the right, then moving down
        if(is_valid(x,y,width, height)&& !is_wall(maze, x,y,width,height) && !is_dangerous(maze, x, y, width, height)){ // check if it is valid
            path[(y)*width+x]=true;

        // mark position of x, y as solution path 
            if (find_safe_path(maze, path, x+1, y  , exit_x, exit_y, width, height)== true){ 
                return true;
                }
            else if (find_safe_path(maze, path, x  , y+1, exit_x, exit_y, width, height)== true){ 
                return true;
                }
            else {
                path[y*width +x]=false;
                return false;
            }       
        }
        else{
            //unmark x and y as solution path 
            return false;
        }
    }
}

/**
    task 2: find a safe path with cheese to the Exit
    description: Given a maze map, find a safe path from the entry to the exit, 
    and save the planned path. Note that the default entry and exit are (0, 0) 
    and (width-1, height-1).

    @param maze the maze map: '.' (empty cell), 'x' (dead cell), 'T' (Tom), 'o' (cheese).
    @param path a variable to save the planned path: true (included), false (not included)
    @param cheese_x x axis of the cheese.
    @param cheese_y y axis of the cheese.
    @param width width of the maze map.
    @param height height of the maze map.
    @return whether find a safe path through (cheese_x, cheese_y) from (x,y) to (exit_x, exit_y) or not
**/
bool find_safe_path_with_cheese(char maze[], bool path[], int cheese_x, int cheese_y, int width, int height) {
    return ((find_safe_path(maze, path, 0, 0, cheese_x, cheese_y, width, height) && find_safe_path(maze, path, cheese_x, cheese_y, width-1, height-1, width, height)));
    
}
    


// Maze Game: Tom and Jerry
int main() {
    // game initialization
    unsigned int width;
    unsigned int height;
    unsigned int cheese_x;
    unsigned int cheese_y;

    // Change this paramenter from 0 to 5 to test different cases.
    unsigned int test_case = 4;

    // set width, height and cheese_x, cheese_y
    switch(test_case) {
        case 1:
            width = 11; height = 10; cheese_x = 6; cheese_y = 7;
            break;
        case 2:
            width = 14; height = 10; cheese_x = 3; cheese_y = 6;
            break;
        case 3:
            width = 16; height = 8; cheese_x = 7; cheese_y = 4;
            break;
        case 4:
            width = 15; height = 9; cheese_x = 8; cheese_y = 3;
            break;
        case 5:
            width = 15; height = 9; cheese_x = 3; cheese_y = 5;
            break;
        default:
            width = 7; height = 5; cheese_x = 3; cheese_y = 1;
            break;
    }

    // a char array recording the maze map.
    char maze[140];

    // set maze map
    if (test_case == 0) {
        char tmp[140] = {
            '.', '.', '.', '.', '.', '#', '.', 
            '.', '#', '#', 'o', '.', '.', 'T',
            '.', '.', '.', '.', '.', '.', '#', 
            '.', '.', '.', '.', '.', '#', '.', 
            '.', '.', '#', '.', '.', '.', '.', 
        }; 
        copy(tmp, tmp + width*height, maze);
    }
    else if (test_case == 1) {
        char tmp[140] = {
            '.', '.', '#', '.', '#', '.', '.', '.', '.', '#', '.', 
            '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 
            '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '#', 
            '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '#', '#', '.', '.', '.', '.', '#', '.', '#', '.',
            '.', '.', '.', '#', '#', '.', '#', '#', '.', '.', '.',
            '.', 'T', '.', '.', '#', '.', '.', '.', '.', '#', '.',
            '.', '.', '.', '.', '.', '#', 'o', '.', '#', '.', '.',
            '#', '.', '.', '.', '#', '#', '.', '#', '.', '.', '#',
            '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.',
        };
        copy(tmp, tmp + width*height, maze);
    } else if (test_case == 2) {
        char tmp[140] = {
            '.', '.', '.', '.', '.', '.', 'T', '.', '.', '.', '#', '.', '.', '#',
            '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.',
            '#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '#', '.', '.',
            '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
            '#', '.', '#', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#',
            '.', '.', '#', 'o', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '.', '.', '.', '.', '.', '.', '#', '.', '#', '.', '.', '.', '#',
            '.', '.', '.', '#', '#', '.', '#', '.', '.', '.', '#', '#', '.', '.',
            '.', '#', '#', '#', '.', '.', '.', '.', '.', '#', '.', '#', '.', '.',
        };
        copy(tmp, tmp + width*height, maze);
    } else if (test_case == 3) {
        char tmp[140] = {
            '.', '.', '#', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.',
            '.', '#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.',
            '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', 'T', '#', '.',
            '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#', '.', '#',
            '.', '#', '.', '#', '.', '.', '.', 'o', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '#', '.', '#', '#',
            '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '#',
            '.', '#', '.', '.', '#', '.', '.', '#', '.', '#', '#', '.', '.', '.', '.', '.',
        }; 
        copy(tmp, tmp + width*height, maze);
    } else if (test_case == 4) {
        char tmp[140] = {
            '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.',
            '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
            '#', '#', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '#', '.', '.', '.', '.', '#', '.', 'o', '#', '.', '.', '#', '.', '.',
            '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.',
            '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.',
            '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '#',
            '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.',
            '.', '#', '#', '.', '#', '#', '.', '#', '#', 'T', '.', '.', '#', '.', '.',
        }; 
        copy(tmp, tmp + width*height, maze);
    } else if (test_case == 5) {
        char tmp[140] = {
            '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#',
            '.', '#', '.', '.', '#', '#', '#', '.', '.', '.', '.', '.', '#', '.', '.',
            '.', '.', '.', '#', '#', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.',
            '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#',
            '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'T', '.', '#', '.',
            '.', '.', '.', 'o', '.', '.', '.', '#', '.', '.', '#', '#', '.', '.', '.',
            '#', '.', '.', '#', '.', '#', '.', '.', '.', '#', '.', '.', '#', '.', '.',
            '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.',
            '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
        }; 
        copy(tmp, tmp + width*height, maze);
    } else {
        cout << "No more test cases!" << endl;
        return 0;
    }

    // a bool array recording the path, "true" means the planned path goes through the cell.
    bool path[140];
    for (int i=0; i<width * height; i++) {
        path[i] = false;
    }

    cout << "**************************************************" << endl;
    cout << "Maze Game: Tom and Jerry" << endl;
    cout << "Maze Size (Width x Height): " << width << "x" << height << endl;
    cout << "Cheese Location: (" << cheese_x << "," << cheese_y << ")" << endl;
    cout << "**************************************************" << endl;

    print_maze(maze, width, height);
    cout << endl;

    // find a path from the entry to the exit
    bool status;
    status = find_safe_path(maze, path, 0, 0, width-1, height-1, width, height);
    if (status) {
        cout<< "found path to exit"<< endl;
        cout << "Find a path to the Exit: " << endl;
        print_path(maze, path, width, height);
    } else {
        cout << "Cannot find a path to the Exit!" << endl;
    }

    cout << endl;

    // find a path with cheese to the exit
    for (int i=0; i<width*height; i++) {
        path[i] = false;
    }

    status = find_safe_path_with_cheese(maze, path, cheese_x, cheese_y, width, height);
    if (status) {
        cout << "Find a path with cheese to the Exit: " << endl;
        print_path(maze, path, width, height);
    } else {
        cout << "Cannot find a path with cheese to the Exit!" << endl;
    }
	return 0;
}