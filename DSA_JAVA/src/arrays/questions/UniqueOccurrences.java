package arrays.questions;

import java.util.*;

public class UniqueOccurrences {
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

        boolean uniqueOccurrencePresent = isUniqueOccurrencePresent(array);
        System.out.println("Unique Occurrences Present: " + uniqueOccurrencePresent);

        sc.close();
    }

    public static boolean isUniqueOccurrencePresent(int[] arr) {

        Set<Integer> set = new HashSet<>();
        Arrays.sort(arr);

        int i = 0;
        int n = arr.length;

        while (i < n) {
            int x = arr[i];
            int count = 0;

            while (i < n && arr[i] == x) {
                count++;
                i++;
            }

            if (set.contains(count))
                return false;
            else
                set.add(count);
        }

        return true;
    }
}
