package com.ijbamboo.pattern.strategy.example.dvd;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:40:31
 */
public class DvdNameReplaceSpacesStrategy extends DvdNameStrategy {
	   public String formatDvdName(String dvdName, char charIn) {
	       return dvdName.replace(' ', charIn);
	   }
	}
