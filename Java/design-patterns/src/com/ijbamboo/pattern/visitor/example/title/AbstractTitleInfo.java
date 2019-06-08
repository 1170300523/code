package com.ijbamboo.pattern.visitor.example.title;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:46:19
 */
public abstract class AbstractTitleInfo {  
	   private String titleName;    
	   public final void setTitleName(String titleNameIn) {
	       this.titleName = titleNameIn;
	   }
	   public final String getTitleName() {
	       return this.titleName;
	   }
	    
	   public abstract void accept(TitleBlurbVisitor titleBlurbVisitor);
	}