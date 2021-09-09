#ifndef _Block_h_
#define _Block_h_

//include only in header if needed in parameters
#include <iostream> //so this is not best practice, but i dont care for now
#include <vector>
#include <streambuf>

using namespace std;

const int BUFFER_SIZE = 256;

struct membuf : std::streambuf // derive because std::streambuf constructor is protected
{
    char* pointer;
    size_t size;

   membuf(char* p, size_t size) 
   {
       this->pointer = p;
       this->size = size;
       set();
   }

   size_t written() {
       return pptr()-pbase(); // how many bytes were really written?
   }

   void set() {
       setp(pointer, pointer + size); // set 3 write pointers
       setg(pointer, pointer, pointer + size); //set 3 read pointers
   }
};

class Block {

private:
    vector<ostream*> streams;
    char* internal_buffer;
    membuf buffer;
    ostream out_stream;
    istream in_stream;

    void writeToAll(const char* data);

public:
    Block();
    ~Block();
    void subscribe(ostream* stream);
    void unsubscribe(ostream* stream);
    void clear();
    char* read();
    void write(const char* data);
    ostream* stream;
};

#endif //!_Block_h_