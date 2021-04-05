#include <iostream>
#include <ctime>


int main()
{
    // srand((unsigned int)time(NULL));
    int random = rand()%60;
    std::cout<<random;
    system("pause");
    return 0;

}