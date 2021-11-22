# Binary Indexed Tree

[YT Tutorial](https://www.youtube.com/watch?v=v_wj_mOAlig)

## Intuition and History

(This is totally a personal analogy)

#### Prefix sum

The order of relativity is of the order n, i.e. **O(n)** in prefix sum.
This means that in the worst case if one of the element changes total of n elements would be affected.
This leads to O(n) complexity for update operation in prefix sum.

#### BIT

The order of relativity, in the BIT, is of the order log(n), i.e. **O(log(n))**.
This is done by relating elements on their binary representation and hence based on the powers of 2.
So, in the worst case, if an element is updated in the BIT at max only log(n) elements will be affected.

## Extra

```c++
int k = 3;  // 3 -> 00101
-k;         // -3 -> 11011 ==> 2's complement of 3
```

To get the RMSB( Right Most Significant Bit)
EG:

```c++
4 -> 0 1 0 0
     8 4 2 1

RMSB = 4;
```
