package com.ijbamboo.pattern.visitor.example.title;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:46:03
 */
public class TitleShortBlurbVisitor extends TitleBlurbVisitor {
	   public void visit(BookInfo bookInfo) {
	       this.setTitleBlurb("SB-Book: " + bookInfo.getTitleName());
	   }   
	   
	   public void visit(DvdInfo dvdInfo) {
	       this.setTitleBlurb("SB-DVD: " + dvdInfo.getTitleName());
	   }
	   
	   public void visit(GameInfo gameInfo) {
	       this.setTitleBlurb("SB-Game: " + gameInfo.getTitleName());
	   }
	}