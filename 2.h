#include "LinkStack.h"

using namespace std;


#ifndef 2_H_INCLUDED
#define 2_H_INCLUDED

class Calculator
{
private:
    static int num1(char theta1);
    static int num2(char theta2);
    static bool IsO(char ch);
    static char Precede(char theta1,char theta2);
    static double Operate(double left,char ch,double right);
    static void Get2Operands(LinkStack<double>&opnd,double &left,double &right);

public:
    Calculator(){};
    virtual ~Calculator(){};
    static void Run();
};

static int Calculator::num1(char theta1)
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

static int Calculator::num2(char theta2)
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

static bool Calculator::IsO(char ch)
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

static char Calculator::Precede(char theta1,char theta2)
{
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

static double Calculator::Operate(double left,char ch,double right)
{
    if(ch=='+')  return (left+right);
    else if(ch=='-') return (left-right);
    else if(ch=='*') return (left*right);
    else if(ch=='/') return (left/right);
    else if(ch=='%') return (left%right);
    else if(ch=='^') return (left^right);
}

static void Calculator::Get2Operands(LinkStack<double> &opnd,double &left;double &right)
{
    opnd.Pop(left);
    opnd.Pop(right);
}

static void Calculator::Run()
{
    Stack<double> opnd;
    Stack<char> optr;
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
            cin>>opetand;
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

#endif // 2_H_INCLUDED
