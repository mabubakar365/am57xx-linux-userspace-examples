#include<stdio.h>
#include<stdlib.h>

#define BACKLIGHT_PATH "/sys/class/backlight/backlight"

int main(int argc, char *argv[])
{
    char path[128];

    int max_brightness, current_brightness, new_brightness;
    FILE *fp;

    if(argc > 1 && strcmp(argv[1], "poweroff") == 0)
    {
        snprintf(path, sizeof(path), "%s/bl_power", BACKLIGHT_PATH);
        fp = fopen(path, "w");
        fprintf(fp, "1");
        fclose(fp);
        printf("Backlight powered off\n");
        return 0;
    }

    else if(argc > 1 && strcmp(argv[1], "poweron") == 0)
    {
        snprintf(path, sizeof(path), "%s/bl_power", BACKLIGHT_PATH);
        fp = fopen(path, "w");
        fprintf(fp, "0");
        fclose(fp);
        printf("Backlight powered on\n");
        return 0;
    }

    else if(argc > 1 && strcmp(argv[1], "type") == 0)
    {
        snprintf(path, sizeof(path), "%s/type", BACKLIGHT_PATH);
        fp = fopen(path, "r");
        if(fp)
        {
            char type[32];
            fgets(type, sizeof(type), fp);
            fclose(fp);
            printf("Backlight type: %s", type);
            return 0;
        }

        return 1;
    }

    else
    {
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
}