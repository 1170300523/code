package temple;

public class GoodStudent extends Student {
    GoodStudent(String name) {
        super(name);
    }

    @Override
    void study() {
        System.out.println("study well");
    }

    @Override
    void eat() {
        System.out.println("eat well");
    }

    @Override
    void sleep() {
        System.out.println("sleep well");
    }

    @Override
    void play() {
        System.out.println("play well");
    }
}
