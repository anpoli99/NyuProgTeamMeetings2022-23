import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args) throws Exception{
        // A HashSet is a set that stores elements in no particular order.
        // It has O(1) time complexity for insertion, deletion, and search.
        
        HashSet<Integer> s = new HashSet<Integer>();
        s.add(1);
        s.add(2);
        s.add(3);
        s.add(4);
        s.add(5);

        System.out.println(s.contains(3)); // true
        System.out.println(s.contains(6)); // false

        s.add(6);
        s.remove(3);
        System.out.println(s.contains(3)); // false
        System.out.println(s.contains(6)); // true

        // A HashMap let's you associate a value with a key.
        // It has O(1) time complexity for insertion, deletion, and search.
        HashMap<String, Integer> m = new HashMap<String, Integer>();
        m.put("one", 1);
        m.put("two", 2);
        m.put("three", 3);
        System.out.println(m.get("one")); // 1
        System.out.println(m.containsKey("four")); // false
        System.out.println(m.get("four")); // null
        m.put("four", 4);
        System.out.println(m.containsKey("four")); // true
        System.out.println(m.get("four")); // 4

        // A TreeSet is a data structure that stores elements in sorted order.
        // It has O(log n) time complexity for insertion, deletion, and search.
        // It also allows for ceiling/floor operations in O(log n) time.

        TreeSet<Integer> s2 = new TreeSet<Integer>();
        s2.add(1);
        s2.add(5);
        s2.add(7);
        s2.add(9);
        s2.add(11);

        System.out.println(s2.contains(7)); // true
        System.out.println(s2.contains(8)); // false

        int ceil = s2.ceiling(7);
        System.out.println(ceil); // 7: ceiling is inclusive
        ceil = s2.ceiling(8);
        System.out.println(ceil); // 9
        int floor = s2.floor(8);
        System.out.println(floor); // 7: floor is inclusive

        Integer ceil2 = s2.ceiling(12);
        System.out.println(ceil2); // ceil/floor return null if out of bounds

        s2.add(1);
        s2.remove(1);
        System.out.println(s2.contains(1)); // false! sets are unique

        // Java doesn't natively support multisets
        // If we want a multiset in Java, we can use a map of Points
    }
}