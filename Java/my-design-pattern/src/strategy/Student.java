package strategy;

public class Student {
    String name;
    StudyStrategy studyStrategy = null;
    int score;

    Student(String name){
        this.name = name;
    }

    public void setStudyStrategy(StudyStrategy studyStrategy) {
        this.studyStrategy = studyStrategy;
    }

    void  exam(){
        System.out.print(name+" ");
        studyStrategy.study();
    }

    public static void main(String[] args) {
        Student tom = new Student("tom");

        tom.setStudyStrategy(new HardStudy());
        tom.exam();

        tom.setStudyStrategy(new LazyStudy());
        tom.exam();
    }

}
