package arrays.questions;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class TripletSum {
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

        System.out.print("Enter K: ");
        int k = sc.nextInt();

        ArrayList<ArrayList<Integer>> tripletsWithSumK = findTriplets(array, n, k);
        System.out.println("Triplets with sum " + k + " are: " + tripletsWithSumK);

        sc.close();
    }

    public static ArrayList<ArrayList<Integer>> findTriplets(int[] arr, int n, int K) {

        Arrays.sort(arr);
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (i != 0 && arr[i] == arr[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum > K)
                    k--;
                else if (sum < K)
                    j++;
                else {
                    list.add(new ArrayList<>(Arrays.asList(arr[i], arr[j], arr[k])));
                    j++;
                    k--;
                    while (j < k && arr[j - 1] == arr[j])
                        j++;
                    while (j < k && arr[k + 1] == arr[k])
                        k--;
                }
            }
        }

        return list;
    }

}
