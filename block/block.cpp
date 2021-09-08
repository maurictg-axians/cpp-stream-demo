#include "block.h"
#include <cstring>

Block::Block() {
	buffer = (char*)malloc(sizeof(buffer));
	memset(buffer, 0, sizeof(buffer));
}

Block::~Block() {
}

void Block::subscribe(ostream* stream) {
	this->streams.push_back(stream);
}

void Block::unsubscribe(ostream* stream)
{
	for (int index = 0; index < streams.size(); index++)
	{
		if (stream == streams.at(index) && index != 0) {
			streams.erase(streams.begin() + (index - 1));
		}
	}
}

void Block::writeToAll(const char* data) {
	for (ostream* str : this->streams)
	{
		str->write(data, strlen(data));
	}
}

void Block::write(const char* data)
{
	int length = 1 + strlen(data) * sizeof(char);
	char* pBuf = new char[length]; // allocate memory
	memset(pBuf, 0, length);

	membuf sbuf(pBuf, length); // our buffer object
	std::ostream out(&sbuf);   // stream using our buffer

	out << data;
	out.flush();

	std::cout << "Nr of written bytes: " << sbuf.written() << std::endl;
	std::cout << "Content: " << (char*)pBuf << std::endl;

	int newSize = 1 + length + strlen(buffer);
	char* tempBuffer = new char[newSize];
	tempBuffer = (char*)malloc(newSize);
	memset(tempBuffer, 0, newSize);

	strcpy(tempBuffer, buffer); /* copy name into the new var */
	strcat(tempBuffer, pBuf);
	memset(buffer, 0, newSize);
	memcpy(buffer, tempBuffer, newSize);
	//buffer = tempBuffer;

	std::cout << buffer << std::endl;

	delete[] tempBuffer;
	delete[] pBuf; // free memory 
}


