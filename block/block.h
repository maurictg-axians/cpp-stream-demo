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
       setp( p, p + size); // set start end end pointers
       setg(p, p, p + size); //?
   }
   size_t written() {return pptr()-pbase();} // how many bytes were really written?
};

class Block {

private:
    vector<ostream*> streams;
    char* internal_buffer;
    membuf buffer;
    ostream out_stream;
    istream in_stream;

public:
    Block();
    ~Block();
    void subscribe(ostream* stream);
    void writeToAll(const char* data);
    char* read();
    void write(const char* data);
    ostream* stream;
};

#endif //!_Block_h_