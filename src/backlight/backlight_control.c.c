#include<stdio.h>
#include<stdlib.h>

#define BACKLIGHT_PATH "/sys/class/backlight/backlight"

int main(void)
{
    char path[128];

    int max_brightness, current_brightness, new_brightness;
    FILE *fp;

    // --- Read max brightness ---
    snprintf(path, sizeof(path), "%s/max_brightness", BACKLIGHT_PATH);
    printf("%s\n", path);

    fp = fopen(path, "r");

    if(!fp)
    {
        perror("Error opening max_brightness");
        return 1;
    }

    fscanf(fp, "%d", &max_brightness);
    fclose(fp);

    // --- Read current brightness ---
    snprintf(path, sizeof(path), "%s/brightness", BACKLIGHT_PATH);
    printf("%s\n", path);

    fp = fopen(path, "r");
    if(!fp)
    {
        perror("Error opening brightness");
        return 1;
    }

    fscanf(fp, "%d", &current_brightness);
    fclose(fp);

    printf("Current brightness: %d / %d\n", current_brightness, max_brightness);

    // --- Increment brightness ---
    new_brightness = current_brightness + 1;
    if (new_brightness > max_brightness)
        new_brightness = 0;  // wrap around to 0 if we exceed max
    printf("Setting brightness to %d\n", new_brightness);

    // --- Write new brightness ---
    printf("%s\n", path);
    fp = fopen(path, "w");
    if(!fp)
    {
        perror("Error writing brightness");
        return 1;
    }

    fprintf(fp, "%d", new_brightness);
    fclose(fp);

    printf("Brightness updated successfully\n");
    return 0;
}