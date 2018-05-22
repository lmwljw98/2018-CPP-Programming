// MyString.h
#include <iostream>
using namespace std;

class MyString {
  private:
    char *memory;

  public:
    MyString();
    MyString(const char *str);
    MyString(MyString& s);
    ~MyString();

    int size() const;
    MyString& operator= (const MyString& s);

    MyString operator+ (const MyString& s);
    char& operator[](int i);
    friend ostream& operator<<(ostream& os, const MyString& s);
};
