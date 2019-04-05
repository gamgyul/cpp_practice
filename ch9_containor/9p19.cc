#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <deque>
int
main(int argc, char **argv) {
    
    int input;
    std::list<int> ls;
    std::deque<int> odd, even;

    while (std::cin >> input) {
        ls.push_back(input);
    }

    for (auto i = ls.begin(); i != ls.end(); i++)
    {
        *i%2 == 0 ? even.push_back(*i) : odd.push_back(*i);
    }
    std::cout << "even member" <<std::endl;
    for (auto i =even.begin(); i !=even.end(); i++)
    {
        std::cout << *i << std::endl;
    }

    std::cout << "odd member" <<std::endl;
    for (auto i = odd.begin(); i != odd.end(); i++)
    {
        std::cout << *i << std::endl;
    }
    
    return 0;
}