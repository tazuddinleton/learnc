
typedef struct {
	char **data;
	int cap;
	int size;
} StringVector;

StringVector *StringVector_create();
void StringVector_free(StringVector *v);
void StringVector_add(StringVector *v, char *val);
char *StringVector_get_at(StringVector *v, int index);
