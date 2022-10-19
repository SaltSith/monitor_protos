#include "pb_helper.h"


#include "protos_src/util.pb.h"

#include "nanopb/pb_encode.h"
#include "nanopb/pb_decode.h"
#include "nanopb/pb_common.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

int
pb_helper_encode_msg(monitor_MonitorMsg *in_msg, uint8_t *out_buff, uint32_t out_buff_size)
{
    if ((in_msg == NULL) || (out_buff == NULL)) {
        return -1;
    }

    pb_ostream_t stream = pb_ostream_from_buffer(out_buff, out_buff_size);
    bool result = pb_encode(&stream, monitor_MonitorMsg_fields, in_msg);
    assert(result == true);

    free(in_msg);

    return stream.bytes_written;
}

int
pb_helper_decode_msg(uint8_t *in_buff, uint32_t in_buff_size, monitor_MonitorMsg *out_msg)
{
    if ((in_buff == NULL) || (out_msg == NULL)) {
        return -1;
    }

    pb_istream_t stream = pb_istream_from_buffer(in_buff, in_buff_size);
    bool result = pb_decode(&stream, monitor_MonitorMsg_fields, out_msg);
    assert(result == true);

    return 0;
}
