#include "xbn.h"
#include "canada.h"
#include "canada_l.h"
#include "canada_xs.h"
#include "jwst_nebula.h"
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

uint8_t data[] = {0xFF, 0x0F, 0x00, 0x70, 0xF8, 0x00, 0x00};

bool arr_equal(const uint8_t *a1, const uint8_t *a2, uint32_t size)
{
    for (uint32_t i = 0; i < size; i++)
    {
        if (a1[i] != a2[i])
        {
            return false;
        }
    }

    return true;
}

void main(void)
{
    uint8_t bd_n;
    uint32_t out_size;
    uint8_t *xbn = xbsn_encode(jwst_nebula_bits, sizeof(jwst_nebula_bits), 2, &bd_n, &out_size);

    uint8_t *dc = xbsn_decode(xbn, sizeof(jwst_nebula_bits), 2, bd_n);

    assert(arr_equal(jwst_nebula_bits, dc, sizeof(jwst_nebula_bits)));

    printf("in: %lu out: %u\n", sizeof(jwst_nebula_bits), out_size);
}