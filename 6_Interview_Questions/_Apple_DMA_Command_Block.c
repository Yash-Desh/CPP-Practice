// Position   :
// Round      : 
// Interviewer: 
// Date       : 

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
// RO = Read Only

int device_read(void* dst, uint64_t device_addr, int length)
{
  
}




// int device_read(void* dst, uint64_t device_addr, int length)
// {
//   if(dst == NULL) {
//     return -1;
//   }
//   // create the struct 
//   reg_t reg;

//   // read data from the device onto dst
//   uint64_t copy_device_addr = device_addr;
//   uint32_t low_address = copy_device_addr & 0xFFFFFFFF;
//   uint32_t high_address = (copy_device_addr>>32) & 0xFFFFFFFF;

//   reg.device_low_reg = low_address;
//   reg.device_high_reg = high_address;

//   // 2nd part
//   uint32_t command = 0x1<<16;
//   uint32_t ulength = length;
//   reg.command_reg = command | ulength;


//   uint32_t intEnable =  1<<31;
//   uint32_t start = 1;
//   reg.flags_reg = intEnable | start;

//   uint64_t dst_cpy = (uint64_t)dst;
//   reg.dst_low_reg = dst_cpy & 0xFFFFFFFF;
//   reg.dst_high_reg = (dst_cpy>>32)& 0xFFFFFFFF;

//   void * ptr = (void*)0x8000;
// }

