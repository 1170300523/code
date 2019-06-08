package com.ijbamboo.pattern.Decorator.example.tea;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午8:57:54
 */
public class TeaLeaves  extends Tea {  
	   public TeaLeaves() {
	       teaIsSteeped = false;
	   }
	   
	   public void steepTea() {
	       teaIsSteeped = true;
	       System.out.println("tea leaves are steeping");
	   }
	}