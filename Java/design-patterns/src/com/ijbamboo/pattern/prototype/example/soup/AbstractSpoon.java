package com.ijbamboo.pattern.prototype.example.soup;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����5:49:41
 */
public  abstract class AbstractSpoon implements Cloneable {  
	   String spoonName; 
	    
	   public void setSpoonName(String spoonName) {
	       this.spoonName = spoonName;
	   }
	   public String getSpoonName() {
	       return this.spoonName;
	   }
	   
	   public Object clone() {
	       Object object = null;
	       try {
	           object = super.clone();
	       } catch (CloneNotSupportedException exception) {
	           System.err.println("AbstractSpoon is not Cloneable");
	       }
	       return object;
	   }
	}
