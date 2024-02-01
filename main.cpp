    #include <GL/glut.h>
    #include <cmath>
    #include <cstdlib>
    #include <string>
    #include <sstream>

    const int numRows = 20;
    const int numCols = 200;
    int matrix[numRows][numCols] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 0, 0, 2, 0, 0, 0, 2, 1, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
 	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    float pyramidLength = 2.0f; // Comprimento de uma pirâmide
    float cubeHeight = 2.0f;    // Altura do cubo
    float cameraSpeed = 0.6f;   // Velocidade de movimento da câmera
    float jumpSpeed = 1.0f;     // Velocidade do pulo
    float gravity = 0.4f;    // Velocidade do pulo
    float cameraX = 0.0f;       // Posição inicial da câmera em x
    float cubeY = 0.0f;         // Altura do cubo
    float jumpHeight = 14.0f;
    float jumpBaseHeight = 0.0f;
    std::string keyInfo = "JUMP: SPACE PAUSE: 'h' EXIT: 'Esc'";
	float fps = 0.0f;
	std::string fpsString;
    bool onGround = true;
    bool paused = false;


    bool jumping = false;       // Flag indicando se o cubo está pulando
    
    void init_lighting() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_position[] = {1.0, -0.9, -0.7, -0.9};
    GLfloat light_color[] = {1.0, 1.0, 0.9, 0.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE, light_color);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat mat_ambient_diffuse[] = {1.0, 1.0, 0.7, 0.7};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_ambient_diffuse);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    glShadeModel(GL_SMOOTH);
}

    void drawGround() {
        glBegin(GL_QUADS);
        glColor3d(0.5, 0.5, 0.5);
        glVertex3f(-50.0f, 0.0f, -50.0f);
        glVertex3f(500.0f, 0.0f, -50.0f);
        glVertex3f(500.0f, 0.0f, 50.0f);
        glVertex3f(-50.0f, 0.0f, 50.0f);
        glEnd();
    }
    

    bool checkGroundCollision(float cubeX, float cubeY, float cubeZ, float sideLength) {
	    float cubeHalfSide = sideLength / 2;
	
	    for (int j = 0; j < numCols; ++j) {
	        float planeX = static_cast<float>(j) * pyramidLength - 50.0f;
	
	        for (int i = 0; i < numRows; ++i) {
	            if (matrix[i][j] == 2) {
	                float planeY = i * pyramidLength;
	                
	                // Check collision in x direction
	                if (cubeX + cubeHalfSide > planeX - pyramidLength / 2 &&
	                    cubeX - cubeHalfSide < planeX + pyramidLength / 2) {
	
	                    // Check collision in y direction
	                    if (cubeY >= planeY && cubeY <= planeY + pyramidLength) {
	                        return true; // Collision detected
	                    }
	                }
	            }
	        }
	    }
	
	    return false; // No collision detected
		}
    
    void checkOnGround(){
    	bool a = checkGroundCollision(cameraX, cubeY, 0.0f, pyramidLength);
		if(cubeY == 0.0f || a){
			onGround = true;
			jumpBaseHeight = cubeY;
		}else{
			onGround = false;
		}
	}
	
	bool checkCollision(float x1, float y1, float z1, float x2, float y2, float z2, float objectWidth, float objectHeight) {
	    return (
	        x1 - objectWidth / 2 < x2 + pyramidLength / 2 &&
	        x1 + objectWidth / 2 > x2 - pyramidLength / 2 &&
	        y1 < y2 + pyramidLength &&
	        y1 + objectHeight > y2
	    );
	}
	
	bool checkPausePyramidCollision(float cubeX, float cubeY, float cubeZ, float cubeSideLength, float cubeHeight) {
	    float cubeHalfSide = cubeSideLength / 2;
	    float cubeHalfHeight = cubeHeight / 2;
	
	    for (int j = 0; j < numCols; ++j) {
	        float pyramidX = static_cast<float>(j) * pyramidLength - 50.0f;
	
	        for (int i = 0; i < numRows; ++i) {
	            if (matrix[i][j] == 1) {
	                float pyramidY = i * pyramidLength;
	
	                // Check collision in x, y, and z directions for points on the cube
	                if (checkCollision(cubeX, cubeY, cubeZ, pyramidX, pyramidY, 0.0f, pyramidLength, pyramidLength)) {
	                    return true; // Collision detected, pause the game
	                }
	            }
	        }
	    }
	
	    return false; // No collision detected
	}
	
	bool checkPauseCollision(float cubeX, float cubeY, float cubeZ, float cubeHeight) {
	    float cubeHalfHeight = cubeHeight / 2;
	
	    for (int j = 0; j < numCols; ++j) {
	        float planeX = static_cast<float>(j) * pyramidLength - 50.0f;
	
	        for (int i = 0; i < numRows; ++i) {
	            if (matrix[i][j] == 2) {
	                float planeY = i * pyramidLength;
	
	                // Check collision in x and y directions for points above cubeY
	                if (checkCollision(cubeX, cubeY + cubeHalfHeight, cubeZ, planeX, planeY, 0.0f, pyramidLength, pyramidLength)) {
	                    return true; // Collision detected, pause the game
	                }
	            }
	        }
	    }
	
	    return false; // No collision detected
	}




    void drawPyramid(float x, float y, float z, int heightIndex) {
        glBegin(GL_TRIANGLES);
        glColor3d(0.65, 0.79, 0.34);
        glVertex3f(x, y + 2.0f + heightIndex * pyramidLength, z);
        glVertex3f(x - 1.0f, y + heightIndex * pyramidLength, z - 1.0f);
        glVertex3f(x + 1.0f, y + heightIndex * pyramidLength, z - 1.0f);

        glVertex3f(x, y + 2.0f + heightIndex * pyramidLength, z);
        glVertex3f(x + 1.0f, y + heightIndex * pyramidLength, z - 1.0f);
        glVertex3f(x + 1.0f, y + heightIndex * pyramidLength, z + 1.0f);

        glVertex3f(x, y + 2.0f + heightIndex * pyramidLength, z);
        glVertex3f(x + 1.0f, y + heightIndex * pyramidLength, z + 1.0f);
        glVertex3f(x - 1.0f, y + heightIndex * pyramidLength, z + 1.0f);

        glVertex3f(x, y + 2.0f + heightIndex * pyramidLength, z);
        glVertex3f(x - 1.0f, y + heightIndex * pyramidLength, z + 1.0f);
        glVertex3f(x - 1.0f, y + heightIndex * pyramidLength, z - 1.0f);
        glEnd();
    }

    void drawCube(float x, float y, float z, float sideLength, float height) {
        glBegin(GL_QUADS);
        glColor3d(0.34, 0.65, 0.79); // Cor do cubo
        // Faces do cubo
        glVertex3f(x - sideLength / 2, y, z - sideLength / 2);
        glVertex3f(x + sideLength / 2, y, z - sideLength / 2);
        glVertex3f(x + sideLength / 2, y + height, z - sideLength / 2);
        glVertex3f(x - sideLength / 2, y + height, z - sideLength / 2);

        glVertex3f(x - sideLength / 2, y, z + sideLength / 2);
        glVertex3f(x + sideLength / 2, y, z + sideLength / 2);
        glVertex3f(x + sideLength / 2, y + height, z + sideLength / 2);
        glVertex3f(x - sideLength / 2, y + height, z + sideLength / 2);

        glVertex3f(x - sideLength / 2, y, z - sideLength / 2);
        glVertex3f(x - sideLength / 2, y, z + sideLength / 2);
        glVertex3f(x - sideLength / 2, y + height, z + sideLength / 2);
        glVertex3f(x - sideLength / 2, y + height, z - sideLength / 2);

        glVertex3f(x + sideLength / 2, y, z - sideLength / 2);
        glVertex3f(x + sideLength / 2, y, z + sideLength / 2);
        glVertex3f(x + sideLength / 2, y + height, z + sideLength / 2);
        glVertex3f(x + sideLength / 2, y + height, z - sideLength / 2);

        glVertex3f(x - sideLength / 2, y, z - sideLength / 2);
        glVertex3f(x + sideLength / 2, y, z - sideLength / 2);
        glVertex3f(x + sideLength / 2, y, z + sideLength / 2);
        glVertex3f(x - sideLength / 2, y, z + sideLength / 2);
        glEnd();
    }

    void drawPlane(float x, float y, float z, int heightIndex) {
        // Desenha um cubo do tamanho da pirâmide
        glBegin(GL_QUADS);
        glColor3d(1.0, 0.0, 0.0); // Cor do cubo do plano
        // Faces do cubo
        glVertex3f(x - pyramidLength / 2, y + heightIndex * pyramidLength, z - pyramidLength / 2);
        glVertex3f(x + pyramidLength / 2, y + heightIndex * pyramidLength, z - pyramidLength / 2);
        glVertex3f(x + pyramidLength / 2, y + pyramidLength + heightIndex * pyramidLength, z - pyramidLength / 2);
        glVertex3f(x - pyramidLength / 2, y + pyramidLength + heightIndex * pyramidLength, z - pyramidLength / 2);

        glVertex3f(x - pyramidLength / 2, y + heightIndex * pyramidLength, z + pyramidLength / 2);
        glVertex3f(x + pyramidLength / 2, y + heightIndex * pyramidLength, z + pyramidLength / 2);
        glVertex3f(x + pyramidLength / 2, y + pyramidLength + heightIndex * pyramidLength, z + pyramidLength / 2);
        glVertex3f(x - pyramidLength / 2, y + pyramidLength + heightIndex * pyramidLength, z + pyramidLength / 2);

        glVertex3f(x - pyramidLength / 2, y + heightIndex * pyramidLength, z - pyramidLength / 2);
        glVertex3f(x - pyramidLength / 2, y + heightIndex * pyramidLength, z + pyramidLength / 2);
        glVertex3f(x - pyramidLength / 2, y + pyramidLength + heightIndex * pyramidLength, z + pyramidLength / 2);
        glVertex3f(x - pyramidLength / 2, y + pyramidLength + heightIndex * pyramidLength, z - pyramidLength / 2);

        glVertex3f(x + pyramidLength / 2, y + heightIndex * pyramidLength, z - pyramidLength / 2);
        glVertex3f(x + pyramidLength / 2, y + heightIndex * pyramidLength, z + pyramidLength / 2);
        glVertex3f(x + pyramidLength / 2, y + pyramidLength + heightIndex * pyramidLength, z + pyramidLength / 2);
        glVertex3f(x + pyramidLength / 2, y + pyramidLength + heightIndex * pyramidLength, z - pyramidLength / 2);

        glVertex3f(x - pyramidLength / 2, y + heightIndex * pyramidLength, z - pyramidLength / 2);
        glVertex3f(x + pyramidLength / 2, y + heightIndex * pyramidLength, z - pyramidLength / 2);
        glVertex3f(x + pyramidLength / 2, y + heightIndex * pyramidLength, z + pyramidLength / 2);
        glVertex3f(x - pyramidLength / 2, y + heightIndex * pyramidLength, z + pyramidLength / 2);
        glEnd();
    }

    void update(int value) {
    	// Calculate FPS
	    static int frameCount = 0;
	    static int previousTime = glutGet(GLUT_ELAPSED_TIME);
	    int currentTime = glutGet(GLUT_ELAPSED_TIME);
	    int elapsedTime = currentTime - previousTime;
	
	    frameCount++;
	
	    if (elapsedTime > 1000) {
	        fps = static_cast<float>(frameCount) / (elapsedTime / 1000.0f);
	        frameCount = 0;
	        previousTime = currentTime;
	
	        // Update fpsString
	        std::ostringstream fpsStream;
	        fpsStream << "FPS: " << fps;
	        fpsString = fpsStream.str();
	    }

    	if(!paused){
	        cameraX += cameraSpeed;
	        checkOnGround();	
	        
	
	        if (cameraX > (numCols - 1) * pyramidLength) {
	            cameraX = 0.0f;
	        }
	        if (jumping) {
	   	        cubeY += jumpSpeed;
	
	            // Verifica se o cubo atingiu a altura máxima do pulo
	            if (cubeY >= jumpBaseHeight + jumpHeight) {
	                jumping = false;
	            }
	        } else {
	            // Aplica a gravidade ao cubo
	            // Impede que o cubo vá abaixo do solo
	            if (!onGround) {
	                cubeY -= jumpSpeed;
	            }
	        }
	        if (checkPauseCollision(cameraX, cubeY, 0.0f, cubeHeight)) {
                paused = true;
            }
            if (checkPausePyramidCollision(cameraX, cubeY, 0.0f, pyramidLength, cubeHeight)) {
                paused = true;
            }
	        glutPostRedisplay();
		}
        glutTimerFunc(16, update, 0); // 60 FPS
    }

    void display() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();


        gluLookAt(cameraX + 4.0f, 20.0f, 100.0f,
                cameraX, cubeY + cubeHeight / 2, 0.0f,
                0.0f, 1.0f, 0.0f);

        drawGround();
        

        float spacingX = pyramidLength;

        for (int j = 0; j < numCols; ++j) {
            float x = static_cast<float>(j) * spacingX - 50.0f;

            for (int i = 0; i < numRows; ++i) {
                if (matrix[i][j] == 1) {
                    drawPyramid(x, 0.0f, 0.0f, i);
                } else if (matrix[i][j] == 2) {
                    drawPlane(x, 0.0f, 0.0f, i);
                }
            }
        }
        // Desenha o cubo na mesma reta das pirâmides
        drawCube(cameraX, cubeY, 0.0f, pyramidLength, cubeHeight);
        
		float textVerticalOffset = 20.0f;
        glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white

	    // Set position for text (adjusted for camera movement)
	    glRasterPos2f(-15.0f + cameraX, 0.9f + textVerticalOffset);
	
	    // Display key information
	    for (size_t i = 0; i < keyInfo.length(); ++i) {
	        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, keyInfo[i]);
	    }
	
	    // Set position for FPS text (adjusted for camera movement)
	    glRasterPos2f(-25.0f + cameraX, 0.8f + textVerticalOffset);
	
	    // Display FPS information
	    for (size_t i = 0; i < fpsString.length(); ++i) {
	        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, fpsString[i]);
	    }

        glutSwapBuffers();
    }

    void reshape(int width, int height) {
        glViewport(0, 0, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0, (double)width / (double)height, 1.0, 200.0);
        glMatrixMode(GL_MODELVIEW);
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
        case ' ':
            if (!jumping && onGround) {
                jumping = true;
            }
            break;
        case 'h':
	        paused = !paused;
	        break;
        case 27:
            exit(0);
            break;
        }
    }

    void init() {
        glEnable(GL_DEPTH_TEST);
    }

    void runGame() {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutCreateWindow("Jogo de Pirâmides com Cubo");
        
        init_lighting(); // Inicialização de iluminação

        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutTimerFunc(0, update, 0);
        glutKeyboardFunc(keyboard);

        glutMainLoop();
    }

    int main(int argc, char** argv) {
        glutInit(&argc, argv);
        init();
        runGame();
        return 0;
    }