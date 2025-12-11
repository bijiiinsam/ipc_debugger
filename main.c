#include "ui.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Remove old log at program start so analysis requires a fresh simulation
    if (remove("trace.log") == 0) {
        printf("[info] Old trace.log removed on startup.\n");
    } else {
        // If remove fails, it may just mean the file didn't exist — that's fine.
        // We avoid printing an error to keep output clean.
    }

    ui_run_menu();
    return 0;
}
