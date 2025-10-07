#include "ArrayStack.hpp"
#include <cstring>

using namespace std;

int main(){
    /*
    test cases:
    - [x] constructor
    - [x] clear
    - [x] copy
    - [x] peek
    - [x] pop
    - [x] push
    - [x] rotate
    */

    // const length var
    const int LEN = 5;

    // creating a new blank stack
    ArrayStack<int> full(LEN);

    try{
        cout << full.peek() << endl; // error should be thrown
    }    
    catch(const string& e){
        cout << e << endl;
    }

    full.push(1);
    cout << full.peek() << endl;
    full.push(2);
    cout << full.peek() << endl;
    full.push(3);
    cout << full.peek() << endl;
    full.push(4);
    cout << full.peek() << endl;
    full.push(5);
    cout << full.peek() << endl;


    ArrayStack<int> blank(full);

    cout << blank.peek() << endl; // should be 5
    
    blank.rotate(Stack<int>::RIGHT);
    cout << blank.peek() << endl; // should be 4
    blank.rotate(Stack<int>::LEFT);
    cout << blank.peek() << endl; // should be 5

    full.pop();
    cout << full.peek() << endl;

    full.clear();
    blank.clear();

    try{
        blank.peek();
    }
    catch(const string& e){
        cout << e << endl;
    }

    try{
        full.peek();
    }
    catch(const string& e){
        cout << e << endl;
    }
    return 0;
}