package com.ijbamboo.pattern.visitor.example.title;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:47:13
 */
public class GameInfo  extends AbstractTitleInfo {  
	   public GameInfo(String titleName) {
	       this.setTitleName(titleName);
	   }    
	   
	   public void accept(TitleBlurbVisitor titleBlurbVisitor) {
	       titleBlurbVisitor.visit(this);
	   }
	}