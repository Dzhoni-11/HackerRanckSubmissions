#include <string>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;
void Swap(string*, string*);
void SortStringVector(vector<string>&);
string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

int main()
{
    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    vector<string> op = {};
    for (int N_itr = 0; N_itr < N; N_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        string firstName = first_multiple_input[0];

        string emailID = first_multiple_input[1];

        if (emailID.find("@gmail.com") != string::npos)
        {
            op.push_back(firstName);
        }
    }

    SortStringVector(op);

    for (const auto& n : op)
    {
        cout << n << endl;
    }

    return 0;
}

void Swap(string* x, string* y)
{
    string dref_x = *x;
    string dref_y = *y;
    *x = dref_y;
    *y = dref_x;
}

void SortStringVector(vector<string>& v)
{
    for (auto& s : v)
    {
        int numberOfSwaps = 0;
        for (size_t j = 0; j < v.size() - 1; j++)
        {
            // Swap adjacent elements if they are in decreasing order
            auto first = v[j].c_str();
            auto last = v[j + 1].c_str();
            if (strcmp(first, last) > 0)
            {
                Swap(&v[j], &v[j + 1]);
                numberOfSwaps++;
            }
        }

        if (numberOfSwaps == 0) break;
    }
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
