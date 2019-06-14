package animal;

public class Dog {
    public static void main(String[] args) {
        Dog dodo = new Dog();
        System.out.println(Dog.class);
        System.out.println(dodo.getClass());
        dodo.getClass();
        System.out.println("kkk".hashCode()+" "+ "kkk".hashCode());
        Integer a = Integer.valueOf(100);
        Integer b = Integer.valueOf(100);
        System.out.println(a == b);

    }
}
