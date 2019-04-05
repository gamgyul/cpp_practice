#include <iostream>
#include <string>
#include <algorithm>
bool IsBigger(const std::string &s, std::string::size_type sz);

int main(int argc, char **argv) {
    std::vector<std::string> svec = {"fox", "red", "the", "over", "slow",
                                     "jumps", "quick", "turtle"};
    int num =0;
    std::string::size_type sz;
    

    std::cout << "Before partition" << std::endl;
    for(auto i = svec.cbegin();i != svec.cend(); i++,num++)
    {
        std::cout << "vector[" << num << "] : " << *i <<std::endl;
    }
    sz = 5;
    auto it = std::partition(svec.begin(), svec.end(),
                             bind(IsBigger, std::placeholders::_1, 4));
    // auto it = std::partition(svec.begin(), svec.end(),
    //                          [sz](const std::string& a){return a.size()>=sz;});
    
    std::cout << " after partition" <<std::endl;

    num = 0;
    for(auto i = svec.cbegin();i != it; i++,num++)
    {
        std::cout << "vector[" << num << "] : " << *i <<std::endl;
    }
} 


bool IsBigger(const std::string &s, std::string::size_type sz)
{
    return s.length() >= sz;
}