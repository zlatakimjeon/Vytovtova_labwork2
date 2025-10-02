#include <assert.h>
#include <stdlib.h>
#include "../include/relation.h"

void test_empty_relations() {
    struct Relation r = {NULL, 0};
    struct Relation s = {NULL, 0};
    struct Relation *res = join_binary(&r, &s);
    assert(res != NULL);
    assert(res->size == 0);
    free_relation(res);
}

void test_single_join() {
    struct Pair rp[] = {{1, 2}};
    struct Pair sp[] = {{2, 3}};
    struct Relation r = {rp, 1};
    struct Relation s = {sp, 1};

    struct Relation *res = join_binary(&r, &s);
    assert(res != NULL);
    assert(res->size == 1);
    assert(res->pairs[0].first == 1 && res->pairs[0].second == 3);
    free_relation(res);
}

void test_no_join() {
    struct Pair rp[] = {{1, 4}};
    struct Pair sp[] = {{2, 3}};
    struct Relation r = {rp, 1};
    struct Relation s = {sp, 1};

    struct Relation *res = join_binary(&r, &s);
    assert(res != NULL);
    assert(res->size == 0);
    free_relation(res);
}

void test_duplicates() {
    struct Pair rp[] = {{1, 2}, {1, 2}};
    struct Pair sp[] = {{2, 3}};
    struct Relation r = {rp, 2};
    struct Relation s = {sp, 1};

    struct Relation *res = join_binary(&r, &s);
    assert(res != NULL);
    assert(res->size == 1);
    assert(res->pairs[0].first == 1 && res->pairs[0].second == 3);
    free_relation(res);
}

int run_all_tests(void) {
    test_empty_relations();
    test_single_join();
    test_no_join();
    test_duplicates();
	return 0;
}                           