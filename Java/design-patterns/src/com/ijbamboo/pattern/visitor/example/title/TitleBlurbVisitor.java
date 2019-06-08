package com.ijbamboo.pattern.visitor.example.title;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:45:09
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