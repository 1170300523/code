package temple;

public class BadStudent extends Student {
    BadStudent(String name) {
        super(name);
    }

    @Override
    void study() {
        System.out.println("study less");
    }

    @Override
    void eat() {
        System.out.println("eat well");
    }

    @Override
    void sleep() {
        System.out.println("sleep less");
    }

    @Override
    void play() {
        System.out.println("play more");
    }
}
