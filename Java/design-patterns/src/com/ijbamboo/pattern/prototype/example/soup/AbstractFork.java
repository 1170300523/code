package com.ijbamboo.pattern.prototype.example.soup;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����5:50:30
 */
public abstract class AbstractFork implements Cloneable
{  
	   String forkName; 
	    
	   public void setForkName(String forkName) {
	       this.forkName = forkName;
	   }
	   public String getForkName() {
	       return this.forkName;
	   }
	   
	   public Object clone() 
	   {
	       Object object = null;
	       try {
	           object = super.clone();
	       } catch (CloneNotSupportedException exception) {
	           System.err.println("AbstractFork is not Cloneable");
	       }
	       return object;
	   }   
	}