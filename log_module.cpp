#include <log_module.h>
#include <utility>
#include <notification.h>

log_module::log_module(std::string Path, std::string ModuleName)
{
  crawler data(ModuleName,Path+'*');
  LinksToLog=data.GetLinks();
  for(auto it:LinksToLog) {  std::cout << it << std::endl;}
  Notify = new notify(Path);
}



log_module::~log_module()
{

}

