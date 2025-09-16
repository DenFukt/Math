#include <iostream>

using namespace std;

bool operation(bool x, bool y, bool z)
{

    return (x == !(y && z) ) == (x == (y && z) );

}

int main() {


    for (int x = 0; x <= 1; ++x)
    {
        for (int y = 0; y <= 1; ++y)
        {
            for (int z = 0; z <= 1; ++z)
            {
                cout << "x=" << x << ", y=" << y << ", z=" << z << ":";
                cout << operation(x, y, z) << endl;
            }
        }
    }

    return 0;
}
