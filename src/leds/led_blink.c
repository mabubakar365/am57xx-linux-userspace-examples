#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define LED_PATH "/sys/class/leds/beagle-x15:usr0/brightness"

const char *LEDS[] = {
    "/sys/class/leds/beagle-x15:usr0/brightness",
    "/sys/class/leds/beagle-x15:usr1/brightness",
    "/sys/class/leds/beagle-x15:usr2/brightness",
    "/sys/class/leds/beagle-x15:usr3/brightness",
};



int main(void)
{
    FILE *led;
    int state = 0;

    printf("Blinking LEDs\n");

    while(1)
    {
        state = 1;
        usleep(500000);

        led = fopen(LEDS[1], "w");
        if(led == NULL)
        {
            perror("Error opening led brightness file");
            return 1;
        }

        fprintf(led, "%d", state);
        printf("LED %s turned ON\n", LEDS[1]);
        fclose(led);

        usleep(500000);

        led = fopen(LEDS[0], "w");
        if(led == NULL)
        {
            perror("Error opening led brightness file");
            return 1;
        }

        fprintf(led, "%d", state);
        printf("LED %s turned ON\n", LEDS[0]);
        fclose(led);

        usleep(500000);

        led = fopen(LEDS[2], "w");
        if(led == NULL)
        {
            perror("Error opening led brightness file");
            return 1;
        }

        fprintf(led, "%d", state);
        printf("LED %s turned ON\n", LEDS[2]);
        fclose(led);

        usleep(500000);

        led = fopen(LEDS[3], "w");
        if(led == NULL)
        {
            perror("Error opening led brightness file");
            return 1;
        }

        fprintf(led, "%d", state);
        printf("LED %s turned ON\n", LEDS[3]);
        fclose(led);

        state = 0;
        usleep(500000);

        led = fopen(LEDS[1], "w");
        if(led == NULL)
        {
            perror("Error opening led brightness file");
            return 1;
        }

        fprintf(led, "%d", state);
        printf("LED %s turned OFF\n", LEDS[1]);
        fclose(led);

        usleep(500000);

        led = fopen(LEDS[0], "w");
        if(led == NULL)
        {
            perror("Error opening led brightness file");
            return 1;
        }

        fprintf(led, "%d", state);
        printf("LED %s turned OFF\n", LEDS[0]);
        fclose(led);

        usleep(500000);

        led = fopen(LEDS[2], "w");
        if(led == NULL)
        {
            perror("Error opening led brightness file");
            return 1;
        }

        fprintf(led, "%d", state);
        printf("LED %s turned OFF\n", LEDS[2]);
        fclose(led);

        usleep(500000);

        led = fopen(LEDS[3], "w");
        if(led == NULL)
        {
            perror("Error opening led brightness file");
            return 1;
        }

        fprintf(led, "%d", state);
        printf("LED %s turned OFF\n", LEDS[3]);
        fclose(led);
    }

    return 0;
}
