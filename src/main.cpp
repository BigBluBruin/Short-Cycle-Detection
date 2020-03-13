#include "cycle_detection.h"

int main()
{
    std::vector<std::vector<int>> matrix =
        {
            {1, 0, 0, 0, 0},
            {1, 0, 0, 0, 1},
            {0, 1, 1, 0, 1},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 1, 1, 1, 1},
        };
    bool result = Cycle_Detection(matrix, 0, 4, 6);
    return 0;
}
