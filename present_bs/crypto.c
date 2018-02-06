#include "crypto.h"
uint64_t boxKS[16] = {
    0x0000000000000000, 0x000000000000ffff, 0x00000000ffff0000, 0x00000000ffffffff,
    0x0000ffff00000000, 0x0000ffff0000ffff, 0x0000ffffffff0000, 0x0000ffffffffffff,
    0xffff000000000000, 0xffff00000000ffff, 0xffff0000ffff0000, 0xffff0000ffffffff,
    0xffffffff00000000, 0xffffffff0000ffff, 0xffffffffffff0000, 0xffffffffffffffff
};
static const uint8_t ksboxR3[256] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
    0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
    0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
    0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
    0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,
    0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,
    0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,
    0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,
    0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,
    0x0a,0x0a,0x0a,0x0a,0x0a,0x0a,0x0a,0x0a,
    0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,0x0b,
    0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,
    0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,0x0d,
    0x0e,0x0e,0x0e,0x0e,0x0e,0x0e,0x0e,0x0e,
    0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,0x0f,
    0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
    0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,
    0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,
    0x13,0x13,0x13,0x13,0x13,0x13,0x13,0x13,
    0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,
    0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,
    0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,
    0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,
    0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,
    0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,
    0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,
    0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,
    0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,
    0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,0x1d,
    0x1e,0x1e,0x1e,0x1e,0x1e,0x1e,0x1e,0x1e,
    0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f
};

static const uint8_t ksboxL5[256] = {
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0,
    0x00,0x20,0x40,0x60,0x80,0xA0,0xC0,0xE0
};
static const uint8_t sbox[16] = {
        0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2,
    };
// For speed move some local var to global
static uint8_t blockStart,j; 
/**
 * Bring normal buffer into bitsliced form
 * @param pt Input: state_bs in normal form
 * @param state_bs Output: Bitsliced state
 */
static void enslice(uint8_t pt[CRYPTO_IN_SIZE * BITSLICE_WIDTH], bs_reg_t state_bs[CRYPTO_IN_SIZE_BIT])
{
    /// INSERT YOUR CODE HERE ///
    uint8_t i;
    for (i = 0; i < BITSLICE_WIDTH; i++){           // 16 blocks
        // multipler is very fast, no need to replace with lut
        blockStart = i*CRYPTO_IN_SIZE;      // The index of start of each block
        for(j=0; j< CRYPTO_IN_SIZE_BIT ; j++){      // 64 bits each block
            // Get the j%8 bit in element j/8 of each block
            // Then "Push" it to the bs array

            // Stays within the byte for each 8 bits
            uint8_t biti = j/8;

            // shl one bit to give space to the incomming bit
            state_bs[j] = state_bs[j]<<1;
            // Get the last bit of the shifited plaintext
            state_bs[j] |= pt[blockStart + biti] & 0x01;
            // shr plaintext in every loop to get better performance
            pt[blockStart +biti] = pt[blockStart + biti] >> 1;
        }
    }

}

/**
 * Bring bitsliced buffer into normal form
 * @param state_bs Input: Bitsliced state
 * @param pt Output: state_bs in normal form
 */
static void unslice(bs_reg_t state_bs[CRYPTO_IN_SIZE_BIT], uint8_t pt[CRYPTO_IN_SIZE * BITSLICE_WIDTH])
{
    /// INSERT YOUR CODE HERE ///
    uint8_t i;
    // Clear the pt buffer
    for(i=0; i < BITSLICE_WIDTH; i++){
        blockStart = i*CRYPTO_IN_SIZE;

        for(j =0; j< CRYPTO_IN_SIZE_BIT; j++){
            // Stays within the byte for each 8 bits
            uint8_t biti = j/8;
            // Give space for incomming bit
            pt[blockStart + biti] = pt[blockStart+biti] >>1;
            // get the MSB of each slice and shift it left
            uint8_t *p = (uint8_t*)(state_bs + j);
            // Put MSB of slice to MSB of each 8bit plaintext element
            pt[blockStart + biti] |= p[1] & 0x80;
            // Shift 16bit slice left discard MSB
            state_bs[j] = state_bs[j] << 1;

        }
    }
}

/**
 * Perform next key schedule step
 * @param key Key register to be updated
 * @param r Round counter
 * @warning For correct function, has to be called with incremented r each time
 * @note You are free to change or optimize this function
 */
static void update_round_key(uint8_t key[CRYPTO_KEY_SIZE], const uint8_t r)
{
    uint8_t tmp = 0;
    const uint8_t tmp2 = key[2];
    const uint8_t tmp1 = key[1];
    const uint8_t tmp0 = key[0];

    // rotate right by 19 bit
    key[0] = ksboxR3[key[2]] | ksboxL5[key[3]];
    key[1] = ksboxR3[key[3]] | ksboxL5[key[4]];
    key[2] = ksboxR3[key[4]] | ksboxL5[key[5]];
    key[3] = ksboxR3[key[5]] | ksboxL5[key[6]];
    key[4] = ksboxR3[key[6]] | ksboxL5[key[7]];
    key[5] = ksboxR3[key[7]] | ksboxL5[key[8]];
    key[6] = ksboxR3[key[8]] | ksboxL5[key[9]];
    key[7] = ksboxR3[key[9]] | ksboxL5[tmp0];
    key[8] = ksboxR3[tmp0]   | ksboxL5[tmp1];
    key[9] = ksboxR3[tmp1]   | ksboxL5[tmp2];

    // perform sbox lookup on MSbits
    tmp = sbox[key[9] >> 4];
    key[9] &= 0x0F;
    key[9] |= tmp << 4;

    // XOR round counter k19 ... k15
    key[1] ^= r << 7;
    key[2] ^= r >> 1;
}

bs_reg_t* add_round_key_spbox(bs_reg_t state[CRYPTO_IN_SIZE_BIT], bs_reg_t bb[CRYPTO_IN_SIZE_BIT], const uint8_t key[CRYPTO_KEY_SIZE])
{
    uint8_t i;
    bs_reg_t x[4];   // For storing bits before sbox per 4 bits

    // Add round key
    for(i=0; i< CRYPTO_IN_SIZE_BIT/8; i++){
        // bitwise index in uint8
        // Get the lower 4 bits of current byte of key
        uint16_t bit4 = key[i] & 0x0f;
        // Slice key usng LUT
        uint64_t slicedKey_4bits = boxKS[bit4];
        // XOR Lower 4bits of Key with state
        uint64_t *p = ((uint64_t*)state)+i*2;
        *p = *p ^ slicedKey_4bits;


        // Higher 4bits of current byte of key
        bit4 = (key[i]>>4) & 0x0f;
        // Slice key usng LUT
        slicedKey_4bits = boxKS[bit4];
        // XOR Higher 4bits of Key with state
        p = ((uint64_t*)state)+i*2+1;
        *p = *p ^ slicedKey_4bits;

    }

    for(i=0; i< CRYPTO_IN_SIZE_BIT/4; i++){
        // i is the count of every 4 bits
        //---------------SPBOX--------------
        // Copy to local variable is faster
        ((uint64_t*)x)[0] = ((uint64_t*)state)[i];

        // Ref: Implementing_Lightweight_Block_Ciphers_on_x86_Architectures
        uint16_t tmp;

        x[2] = x[2]^x[1];
        x[3] = x[3]^x[1];
        tmp = x[2];
        x[2] = x[2] & x[3];

        x[1] = x[1] ^ x[2];
        tmp = tmp ^ x[0];
        x[2] = x[1];
        x[1] = x[1] & tmp;

        x[1] = x[1]^x[3];
        tmp= tmp^x[0];
        tmp = tmp|x[2];
        x[2] = x[2]^x[0];

        x[2] = x[2]^x[1];
        tmp= tmp^x[3];
        x[2] = ~x[2];
        x[0] = x[0]^tmp;

        x[3] = x[2];
        x[2] = x[2]&x[1];
        x[2] = x[2]^tmp;
        x[2] = ~x[2];


        bb[i] = x[0];
        bb[i+16] = x[1];
        bb[i + 2*16] = x[2];
        bb[i + 3*16] = x[3];


    }
    return bb;


}
void add_round_key(bs_reg_t state[CRYPTO_IN_SIZE_BIT],
        const uint8_t key[CRYPTO_KEY_SIZE])
{
    uint8_t i;
    // Add round key
    for(i=0; i< CRYPTO_IN_SIZE_BIT/8; i++){
        // bitwise index in uint8
        // Get the lower 4 bits of current byte of key
        uint16_t bit4 = key[i] & 0x0f;
        // Slice key usng LUT
        uint64_t slicedKey_4bits = boxKS[bit4];
        // XOR Lower 4bits of Key with state
        uint64_t *p = ((uint64_t*)state)+i*2;
        *p = *p ^ slicedKey_4bits;


        // Higher 4bits of current byte of key
        bit4 = (key[i]>>4) & 0x0f;
        // Slice key usng LUT
        slicedKey_4bits = boxKS[bit4];
        // XOR Higher 4bits of Key with state
        p = ((uint64_t*)state)+i*2+1;
        *p = *p ^ slicedKey_4bits;

    }
}
void crypto_func(uint8_t pt[CRYPTO_IN_SIZE * BITSLICE_WIDTH], uint8_t key[CRYPTO_KEY_SIZE])
{
    // State buffer and additional backbuffer of same size (you can remove the backbuffer if you do not need it)
    bs_reg_t state[CRYPTO_IN_SIZE_BIT];
    bs_reg_t bb[CRYPTO_IN_SIZE_BIT];
    bs_reg_t *pcontent = bb;
    bs_reg_t *pbb = state;
    bs_reg_t *ptmp;

    // Bring into bitslicing form
    enslice(pt, state);

    /// INSERT YOUR CODE HERE ///
    uint8_t i;
    for(i = 1; i <= 31; i++)
    {
        // Note +2 offset on key since output of keyschedule are upper 8 byte
        ptmp = pcontent;
        pcontent = pbb;
        pbb = ptmp;
        // Reduce data copy by switch between buffers
        //if(ptmp == bb){
            add_round_key_spbox(pcontent, pbb, key + 2);
        //}else{
            //ptmp = add_round_key_spbox(state,bb, key + 2);
        //}

        //ptmp = ....
        //state
        // Use swap XOR trick to swap pointers

        /*ptmp = ptmp1 ^ ptmp;
        ptmp1 = ptmp ^ ptmp1;
        ptmp = ptmp1 ^ptmp;*/
        update_round_key(key, i);
    }

    // Note +2 offset on key since output of keyschedule are upper 8 byte
    add_round_key(pbb, key + 2);

    // Convert back to normal form
    unslice(pbb, pt);
}
