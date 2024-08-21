## Data Types

<details><summary>6- Ultrasonic Measurement| Long data type</summary>

### 6 Ultrasonic Measurement

### What is a long data type?
A long data type (64 bit) is used when we are dealing with numbers that are longer than that of which an int data type can handle. In addition to this, the long data type is able to process numbers from  -9, 223, 372, 036, 854, 775, 808 to 9, 223, 372, 036, 854, 775, 807. It is important for you to be aware of this as it gives you a good idea to what range of numbers this data type is able to process. In this scenario, a long data type is being used for the distance driver by the robot.

```cpp
long distance;
```

#### What is a ulong data type?

Despite not being used within this tutorial, it is ideal that you are aware of the alternative to a long data type which is still similar. This is a ulong data type, and that is another data type which can process a wider range of numbers than an int (0 to 18, 446, 744, 073, 709, 551, 615)
</details>


<details><summary>7- Drive until object| int data type</summary>

### 7- Drive until object

#### What is an int data type?
int, or integers, are the primary data type used to store numbers. However, they are not able to store as wide a range of numbers as the long data type can. The range in which the int data type can process is (–2, 147, 483, 648 to 2, 147, 483, 647), this means that it can process negative numbers, but not quite to as much as the long data type can. An int is used when we don't quite need to process a big number.

``` cpp
int speedLeft = 0;  // holds the speed of left wheels
```

#### What is a Uint data type?
A uint is used to process shorter positive numbers. A good way of being able to understand this is that it is the shorter or less capable version of the Ulong data type. This data type has a data processing range of (0 to 4, 294, 967, 295)

</details>


<details><summary>Double data type</summary>

#### Double

Double is a data type within the C coding language which has the capability of storing  8 bytes (64 bits) of memory. It helps in storing high- precision sorts of floating- point numbers or data in the computer memory. It is known as the double data type becuase it is able to store double the size of info and data in comparison to the float data type. The double data stores data from 1.7 x10 ^-308 to 2.3 x10 ^+308 numbers.



</details>


<details><summary>Float data type</summary>

#### float

Floats are another data storing value which can store up to 4 bytes (32 bits) of memory. The float data type has a number range of 1.2 x10 ^-38 to 3.4 x10^38. Float is a data type which can store floating point numbers, which are numbers that have a decimal point. Floats can store negative and positive numbers with a decimal point.

</details>


<details><summary>Char data type</summary>

#### char

The char data type is ideal for storing single character values. 

</details>


<details><summary>String data type</summary>

#### string

Typically a string is a sequence of characters which form some sort of variable.

</details>