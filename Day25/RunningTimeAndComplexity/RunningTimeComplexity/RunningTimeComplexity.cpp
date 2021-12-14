#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */     int T;
    cin >> T;

    vector<int> Ts = {};
    for (int c = 0; c < T; c++)
    {
        int x = 0;
        cin >> x;
        Ts.push_back(x);
    }

    vector<string> op = {};
    for (auto& val : Ts)
    {
        bool not_prime = false;
        if (val > 1)
        {
            for (int j = sqrt(val); j != 1; --j)
            {
                auto x = val % j;
                if (x == 0)
                {
                    not_prime = true;
                    break;
                }
            }
        }

        if (not_prime || val == 1)
        {
            op.push_back("Not prime");
        }
        else
        {
            op.push_back("Prime");
        }
    }

    for (const auto& o : op)
    {
        cout << o << endl;
    }

    return 0;
}
