#include <stdint.h>

#include <stdint.h>

#include "protos_src/monitor.pb.h"

int pb_helper_encode_msg(monitor_MonitorMsg *in_msg, uint8_t *out_buff, uint32_t out_buff_size);
int pb_helper_decode_msg(uint8_t *in_buff, uint32_t in_buff_size, monitor_MonitorMsg *out_msg);