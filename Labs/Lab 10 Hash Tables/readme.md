# Lab 10 Hash Tables
---

## 1. Introduction

#### Hash Tables

The goal of this lab is to provide background on **Hash Tables, Chaining, & Open-Addressing**.

Hash Tables are a Data Structure that maps keys to values via a Hash Function.

The core concept is to have an array of size *n* with efficient storage/retrieval time.

Let's take a brief look at how these work. Using an example w/ a table size of 5, we have the following:

| Index | Value |
| ----- | ----- |
| 0     |       |
| 1     |       |
| 2     |       |
| 3     |       |
| 4     |       |

But how do we store values? We need a Hash Function!

A Hash Function is (surprise) a function that generates some Hash out of the value to be stored. This is an entire field of research, so we'll keep it simple for now. Let's use the following function:

<center>f(x) = x % n </center>

Let's use it to store the following values: 1, 14, 13, 16

1 % 5 = 1

| Index | Value |
| ----- | ----- |
| 0     |       |
| 1     | 1     |
| 2     |       |
| 3     |       |
| 4     |       |

14 % 5 = 4

| Index | Value |
| ----- | ----- |
| 0     |       |
| 1     | 1     |
| 2     |       |
| 3     |       |
| 4     | 14    |

13 % 5 = 3

| Index | Value |
| ----- | ----- |
| 0     |       |
| 1     | 1     |
| 2     |       |
| 3     | 13    |
| 4     | 14    |

16 % 5 = 1

| Index | Value                  |
| ----- | ---------------------- |
| 0     |                        |
| 1     | 1 <-- already a value! |
| 2     |                        |
| 3     | 13                     |
| 4     | 14                     |

We've found an issue with our new Data Structure! This is known as a Hash Collision. Let's look at methods to combat this.

## 2. Open Addressing

Open Addressing is a method of collision resolution in hash tables. This method uses **probing** in order to find an open spot in the array to place a value that has encountered a collision. Let's look at a few:

#### Linear Probing

For this method, we simply keep checking the next spot to see if it is available. Let's use the example collision from above and see where we end up:

| Index | Value                  |
| ----- | ---------------------- |
| 0     |                        |
| 1     | 1 <-- already a value! |
| 2     | 16                     |
| 3     | 13                     |
| 4     | 14                     |

Since the very next spot was open, 16 gets placed at index 2.

#### Double Hashing

Another open addressing method is to use double hashing. In this strategy, a second hash function is utilized to re-hash a value that has collisions. Let's view that example from above again using this new definition:

<center>f(x, i) = [(x % n) + (i * f'(x))] % n</center>

<center>f'(x) = x+3</center>
<center>Where i is the number of collisions so far</center>

At the first attempt there are no recorded collisions yet for the input 16 so i is 0
f(16, 0) = [(16 % n) + (0 * 19)] % n = 1

After encountering a collision on the first pass, i will now be 1
f(16, 1) = [(16 % n) + (1 * 19)] % n = [(1) + 19] % n = 0

| Index | Value |
| ----- | ----- |
| 0     | 16    |
| 1     | 1     |
| 2     |       |
| 3     | 13    |
| 4     | 14    |

A slightly different result than Linear Probing. There are many different strategies for implementing these functions, such as quadratic probing. Let's look at another method entirely.

#### Chaining

In Chaining, instead of an array of keys, we have an array of lists that hold keys. This means probing strategies are not needed, and we just need to push a new value onto the list. For efficiency's sake, we typically push onto the front of the list to maintain O(1) time. Thus, our example values from earlier create the following table:

| Index | Value   |
| ----- | ------- |
| 0     |         |
| 1     | 16 -> 1 |
| 2     |         |
| 3     | 13      |
| 4     | 14      |


## 3. Resizing
As a Hash Table gets full it will end up with more collisions per insert, lowering the efficiency of the data structure.

To fix this, you occasionally need to resize the table, which is a $O(n)$ cost operation with the following steps:
- Create a new table with twice the size of the old table
- Insert every element from the old table into the new
  - Note: You do **not** copy the elements over directly! Their indices will change due to the new table size!
- Delete the old table

When to resize the table is up to the programmer, but it has been found that no more than 70% full yields optimal performance.

Here is an example using Separate Chaining:

Inserting a 26 into this table:

The table is currently 80% full, so we need to resize before the insert takes place.

| Index | Value   |
| ----- | ------- |
| 0     |         |
| 1     | 16 -> 1 |
| 2     |         |
| 3     | 13      |
| 4     | 14      |

After re-sizing & re-inserting the old values:

| Index | Value |
|-------|---|
| 0     |   |
| 1     | 1 |
| 2     |   |
| 3     | 3 |
| 4     | 4 |
| 5     |   |
| 6     | 6 |
| 7     |   |
| 8     |   |
| 9     |   |

Now we can insert the 26:

| Index | Value   |
|-------|---------|
| 0     |         |
| 1     | 1       |
| 2     |         |
| 3     | 3       |
| 4     | 4       |
| 5     |         |
| 6     | 6 -> 26 |
| 7     |         |
| 8     |         |
| 9     |         |

## 4. Your Task 

Your goal for this lab is to complete the following tasks:

1. Write a program that accepts the name of an input file along with an integer dictating which hashing strategy is to be used.
2. Implement the Linear Probing collision resolution strategy.
2. Implement the Double Hashing collision resolution strategy.
3. Implement the Separate Chaining collision resolution strategy.
4. Your table should resize if the number of elements added is >=70% of the table max size.
5. For all strategies, you should keep track of the # of collisions and report it at the end.

To complete the above objectives, create a Hash Table class using a vector as the underlying data structure. Then write a hash function, insert function and an accessing function.

### Hash
The hash function should accept the value to insert into the table and return its index.

For Double Hashing, you'll need to use 2 hash functions:

h1(k) = k % table_size

h2(k) = k^2 % table_size

dbl_hash = (h1 + (#_collisions + h2)) % table_size

### Insert
Insert will call the hash function to find the index to insert into, as well as handle collisions/calculating the new index.

### Access
The accessing function will call the hashing function and return the data stored at that spot. It will also need to re-calculate an index if it
        doesn't find the data in the case of the data having been stored somewhere else due to a collision. Finally it will need to handle missing entries.

The lecture slides have Java code outlining these functions. Use them for additional clarity if necessary.

Example:

**test_1.txt**
```
2893 11104 3732 12468 7688 14199 361 7115 8154 953
```

**./prog test_1.txt 0**

```
0: 11104
1: 0
2: 0
3: 0
4: 3732
5: 12468
6: 0
7: 14199
8: 7688
9: 361
10: 8154
11: 7115
12: 953
13: 2893
14: 0
15: 0
Total Collisions: 9
```

## 5. Submission
You will submit files `hash_table.h`, `hash_table.cpp`, and `main.cpp`
