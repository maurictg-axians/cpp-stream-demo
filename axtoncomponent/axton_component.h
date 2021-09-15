#ifndef OWWSTREAM_AXTON_COMPONENT_H
#define OWWSTREAM_AXTON_COMPONENT_H

#include <streambuf>
#include <iostream>
#include <vector>

class AxtonComponent : private std::streambuf, private std::istream, public std::ostream {
public:
    AxtonComponent(int buffSize);
    void subscribe(std::ostream* stream);
    void unsubscribe(std::ostream* stream);
    void clear();
    char* read();
    void write(const char* data);
private:
    int overflow(int c) override;
    void setPointers();
    int internal_buffer_size;
    size_t bytes_written();
    char* internal_buffer;
    std::vector<std::ostream*> streams;
    void writeToAll(const char* data);
};


#endif //OWWSTREAM_AXTON_COMPONENT_H
