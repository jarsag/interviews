#include <iostream>

namespace DigitSum
{
    int calculate(int number)
    {
        int sum = 0U;
        while(number) 
        {
            sum += number % 10U;
            number /= 10U;
        }
        return sum;
    }
};

int main()
{
    int initX = 1000U;
    int initY = 1000U;
    int maxValue = initY;
    int count = 0U;

    //Определим область значений
    while((DigitSum::calculate(initX) + DigitSum::calculate(maxValue)) <= 25U)
    {
        ++maxValue;
    }

    maxValue = maxValue - 1U;

    int gridRows = maxValue;
    int gridCols = maxValue;

    //Создаем двумерный массив результатов вычисления
    int** grid = new int* [gridRows];

    for(int i = 0U; i < gridRows; ++i)
    {
        grid[i] = new int [gridCols];
    }
    //Заполняем нулями
    for(int x = 0U; x < gridCols; ++x)
    {
        for(int y = 0U; y < gridRows; ++y)
        {
            grid[x][y] = 0U;
        }
    }

    grid[0U][0U] = 1U;
    count = 1U;

    //Строим допустимые точки вдоль осей
    for(int j = 1U; j < gridRows; ++j)
    {
        int y = 1000U + j;
        if(((DigitSum::calculate(y) + 1U) <= 25U) && (grid[0U][j - 1U] > 0U))
        {
            grid[0U][j] = 1U;
            ++count;
        }
    }

    for(int i = 1U; i < gridCols; ++i)
    {
        int x = 1000U + i;
        if(((DigitSum::calculate(x) + 1U) <= 25U) && (grid[i - 1U][0U] > 0U))
        {
            grid[i][0U] = 1U;
            ++count;
        }
    }

    // Проверяем, есть ли доступ к остальным точкам плоскости
    for(int i = 1U; i < gridRows; ++i)
    {
        int y = 1000U + i;
        for(int j = 1U; j < gridCols; ++j)
        {
            int x = 1000U + j;
            if(((DigitSum::calculate(x) + DigitSum::calculate(y)) <= 25U) && ((grid[i - 1U][j] > 0U) || (grid[i][j - 1U] > 0U)))
            {
                grid[i][j] = 1U;
                ++count;
            }
        }
    }


    std::cout << "Муравью доступно " << count << " точек" << std::endl;


    return 1;
}
