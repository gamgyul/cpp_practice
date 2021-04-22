#include <iostream>
#include <cstring>

class MyString {
public:
    MyString(char c, int n);
    MyString(const char *s);
    MyString(const MyString &s);

    void add_string(const MyString &s);
    void copy_string(const MyString &s);
    void print() {std::cout << str << std::endl;}
    int strlen() const;
    int find(const MyString &s);
    bool is_same(const MyString &s);
private:
    int len;
    char *str;
};

MyString::MyString(char c, int n) {
    str = new char[(n )];
    len = n;
    memset(str, c, len);
    // *(str+n) = '\0'; 
}

MyString::MyString(const char *s) {
    int i = 0;
    char *tmp = NULL;
    tmp = const_cast<char *>(s);
    while(*tmp != '\0') {
        ++i;
        ++tmp;
    }
    len = i;
    str = new char[(len)];
    i = 0;
    tmp = const_cast<char *>(s);
    for(i = 0; i < len; ++i) {
    // while(*tmp != '\0') {
        str[i] =tmp[i];
    }
}

MyString::MyString(const MyString &s) {
    str = new char[s.len + 1];
    len = s.len;
    memcpy(str, s.str, s.len);
}

MyString::~MyString() {
    delete[] str;
}

void MyString::add_string(const MyString &s) {
    char * tmp = new char[len + s.len + 1];
    if(str != NULL) {
        memcpy(tmp, str, len);
        delete[] str;
    }
    memcpy(tmp + len, s.str, s.len);
    str = tmp;
    len = len + s.len;
}

void MyString::copy_string(const MyString &s) {
    if(str != NULL) 
        delete[] str;
    str = new char[s.len + 1];
    len = s.len;
    memcpy(str, s.str, s.len);
}
int MyString::find(const MyString &s) {
    int pos = 0;
    int idx = 0;
    int slen = s.len;
    char* sstr = s.str;
    for(pos = 0; pos < len-slen + 1; ) {
        while (str[pos] == sstr[idx]) {
            if (idx == slen - 1) {
                return (pos -idx);
            }
            pos++;
            idx++;
        }
        if(idx != 0) {
            idx = 0;
            continue;
        }
        pos++;
    }
    return -1;
}

bool MyString::is_same(const MyString &s) {
    int sslen = s.len;
    char *sstr = s.str;
    int pos = 0;
    while(str[pos] == sstr[pos]){
        pos++;
        if (pos >= len) return true;
    }
    return false;
}

int MyString::strlen() const{
    return len;
}


int main() {
    MyString S1("testest");
    MyString S2("test");
    MyString S3 = S2;
}