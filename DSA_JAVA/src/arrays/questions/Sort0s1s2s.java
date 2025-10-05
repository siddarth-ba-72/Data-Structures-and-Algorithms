package arrays.questions;

import java.util.Arrays;
import java.util.Scanner;

public class Sort0s1s2s {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter length: ");
        int n = sc.nextInt();

        int[] array = new int[n];
        System.out.println("Enter Array elements");
        for (int i = 0; i < n; i++) {
            System.out.print("array[" + i + "]: ");
            array[i] = sc.nextInt();
        }

        System.out.print("Before Sorting 0s, 1s and 2s : ");
        System.out.println(Arrays.toString(array));

        sortZerosOnesAndTwos(array);

        System.out.print("After Sorting 0s, 1s and 2s : ");
        System.out.println(Arrays.toString(array));

        sc.close();
    }

    public static void sortZerosOnesAndTwos(int[] arr) {
        int i = 0;
        int j = 0;
        int k = arr.length - 1;

        while (j <= k) {
            if (arr[j] == 0) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j++;
            } else if (arr[j] == 2) {
                int temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
                k--;
            } else
                j++;
        }
    }

}
