#include "ring_buffer.h"

void ringFlush(struct rBuffer *buff)
{
  buff->tail = 0;
  buff->count = 0;
  buff->head = 0;
}

void ringWrite(struct rBuffer *buff, char sym)
{
  if (buff->count < RING_BUFFER_SIZE){
      buff->buffer[buff->tail] = sym;
      buff->count++;
      buff->tail++;
      if (buff->tail == RING_BUFFER_SIZE) buff->tail = 0;
    }
}

unsigned char ringRead(struct rBuffer *buff)
{
   unsigned char sym = 0;
   if (buff->count > 0){
      sym = buff->buffer[buff->head];
      buff->count--;
      buff->head++;
      if (buff->head == RING_BUFFER_SIZE) buff->head = 0;
   }
   return sym;
}

bool ringTest(struct rBuffer *buff) {
    return (((buff->tail)>(buff->head))?(buff->count == (buff->tail - buff->head)):(buff->count == (RING_BUFFER_SIZE + buff->tail - buff->head)));
}

uint8_t ringRemain(struct rBuffer *buff) {
    return (((buff->tail)>(buff->head))?(buff->tail - buff->head):(RING_BUFFER_SIZE + buff->tail - buff->head));
}