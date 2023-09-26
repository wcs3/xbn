// (c) 2023 Schmidt
// This code is licensed under MIT license (see LICENSE file for details)

#ifndef __XBN_H__
#define __XBN_H__

#include <stdint.h>

/**
 * Compress data using xbn compression scheme.
 *
 * @param data data to compress
 * @param size size of data in bytes
 * @param x compression parameter
 * @param bd_n output compression parameter
 * @param out_size size of compressed data in bytes
 *
 * @return pointer to malloced array with compressed data
 */
uint8_t *xbn_encode(const uint8_t *data,
                    const uint32_t size,
                    const uint8_t x,
                    uint8_t *bd_n,
                    uint32_t *out_size);

/**
 * Decompress xbn encoded data
 *
 * @param xbn compressed data
 * @param size uncompressed size in bytes
 * @param x compression parameter
 * @param bd_n compression parameter
 *
 * @return pointer to malloced array with uncompressed data
 */
uint8_t *xbn_decode(const uint8_t *xbn,
                    const uint32_t size,
                    const uint8_t x,
                    const uint8_t bd_n);

/**
 * Compress data using xbsn compression scheme.
 *
 * @param data data to compress
 * @param size size of data in bytes
 * @param x compression parameter
 * @param bd_s output compression parameter
 * @param out_size size of compressed data in bytes
 *
 * @return pointer to malloced array with compressed data
 */
uint8_t *xbsn_encode(const uint8_t *data,
                     const uint32_t size,
                     const uint8_t x,
                     uint8_t *bd_s,
                     uint32_t *out_size);

/**
 * Decompress xbsn encoded data
 *
 * @param xbn compressed data
 * @param size uncompressed size in bytes
 * @param x compression parameter
 * @param bd_n compression parameter
 *
 * @return pointer to malloced array with uncompressed data
 */
uint8_t *xbsn_decode(const uint8_t *xbsn,
                     const uint32_t size,
                     const uint8_t x,
                     const uint8_t bd_s);

#endif // __XBN_H__