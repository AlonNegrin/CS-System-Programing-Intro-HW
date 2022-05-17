//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//
////Student : Alon Negrin 205843733
////Student : Dani Reznik 205953821
//
////function gets a string and returns the length.
//int my_strlen(const char *string) {
//    int len = 0;
//    while (*string != 0) {
//        len++;
//        string++;
//    }
//    return len;
//}
//
////function gets 2 strings - destination and source.
////appends source to the end of destination.
//void my_strcat(char *dest, char *src) {
//    int len = my_strlen(dest);
//    for (int i = 0; i < my_strlen(src); i++) {
//        dest[len + i] = src[i];
//    }
//}
//
////function gets a string, returns the first word before first whitespace.
//char *first_word(char *string) {
//    char *word = (char *) malloc(30);
//    sscanf(string, "%s", word);
//    return word;
//}
//
////function gets 2 strings, returns true if the first string begins with the 2nd string, otherwise false.
//bool starts_with(char *s, char *prefix) {
//    char *first = first_word(s);
//    if (my_strlen(first) != my_strlen(prefix)) {
//        return false;
//    }
//    for (int i = 0; i < my_strlen(prefix); i++) {
//        if (prefix[i] != first[i]) {
//            free(first);
//            return false;
//        }
//    }
//    free(first); //used in first_word().
//    return true;
//}
//
////function gets a string and returns the number of words in it.
//int num_words(char *str) {
//    int flag = 0;
//    int words = 0;
//    while (*str) {
//        if (*str == ' ' || *str == '\n' || *str == '\t')
//            flag = 0;
//        else if (flag == 0) {
//            flag = 1;
//            ++words;
//        }
//        ++str;
//    }
//    return words;
//}
//
////function gets a string and return a new string with whitespaces replaced to "-".
//char *normal(const char *str) {
//    int flag = 0;
//    char *new_str = (char *) calloc(my_strlen(str), sizeof(char));
//    if (new_str == NULL) {
//        printf("could not clear allocation for file name (%lu) bits requested.", my_strlen(str) * sizeof(char));
//        exit(-1);
//    }
//    for (int i = 0; str[i] != '\0'; i++) {
//        if ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && flag == 0) {
//            flag = 1;
//            new_str[i] = '-';
//        } else if ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && flag == 1) {
//
//        }
//        if (!(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')) {
//            new_str[i] = str[i];
//            flag = 0;
//        }
//    }
//    return new_str;
//}
//
////function gets a string, prefix and suffix and returns all of them stringed together normalized.
//char *get_chapter_file_name(const char *s, char *prefix, char *suffix) {
//    int size = my_strlen(s) + my_strlen(prefix) + my_strlen(suffix);
//    char *name = calloc(size, sizeof(char));
//    if (name == NULL) {
//        printf("could not clear allocation for file name (%lu) bits requested.", size * sizeof(char));
//        exit(-1);
//    }
//    char *normstr = normal(s);
//    while (normstr[my_strlen(normstr) - 1] == '-') {
//        normstr[my_strlen(normstr) - 1] = '\0';
//    }
//    my_strcat(name, prefix);
//    my_strcat(name, normstr);
//    my_strcat(name, suffix);
//    free(normstr);
//    return name;
//}
//
//
//int main(int argc, char *argv[]) {
//    if (argc <= 2) {
//        fprintf(stderr, "\nUsage: %s <file-path>\n", argv[0]);
//        return 1;
//    }
//
//    char *file_name = argv[1];
//    char *output_prefix = argv[2];
//    char *output_suffix = ".txt";
//
//    //opening file to read.
//    FILE *fp = fopen(argv[1], "r");
//    if (fp == NULL) {
//        printf("Error while opening file mobydick.txt");
//        exit(-1);
//    }
//
//    int all_characters = 0;
//    int all_words = 0;
//    int all_lines = 0;
//    int characters = 0;
//    int words = 0;
//    int lines = 0;
//    char *chap_file_name = get_chapter_file_name("PREFACE", output_prefix, output_suffix);
//    char *buf = NULL;
//    size_t bufsize = 0;
//
//    while (getline(&buf, &bufsize, fp) != EOF) {
//
//        //if starting a new chapter/file.
//        if (starts_with(buf, "CHAPTER")) {
//            printf("%-30s: %d lines, %d words, %d characters\n", chap_file_name, lines, words, characters);
//            chap_file_name = get_chapter_file_name(buf, output_prefix, output_suffix);
//            characters = 0;
//            words = 0;
//            lines = 0;
//        }
//
//        //counting statistics for chapter.
//        characters += my_strlen(buf);
//        words += num_words(buf);
//        lines++;
//
//        //counting statistics for all.
//        all_characters += my_strlen(buf);
//        all_words += num_words(buf);
//        all_lines++;
//
//        //opening / appending to this chapter.
//        FILE *new_file = fopen(chap_file_name, "a");
//        if (new_file == NULL) {
//            printf("Error while opening file %s\n", chap_file_name);
//            exit(-1);
//        }
//        fprintf(new_file,"%s", buf);
//        fclose(new_file);
//    }
//    printf("%-30s: %d lines, %d words, %d characters\n", "TOTAL", all_lines, all_words, all_characters);
//    fclose(fp);
//    free(buf);
//    return 0;
//
//}