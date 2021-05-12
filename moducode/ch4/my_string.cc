#include <iostream>
#include <cstring>
#include <vector>
class MyString {
public:
    MyString(char c, int n);
    MyString(const char *s);
    MyString(const MyString &s);
    explicit MyString(int capacity);
    ~MyString();
    bool operator==(MyString & str);

    void add_string(const MyString &s);
    void copy_string(const MyString &s);
    void print() {std::cout << str << std::endl;}
    int strlen() const;
    int find(const MyString &s);
    bool is_same(const MyString &s);
    std::vector<int> getPi(const MyString &s);
private:
    int len;
    char *str;
    int capacity_;
};

MyString::MyString(int capacity) {
    str = new char[capacity];
    len = 0;
    capacity_ =  capacity;
}

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

bool MyString::operator==(MyString & s) {
    return strcmp(str, s.str) ? false: true;
};

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
// int MyString::find(const MyString &s) {
//     int pos = 0;
//     int idx = 0;
//     int slen = s.len;
//     char* sstr = s.str;
//     for(pos = 0; pos < len-slen + 1; ) {
//         while (str[pos] == sstr[idx]) {
//             if (idx == slen - 1) {
//                 return (pos -idx);
//             }
//             pos++;
//             idx++;
//         }
//         if(idx != 0) {
//             idx = 0;
//             continue;
//         }
//         pos++;
//     }
//     return -1;
// }

/* KMP 알고리즘으로 구현 */
std::vector<int> MyString::getPi(const MyString &s) {
    int size = s.strlen();
    int j = 0;
    std::vector<int> p(size);
    for(int i = 1; i < size; ++i) {
        while(j > 0 && s.str[i] != s.str[j]) {// while 체크를 하지 않는 조건 j=0이여서 처음부터 시작하거나
            j = p[j - 1];             // 새로 추가 되는 문자가 동일한 경우에는 바로 pi확인가능 
                                     // p[i] = suffix 끝문자  p[j] = prefix 끝문자
                                       // 문자가 동일하지 않으면 prefix 의 pi만큼 옮겨서 다시 비교 가능       
        }
        if(s.str[i] == s.str[j])
            j++;
        p[i] = j;
    }
    return p;
}

int MyString::find(const MyString &s) {
    int slen = s.len;
    
    int j = 0;
    std::vector<int> pi(slen);
    pi = getPi(s);
    for(int i = 0; i< len; ++i) {
        while (j > 0 && str[i] != s.str[j]) {
            j = pi[j - 1];
        }
        if (str[i] == s.str[j]) {
            
            if( j == slen - 1)
                return i - j + 1;
            ++j;
        }
        /* 여러개 일때 */
        // if(str[i] == s.str[j]) {
            
        //     if ( j == slen - 1) {
        //         ret_vec.push_back(i - j + 1);
        //         j = pi[j];
        //     }
        //     else
        //         ++j;
        // }

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
    std::cout << (S3 == S1) << std::endl;
}