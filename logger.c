#include "logger.h"
#include <stdio.h>
#include <time.h>

static const char *LOGFILE = "trace.log";

double timestamp() {
    return (double)clock() / CLOCKS_PER_SEC;   // Windows safe
}

void log_event(const char *pid, const char *action, const char *resource) {
    FILE *f = fopen(LOGFILE, "a");
    if (!f) return;

    double t = timestamp();
    fprintf(f, "%.4f %s %s %s\n", t, pid, action, resource);
    fclose(f);
}
