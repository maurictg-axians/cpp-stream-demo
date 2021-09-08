#include "block.h"
#include <cstring>

Block::Block() {
}

Block::~Block() {
    //delete this->stream;
}

void Block::subscribe(ostream* stream) {
    this->streams.push_back(stream);
}

void Block::writeToAll(const char* data) {
    for (ostream* str : this->streams)
    {
        str->write(data, strlen(data));
    }
}