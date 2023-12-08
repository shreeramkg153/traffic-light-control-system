#include <stdio.h>
#include <unistd.h>

// Define states
enum States {
    GreenRoad1,
    YellowRoad1,
    RedRoad1,
    GreenRoad2,
    YellowRoad2,
    RedRoad2
};

// Define transitions and durations
struct Transition {
    enum States next_state;
    int duration;
};

struct Transition transitions[] = {
    {YellowRoad1, 5},
    {RedRoad1, 2},
    {GreenRoad2, 3},
    {YellowRoad2, 5},
    {RedRoad2, 2},
    {GreenRoad1, 3}
};

int main() {
    enum States current_state = GreenRoad1;
    
    while (1) {
        printf("Current State: %d\n", current_state);
        sleep(transitions[current_state].duration);
        current_state = transitions[current_state].next_state;
    }

    return 0;
}
