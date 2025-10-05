package arrays.questions;

import java.util.Scanner;

public class FindDuplicateInAnArray {
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

        System.out.println("Duplicate element from 1 to N : " + findDuplicateFrom1ToN(array));

        sc.close();
    }

    public static int findDuplicateFrom1ToN(int[] arr) {
        int duplicate = 0;

        for (int j : arr) {
            duplicate = duplicate ^ j;
        }

        for (int i = 0; i < arr.length; i++) {
            duplicate = duplicate ^ i;
        }

        return duplicate;
    }
}