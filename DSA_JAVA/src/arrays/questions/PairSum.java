package arrays.questions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class PairSum {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter length of array : ");
        int n = sc.nextInt();

        int[] array = new int[n];
        System.out.println("Enter Array elements");
        for (int i = 0; i < n; i++) {
            System.out.print("array[" + i + "]: ");
            array[i] = sc.nextInt();
        }

        System.out.print("Enter s: ");
        int s = sc.nextInt();

        List<int[]> pairs = getPairsWithSum(array, s);
        System.out.print("Pairs: ");
        for (int[] pair : pairs) {
            System.out.print(Arrays.toString(pair) + " ");
        }

        sc.close();
    }

    public static List<int[]> getPairsWithSum(int[] arr, int s) {
        Arrays.sort(arr);
        List<int[]> pairs = new ArrayList<>();

        int i = 0;
        int j = arr.length - 1;
        int x;
        int y;
        int sum;

        while (i < j) {
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
                        pairs.add(new int[] { x, y });
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
                        pairs.add(new int[] { x, y });
                    }
                }
            }
        }

        return pairs;
    }
}