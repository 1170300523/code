package com.ijbamboo.pattern.Mediator.example.dvd;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:29:47
 */
public abstract class DvdTitle {  
	   private String title; 
	   
	   public void setTitle(String titleIn) {
	       this.title = titleIn;
	   }
	   public String getTitle() {
	       return this.title;
	   }
	}
