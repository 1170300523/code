package com.ijbamboo.pattern.template.example.dvd;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:43:32
 */
public class BookTitleInfo extends TitleInfo {  
	   private String author;
	    
	   public BookTitleInfo(String titleName, String author) {
	       this.setTitleName(titleName);
	       this.setAuthor(author);
	   }    
	   
	   public void setAuthor(String authorIn) {this.author = authorIn;}
	   public String getAuthor() {return this.author;}   
	   
	   public String getTitleBlurb() {
	       return ("Book: " + this.getTitleName() + 
	               ", Author: " + this.getAuthor());
	   }
	}
