package com.ijbamboo.pattern.proxy.example.tea;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:09:15
 */
public class PotOfTea implements PotOfTeaInterface {  
	   public PotOfTea() {
	       System.out.println("Making a pot of tea");
	   }
	   
	   public void pourTea() {
	       System.out.println("Pouring tea");
	   }   
	}