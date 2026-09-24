# 3550. Smallest Index With Digit Sum Equal to Index

**Difficulty:** `Easy` | **Topics:** `Array`, `Math` | [LeetCode Problem](https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/)

---

### Problem Description

You are given an integer array `nums`.

Return the **smallest** index `i` such that the sum of the digits of `nums[i]` is equal to `i`.

If no such index exists, return `-1`.

 

<strong class="example">Example 1:</strong>

<div class="example-block">

**Input:** <span class="example-io">nums = [1,3,2]</span>

**Output:** <span class="example-io">2</span>

**Explanation:**

	- For `nums[2] = 2`, the sum of digits is 2, which is equal to index `i = 2`. Thus, the output is 2.

</div>

<strong class="example">Example 2:</strong>

<div class="example-block">

**Input:** <span class="example-io">nums = [1,10,11]</span>

**Output:** <span class="example-io">1</span>

**Explanation:**

	- For `nums[1] = 10`, the sum of digits is `1 + 0 = 1`, which is equal to index `i = 1`.

	- For `nums[2] = 11`, the sum of digits is `1 + 1 = 2`, which is equal to index `i = 2`.

	- Since index 1 is the smallest, the output is 1.

</div>

<strong class="example">Example 3:</strong>

<div class="example-block">

**Input:** <span class="example-io">nums = [1,2,3]</span>

**Output:** <span class="example-io">-1</span>

**Explanation:**

	- Since no index satisfies the condition, the output is -1.

</div>

 

**Constraints:**

	- `1 <= nums.length <= 100`

	- `0 <= nums[i] <= 1000`

---

## 🧠 Logic & Approach Breakdown

### 💡 Approach & Intuition

**Detected Pattern:** `Optimized Single-Pass Traversal`

Processes elements sequentially in a single pass while tracking required state, avoiding redundant nested re-evaluations.

#### 🚫 Why Not Brute Force?
Nested iterations re-checking previously processed states take O(n²) time.

Single-pass execution processes each element in linear O(n) time, scaling cleanly up to large constraints.

#### ⭐️ Key Points
- **Process inputs in a single forward iteration.**
- **Maintain running state dynamically to make immediate decisions.**
- **Early exit as soon as target condition is satisfied.**

---

### 🧪 Step-by-Step Visual Dry Run

**Sample Input:** `Sample testcase`

#### Step 1:
- **State:** `Initial state`
- **Action:** Process element, update state, and check condition.

🎉 **Result:** `Target condition reached.`

---

### ⏱️ Complexity Analysis
- **Time Complexity:** `O(n)` — Single linear pass over the input of size n.
- **Space Complexity:** `O(1)` — Requires minimal auxiliary variables.

---

### 📝 Summary
An optimal linear time approach that processes each element sequentially with minimal memory overhead.


---

*Synced automatically by [CodeCrus](https://github.com/Krishnadev_sharma)*
