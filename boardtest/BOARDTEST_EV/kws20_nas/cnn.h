/**************************************************************************************************
* Copyright (C) 2019-2021 Maxim Integrated Products, Inc. All Rights Reserved.
*
* Maxim Integrated Products, Inc. Default Copyright Notice:
* https://www.maximintegrated.com/en/aboutus/legal/copyrights.html
**************************************************************************************************/

/*
 * This header file was automatically @generated for the kws20_nas network from a template.
 * Please do not edit; instead, edit the template and regenerate.
 */

#ifndef __CNN_H__
#define __CNN_H__

#include <stdint.h>
typedef int32_t q31_t;
typedef int16_t q15_t;

/* Return codes */
#define CNN_FAIL 0
#define CNN_OK 1

/*
  SUMMARY OF OPS
  Hardware: 17,464,576 ops (17,361,408 macc; 103,168 comp; 0 add; 0 mul; 0 bitwise)
    Layer 0: 2,113,536 ops (2,097,152 macc; 16,384 comp; 0 add; 0 mul; 0 bitwise)
    Layer 1: 3,153,920 ops (3,145,728 macc; 8,192 comp; 0 add; 0 mul; 0 bitwise)
    Layer 2: 3,162,112 ops (3,145,728 macc; 16,384 comp; 0 add; 0 mul; 0 bitwise)
    Layer 3: 3,170,304 ops (3,145,728 macc; 24,576 comp; 0 add; 0 mul; 0 bitwise)
    Layer 4: 528,384 ops (524,288 macc; 4,096 comp; 0 add; 0 mul; 0 bitwise)
    Layer 5: 532,480 ops (524,288 macc; 8,192 comp; 0 add; 0 mul; 0 bitwise)
    Layer 6: 1,585,152 ops (1,572,864 macc; 12,288 comp; 0 add; 0 mul; 0 bitwise)
    Layer 7: 1,312,768 ops (1,310,720 macc; 2,048 comp; 0 add; 0 mul; 0 bitwise)
    Layer 8: 659,456 ops (655,360 macc; 4,096 comp; 0 add; 0 mul; 0 bitwise)
    Layer 9: 264,192 ops (262,144 macc; 2,048 comp; 0 add; 0 mul; 0 bitwise)
    Layer 10: 658,432 ops (655,360 macc; 3,072 comp; 0 add; 0 mul; 0 bitwise)
    Layer 11: 197,120 ops (196,608 macc; 512 comp; 0 add; 0 mul; 0 bitwise)
    Layer 12: 82,688 ops (81,920 macc; 768 comp; 0 add; 0 mul; 0 bitwise)
    Layer 13: 33,280 ops (32,768 macc; 512 comp; 0 add; 0 mul; 0 bitwise)
    Layer 14: 10,752 ops (10,752 macc; 0 comp; 0 add; 0 mul; 0 bitwise)

  RESOURCE USAGE
  Weight memory: 424,448 bytes out of 442,368 bytes total (95.9%)
  Bias memory:   1,493 bytes out of 2,048 bytes total (72.9%)
*/

/* Number of outputs for this network */
#define CNN_NUM_OUTPUTS 21

/* Port pin actions used to signal that processing is active */

#define CNN_START LED_On(1)
#define CNN_COMPLETE LED_Off(1)
#define SYS_START LED_On(0)
#define SYS_COMPLETE LED_Off(0)

/* Run software SoftMax on unloaded data */
void softmax_q17p14_q15(const q31_t * vec_in, const uint16_t dim_vec, q15_t * p_out);
/* Shift the input, then calculate SoftMax */
void softmax_shift_q17p14_q15(q31_t * vec_in, const uint16_t dim_vec, uint8_t in_shift, q15_t * p_out);

/* Stopwatch - holds the runtime when accelerator finishes */
extern volatile uint32_t cnn_time;

/* Custom memcopy routines used for weights and data */
void memcpy32(uint32_t *dst, const uint32_t *src, int n);
void memcpy32_const(uint32_t *dst, int n);

/* Enable clocks and power to accelerator, enable interrupt */
int cnn_enable(uint32_t clock_source, uint32_t clock_divider);

/* Disable clocks and power to accelerator */
int cnn_disable(void);

/* Perform minimum accelerator initialization so it can be configured */
int cnn_init(void);

/* Configure accelerator for the given network */
int cnn_configure(void);

/* Load accelerator weights */
int cnn_load_weights(void);

/* Verify accelerator weights (debug only) */
int cnn_verify_weights(void);

/* Load accelerator bias values (if needed) */
int cnn_load_bias(void);

/* Start accelerator processing */
int cnn_start(void);

/* Force stop accelerator */
int cnn_stop(void);

/* Continue accelerator after stop */
int cnn_continue(void);

/* Unload results from accelerator */
int cnn_unload(uint32_t *out_buf);

/* Turn on the boost circuit */
int cnn_boost_enable(mxc_gpio_regs_t *port, uint32_t pin);

/* Turn off the boost circuit */
int cnn_boost_disable(mxc_gpio_regs_t *port, uint32_t pin);

#endif // __CNN_H__
