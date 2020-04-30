//1. + Represent generation state
//2. - Generate a random start position
//3. + Print the first generation
//4. Go through the board to build the next generation (Examine nine cells group and set state of the inner cell)
//5. Jump to the opposite side of console when the figure reaches the corner
//6. Optimaze not to check neighbourhood that didn't change
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define BOARD_SIZE_X 100
#define BOARD_SIZE_Y 50

void setWindowParams();
void initDefault2DArray(bool* cells, size_t x_size, size_t y_size);
void generateToadOscillators(bool cells[][BOARD_SIZE_X]);
void printGeneration(bool* cells, size_t x_size, size_t y_size);
void printSymbol(int x, int y, int symbol);
void calculateFollowingGeneration(bool* current_generation, bool* following_generation, size_t x_size, size_t y_size);

int main()
{
    setWindowParams();

    bool current_generation[BOARD_SIZE_Y][BOARD_SIZE_X];
    bool following_generation[BOARD_SIZE_Y][BOARD_SIZE_X];
    bool* current_generation_ptr = &current_generation;
    bool* following_generation_ptr = &following_generation;
    bool* temp_storage_ptr;

    initDefault2DArray(current_generation, BOARD_SIZE_X, BOARD_SIZE_Y);
    initDefault2DArray(following_generation, BOARD_SIZE_X, BOARD_SIZE_Y);

    generateToadOscillators(current_generation, BOARD_SIZE_Y);
    generateToadOscillators(following_generation, BOARD_SIZE_Y);

    while (true)
    {
        printGeneration(current_generation_ptr, BOARD_SIZE_X, BOARD_SIZE_Y);
        calculateFollowingGeneration(current_generation_ptr, following_generation_ptr, BOARD_SIZE_X, BOARD_SIZE_Y);

        temp_storage_ptr = current_generation_ptr;
        current_generation_ptr = following_generation_ptr;
        following_generation_ptr = temp_storage_ptr;
    }
}

void setWindowParams()
{
    SMALL_RECT window_size = { 0, 0, BOARD_SIZE_X, BOARD_SIZE_Y };
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(hOut, TRUE, &window_size);
}
    
void initDefault2DArray(bool* cells, size_t x_size, size_t y_size)
{
    for (size_t y = 0; y < y_size; y++)
    {
        for (size_t x = 0; x < x_size; x++)
        {
            *(cells + y * x_size + x) = false;
        }
    }
}

void generateToadOscillators(bool current_generation[][BOARD_SIZE_X])
{
    current_generation[25][51] = true;
    current_generation[25][52] = true;
    current_generation[25][53] = true;
    current_generation[26][50] = true;
    current_generation[26][51] = true;
    current_generation[26][52] = true;
}

void printGeneration(bool* current_generation, size_t x_size, size_t y_size)
{
    system("cls");
    for (size_t y = 0; y < y_size; y++)
    {
        for (size_t x = 0; x < x_size; x++)
        {
            if (*(current_generation + y * x_size + x))
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

void calculateFollowingGeneration(bool* current_generation, bool* following_generation, size_t x_size, size_t y_size)
{
    int number_of_live_cells;
    for (size_t y = 0; y < y_size; y++)
    {
        for (size_t x = 0; x < x_size; x++)
        {
            number_of_live_cells = 0;

            for (size_t i = 0; i < 3; i++)
            {
                for (size_t u = 0; u < 3; u++)
                {
                    if (*(current_generation + y * (x_size + i) + (x + u)) == true)
                    {
                        number_of_live_cells++;
                    }
                }
            }

            if (number_of_live_cells == 3)
            {
                *(following_generation + y * (x_size + 1) + (x + 1)) = true;
            }
            else if (number_of_live_cells != 4)
            {
                *(following_generation + y * (x_size + 1) + (x + 1)) = false;
            }
        }
    }
}
