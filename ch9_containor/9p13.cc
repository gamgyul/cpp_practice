#include <vector>
#include <iostream>
#include <list>
int
main(int argc, char **argv) {
    std::list<int> li = {3, 2, 1};
    auto a = li.begin();
    auto b = li.end();

    std::vector<double> vd(a, b);

    for ( auto i = vd.cbegin(); i != vd.cend(); i++)
        std::cout << *i << std::endl;
    return 0;
}