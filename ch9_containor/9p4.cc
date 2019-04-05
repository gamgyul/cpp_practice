#include <vector>
#include <iostream>
bool check_exist(std::vector<int>::const_iterator, std::vector<int>::const_iterator, int);
int main()
{
    std::vector<int> vi={1,2,3,4};
    int i=5;

    std::cout<< "check:" << check_exist(vi.cbegin(), vi.cend(), i) << false << std::endl;
    return 0;
}

bool check_exist(std::vector<int>::const_iterator a_begin, std::vector<int>::const_iterator a_end, int a_i)
{
    for(auto it = a_begin; it != a_end;++it)
    {
        if (*it==a_i)
            return true;
        
        
    }
    return false;
}