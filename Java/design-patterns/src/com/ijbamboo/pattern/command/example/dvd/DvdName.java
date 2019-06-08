package com.ijbamboo.pattern.command.example.dvd;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:16:49
 */
public class DvdName {

	private String titleName;  
    
	   public DvdName(String titleName) {
	       this.setTitleName(titleName);
	   }    
	  
	   public final void setTitleName(String titleNameIn) {
	       this.titleName = titleNameIn;
	   }
	   public final String getTitleName() {
	       return this.titleName;
	   }
	   
	   public void setNameStarsOn() {
	       this.setTitleName(this.getTitleName().replace(' ','*'));
	   }
	   public void setNameStarsOff() {
	       this.setTitleName(this.getTitleName().replace('*',' '));
	   }   
	   
	   public String toString() {
	       return ("DVD: " + this.getTitleName());
	   }
	}
