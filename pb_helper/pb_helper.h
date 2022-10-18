#include <stdint.h>

#include <stdint.h>

int pb_helper_encode_msg(void *in_msg, uint8_t *out_msg, uint32_t out_msg_len);
int pb_helper_decode_msg(void *in_msg, uint32_t in_msg_len, void *out_msg, uint32_t out_msg_len);