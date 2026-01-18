# C++ Module 08: Templated Containers & STL Mastery

## Overview
Apply advanced template techniques to real-world container design. Learn to work with STL containers, understand adapter patterns, and master template edge cases.

---

## **ex00: Easy Functions**

### Problem Statement
Implement three template functions in a `whatever` namespace:

```cpp
namespace whatever {
    template<typename T>
    void swap(T& a, T& b);
    
    template<typename T>
    T min(T a, T b);
    
    template<typename T>
    T max(T a, T b);
}
```

### Key Requirements
- `swap`: Exchange two values (no return)
- `min`: Return the smaller value
- `max`: Return the larger value
- Should work with any comparable type

### Example Usage
```cpp
int a = 5, b = 10;
whatever::swap(a, b);
std::cout << a << ", " << b;        // 10, 5

double x = 3.14, y = 2.71;
std::cout << whatever::min(x, y);   // 2.71
std::cout << whatever::max(x, y);   // 3.14

std::string s1 = "hello", s2 = "world";
whatever::swap(s1, s2);
std::cout << s1;                    // "world"
```

### Implementation Details
```cpp
template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T min(T a, T b) {
    return (b < a) ? b : a;
}

template<typename T>
T max(T a, T b) {
    return (a < b) ? b : a;
}
```

### Why This Matters
- Directly parallels `std::swap`, `std::min`, `std::max`
- Shows templates work with ANY type supporting the necessary operators
- Reinforces that STL functions are just templates too

### Lesson
Even simple templates are powerful. These three functions alone eliminate the need to write `swap`, `min`, `max` for int, double, string, custom classes, etc.

---

## **ex01: Iter Function**

### Problem Statement
Create a generic function that applies an action to each element of an array:

```cpp
template<typename T>
void iter(T* array, size_t length, void (*func)(const T&));
```

The function should:
1. Accept a pointer to an array of T
2. Accept the length of the array
3. Accept a function pointer
4. Call the function on each element

### Example Usage
```cpp
void printInt(const int& x) {
    std::cout << x << " ";
}

int arr[] = {1, 2, 3, 4, 5};
iter(arr, 5, printInt);             // Output: 1 2 3 4 5

double darr[] = {1.5, 2.5, 3.5};
void printDouble(const double& x) { std::cout << x << " "; }
iter(darr, 3, printDouble);         // Output: 1.5 2.5 3.5
```

### Implementation
```cpp
template<typename T>
void iter(T* array, size_t length, void (*func)(const T&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}
```

### Key Concepts
- **Function Pointers**: `void (*func)(const T&)` means "pointer to function taking const T& returning void"
- **Const Reference**: Using `const T&` prevents accidental modification and works with temporary objects
- **Non-Type Parameters**: `size_t length` is a regular parameter, not a template parameter
- **Template Type Parameter**: `T` is deduced from the array type

### How Function Pointer Type Works
```cpp
// Read right-to-left:
void (*func)(const T&)
// func is a pointer to a function
// taking const T& and returning void

// Compare with:
void (*func)(T)       // Takes T by value
void (&func)(T)       // Reference to function (not pointer)
void (*func)(T*)      // Takes T* (pointer to T)
```

### Practical Comparison
```cpp
// Modern C++ equivalent using lambdas:
for (size_t i = 0; i < 5; ++i) {
    [](const int& x) { std::cout << x << " "; }(arr[i]);
}

// C++11 std::for_each:
std::for_each(arr, arr + 5, printInt);

// C++11 range-based for:
for (int x : arr) {
    printInt(x);
}
```

### Why This Exercise?
Shows that:
1. Templates work with function pointers
2. You can pass behavior (functions) to generic code
3. This is a precursor to modern functional programming patterns in C++

### Common Pitfalls
- Forgetting `&` in `const T&`—then can't call with temporary values
- Mixing `T` and `T*` in function signature
- Function pointer syntax is notoriously confusing: practice reading it right-to-left
- Type mismatch between array element type and function parameter type

### Lesson
Functional programming patterns in C++: passing functions to generic code enables flexible, reusable algorithms.

---

## **ex02: MutantStack ⭐ (Most Important)**

### The Problem
`std::stack` is a **container adapter** that only exposes:
- `push()` - Add element
- `pop()` - Remove top element
- `top()` - Access top element
- `size()` - Get size

It deliberately **hides** the underlying data structure to enforce LIFO semantics. This is good for pure stack problems, but what if you want to iterate?

```cpp
std::stack<int> s;
s.push(5);
s.push(17);

// Can't do this:
for (auto it = s.begin(); it != s.end(); ++it) {  // ERROR! No iterators!
    std::cout << *it << std::endl;
}
```

### The Solution: MutantStack
Create a stack that supports iteration by inheriting from `std::list<T>`:

```cpp
template<typename T>
class MutantStack : public std::list<T> {
public:
    // Stack interface
    void push(const T& value) { this->push_back(value); }
    void pop() { this->pop_back(); }
    T& top() { return this->back(); }
    
    // Expose list iterators
    typedef typename std::list<T>::iterator iterator;
    typedef typename std::list<T>::reverse_iterator reverse_iterator;
    typedef typename std::list<T>::const_iterator const_iterator;
    typedef typename std::list<T>::const_reverse_iterator const_reverse_iterator;
    
    iterator begin() { return std::list<T>::begin(); }
    iterator end() { return std::list<T>::end(); }
    reverse_iterator rbegin() { return std::list<T>::rbegin(); }
    reverse_iterator rend() { return std::list<T>::rend(); }
    
    // Const versions
    const_iterator begin() const { return std::list<T>::begin(); }
    const_iterator end() const { return std::list<T>::end(); }
    const_reverse_iterator rbegin() const { return std::list<T>::rbegin(); }
    const_reverse_iterator rend() const { return std::list<T>::rend(); }
};
```

### Now This Works!
```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
mstack.push(3);
mstack.push(737);

// Forward iteration (bottom to top)
for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
    std::cout << *it << " ";   // Output: 5 17 3 737
}

// Reverse iteration (top to bottom)
for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
    std::cout << *rit << " ";  // Output: 737 3 17 5
}

// Works with STL algorithms now!
std::sort(mstack.begin(), mstack.end());
std::find(mstack.begin(), mstack.end(), 17);
```

### Key Insights

**1. Container Adapters vs Containers**
| Type | Uses | Interface |
|------|------|-----------|
| `std::stack` | Adapts `std::deque` | Only LIFO operations |
| `std::list` | Actual container | Full bidirectional access |
| `MutantStack` | Inherits from `std::list` | LIFO + iteration |

**2. Why Inherit from `std::list`?**
- `std::list` already supports iteration (begin/end/rbegin/rend)
- Just inherit and expose those methods
- `push_back()/pop_back()` give LIFO behavior
- Much simpler than implementing from scratch

**3. The Trade-off**
```
std::stack:
  Advantages: Clear intent (LIFO only), prevents misuse
  Disadvantages: No iteration capability
  
MutantStack:
  Advantages: Stack operations + iteration, works with STL algorithms
  Disadvantages: Breaks encapsulation of stack abstraction
  
Real code: Usually use std::stack unless you specifically need iteration
```

**4. Why Public Inheritance?**
```cpp
class MutantStack : public std::list<T>  // Publicly inherit
```
- Exposes `std::list` interface
- Allows treating MutantStack as a `std::list` in some contexts
- In production, composition would be safer, but inheritance is clearer for learning

**5. Iterator Types**
```cpp
// Need ALL of these for full iterator support:
typedef typename std::list<T>::iterator            iterator;
typedef typename std::list<T>::reverse_iterator    reverse_iterator;
typedef typename std::list<T>::const_iterator      const_iterator;
typedef typename std::list<T>::const_reverse_iterator const_reverse_iterator;

// And matching begin/end methods for each:
iterator begin()               { return std::list<T>::begin(); }
const_iterator begin() const   { return std::list<T>::begin(); }
reverse_iterator rbegin()              { return std::list<T>::rbegin(); }
const_reverse_iterator rbegin() const  { return std::list<T>::rbegin(); }
// ... etc
```

### Design Pattern: Adapter
This is the **Adapter Pattern**:
- Takes existing interface (`std::list`)
- Wraps it with new interface (`std::stack` methods)
- Adds back old interface (iterators)

### What Makes This "Advanced"?

Most beginners don't understand:
1. **Container adapters exist for a reason**: They restrict what you can do to prevent bugs
2. **You can extend them**: But know the cost (breaking abstractions)
3. **Iterators are the glue of STL**: Any container with iterators works with all STL algorithms
4. **Template specialization**: Managing different iterator types (const/reverse) is complex
5. **The cost-benefit**: Is it worth breaking stack semantics for iteration?

### Common Pitfalls
- Forgetting const versions of methods—algorithms can't iterate over const MutantStack
- Forgetting reverse iterators—range-based for only uses forward iterators
- Using `std::list<T>` private instead of public—then can't access methods
- Missing some iterator method, leading to compilation errors

### Production Code Reality
In real code, you'd probably:
```cpp
// Instead of public inheritance:
template<typename T>
class MutantStack {
private:
    std::list<T> _data;
    
public:
    // Stack interface
    void push(const T& v) { _data.push_back(v); }
    void pop() { _data.pop_back(); }
    T& top() { return _data.back(); }
    
    // Expose iterators (composition version)
    auto begin() { return _data.begin(); }
    auto end() { return _data.end(); }
    // ...
};
```
This is safer because `MutantStack` can't accidentally be used as a `std::list`.

### Lesson
Understanding STL design philosophy and trade-offs. When to use container adapters (restrict interface), when to extend containers (add capability), and when to create new containers from scratch. Shows that C++ gives you power—use it wisely.

---

## **Comparative Analysis: std::stack vs MutantStack**

| Feature | std::stack | MutantStack |
|---------|-----------|-----------|
| **Iteration** | ❌ No | ✅ Yes |
| **Random Access** | ❌ No | ✅ Yes (via iterators) |
| **Encapsulation** | ✅ Strict LIFO | ⚠️ Broken (but intentional) |
| **STL Algorithm Compatible** | ❌ No | ✅ Yes |
| **Performance** | ⭐⭐⭐ | ⭐⭐ (slight overhead) |

---

## **Key Takeaways for Module 08**

✅ **Templates Power Modern C++**: Most of STL is template-based  
✅ **Function Pointers Enable Functional Patterns**: Pass behavior to generic algorithms  
✅ **Container Adapters Have Purpose**: Restrictions improve code clarity and prevent misuse  
✅ **Iterators = Generic Programming Bridge**: Anything with proper iterators works with all STL algorithms  
✅ **Inheritance vs Composition Trade-off**: Public inheritance exposes everything; composition is safer  
✅ **LIFO Semantics Matter**: Breaking them requires excellent reason and documentation  
✅ **Const Correctness with Templates**: Provide const and non-const iterator versions  
✅ **The MutantStack teaches philosophy**: When to extend vs restrict interfaces, and the power/responsibility of C++  
✅ **STL design is intentional**: Every restriction serves a purpose; understand before breaking it
