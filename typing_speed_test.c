#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    char text[] = "C programming improves problem solving skills";
    char input[200];
    clock_t start, end;
    double time_taken;
    int correct_chars = 0, i;
    printf("==== Typing Speed Test ====\n\n");
    printf("Type the following sentence:\n");
    printf("\"%s\"\n\n", text);
    printf("Press Enter to start...");
    getchar();
    start = clock();
    fgets(input, sizeof(input), stdin);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    for (i = 0; text[i] != '\0' && input[i] != '\0'; i++) {
        if (text[i] == input[i])
            correct_chars++;
    }
    int words = 6; 
    double wpm = (words / time_taken) * 60;
    printf("\n--- Results ---\n");
    printf("Time Taken: %.2f seconds\n", time_taken);
    printf("Accuracy: %.2f%%\n", (correct_chars * 100.0) / strlen(text));
    printf("Typing Speed: %.2f WPM\n", wpm);
    return 0;
}
