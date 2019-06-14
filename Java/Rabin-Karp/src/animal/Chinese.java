package animal;

public class Chinese extends Person{
    @Override
    public void speak() {
        System.out.println("Chinese speak");
    }

    public static void main(String[] args) {
        Person dodo = new Chinese();
        dodo.speak();
    }
}
