package com.ijbamboo.pattern.template.example.dvd;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:43:51
 */
public class GameTitleInfo  extends TitleInfo {  
	   public GameTitleInfo(String titleName) {
	       this.setTitleName(titleName);
	   }     
	   
	   public String getTitleBlurb() {
	       return ("Game: " + this.getTitleName());
	   }
	}