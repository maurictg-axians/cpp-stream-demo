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

    b.write("Hello ");
    b.write("This ");
    b.write("Is ");
    b.write("Fun ");

    char* read = b.read();

    b.write("Hey");

    char* read2 = b.read();
    cout << "read: " << read << endl;
    cout << "read2: " << read2 << endl;

    b.writeToAll("Bye!\n");
    return 0;
}
