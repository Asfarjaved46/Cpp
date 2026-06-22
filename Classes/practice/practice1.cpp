#include<iostream>
using namespace std;

class X {
        int m;
        int mf(int);
    public:
        int f(int i) { m=i; return mf(i); }
};

int main(){
X x;
int y = x.f(2);

}

int X::mf(int)
{
    return 0;
}
