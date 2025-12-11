#include "ui.h"
#include "simulator.h"
#include "analyzer.h"
#include <stdio.h>
#include <unistd.h>

void ui_run_menu() {
    int choice;

    while (1) {
        printf("\nIPC Debugger Menu\n");
        printf("1. Run Simulation\n");
        printf("2. Analyze Log\n");
        printf("3. exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Running simulation...\n");
            run_demo_simulation();
            printf("Simulation complete.\n");
        }
        else if (choice == 2) {
            analyze();
        }
        else if (choice == 3) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice.\n");
        }
    }
}
