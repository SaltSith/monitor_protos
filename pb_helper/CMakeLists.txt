add_library(pb_helper 
            pb_helper.h pb_helper.c)

include_directories ("${PROJECT_SOURCE_DIR}/monitor")
include_directories ("${PROJECT_SOURCE_DIR}/monitor_protos")
include_directories ("${PROJECT_SOURCE_DIR}/monitor_protos/nanopb")
target_link_libraries(pb_helper monitor_protos nanopb)