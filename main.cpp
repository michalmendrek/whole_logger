#include <log_module.h>
#include <iostream>

using namespace std;

void funkcja_testu(std::string data,std::string name) { std::cout << "ModName: " << name << "Data: " << data << std::endl; }

void funkcja_dwa(std::string data, std::string name) { std::cout << "Dwa" << std::endl;  std::cout << "ModName: " << name << "Data: " << data << std::endl;}

int main() {
  log_module plik("./");
  plik.AddModule("module1",funkcja_testu);
  plik.AddModule("module2",funkcja_dwa);

 std::cout << "Module1 " <<  plik.GetWholeLog("module1") << std::endl;
 std::cout << "Module2 " <<  plik.GetWholeLog("module2") << std::endl;
  while (1)
    ;
}
