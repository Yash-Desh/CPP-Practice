// ------------------------------------------- Question ------------------------------------------- 
// You are writing a driver for a new mouse. All incoming data is processed in a function named handleReport();

// void handleReport(uint8_t *buffer, uint16_t length);

// A mouse packet has the following structure:

// B0: report format
// B1: reserved
// B2: dX (bits[7:0])
// B3: dY (bits[7:0])

// B4[1:0]: Left/Right button states
// B4[3:2]: dX (bits[9:8])
// B4[5:4]: dY (bits[9:8])
// B4[7:6]: timestamp (ms) bits[1:0]

// B5: timestamp (ms) bits[9:2]
// B6: timestamp (ms) bits[17:10]

// 1) Write one or more functions that extract the mouse deltas, button state, and timestamp from the device.
// --------------------------------------------------------------------------------------


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

uint16_t get_dX(uint8_t *buffer, uint16_t length)
{
    uint16_t ans = 0;
    ans = buffer[2];

    uint16_t store = buffer[4];
    uint16_t mask = 0x0C;
    store = store & mask;
    store << 7;

    ans = ans | store;
    return ans;
}

uint8_t get_b_state(uint8_t *buffer)
{
    uint8_t ans = 0;
    uint8_t store_bs = buffer[4];
    uint8_t mask = 3;
    ans = store_bs & mask;
    return ans;
}

uint32_t get_ts(uint8_t *buffer){
    uint32_t ans = 0;
    uint32_t store1 = buffer[4];
    uint32_t store2 = buffer[5];
    uint32_t store3 = buffer[6];

    Uint mask = 3;
    Mask << 6;
    store1 = store1 & mask;
    store1 >> 6;
    ans = ans | store1;

    store2 << 2;
    store3 << 10;

    ans = ans | store2;
    ans = ans | store3;
    return ans;
}


uint32_t get_ts(uint8_t *buffer){
    uint32_t ans = 0;
    uint8_t temp = buffer[4];
    uint8_t temp3 = buffer[6];
    ans = temp3;
    ans = ans << 8;
    ans = ans | buffer[5];
    ans = ans << 2;

}


void handleReport(uint8_t *buffer, uint16_t length)
{
    if (length != 7)
        return;

    if (buffer == NULL)
    {
        return;
    }

    mousedata.dX = get_dX(buffer, length);
    mousedata.state = get_b_state(buffer);
    mosuedata.ts = get_ts(uint8_t * buffer);
}