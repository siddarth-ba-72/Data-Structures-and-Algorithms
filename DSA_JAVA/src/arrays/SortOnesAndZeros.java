package arrays;

import java.util.Arrays;
import java.util.Scanner;

public class SortOnesAndZeros {
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

        System.out.print("Before Sorting 0s and 1s : ");
        System.out.println(Arrays.toString(array));

        sortOnesAndZerosInArray(array);

        System.out.print("After Sorting 0s and 1s : ");
        System.out.println(Arrays.toString(array));

        sc.close();
    }

    public static void sortOnesAndZerosInArray(int[] array) {
        int i = 0;
        int j = array.length - 1;

        while (i < j) {
            if (array[i] == 1 && array[j] == 0) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
            }
            while (array[i] == 0)
                i++;
            while (array[j] == 1)
                j--;
        }
    }

}
