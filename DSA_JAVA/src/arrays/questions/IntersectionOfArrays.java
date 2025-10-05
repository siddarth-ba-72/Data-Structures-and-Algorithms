package arrays.questions;

import java.util.*;

public class IntersectionOfArrays {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter length of arr1 : ");
        int n = sc.nextInt();

        ArrayList<Integer> arr1 = new ArrayList<>();
        System.out.println("Enter Array elements");
        for (int i = 0; i < n; i++) {
            System.out.print("arr1[" + i + "]: ");
            int x = sc.nextInt();
            arr1.add(x);
        }

        System.out.print("Enter length of arr2 : ");
        int m = sc.nextInt();

        ArrayList<Integer> arr2 = new ArrayList<>();
        System.out.println("Enter Array elements");
        for (int i = 0; i < m; i++) {
            System.out.print("arr2[" + i + "]: ");
            int x = sc.nextInt();
            arr2.add(x);
        }

        Collections.sort(arr1);
        Collections.sort(arr2);

        List<Integer> intersection = intersectionArray(arr1, arr2);
        System.out.println("Intersection of arr1 and arr2: " + intersection);

        sc.close();
    }

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

}