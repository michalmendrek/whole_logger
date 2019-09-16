#include <log_module.h>
#include <utility>
#include <notification.h>

log_module::log_module(std::string Path, std::string ModuleName)
{
  crawler data(ModuleName,Path+'*');
  LinksToLog=data.GetLinks();
  for(auto it:LinksToLog) {  std::cout << it << std::endl;}
  Notify = new notify(Path);
  //std::cout << LinksToLog[1] << std::endl;
  Loger  = new log_loger(LinksToLog[1]);
}



log_module::~log_module()
{

}

