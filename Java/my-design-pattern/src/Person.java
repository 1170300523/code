import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Person implements Comparable<Person>{

    int age;
    String name;

    Person(String name, int age){
        this.age = age;
        this.name = name;
    }
    @Override
    public int compareTo(Person o) {
        return this.age - o.age;
    }

    public static void main(String[] args) {
        List<Person> list = new ArrayList<>();
        list.add(new Person("kk",39));
        list.add(new Person("ee",9));
        list.add(new Person("gg",93));
        list.add(new Person("ff",19));

        Comparator<Person> comparator = new Comparator<Person>() {
            @Override
            public int compare(Person o1, Person o2) {
                return o1.name.toLowerCase().compareTo(o2.name.toLowerCase());
            }
        };

        Collections.sort(list,comparator);
        for(Person i :list){
            System.out.println(i.name);
        }


    }
}
