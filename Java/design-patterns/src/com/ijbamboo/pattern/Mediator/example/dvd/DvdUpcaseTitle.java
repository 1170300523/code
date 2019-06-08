package com.ijbamboo.pattern.Mediator.example.dvd;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:30:26
 */
public class DvdUpcaseTitle extends DvdTitle {  
	   private String upcaseTitle;
	   private DvdMediator dvdMediator;
	    
	   public DvdUpcaseTitle(String title, 
	                         DvdMediator dvdMediator) {
	       this.setTitle(title);
	       resetTitle();
	       this.dvdMediator = dvdMediator;
	       this.dvdMediator.setUpcase(this);
	   }    
	   
	   public DvdUpcaseTitle(DvdTitle dvdTitle, 
	                         DvdMediator dvdMediator) {
	       this(dvdTitle.getTitle(), dvdMediator);
	   }       
	   
	   public void resetTitle() {
	       this.setUpcaseTitle(this.getTitle().toUpperCase());
	   }
	   public void resetTitle(String title) {
	       this.setTitle(title);
	       this.resetTitle();
	   }    
	   
	   public void setSuperTitleUpcase() {
	       this.setTitle(this.getUpcaseTitle());
	       dvdMediator.changeTitle(this);       
	   }
	   
	   public String getUpcaseTitle() {
	      return upcaseTitle;
	   }
	   private void setUpcaseTitle(String upcaseTitle) {
	       this.upcaseTitle = upcaseTitle;
	   }
	}