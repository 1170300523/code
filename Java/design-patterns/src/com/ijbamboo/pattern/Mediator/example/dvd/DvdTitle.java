package com.ijbamboo.pattern.Mediator.example.dvd;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:29:47
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
