package com.ijbamboo.pattern.visitor.example.title;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:45:09
 */
public abstract class TitleBlurbVisitor {
	   String titleBlurb;
	   public void setTitleBlurb(String blurbIn) {
	       this.titleBlurb = blurbIn;
	   }
	   public String getTitleBlurb() {
	       return this.titleBlurb;
	   }
	    
	   public abstract void visit(BookInfo bookInfo);
	   public abstract void visit(DvdInfo dvdInfo);   
	   public abstract void visit(GameInfo gameInfo);
	}  