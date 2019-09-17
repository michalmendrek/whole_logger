#ifndef LOG_MODULE
#define LOG_MODULE

#include <loger.h>
#include <notification.h>
#include <unix_crawler.h>
#include <memory>

class log_module {
 private:
  std::vector<std::string> LinksToLog;
  // std::vector<log_loger *> Loger;
 public:
  log_module(std::string Path, std::string ModuleName);
  ~log_module();
  notify *Notify;
  // log_loger *Loger;
  std::vector<log_loger *> Loger;
};

#endif
