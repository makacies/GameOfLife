//1. + Represent generation state
//2. - Generate a random start position
//3. Print the first generation
//4. Go through the board to build the next generation (Examine nine cells group and set state of the inner cell)
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define BOARD_SIZE_X 100
#define BOARD_SIZE_Y 50

void setWindowParams();
void init(bool* cells, size_t xSize, size_t ySize);
void generateToadOscillators(bool cells[][BOARD_SIZE_Y]);
void printGeneration(bool* cells, size_t xSize, size_t ySize);
void printSymbol(int x, int y, char symbol);
void calculateCellsState();

int main()
{
    setWindowParams();

    bool cells[BOARD_SIZE_X][BOARD_SIZE_Y];

    init (cells, BOARD_SIZE_X, BOARD_SIZE_Y);
    generateToadOscillators(cells, BOARD_SIZE_Y);
    printGeneration(cells, BOARD_SIZE_X, BOARD_SIZE_Y);
}

void setWindowParams()
{
    SMALL_RECT windowSize = { 0, 0, BOARD_SIZE_X, BOARD_SIZE_Y };
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(hOut, TRUE, &windowSize);
}

void init(bool* cells, size_t xSize, size_t ySize)
{
    for (size_t x = 0; x < xSize; x++)
    {
        for (size_t y = 0; y < ySize; y++)
        {
            *(cells + x * ySize + y) = false;
        }
    }
}

void generateToadOscillators(bool cells[][BOARD_SIZE_Y])
{
    cells[10][1] = true;

    /*cells[11][11] = true;
    cells[11][12] = true;
    cells[11][13] = true;
    cells[12][12] = true;
    cells[12][13] = true;
    cells[12][14] = true;*/
}

void printGeneration(bool* cells, size_t xSize, size_t ySize)
{
    for (size_t x = 0; x < xSize; x++)
    {
        for (size_t y = 0; y < ySize; y++)
        {
            if (*(cells + x * ySize + y))
            {
                printSymbol(x, y, 35);
            }
        }
    }
}

void printSymbol(int x, int y, int symbol)
{
    printf("\033[%d;%df", y, x);
    printf("%c", symbol);
}

void calculateCellsState(){}
