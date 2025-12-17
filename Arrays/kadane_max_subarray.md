## Maximum Subarray Sum (Kadane's Algorithm)

**Idea:**  
Negative sum reduces future contribution, so reset.

**Steps:**
- Iterate through array
- Add to current sum
- Reset when negative

**Complexity:**
- Time: O(n)
- Space: O(1)
