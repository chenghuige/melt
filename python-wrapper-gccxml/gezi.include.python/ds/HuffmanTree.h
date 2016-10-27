#ifndef GEZI_DS__HUFFMAN_TREE_H_
#define GEZI_DS__HUFFMAN_TREE_H_
#include "common_util.h"
namespace gezi {
class HuffmanTree
{
public:
HuffmanTree(const vector<int64>& freqs, int numBranchces = 2);
int NumBranches() const;
bool IsLeaf(int node) const;
int Root() const;
int NumLeaves() const;
size_t size() const;
const vector<int>& NodePaths(int node) const;
const vector<int>& BranchPaths(int node) const;
int Height() const;
protected:
private:
void Init();
int InterNodeIndex(int index) const;
void Build();
private:
int _numBranches;
int _numLeaves;
int _numInterNodes;
int _numNodes;
int _root;
int _height;
vector<int64> _weight;
ufo::Matrix<int> _childs;
vector<vector<int> > _nodePaths;
vector<vector<int> > _branchPaths;
};
}
#endif
