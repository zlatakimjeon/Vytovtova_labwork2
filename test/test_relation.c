#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/relation.h"

void test_empty_relations() {
    printf("Testing empty relations...\n");
    
    struct Relation r = {NULL, 0};
    struct Relation s = {NULL, 0};
    
    printf("Before join_binary call\n");
    struct Relation *res = join_binary(&r, &s);
    printf("After join_binary call, res = %p\n", (void *)res);
    
    if (res == NULL) {
        printf("ERROR: join_binary returned NULL for empty relations!\n");
    } else {
        printf("Success: result size = %u\n", res->size);
    }
    
    assert(res != NULL);
    assert(res->size == 0);
    free_relation(res);
    printf("Empty relations test passed!\n");
}