#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "windows.h"
#include "dictionary.hpp"

void ChangeCase(std::map<long int, std::string>& digitMap, std::map<long int, std::string>& newDigitMap)
{
    digitMap = newDigitMap;
}

std::string sumProp(long long int nSum, std::string sGender, std::string sCase)
{
    std::map<long int, std::string> oneDigit;
    std::map<long int, std::string> twoDigits;
    std::map<long int, std::string> threeDigits;
    std::map<long int, std::string> digitNums;
    std::map<long int, std::string> thousand;
    std::map<long int, std::string> millions;
    std::map<long int, std::string> billions;
    std::map<long int, std::string> thousandDigit;
    std::map<long int, std::string> numGender;

    if (sCase == "И")
    {
        ChangeCase(oneDigit, oneDigitI);
        ChangeCase(twoDigits, twoDigitsI);
        ChangeCase(threeDigits, threeDigitsI);
        ChangeCase(digitNums, digitNumsI);
        ChangeCase(thousand, thousandI);
        ChangeCase(millions, millionsI);
        ChangeCase(billions, billionsI);
        ChangeCase(thousandDigit, thousandDigitI);
        ChangeCase(numGender, numGenderI);
    }
    else if (sCase == "Р")
    {
        ChangeCase(oneDigit, oneDigitR);
        ChangeCase(twoDigits, twoDigitsR);
        ChangeCase(threeDigits, threeDigitsR);
        ChangeCase(digitNums, digitNumsR);
        ChangeCase(thousand, thousandR);
        ChangeCase(millions, millionsR);
        ChangeCase(billions, billionsR);
        ChangeCase(thousandDigit, thousandDigitR);
        ChangeCase(numGender, numGenderR);

    }
    else if (sCase == "Д")
    {
        ChangeCase(oneDigit, oneDigitD);
        ChangeCase(twoDigits, twoDigitsD);
        ChangeCase(threeDigits, threeDigitsD);
        ChangeCase(digitNums, digitNumsD);
        ChangeCase(thousand, thousandD);
        ChangeCase(millions, millionsD);
        ChangeCase(billions, billionsD);
        ChangeCase(thousandDigit, thousandDigitD);
        ChangeCase(numGender, numGenderD);
    }
    else if (sCase == "В")
    {
        ChangeCase(oneDigit, oneDigitV);
        ChangeCase(twoDigits, twoDigitsV);
        ChangeCase(threeDigits, threeDigitsV);
        ChangeCase(digitNums, digitNumsV);
        ChangeCase(thousand, thousandV);
        ChangeCase(millions, millionsV);
        ChangeCase(billions, billionsV);
        ChangeCase(thousandDigit, thousandDigitV);
        ChangeCase(numGender, numGenderV);
    }
    else if (sCase == "Т")
    {
        ChangeCase(oneDigit, oneDigitT);
        ChangeCase(twoDigits, twoDigitsT);
        ChangeCase(threeDigits, threeDigitsT);
        ChangeCase(digitNums, digitNumsT);
        ChangeCase(thousand, thousandT);
        ChangeCase(millions, millionsT);
        ChangeCase(billions, billionsT);
        ChangeCase(thousandDigit, thousandDigitT);
        ChangeCase(numGender, numGenderT);
    }
    else if (sCase == "П")
    {
        ChangeCase(oneDigit, oneDigitP);
        ChangeCase(twoDigits, twoDigitsP);
        ChangeCase(threeDigits, threeDigitsP);
        ChangeCase(digitNums, digitNumsP);
        ChangeCase(thousand, thousandP);
        ChangeCase(millions, millionsP);
        ChangeCase(billions, billionsP);
        ChangeCase(thousandDigit, thousandDigitP);
        ChangeCase(numGender, numGenderP);
    }
    else
    {
        std::cout << "Нет такого падежа" << std::endl;
        std::cout << "Именительный падеж по умолчанию" << std::endl;
        ChangeCase(oneDigit, oneDigitI);
        ChangeCase(twoDigits, twoDigitsI);
        ChangeCase(threeDigits, threeDigitsI);
        ChangeCase(digitNums, digitNumsI);
        ChangeCase(thousand, thousandI);
        ChangeCase(millions, millionsI);
        ChangeCase(billions, billionsI);
        ChangeCase(thousandDigit, thousandDigitI);

    }

    std::vector<int> numberDigit;
    std::string result;

    int digitSize = 0U;
    if (nSum < 10U)
    {
        for (auto oneDigitIt = oneDigit.begin(); oneDigitIt != oneDigit.end(); ++oneDigitIt)
        {
            if (nSum == oneDigitIt->first)
            {
                result += oneDigitIt->second;
            }
        }
    }
    else
    {
        while (nSum)
        {
            int currentDigit = nSum % 10;
            nSum /= 10;
            ++digitSize;
            numberDigit.push_back(currentDigit);
        }
    }

    bool isTwoDigit = false;

    for (auto numberDigitIt = numberDigit.rbegin(); numberDigitIt != numberDigit.rend(); ++numberDigitIt)
    {
        if (*numberDigitIt)
        {
            if (digitSize == 12 || digitSize == 9 || digitSize == 6 || digitSize == 3)
            {
                for (auto threeDigitsIt = threeDigits.begin(); threeDigitsIt != threeDigits.end(); ++threeDigitsIt)
                {
                    if (*numberDigitIt == threeDigitsIt->first)
                    {
                        result += threeDigitsIt->second;
                        switch (digitSize)
                        {
                        case 6:
                            if (*(numberDigitIt + 1) == 0 && *(numberDigitIt + 2) == 0)
                            {
                                result += thousand[3];
                            }
                            break;
                        case 9:
                            if (*(numberDigitIt + 1) == 0 && *(numberDigitIt + 2) == 0)
                            {
                                result += millions[3];
                            }
                            break;
                        case 12:
                            if (*(numberDigitIt + 1) == 0 && *(numberDigitIt + 2) == 0)
                            {
                                result += billions[3];
                            }
                            break;
                        }
                        break;
                    }
                }
            }
            if (digitSize == 11 || digitSize == 8 || digitSize == 5 || digitSize == 2)
            {
                if (*numberDigitIt == 1U && *(numberDigitIt + 1) != 0)
                {
                    for (auto digitNumsIt = digitNums.begin(); digitNumsIt != digitNums.end(); ++digitNumsIt)
                    {
                        if (*(numberDigitIt + 1) == digitNumsIt->first)
                        {
                            result += digitNumsIt->second;
                            isTwoDigit = true;
                            break;
                        }
                    }
                }
                else
                {
                    for (auto twoDigitsIt = twoDigits.begin(); twoDigitsIt != twoDigits.end(); ++twoDigitsIt)
                    {
                        if (*numberDigitIt == twoDigitsIt->first)
                        {
                            result += twoDigitsIt->second;
                            break;
                        }
                    }
                }

                switch (digitSize)
                {
                case 5:
                    if ((*(numberDigitIt + 1) == 0) || isTwoDigit == true)
                    {
                        result += thousand[3];
                        break;
                    }
                    break;
                case 8:
                    if (*(numberDigitIt + 1) == 0 || isTwoDigit == true)
                    {
                        result += millions[3];
                        break;
                    }
                    break;
                case 11:
                    if (*(numberDigitIt + 1) == 0 || isTwoDigit == true)
                    {
                        result += billions[3];
                        break;
                    }
                    break;
                }
            }
            if (digitSize == 10 || digitSize == 7 || digitSize == 4)
            {
                if (!isTwoDigit)
                {
                    for (auto oneDigitIt = oneDigit.begin(); oneDigitIt != oneDigit.end(); ++oneDigitIt)
                    {
                        if (*numberDigitIt == oneDigitIt->first)
                        {
                            if (digitSize == 4)
                            {
                                switch (*numberDigitIt)
                                {
                                case 1:
                                    result += thousandDigit[1];
                                    break;
                                case 2:
                                    result += thousandDigit[2];
                                    break;
                                default:
                                    result += oneDigitIt->second;
                                    break;
                                }
                            }
                            else
                            {
                                result += oneDigitIt->second;
                                break;
                            }
                        }
                    }
                    switch (digitSize)
                    {
                    case 4:
                        if (*numberDigitIt)
                        {
                            if (*numberDigitIt == 1)
                            {
                                result += thousand[1];
                            }
                            else if (*numberDigitIt == 2 || *numberDigitIt == 3 || *numberDigitIt == 4)
                            {
                                result += thousand[2];
                            }
                            else
                            {
                                result += thousand[3];
                            }
                        }

                        break;
                    case 7:
                        if (*numberDigitIt)
                        {
                            if (*numberDigitIt == 1)
                            {
                                result += millions[1];
                            }
                            else if (*numberDigitIt == 2 || *numberDigitIt == 3 || *numberDigitIt == 4)
                            {
                                result += millions[2];
                            }
                            else
                            {
                                result += millions[3];
                            }
                        }
                        break;
                    case 10:
                        if (*numberDigitIt)
                        {
                            if (*numberDigitIt == 1)
                            {
                                result += billions[1];
                            }
                            else if (*numberDigitIt == 2 || *numberDigitIt == 3 || *numberDigitIt == 4)
                            {
                                result += billions[2];
                            }
                            else
                            {
                                result += billions[3];
                            }
                        }
                        break;
                    }
                }
                else
                {

                    isTwoDigit = false;
                }

            }

            if (digitSize == 1)
            {
                if (!isTwoDigit)
                {
                    for (auto oneDigitIt = oneDigit.begin(); oneDigitIt != oneDigit.end(); ++oneDigitIt)
                    {
                        if (*numberDigitIt == oneDigitIt->first)
                        {

                            if (*numberDigitIt == 1)
                            {
                                if (sGender == "М")
                                {
                                    result += numGender[1];
                                    break;
                                }
                                else if (sGender == "Ж")
                                {
                                    result += numGender[2];
                                    break;
                                }
                                else
                                {
                                    result += numGender[3];
                                    break;
                                }

                            }
                            else if (*numberDigitIt == 2)
                            {
                                if (sGender == "М")
                                {
                                    result += numGender[4];
                                    break;
                                }
                                else if (sGender == "Ж")
                                {
                                    result += numGender[5];
                                    break;
                                }
                                else
                                {
                                    result += numGender[6];
                                    break;
                                }
                            }
                            else
                            {
                                result += oneDigitIt->second;
                                break;
                            }
                        }
                    }
                }
                else
                {
                    isTwoDigit = false;
                }
            }
            --digitSize;
        }
        else
        {
            --digitSize;
        }
    }

    return result;
}

int main()
{
    
    long long int num;
    for (;;)
    {
        SetConsoleOutputCP(1251);
        std::cout << "Введите число от 1 до 999'999'999'999:" << std::endl;
        std::cin >> num;
        std::string test = sumProp(num, "М", "И");
        std::string test1 = sumProp(num, "М", "Р");
        std::string test2 = sumProp(num, "М", "Д");
        
        std::string test3 = sumProp(num, "М", "В");
        std::string test4 = sumProp(num, "М", "Т");
        std::string test5 = sumProp(num, "М", "П");

        std::cout << test << std::endl;
        std::cout << test1 << std::endl;
        std::cout << test2 << std::endl;
        std::cout << test3 << std::endl;
        std::cout << test4 << std::endl;
        std::cout << test5 << std::endl;
    }
    return 1;
}
