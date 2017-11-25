#include <iostream>
#include "LinkStack.h"
#include <math.h>

using namespace std;

class Calculator
{
public:
    int num1(char ch);
    int num2(char ch);
    bool IsO(char ch);
    char Precede(char theta1,char theta2);
    double Operate(double left,char ch,double right);
    void Get2Operands(LinkStack<double>&opnd,double &left,double &right);
    Calculator(){};
    virtual ~Calculator(){};
    void Run();
};

int Calculator::num1(char ch)
{
    if(ch=='+'){
        return (int)3;
    }
    else if(ch=='-'){
        return (int)3;
    }
    else if(ch=='*'){
        return (int)5;
    }
    else if(ch=='/'){
        return (int)5;
    }
    else if(ch=='%'){
        return (int)5;
    }
    else if(ch=='&'){
        return (int)7;
    }
    else if(ch=='^'){
        return (int)7;
    }
    else if(ch=='('){
        return (int)1;
    }
    else if(ch==')'){
        return (int)8;
    }
    else if(ch=='='){
        return (int)0;
    }
}

int Calculator::num2(char ch)
{
    if(ch=='+')
    {
        return (int)2;
    }
    else if(ch=='-')
    {
        return (int)2;
    }
    else if(ch=='*')
    {
        return (int)4;
    }
    else if(ch=='/')
    {
        return (int)4;
    }
    else if(ch=='%')
    {
        return (int)4;
    }
    else if(ch=='&')
    {
        return (int)6;
    }
    else if(ch=='^')
    {
        return (int)6;
    }
    else if(ch=='(')
    {
        return (int)8;
    }
    else if(ch==')')
    {
        return (int)1;
    }
    else if(ch=='=')
    {
        return (int)0;
    }
}

bool Calculator::IsO(char ch)
{
    if(ch=='='||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='^'||ch=='&'||ch=='('||ch==')'||ch=='+')
    {
        return true;
    }
    else
    {
        return false;
    }
}

char Calculator::Precede(char theta1,char theta2)
{
    int n1,n2;
    n1 = num1(theta1);
    n2 = num2(theta2);
    if(n1==1&&n2==0)
        return 'e';
    else if(n1==8&&n2==8)
        return 'e';
    else if(n1==0&&n2==1)
        return 'e';
    else if(n1>n2)
        return '>';
    else if(n1==n2)
        return '=';
    else if(n1<n2)
        return '<';
}

double Calculator::Operate(double left,char ch,double right)
{
    if(ch=='+')  return (left+right);
    else if(ch=='-') return (left-right);
    else if(ch=='*') return (left*right);
    else if(ch=='/') return (left/right);
    else if(ch=='%') return (int(left)%int(right));
    else if(ch=='^') return (pow(left,right));
}

void Calculator::Get2Operands(LinkStack<double> &opnd,double &left,double &right)
{
    opnd.Pop(left);
    opnd.Pop(right);
}

void Calculator::Run()
{
    LinkStack<double> opnd;
    LinkStack<char> optr;
    optr.Push('=');
    char ch;
    char optrTop;
    double operand;
    char theta;

    cin>>ch;
    while((optr.Top(optrTop),optrTop!='=')||ch!='=')
    {
        if(!IsO(ch))
        {
            cin.putback(ch);
            cin>>operand;
            opnd.Push(operand);
            cin>>ch;
        }
        else if(ch=='-'&&(optr.Top(optrTop),optrTop!=NULL))
        {
            cin>>operand;
            operand = 0-operand;
            opnd.Push(operand);
            cin>>ch;
        }
        else
        {
            switch(Precede(optrTop,ch))
            {
            case '<':
                optr.Push(ch);
                cin>>ch;
                break;
            case '=':
                optr.Pop(optrTop);
                cin>>ch;
                break;
            case '>':
                double left,right;
                Get2Operands(opnd,left,right);
                optr.Pop(theta);
                opnd.Push(Operate(left,theta,right));
                break;
            case 'e':
                cout<<"操作数匹配错"<<endl;
                exit(2);
            }
        }
    }

    opnd.Top(operand);
    cout<<"表达式的值为："<<operand<<endl;

}

main()
{
    char command;
    while(1)
    {
        cout<<"请输入表达式："<<endl;
        Calculator A;
        A.Run();
        cout<<"是否继续？若不愿意继续请输入n"<<endl;
        cin>>command;
        if(command=='n')
            break;
    }
}
