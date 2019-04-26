#include <iostream>
#include "music_collection.h"

using namespace std;

int main()
{
    Music_collection a;
    Tune test("test");
    Tune test2("a");
    Tune test3("b");
    Tune test4("c");
    Tune test5("c");
    a.add_tune(test);
    a.add_tune(test2);
    a.add_tune(test3);
    a.add_tune(test4);
    a.add_tune(test5);
    cout << a << endl;

    Music_collection b(a);
    Tune test6("aha");
    b.set_tune(2, test6);
    cout << b << endl;

    Music_collection c;
    c = b;
    Tune test7("reee");
    Tune test8("papapa");
    b.add_tune(test7);
    c.set_tune(1, test8);

    cout << c << endl;
    cout << b << endl;
    return 0;
}
