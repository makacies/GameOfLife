//1. Represent generation state
//2. Generate a random start position
//3. Print the first generation
//4. Go through the board to build the next generation (Examine nine cells group and set state of the inner cell)
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 100

void init(void);

int main()
{
    bool cell[BOARD_SIZE][BOARD_SIZE];
    init (cell, BOARD_SIZE, BOARD_SIZE);

    printf("Hello World!\n");
}

void init(bool* cell, size_t xSize, size_t ySize)
{
    for (size_t x = 0; x < xSize; x++)
    {
        for (size_t y = 0; y < ySize; y++)
        {
            *(cell + x * ySize + y) = false;
        }
    }
}
