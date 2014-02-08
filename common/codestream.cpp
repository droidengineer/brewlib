#include "codestream.hpp"



void
ByteCodeStream::dumpSegmentsAsBin()
{
   unsigned long i, j;
   for (i = 0; i < textpos; i++)
	   fputc(*(textseg+i),f);

   for (j = i; j < datasetbase; j++)
	   fputc(0,f);

   for (j = (i < dataset ? i : 0); j < datapos; j++)
	   fputc(*(dataseg+j), f);
}

void
ByteCodeStream::dumpSegmentsAsIHex()
{

}


void
ByteCodeStream::emitString(brew::string & s)
{
  char * ptr = (char*)s;
  while (*++ptr)
  {
	  if (*ptr == '\'')
	  {
		  if (*(ptr+1) == '\'')
		  {
			  emit8(*ptr++);
		  }
	  } else {
		  emit8(*ptr);
	  }
  }
}

void
ByteCodeStream::emit8(uint8_t b)
{

}

void
ByteCodeStream::emit16(uint16_t w)
{
	emit8((uint8_t)((w >> 8) & 0x00ff));
	emit8((uint8_t)(w & 0x00ff));
}

void
ByteCodeStream::emit32(uint32_t l)
{
	  emit16((uint16_t)((l >> 16) & 0x00ff));
	  emit16((uint16_t)(l & 0x00ff));
}