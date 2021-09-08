#include <iostream>
#include <vector>

#include "block/block.h"

using namespace std;

int main(int argc, char const* argv[])
{
    Block b;
    b.subscribe(&cout);
    b.subscribe(&cout);
    b.subscribe(&cout);

    b.writeToAll("Hello\n");

    b.write("generic test hello");
    b.write("hello there");

    //test unsub
    //b.unsubscribe(&cout);

    //b.writeToAll("Hello\n");

    return 0;
}
