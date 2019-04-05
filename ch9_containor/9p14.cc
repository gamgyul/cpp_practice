#include <vector>
#include <iostream>
#include <string>
#include <list>
int
main(int argc, char **argv) {
    std::list<char*> li = {"aa", "bb", "cc"};
    auto a = li.begin();
    auto b = li.end();

    std::vector<std::string> vs(2,"ttt");
    vs.assign(li.cbegin(), li.cend());
    


    for ( auto i = vs.cbegin(); i != vs.cend(); i++)
        std::cout << *i << std::endl;
    return 0;
}