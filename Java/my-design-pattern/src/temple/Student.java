package temple;

import strategy.HardStudy;
import strategy.LazyStudy;
import strategy.StudyStrategy;

public abstract class Student {
    String name;
    int score;
    Student(String name){
        this.name = name;
    }

    abstract  void  study();
    abstract  void  eat();
    abstract  void  sleep();
    abstract  void  play();

    void inSchool(){
        System.out.println(name+ "'s life in school:");
        study();
        eat();
        sleep();
        play();
    }

    public static void main(String[] args) {
        Student tom = new GoodStudent("tom");
        Student dodo = new BadStudent("dodo");
        tom.inSchool();
        dodo.inSchool();
    }
}
