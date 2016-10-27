#ifndef _SCORE_H_
#define _SCORE_H_
class Score
{
public:
Score();
void addItem(double item);
int getItemNum();
double itemAtIndex(int n);
//inline double& operator[](int index);
inline double value(int index = 0);
public:
virtual ~Score();
private:
double *_items;
int _nitem;
int _size;
};
#endif
