package strategy;

public class HardStudy implements StudyStrategy {
    @Override
    public void study() {
        System.out.println("got 100 by hardStudy");
    }
}
