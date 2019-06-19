package strategy;

public class LazyStudy implements  StudyStrategy {
    @Override
    public void study() {
        System.out.println("got 59 by lazyStudy");
    }
}
