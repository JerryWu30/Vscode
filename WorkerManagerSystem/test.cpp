#include "Employee.h"
#include "Boss.h"
// #include "Manager.h"
// #include "Boss.h"



void test()
{
    Employee ep = Employee(1,"abcc",1);
    ep.show_info();
    Boss bs = Boss(1,"abc",3);
    bs.show_info();

}

int main()
{
    test();
    system ("pause");
    return 0;
}