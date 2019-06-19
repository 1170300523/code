package animal;

import java.util.ArrayList;
import java.util.List;

public class Dog implements   Animal{
    static  void  bark(Animal animal){

    }

    static  void  bar(Dog dog){

    }
    public static void main(String[] args) {
        Dog dodo = new Dog();
        System.out.println(Dog.class);
        System.out.println(dodo.getClass());
        dodo.getClass();
        System.out.println("kkk".hashCode()+" "+ "kkk".hashCode());
        Integer a = Integer.valueOf(100);
        Integer b = Integer.valueOf(100);
        System.out.println(a == b);
        bark(dodo);
        List<? extends  Animal> animals = new ArrayList<Dog>();
    }
}
