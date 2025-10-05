package arrays.questions;

import java.util.Scanner;

public class FindUniqueElement {
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

        System.out.println("Unique element : " + findUniqueNumber(array));

        sc.close();
    }

    public static int findUniqueNumber(int[] arr) {
        int unique = arr[0];
        for (int i = 1; i < arr.length; i++) {
            unique = unique ^ arr[i];
        }
        return unique;
    }
}