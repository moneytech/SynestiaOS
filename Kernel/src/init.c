#include <../../Board/RaspberryPi3/include/synestia_os_hal.h>
#include <../../Libraries/LibC/include/stdlib.h>
#include <interrupt.h>
#include <stdint.h>

void clean_bss(uint8_t *start, uint8_t *end) {
    uint32_t i;
    for (i = 0; start + i < end; i++) {
        *(start + i) = '\0';
    }
}

void print_splash() {
    const char *str = "   _____                       _   _       \n"
                      "  / ____|                     | | (_)      \n"
                      " | (___  _   _ _ __   ___  ___| |_ _  __ _ \n"
                      "  \\___ \\| | | | '_ \\ / _ \\/ __| __| |/ _` |\n"
                      "  ____) | |_| | | | |  __/\\__ \\ |_| | (_| |\n"
                      " |_____/ \\__, |_| |_|\\___||___/\\__|_|\\__,_|\n"
                      "          __/ |                            \n"
                      "         |___/                          \n";

    print(str);
}

void kernel_main(void) {
    print_splash();

    init_interrupt();

    init_bsp();

    swi(1);

    print("swi works\n");

    swi(2);

    print("swi works\n");
}
