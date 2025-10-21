#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>


/**
 * We have a CPU that is memory constrained connected to an arbitrary sensor.
 *
 * At system boot we need to read the first 400 registers from the sensor and do some processing on the data returned.
 *
 * Assume that all the logic in our code is correct (if run on a system with unlimited resources there would be no problems)
 *
 * The CPU is panicking... what's wrong?
 */


// Helpers
#define APPLE_STACK_SIZE(sizeInBytes)         // Allocate the stack for our main thread
#define APPLE_HEAP_SIZE(sizeInBytes)          // Allocate the heap pool for our system


//  Apple didn't give our processor much memory :(
APPLE_STACK_SIZE(1 * 1024); // 1kB
APPLE_HEAP_SIZE(4 * 1024);  // 4kB


///
/// Sensor helpers
///
#define N_REGS_TO_READ        (400)


/**
* Read N sensor registers of size uint32_t:
* @param[in] nRegs       - Number of registers to read
* @param[in] startoffset - offset from MY_SENSOR_BASE_ADDR to start reading from
* @param[out] myBuffer   - Buffer to store all the samples
*/
static void      getNSensorRegs(uint32_t nRegs, uint32_t startOffset, uint32_t *myBuffer);


/**
* Process the sensor data:
* @param[in] nRegs     - Number of entries in "myBuffer"
* @param[in] myBuffer  - Buffer containing sensor data
*
* @return bool - Whether or not the sensor data is "valid"
*/
static bool      processSensorData(uint32_t nRegs, uint32_t *myBuffer);


int main()
{
   uint32_t myRegArray[N_REGS_TO_READ] = {0};


   // 1. Read the sensor data
   getNSensorRegs(N_REGS_TO_READ, 0, myRegArray);


   // 2. Process the sensor data
   bool isSensorDatValid = processSensorData(N_REGS_TO_READ, myRegArray);


   // 3. Do something with that data
   doSomething(myRegArray);
}


// Helpers, not important
static uint32_t  getDataAtSensorAddr(uint32_t index); // returns a register value


void getNSensorRegs(uint32_t nRegs, uint32_t startOffset, uint32_t *myBuffer)
{
   if (nRegs == 1)
   {
       // Base case
       uint32_t *myNextVal = (uint32_t *)malloc(sizeof(uint32_t));
       *myNextVal = getDataAtSensorAddr(startOffset);
       myBuffer[0] = *myNextVal;
       return;
   }
   else
   {
       // Recurse
       myBuffer[0] = getDataAtSensorAddr(startOffset);
       return getNSensorRegs(nRegs - 1, startOffset + 1, &myBuffer[1]);
   }
}


bool processSensorData(uint32_t nRegs, uint32_t *myBuffer)
{
   uint32_t crcReg = myBuffer[0];


   // Suppose our CRC algorithm needs a scratch buffer as input
   uint32_t *scratchBuffer = (uint32_t *)malloc(sizeof(uint32_t) * nRegs * 4);
   uint32_t outCRC = computeCRC(scratchBuffer, &myBuffer[1]);


   bool valid = (crcReg == outCRC);
   return valid;
}
































