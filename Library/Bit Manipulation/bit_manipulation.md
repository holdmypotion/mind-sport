# Bit Manipulation

## Even or odd

```c++
if (x & 1) -> odd otherwise even
```

```c++
if (x & (2^k - 1)) -> x is completely divisible by 2^k otherwise not
	// 16 -> 10000
	// 8  -> 01000
```

```c++
	int	x = 16;
	// => -x = ~x + 1 => 2's Complement
	cout << x << " " << ~x + 1 << ln;
```

```c++
for (int i = 18; ~i; i--)  ==> for(int i = 18; i >= 0; i--)
reason:
as ~i = -i - 1 and this for loop runs 19 times as it goes from
-19 to -1;
```

Note that x << k corresponds to multiplying x by 2k, and x >> k corresponds
to dividing x by 2k rounded down to an integer.

```c++
14 << 2 = 56 // -> 14 * 2^2
49 >> 3 = 6  // -> 49 / 2^3
```

### Printing binary representation

```c++
for (int i = 31; ~i; i--) {
	if (x&(1<<i)) cout << "1";
	else cout << "0";
}
```

### Settings bits

- x | (1 << k) sets the kth bit of x to one
- x & ~(1 << k) sets the kth bit of x to zero
- x ^ (1 << k) inverts the kth bit of x
- x & (x−1) sets the last one bit of x to zero
- x & −x sets all the one bits to zero, except for the last one bit
- x | (x−1) inverts all the bits after the last one bit
- x is a power of two exactly when x & (x−1) = 0.

```c++
// 8 -> 1000
// 7 -> 0111
// & -> 0000
Hence, 8 is a power of 2
```

### C++ functions

```c++
int x = 5328; // 00000000000000000001010011010000
cout << __builtin_clz(x) << "\n"; // 19
cout << __builtin_ctz(x) << "\n"; // 4
cout << __builtin_popcount(x) << "\n"; // 5
cout << __builtin_parity(x) << "\n"; // 1
```

### Set implementation

```c++
int x = 0;
x |= (1<<1);
x |= (1<<3);
x |= (1<<4);
x |= (1<<8);
cout << __builtin_popcount(x) << "\n"; // 4
//  No. of elements in the set == 4

// Then, the following code prints all elements that belong to the set:
for (int i = 0; i < 32; i++) {
	if (x&(1<<i)) cout << i << " ";
}
// output: 1 3 4 8



// Example of set union using binary
int x = (1<<1)|(1<<3)|(1<<4)|(1<<8);
int y = (1<<3)|(1<<6)|(1<<8)|(1<<9);
int z = x|y;
cout << __builtin_popcount(z) << "\n"; // 6
```

## Optimizations using Bit

### Hamming Distance

The Hamming distance hamming(a,b) between two bit strings a and b of equal
length is the number of positions where the strings differ.

Examples

- hamming(01101,11001) = 2
- hamming(00111,01101) = 2,
- hamming(00111,11110) = 3
- hamming(01101,11110) = 3

Naive

```c++
int hamming(string a, string b) {
	int d = 0;
	for (int i = 0; i < k; i++) {
		if (a[i] != b[i]) d++;
	}
	return d;
}
```

Optimized Using bit operations
**only possible if k <= 32**

```c++
int hamming(int a, int b) {
	return __builtin_popcount(a^b);
}

// In the above function, the xor operation constructs a bit string that has one bits
// in positions where a and b differ. Then, the number of bits is calculated using
// the __builtin_popcount function
```

To compare the implementations, we generated a list of 10000 random bit
strings of length 30. Using the first approach, the search took 13.5 seconds, and
after the bit optimization, it only took 0.5 seconds. Thus, the bit optimized code
was almost 30 times faster than the original code.

## Dynamic Programming

Bit operations provide an efficient and convenient way to implement dynamic
programming algorithms whose states contain subsets of elements, because such
states can be stored as integers
