package com.ijbamboo.pattern.prototype.example.soup;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����5:48:34
 */
public class PrototypeFactory {  
    AbstractSpoon prototypeSpoon;
    AbstractFork prototypeFork;
    
    public PrototypeFactory(AbstractSpoon spoon, AbstractFork fork) {
       prototypeSpoon = spoon;
       prototypeFork = fork;
   }
    
   public AbstractSpoon makeSpoon() {
       return (AbstractSpoon)prototypeSpoon.clone();
   }
   public AbstractFork makeFork() {
       return (AbstractFork)prototypeFork.clone();
   }
}