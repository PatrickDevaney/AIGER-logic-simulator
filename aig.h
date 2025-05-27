#ifndef AIG_H
#define AIG_H

#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include "aignode.h"

typedef unordered_map<const unsigned, AigNode*, hash<unsigned>, eqNode> NodeMap;


class AigDef {

public:
  AigDef();
  ~AigDef();

  void noMin(void);

  // Accessor Methods
  AigNode* One(void) const;
  AigNode* Zero(void) const;

  AigNode* NewInputNode(unsigned index);
  AigNode* NewLatchNode(unsigned index);
  AigNode* NewAndNode(AigNode* left, bool lpol, AigNode* right, bool rpol, unsigned index);
  AigNode* NewAndNode(AigNode* left, bool lpol, AigNode* right, bool rpol);

  void clean(void);
  void recursive_erase(AigNode* node);
  void erase(AigNode* node);

  unsigned getIndex();
  static unsigned aigerIndex(unsigned lit);

  void sim(AigNode* function, unsigned cycles);
  void sim(AigNode* function, unsigned cycles, NodeMap &latches, NodeMap &inputs, ostream &out);
  void sim(AigNode* function, vector<AigNode*> &latches, vector<AigNode*> &inputs, vector<AigNode*> &latchLogic, string inputFile, string outputFile);
  bool recursiveSim(AigNode* function, valMap &terminalValues, vector<AigNode*> &traversedNodes);

private:
  NodeSet NodeTbl; 
  AigNode* Node0;
  AigNode* Node1;
  unsigned indexCount;

  void clear_flags(void);
  void clear_flags(vector<AigNode*> &vec);
};

#endif
