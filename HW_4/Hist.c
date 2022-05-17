#include "Hist.h"
#include "LinkedList.h"
#include "Set.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static Element clone_int(Element int_elem) {
    if (!int_elem) return NULL;
    int *p = malloc(sizeof(int));
    *p = *((int *) int_elem);
    return p;
}

struct Hist {

    Element (*clone_func)(Element);

    void (*free_func)(Element);

    bool (*cmp_func)(Element, Element);

    LinkedList lines;
    int *counters_arr;
};



// An ADT for the Hist object. Such object maintains and unordered set of elements, along with a count for each one.

// Create a new histogram object, with element manipulation functions:
// clone_func - return a pointer to the cloned element.
// free_func - free an element returned by clone_func
// cmp_func - return true if the two elements are equal
Hist HistCreate(Element (*clone_func)(Element),
                void (*free_func)(Element),
                bool (*cmp_func)(Element, Element)) {

    Hist hist = calloc(sizeof(struct Hist), 1);
    if (!hist) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n",
                __FILE__, __LINE__, sizeof(Hist));
        exit(-1);
    }

    hist->clone_func = clone_func;
    hist->free_func = free_func;
    hist->cmp_func = cmp_func;
    hist->lines = LLCreate(hist->clone_func, free_func);
    hist->counters_arr = (int *) calloc(sizeof(int), 100);

    return hist;
}

// Destroy a histogram object (along with all its elements)
void HistDestroy(Hist hist) {
    LLDestroy(hist->lines);
    free(hist->counters_arr);
    free(hist);
}

// Return the number of elements in the hist object
unsigned int HistSize(Hist hist) {
    if (!hist) {
        return 0;
    }
    return LLSize(hist->lines);
}

// Get the count of element e. If e is not in hist, returns 0.
//the count is int.
int HistGetCount(Hist hist, Element e) {
    int index = -1;
    unsigned int hist_size = HistSize(hist);
    for (int i = 0; i < hist_size; i++) {
        Element element = LLRemove(hist->lines, i);
        LLAdd(hist->lines, i, element);
        if (hist->cmp_func(element, e)) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return 0;
    }
    return hist->counters_arr[index];


}

// Increment the count of e by one.
// If e is not in hist, create a new entry with a clone of e and a count of 1.
void HistInc(Hist hist, Element e) {
    int index = 0;
    unsigned int hist_size = HistSize(hist);

    if (hist_size == 0) {                                             // if hist is empty

        LLAdd(hist->lines, 0, e);  // add element to hist

        hist->counters_arr[0] = 1;

        return;                                                     //finish.
    } else {

        for (int i = 0; i < hist_size; i++) {                     // iterate through the hist
            Element element = LLRemove(hist->lines, i);
            LLAdd(hist->lines, i, hist->clone_func(element));
            if (hist->cmp_func(element, e)) {
                hist->counters_arr[i] += 1;
                return;                                                //finish.
            }
            index++;
        } // gets here if the element is new to the hist.
        LLAdd(hist->lines, index, hist->clone_func(e));
        hist->counters_arr[index] = 1;
    }
}

// Gets (a clone of) the element at given index.
// If index<0 or index >= HistSize(hist) then NULL is returned.
Element HistGetElement(Hist hist, unsigned int index) {
    if (index < 0 || index >= HistSize(hist)) {
        return NULL;
    }
    Element temp = LLRemove(hist->lines, index);
    LLAdd(hist->lines, index, temp);
    return temp;
}












