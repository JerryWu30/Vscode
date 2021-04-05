#include <iostream>

using namespace std;

class Mark
{
    public:
    Mark(int i,int j):m1(i),m2(j){}
    Mark(){m1=0,m2=0;}
    Mark operator+(Mark &mk)
    {
        Mark temp;
        temp.m1 = this->m1 + mk.m1;
        temp.m2 = this->m2 + mk.m2;
        return temp;
    }

    friend ostream &operator<<(ostream& out,Mark *mm)
    {
        out<<"m1="<<mm->m1<<endl;
        out<<"hhhhh"<<endl;
        return out;
    }

    void display()
    {
        cout<<this->m1<<endl;
        cout<<this->m2<<endl;
    }
    friend int getvalue(Mark &m);
    
    




    private:
    int m1;
    int m2;
};

int getvalue(Mark &m)
{
    return(m.m1+m.m2);
}

int main()
{
    Mark M1(12,12);
    Mark M2(21,33);
    Mark M3 = M1+M2;
    M3.display();
    Mark* M4 = &M3;
    cout<<M4;
    cout<<getvalue(M1);
    system("pause");
    return 0;
    
    
}