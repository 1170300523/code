package com.ijbamboo.pattern.State.example.dvd;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:36:57
 */
public class DvdStateContext {
	private DvdStateName dvdStateName; 
    
	   public DvdStateContext() {
	       setDvdStateName(new DvdStateNameStars());  
	       //start with stars
	   }
	   
	   public void setDvdStateName(DvdStateName dvdStateNameIn) {
	       this.dvdStateName = dvdStateNameIn;
	   }
	   
	   public void showName(String nameIn) {
	       this.dvdStateName.showName(this, nameIn);
	   }
	}
