#include <iostream>
using namespace std;

class Salary
{
    
    public:
        Salary(){}
        Salary(int salary)
        {
            m_salary=salary;
        }
        void showValue()
        {
            cout<<m_salary;
        }

    friend Salary operator+(const Salary& s1,const Salary& s2);
    private:
        int m_salary;
};

Salary operator+(const Salary& s1,const Salary& s2)
{
    Salary temp;
    temp.m_salary=s1.m_salary+s2.m_salary;
    return temp;
}

int main()
{
    Salary s1(20);
    Salary s2(10);
    Salary s3= s1+s2;
    s3.showValue();
    system("pause");
    return 0;
}