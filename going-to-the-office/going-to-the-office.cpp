#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <sstream>
#include <limits>
#include <map>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int MAX = numeric_limits<int>::max();

// The node
class Node{

public:

Node()
{
visited = false;
w = MAX;
prev = NULL;
sp_iter=-1;
}

void init()
{
visited=false;
prev=NULL;
w=MAX;
heapIndex=-1;
}

bool visited;
// float w;
int w;
Node *prev;

int nodeNo;

// all the incoming or outgoing (since they are 2-way) edges
//map<Node *, float> inNodesMap;
map<Node *, int> inNodesMap;

// Nodes index in the heap
// to help in the decrease queue (dkq) Op
int heapIndex;

// we do it the first time the node is called
// for a shortest path method
int sp_iter;
};

// The edge
class Edge{
public:

string str(){
stringstream o;
o << p << "-" << q;
return o.str();
}

int p;
int q;
};

struct classcomp {
bool operator() (const Edge& lhs, const Edge& rhs) const
{
// return (lhs.p + lhs.q) < (rhs.p + rhs.q);
if(lhs.p < rhs.p)
return true;
else
{
if(lhs.p == rhs.p)
{
if(lhs.q < rhs.q)
return true;
}
return false;
}
}
};

class Path {

public:

Path()
{
w=0;
}

// node order from the back
vector<int> nodeOrder;
// distance of nodes corresponding to node order
//vector<float> distVec;
vector<int> distVec;

// key is nodeNo and value is position from the destination D
unordered_map<int, int> nodeMap;

//float w;
int w;

bool hasEdge(Edge & bp)
{
if(nodeMap.find(bp.p) == nodeMap.end())
return false;
if(nodeMap.find(bp.q) == nodeMap.end())
return false;

int ppos = nodeMap[bp.p];
int qpos = nodeMap[bp.q];

int diff = ppos - qpos;
// cout << “diff: ” << diff << endl;
if( diff == 1 || diff == -1)
return true;
else
return false;
}

void print()
{
unordered_map<int, int>::iterator it = nodeMap.begin();

cout << "nodes o: ";
while (it != nodeMap.end())
{
cout << it->first << ": " << it->second << "; ";
it++;
}

cout << endl << "nodes w: ";
for(int i=0; i< nodeOrder.size(); i++)
{
cout << nodeOrder[i] << ": " << distVec[i] << "; ";
}

cout << endl << "weight: " << w << endl << "——" << endl;
}
};

Path * createPathFromGivenNode(Node *n)
{
Path *p = new Path();
p->w = n->w;
// cout << “createPathFromGivenNode() weight: ” << p->w << endl;
Node *tempn = n;
int d=0;
while(tempn != NULL)
{
p->nodeMap[tempn->nodeNo] = d++;
p->nodeOrder.push_back(tempn->nodeNo);
p->distVec.push_back(p->w - tempn->w);

tempn = tempn->prev;
}
return p;
}

int N;

//unordered_map<string, float> bp_map;
unordered_map<string, int> bp_map;

map<int, Node *> mymap;

//float deleteEdge(Edge e)
int deleteEdge(Edge e)
{
//float w;
int w;
Node *n1 = mymap[e.p];
Node *n2 = mymap[e.q];

//map<Node *, float>::iterator it1 = n1->inNodesMap.find(n2);
map<Node *, int>::iterator it1 = n1->inNodesMap.find(n2);
if(it1 != n1->inNodesMap.end())
{
w = it1->second;
n1->inNodesMap.erase(it1);
}

it1 = n2->inNodesMap.find(n1);
if(it1 != n2->inNodesMap.end())
n2->inNodesMap.erase(it1);

// cout << “deleting edge ” << e.p << ” ” << e.q << endl;
return w;
}

// adds the edge from the network
//void addEdge(Edge e, float w)
void addEdge(Edge e, int w)
{
Node *n1 = mymap[e.p];
Node *n2 = mymap[e.q];

n1->inNodesMap[n2] = w;
n2->inNodesMap[n1] = w;

// cout << “adding edge ” << e.p << ” ” << e.q << ” w: ” << w << endl;
}

class MinHeap{
public:

MinHeap()
{
// num_deleted=0;
}

// NOT NEEDED AS IN POP WE START BY REPLACING THE ROOT NODE WITH LAST NODE
// we keep this as a counter of number of items deleted overall
// this + the heapIndex in the Node gives and accurate position
// of a Node in the vector at any given time
// int num_deleted;

vector<Node *> dataVec;

void push(Node *n)
{
// cout << “min heap push called ” << n->heapIndex << “/” << dataVec.size() << endl;
if(n->heapIndex == -1)
{
int i = dataVec.size();
n->heapIndex=i;
dataVec.push_back(n);
int c=i;
int p = floor( (c-1)/2);
while(p >=0)
{
if(dataVec[c]->w < dataVec[p]->w)
{
swap(c,p);
c=p;
p = floor( (c-1)/2);
}
else
break;
}
}
}

Node * pop()
{
// cout << “min heap pop called ” << dataVec.size() << endl;
int li = dataVec.size() -1;
if(li < 0)
return NULL;

// num_deleted++;
Node *root = dataVec[0];
root->heapIndex = -1;

dataVec[0] = dataVec[li];
dataVec[0]->heapIndex = 0;
li--;
vector<Node *>::iterator vit = dataVec.end();
vit--;
dataVec.erase(vit);
bool max=true;
int p=0;
do{
int minc = -1;
//float wc=-1;
int wc=-1;
int c1 = 2*p+1;
if(c1 <=li && dataVec[p]->w > dataVec[c1]->w)
{
minc = c1;
wc = dataVec[c1]->w;
}

int c2 = 2*p+2;
if(c2 <= li && dataVec[p]->w > dataVec[c2]->w)
{
if(wc == -1 || // Man not having this check, caused so many problems
dataVec[c2]->w < wc)
minc=c2;
}

if(minc > -1)
{
swap(p,minc);
p = minc;
}
else
max=false;

}while(max);

// cout << “heapIndex of 173906 after pop ” << mymap[173906]->heapIndex << endl;
return root;
}

// It will use the heap index stored in the node
// to do it efficiently
// update the heap with the new lower weight of this node
void update(Node *n)
{
// cout << “min heap update called ” << n->heapIndex << “/” << dataVec.size() << endl;
// this paper gives an excellent example
// http://www.policyalmanac.org/games/binaryHeaps.htm
int c = n->heapIndex;

// same as that of push
int p = floor( (c-1)/2);
while(p >=0)
{
if(dataVec[c]->w < dataVec[p]->w)
{
swap(c,p);
c=p;
p = floor( (c-1)/2);
}
else
break;
}
}

private:
void swap(int i, int j)
{
Node *t= dataVec[i];
dataVec[i] = dataVec[j]; dataVec[i]->heapIndex=i;
dataVec[j] = t; t->heapIndex=j;
}
};

MinHeap *mhq = NULL;

// initialize the priority queue
void init_pq(int s, int iterCount)
{
//if(pq != NULL)
// delete pq;
if(mhq != NULL)
{
delete mhq;
}

// pq = new priority_queue<Node *, vector<Node *>, pqcomp >();
// mpq = new map<int, unordered_set<Node *> >();
mhq = new MinHeap();

map<int, Node *>::iterator it = mymap.find(s);
if(it != mymap.end() )
{
Node * n= (*it).second;
n->sp_iter = iterCount;
n->init();
n->w = 0;
mhq->push(n);
}
}

Path * getShortestPath(int iterCount, int s, int d)
{
// cout << “Inside getShortestPath() ” << s << endl;

// initialize the priority queue
init_pq(s, iterCount);

// cout << “mhq->dataVec.size(): ” << mhq->dataVec.size() << endl;

while(mhq->dataVec.size() > 0)
{
Node *n = mhq->pop();

//if(iterCount > n->sp_iter)
//{
// n->sp_iter = iterCount;
// n->init();
//}
// cout << “got ” << n->nodeNo << ” with weight: ” << n->w << endl;

n->visited = true;
if(n->w >= MAX)
break;

if( n->nodeNo == d)
{
return createPathFromGivenNode(n);
}

//map<Node *, float> inNodesMap = n->inNodesMap;
//map<Node *, float>::iterator it = inNodesMap.begin();
map<Node *, int> inNodesMap = n->inNodesMap;
map<Node *, int>::iterator it = inNodesMap.begin();

while(it != inNodesMap.end() )
{
Node * tempn = (*it).first;
//float ww = (*it).second;
int ww = (*it).second;

if(iterCount > tempn->sp_iter)
{
tempn->sp_iter = iterCount;
tempn->init();
}

// cout << “tempn->nodeNo: ” << tempn->nodeNo << endl;
it++;

// if node is visited, ignore it
if(tempn->visited)
{
//cout << “after calling has node — continue” << endl;
continue;
}

// float w = n->w + ww ;
int w = n->w + ww ;

if(tempn->w > w)
{
tempn->w = w;
tempn->prev = n;

if(tempn->heapIndex == -1)
{
mhq->push(tempn);
// cout << “pushed ” << tempn->nodeNo << ” with weight: ” << tempn->w << “heapIndex: ” << tempn->heapIndex << endl;
}
else
{
mhq->update(tempn);
// cout << “updated ” << tempn->nodeNo << ” with weight: ” << tempn->w << “heapIndex: ” << tempn->heapIndex << endl;
}

}

} // while all edges of node

} // end while !pq.empty
// we could not find a single path to d
return NULL;
}

// We now use a priority queue for constraints
class Constraint{

public:
Constraint()
{
w=MAX;
n = -1;
}

//float w;
int w;
int n;
};

struct cqcomp {
bool operator() (Constraint & lhs, Constraint & rhs) const
{
return lhs.w > rhs.w;
}
};

priority_queue<Constraint, vector<Constraint>, cqcomp > cq;

//Path * getEdgeCutShortestPath(int iterCount, int s, int d, int cutEdgeEndNode, float prevPath, float constraint, Path *firstMinPath)
Path * getEdgeCutShortestPath(int iterCount, int s, int d, int cutEdgeEndNode, int prevPath, int constraint, Path *firstMinPath)
{
// cout << “Inside getEdgeCutShortestPath() s: ” << s << “, prevPath: ” << prevPath << “, constraint: ” << constraint << endl;

Constraint cons;
int cutEdgePos = firstMinPath->nodeMap[cutEdgeEndNode];

// initialize the priority queue
init_pq(s, iterCount);

// cout << “mhq->dataVec.size(): ” << mhq->dataVec.size() << endl;

while(mhq->dataVec.size() > 0)
{
Node *n = mhq->pop();

if(iterCount > n->sp_iter)
{
n->sp_iter = iterCount;
n->init();
}

n->visited = true;
if(n->w >= MAX)
break;

//float w2 = prevPath + n->w;
int w2 = prevPath + n->w;
// check if the current min path is already bigger
// than the contraint — encompassing shortest path
if(constraint < MAX && w2 > constraint)
{
Path *p = new Path();
p->w = constraint;
return p;
}

// check if any node in the path to D is there
// after the current start node
unordered_map<int, int>:: iterator it1 = firstMinPath->nodeMap.find(n->nodeNo);
if(it1 != firstMinPath->nodeMap.end())
{
int npos = it1->second;
if(npos <= cutEdgePos)
{
//float w3 = prevPath + n->w + firstMinPath->distVec[npos];
int w3 = prevPath + n->w + firstMinPath->distVec[npos];
//cout << “===>cutEdgePos: ” << cutEdgePos << endl;
//cout << “n->nodeNo: ” << n->nodeNo << “, npos: ” << npos << endl;
//cout << “n->w: ” << n->w << endl;
//cout << “firstMinPath->distVec[npos]: ” << firstMinPath->distVec[npos] << endl;
//cout << “w3: ” << w3 << endl;
//Path *tp = createPathFromGivenNode(n);
//tp->print();

// could be a local minima
if(w3 <= cons.w)
{
cons.w = w3;
cons.n = npos;
}

continue;
}
}

//map<Node *, float> inNodesMap = n->inNodesMap;
//map<Node *, float>::iterator it = inNodesMap.begin();
map<Node *, int> inNodesMap = n->inNodesMap;
map<Node *, int>::iterator it = inNodesMap.begin();

while(it != inNodesMap.end() )
{
Node * tempn = (*it).first;
//float ww = (*it).second;
int ww = (*it).second;

if(iterCount > tempn->sp_iter)
{
tempn->sp_iter = iterCount;
tempn->init();
}

it++;

// if node is visited, ignore it
if(tempn->visited)
{
//cout << “after calling has node — continue” << endl;
continue;
}

// cout << “n->nodeNo: ” << n->nodeNo << “; tempn->nodeNo: ” << tempn->nodeNo << endl;

//float w = n->w + ww ;
int w = n->w + ww ;
if(tempn->w > w)
{
tempn->w = w;
tempn->prev = n;

if(tempn->heapIndex == -1)
mhq->push(tempn);
else
mhq->update(tempn);

}

} // while all edges of node

} // end while !pq.empty
if(cons.w < MAX)
{
// first push the new constrain (max path) for further iterations
// cout << “pushing constraint w: ” << cons.w << “, pos : ” << cons.n << endl;
cq.push(cons);

// return this path
Path *p = new Path();
p->w = cons.w;
return p;
}
else
{
// we could not find a single path to d
return NULL;
}
}

unordered_map<string, Edge> bp_vec_map;

//void populateProcMap(Path * p, unordered_map<string, float> & proc_map,
// unordered_map<string, float> & bp_map, vector<string> & bp_vec)
void populateProcMap(Path * p, unordered_map<string, int> & proc_map,
unordered_map<string, int> & bp_map, vector<string> & bp_vec)
{
// cout << “populateProcMap, bp_map.size(): ” << bp_map.size() << endl;
//unordered_map<string, float>::iterator bp_it = bp_map.begin();
unordered_map<string, int>::iterator bp_it = bp_map.begin();
while(bp_it != bp_map.end())
{
string bpstr = bp_it->first;
Edge bp = bp_vec_map[bpstr];

if(!p->hasEdge(bp) )
{
// cout << “putting w = ” << p->w << ” for ” << bp.p << ” ” << bp.q << endl;
proc_map[bpstr]=p->w;
//bp_map.erase(bp_it++);
bp_it = bp_map.erase(bp_it);
}
else
{
// cout << “ignoring ” ” for ” << bp.p << ” ” << bp.q << endl;
bp_it++;
}
}

}

int
main(int c, char **v)
{
//cout << “try hello” << endl;
vector<string> bp_vec;

int M = -1;
int S = -1;
int D = -1;
int Q = -1;
// read the input
string line;
int ln=0;
while ( cin)
{
getline (cin,line);
// cout << “line: ” << line << endl;
char * tok;
tok = strtok((char *)line.c_str(), " ");
int tn=0;
int u=-1,v=-1;
//float w=-1;
int w=-1;
int p=-1,q=-1;
while(tok != NULL)
{
// cout << tok << “-“;
if(ln == 0)
{
if(tn==0)
N = atoi(tok);
else
M = atoi(tok);
}
else if(ln > 0 && ln <=M)
{
// edges
if(tn==0)
u = atoi(tok);
else if(tn == 1)
v = atoi(tok);
else
w = atof(tok);
}
else if( ln == M+1)
{
if(tn==0)
S = atoi(tok);
else
D = atoi(tok);
}
else if( ln == M+2)
{
Q = atoi(tok);
}
else if( ln > M+2 && ln <=M+2+Q)
{
if(tn==0)
p = atoi(tok);
else
q = atoi(tok);
}

tok = strtok(NULL, " ");
tn++;
}

if(ln > 0 && ln <=M)
{
Node *nu = NULL;
Node *nv = NULL;
if(mymap.find(u) == mymap.end())
{
nu = new Node();
mymap[u] = nu;
}
else
nu = mymap[u];

if(mymap.find(v) == mymap.end())
{
nv = new Node();
mymap[v] = nv;
}
else
nv = mymap[v];

nu->nodeNo = u;
nu->inNodesMap[nv] = w;

nv->nodeNo = v;
nv->inNodesMap[nu] = w;
}
else if( ln > M+2 && ln <=M+2+Q)
{
Edge bp;
bp.p = p;
bp.q = q;
string bpstr = bp.str();
bp_vec.push_back(bpstr);
bp_vec_map[bpstr] = bp;
bp_map[bpstr] = MAX;
}

// cout << endl;
ln++;
}

/***
// Printng the test values
map<int, Node *>::iterator it = mymap.begin();
while(it != mymap.end())
{
int i= (*it).first;
Node * n= (*it).second;
cout << “i: ” << i << ” — ” << n->nodeNo << ” — ” << n->inNodesMap.size() << ” ==== ” ;

//map<Node *, float>::iterator it2 = n->inNodesMap.begin();
map<Node *, int>::iterator it2 = n->inNodesMap.begin();
while(it2 != n->inNodesMap.end())
{
Node * tempn = (*it2).first;
//float ww = (*it2).second;
int ww = (*it2).second;
cout << tempn-> nodeNo << ” : ” << ww << ” ; “;
it2++;
}
cout << endl;

it++;
}

cout << “S: ” << S << ” D: ” << D << ” Q: ” << Q << endl;
***/

// cout << “read the file” << endl;
int iterCount=0;
Path *p = getShortestPath(iterCount, S, D);

/**
if( p == NULL)
cout << “Infinity” << endl;
else
{
cout << “shortest path weight: ” << p->w << endl;
p->print();
}
**/
// exit(-2);

//unordered_map<string, float> proc_map;
unordered_map<string, int> proc_map;
if(p != NULL)
{
populateProcMap(p, proc_map, bp_map, bp_vec);

// the edges inside the shortest path
// have to be checked in the bp_map
int cur_s = S;
//float prevDist = 0;
int prevDist = 0;
for(int i= p->nodeOrder.size()-1; i>0; i--)
{
//float cons_dist= MAX;
int cons_dist= MAX;

while(!cq.empty())
{
Constraint cons = cq.top();
// cout << “top constraint is w: ” << cons.w << “, pos : ” << cons.n << endl;
if( i-1 >= cons.n)
{
cons_dist = cons.w;
break;
}
else
cq.pop();
}

Edge e1; e1.p = p->nodeOrder[i]; e1.q = p->nodeOrder[i-1];
//float deletedW = deleteEdge(e1);
int deletedW = deleteEdge(e1);

// cout << “doing it for edge: ” << e1.p << ” ” << e1.q << endl;

iterCount++;
// Path *p1 = getEdgeCutShortestPath(iterCount, cur_s, D, e1.q, prevDist, cons_dist, p);
Path *p1 = getEdgeCutShortestPath(iterCount, cur_s, D, e1.q, prevDist, MAX, p);
if(p1 != NULL)
{
addEdge(e1, deletedW);
//cout <<“——-Path for edge: ” << e1.p << ” ” << e1.q << endl;
//p1->print();
// exit(-3);
}
else
{
// we got infinity weight so have to advance cur_s
// to save on traversal time
if(i > 0)
{
cur_s = p->nodeOrder[i-1];
prevDist = p->w - p->distVec[i-1];
}
//cout << “we got infinity weight so have to advance cur_s” << cur_s << endl;
}

//unordered_map<string, float>::iterator bp_it = bp_map.find(e1.str());
unordered_map<string, int>::iterator bp_it = bp_map.find(e1.str());
if(bp_it != bp_map.end())
{
string bpstr = bp_it->first;
if(p1 != NULL)
{
proc_map[bpstr] = p1->w;
}
bp_map.erase(bp_it);
}

// Fix for edges occuring
// both ways e.g. 0 5 and 5 0
Edge e2; e2.p = e1.q; e2.q = e1.p;
bp_it = bp_map.find(e2.str());
if(bp_it != bp_map.end())
{
string bpstr = bp_it->first;
if(p1 != NULL)
{
proc_map[bpstr] = p1->w;
}
bp_map.erase(bp_it);
}
} // end for
} // end if

// cout << “print the results” << endl;
// now print out all the results
for(int k=0; k< bp_vec.size(); k++)
{
string bpstr = bp_vec[k];
//float minDist = MAX;
int minDist = MAX;
if(proc_map.find(bpstr) != proc_map.end())
minDist = proc_map[bpstr];

if(minDist < MAX)
//cout << bpstr << “: ” << minDist << endl;
cout << minDist << endl;
else
//cout << bpstr << “: ” << “Infinity” << endl;
cout << "Infinity" << endl;
} // end for (k)

}

