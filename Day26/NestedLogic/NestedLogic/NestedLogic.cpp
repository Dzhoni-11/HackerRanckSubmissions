#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

// forward declarations

struct dt;

bool IsEqual(int, int);
bool IsGreater(int, int);
int GetDiffInDays(const dt*, const  dt*);
int GetDiffInMonths(const dt*, const dt*);
int GetDiffInYears(const dt*, const dt*);


// definitions

enum idx { DAY, MONTH, YEAR };

class dt
{
    public:
        int day; int month; int year;

    dt(int x, int  y, int z) : day(x), month(y), year(z) {}

    using TriBoolTup = tuple<bool, bool, bool>;

    TriBoolTup operator==(const dt& x)
    {
        bool d; bool m; bool y;
        (IsEqual(year,  x.year))    ? y = true : y = false;
        
        (IsEqual(month, x.month))   ? m = true : m = false;
        
        (IsEqual(day,   x.day))     ? d = true : d = false;

        return tie(d, m, y);
    }

    TriBoolTup operator>(dt& x)
    {
        bool d; bool m; bool y;
        (IsGreater(year,        x.year))    ? y = true : y = false;

        (GetDiffInMonths(this,  &x) > 0)    ? m = true : m = false;

        (GetDiffInDays(this,    &x) > 0)    ? d = true : d = false;

        return tie(d, m, y);
    }
};

bool IsEqual(int x, int y)
{
    return x == y;
}

bool IsGreater(int x, int y)
{
    return x > y;
}

int GetDiffInDays(const dt* x, const  dt* y)
{
    return x->day - y->day;
}

int GetDiffInMonths(const dt* x, const  dt* y)
{
    return x->month - y->month;
}

int GetDiffInYears(const dt* x, const  dt* y)
{
    return max(x->year, y->year) - min(x->year, y->year);
}


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int retDay, retMonth, retYear, dueDay, dueMonth, dueYear;
    cin >> retDay >> retMonth >> retYear;
    cin >> dueDay >> dueMonth >> dueYear;

    dt ret(retDay, retMonth, retYear);
    dt due(dueDay, dueMonth, dueYear);

    int fine = 0;
    auto d_e_r = (due == ret);
    auto d_g_r = (due > ret);
    auto r_g_d = (ret > due);

    if (get<DAY>(d_g_r) && get<MONTH>(d_g_r) && get<YEAR>(d_g_r))
    {
        fine = 0;
    }
    else if (get<DAY>(d_e_r) && get<MONTH>(d_e_r) && get<YEAR>(d_e_r))
    {
        fine = 0;
    }
    else if (get<DAY>(r_g_d) && get<MONTH>(d_e_r) && get<YEAR>(d_e_r))
    {
        fine = 15 * GetDiffInDays(&ret, &due);
    }
    else if (get<MONTH>(r_g_d) && get<YEAR>(d_e_r))
    {
        fine = 500 * GetDiffInMonths(&ret, &due);
    }
    else if (get<YEAR>(r_g_d))
    {
        fine = 10000;
    }

    cout << fine;

    return 0;
}
