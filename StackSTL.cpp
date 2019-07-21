#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<char> charStack;
    charStack.push('a');

    cout<<"stack top"<<charStack.top();
    return 0;
}