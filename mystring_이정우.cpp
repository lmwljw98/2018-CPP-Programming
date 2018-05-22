// 20171676 이정우
#include <iostream>

using namespace std;

class MyString{
public:
    char* memory;
    MyString(){
        memory = new char[1];
        memory[0] = '\0';
    }
    MyString& operator=(MyString& s){
        this->memory = new char[s.size()+1];
        int i = 0;
        while(s.memory[i] != '\0'){
            this->memory[i] = s.memory[i];
            i++;
        }
        this->memory[i] = '\0';
        return *this;
    }
    MyString(char str[]){
        int arg_size = 0;
        while(str[arg_size] != '\0')
            arg_size++;
        memory = new char[arg_size+1];
        int i = 0;
        while(str[i] != '\0'){
            memory[i] = str[i];
            i++;
        }
        memory[i] = '\0';
    }
    MyString(MyString& s){
        memory = new char[s.size()+1];
        int i = 0;
        while(s.memory[i] != '\0'){
            memory[i] = s.memory[i];
            i++;
        }
        memory[i] = '\0';
    }
    ~MyString(){
        delete[] memory;
    }
    int size(){
        int i = 0;
        while(memory[i] != '\0')
            i++;
        return i;
    }
    void cpy(char str[]){
        int arg_size = 0;
        while(str[arg_size] != '\0')
            arg_size++;
        delete[] memory;
        memory = new char[arg_size+1];
        int i = 0;
        while(str[i] != '\0'){
            memory[i] = str[i];
            i++;
        }
        memory[i] = '\0';
    }
    void cat(char str[]){
        int arg_size = 0;
        while(str[arg_size] != '\0')
            arg_size++;

        int i = size(); int j = 0; int a = 0;
        char* temp;
        temp = new char[i+1];
        while(memory[a] != '\0'){
            temp[a] = memory[a];
            a++;
        }
        temp[a] = '\0';
        delete[] memory;
        memory = new char[i + arg_size + 1];
        a = 0;
        while(temp[a] != '\0'){
            memory[a] = temp[a];
            a++;
        }
        while(str[j] != '\0'){
            memory[i] = str[j];
            j++; i++;
        }
        memory[i] = '\0';
        delete[] temp;
    }
    int cmp(char str[]){
        for(int i = 0; i < size() && str[i] != '\0'; i++){
            int m = memory[i];
            int s = str[i];
            if(m > s)
                return 1;
            else if(m < s)
                return -1;
            else
                return 0;
        }
    }
};

int main(){
    MyString a("test");
    int compare;

    MyString b(a);
    cout << b.memory << endl;
    cout << b.size() << endl;

    MyString c("asfdasfasfasf");
    MyString d;
    d = c;
    cout << d.memory << endl;

    cout << a.memory << endl;
    cout << a.size() << endl;
    a.cpy("first word");
    a.cat("+second word");
    cout << a.memory << endl;
    cout << a.size() << endl;
    compare = a.cmp("debugging");
    cout << compare << endl;
    cout << a.memory << endl;
    cout << b.memory << endl;
}
