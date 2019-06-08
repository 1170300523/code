package com.ijbamboo.pattern.visitor.example.title;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:47:13
 */
public class GameInfo  extends AbstractTitleInfo {  
	   public GameInfo(String titleName) {
	       this.setTitleName(titleName);
	   }    
	   
	   public void accept(TitleBlurbVisitor titleBlurbVisitor) {
	       titleBlurbVisitor.visit(this);
	   }
	}