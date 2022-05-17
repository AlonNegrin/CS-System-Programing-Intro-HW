////
//// Created by baloo on 13/05/2022.
////
//
//#include "Hist.h"
//#include "LinkedList.h"
//#include "TestLinkedList.h"
//#include <assert.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//
//static Element clone_int(Element int_elem) {
//    if (!int_elem) return NULL;
//    int *p = malloc(sizeof(int));
//    *p = *((int*)int_elem);
//    return p;
//}
//
//static bool cmp_int(Element int_elem_1, Element int_elem_2) {
//    return int_elem_1 == int_elem_2;
//}
//
//static void test_int_hist(int n) {
//    Hist hist = HistCreate(clone_int, free,cmp_int);
//    for(int i=0; i<n; i++) {
//        assert(HistSize(hist) == i);
//        HistInc(hist,i);
//    }
//    for(int i=0; i<n; i++) {
//        assert(LLSize(hist) == n-i);
//        int *p = LLRemove(hist,0);
//        assert(p && *p == i);
//        free(p);
//    }
//    assert(!LLRemove(hist,0));
//    for(int i=0; i<n; i++) {
//        assert(LLSize(hist) == i);
//        LLAdd(hist,0,&i);
//    }
//    for(int i=0; i<n; i++) {
//        assert(LLSize(hist) == n-i);
//        int *p = LLRemove(hist,n-i-1);
//        assert(p && *p == i);
//        free(p);
//    }
//    assert(!LLRemove(hist,0));
//    LLDestroy(hist);
//}
//
//static Element clone_str(Element str_elem) {
//    if (!str_elem) return NULL;
//    char *p = malloc(strlen(str_elem)+1);
//    strcpy(p, str_elem);
//    return p;
//}
//
//static bool test_str_at_index(LinkedList ll, int index, const char *ref) {
//    char *cur = LLRemove(ll, index);
//    if (!cur || strcmp(cur,ref) != 0) return false;
//    free(cur);
//    return true;
//}
//
//static void test_str_ll() {
//    LinkedList ll = LLCreate(clone_str, free);
//    assert(LLSize(ll) == 0);
//    LLAdd(ll,0,"abc"); // abc
//    LLAdd(ll,0,"d");   // d abc
//    LLAdd(ll,1,"ef");  // d ef abc
//    LLAdd(ll,3,"ghi"); // d ef abc ghi
//    assert(LLSize(ll) == 4);
//    assert( test_str_at_index(ll, 0, "d") ); // ef abc ghi
//    assert( test_str_at_index(ll, 1, "abc") ); // ef ghi
//    assert( test_str_at_index(ll, 1, "ghi") ); // ef
//    assert( test_str_at_index(ll, 0, "ef") );
//    assert(!LLRemove(ll,0));
//    LLDestroy(ll);
//}
//
//void test_linked_list() {
//    test_str_ll();
//}
//
