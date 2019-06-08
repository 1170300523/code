package com.ijbamboo.pattern.template.example.dvd;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:43:51
 */
public class GameTitleInfo  extends TitleInfo {  
	   public GameTitleInfo(String titleName) {
	       this.setTitleName(titleName);
	   }     
	   
	   public String getTitleBlurb() {
	       return ("Game: " + this.getTitleName());
	   }
	}