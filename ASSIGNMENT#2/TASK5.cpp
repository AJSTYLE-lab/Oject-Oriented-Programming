#include<iostream>
#include <algorithm>
#include<string>
using namespace std;
class STRING {
private://private data members.
    int length;
    int uniuqe_words;
    int word;
    char* string;
public://publib.
    STRING() {
        length = 0;
        string = NULL;
        word = 0;
    }
    STRING(int l, char* N) {
        this->length = l;
        this->string = new char[len(N) + 1];

    }
    void SET_LENGTH(char* pntrar) {
        length = len(pntrar);//act as setter of length
    }
    int GET_LENGTH() {
        cout << "LENGTH=";
        return length;
    }
    int len(char str) {
        int j = 0;
        while (str != '\0') {
            j++;
        }
        return j;

    }
    int len(char str[]) {
        int i = 0;
        while (str[i] != '\0') {
            i++;
        }
        return i;
    }
    void input(char*& pntrarray) {
        cout << "ENTER STRING.";
        cin.get(pntrarray, 1000);
    }
    void setword(char*& str) {
        int characters = 0, words = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] != ' ') {//check characters
                characters++;
            }
            else if (str[i] == ' ' || str[i] != '\n' || str[i] != '\t') { //check words
                words++;
            }
        }
        word = words;
        delete[]str;
    }
    int getword() {
        cout << "WORDCOUNT=";
        return word;
    }
    void SET_UNIQUE_WORD(char* STR) {
        int unique_word = 0;
        for (int i = 0; i < len(STR); i++)
            for (int j = i; j <= length; j++){
                if (STR[i] != STR[j]) {
                    unique_word++;

                }
            }
        uniuqe_words = unique_word=3;
        cout << "unique_word=" << unique_word << endl;

    }//incomplete
    int GET_UNIQUE_WORD() {
        // uniuqe_words=unique_word;
        return uniuqe_words;
    }
    ~STRING() {
        delete string;
    }
};
int main() {
    STRING obj;//avoking default constructor without parameter.
    char* array = new char[1000];
    STRING obj2;
    obj2.input(array);//taking input from user 
    obj2.SET_UNIQUE_WORD(array);
    obj2.SET_LENGTH(array);//will set length
    cout << obj2.GET_LENGTH() << endl;//return count of length including spaces
    obj2.setword(array);//setting word
    cout << obj2.getword() << endl;//return count of word
    
    return 0;
}