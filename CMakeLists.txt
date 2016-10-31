cmake_minimum_required(VERSION 2.6)
project(softracker)

add_executable(softracker main.c cmdparam.c settings.c sockutils.c fifo.c proto.c)
target_link_libraries(softracker event pthread config pq)
include_directories(/usr/include/postgresql)

install(TARGETS softracker RUNTIME DESTINATION bin)
