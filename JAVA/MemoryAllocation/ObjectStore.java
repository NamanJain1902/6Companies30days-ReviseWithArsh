class ObjectStore {

    /*
     * There are two ways to create an object  of string in java:
     * 
     * 1. By String Literal
     * 2. By new Keyword
     */


    public static void main(String[] args) {
        String s1 = "Memory Alocated once";
        String s2 = "Memory Alocated once";
    
        System.out.println(s1);
        System.out.println(s2);

        if(s1.equals(s2)) {
            if(s1.hashCode() == s2.hashCode()) {
                System.out.println(s1 + " == " + s2);
            }
        } else {
            System.out.println(s1 + " != " + s2);
        }

        System.out.println(s1.hashCode());
        System.out.println(s2.hashCode());

        Object myVar = s1.hashCode();
        System.out.println(myVar.getClass().getName());
    }
}