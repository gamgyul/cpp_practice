#include "screen.h"
void Screen::some_member() const
{
    ++access_ctr;
}

int main(){
    Screen myScreen(5, 5,'x');
    const Screen blank(5, 3);
    
    std::cout << "\n";
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    
}
