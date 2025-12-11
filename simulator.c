#include "simulator.h"
#include "logger.h"
#include <unistd.h>

void run_demo_simulation(void) {
    remove("trace.log");

    // Simulate Process 1
    log_event("P1", "LOCK", "A");
    usleep(500);

    log_event("P1", "TRYLOCK", "B");
    log_event("P1", "WAIT", "B");
    usleep(500);

    // Simulate Process 2
    log_event("P2", "LOCK", "B");
    usleep(500);

    log_event("P2", "TRYLOCK", "A");
    log_event("P2", "WAIT", "A");
    usleep(500);

    // Simulate queue messages (bottleneck)
    for (int i = 0; i < 8; i++) {
        log_event("P3", "SEND", "Queue1");
        usleep(200);
    }

    // Simulate shared memory access
    log_event("P4", "SHM_WRITE", "ShmX");
    usleep(200);

    log_event("P4", "SHM_READ", "ShmX");
}
