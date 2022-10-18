add_library(monitor_protos
            util.pb.h util.pb.c
            monitor.pb.h monitor.pb.c)

include_directories ("${PROJECT_SOURCE_DIR}/monitor_protos/nanopb")
link_libraries(nanopb)