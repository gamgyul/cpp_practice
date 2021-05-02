#include <iostream>
//#include <string>
#include <cstring>

class string {
public:
    string(char c, int n);
    string(const char *s);
    string(const string &s);
    ~string();

    void add_string(const string &s);
    void copy_string(const string &s);
    void print() {std::cout << str << std::endl;}
    int strlen();
    int find(const string &s);
    bool is_same(const string &s);
private:
    char *str;
    int len;
};

string::string(char c, int n) {
    str = new char[(n +1)];
    len = n;
    memset(str, c, len);
    *(str+n) = '\0'; 
}

string::string(const char *s) {
    int i = 0;
    char *tmp = NULL;
    tmp = const_cast<char *>(s);
    while(*tmp != '\0') {
        ++i;
        ++tmp;
    }
    len = i;
    str = new char[(len+1)];
    i = 0;
    tmp = const_cast<char *>(s);
    while(*tmp != '\0') {
        str[i] =*tmp;
        ++i;
        ++tmp;
    }
}

string::string(const string &s) {
    str = new char[s.len + 1];
    len = s.len;
    memcpy(str, s.str, s.len);

}

string::~string() {
    delete[] str;
}

void string::add_string(const string &s) {
    char * tmp = new char[len + s.len + 1];
    if(str != NULL) {
        memcpy(tmp, str, len);
        delete[] str;
    }
    memcpy(tmp + len, s.str, s.len);
    str = tmp;
    len = len + s.len;
}

void string::copy_string(const string &s) {
    if(str != NULL) 
        delete[] str;
    str = new char[s.len + 1];
    len = s.len;
    memcpy(str, s.str, s.len);
}
int string::find(const string &s) {
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

bool string::is_same(const string &s) {
    int sslen = s.len;
    char *sstr = s.str;
    int pos = 0;
    while(str[pos] == sstr[pos]){
        pos++;
        if (pos >= len) return true;
    }
    return false;
}

int string::strlen() {
    return len;
}
int main() 
{
    string S1("testest");
    string S2("test");
    string S3 = S2;

    S1.print();
    S2.print();
    S3.print();
    std::cout << S1.strlen() << S2.strlen() << S3.strlen() << std::endl;
    std::cout <<"find: " << S1.find(S2) <<std::endl;
    std::cout <<"is_same : " << S1.is_same(S2) << " s2s3 : " << S2.is_same(S3) << std::endl;
    return 0;

}