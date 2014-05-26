
Ring buffer
===========
RING_BUFFER_SIZE - задает длину кольцевого буфера
rBuffer - структура кольцевого буфера
buffer[RING_BUFFER_SIZE] - собственно буфер
head - индекс начала данных (первый занятый байт)
tail - индекс конца данных (первый свободный байт)
count - количество байт в буфере дл чтения


void ringFlush(struct rBuffer *);
Принимает указатель на буфер, очищает буфер.

void ringWrite(struct rBuffer *, unsigned char);
Принимает указатель на буфер, байт для записи в буфер.  

unsigned char ringRead(struct rBuffer *);
Принимает указатель на буфер, возвращает байт по порядку.

bool ringTest(struct rBuffer *);
Проверяет целостность буфера.

uint8_t ringRemain(struct rBuffer *);
Возвращает количество свободных байт в буфере.
