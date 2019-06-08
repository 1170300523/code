package com.ijbamboo.pattern.Mediator.example.dvd;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:30:43
 */
public class DvdMediator {

	private DvdUpcaseTitle dvdUpcaseTitle; 
	   private DvdLowercaseTitle dvdLowercaseTitle;    
	   
	   public void setUpcase(DvdUpcaseTitle dvdUpcaseTitle) {
	       this.dvdUpcaseTitle = dvdUpcaseTitle;
	   } 
	   
	   public void setLowercase(DvdLowercaseTitle dvdLowercaseTitle) {
	       this.dvdLowercaseTitle = dvdLowercaseTitle;
	   }   
	   
	   public void changeTitle(DvdUpcaseTitle dvdUpcaseTitle) {
	       this.dvdLowercaseTitle.resetTitle(dvdUpcaseTitle.getTitle());
	   }
	   
	   public void changeTitle(DvdLowercaseTitle dvdLowercaseTitle) {
	       this.dvdUpcaseTitle.resetTitle(dvdLowercaseTitle.getTitle());
	   }   
	}