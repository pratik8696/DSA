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
}

int pop(struct stack *st, int x)
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

int main()
{
    struct stack st;
    cout << "Enter the size of the Stack" << endl;
    cin >> st.size;
    st.top = -1;
    st.S = new int[st.size];
    st.S[st.size] = {1, 2, 3};

    return 0;
}