#include <iostream>
#include <list>
using namespace std;

bool myCompare(double fi, double se) {
    return ((fi) > (se));
}

int main() {
    list<double> fi, se;
    fi.push_back(3.1);
    fi.push_back(2.2);
    fi.push_back(2.9);

    se.push_back(3.7);
    se.push_back(7.1);
    se.push_back(1.4);
    se.push_back(2.1);

    fi.merge(se, myCompare);

    cout << "fi list contains: \n";
    for(list<double>::iterator it = fi.begin(); it != fi.end(); it++)
        cout << *it << " ";

    return 0;
}
// Dxy