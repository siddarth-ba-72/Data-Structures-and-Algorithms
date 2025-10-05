
# 2. Binary and Decimal

## i. Reverse Integer
- https://leetcode.com/problems/reverse-integer/description/
```java
    public int reverse(int x) {
        int ans = 0;
        int n = Math.abs(x);

        while (n != 0) {
            int rem = n % 10;

            if ((ans > (Integer.MAX_VALUE / 10)) || (ans < (Integer.MIN_VALUE / 10))) {
                return 0;
            }

            ans = (ans * 10) + rem;
            n /= 10;
        }

        return (x < 0) ? -ans : ans;
    }
```

## ii. Complement of Base 10 Integer
- https://leetcode.com/problems/complement-of-base-10-integer/description/
```java
    public int bitwiseComplement(int n) {
        if (n == 0) {
            return 1;
        }

        int ans = 0;
        int i = 0;

        while (n != 0) {
            int bit = n & 1;
            if (bit == 0) {
                ans += (int) Math.pow(2, i);
            }
            n = n >> 1;
            i++;
        }

        return ans; 
    }
```

# 3. Arrays

## i. Find Unique Element
- https://www.naukri.com/code360/problems/find-unique_625159
```java
    public int findUniqueNumber(int[] arr) {
        int unique = arr[0];
        for (int i = 1; i < arr.length; i++) {
            unique = unique ^ arr[i];
        }
        return unique;
    }
```

## ii. Intersection of Arrays
- https://www.naukri.com/code360/problems/intersection-of-2-arrays_1082149
```java
    public static List<Integer> intersectionArray(List<Integer> arr1, List<Integer> arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int i = 0;
        int j = 0;
        ArrayList<Integer> intersection = new ArrayList<>();

        while (i < n && j < m) {
            if (arr1.get(i).equals(arr2.get(j))) {
                intersection.add(arr1.get(i));
                i++;
                j++;
            } else {
                if (arr1.get(i) < arr2.get(j)) {
                    i++;
                } else {
                    j++;
                }
            }
        }

        return !intersection.isEmpty() ? intersection : new ArrayList<>(List.of(-1));
    }
```

## iii. Pair Sum
- https://www.naukri.com/code360/problems/pair-sum_697295
```java
    public static List<int[]> getPairsWithSum(int[] arr, int s) {
        Arrays.sort(arr);
        List<int[]> pairs = new ArrayList<>();

        int i = 0;
        int j = arr.length - 1;
        int x;
        int y;
        int sum;

        while(i < j) {
            x = arr[i];
            y = arr[j];
            sum = (x + y);

            if (sum < s)
                i++;
            else if (sum > s)
                j--;
            else {
                if (x == y) {
                    int totalElements = j - i + 1;
                    int totalCombinations = (totalElements - 1) * totalElements / 2;
                    while (totalCombinations-- > 0) {
                        pairs.add(new int[]{x, y});
                    }
                    break;
                } else {
                    int totalFirstElem = 1;
                    int totalSecondElem = 1;
                    while (arr[++i] == x)
                        totalFirstElem++;
                    while (arr[--j] == y)
                        totalSecondElem++;
                    int totalCombinations = totalFirstElem * totalSecondElem;
                    while (totalCombinations-- > 0) {
                        pairs.add(new int[]{x, y});
                    }
                }
            }
        }

        return pairs;
    }
```