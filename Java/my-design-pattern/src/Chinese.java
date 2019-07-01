import java.util.*;

public class Chinese extends  Thread{
    String name;
    static int countryAge ;
    final  int k = 8;

    public  void  run(){
        testA();

    }


    Chinese(String name){
        this.name = name;
    }

    static void testA(){
        for (int i = 0; i < 10; i++) {
            System.out.println(i);
        }
    }

    void testB(){
        System.out.println("testB");
    }



    public static void main(String[] args) {


    Chinese t = new Chinese("kk");

    t.start();
    t.testA();

        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }


}
