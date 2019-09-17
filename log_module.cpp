#include <log_module.h>
#include <notification.h>
#include <utility>


std::string eraseSubStr(std::string mainStr,
                                const std::string &toErase) {
  // Search for the substring in string
  size_t pos = mainStr.find(toErase);

  if (pos != std::string::npos) {
    // If found then erase it from string
    mainStr.erase(pos, toErase.length());
  }
  return mainStr;
}






log_module::log_module(std::string Path) {

    PathToLogDir=Path;
    Notify = new notify(Path);
}

log_module::~log_module() {}


void log_module::AddModule(std::string ModuleName, std::function<void(std::string,std::string)> CallBack)
{

   crawler data(ModuleName, PathToLogDir + '*');
   LinksToLog = data.GetLinks();
   for (auto it : LinksToLog) {
    Loger.push_back(new log_loger(it));
    std::cout << "Plik: " << eraseSubStr(it, "./") << std::endl;
    Notify->AddFileName(eraseSubStr(it, "./"),CallBack);
  }
    Notify->AddLogerInstance(Loger);



}


std::string log_module::GetWholeLog(std::string ModuleName)
{
  std::string WholeLog;




return WholeLog;
}
