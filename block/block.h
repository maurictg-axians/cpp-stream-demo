#ifndef _Block_h_
#define _Server_h

//include only in header if needed in parameters
#include <iostream> //so this is not best practice, but i dont care for now
#include <vector>
#include <streambuf>

using namespace std;

struct membuf : std::streambuf // derive because std::streambuf constructor is protected
{
    membuf(char* p, size_t size)
    {
        setp(p, p + size); // set start end end pointers
    }
    size_t written() { return pptr() - pbase(); } // how many bytes were really written?
};

class Block {

private:
    vector<ostream*> streams;
    char* buffer;

public:
    Block();
    ~Block();
    void subscribe(ostream* stream);
    void unsubscribe(ostream* stream);
    void writeToAll(const char* data);
    void write(const char* data);
};

#endif //!_Block_h_