#include "axton_component.h"

#include <cstring>
#include <algorithm>

AxtonComponent::AxtonComponent(int buffSize) : std::ostream(this), std::istream(this), internal_buffer_size(buffSize) {
    //Set pointers
    internal_buffer = new char[internal_buffer_size];
    setPointers();
}

void AxtonComponent::setPointers() {
    setp(internal_buffer, internal_buffer + internal_buffer_size); // set 3 write pointers
    setg(internal_buffer, internal_buffer, internal_buffer + internal_buffer_size); //set 3 read pointers
}

size_t AxtonComponent::bytes_written() {
    return pptr()-pbase(); // how many bytes were really written?
}

int AxtonComponent::overflow(int c)
{
    //Every byte that is sent here is a byte that overflows the internal_buffer
    return 0;
}

//AxtonCompontent normal methods
void AxtonComponent::subscribe(std::ostream *stream) {
    streams.push_back(stream);
}

void AxtonComponent::unsubscribe(std::ostream *stream) {
    auto position = std::find(streams.begin(), streams.end(), stream);
    if(position != streams.end())
        streams.erase(position);
}

void AxtonComponent::clear() {
    memset(internal_buffer, 0, internal_buffer_size);
    setPointers();
}

char* AxtonComponent::read() {
    size_t size = bytes_written();
    char* buff = new char[size];
    std::istream::read(buff, size);
    return buff;
}

void AxtonComponent::write(const char *data) {
    std::ostream::write(data, strlen(data));
}

void AxtonComponent::writeToAll(const char *data) {
    for (std::ostream* str : streams)
        str->write(data, strlen(data));
}