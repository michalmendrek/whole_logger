#include <log_module.h>
#include <iostream>

using namespace std;

void funkcja_testu(std::string data,std::string name) { std::cout << "ModName: " << name << "Data: " << data << std::endl; }

void funkcja_dwa(std::string data, std::string name) { std::cout << "Dwa" << std::endl;  std::cout << "ModName: " << name << "Data: " << data << std::endl; }

int main() {
  log_module plik("./");
  plik.AddModule("module1",funkcja_testu);
  plik.AddModule("module2",funkcja_dwa);

 std::cout << "Module1 " <<  plik.GetWholeLog("module1") << std::endl;

/*
  cout << plik.Loger[0]->GetFileName();
  plik.Loger[0]->ReadWholeLog();
  cout << plik.Loger[0]->ReadLog() << endl;
  cout << plik.Loger[0]->GetFileName();
  plik.Loger[1]->ReadWholeLog();
  cout << plik.Loger[1]->ReadLog() << endl;
*/
  while (1)
    ;
}
