#include <iostream>
#include <string>
#include <cstring>
class Cannon {
public:
    Cannon();
    Cannon(int x, int y);
    Cannon(int x, int y, const char* name);
    Cannon(const Cannon &pc);
    ~Cannon();

    int Attack();
    void BeAttacked(int damage_taken);

    void show_status();
private:
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char *name_;
};

Cannon::Cannon() {
    hp = 50;
    coord_x = coord_y = 0;
    damage =5;
    is_dead = false;
    name_ = NULL;
}

Cannon::Cannon(int x, int y) {
    std::cout << "생성자 호출" << std::endl;
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage =5;
    is_dead = false;
    name_ = NULL;
}

Cannon::Cannon(int x, int y, const char* name) {
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage =5;
    is_dead = false;
    name_ = new char[strlen(name)+1];
    strcpy(name_, name);
}

Cannon::Cannon(const Cannon &name) {
    std::cout << "복사 생성자 호출" << std::endl;
    hp = 50;
    coord_x = name.coord_x;
    coord_y = name.coord_y;
    damage =5;
    is_dead = false;
    name_ = NULL;
}

Cannon::~Cannon() {
    std::cout << name_ << "의 소멸자 호출 ! " << std::endl;
    if(name_ != NULL)
    delete[] name_;
}

int Cannon::Attack() {return damage;}
void Cannon::BeAttacked(int damage_taken) {
    hp -= damage_taken;
    if( hp <= 0 ) is_dead = true;
}
void Cannon::show_status() {
    std::cout << "*** Cannon : " << name_ << "***" << std::endl;
    std::cout << "Location : ( " << coord_x << " , " << coord_y << " ) "
              << std::endl;
    std::cout << "HP : " << hp << std::endl;
}
int main() {
    Cannon pc1(1,1);
    Cannon pc2(pc1);
    Cannon pc3 = pc1;
    return 0;
}