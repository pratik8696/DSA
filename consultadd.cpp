#include <iostream>
using namespace std;

class Vikram
{
    int val;

public:
    static int x;
    Vikram()
    {
        val = x++;
        if (val == 4)
        {
            throw val;
        }
        cout << "BN GYA CONSTUCTOR " << val << endl;
    }
    ~Vikram()
    {
        val--;
        cout << "AA GYA DESTRUCTOR " << val << endl;
    }
};

int Vikram::x = 0;
/*
//1st call: val=0,x=1
// outpu 1:/bn gya constructor
//second call val=1,x=2
op: bn gya coinstructor
3rd call val=2,x=3
op bn gya constructor
4th call val=3 x =4
op bgc
5th call val=4,x=5
op: agd 4
agd agd3
agd2
agd 1
handling float exception
hadling float exception

op: Handle Partially 1
*/

int main()
{
    try
    {
        try
        {
            try
            {
                Vikram c[10];
                throw 20;
            }
            catch (int n)
            {
                cout << "Handle Partially 1" << endl;
                throw double(0.0); // Re-throwing an exception
            }
            catch (...)
            {
                cout << "DEFAULT EXCEPTION" << endl;
            }
        }
        catch (float x)
        {
            Vikram::x = 10;
            Vikram c[20];
            cout << "Handling float exception" << endl;
            throw;
        }
        catch (char x)
        {
            cout << "Handling char exception" << endl;
            throw;
        }
        catch (int n)
        {
            cout << "Handle Partially 2" << endl;
            throw 'x'; // Re-throwing an exception
        }
    }
    catch (int n)
    {
        cout << "Handle remaining 3" << endl;
    }
    catch (float x)
    {
        cout << "Handling float exception" << endl;
        throw;
    }
    catch (char x)
    {
        cout << "Handling char exception" << endl;
        throw;
    }
    return 0;
}
