# 1 奇诺之旅(journey)
### 1 Description

奇诺在旅途中经过了许许多多的国家，其中某些国家之间准备修建道路，而道路将增加这两个国家之间的友好度。由于资金问题，每个国家最多只能修建与自身相连的一条道路。这些国家希望所有好感度的和最大，并请求见多识广的奇诺为他们提供建造方案。但这些国家都是很善变的，有些时候两个国家会断绝互相的友好关系，这时在这两个国家之间修建道路不会带来友好度。他们希望这种事件发生时可以快速得到此时的最大好感度之和。

奇诺并不愿意搀和这件事，于是把它留给了下一个到访的旅行者——号称“超高校级的算法之神”的你。

### 2 Input Format

第一行两个整数n;m，分别表示国家数目和关系数目。
接下来m 行，每行三个整数x,y,w,表示开始时若在x和y国家间修建道路将带来w 的好感度。

### 3 Output Format
输出m行，第i行一个整数表示若第i组友好关系断绝，所有国家的好感度之和最多是多少。

**注意** “断绝关系”只是假设的情况，它们不会互相影响。

### 4 Sample
#### 4.1 Input
```
6 8
1 2 6
1 3 5
3 4 2
2 3 4
4 5 3
6 4 3
5 6 4
2 4 2
```

#### 4.2 Output
```
21
22
25
23
24
24
23
25
```

### 5 Constraints
对于20% 的数据，n,m <= 20。
对于40% 的数据，n,m <= 200。
对于60% 的数据，n,m <= 5000。
对于100% 的数据，2 <= n,m <= 200000, 1 <= w <= 10^9，x != y，且保证同一对友好关系不会被重复描述。