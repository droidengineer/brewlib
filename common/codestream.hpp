#ifndef _BREW_LIB_CODESTREAM_H_
#define _BREW_LIB_CODESTREAM_H_

#include <string>
#include <fstream>
#include "brew.hpp"

#define DEFAULT_SEGMENT_SIZE 65535

class CodeStream : public OutStream
{
public:
	CodeStream(string & fn) : OutStream(fn) { }
	CodeStream(string &fn, brew::stream::mode m) : OutStream(fn,m) { }

};

#define DEFAULT_SEGMENT_MAX_SIZE 65535
#define DEFAULT_SEGMENT_SIZE	4192

// outputs to a binary byte stream file
// this is not an executable binary, say, in BROWNIE or elf-avr format.
class ByteCodeStream : public CodeStream
{
	struct Segment {
		enum class Type { Text, Data, ConstPool, StringTable, Exec, TypeID, SymbolTable,
			MethodID, MemberID, 
			blah
		};

		Segment()
			: type(Type::blah), pos(0), org(0), size(0)
		{
			seg = new uint8_t[DEFAULT_SEGMENT_SIZE];

		}
		Segment(Type t) 
			: type(t), seg(0), pos(0), org(0), size(0) 
		{ 
			seg = new uint8_t[DEFAULT_SEGMENT_SIZE];
		}
		Segment(Type t, uint16_t sz) : type(t), size(sz), seg(new uint8_t [sz]), pos(0), org(0) { }
		~Segment() { delete [] seg; }

		void setLabel(string & s) { label = s; }

		void	emitString(char * s) {
			while (*++s)
		{
			if (*s == '\'')
				{
					if (*(s+1) == '\'')
						emit8(*s++);
				}
				else
				{
					emit8(*s);
				}
			}
		}
		void	emit8(uint8_t b) {
			*(seg + pos) = b;
			++pos;
		}
		void	emit16(uint16_t w) {
			emit8((uint8_t)((w >> 8) & 0x00ff));
			emit8((uint8_t)(w & 0x00ff));
		}
		void	emit32(uint32_t i) {
			emit16((uint16_t)((i >> 16) & 0x0000ffff));
			emit16((uint16_t)(i & 0x0000ffff));

		}

		uint8_t * seg;
		uint16_t	pos;
		uint16_t	org;
		Type		type;
		uint16_t	size;
		string		label;
	};
public:
	ByteCodeStream(string & fn) 
		: CodeStream(fn,brew::stream::mode m) 
	{ currSegment = &textSegment; }

	~ByteCodeStream() { if (seg) delete [] seg; }
	
	void	emitString(char * s) {
		currSegment->emitString(s);
	}
	void	emit8(uint8_t b) {
		currSegment->emit8(b);
	}
	void	emit16(uint16_t w) {
		currSegment->emit16(w);
	}
	void	emit32(uint32_t i) {
		currSegment->emit32(i);
	}

	void	dumpSegmentsAsBin(ostream & o) {
		unsigned long i, j;

		for (i = 0; i < currSegment->pos; i++)
			o << *(currSegment->seg + i);
		for (j = i; j < currSegment->org; j++)
			o << 0;
		for (j = (i > currSegment->org ? i : 0); j < currSegment->pos; j++)
			o << *(currSegment->seg + j);
	}
	void	dumpSegmentsAsIHex() {

	}

	string	getCurrSegmentLabel() { return currSegment->label; }

protected:
	 Segment	textSegment;
	 Segment	dataSegment;
	 Segment *	currSegment;
	//Segment	textSegment(Segment::Type::text);
	//Segment	dataSegment(Segment::Type::data);
	//Segment	constPool(Segment.Type::constPool);
	//Segment stringTable(Segment.Type::stringTable);
	//Segment exec(Segment.Type::exec);


};


// outputs a stream in the LLVM assembly language
class LLVMAsmStream : public CodeStream
{

};




#endif