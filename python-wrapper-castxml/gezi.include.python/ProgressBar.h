#ifndef PROGRESS_BAR_H_
#define PROGRESS_BAR_H_
#include <string>
#include <iostream>
#include <iomanip>
#include <boost/progress.hpp>
#include <glog/logging.h>
#include "time_util.h"
using std::string;
namespace gezi {
class ProgressBar
{
public:
ProgressBar();
ProgressBar(string log_word);
ProgressBar(size_t total);
ProgressBar(string log_word, size_t total);
ProgressBar(size_t total, string log_word);
~ProgressBar();
void set_level(int level);
size_t counter() const;
void progress();
void progress(size_t current);
void progress(size_t current, size_t total);
void operator()(size_t current);
void operator++();
void operator+=(size_t step);
void operator()(size_t current, size_t total);
private:
int _level;
size_t _prev_progress;
size_t _current;
std::string _log_word;
std::string Bar;
std::string Space;
size_t Size;
size_t _total;
Timer _timer;
};
struct NoProgressBar
{
void operator()(size_t, size_t) const;
};
typedef NoProgressBar DefaultProgressBar;
}
#endif
