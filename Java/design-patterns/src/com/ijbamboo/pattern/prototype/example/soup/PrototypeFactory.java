package com.ijbamboo.pattern.prototype.example.soup;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午5:48:34
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