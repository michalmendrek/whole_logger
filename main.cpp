#include <log_module.h>
#include <iostream>

using namespace std;

void funkcja_testu(std::string data) { std::cout << data << std::endl; }

void funkcja_dwa(std::string data) { std::cout << data << std::endl; }

int main() {
  log_module plik("./", "module1");
  plik.Notify->AddFileName("module1.err.log", funkcja_testu);
  plik.Notify->AddFileName("module1.out.log", funkcja_dwa);

  cout << plik.Loger[0]->GetFileName();
  plik.Loger[0]->ReadWholeLog();
  cout << plik.Loger[0]->ReadLog() << endl;
  cout << plik.Loger[0]->GetFileName();
  plik.Loger[1]->ReadWholeLog();
  cout << plik.Loger[1]->ReadLog() << endl;

  while (1)
    ;
}
