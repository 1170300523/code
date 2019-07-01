import java.awt.*;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.*;
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



    static void exceptionTest() throws  MyException{
       throw  new MyException("kkk");
    }

    public static void main(String[] args)  {


        try {
            exceptionTest();
        } catch (MyException e) {
            System.out.println("重新输入"+e.getMessage());
        }


    }
}
