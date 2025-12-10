
typedef struct {
	char **data;
	int cap;
	int size;
} StringVector;

StringVector *IntVector_create();
void IntVector_free(StringVector *v);
void IntVector_add(StringVector *v, char *val);
void IntVector_remove(StringVector *v);
int IntVector_get_at(StringVector *v, int index);
