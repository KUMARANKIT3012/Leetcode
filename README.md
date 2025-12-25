# 🚀 LeetCode & DSA Solutions Repository

<div align="center">

![LeetCode](https://img.shields.io/badge/LeetCode-Solutions-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)
![Language](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Problems Solved](https://img.shields.io/badge/Problems-500+-success?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge)

**A comprehensive collection of Data Structures & Algorithms solutions**

[View Problems](#-problem-categories) • [Features](#-features) • [Getting Started](#-getting-started)

</div>

---

## 📋 Table of Contents

- [About](#-about)
- [Problem Categories](#-problem-categories)
- [Features](#-features)
- [Getting Started](#-getting-started)
- [Repository Structure](#-repository-structure)
- [Usage](#-usage)
- [Contributing](#-contributing)
- [License](#-license)

---

## 🎯 About

This repository contains my solutions to various **LeetCode**, **GeeksforGeeks**, and other competitive programming problems. Each solution is implemented in **C++** with clean, optimized code and comprehensive comments explaining the approach and complexity analysis.

### 🌟 Key Highlights

- ✅ **500+ Problems Solved** across multiple difficulty levels
- ✅ **Clean & Optimized Code** with detailed comments
- ✅ **Multiple Approaches** for complex problems
- ✅ **Time & Space Complexity** analysis
- ✅ **Regular Updates** with new problems and solutions

---

## 📚 Problem Categories

### 🔢 Arrays & Strings
- Two Sum, 3Sum, 4Sum
- Longest Substring Without Repeating Characters
- Container With Most Water
- Trapping Rain Water
- Product of Array Except Self
- And many more...

### 🔗 Linked Lists
- Reverse Linked List
- Detect & Remove Cycle
- Merge K Sorted Lists
- Copy List with Random Pointer
- Palindrome Linked List
- Flatten a Linked List

### 🌳 Trees & Graphs
- Binary Tree Traversals (Inorder, Preorder, Postorder)
- Lowest Common Ancestor
- Serialize & Deserialize Binary Tree
- Graph BFS & DFS
- Topological Sort
- Dijkstra's Algorithm
- Minimum Spanning Tree

### 🔍 Binary Search
- Binary Search variations
- Search in Rotated Sorted Array
- Find Peak Element
- Median of Two Sorted Arrays
- Kth Smallest Element

### 💡 Dynamic Programming
- Fibonacci Numbers
- Longest Common Subsequence
- Knapsack Problem
- Coin Change
- Longest Increasing Subsequence
- Matrix Chain Multiplication

### 🎯 Greedy Algorithms
- Jump Game
- Candy Distribution
- Job Sequencing Problem
- Fractional Knapsack
- N Meetings in One Room

### 📊 Stacks & Queues
- Valid Parentheses
- Next Greater Element
- Largest Rectangle in Histogram
- LRU Cache
- Min Stack

### 🔐 Backtracking
- N-Queens Problem
- Sudoku Solver
- Permutations & Combinations
- Rat in a Maze
- Word Search

### 🎲 Bit Manipulation
- Single Number
- Power of Two
- XOR Operations
- Count Set Bits

---

## ✨ Features

### 📝 Code Quality
- **Clean Code**: Easy to read and understand
- **Detailed Comments**: Explaining the logic and approach
- **Multiple Solutions**: Different approaches for the same problem
- **Edge Cases**: Handling all possible scenarios

### 📈 Complexity Analysis
Each solution includes:
- ⏱️ **Time Complexity** analysis
- 💾 **Space Complexity** analysis
- 🚀 **Optimization** notes

### 🎓 Learning Resources
- Problem-solving patterns
- Algorithm explanations
- Data structure implementations
- Best practices in C++

---

## 🚀 Getting Started

### Prerequisites
- C++ Compiler (GCC 7.0+ or Clang 5.0+)
- Basic knowledge of Data Structures & Algorithms

### Installation

1. **Clone the repository**
```bash
git clone https://github.com/KUMARANKIT3012/Leetcode.git
cd Leetcode
```

2. **Compile a solution**
```bash
g++ -std=c++17 "Problem Name.cpp" -o solution
```

3. **Run the executable**
```bash
./solution
```

---

## 📁 Repository Structure

```
Leetcode/
│
├── Arrays/
│   ├── Two Sum.cpp
│   ├── 3Sum.cpp
│   └── ...
│
├── Linked Lists/
│   ├── Reverse Linked List.cpp
│   ├── Merge Two Sorted Lists.cpp
│   └── ...
│
├── Trees/
│   ├── Binary Tree Inorder Traversal.cpp
│   ├── Lowest Common Ancestor.cpp
│   └── ...
│
├── Dynamic Programming/
│   ├── Climbing Stairs.cpp
│   ├── Coin Change.cpp
│   └── ...
│
└── README.md
```

---

## 💻 Usage

### Example: Two Sum Problem

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
```

---

## 🤝 Contributing

Contributions are welcome! If you'd like to contribute:

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

---

## 📊 Problem Statistics

| Category | Problems Solved |
|----------|----------------|
| Arrays | 80+ |
| Linked Lists | 40+ |
| Trees & Graphs | 100+ |
| Dynamic Programming | 60+ |
| Binary Search | 30+ |
| Greedy | 25+ |
| Stacks & Queues | 35+ |
| Backtracking | 20+ |
| Others | 110+ |

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🙏 Acknowledgments

- [LeetCode](https://leetcode.com) for the amazing problem set
- [GeeksforGeeks](https://www.geeksforgeeks.org) for additional problems
- The programming community for inspiration and support

---

## 📞 Contact

**Ankit Kumar**

[![GitHub](https://img.shields.io/badge/GitHub-KUMARANKIT3012-181717?style=for-the-badge&logo=github)](https://github.com/KUMARANKIT3012)
[![LeetCode](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode)](https://leetcode.com)

---

<div align="center">

### ⭐ Star this repository if you find it helpful!

**Happy Coding! 🚀**

</div>