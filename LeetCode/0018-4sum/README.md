# 18. 4Sum

**Difficulty:** `Medium` | **Topics:** `Array`, `Two Pointers`, `Sorting` | [LeetCode Problem](https://leetcode.com/problems/4sum/)

---

### Problem Description

Given an array `nums` of `n` integers, return *an array of all the **unique** quadruplets* `[nums[a], nums[b], nums[c], nums[d]]` such that:

	- `0 <= a, b, c, d < n`

	- `a`, `b`, `c`, and `d` are **distinct**.

	- `nums[a] + nums[b] + nums[c] + nums[d] == target`

You may return the answer in **any order**.

 

<strong class="example">Example 1:</strong>

```

**Input:** nums = [1,0,-1,0,-2,2], target = 0
**Output:** [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

```

<strong class="example">Example 2:</strong>

```

**Input:** nums = [2,2,2,2,2], target = 8
**Output:** [[2,2,2,2]]

```

 

**Constraints:**

	- `1 <= nums.length <= 200`

	- `-10<sup>9</sup> <= nums[i] <= 10<sup>9</sup>`

	- `-10<sup>9</sup> <= target <= 10<sup>9</sup>`

---

## 🧠 Logic & Approach Breakdown

### 💡 Approach & Intuition

**Detected Pattern:** `One-Pass Hash Map (Complement Lookup)`

Instead of checking every pair with nested loops, we store each visited number and its index in a hash map. For every number, we check in O(1) time if its target complement already exists.

#### 🚫 Why Not Brute Force?
If you check all possible pairs, we need two nested loops which is O(n²).

```text
Input: nums = [2, 7, 11, 15], target = 9
All possible pairs are:
[2,2]  [2,7]  [2,11]  [2,15]  = 4
[7,2]  [7,7]  [7,11]  [7,15]  = 4
[11,2] [11,7] [11,11] [11,15] = 4
[15,2] [15,7] [15,11] [15,15] = 4
Total: 16 pairs (4²)
```

Looping 16 times is manageable. But what if we have 10,000 numbers in the array? Looping 100,000,000 times will result in Time Limit Exceeded (TLE). Improving to O(n) ensures at most 10,000 operations.

#### ⭐️ Key Points
- **Use extra memory (Hash Map) to trade space for O(1) average lookup time.**
- **Keep numbers (elements) as keys and their index numbers as values.**
- **For current number x, complement needed to form target is target - x.**

---

### 🧪 Step-by-Step Visual Dry Run

**Sample Input:** `nums = [2, 7, 11, 15], target = 9`

Let's iterate through the array element-by-element using our hash map.

#### Step 1:
```text
[2, 7, 11, 15], target = 9
 ↑
```
- **State:** `pair_idx = {}`
- **Action:** Current number is 2. Need 9 - 2 = 7. 7 is not in pair_idx. Add { 2: 0 }.

#### Step 2:
```text
[2, 7, 11, 15], target = 9
    ↑
```
- **State:** `pair_idx = { 2: 0 }`
- **Action:** Current number is 7. Need 9 - 7 = 2. Check if 2 is in pair_idx. Found at index 0!

🎉 **Result:** `return [0, 1]`

---

### ⏱️ Complexity Analysis
- **Time Complexity:** `O(n)` — n is the number of elements in the array. We traverse the array only once, and hash map lookups take O(1) time on average.
- **Space Complexity:** `O(n)` — In the worst case, the hash map stores up to n elements if the matching pair is at the end.

---

### 📋 Step-by-Step Algorithm (Code Walkthrough)

#### 1. Initializing the Hash Map
```c++
unordered_map<int, int> pairIdx;
```
We initialize an empty hash table/dictionary to store visited numbers as keys and their indices as values.

#### 2. Iterating Through the Array
```c++
for (int i = 0; i < nums.size(); ++i)
```
We iterate through the array element by element, accessing both the value and its index.

#### 3. Checking for Complementary Pair
```c++
if (pairIdx.find(target - nums[i]) != pairIdx.end()) {
    return {pairIdx[target - nums[i]], i};
}
```
We check if the required complement (target - current_number) already exists in our hash map. If found, we return the pair of indices immediately.

#### 4. Storing Visited Number & Index
```c++
pairIdx[nums[i]] = i;
```
If no complementary match was found, we save the current number and its index in our map so later elements can find it.

---

### 📝 Summary
This algorithm efficiently replaces the naive O(n²) pairwise search with a single O(n) pass by utilizing a hash map for O(1) complement lookups, achieving optimal runtime.


---

*Synced automatically by [CodeCrus](https://github.com/Krishnadev_sharma)*
