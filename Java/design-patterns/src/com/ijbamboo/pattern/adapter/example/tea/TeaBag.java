package com.ijbamboo.pattern.adapter.example.tea;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午8:42:59
 */
public class TeaBag {
	boolean teaBagIsSteeped; 
    
	   public TeaBag() {
	       teaBagIsSteeped = false;
	   }
	   
	   public void steepTeaInCup() {
	       teaBagIsSteeped = true;
	       System.out.println("tea bag is steeping in cup");
	   }
}
