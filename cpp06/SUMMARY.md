# C++ Module 06: Casts & Polymorphism

## Overview
Master C++ type casting mechanisms, polymorphism, and runtime type identification. This module bridges compile-time type safety with runtime flexibility.

---

## **ex00: ScalarConverter**

### Problem Statement
Create a `ScalarConverter` class with a static method `convert(std::string const & str)` that:
1. Receives a string representing any scalar type (char, int, float, double)
2. Detects the literal type (e.g., "42.0f" is float, "42" is int)
3. Converts to all other scalar types
4. Displays results with proper formatting

### Example Behavior
```
Input: "42"
char: '*'
int: 42
float: 42.0f
double: 42.0

Input: "42.5f"
char: '*'
int: 42
float: 42.5f
double: 42.5

Input: "nan"
char: impossible
int: impossible
float: nanf
double: nan
```

### Key Concepts & Challenges
- **`static_cast`**: Safe compile-time conversions (int → float)
- **Literal Detection**: Parse string to determine original type
  - "42" → int
  - "42.0" or "42." → double
  - "42.0f" or "42f" → float
  - Single character (not digit) → char
- **Edge Cases**:
  - Overflow: `stoi()` throws, `stof()`/`stod()` may become inf
  - `NaN`, `+inf`, `-inf` have special string representations
  - Non-printable chars (0-31, 127) should show "Non displayable"
  - Floats outside double range should become inf

### Common Pitfalls
- Forgetting to check if char conversion is possible (97 is 'a', 1000 is impossible)
- Not handling `stof()`/`stod()` exceptions from invalid input
- Incorrect float formatting (f suffix, precision)
- Special values (nan, inf) not properly detected

### Lesson
Understanding type system boundaries, safe conversions, and defensive programming. Introduces the concept of "impossible" conversions and how to communicate them.

---

## **ex01: Serializer**

### Problem Statement
Create a `Serializer` class that converts a `Data` pointer to an `unsigned long` and back:

```cpp
struct Data { std::string data; };

class Serializer {
public:
    static unsigned long serialize(Data* ptr);
    static Data* deserialize(unsigned long raw);
private:
    Serializer();
};
```

### How It Works
```cpp
Data data;
Data* original = &data;

unsigned long serialized = Serializer::serialize(original);  // 0x7fff5fbff8ac
Data* restored = Serializer::deserialize(serialized);

// original == restored (MUST be true)
assert(original == restored);
```

### Key Concepts & Challenges
- **`reinterpret_cast`**: Treats pointer bits as an unsigned long
  ```cpp
  unsigned long serialize(Data* ptr) {
      return reinterpret_cast<unsigned long>(ptr);
  }
  Data* deserialize(unsigned long raw) {
      return reinterpret_cast<Data*>(raw);
  }
  ```
- **Why This Works**: Pointers and integers have the same binary representation on most 64-bit systems
- **Why This Is Dangerous**: 
  - Only works if pointer is still valid (points to same object)
  - No type checking—can deserialize to wrong type
  - Architecture-dependent (32-bit vs 64-bit)
  - Pointer invalidation causes Undefined Behavior

### Real-World Analogy
Like taking a street address ("123 Main St"), writing it down as a number, storing it, and later looking up that address to return to the same place. Only works if the building still exists!

### Lesson
Pointers are just memory addresses; `reinterpret_cast` is the "do what I say" operator. Shows the power and danger of low-level C++ programming. Demonstrates why type safety matters and when you need it.

---

## **ex02: RTTI & Dynamic Polymorphism**

### Problem Statement
Create a class hierarchy with a base class and multiple derived classes. Implement:
1. A factory function that randomly returns a pointer to one of the derived types
2. Identify functions that determine actual type using `dynamic_cast`
3. A delete function that safely handles any base class pointer

```cpp
class Base { public: virtual ~Base() {} virtual void announce() = 0; };
class A : public Base { void announce() { std::cout << "I am A\n"; } };
class B : public Base { void announce() { std::cout << "I am B\n"; } };
class C : public Base { void announce() { std::cout << "I am C\n"; } };

Base* generate();  // Returns random A, B, or C
void identify(Base* p);
void identify(Base& r);
void delete_object(Base* p);
```

### The Challenge
```cpp
Base* ptr = generate();  // Could be A, B, or C

// How do you know what it really is?
if (A* a = dynamic_cast<A*>(ptr)) {
    std::cout << "Got an A\n";
} else if (B* b = dynamic_cast<B*>(ptr)) {
    std::cout << "Got a B\n";
} else if (C* c = dynamic_cast<C*>(ptr)) {
    std::cout << "Got a C\n";
}
```

### Key Concepts & Challenges
- **RTTI Requirement**: Base class must have at least one virtual function
  - Without virtual functions, `dynamic_cast` returns nullptr
  - Virtual destructor is best practice
- **`dynamic_cast<Derived*>(base_ptr)`**:
  - Returns pointer to Derived if conversion is valid
  - Returns `nullptr` if conversion fails (safe!)
  - Much safer than C-style `(Derived*)base_ptr` which blindly casts
- **`dynamic_cast<Derived&>(base_ref)`**:
  - Throws `std::bad_cast` exception on failure
  - Useful when you expect the type to match
- **Reference vs Pointer**: Reference cast throws; pointer cast returns nullptr

### Why This Matters
```cpp
// DANGEROUS - no type checking
void wrongDelete(Base* ptr) {
    A* a = (A*)ptr;  // Could be wrong! Undefined behavior
    delete a;
}

// SAFE - type checking
void safeDelete(Base* ptr) {
    if (dynamic_cast<A*>(ptr)) {
        delete ptr;  // We know it's an A
    }
}
```

### Common Pitfalls
- Forgetting virtual functions (dynamic_cast silently fails)
- Not checking if dynamic_cast returned nullptr
- Using C-style casts instead of dynamic_cast
- Undefined behavior from invalid polymorphic casts
- Memory leaks if you don't use proper deletion

### Performance Consideration
RTTI has runtime overhead (type information stored, runtime lookup). For tight loops or performance-critical code, prefer compile-time polymorphism (templates) or redesign to avoid casting.

### Lesson
Safe polymorphism requires runtime type information. `dynamic_cast` is your tool for working with unknown derived types. It represents the balance between flexibility and safety.

---

## **The Four C++ Casts: When to Use Each**

| Cast | Purpose | Safety | Usage |
|------|---------|--------|-------|
| `static_cast` | Compile-time conversions | ✅ Safe | int → double, base → derived (non-polymorphic) |
| `dynamic_cast` | Runtime polymorphic casts | ✅ Safe | Check actual type of polymorphic pointers |
| `const_cast` | Remove/add const | ⚠️ Use sparingly | Override const in legacy code |
| `reinterpret_cast` | Bit reinterpretation | ❌ Dangerous | Pointers ↔ integers, fundamentally different types |

---

## **Key Takeaways for Module 06**

✅ **Type Safety First**: Prefer `dynamic_cast` over C-style casts for pointers  
✅ **Literal Detection**: Parse string format to determine original scalar type  
✅ **Edge Cases Matter**: Handle NaN, inf, overflow, and non-printable characters  
✅ **RTTI Requires Virtuals**: `dynamic_cast` only works with polymorphic classes  
✅ **Pointer Serialization is Dangerous**: Use only when pointer validity is guaranteed  
✅ **Check dynamic_cast Results**: Always verify nullptr before dereferencing  
✅ **Performance Trade-off**: RTTI adds runtime cost; consider alternatives for hot paths
