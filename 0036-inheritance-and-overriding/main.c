#include <stdio.h>

struct Animal {
    const char *(*speak)(void);
};

const char *animal_speak(void) { return "some sound"; }
const char *dog_speak(void) { return "Woof"; }

int main(void) {
    struct Animal animal = { animal_speak };
    struct Animal dog = { dog_speak };
    printf("animal: %s\n", animal.speak());
    printf("dog: %s\n", dog.speak());
    return 0;
}
