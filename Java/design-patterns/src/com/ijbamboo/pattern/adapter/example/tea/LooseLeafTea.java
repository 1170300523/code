package com.ijbamboo.pattern.adapter.example.tea;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午8:44:04
 */
public class LooseLeafTea {
	boolean teaIsSteeped; 
    
	   public LooseLeafTea() {
	       teaIsSteeped = false;
	   }
	   
	   public void steepTea() {
	       teaIsSteeped = true;
	       System.out.println("tea is steeping");
	   }
	}
