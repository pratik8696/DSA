// CPP program to find two numbers with
// given Sum and XOR such that value of
// first number is minimum.
#include <iostream>
using namespace std;

// Function that takes in the sum and XOR
// of two numbers and generates the two
// numbers such that the value of X is
// minimized
void compute(unsigned long int S,
             unsigned long int X)
{
    unsigned long int A = (S - X) / 2;

    int a = 0, b = 0;

    // Traverse through all bits
    for (int i = 0; i < 8 * sizeof(S); i++)
    {
        unsigned long int Xi = (X & (1 << i));
        unsigned long int Ai = (A & (1 << i));
        if (Xi == 0 && Ai == 0)
        {
            // Let us leave bits as 0.
        }
        else if (Xi == 0 && Ai > 0)
        {
            a = ((1 << i) | a);
            b = ((1 << i) | b);
        }
        else if (Xi > 0 && Ai == 0)
        {
            a = ((1 << i) | a);

            // We leave i-th bit of b as 0.
        }
        else // (Xi == 1 && Ai == 1)
        {
            cout << "Not Possible";
            return;
        }
    }

    cout << "a = " << a << endl
         << "b = " << b;
}

// Driver function
int main()
{
    unsigned long int S = 4, X = 2;
    cin >> S >> X;
    compute(S, X);
    return 0;
}
