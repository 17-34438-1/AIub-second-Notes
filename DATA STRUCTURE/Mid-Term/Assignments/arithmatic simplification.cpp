#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int size = 1;
char *arr = new char[size];
int top = -1;
int val[100];
int pos=0;

void resize()
{
	char *newarr = new char[size * 2];
	for(int i = 0; i <= top; i++)
	{
		newarr[i] = arr[i];
	}
	size = size * 2;
	delete [] arr;
	arr = newarr;
}

void push(int value)
{
	if(top < size - 1)
	{
		top++;
		arr[top] = value;
	}
	else
	{
		resize();
		top++;
		arr[top] = value;
	}
}

void pop()
{
	if(top <= -1)
	{
		cout << "cannot pop, stack empty" << endl;
	}
	else
	{
		top--;
	}
}

void calculate(char c)
{
    if(c=='*')
        {val[pos-2]= val[pos-2]*val[pos-1];  --pos;}
    else if(c=='/')
        {val[pos-2]= val[pos-2]/val[pos-1];--pos;}
    else if(c=='^')
        {val[pos-2] = pow(val[pos-2],val[pos-1]); --pos;}
    else if(c=='%')
        {val[pos-2]= val[pos-2]%val[pos-1] ; --pos;}
    else if(c=='+')
        {val[pos-2]= val[pos-2]+val[pos-1] ; --pos;}
    else if(c=='-')
        {val[pos-2]= val[pos-2]-val[pos-1] ;--pos;}
}
bool startbrace(char c)
{
    if(c == '(' || c == '{' || c == '[')
        return true;
    return false;
}
bool isoperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '^'|| C == '%')
		return true;

	return false;
}
int o_weight(char oprt)
{
    int weight=-1;
    switch(oprt) {
    case '+' :
    case '-' :
    {
        weight = 1 ;
        break;
    }
    case '*' :
    case '/' :
    {
        weight = 2 ;
        break;
    }
    case '%':
    {
        weight = 3 ;
        break;
    }
    case '^':
    {
        weight = 4 ;
        break;
    }
    }
    return weight;
}
bool endbrace(char c)
{
    if(c == ')' || c == '}' || c == ']')
        return true;
    return false;
}
int main()
{
    string s;
    cin>>s;
    int i=0;
    for(i=0; i<s.size(); i++)
    {
        if(startbrace(s[i]))
        {
            push(s[i]);
        }
        else if( isoperator(s[i]) )
        {
            while(true)
            {
                if(o_weight(arr[top]) >= o_weight(s[i]))
                {
                    calculate(arr[top]);
                    pop();
                }
                else
                {
                    push(s[i]);
                    break;
                }
            }
        }
        else if(endbrace(s[i]))
        {
            if(s[i]==']' )
            {
                while(arr[top]!='[')
                {
                    calculate(arr[top]); pop();
                }
                if(arr[top]=='[')
                    pop();
            }
            else if(s[i]=='}' )
            {
                while(arr[top]!='{')
                {
                    calculate(arr[top]); pop();
                }
                if(arr[top]=='{')
                    pop();
            }
            else if(s[i]==')' )
            {
                while(arr[top]!='(')
                {
                    calculate(arr[top]); pop();
                }
                if(arr[top]=='(')
                    pop();
            }
            else if(s[i]==']' || s[i]=='}' || s[i]==')' && top==-1)
            {
                break;
            }
            else if(arr[top]='[' || arr[top]=='{' || arr[top]=='(' && s[i]=='\0')
            {
                break;
            }
            else
            {
                break;
            }
        }
        else
        {
            val[pos] = s[i] - 48;
            pos++;
            if(s[i+1]=='\0')
            {
                while(top!= -1)
                {
                    calculate(arr[top]); pop();
                }
            }
        }

    }
    if(top != -1)
    {
        while(top!=-1) {
            calculate(arr[top]);
            top--;
        }
    }
    cout<<val[0]<<endl;
    cout<<endl;
    if(i==s.size())
    {
        cout<<"string is right"<<endl;;
    }
    else
    {
        cout<<"String is wrong";
    }
	return 0;
}
