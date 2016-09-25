#ifndef _RUNTIME_H_
#define _RUNTIME_H_

typedef unsigned char   uint8_t;
typedef unsigned short  uint16_t;
typedef unsigned int    uint32_t;
typedef _Bool           bool;
typedef unsigned int    size_t;

#define ARRAY_SIZE(_a) (sizeof(_a) / sizeof(*(_a)))

void bios_printf(const char *, ...)
  __attribute__ ((format (printf, 1, 2)));
void bios_gpu_sync(void);

static inline void nop(void) {
  __asm__ __volatile__ ("nop");
}

static inline void brk(void) {
  __asm__ __volatile__ ("break");
}

static inline uint32_t read32(size_t addr) {
  volatile const uint32_t *p = (volatile void *)addr;

  return *p;
}

static inline uint16_t read16(size_t addr) {
  volatile const uint16_t *p = (volatile void *)addr;

  return *p;
}

static inline uint8_t read8(size_t addr) {
  volatile const uint8_t *p = (volatile void *)addr;

  return *p;
}

static inline void write32(size_t addr, uint32_t val) {
  volatile uint32_t *p = (volatile void *)addr;

  *p = val;
}

static inline void write16(size_t addr, uint16_t val) {
  volatile uint16_t *p = (volatile void *)addr;

  *p = val;
}

static inline void write8(size_t addr, uint8_t val) {
  volatile uint8_t *p = (volatile void *)addr;

  *p = val;
}

#endif /* _RUNTIME_H_ */