#include <iostream>
#include <string>
#include <cstring>
class Marine {
    static int total_marine_num;

public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, const char* name);
    Marine(int x, int y, int default_damage);
    Marine(std::string);

    ~Marine();

    int Attack() const;
    Marine &BeAttacked(int damage_taken);
    void Move(int x, int y);

    void show_status();
    static void show_total_marine();
private:
    
    int hp;
    int coord_x, coord_y;
    const int default_damage;
    bool is_dead;
    char *name_;
};
int Marine::total_marine_num =0;
void Marine::show_total_marine() {
    std::cout << "Total Count Marine: " << total_marine_num << std::endl;
}
Marine::Marine()
     : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false), name_(NULL) {
    total_marine_num++;
}

Marine::Marine(int x, int y) 
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false), name_(NULL) {
    total_marine_num++;
}

Marine::Marine(int x, int y, const char* name) : hp(50), coord_x(x), coord_y(y), default_damage(5), is_dead(false) { 
    total_marine_num++;
    name_ = new char[strlen(name)+1];
    strcpy(name_, name);
}
Marine::Marine(int x, int y, int default_damage) 
    : hp(50),
      coord_x(x),
      coord_y(y),
      default_damage(default_damage),
      is_dead(false),
      name_(NULL)
{total_marine_num++;}
Marine::Marine(std::string a) 
    :  default_damage(5),
     name_(NULL) {
    }
Marine::~Marine() {
    if(name_)
        std::cout << name_ << "의 소멸자 호출 ! " << std::endl;
    total_marine_num--;
    if(name_ != NULL)
        delete[] name_;
}

void Marine::Move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::Attack() const {return default_damage;}
Marine& Marine::BeAttacked(int damage_taken) {
    hp -= damage_taken;
    if( hp <= 0 ) is_dead = true;
    return *this;
}
void Marine::show_status() {
    if(name_)
        std::cout << "*** Marine : " << name_ << "***" << std::endl;
    std::cout << "Location : ( " << coord_x << " , " << coord_y << " ) "
              << std::endl;
    std::cout << "HP : " << hp << std::endl;
    std::cout << "total marine num : " << total_marine_num << std::endl;
}
void create_marine() {
  Marine marine3(10, 10, 4);
//   Marine marine3("a");
  marine3.show_status();

  std::cout << "##test##" << std::endl;

}
int main() {
    Marine *m[100];
    m[0] = new Marine(2,3,10);
    m[1] = new Marine(3,5,5);
    
    m[0]->show_status();
    m[1]->show_status();
    m[1]->BeAttacked(m[0]->Attack());
    create_marine();
  std::cout << "##testout##" << std::endl;

    m[0]->show_status();
    m[1]->show_status();

    delete m[0];
    delete m[1];
}