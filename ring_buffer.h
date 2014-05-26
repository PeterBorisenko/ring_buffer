/* 
 * File:   ring_buffer.h
 * Author: Disgust
 *
 * Created on May 26, 2014, 1:41 AM
 */

#ifndef RING_BUFFER_H
#define	RING_BUFFER_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <stdbool.h>

#define RING_BUFFER_SIZE 64

    struct  rBuffer{
    unsigned char buffer[RING_BUFFER_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t count;
    };

    void ringFlush(struct rBuffer *);
    void ringWrite(struct rBuffer *, unsigned char);
    unsigned char ringRead(struct rBuffer *);
    bool ringTest(struct rBuffer *);
    uint8_t ringRemain(struct rBuffer *);

#ifdef	__cplusplus
}
#endif

#endif	/* RING_BUFFER_H */

