#include <string>
#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;

std::vector<std::string> string_vec(std::string &a_str);
int main()
{
    std::string test = "file";
    std::vector<std::string> s;
    s = string_vec(test);
    //stream_print(std::cin);

    return 0;
}

std::vector<std::string> string_vec(std::string &a_str)
{

    std::ifstream input(a_str);
    std::string str;
    std::vector<std::string> s_vec;

    if (input)
    {
        for(std::string s; std::getline(input,s);)
        {
            s_vec.push_back(s);
            std::cout << s <<std::endl;
        }    
    }
    return s_vec;
}
    
    