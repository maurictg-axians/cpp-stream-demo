#include <iostream>
#include <sys/socket.h>
#include <vector>
#include <cstring>

#include "block/block.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Block b;
    b.write("Hello world!\n");

    b.subscribe(&cout);
    b.subscribe(&cout);
    b.unsubscribe(&cout);

    b.write("Hey.\n");

    b.unsubscribe(&cout);
    b.write("Bye!\n");

    b.clear();
    b.write("hello");

    char* read = b.read();
    printf("read: \"%s\"\n", read);

    b.subscribe(&cout);

    return 0;
}
