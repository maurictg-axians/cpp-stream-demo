#include "block.h"
#include <cstring>
#include <algorithm>

Block::Block() : internal_buffer(new char[BUFFER_SIZE]), buffer(internal_buffer, BUFFER_SIZE), out_stream(&buffer), in_stream(&buffer) {
    stream = &out_stream;
}

Block::~Block() {
}

void Block::clear() {
    memset(internal_buffer, 0, BUFFER_SIZE);
    buffer.set();
}

char* Block::read() {
    size_t size = buffer.written();
    char* buff = new char[size];
    in_stream.read(buff, size);
    return buff;
}

void Block::write(const char *data) {
    stream->write(data, strlen(data));

    //foreach to subscribers?? (after processing)
    //writeToAll(data); can also write to stream so..
}

void Block::subscribe(ostream* str) {
    this->streams.push_back(str);

    //Write history? (after processing)
    //str->write(internal_buffer, buffer.written());
}

void Block::unsubscribe(ostream *str) {
    auto position = std::find(streams.begin(), streams.end(), str);
    if(position != streams.end())
        streams.erase(position);
    //str->flush();
}

void Block::writeToAll(const char* data) {
    for (ostream* str : this->streams)
        str->write(data, strlen(data));
}