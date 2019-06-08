package com.ijbamboo.pattern.composite.example.tea;

import java.util.LinkedList;
import java.util.ListIterator;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午8:53:19
 */
public  abstract class TeaBags {  
	   LinkedList teaBagList; 
	   TeaBags parent;
	   String name;
	    
	   public abstract int countTeaBags();
	   
	   public abstract boolean add(TeaBags teaBagsToAdd);
	   public abstract boolean remove(TeaBags teaBagsToRemove);
	   public abstract ListIterator createListIterator();
	   
	   public void setParent(TeaBags parentIn) {
	       parent = parentIn;
	   }
	   public TeaBags getParent() {
	      return parent;
	   }
	   
	   public void setName(String nameIn) {
	       name = nameIn;
	   }
	   public String getName() {
	       return name;
	   }
	}