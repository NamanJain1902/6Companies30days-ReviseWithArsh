// classic implementation
class Singleton {
    private static Singleton obj;

    // private constructor to force use of 
    // getInstance() to create Singleton object
    private Singleton() {};
    /*
     * Here we have declared getInstance() static 
     * so that we can call it without instantiating the class. 
     * The first time getInstance() is called it creates a 
     * new singleton object and after that it just returns 
     * the same object. Note that Singleton obj is not created 
     * until we need it and call getInstance() method. 
     * This is called "lazy instantiation".
     */
    public static Singleton getInstance_notThreadSafe() {
        if(obj == null) {
            obj = new Singleton();
        }
        return obj;
    }

    /*
     * Here hsing synchronized makes sure that only one thread
     * at a time can execute getInstance(). The main disadvantage
     * of this method is that using synchronized every time while 
     * creating the singleton object is expensive and may decrease 
     * the performance of your program. 
     */
    public static synchronized Singleton getInstance_ThreadSafe() {
        if(obj == null) {
            obj = new Singleton();
        }
        return obj;
    }


}

// make getInstance() synchronized


class Eager_Instantiation_Singleton
{
    private static Eager_Instantiation_Singleton obj = new Eager_Instantiation_Singleton();
 
    private Eager_Instantiation_Singleton() {}
 
    public static Eager_Instantiation_Singleton getInstance()
    {
        return obj;
    }
}


// double checked locking
class Singleton_DoubleCheckedLocking {
    /*
     * We have declared the obj volatile which ensures that 
     * multiple threads offer the obj variable correctly when 
     * it is being initialized to Singleton instance. This method
     * drastically reduces the overhead of calling the synchronized
     * method every time.
    */
    private static volatile Singleton_DoubleCheckedLocking obj = null;

    private Singleton_DoubleCheckedLocking() {}

    public static Singleton_DoubleCheckedLocking getInstance() {
        if(obj == null) {
            synchronized (Singleton_DoubleCheckedLocking.class) 
            {
                if(obj == null) {
                    obj = new Singleton_DoubleCheckedLocking();
                }
            }
        }
        return obj;
    }
}
