#include <iostream>
#include <sys/socket.h>
#include <vector>
#include <cstring>

#include "block/block.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Block b;
    b.subscribe(&cout);

    b.writeToAll("Hello\n");
    b.writeToAll("Hello\n");

    return 0;
}
