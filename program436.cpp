#include<iostream>
using namespace std;
class Arithamtic
{
    private :
    int No1, No2;

    public :
    Arithamtic(int A,int B);

    int Addition();

    int Substraction();
    

};

Arithamtic :: Arithamtic(int A,int B)
{
    this->No1=A;
    this->No2=B;
}
int Arithamtic :: Addition()
{
    return No1 + No2;
}

    int Arithamtic :: Substraction()
{
    return No1 - No2;
}

int main()
{
    Arithamtic aobj(11,10);

    cout<<aobj.Addition()<<"\n";
    cout<<aobj.Substraction()<<"\n";

    return 0;
}