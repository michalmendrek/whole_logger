#include <iostream>
#include <log_module.h>

using namespace std;


void funkcja_testu(void)
{
std::cout << "dupa" << std::endl;

}

void funkcja_dwa(void)
{

std::cout << "dupa2" << std::endl;
}


int main()
{

log_module plik("./","module1");
plik.Notify->AddFileName("module1.err.log",funkcja_testu);
plik.Notify->AddFileName("module1.out.log",funkcja_dwa);
while(1);


}
