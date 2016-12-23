#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
    A(){cout << "constructor" << endl;};
    ~A(){cout << "destructor"  << endl;};
};

shared_ptr<vector<shared_ptr<A>>> getVector()
{
    auto v = make_shared<vector<shared_ptr<A>>>();
    for(int i = 0; i < 10; i++){
        auto element = make_shared<A>();
        v->push_back(element);
    }
    cout << "leave getVector()";
    return v;
}
int main( )
{
    auto v = getVector();
    v->clear();
    cout << "I am here" << endl;
}
