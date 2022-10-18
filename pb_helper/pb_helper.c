#include "pb_helper.h"

#include "protos_src/monitor.pb.h"
#include "protos_src/util.pb.h"

#include "nanopb/pb_encode.h"
#include "nanopb/pb_decode.h"
#include "nanopb/pb_common.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

int
pb_helper_encode_msg(void *in_msg, uint8_t *out_msg, uint32_t out_msg_len)
{
    if ((in_msg == NULL) || (out_msg == NULL)) {
        return -1;
    }

    monitor_MonitorMsg *monitor_msg = (monitor_MonitorMsg *)in_msg;
    uint8_t *proto_buf = out_msg;

    pb_ostream_t stream = pb_ostream_from_buffer(proto_buf, (sizeof(monitor_MonitorMsg)));
    bool result = pb_encode(&stream, monitor_MonitorMsg_fields, monitor_msg);
    assert(result == true);

    free(monitor_msg);

    return stream.bytes_written;
}

int
pb_helper_decode_msg(void *in_msg, uint32_t in_msg_len, void *out_msg, uint32_t out_msg_len)
{
    if ((in_msg == NULL) || (out_msg == NULL)) {
        return -1;
    }

    uint8_t *proto_buf = malloc(sizeof(monitor_MonitorMsg));
    assert(proto_buf != NULL);

    monitor_MonitorMsg *monitor_msg = malloc(sizeof(monitor_MonitorMsg));
    assert(monitor_msg != NULL);

    pb_istream_t stream = pb_istream_from_buffer(in_msg, in_msg_len);
    bool result = pb_decode(&stream, monitor_MonitorMsg_fields, monitor_msg);
    assert(result == true);

    return 0;
}