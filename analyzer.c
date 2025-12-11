// Analyzer module updated for testing branch workflow


#include "analyzer.h"
#include <stdio.h>
#include <string.h>

void analyze() {
    FILE *f = fopen("trace.log", "r");
    if (!f) {
        printf("\n[ERROR] trace.log not found. Run simulation first.\n");
        return;
    }

    double ts;
    char pid[32], action[32], res[64];
    int p1_wait_b = 0, p2_wait_a = 0, send_count = 0;
    int parsed = 0;

    printf("\n[debug] Contents parsed from trace.log:\n");

    while (fscanf(f, "%lf %31s %31s %63s", &ts, pid, action, res) == 4) {
        parsed++;
        printf("  ts=%.4f pid=%s action=%s res=%s\n", ts, pid, action, res);

        if (strcmp(pid, "P1")==0 && strcmp(action, "WAIT")==0 && strcmp(res, "B")==0)
            p1_wait_b = 1;
        if (strcmp(pid, "P2")==0 && strcmp(action, "WAIT")==0 && strcmp(res, "A")==0)
            p2_wait_a = 1;
        if (strcmp(action, "SEND")==0)
            send_count++;
    }

    if (parsed == 0) {
        // try no-timestamp format
        rewind(f);
        printf("[debug] No timestamped lines found, trying pid action res format...\n");
        while (fscanf(f, "%31s %31s %63s", pid, action, res) == 3) {
            parsed++;
            printf("  pid=%s action=%s res=%s\n", pid, action, res);
            if (strcmp(pid, "P1")==0 && strcmp(action, "WAIT")==0 && strcmp(res, "B")==0)
                p1_wait_b = 1;
            if (strcmp(pid, "P2")==0 && strcmp(action, "WAIT")==0 && strcmp(res, "A")==0)
                p2_wait_a = 1;
            if (strcmp(action, "SEND")==0)
                send_count++;
        }
    }

    fclose(f);

    printf("\n[debug] Summary: parsed=%d, P1_WAIT_B=%d, P2_WAIT_A=%d, SENDs=%d\n",
           parsed, p1_wait_b, p2_wait_a, send_count);

    printf("\n===== IPC ANALYSIS =====\n");
    if (p1_wait_b && p2_wait_a)
        printf("[!] DEADLOCK DETECTED: P1 <-> P2\n");
    else
        printf("[OK] No deadlock detected.\n");

    if (send_count > 5)
        printf("[!] BOTTLENECK DETECTED: Queue1 overloaded (%d messages)\n", send_count);
    else
        printf("[OK] No queue bottleneck.\n");
    printf("=========================\n");
}
