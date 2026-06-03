# **Assignments 7–10 (Typora-friendly Markdown)**


# ## **7. Tokenize a String Using a Dynamic Array**

### **Goal**

Write a function that splits a string into tokens (words) and stores them in a dynamic array of `char*` (like a vector of strings).

### **What to Implement**

- A dynamic structure:

```c
typedef struct {
    char **data;
    int size;
    int cap;
} StrVec;
```

- Functions:
  - `StrVec* create_strvec();`
  - `void push_back(StrVec *v, char *token);`
  - `void free_strvec(StrVec *v);`
- A tokenizer:
  - Read one line of input
  - Split by spaces (you may use `strtok`)
  - Each token must be `strdup`’d and pushed into the `StrVec`
  - Print each token with its index

### **Hints**

- Resize exactly like your `IntVec`
- The dynamic array should grow as needed
- Remember to `free` the vector **and** the token strings

------

# ## **8. Load an Entire File into a Dynamically Resized Buffer**

### **Goal**

Write a function that reads a whole file into memory without knowing the file size in advance.

### **What to Implement**

```c
char* read_file(const char *filename);
```

### **Behavior**

- Start with a small buffer (256 bytes)
- Repeatedly read into it using `fread`
- If buffer fills up, grow it with `realloc`
- At end, add `'\0'`
- Return the buffer

### **Test Program**

- Load a file
- Print the number of bytes read
- Print the first 200 characters
- Free the buffer

### **Concepts Learned**

- Chunked reading
- Exponential growth strategy
- Using `realloc` safely
- Managing large memory blocks

------

# ## **9. Implement Your Own `realloc`**

### **Goal**

Recreate the behavior of `realloc` using `malloc`, `memcpy`, and `free`.

### **Function**

```c
void* my_realloc(void* ptr, size_t old_size, size_t new_size);
```

### **Behavior**

1. If `ptr == NULL`, behave like `malloc(new_size)`
2. If `new_size == 0`, behave like `free(ptr)` and return NULL
3. Otherwise:
   - Allocate new memory
   - Copy the old data (up to the min of old/new size)
   - Free the old memory

### **Test It**

- Allocate an int array of 10 elements
- Fill with numbers
- Resize to 20 and check old values still exist
- Resize to 5 and check truncation works

### **Concepts Learned**

- Memory copying
- Ownership transfer
- Low-level understanding of how `realloc` works

------

# ## **10. Build a Simple Text Editor Buffer**

### **Goal**

Make a minimal text buffer structure that supports insertion and deletion.

### **Structure**

```c
typedef struct {
    char *buf;
    int size;
    int cap;
    int cursor;
} TextBuf;
```

### **Required Features**

### ✔ Initialization

```c
TextBuf* new_textbuf();
```

### ✔ Insert character at cursor

```c
void insert_char(TextBuf *tb, char c);
```

### ✔ Delete character before cursor

```c
void delete_char(TextBuf *tb);
```

### ✔ Move cursor left/right

```c
void move_left(TextBuf *tb);
void move_right(TextBuf *tb);
```

### ✔ Resize buffer automatically

Same idea as your `IntVec`, but with `char*`.

### ✔ Print buffer state

Like:

```
Buffer: Hel|lo
Size: 5  Cap: 16  Cursor: 3
```

(`|` marks cursor position)

### **Concepts Learned**

- Editable strings
- Cursor tracking
- Resizing while keeping consistent state
- Real-world text-editor mechanics (nano, vim)

------

# 🎉 You Now Have All Your Assignments Back

And they are in **clean, Typora-friendly Markdown** that you can copy straight into your notes.

If you'd like, I can also provide:

- **Starter code templates** for each assignment
- **Solutions** (only when you'd like them)
- **Bonus assignments** (dynamic matrix, rope data structure, memory pool allocator, etc.)

Would you like the **starter code** for #7 next?
