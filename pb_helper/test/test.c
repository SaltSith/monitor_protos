#include "../../../acutest.h"

#include "pb_helper/pb_helper.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void test_pb_helper_encode_msg_in_msg_null_ptr(void) {
    uint8_t *out_buf = malloc(sizeof(uint8_t));
    TEST_ASSERT(out_buf != NULL);

    TEST_ASSERT(pb_helper_encode_msg(NULL, out_buf, sizeof(uint8_t)) == -1);
}

void test_pb_helper_encode_msg_out_buf_null_ptr(void) {
    monitor_MonitorMsg *in_msg = malloc(sizeof(monitor_MonitorMsg));
    TEST_ASSERT(in_msg != NULL);

    TEST_ASSERT(pb_helper_encode_msg(in_msg, NULL, 1) == -1);
}

void test_pb_helper_decode_msg_in_buff_null_ptr(void) {
    monitor_MonitorMsg *out_msg = malloc(sizeof(monitor_MonitorMsg));
    TEST_ASSERT(out_msg != NULL);
    TEST_ASSERT(pb_helper_decode_msg(NULL, 1, out_msg) == -1);
}

void test_pb_helper_decode_msg_out_msg_null_ptr(void) {
    uint8_t *in_buff = malloc(sizeof(uint8_t));
    TEST_ASSERT(in_buff != NULL);

    TEST_ASSERT(pb_helper_decode_msg(in_buff, sizeof(in_buff), NULL) == -1);
}

void test_pb_helper_encode_decode(void) {
    monitor_MonitorMsg *to_encode = malloc(sizeof(monitor_MonitorMsg));
    TEST_ASSERT(to_encode != NULL);
    memset(to_encode, 0, sizeof(to_encode));

    to_encode->has_uid = true;
    to_encode->uid = 455468454;

    to_encode->has_msg_status = true;
    to_encode->msg_status = util_MsgStatus_STATUS_OK;

    to_encode->has_timestamp = true;
    to_encode->timestamp = 1666375352;

    to_encode->which_msg = monitor_MonitorMsg_temperature_async_tag;
    to_encode->msg.temperature_async.temperatures_count = 1;
    to_encode->msg.temperature_async.temperatures[0].temp = 66.6;

    uint8_t *proto_buffer = malloc(sizeof(monitor_MonitorMsg));
    TEST_ASSERT(proto_buffer != NULL);

    size_t bytes_written = pb_helper_encode_msg(to_encode, proto_buffer, sizeof(monitor_MonitorMsg));

    monitor_MonitorMsg decoded;
    memset(&decoded, 0, sizeof(decoded));

    int decode_result = pb_helper_decode_msg(proto_buffer, bytes_written, &decoded);
    TEST_ASSERT(decode_result == 0);
}


TEST_LIST = {
	{"test_pb_helper_encode_msg_in_msg_null_ptr", test_pb_helper_encode_msg_in_msg_null_ptr},
	{"test_pb_helper_encode_msg_out_buf_null_ptr", test_pb_helper_encode_msg_out_buf_null_ptr},

	{"test_pb_helper_decode_msg_in_buff_null_ptr", test_pb_helper_decode_msg_in_buff_null_ptr},
	{"test_pb_helper_decode_msg_out_msg_null_ptr", test_pb_helper_decode_msg_out_msg_null_ptr},

    {"test_pb_helper_encode_decode", test_pb_helper_encode_decode},
	{0} /* must be terminated with 0 */
};
