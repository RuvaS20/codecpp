### 1. Integer types

These store whole numbers.

| Type        | Typical size |                                                   Range |
| ----------- | -----------: | ------------------------------------------------------: |
| `short`     |      2 bytes |                                       −32,768 to 32,767 |
| `int`       |      4 bytes |                         −2,147,483,648 to 2,147,483,647 |
| `long`      | 4 or 8 bytes |                                       Depends on system |
| `long long` |      8 bytes | −9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |

**Important:** `long` is system-dependent. On many modern Macs/Linux systems, it is **8 bytes**, while on Windows it is usually **4 bytes**.

### 2. Decimal / floating-point types

These store numbers with decimal places such as `3.14`, `0.5`, or `123.456`.

| Type          |       Typical size |     Approx. range |          Precision |
| ------------- | -----------------: | ----------------: | -----------------: |
| `float`       |            4 bytes |       ±3.4 × 10³⁸ |        ~6–7 digits |
| `double`      |            8 bytes |      ±1.7 × 10³⁰⁸ |      ~15–16 digits |
| `long double` | 8, 12, or 16 bytes | Depends on system | Usually ≥ `double` |

### The key difference: `float` vs `double`

Think of it as:

```cpp
float  x = 3.14159265;
double y = 3.14159265;
```

`float` has **less precision** than `double`.

For example:

```text
float:   3.141593
double:  3.141592650000...
```

### 3. Unsigned integers

You can also use `unsigned` when you **don't need negative numbers**.

For example:

```cpp
unsigned int age;
```

A typical `unsigned int` has this range:

```text
0 to 4,294,967,295
```

Because all the bits are used for positive values.
