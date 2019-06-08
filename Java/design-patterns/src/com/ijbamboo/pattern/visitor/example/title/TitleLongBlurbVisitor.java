package com.ijbamboo.pattern.visitor.example.title;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:45:42
 */
public class TitleLongBlurbVisitor extends TitleBlurbVisitor {
	   public void visit(BookInfo bookInfo) {
	       this.setTitleBlurb("LB-Book: " + 
	                           bookInfo.getTitleName() + 
	                           ", Author: " + 
	                           bookInfo.getAuthor());
	   }   
	   
	   public void visit(DvdInfo dvdInfo) {
	       this.setTitleBlurb("LB-DVD: " + 
	                           dvdInfo.getTitleName() + 
	                           ", starring " + 
	                           dvdInfo.getStar() + 
	                           ", encoding region: " + 
	                           dvdInfo.getEncodingRegion());
	   }   
	   
	   public void visit(GameInfo gameInfo) {
	       this.setTitleBlurb("LB-Game: " + 
	                           gameInfo.getTitleName());
	   }   
	}
