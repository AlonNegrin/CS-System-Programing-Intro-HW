//#include "Hist.h"
//#include "LinkedList.h"
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdbool.h>
//#include <assert.h>
//
//static Element clone_str(Element str_elem) {
//
//    if (!str_elem) {
//        return NULL;
//    }
//    char *p = malloc(strlen(str_elem) + 1);
//    if (!p) {
//        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n",
//                __FILE__, __LINE__, sizeof(p));
//        exit(-1);
//    }
//    strcpy(p, str_elem);
//    return p;
//}
//
//static bool cmp_str(Element str_elem_1, Element str_elem_2) {
//    return strcmp(str_elem_1, str_elem_2) == 0;
//}
//
//// checking for arguments ->
//// if more than 3, exit. if file no found -> error.  if name invalid -> writes to stdin\out.
////reads data from file to an ADT that keeps count.
////writes the data to a new text file.
//int main(int argc, char *argv[]) {
////    printf(" ");
//    setbuf(stdout, NULL);
//    setbuf(stderr, NULL);
//
//    if (argc > 3) {
//        fprintf(stderr, "\nUsage: %s <file-path0>\n", argv[0]);
//        return 1;
//    }
//    FILE *input_file, *output_file;
//    //init input file.
//    if (argc < 2 || strcmp(argv[1], "-") == 0) {
//        input_file = stdin;
//    } else {
//        input_file = fopen(argv[1], "r");
//        if (!input_file) {
//            fprintf(stderr, "\nUsage: %s <file-path1>\n", argv[0]);
//            exit(-1);
//        }
//    }
//    //init output file.
//    if (argc < 2 || strcmp(argv[2], "-") == 0) {
//        output_file = stdout;
//    } else {
//        output_file = fopen(argv[2], "w");
//        if (!output_file) {
//            fprintf(stderr, "\nUsage: %s <file-path2>\n", argv[0]);
//            exit(-1);
//        }
//    }
//
//    Hist hist = HistCreate(clone_str, free, cmp_str);
//    LinkedList lines = LLCreate(clone_str, free);
//
//    char *buf = NULL;
//    size_t bufsize = 0;
//    int index = 0;
//
//    while (getline(&buf, &bufsize, input_file) != EOF) {
//        HistInc(hist, buf);
//
//        LLAdd(lines, index, buf);
//
//        index++;
//    }
//
//    free(buf);
//    fclose(input_file);
//
//    for (int i = 0; i < LLSize(lines); i++) {
//        Element line = LLRemove(lines, i);
//        LLAdd(lines, i, line);
//        int num = HistGetCount(hist, line);
//        fprintf(output_file, "%3d %s", num, (char *) line);
//    }
//    HistDestroy(hist);
//    LLDestroy(lines);
//    fclose(output_file);
//    return 0;
//}
