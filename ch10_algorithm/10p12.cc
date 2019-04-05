#include <iostream>
#include <string>
#include <algorithm>
bool IsBigger(const std::string&);

int main(int argc, char **argv) {
    std::vector<std::string> svec = {"fox", "red", "the", "over", "slow",
                                     "jumps", "quick", "turtle"};
    int num =0;


    std::cout << "Before partition" << std::endl;
    for(auto i = svec.cbegin();i != svec.cend(); i++,num++)
    {
        std::cout << "vector[" << num << "] : " << *i <<std::endl;
    }

    auto it = std::partition(svec.begin(), svec.end(), IsBigger);
    num = 0;
    for(auto i = svec.cbegin();i != it; i++,num++)
    {
        std::cout << "vector[" << num << "] : " << *i <<std::endl;
    }
}


bool IsBigger(const std::string &s) {
    return s.length() >= 5;
}