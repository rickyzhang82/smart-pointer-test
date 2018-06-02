#include <vector>
#include <map>
#include <iostream>
#include <memory>

using namespace std;
const int NUM_OBJ=3;
class A
{
public:
    A(int index): index(index) {cout<< "constructor of A with index: "<<index<< endl;};
    ~A(){cout<<"destructoro of A with index:"<<index<< endl;};
private:
    int index;
};

typedef shared_ptr<A> SP_A;

shared_ptr<vector<SP_A>> getVector()
{
    auto v = make_shared<vector<SP_A>>();
    cout<<"creating "<<NUM_OBJ<<" into vector"<<endl;
    for(int i = 0; i < NUM_OBJ; i++){
        auto element = make_shared<A>(i);
        v->push_back(element);
    }
    cout << "leaving getVector()"<<endl;
    return v;
}

shared_ptr<map<int, SP_A>> getMap()
{
    auto m = make_shared<map<int, SP_A>>();
    cout<<"creating "<<NUM_OBJ<<" into map"<<endl;
    for(int i = 0; i < NUM_OBJ; i++){
        auto element = make_shared<A>(i);
        m->insert(pair<int, SP_A>(i, element));
    }
    cout << "leaving getMap()"<<endl;
    return m;

}

void demoVector()
{
    cout<<"starting demo vector"<<endl;
    auto v = getVector();
    v->clear();
    cout << "finished demo vector" <<endl<<endl;
}

void demoMap()
{
    cout<<"starting demo map"<<endl;
    auto m = getMap();
    m->clear();
    cout << "finished demo map" <<endl<<endl;
}

int main( )
{
    demoVector();
    demoMap();
    cout<<"I'm done."<<endl;
    return 0;
}
