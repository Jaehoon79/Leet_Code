#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool validWordAbbreviation(char* word, char* abbr) {
    int word_len = 0;
    int word_ind = 0;
    int abbr_ind = 0;
    int num_cnt = 0;
    int num = 0;

    char * cmp_word = (char *)malloc((strlen(word) +2) * sizeof(char));
    char * cmp_abbr = (char *)malloc((strlen(abbr) +2) * sizeof(char));
    strcpy(cmp_word, word); strcat(cmp_word, "#");
    strcpy(cmp_abbr, abbr); strcat(cmp_abbr, "#");

    word_len = strlen(cmp_word);

    printf("%d %s, %s \n", word_len, cmp_word, cmp_abbr);

    for (abbr_ind = 0; abbr_ind < strlen(cmp_abbr); abbr_ind++) {
        //printf("%c \n", cmp_abbr[abbr_ind]);
        
        if (isdigit(cmp_abbr[abbr_ind])) {
            int val = cmp_abbr[abbr_ind] - '0';
                            
            if (val == 0 && num_cnt == 0) return false;
            num = (num * 10) + val;
            num_cnt++;
        }
        else {
            printf("%d , %d , %d\n", word_ind, num, word_len);
            word_ind += num;
            if (word_ind >= word_len) return false;
            if(cmp_word[word_ind] != cmp_abbr[abbr_ind]) return false;
            else {
                word_ind++;
                num = 0;
                num_cnt = 0;
            }
        }
        printf("word_index: %d \n", word_ind);
    }

    return true;
}

int main() {
    char word_1 []= "internationalization";
    char abbr_1[] = "i12iz4n";
    
    char word_2[] = "apple";
    char abbr_2[] = "a2e";
    
    char word_3[] = "a";
    char abbr_3[] = "2";

    printf("1.Answer of 1st-Q: %d\n", validWordAbbreviation(word_1, abbr_1));
    printf("2.Answer of 2nd-Q: %d\n", validWordAbbreviation(word_2, abbr_2));
    printf("3.Answer of 3rd-Q: %d\n", validWordAbbreviation(word_3, abbr_3));
    //printf("4.Answer of 4th-Q: %d\n", validWordAbbreviation(word_4, abbr_4));
    return 0;
}