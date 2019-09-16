#ifndef LOG_MODULE
#define LOG_MODULE

#include <unix_crawler.h>
#include <memory>
#include <notification.h>
#include <loger.h>

class log_module
{
  private:
          std::vector<std::string> LinksToLog;
	  //notify  *Notify;
  public:
  log_module(std::string Path, std::string ModuleName);
 ~log_module();
  notify    *Notify;
  log_loger *Loger;




};


#endif
