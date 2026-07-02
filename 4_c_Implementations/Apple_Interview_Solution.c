/*Implement a device driver function that reads a buffer of arbitrary length from a block device.
  Memory Mapped Register Layout (base virtual address = 0x8000, already mapped)
    0 -> 32bit device address low (must be 512-byte aligned)
    1 -> 32bit device address high
    2 -> (high) 16 bits command | 16 bits length (number of 512 byte sectors)
      Command 0x1 = Read
      Command 0x2 = Write
    3 -> (high) 1 bit interrupt enable | 1 bit status (RO) | 29 bits unused | 1 bit start
    4 -> 32 bit physical destination address low
    5 -> 32 bit physical destination address high

You may assume any standard kernel library functions exist. */

#include <stdint.h>
#include <stdlib.h>

typedef struct {
  uint32_t device_low_reg;  // reg0 
  uint32_t device_high_reg; // reg1
  union {
    uint32_t command_reg;
    struct {
      uint16_t length;
      uint16_t command;
    };
  };
  union {
    uint32_t flags_reg; 
    struct {
      uint8_t start : 1;
      uint32_t _unused : 29;
      uint8_t status : 1;
      uint8_t interrupt_enable : 1;
    };
  };
  uint32_t dst_low_reg;
  uint32_t dst_high_reg;
} reg_t;

/*
Constraints:
dst: virtual destination buffer, (uintptr_t)dst % 512 == 0
device_addr: linear address, device_addr % 512 == 0
length: length in bytes, length % 512 == 0
*/
// void *dst = kmalloc(1024);
// device_read(dst, 0x2000, 1024);
// memcpy(dst, src, 1024);
// dst -> contents of device @ 0x2000
int device_read(void* dst, uint64_t device_addr, int length)
{
  if(dst == NULL) {
    return -1;
  }
  // create the struct 
  reg_t reg;

  // read data from the device onto dst
  uint64_t copy_device_addr = device_addr;
  uint32_t low_address = copy_device_addr & 0xFFFFFFFF;
  uint32_t high_address = (copy_device_addr>>32) & 0xFFFFFFFF;

  reg.device_low_reg = low_address;
  reg.device_high_reg = high_address;

  // 2nd part
  uint32_t command = 0x1<<16;
  uint32_t ulength = length;
  reg.command_reg = command | ulength;


  uint32_t intEnable =  1<<31;
  uint32_t start = 1;
  reg.flags_reg = intEnable | start;

  uint64_t dst_cpy = (uint64_t)dst;
  reg.dst_low_reg = dst_cpy & 0xFFFFFFFF;
  reg.dst_high_reg = (dst_cpy>>32)& 0xFFFFFFFF;

  void * ptr = (void*)0x8000;
}

/* ===========================================================================
 * AI-generated solution by Claude Opus 4.8 (Cursor)  -  Date: 2026-06-20
 * ===========================================================================
 *
 * Key ideas vs. a naive attempt:
 *   - Write THROUGH the memory-mapped registers (volatile pointer to 0x8000),
 *     not a stack-local struct, so the writes actually reach the hardware.
 *   - reg2 length field is in 512-byte SECTORS, so convert bytes -> sectors.
 *   - reg4/reg5 need a PHYSICAL address; dst is virtual, so translate it.
 *   - Poll the status bit until the DMA transfer completes before returning.
 */

#define DEV_REG_BASE 0x8000

#define CMD_READ  0x1u
#define CMD_WRITE 0x2u

#define SECTOR_SIZE 512

int device_read_ai(void* dst, uint64_t device_addr, int length)
{
    /* --- Validate inputs against the stated constraints --- */
    if (dst == NULL)
        return -1;
    if (length <= 0 || (length % SECTOR_SIZE) != 0)
        return -1;
    if ((device_addr % SECTOR_SIZE) != 0)
        return -1;
    if (((uintptr_t)dst % SECTOR_SIZE) != 0)
        return -1;

    /* Number of 512-byte sectors must fit in the 16-bit length field. */
    uint32_t sectors = (uint32_t)length / SECTOR_SIZE;
    if (sectors == 0 || sectors > 0xFFFFu)
        return -1;

    /* volatile: the registers are real hardware, never cache/optimize them. */
    volatile reg_t* reg = (volatile reg_t*)DEV_REG_BASE;

    /* --- Program the device (source) address: regs 0 and 1 --- */
    reg->device_low_reg  = (uint32_t)(device_addr & 0xFFFFFFFFu);
    reg->device_high_reg = (uint32_t)((device_addr >> 32) & 0xFFFFFFFFu);

    /* --- Program command (high 16 bits) | length-in-sectors (low 16) : reg 2 --- */
    reg->command_reg = (CMD_READ << 16) | (sectors & 0xFFFFu);

    /* --- Program the physical destination address: regs 4 and 5 ---
     * dst is a virtual address; the device performs DMA to physical memory,
     * so translate first. (virt_to_phys is a standard kernel helper.) */
    uint64_t dst_phys = (uint64_t)virt_to_phys(dst);
    reg->dst_low_reg  = (uint32_t)(dst_phys & 0xFFFFFFFFu);
    reg->dst_high_reg = (uint32_t)((dst_phys >> 32) & 0xFFFFFFFFu);

    /* --- Kick off the transfer: set the start bit (reg 3) ---
     * Using polling here, so leave interrupt-enable off. */
    reg->flags_reg = 0;       /* clear stale state */
    reg->start = 1;           /* bit0 -> start the DMA */

    /* --- Wait for completion by polling the read-only status bit --- */
    while (reg->status == 0) {
        /* busy-wait; in a real driver yield/cpu_relax() here */
    }

    return 0;
}

