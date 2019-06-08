package com.ijbamboo.pattern.visitor.example.title;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:46:19
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