package com.ijbamboo.pattern.test;

import com.ijbamboo.pattern.builder.example.soup.SoupBuffet;
import com.ijbamboo.pattern.soup.ChickenSoup;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午4:51:05
 */
public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		SoupBuffet soup = new SoupBuffet();
		soup.setChickenSoup(new ChickenSoup());
		soup.getTodaysSoups();
	}

}
