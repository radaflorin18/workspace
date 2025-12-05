//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int Add(int a, int b)
{
    return a + b;
}

int Substract(int a, int b)
{
    return a - b;
}

int Multiply(int a, int b)
{
    return a * b;
}

int Divide(int a, int b)
{
    return a / b;
}

int main()
{
    int select, a, b, result = 0;
    int ret; // will be initialized when calling scanf()
    int (*function_name[])(int, int) = { Add, Substract, Multiply, Divide };

    //Or you can do it explicitly like this
    //function_name[0] = &Add;
    //function_name[1] = &Substract;
    //function_name[2] = &Multiply;
    //function_name[3] = &Divide;

    printf("Select an operation: \n");
    printf("[1]: Add \n");
    printf("[2]: Substract \n");
    printf("[3]: Multiply \n");
    printf("[4]: Divide \n");

    //Some input validation
    do { ret = scanf_s("%u", &select); getchar(); } while (!(1 == ret)); //compare with the number of written parameters

    printf("Enter the two operands: a and b \n");

    //Some input validation
    do { ret = scanf_s("%d %d", &a, &b); getchar(); } while (!(2 == ret)); //compare with the number of written parameters

    switch (select)
    {
        //Be careful at operation mapping
    case 1: result = function_name[0](a, b); break;
    case 2: result = function_name[1](a, b); break;
    case 3: result = function_name[2](a, b); break;
    case 4:
        if (0 != b)
        {
            result = function_name[3](a, b);
        }
        else
        {
            printf("Denominator must be different than 0! \n");
        }
        break;
    default:
        printf("Please select a valid operation! \n");
        break;
    }

    printf("The result of operation is: %d \n", result);

    getchar();
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
