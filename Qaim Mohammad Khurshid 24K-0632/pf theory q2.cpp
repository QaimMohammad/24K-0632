#include <stdio.h>
#include <string.h>

int main() {
    const char *slogans[] = {"buy now", "save big", "limited offer"};
    int num_slogans = sizeof(slogans) / sizeof(slogans[0]);
    
    for (int i = 0; i < num_slogans; i++) {
        const char *slogan = slogans[i];
        int result[128] = {0};  
        int order[128] = {0};   
        int index = 0;          
        
        
        for (int j = 0; j < strlen(slogan); j++) {
            int char_value = (int)slogan[j];
            if (result[char_value] == 0) {
                order[index++] = char_value;
            }
            result[char_value]++;
        }
        
        
        printf("For \"%s\": {", slogan);
        for (int k = 0; k < index; k++) {
            int char_value = order[k];
            printf("'%c': %d", char_value, result[char_value]);
            if (k < index - 1) {
                printf(", ");
            }
        }
        printf("}\n");
    }
    
    return 0;
}
