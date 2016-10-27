#ifndef LOAD_SAVE_H_
#define LOAD_SAVE_H_
#include <string>
#include <glog/logging.h>
namespace gezi {
#ifndef GCCXML
class LoadSave
{
public:
virtual void Save(std::string path);
virtual bool Load(std::string path);
virtual void CustomSave(std::string path);
virtual bool CustomLoad(std::string path);
virtual void SaveText(std::string file);
virtual bool LoadText(std::string file);
virtual void SaveXml(std::string file);
virtual bool LoadXml(std::string file);
virtual void SaveJson(std::string file);
virtual bool LoadJson(std::string file);
virtual std::string Name();
};
#endif
}
#endif
