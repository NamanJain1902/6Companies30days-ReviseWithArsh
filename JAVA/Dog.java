public class Dog {

    String name;
    String breed;
    String color;
    int age;
    public Dog() {

    }
    public Dog(String _name, String _breed, String _color, int _age) {
        this.name = _name;
        this.breed = _breed;
        this.color = _color;
        this.age = _age;
    }

    // method 1
    public String getName()
    {
        return name;
    }
 
    // method 2
    public String getBreed()
    {
        return breed;
    }
 
    // method 3
    public int getAge()
    {
        return age;
    }
 
    // method 4
    public String getColor()
    {
        return color;
    }

    // @Override
    // public String toString() {
    //     return("Hi my name is "+ this.getName()+
    //     ".\nMy breed, age and color are " +
    //     this.getBreed()+"," + this.getAge()+
    //     ","+ this.getColor());
    // }

    public static void main(String[] args) {
        Dog moo = new Dog("moo", "m000o", "golden", 3);
        System.out.println(moo.toString());
        // System.out.println(&moo);
        Object object = new Dog();
        Object object2 = new Dog();
        System.out.println(object);
        System.out.println(object.getClass());
        System.out.println(object.hashCode());
        System.out.println(object.toString());
        System.out.println(object2.toString());
    }
}