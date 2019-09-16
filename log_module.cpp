#include <log_module.h>
#include <notification.h>
#include <utility>

log_module::log_module(std::string Path, std::string ModuleName) {
  crawler data(ModuleName, Path + '*');
  LinksToLog = data.GetLinks();
  // for(auto it:LinksToLog) {  std::cout << it << std::endl;}
  Notify = new notify(Path);
  for (auto it : LinksToLog) {
    Loger.push_back(new log_loger(it));
  }
  Notify->AddLogerInstance(Loger);
}

log_module::~log_module() {}
