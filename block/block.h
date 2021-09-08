#ifndef _Block_h_
#define _Server_h

//include only in header if needed in parameters
#include <iostream> //so this is not best practice, but i dont care for now
#include <vector>
#include <streambuf>

using namespace std;

class Block {

private:
    vector<ostream*> streams;

public:
    Block();
    ~Block();
    void subscribe(ostream* stream);
    void writeToAll(const char* data);
    //ostream* stream;
};

#endif //!_Block_h_