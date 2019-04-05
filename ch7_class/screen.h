#include <iostream>
#include <string>
#include <vector>
class Screen;
class Window_mgr{
    public:
    using screen_index = std::vector<Screen>::size_type;

    void clear(screen_index);
    screen_index addScreen(const Screen&);
    Window_mgr();
    private:
    std::vector<Screen> screens;
};

class Screen {
    friend void Window_mgr::clear(screen_index);
public: 
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos a_ht, pos a_wd, char a_c): height(a_ht), width(a_wd), contents(a_ht * a_wd, a_c){}
    Screen(pos a_ht, pos a_wd): height(a_ht), width(a_wd), contents(a_ht * a_wd, ' '){}
    
    char get() const {return contents[cursor]; }
    inline char get(pos a_r, pos a_c) const;
    Screen &move(pos a_r, pos a_c);
    Screen &set(char);
    Screen &set(pos a_r, pos a_c, char);
    Screen &display(std::ostream &os);
    const Screen &display(std::ostream &os) const;
    void some_member() const;

private:
    pos cursor = 0;
    pos height = 0, width = 0 ;
    std::string contents;
    mutable size_t access_ctr;
    void do_display(std::ostream &os) const {os << contents;}
};
inline
Screen &Screen::move(pos a_r, pos a_c){
    pos row = a_r * width;
    cursor = row + a_c;
    return *this;
}
inline
Screen &Screen::set(char a_ch)
{
    contents[cursor] = a_ch;
    return *this;
}
inline
Screen &Screen::set(pos a_r, pos a_c, char a_ch)
{
    pos tmp_cursor = a_r * width + a_c;
    contents[tmp_cursor] = a_ch;
    return *this;
}
inline
Screen &Screen::display(std::ostream &os) {
    do_display(os); return *this;
}
inline
const Screen &Screen::display(std::ostream &os) const{
    do_display(os); return *this;
}
char Screen::get(pos a_r, pos a_c) const{
    pos row = a_r * width;
    return contents[row+a_c];
}

Window_mgr::Window_mgr():screens{Screen(24,80)}{}
Window_mgr::screen_index
Window_mgr::addScreen(const Screen& a_s){
    screens.push_back(a_s);
    return screens.size() - 1;    
}
void Window_mgr::clear(screen_index a_i){
    screens[a_i].contents = std::string(screens[a_i].height * screens[a_i].width,' '); 

}
