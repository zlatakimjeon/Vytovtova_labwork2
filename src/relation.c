#include <stdlib.h>
#include "relation.h"

struct Relation *join_binary (struct Relation *r, struct Relation *s){
	if (r == NULL || s == NULL) return NULL;
	if (r->size == 0 || s->size == 0) {
        struct Relation *result = malloc(sizeof(struct Relation));
        if (result == NULL) return NULL;
        result->pairs = NULL;
        result->size = 0;
        return result;
    }

	unsigned max_size = r->size + s->size;
	struct Pair *result_pairs = malloc(max_size * sizeof(struct Pair));
	if (result_pairs == NULL) return NULL;

	unsigned result_size = 0;

	for (unsigned i = 0; i < r->size; i++) {
		int a = r->pairs[i].first;
		int b = r->pairs[i].second;
		for (unsigned j = 0; j < s->size; j++) {
			if (s->pairs[j].first == b) {
				int c = s->pairs[j].second;
				int already_exsist = 0;
				for (unsigned k = 0; k < result_size; k++){
					if (result_pairs[k].first == a && result_pairs[k].second == c) {
						already_exsist = 1;
						break;
					}
				}
				if (already_exsist == 0) {
					result_pairs[result_size].first = a;
					result_pairs[result_size].second = c;
					result_size++;
				}
			}
		}
	}

	struct Pair *final_pairs = result_pairs;
    if (result_size == 0) {
        free(result_pairs);
        final_pairs = NULL;
    } else if (result_size < max_size) {
        struct Pair *temp = realloc(result_pairs, result_size * sizeof(struct Pair));
        if (temp != NULL) {
            final_pairs = temp;
        }
    }

    struct Relation *result = malloc(sizeof(struct Relation));
    if (result == NULL) {
        if (final_pairs != NULL) free(final_pairs);
        return NULL;
    }
    
    result->pairs = final_pairs;
    result->size = result_size;
    return result;
}

void free_relation (struct Relation *rel) {
	if (rel != NULL) {
		free(rel->pairs);
		free(rel);
	}
}
