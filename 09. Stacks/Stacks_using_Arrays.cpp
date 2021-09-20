#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *S;
};

int Push(struct stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
    cout<<"Inserted Succesfully"<<endl;
}

int pop(struct stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(struct stack st, int pos)
{
    int index = st.top - pos + 1;
    if (index < 0)
    {
        cout << "Invalid Input" << endl;
    }
    else
    {
        return st.S[index];
    }
    return 0;
}

int stackTop(struct stack st)
{
    if (st.top == -1)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        return st.S[st.top];
    }
}

int isEmpty(struct stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack st)
{
    if (st.top == st.size - 1)
    {
        return 1;
    }
    return 0;
}

int DisplayStack(struct stack st)
{
    cout<<endl<<"The stack is = "<<endl;
    while(st.top!=-1)
    {
        cout<<st.S[st.top]<<" ";
        st.top--;
    }
}

int main()
{
    struct stack st;
    cout << "Enter the size of the Stack" << endl;
    cin >> st.size;
    st.top = -1;
    st.S = new int[st.size];
    Push(&st,10);
    Push(&st, 20);
    Push(&st, 30);
    Push(&st, 40);
    DisplayStack(st);
    pop(&st);
    DisplayStack(st);
    cout<<peek(st,2)<<endl;
    cout<<stackTop(st)<<endl;
    cout<<isFull(st)<<endl;
    cout<<isEmpty(st)<<endl;
    DisplayStack(st);
    return 0;
}