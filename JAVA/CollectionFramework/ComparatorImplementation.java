import java.util.Arrays;
import java.util.Collections;
import java.util.*;


class Student {
	int rollno;
	String name, address;

	// Constructor
	public Student(int rollno, String name, String address)
	{
		// This keyword refers to current object itself
		this.rollno = rollno;
		this.name = name;
		this.address = address;
	}

	// Used to print student details in main()
	public String toString()
	{
		return this.rollno + " " + this.name + " "
			+ this.address;
	}
}

class SortByAddress implements Comparator<Student> {
    
    @Override
    public int compare(Student a, Student b)
	{
		// return a.address < b.address;
      for(int i=0; i<a.address.length() && i<b.address.length(); ++i) {
        	if((int)a.address.charAt(i) == (int)b.address.charAt(i)) {
            	continue;
            } else {
              return (int)a.address.charAt(i) - (int)b.address.charAt(i);
            }
        }
      	
      	if(a.address.length() < b.address.length()){ 
        	return a.address.length() - b.address.length();
        } else if(a.address.length() > b.address.length()) {
       	 	return a.address.length() - b.address.length();
        } else {
          	return 0;
        }
	}
}

class ComparatorImplementation {
    public static void main(String[] args) {
        Integer[] nums = {1,7,8,2,9,3,4,5,6};

        System.out.println(Arrays.toString(nums));
        System.out.println();
        Arrays.sort(nums);
        System.out.println(Arrays.toString(nums));
        System.out.println();
        Arrays.sort(nums, Collections.reverseOrder());
        System.out.println(Arrays.toString(nums));


        Student[] arr
			= { new Student(111, "bbbb", "london"),
				new Student(131, "aaaa", "nyc"),
				new Student(121, "cccc", "jaipur") };

		System.out.println("Unsorted");

		for (int i = 0; i < arr.length; i++)
			System.out.println(arr[i]);

		// Sorting on basic as per class 1 created
		// (user-defined)
		Arrays.sort(arr, new SortByAddress());

		System.out.println("\nSorted by address\n");

		for (int i = 0; i < arr.length; i++)
			System.out.println(arr[i]);
    }
}