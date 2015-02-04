/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted
arrays. The overall run time complexity should be O (log ( m + n ))
*/

/*
更通用的形式是，给定两个已经排序好的数组，找到两者所有元素中第 k 大的元素。

O ( m + n ) 的解法比较直观，直接 merge 两个数组，然后求第 k 大的元素。
可以用一个计数器，记录当前已经找到第 m 大的元素了。同时我们使用两个指针 pA 和 pB，分别指向 A 和 B 数组的第一个元素，使用类似于 merge sort 的原理，如果数组 A 当前元素小，那么 pA++，同时 m++；如果数组 B 当前元素小，那么 pB++，同时 m++。最终当 m 等于 k 的时候，就得到了我们的答案， O ( k ) 时间， O (1) 空间。但是，当 k 很接近 m + n 的时候，这个方法还是 O ( m + n ) 的。

有没有更好的方案呢？我们可以考虑从 k 入手。
如果我们每次都能够删除一个一定在第 k 大元素之前的元素，那么我们需要进行 k 次。但是如果每次我们都删除一半呢？由于 A 和 B 都是有序的，我们应该充分利用这里面的信息，类似于二分查找，也是充分利用了“有序”。
假设 A 和 B 的元素个数都大于 k /2，我们将 A 的第 k /2 个元素（即 A[k/2-1] ）和 B 的第 k /2个元素（即 B[k/2-1] ）进行比较，有以下三种情况（为了简化这里先假设 k 为偶数，所得到的结论
对于 k 是奇数也是成立的）：
• A[k/2-1] == B[k/2-1]
• A[k/2-1] > B[k/2-1]
• A[k/2-1] < B[k/2-1]

如果 A[k/2-1] < B[k/2-1] ，意味着 A[0] 到 A[k/2-1] 的肯定在 A ∪ B 的 top k 元素的范围内，换句话说， A[k/2-1] 不可能大于 A ∪ B 的第 k 大元素。
因此，我们可以放心的删除 A 数组的这 k /2 个元素。
同理，当 A[k/2-1] > B[k/2-1] 时，可以删除 B 数组的 k /2 个元素。

当 A[k/2-1] == B[k/2-1] 时，说明找到了第 k 大的元素，直接返回 A[k/2-1] 或 B[k/2-1]即可。

因此，我们可以写一个递归函数。那么函数什么时候应该终止呢？
• 当 A 或 B 是空时，直接返回 B[k-1] 或 A[k-1] ；
• 当 k=1 是，返回 min(A[0], B[0]) ；
• 当 A[k/2-1] == B[k/2-1] 时，返回 A[k/2-1] 或 B[k/2-1]
*/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total % 2 != 0) {
            return findKth(A, m, B, n, total / 2 + 1);
        } else {
            return (findKth(A, m, B, n, total / 2) + findKth(A, m, B, n, total / 2 + 1)) / 2.0;
        }
     }
 private:
    double findKth(int *A, int m, int *B, int n, int k) {
        if (m > n) {
            return findKth(B, n, A, m, k);
        }
        if (m == 0) {
            return B[k - 1];
        }
        if (k == 1) {
            return min(A[0], B[0]);
        }
        int ia = min(k / 2, m), ib = k - ia;
        if (A[ia - 1] == B[ib - 1]) {
            return A[ia - 1];
        } else if (A[ia - 1] < B[ib - 1]) {
            return findKth(A + ia, m - ia, B, n, k - ia);
        } else {
            return findKth(A, m, B + ib, n - ib, k - ib);
        }
    }
};
