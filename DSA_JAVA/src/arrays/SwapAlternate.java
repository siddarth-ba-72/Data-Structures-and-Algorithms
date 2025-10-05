package arrays;

import java.util.Arrays;
import java.util.Scanner;

public class SwapAlternate {
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

        System.out.print("Before Swapping Alternates: ");
        System.out.println(Arrays.toString(array));

        swapAlternativeElements(array);

        System.out.print("After Swapping Alternates: ");
        System.out.println(Arrays.toString(array));

        sc.close();
    }

    public static void swapAlternativeElements(int[] array) {
        for (int i = 0; i + 1 < array.length; i += 2) {
            int temp = array[i + 1];
            array[i + 1] = array[i];
            array[i] = temp;
        }
    }
}