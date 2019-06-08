package com.ijbamboo.pattern.prototype.example.soup;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午5:52:14
 */
public class TestPrototype{ 
	   public static void main(String[] args) {
	       System.out.println(
	         "Creating a Prototype Factory with " + 
	         " a SoupSpoon and a SaladFork");
	       PrototypeFactory prototypeFactory = 
	         new PrototypeFactory(new SoupSpoon(), new SaladFork());
	       AbstractSpoon spoon = 
	         prototypeFactory.makeSpoon();
	       AbstractFork fork = 
	         prototypeFactory.makeFork();
	       System.out.println("Getting the Spoon and Fork name:");
	       System.out.println("Spoon: " + spoon.getSpoonName() + 
	                          ", Fork: " + fork.getForkName());
	       System.out.println(" ");       
	       System.out.println("Creating a Prototype Factory " + 
	                          "with a SaladSpoon and a SaladFork");
	       prototypeFactory = 
	         new PrototypeFactory(new SaladSpoon(), new SaladFork());
	       spoon = prototypeFactory.makeSpoon();
	       fork = prototypeFactory.makeFork();
	       System.out.println("Getting the Spoon and Fork name:");
	       System.out.println("Spoon: " + spoon.getSpoonName() + 
	                          ", Fork: " + fork.getForkName());
	    }
	}