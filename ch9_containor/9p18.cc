#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <deque>
int
main(int argc, char **argv) {
    
    std::string input;
    std::deque<std::string> ds;
    while (std::cin >> input && input != "q"){
        ds.push_back(input);
    }
    for (auto i = ds.begin(); i!=ds.end();i++)
    {
        std::cout << *i << std::endl;
    }
    
    return 0;
}