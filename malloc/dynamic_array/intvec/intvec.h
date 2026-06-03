/*
 * IntVec is an array of integer, that dynamically grows.
 * */
typedef struct {
	int *data;
	int cap;
	int size;
} IntVector;

void throw_if_null(IntVector *v);
IntVector *IntVector_create();
void IntVector_free(IntVector *v);
void IntVector_push_back(IntVector *v, int val);
void IntVector_pop_back(IntVector *v);
int IntVector_get_at(IntVector *v, int index);
