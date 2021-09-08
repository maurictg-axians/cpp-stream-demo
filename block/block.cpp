#include "block.h"
#include <cstring>

Block::Block() : internal_buffer(new char[2048]), buffer(internal_buffer, 2048), out_stream(&buffer), in_stream(&buffer) {
    stream = &out_stream;
}

Block::~Block() {

}

char* Block::read() {
    size_t size = buffer.written();
    char* buff = new char[size];
    in_stream.read(buff, size);
    return buff;
}

void Block::write(const char *data) {
    stream->write(data, strlen(data));
}

void Block::subscribe(ostream* stream) {
    this->streams.push_back(stream);
}

void Block::writeToAll(const char* data) {
    for (ostream* str : this->streams)
        str->write(data, strlen(data));
}