# Data Types

<details><summary>6- Ultrasonic Measurement| Long data type</summary>

## 6 Ultrasonic Measurement

### What is a long data type?

A long data type (64 bit) is used when we are dealing with numbers that are longer than that of which an int data type can handle. In addition to this, the long data type is able to process numbers from  -9, 223, 372, 036, 854, 775, 808 to 9, 223, 372, 036, 854, 775, 807. It is important for you to be aware of this as it gives you a good idea to what range of numbers this data type is able to process. In this scenario, a long data type is being used for the distance driver by the robot.

```cpp
long distance;
```

### What is a ulong data type?

Despite not being used within this tutorial, it is ideal that you are aware of the alternative to a long data type which is still similar. This is a ulong data type, and that is another data type which can process a wider range of numbers than an int (0 to 18, 446, 744, 073, 709, 551, 615)
</details>


<details><summary>7- Drive until object| int data type</summary>

## 7- Drive until object

### What is an int data type?

int, or integers, are the primary data type used to store numbers. However, they are not able to store as wide a range of numbers as the long data type can. The range in which the int data type can process is (–2, 147, 483, 648 to 2, 147, 483, 647), this means that it can process negative numbers, but not quite to as much as the long data type can. An int is used when we don't quite need to process a big number.

``` cpp
int speedLeft = 0;  // holds the speed of left wheels
```

### What is a Uint data type?

A uint is used to process shorter positive numbers. A good way of being able to understand this is that it is the shorter or less capable version of the Ulong data type. This data type has a data processing range of (0 to 4, 294, 967, 295)

</details>


<details><summary>Double data type</summary>

### Double

The double data type is used when you are needing to store a decimal point number that is quite long. The advantage that the double data type offers is that you can store very precise numbers. See the example down below.

```cpp
    double pi = 3.14159265358979323846;
```

This data type is capable of storing 8 bytes (64 bits) of memory. A good way of remembering this data type is that it is known for being able to store double the amount of data than a float can. 

- Precision: It offers a higher level of precision than float, meaning it can represent numbers with more decimal places.<p>
  
- Range: It has a wider range of values it can store, allowing for larger numbers and smaller fractions.<p>
  
- Memory Usage: It occupies more memory than float, as it requires more bits to store the additional precision.<p>
  
- Usage: It is suitable for calculations that require high precision or when dealing with very large or very small numbers.

</details>


<details><summary>Float data type</summary>

### float

Floats are used to store floating- point numbers which are just numbers with a decimal point. They can store up to 4 bytes of memory which is half of that of a double data type. See the example of a float being used down below.

- Precision: It offers a reasonable level of precision for most practical applications, but it may not be suitable for extremely precise calculations.<p>
  
- Range: It can store a wide range of numbers, both positive and negative, including very large and very small values.<p>
  
- Memory Usage: It occupies 4 bytes (32 bits) of memory, which is a relatively small amount compared to other data types.<p>
  
- Usage: It is commonly used for representing values such as measurements, sensor readings, and calculations that involve decimal numbers.

```cpp
    float pi = 3.14159;
```

</details>


<details><summary>Char data type</summary>

### char

The char data type is ideal for storing single character values. 

- Size: It occupies 1 byte (8 bits) of memory.
Values: It can store any character, including letters, numbers, symbols, and control characters.

- Encoding: Characters are typically stored using the ASCII (American Standard Code for Information Interchange) character set, which assigns a numerical value to each character.

- Usage: It is commonly used for storing individual letters, numbers, or symbols, and for working with text-based data.

Below is an example of a char being used.

```cpp
    char letter = 'A';
    char number = '5';
    char symbol = '$';
```

</details>


<details><summary>String data type</summary>

### string

Typically a string is a sequence of characters which form some sort of variable.

- Dynamic Size: Unlike character arrays, String objects can dynamically adjust their size to accommodate different lengths of text.

- Functions: The String class provides various functions for manipulating text, such as concatenation, comparison, searching, and extraction of substrings.

- Memory Usage: While String objects offer flexibility, they can consume more memory compared to character arrays, especially for large strings.

- Usage: String is commonly used for working with text data, such as displaying messages, reading user input, and formatting output.

Below is an example of a string being used.

```cpp
String greeting = "Hello, world!";
String name = "Alice";
String message = greeting + " My name is " + name;
```

</details>