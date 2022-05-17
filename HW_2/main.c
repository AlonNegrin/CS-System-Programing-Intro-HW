//#include <stdio.h>
//#include <stdbool.h>
//#include <ctype.h>
//#include <string.h>
//#include <assert.h>
//
//// Student :Alon Negrin - 205843733
//
////function gets an array of integers and size of array,
////returns the number of same elements.
//int same_value(const int *arr, int size) {
//    for (int i = 0; i < size - 1; i++) { //size-1 in loop to not go into index problems.
//        if (arr[i] == arr[i + 1]) {
//            return i;
//        }
//    }
//    return -1;
//}
//
////function gets an array of integers, array size and target value.
////returns number of element couples that sums to target value.
//int sum_n(const int *arr, int size, int target) {
//    int cnt = 0;
//    for (int i = 0; i < size; i++) {
//        for (int j = i + 1; j < size; j++) {
//            if ((arr[i] + arr[j]) == target) {
//                cnt++;
//            }
//        }
//    }
//    return cnt;
//}
////function gets an array of integers, array size.
////swapping all 0 valued elements to end of the list.
////returns the number of integers that are not 0.
//int reduce(int *arr, int size) {
//    int cnt = 0;
//    for (int i = 0; i < size; i++) {
//        if (arr[i] == 0) {
//            arr[i] = arr[i + 1];
//            cnt++;
//        }
//    }
//    return size - cnt;
//}
//
////gets a string of email address.
//// returns true of its valid.
//bool is_legal_email(const char *address) {
//    int at = 0;
//    int preAt = 0;
//    int dot = 0;
//    for (int i = 0; address[i] != 0; i++) {
//        if (i >= 20 || at > 1) {     //if length is longer then 20 or more than one @ signs.
//            return false;
//        }
//        if (at < 1) {
//            if (address[i] == '@') {
//                at++;
//                continue;
//            }
//            if (!isalpha(address[i]) && !isdigit(address[i])) { // if before @ the elements is not digit/alpha.
//                return false;
//            } else { preAt++; }
//
//        }
//        if (address[i] == '@') {
//            at++;
//        }
//        if (at == 1 && preAt == 0) { //if nothing before the @ sign.
//            return false;
//        }
//        if (at > 0 && address[i] == '.') {
//            dot++;
//        }
//
//
//    }
//
//    if (dot == 0) { // if less than 1 '.' in the address.
//        return false;
//    }
//    return true; //all good
//}
//
////gets 2 strings of email addresses.
////return true if it's the same address.
//bool is_same_email(const char *arr1, const char *arr2) {
//    if (strlen(arr1) != strlen(arr2)) { return false; }
//    for (int i = 0; arr1[i] != 0; i++) {
//        if (tolower(arr1[i] != tolower(arr2[i]))) {
//            return false;
//        }
//    }
//    return true;
//}
//
//
//int main() {
//    int arr[8] = {1, 8, 8, 4, 3, 0, 1, 7};
//    assert(same_value(arr, 8) == 1);
//    assert(sum_n(arr, 8, 7) == 2);
//    assert(reduce(arr, 8) == 7);
//    char add1[] = "balotman5@gmail.com";
//    char add2[] = "bAlOTmAn5@gmail.cOm";
//    assert(is_legal_email("baloot5@gmail.com") != 0);
//    assert(is_legal_email("balo@tman5@gmail.com") == 0);
//    assert(is_legal_email("b#otman5@gmail.com") == 0);
//    assert(is_same_email(add1, add2) == 1);
//    assert(is_same_email("balootman5@gmail.com", "balootman5@gmail.com2") == 0);
//    printf("PASS");
//    return 0;
//}
