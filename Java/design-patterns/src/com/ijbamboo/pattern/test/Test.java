package com.ijbamboo.pattern.test;

import com.ijbamboo.pattern.builder.example.soup.SoupBuffet;
import com.ijbamboo.pattern.soup.ChickenSoup;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����4:51:05
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
