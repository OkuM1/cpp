# C++ Module 07: Advanced Templates

## Overview
Master generic programming through templates. Learn compile-time polymorphism, template specialization, and how to write truly reusable code that works with any type.

---

## **ex00: Function & Class Templates**

### Problem Statement
Implement three template functions:
1. `max<T>(T a, T b)` - Returns the larger value
2. `min<T>(T a, T b)` - Returns the smaller value  
3. `swap<T>(T& a, T& b)` - Swaps two values

And test with multiple types (int, double, string, etc.)

### Example Usage
```cpp
int a = 5, b = 10;
std::cout << max(a, b);      // 10

double x = 3.14, y = 2.71;
std::cout << min(x, y);      // 2.71

std::string s1 = "hello", s2 = "world";
swap(s1, s2);
std::cout << s1;             // "world"
```

### Key Concepts & Challenges
- **Function Template Syntax**:
  ```cpp
  template<typename T>
  T max(T a, T b) {
      return (a > b) ? a : b;
  }
  ```
- **Template Instantiation**: When you call `max(5, 10)`, the compiler generates `max<int>(int, int)`
- **Type Deduction**: Compiler automatically determines T from arguments
- **Operator Requirements**: max/min need `>` and `<` operators; swap needs assignment
- **Implicit Instantiation**: Templates only generate code when used (not when declared)

### Common Pitfalls
- Trying to use operators not defined for the type (e.g., `>` for custom class without overload)
- Confusing template declaration with definition (must be in header for implicit instantiation)
- Type mismatch: `max(5, 3.14)` is ambiguous—compiler can't choose T
- Templates don't work with built-in arrays directly

### Actual Behavior
```cpp
// These calls generate different code:
max(5, 10);              // Generates max<int>
max(3.14, 2.71);         // Generates max<double>
max("a", "b");           // Generates max<const char*>

// Each instantiation is a completely separate function
// No runtime overhead compared to manually writing each version
```

### Lesson
Templates enable **zero-cost abstraction**: you get generic code without performance penalty. The compiler does the work at compile-time, not runtime.

---

## **ex01: Template Specialization**

### Problem Statement
Create a template class that can be specialized for pointers and arrays:

```cpp
template<typename T>
void iter(T* array, size_t length, void (*func)(T&));

// This function should:
// 1. Accept a pointer to array of T
// 2. Accept the array length
// 3. Accept a function pointer to apply to each element
// 4. Call the function on each element
```

### Example Usage
```cpp
void printInt(int& x) { std::cout << x << " "; }
void printDouble(double& x) { std::cout << x << " "; }

int arr[] = {1, 2, 3, 4, 5};
iter(arr, 5, printInt);           // Prints: 1 2 3 4 5

double darr[] = {1.1, 2.2, 3.3};
iter(darr, 3, printDouble);       // Prints: 1.1 2.2 3.3
```

### Key Concepts & Challenges
- **Function Pointers as Template Parameters**:
  ```cpp
  template<typename T>
  void iter(T* array, size_t length, void (*func)(T&)) {
      for (size_t i = 0; i < length; ++i) {
          func(array[i]);
      }
  }
  ```
- **Why Not Specialization?** This is actually a simple template, not specialization—it works for all T the same way
- **Function Pointer Type**: `void (*func)(T&)` means "pointer to function taking T& returning void"
- **Non-Type Template Parameters**: `size_t length` is not a template parameter, it's a regular parameter

### Real-World Use
This is an early predecessor to `std::for_each` algorithm:
```cpp
// Modern C++11+ alternative:
std::for_each(arr, arr + 5, printInt);

// Or range-based for:
for (int& x : arr) {
    printInt(x);
}
```

### Common Pitfalls
- Forgetting the `&` in function signature: `void (*func)(T)` vs `void (*func)(T&)`
- Type mismatch between array type and function parameter type
- Function pointer syntax is tricky: `void (*)(T&)` not `void*(&)(T&)`

### Lesson
Templates work with function pointers, enabling functional programming patterns. This is the foundation for concepts like callbacks and higher-order functions in C++.

---

## **ex02: Template Iterators & Advanced Template Techniques**

### Problem Statement
Create a template class that behaves like a linked list:

```cpp
template<typename T>
class Array {
public:
    Array(unsigned int n);              // Constructor with size
    ~Array();                           // Destructor
    unsigned int size() const;          // Get size
    T& operator[](unsigned int i);      // Element access
    const T& operator[](unsigned int i) const;
    
    // Iterator support
    typedef T* iterator;
    typedef const T* const_iterator;
    
    iterator begin() { return _data; }
    iterator end() { return _data + _size; }
    const_iterator begin() const { return _data; }
    const_iterator end() const { return _data + _size; }
};
```

### Why This Matters
```cpp
Array<int> arr(5);
arr[0] = 10;
arr[1] = 20;

// Now works with STL algorithms because it has iterators:
std::sort(arr.begin(), arr.end());

// Works with range-based for loop:
for (int x : arr) {
    std::cout << x << " ";
}

// Works with std::for_each:
std::for_each(arr.begin(), arr.end(), [](int x) {
    std::cout << x << " ";
});
```

### Key Concepts & Challenges
- **Nested Type Definitions**:
  ```cpp
  typedef T* iterator;
  typedef const T* const_iterator;
  ```
  These tell the STL that your container has iterators.
  
- **Iterator Categories**:
  - Random Access: `T*` (fastest, full access)
  - Bidirectional: Linked lists (slower, forward & backward)
  - Forward: Single-pass
  - Input/Output: Streams

- **Const Correctness is Critical**:
  ```cpp
  // Non-const version
  iterator begin() { return _data; }
  
  // Const version
  const_iterator begin() const { return _data; }
  ```

- **Why `T*` Works as Iterator**: Raw pointers satisfy the random access iterator concept. They support `++`, `--`, `+`, `[]`, dereferencing, etc.

### What Makes This "Advanced"
Most beginners don't understand that:
1. Iterators aren't special—they're just objects with `++`, `*`, and comparison operators
2. Raw pointers ARE valid iterators
3. STL algorithms (sort, find, etc.) work with ANY iterator, not just STL containers

### Integration with STL
```cpp
// All of these now work:
std::find(arr.begin(), arr.end(), 42);
std::count_if(arr.begin(), arr.end(), [](int x) { return x > 10; });
std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
std::reverse(arr.begin(), arr.end());
```

### Common Pitfalls
- Forgetting `const` versions of iterator methods
- Using `std::iterator` base class (deprecated in C++17)
- Not understanding that `T*` is a valid iterator
- Forgetting to define both `iterator` and `const_iterator`

### Lesson
Iterators are the "glue" of STL. Any data structure with proper iterator support instantly works with all STL algorithms. This is the power of generic programming in C++.

---

## **Key Takeaways for Module 07**

✅ **Templates = Compile-Time Polymorphism**: No virtual function overhead  
✅ **Type Deduction is Automatic**: Compiler figures out types in most cases  
✅ **Code Bloat Risk**: Template instantiation can lead to large binaries; be mindful  
✅ **Type Safety**: Templates provide stronger type checking than runtime polymorphism  
✅ **Iterator Support is Everything**: Proper iterators make your container work with all STL algorithms  
✅ **Const Correctness**: Always provide const versions of iteration methods  
✅ **Templates Live in Headers**: Most template code must be in .hpp files for implicit instantiation  
✅ **Specialization Enables Optimization**: Optimize hot paths with full or partial specialization
