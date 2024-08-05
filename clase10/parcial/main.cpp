#include <iostream>

using namespace std;

int XXX(int n);

int main()
{
    cout << "1522, 645, 876." << endl;
    cout << XXX(1522) << endl;
    cout << XXX(645) << endl;
    cout << XXX(876) << endl;
    return 0;
}

int XXX(int n) {
    if(n < 10) return n;
    return n%10+XXX(n/10);
}
