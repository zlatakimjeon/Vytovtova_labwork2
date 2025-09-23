#ifndef RELATION_H
#define RELATION_H

struct Pair {
    int first;
    int second;
};

struct Relation {
    struct Pair *pairs;
    unsigned size;
};

struct Relation *join_binary(struct Relation *r, struct Relation *s);

void free_relation(struct Relation *rel);

#endif
