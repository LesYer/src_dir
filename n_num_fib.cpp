#include <cstdio>
#include <vector>

using namespace std;
vector<short> *res;
vector<short>* add(vector<short>* a, vector<short>* b)
{
res = new vector<short>;
int rem = 0;
int add = 0;
int i = 0;
for(i = 0; i < a->size() && i < b->size(); i++){
add = a->at(i) + b->at(i) + rem;
rem = add/10;
res->push_back(add%10);
}
if(i == a->size()){
while(i < b->size()){
add = b->at(i) + rem;
rem = add/10;
res->push_back(add%10);
i++;
}
}
else if(i == b->size()){
while(i < a->size()){
add = a->at(i) + rem;
rem = add/10;
res->push_back(add%10);
i++;
}
}
while(rem != 0){
res->push_back(rem%10);
rem /= 10;
}
return res;
}
int main()
{
vector<short> *a = new vector<short>;
vector<short> *b = new vector<short>;
vector<short> *c = new vector<short>;
a->push_back(1);
b->push_back(1);
long long index = 2;
while(c->size() < 10000)
{
c = new vector<short>;
c = add(a, b);
a = b;
b = c;
index++;
}
printf("%lld\n", index);
return 0;
} 