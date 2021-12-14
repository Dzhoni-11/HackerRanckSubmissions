#include <string>
#include <vector>
#include <functional>
#include <fstream>
#include <iostream>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'bitwiseAnd' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER K
 */

int bitwiseAnd(int N, int K)
{
    vector<int> myArray(N);
    int max = 0;

    for (int i = 0; i < N; i++) myArray.at(i) = i + 1;

    for (int f_pos = 0; f_pos != myArray.size() - 1; f_pos++)
    {
        for (int n_pos = f_pos + 1; n_pos != myArray.size(); n_pos++)
        {
            int tmpMax = myArray.at(f_pos) & myArray.at(n_pos);
            if ((tmpMax >= max) && (tmpMax < K)) { max = tmpMax; }
        }
    }
    return max;
}

int main()
{
    ifstream ifs("test.txt", ifstream::in);
    ifstream ofs("comp.txt", ifstream::in);
    string t_temp;
    getline(ifs, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));
    vector<int> op = {};
    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        if (t_itr == 128)
        {
            int x = 0;
        }
        string first_multiple_input_temp;
        getline(ifs, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int count = stoi(first_multiple_input[0]);

        int lim = stoi(first_multiple_input[1]);

        int res = bitwiseAnd(count, lim);

        string ss;
        getline(ofs, ss);
        int x = stoi(ltrim(rtrim(ss)));

    }
    ifs.close();

    //for (const auto& o : op)
    //{
    //    cout << o << endl;
    //}

    return 0;
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
