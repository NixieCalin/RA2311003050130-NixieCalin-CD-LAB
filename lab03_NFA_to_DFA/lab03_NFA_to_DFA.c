#include <stdio.h>

int nfa[10][10][10], dfa[10][10];
int n, m;
int dfa_states[10][10], dfa_state_count = 0;

int is_new_state(int state[], int size) {
    for (int i = 0; i < dfa_state_count; i++) {
        int same = 1;
        for (int j = 0; j < size; j++) {
            if (dfa_states[i][j] != state[j]) {
                same = 0;
                break;
            }
        }
        if (same)
            return 0;
    }
    return 1;
}

void copy_state(int dest[], int src[], int size) {
    for (int i = 0; i < size; i++)
        dest[i] = src[i];
}

int main() {
    int i, j, k, l;

    printf("Enter number of NFA states: ");
    scanf("%d", &n);

    printf("Enter number of input symbols: ");
    scanf("%d", &m);

    printf("Enter NFA transition table:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Number of transitions from state %d on input %d: ", i, j);
            int t;
            scanf("%d", &t);
            for (k = 0; k < t; k++) {
                scanf("%d", &nfa[i][j][k]);
            }
            nfa[i][j][t] = -1;
        }
    }

    int start_state[10] = {0};
    start_state[0] = 1;
    copy_state(dfa_states[dfa_state_count++], start_state, n);

    for (i = 0; i < dfa_state_count; i++) {
        for (j = 0; j < m; j++) {
            int new_state[10] = {0};

            for (k = 0; k < n; k++) {
                if (dfa_states[i][k]) {
                    l = 0;
                    while (nfa[k][j][l] != -1) {
                        new_state[nfa[k][j][l]] = 1;
                        l++;
                    }
                }
            }

            if (is_new_state(new_state, n)) {
                copy_state(dfa_states[dfa_state_count++], new_state, n);
            }
        }
    }

    printf("\nDFA States:\n");
    for (i = 0; i < dfa_state_count; i++) {
        printf("State %d: { ", i);
        for (j = 0; j < n; j++) {
            if (dfa_states[i][j])
                printf("%d ", j);
        }
        printf("}\n");
    }

    printf("\nDFA Transition Table:\n");
    for (i = 0; i < dfa_state_count; i++) {
        for (j = 0; j < m; j++) {
            int new_state[10] = {0};

            for (k = 0; k < n; k++) {
                if (dfa_states[i][k]) {
                    l = 0;
                    while (nfa[k][j][l] != -1) {
                        new_state[nfa[k][j][l]] = 1;
                        l++;
                    }
                }
            }

            for (k = 0; k < dfa_state_count; k++) {
                int same = 1;
                for (l = 0; l < n; l++) {
                    if (dfa_states[k][l] != new_state[l]) {
                        same = 0;
                        break;
                    }
                }
                if (same) {
                    dfa[i][j] = k;
                    break;
                }
            }
        }
    }

    for (i = 0; i < dfa_state_count; i++) {
        printf("State %d: ", i);
        for (j = 0; j < m; j++) {
            printf("%d ", dfa[i][j]);
        }
        printf("\n");
    }

    return 0;
}
